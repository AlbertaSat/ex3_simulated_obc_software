// ======================================================================
// \title  DeployablesService.hpp
// \author fprime-dev
// \brief  hpp file for DeployablesService component implementation class
// ======================================================================

#ifndef DeployablesService_HPP
#define DeployablesService_HPP

#include "Components/DeployablesService/DeployablesServiceComponentAc.hpp"

#include <map>
#include <string>

#define NAME_CHAR_MAX 32
#define NUMBER_OF_DEPLOYABLES 7


namespace Components {

  enum class DeployableStatus {
    STOWED = 0,
    PENDING = 1,
    DEPLOYED = 2,
  };

  class DeployablesService :
    public DeployablesServiceComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DeployablesService
      //!
      DeployablesService(
          const char *const compName /*!< The component name*/
      );

      //! Destroy object DeployablesService
      //!
      ~DeployablesService();

    PRIVATE:

      // Holds a reference to each component and its associated deployment status 
      std::map<std::string, DeployableStatus> deployablesMap;


      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for deployableFeedbackSwitchPort
      //!
      void deployableFeedbackSwitchPort_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const aString &a 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for ActivateDeploymentSequence command handler
      //! 
      void ActivateDeploymentSequence_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Components

#endif
