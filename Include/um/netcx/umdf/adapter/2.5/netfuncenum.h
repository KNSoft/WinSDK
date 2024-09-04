/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name: NetFuncEnum.h

Abstract:
    Generated an enum of all WDF API functions

Environment:
    kernel mode only

    Warning: manual changes to this file will be lost.
--*/

#ifndef _NETFUNCENUM_2_5_H_
#define _NETFUNCENUM_2_5_H_

extern PNET_DRIVER_GLOBALS NetDriverGlobals;


//
//
// The first version of the framework that added the support
// for client version to be higher than the framework version
//
#define NET_FIRST_VERSION_SUPPORTING_CLIENT_VERSION_HIGHER_THAN_FRAMEWORK 4

//
// The function count from the first framework which added the support.
// Any function with index less than the count is always available
//
#define NET_ALWAYS_AVAILABLE_FUNCTION_COUNT  59

//
// Validate NET_MINIMUM_VERSION_REQUIRED falls into the correct range
//
#if defined(NET_MINIMUM_VERSION_REQUIRED)

    #if NET_MINIMUM_VERSION_REQUIRED < NET_FIRST_VERSION_SUPPORTING_CLIENT_VERSION_HIGHER_THAN_FRAMEWORK
    #error NET_MINIMUM_VERSION_REQUIRED < 4
    #endif

    #if NET_MINIMUM_VERSION_REQUIRED > NET_VERSION_MINOR
    #error NET_MINIMUM_VERSION_REQUIRED > NET_VERSION_MINOR
    #endif

#endif


//
// All functions/structures are always available in following two cases:
//
//  1) Building framework itself (which defines NET_EVERYTHING_ALWAYS_AVAILABLE)
//
//  2) Traditional client drivers who are not aware of the new feature
//     "client version can be higher than framework's" and thus implies
//     NET_VERSION_MINOR == NET_MINIMUM_VERSION_REQUIRED
//
#if defined(NET_MINIMUM_VERSION_REQUIRED) && (NET_VERSION_MINOR == NET_MINIMUM_VERSION_REQUIRED)

    #if !defined(NET_EVERYTHING_ALWAYS_AVAILABLE)
    #define NET_EVERYTHING_ALWAYS_AVAILABLE
    #endif

#endif


//
// private:
//
// TRUE - the client driver's target version is higher than the current framework version.
//     IS_FUNCTION_AVAILABLE() will compare function index agains function count to determine
//     whether the function is usable on the platform. The same for IS_FIELD_AVAILABLE().
//
// FALSE - the client driver is running on a new framework. All functions/Structures
//     from the target framework are always available
//
extern BOOLEAN NetClientVersionHigherThanFramework;

//
// private:
//
// Only valid when NetClientVersionHigherThanFramework is TRUE.
//
// Hold the count of usable functions from the framework. Used by IS_FUNCTION_AVAILABLE
// to determine whether a function is available on the platform.
//
extern ULONG   NetFunctionCount;

//
// private:
//
// Only valid when NetClientVersionHigherThanFramework is TRUE.
//
// Hold the count of usable structures from the framework. Used by IS_FIELD_AVAILABLE
// to determine whether a field in a structure is available on the platform.
//
extern ULONG   NetStructureCount;
extern WDF_STRUCT_INFO NetStructures;


//
// private:
//
// Only valid when NetClientVersionHigherThanFramework is TRUE.
//
// Hold the name of the Framework Extension.
//
extern PCWSTR  NetFrameworkExtensionName;


#ifndef NET_STUB

    #ifndef NET_VERSION_MAJOR
    #error  NET_VERSION_MAJOR is not defined
    #endif

    //
    // "Version Minor(Target version)" controls which version of public header files to include
    //
    #ifndef NET_VERSION_MINOR
    #error  NET_VERSION_MINOR is not defined
    #endif

    //
    // "Version Minor (Minimum Required)" controls the oldest version of framework to load the driver
    //
    #ifndef NET_MINIMUM_VERSION_REQUIRED
    #define NET_MINIMUM_VERSION_REQUIRED NET_VERSION_MINOR
    #endif

    __declspec(selectany)
    ULONG NetMinimumVersionRequired = NET_MINIMUM_VERSION_REQUIRED;

#else

    //
    // Implemented in client driver code
    //
    extern ULONG NetMinimumVersionRequired;

#endif

//
// BOOLEAN
// NET_IS_FUNCTION_AVAILABLE(
//     FunctionName
//     );
//
#define NET_IS_FUNCTION_AVAILABLE(FunctionName)                                \
(                                                                              \
    (FunctionName ## TableIndex < NET_ALWAYS_AVAILABLE_FUNCTION_COUNT)         \
    ||                                                                         \
    (!NetClientVersionHigherThanFramework)                                     \
    ||                                                                         \
    (FunctionName ## TableIndex < NetFunctionCount)                            \
)

//
// BOOLEAN
// NET_IS_STRUCTURE_AVAILABLE(
//     StructName
//     );
//
#define NET_IS_STRUCTURE_AVAILABLE(StructName)                                 \
(                                                                              \
    (!NetClientVersionHigherThanFramework)                                     \
    ||                                                                         \
    (INDEX_ ## StructName < NetStructureCount)                                 \
)

//
// BOOLEAN
// NET_IS_FIELD_AVAILABLE(
//     StructName,
//     FieldName
//     );
//
#define NET_IS_FIELD_AVAILABLE(StructName, FieldName)                          \
(                                                                              \
    (!NetClientVersionHigherThanFramework)                                     \
    ||                                                                         \
    (                                                                          \
        (INDEX_ ## StructName < NetStructureCount)                             \
        &&                                                                     \
        (FIELD_OFFSET(StructName, FieldName) < NetStructures[INDEX_ ## StructName])\
    )                                                                          \
)

//
// ULONG
// NET_STRUCTURE_SIZE(
//     StructName
//     );
//
// NOTE: if it returns (-1), the structure is not available on the
//       current framework (and should not be used).
//
#if defined(NET_EVERYTHING_ALWAYS_AVAILABLE)

#define NET_STRUCTURE_SIZE(StructName)  (ULONG)sizeof(StructName)

#else

#define NET_STRUCTURE_SIZE(StructName)                                         \
(ULONG)                                                                        \
(                                                                              \
    NetClientVersionHigherThanFramework                                        \
        ? (                                                                    \
            (INDEX_ ## StructName < NetStructureCount)                         \
            ? NetStructures[INDEX_ ## StructName]                              \
            : (size_t)(-1)                                                     \
          )                                                                    \
        : sizeof(StructName)                                                   \
)

#endif // NET_STRUCTURE_SIZE

typedef enum _NETFUNCENUM {

    NetAdapterInitAllocateTableIndex = 0,
    NetAdapterInitFreeTableIndex = 1,
    NetAdapterInitSetDatapathCallbacksTableIndex = 2,
    NetAdapterCreateTableIndex = 3,
    NetAdapterStartTableIndex = 4,
    NetAdapterStopTableIndex = 5,
    NetAdapterSetLinkLayerCapabilitiesTableIndex = 6,
    NetAdapterSetLinkLayerMtuSizeTableIndex = 7,
    NetAdapterSetDataPathCapabilitiesTableIndex = 8,
    NetAdapterSetLinkStateTableIndex = 9,
    NetAdapterGetNetLuidTableIndex = 10,
    NetAdapterOpenConfigurationTableIndex = 11,
    NetAdapterSetPermanentLinkLayerAddressTableIndex = 12,
    NetAdapterSetCurrentLinkLayerAddressTableIndex = 13,
    NetAdapterSetReceiveFilterCapabilitiesTableIndex = 14,
    NetReceiveFilterGetPacketFilterTableIndex = 15,
    NetReceiveFilterGetMulticastAddressCountTableIndex = 16,
    NetReceiveFilterGetMulticastAddressListTableIndex = 17,
    NetAdapterOffloadSetTxChecksumCapabilitiesTableIndex = 18,
    NetOffloadIsTxChecksumIPv4EnabledTableIndex = 19,
    NetOffloadIsTxChecksumTcpEnabledTableIndex = 20,
    NetOffloadIsTxChecksumUdpEnabledTableIndex = 21,
    NetAdapterOffloadSetRxChecksumCapabilitiesTableIndex = 22,
    NetOffloadIsRxChecksumIPv4EnabledTableIndex = 23,
    NetOffloadIsRxChecksumTcpEnabledTableIndex = 24,
    NetOffloadIsRxChecksumUdpEnabledTableIndex = 25,
    NetAdapterOffloadSetGsoCapabilitiesTableIndex = 26,
    NetOffloadIsLsoIPv4EnabledTableIndex = 27,
    NetOffloadIsLsoIPv6EnabledTableIndex = 28,
    NetOffloadIsUsoIPv4EnabledTableIndex = 29,
    NetOffloadIsUsoIPv6EnabledTableIndex = 30,
    NetAdapterOffloadSetRscCapabilitiesTableIndex = 31,
    NetOffloadIsTcpRscIPv4EnabledTableIndex = 32,
    NetOffloadIsTcpRscIPv6EnabledTableIndex = 33,
    NetOffloadIsRscTcpTimestampOptionEnabledTableIndex = 34,
    NetAdapterOffloadSetIeee8021qTagCapabilitiesTableIndex = 35,
    NetConfigurationCloseTableIndex = 36,
    NetConfigurationOpenSubConfigurationTableIndex = 37,
    NetConfigurationQueryUlongTableIndex = 38,
    NetConfigurationQueryStringTableIndex = 39,
    NetConfigurationQueryMultiStringTableIndex = 40,
    NetConfigurationQueryBinaryTableIndex = 41,
    NetConfigurationQueryLinkLayerAddressTableIndex = 42,
    NetConfigurationAssignUlongTableIndex = 43,
    NetConfigurationAssignUnicodeStringTableIndex = 44,
    NetConfigurationAssignMultiStringTableIndex = 45,
    NetConfigurationAssignBinaryTableIndex = 46,
    NetDeviceInitConfigTableIndex = 47,
    NetDeviceOpenConfigurationTableIndex = 48,
    NetRxQueueCreateTableIndex = 49,
    NetRxQueueNotifyMoreReceivedPacketsAvailableTableIndex = 50,
    NetRxQueueInitGetQueueIdTableIndex = 51,
    NetRxQueueGetRingCollectionTableIndex = 52,
    NetRxQueueGetExtensionTableIndex = 53,
    NetTxQueueCreateTableIndex = 54,
    NetTxQueueNotifyMoreCompletedPacketsAvailableTableIndex = 55,
    NetTxQueueInitGetQueueIdTableIndex = 56,
    NetTxQueueGetRingCollectionTableIndex = 57,
    NetTxQueueGetExtensionTableIndex = 58,
    NetAdapterPowerOffloadSetArpCapabilitiesTableIndex = 59,
    NetAdapterPowerOffloadSetNSCapabilitiesTableIndex = 60,
    NetAdapterWakeSetBitmapCapabilitiesTableIndex = 61,
    NetAdapterWakeSetMediaChangeCapabilitiesTableIndex = 62,
    NetAdapterWakeSetMagicPacketCapabilitiesTableIndex = 63,
    NetAdapterWakeSetEapolPacketCapabilitiesTableIndex = 64,
    NetAdapterWakeSetPacketFilterCapabilitiesTableIndex = 65,
    NetAdapterReportWakeReasonPacketTableIndex = 66,
    NetAdapterReportWakeReasonMediaChangeTableIndex = 67,
    NetDriverExtensionInitializeTableIndex = 68,
    NetAdapterInitGetCreatedAdapterTableIndex = 69,
    NetAdapterExtensionInitAllocateTableIndex = 70,
    NetAdapterExtensionInitSetOidRequestPreprocessCallbackTableIndex = 71,
    NetAdapterExtensionInitSetDirectOidRequestPreprocessCallbackTableIndex = 72,
    NetExAdapterInitSetDirectOidPreprocessCallbackTableIndex = 73,
    NetAdapterDispatchPreprocessedOidRequestTableIndex = 74,
    NetAdapterDispatchPreprocessedDirectOidRequestTableIndex = 75,
    NetExAdapterDispatchPreprocessedDirectOidTableIndex = 76,
    NetAdapterGetParentTableIndex = 77,
    NetAdapterGetLinkLayerMtuSizeTableIndex = 78,
    NetAdapterExtensionInitSetNdisPmCapabilitiesTableIndex = 79,
    NetAdapterExtensionSetNdisPmCapabilitiesTableIndex = 80,
    NetAdapterInitAllocateContextTableIndex = 81,
    NetAdapterInitGetTypedContextWorkerTableIndex = 82,
    NetAdapterExtensionInitSetPowerPolicyCallbacksTableIndex = 83,
    NetAdapterInitSetSelfManagedPowerReferencesTableIndex = 84,
    NetOffloadIsUdpRscEnabledTableIndex = 85,
    NetAdapterInitAddTxDemuxTableIndex = 86,
    NetAdapterPauseOffloadCapabilitiesTableIndex = 87,
    NetAdapterResumeOffloadCapabilitiesTableIndex = 88,
    NetAdapterQueryWakeReasonTableIndex = 89,
    NetDeviceInitSetPowerPolicyEventCallbacksTableIndex = 90,
    NetDeviceInitSetResetCapabilitiesTableIndex = 91,
    NetDeviceStoreResetDiagnosticsTableIndex = 92,
    NetDeviceRequestResetTableIndex = 93,
    NetDeviceInitSetResetConfigTableIndex = 94,
    NetDeviceAssignSupportedOidListTableIndex = 95,
    NetPowerOffloadGetTypeTableIndex = 96,
    NetPowerOffloadGetAdapterTableIndex = 97,
    NetPowerOffloadGetArpParametersTableIndex = 98,
    NetPowerOffloadGetNSParametersTableIndex = 99,
    NetDeviceGetPowerOffloadListTableIndex = 100,
    NetPowerOffloadListGetCountTableIndex = 101,
    NetPowerOffloadListGetElementTableIndex = 102,
    NetAdapterSetReceiveScalingCapabilitiesTableIndex = 103,
    NetTxQueueGetDemux8021pTableIndex = 104,
    NetTxQueueGetDemuxWmmInfoTableIndex = 105,
    NetWakeSourceGetTypeTableIndex = 106,
    NetWakeSourceGetAdapterTableIndex = 107,
    NetWakeSourceGetBitmapParametersTableIndex = 108,
    NetWakeSourceGetMediaChangeParametersTableIndex = 109,
    NetDeviceGetWakeSourceListTableIndex = 110,
    NetWakeSourceListGetCountTableIndex = 111,
    NetWakeSourceListGetElementTableIndex = 112,
    NetFunctionTableNumEntries = 113,
} NETFUNCENUM;

typedef enum _NETSTRUCTENUM {

    INDEX_NET_ADAPTER_DATAPATH_CALLBACKS               = 0,
    INDEX_NET_ADAPTER_EXTENSION_POWER_POLICY_CALLBACKS = 1,
    INDEX_NET_ADAPTER_LINK_LAYER_ADDRESS               = 2,
    INDEX_NET_ADAPTER_LINK_LAYER_CAPABILITIES          = 3,
    INDEX_NET_ADAPTER_LINK_STATE                       = 4,
    INDEX_NET_ADAPTER_NDIS_PM_CAPABILITIES             = 5,
    INDEX_NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES         = 6,
    INDEX_NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES = 7,
    INDEX_NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES         = 8,
    INDEX_NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES = 9,
    INDEX_NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES = 10,
    INDEX_NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES   = 11,
    INDEX_NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES    = 12,
    INDEX_NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES      = 13,
    INDEX_NET_ADAPTER_RX_CAPABILITIES                  = 14,
    INDEX_NET_ADAPTER_TX_CAPABILITIES                  = 15,
    INDEX_NET_ADAPTER_WAKE_BITMAP_CAPABILITIES         = 16,
    INDEX_NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES   = 17,
    INDEX_NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES   = 18,
    INDEX_NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES   = 19,
    INDEX_NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES  = 20,
    INDEX_NET_ADAPTER_WAKE_REASON_PACKET               = 21,
    INDEX_NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS      = 22,
    INDEX_NET_DEVICE_RESET_CONFIG                      = 23,
    INDEX_NET_DRIVER_EXTENSION_CONFIG                  = 24,
    INDEX_NET_DRIVER_GLOBALS                           = 25,
    INDEX_NET_EXTENSION_QUERY                          = 26,
    INDEX_NET_PACKET_QUEUE_CONFIG                      = 27,
    INDEX_NET_POWER_OFFLOAD_ARP_PARAMETERS             = 28,
    INDEX_NET_POWER_OFFLOAD_LIST                       = 29,
    INDEX_NET_POWER_OFFLOAD_NS_PARAMETERS              = 30,
    INDEX_NET_RXQUEUE_BUFFER_LAYOUT_HINT               = 31,
    INDEX_NET_WAKE_SOURCE_BITMAP_PARAMETERS            = 32,
    INDEX_NET_WAKE_SOURCE_LIST                         = 33,
    INDEX_NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS      = 34,
    INDEX_NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES     = 35,
    INDEX_NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY  = 36,
    INDEX_NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES = 37,
    INDEX_NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY = 38,
    INDEX_NET_ADAPTER_TX_DEMUX                         = 39,
    INDEX_NET_DEVICE_RESET_CAPABILITIES                = 40,
    NET_STRUCTURE_TABLE_NUM_ENTRIES                    = 41,
} NETSTRUCTENUM;

#define Net_STRUCTURE_TABLE_NUM_ENTRIES NET_STRUCTURE_TABLE_NUM_ENTRIES

#endif // _NETFUNCENUM_2_5_H_

