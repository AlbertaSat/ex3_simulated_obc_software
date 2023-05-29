// ======================================================================
// \title  Burnwire.cpp
// \author fprime-dev
// \brief  cpp file for Burnwire component implementation class
// ======================================================================


#include <Components/Burnwire/Burnwire.hpp>
#include <FpConfig.hpp>

namespace Burnwire {

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
  // Command handler implementations
  // ----------------------------------------------------------------------

  void Burnwire ::
    TODO_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Burnwire
