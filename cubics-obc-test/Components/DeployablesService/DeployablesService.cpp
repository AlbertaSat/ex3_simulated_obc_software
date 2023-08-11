// ======================================================================
// \title  DeployablesService.cpp
// \author fprime-dev
// \brief  cpp file for DeployablesService component implementation class
// ======================================================================


#include <Components/DeployablesService/DeployablesService.hpp>
#include <FpConfig.hpp>


namespace Components {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DeployablesService ::
    DeployablesService(
        const char *const compName
    ) : DeployablesServiceComponentBase(compName)
  {
    //Initialize deployables map with all deployable items set to stowed
    //TODO - this will have to fetch the deployables deployment state from some sort of non volatile memory
    deployablesMap["DFGM"] = DeployableStatus::STOWED;
    deployablesMap["UHF_P"] = DeployableStatus::STOWED;
    deployablesMap["UHF_Z"] = DeployableStatus::STOWED;
    deployablesMap["UHF_N"] = DeployableStatus::STOWED;
    deployablesMap["UHF_S"] = DeployableStatus::STOWED;
    deployablesMap["SOLAR_S"] = DeployableStatus::STOWED;
    deployablesMap["SOLAR_P"] = DeployableStatus::STOWED;
  }

  DeployablesService ::
    ~DeployablesService()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DeployablesService ::
    deployableFeedbackSwitchPort_handler(
        const NATIVE_INT_TYPE portNum,
        const aString &a
    )
  {
    
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void DeployablesService ::
    ActivateDeploymentSequence_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    //Send command to toggle DFGM burnwire HIGH  
    

    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Components
