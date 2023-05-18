// ======================================================================
// \title  SpiReadWritePortAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for SpiReadWrite port
// ======================================================================

#include "F-Prime/Drv/SpiDriverPorts/SpiReadWritePortAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

namespace Drv {

  namespace {

    // ----------------------------------------------------------------------
    // Port buffer class
    // ----------------------------------------------------------------------

    class SpiReadWritePortBuffer : public Fw::SerializeBufferBase {

      public:

        NATIVE_UINT_TYPE getBuffCapacity() const {
          return InputSpiReadWritePort::SERIALIZED_SIZE;
        }

        U8* getBuffAddr() {
          return m_buff;
        }

        const U8* getBuffAddr() const {
          return m_buff;
        }

      private:

        U8 m_buff[InputSpiReadWritePort::SERIALIZED_SIZE];

    };

  }

  // ----------------------------------------------------------------------
  // Input Port Member functions
  // ----------------------------------------------------------------------

  InputSpiReadWritePort ::
    InputSpiReadWritePort() :
      Fw::InputPortBase(),
      m_func(nullptr)
  {

  }

  void InputSpiReadWritePort ::
    init()
  {
    Fw::InputPortBase::init();
  }

  void InputSpiReadWritePort ::
    addCallComp(
        Fw::PassiveComponentBase* callComp,
        CompFuncPtr funcPtr
    )
  {
    FW_ASSERT(callComp != nullptr);
    FW_ASSERT(funcPtr != nullptr);

    this->m_comp = callComp;
    this->m_func = funcPtr;
    this->m_connObj = callComp;
  }

  void InputSpiReadWritePort ::
    invoke(
        Fw::Buffer& writeBuffer,
        Fw::Buffer& readBuffer
    )
  {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

    FW_ASSERT(this->m_comp != nullptr);
    FW_ASSERT(this->m_func != nullptr);

    return this->m_func(this->m_comp, this->m_portNum, writeBuffer, readBuffer);
  }

#if FW_PORT_SERIALIZATION == 1

  Fw::SerializeStatus InputSpiReadWritePort ::
    invokeSerial(Fw::SerializeBufferBase& _buffer)
  {
    Fw::SerializeStatus _status;

#if FW_PORT_SERIALIZATION == 1
    this->trace();
#endif

    FW_ASSERT(this->m_comp != nullptr);
    FW_ASSERT(this->m_func != nullptr);

    Fw::Buffer writeBuffer;
    _status = _buffer.deserialize(writeBuffer);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    Fw::Buffer readBuffer;
    _status = _buffer.deserialize(readBuffer);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    this->m_func(this->m_comp, this->m_portNum, writeBuffer, readBuffer);

    return Fw::FW_SERIALIZE_OK;
  }

#endif

  // ----------------------------------------------------------------------
  // Output Port Member functions
  // ----------------------------------------------------------------------

  OutputSpiReadWritePort ::
    OutputSpiReadWritePort() :
      Fw::OutputPortBase(),
      m_port(nullptr)
  {

  }

  void OutputSpiReadWritePort ::
    init()
  {
    Fw::OutputPortBase::init();
  }

  void OutputSpiReadWritePort ::
    addCallPort(InputSpiReadWritePort* callPort)
  {
    FW_ASSERT(callPort != nullptr);

    this->m_port = callPort;
    this->m_connObj = callPort;

#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
  }

  void OutputSpiReadWritePort ::
    invoke(
        Fw::Buffer& writeBuffer,
        Fw::Buffer& readBuffer
    )
  {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT((this->m_port != nullptr) || (this->m_serPort != nullptr));

    if (this->m_port != nullptr) {
      this->m_port->invoke(writeBuffer, readBuffer);
    }
    else {
      Fw::SerializeStatus _status;
      SpiReadWritePortBuffer _buffer;

      _status = _buffer.serialize(writeBuffer);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = _buffer.serialize(readBuffer);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = this->m_serPort->invokeSerial(_buffer);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));
    }
#else
    FW_ASSERT(this->m_port != nullptr);
    this->m_port->invoke(writeBuffer, readBuffer);
#endif
  }

}
