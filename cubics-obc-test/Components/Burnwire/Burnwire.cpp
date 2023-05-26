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

  void Burnwire ::
    run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    if(state == Fw::On::ON){
      if(count >= 20){
        //Turn off gpio
        //reset state to off
        // Port may not be connected, so check before sending output
        if (this->isConnected_gpioSet_OutputPort(0))
        {
          this->gpioSet_out(0, Fw::Logic::LOW);
          state = Fw::On::OFF;
          this->tlmWrite_BurnwireState(state);
          this->log_ACTIVITY_HI_SetBurnwireState(state);
     
        }
      }
      else if(count == 0){
        //turn on gpio 
        if (this->isConnected_gpioSet_OutputPort(0))
        {
          this->gpioSet_out(0, Fw::Logic::HIGH);
          this->tlmWrite_BurnwireState(state);
          this->log_ACTIVITY_HI_SetBurnwireState(state);
          count = count + 1;
     
          
        }
      }
      else{
        //increment count
        count = count+1; 
        this->tlmWrite_BurnwireCounter(count);
      }

    }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void Burnwire ::
    ACTIVATE_BURNWIRE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // Create a variable to represent the command response
    auto cmdResp = Fw::CmdResponse::OK;

    //This function just sets the burnwire state to 'on' and resets the counter to zero 
    state = Fw::On::ON;
    count = 0; 
    this->tlmWrite_BurnwireCounter(count);
  
    //The burnwire_run function implements the cyclic counter increment 
    //Run_handler function using scheduled input port to receive calls from rate group. If the burnwire state is 'off' , ignore them. 
    //Increment count. Rate group should call this fxn each second (using 1Hz rate group)

    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Components
