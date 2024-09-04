/*++

Copyright (C) Microsoft Corporation. All rights reserved.

Module Name:

    NetDatapathDescriptor.h

Abstract:

    This module defines the NET_DATAPATH_DESCRIPTOR type.

Notes:

    Do not include this header directly. This is to be used together with NetAdapterCx.

    NetAdapterCx is preview only, any files related to it may be substantially modified
    or removed in future releases of Windows.

 --*/

#pragma once

#if (defined(NET_ADAPTER_CX_1_0) || defined(NET_ADAPTER_CX_1_1) || defined(NET_ADAPTER_CX_1_2) || defined(NET_ADAPTER_CX_1_3))
#    if (NET_ADAPTER_CX_1_0 != 1 && NET_ADAPTER_CX_1_1 != 1 && NET_ADAPTER_CX_1_2 != 1 && NET_ADAPTER_CX_1_3 != 1)
#        error NetDatapathDescriptor.h can be used only with NetAdapterCx
#    endif
#else
#    error Include NetAdapterCx.h
#endif // (defined(NET_ADAPTER_CX_1_0) || defined(NET_ADAPTER_CX_1_1) || defined(NET_ADAPTER_CX_1_2 || defined(NET_ADAPTER_CX_1_3))

typedef enum _NET_DATPATH_RING_BUFFER_INDEX {
    NET_DATPATH_RING_BUFFER_INDEX_PACKET,
    NET_DATPATH_RING_BUFFER_INDEX_FRAGMENT
} NET_DATPATH_RING_BUFFER_INDEX;

typedef struct _NET_DATAPATH_DESCRIPTOR
{
    PNET_RING_BUFFER RingBuffer[NET_DATPATH_RING_BUFFER_INDEX_FRAGMENT + 1];
} NET_DATAPATH_DESCRIPTOR, *PNET_DATAPATH_DESCRIPTOR;
typedef NET_DATAPATH_DESCRIPTOR const * PCNET_DATAPATH_DESCRIPTOR;


#define NET_DATAPATH_DESCRIPTOR_GET_PACKET_RING_BUFFER(rbs) \
    ((rbs)->RingBuffer[NET_DATPATH_RING_BUFFER_INDEX_PACKET])

#define NET_DATAPATH_DESCRIPTOR_GET_FRAGMENT_RING_BUFFER(rbs) \
    ((rbs)->RingBuffer[NET_DATPATH_RING_BUFFER_INDEX_FRAGMENT])

#define NET_PACKET_GET_FRAGMENT(packet, desc, index) \
    ((NET_PACKET_FRAGMENT*)NetRingBufferGetElementAtIndex(NET_DATAPATH_DESCRIPTOR_GET_FRAGMENT_RING_BUFFER(desc), ((packet)->FragmentOffset + index) & (NET_DATAPATH_DESCRIPTOR_GET_FRAGMENT_RING_BUFFER(desc)->ElementIndexMask)))

