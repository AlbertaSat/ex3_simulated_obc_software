// ======================================================================
// \title  BlockDriverComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for BlockDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Drv/BlockDriver/BlockDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Drv {

  // ----------------------------------------------------------------------
  // Anonymous namespace to prevent name collisions
  // ----------------------------------------------------------------------

  namespace {

    typedef enum {
      BLOCKDRIVER_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      BUFFERIN_DATABUFFER,
      PINGIN_PING,
      SCHED_SCHED,
      INT_IF_INTERRUPTREPORT
    } MsgTypeEnum;

    // Get the max size by doing a union of the input port serialization sizes.

    typedef union {
      BYTE port1[Drv::InputDataBufferPort::SERIALIZED_SIZE];
      BYTE port2[Svc::InputPingPort::SERIALIZED_SIZE];
      BYTE port3[Svc::InputSchedPort::SERIALIZED_SIZE];
      // Size of InterruptReport argument list
      BYTE InterruptReportIntIfSize[
        sizeof(U32) +
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

  Drv::InputDataBufferPort *BlockDriverComponentBase ::
    get_BufferIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_BufferIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_BufferIn_InputPort[portNum];
  }

  Svc::InputPingPort *BlockDriverComponentBase ::
    get_PingIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_PingIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_PingIn_InputPort[portNum];
  }

  Svc::InputSchedPort *BlockDriverComponentBase ::
    get_Sched_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_Sched_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_Sched_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void BlockDriverComponentBase ::
    set_BufferOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputDataBufferPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_BufferOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_BufferOut_OutputPort[portNum].addCallPort(port);
  }

  void BlockDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputCyclePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CycleOut_OutputPort[portNum].addCallPort(port);
  }

  void BlockDriverComponentBase ::
    set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputPingPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_PingOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_PingOut_OutputPort[portNum].addCallPort(port);
  }

  void BlockDriverComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Time_OutputPort[portNum].addCallPort(port);
  }

  void BlockDriverComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Tlm_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void BlockDriverComponentBase ::
    set_BufferOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_BufferOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_BufferOut_OutputPort[portNum].registerSerialPort(port);
  }

  void BlockDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_CycleOut_OutputPort[portNum].registerSerialPort(port);
  }

  void BlockDriverComponentBase ::
    set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_PingOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_PingOut_OutputPort[portNum].registerSerialPort(port);
  }

  void BlockDriverComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Time_OutputPort[portNum].registerSerialPort(port);
  }

  void BlockDriverComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Tlm_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    BlockDriverComponentBase :: BlockDriverComponentBase(const char* compName) :
        Fw::ActiveComponentBase(compName) {



  }

  void BlockDriverComponentBase ::
    init(
        NATIVE_INT_TYPE queueDepth,
        NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    // Connect input port BufferIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_BufferIn_InputPorts());
        port++
    ) {

      this->m_BufferIn_InputPort[port].init();
      this->m_BufferIn_InputPort[port].addCallComp(
          this,
          m_p_BufferIn_in
      );
      this->m_BufferIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_BufferIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_BufferIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port PingIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_PingIn_InputPorts());
        port++
    ) {

      this->m_PingIn_InputPort[port].init();
      this->m_PingIn_InputPort[port].addCallComp(
          this,
          m_p_PingIn_in
      );
      this->m_PingIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_PingIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_PingIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port Sched
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_Sched_InputPorts());
        port++
    ) {

      this->m_Sched_InputPort[port].init();
      this->m_Sched_InputPort[port].addCallComp(
          this,
          m_p_Sched_in
      );
      this->m_Sched_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Sched_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_Sched_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port BufferOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_BufferOut_OutputPorts());
        port++
    ) {
      this->m_BufferOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_BufferOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_BufferOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CycleOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CycleOut_OutputPorts());
        port++
    ) {
      this->m_CycleOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CycleOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CycleOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port PingOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_PingOut_OutputPorts());
        port++
    ) {
      this->m_PingOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_PingOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_PingOut_OutputPort[port].setObjName(portName);
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

    // Initialize output port Tlm
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_Tlm_OutputPorts());
        port++
    ) {
      this->m_Tlm_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Tlm_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_Tlm_OutputPort[port].setObjName(portName);
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

  BlockDriverComponentBase::
    ~BlockDriverComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void BlockDriverComponentBase ::
    BufferOut_out(
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    FW_ASSERT(portNum < this->getNum_BufferOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_BufferOut_OutputPort[portNum].invoke(buff);
  }

  void BlockDriverComponentBase ::
    CycleOut_out(
        NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CycleOut_OutputPort[portNum].invoke(cycleStart);
  }

  void BlockDriverComponentBase ::
    PingOut_out(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(portNum < this->getNum_PingOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_PingOut_OutputPort[portNum].invoke(key);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_BufferIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_BufferIn_InputPort));
  }

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_BufferOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_BufferOut_OutputPort));
  }

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_CycleOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CycleOut_OutputPort));
  }

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_PingIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_PingIn_InputPort));
  }

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_PingOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_PingOut_OutputPort));
  }

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_Sched_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Sched_InputPort));
  }

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_Time_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Time_OutputPort));
  }

  NATIVE_INT_TYPE BlockDriverComponentBase ::
    getNum_Tlm_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Tlm_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool BlockDriverComponentBase ::
    isConnected_BufferOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_BufferOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_BufferOut_OutputPort[portNum].isConnected();
  }

  bool BlockDriverComponentBase ::
    isConnected_CycleOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CycleOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_CycleOut_OutputPort[portNum].isConnected();
  }

  bool BlockDriverComponentBase ::
    isConnected_PingOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_PingOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_PingOut_OutputPort[portNum].isConnected();
  }

  bool BlockDriverComponentBase ::
    isConnected_Time_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Time_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Time_OutputPort[portNum].isConnected();
  }

  bool BlockDriverComponentBase ::
    isConnected_Tlm_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Tlm_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Tlm_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Telemetry write functions
  // ----------------------------------------------------------------------

  void BlockDriverComponentBase ::
    tlmWrite_BD_Cycles(U32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_BD_CYCLES;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time BlockDriverComponentBase ::
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
  // Invocation functions for interfaces
  // ----------------------------------------------------------------------

  void BlockDriverComponentBase::
    InterruptReport_internalInterfaceInvoke(
        U32 interrupt
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(INT_IF_INTERRUPTREPORT));
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

    _status = msg.serialize(interrupt);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 1,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void BlockDriverComponentBase ::
    m_p_BufferIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    FW_ASSERT(callComp);
    BlockDriverComponentBase* compPtr = static_cast<BlockDriverComponentBase*>(callComp);
    compPtr->BufferIn_handlerBase(portNum, buff);
  }

  void BlockDriverComponentBase ::
    m_p_PingIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(callComp);
    BlockDriverComponentBase* compPtr = static_cast<BlockDriverComponentBase*>(callComp);
    compPtr->PingIn_handlerBase(portNum, key);
  }

  void BlockDriverComponentBase ::
    m_p_Sched_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    BlockDriverComponentBase* compPtr = static_cast<BlockDriverComponentBase*>(callComp);
    compPtr->Sched_handlerBase(portNum, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void BlockDriverComponentBase ::
    BufferIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_BufferIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    BufferIn_preMsgHook(
        portNum,
        buff
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(BUFFERIN_DATABUFFER)
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

    // Serialize argument buff
    _status = msg.serialize(buff);
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

  void BlockDriverComponentBase ::
    PingIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_PingIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    PingIn_preMsgHook(
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

  void BlockDriverComponentBase ::
    Sched_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_Sched_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    Sched_preMsgHook(
        portNum,
        context
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(SCHED_SCHED)
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

    // Serialize argument context
    _status = msg.serialize(context);
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

  void BlockDriverComponentBase ::
    BufferIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        Drv::DataBuffer &buff
    )
  {
    // Default: no-op
  }

  void BlockDriverComponentBase ::
    PingIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    // Default: no-op
  }

  void BlockDriverComponentBase ::
    Sched_preMsgHook(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // Default: no-op
  }

  // ----------------------------------------------------------------------
  // Message dispatch method for active and queued components. Called
  // by active component thread or implementation code for queued components
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus BlockDriverComponentBase ::
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

    if (msgType == BLOCKDRIVER_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    NATIVE_INT_TYPE portNum = 0;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
    );

    switch (msgType) {

      // Handle async input port BufferIn
      case BUFFERIN_DATABUFFER: {

        // Deserialize argument buff
        Drv::DataBuffer buff;
        deserStatus = msg.deserialize(buff);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->BufferIn_handler(
            portNum,
            buff
        );

        break;

      }

      // Handle async input port PingIn
      case PINGIN_PING: {

        // Deserialize argument key
        U32 key;
        deserStatus = msg.deserialize(key);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->PingIn_handler(
            portNum,
            key
        );

        break;

      }

      // Handle async input port Sched
      case SCHED_SCHED: {

        // Deserialize argument context
        NATIVE_UINT_TYPE context;
        deserStatus = msg.deserialize(context);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->Sched_handler(
            portNum,
            context
        );

        break;

      }

      // Handle internal interface InterruptReport
      case INT_IF_INTERRUPTREPORT: {

        U32 interrupt;
        deserStatus = msg.deserialize(interrupt);

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
        this->InterruptReport_internalInterfaceHandler(interrupt);

        break;

      }

      default:
        return MSG_DISPATCH_ERROR;

    }

    return MSG_DISPATCH_OK;

  }

} // end namespace Drv
