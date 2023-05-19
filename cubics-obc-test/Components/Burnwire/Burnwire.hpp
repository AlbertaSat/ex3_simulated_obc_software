// ======================================================================
// \title  Burnwire.hpp
// \author fprime-dev
// \brief  hpp file for Burnwire component implementation class
// ======================================================================

#ifndef Burnwire_HPP
#define Burnwire_HPP

#include "Components/Burnwire/BurnwireComponentAc.hpp"
#include <Fw/Types/OnEnumAc.hpp>

namespace Components {

  class Burnwire :
    public BurnwireComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Burnwire
      //!
      Burnwire(
          const char *const compName /*!< The component name*/
      );

      //! Destroy object Burnwire
      //!
      ~Burnwire();

    PRIVATE:

      // Component state tracking variables
      Fw::On state; //Tracks state of whether or not burnwire is on or off. 

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for TODO command handler
      //! Comand to activate the burnwire
      void ACTIVATE_BURNWIRE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

    };

} // end namespace Components

#endif
