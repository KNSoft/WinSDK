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

    NetAdapterDeviceInitConfigTableIndex = 0,
    NetAdapterCreateTableIndex = 1,
    NetAdapterStartTableIndex = 2,
    NetAdapterStopTableIndex = 3,
    NetAdapterSetLinkLayerCapabilitiesTableIndex = 4,
    NetAdapterSetLinkLayerMtuSizeTableIndex = 5,
    NetAdapterSetPowerCapabilitiesTableIndex = 6,
    NetAdapterSetDataPathCapabilitiesTableIndex = 7,
    NetAdapterSetCurrentLinkStateTableIndex = 8,
    NetAdapterWdmGetNdisHandleTableIndex = 9,
    NetAdapterGetNetLuidTableIndex = 10,
    NetAdapterOpenConfigurationTableIndex = 11,
    NetAdapterGetPowerSettingsTableIndex = 12,
    NetAdapterDriverWdmGetHandleTableIndex = 13,
    NetAdapterSetPermanentLinkLayerAddressTableIndex = 14,
    NetAdapterSetCurrentLinkLayerAddressTableIndex = 15,
    NetPacketGetTypedContextTableIndex = 16,
    NetPacketGetContextFromTokenTableIndex = 17,
    NetConfigurationCloseTableIndex = 18,
    NetConfigurationOpenSubConfigurationTableIndex = 19,
    NetConfigurationQueryUlongTableIndex = 20,
    NetConfigurationQueryStringTableIndex = 21,
    NetConfigurationQueryMultiStringTableIndex = 22,
    NetConfigurationQueryBinaryTableIndex = 23,
    NetConfigurationQueryLinkLayerAddressTableIndex = 24,
    NetConfigurationAssignUlongTableIndex = 25,
    NetConfigurationAssignUnicodeStringTableIndex = 26,
    NetConfigurationAssignMultiStringTableIndex = 27,
    NetConfigurationAssignBinaryTableIndex = 28,
    NetObjectMarkCancelableExTableIndex = 29,
    NetObjectUnmarkCancelableTableIndex = 30,
    NetAdapterRegisterPacketExtensionTableIndex = 31,
    NetAdapterQueryRegisteredPacketExtensionTableIndex = 32,
    NetTxQueueInitAddPacketExtensionTableIndex = 33,
    NetRxQueueInitAddPacketExtensionTableIndex = 34,
    NetPowerSettingsGetWakePatternCountTableIndex = 35,
    NetPowerSettingsGetWakePatternCountForTypeTableIndex = 36,
    NetPowerSettingsGetWakePatternTableIndex = 37,
    NetPowerSettingsIsWakePatternEnabledTableIndex = 38,
    NetPowerSettingsGetEnabledWakeUpFlagsTableIndex = 39,
    NetPowerSettingsGetEnabledWakePatternFlagsTableIndex = 40,
    NetPowerSettingsGetEnabledProtocolOffloadFlagsTableIndex = 41,
    NetPowerSettingsGetEnabledMediaSpecificWakeUpEventsTableIndex = 42,
    NetPowerSettingsGetProtocolOffloadCountTableIndex = 43,
    NetPowerSettingsGetProtocolOffloadCountForTypeTableIndex = 44,
    NetPowerSettingsGetProtocolOffloadTableIndex = 45,
    NetPowerSettingsIsProtocolOffloadEnabledTableIndex = 46,
    NetAdapterSetReceiveScalingCapabilitiesTableIndex = 47,
    NetAdapterGetReceiveScalingHashSecretKeyTableIndex = 48,
    NetAdapterGetReceiveScalingProtocolTypesTableIndex = 49,
    NetAdapterGetReceiveScalingHashTypeTableIndex = 50,
    NetRequestRetrieveInputOutputBufferTableIndex = 51,
    NetRequestWdmGetNdisOidRequestTableIndex = 52,
    NetRequestCompleteWithoutInformationTableIndex = 53,
    NetRequestSetDataCompleteTableIndex = 54,
    NetRequestQueryDataCompleteTableIndex = 55,
    NetRequestMethodCompleteTableIndex = 56,
    NetRequestSetBytesNeededTableIndex = 57,
    NetRequestGetIdTableIndex = 58,
    NetRequestGetPortNumberTableIndex = 59,
    NetRequestGetSwitchIdTableIndex = 60,
    NetRequestGetVPortIdTableIndex = 61,
    NetRequestGetTypeTableIndex = 62,
    NetRequestGetAdapterTableIndex = 63,
    NetRequestQueueCreateTableIndex = 64,
    NetRequestQueueGetAdapterTableIndex = 65,
    NetRssQueueGroupCreateTableIndex = 66,
    NetRssQueueGroupGetCountTableIndex = 67,
    NetRssQueueGroupGetRxQueueInitTableIndex = 68,
    NetRxQueueCreateTableIndex = 69,
    NetRxQueueNotifyMoreReceivedPacketsAvailableTableIndex = 70,
    NetRxQueueInitGetQueueIdTableIndex = 71,
    NetRxQueueGetDatapathDescriptorTableIndex = 72,
    NetRxQueueGetPacketContextTokenTableIndex = 73,
    NetRxQueueInitAddPacketContextAttributesTableIndex = 74,
    NetRxQueueGetPacketExtensionOffsetTableIndex = 75,
    NetTxQueueCreateTableIndex = 76,
    NetTxQueueNotifyMoreCompletedPacketsAvailableTableIndex = 77,
    NetTxQueueInitGetQueueIdTableIndex = 78,
    NetTxQueueGetDatapathDescriptorTableIndex = 79,
    NetTxQueueGetPacketContextTokenTableIndex = 80,
    NetTxQueueInitAddPacketContextAttributesTableIndex = 81,
    NetTxQueueGetPacketExtensionOffsetTableIndex = 82,
    NetFunctionTableNumEntries = 83,
} NETFUNCENUM;

#endif // _NETFUNCENUM_H_

