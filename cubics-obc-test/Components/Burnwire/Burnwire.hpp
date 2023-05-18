// ======================================================================
// \title  Burnwire.hpp
// \author fprime-dev
// \brief  hpp file for Burnwire component implementation class
// ======================================================================

#ifndef Burnwire_HPP
#define Burnwire_HPP

#include "Components/Burnwire/BurnwireComponentAc.hpp"

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

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for TODO command handler
      //! TODO
      void TODO_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Components

#endif
