// Copyright (C) Microsoft Corporation. All rights reserved.

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _NETADAPTERTXDEMUX_2_5_H_
#define _NETADAPTERTXDEMUX_2_5_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START


typedef enum _NET_ADAPTER_TX_DEMUX_TYPE {
    NetAdapterTxDemuxType8021p = 1,
} NET_ADAPTER_TX_DEMUX_TYPE;




typedef struct _NET_ADAPTER_TX_DEMUX
{
    ULONG
        Size;

    NET_ADAPTER_TX_DEMUX_TYPE
        Type;

    UINT8
        Range;

} NET_ADAPTER_TX_DEMUX;

inline
void
NET_ADAPTER_TX_8021P_DEMUX_INIT(
    _Out_ NET_ADAPTER_TX_DEMUX * Demux
)
{
    RtlZeroMemory(Demux, sizeof(*Demux));
    Demux->Size = sizeof(*Demux);
    Demux->Type = NetAdapterTxDemuxType8021p;
    Demux->Range = 8;
}


//
// NET Function: NetAdapterInitAddTxDemux
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
void
(NTAPI *PFN_NETADAPTERINITADDTXDEMUX)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER_INIT* AdapterInit,
    _In_
    CONST NET_ADAPTER_TX_DEMUX* Demux
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
void
NetAdapterInitAddTxDemux(
    _In_
    NETADAPTER_INIT* AdapterInit,
    _In_
    CONST NET_ADAPTER_TX_DEMUX* Demux
    )
{
    ((PFN_NETADAPTERINITADDTXDEMUX) NetFunctions[NetAdapterInitAddTxDemuxTableIndex])(NetDriverGlobals, AdapterInit, Demux);
}



WDF_EXTERN_C_END

#endif // _NETADAPTERTXDEMUX_2_5_H_

