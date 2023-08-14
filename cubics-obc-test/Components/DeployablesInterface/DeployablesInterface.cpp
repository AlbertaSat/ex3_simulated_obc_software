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
            timeout.tv_sec = 10;
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

    // Create a thread to handle socket read
    std::thread socketReadThread(&DeployablesInterface::handleSocketRead, this, client_fd);
    socketReadThread.detach(); // Detach the thread so it runs independently


    return 0;

  }
  // int DeployablesInterface :: openSocket(){
  //   // get file descriptor for client:
  //   if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
  //       fprintf(stderr, "Socket creation error \n");
  //       this->log_WARNING_HI_socketOpenFailure("Socket creation error");
  //       return -1;
  //   }

  //   // Initialize server socket with expected port and family
  //   serv_addr.sin_family = AF_INET;
  //   serv_addr.sin_port = htons(TCP_PORT);

  //   // Convert IPv4 and IPv6 addresses from text to binary
  //   if (inet_pton(AF_INET, LOCAL_HOST, &serv_addr.sin_addr) <= 0) {
  //       fprintf(stderr, "Invalid socket address \n");
  //       this->log_WARNING_HI_socketOpenFailure(
  //           "Invalid address/ Address not supported");
  //       return -1;
  //   }

  //   // Attempt to connect to port
  //   if ((status = connect(client_fd, (struct sockaddr *)&serv_addr,
  //                         sizeof(serv_addr))) < 0) {
  //       fprintf(stderr, "Port connection failed \n");
  //       this->log_WARNING_HI_socketOpenFailure("Port Connection Failed");
  //       return -1;
  //   }

  //   return 0;
  // }

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

        if (FD_ISSET(client_fd, &set)) {
            memset(buffer, 0, sizeof(buffer));
            read(client_fd, buffer, sizeof(buffer));
            printf("From server: %s\n", buffer);

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

  void DeployablesInterface ::
    deployableDataOutgoing_handler(
        const NATIVE_INT_TYPE portNum,
        const aString &a
    )
  {
    // Put the received data into the client TCP socket to be sent to the deployables component

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
