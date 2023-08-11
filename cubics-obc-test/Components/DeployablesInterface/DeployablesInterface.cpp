// ======================================================================
// \title  DeployablesInterface.cpp
// \author fprime-dev
// \brief  cpp file for DeployablesInterface component implementation class
// ======================================================================


#include <Components/DeployablesInterface/DeployablesInterface.hpp>
#include <FpConfig.hpp>

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

  int DeployablesInterface :: openSocket(){
    // get file descriptor for client:
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Socket creation error \n");
        this->log_WARNING_HI_socketOpenFailure("Socket creation error");
        return -1;
    }

    // Initialize server socket with expected port and family
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(TCP_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, LOCAL_HOST, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid socket address \n");
        this->log_WARNING_HI_socketOpenFailure(
            "Invalid address/ Address not supported");
        return -1;
    }

    // Attempt to connect to port
    if ((status = connect(client_fd, (struct sockaddr *)&serv_addr,
                          sizeof(serv_addr))) < 0) {
        fprintf(stderr, "Port connection failed \n");
        this->log_WARNING_HI_socketOpenFailure("Port Connection Failed");
        return -1;
    }

    fprintf(stderr, "Socket connection success \n");
    this->log_ACTIVITY_LO_socketOpenSuccess();
    return 0;
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

    char outgoingData[REPLY_BUFFER_MAX_CHARS] = {0};
    strcpy(outgoingData, a.toChar());

    ssize_t len = send(client_fd, outgoingData, strlen(outgoingData), 0);
    if (len > 0) {
        fprintf(stderr, "Socket send success \n");
        this->log_ACTIVITY_LO_sentDeployableData(outgoingData);
    } else {
        fprintf(stderr, "Socket send failure \n");
        this->log_WARNING_HI_socketSendFailure("Socket send failure");
    }

  }

} // end namespace Components
