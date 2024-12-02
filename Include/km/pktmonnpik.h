/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Abstract:

    Public NPI (NMR) interface for network packet monitoring

Environment:

    Kernel mode

--*/

#ifdef _MSC_VER
#pragma once
#endif //_MSC_VER

#ifndef _PKTMONNPIK_H_ // include guard for 3rd party interop
#define _PKTMONNPIK_H_

#include <PktMonDefk.h>
#include <netiodef.h>

#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)

#ifdef __cplusplus
extern "C" {
#endif

//
// Packet payload type
//
typedef enum _PKTMON_PACKET_TYPE
{
    PktMonPayload_Unknown,
    PktMonPayload_Ethernet,
    PktMonPayload_WiFi,
    PktMonPayload_IP,
    PktMonPayload_HTTP,
    PktMonPayload_TCP,
    PktMonPayload_UDP,
    PktMonPayload_ARP,
    PktMonPayload_ICMP,
    PktMonPayload_ESP,
    PktMonPayload_AH,
    PktMonPayload_L4Payload
} PKTMON_PACKET_TYPE;

//
// Packet direction.
// Each component reports packets in two directions only (IN or OUT).
// A component may assign more suitable labels for packet directions
// from PKTMON_DIRECTION_TAG enum.
// Labels are being assigned during component or edge registration.
//
typedef enum _PKTMON_DIRECTION
{
    PktMonDir_In = 1,
    PktMonDir_Out,
} PKTMON_DIRECTION;

//
// Packet context Id
//
typedef enum _PKTMON_PACKET_CONTEXT_ID
{
    PktMonPacketContext_Unspecified,
    PktMonPacketContext_HttpRequestId,

} PKTMON_PACKET_CONTEXT_ID;

//
// Common header for version control
//
typedef struct _PKTMON_HEADER
{
    USHORT Size;
    USHORT Version;

} PKTMON_HEADER;

#ifndef ADDRESS_FAMILY
typedef USHORT ADDRESS_FAMILY;
#endif

//
// Packet header information
//
typedef struct _PKTMON_PACKET_HEADER_INFORMATION
{
    SOCKADDR_INET SockAddrLocal;
    SOCKADDR_INET SockAddrRemote;

    UCHAR IpProtocol;

    union _PKTMON_TRANSPORT_PROTOCOL
    {
        struct _PKTMON_TRANSPORT_UDP_PROTOCOL
        {
            USHORT PortLocal;
            USHORT PortRemote;
        } Udp;

        struct _PKTMON_TRANSPORT_TCP_PROTOCOL
        {
            USHORT PortLocal;
            USHORT PortRemote;
            UCHAR  Flags;
        } Tcp;

        struct _PKTMON_TRANSPORT_ICMP_PROTOCOL
        {
            UCHAR Type;
            UCHAR Code;
        } Icmp;

    } Transport;

} PKTMON_PACKET_HEADER_INFORMATION;

//
// Packet context
// Used as parameter for PktMonPacketLog() and PktMonPacketDrop()
//
typedef struct _PKTMON_PACKET_CONTEXT_IN
{
    PKTMON_HEADER Header;

    INT Id;
    PVOID Value;
    USHORT Size;

} PKTMON_PACKET_CONTEXT_IN;

#if (NTDDI_VERSION >= NTDDI_WIN11_ZN)

#ifndef USER_MODE
typedef struct _PKTMON_NETEVT_DISPATCH_HEADER
{
    UINT16 Version;
    SIZE_T Size;

} PKTMON_NETEVT_DISPATCH_HEADER;

//
// Packet Monitor NMR provider dispatch table
//
typedef struct _PKTMON_NETEVT_PROVIDER_DISPATCH
{
    PKTMON_NETEVT_DISPATCH_HEADER Header;
    UINT32 HandlerCount;
    UINT64* Handlers;

} PKTMON_NETEVT_PROVIDER_DISPATCH;

//
// Packet Monitor NetEvt NMR client dispatch table
//
typedef struct _PKTMON_NETEVT_CLIENT_DISPATCH
{
    PKTMON_NETEVT_DISPATCH_HEADER Header;
    UINT32 HandlerCount;
    UINT64* Handlers;

} PKTMON_NETEVT_CLIENT_DISPATCH;

//
// Packet monitor NetEvt NMR client context
//
typedef struct _PKTMON_NETEVT_CLIENT_CONTEXT
{
    HANDLE  NmrClientHandle;

    PEX_RUNDOWN_REF_CACHE_AWARE RundownRef;

    BOOLEAN Enabled;

    //
    // Provider dispatch
    //
    PVOID ProviderContext;
    PKTMON_NETEVT_PROVIDER_DISPATCH *ProviderDispatch;

} PKTMON_NETEVT_CLIENT_CONTEXT;
#endif // USER_MODE

#pragma pack(push, 1)

//
// Packet descriptor used for event streaming
//
typedef struct _PKTMON_EVT_STREAM_PACKET_DESCRIPTOR
{
    ULONG PacketOriginalLength;
    ULONG PacketLoggedLength;
    ULONG PacketMetaDataLength;
} PKTMON_EVT_STREAM_PACKET_DESCRIPTOR;

//
// Metadata information used for event streaming
//
typedef struct _PKTMON_EVT_STREAM_METADATA
{
    UINT64  PktGroupId;
    UINT16  PktCount;
    UINT16  AppearanceCount;
    UINT16  DirectionName;
    UINT16  PacketType;
    UINT16  ComponentId;
    UINT16  EdgeId;
    UINT16  FilterId;
    UINT32  DropReason;
    UINT32  DropLocation;
    UINT16  ProcNum;
    LARGE_INTEGER TimeStamp;
} PKTMON_EVT_STREAM_METADATA;

//
// Packet header used for event streaming
//
typedef struct _PKTMON_EVT_STREAM_PACKET_HEADER
{
    UCHAR EventId;
    PKTMON_EVT_STREAM_PACKET_DESCRIPTOR PacketDescriptor;
    PKTMON_EVT_STREAM_METADATA Metadata;
} PKTMON_EVT_STREAM_PACKET_HEADER;

#pragma pack(pop)

//
// Start and end pointer of the buffer containing the dropped packet information
//
typedef struct _PKTMON_NETEVT_CLIENT_REPORT_PACKET_DROP_OUT
{
    PKTMON_EVT_STREAM_PACKET_HEADER* BufferStart;
    UCHAR* BufferEnd;
} PKTMON_NETEVT_CLIENT_REPORT_PACKET_DROP_OUT;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // (NTDDI_VERSION >= NTDDI_WIN11_ZN)

#endif // (NTDDI_VERSION >= NTDDI_WIN10_RS5)

#endif // _PKTMONNPIK_H_

