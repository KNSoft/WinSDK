//**********************************************************************`
//* This is an include file generated by Message Compiler.             *`
//*                                                                    *`
//* Copyright (c) Microsoft Corporation. All Rights Reserved.          *`
//**********************************************************************`
#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Provider "Microsoft-Windows-Kernel-WHEA" event count 33
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Provider GUID = 7b563579-53c8-44e7-8236-0f87b9fe6594
EXTERN_C __declspec(selectany) const GUID WHEA_ETW_PROVIDER = {0x7b563579, 0x53c8, 0x44e7, {0x82, 0x36, 0x0f, 0x87, 0xb9, 0xfe, 0x65, 0x94}};

#ifndef WHEA_ETW_PROVIDER_Traits
#define WHEA_ETW_PROVIDER_Traits NULL
#endif // WHEA_ETW_PROVIDER_Traits

//
// Channel
//
#define WHEA_ETW_PROVIDER_CHANNEL_systemChannel 0x8
#define WHEA_ETW_PROVIDER_CHANNEL_systemChannel_KEYWORD 0x8000000000000000
#define WHEA_CHANNEL 0x10
#define WHEA_CHANNEL_KEYWORD 0x4000000000000000
#define WHEA_EVENTLOG_CHANNEL 0x11
#define WHEA_EVENTLOG_CHANNEL_KEYWORD 0x2000000000000000

//
// Keyword
//
#define WHEA_ERROR_KEYWORD 0x800
#define WHEA_EVENTLOG_KEYWORD 0x400

//
// Event Descriptors
//
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR EVENT_WHEA_INIT_OP = {0x5, 0x0, 0x11, 0x4, 0x0, 0x0, 0x2000000000000000};
#define EVENT_WHEA_INIT_OP_value 0x5
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR EVENT_WHEA_ERROR = {0x14, 0x0, 0x10, 0x4, 0x0, 0x0, 0x4000000000000800};
#define EVENT_WHEA_ERROR_value 0x14
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR EVENT_WHEA_ERROR_PART = {0x15, 0x0, 0x10, 0x4, 0x0, 0x0, 0x4000000000000800};
#define EVENT_WHEA_ERROR_PART_value 0x15
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR EVENT_WHEA_MEMORY_OFFLINE = {0x1f, 0x0, 0x8, 0x4, 0x0, 0x0, 0x8000000000000800};
#define EVENT_WHEA_MEMORY_OFFLINE_value 0x1f
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_START_SESSION = {0x20, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_START_SESSION_value 0x20
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_END_SESSION = {0x21, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_END_SESSION_value 0x21
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_SETDWORD = {0x22, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_SETDWORD_value 0x22
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_INCREMENTDWORD = {0x23, 0x0, 0x0, 0x4, 0x2, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_INCREMENTDWORD_value 0x23
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_ADDTOAVERAGEDWORD = {0x24, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_ADDTOAVERAGEDWORD_value 0x24
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_SETIFMAXDWORD = {0x25, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_SETIFMAXDWORD_value 0x25
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_SETIFMINDWORD = {0x26, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_SETIFMINDWORD_value 0x26
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_SETSTRING = {0x27, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_SETSTRING_value 0x27
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR WHEA_SQM_EVENT_ADDTOSTREAM = {0x28, 0x0, 0x0, 0x4, 0x0, 0x0, 0x8000000000000};
#define WHEA_SQM_EVENT_ADDTOSTREAM_value 0x28
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR EVENT_WHEA_PROCESS_TERMINATE = {0x29, 0x0, 0x8, 0x4, 0x0, 0x0, 0x8000000000000800};
#define EVENT_WHEA_PROCESS_TERMINATE_value 0x29
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR EVENT_WHEA_LOG_ENTRY = {0x2a, 0x0, 0x11, 0x4, 0x0, 0x0, 0x2000000000000400};
#define EVENT_WHEA_LOG_ENTRY_value 0x2a

#define MSG_CorrectedError_EventMessage      0x00000001L
#define MSG_UncorrectedError_EventMessage    0x00000002L
#define MSG_MCAMemHierarchyErr_EventMessage  0x00000006L
#define MSG_MCATLBErr_EventMessage           0x00000008L
#define MSG_MCABusErr_EventMessage           0x0000000AL
#define MSG_MCABusTOErr_EventMessage         0x0000000CL
#define MSG_MCAWDTOErr_EventMessage          0x0000000EL
#define MSG_MCAExternalErr_EventMessage      0x00000010L
#define MSG_MCAFRCErr_EventMessage           0x00000011L
#define MSG_PCIeErr_EventMessage             0x00000012L
#define MSG_MemoryOffline_EventMessage       0x0000001FL
#define MSG_ProcessTerminate_EventMessage    0x00000029L
#define MSG_WHEA_EVENTLOG_KEYWORD_KeywordMessage 0x1000000BL
#define MSG_WHEA_ERROR_KEYWORD_KeywordMessage 0x1000000CL
#define MSG_eventProviderName                0x90000001L
#define MSG_Init_EventMessage                0xB0000005L
#define MSG_MCAMemHierarchyWrn_EventMessage  0xB0000007L
#define MSG_MCATLBWrn_EventMessage           0xB0000009L
#define MSG_MCABusWrn_EventMessage           0xB000000BL
#define MSG_MCABusTOWrn_EventMessage         0xB000000DL
#define MSG_MCAROMParityErr_EventMessage     0xB000000FL
#define MSG_PCIeWrn_EventMessage             0xB0000013L
#define MSG_WHEA_EventMessage                0xB0000014L
#define MSG_WheaEventLog_EventMessage        0xB000002AL
#define MSG_mapWHEAPending_No                0xD0000001L
#define MSG_mapWHEAPending_Yes               0xD0000002L
#define MSG_mapWHEAPlatformDirected_No       0xD0000003L
#define MSG_mapWHEAPlatformDirected_Yes      0xD0000004L
#define MSG_mapWHEAUncorrected_No            0xD0000005L
#define MSG_mapWHEAUncorrected_Yes           0xD0000006L
#define MSG_mapWHEAPersisted_No              0xD0000007L
#define MSG_mapWHEAPersisted_Yes             0xD0000008L
