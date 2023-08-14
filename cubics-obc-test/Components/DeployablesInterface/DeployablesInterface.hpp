// ======================================================================
// \title  DeployablesInterface.hpp
// \author fprime-dev
// \brief  hpp file for DeployablesInterface component implementation class
// ======================================================================

#ifndef DeployablesInterface_HPP
#define DeployablesInterface_HPP


#define LOCAL_HOST "127.0.0.1"
#define TCP_PORT 1811

#define MAX_BUFFER_CHARS 1024

#define THREAD_READ_TIMEOUT_SECONDS 10

#define SA struct sockaddr

#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "Components/DeployablesInterface/DeployablesInterfaceComponentAc.hpp"

namespace Components {

  class DeployablesInterface :
    public DeployablesInterfaceComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DeployablesInterface
      //!
      DeployablesInterface(
          const char *const compName /*!< The component name*/
      );

      //! Destroy object DeployablesInterface
      //!
      ~DeployablesInterface();

    PRIVATE:

      int status;
      int client_fd;
      struct sockaddr_in serv_addr;
      char incomingData[MAX_BUFFER_CHARS] = {0};

      int openSocket();

      void closeSocket();

      void handleSocketRead(int sockfd);

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for deployableDataOutgoing
      //!
      void deployableDataOutgoing_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const aString &a 
      );


    };

} // end namespace Components

#endif
