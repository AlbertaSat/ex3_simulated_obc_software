// ======================================================================
// \title  ActiveLoggerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ActiveLogger component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/ActiveLogger/ActiveLoggerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Anonymous namespace to prevent name collisions
  // ----------------------------------------------------------------------

  namespace {

    typedef enum {
      ACTIVELOGGER_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      PINGIN_PING,
      CMD_SET_ID_FILTER,
      CMD_DUMP_FILTER_STATE,
      INT_IF_LOQQUEUE
    } MsgTypeEnum;

    // Get the max size by doing a union of the input port serialization sizes.

    typedef union {
      BYTE port1[Svc::InputPingPort::SERIALIZED_SIZE];
      BYTE cmdPort[Fw::InputCmdPort::SERIALIZED_SIZE];
      // Size of loqQueue argument list
      BYTE loqQueueIntIfSize[
        sizeof(FwEventIdType) +
        Fw::Time::SERIALIZED_SIZE +
        Fw::LogSeverity::SERIALIZED_SIZE +
        Fw::LogBuffer::SERIALIZED_SIZE +
        0
      ];
    } BuffUnion;

    // Define a message buffer class large enough to handle all the
    // asynchronous inputs to the component

    class ComponentIpcSerializableBuffer :
      public Fw::SerializeBufferBase
    {

      public:

        enum {
          // Max. message size = size of data + message id + port
          SERIALIZATION_SIZE =
            sizeof(BuffUnion) +
            sizeof(NATIVE_INT_TYPE) +
            sizeof(NATIVE_INT_TYPE)
        };

        NATIVE_UINT_TYPE getBuffCapacity() const {
          return sizeof(m_buff);
        }

        U8* getBuffAddr() {
          return m_buff;
        }

        const U8* getBuffAddr() const {
          return m_buff;
        }

      private:
        // Should be the max of all the input ports serialized sizes...
        U8 m_buff[SERIALIZATION_SIZE];

    };

  }

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputCmdPort *ActiveLoggerComponentBase ::
    get_CmdDisp_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_CmdDisp_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_CmdDisp_InputPort[portNum];
  }

  Fw::InputLogPort *ActiveLoggerComponentBase ::
    get_LogRecv_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_LogRecv_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_LogRecv_InputPort[portNum];
  }

  Svc::InputPingPort *ActiveLoggerComponentBase ::
    get_pingIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_pingIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_pingIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdRegPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdReg_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CmdReg_OutputPort[portNum].addCallPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdResponsePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdStatus_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CmdStatus_OutputPort[portNum].addCallPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_FatalAnnounce_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputFatalEventPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_FatalAnnounce_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_FatalAnnounce_OutputPort[portNum].addCallPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Log_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ActiveLoggerComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_LogText_OutputPort[portNum].addCallPort(port);
  }
#endif

  void ActiveLoggerComponentBase ::
    set_PktSend_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputComPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_PktSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_PktSend_OutputPort[portNum].addCallPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Time_OutputPort[portNum].addCallPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputPingPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_pingOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_pingOut_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void ActiveLoggerComponentBase ::
    set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdReg_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_CmdReg_OutputPort[portNum].registerSerialPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdStatus_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_CmdStatus_OutputPort[portNum].registerSerialPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_FatalAnnounce_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_FatalAnnounce_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_FatalAnnounce_OutputPort[portNum].registerSerialPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Log_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ActiveLoggerComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_LogText_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void ActiveLoggerComponentBase ::
    set_PktSend_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_PktSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_PktSend_OutputPort[portNum].registerSerialPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Time_OutputPort[portNum].registerSerialPort(port);
  }

  void ActiveLoggerComponentBase ::
    set_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_pingOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_pingOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Command registration
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    regCommands()
  {
    FW_ASSERT(this->m_CmdReg_OutputPort[0].isConnected());
    this->m_CmdReg_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_SET_EVENT_FILTER
    );
    this->m_CmdReg_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_SET_ID_FILTER
    );
    this->m_CmdReg_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_DUMP_FILTER_STATE
    );
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    ActiveLoggerComponentBase :: ActiveLoggerComponentBase(const char* compName) :
        Fw::ActiveComponentBase(compName) {



  }

  void ActiveLoggerComponentBase ::
    init(
        NATIVE_INT_TYPE queueDepth,
        NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    // Connect input port CmdDisp
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CmdDisp_InputPorts());
        port++
    ) {

      this->m_CmdDisp_InputPort[port].init();
      this->m_CmdDisp_InputPort[port].addCallComp(
          this,
          m_p_CmdDisp_in
      );
      this->m_CmdDisp_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdDisp_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CmdDisp_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port LogRecv
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_LogRecv_InputPorts());
        port++
    ) {

      this->m_LogRecv_InputPort[port].init();
      this->m_LogRecv_InputPort[port].addCallComp(
          this,
          m_p_LogRecv_in
      );
      this->m_LogRecv_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_LogRecv_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_LogRecv_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port pingIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_pingIn_InputPorts());
        port++
    ) {

      this->m_pingIn_InputPort[port].init();
      this->m_pingIn_InputPort[port].addCallComp(
          this,
          m_p_pingIn_in
      );
      this->m_pingIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_pingIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_pingIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CmdReg
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CmdReg_OutputPorts());
        port++
    ) {
      this->m_CmdReg_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdReg_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CmdReg_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CmdStatus
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CmdStatus_OutputPorts());
        port++
    ) {
      this->m_CmdStatus_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdStatus_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CmdStatus_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port FatalAnnounce
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_FatalAnnounce_OutputPorts());
        port++
    ) {
      this->m_FatalAnnounce_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_FatalAnnounce_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_FatalAnnounce_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Log
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_Log_OutputPorts());
        port++
    ) {
      this->m_Log_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Log_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_Log_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port LogText
#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_LogText_OutputPorts());
        port++
    ) {
      this->m_LogText_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_LogText_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_LogText_OutputPort[port].setObjName(portName);
#endif

    }
#endif

    // Initialize output port PktSend
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_PktSend_OutputPorts());
        port++
    ) {
      this->m_PktSend_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_PktSend_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_PktSend_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Time
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_Time_OutputPorts());
        port++
    ) {
      this->m_Time_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Time_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_Time_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port pingOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_pingOut_OutputPorts());
        port++
    ) {
      this->m_pingOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_pingOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_pingOut_OutputPort[port].setObjName(portName);
#endif

    }

    Os::Queue::QueueStatus qStat =
    this->createQueue(
        queueDepth,
        ComponentIpcSerializableBuffer::SERIALIZATION_SIZE
    );
    FW_ASSERT(
        Os::Queue::QUEUE_OK == qStat,
        static_cast<FwAssertArgType>(qStat)
    );

  }

  ActiveLoggerComponentBase::
    ~ActiveLoggerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    FatalAnnounce_out(
        NATIVE_INT_TYPE portNum,
        FwEventIdType Id
    )
  {
    FW_ASSERT(portNum < this->getNum_FatalAnnounce_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_FatalAnnounce_OutputPort[portNum].invoke(Id);
  }

  void ActiveLoggerComponentBase ::
    PktSend_out(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(portNum < this->getNum_PktSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_PktSend_OutputPort[portNum].invoke(data, context);
  }

  void ActiveLoggerComponentBase ::
    pingOut_out(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(portNum < this->getNum_pingOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_pingOut_OutputPort[portNum].invoke(key);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_CmdDisp_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CmdDisp_InputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_CmdReg_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CmdReg_OutputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_CmdStatus_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CmdStatus_OutputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_FatalAnnounce_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_FatalAnnounce_OutputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_Log_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Log_OutputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_LogRecv_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_LogRecv_InputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_LogText_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_LogText_OutputPort));
  }
#endif

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_PktSend_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_PktSend_OutputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_Time_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Time_OutputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_pingIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_pingIn_InputPort));
  }

  NATIVE_INT_TYPE ActiveLoggerComponentBase ::
    getNum_pingOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_pingOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool ActiveLoggerComponentBase ::
    isConnected_CmdReg_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CmdReg_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_CmdReg_OutputPort[portNum].isConnected();
  }

  bool ActiveLoggerComponentBase ::
    isConnected_CmdStatus_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CmdStatus_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_CmdStatus_OutputPort[portNum].isConnected();
  }

  bool ActiveLoggerComponentBase ::
    isConnected_FatalAnnounce_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_FatalAnnounce_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_FatalAnnounce_OutputPort[portNum].isConnected();
  }

  bool ActiveLoggerComponentBase ::
    isConnected_Log_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Log_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Log_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool ActiveLoggerComponentBase ::
    isConnected_LogText_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_LogText_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_LogText_OutputPort[portNum].isConnected();
  }
#endif

  bool ActiveLoggerComponentBase ::
    isConnected_PktSend_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_PktSend_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_PktSend_OutputPort[portNum].isConnected();
  }

  bool ActiveLoggerComponentBase ::
    isConnected_Time_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Time_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Time_OutputPort[portNum].isConnected();
  }

  bool ActiveLoggerComponentBase ::
    isConnected_pingOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_pingOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_pingOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for messages received on command input ports
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    m_p_CmdDisp_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Select base class function based on opcode
    FW_ASSERT(callComp);
    ActiveLoggerComponentBase* compPtr = static_cast<ActiveLoggerComponentBase*>(callComp);

    const U32 idBase = callComp->getIdBase();
    FW_ASSERT(opCode >= idBase, opCode, idBase);
    switch (opCode - idBase) {

      case OPCODE_SET_EVENT_FILTER: /*!< Set filter for reporting events. Events are not stored in component. */
        compPtr->SET_EVENT_FILTER_cmdHandlerBase(
            opCode,
            cmdSeq,
            args
        );
        break;

      case OPCODE_SET_ID_FILTER: /*!< Filter a particular ID */
        compPtr->SET_ID_FILTER_cmdHandlerBase(
            opCode,
            cmdSeq,
            args
        );
        break;

      case OPCODE_DUMP_FILTER_STATE: /*!< Dump the filter states via events */
        compPtr->DUMP_FILTER_STATE_cmdHandlerBase(
            opCode,
            cmdSeq,
            args
        );
        break;

      default: {
        compPtr->cmdResponse_out(
            opCode,cmdSeq,
            Fw::CmdResponse::INVALID_OPCODE
        );
        break;
      }

    }

  }

  void ActiveLoggerComponentBase ::
    cmdResponse_out(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdResponse response
    )
  {
    FW_ASSERT(this->m_CmdStatus_OutputPort[0].isConnected());
    this->m_CmdStatus_OutputPort[0].invoke(opCode,cmdSeq,response);
  }

  // ----------------------------------------------------------------------
  // Base class command functions
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    SET_EVENT_FILTER_cmdHandlerBase(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Deserialize the arguments
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Reset the buffer
    args.resetDeser();

    Svc::ActiveLogger_FilterSeverity filterLevel;
    _status = args.deserialize(filterLevel);
    if (_status != Fw::FW_SERIALIZE_OK) {
      if (this->m_CmdStatus_OutputPort[0].isConnected()) {
        this->m_CmdStatus_OutputPort[0].invoke(
            opCode,
            cmdSeq,Fw::CmdResponse::FORMAT_ERROR
        );
      }
      return;
    }

    Svc::ActiveLogger_Enabled filterEnabled;
    _status = args.deserialize(filterEnabled);
    if (_status != Fw::FW_SERIALIZE_OK) {
      if (this->m_CmdStatus_OutputPort[0].isConnected()) {
        this->m_CmdStatus_OutputPort[0].invoke(
            opCode,
            cmdSeq,Fw::CmdResponse::FORMAT_ERROR
        );
      }
      return;
    }

#if FW_CMD_CHECK_RESIDUAL
    // Make sure there was no data left over.
    // That means the argument buffer size was incorrect.
    if (args.getBuffLeft() != 0) {
      if (this->m_CmdStatus_OutputPort[0].isConnected()) {
        this->m_CmdStatus_OutputPort[0].invoke(
            opCode,
            cmdSeq,Fw::CmdResponse::FORMAT_ERROR
        );
      }
      return;
    }
#endif
    this->SET_EVENT_FILTER_cmdHandler(
        opCode,
        cmdSeq,
        filterLevel, filterEnabled
    );

  }

  void ActiveLoggerComponentBase ::
    SET_ID_FILTER_cmdHandlerBase(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Call pre-message hook
    this->SET_ID_FILTER_preMsgHook(opCode,cmdSeq);

    // Defer deserializing arguments to the message dispatcher
    // to avoid deserializing and reserializing just for IPC
    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize for IPC
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(CMD_SET_ID_FILTER));
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
        );

    // Fake port number to make message dequeue work
    NATIVE_INT_TYPE port = 0;
    _status = msg.serialize(port);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(opCode);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(cmdSeq);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(args);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  void ActiveLoggerComponentBase::
    SET_ID_FILTER_preMsgHook(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // Defaults to no-op; can be overridden
  }

  void ActiveLoggerComponentBase ::
    DUMP_FILTER_STATE_cmdHandlerBase(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Call pre-message hook
    this->DUMP_FILTER_STATE_preMsgHook(opCode,cmdSeq);

    // Defer deserializing arguments to the message dispatcher
    // to avoid deserializing and reserializing just for IPC
    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize for IPC
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(CMD_DUMP_FILTER_STATE));
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
        );

    // Fake port number to make message dequeue work
    NATIVE_INT_TYPE port = 0;
    _status = msg.serialize(port);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(opCode);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(cmdSeq);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(args);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  void ActiveLoggerComponentBase::
    DUMP_FILTER_STATE_preMsgHook(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // Defaults to no-op; can be overridden
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time ActiveLoggerComponentBase ::
    getTime()
  {
    if (this->m_Time_OutputPort[0].isConnected()) {
      Fw::Time _time;
      this->m_Time_OutputPort[0].invoke(_time);
      return _time;
    } else {
      return Fw::Time(TB_NONE,0,0);
    }
  }

  // ----------------------------------------------------------------------
  // Event handling functions
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    log_ACTIVITY_LO_SEVERITY_FILTER_STATE(
        Svc::ActiveLogger_FilterSeverity severity, bool enabled
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_SEVERITY_FILTER_STATE;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(2));
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(severity);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(enabled);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: %s filter state. %d";
#else
      const char* _formatString =
        "%s: %s filter state. %d";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      Fw::String severityStr;
      severity.toString(severityStr);
      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "SEVERITY_FILTER_STATE "
        , severityStr.toChar()
        , enabled
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logString
      );

    }
#endif

  }


  void ActiveLoggerComponentBase ::
    log_ACTIVITY_HI_ID_FILTER_ENABLED(
        U32 ID
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_ID_FILTER_ENABLED;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(1));
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(ID);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: ID %u is filtered.";
#else
      const char* _formatString =
        "%s: ID %u is filtered.";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "ID_FILTER_ENABLED "
        , ID
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logString
      );

    }
#endif

  }


  void ActiveLoggerComponentBase ::
    log_WARNING_LO_ID_FILTER_LIST_FULL(
        U32 ID
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_ID_FILTER_LIST_FULL;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(1));
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(ID);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: ID filter list is full. Cannot filter %u .";
#else
      const char* _formatString =
        "%s: ID filter list is full. Cannot filter %u .";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "ID_FILTER_LIST_FULL "
        , ID
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_LO,
          _logString
      );

    }
#endif

  }


  void ActiveLoggerComponentBase ::
    log_ACTIVITY_HI_ID_FILTER_REMOVED(
        U32 ID
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_ID_FILTER_REMOVED;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(1));
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(ID);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: ID filter ID %u removed.";
#else
      const char* _formatString =
        "%s: ID filter ID %u removed.";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "ID_FILTER_REMOVED "
        , ID
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logString
      );

    }
#endif

  }


  void ActiveLoggerComponentBase ::
    log_WARNING_LO_ID_FILTER_NOT_FOUND(
        U32 ID
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_ID_FILTER_NOT_FOUND;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(1));
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(ID);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: ID filter ID %u not found.";
#else
      const char* _formatString =
        "%s: ID filter ID %u not found.";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "ID_FILTER_NOT_FOUND "
        , ID
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_LO,
          _logString
      );

    }
#endif

  }


  // ----------------------------------------------------------------------
  // Invocation functions for interfaces
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase::
    loqQueue_internalInterfaceInvoke(
        FwEventIdType id, const Fw::Time& timeTag, const Fw::LogSeverity& severity, const Fw::LogBuffer& args
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(INT_IF_LOQQUEUE));
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(0));
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(id);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));
    _status = msg.serialize(timeTag);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));
    _status = msg.serialize(severity);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));
    _status = msg.serialize(args);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 1,_block);
    if (qStatus == Os::Queue::QUEUE_FULL) {
        this->incNumMsgDropped();
        return;
    }
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    m_p_LogRecv_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::LogBuffer &args
    )
  {
    FW_ASSERT(callComp);
    ActiveLoggerComponentBase* compPtr = static_cast<ActiveLoggerComponentBase*>(callComp);
    compPtr->LogRecv_handlerBase(portNum, id, timeTag, severity, args);
  }

  void ActiveLoggerComponentBase ::
    m_p_pingIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(callComp);
    ActiveLoggerComponentBase* compPtr = static_cast<ActiveLoggerComponentBase*>(callComp);
    compPtr->pingIn_handlerBase(portNum, key);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    LogRecv_handlerBase(
        NATIVE_INT_TYPE portNum,
        FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::LogBuffer &args
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_LogRecv_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->LogRecv_handler(portNum, id, timeTag, severity, args);

  }

  void ActiveLoggerComponentBase ::
    pingIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_pingIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    pingIn_preMsgHook(
        portNum,
        key
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(PINGIN_PING)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // Serialize argument key
    _status = msg.serialize(key);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );


    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  // ----------------------------------------------------------------------
  // Pre-message hooks for async input ports
  // ----------------------------------------------------------------------

  void ActiveLoggerComponentBase ::
    pingIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    // Default: no-op
  }

  // ----------------------------------------------------------------------
  // Message dispatch method for active and queued components. Called
  // by active component thread or implementation code for queued components
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus ActiveLoggerComponentBase ::
    doDispatch()
  {
    ComponentIpcSerializableBuffer msg;
    NATIVE_INT_TYPE priority = 0;

    Os::Queue::QueueStatus msgStatus = this->m_queue.receive(msg,priority,Os::Queue::QUEUE_BLOCKING);
    FW_ASSERT(
        msgStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(msgStatus)
    );

    // Reset to beginning of buffer
    msg.resetDeser();

    NATIVE_INT_TYPE desMsg = 0;
    Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
    );

    MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

    if (msgType == ACTIVELOGGER_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    NATIVE_INT_TYPE portNum = 0;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
    );

    switch (msgType) {

      // Handle async input port pingIn
      case PINGIN_PING: {

        // Deserialize argument key
        U32 key;
        deserStatus = msg.deserialize(key);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->pingIn_handler(
            portNum,
            key
        );

        break;

      }

      // Handle command SET_ID_FILTER
      case CMD_SET_ID_FILTER: {
        // Deserialize opcode
        FwOpcodeType opCode = 0;
        deserStatus = msg.deserialize(opCode);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize command sequence
        U32 cmdSeq = 0;
        deserStatus = msg.deserialize(cmdSeq);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize command argument buffer
        Fw::CmdArgBuffer args;
        deserStatus = msg.deserialize(args);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Reset buffer
        args.resetDeser();

        // Deserialize argument ID
        U32 ID;
        deserStatus = args.deserialize(ID);
        if (deserStatus != Fw::FW_SERIALIZE_OK) {
          if (this->m_CmdStatus_OutputPort[0].isConnected()) {
            this->cmdResponse_out(
                opCode,
                cmdSeq,
                Fw::CmdResponse::FORMAT_ERROR
            );
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }

        // Deserialize argument idFilterEnabled
        Svc::ActiveLogger_Enabled idFilterEnabled;
        deserStatus = args.deserialize(idFilterEnabled);
        if (deserStatus != Fw::FW_SERIALIZE_OK) {
          if (this->m_CmdStatus_OutputPort[0].isConnected()) {
            this->cmdResponse_out(
                opCode,
                cmdSeq,
                Fw::CmdResponse::FORMAT_ERROR
            );
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }

        // Make sure there was no data left over.
        // That means the argument buffer size was incorrect.
#if FW_CMD_CHECK_RESIDUAL
        if (args.getBuffLeft() != 0) {
          if (this->m_CmdStatus_OutputPort[0].isConnected()) {
            this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::FORMAT_ERROR);
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }
#endif
        // Call handler function
        this->SET_ID_FILTER_cmdHandler(
            opCode,
            cmdSeq,
            ID, idFilterEnabled
        );

        break;

      }

      // Handle command DUMP_FILTER_STATE
      case CMD_DUMP_FILTER_STATE: {
        // Deserialize opcode
        FwOpcodeType opCode = 0;
        deserStatus = msg.deserialize(opCode);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize command sequence
        U32 cmdSeq = 0;
        deserStatus = msg.deserialize(cmdSeq);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize command argument buffer
        Fw::CmdArgBuffer args;
        deserStatus = msg.deserialize(args);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Reset buffer
        args.resetDeser();

        // Make sure there was no data left over.
        // That means the argument buffer size was incorrect.
#if FW_CMD_CHECK_RESIDUAL
        if (args.getBuffLeft() != 0) {
          if (this->m_CmdStatus_OutputPort[0].isConnected()) {
            this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::FORMAT_ERROR);
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }
#endif
        // Call handler function
        this->DUMP_FILTER_STATE_cmdHandler(opCode, cmdSeq);

        break;

      }

      // Handle internal interface loqQueue
      case INT_IF_LOQQUEUE: {

        FwEventIdType id;
        deserStatus = msg.deserialize(id);

        // Internal interfaces should always deserialize
        FW_ASSERT(
            Fw::FW_SERIALIZE_OK == deserStatus,
            static_cast<FwAssertArgType>(deserStatus)
        );

        Fw::Time timeTag;
        deserStatus = msg.deserialize(timeTag);

        // Internal interfaces should always deserialize
        FW_ASSERT(
            Fw::FW_SERIALIZE_OK == deserStatus,
            static_cast<FwAssertArgType>(deserStatus)
        );

        Fw::LogSeverity severity;
        deserStatus = msg.deserialize(severity);

        // Internal interfaces should always deserialize
        FW_ASSERT(
            Fw::FW_SERIALIZE_OK == deserStatus,
            static_cast<FwAssertArgType>(deserStatus)
        );

        Fw::LogBuffer args;
        deserStatus = msg.deserialize(args);

        // Internal interfaces should always deserialize
        FW_ASSERT(
            Fw::FW_SERIALIZE_OK == deserStatus,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Make sure there was no data left over.
        // That means the buffer size was incorrect.
        FW_ASSERT(
            msg.getBuffLeft() == 0,
            static_cast<FwAssertArgType>(msg.getBuffLeft())
        );

        // Call handler function
        this->loqQueue_internalInterfaceHandler(id, timeTag, severity, args);

        break;

      }

      default:
        return MSG_DISPATCH_ERROR;

    }

    return MSG_DISPATCH_OK;

  }

} // end namespace Svc
