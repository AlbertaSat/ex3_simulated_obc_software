// ======================================================================
// \title  Burnwire.cpp
// \author fprime-dev
// \brief  cpp file for Burnwire component implementation class
// ======================================================================


#include <Components/Burnwire/Burnwire.hpp>
#include <FpConfig.hpp>
#include <Fw/Types/LogicEnumAc.hpp>

namespace Components {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  Burnwire ::
    Burnwire(
        const char *const compName
    ) : BurnwireComponentBase(compName)
  {

  }

  Burnwire ::
    ~Burnwire()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

/*
 *   When ACTIVATE_BURNWIRE_cmdHandler() toggles the burnwire state to Fw::On::ON, and
 *   sets the counter value is to zero, this function toggles the burnwire GPIO high. 
 *   This function will report via telemetry and log the burnwire state, and increment
 *   a counter once per second. Once the counter value exceeds BURNWIRE_TIME_SECONDS, 
 *   the state is set of OFF. The counter value is not reset here in case the state is 
 *   somehow set to ON erronesouly, then the function will simply set the state to back 
 *   to OFF. 
 * 
 *   A 1Hz rate group timer output must be attached to the input port of this component. 
 *   This is done within the topology.fpp file of the deployment using it.
 */
  void Burnwire ::
    run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    if(state == Fw::On::ON){
      if(count >= BURNWIRE_TIME_SECONDS){
        //Turn off gpio
        //reset state to off
        // Port may not be connected, so check before sending output
        // if (this->isConnected_gpioSet_OutputPort(0))
        // {
        //   this->gpioSet_out(0, Fw::Logic::LOW);
          state = Fw::On::OFF;
          this->tlmWrite_BurnwireState(state);
          this->log_ACTIVITY_HI_SetBurnwireState(state);
        // }
      }
      else if(count == 0){
        //turn on gpio 
        // if (this->isConnected_gpioSet_OutputPort(0))
        // {
        //   this->gpioSet_out(0, Fw::Logic::HIGH);
          this->tlmWrite_BurnwireState(state);
          this->log_ACTIVITY_HI_SetBurnwireState(state);
          count = count + 1;
        // }
      }
      else{
        count = count+1; 
        this->tlmWrite_BurnwireCounter(count);
      }
    }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

/*
 *   Sets the burnwire state to ON and resets the counter to zero. This will allow the 
 *   run_handler to begin. 
 */
  void Burnwire ::
    ACTIVATE_BURNWIRE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // Create a variable to represent the command response
    auto cmdResp = Fw::CmdResponse::OK;

    state = Fw::On::ON;
    count = 0; 
    this->tlmWrite_BurnwireCounter(count);
  
    //run_handler function uses a scheduled input port to receive calls from rate group. If the burnwire state is 'off', ignore them. 

    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Components
