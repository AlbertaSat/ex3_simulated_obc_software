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
    ) : BurnwireComponentBase(compName) ,
    state(Fw::On::OFF)
  {

  }

  Burnwire ::
    ~Burnwire()
  {

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

    state = Fw::On::ON;
    // Port may not be connected, so check before sending output
    if (this->isConnected_gpioSet_OutputPort(0))
    {
      this->tlmWrite_BurnwireState(state);
    }

    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Components
