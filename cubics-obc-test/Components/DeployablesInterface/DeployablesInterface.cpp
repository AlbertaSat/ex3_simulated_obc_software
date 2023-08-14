// ======================================================================
// \title  DeployablesInterface.cpp
// \author fprime-dev
// \brief  cpp file for DeployablesInterface component implementation class
// ======================================================================


#include <Components/DeployablesInterface/DeployablesInterface.hpp>
#include <FpConfig.hpp>

#include <fcntl.h>   // For fcntl
#include <sys/select.h> // For select

#include <thread>

#include <errno.h>
#include <string.h>

namespace Components {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DeployablesInterface ::
    DeployablesInterface(
        const char *const compName
    ) : DeployablesInterfaceComponentBase(compName)
  {
    openSocket();
  }

  DeployablesInterface ::
    ~DeployablesInterface()
  {
    closeSocket();
  }

  int DeployablesInterface :: openSocket()
  {
    struct sockaddr_in servaddr;

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("Socket creation for Deployables Interface failed");
        return 1;
    }
    printf("Socket for Deployables Interface successfully created\n");

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(TCP_PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int flags = fcntl(client_fd, F_GETFL, 0);
    fcntl(client_fd, F_SETFL, flags | O_NONBLOCK);

    if (connect(client_fd, (SA*)&servaddr, sizeof(servaddr)) < 0) {
        if (errno == EINPROGRESS) {
            fd_set set;
            struct timeval timeout;
            FD_ZERO(&set);
            FD_SET(client_fd, &set);
            timeout.tv_sec = THREAD_READ_TIMEOUT_SECONDS;
            timeout.tv_usec = 0;

            int result = select(client_fd + 1, NULL, &set, NULL, &timeout);
            if (result < 0 && errno != EINTR) {
                perror("Error during connection to Deployables Interface socket");
                return 1;
            }
            else if (result > 0) {
                int so_error;
                socklen_t len = sizeof so_error;

                getsockopt(client_fd, SOL_SOCKET, SO_ERROR, &so_error, &len);

                if (so_error == 0) {
                    printf("Successfully connected to Deployables Interface socket\n");
                } else {
                    // Connection failed
                    errno = so_error;
                    perror("Error during connection to Deployables Interface ");
                    return 1;
                }
            } else {
                fprintf(stderr, "Timeout or error during Deployables Interface connection\n");
                return 1;
            }
        } else {
            perror("Connection to Deployables Interface socket failed");
            return 1;
        }
    }

    // Create a thread to handle socket reading
    std::thread socketReadThread(&DeployablesInterface::handleSocketRead, this, client_fd);
    socketReadThread.detach(); // Detach the thread so it runs independently 

    return 0;
  }

  // Runs in an independent thread, handles reading from the socket with the select function
  void DeployablesInterface :: handleSocketRead(int client_fd){
    char buffer[MAX_BUFFER_CHARS];
    fd_set set;
    struct timeval timeout;

    while(1) {
        FD_ZERO(&set);
        FD_SET(client_fd, &set);
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        int activity = select(client_fd + 1, &set, NULL, NULL, &timeout);

        if ((activity < 0) && (errno!=EINTR)) {
            perror("Select error");
        }

        //If there is data to be read from this socket, read it and send it to DeployablesService component 
        if (FD_ISSET(client_fd, &set)) {
            memset(buffer, 0, sizeof(buffer));
            read(client_fd, buffer, sizeof(buffer));
            fprintf(stderr, "From server: %s\n", buffer);

           this->deployableDataIncoming_out(0, buffer);
        }
    }
  }

  void DeployablesInterface :: closeSocket(){
    close(client_fd);
    fprintf(stderr, "Socket closed \n");
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  // Put the received data into the client TCP socket to be sent to the deployables component
  void DeployablesInterface ::
    deployableDataOutgoing_handler(
        const NATIVE_INT_TYPE portNum,
        const aString &a
    )
  {
    char outgoingData[MAX_BUFFER_CHARS] = {0};
    strcpy(outgoingData, a.toChar());

    ssize_t len = send(client_fd, outgoingData, strlen(outgoingData), 0);
    if (len > 0) {
        fprintf(stderr, "Socket send success \n");
        this->log_ACTIVITY_LO_sentDeployableData(outgoingData);
    } else {
        fprintf(stderr, "ERROR: Socket send failure: %s \n", strerror(errno));
        this->log_WARNING_HI_socketSendFailure("Socket send failure");
    }

  }

} // end namespace Components
