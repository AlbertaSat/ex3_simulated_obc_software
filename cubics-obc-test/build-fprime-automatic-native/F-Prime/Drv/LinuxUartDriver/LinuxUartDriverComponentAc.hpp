// ======================================================================
// \title  LinuxUartDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for LinuxUartDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef DRV_LINUXUARTDRIVER_COMP_HPP_
#define DRV_LINUXUARTDRIVER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Drv/ByteStreamDriverModel/RecvStatusEnumAc.hpp>
#include <Drv/ByteStreamDriverModel/SendStatusEnumAc.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamReadyPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamRecvPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamSendPortAc.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>

namespace Drv {

  //! \class LinuxUartDriverComponentBase
  //! \brief Auto-generated base for LinuxUartDriver component
  //!
  class LinuxUartDriverComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class LinuxUartDriverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return send[portNum]
    //!
    Drv::InputByteStreamSendPort* get_send_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

    //! Connect port to allocate[portNum]
    //!
    void set_allocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferGetPort *port /*!< The port*/
    );

    //! Connect port to deallocate[portNum]
    //!
    void set_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to ready[portNum]
    //!
    void set_ready_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamReadyPort *port /*!< The port*/
    );

    //! Connect port to recv[portNum]
    //!
    void set_recv_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamRecvPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to allocate[portNum]
    //!
    void set_allocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to deallocate[portNum]
    //!
    void set_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to ready[portNum]
    //!
    void set_ready_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to recv[portNum]
    //!
    void set_recv_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a LinuxUartDriverComponentBase object
    //!
    LinuxUartDriverComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a LinuxUartDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a LinuxUartDriverComponentBase object
    //!
    virtual ~LinuxUartDriverComponentBase();

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

    //! Handler for input port send
    //
    virtual Drv::SendStatus send_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port send
    //!
    Drv::SendStatus send_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port allocate
    //!
    Fw::Buffer allocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Invoke output port deallocate
    //!
    void deallocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port ready
    //!
    void ready_out(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Invoke output port recv
    //!
    void recv_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of send input ports
    //!
    //! \return The number of send input ports
    //!
    NATIVE_INT_TYPE getNum_send_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_SEND_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of Log output ports
    //!
    //! \return The number of Log output ports
    //!
    NATIVE_INT_TYPE getNum_Log_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts();
#endif

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts();

    //! Get the number of Tlm output ports
    //!
    //! \return The number of Tlm output ports
    //!
    NATIVE_INT_TYPE getNum_Tlm_OutputPorts();

    //! Get the number of allocate output ports
    //!
    //! \return The number of allocate output ports
    //!
    NATIVE_INT_TYPE getNum_allocate_OutputPorts();

    //! Get the number of deallocate output ports
    //!
    //! \return The number of deallocate output ports
    //!
    NATIVE_INT_TYPE getNum_deallocate_OutputPorts();

    //! Get the number of ready output ports
    //!
    //! \return The number of ready output ports
    //!
    NATIVE_INT_TYPE getNum_ready_OutputPorts();

    //! Get the number of recv output ports
    //!
    //! \return The number of recv output ports
    //!
    NATIVE_INT_TYPE getNum_recv_OutputPorts();


    enum {
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
       NUM_ALLOCATE_OUTPUT_PORTS = 1,
       NUM_DEALLOCATE_OUTPUT_PORTS = 1,
       NUM_READY_OUTPUT_PORTS = 1,
       NUM_RECV_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port Log is connected
    //!
    //! \return Whether port Log is connected
    //!
    bool isConnected_Log_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Tlm is connected
    //!
    //! \return Whether port Tlm is connected
    //!
    bool isConnected_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port allocate is connected
    //!
    //! \return Whether port allocate is connected
    //!
    bool isConnected_allocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port deallocate is connected
    //!
    //! \return Whether port deallocate is connected
    //!
    bool isConnected_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port ready is connected
    //!
    //! \return Whether port ready is connected
    //!
    bool isConnected_ready_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port recv is connected
    //!
    //! \return Whether port recv is connected
    //!
    bool isConnected_recv_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_OPENERROR = 0x0, /* UART open error */
      EVENTID_CONFIGERROR = 0x1, /* UART config error */
      EVENTID_WRITEERROR = 0x2, /* UART write error */
      EVENTID_READERROR = 0x3, /* UART read error */
      EVENTID_PORTOPENED = 0x4, /* UART port opened event */
      EVENTID_NOBUFFERS = 0x5, /* UART ran out of buffers */
      EVENTID_BUFFERTOOSMALL = 0x6, /* UART ran out of buffers */
    };

    // ----------------------------------------------------------------------
    // Event Throttle values - sets initial value of countdown variable
    // ----------------------------------------------------------------------

    enum {
      EVENTID_WRITEERROR_THROTTLE = 5, /*!< Throttle reset count for WriteError*/
      EVENTID_READERROR_THROTTLE = 5, /*!< Throttle reset count for ReadError*/
      EVENTID_NOBUFFERS_THROTTLE = 20, /*!< Throttle reset count for NoBuffers*/
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event OpenError
    //!
    /* UART open error */
    void log_WARNING_HI_OpenError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error, /*!< The error code*/
        const Fw::LogStringArg& name /*!< error string*/
    );


    //! Log event ConfigError
    //!
    /* UART config error */
    void log_WARNING_HI_ConfigError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error /*!< The error code*/
    );


    //! Log event WriteError
    //!
    /* UART write error */
    void log_WARNING_HI_WriteError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error /*!< The error code*/
    );

    // reset throttle value for WriteError
    void log_WARNING_HI_WriteError_ThrottleClear();

    //! Log event ReadError
    //!
    /* UART read error */
    void log_WARNING_HI_ReadError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error /*!< The error code*/
    );

    // reset throttle value for ReadError
    void log_WARNING_HI_ReadError_ThrottleClear();

    //! Log event PortOpened
    //!
    /* UART port opened event */
    void log_ACTIVITY_HI_PortOpened(
        const Fw::LogStringArg& device /*!< The device*/
    );


    //! Log event NoBuffers
    //!
    /* UART ran out of buffers */
    void log_WARNING_HI_NoBuffers(
        const Fw::LogStringArg& device /*!< The device*/
    );

    // reset throttle value for NoBuffers
    void log_WARNING_HI_NoBuffers_ThrottleClear();

    //! Log event BufferTooSmall
    //!
    /* UART ran out of buffers */
    void log_WARNING_HI_BufferTooSmall(
        const Fw::LogStringArg& device, /*!< The device*/
        U32 size, /*!< The provided buffer size*/
        U32 needed /*!< The buffer size needed*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_BYTESSENT = 0x0, //!< Channel ID for BytesSent
      CHANNELID_BYTESRECV = 0x1, //!< Channel ID for BytesRecv
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel BytesSent
    //!
    /* Bytes Sent */
    void tlmWrite_BytesSent(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel BytesRecv
    //!
    /* Bytes Received */
    void tlmWrite_BytesRecv(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //! Get the time
    //!
    //! \return The current time
    //!
    Fw::Time getTime();



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port send
    //!
    Drv::InputByteStreamSendPort m_send_InputPort[NUM_SEND_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

    //! Output port allocate
    //!
    Fw::OutputBufferGetPort m_allocate_OutputPort[NUM_ALLOCATE_OUTPUT_PORTS];

    //! Output port deallocate
    //!
    Fw::OutputBufferSendPort m_deallocate_OutputPort[NUM_DEALLOCATE_OUTPUT_PORTS];

    //! Output port ready
    //!
    Drv::OutputByteStreamReadyPort m_ready_OutputPort[NUM_READY_OUTPUT_PORTS];

    //! Output port recv
    //!
    Drv::OutputByteStreamRecvPort m_recv_OutputPort[NUM_RECV_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port send
    //!
    static Drv::SendStatus m_p_send_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------
    NATIVE_UINT_TYPE m_WriteErrorThrottle; //!< throttle for WriteError
    NATIVE_UINT_TYPE m_ReadErrorThrottle; //!< throttle for ReadError
    NATIVE_UINT_TYPE m_NoBuffersThrottle; //!< throttle for NoBuffers

  };

} // end namespace Drv
#endif
