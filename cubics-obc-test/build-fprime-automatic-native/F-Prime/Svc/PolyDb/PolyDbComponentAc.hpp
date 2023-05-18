// ======================================================================
// \title  PolyDbComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for PolyDb component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_POLYDB_COMP_HPP_
#define SVC_POLYDB_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Svc/PolyIf/MeasurementStatusEnumAc.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Types/PolyType.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Types/PolyType.hpp>
#include <Svc/PolyIf/PolyPortAc.hpp>

namespace Svc {

  //! \class PolyDbComponentBase
  //! \brief Auto-generated base for PolyDb component
  //!
  class PolyDbComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class PolyDbComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return getValue[portNum]
    //!
    Svc::InputPolyPort* get_getValue_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return setValue[portNum]
    //!
    Svc::InputPolyPort* get_setValue_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a PolyDbComponentBase object
    //!
    PolyDbComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a PolyDbComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a PolyDbComponentBase object
    //!
    virtual ~PolyDbComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    //! Mutex operations for guarded ports.
    // ----------------------------------------------------------------------
    //! You can override these operations to provide more sophisticated
    //! synchronization.
    // ----------------------------------------------------------------------

    //! Lock the guarded mutex
    //!
    virtual void lock();

    //! Unlock the guarded mutex
    //!
    virtual void unLock();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port getValue
    //
    virtual void getValue_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 entry, /*!< 
      The entry to access
      */
        Svc::MeasurementStatus &status, /*!< 
      The command response argument
      */
        Fw::Time &time, /*!< 
      The time of the measurement
      */
        Fw::PolyType &val /*!< 
      The value to be passed
      */
    ) = 0;

    //! Handler for input port setValue
    //
    virtual void setValue_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 entry, /*!< 
      The entry to access
      */
        Svc::MeasurementStatus &status, /*!< 
      The command response argument
      */
        Fw::Time &time, /*!< 
      The time of the measurement
      */
        Fw::PolyType &val /*!< 
      The value to be passed
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port getValue
    //!
    void getValue_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 entry, /*!< 
      The entry to access
      */
        Svc::MeasurementStatus &status, /*!< 
      The command response argument
      */
        Fw::Time &time, /*!< 
      The time of the measurement
      */
        Fw::PolyType &val /*!< 
      The value to be passed
      */
    );

    //! Handler base-class function for input port setValue
    //!
    void setValue_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 entry, /*!< 
      The entry to access
      */
        Svc::MeasurementStatus &status, /*!< 
      The command response argument
      */
        Fw::Time &time, /*!< 
      The time of the measurement
      */
        Fw::PolyType &val /*!< 
      The value to be passed
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of getValue input ports
    //!
    //! \return The number of getValue input ports
    //!
    NATIVE_INT_TYPE getNum_getValue_InputPorts();

    //! Get the number of setValue input ports
    //!
    //! \return The number of setValue input ports
    //!
    NATIVE_INT_TYPE getNum_setValue_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_GETVALUE_INPUT_PORTS = 1,
       NUM_SETVALUE_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port getValue
    //!
    Svc::InputPolyPort m_getValue_InputPort[NUM_GETVALUE_INPUT_PORTS];

    //! Input port setValue
    //!
    Svc::InputPolyPort m_setValue_InputPort[NUM_SETVALUE_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port getValue
    //!
    static void m_p_getValue_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 entry, /*!< 
      The entry to access
      */
        Svc::MeasurementStatus &status, /*!< 
      The command response argument
      */
        Fw::Time &time, /*!< 
      The time of the measurement
      */
        Fw::PolyType &val /*!< 
      The value to be passed
      */
    );

    //! Callback for port setValue
    //!
    static void m_p_setValue_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 entry, /*!< 
      The entry to access
      */
        Svc::MeasurementStatus &status, /*!< 
      The command response argument
      */
        Fw::Time &time, /*!< 
      The time of the measurement
      */
        Fw::PolyType &val /*!< 
      The value to be passed
      */
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;



  };

} // end namespace Svc
#endif
