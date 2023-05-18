// ======================================================================
// \title  PolyDbComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for PolyDb component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/PolyDb/PolyDbComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Svc::InputPolyPort *PolyDbComponentBase ::
    get_getValue_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_getValue_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_getValue_InputPort[portNum];
  }

  Svc::InputPolyPort *PolyDbComponentBase ::
    get_setValue_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_setValue_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_setValue_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    PolyDbComponentBase :: PolyDbComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void PolyDbComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port getValue
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_getValue_InputPorts());
        port++
    ) {

      this->m_getValue_InputPort[port].init();
      this->m_getValue_InputPort[port].addCallComp(
          this,
          m_p_getValue_in
      );
      this->m_getValue_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_getValue_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_getValue_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port setValue
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_setValue_InputPorts());
        port++
    ) {

      this->m_setValue_InputPort[port].init();
      this->m_setValue_InputPort[port].addCallComp(
          this,
          m_p_setValue_in
      );
      this->m_setValue_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_setValue_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_setValue_InputPort[port].setObjName(portName);
#endif

    }


  }

  PolyDbComponentBase::
    ~PolyDbComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE PolyDbComponentBase ::
    getNum_getValue_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_getValue_InputPort));
  }

  NATIVE_INT_TYPE PolyDbComponentBase ::
    getNum_setValue_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_setValue_InputPort));
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void PolyDbComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void PolyDbComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void PolyDbComponentBase ::
    m_p_getValue_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 entry, Svc::MeasurementStatus &status, Fw::Time &time, Fw::PolyType &val
    )
  {
    FW_ASSERT(callComp);
    PolyDbComponentBase* compPtr = static_cast<PolyDbComponentBase*>(callComp);
    compPtr->getValue_handlerBase(portNum, entry, status, time, val);
  }

  void PolyDbComponentBase ::
    m_p_setValue_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 entry, Svc::MeasurementStatus &status, Fw::Time &time, Fw::PolyType &val
    )
  {
    FW_ASSERT(callComp);
    PolyDbComponentBase* compPtr = static_cast<PolyDbComponentBase*>(callComp);
    compPtr->setValue_handlerBase(portNum, entry, status, time, val);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void PolyDbComponentBase ::
    getValue_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 entry, Svc::MeasurementStatus &status, Fw::Time &time, Fw::PolyType &val
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_getValue_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->getValue_handler(portNum, entry, status, time, val);

    // Unlock guard mutex
    this->unLock();

  }

  void PolyDbComponentBase ::
    setValue_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 entry, Svc::MeasurementStatus &status, Fw::Time &time, Fw::PolyType &val
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_setValue_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->setValue_handler(portNum, entry, status, time, val);

    // Unlock guard mutex
    this->unLock();

  }

} // end namespace Svc
