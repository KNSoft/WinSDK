/*++

Copyright (C) Microsoft Corporation. All rights reserved.

Module Name:

    NetPacket.h

Abstract:

    This module defines the NET_PACKET type.

Notes:

    Do not include this header directly. This is to be used together with NetAdapterCx.

    NetAdapterCx is preview only, any files related to it may be substantially modified
    or removed in future releases of Windows.

 --*/

#pragma once

#if (defined(NET_ADAPTER_CX_1_0) || defined(NET_ADAPTER_CX_1_1) || defined(NET_ADAPTER_CX_1_2) || defined(NET_ADAPTER_CX_1_3))
#    if (NET_ADAPTER_CX_1_0 != 1 && NET_ADAPTER_CX_1_1 != 1 && NET_ADAPTER_CX_1_2 != 1 && NET_ADAPTER_CX_1_3 != 1)
#        error NetPacket.h can be used only with NetAdapterCx
#    endif
#else
#    error Include NetAdapterCx.h
#endif // (defined(NET_ADAPTER_CX_1_0) || defined(NET_ADAPTER_CX_1_1) || defined(NET_ADAPTER_CX_1_2) || defined(NET_ADAPTER_CX_1_3))

#pragma warning(push)
#pragma warning(default : 4820) // Warn if the compiler inserted padding
#pragma warning(disable:4201) // 'nonstandard extension used: nameless struct/union'

#if _WIN64
#  define NET_PACKET_FRAGMENT_ALIGNMENT_BYTES 32
#  define NET_PACKET_FRAGMENT_ALIGNMENT_SHIFT 5
#else
#  define NET_PACKET_FRAGMENT_ALIGNMENT_BYTES 8
#  define NET_PACKET_FRAGMENT_ALIGNMENT_SHIFT 3
#endif

C_ASSERT(NET_PACKET_FRAGMENT_ALIGNMENT_BYTES == (1 << NET_PACKET_FRAGMENT_ALIGNMENT_SHIFT));

#define NET_PACKET_FRAGMENT_ALIGNMENT_MASK (NET_PACKET_FRAGMENT_ALIGNMENT_BYTES - 1)

typedef LARGE_INTEGER PHYSICAL_ADDRESS;

#include <pshpack4.h>
typedef struct DECLSPEC_ALIGN(NET_PACKET_FRAGMENT_ALIGNMENT_BYTES) _NET_PACKET_FRAGMENT
{
    ULONG_PTR OsReserved_Bounced    : 1;
#ifdef _WIN64
    ULONG_PTR Reserved              : 63;
#else
    ULONG_PTR Reserved              : 31;
#endif

    union
    {
        struct
        {
            PVOID RxBufferReturnContext;
        }
        DUMMYSTRUCTNAME;

        union
        {
            MDL *Mdl;
            PHYSICAL_ADDRESS DmaLogicalAddress;
            ULONG64 AsInteger;
        } Mapping;
    }
    DUMMYUNIONNAME;

    PVOID VirtualAddress;

    UINT64 ValidLength             : 26;
    UINT64 Capacity                : 26;
    UINT64 Offset                  : 10;

    UINT64 NetPacketFragmentReserved1 : 1;
    UINT64 Scratch                 : 1;

} NET_PACKET_FRAGMENT, *PNET_PACKET_FRAGMENT;
#include <poppack.h>

#ifdef _WIN64
C_ASSERT(sizeof(NET_PACKET_FRAGMENT) == 32);
#else
C_ASSERT(sizeof(NET_PACKET_FRAGMENT) == 24);
#endif

typedef enum _NET_PACKET_LAYER2_TYPE
{
    NET_PACKET_LAYER2_TYPE_UNSPECIFIED                  = 0,
    NET_PACKET_LAYER2_TYPE_NULL                         = 1,
    NET_PACKET_LAYER2_TYPE_ETHERNET                     = 2,
} NET_PACKET_LAYER2_TYPE;

typedef enum _NET_PACKET_LAYER3_TYPE
{
    NET_PACKET_LAYER3_TYPE_UNSPECIFIED                  = 0,
    NET_PACKET_LAYER3_TYPE_IPV4_UNSPECIFIED_OPTIONS     = 1,
    NET_PACKET_LAYER3_TYPE_IPV4_WITH_OPTIONS            = 2,
    NET_PACKET_LAYER3_TYPE_IPV4_NO_OPTIONS              = 3,
    NET_PACKET_LAYER3_TYPE_IPV6_UNSPECIFIED_EXTENSIONS  = 4,
    NET_PACKET_LAYER3_TYPE_IPV6_WITH_EXTENSIONS         = 5,
    NET_PACKET_LAYER3_TYPE_IPV6_NO_EXTENSIONS           = 6,
} NET_PACKET_LAYER3_TYPE;

typedef enum _NET_PACKET_LAYER4_TYPE
{
    NET_PACKET_LAYER4_TYPE_UNSPECIFIED                  = 0,
    NET_PACKET_LAYER4_TYPE_TCP                          = 1,
    NET_PACKET_LAYER4_TYPE_UDP                          = 2,
    NET_PACKET_LAYER4_TYPE_IP_NOT_FRAGMENTED            = 3,
    NET_PACKET_LAYER4_TYPE_IP_FRAGMENT                  = 4,
} NET_PACKET_LAYER4_TYPE;

#include <pshpack1.h>
typedef struct _NET_PACKET_LAYOUT
{
    /// One of the NET_PACKET_LAYER2_TYPE values
    UINT8 Layer2Type : 4;

    /// One of the NET_PACKET_LAYER3_TYPE values
    UINT8 Layer3Type : 4;

    /// One of the NET_PACKET_LAYER4_TYPE values
    UINT8 Layer4Type : 4;
    UINT8 Reserved   : 4;

    UINT16 Layer2HeaderLength : 7;
    UINT16 Layer3HeaderLength : 9;
    UINT8  Layer4HeaderLength : 8;

} NET_PACKET_LAYOUT;
#include <poppack.h>

C_ASSERT(sizeof(NET_PACKET_LAYOUT) == 5);

typedef enum _NET_PACKET_TX_CHECKSUM_ACTION
{
    NET_PACKET_TX_CHECKSUM_PASSTHROUGH = 0,
    NET_PACKET_TX_CHECKSUM_REQUIRED = 2,
} NET_PACKET_TX_CHECKSUM_ACTION;

typedef enum _NET_PACKET_RX_CHECKSUM_EVALUATION
{
    NET_PACKET_RX_CHECKSUM_NOT_CHECKED = 0,
    NET_PACKET_RX_CHECKSUM_VALID = 1,
    NET_PACKET_RX_CHECKSUM_INVALID = 2,
} NET_PACKET_RX_CHECKSUM_EVALUATION;

typedef struct _NET_PACKET_CHECKSUM
{
    // One of NET_PACKET_TX_CHECKSUM_ACTION or NET_PACKET_RX_CHECKSUM_EVALUATION
    UINT8 Layer2 : 2;

    // One of NET_PACKET_TX_CHECKSUM_ACTION or NET_PACKET_RX_CHECKSUM_EVALUATION
    UINT8 Layer3 : 2;

    // One of NET_PACKET_TX_CHECKSUM_ACTION or NET_PACKET_RX_CHECKSUM_EVALUATION
    UINT8 Layer4 : 2;

    UINT8 Reserved : 2;

} NET_PACKET_CHECKSUM;

C_ASSERT(sizeof(NET_PACKET_CHECKSUM) == 1);


#  define NET_PACKET_ALIGNMENT_BYTES 16

typedef struct DECLSPEC_ALIGN(NET_PACKET_ALIGNMENT_BYTES) _NET_PACKET
{
    UINT32 FragmentOffset;
    UINT16 FragmentCount;

    NET_PACKET_LAYOUT Layout;

    UINT8 IgnoreThisPacket : 1;
    UINT8 AdvancedOffloadRequested : 1;
    UINT8 Completed : 1;
    UINT8 NetPacketReserved0 : 5;

    UINT32 NetPacketReserved1;
} NET_PACKET, *PNET_PACKET;

C_ASSERT(sizeof(NET_PACKET) == 16);

typedef struct _NET_PACKET_8021Q_HEADER
{
    UINT16 UserPriority : 3;
    UINT16 CanonicalFormatId : 1;
    UINT16 VlanId : 12;
} NET_PACKET_8021Q_HEADER;

C_ASSERT(sizeof(NET_PACKET_8021Q_HEADER) == 2);

typedef enum _NET_PACKET_ENCAPSULATION_TYPE
{
    NET_PACKET_ENCAPSULATION_TYPE_UNSPECIFIED           = 0,
    NET_PACKET_ENCAPSULATION_TYPE_IP_IN_IP              = 1, // RFC2003, RFC2473, RFC4213, etc
    NET_PACKET_ENCAPSULATION_TYPE_IP_IN_GRE             = 2,
    NET_PACKET_ENCAPSULATION_TYPE_NVGRE                 = 3, // RFC7637
    NET_PACKET_ENCAPSULATION_TYPE_VXLAN                 = 4,
} NET_PACKET_ENCAPSULATION_TYPE;

typedef struct _NET_PACKET_ADVANCED_OFFLOAD
{
    UINT16 InsertVlanHeader          :  1;
    UINT16 InsertNestedVlanHeader    :  1;
    UINT16 InsertEncapsulationHeader :  4;

    UINT16 Reserved1                 : 10;

    // One of NET_PACKET_ENCAPSULATION_TYPE
    NET_PACKET_LAYOUT EncapsulatedLayout;

    // One of NET_PACKET_ENCAPSULATION_TYPE
    NET_PACKET_CHECKSUM EncapsulatedChecksum;

    NET_PACKET_8021Q_HEADER VlanHeader;
    NET_PACKET_8021Q_HEADER NestedVlanHeader;

    UINT32 TcpMss : 20;  // TX: LSO
    UINT32 Reserved2 : 12;

    UINT32 VirtualSubnetId : 24; // NVGRE, VXLAN
    UINT32 Reserved3 : 8;

} NET_PACKET_ADVANCED_OFFLOAD;

C_ASSERT(sizeof(NET_PACKET_ADVANCED_OFFLOAD) == 20);

FORCEINLINE
BOOLEAN
NetPacketIsIpv4(
    const NET_PACKET * packet
)
{
    return (packet->Layout.Layer3Type == NET_PACKET_LAYER3_TYPE_IPV4_NO_OPTIONS ||
        packet->Layout.Layer3Type == NET_PACKET_LAYER3_TYPE_IPV4_UNSPECIFIED_OPTIONS ||
        packet->Layout.Layer3Type == NET_PACKET_LAYER3_TYPE_IPV4_WITH_OPTIONS);
}

FORCEINLINE
BOOLEAN
NetPacketIsIpv6(
    const NET_PACKET * packet
)
{
    return (packet->Layout.Layer3Type == NET_PACKET_LAYER3_TYPE_IPV6_NO_EXTENSIONS ||
        packet->Layout.Layer3Type == NET_PACKET_LAYER3_TYPE_IPV6_UNSPECIFIED_EXTENSIONS ||
        packet->Layout.Layer3Type == NET_PACKET_LAYER3_TYPE_IPV6_WITH_EXTENSIONS);
}

//
// Net packet extension defines
//

//
// Known packet extension constants and helper macros
//
#define NET_PACKET_EXTENSION_INVALID_OFFSET ((ULONG)0)

FORCEINLINE
PVOID
NetPacketGetExtension(
    const NET_PACKET * packet,
    size_t offset
)
{
    NT_ASSERT(offset != NET_PACKET_EXTENSION_INVALID_OFFSET);
    NT_ASSERT(offset <= 0xffff);

    return (PVOID)((UCHAR*)(packet)+offset);
}

//
// ms_PacketChecksum
//

#define NET_PACKET_EXTENSION_CHECKSUM_NAME L"ms_PacketChecksum"
#define NET_PACKET_EXTENSION_CHECKSUM_VERSION_1 1

#define NET_PACKET_EXTENSION_CHECKSUM_VERSION_1_SIZE 1

FORCEINLINE
NET_PACKET_CHECKSUM*
NetPacketGetPacketChecksum(
    const NET_PACKET * packet,
    size_t offset
)
{
    return (NET_PACKET_CHECKSUM*)NetPacketGetExtension(packet, offset);
}

//
// ms_PacketLargeSendSegmentation
//
#define NET_PACKET_EXTENSION_LSO_NAME L"ms_PacketLargeSendSegmentation"
#define NET_PACKET_EXTENSION_LSO_VERSION_1 1

typedef struct _NET_PACKET_LARGE_SEND_SEGMENTATION
{
    union {
        struct {
            ULONG Mss : 20;
            ULONG Reserved0 : 12;
        } TCP;
    } DUMMYUNIONNAME;
} NET_PACKET_LARGE_SEND_SEGMENTATION;

#define NET_PACKET_EXTENSION_LSO_VERSION_1_SIZE sizeof(ULONG)

FORCEINLINE
NET_PACKET_LARGE_SEND_SEGMENTATION*
NetPacketGetPacketLargeSendSegmentation(
    const NET_PACKET * packet,
    size_t offset
)
{
    return (NET_PACKET_LARGE_SEND_SEGMENTATION*)NetPacketGetExtension(packet, offset);
}

//
// ms_PacketReceiveSegmentCoalescence
//
#define NET_PACKET_EXTENSION_RSC_NAME L"ms_PacketReceiveSegmentCoalescence"
#define NET_PACKET_EXTENSION_RSC_VERSION_1 1

#include <pshpack2.h>
typedef struct _NET_PACKET_RECEIVE_SEGMENT_COALESCENCE
{
    USHORT CoalescedSegmentCount;
    union {
        struct {
            UINT16 RscTcpTimestampDelta;
        } TCP;
    } DUMMYUNIONNAME;
} NET_PACKET_RECEIVE_SEGMENT_COALESCENCE;
#include <poppack.h>

#define NET_PACKET_EXTENSION_RSC_VERSION_1_SIZE (sizeof(USHORT) + sizeof(UINT16))

FORCEINLINE
NET_PACKET_RECEIVE_SEGMENT_COALESCENCE*
NetPacketGetPacketReceiveSegmentCoalescence(
    const NET_PACKET * packet,
    size_t offset
)
{
    return (NET_PACKET_RECEIVE_SEGMENT_COALESCENCE*)NetPacketGetExtension(packet, offset);
}

#pragma warning(pop)
