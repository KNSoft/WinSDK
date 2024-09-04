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

#ifndef _NETFUNCENUM_H_
#define _NETFUNCENUM_H_

extern PNET_DRIVER_GLOBALS NetDriverGlobals;

typedef enum _NETFUNCENUM {

    NetDefaultAdapterInitAllocateTableIndex = 0,
    NetAdapterInitAllocateTableIndex = 1,
    NetAdapterInitFreeTableIndex = 2,
    NetAdapterInitSetDatapathCallbacksTableIndex = 3,
    NetAdapterInitSetNetRequestAttributesTableIndex = 4,
    NetAdapterInitSetNetPowerSettingsAttributesTableIndex = 5,
    NetAdapterDeviceInitConfigTableIndex = 6,
    NetAdapterCreateTableIndex = 7,
    NetAdapterStartTableIndex = 8,
    NetAdapterStopTableIndex = 9,
    NetAdapterSetLinkLayerCapabilitiesTableIndex = 10,
    NetAdapterSetLinkLayerMtuSizeTableIndex = 11,
    NetAdapterSetPowerCapabilitiesTableIndex = 12,
    NetAdapterSetDataPathCapabilitiesTableIndex = 13,
    NetAdapterSetCurrentLinkStateTableIndex = 14,
    NetAdapterWdmGetNdisHandleTableIndex = 15,
    NetAdapterGetNetLuidTableIndex = 16,
    NetAdapterOpenConfigurationTableIndex = 17,
    NetAdapterGetPowerSettingsTableIndex = 18,
    NetAdapterDriverWdmGetHandleTableIndex = 19,
    NetAdapterSetPermanentLinkLayerAddressTableIndex = 20,
    NetAdapterSetCurrentLinkLayerAddressTableIndex = 21,
    NetAdapterOffloadSetChecksumCapabilitiesTableIndex = 22,
    NetAdapterOffloadSetLsoCapabilitiesTableIndex = 23,
    NetAdapterInitGetCreatedAdapterTableIndex = 24,
    NetAdapterExtensionInitAllocateTableIndex = 25,
    NetAdapterExtensionInitSetNetRequestPreprocessCallbackTableIndex = 26,
    NetAdapterDispatchPreprocessedNetRequestTableIndex = 27,
    NetAdapterGetParentTableIndex = 28,
    NetAdapterGetLinkLayerMtuSizeTableIndex = 29,
    NetPacketGetTypedContextTableIndex = 30,
    NetPacketGetContextFromTokenTableIndex = 31,
    NetConfigurationCloseTableIndex = 32,
    NetConfigurationOpenSubConfigurationTableIndex = 33,
    NetConfigurationQueryUlongTableIndex = 34,
    NetConfigurationQueryStringTableIndex = 35,
    NetConfigurationQueryMultiStringTableIndex = 36,
    NetConfigurationQueryBinaryTableIndex = 37,
    NetConfigurationQueryLinkLayerAddressTableIndex = 38,
    NetConfigurationAssignUlongTableIndex = 39,
    NetConfigurationAssignUnicodeStringTableIndex = 40,
    NetConfigurationAssignMultiStringTableIndex = 41,
    NetConfigurationAssignBinaryTableIndex = 42,
    NetDeviceOpenConfigurationTableIndex = 43,
    NetDeviceSetResetCallbackTableIndex = 44,
    NetAdapterRegisterPacketExtensionTableIndex = 45,
    NetAdapterQueryRegisteredPacketExtensionTableIndex = 46,
    NetTxQueueInitAddPacketExtensionTableIndex = 47,
    NetRxQueueInitAddPacketExtensionTableIndex = 48,
    NetPowerSettingsGetWakePatternCountTableIndex = 49,
    NetPowerSettingsGetWakePatternCountForTypeTableIndex = 50,
    NetPowerSettingsGetWakePatternTableIndex = 51,
    NetPowerSettingsIsWakePatternEnabledTableIndex = 52,
    NetPowerSettingsGetEnabledWakeUpFlagsTableIndex = 53,
    NetPowerSettingsGetEnabledWakePatternFlagsTableIndex = 54,
    NetPowerSettingsGetEnabledProtocolOffloadFlagsTableIndex = 55,
    NetPowerSettingsGetEnabledMediaSpecificWakeUpEventsTableIndex = 56,
    NetPowerSettingsGetProtocolOffloadCountTableIndex = 57,
    NetPowerSettingsGetProtocolOffloadCountForTypeTableIndex = 58,
    NetPowerSettingsGetProtocolOffloadTableIndex = 59,
    NetPowerSettingsIsProtocolOffloadEnabledTableIndex = 60,
    NetAdapterSetReceiveScalingCapabilitiesTableIndex = 61,
    NetRequestRetrieveInputOutputBufferTableIndex = 62,
    NetRequestWdmGetNdisOidRequestTableIndex = 63,
    NetRequestCompleteWithoutInformationTableIndex = 64,
    NetRequestSetDataCompleteTableIndex = 65,
    NetRequestQueryDataCompleteTableIndex = 66,
    NetRequestMethodCompleteTableIndex = 67,
    NetRequestSetBytesNeededTableIndex = 68,
    NetRequestGetIdTableIndex = 69,
    NetRequestGetPortNumberTableIndex = 70,
    NetRequestGetSwitchIdTableIndex = 71,
    NetRequestGetVPortIdTableIndex = 72,
    NetRequestGetTypeTableIndex = 73,
    NetRequestGetAdapterTableIndex = 74,
    NetRequestQueueCreateTableIndex = 75,
    NetRequestQueueGetAdapterTableIndex = 76,
    NetRxQueueCreateTableIndex = 77,
    NetRxQueueNotifyMoreReceivedPacketsAvailableTableIndex = 78,
    NetRxQueueInitGetQueueIdTableIndex = 79,
    NetRxQueueGetDatapathDescriptorTableIndex = 80,
    NetRxQueueGetPacketContextTokenTableIndex = 81,
    NetRxQueueInitAddPacketContextAttributesTableIndex = 82,
    NetRxQueueGetPacketExtensionOffsetTableIndex = 83,
    NetTxQueueCreateTableIndex = 84,
    NetTxQueueNotifyMoreCompletedPacketsAvailableTableIndex = 85,
    NetTxQueueInitGetQueueIdTableIndex = 86,
    NetTxQueueGetDatapathDescriptorTableIndex = 87,
    NetTxQueueGetPacketContextTokenTableIndex = 88,
    NetTxQueueInitAddPacketContextAttributesTableIndex = 89,
    NetTxQueueGetPacketExtensionOffsetTableIndex = 90,
    NetFunctionTableNumEntries = 91,
} NETFUNCENUM;

#endif // _NETFUNCENUM_H_

