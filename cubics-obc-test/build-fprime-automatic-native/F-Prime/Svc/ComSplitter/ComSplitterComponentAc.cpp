// ======================================================================
// \title  ComSplitterComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ComSplitter component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/ComSplitter/ComSplitterComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputComPort *ComSplitterComponentBase ::
    get_comIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_comIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_comIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void ComSplitterComponentBase ::
    set_comOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputComPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_comOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comOut_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void ComSplitterComponentBase ::
    set_comOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_comOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_comOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    ComSplitterComponentBase :: ComSplitterComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void ComSplitterComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port comIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comIn_InputPorts());
        port++
    ) {

      this->m_comIn_InputPort[port].init();
      this->m_comIn_InputPort[port].addCallComp(
          this,
          m_p_comIn_in
      );
      this->m_comIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port comOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comOut_OutputPorts());
        port++
    ) {
      this->m_comOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comOut_OutputPort[port].setObjName(portName);
#endif

    }


  }

  ComSplitterComponentBase::
    ~ComSplitterComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void ComSplitterComponentBase ::
    comOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(portNum < this->getNum_comOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comOut_OutputPort[portNum].invoke(data, context);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ComSplitterComponentBase ::
    getNum_comIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comIn_InputPort));
  }

  NATIVE_INT_TYPE ComSplitterComponentBase ::
    getNum_comOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool ComSplitterComponentBase ::
    isConnected_comOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_comOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_comOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void ComSplitterComponentBase ::
    m_p_comIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(callComp);
    ComSplitterComponentBase* compPtr = static_cast<ComSplitterComponentBase*>(callComp);
    compPtr->comIn_handlerBase(portNum, data, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void ComSplitterComponentBase ::
    comIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_comIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->comIn_handler(portNum, data, context);

  }

} // end namespace Svc
