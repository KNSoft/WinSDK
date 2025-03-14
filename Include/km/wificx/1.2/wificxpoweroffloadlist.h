// Copyright (C) Microsoft Corporation. All rights reserved.

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _WIFICXPOWEROFFLOADLIST_H_
#define _WIFICXPOWEROFFLOADLIST_H_

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




typedef struct _WIFI_POWER_OFFLOAD_LIST
{
    ULONG Size;
    void * Reserved[4];
} WIFI_POWER_OFFLOAD_LIST;

inline
void
WIFI_POWER_OFFLOAD_LIST_INIT(
    _Out_ WIFI_POWER_OFFLOAD_LIST * List
)
{
    RtlZeroMemory(List, sizeof(WIFI_POWER_OFFLOAD_LIST));
    List->Size = WIFI_STRUCTURE_SIZE(WIFI_POWER_OFFLOAD_LIST);
}

//
// WIFI Function: WifiDeviceGetPowerOffloadList
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
void
(NTAPI *PFN_WIFIDEVICEGETPOWEROFFLOADLIST)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _Inout_
    WIFI_POWER_OFFLOAD_LIST* List
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
void
WifiDeviceGetPowerOffloadList(
    _In_
    WDFDEVICE Device,
    _Inout_
    WIFI_POWER_OFFLOAD_LIST* List
    )
{
    ((PFN_WIFIDEVICEGETPOWEROFFLOADLIST) WifiFunctions[WifiDeviceGetPowerOffloadListTableIndex])(WifiDriverGlobals, Device, List);
}

//
// WIFI Function: WifiPowerOffloadListGetCount
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
SIZE_T
(NTAPI *PFN_WIFIPOWEROFFLOADLISTGETCOUNT)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    CONST WIFI_POWER_OFFLOAD_LIST* List
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
SIZE_T
WifiPowerOffloadListGetCount(
    _In_
    CONST WIFI_POWER_OFFLOAD_LIST* List
    )
{
    return ((PFN_WIFIPOWEROFFLOADLISTGETCOUNT) WifiFunctions[WifiPowerOffloadListGetCountTableIndex])(WifiDriverGlobals, List);
}

//
// WIFI Function: WifiPowerOffloadListGetElement
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
WIFIPOWEROFFLOAD
(NTAPI *PFN_WIFIPOWEROFFLOADLISTGETELEMENT)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    CONST WIFI_POWER_OFFLOAD_LIST* List,
    _In_
    SIZE_T Index
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
WIFIPOWEROFFLOAD
WifiPowerOffloadListGetElement(
    _In_
    CONST WIFI_POWER_OFFLOAD_LIST* List,
    _In_
    SIZE_T Index
    )
{
    return ((PFN_WIFIPOWEROFFLOADLISTGETELEMENT) WifiFunctions[WifiPowerOffloadListGetElementTableIndex])(WifiDriverGlobals, List, Index);
}



WDF_EXTERN_C_END

#endif // _WIFICXPOWEROFFLOADLIST_H_

