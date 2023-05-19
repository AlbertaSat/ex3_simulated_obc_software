

#ifndef BurnwireTesterPackets_header_h
#define BurnwireTesterPackets_header_h

#include <Svc/TlmPacketizer/TlmPacketizerTypes.hpp>

namespace BurnwireTester {

    // set of packets to send
    extern const Svc::TlmPacketizerPacketList BurnwireTesterPacketsPkts;
    // set of channels to ignore
    extern const Svc::TlmPacketizerPacket BurnwireTesterPacketsIgnore;

}

#endif // BurnwireTesterPackets_header_h

