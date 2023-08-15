// ======================================================================
// \title  DeployablesService.cpp
// \author fprime-dev
// \brief  cpp file for DeployablesService component implementation class
// ======================================================================


#include <Components/DeployablesService/DeployablesService.hpp>
#include <FpConfig.hpp>


#include <iostream>
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
    deployablesMap["DFGM"] = {DeployableStatus::STOWED, 0};
    deployablesMap["UHF_P"] = {DeployableStatus::STOWED, 0};
    deployablesMap["UHF_Z"] = {DeployableStatus::STOWED, 0};
    deployablesMap["UHF_N"] = {DeployableStatus::STOWED, 0};
    deployablesMap["UHF_S"] = {DeployableStatus::STOWED, 0};
    deployablesMap["SOLAR_S"] = {DeployableStatus::STOWED, 0};
    deployablesMap["SOLAR_P"] = {DeployableStatus::STOWED, 0};

    LEOPDeploymentSequence = {
      "DFGM",
      "UHF_P",
      "UHF_Z",
      "UHF_N",
      "UHF_S",
      "SOLAR_S",
      "SOLAR_P"
    };

  }

  DeployablesService ::
    ~DeployablesService()
  {

  }

  std::string DeployablesService :: getStatusString(DeployableStatus status) {
    switch (status) {
        case DeployableStatus::STOWED:
            return "STOWED";
        case DeployableStatus::PENDING:
            return "PENDING";
        case DeployableStatus::DEPLOYED:
            return "DEPLOYED";
        case DeployableStatus::FAILED_ALL_ATTEMPTS:
            return "FAILED_ALL_ATTEMPTS";
        default:
            return "UNKNOWN";
    }
  }

  void DeployablesService :: printAllDeployablesStatus(){
    std::cout << "---------- Deployables Status ----------" << std::endl;
    for (const std::string& deployableName : LEOPDeploymentSequence){
      const DeployableInfo& deployableInfo = deployablesMap[deployableName];
      std::cout << "Deployable: " << deployableName
                  << ", Status: " << getStatusString(deployableInfo.status)
                  << ", Attempts: " << deployableInfo.numAttempts << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
  }


  void DeployablesService :: updateDeployableStatus(const std::string& deployableName, DeployableStatus status){
    deployablesMap[deployableName.c_str()].status = status;

    if(status == DeployableStatus::DEPLOYED){
      this->log_ACTIVITY_LO_deployableDeployed(deployableName.c_str());
    } else if(status == DeployableStatus::STOWED){
      this->log_ACTIVITY_LO_deployableStowed(deployableName.c_str());
    } else if(status == DeployableStatus::PENDING){
      this->log_ACTIVITY_LO_deployablePending(deployableName.c_str());
    }
  }

  void DeployablesService :: updateDeployableAttempts(const std::string& deployableName, int numAttempts){
    deployablesMap[deployableName.c_str()].numAttempts = numAttempts;
  }

  void DeployablesService :: attemptDeployment(const std::string& deployableName){
    DeployableInfo& deployableInfo = deployablesMap[deployableName.c_str()];

    //Build string to send to deployables interface
    std::string burnwireSetString = "burnwire_set:" + deployableName + ":1";

    //Send command to toggle target component burnwire HIGH to deployables interface via port 
    this->deployableToggleBurnwirePort_out(0, burnwireSetString.c_str());

    while(deployableInfo.numAttempts < NUMBER_OF_DEPLOYMENT_ATTEMPTS && deployableInfo.status != DeployableStatus::DEPLOYED){
      deployableInfo = deployablesMap[deployableName.c_str()];

      //Wait for deployable burnwire to physically burn
      sleep(BURNWIRE_WAIT_TIME_SECONDS); 

      //Build string to send query for target components feedback switch status
      std::string switchStatusRequestString = "switch_request:" + deployableName;

      //Send command to query target component feedback switch status to deployables interface via port 
      this->deployableToggleBurnwirePort_out(0, switchStatusRequestString.c_str());

      //Wait for response to come in from deployables interface
      sleep(SWITCH_QUERY_RESPONSE_WAIT_TIME_SECONDS); 

      updateDeployableAttempts(deployableName, deployableInfo.numAttempts + 1);

      //If N attempts fail, then this component is skipped 
      if(deployableInfo.numAttempts >= NUMBER_OF_DEPLOYMENT_ATTEMPTS){
        updateDeployableStatus(deployableName, DeployableStatus::FAILED_ALL_ATTEMPTS);
      }

      printAllDeployablesStatus();
    }

    //Set burnwire LOW 
    burnwireSetString = "burnwire_set:" + deployableName + ":0";

    this->deployableToggleBurnwirePort_out(0, burnwireSetString.c_str());

  }
  

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  //This handler is called when a deployable feedback switch status is received from the deployables interface (via async input port)
  //TODO - error handling and checking response string  
  void DeployablesService ::
    deployableFeedbackSwitchPort_handler(
        const NATIVE_INT_TYPE portNum,
        const aString &a
    )
  {
    //Convert the response string to std::string for easier manipulation
    std::string responseString = a.toChar();
    
    //Parse the response string to get the deployable name and feedback switch status
    std::string delimiter = ":";
    std::string deployableName = responseString.substr(0, responseString.find(delimiter));

    // Ignore the string if the first token is not a deployable name 
    if(deployablesMap.find(deployableName.c_str()) == deployablesMap.end()){
      return;
    }
    std::string feedbackSwitchStatus = responseString.substr(responseString.find(delimiter) + 1, responseString.length());
    // fprintf(stderr,"Deployable name: %s\n", deployableName.c_str());
    // fprintf(stderr,"Feedback switch status: %s\n", feedbackSwitchStatus.c_str());

    if(feedbackSwitchStatus == "1"){
      updateDeployableStatus(deployableName, DeployableStatus::DEPLOYED);
    } else {
      updateDeployableStatus(deployableName, DeployableStatus::STOWED);
    }
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
    this->log_ACTIVITY_LO_deploymentSequenceStarted();
    //Loop through all items in deployables map and attempt to deploy them
    for (const std::string& deployableName : LEOPDeploymentSequence){
      attemptDeployment(deployableName);
    }
    this->log_ACTIVITY_LO_deploymentSequenceEnded();

    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Components
