// ======================================================================
// \title  DeployablesService.cpp
// \author fprime-dev
// \brief  cpp file for DeployablesService component implementation class
// ======================================================================


#include <Components/DeployablesService/DeployablesService.hpp>
#include <FpConfig.hpp>

#include <unistd.h>


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
    //Update the deployables map with the feedback switch status
    
    std::string responseString = a.toChar();

    //Parse the response string to get the deployable name and feedback switch status
    std::string delimiter = ":";
    std::string deployableName = responseString.substr(0, responseString.find(delimiter));
    std::string feedbackSwitchStatus = responseString.substr(responseString.find(delimiter) + 1, responseString.length());

    fprintf(stdout,"Deployable name: %s\n", deployableName.c_str());
    fprintf(stdout,"Feedback switch status: %s\n", feedbackSwitchStatus.c_str());


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
    this->deployableToggleBurnwirePort_out(0, "burnwire_set:DFGM:1");
    this->log_ACTIVITY_LO_burnwireToggled("DFGM", "1");

    //Wait 20 seconds. Request feedback switch status. 
    // If feedback switch is HIGH, then toggle burnwire LOW
    // If feedback switch is LOW, leave burnwire HIGH and wait another 20 seconds 
    
    sleep(20);
    this->deployableToggleBurnwirePort_out(0, "switch_request:DFGM");
    sleep(5); //Wait for response to come in 


    //Check DFGM switch status 

    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Components
