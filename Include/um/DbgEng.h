//----------------------------------------------------------------------------
//
// Debugger engine interfaces.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#ifndef __DBGENG_H__
#define __DBGENG_H__

#include <winapifamily.h>

#pragma region Desktop Family or WER Package
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_WER)

#include <stdarg.h>
#include <objbase.h>

#ifndef _WDBGEXTS_
typedef struct _WINDBG_EXTENSION_APIS32* PWINDBG_EXTENSION_APIS32;
typedef struct _WINDBG_EXTENSION_APIS64* PWINDBG_EXTENSION_APIS64;
#endif

#ifndef _CRASHLIB_
typedef struct _MEMORY_BASIC_INFORMATION64* PMEMORY_BASIC_INFORMATION64;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------------------------------
//
// Special exception code extensions could throw
//
//----------------------------------------------------------------------------
#define ERROR_DBG_CANCELLED 0xC00004C7 // 0xC0000000 + ERROR_CANCELLED
#define ERROR_DBG_TIMEOUT   0xC00005B4 // 0xC0000000 + ERROR_TIMEOUT

//----------------------------------------------------------------------------
//
// GUIDs and interface forward declarations.
//
//----------------------------------------------------------------------------

/* f2df5f53-071f-47bd-9de6-5734c3fed689 */
DEFINE_GUID(IID_IDebugAdvanced, 0xf2df5f53, 0x071f, 0x47bd,
            0x9d, 0xe6, 0x57, 0x34, 0xc3, 0xfe, 0xd6, 0x89);
/* 716d14c9-119b-4ba5-af1f-0890e672416a */
DEFINE_GUID(IID_IDebugAdvanced2, 0x716d14c9, 0x119b, 0x4ba5,
            0xaf, 0x1f, 0x08, 0x90, 0xe6, 0x72, 0x41, 0x6a);
/* cba4abb4-84c4-444d-87ca-a04e13286739 */
DEFINE_GUID(IID_IDebugAdvanced3, 0xcba4abb4, 0x84c4, 0x444d,
            0x87, 0xca, 0xa0, 0x4e, 0x13, 0x28, 0x67, 0x39);
/* d1069067-2a65-4bf0-ae97-76184b67856b */
DEFINE_GUID(IID_IDebugAdvanced4, 0xd1069067, 0x2a65, 0x4bf0,
            0xae, 0x97, 0x76, 0x18, 0x4b, 0x67, 0x85, 0x6b);
/* 5bd9d474-5975-423a-b88b-65a8e7110e65 */
DEFINE_GUID(IID_IDebugBreakpoint, 0x5bd9d474, 0x5975, 0x423a,
            0xb8, 0x8b, 0x65, 0xa8, 0xe7, 0x11, 0x0e, 0x65);
/* 1b278d20-79f2-426e-a3f9-c1ddf375d48e */
DEFINE_GUID(IID_IDebugBreakpoint2, 0x1b278d20, 0x79f2, 0x426e,
            0xa3, 0xf9, 0xc1, 0xdd, 0xf3, 0x75, 0xd4, 0x8e);
/* 38f5c249-b448-43bb-9835-579d4ec02249 */
DEFINE_GUID(IID_IDebugBreakpoint3, 0x38f5c249, 0xb448, 0x43bb,
            0x98, 0x35, 0x57, 0x9d, 0x4e, 0xc0, 0x22, 0x49);
/* 27fe5639-8407-4f47-8364-ee118fb08ac8 */
DEFINE_GUID(IID_IDebugClient, 0x27fe5639, 0x8407, 0x4f47,
            0x83, 0x64, 0xee, 0x11, 0x8f, 0xb0, 0x8a, 0xc8);
/* edbed635-372e-4dab-bbfe-ed0d2f63be81 */
DEFINE_GUID(IID_IDebugClient2, 0xedbed635, 0x372e, 0x4dab,
        0xbb, 0xfe, 0xed, 0x0d, 0x2f, 0x63, 0xbe, 0x81);
/* dd492d7f-71b8-4ad6-a8dc-1c887479ff91 */
DEFINE_GUID(IID_IDebugClient3, 0xdd492d7f, 0x71b8, 0x4ad6,
            0xa8, 0xdc, 0x1c, 0x88, 0x74, 0x79, 0xff, 0x91);
/* ca83c3de-5089-4cf8-93c8-d892387f2a5e */
DEFINE_GUID(IID_IDebugClient4, 0xca83c3de, 0x5089, 0x4cf8,
            0x93, 0xc8, 0xd8, 0x92, 0x38, 0x7f, 0x2a, 0x5e);
/* e3acb9d7-7ec2-4f0c-a0da-e81e0cbbe628 */
DEFINE_GUID(IID_IDebugClient5, 0xe3acb9d7, 0x7ec2, 0x4f0c,
            0xa0, 0xda, 0xe8, 0x1e, 0x0c, 0xbb, 0xe6, 0x28);
/* fd28b4c5-c498-4686-a28e-62cad2154eb3 */
DEFINE_GUID(IID_IDebugClient6, 0xfd28b4c5, 0xc498, 0x4686,
            0xa2, 0x8e, 0x62, 0xca, 0xd2, 0x15, 0x4e, 0xb3);
/* 13586be3-542e-481e-b1f2-8497ba74f9a9 */
DEFINE_GUID(IID_IDebugClient7, 0x13586be3, 0x542e, 0x481e,
            0xb1, 0xf2, 0x84, 0x97, 0xba, 0x74, 0xf9, 0xa9);
/* CEC43ADD-6375-469e-83D5-414E4033C19A */
DEFINE_GUID(IID_IDebugClient8, 0xcec43add, 0x6375, 0x469e,
            0x83, 0xd5, 0x41, 0x4e, 0x40, 0x33, 0xc1, 0x9a);
/* 2C24CD5B-4D9E-4DF4-8A70-3D37440D119F */
DEFINE_GUID(IID_IDebugClient9, 0x2c24cd5b, 0x4d9e, 0x4df4,
            0x8a, 0x70, 0x3d, 0x37, 0x44, 0x0d, 0x11, 0x9f);
/* a02b66c4-aea3-4234-a9f7-fe4c383d4e29 */
DEFINE_GUID(IID_IDebugPlmClient, 0xa02b66c4, 0xaea3, 0x4234,
            0xa9, 0xf7, 0xfe, 0x4c, 0x38, 0x3d, 0x4e, 0x29);
/* 597c980d-e7bd-4309-962c-9d9b69a7372c */
DEFINE_GUID(IID_IDebugPlmClient2, 0x597c980d, 0xe7bd, 0x4309,
            0x96, 0x2c, 0x9d, 0x9b, 0x69, 0xa7, 0x37, 0x2c);
/* cdf48669-901f-4791-b868-7d2cb3a2d7fc */
DEFINE_GUID(IID_IDebugPlmClient3, 0xcdf48669, 0x901f, 0x4791,
            0xb8, 0x68, 0x7d, 0x2c, 0xb3, 0xa2, 0xd7, 0xfc);
/* 7782d8f2-2b85-4059-ab88-28ceddca1c80 */
DEFINE_GUID(IID_IDebugOutputStream, 0x7782d8f2, 0x2b85, 0x4059,
            0xab, 0x88, 0x28, 0xce, 0xdd, 0xca, 0x1c, 0x80);
/* 5182e668-105e-416e-ad92-24ef800424ba */
DEFINE_GUID(IID_IDebugControl, 0x5182e668, 0x105e, 0x416e,
            0xad, 0x92, 0x24, 0xef, 0x80, 0x04, 0x24, 0xba);
/* d4366723-44df-4bed-8c7e-4c05424f4588 */
DEFINE_GUID(IID_IDebugControl2, 0xd4366723, 0x44df, 0x4bed,
            0x8c, 0x7e, 0x4c, 0x05, 0x42, 0x4f, 0x45, 0x88);
/* 7df74a86-b03f-407f-90ab-a20dadcead08 */
DEFINE_GUID(IID_IDebugControl3, 0x7df74a86, 0xb03f, 0x407f,
            0x90, 0xab, 0xa2, 0x0d, 0xad, 0xce, 0xad, 0x08);
/* 94e60ce9-9b41-4b19-9fc0-6d9eb35272b3 */
DEFINE_GUID(IID_IDebugControl4, 0x94e60ce9, 0x9b41, 0x4b19,
            0x9f, 0xc0, 0x6d, 0x9e, 0xb3, 0x52, 0x72, 0xb3);
/* b2ffe162-2412-429f-8d1d-5bf6dd824696 */
DEFINE_GUID(IID_IDebugControl5, 0xb2ffe162, 0x2412, 0x429f,
            0x8d, 0x1d, 0x5b, 0xf6, 0xdd, 0x82, 0x46, 0x96);
/* bc0d583f-126d-43a1-9cc4-a860ab1d537b */
DEFINE_GUID(IID_IDebugControl6, 0xbc0d583f, 0x126d, 0x43a1,
            0x9c, 0xc4, 0xa8, 0x60, 0xab, 0x1d, 0x53, 0x7b);
/* b86fb3b1-80d4-475b-aea3-cf06539cf63a */
DEFINE_GUID(IID_IDebugControl7, 0xb86fb3b1, 0x80d4, 0x475b,
            0xae, 0xa3, 0xcf, 0x06, 0x53, 0x9c, 0xf6, 0x3a);
/* 88f7dfab-3ea7-4c3a-aefb-c4e8106173aa */
DEFINE_GUID(IID_IDebugDataSpaces, 0x88f7dfab, 0x3ea7, 0x4c3a,
            0xae, 0xfb, 0xc4, 0xe8, 0x10, 0x61, 0x73, 0xaa);
/* 7a5e852f-96e9-468f-ac1b-0b3addc4a049 */
DEFINE_GUID(IID_IDebugDataSpaces2, 0x7a5e852f, 0x96e9, 0x468f,
            0xac, 0x1b, 0x0b, 0x3a, 0xdd, 0xc4, 0xa0, 0x49);
/* 23f79d6c-8aaf-4f7c-a607-9995f5407e63 */
DEFINE_GUID(IID_IDebugDataSpaces3, 0x23f79d6c, 0x8aaf, 0x4f7c,
            0xa6, 0x07, 0x99, 0x95, 0xf5, 0x40, 0x7e, 0x63);
/* d98ada1f-29e9-4ef5-a6c0-e53349883212 */
DEFINE_GUID(IID_IDebugDataSpaces4, 0xd98ada1f, 0x29e9, 0x4ef5,
            0xa6, 0xc0, 0xe5, 0x33, 0x49, 0x88, 0x32, 0x12);
/* 337be28b-5036-4d72-b6bf-c45fbb9f2eaa */
DEFINE_GUID(IID_IDebugEventCallbacks, 0x337be28b, 0x5036, 0x4d72,
            0xb6, 0xbf, 0xc4, 0x5f, 0xbb, 0x9f, 0x2e, 0xaa);
/* 0690e046-9c23-45ac-a04f-987ac29ad0d3 */
DEFINE_GUID(IID_IDebugEventCallbacksWide, 0x0690e046, 0x9c23, 0x45ac,
            0xa0, 0x4f, 0x98, 0x7a, 0xc2, 0x9a, 0xd0, 0xd3);
/* 61a4905b-23f9-4247-b3c5-53d087529ab7 */
DEFINE_GUID(IID_IDebugEventContextCallbacks, 0x61a4905b, 0x23f9, 0x4247,
            0xb3, 0xc5, 0x53, 0xd0, 0x87, 0x52, 0x9a, 0xb7);
/* 9f50e42c-f136-499e-9a97-73036c94ed2d */
DEFINE_GUID(IID_IDebugInputCallbacks, 0x9f50e42c, 0xf136, 0x499e,
            0x9a, 0x97, 0x73, 0x03, 0x6c, 0x94, 0xed, 0x2d);
/* 4bf58045-d654-4c40-b0af-683090f356dc */
DEFINE_GUID(IID_IDebugOutputCallbacks, 0x4bf58045, 0xd654, 0x4c40,
            0xb0, 0xaf, 0x68, 0x30, 0x90, 0xf3, 0x56, 0xdc);
/* 4c7fd663-c394-4e26-8ef1-34ad5ed3764c */
DEFINE_GUID(IID_IDebugOutputCallbacksWide, 0x4c7fd663, 0xc394, 0x4e26,
            0x8e, 0xf1, 0x34, 0xad, 0x5e, 0xd3, 0x76, 0x4c);
/* 67721fe9-56d2-4a44-a325-2b65513ce6eb */
DEFINE_GUID(IID_IDebugOutputCallbacks2, 0x67721fe9, 0x56d2, 0x4a44,
            0xa3, 0x25, 0x2b, 0x65, 0x51, 0x3c, 0xe6, 0xeb);
/* ce289126-9e84-45a7-937e-67bb18691493 */
DEFINE_GUID(IID_IDebugRegisters, 0xce289126, 0x9e84, 0x45a7,
            0x93, 0x7e, 0x67, 0xbb, 0x18, 0x69, 0x14, 0x93);
/* 1656afa9-19c6-4e3a-97e7-5dc9160cf9c4 */
DEFINE_GUID(IID_IDebugRegisters2, 0x1656afa9, 0x19c6, 0x4e3a,
            0x97, 0xe7, 0x5d, 0xc9, 0x16, 0x0c, 0xf9, 0xc4);
/* f2528316-0f1a-4431-aeed-11d096e1e2ab */
DEFINE_GUID(IID_IDebugSymbolGroup, 0xf2528316, 0x0f1a, 0x4431,
            0xae, 0xed, 0x11, 0xd0, 0x96, 0xe1, 0xe2, 0xab);
/* 6a7ccc5f-fb5e-4dcc-b41c-6c20307bccc7 */
DEFINE_GUID(IID_IDebugSymbolGroup2, 0x6a7ccc5f, 0xfb5e, 0x4dcc,
            0xb4, 0x1c, 0x6c, 0x20, 0x30, 0x7b, 0xcc, 0xc7);
/* 8c31e98c-983a-48a5-9016-6fe5d667a950 */
DEFINE_GUID(IID_IDebugSymbols, 0x8c31e98c, 0x983a, 0x48a5,
            0x90, 0x16, 0x6f, 0xe5, 0xd6, 0x67, 0xa9, 0x50);
/* 3a707211-afdd-4495-ad4f-56fecdf8163f */
DEFINE_GUID(IID_IDebugSymbols2, 0x3a707211, 0xafdd, 0x4495,
            0xad, 0x4f, 0x56, 0xfe, 0xcd, 0xf8, 0x16, 0x3f);
/* f02fbecc-50ac-4f36-9ad9-c975e8f32ff8 */
DEFINE_GUID(IID_IDebugSymbols3, 0xf02fbecc, 0x50ac, 0x4f36,
            0x9a, 0xd9, 0xc9, 0x75, 0xe8, 0xf3, 0x2f, 0xf8);
/* e391bbd8-9d8c-4418-840b-c006592a1752 */
DEFINE_GUID(IID_IDebugSymbols4, 0xe391bbd8, 0x9d8c, 0x4418,
            0x84, 0x0b, 0xc0, 0x06, 0x59, 0x2a, 0x17, 0x52);
/* c65fa83e-1e69-475e-8e0e-b5d79e9cc17e */
DEFINE_GUID(IID_IDebugSymbols5, 0xc65fa83e, 0x1e69, 0x475e,
            0x8e, 0x0e, 0xb5, 0xd7, 0x9e, 0x9c, 0xc1, 0x7e);
/* 6b86fe2c-2c4f-4f0c-9da2-174311acc327 */
DEFINE_GUID(IID_IDebugSystemObjects, 0x6b86fe2c, 0x2c4f, 0x4f0c,
            0x9d, 0xa2, 0x17, 0x43, 0x11, 0xac, 0xc3, 0x27);
/* 0ae9f5ff-1852-4679-b055-494bee6407ee */
DEFINE_GUID(IID_IDebugSystemObjects2, 0x0ae9f5ff, 0x1852, 0x4679,
            0xb0, 0x55, 0x49, 0x4b, 0xee, 0x64, 0x07, 0xee);
/* e9676e2f-e286-4ea3-b0f9-dfe5d9fc330e */
DEFINE_GUID(IID_IDebugSystemObjects3, 0xe9676e2f, 0xe286, 0x4ea3,
            0xb0, 0xf9, 0xdf, 0xe5, 0xd9, 0xfc, 0x33, 0x0e);
/* 489468e6-7d0f-4af5-87ab-25207454d553 */
DEFINE_GUID(IID_IDebugSystemObjects4, 0x489468e6, 0x7d0f, 0x4af5,
            0x87, 0xab, 0x25, 0x20, 0x74, 0x54, 0xd5, 0x53);

typedef interface DECLSPEC_UUID("f2df5f53-071f-47bd-9de6-5734c3fed689")
    IDebugAdvanced* PDEBUG_ADVANCED;
typedef interface DECLSPEC_UUID("716d14c9-119b-4ba5-af1f-0890e672416a")
    IDebugAdvanced2* PDEBUG_ADVANCED2;
typedef interface DECLSPEC_UUID("cba4abb4-84c4-444d-87ca-a04e13286739")
    IDebugAdvanced3* PDEBUG_ADVANCED3;
typedef interface DECLSPEC_UUID("d1069067-2a65-4bf0-ae97-76184b67856b")
    IDebugAdvanced4* PDEBUG_ADVANCED4;
typedef interface DECLSPEC_UUID("5bd9d474-5975-423a-b88b-65a8e7110e65")
    IDebugBreakpoint* PDEBUG_BREAKPOINT;
typedef interface DECLSPEC_UUID("1b278d20-79f2-426e-a3f9-c1ddf375d48e")
    IDebugBreakpoint2* PDEBUG_BREAKPOINT2;
typedef interface DECLSPEC_UUID("38f5c249-b448-43bb-9835-579d4ec02249")
    IDebugBreakpoint3* PDEBUG_BREAKPOINT3;
typedef interface DECLSPEC_UUID("27fe5639-8407-4f47-8364-ee118fb08ac8")
    IDebugClient* PDEBUG_CLIENT;
typedef interface DECLSPEC_UUID("edbed635-372e-4dab-bbfe-ed0d2f63be81")
    IDebugClient2* PDEBUG_CLIENT2;
typedef interface DECLSPEC_UUID("dd492d7f-71b8-4ad6-a8dc-1c887479ff91")
    IDebugClient3* PDEBUG_CLIENT3;
typedef interface DECLSPEC_UUID("ca83c3de-5089-4cf8-93c8-d892387f2a5e")
    IDebugClient4* PDEBUG_CLIENT4;
typedef interface DECLSPEC_UUID("e3acb9d7-7ec2-4f0c-a0da-e81e0cbbe628")
    IDebugClient5* PDEBUG_CLIENT5;
typedef interface DECLSPEC_UUID("fd28b4c5-c498-4686-a28e-62cad2154eb3")
    IDebugClient6* PDEBUG_CLIENT6;
typedef interface DECLSPEC_UUID("13586be3-542e-481e-b1f2-8497ba74f9a9")
    IDebugClient7* PDEBUG_CLIENT7;
typedef interface DECLSPEC_UUID("CEC43ADD-6375-469e-83D5-414E4033C19A")
    IDebugClient8* PDEBUG_CLIENT8;
typedef interface DECLSPEC_UUID("2C24CD5B-4D9E-4DF4-8A70-3D37440D119F")
    IDebugClient9* PDEBUG_CLIENT9;
typedef interface DECLSPEC_UUID("a02b66c4-aea3-4234-a9f7-fe4c383d4e29")
    IDebugPlmClient* PIDEBUG_PLMCLIENT;
typedef interface DECLSPEC_UUID("597c980d-e7bd-4309-962c-9d9b69a7372c")
    IDebugPlmClient2* PIDEBUG_PLMCLIENT2;
typedef interface DECLSPEC_UUID("d4a5dbd1-ca02-4d90-856a-2a92bfd0f20f")
    IDebugPlmClient3* PIDEBUG_PLMCLIENT3;
typedef interface DECLSPEC_UUID("7782d8f2-2b85-4059-ab88-28ceddca1c80")
    IDebugOutputStream* PDEBUG_OUTPUT_STREAM;
typedef interface DECLSPEC_UUID("5182e668-105e-416e-ad92-24ef800424ba")
    IDebugControl* PDEBUG_CONTROL;
typedef interface DECLSPEC_UUID("d4366723-44df-4bed-8c7e-4c05424f4588")
    IDebugControl2* PDEBUG_CONTROL2;
typedef interface DECLSPEC_UUID("7df74a86-b03f-407f-90ab-a20dadcead08")
    IDebugControl3* PDEBUG_CONTROL3;
typedef interface DECLSPEC_UUID("94e60ce9-9b41-4b19-9fc0-6d9eb35272b3")
    IDebugControl4* PDEBUG_CONTROL4;
typedef interface DECLSPEC_UUID("b2ffe162-2412-429f-8d1d-5bf6dd824696")
    IDebugControl5* PDEBUG_CONTROL5;
typedef interface DECLSPEC_UUID("bc0d583f-126d-43a1-9cc4-a860ab1d537b")
    IDebugControl6* PDEBUG_CONTROL6;
typedef interface DECLSPEC_UUID("b86fb3b1-80d4-475b-aea3-cf06539cf63a")
    IDebugControl7* PDEBUG_CONTROL7;

typedef interface DECLSPEC_UUID("88f7dfab-3ea7-4c3a-aefb-c4e8106173aa")
    IDebugDataSpaces* PDEBUG_DATA_SPACES;
typedef interface DECLSPEC_UUID("7a5e852f-96e9-468f-ac1b-0b3addc4a049")
    IDebugDataSpaces2* PDEBUG_DATA_SPACES2;
typedef interface DECLSPEC_UUID("23f79d6c-8aaf-4f7c-a607-9995f5407e63")
    IDebugDataSpaces3* PDEBUG_DATA_SPACES3;
typedef interface DECLSPEC_UUID("d98ada1f-29e9-4ef5-a6c0-e53349883212")
    IDebugDataSpaces4* PDEBUG_DATA_SPACES4;
typedef interface DECLSPEC_UUID("337be28b-5036-4d72-b6bf-c45fbb9f2eaa")
    IDebugEventCallbacks* PDEBUG_EVENT_CALLBACKS;
typedef interface DECLSPEC_UUID("0690e046-9c23-45ac-a04f-987ac29ad0d3")
    IDebugEventCallbacksWide* PDEBUG_EVENT_CALLBACKS_WIDE;
typedef interface DECLSPEC_UUID("61a4905b-23f9-4247-b3c5-53d087529ab7")
    IDebugEventContextCallbacks* PDEBUG_EVENT_CONTEXT_CALLBACKS;
typedef interface DECLSPEC_UUID("9f50e42c-f136-499e-9a97-73036c94ed2d")
    IDebugInputCallbacks* PDEBUG_INPUT_CALLBACKS;
typedef interface DECLSPEC_UUID("4bf58045-d654-4c40-b0af-683090f356dc")
    IDebugOutputCallbacks* PDEBUG_OUTPUT_CALLBACKS;
typedef interface DECLSPEC_UUID("4c7fd663-c394-4e26-8ef1-34ad5ed3764c")
    IDebugOutputCallbacksWide* PDEBUG_OUTPUT_CALLBACKS_WIDE;
typedef interface DECLSPEC_UUID("67721fe9-56d2-4a44-a325-2b65513ce6eb")
    IDebugOutputCallbacks2* PDEBUG_OUTPUT_CALLBACKS2;
typedef interface DECLSPEC_UUID("ce289126-9e84-45a7-937e-67bb18691493")
    IDebugRegisters* PDEBUG_REGISTERS;
typedef interface DECLSPEC_UUID("1656afa9-19c6-4e3a-97e7-5dc9160cf9c4")
    IDebugRegisters2* PDEBUG_REGISTERS2;
typedef interface DECLSPEC_UUID("f2528316-0f1a-4431-aeed-11d096e1e2ab")
    IDebugSymbolGroup* PDEBUG_SYMBOL_GROUP;
typedef interface DECLSPEC_UUID("6a7ccc5f-fb5e-4dcc-b41c-6c20307bccc7")
    IDebugSymbolGroup2* PDEBUG_SYMBOL_GROUP2;
typedef interface DECLSPEC_UUID("8c31e98c-983a-48a5-9016-6fe5d667a950")
    IDebugSymbols* PDEBUG_SYMBOLS;
typedef interface DECLSPEC_UUID("3a707211-afdd-4495-ad4f-56fecdf8163f")
    IDebugSymbols2* PDEBUG_SYMBOLS2;
typedef interface DECLSPEC_UUID("f02fbecc-50ac-4f36-9ad9-c975e8f32ff8")
    IDebugSymbols3* PDEBUG_SYMBOLS3;
typedef interface DECLSPEC_UUID("e391bbd8-9d8c-4418-840b-c006592a1752")
    IDebugSymbols4* PDEBUG_SYMBOLS4;
typedef interface DECLSPEC_UUID("c65fa83e-1e69-475e-8e0e-b5d79e9cc17e")
    IDebugSymbols5* PDEBUG_SYMBOLS5;
typedef interface DECLSPEC_UUID("6b86fe2c-2c4f-4f0c-9da2-174311acc327")
    IDebugSystemObjects* PDEBUG_SYSTEM_OBJECTS;
typedef interface DECLSPEC_UUID("0ae9f5ff-1852-4679-b055-494bee6407ee")
    IDebugSystemObjects2* PDEBUG_SYSTEM_OBJECTS2;
typedef interface DECLSPEC_UUID("e9676e2f-e286-4ea3-b0f9-dfe5d9fc330e")
    IDebugSystemObjects3* PDEBUG_SYSTEM_OBJECTS3;
typedef interface DECLSPEC_UUID("489468e6-7d0f-4af5-87ab-25207454d553")
    IDebugSystemObjects4* PDEBUG_SYSTEM_OBJECTS4;

//----------------------------------------------------------------------------
//
// Macros.
//
//----------------------------------------------------------------------------

// Extends a 32-bit address into a 64-bit address.
#define DEBUG_EXTEND64(Addr) ((ULONG64)(LONG64)(LONG)(Addr))

//----------------------------------------------------------------------------
//
// Client creation functions.
//
//----------------------------------------------------------------------------

// RemoteOptions specifies connection types and
// their parameters.  Supported strings are:
//    npipe:Server=<Machine>,Pipe=<Pipe name>
//    tcp:Server=<Machine>,Port=<IP port>
STDAPI
DebugConnect(
    _In_ PCSTR RemoteOptions,
    _In_ REFIID InterfaceId,
    _Out_ PVOID* Interface
    );

STDAPI
DebugConnectWide(
    _In_ PCWSTR RemoteOptions,
    _In_ REFIID InterfaceId,
    _Out_ PVOID* Interface
    );

STDAPI
DebugCreate(
    _In_ REFIID InterfaceId,
    _Out_ PVOID* Interface
    );

STDAPI
DebugCreateEx(
    _In_ REFIID InterfaceId,
    _In_ DWORD  DbgEngOptions,
    _Out_ PVOID* Interface
    );

//----------------------------------------------------------------------------
//
// IDebugAdvanced.
//
//----------------------------------------------------------------------------

typedef struct _DEBUG_OFFSET_REGION
{
    ULONG64 Base;
    ULONG64 Size;
} DEBUG_OFFSET_REGION, *PDEBUG_OFFSET_REGION;

#undef INTERFACE
#define INTERFACE IDebugAdvanced
DECLARE_INTERFACE_(IDebugAdvanced, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugAdvanced.

    // Get/SetThreadContext offer control over
    // the full processor context for a thread.
    // Higher-level functions, such as the
    // IDebugRegisters interface, allow similar
    // access in simpler and more generic ways.
    // Get/SetThreadContext are useful when
    // large amounts of thread context must
    // be changed and processor-specific code
    // is not a problem.
    STDMETHOD(GetThreadContext)(
        THIS_
        _Out_writes_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    STDMETHOD(SetThreadContext)(
        THIS_
        _In_reads_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
};

typedef struct _DEBUG_READ_USER_MINIDUMP_STREAM
{
    IN ULONG StreamType;
    IN ULONG Flags;
    IN ULONG64 Offset;
    OUT PVOID Buffer;
    IN ULONG BufferSize;
    OUT ULONG BufferUsed;
} DEBUG_READ_USER_MINIDUMP_STREAM, *PDEBUG_READ_USER_MINIDUMP_STREAM;

#define DEBUG_GET_TEXT_COMPLETIONS_NO_DOT_COMMANDS       0x00000001
#define DEBUG_GET_TEXT_COMPLETIONS_NO_EXTENSION_COMMANDS 0x00000002
#define DEBUG_GET_TEXT_COMPLETIONS_NO_SYMBOLS            0x00000004

typedef struct _DEBUG_GET_TEXT_COMPLETIONS_IN
{
    ULONG Flags;
    ULONG MatchCountLimit;
    ULONG64 Reserved[3];
    // Input text string follows.
} DEBUG_GET_TEXT_COMPLETIONS_IN, *PDEBUG_GET_TEXT_COMPLETIONS_IN;

#define DEBUG_GET_TEXT_COMPLETIONS_IS_DOT_COMMAND       0x00000001
#define DEBUG_GET_TEXT_COMPLETIONS_IS_EXTENSION_COMMAND 0x00000002
#define DEBUG_GET_TEXT_COMPLETIONS_IS_SYMBOL            0x00000004

typedef struct _DEBUG_GET_TEXT_COMPLETIONS_OUT
{
    ULONG Flags;
    // Char index in input string where completions start.
    ULONG ReplaceIndex;
    ULONG MatchCount;
    ULONG Reserved1;
    ULONG64 Reserved2[2];
    // Completions follow.
    // Completion data is zero-terminated strings ended
    // by a final zero double-terminator.
} DEBUG_GET_TEXT_COMPLETIONS_OUT, *PDEBUG_GET_TEXT_COMPLETIONS_OUT;

typedef struct _DEBUG_CACHED_SYMBOL_INFO
{
    ULONG64 ModBase;
    ULONG64 Arg1;
    ULONG64 Arg2;
    ULONG Id;
    ULONG Arg3;
} DEBUG_CACHED_SYMBOL_INFO, *PDEBUG_CACHED_SYMBOL_INFO;

typedef struct _PROCESS_NAME_ENTRY
{
    ULONG ProcessId;
    ULONG NameOffset;  // offset for the process name string.
    ULONG NameSize;    // ProcessName will always be NULL terminated, NameSize is for struct align and safeguard.
    ULONG NextEntry;   // offset for next entry, 0 if the last.
} PROCESS_NAME_ENTRY, *PPROCESS_NAME_ENTRY;

//
// Request requests.
//

// InBuffer - Unused.
// OutBuffer - Unused.
#define DEBUG_REQUEST_SOURCE_PATH_HAS_SOURCE_SERVER 0

// InBuffer - Unused.
// OutBuffer - Machine-specific CONTEXT.
#define DEBUG_REQUEST_TARGET_EXCEPTION_CONTEXT 1

// InBuffer - Unused.
// OutBuffer - ULONG system ID of thread.
#define DEBUG_REQUEST_TARGET_EXCEPTION_THREAD 2

// InBuffer - Unused.
// OutBuffer - EXCEPTION_RECORD64.
#define DEBUG_REQUEST_TARGET_EXCEPTION_RECORD 3

// InBuffer - Unused.
// OutBuffer - DEBUG_CREATE_PROCESS_OPTIONS.
#define DEBUG_REQUEST_GET_ADDITIONAL_CREATE_OPTIONS 4

// InBuffer - DEBUG_CREATE_PROCESS_OPTIONS.
// OutBuffer - Unused.
#define DEBUG_REQUEST_SET_ADDITIONAL_CREATE_OPTIONS 5

// InBuffer - Unused.
// OutBuffer - ULONG[2] major/minor.
#define DEBUG_REQUEST_GET_WIN32_MAJOR_MINOR_VERSIONS 6

// InBuffer - DEBUG_READ_USER_MINIDUMP_STREAM.
// OutBuffer - Unused.
#define DEBUG_REQUEST_READ_USER_MINIDUMP_STREAM 7

// InBuffer - Unused.
// OutBuffer - Unused.
#define DEBUG_REQUEST_TARGET_CAN_DETACH 8

// InBuffer - PTSTR.
// OutBuffer - Unused.
#define DEBUG_REQUEST_SET_LOCAL_IMPLICIT_COMMAND_LINE 9

// InBuffer - Unused.
// OutBuffer - Event code stream offset.
#define DEBUG_REQUEST_GET_CAPTURED_EVENT_CODE_OFFSET 10

// InBuffer - Unused.
// OutBuffer - Event code stream information.
#define DEBUG_REQUEST_READ_CAPTURED_EVENT_CODE_STREAM 11

// InBuffer - Input data block.
// OutBuffer - Processed data block.
#define DEBUG_REQUEST_EXT_TYPED_DATA_ANSI 12

// InBuffer - Unused.
// OutBuffer - Returned path.
#define DEBUG_REQUEST_GET_EXTENSION_SEARCH_PATH_WIDE 13

// InBuffer - DEBUG_GET_TEXT_COMPLETIONS_IN.
// OutBuffer - DEBUG_GET_TEXT_COMPLETIONS_OUT.
#define DEBUG_REQUEST_GET_TEXT_COMPLETIONS_WIDE 14

// InBuffer - ULONG64 cookie.
// OutBuffer - DEBUG_CACHED_SYMBOL_INFO.
#define DEBUG_REQUEST_GET_CACHED_SYMBOL_INFO 15

// InBuffer - DEBUG_CACHED_SYMBOL_INFO.
// OutBuffer - ULONG64 cookie.
#define DEBUG_REQUEST_ADD_CACHED_SYMBOL_INFO 16

// InBuffer - ULONG64 cookie.
// OutBuffer - Unused.
#define DEBUG_REQUEST_REMOVE_CACHED_SYMBOL_INFO 17

// InBuffer - DEBUG_GET_TEXT_COMPLETIONS_IN.
// OutBuffer - DEBUG_GET_TEXT_COMPLETIONS_OUT.
#define DEBUG_REQUEST_GET_TEXT_COMPLETIONS_ANSI 18

// InBuffer - Unused.
// OutBuffer - Unused.
#define DEBUG_REQUEST_CURRENT_OUTPUT_CALLBACKS_ARE_DML_AWARE 19

// InBuffer - ULONG64 offset.
// OutBuffer - Unwind information.
#define DEBUG_REQUEST_GET_OFFSET_UNWIND_INFORMATION 20

// InBuffer - Unused
// OutBuffer - returned DUMP_HEADER32/DUMP_HEADER64 structure.
#define DEBUG_REQUEST_GET_DUMP_HEADER 21

// InBuffer - DUMP_HEADER32/DUMP_HEADER64 structure.
// OutBuffer - Unused
#define DEBUG_REQUEST_SET_DUMP_HEADER 22

// InBuffer - Midori specific
// OutBuffer - Midori specific
#define DEBUG_REQUEST_MIDORI 23

// InBuffer - Unused
// OutBuffer - PROCESS_NAME_ENTRY blocks
#define DEBUG_REQUEST_PROCESS_DESCRIPTORS 24

// InBuffer - Unused
// OutBuffer - MINIDUMP_MISC_INFO_N blocks
#define DEBUG_REQUEST_MISC_INFORMATION 25

// InBuffer - Unused
// OutBuffer - ULONG64 as TokenHandle value
#define DEBUG_REQUEST_OPEN_PROCESS_TOKEN 26

// InBuffer - Unused
// OutBuffer - ULONG64 as TokenHandle value
#define DEBUG_REQUEST_OPEN_THREAD_TOKEN 27

// InBuffer -  ULONG64 as TokenHandle being duplicated
// OutBuffer - ULONG64 as new duplicated TokenHandle
#define DEBUG_REQUEST_DUPLICATE_TOKEN 28

// InBuffer - a ULONG64 as TokenHandle and a ULONG as NtQueryInformationToken() request code
// OutBuffer - NtQueryInformationToken() return
#define DEBUG_REQUEST_QUERY_INFO_TOKEN 29

// InBuffer - ULONG64 as TokenHandle
// OutBuffer - Unused
#define DEBUG_REQUEST_CLOSE_TOKEN 30

// InBuffer - ULONG64 for process server identification and ULONG as PID
// OutBuffer - Unused
#define DEBUG_REQUEST_WOW_PROCESS 31

// InBuffer - ULONG64 for process server identification and PWSTR as module path
// OutBuffer - Unused
#define DEBUG_REQUEST_WOW_MODULE 32

// InBuffer - Unused
// OutBuffer - Unused
// return - S_OK if non-invasive user-mode attach, S_FALSE if not (but still live user-mode), E_FAIL otherwise.
#define DEBUG_LIVE_USER_NON_INVASIVE 33

// InBuffer - TID
// OutBuffer - Unused
// return - ResumeThreads() return.
#define DEBUG_REQUEST_RESUME_THREAD 34

// InBuffer - LONG32 - 0:query current state; >0:enable inline queries; <0: disable inline queries
// OutBuffer - Unused
// return - S_OK: inline queries are enabled; S_FALSE: inline queries are disabled; others: errors.
#define DEBUG_REQUEST_INLINE_QUERY 35

// InBuffer - Unused
// OutBuffer - Unused
// return - S_OK.
#define DEBUG_REQUEST_TL_INSTRUMENTATION_AWARE 36

// InBuffer - Unused
// OutBuffer - ULONG for version number supported
// return - S_OK.
#define DEBUG_REQUEST_GET_INSTRUMENTATION_VERSION 37

// InBuffer - ULONG for module index
// OutBuffer - ULONG for architecture
// return - S_OK
#define DEBUG_REQUEST_GET_MODULE_ARCHITECTURE 38

// InBuffer - ULONG64 for process server identification and PWSTR as module path
// OutBuffer - ULONG for architecture
#define DEBUG_REQUEST_GET_IMAGE_ARCHITECTURE 39

// InBuffer - HWND for the new parent
// OutBuffer - HWND for the old parent window
#define DEBUG_REQUEST_SET_PARENT_HWND 40

//
// GetSourceFileInformation requests.
//

// Arg64 - Module base.
// Arg32 - Unused.
#define DEBUG_SRCFILE_SYMBOL_TOKEN 0

// Arg64 - Module base.
// Arg32 - Unused.
#define DEBUG_SRCFILE_SYMBOL_TOKEN_SOURCE_COMMAND_WIDE 1

// Arg64 - Module base.
// Arg32 - Unused
#define DEBUG_SRCFILE_SYMBOL_CHECKSUMINFO 2

//
// GetSymbolInformation requests.
//

// Arg64 - Unused.
// Arg32 - Breakpoint ID.
// Buffer - ULONG line number.
// String - File name.
#define DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE 0

// Arg64 - Module base.
// Arg32 - Unused.
// Buffer - IMAGEHLP_MODULEW64.
// String - Unused.
#define DEBUG_SYMINFO_IMAGEHLP_MODULEW64 1

// Arg64 - Offset.
// Arg32 - Symbol tag.
// Buffer - Unicode symbol name strings.  Could have multiple strings.
// String - Unused, strings are returned in Buffer as there
//          may be more than one.
#define DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE 2

// Arg64 - Module base.
// Arg32 - Symbol tag.
// Buffer - Array of symbol addresses.
// String - Concatenated symbol strings.  Individual symbol
//          strings are zero-terminated and the final string in
//          a symbol is double-zero-terminated.
#define DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS 3

//
// GetSystemObjectInformation requests.
//

// Arg64 - Unused.
// Arg32 - Debugger thread ID.
// Buffer - DEBUG_THREAD_BASIC_INFORMATION.
#define DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION 0

// Arg64 - Unused.
// Arg32 - Debugger thread ID.
// Buffer - Unicode name string.
#define DEBUG_SYSOBJINFO_THREAD_NAME_WIDE 1

// Arg64 - Unused.
// Arg32 - Unused.
// Buffer - ULONG cookie value.
#define DEBUG_SYSOBJINFO_CURRENT_PROCESS_COOKIE 2

#define DEBUG_TBINFO_EXIT_STATUS    0x00000001
#define DEBUG_TBINFO_PRIORITY_CLASS 0x00000002
#define DEBUG_TBINFO_PRIORITY       0x00000004
#define DEBUG_TBINFO_TIMES          0x00000008
#define DEBUG_TBINFO_START_OFFSET   0x00000010
#define DEBUG_TBINFO_AFFINITY       0x00000020
#define DEBUG_TBINFO_ALL            0x0000003f

typedef struct _DEBUG_THREAD_BASIC_INFORMATION
{
    // Valid members have a DEBUG_TBINFO bit set in Valid.
    ULONG Valid;
    ULONG ExitStatus;
    ULONG PriorityClass;
    ULONG Priority;
    ULONG64 CreateTime;
    ULONG64 ExitTime;
    ULONG64 KernelTime;
    ULONG64 UserTime;
    ULONG64 StartOffset;
    ULONG64 Affinity;
} DEBUG_THREAD_BASIC_INFORMATION, *PDEBUG_THREAD_BASIC_INFORMATION;

#undef INTERFACE
#define INTERFACE IDebugAdvanced2
DECLARE_INTERFACE_(IDebugAdvanced2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugAdvanced.

    // Get/SetThreadContext offer control over
    // the full processor context for a thread.
    // Higher-level functions, such as the
    // IDebugRegisters interface, allow similar
    // access in simpler and more generic ways.
    // Get/SetThreadContext are useful when
    // large amounts of thread context must
    // be changed and processor-specific code
    // is not a problem.
    STDMETHOD(GetThreadContext)(
        THIS_
        _Out_writes_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    STDMETHOD(SetThreadContext)(
        THIS_
        _In_reads_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // IDebugAdvanced2.

    //
    // Generalized open-ended methods for querying
    // and manipulation.  The open-ended nature of
    // these methods makes it easy to add new requests,
    // although at a cost in convenience of calling.
    // Sufficiently common requests may have more specific,
    // simpler methods elsewhere.
    //

    STDMETHOD(Request)(
        THIS_
        _In_ ULONG Request,
        _In_reads_bytes_opt_(InBufferSize) PVOID InBuffer,
        _In_ ULONG InBufferSize,
        _Out_writes_bytes_opt_(OutBufferSize) PVOID OutBuffer,
        _In_ ULONG OutBufferSize,
        _Out_opt_ PULONG OutSize
        ) PURE;

    STDMETHOD(GetSourceFileInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ PSTR SourceFile,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;
    STDMETHOD(FindSourceFileAndToken)(
        THIS_
        _In_ ULONG StartElement,
        _In_ ULONG64 ModAddr,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _In_reads_bytes_opt_(FileTokenSize) PVOID FileToken,
        _In_ ULONG FileTokenSize,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;

    STDMETHOD(GetSymbolInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize,
        _Out_writes_opt_(StringBufferSize) PSTR StringBuffer,
        _In_ ULONG StringBufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    STDMETHOD(GetSystemObjectInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugAdvanced3
DECLARE_INTERFACE_(IDebugAdvanced3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugAdvanced.

    // Get/SetThreadContext offer control over
    // the full processor context for a thread.
    // Higher-level functions, such as the
    // IDebugRegisters interface, allow similar
    // access in simpler and more generic ways.
    // Get/SetThreadContext are useful when
    // large amounts of thread context must
    // be changed and processor-specific code
    // is not a problem.
    STDMETHOD(GetThreadContext)(
        THIS_
        _Out_writes_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    STDMETHOD(SetThreadContext)(
        THIS_
        _In_reads_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // IDebugAdvanced2.

    //
    // Generalized open-ended methods for querying
    // and manipulation.  The open-ended nature of
    // these methods makes it easy to add new requests,
    // although at a cost in convenience of calling.
    // Sufficiently common requests may have more specific,
    // simpler methods elsewhere.
    //

    STDMETHOD(Request)(
        THIS_
        _In_ ULONG Request,
        _In_reads_bytes_opt_(InBufferSize) PVOID InBuffer,
        _In_ ULONG InBufferSize,
        _Out_writes_bytes_opt_(OutBufferSize) PVOID OutBuffer,
        _In_ ULONG OutBufferSize,
        _Out_opt_ PULONG OutSize
        ) PURE;

    STDMETHOD(GetSourceFileInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ PSTR SourceFile,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;
    STDMETHOD(FindSourceFileAndToken)(
        THIS_
        _In_ ULONG StartElement,
        _In_ ULONG64 ModAddr,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _In_reads_bytes_opt_(FileTokenSize) PVOID FileToken,
        _In_ ULONG FileTokenSize,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;

    STDMETHOD(GetSymbolInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize,
        _Out_writes_opt_(StringBufferSize) PSTR StringBuffer,
        _In_ ULONG StringBufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    STDMETHOD(GetSystemObjectInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;

    // IDebugAdvanced3.

    STDMETHOD(GetSourceFileInformationWide)(
        THIS_
        _In_ ULONG Which,
        _In_ PWSTR SourceFile,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;
    STDMETHOD(FindSourceFileAndTokenWide)(
        THIS_
        _In_ ULONG StartElement,
        _In_ ULONG64 ModAddr,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _In_reads_bytes_opt_(FileTokenSize) PVOID FileToken,
        _In_ ULONG FileTokenSize,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;

    STDMETHOD(GetSymbolInformationWide)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize,
        _Out_writes_opt_(StringBufferSize) PWSTR StringBuffer,
        _In_ ULONG StringBufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
};

//
//  Extended line symbol information.
//
typedef struct _SYMBOL_INFO_EX
{
    ULONG   SizeOfStruct;       // Set to sizeof(SYMBOL_INFO_EX).
    ULONG   TypeOfInfo;         // Type of the symbol information stored (Ex. DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE)
    ULONG64 Offset;             // Address of the line.
    ULONG   Line;               // First line number that does not correspond to a compiler added glue lines.
    ULONG   Displacement;       // Line displacement: Offset between given address and the first instruction of the line.
    ULONG   Reserved[4];
} SYMBOL_INFO_EX, *PSYMBOL_INFO_EX;

#undef INTERFACE
#define INTERFACE IDebugAdvanced4
DECLARE_INTERFACE_(IDebugAdvanced4, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugAdvanced.

    // Get/SetThreadContext offer control over
    // the full processor context for a thread.
    // Higher-level functions, such as the
    // IDebugRegisters interface, allow similar
    // access in simpler and more generic ways.
    // Get/SetThreadContext are useful when
    // large amounts of thread context must
    // be changed and processor-specific code
    // is not a problem.
    STDMETHOD(GetThreadContext)(
        THIS_
        _Out_writes_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    STDMETHOD(SetThreadContext)(
        THIS_
        _In_reads_bytes_(ContextSize) /* align_is(16) */ PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // IDebugAdvanced2.

    //
    // Generalized open-ended methods for querying
    // and manipulation.  The open-ended nature of
    // these methods makes it easy to add new requests,
    // although at a cost in convenience of calling.
    // Sufficiently common requests may have more specific,
    // simpler methods elsewhere.
    //

    STDMETHOD(Request)(
        THIS_
        _In_ ULONG Request,
        _In_reads_bytes_opt_(InBufferSize) PVOID InBuffer,
        _In_ ULONG InBufferSize,
        _Out_writes_bytes_opt_(OutBufferSize) PVOID OutBuffer,
        _In_ ULONG OutBufferSize,
        _Out_opt_ PULONG OutSize
        ) PURE;

    STDMETHOD(GetSourceFileInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ PSTR SourceFile,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;
    STDMETHOD(FindSourceFileAndToken)(
        THIS_
        _In_ ULONG StartElement,
        _In_ ULONG64 ModAddr,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _In_reads_bytes_opt_(FileTokenSize) PVOID FileToken,
        _In_ ULONG FileTokenSize,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;

    STDMETHOD(GetSymbolInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize,
        _Out_writes_opt_(StringBufferSize) PSTR StringBuffer,
        _In_ ULONG StringBufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    STDMETHOD(GetSystemObjectInformation)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;

    // IDebugAdvanced3.

    STDMETHOD(GetSourceFileInformationWide)(
        THIS_
        _In_ ULONG Which,
        _In_ PWSTR SourceFile,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;
    STDMETHOD(FindSourceFileAndTokenWide)(
        THIS_
        _In_ ULONG StartElement,
        _In_ ULONG64 ModAddr,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _In_reads_bytes_opt_(FileTokenSize) PVOID FileToken,
        _In_ ULONG FileTokenSize,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;

    STDMETHOD(GetSymbolInformationWide)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize,
        _Out_writes_opt_(StringBufferSize) PWSTR StringBuffer,
        _In_ ULONG StringBufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    // IDebugAdvanced4.

    STDMETHOD(GetSymbolInformationWideEx)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG64 Arg64,
        _In_ ULONG Arg32,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize,
        _Out_writes_opt_(StringBufferSize) PWSTR StringBuffer,
        _In_ ULONG StringBufferSize,
        _Out_opt_ PULONG StringSize,
        _Out_opt_ PSYMBOL_INFO_EX pInfoEx
        ) PURE;

};

//----------------------------------------------------------------------------
//
// IDebugBreakpoint.
//
//----------------------------------------------------------------------------

// Types of breakpoints.
#define DEBUG_BREAKPOINT_CODE 0
#define DEBUG_BREAKPOINT_DATA 1
#define DEBUG_BREAKPOINT_TIME 2
#define DEBUG_BREAKPOINT_INLINE 3

// Breakpoint flags.
// Go-only breakpoints are only active when
// the engine is in unrestricted execution
// mode.  They do not fire when the engine
// is stepping.
#define DEBUG_BREAKPOINT_GO_ONLY    0x00000001
// A breakpoint is flagged as deferred as long as
// its offset expression cannot be evaluated.
// A deferred breakpoint is not active.
#define DEBUG_BREAKPOINT_DEFERRED   0x00000002
#define DEBUG_BREAKPOINT_ENABLED    0x00000004
// The adder-only flag does not affect breakpoint
// operation.  It is just a marker to restrict
// output and notifications for the breakpoint to
// the client that added the breakpoint.  Breakpoint
// callbacks for adder-only breaks will only be delivered
// to the adding client.  The breakpoint can not
// be enumerated and accessed by other clients.
#define DEBUG_BREAKPOINT_ADDER_ONLY 0x00000008
// One-shot breakpoints automatically clear themselves
// the first time they are hit.
#define DEBUG_BREAKPOINT_ONE_SHOT   0x00000010

// Data breakpoint access types.
// Different architectures support different
// sets of these bits.
#define DEBUG_BREAK_READ    0x00000001
#define DEBUG_BREAK_WRITE   0x00000002
#define DEBUG_BREAK_EXECUTE 0x00000004
#define DEBUG_BREAK_IO      0x00000008

// Structure for querying breakpoint information
// all at once.
typedef struct _DEBUG_BREAKPOINT_PARAMETERS
{
    ULONG64 Offset;
    ULONG Id;
    ULONG BreakType;
    ULONG ProcType;
    ULONG Flags;
    ULONG DataSize;
    ULONG DataAccessType;
    ULONG PassCount;
    ULONG CurrentPassCount;
    ULONG MatchThread;
    ULONG CommandSize;
    ULONG OffsetExpressionSize;
} DEBUG_BREAKPOINT_PARAMETERS, *PDEBUG_BREAKPOINT_PARAMETERS;

#undef INTERFACE
#define INTERFACE IDebugBreakpoint
DECLARE_INTERFACE_(IDebugBreakpoint, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugBreakpoint.

    // Retrieves debugger engine unique ID
    // for the breakpoint.  This ID is
    // fixed as long as the breakpoint exists
    // but after that may be reused.
    STDMETHOD(GetId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    // Retrieves the type of break and
    // processor type for the breakpoint.
    STDMETHOD(GetType)(
        THIS_
        _Out_ PULONG BreakType,
        _Out_ PULONG ProcType
        ) PURE;
    // Returns the client that called AddBreakpoint.
    STDMETHOD(GetAdder)(
        THIS_
        _Out_ PDEBUG_CLIENT* Adder
        ) PURE;

    STDMETHOD(GetFlags)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    // Only certain flags can be changed.  Flags
    // are: GO_ONLY, ENABLE.
    // Sets the given flags.
    STDMETHOD(AddFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Clears the given flags.
    STDMETHOD(RemoveFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Sets the flags.
    STDMETHOD(SetFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;

    // Controls the offset of the breakpoint.  The
    // interpretation of the offset value depends on
    // the type of breakpoint and its settings.  It
    // may be a code address, a data address, an
    // I/O port, etc.
    STDMETHOD(GetOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;

    // Data breakpoint methods will fail if the
    // target platform does not support the
    // parameters used.
    // These methods only function for breakpoints
    // created as data breakpoints.
    STDMETHOD(GetDataParameters)(
        THIS_
        _Out_ PULONG Size,
        _Out_ PULONG AccessType
        ) PURE;
    STDMETHOD(SetDataParameters)(
        THIS_
        _In_ ULONG Size,
        _In_ ULONG AccessType
        ) PURE;

    // Pass count defaults to one.
    STDMETHOD(GetPassCount)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(SetPassCount)(
        THIS_
        _In_ ULONG Count
        ) PURE;
    // Gets the current number of times
    // the breakpoint has been hit since
    // it was last triggered.
    STDMETHOD(GetCurrentPassCount)(
        THIS_
        _Out_ PULONG Count
        ) PURE;

    // If a match thread is set this breakpoint will
    // only trigger if it occurs on the match thread.
    // Otherwise it triggers for all threads.
    // Thread restrictions are not currently supported
    // in kernel mode.
    STDMETHOD(GetMatchThreadId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetMatchThreadId)(
        THIS_
        _In_ ULONG Thread
        ) PURE;

    // The command for a breakpoint is automatically
    // executed by the engine before the event
    // is propagated.  If the breakpoint continues
    // execution the event will begin with a continue
    // status.  If the breakpoint does not continue
    // the event will begin with a break status.
    // This allows breakpoint commands to participate
    // in the normal event status voting.
    // Breakpoint commands are only executed until
    // the first command that alters the execution
    // status, such as g, p and t.
    STDMETHOD(GetCommand)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetCommand)(
        THIS_
        _In_ PCSTR Command
        ) PURE;

    // Offset expressions are evaluated immediately
    // and at module load and unload events.  If the
    // evaluation is successful the breakpoints
    // offset is updated and the breakpoint is
    // handled normally.  If the expression cannot
    // be evaluated the breakpoint is deferred.
    // Currently the only offset expression
    // supported is a module-relative symbol
    // of the form <Module>!<Symbol>.
    STDMETHOD(GetOffsetExpression)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExpressionSize
        ) PURE;
    STDMETHOD(SetOffsetExpression)(
        THIS_
        _In_ PCSTR Expression
        ) PURE;

    STDMETHOD(GetParameters)(
        THIS_
        _Out_ PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugBreakpoint2
DECLARE_INTERFACE_(IDebugBreakpoint2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugBreakpoint.

    // Retrieves debugger engine unique ID
    // for the breakpoint.  This ID is
    // fixed as long as the breakpoint exists
    // but after that may be reused.
    STDMETHOD(GetId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    // Retrieves the type of break and
    // processor type for the breakpoint.
    STDMETHOD(GetType)(
        THIS_
        _Out_ PULONG BreakType,
        _Out_ PULONG ProcType
        ) PURE;
    // Returns the client that called AddBreakpoint.
    STDMETHOD(GetAdder)(
        THIS_
        _Out_ PDEBUG_CLIENT* Adder
        ) PURE;

    STDMETHOD(GetFlags)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    // Only certain flags can be changed.  Flags
    // are: GO_ONLY, ENABLE.
    // Sets the given flags.
    STDMETHOD(AddFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Clears the given flags.
    STDMETHOD(RemoveFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Sets the flags.
    STDMETHOD(SetFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;

    // Controls the offset of the breakpoint.  The
    // interpretation of the offset value depends on
    // the type of breakpoint and its settings.  It
    // may be a code address, a data address, an
    // I/O port, etc.
    STDMETHOD(GetOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;

    // Data breakpoint methods will fail if the
    // target platform does not support the
    // parameters used.
    // These methods only function for breakpoints
    // created as data breakpoints.
    STDMETHOD(GetDataParameters)(
        THIS_
        _Out_ PULONG Size,
        _Out_ PULONG AccessType
        ) PURE;
    STDMETHOD(SetDataParameters)(
        THIS_
        _In_ ULONG Size,
        _In_ ULONG AccessType
        ) PURE;

    // Pass count defaults to one.
    STDMETHOD(GetPassCount)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(SetPassCount)(
        THIS_
        _In_ ULONG Count
        ) PURE;
    // Gets the current number of times
    // the breakpoint has been hit since
    // it was last triggered.
    STDMETHOD(GetCurrentPassCount)(
        THIS_
        _Out_ PULONG Count
        ) PURE;

    // If a match thread is set this breakpoint will
    // only trigger if it occurs on the match thread.
    // Otherwise it triggers for all threads.
    // Thread restrictions are not currently supported
    // in kernel mode.
    STDMETHOD(GetMatchThreadId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetMatchThreadId)(
        THIS_
        _In_ ULONG Thread
        ) PURE;

    // The command for a breakpoint is automatically
    // executed by the engine before the event
    // is propagated.  If the breakpoint continues
    // execution the event will begin with a continue
    // status.  If the breakpoint does not continue
    // the event will begin with a break status.
    // This allows breakpoint commands to participate
    // in the normal event status voting.
    // Breakpoint commands are only executed until
    // the first command that alters the execution
    // status, such as g, p and t.
    STDMETHOD(GetCommand)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetCommand)(
        THIS_
        _In_ PCSTR Command
        ) PURE;

    // Offset expressions are evaluated immediately
    // and at module load and unload events.  If the
    // evaluation is successful the breakpoints
    // offset is updated and the breakpoint is
    // handled normally.  If the expression cannot
    // be evaluated the breakpoint is deferred.
    // Currently the only offset expression
    // supported is a module-relative symbol
    // of the form <Module>!<Symbol>.
    STDMETHOD(GetOffsetExpression)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExpressionSize
        ) PURE;
    STDMETHOD(SetOffsetExpression)(
        THIS_
        _In_ PCSTR Expression
        ) PURE;

    STDMETHOD(GetParameters)(
        THIS_
        _Out_ PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;

    // IDebugBreakpoint2.

    STDMETHOD(GetCommandWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetCommandWide)(
        THIS_
        _In_ PCWSTR Command
        ) PURE;

    STDMETHOD(GetOffsetExpressionWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExpressionSize
        ) PURE;
    STDMETHOD(SetOffsetExpressionWide)(
        THIS_
        _In_ PCWSTR Expression
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugBreakpoint3
DECLARE_INTERFACE_(IDebugBreakpoint3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugBreakpoint.

    // Retrieves debugger engine unique ID
    // for the breakpoint.  This ID is
    // fixed as long as the breakpoint exists
    // but after that may be reused.
    STDMETHOD(GetId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    // Retrieves the type of break and
    // processor type for the breakpoint.
    STDMETHOD(GetType)(
        THIS_
        _Out_ PULONG BreakType,
        _Out_ PULONG ProcType
        ) PURE;
    // Returns the client that called AddBreakpoint.
    STDMETHOD(GetAdder)(
        THIS_
        _Out_ PDEBUG_CLIENT* Adder
        ) PURE;

    STDMETHOD(GetFlags)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    // Only certain flags can be changed.  Flags
    // are: GO_ONLY, ENABLE.
    // Sets the given flags.
    STDMETHOD(AddFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Clears the given flags.
    STDMETHOD(RemoveFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Sets the flags.
    STDMETHOD(SetFlags)(
        THIS_
        _In_ ULONG Flags
        ) PURE;

    // Controls the offset of the breakpoint.  The
    // interpretation of the offset value depends on
    // the type of breakpoint and its settings.  It
    // may be a code address, a data address, an
    // I/O port, etc.
    STDMETHOD(GetOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;

    // Data breakpoint methods will fail if the
    // target platform does not support the
    // parameters used.
    // These methods only function for breakpoints
    // created as data breakpoints.
    STDMETHOD(GetDataParameters)(
        THIS_
        _Out_ PULONG Size,
        _Out_ PULONG AccessType
        ) PURE;
    STDMETHOD(SetDataParameters)(
        THIS_
        _In_ ULONG Size,
        _In_ ULONG AccessType
        ) PURE;

    // Pass count defaults to one.
    STDMETHOD(GetPassCount)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(SetPassCount)(
        THIS_
        _In_ ULONG Count
        ) PURE;
    // Gets the current number of times
    // the breakpoint has been hit since
    // it was last triggered.
    STDMETHOD(GetCurrentPassCount)(
        THIS_
        _Out_ PULONG Count
        ) PURE;

    // If a match thread is set this breakpoint will
    // only trigger if it occurs on the match thread.
    // Otherwise it triggers for all threads.
    // Thread restrictions are not currently supported
    // in kernel mode.
    STDMETHOD(GetMatchThreadId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetMatchThreadId)(
        THIS_
        _In_ ULONG Thread
        ) PURE;

    // The command for a breakpoint is automatically
    // executed by the engine before the event
    // is propagated.  If the breakpoint continues
    // execution the event will begin with a continue
    // status.  If the breakpoint does not continue
    // the event will begin with a break status.
    // This allows breakpoint commands to participate
    // in the normal event status voting.
    // Breakpoint commands are only executed until
    // the first command that alters the execution
    // status, such as g, p and t.
    STDMETHOD(GetCommand)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetCommand)(
        THIS_
        _In_ PCSTR Command
        ) PURE;

    // Offset expressions are evaluated immediately
    // and at module load and unload events.  If the
    // evaluation is successful the breakpoints
    // offset is updated and the breakpoint is
    // handled normally.  If the expression cannot
    // be evaluated the breakpoint is deferred.
    // Currently the only offset expression
    // supported is a module-relative symbol
    // of the form <Module>!<Symbol>.
    STDMETHOD(GetOffsetExpression)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExpressionSize
        ) PURE;
    STDMETHOD(SetOffsetExpression)(
        THIS_
        _In_ PCSTR Expression
        ) PURE;

    STDMETHOD(GetParameters)(
        THIS_
        _Out_ PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;

    // IDebugBreakpoint2.

    STDMETHOD(GetCommandWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetCommandWide)(
        THIS_
        _In_ PCWSTR Command
        ) PURE;

    STDMETHOD(GetOffsetExpressionWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExpressionSize
        ) PURE;
    STDMETHOD(SetOffsetExpressionWide)(
        THIS_
        _In_ PCWSTR Expression
        ) PURE;

    // IDebugBreakpoint3.

    STDMETHOD(GetGuid)(
        THIS_
        _Out_ LPGUID Guid
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugClient.
//
//----------------------------------------------------------------------------

// Kernel attach flags.
#define DEBUG_ATTACH_KERNEL_CONNECTION 0x00000000
// Attach to the local machine.  If this flag is not set
// a connection is made to a separate target machine using
// the given connection options.
#define DEBUG_ATTACH_LOCAL_KERNEL      0x00000001
// Attach to an eXDI driver.
#define DEBUG_ATTACH_EXDI_DRIVER       0x00000002
// Just install client-side transpotr drivers
#define DEBUG_ATTACH_INSTALL_DRIVER    0x00000004

// GetRunningProcessSystemIdByExecutableName flags.
// By default the match allows a tail match on
// just the filename.  The match returns the first hit
// even if multiple matches exist.
#define DEBUG_GET_PROC_DEFAULT      0x00000000
// The name must match fully.
#define DEBUG_GET_PROC_FULL_MATCH   0x00000001
// The match must be the only match.
#define DEBUG_GET_PROC_ONLY_MATCH   0x00000002
// The name is a service name instead of an executable name.
#define DEBUG_GET_PROC_SERVICE_NAME 0x00000004

// GetRunningProcessDescription flags.
#define DEBUG_PROC_DESC_DEFAULT         0x00000000
// Return only filenames, not full paths.
#define DEBUG_PROC_DESC_NO_PATHS        0x00000001
// Dont look up service names.
#define DEBUG_PROC_DESC_NO_SERVICES     0x00000002
// Dont look up MTS package names.
#define DEBUG_PROC_DESC_NO_MTS_PACKAGES 0x00000004
// Dont retrieve the command line.
#define DEBUG_PROC_DESC_NO_COMMAND_LINE 0x00000008
// Dont retrieve the session ID.
#define DEBUG_PROC_DESC_NO_SESSION_ID   0x00000010
// Dont retrieve the process's user name.
#define DEBUG_PROC_DESC_NO_USER_NAME    0x00000020
// Retrieve the process's package family name.
#define DEBUG_PROC_DESC_WITH_PACKAGEFAMILY 0x00000040
// Retrieve the process's architecture.
#define DEBUG_PROC_DESC_WITH_ARCHITECTURE 0x00000080

//
// Attach flags.
//

// Call DebugActiveProcess when attaching.
#define DEBUG_ATTACH_DEFAULT                   0x00000000
// When attaching to a process just examine
// the process state and suspend the threads.
// DebugActiveProcess is not called so the process
// is not actually being debugged.  This is useful
// for debugging processes holding locks which
// interfere with the operation of DebugActiveProcess
// or in situations where it is not desirable to
// actually set up as a debugger.
#define DEBUG_ATTACH_NONINVASIVE               0x00000001
// Attempt to attach to a process that was abandoned
// when being debugged.  This is only supported in
// some system versions.
// This flag also allows multiple debuggers to
// attach to the same process, which can result
// in numerous problems unless very carefully
// managed.
#define DEBUG_ATTACH_EXISTING                  0x00000002
// When attaching non-invasively, do not suspend
// threads.  It is the callers responsibility
// to either suspend the threads itself or be
// aware that the attach state may not reflect
// the current state of the process if threads
// are still running.
#define DEBUG_ATTACH_NONINVASIVE_NO_SUSPEND    0x00000004
// When doing an invasive attach do not inject
// a break-in thread to generate the initial break-in
// event.  This can be useful to save resources when
// an initial break is not necessary or when injecting
// a thread might affect the debuggee's state.  This
// option is only supported on Windows XP and above.
#define DEBUG_ATTACH_INVASIVE_NO_INITIAL_BREAK 0x00000008
// When doing an invasive attach resume all threads at the
// time of attach.  This makes it possible to attach
// to a process created suspended and cause it to start running.
#define DEBUG_ATTACH_INVASIVE_RESUME_PROCESS   0x00000010
// When doing a non-invasive attach the engine must
// recover information for all debuggee elements.  The
// engine may not have permissions for all elements,
// for example it may not be able to open all threads,
// and that would ordinarily block the attach.  This
// flag allows unusable elements to be ignored.
#define DEBUG_ATTACH_NONINVASIVE_ALLOW_PARTIAL 0x00000020


//
// Process creation flags to merge with Win32 flags.
//

// On Windows XP this flag prevents the debug
// heap from being used in the new process.
#define DEBUG_CREATE_PROCESS_NO_DEBUG_HEAP CREATE_UNICODE_ENVIRONMENT
// Indicates that the native NT RTL process creation
// routines should be used instead of Win32.  This
// is only meaningful for special processes that run
// as NT native processes.
#define DEBUG_CREATE_PROCESS_THROUGH_RTL   STACK_SIZE_PARAM_IS_A_RESERVATION

//
// Process creation flags specific to the debugger engine.
//

#define DEBUG_ECREATE_PROCESS_DEFAULT                   0x00000000
#define DEBUG_ECREATE_PROCESS_INHERIT_HANDLES           0x00000001
#define DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS        0x00000002
#define DEBUG_ECREATE_PROCESS_USE_IMPLICIT_COMMAND_LINE 0x00000004

typedef struct _DEBUG_CREATE_PROCESS_OPTIONS
{
    // Win32 create flags.
    ULONG CreateFlags;
    // DEBUG_ECREATE_PROCESS_* flags.
    ULONG EngCreateFlags;
    // Application Verifier flags,
    // if DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS is set.
    ULONG VerifierFlags;
    // Must be zero.
    ULONG Reserved;
} DEBUG_CREATE_PROCESS_OPTIONS, *PDEBUG_CREATE_PROCESS_OPTIONS;

//
// Process options.
//

// Indicates that the debuggee process should be
// automatically detached when the debugger exits.
// A debugger can explicitly detach on exit or this
// flag can be set so that detach occurs regardless
// of how the debugger exits.
// This is only supported on some system versions.
#define DEBUG_PROCESS_DETACH_ON_EXIT    0x00000001
// Indicates that processes created by the current
// process should not be debugged.
// Modifying this flag is only supported on some
// system versions.
#define DEBUG_PROCESS_ONLY_THIS_PROCESS 0x00000002

// ConnectSession flags.
// Default connect.
#define DEBUG_CONNECT_SESSION_DEFAULT     0x00000000
// Do not output the debugger version.
#define DEBUG_CONNECT_SESSION_NO_VERSION  0x00000001
// Do not announce the connection.
#define DEBUG_CONNECT_SESSION_NO_ANNOUNCE 0x00000002

// OutputServers flags.
// Debugger servers from StartSever.
#define DEBUG_SERVERS_DEBUGGER 0x00000001
// Process servers from StartProcessServer.
#define DEBUG_SERVERS_PROCESS  0x00000002
#define DEBUG_SERVERS_ALL      0x00000003

// EndSession flags.
// Perform cleanup for the session.
#define DEBUG_END_PASSIVE          0x00000000
// Actively terminate the session and then perform cleanup.
#define DEBUG_END_ACTIVE_TERMINATE 0x00000001
// If possible, detach from all processes and then perform cleanup.
#define DEBUG_END_ACTIVE_DETACH    0x00000002
// Perform whatever cleanup is possible that doesn't require
// acquiring any locks.  This is useful for situations where
// a thread is currently using the engine but the application
// needs to exit and still wants to give the engine
// the opportunity to clean up as much as possible.
// This may leave the engine in an indeterminate state so
// further engine calls should not be made.
// When making a reentrant EndSession call from a remote
// client it is the callers responsibility to ensure
// that the server can process the request.  It is best
// to avoid making such calls.
#define DEBUG_END_REENTRANT        0x00000003
// Notify a server that a remote client is disconnecting.
// This isnt required but if it isnt called then
// no disconnect messages will be generated by the server.
#define DEBUG_END_DISCONNECT       0x00000004

// Output mask bits.
// Normal output.
#define DEBUG_OUTPUT_NORMAL            0x00000001
// Error output.
#define DEBUG_OUTPUT_ERROR             0x00000002
// Warnings.
#define DEBUG_OUTPUT_WARNING           0x00000004
// Additional output.
#define DEBUG_OUTPUT_VERBOSE           0x00000008
// Prompt output.
#define DEBUG_OUTPUT_PROMPT            0x00000010
// Register dump before prompt.
#define DEBUG_OUTPUT_PROMPT_REGISTERS  0x00000020
// Warnings specific to extension operation.
#define DEBUG_OUTPUT_EXTENSION_WARNING 0x00000040
// Debuggee debug output, such as from OutputDebugString.
#define DEBUG_OUTPUT_DEBUGGEE          0x00000080
// Debuggee-generated prompt, such as from DbgPrompt.
#define DEBUG_OUTPUT_DEBUGGEE_PROMPT   0x00000100
// Symbol messages, such as for !sym noisy.
#define DEBUG_OUTPUT_SYMBOLS           0x00000200
// Output which modifies the status bar
#define DEBUG_OUTPUT_STATUS            0x00000400
// Structured XML status messages
#define DEBUG_OUTPUT_XML               0x00000800

// Internal debugger output, used mainly
// for debugging the debugger.  Output
// may only occur in debug builds.
// KD protocol output.
#define DEBUG_IOUTPUT_KD_PROTOCOL      0x80000000
// Remoting output.
#define DEBUG_IOUTPUT_REMOTING         0x40000000
// Breakpoint output.
#define DEBUG_IOUTPUT_BREAKPOINT       0x20000000
// Event output.
#define DEBUG_IOUTPUT_EVENT            0x10000000
// Virtual/Physical address translation
#define DEBUG_IOUTPUT_ADDR_TRANSLATE   0x08000000

// OutputIdentity flags.
#define DEBUG_OUTPUT_IDENTITY_DEFAULT 0x00000000

// Client identification constants
#define DEBUG_CLIENT_UNKNOWN            0x0
#define DEBUG_CLIENT_VSINT              0x1
#define DEBUG_CLIENT_NTSD               0x2
#define DEBUG_CLIENT_NTKD               0x3
#define DEBUG_CLIENT_CDB                0x4
#define DEBUG_CLIENT_KD                 0x5
#define DEBUG_CLIENT_WINDBG             0x6
#define DEBUG_CLIENT_WINIDE             0x7

typedef struct _DEBUG_CLIENT_CONTEXT
{
    UINT cbSize;
    UINT eClient;
} DEBUG_CLIENT_CONTEXT, *PDEBUG_CLIENT_CONTEXT;

#undef INTERFACE
#define INTERFACE IDebugClient
DECLARE_INTERFACE_(IDebugClient, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;
};

// Per-dump-format control flags.
#define DEBUG_FORMAT_DEFAULT                  0x00000000
// When creating a CAB with secondary images do searches
// for all image files, regardless of whether they're
// needed for the current session or not.
#define DEBUG_FORMAT_CAB_SECONDARY_ALL_IMAGES 0x10000000
// Write dump to a temporary file, then package it
// into a CAB file and delete the temporary file.
#define DEBUG_FORMAT_WRITE_CAB                0x20000000
// When creating a CAB add secondary files such as
// current symbols and mapped images.
#define DEBUG_FORMAT_CAB_SECONDARY_FILES      0x40000000
// Don't overwrite existing files.
#define DEBUG_FORMAT_NO_OVERWRITE             0x80000000

#define DEBUG_FORMAT_USER_SMALL_FULL_MEMORY               0x00000001
#define DEBUG_FORMAT_USER_SMALL_HANDLE_DATA               0x00000002
#define DEBUG_FORMAT_USER_SMALL_UNLOADED_MODULES          0x00000004
#define DEBUG_FORMAT_USER_SMALL_INDIRECT_MEMORY           0x00000008
#define DEBUG_FORMAT_USER_SMALL_DATA_SEGMENTS             0x00000010
#define DEBUG_FORMAT_USER_SMALL_FILTER_MEMORY             0x00000020
#define DEBUG_FORMAT_USER_SMALL_FILTER_PATHS              0x00000040
#define DEBUG_FORMAT_USER_SMALL_PROCESS_THREAD_DATA       0x00000080
#define DEBUG_FORMAT_USER_SMALL_PRIVATE_READ_WRITE_MEMORY 0x00000100
#define DEBUG_FORMAT_USER_SMALL_NO_OPTIONAL_DATA          0x00000200
#define DEBUG_FORMAT_USER_SMALL_FULL_MEMORY_INFO          0x00000400
#define DEBUG_FORMAT_USER_SMALL_THREAD_INFO               0x00000800
#define DEBUG_FORMAT_USER_SMALL_CODE_SEGMENTS             0x00001000
#define DEBUG_FORMAT_USER_SMALL_NO_AUXILIARY_STATE        0x00002000
#define DEBUG_FORMAT_USER_SMALL_FULL_AUXILIARY_STATE      0x00004000
#define DEBUG_FORMAT_USER_SMALL_MODULE_HEADERS            0x00008000
#define DEBUG_FORMAT_USER_SMALL_FILTER_TRIAGE             0x00010000
#define DEBUG_FORMAT_USER_SMALL_ADD_AVX_XSTATE_CONTEXT    0x00020000
#define DEBUG_FORMAT_USER_SMALL_IPT_TRACE                 0x00040000
#define DEBUG_FORMAT_USER_SMALL_IGNORE_INACCESSIBLE_MEM   0x08000000
#define DEBUG_FORMAT_USER_SMALL_SCAN_PARTIAL_PAGES        0x10000000


//
// Dump information file types.
//

// Base dump file, returned when querying for dump files.
#define DEBUG_DUMP_FILE_BASE           0xffffffff
// Single file containing packed page file information.
#define DEBUG_DUMP_FILE_PAGE_FILE_DUMP 0x00000000

#undef INTERFACE
#define INTERFACE IDebugClient2
DECLARE_INTERFACE_(IDebugClient2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugClient3
DECLARE_INTERFACE_(IDebugClient3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;

    // IDebugClient3.

    STDMETHOD(GetRunningProcessSystemIdByExecutableNameWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescriptionWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PWSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    STDMETHOD(CreateProcessWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttachWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
};

//
// Special indices for GetDumpFile to return
// alternate filenames.
//

// Special index that returns the name of the last .dmp file
// that failed to load (whether directly or from inside a
// .cab file).
#define DEBUG_DUMP_FILE_LOAD_FAILED_INDEX  0xffffffff
// Index that returns last cab file opened, this is needed to
// get the name of original CAB file since debugger returns the
// extracted dump file in the GetDumpFile method.
#define DEBUG_DUMP_FILE_ORIGINAL_CAB_INDEX 0xfffffffe

#undef INTERFACE
#define INTERFACE IDebugClient4
DECLARE_INTERFACE_(IDebugClient4, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;

    // IDebugClient3.

    STDMETHOD(GetRunningProcessSystemIdByExecutableNameWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescriptionWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PWSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    STDMETHOD(CreateProcessWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttachWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
    STDMETHOD(OpenDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle
        ) PURE;
    STDMETHOD(WriteDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCWSTR Comment
        ) PURE;
    STDMETHOD(AddDumpInformationFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Type
        ) PURE;
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
    STDMETHOD(GetNumberDumpFiles)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDumpFile)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(GetDumpFileWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugClient5
DECLARE_INTERFACE_(IDebugClient5, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;

    // IDebugClient3.

    STDMETHOD(GetRunningProcessSystemIdByExecutableNameWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescriptionWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PWSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    STDMETHOD(CreateProcessWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttachWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
    STDMETHOD(OpenDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle
        ) PURE;
    STDMETHOD(WriteDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCWSTR Comment
        ) PURE;
    STDMETHOD(AddDumpInformationFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Type
        ) PURE;
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
    STDMETHOD(GetNumberDumpFiles)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDumpFile)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(GetDumpFileWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;

    // IDebugClient5.

    STDMETHOD(AttachKernelWide)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCWSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptionsWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    STDMETHOD(SetKernelConnectionOptionsWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;

    STDMETHOD(StartProcessServerWide)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCWSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServerWide)(
        THIS_
        _In_ PCWSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;

    STDMETHOD(StartServerWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;
    STDMETHOD(OutputServersWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetOutputCallbacksWide)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacksWide)(
        THIS_
        _In_ PDEBUG_OUTPUT_CALLBACKS_WIDE Callbacks
        ) PURE;
    STDMETHOD(GetOutputLinePrefixWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR Prefix
        ) PURE;

    STDMETHOD(GetIdentityWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    STDMETHOD(OutputIdentityWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCWSTR Format
        ) PURE;

    STDMETHOD(GetEventCallbacksWide)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacksWide)(
        THIS_
        _In_ PDEBUG_EVENT_CALLBACKS_WIDE Callbacks
        ) PURE;

    STDMETHOD(CreateProcess2)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment
        ) PURE;
    STDMETHOD(CreateProcess2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // Helpers for saving and restoring the
    // current output line prefix.
    STDMETHOD(PushOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PushOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PopOutputLinePrefix)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    // Queries to determine if any clients
    // could potentially respond to the given callback.
    STDMETHOD(GetNumberInputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberOutputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberEventCallbacks)(
        THIS_
        _In_ ULONG EventFlags,
        _Out_ PULONG Count
        ) PURE;

    // Control over locking the session against
    // undesired quits.  The quit lock string
    // cannot be retrieved from a secure session.
    STDMETHOD(GetQuitLockString)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockString)(
        THIS_
        _In_ PCSTR String
        ) PURE;
    STDMETHOD(GetQuitLockStringWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockStringWide)(
        THIS_
        _In_ PCWSTR String
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugClient6
DECLARE_INTERFACE_(IDebugClient6, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;

    // IDebugClient3.

    STDMETHOD(GetRunningProcessSystemIdByExecutableNameWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescriptionWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PWSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    STDMETHOD(CreateProcessWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttachWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
    STDMETHOD(OpenDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle
        ) PURE;
    STDMETHOD(WriteDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCWSTR Comment
        ) PURE;
    STDMETHOD(AddDumpInformationFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Type
        ) PURE;
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
    STDMETHOD(GetNumberDumpFiles)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDumpFile)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(GetDumpFileWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;

    // IDebugClient5.

    STDMETHOD(AttachKernelWide)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCWSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptionsWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    STDMETHOD(SetKernelConnectionOptionsWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;

    STDMETHOD(StartProcessServerWide)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCWSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServerWide)(
        THIS_
        _In_ PCWSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;

    STDMETHOD(StartServerWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;
    STDMETHOD(OutputServersWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetOutputCallbacksWide)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacksWide)(
        THIS_
        _In_ PDEBUG_OUTPUT_CALLBACKS_WIDE Callbacks
        ) PURE;
    STDMETHOD(GetOutputLinePrefixWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR Prefix
        ) PURE;

    STDMETHOD(GetIdentityWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    STDMETHOD(OutputIdentityWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCWSTR Format
        ) PURE;

    STDMETHOD(GetEventCallbacksWide)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacksWide)(
        THIS_
        _In_ PDEBUG_EVENT_CALLBACKS_WIDE Callbacks
        ) PURE;

    STDMETHOD(CreateProcess2)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment
        ) PURE;
    STDMETHOD(CreateProcess2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // Helpers for saving and restoring the
    // current output line prefix.
    STDMETHOD(PushOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PushOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PopOutputLinePrefix)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    // Queries to determine if any clients
    // could potentially respond to the given callback.
    STDMETHOD(GetNumberInputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberOutputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberEventCallbacks)(
        THIS_
        _In_ ULONG EventFlags,
        _Out_ PULONG Count
        ) PURE;

    // Control over locking the session against
    // undesired quits.  The quit lock string
    // cannot be retrieved from a secure session.
    STDMETHOD(GetQuitLockString)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockString)(
        THIS_
        _In_ PCSTR String
        ) PURE;
    STDMETHOD(GetQuitLockStringWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockStringWide)(
        THIS_
        _In_ PCWSTR String
        ) PURE;

    // IDebugClient6

    STDMETHOD(SetEventContextCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CONTEXT_CALLBACKS Callbacks
        ) PURE;

};

#undef INTERFACE
#define INTERFACE IDebugClient7
DECLARE_INTERFACE_(IDebugClient7, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;

    // IDebugClient3.

    STDMETHOD(GetRunningProcessSystemIdByExecutableNameWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescriptionWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PWSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    STDMETHOD(CreateProcessWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttachWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
    STDMETHOD(OpenDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle
        ) PURE;
    STDMETHOD(WriteDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCWSTR Comment
        ) PURE;
    STDMETHOD(AddDumpInformationFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Type
        ) PURE;
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
    STDMETHOD(GetNumberDumpFiles)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDumpFile)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(GetDumpFileWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;

    // IDebugClient5.

    STDMETHOD(AttachKernelWide)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCWSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptionsWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    STDMETHOD(SetKernelConnectionOptionsWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;

    STDMETHOD(StartProcessServerWide)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCWSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServerWide)(
        THIS_
        _In_ PCWSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;

    STDMETHOD(StartServerWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;
    STDMETHOD(OutputServersWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetOutputCallbacksWide)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacksWide)(
        THIS_
        _In_ PDEBUG_OUTPUT_CALLBACKS_WIDE Callbacks
        ) PURE;
    STDMETHOD(GetOutputLinePrefixWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR Prefix
        ) PURE;

    STDMETHOD(GetIdentityWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    STDMETHOD(OutputIdentityWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCWSTR Format
        ) PURE;

    STDMETHOD(GetEventCallbacksWide)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacksWide)(
        THIS_
        _In_ PDEBUG_EVENT_CALLBACKS_WIDE Callbacks
        ) PURE;

    STDMETHOD(CreateProcess2)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment
        ) PURE;
    STDMETHOD(CreateProcess2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // Helpers for saving and restoring the
    // current output line prefix.
    STDMETHOD(PushOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PushOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PopOutputLinePrefix)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    // Queries to determine if any clients
    // could potentially respond to the given callback.
    STDMETHOD(GetNumberInputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberOutputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberEventCallbacks)(
        THIS_
        _In_ ULONG EventFlags,
        _Out_ PULONG Count
        ) PURE;

    // Control over locking the session against
    // undesired quits.  The quit lock string
    // cannot be retrieved from a secure session.
    STDMETHOD(GetQuitLockString)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockString)(
        THIS_
        _In_ PCSTR String
        ) PURE;
    STDMETHOD(GetQuitLockStringWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockStringWide)(
        THIS_
        _In_ PCWSTR String
        ) PURE;

    // IDebugClient6

    STDMETHOD(SetEventContextCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CONTEXT_CALLBACKS Callbacks
        ) PURE;

    // IDebugClient7

    STDMETHOD(SetClientContext)(
        THIS_
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugClient8
DECLARE_INTERFACE_(IDebugClient8, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;

    // IDebugClient3.

    STDMETHOD(GetRunningProcessSystemIdByExecutableNameWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescriptionWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PWSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    STDMETHOD(CreateProcessWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttachWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
    STDMETHOD(OpenDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle
        ) PURE;
    STDMETHOD(WriteDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCWSTR Comment
        ) PURE;
    STDMETHOD(AddDumpInformationFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Type
        ) PURE;
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
    STDMETHOD(GetNumberDumpFiles)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDumpFile)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(GetDumpFileWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;

    // IDebugClient5.

    STDMETHOD(AttachKernelWide)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCWSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptionsWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    STDMETHOD(SetKernelConnectionOptionsWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;

    STDMETHOD(StartProcessServerWide)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCWSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServerWide)(
        THIS_
        _In_ PCWSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;

    STDMETHOD(StartServerWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;
    STDMETHOD(OutputServersWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetOutputCallbacksWide)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacksWide)(
        THIS_
        _In_ PDEBUG_OUTPUT_CALLBACKS_WIDE Callbacks
        ) PURE;
    STDMETHOD(GetOutputLinePrefixWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR Prefix
        ) PURE;

    STDMETHOD(GetIdentityWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    STDMETHOD(OutputIdentityWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCWSTR Format
        ) PURE;

    STDMETHOD(GetEventCallbacksWide)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacksWide)(
        THIS_
        _In_ PDEBUG_EVENT_CALLBACKS_WIDE Callbacks
        ) PURE;

    STDMETHOD(CreateProcess2)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment
        ) PURE;
    STDMETHOD(CreateProcess2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // Helpers for saving and restoring the
    // current output line prefix.
    STDMETHOD(PushOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PushOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PopOutputLinePrefix)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    // Queries to determine if any clients
    // could potentially respond to the given callback.
    STDMETHOD(GetNumberInputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberOutputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberEventCallbacks)(
        THIS_
        _In_ ULONG EventFlags,
        _Out_ PULONG Count
        ) PURE;

    // Control over locking the session against
    // undesired quits.  The quit lock string
    // cannot be retrieved from a secure session.
    STDMETHOD(GetQuitLockString)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockString)(
        THIS_
        _In_ PCSTR String
        ) PURE;
    STDMETHOD(GetQuitLockStringWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockStringWide)(
        THIS_
        _In_ PCWSTR String
        ) PURE;

    // IDebugClient6

    STDMETHOD(SetEventContextCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CONTEXT_CALLBACKS Callbacks
        ) PURE;

    // IDebugClient7

    STDMETHOD(SetClientContext)(
        THIS_
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // IDebugClient8

    STDMETHOD(OpenDumpFileWide2)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG AlternateArch
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugClient9
DECLARE_INTERFACE_(IDebugClient9, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
    STDMETHOD(AttachKernel)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptions)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
    STDMETHOD(SetKernelConnectionOptions)(
        THIS_
        _In_ PCSTR Options
        ) PURE;

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
    STDMETHOD(StartProcessServer)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServer)(
        THIS_
        _In_ PCSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(DisconnectProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;

    // Enumerates and describes processes
    // accessible through the given process server.
    STDMETHOD(GetRunningProcessSystemIds)(
        THIS_
        _In_ ULONG64 Server,
        _Out_writes_opt_(Count) PULONG Ids,
        _In_ ULONG Count,
        _Out_opt_ PULONG ActualCount
        ) PURE;
    STDMETHOD(GetRunningProcessSystemIdByExecutableName)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescription)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    // Attaches to a running user-mode process.
    STDMETHOD(AttachProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
    STDMETHOD(CreateProcessAndAttach)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    // Gets and sets process control flags.
    STDMETHOD(GetProcessOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetProcessOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
    STDMETHOD(OpenDumpFile)(
        THIS_
        _In_ PCSTR DumpFile
        ) PURE;
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
    STDMETHOD(WriteDumpFile)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier
        ) PURE;

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
    STDMETHOD(ConnectSession)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG HistoryLimit
        ) PURE;
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
    STDMETHOD(StartServer)(
        THIS_
        _In_ PCSTR Options
        ) PURE;
    // List the servers running on the given machine.
    // Uses the line prefix.
    STDMETHOD(OutputServers)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    // Attempts to terminate all processes in the debuggers list.
    STDMETHOD(TerminateProcesses)(
        THIS
        ) PURE;
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachProcesses)(
        THIS
        ) PURE;
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
    STDMETHOD(EndSession)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
    STDMETHOD(GetExitCode)(
        THIS_
        _Out_ PULONG Code
        ) PURE;

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
    STDMETHOD(DispatchCallbacks)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
    STDMETHOD(ExitDispatch)(
        THIS_
        _In_ PDEBUG_CLIENT Client
        ) PURE;

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
    STDMETHOD(CreateClient)(
        THIS_
        _Out_ PDEBUG_CLIENT* Client
        ) PURE;

    STDMETHOD(GetInputCallbacks)(
        THIS_
        _Out_ PDEBUG_INPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetInputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_INPUT_CALLBACKS Callbacks
        ) PURE;

    // Output callback interfaces are described separately.
    STDMETHOD(GetOutputCallbacks)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacks)(
        THIS_
        _In_opt_ PDEBUG_OUTPUT_CALLBACKS Callbacks
        ) PURE;
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
    STDMETHOD(GetOutputMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOutputMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
    STDMETHOD(GetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetOtherOutputMask)(
        THIS_
        _In_ PDEBUG_CLIENT Client,
        _In_ ULONG Mask
        ) PURE;
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
    STDMETHOD(GetOutputWidth)(
        THIS_
        _Out_ PULONG Columns
        ) PURE;
    STDMETHOD(SetOutputWidth)(
        THIS_
        _In_ ULONG Columns
        ) PURE;
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
    STDMETHOD(GetOutputLinePrefix)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR Prefix
        ) PURE;

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
    STDMETHOD(GetIdentity)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    // Format is a printf-like format string
    // with one %s where the identity string should go.
    STDMETHOD(OutputIdentity)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCSTR Format
        ) PURE;

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
    STDMETHOD(GetEventCallbacks)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CALLBACKS Callbacks
        ) PURE;

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
    STDMETHOD(FlushCallbacks)(
        THIS
        ) PURE;

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
    STDMETHOD(WriteDumpFile2)(
        THIS_
        _In_ PCSTR DumpFile,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCSTR Comment
        ) PURE;
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
    STDMETHOD(AddDumpInformationFile)(
        THIS_
        _In_ PCSTR InfoFile,
        _In_ ULONG Type
        ) PURE;

    // Requests that the remote process server shut down.
    STDMETHOD(EndProcessServer)(
        THIS_
        _In_ ULONG64 Server
        ) PURE;
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
    STDMETHOD(WaitForProcessServerEnd)(
        THIS_
        _In_ ULONG Timeout
        ) PURE;

    // Returns S_OK if the system is configured
    // to allow kernel debugging.
    STDMETHOD(IsKernelDebuggerEnabled)(
        THIS
        ) PURE;

    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
    STDMETHOD(TerminateCurrentProcess)(
        THIS
        ) PURE;
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
    STDMETHOD(DetachCurrentProcess)(
        THIS
        ) PURE;
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
    STDMETHOD(AbandonCurrentProcess)(
        THIS
        ) PURE;

    // IDebugClient3.

    STDMETHOD(GetRunningProcessSystemIdByExecutableNameWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR ExeName,
        _In_ ULONG Flags,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetRunningProcessDescriptionWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG SystemId,
        _In_ ULONG Flags,
        _Out_writes_opt_(ExeNameSize) PWSTR ExeName,
        _In_ ULONG ExeNameSize,
        _Out_opt_ PULONG ActualExeNameSize,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG ActualDescriptionSize
        ) PURE;

    STDMETHOD(CreateProcessWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_ ULONG CreateFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttachWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_ ULONG CreateFlags,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
    STDMETHOD(OpenDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle
        ) PURE;
    STDMETHOD(WriteDumpFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Qualifier,
        _In_ ULONG FormatFlags,
        _In_opt_ PCWSTR Comment
        ) PURE;
    STDMETHOD(AddDumpInformationFileWide)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG Type
        ) PURE;
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
    STDMETHOD(GetNumberDumpFiles)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDumpFile)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(GetDumpFileWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Handle,
        _Out_ PULONG Type
        ) PURE;

    // IDebugClient5.

    STDMETHOD(AttachKernelWide)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PCWSTR ConnectOptions
        ) PURE;
    STDMETHOD(GetKernelConnectionOptionsWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG OptionsSize
        ) PURE;
    STDMETHOD(SetKernelConnectionOptionsWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;

    STDMETHOD(StartProcessServerWide)(
        THIS_
        _In_ ULONG Flags,
        _In_ PCWSTR Options,
        _In_opt_ _Reserved_ PVOID Reserved
        ) PURE;
    STDMETHOD(ConnectProcessServerWide)(
        THIS_
        _In_ PCWSTR RemoteOptions,
        _Out_ PULONG64 Server
        ) PURE;

    STDMETHOD(StartServerWide)(
        THIS_
        _In_ PCWSTR Options
        ) PURE;
    STDMETHOD(OutputServersWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Machine,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetOutputCallbacksWide)(
        THIS_
        _Out_ PDEBUG_OUTPUT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetOutputCallbacksWide)(
        THIS_
        _In_ PDEBUG_OUTPUT_CALLBACKS_WIDE Callbacks
        ) PURE;
    STDMETHOD(GetOutputLinePrefixWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PrefixSize
        ) PURE;
    STDMETHOD(SetOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR Prefix
        ) PURE;

    STDMETHOD(GetIdentityWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG IdentitySize
        ) PURE;
    STDMETHOD(OutputIdentityWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ PCWSTR Format
        ) PURE;

    STDMETHOD(GetEventCallbacksWide)(
        THIS_
        _Out_ PDEBUG_EVENT_CALLBACKS_WIDE* Callbacks
        ) PURE;
    STDMETHOD(SetEventCallbacksWide)(
        THIS_
        _In_ PDEBUG_EVENT_CALLBACKS_WIDE Callbacks
        ) PURE;

    STDMETHOD(CreateProcess2)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment
        ) PURE;
    STDMETHOD(CreateProcess2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCSTR InitialDirectory,
        _In_opt_ PCSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;
    STDMETHOD(CreateProcessAndAttach2Wide)(
        THIS_
        _In_ ULONG64 Server,
        _In_opt_ PWSTR CommandLine,
        _In_reads_bytes_(OptionsBufferSize) PVOID OptionsBuffer,
        _In_ ULONG OptionsBufferSize,
        _In_opt_ PCWSTR InitialDirectory,
        _In_opt_ PCWSTR Environment,
        _In_ ULONG ProcessId,
        _In_ ULONG AttachFlags
        ) PURE;

    // Helpers for saving and restoring the
    // current output line prefix.
    STDMETHOD(PushOutputLinePrefix)(
        THIS_
        _In_opt_ PCSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PushOutputLinePrefixWide)(
        THIS_
        _In_opt_ PCWSTR NewPrefix,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(PopOutputLinePrefix)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    // Queries to determine if any clients
    // could potentially respond to the given callback.
    STDMETHOD(GetNumberInputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberOutputCallbacks)(
        THIS_
        _Out_ PULONG Count
        ) PURE;
    STDMETHOD(GetNumberEventCallbacks)(
        THIS_
        _In_ ULONG EventFlags,
        _Out_ PULONG Count
        ) PURE;

    // Control over locking the session against
    // undesired quits.  The quit lock string
    // cannot be retrieved from a secure session.
    STDMETHOD(GetQuitLockString)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockString)(
        THIS_
        _In_ PCSTR String
        ) PURE;
    STDMETHOD(GetQuitLockStringWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(SetQuitLockStringWide)(
        THIS_
        _In_ PCWSTR String
        ) PURE;

    // IDebugClient6

    STDMETHOD(SetEventContextCallbacks)(
        THIS_
        _In_opt_ PDEBUG_EVENT_CONTEXT_CALLBACKS Callbacks
        ) PURE;

    // IDebugClient7

    STDMETHOD(SetClientContext)(
        THIS_
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // IDebugClient8

    STDMETHOD(OpenDumpFileWide2)(
        THIS_
        _In_opt_ PCWSTR FileName,
        _In_ ULONG64 FileHandle,
        _In_ ULONG AlternateArch
        ) PURE;

    // IDebugClient9

    STDMETHOD(OpenDumpDirectoryWide)(
        THIS_
        _In_opt_ PCWSTR DirName,
        _In_ ULONG AlternateArch
        ) PURE;
    STDMETHOD(OpenDumpDirectory)(
        THIS_
        _In_ PCSTR DumpDir,
        _In_ ULONG AlternativeArch
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugPlmClient
DECLARE_INTERFACE_(IDebugPlmClient, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugPlmClient

    // Launches suspended Plm Application
    STDMETHOD(LaunchPlmPackageForDebugWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG Timeout,
        _In_ PCWSTR PackageFullName,
        _In_ PCWSTR AppName,
        _In_opt_ PCWSTR Arguments,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugPlmClient2
DECLARE_INTERFACE_(IDebugPlmClient2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugPlmClient

    // Launches suspended Plm Application
    STDMETHOD(LaunchPlmPackageForDebugWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG Timeout,
        _In_ PCWSTR PackageFullName,
        _In_ PCWSTR AppName,
        _In_opt_ PCWSTR Arguments,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId
        ) PURE;

    // IDebugPlmClient2

     // Launches suspended Plm Bg Task
    STDMETHOD(LaunchPlmBgTaskForDebugWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG Timeout,
        _In_ PCWSTR PackageFullName,
        _In_ PCWSTR BackgroundTaskId,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugPlmClient3
DECLARE_INTERFACE_(IDebugPlmClient3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugPlmClient

    // Launches suspended Plm Application
    STDMETHOD(LaunchPlmPackageForDebugWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG Timeout,
        _In_ PCWSTR PackageFullName,
        _In_ PCWSTR AppName,
        _In_opt_ PCWSTR Arguments,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId
        ) PURE;

    // IDebugPlmClient2

     // Launches suspended Plm Bg Task
    STDMETHOD(LaunchPlmBgTaskForDebugWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ ULONG Timeout,
        _In_ PCWSTR PackageFullName,
        _In_ PCWSTR BackgroundTaskId,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId
        ) PURE;

    // IDebugPlmClient3

    STDMETHOD(QueryPlmPackageWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName,
        _In_ PDEBUG_OUTPUT_STREAM Stream
        ) PURE;

    STDMETHOD(QueryPlmPackageList)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PDEBUG_OUTPUT_STREAM Stream
        ) PURE;

    STDMETHOD(EnablePlmPackageDebugWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName
        ) PURE;

    STDMETHOD(DisablePlmPackageDebugWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName
        ) PURE;

    STDMETHOD(SuspendPlmPackageWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName
        ) PURE;

    STDMETHOD(ResumePlmPackageWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName
        ) PURE;

    STDMETHOD(TerminatePlmPackageWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName
        ) PURE;

    // Launches and attaches to Plm Application. Starts debugger session
    // if it is not already started
    STDMETHOD(LaunchAndDebugPlmAppWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName,
        _In_ PCWSTR AppName,
        _In_ PCWSTR Arguments
        ) PURE;

    // Launches and attaches to Plm Bg Task. Starts debugger session
    // if it is not already started
    STDMETHOD(ActivateAndDebugPlmBgTaskWide)(
        THIS_
        _In_ ULONG64 Server,
        _In_ PCWSTR PackageFullName,
        _In_ PCWSTR BackgroundTaskId
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugOutputStream
DECLARE_INTERFACE_(IDebugOutputStream, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        __in REFIID InterfaceId,
        __out PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugOutputStream.
    STDMETHOD(Write)(
        THIS_
        _In_ PCWSTR psz
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugControl.
//
//----------------------------------------------------------------------------

// Execution status codes used for waiting,
// for returning current status and for
// event method return values.
#define DEBUG_STATUS_NO_CHANGE           0
#define DEBUG_STATUS_GO                  1
#define DEBUG_STATUS_GO_HANDLED          2
#define DEBUG_STATUS_GO_NOT_HANDLED      3
#define DEBUG_STATUS_STEP_OVER           4
#define DEBUG_STATUS_STEP_INTO           5
#define DEBUG_STATUS_BREAK               6
#define DEBUG_STATUS_NO_DEBUGGEE         7
#define DEBUG_STATUS_STEP_BRANCH         8
#define DEBUG_STATUS_IGNORE_EVENT        9
#define DEBUG_STATUS_RESTART_REQUESTED   10
#define DEBUG_STATUS_REVERSE_GO          11
#define DEBUG_STATUS_REVERSE_STEP_BRANCH 12
#define DEBUG_STATUS_REVERSE_STEP_OVER   13
#define DEBUG_STATUS_REVERSE_STEP_INTO   14
#define DEBUG_STATUS_OUT_OF_SYNC		 15
#define DEBUG_STATUS_WAIT_INPUT			 16
#define DEBUG_STATUS_TIMEOUT             17

#define DEBUG_STATUS_MASK                0x1f

// This bit is added in DEBUG_CES_EXECUTION_STATUS
// notifications when the engines execution status
// is changing due to operations performed during
// a wait, such as making synchronous callbacks.  If
// the bit is not set the execution status is changing
// due to a wait being satisfied.
#define DEBUG_STATUS_INSIDE_WAIT  0x100000000
// This bit is added in DEBUG_CES_EXECUTION_STATUS
// notifications when the engines execution status
// update is coming after a wait has timed-out.
// It indicates that the execution status change
// was not due to an actual event.
#define DEBUG_STATUS_WAIT_TIMEOUT 0x200000000

// Output control flags.
// Output generated by methods called by this
// client will be sent only to this clients
// output callbacks.
#define DEBUG_OUTCTL_THIS_CLIENT       0x00000000
// Output will be sent to all clients.
#define DEBUG_OUTCTL_ALL_CLIENTS       0x00000001
// Output will be sent to all clients except
// the client generating the output.
#define DEBUG_OUTCTL_ALL_OTHER_CLIENTS 0x00000002
// Output will be discarded immediately and will not
// be logged or sent to callbacks.
#define DEBUG_OUTCTL_IGNORE            0x00000003
// Output will be logged but not sent to callbacks.
#define DEBUG_OUTCTL_LOG_ONLY          0x00000004
// All send control bits.
#define DEBUG_OUTCTL_SEND_MASK         0x00000007
// Do not place output from this client in
// the global log file.
#define DEBUG_OUTCTL_NOT_LOGGED        0x00000008
// Send output to clients regardless of whether the
// mask allows it or not.
#define DEBUG_OUTCTL_OVERRIDE_MASK     0x00000010
// Text is markup instead of plain text.
#define DEBUG_OUTCTL_DML               0x00000020

// Special values which mean leave the output settings
// unchanged.
#define DEBUG_OUTCTL_AMBIENT_DML       0xfffffffe
#define DEBUG_OUTCTL_AMBIENT_TEXT      0xffffffff

// Old ambient flag which maps to text.
#define DEBUG_OUTCTL_AMBIENT           DEBUG_OUTCTL_AMBIENT_TEXT

// Interrupt types.
// Force a break in if the debuggee is running.
#define DEBUG_INTERRUPT_ACTIVE  0
// Notify but do not force a break in.
#define DEBUG_INTERRUPT_PASSIVE 1
// Try and get the current engine operation to
// complete so that the engine will be available
// again.  If no wait is active this is the same
// as a passive interrupt.  If a wait is active
// this will try to cause the wait to fail without
// breaking in to the debuggee.  There is
// no guarantee that issuing an exit interrupt
// will cause the engine to become available
// as not all operations are arbitrarily
// interruptible.
#define DEBUG_INTERRUPT_EXIT    2

// OutputCurrentState flags.  These flags
// allow a particular type of information
// to be displayed but do not guarantee
// that it will be displayed.  Other global
// settings may override these flags or
// the particular state may not be available.
// For example, source line information may
// not be present so source line information
// may not be displayed.
#define DEBUG_CURRENT_DEFAULT     0x0000000f
#define DEBUG_CURRENT_SYMBOL      0x00000001
#define DEBUG_CURRENT_DISASM      0x00000002
#define DEBUG_CURRENT_REGISTERS   0x00000004
#define DEBUG_CURRENT_SOURCE_LINE 0x00000008

//
// Disassemble flags.
//

// Compute the effective address from current register
// information and display it.
#define DEBUG_DISASM_EFFECTIVE_ADDRESS  0x00000001
// If the current disassembly offset has an exact
// symbol match output the symbol.
#define DEBUG_DISASM_MATCHING_SYMBOLS   0x00000002
// Output the source line number for each disassembly offset.
#define DEBUG_DISASM_SOURCE_LINE_NUMBER 0x00000004
// Output the source file name (no path) for each disassembly offset.
#define DEBUG_DISASM_SOURCE_FILE_NAME   0x00000008

// Code interpretation levels for stepping
// and other operations.
#define DEBUG_LEVEL_SOURCE   0
#define DEBUG_LEVEL_ASSEMBLY 1

// Engine control flags.
#define DEBUG_ENGOPT_IGNORE_DBGHELP_VERSION      0x00000001
#define DEBUG_ENGOPT_IGNORE_EXTENSION_VERSIONS   0x00000002
// If neither allow nor disallow is specified
// the engine will pick one based on what kind
// of debugging is going on.
#define DEBUG_ENGOPT_ALLOW_NETWORK_PATHS         0x00000004
#define DEBUG_ENGOPT_DISALLOW_NETWORK_PATHS      0x00000008
#define DEBUG_ENGOPT_NETWORK_PATHS               (0x00000004 | 0x00000008)
// Ignore loader-generated first-chance exceptions.
#define DEBUG_ENGOPT_IGNORE_LOADER_EXCEPTIONS    0x00000010
// Break in on a debuggees initial event.  In user-mode
// this will break at the initial system breakpoint
// for every created process.  In kernel-mode it
// will attempt break in on the target at the first
// WaitForEvent.
#define DEBUG_ENGOPT_INITIAL_BREAK               0x00000020
// Break in on the first module load for a debuggee.
#define DEBUG_ENGOPT_INITIAL_MODULE_BREAK        0x00000040
// Break in on a debuggees final event.  In user-mode
// this will break on process exit for every process.
// In kernel-mode it currently does nothing.
#define DEBUG_ENGOPT_FINAL_BREAK                 0x00000080
// By default Execute will repeat the last command
// if it is given an empty string.  The flags to
// Execute can override this behavior for a single
// command or this engine option can be used to
// change the default globally.
#define DEBUG_ENGOPT_NO_EXECUTE_REPEAT           0x00000100
// Disable places in the engine that have fallback
// code when presented with incomplete information.
//   1. Fails minidump module loads unless matching
//      executables can be mapped.
#define DEBUG_ENGOPT_FAIL_INCOMPLETE_INFORMATION 0x00000200
// Allow the debugger to manipulate page protections
// in order to insert code breakpoints on pages that
// do not have write access.  This option is not on
// by default as it allows breakpoints to be set
// in potentially hazardous memory areas.
#define DEBUG_ENGOPT_ALLOW_READ_ONLY_BREAKPOINTS 0x00000400
// When using a software (bp/bu) breakpoint in code
// that will be executed by multiple threads it is
// possible for breakpoint management to cause the
// breakpoint to be missed or for spurious single-step
// exceptions to be generated.  This flag suspends
// all but the active thread when doing breakpoint
// management and thereby avoids multithreading
// problems.  Care must be taken when using it, though,
// as the suspension of threads can cause deadlocks
// if the suspended threads are holding resources that
// the active thread needs.  Additionally, there
// are still rare situations where problems may
// occur, but setting this flag corrects nearly
// all multithreading issues with software breakpoints.
// Thread-restricted stepping and execution supersedes
// this flags effect.
// This flag is ignored in kernel sessions as there
// is no way to restrict processor execution.
#define DEBUG_ENGOPT_SYNCHRONIZE_BREAKPOINTS     0x00000800
// Disallows executing shell commands through the
// engine with .shell (!!).
#define DEBUG_ENGOPT_DISALLOW_SHELL_COMMANDS     0x00001000
// Turns on "quiet mode", a somewhat less verbose mode
// of operation supported in the debuggers that were
// superseded by dbgeng.dll.  This equates to the KDQUIET
// environment variable.
#define DEBUG_ENGOPT_KD_QUIET_MODE               0x00002000
// Disables managed code debugging support in the engine.
// If managed support is already in use this flag has no effect.
#define DEBUG_ENGOPT_DISABLE_MANAGED_SUPPORT     0x00004000
// Disables symbol loading for all modules created
// after this flag is set.
#define DEBUG_ENGOPT_DISABLE_MODULE_SYMBOL_LOAD  0x00008000
// Disables execution commands.
#define DEBUG_ENGOPT_DISABLE_EXECUTION_COMMANDS  0x00010000
// Disallows mapping of image files from disk for any use.
// For example, this disallows image mapping for memory
// content when debugging minidumps.
// Does not affect existing mappings, only future attempts.
#define DEBUG_ENGOPT_DISALLOW_IMAGE_FILE_MAPPING 0x00020000
// Requests that dbgeng run DML-enhanced versions of commands
// and operations by default.
#define DEBUG_ENGOPT_PREFER_DML                  0x00040000
// Explicitly disable SQM upload.
#define DEBUG_ENGOPT_DISABLESQM                  0x00080000
// This is used to disable the source stepping (step over/step in) into CFG code.
#define DEBUG_ENGOPT_DISABLE_STEPLINES_OPTIONS   0x00200000
// This is used when debugging target with sensitive data.
// It will disable saving dumps during debugging
// Can be set only (no reset once it is set)
#define DEBUG_ENGOPT_DEBUGGING_SENSITIVE_DATA    0x00400000
// When opening .cab or .zip files, if there is a trace (.run file), open
// it instead of any other dump files in the archive.
#define DEBUG_ENGOPT_PREFER_TRACE_FILES          0x00800000
// Use suffixes of the form @n (n is a non-negative integer) to disambiguate shadowed variables.
#define DEBUG_ENGOPT_RESOLVE_SHADOWED_VARIABLES  0x01000000
#define DEBUG_ENGOPT_ALL                         0x01EFFFFF

// General unspecified ID constant.
#define DEBUG_ANY_ID 0xffffffff

typedef struct _DEBUG_STACK_FRAME
{
    ULONG64 InstructionOffset;
    ULONG64 ReturnOffset;
    ULONG64 FrameOffset;
    ULONG64 StackOffset;
    ULONG64 FuncTableEntry;
    ULONG64 Params[4];
    ULONG64 Reserved[6];
    BOOL    Virtual;
    ULONG   FrameNumber;
} DEBUG_STACK_FRAME, *PDEBUG_STACK_FRAME;

#define DBG_FRAME_DEFAULT                0 // the same as INLINE_FRAME_CONTEXT_INIT in dbghelp.h
#define DBG_FRAME_IGNORE_INLINE 0xFFFFFFFF // the same as INLINE_FRAME_CONTEXT_IGNORE in dbghelp.h

typedef struct _DEBUG_STACK_FRAME_EX
{
    // First DEBUG_STACK_FRAME structure
    ULONG64 InstructionOffset;
    ULONG64 ReturnOffset;
    ULONG64 FrameOffset;
    ULONG64 StackOffset;
    ULONG64 FuncTableEntry;
    ULONG64 Params[4];
    ULONG64 Reserved[6];
    BOOL    Virtual;
    ULONG   FrameNumber;

    // Extended DEBUG_STACK_FRAME fields.
    ULONG InlineFrameContext;
    ULONG Reserved1; // For alignment purpose.
} DEBUG_STACK_FRAME_EX, *PDEBUG_STACK_FRAME_EX;

// The types of inline frame context.
#define STACK_FRAME_TYPE_INIT   0x00
#define STACK_FRAME_TYPE_STACK  0x01
#define STACK_FRAME_TYPE_INLINE 0x02
#define STACK_FRAME_TYPE_RA     0x80 // Whether the instruction pointer is the current IP or a RA from callee frame.
#define STACK_FRAME_TYPE_IGNORE 0xFF

#pragma warning(push)
#pragma warning(disable:4201) // nonstandard extension used : nameless struct

typedef union _INLINE_FRAME_CONTEXT {
    DWORD ContextValue;
    struct {
        BYTE FrameId;
        BYTE FrameType;
        WORD FrameSignature;
    };
} INLINE_FRAME_CONTEXT;

#pragma warning(pop)

typedef struct _STACK_SRC_INFO
{
    PCWSTR ImagePath;
    PCWSTR ModuleName;
    PCWSTR Function;
    ULONG Displacement;
    ULONG Row;
    ULONG Column;
} STACK_SRC_INFO, *PSTACK_SRC_INFO;

typedef struct _STACK_SYM_FRAME_INFO
{
    DEBUG_STACK_FRAME_EX StackFrameEx;
    STACK_SRC_INFO       SrcInfo;
} STACK_SYM_FRAME_INFO, *PSTACK_SYM_FRAME_INFO;

// OutputStackTrace flags.
// Display a small number of arguments for each call.
// These may or may not be the actual arguments depending
// on the architecture, particular function and
// point during the execution of the function.
// If the current code level is assembly arguments
// are dumped as hex values.  If the code level is
// source the engine attempts to provide symbolic
// argument information.
#define DEBUG_STACK_ARGUMENTS               0x00000001
// Displays information about the functions
// frame such as __stdcall arguments, FPO
// information and whatever else is available.
#define DEBUG_STACK_FUNCTION_INFO           0x00000002
// Displays source line information for each
// frame of the stack trace.
#define DEBUG_STACK_SOURCE_LINE             0x00000004
// Show return, previous frame and other relevant address
// values for each frame.
#define DEBUG_STACK_FRAME_ADDRESSES         0x00000008
// Show column names.
#define DEBUG_STACK_COLUMN_NAMES            0x00000010
// Show non-volatile register context for each
// frame.  This is only meaningful for some platforms.
#define DEBUG_STACK_NONVOLATILE_REGISTERS   0x00000020
// Show frame numbers
#define DEBUG_STACK_FRAME_NUMBERS           0x00000040
// Show typed source parameters.
#define DEBUG_STACK_PARAMETERS              0x00000080
// Show just return address in stack frame addresses.
#define DEBUG_STACK_FRAME_ADDRESSES_RA_ONLY 0x00000100
// Show frame-to-frame memory usage.
#define DEBUG_STACK_FRAME_MEMORY_USAGE      0x00000200
// Show typed source parameters one to a line.
#define DEBUG_STACK_PARAMETERS_NEWLINE      0x00000400
// Produce stack output enhanced with DML content.
#define DEBUG_STACK_DML                     0x00000800
// Show offset from stack frame
#define DEBUG_STACK_FRAME_OFFSETS           0x00001000
// The stack trace information is from a stack provider
#define DEBUG_STACK_PROVIDER                0x00002000
// The architecture of the frame (for mixed architecture stacks)
#define DEBUG_STACK_FRAME_ARCH              0x00004000

// Classes of debuggee.  Each class
// has different qualifiers for specific
// kinds of debuggees.
#define DEBUG_CLASS_UNINITIALIZED 0
#define DEBUG_CLASS_KERNEL        1
#define DEBUG_CLASS_USER_WINDOWS  2
#define DEBUG_CLASS_IMAGE_FILE    3

// Generic dump types.  These can be used
// with either user or kernel sessions.
// Session-type-specific aliases are also
// provided.
#define DEBUG_DUMP_SMALL      1024
#define DEBUG_DUMP_DEFAULT    1025
#define DEBUG_DUMP_FULL       1026
#define DEBUG_DUMP_IMAGE_FILE 1027
#define DEBUG_DUMP_TRACE_LOG  1028
#define DEBUG_DUMP_WINDOWS_CE 1029
#define DEBUG_DUMP_ACTIVE     1030

// Specific types of kernel debuggees.
#define DEBUG_KERNEL_CONNECTION     0
#define DEBUG_KERNEL_LOCAL          1
#define DEBUG_KERNEL_EXDI_DRIVER    2
#define DEBUG_KERNEL_IDNA           3
#define DEBUG_KERNEL_INSTALL_DRIVER 4
#define DEBUG_KERNEL_REPT           5

#define DEBUG_KERNEL_SMALL_DUMP  DEBUG_DUMP_SMALL
#define DEBUG_KERNEL_DUMP        DEBUG_DUMP_DEFAULT
#define DEBUG_KERNEL_ACTIVE_DUMP DEBUG_DUMP_ACTIVE
#define DEBUG_KERNEL_FULL_DUMP   DEBUG_DUMP_FULL

#define DEBUG_KERNEL_TRACE_LOG   DEBUG_DUMP_TRACE_LOG

// Specific types of Windows user debuggees.
#define DEBUG_USER_WINDOWS_PROCESS         0
#define DEBUG_USER_WINDOWS_PROCESS_SERVER  1
#define DEBUG_USER_WINDOWS_IDNA            2
#define DEBUG_USER_WINDOWS_REPT            3
#define DEBUG_USER_WINDOWS_SMALL_DUMP      DEBUG_DUMP_SMALL
#define DEBUG_USER_WINDOWS_DUMP            DEBUG_DUMP_DEFAULT
#define DEBUG_USER_WINDOWS_DUMP_WINDOWS_CE DEBUG_DUMP_WINDOWS_CE

// Extension flags.
#define DEBUG_EXTENSION_AT_ENGINE 0x00000000

// Execute and ExecuteCommandFile flags.
// These flags only apply to the command
// text itself; output from the executed
// command is controlled by the output
// control parameter.
// Default execution.  Command is logged
// but not output.
#define DEBUG_EXECUTE_DEFAULT    0x00000000
// Echo commands during execution.  In
// ExecuteCommandFile also echoes the prompt
// for each line of the file.
#define DEBUG_EXECUTE_ECHO       0x00000001
// Do not log or output commands during execution.
// Overridden by DEBUG_EXECUTE_ECHO.
#define DEBUG_EXECUTE_NOT_LOGGED 0x00000002
// If this flag is not set an empty string
// to Execute will repeat the last Execute
// string.
#define DEBUG_EXECUTE_NO_REPEAT  0x00000004
// If this flag is set , the source of command
// execution is user typing from remote session.
#define DEBUG_EXECUTE_USER_TYPED  0x00000008
// If this flag is set , the source of command
// execution is user clicking from remote session.
#define DEBUG_EXECUTE_USER_CLICKED  0x00000010
// If this flag is set , the source of command
// execution is debugger extension.
#define DEBUG_EXECUTE_EXTENSION  0x00000020
// If this flag is set , the source of command
// execution is internal command like debugger setup.
#define DEBUG_EXECUTE_INTERNAL  0x00000040
// If this flag is set , the source of command
// execution is debugger script.
#define DEBUG_EXECUTE_SCRIPT  0x00000080
// If this flag is set, the source of command
// execution is a toolbar button.
#define DEBUG_EXECUTE_TOOLBAR  0x00000100
// If this flag is set, the source of command
// execution is a menu item.
#define DEBUG_EXECUTE_MENU  0x00000200
// If this flag is set, the source of command
// execution is a keyboard shortcut or hotkey.
#define DEBUG_EXECUTE_HOTKEY  0x00000400
// If this flag is set, the source of command
// execution is a command registered on an event.
#define DEBUG_EXECUTE_EVENT  0x00000800

// Specific event filter types.  Some event
// filters have optional arguments to further
// qualify their operation.
#define DEBUG_FILTER_CREATE_THREAD       0x00000000
#define DEBUG_FILTER_EXIT_THREAD         0x00000001
#define DEBUG_FILTER_CREATE_PROCESS      0x00000002
#define DEBUG_FILTER_EXIT_PROCESS        0x00000003
// Argument is the name of a module to break on.
#define DEBUG_FILTER_LOAD_MODULE         0x00000004
// Argument is the base address of a specific module to break on.
#define DEBUG_FILTER_UNLOAD_MODULE       0x00000005
#define DEBUG_FILTER_SYSTEM_ERROR        0x00000006
// Initial breakpoint and initial module load are one-shot
// events that are triggered at the appropriate points in
// the beginning of a session.  Their commands are executed
// and then further processing is controlled by the normal
// exception and load module filters.
#define DEBUG_FILTER_INITIAL_BREAKPOINT  0x00000007
#define DEBUG_FILTER_INITIAL_MODULE_LOAD 0x00000008
// The debug output filter allows the debugger to stop
// when output is produced so that the code causing
// output can be tracked down or synchronized with.
// This filter is not supported for live dual-machine
// kernel debugging.
#define DEBUG_FILTER_DEBUGGEE_OUTPUT     0x00000009

// Event filter execution options.
// Break in always.
#define DEBUG_FILTER_BREAK               0x00000000
// Break in on second-chance exceptions.  For events
// that are not exceptions this is the same as BREAK.
#define DEBUG_FILTER_SECOND_CHANCE_BREAK 0x00000001
// Output a message about the event but continue.
#define DEBUG_FILTER_OUTPUT              0x00000002
// Continue the event.
#define DEBUG_FILTER_IGNORE              0x00000003
// Used to remove general exception filters.
#define DEBUG_FILTER_REMOVE              0x00000004

// Event filter continuation options.  These options are
// only used when DEBUG_STATUS_GO is used to continue
// execution.  If a specific go status such as
// DEBUG_STATUS_GO_NOT_HANDLED is used it controls
// the continuation.
#define DEBUG_FILTER_GO_HANDLED          0x00000000
#define DEBUG_FILTER_GO_NOT_HANDLED      0x00000001

// Specific event filter settings.
typedef struct _DEBUG_SPECIFIC_FILTER_PARAMETERS
{
    ULONG ExecutionOption;
    ULONG ContinueOption;
    ULONG TextSize;
    ULONG CommandSize;
    // If ArgumentSize is zero this filter does
    // not have an argument.  An empty argument for
    // a filter which does have an argument will take
    // one byte for the terminator.
    ULONG ArgumentSize;
} DEBUG_SPECIFIC_FILTER_PARAMETERS, *PDEBUG_SPECIFIC_FILTER_PARAMETERS;

// Exception event filter settings.
typedef struct _DEBUG_EXCEPTION_FILTER_PARAMETERS
{
    ULONG ExecutionOption;
    ULONG ContinueOption;
    ULONG TextSize;
    ULONG CommandSize;
    ULONG SecondCommandSize;
    ULONG ExceptionCode;
} DEBUG_EXCEPTION_FILTER_PARAMETERS, *PDEBUG_EXCEPTION_FILTER_PARAMETERS;

// Wait flags.
#define DEBUG_WAIT_DEFAULT 0x00000000

// Last event information structures.
typedef struct _DEBUG_LAST_EVENT_INFO_BREAKPOINT
{
    ULONG Id;
} DEBUG_LAST_EVENT_INFO_BREAKPOINT, *PDEBUG_LAST_EVENT_INFO_BREAKPOINT;

typedef struct _DEBUG_LAST_EVENT_INFO_EXCEPTION
{
    EXCEPTION_RECORD64 ExceptionRecord;
    ULONG FirstChance;
} DEBUG_LAST_EVENT_INFO_EXCEPTION, *PDEBUG_LAST_EVENT_INFO_EXCEPTION;

typedef struct _DEBUG_LAST_EVENT_INFO_EXIT_THREAD
{
    ULONG ExitCode;
} DEBUG_LAST_EVENT_INFO_EXIT_THREAD, *PDEBUG_LAST_EVENT_INFO_EXIT_THREAD;

typedef struct _DEBUG_LAST_EVENT_INFO_EXIT_PROCESS
{
    ULONG ExitCode;
} DEBUG_LAST_EVENT_INFO_EXIT_PROCESS, *PDEBUG_LAST_EVENT_INFO_EXIT_PROCESS;

typedef struct _DEBUG_LAST_EVENT_INFO_LOAD_MODULE
{
    ULONG64 Base;
} DEBUG_LAST_EVENT_INFO_LOAD_MODULE, *PDEBUG_LAST_EVENT_INFO_LOAD_MODULE;

typedef struct _DEBUG_LAST_EVENT_INFO_UNLOAD_MODULE
{
    ULONG64 Base;
} DEBUG_LAST_EVENT_INFO_UNLOAD_MODULE, *PDEBUG_LAST_EVENT_INFO_UNLOAD_MODULE;

typedef struct _DEBUG_LAST_EVENT_INFO_SYSTEM_ERROR
{
    ULONG Error;
    ULONG Level;
} DEBUG_LAST_EVENT_INFO_SYSTEM_ERROR, *PDEBUG_LAST_EVENT_INFO_SYSTEM_ERROR;

typedef struct _DEBUG_LAST_EVENT_INFO_SERVICE_EXCEPTION
{
    ULONG Kind;
    ULONG DataSize;
    ULONG64 Address;

    //
    // (Kind) Specific Data... (e.g.: an EXCEPTION_RECORD64 or another definition given by
    //                                a specific platform service)
    //
} DEBUG_LAST_EVENT_INFO_SERVICE_EXCEPTION, *PDEBUG_LAST_EVENT_INFO_SERVICE_EXCEPTION;

// DEBUG_VALUE types.
#define DEBUG_VALUE_INVALID      0
#define DEBUG_VALUE_INT8         1
#define DEBUG_VALUE_INT16        2
#define DEBUG_VALUE_INT32        3
#define DEBUG_VALUE_INT64        4
#define DEBUG_VALUE_FLOAT32      5
#define DEBUG_VALUE_FLOAT64      6
#define DEBUG_VALUE_FLOAT80      7
#define DEBUG_VALUE_FLOAT82      8
#define DEBUG_VALUE_FLOAT128     9
#define DEBUG_VALUE_VECTOR64     10
#define DEBUG_VALUE_VECTOR128    11
// Count of type indices.
#define DEBUG_VALUE_TYPES        12

#if defined(_MSC_VER)
#if _MSC_VER >= 800
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201)    /* Nameless struct/union */
#endif
#endif

// We want the DEBUG_VALUE structure to have 8-byte alignment
// and be 32 bytes total.  This is tricky because the compiler
// wants to pad the union of values out to a even 8-byte multiple,
// pushing the type out too far.  We can't use 4-packing because
// then the 8-byte alignment requirement is lost, so instead
// we shrink the union to 24 bytes and have a reserved field
// before the type field.  The same amount of space is available
// and everybody's happy, but the structure is somewhat unusual.

typedef struct _DEBUG_VALUE
{
    union
    {
        UCHAR I8;
        USHORT I16;
        ULONG I32;
        struct
        {
            // Extra NAT indicator for IA64
            // integer registers.  NAT will
            // always be false for other CPUs.
            ULONG64 I64;
            BOOL Nat;
        };
        float F32;
        double F64;
        UCHAR F80Bytes[10];
        UCHAR F82Bytes[11];
        UCHAR F128Bytes[16];
        // Vector interpretations.  The actual number
        // of valid elements depends on the vector length.
        UCHAR VI8[16];
        USHORT VI16[8];
        ULONG VI32[4];
        ULONG64 VI64[2];
        float VF32[4];
        double VF64[2];
        struct
        {
            ULONG LowPart;
            ULONG HighPart;
        } I64Parts32;
        struct
        {
            ULONG64 LowPart;
            LONG64 HighPart;
        } F128Parts64;
        // Allows raw byte access to content.  Array
        // can be indexed for as much data as Type
        // describes.  This array also serves to pad
        // the structure out to 32 bytes and reserves
        // space for future members.
        UCHAR RawBytes[24];
    };
    ULONG TailOfRawBytes;
  ULONG Type;
} DEBUG_VALUE, *PDEBUG_VALUE;

#if defined(_MSC_VER)
#if _MSC_VER >= 800
#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201)    /* Nameless struct/union */
#endif
#endif
#endif

#undef INTERFACE
#define INTERFACE IDebugControl
DECLARE_INTERFACE_(IDebugControl, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
    STDMETHOD(GetInterrupt)(
        THIS
        ) PURE;
    // Registers a user interrupt.
    // This method is reentrant.
    STDMETHOD(SetInterrupt)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
    STDMETHOD(GetInterruptTimeout)(
        THIS_
        _Out_ PULONG Seconds
        ) PURE;
    STDMETHOD(SetInterruptTimeout)(
        THIS_
        _In_ ULONG Seconds
        ) PURE;

    STDMETHOD(GetLogFile)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
    STDMETHOD(OpenLogFile)(
        THIS_
        _In_ PCSTR File,
        _In_ BOOL Append
        ) PURE;
    STDMETHOD(CloseLogFile)(
        THIS
        ) PURE;
    // Controls what output is logged.
    STDMETHOD(GetLogMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetLogMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;

    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
    STDMETHOD(Input)(
        THIS_
        _Out_writes_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
    STDMETHOD(ReturnInput)(
        THIS_
        _In_ PCSTR Buffer
        ) PURE;

    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
    STDMETHODV(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaList)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
    STDMETHODV(ControlledOutput)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;

    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
    STDMETHODV(OutputPrompt)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // Gets the text that would be displayed by OutputPrompt.
    STDMETHOD(GetPromptText)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
    STDMETHOD(OutputCurrentState)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
    STDMETHOD(OutputVersionInformation)(
        THIS_
        _In_ ULONG OutputControl
        ) PURE;

    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
    STDMETHOD(GetNotifyEventHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(SetNotifyEventHandle)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Assemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(Disassemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
    STDMETHOD(GetDisassembleEffectiveOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Uses the line prefix if necessary.
    STDMETHOD(OutputDisassembly)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
    STDMETHOD(OutputDisassemblyLines)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG PreviousLines,
        _In_ ULONG TotalLines,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_opt_ PULONG OffsetLine,
        _Out_opt_ PULONG64 StartOffset,
        _Out_opt_ PULONG64 EndOffset,
        _Out_writes_opt_(TotalLines) PULONG64 LineOffsets
        ) PURE;
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
    STDMETHOD(GetNearInstruction)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_ PULONG64 NearOffset
        ) PURE;

    // Offsets can be passed in as zero to use the current
    // thread state.
    STDMETHOD(GetStackTrace)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    // Does a simple stack trace to determine
    // what the current return address is.
    STDMETHOD(GetReturnOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
    STDMETHOD(OutputStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
    STDMETHOD(GetDebuggeeType)(
        THIS_
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
    STDMETHOD(GetActualProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Returns the type of processor used in the
    // current processor context.
    STDMETHOD(GetExecutingProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Query all the possible processor types that
    // may be encountered during this debug session.
    STDMETHOD(GetNumberPossibleExecutingProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPossibleExecutingProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Get the number of actual processors in
    // the machine.
    STDMETHOD(GetNumberProcessors)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
    STDMETHOD(GetSystemVersion)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Major,
        _Out_ PULONG Minor,
        _Out_writes_opt_(ServicePackStringSize) PSTR ServicePackString,
        _In_ ULONG ServicePackStringSize,
        _Out_opt_ PULONG ServicePackStringUsed,
        _Out_ PULONG ServicePackNumber,
        _Out_writes_opt_(BuildStringSize) PSTR BuildString,
        _In_ ULONG BuildStringSize,
        _Out_opt_ PULONG BuildStringUsed
        ) PURE;
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
    STDMETHOD(GetPageSize)(
        THIS_
        _Out_ PULONG Size
        ) PURE;
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
    STDMETHOD(IsPointer64Bit)(
        THIS
        ) PURE;
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
    STDMETHOD(ReadBugCheckData)(
        THIS_
        _Out_ PULONG Code,
        _Out_ PULONG64 Arg1,
        _Out_ PULONG64 Arg2,
        _Out_ PULONG64 Arg3,
        _Out_ PULONG64 Arg4
        ) PURE;

    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
    STDMETHOD(GetNumberSupportedProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSupportedProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
    STDMETHOD(GetProcessorTypeNames)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
    STDMETHOD(GetEffectiveProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(SetEffectiveProcessorType)(
        THIS_
        _In_ ULONG Type
        ) PURE;

    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
    STDMETHOD(GetExecutionStatus)(
        THIS_
        _Out_ PULONG Status
        ) PURE;
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
    STDMETHOD(SetExecutionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
    STDMETHOD(GetCodeLevel)(
        THIS_
        _Out_ PULONG Level
        ) PURE;
    STDMETHOD(SetCodeLevel)(
        THIS_
        _In_ ULONG Level
        ) PURE;

    // Gets and sets engine control flags.
    // These methods are reentrant.
    STDMETHOD(GetEngineOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
    STDMETHOD(GetSystemErrorControl)(
        THIS_
        _Out_ PULONG OutputLevel,
        _Out_ PULONG BreakLevel
        ) PURE;
    STDMETHOD(SetSystemErrorControl)(
        THIS_
        _In_ ULONG OutputLevel,
        _In_ ULONG BreakLevel
        ) PURE;

    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
    STDMETHOD(GetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCSTR Macro
        ) PURE;

    // Controls the default number radix used
    // in expressions and commands.
    STDMETHOD(GetRadix)(
        THIS_
        _Out_ PULONG Radix
        ) PURE;
    STDMETHOD(SetRadix)(
        THIS_
        _In_ ULONG Radix
        ) PURE;

    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
    STDMETHOD(Evaluate)(
        THIS_
        _In_ PCSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
    STDMETHOD(CoerceValue)(
        THIS_
        _In_ PDEBUG_VALUE In,
        _In_ ULONG OutType,
        _Out_ PDEBUG_VALUE Out
        ) PURE;
    STDMETHOD(CoerceValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_VALUE In,
        _In_reads_(Count) PULONG OutTypes,
        _Out_writes_(Count) PDEBUG_VALUE Out
        ) PURE;

    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
    STDMETHOD(Execute)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Command,
        _In_ ULONG Flags
        ) PURE;
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
    STDMETHOD(ExecuteCommandFile)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    // Breakpoint interfaces are described
    // elsewhere in this section.
    STDMETHOD(GetNumberBreakpoints)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
    STDMETHOD(GetBreakpointByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
    STDMETHOD(GetBreakpointParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Ids,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
    STDMETHOD(AddBreakpoint)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // Breakpoint interface is invalid after this call.
    STDMETHOD(RemoveBreakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Control and use extension DLLs.
    STDMETHOD(AddExtension)(
        THIS_
        _In_ PCSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(RemoveExtension)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPath)(
        THIS_
        _In_ PCSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
    STDMETHOD(CallExtension)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR Function,
        _In_opt_ PCSTR Arguments
        ) PURE;
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // _EFN_ is automatically prepended to
    // the name string given.
    // This function cannot be called remotely.
    STDMETHOD(GetExtensionFunction)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
    STDMETHOD(GetWindbgExtensionApis32)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS32 Api
        ) PURE;
    STDMETHOD(GetWindbgExtensionApis64)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS64 Api
        ) PURE;

    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
    STDMETHOD(GetNumberEventFilters)(
        THIS_
        _Out_ PULONG SpecificEvents,
        _Out_ PULONG SpecificExceptions,
        _Out_ PULONG ArbitraryExceptions
        ) PURE;
    // Some filters have descriptive text associated with them.
    STDMETHOD(GetEventFilterText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // All filters support executing a command when the
    // event occurs.
    STDMETHOD(GetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    STDMETHOD(SetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    // Some specific filters have arguments to further
    // qualify their operation.
    STDMETHOD(GetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Argument
        ) PURE;
    // If Codes is non-NULL Start is ignored.
    STDMETHOD(GetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Codes,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
    STDMETHOD(SetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // Exception filters support an additional command for
    // second-chance events.
    STDMETHOD(GetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;

    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
    STDMETHOD(WaitForEvent)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Timeout
        ) PURE;

    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
    STDMETHOD(GetLastEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;
};

// OutputTextReplacements flags.
#define DEBUG_OUT_TEXT_REPL_DEFAULT 0x00000000

#undef INTERFACE
#define INTERFACE IDebugControl2
DECLARE_INTERFACE_(IDebugControl2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
    STDMETHOD(GetInterrupt)(
        THIS
        ) PURE;
    // Registers a user interrupt.
    // This method is reentrant.
    STDMETHOD(SetInterrupt)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
    STDMETHOD(GetInterruptTimeout)(
        THIS_
        _Out_ PULONG Seconds
        ) PURE;
    STDMETHOD(SetInterruptTimeout)(
        THIS_
        _In_ ULONG Seconds
        ) PURE;

    STDMETHOD(GetLogFile)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
    STDMETHOD(OpenLogFile)(
        THIS_
        _In_ PCSTR File,
        _In_ BOOL Append
        ) PURE;
    STDMETHOD(CloseLogFile)(
        THIS
        ) PURE;
    // Controls what output is logged.
    STDMETHOD(GetLogMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetLogMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;

    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
    STDMETHOD(Input)(
        THIS_
        _Out_writes_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
    STDMETHOD(ReturnInput)(
        THIS_
        _In_ PCSTR Buffer
        ) PURE;

    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
    STDMETHODV(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaList)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
    STDMETHODV(ControlledOutput)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;

    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
    STDMETHODV(OutputPrompt)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // Gets the text that would be displayed by OutputPrompt.
    STDMETHOD(GetPromptText)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
    STDMETHOD(OutputCurrentState)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
    STDMETHOD(OutputVersionInformation)(
        THIS_
        _In_ ULONG OutputControl
        ) PURE;

    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
    STDMETHOD(GetNotifyEventHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(SetNotifyEventHandle)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Assemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(Disassemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
    STDMETHOD(GetDisassembleEffectiveOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Uses the line prefix if necessary.
    STDMETHOD(OutputDisassembly)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
    STDMETHOD(OutputDisassemblyLines)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG PreviousLines,
        _In_ ULONG TotalLines,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_opt_ PULONG OffsetLine,
        _Out_opt_ PULONG64 StartOffset,
        _Out_opt_ PULONG64 EndOffset,
        _Out_writes_opt_(TotalLines) PULONG64 LineOffsets
        ) PURE;
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
    STDMETHOD(GetNearInstruction)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_ PULONG64 NearOffset
        ) PURE;

    // Offsets can be passed in as zero to use the current
    // thread state.
    STDMETHOD(GetStackTrace)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    // Does a simple stack trace to determine
    // what the current return address is.
    STDMETHOD(GetReturnOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
    STDMETHOD(OutputStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
    STDMETHOD(GetDebuggeeType)(
        THIS_
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
    STDMETHOD(GetActualProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Returns the type of processor used in the
    // current processor context.
    STDMETHOD(GetExecutingProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Query all the possible processor types that
    // may be encountered during this debug session.
    STDMETHOD(GetNumberPossibleExecutingProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPossibleExecutingProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Get the number of actual processors in
    // the machine.
    STDMETHOD(GetNumberProcessors)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
    STDMETHOD(GetSystemVersion)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Major,
        _Out_ PULONG Minor,
        _Out_writes_opt_(ServicePackStringSize) PSTR ServicePackString,
        _In_ ULONG ServicePackStringSize,
        _Out_opt_ PULONG ServicePackStringUsed,
        _Out_ PULONG ServicePackNumber,
        _Out_writes_opt_(BuildStringSize) PSTR BuildString,
        _In_ ULONG BuildStringSize,
        _Out_opt_ PULONG BuildStringUsed
        ) PURE;
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
    STDMETHOD(GetPageSize)(
        THIS_
        _Out_ PULONG Size
        ) PURE;
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
    STDMETHOD(IsPointer64Bit)(
        THIS
        ) PURE;
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
    STDMETHOD(ReadBugCheckData)(
        THIS_
        _Out_ PULONG Code,
        _Out_ PULONG64 Arg1,
        _Out_ PULONG64 Arg2,
        _Out_ PULONG64 Arg3,
        _Out_ PULONG64 Arg4
        ) PURE;

    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
    STDMETHOD(GetNumberSupportedProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSupportedProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
    STDMETHOD(GetProcessorTypeNames)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
    STDMETHOD(GetEffectiveProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(SetEffectiveProcessorType)(
        THIS_
        _In_ ULONG Type
        ) PURE;

    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
    STDMETHOD(GetExecutionStatus)(
        THIS_
        _Out_ PULONG Status
        ) PURE;
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
    STDMETHOD(SetExecutionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
    STDMETHOD(GetCodeLevel)(
        THIS_
        _Out_ PULONG Level
        ) PURE;
    STDMETHOD(SetCodeLevel)(
        THIS_
        _In_ ULONG Level
        ) PURE;

    // Gets and sets engine control flags.
    // These methods are reentrant.
    STDMETHOD(GetEngineOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
    STDMETHOD(GetSystemErrorControl)(
        THIS_
        _Out_ PULONG OutputLevel,
        _Out_ PULONG BreakLevel
        ) PURE;
    STDMETHOD(SetSystemErrorControl)(
        THIS_
        _In_ ULONG OutputLevel,
        _In_ ULONG BreakLevel
        ) PURE;

    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
    STDMETHOD(GetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCSTR Macro
        ) PURE;

    // Controls the default number radix used
    // in expressions and commands.
    STDMETHOD(GetRadix)(
        THIS_
        _Out_ PULONG Radix
        ) PURE;
    STDMETHOD(SetRadix)(
        THIS_
        _In_ ULONG Radix
        ) PURE;

    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
    STDMETHOD(Evaluate)(
        THIS_
        _In_ PCSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
    STDMETHOD(CoerceValue)(
        THIS_
        _In_ PDEBUG_VALUE In,
        _In_ ULONG OutType,
        _Out_ PDEBUG_VALUE Out
        ) PURE;
    STDMETHOD(CoerceValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_VALUE In,
        _In_reads_(Count) PULONG OutTypes,
        _Out_writes_(Count) PDEBUG_VALUE Out
        ) PURE;

    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
    STDMETHOD(Execute)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Command,
        _In_ ULONG Flags
        ) PURE;
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
    STDMETHOD(ExecuteCommandFile)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    // Breakpoint interfaces are described
    // elsewhere in this section.
    STDMETHOD(GetNumberBreakpoints)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
    STDMETHOD(GetBreakpointByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
    STDMETHOD(GetBreakpointParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Ids,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
    STDMETHOD(AddBreakpoint)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // Breakpoint interface is invalid after this call.
    STDMETHOD(RemoveBreakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Control and use extension DLLs.
    STDMETHOD(AddExtension)(
        THIS_
        _In_ PCSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(RemoveExtension)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPath)(
        THIS_
        _In_ PCSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
    STDMETHOD(CallExtension)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR Function,
        _In_opt_ PCSTR Arguments
        ) PURE;
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // This function cannot be called remotely.
    STDMETHOD(GetExtensionFunction)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
    STDMETHOD(GetWindbgExtensionApis32)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS32 Api
        ) PURE;
    STDMETHOD(GetWindbgExtensionApis64)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS64 Api
        ) PURE;

    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
    STDMETHOD(GetNumberEventFilters)(
        THIS_
        _Out_ PULONG SpecificEvents,
        _Out_ PULONG SpecificExceptions,
        _Out_ PULONG ArbitraryExceptions
        ) PURE;
    // Some filters have descriptive text associated with them.
    STDMETHOD(GetEventFilterText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // All filters support executing a command when the
    // event occurs.
    STDMETHOD(GetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    STDMETHOD(SetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    // Some specific filters have arguments to further
    // qualify their operation.
    STDMETHOD(GetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Argument
        ) PURE;
    // If Codes is non-NULL Start is ignored.
    STDMETHOD(GetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Codes,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
    STDMETHOD(SetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // Exception filters support an additional command for
    // second-chance events.
    STDMETHOD(GetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;

    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
    STDMETHOD(WaitForEvent)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Timeout
        ) PURE;

    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
    STDMETHOD(GetLastEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    // IDebugControl2.

    STDMETHOD(GetCurrentTimeDate)(
        THIS_
        _Out_ PULONG TimeDate
        ) PURE;
    // Retrieves the number of seconds since the
    // machine started running.
    STDMETHOD(GetCurrentSystemUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // If the current session is a dump session,
    // retrieves any extended format information.
    STDMETHOD(GetDumpFormatFlags)(
        THIS_
        _Out_ PULONG FormatFlags
        ) PURE;

    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
    STDMETHOD(GetNumberTextReplacements)(
        THIS_
        _Out_ PULONG NumRepl
        ) PURE;
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
    STDMETHOD(GetTextReplacement)(
        THIS_
        _In_opt_ PCSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    // Setting the destination text to
    // NULL removes the alias.
    STDMETHOD(SetTextReplacement)(
        THIS_
        _In_ PCSTR SrcText,
        _In_opt_ PCSTR DstText
        ) PURE;
    STDMETHOD(RemoveTextReplacements)(
        THIS
        ) PURE;
    // Outputs the complete list of current
    // replacements.
    STDMETHOD(OutputTextReplacements)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;
};

//
// Assembly/disassembly options.
//
// The specific effects of these flags varies depending
// on the particular instruction set.
//

#define DEBUG_ASMOPT_DEFAULT             0x00000000
// Display additional information in disassembly.
#define DEBUG_ASMOPT_VERBOSE             0x00000001
// Do not display raw code bytes in disassembly.
#define DEBUG_ASMOPT_NO_CODE_BYTES       0x00000002
// Do not take the output width into account when
// formatting disassembly.
#define DEBUG_ASMOPT_IGNORE_OUTPUT_WIDTH 0x00000004
// Display source file line number before each line if available.
#define DEBUG_ASMOPT_SOURCE_LINE_NUMBER  0x00000008

//
// Expression syntax options.
//

// MASM-style expression evaluation.
#define DEBUG_EXPR_MASM      0x00000000
// C++-style expression evaluation.
#define DEBUG_EXPR_CPLUSPLUS 0x00000001

//
// Event index description information.
//

#define DEBUG_EINDEX_NAME 0x00000000

//
// SetNextEventIndex relation options.
//

// Value increases forward from the first index.
#define DEBUG_EINDEX_FROM_START   0x00000000
// Value increases backwards from the last index.
#define DEBUG_EINDEX_FROM_END     0x00000001
// Value is a signed delta from the current index.
#define DEBUG_EINDEX_FROM_CURRENT 0x00000002

#undef INTERFACE
#define INTERFACE IDebugControl3
DECLARE_INTERFACE_(IDebugControl3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
    STDMETHOD(GetInterrupt)(
        THIS
        ) PURE;
    // Registers a user interrupt.
    // This method is reentrant.
    STDMETHOD(SetInterrupt)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
    STDMETHOD(GetInterruptTimeout)(
        THIS_
        _Out_ PULONG Seconds
        ) PURE;
    STDMETHOD(SetInterruptTimeout)(
        THIS_
        _In_ ULONG Seconds
        ) PURE;

    STDMETHOD(GetLogFile)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
    STDMETHOD(OpenLogFile)(
        THIS_
        _In_ PCSTR File,
        _In_ BOOL Append
        ) PURE;
    STDMETHOD(CloseLogFile)(
        THIS
        ) PURE;
    // Controls what output is logged.
    STDMETHOD(GetLogMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetLogMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;

    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
    STDMETHOD(Input)(
        THIS_
        _Out_writes_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
    STDMETHOD(ReturnInput)(
        THIS_
        _In_ PCSTR Buffer
        ) PURE;

    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
    STDMETHODV(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaList)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
    STDMETHODV(ControlledOutput)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;

    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
    STDMETHODV(OutputPrompt)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // Gets the text that would be displayed by OutputPrompt.
    STDMETHOD(GetPromptText)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
    STDMETHOD(OutputCurrentState)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
    STDMETHOD(OutputVersionInformation)(
        THIS_
        _In_ ULONG OutputControl
        ) PURE;

    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
    STDMETHOD(GetNotifyEventHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(SetNotifyEventHandle)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Assemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(Disassemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
    STDMETHOD(GetDisassembleEffectiveOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Uses the line prefix if necessary.
    STDMETHOD(OutputDisassembly)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
    STDMETHOD(OutputDisassemblyLines)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG PreviousLines,
        _In_ ULONG TotalLines,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_opt_ PULONG OffsetLine,
        _Out_opt_ PULONG64 StartOffset,
        _Out_opt_ PULONG64 EndOffset,
        _Out_writes_opt_(TotalLines) PULONG64 LineOffsets
        ) PURE;
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
    STDMETHOD(GetNearInstruction)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_ PULONG64 NearOffset
        ) PURE;

    // Offsets can be passed in as zero to use the current
    // thread state.
    STDMETHOD(GetStackTrace)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    // Does a simple stack trace to determine
    // what the current return address is.
    STDMETHOD(GetReturnOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
    STDMETHOD(OutputStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
    STDMETHOD(GetDebuggeeType)(
        THIS_
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
    STDMETHOD(GetActualProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Returns the type of processor used in the
    // current processor context.
    STDMETHOD(GetExecutingProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Query all the possible processor types that
    // may be encountered during this debug session.
    STDMETHOD(GetNumberPossibleExecutingProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPossibleExecutingProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Get the number of actual processors in
    // the machine.
    STDMETHOD(GetNumberProcessors)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
    STDMETHOD(GetSystemVersion)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Major,
        _Out_ PULONG Minor,
        _Out_writes_opt_(ServicePackStringSize) PSTR ServicePackString,
        _In_ ULONG ServicePackStringSize,
        _Out_opt_ PULONG ServicePackStringUsed,
        _Out_ PULONG ServicePackNumber,
        _Out_writes_opt_(BuildStringSize) PSTR BuildString,
        _In_ ULONG BuildStringSize,
        _Out_opt_ PULONG BuildStringUsed
        ) PURE;
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
    STDMETHOD(GetPageSize)(
        THIS_
        _Out_ PULONG Size
        ) PURE;
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
    STDMETHOD(IsPointer64Bit)(
        THIS
        ) PURE;
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
    STDMETHOD(ReadBugCheckData)(
        THIS_
        _Out_ PULONG Code,
        _Out_ PULONG64 Arg1,
        _Out_ PULONG64 Arg2,
        _Out_ PULONG64 Arg3,
        _Out_ PULONG64 Arg4
        ) PURE;

    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
    STDMETHOD(GetNumberSupportedProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSupportedProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
    STDMETHOD(GetProcessorTypeNames)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
    STDMETHOD(GetEffectiveProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(SetEffectiveProcessorType)(
        THIS_
        _In_ ULONG Type
        ) PURE;

    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
    STDMETHOD(GetExecutionStatus)(
        THIS_
        _Out_ PULONG Status
        ) PURE;
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
    STDMETHOD(SetExecutionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
    STDMETHOD(GetCodeLevel)(
        THIS_
        _Out_ PULONG Level
        ) PURE;
    STDMETHOD(SetCodeLevel)(
        THIS_
        _In_ ULONG Level
        ) PURE;

    // Gets and sets engine control flags.
    // These methods are reentrant.
    STDMETHOD(GetEngineOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
    STDMETHOD(GetSystemErrorControl)(
        THIS_
        _Out_ PULONG OutputLevel,
        _Out_ PULONG BreakLevel
        ) PURE;
    STDMETHOD(SetSystemErrorControl)(
        THIS_
        _In_ ULONG OutputLevel,
        _In_ ULONG BreakLevel
        ) PURE;

    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
    STDMETHOD(GetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCSTR Macro
        ) PURE;

    // Controls the default number radix used
    // in expressions and commands.
    STDMETHOD(GetRadix)(
        THIS_
        _Out_ PULONG Radix
        ) PURE;
    STDMETHOD(SetRadix)(
        THIS_
        _In_ ULONG Radix
        ) PURE;

    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
    STDMETHOD(Evaluate)(
        THIS_
        _In_ PCSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
    STDMETHOD(CoerceValue)(
        THIS_
        _In_ PDEBUG_VALUE In,
        _In_ ULONG OutType,
        _Out_ PDEBUG_VALUE Out
        ) PURE;
    STDMETHOD(CoerceValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_VALUE In,
        _In_reads_(Count) PULONG OutTypes,
        _Out_writes_(Count) PDEBUG_VALUE Out
        ) PURE;

    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
    STDMETHOD(Execute)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Command,
        _In_ ULONG Flags
        ) PURE;
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
    STDMETHOD(ExecuteCommandFile)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    // Breakpoint interfaces are described
    // elsewhere in this section.
    STDMETHOD(GetNumberBreakpoints)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
    STDMETHOD(GetBreakpointByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
    STDMETHOD(GetBreakpointParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Ids,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
    STDMETHOD(AddBreakpoint)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // Breakpoint interface is invalid after this call.
    STDMETHOD(RemoveBreakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Control and use extension DLLs.
    STDMETHOD(AddExtension)(
        THIS_
        _In_ PCSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(RemoveExtension)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPath)(
        THIS_
        _In_ PCSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
    STDMETHOD(CallExtension)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR Function,
        _In_opt_ PCSTR Arguments
        ) PURE;
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // This function cannot be called remotely.
    STDMETHOD(GetExtensionFunction)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
    STDMETHOD(GetWindbgExtensionApis32)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS32 Api
        ) PURE;
    STDMETHOD(GetWindbgExtensionApis64)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS64 Api
        ) PURE;

    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
    STDMETHOD(GetNumberEventFilters)(
        THIS_
        _Out_ PULONG SpecificEvents,
        _Out_ PULONG SpecificExceptions,
        _Out_ PULONG ArbitraryExceptions
        ) PURE;
    // Some filters have descriptive text associated with them.
    STDMETHOD(GetEventFilterText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // All filters support executing a command when the
    // event occurs.
    STDMETHOD(GetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    STDMETHOD(SetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    // Some specific filters have arguments to further
    // qualify their operation.
    STDMETHOD(GetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Argument
        ) PURE;
    // If Codes is non-NULL Start is ignored.
    STDMETHOD(GetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Codes,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
    STDMETHOD(SetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // Exception filters support an additional command for
    // second-chance events.
    STDMETHOD(GetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;

    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
    STDMETHOD(WaitForEvent)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Timeout
        ) PURE;

    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
    STDMETHOD(GetLastEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    // IDebugControl2.

    STDMETHOD(GetCurrentTimeDate)(
        THIS_
        _Out_ PULONG TimeDate
        ) PURE;
    // Retrieves the number of seconds since the
    // machine started running.
    STDMETHOD(GetCurrentSystemUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // If the current session is a dump session,
    // retrieves any extended format information.
    STDMETHOD(GetDumpFormatFlags)(
        THIS_
        _Out_ PULONG FormatFlags
        ) PURE;

    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
    STDMETHOD(GetNumberTextReplacements)(
        THIS_
        _Out_ PULONG NumRepl
        ) PURE;
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
    STDMETHOD(GetTextReplacement)(
        THIS_
        _In_opt_ PCSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    // Setting the destination text to
    // NULL removes the alias.
    STDMETHOD(SetTextReplacement)(
        THIS_
        _In_ PCSTR SrcText,
        _In_opt_ PCSTR DstText
        ) PURE;
    STDMETHOD(RemoveTextReplacements)(
        THIS
        ) PURE;
    // Outputs the complete list of current
    // replacements.
    STDMETHOD(OutputTextReplacements)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl3.

    // Control options for assembly and disassembly.
    STDMETHOD(GetAssemblyOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Control the expression syntax.
    STDMETHOD(GetExpressionSyntax)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(SetExpressionSyntax)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Look up a syntax by its abbreviated
    // name and set it.
    STDMETHOD(SetExpressionSyntaxByName)(
        THIS_
        _In_ PCSTR AbbrevName
        ) PURE;
    STDMETHOD(GetNumberExpressionSyntaxes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNames)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    //
    // Some debug sessions have only a single
    // possible event, such as a snapshot dump
    // file; some have dynamic events, such as
    // a live debug session; and others may have
    // multiple events, such as a dump file that
    // contains snapshots from different points
    // in time.  The following methods allow
    // discovery and selection of the available
    // events for a session.
    // Sessions with one or more static events
    // will be able to report all of the events
    // when queried.  Sessions with dynamic events
    // will only report a single event representing
    // the current event.
    // Switching events constitutes execution and
    // changing the current event will alter the
    // execution status to a running state, after
    // which WaitForEvent must be used to process
    // the selected event.
    //

    // GetNumberEvents returns S_OK if this is the
    // complete set of events possible, such as for
    // a static session; or S_FALSE if other events
    // may be possible, such as for a dynamic session.
    STDMETHOD(GetNumberEvents)(
        THIS_
        _Out_ PULONG Events
        ) PURE;
    // Sessions may have descriptive information for
    // the various events available.  The amount of
    // information varies according to the specific
    // session and data.
    STDMETHOD(GetEventIndexDescription)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;
    STDMETHOD(GetCurrentEventIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    // SetNextEventIndex works like seek in that
    // it can set an absolute or relative index.
    // SetNextEventIndex works similarly to SetExecutionStatus
    // by putting the session into a running state, after
    // which the caller must call WaitForEvent.  The
    // current event index only changes when WaitForEvent
    // is called.
    STDMETHOD(SetNextEventIndex)(
        THIS_
        _In_ ULONG Relation,
        _In_ ULONG Value,
        _Out_ PULONG NextIndex
        ) PURE;
};

//
// Log file flags.
//

#define DEBUG_LOG_DEFAULT 0x00000000
#define DEBUG_LOG_APPEND  0x00000001
#define DEBUG_LOG_UNICODE 0x00000002
#define DEBUG_LOG_DML     0x00000004

//
// System version strings.
//

#define DEBUG_SYSVERSTR_SERVICE_PACK 0x00000000
#define DEBUG_SYSVERSTR_BUILD        0x00000001

//
// GetManagedStatus flags and strings.
//

#define DEBUG_MANAGED_DISABLED   0x00000000
#define DEBUG_MANAGED_ALLOWED    0x00000001
#define DEBUG_MANAGED_DLL_LOADED 0x00000002

#define DEBUG_MANSTR_NONE               0x00000000
#define DEBUG_MANSTR_LOADED_SUPPORT_DLL 0x00000001
#define DEBUG_MANSTR_LOAD_STATUS        0x00000002

//
// ResetManagedStatus flags.
//

// Reset state to default engine startup state with
// no support loaded.
#define DEBUG_MANRESET_DEFAULT  0x00000000
// Force managed support DLL load attempt.
#define DEBUG_MANRESET_LOAD_DLL 0x00000001

#undef INTERFACE
#define INTERFACE IDebugControl4
DECLARE_INTERFACE_(IDebugControl4, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
    STDMETHOD(GetInterrupt)(
        THIS
        ) PURE;
    // Registers a user interrupt.
    // This method is reentrant.
    STDMETHOD(SetInterrupt)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
    STDMETHOD(GetInterruptTimeout)(
        THIS_
        _Out_ PULONG Seconds
        ) PURE;
    STDMETHOD(SetInterruptTimeout)(
        THIS_
        _In_ ULONG Seconds
        ) PURE;

    STDMETHOD(GetLogFile)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
    STDMETHOD(OpenLogFile)(
        THIS_
        _In_ PCSTR File,
        _In_ BOOL Append
        ) PURE;
    STDMETHOD(CloseLogFile)(
        THIS
        ) PURE;
    // Controls what output is logged.
    STDMETHOD(GetLogMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetLogMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;

    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
    STDMETHOD(Input)(
        THIS_
        _Out_writes_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
    STDMETHOD(ReturnInput)(
        THIS_
        _In_ PCSTR Buffer
        ) PURE;

    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
    STDMETHODV(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaList)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
    STDMETHODV(ControlledOutput)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;

    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
    STDMETHODV(OutputPrompt)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // Gets the text that would be displayed by OutputPrompt.
    STDMETHOD(GetPromptText)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
    STDMETHOD(OutputCurrentState)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
    STDMETHOD(OutputVersionInformation)(
        THIS_
        _In_ ULONG OutputControl
        ) PURE;

    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
    STDMETHOD(GetNotifyEventHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(SetNotifyEventHandle)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Assemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(Disassemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
    STDMETHOD(GetDisassembleEffectiveOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Uses the line prefix if necessary.
    STDMETHOD(OutputDisassembly)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
    STDMETHOD(OutputDisassemblyLines)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG PreviousLines,
        _In_ ULONG TotalLines,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_opt_ PULONG OffsetLine,
        _Out_opt_ PULONG64 StartOffset,
        _Out_opt_ PULONG64 EndOffset,
        _Out_writes_opt_(TotalLines) PULONG64 LineOffsets
        ) PURE;
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
    STDMETHOD(GetNearInstruction)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_ PULONG64 NearOffset
        ) PURE;

    // Offsets can be passed in as zero to use the current
    // thread state.
    STDMETHOD(GetStackTrace)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    // Does a simple stack trace to determine
    // what the current return address is.
    STDMETHOD(GetReturnOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
    STDMETHOD(OutputStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
    STDMETHOD(GetDebuggeeType)(
        THIS_
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
    STDMETHOD(GetActualProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Returns the type of processor used in the
    // current processor context.
    STDMETHOD(GetExecutingProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Query all the possible processor types that
    // may be encountered during this debug session.
    STDMETHOD(GetNumberPossibleExecutingProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPossibleExecutingProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Get the number of actual processors in
    // the machine.
    STDMETHOD(GetNumberProcessors)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
    STDMETHOD(GetSystemVersion)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Major,
        _Out_ PULONG Minor,
        _Out_writes_opt_(ServicePackStringSize) PSTR ServicePackString,
        _In_ ULONG ServicePackStringSize,
        _Out_opt_ PULONG ServicePackStringUsed,
        _Out_ PULONG ServicePackNumber,
        _Out_writes_opt_(BuildStringSize) PSTR BuildString,
        _In_ ULONG BuildStringSize,
        _Out_opt_ PULONG BuildStringUsed
        ) PURE;
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
    STDMETHOD(GetPageSize)(
        THIS_
        _Out_ PULONG Size
        ) PURE;
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
    STDMETHOD(IsPointer64Bit)(
        THIS
        ) PURE;
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
    STDMETHOD(ReadBugCheckData)(
        THIS_
        _Out_ PULONG Code,
        _Out_ PULONG64 Arg1,
        _Out_ PULONG64 Arg2,
        _Out_ PULONG64 Arg3,
        _Out_ PULONG64 Arg4
        ) PURE;

    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
    STDMETHOD(GetNumberSupportedProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSupportedProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
    STDMETHOD(GetProcessorTypeNames)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
    STDMETHOD(GetEffectiveProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(SetEffectiveProcessorType)(
        THIS_
        _In_ ULONG Type
        ) PURE;

    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
    STDMETHOD(GetExecutionStatus)(
        THIS_
        _Out_ PULONG Status
        ) PURE;
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
    STDMETHOD(SetExecutionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
    STDMETHOD(GetCodeLevel)(
        THIS_
        _Out_ PULONG Level
        ) PURE;
    STDMETHOD(SetCodeLevel)(
        THIS_
        _In_ ULONG Level
        ) PURE;

    // Gets and sets engine control flags.
    // These methods are reentrant.
    STDMETHOD(GetEngineOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
    STDMETHOD(GetSystemErrorControl)(
        THIS_
        _Out_ PULONG OutputLevel,
        _Out_ PULONG BreakLevel
        ) PURE;
    STDMETHOD(SetSystemErrorControl)(
        THIS_
        _In_ ULONG OutputLevel,
        _In_ ULONG BreakLevel
        ) PURE;

    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
    STDMETHOD(GetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCSTR Macro
        ) PURE;

    // Controls the default number radix used
    // in expressions and commands.
    STDMETHOD(GetRadix)(
        THIS_
        _Out_ PULONG Radix
        ) PURE;
    STDMETHOD(SetRadix)(
        THIS_
        _In_ ULONG Radix
        ) PURE;

    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
    STDMETHOD(Evaluate)(
        THIS_
        _In_ PCSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
    STDMETHOD(CoerceValue)(
        THIS_
        _In_ PDEBUG_VALUE In,
        _In_ ULONG OutType,
        _Out_ PDEBUG_VALUE Out
        ) PURE;
    STDMETHOD(CoerceValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_VALUE In,
        _In_reads_(Count) PULONG OutTypes,
        _Out_writes_(Count) PDEBUG_VALUE Out
        ) PURE;

    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
    STDMETHOD(Execute)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Command,
        _In_ ULONG Flags
        ) PURE;
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
    STDMETHOD(ExecuteCommandFile)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    // Breakpoint interfaces are described
    // elsewhere in this section.
    STDMETHOD(GetNumberBreakpoints)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
    STDMETHOD(GetBreakpointByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
    STDMETHOD(GetBreakpointParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Ids,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
    STDMETHOD(AddBreakpoint)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // Breakpoint interface is invalid after this call.
    STDMETHOD(RemoveBreakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Control and use extension DLLs.
    STDMETHOD(AddExtension)(
        THIS_
        _In_ PCSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(RemoveExtension)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPath)(
        THIS_
        _In_ PCSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
    STDMETHOD(CallExtension)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR Function,
        _In_opt_ PCSTR Arguments
        ) PURE;
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // This function cannot be called remotely.
    STDMETHOD(GetExtensionFunction)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
    STDMETHOD(GetWindbgExtensionApis32)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS32 Api
        ) PURE;
    STDMETHOD(GetWindbgExtensionApis64)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS64 Api
        ) PURE;

    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
    STDMETHOD(GetNumberEventFilters)(
        THIS_
        _Out_ PULONG SpecificEvents,
        _Out_ PULONG SpecificExceptions,
        _Out_ PULONG ArbitraryExceptions
        ) PURE;
    // Some filters have descriptive text associated with them.
    STDMETHOD(GetEventFilterText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // All filters support executing a command when the
    // event occurs.
    STDMETHOD(GetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    STDMETHOD(SetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    // Some specific filters have arguments to further
    // qualify their operation.
    STDMETHOD(GetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Argument
        ) PURE;
    // If Codes is non-NULL Start is ignored.
    STDMETHOD(GetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Codes,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
    STDMETHOD(SetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // Exception filters support an additional command for
    // second-chance events.
    STDMETHOD(GetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;

    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
    STDMETHOD(WaitForEvent)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Timeout
        ) PURE;

    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
    STDMETHOD(GetLastEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    // IDebugControl2.

    STDMETHOD(GetCurrentTimeDate)(
        THIS_
        _Out_ PULONG TimeDate
        ) PURE;
    // Retrieves the number of seconds since the
    // machine started running.
    STDMETHOD(GetCurrentSystemUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // If the current session is a dump session,
    // retrieves any extended format information.
    STDMETHOD(GetDumpFormatFlags)(
        THIS_
        _Out_ PULONG FormatFlags
        ) PURE;

    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
    STDMETHOD(GetNumberTextReplacements)(
        THIS_
        _Out_ PULONG NumRepl
        ) PURE;
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
    STDMETHOD(GetTextReplacement)(
        THIS_
        _In_opt_ PCSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    // Setting the destination text to
    // NULL removes the alias.
    STDMETHOD(SetTextReplacement)(
        THIS_
        _In_ PCSTR SrcText,
        _In_opt_ PCSTR DstText
        ) PURE;
    STDMETHOD(RemoveTextReplacements)(
        THIS
        ) PURE;
    // Outputs the complete list of current
    // replacements.
    STDMETHOD(OutputTextReplacements)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl3.

    // Control options for assembly and disassembly.
    STDMETHOD(GetAssemblyOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Control the expression syntax.
    STDMETHOD(GetExpressionSyntax)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(SetExpressionSyntax)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Look up a syntax by its abbreviated
    // name and set it.
    STDMETHOD(SetExpressionSyntaxByName)(
        THIS_
        _In_ PCSTR AbbrevName
        ) PURE;
    STDMETHOD(GetNumberExpressionSyntaxes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNames)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    //
    // Some debug sessions have only a single
    // possible event, such as a snapshot dump
    // file; some have dynamic events, such as
    // a live debug session; and others may have
    // multiple events, such as a dump file that
    // contains snapshots from different points
    // in time.  The following methods allow
    // discovery and selection of the available
    // events for a session.
    // Sessions with one or more static events
    // will be able to report all of the events
    // when queried.  Sessions with dynamic events
    // will only report a single event representing
    // the current event.
    // Switching events constitutes execution and
    // changing the current event will alter the
    // execution status to a running state, after
    // which WaitForEvent must be used to process
    // the selected event.
    //

    // GetNumberEvents returns S_OK if this is the
    // complete set of events possible, such as for
    // a static session; or S_FALSE if other events
    // may be possible, such as for a dynamic session.
    STDMETHOD(GetNumberEvents)(
        THIS_
        _Out_ PULONG Events
        ) PURE;
    // Sessions may have descriptive information for
    // the various events available.  The amount of
    // information varies according to the specific
    // session and data.
    STDMETHOD(GetEventIndexDescription)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;
    STDMETHOD(GetCurrentEventIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    // SetNextEventIndex works like seek in that
    // it can set an absolute or relative index.
    // SetNextEventIndex works similarly to SetExecutionStatus
    // by putting the session into a running state, after
    // which the caller must call WaitForEvent.  The
    // current event index only changes when WaitForEvent
    // is called.
    STDMETHOD(SetNextEventIndex)(
        THIS_
        _In_ ULONG Relation,
        _In_ ULONG Value,
        _Out_ PULONG NextIndex
        ) PURE;

    // IDebugControl4.

    STDMETHOD(GetLogFileWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    STDMETHOD(OpenLogFileWide)(
        THIS_
        _In_ PCWSTR File,
        _In_ BOOL Append
        ) PURE;

    STDMETHOD(InputWide)(
        THIS_
        _Out_writes_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    STDMETHOD(ReturnInputWide)(
        THIS_
        _In_ PCWSTR Buffer
        ) PURE;

    STDMETHODV(OutputWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaListWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHODV(ControlledOutputWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;

    STDMETHODV(OutputPromptWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHOD(GetPromptTextWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;

    STDMETHOD(AssembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCWSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(DisassembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;

    STDMETHOD(GetProcessorTypeNamesWide)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCWSTR Macro
        ) PURE;

    STDMETHOD(EvaluateWide)(
        THIS_
        _In_ PCWSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;

    STDMETHOD(ExecuteWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Command,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ExecuteCommandFileWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetBreakpointByIndex2)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById2)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(AddBreakpoint2)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(RemoveBreakpoint2)(
        THIS_
        _In_ PDEBUG_BREAKPOINT2 Bp
        ) PURE;

    STDMETHOD(AddExtensionWide)(
        THIS_
        _In_ PCWSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPathWide)(
        THIS_
        _In_ PCWSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(CallExtensionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR Function,
        _In_opt_ PCWSTR Arguments
        ) PURE;
    STDMETHOD(GetExtensionFunctionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;

    STDMETHOD(GetEventFilterTextWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    STDMETHOD(GetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Argument
        ) PURE;
    STDMETHOD(GetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;

    STDMETHOD(GetLastEventInformationWide)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    STDMETHOD(GetTextReplacementWide)(
        THIS_
        _In_opt_ PCWSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PWSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PWSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    STDMETHOD(SetTextReplacementWide)(
        THIS_
        _In_ PCWSTR SrcText,
        _In_opt_ PCWSTR DstText
        ) PURE;

    STDMETHOD(SetExpressionSyntaxByNameWide)(
        THIS_
        _In_ PCWSTR AbbrevName
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNamesWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetEventIndexDescriptionWide)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;

    STDMETHOD(GetLogFile2)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2)(
        THIS_
        _In_ PCSTR File,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(GetLogFile2Wide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2Wide)(
        THIS_
        _In_ PCWSTR File,
        _In_ ULONG Flags
        ) PURE;

    // GetSystemVersion always returns the kd
    // major/minor version numbers, which are
    // different than the Win32 version numbers.
    // GetSystemVersionValues can be used
    // to determine the Win32 version values.
    STDMETHOD(GetSystemVersionValues)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Win32Major,
        _Out_ PULONG Win32Minor,
        _Out_opt_ PULONG KdMajor,
        _Out_opt_ PULONG KdMinor
        ) PURE;
    // Strings are selected with DEBUG_SYSVERSTR_*.
    STDMETHOD(GetSystemVersionString)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSystemVersionStringWide)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    // Stack tracing with a full initial context
    // and full context return for each frame.
    // The FrameContextsSize parameter is the total
    // byte size of FrameContexts.  FrameContextsEntrySize
    // gives the byte size of each entry in
    // FrameContexts.
    STDMETHOD(GetContextStackTrace)(
        THIS_
        _In_reads_bytes_opt_(StartContextSize) PVOID StartContext,
        _In_ ULONG StartContextSize,
        _Out_writes_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_writes_bytes_opt_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    STDMETHOD(OutputContextStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_reads_bytes_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _In_ ULONG Flags
        ) PURE;

    // Some targets, such as user-mode minidump files,
    // have separate "event of interest" information
    // stored within them.  This method allows
    // access to that information.
    STDMETHOD(GetStoredEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize,
        _Out_opt_ PULONG ContextUsed,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed
        ) PURE;

    // Managed debugging support relies on debugging
    // functionality provided by the Common Language Runtime.
    // This method provides feedback on the engine's
    // use of the runtime debugging APIs.
    STDMETHOD(GetManagedStatus)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    STDMETHOD(GetManagedStatusWide)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PWSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    // Clears and reinitializes the engine's
    // managed code debugging support.
    STDMETHOD(ResetManagedStatus)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugControl5
DECLARE_INTERFACE_(IDebugControl5, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
    STDMETHOD(GetInterrupt)(
        THIS
        ) PURE;
    // Registers a user interrupt.
    // This method is reentrant.
    STDMETHOD(SetInterrupt)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
    STDMETHOD(GetInterruptTimeout)(
        THIS_
        _Out_ PULONG Seconds
        ) PURE;
    STDMETHOD(SetInterruptTimeout)(
        THIS_
        _In_ ULONG Seconds
        ) PURE;

    STDMETHOD(GetLogFile)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
    STDMETHOD(OpenLogFile)(
        THIS_
        _In_ PCSTR File,
        _In_ BOOL Append
        ) PURE;
    STDMETHOD(CloseLogFile)(
        THIS
        ) PURE;
    // Controls what output is logged.
    STDMETHOD(GetLogMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetLogMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;

    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
    STDMETHOD(Input)(
        THIS_
        _Out_writes_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
    STDMETHOD(ReturnInput)(
        THIS_
        _In_ PCSTR Buffer
        ) PURE;

    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
    STDMETHODV(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaList)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
    STDMETHODV(ControlledOutput)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;

    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
    STDMETHODV(OutputPrompt)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // Gets the text that would be displayed by OutputPrompt.
    STDMETHOD(GetPromptText)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
    STDMETHOD(OutputCurrentState)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
    STDMETHOD(OutputVersionInformation)(
        THIS_
        _In_ ULONG OutputControl
        ) PURE;

    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
    STDMETHOD(GetNotifyEventHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(SetNotifyEventHandle)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Assemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(Disassemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
    STDMETHOD(GetDisassembleEffectiveOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Uses the line prefix if necessary.
    STDMETHOD(OutputDisassembly)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
    STDMETHOD(OutputDisassemblyLines)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG PreviousLines,
        _In_ ULONG TotalLines,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_opt_ PULONG OffsetLine,
        _Out_opt_ PULONG64 StartOffset,
        _Out_opt_ PULONG64 EndOffset,
        _Out_writes_opt_(TotalLines) PULONG64 LineOffsets
        ) PURE;
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
    STDMETHOD(GetNearInstruction)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_ PULONG64 NearOffset
        ) PURE;

    // Offsets can be passed in as zero to use the current
    // thread state.
    STDMETHOD(GetStackTrace)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_to_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    // Does a simple stack trace to determine
    // what the current return address is.
    STDMETHOD(GetReturnOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
    STDMETHOD(OutputStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
    STDMETHOD(GetDebuggeeType)(
        THIS_
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
    STDMETHOD(GetActualProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Returns the type of processor used in the
    // current processor context.
    STDMETHOD(GetExecutingProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Query all the possible processor types that
    // may be encountered during this debug session.
    STDMETHOD(GetNumberPossibleExecutingProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPossibleExecutingProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Get the number of actual processors in
    // the machine.
    STDMETHOD(GetNumberProcessors)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
    STDMETHOD(GetSystemVersion)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Major,
        _Out_ PULONG Minor,
        _Out_writes_opt_(ServicePackStringSize) PSTR ServicePackString,
        _In_ ULONG ServicePackStringSize,
        _Out_opt_ PULONG ServicePackStringUsed,
        _Out_ PULONG ServicePackNumber,
        _Out_writes_opt_(BuildStringSize) PSTR BuildString,
        _In_ ULONG BuildStringSize,
        _Out_opt_ PULONG BuildStringUsed
        ) PURE;
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
    STDMETHOD(GetPageSize)(
        THIS_
        _Out_ PULONG Size
        ) PURE;
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
    STDMETHOD(IsPointer64Bit)(
        THIS
        ) PURE;
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
    STDMETHOD(ReadBugCheckData)(
        THIS_
        _Out_ PULONG Code,
        _Out_ PULONG64 Arg1,
        _Out_ PULONG64 Arg2,
        _Out_ PULONG64 Arg3,
        _Out_ PULONG64 Arg4
        ) PURE;

    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
    STDMETHOD(GetNumberSupportedProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSupportedProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
    STDMETHOD(GetProcessorTypeNames)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
    STDMETHOD(GetEffectiveProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(SetEffectiveProcessorType)(
        THIS_
        _In_ ULONG Type
        ) PURE;

    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
    STDMETHOD(GetExecutionStatus)(
        THIS_
        _Out_ PULONG Status
        ) PURE;
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
    STDMETHOD(SetExecutionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
    STDMETHOD(GetCodeLevel)(
        THIS_
        _Out_ PULONG Level
        ) PURE;
    STDMETHOD(SetCodeLevel)(
        THIS_
        _In_ ULONG Level
        ) PURE;

    // Gets and sets engine control flags.
    // These methods are reentrant.
    STDMETHOD(GetEngineOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
    STDMETHOD(GetSystemErrorControl)(
        THIS_
        _Out_ PULONG OutputLevel,
        _Out_ PULONG BreakLevel
        ) PURE;
    STDMETHOD(SetSystemErrorControl)(
        THIS_
        _In_ ULONG OutputLevel,
        _In_ ULONG BreakLevel
        ) PURE;

    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
    STDMETHOD(GetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCSTR Macro
        ) PURE;

    // Controls the default number radix used
    // in expressions and commands.
    STDMETHOD(GetRadix)(
        THIS_
        _Out_ PULONG Radix
        ) PURE;
    STDMETHOD(SetRadix)(
        THIS_
        _In_ ULONG Radix
        ) PURE;

    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
    STDMETHOD(Evaluate)(
        THIS_
        _In_ PCSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
    STDMETHOD(CoerceValue)(
        THIS_
        _In_ PDEBUG_VALUE In,
        _In_ ULONG OutType,
        _Out_ PDEBUG_VALUE Out
        ) PURE;
    STDMETHOD(CoerceValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_VALUE In,
        _In_reads_(Count) PULONG OutTypes,
        _Out_writes_(Count) PDEBUG_VALUE Out
        ) PURE;

    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
    STDMETHOD(Execute)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Command,
        _In_ ULONG Flags
        ) PURE;
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
    STDMETHOD(ExecuteCommandFile)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    // Breakpoint interfaces are described
    // elsewhere in this section.
    STDMETHOD(GetNumberBreakpoints)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
    STDMETHOD(GetBreakpointByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
    STDMETHOD(GetBreakpointParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Ids,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
    STDMETHOD(AddBreakpoint)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // Breakpoint interface is invalid after this call.
    STDMETHOD(RemoveBreakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Control and use extension DLLs.
    STDMETHOD(AddExtension)(
        THIS_
        _In_ PCSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(RemoveExtension)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPath)(
        THIS_
        _In_ PCSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
    STDMETHOD(CallExtension)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR Function,
        _In_opt_ PCSTR Arguments
        ) PURE;
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // This function cannot be called remotely.
    STDMETHOD(GetExtensionFunction)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
    STDMETHOD(GetWindbgExtensionApis32)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS32 Api
        ) PURE;
    STDMETHOD(GetWindbgExtensionApis64)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS64 Api
        ) PURE;

    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
    STDMETHOD(GetNumberEventFilters)(
        THIS_
        _Out_ PULONG SpecificEvents,
        _Out_ PULONG SpecificExceptions,
        _Out_ PULONG ArbitraryExceptions
        ) PURE;
    // Some filters have descriptive text associated with them.
    STDMETHOD(GetEventFilterText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // All filters support executing a command when the
    // event occurs.
    STDMETHOD(GetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    STDMETHOD(SetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    // Some specific filters have arguments to further
    // qualify their operation.
    STDMETHOD(GetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Argument
        ) PURE;
    // If Codes is non-NULL Start is ignored.
    STDMETHOD(GetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Codes,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
    STDMETHOD(SetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // Exception filters support an additional command for
    // second-chance events.
    STDMETHOD(GetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;

    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
    STDMETHOD(WaitForEvent)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Timeout
        ) PURE;

    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
    STDMETHOD(GetLastEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    // IDebugControl2.

    STDMETHOD(GetCurrentTimeDate)(
        THIS_
        _Out_ PULONG TimeDate
        ) PURE;
    // Retrieves the number of seconds since the
    // machine started running.
    STDMETHOD(GetCurrentSystemUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // If the current session is a dump session,
    // retrieves any extended format information.
    STDMETHOD(GetDumpFormatFlags)(
        THIS_
        _Out_ PULONG FormatFlags
        ) PURE;

    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
    STDMETHOD(GetNumberTextReplacements)(
        THIS_
        _Out_ PULONG NumRepl
        ) PURE;
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
    STDMETHOD(GetTextReplacement)(
        THIS_
        _In_opt_ PCSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    // Setting the destination text to
    // NULL removes the alias.
    STDMETHOD(SetTextReplacement)(
        THIS_
        _In_ PCSTR SrcText,
        _In_opt_ PCSTR DstText
        ) PURE;
    STDMETHOD(RemoveTextReplacements)(
        THIS
        ) PURE;
    // Outputs the complete list of current
    // replacements.
    STDMETHOD(OutputTextReplacements)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl3.

    // Control options for assembly and disassembly.
    STDMETHOD(GetAssemblyOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Control the expression syntax.
    STDMETHOD(GetExpressionSyntax)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(SetExpressionSyntax)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Look up a syntax by its abbreviated
    // name and set it.
    STDMETHOD(SetExpressionSyntaxByName)(
        THIS_
        _In_ PCSTR AbbrevName
        ) PURE;
    STDMETHOD(GetNumberExpressionSyntaxes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNames)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    //
    // Some debug sessions have only a single
    // possible event, such as a snapshot dump
    // file; some have dynamic events, such as
    // a live debug session; and others may have
    // multiple events, such as a dump file that
    // contains snapshots from different points
    // in time.  The following methods allow
    // discovery and selection of the available
    // events for a session.
    // Sessions with one or more static events
    // will be able to report all of the events
    // when queried.  Sessions with dynamic events
    // will only report a single event representing
    // the current event.
    // Switching events constitutes execution and
    // changing the current event will alter the
    // execution status to a running state, after
    // which WaitForEvent must be used to process
    // the selected event.
    //

    // GetNumberEvents returns S_OK if this is the
    // complete set of events possible, such as for
    // a static session; or S_FALSE if other events
    // may be possible, such as for a dynamic session.
    STDMETHOD(GetNumberEvents)(
        THIS_
        _Out_ PULONG Events
        ) PURE;
    // Sessions may have descriptive information for
    // the various events available.  The amount of
    // information varies according to the specific
    // session and data.
    STDMETHOD(GetEventIndexDescription)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;
    STDMETHOD(GetCurrentEventIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    // SetNextEventIndex works like seek in that
    // it can set an absolute or relative index.
    // SetNextEventIndex works similarly to SetExecutionStatus
    // by putting the session into a running state, after
    // which the caller must call WaitForEvent.  The
    // current event index only changes when WaitForEvent
    // is called.
    STDMETHOD(SetNextEventIndex)(
        THIS_
        _In_ ULONG Relation,
        _In_ ULONG Value,
        _Out_ PULONG NextIndex
        ) PURE;

    // IDebugControl4.

    STDMETHOD(GetLogFileWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    STDMETHOD(OpenLogFileWide)(
        THIS_
        _In_ PCWSTR File,
        _In_ BOOL Append
        ) PURE;

    STDMETHOD(InputWide)(
        THIS_
        _Out_writes_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    STDMETHOD(ReturnInputWide)(
        THIS_
        _In_ PCWSTR Buffer
        ) PURE;

    STDMETHODV(OutputWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaListWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHODV(ControlledOutputWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;

    STDMETHODV(OutputPromptWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHOD(GetPromptTextWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;

    STDMETHOD(AssembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCWSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(DisassembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;

    STDMETHOD(GetProcessorTypeNamesWide)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCWSTR Macro
        ) PURE;

    STDMETHOD(EvaluateWide)(
        THIS_
        _In_ PCWSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;

    STDMETHOD(ExecuteWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Command,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ExecuteCommandFileWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetBreakpointByIndex2)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById2)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(AddBreakpoint2)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(RemoveBreakpoint2)(
        THIS_
        _In_ PDEBUG_BREAKPOINT2 Bp
        ) PURE;

    STDMETHOD(AddExtensionWide)(
        THIS_
        _In_ PCWSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPathWide)(
        THIS_
        _In_ PCWSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(CallExtensionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR Function,
        _In_opt_ PCWSTR Arguments
        ) PURE;
    STDMETHOD(GetExtensionFunctionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;

    STDMETHOD(GetEventFilterTextWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    STDMETHOD(GetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Argument
        ) PURE;
    STDMETHOD(GetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;

    STDMETHOD(GetLastEventInformationWide)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    STDMETHOD(GetTextReplacementWide)(
        THIS_
        _In_opt_ PCWSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PWSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PWSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    STDMETHOD(SetTextReplacementWide)(
        THIS_
        _In_ PCWSTR SrcText,
        _In_opt_ PCWSTR DstText
        ) PURE;

    STDMETHOD(SetExpressionSyntaxByNameWide)(
        THIS_
        _In_ PCWSTR AbbrevName
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNamesWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetEventIndexDescriptionWide)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;

    STDMETHOD(GetLogFile2)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2)(
        THIS_
        _In_ PCSTR File,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(GetLogFile2Wide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2Wide)(
        THIS_
        _In_ PCWSTR File,
        _In_ ULONG Flags
        ) PURE;

    // GetSystemVersion always returns the kd
    // major/minor version numbers, which are
    // different than the Win32 version numbers.
    // GetSystemVersionValues can be used
    // to determine the Win32 version values.
    STDMETHOD(GetSystemVersionValues)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Win32Major,
        _Out_ PULONG Win32Minor,
        _Out_opt_ PULONG KdMajor,
        _Out_opt_ PULONG KdMinor
        ) PURE;
    // Strings are selected with DEBUG_SYSVERSTR_*.
    STDMETHOD(GetSystemVersionString)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSystemVersionStringWide)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    // Stack tracing with a full initial context
    // and full context return for each frame.
    // The FrameContextsSize parameter is the total
    // byte size of FrameContexts.  FrameContextsEntrySize
    // gives the byte size of each entry in
    // FrameContexts.
    STDMETHOD(GetContextStackTrace)(
        THIS_
        _In_reads_bytes_opt_(StartContextSize) PVOID StartContext,
        _In_ ULONG StartContextSize,
        _Out_writes_to_opt_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_writes_bytes_opt_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    STDMETHOD(OutputContextStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_reads_bytes_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _In_ ULONG Flags
        ) PURE;

    // Some targets, such as user-mode minidump files,
    // have separate "event of interest" information
    // stored within them.  This method allows
    // access to that information.
    STDMETHOD(GetStoredEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize,
        _Out_opt_ PULONG ContextUsed,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed
        ) PURE;

    // Managed debugging support relies on debugging
    // functionality provided by the Common Language Runtime.
    // This method provides feedback on the engine's
    // use of the runtime debugging APIs.
    STDMETHOD(GetManagedStatus)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    STDMETHOD(GetManagedStatusWide)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PWSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    // Clears and reinitializes the engine's
    // managed code debugging support.
    STDMETHOD(ResetManagedStatus)(
        THIS_
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl5
    STDMETHOD(GetStackTraceEx)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_to_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;

    STDMETHOD(OutputStackTraceEx)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetContextStackTraceEx)(
        THIS_
        _In_reads_bytes_opt_(StartContextSize) PVOID StartContext,
        _In_ ULONG StartContextSize,
        _Out_writes_to_opt_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _Out_writes_bytes_opt_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;

    STDMETHOD(OutputContextStackTraceEx)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_(FramesSize) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _In_reads_bytes_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetBreakpointByGuid)(
        THIS_
        _In_ LPGUID Guid,
        _Out_ PDEBUG_BREAKPOINT3* Bp
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugControl6
DECLARE_INTERFACE_(IDebugControl6, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
    STDMETHOD(GetInterrupt)(
        THIS
        ) PURE;
    // Registers a user interrupt.
    // This method is reentrant.
    STDMETHOD(SetInterrupt)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
    STDMETHOD(GetInterruptTimeout)(
        THIS_
        _Out_ PULONG Seconds
        ) PURE;
    STDMETHOD(SetInterruptTimeout)(
        THIS_
        _In_ ULONG Seconds
        ) PURE;

    STDMETHOD(GetLogFile)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
    STDMETHOD(OpenLogFile)(
        THIS_
        _In_ PCSTR File,
        _In_ BOOL Append
        ) PURE;
    STDMETHOD(CloseLogFile)(
        THIS
        ) PURE;
    // Controls what output is logged.
    STDMETHOD(GetLogMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetLogMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;

    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
    STDMETHOD(Input)(
        THIS_
        _Out_writes_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
    STDMETHOD(ReturnInput)(
        THIS_
        _In_ PCSTR Buffer
        ) PURE;

    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
    STDMETHODV(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaList)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
    STDMETHODV(ControlledOutput)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;

    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
    STDMETHODV(OutputPrompt)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // Gets the text that would be displayed by OutputPrompt.
    STDMETHOD(GetPromptText)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
    STDMETHOD(OutputCurrentState)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
    STDMETHOD(OutputVersionInformation)(
        THIS_
        _In_ ULONG OutputControl
        ) PURE;

    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
    STDMETHOD(GetNotifyEventHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(SetNotifyEventHandle)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Assemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(Disassemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
    STDMETHOD(GetDisassembleEffectiveOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Uses the line prefix if necessary.
    STDMETHOD(OutputDisassembly)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
    STDMETHOD(OutputDisassemblyLines)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG PreviousLines,
        _In_ ULONG TotalLines,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_opt_ PULONG OffsetLine,
        _Out_opt_ PULONG64 StartOffset,
        _Out_opt_ PULONG64 EndOffset,
        _Out_writes_opt_(TotalLines) PULONG64 LineOffsets
        ) PURE;
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
    STDMETHOD(GetNearInstruction)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_ PULONG64 NearOffset
        ) PURE;

    // Offsets can be passed in as zero to use the current
    // thread state.
    STDMETHOD(GetStackTrace)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_to_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    // Does a simple stack trace to determine
    // what the current return address is.
    STDMETHOD(GetReturnOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
    STDMETHOD(OutputStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
    STDMETHOD(GetDebuggeeType)(
        THIS_
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
    STDMETHOD(GetActualProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Returns the type of processor used in the
    // current processor context.
    STDMETHOD(GetExecutingProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Query all the possible processor types that
    // may be encountered during this debug session.
    STDMETHOD(GetNumberPossibleExecutingProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPossibleExecutingProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Get the number of actual processors in
    // the machine.
    STDMETHOD(GetNumberProcessors)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
    STDMETHOD(GetSystemVersion)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Major,
        _Out_ PULONG Minor,
        _Out_writes_opt_(ServicePackStringSize) PSTR ServicePackString,
        _In_ ULONG ServicePackStringSize,
        _Out_opt_ PULONG ServicePackStringUsed,
        _Out_ PULONG ServicePackNumber,
        _Out_writes_opt_(BuildStringSize) PSTR BuildString,
        _In_ ULONG BuildStringSize,
        _Out_opt_ PULONG BuildStringUsed
        ) PURE;
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
    STDMETHOD(GetPageSize)(
        THIS_
        _Out_ PULONG Size
        ) PURE;
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
    STDMETHOD(IsPointer64Bit)(
        THIS
        ) PURE;
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
    STDMETHOD(ReadBugCheckData)(
        THIS_
        _Out_ PULONG Code,
        _Out_ PULONG64 Arg1,
        _Out_ PULONG64 Arg2,
        _Out_ PULONG64 Arg3,
        _Out_ PULONG64 Arg4
        ) PURE;

    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
    STDMETHOD(GetNumberSupportedProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSupportedProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
    STDMETHOD(GetProcessorTypeNames)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
    STDMETHOD(GetEffectiveProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(SetEffectiveProcessorType)(
        THIS_
        _In_ ULONG Type
        ) PURE;

    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
    STDMETHOD(GetExecutionStatus)(
        THIS_
        _Out_ PULONG Status
        ) PURE;
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
    STDMETHOD(SetExecutionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
    STDMETHOD(GetCodeLevel)(
        THIS_
        _Out_ PULONG Level
        ) PURE;
    STDMETHOD(SetCodeLevel)(
        THIS_
        _In_ ULONG Level
        ) PURE;

    // Gets and sets engine control flags.
    // These methods are reentrant.
    STDMETHOD(GetEngineOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
    STDMETHOD(GetSystemErrorControl)(
        THIS_
        _Out_ PULONG OutputLevel,
        _Out_ PULONG BreakLevel
        ) PURE;
    STDMETHOD(SetSystemErrorControl)(
        THIS_
        _In_ ULONG OutputLevel,
        _In_ ULONG BreakLevel
        ) PURE;

    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
    STDMETHOD(GetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCSTR Macro
        ) PURE;

    // Controls the default number radix used
    // in expressions and commands.
    STDMETHOD(GetRadix)(
        THIS_
        _Out_ PULONG Radix
        ) PURE;
    STDMETHOD(SetRadix)(
        THIS_
        _In_ ULONG Radix
        ) PURE;

    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
    STDMETHOD(Evaluate)(
        THIS_
        _In_ PCSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
    STDMETHOD(CoerceValue)(
        THIS_
        _In_ PDEBUG_VALUE In,
        _In_ ULONG OutType,
        _Out_ PDEBUG_VALUE Out
        ) PURE;
    STDMETHOD(CoerceValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_VALUE In,
        _In_reads_(Count) PULONG OutTypes,
        _Out_writes_(Count) PDEBUG_VALUE Out
        ) PURE;

    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
    STDMETHOD(Execute)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Command,
        _In_ ULONG Flags
        ) PURE;
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
    STDMETHOD(ExecuteCommandFile)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    // Breakpoint interfaces are described
    // elsewhere in this section.
    STDMETHOD(GetNumberBreakpoints)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
    STDMETHOD(GetBreakpointByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
    STDMETHOD(GetBreakpointParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Ids,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
    STDMETHOD(AddBreakpoint)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // Breakpoint interface is invalid after this call.
    STDMETHOD(RemoveBreakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Control and use extension DLLs.
    STDMETHOD(AddExtension)(
        THIS_
        _In_ PCSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(RemoveExtension)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPath)(
        THIS_
        _In_ PCSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
    STDMETHOD(CallExtension)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR Function,
        _In_opt_ PCSTR Arguments
        ) PURE;
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // This function cannot be called remotely.
    STDMETHOD(GetExtensionFunction)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
    STDMETHOD(GetWindbgExtensionApis32)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS32 Api
        ) PURE;
    STDMETHOD(GetWindbgExtensionApis64)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS64 Api
        ) PURE;

    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
    STDMETHOD(GetNumberEventFilters)(
        THIS_
        _Out_ PULONG SpecificEvents,
        _Out_ PULONG SpecificExceptions,
        _Out_ PULONG ArbitraryExceptions
        ) PURE;
    // Some filters have descriptive text associated with them.
    STDMETHOD(GetEventFilterText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // All filters support executing a command when the
    // event occurs.
    STDMETHOD(GetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    STDMETHOD(SetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    // Some specific filters have arguments to further
    // qualify their operation.
    STDMETHOD(GetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Argument
        ) PURE;
    // If Codes is non-NULL Start is ignored.
    STDMETHOD(GetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Codes,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
    STDMETHOD(SetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // Exception filters support an additional command for
    // second-chance events.
    STDMETHOD(GetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;

    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
    STDMETHOD(WaitForEvent)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Timeout
        ) PURE;

    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
    STDMETHOD(GetLastEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    // IDebugControl2.

    STDMETHOD(GetCurrentTimeDate)(
        THIS_
        _Out_ PULONG TimeDate
        ) PURE;
    // Retrieves the number of seconds since the
    // machine started running.
    STDMETHOD(GetCurrentSystemUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // If the current session is a dump session,
    // retrieves any extended format information.
    STDMETHOD(GetDumpFormatFlags)(
        THIS_
        _Out_ PULONG FormatFlags
        ) PURE;

    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
    STDMETHOD(GetNumberTextReplacements)(
        THIS_
        _Out_ PULONG NumRepl
        ) PURE;
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
    STDMETHOD(GetTextReplacement)(
        THIS_
        _In_opt_ PCSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    // Setting the destination text to
    // NULL removes the alias.
    STDMETHOD(SetTextReplacement)(
        THIS_
        _In_ PCSTR SrcText,
        _In_opt_ PCSTR DstText
        ) PURE;
    STDMETHOD(RemoveTextReplacements)(
        THIS
        ) PURE;
    // Outputs the complete list of current
    // replacements.
    STDMETHOD(OutputTextReplacements)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl3.

    // Control options for assembly and disassembly.
    STDMETHOD(GetAssemblyOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Control the expression syntax.
    STDMETHOD(GetExpressionSyntax)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(SetExpressionSyntax)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Look up a syntax by its abbreviated
    // name and set it.
    STDMETHOD(SetExpressionSyntaxByName)(
        THIS_
        _In_ PCSTR AbbrevName
        ) PURE;
    STDMETHOD(GetNumberExpressionSyntaxes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNames)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    //
    // Some debug sessions have only a single
    // possible event, such as a snapshot dump
    // file; some have dynamic events, such as
    // a live debug session; and others may have
    // multiple events, such as a dump file that
    // contains snapshots from different points
    // in time.  The following methods allow
    // discovery and selection of the available
    // events for a session.
    // Sessions with one or more static events
    // will be able to report all of the events
    // when queried.  Sessions with dynamic events
    // will only report a single event representing
    // the current event.
    // Switching events constitutes execution and
    // changing the current event will alter the
    // execution status to a running state, after
    // which WaitForEvent must be used to process
    // the selected event.
    //

    // GetNumberEvents returns S_OK if this is the
    // complete set of events possible, such as for
    // a static session; or S_FALSE if other events
    // may be possible, such as for a dynamic session.
    STDMETHOD(GetNumberEvents)(
        THIS_
        _Out_ PULONG Events
        ) PURE;
    // Sessions may have descriptive information for
    // the various events available.  The amount of
    // information varies according to the specific
    // session and data.
    STDMETHOD(GetEventIndexDescription)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;
    STDMETHOD(GetCurrentEventIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    // SetNextEventIndex works like seek in that
    // it can set an absolute or relative index.
    // SetNextEventIndex works similarly to SetExecutionStatus
    // by putting the session into a running state, after
    // which the caller must call WaitForEvent.  The
    // current event index only changes when WaitForEvent
    // is called.
    STDMETHOD(SetNextEventIndex)(
        THIS_
        _In_ ULONG Relation,
        _In_ ULONG Value,
        _Out_ PULONG NextIndex
        ) PURE;

    // IDebugControl4.

    STDMETHOD(GetLogFileWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    STDMETHOD(OpenLogFileWide)(
        THIS_
        _In_ PCWSTR File,
        _In_ BOOL Append
        ) PURE;

    STDMETHOD(InputWide)(
        THIS_
        _Out_writes_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    STDMETHOD(ReturnInputWide)(
        THIS_
        _In_ PCWSTR Buffer
        ) PURE;

    STDMETHODV(OutputWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaListWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHODV(ControlledOutputWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;

    STDMETHODV(OutputPromptWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHOD(GetPromptTextWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;

    STDMETHOD(AssembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCWSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(DisassembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;

    STDMETHOD(GetProcessorTypeNamesWide)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCWSTR Macro
        ) PURE;

    STDMETHOD(EvaluateWide)(
        THIS_
        _In_ PCWSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;

    STDMETHOD(ExecuteWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Command,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ExecuteCommandFileWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetBreakpointByIndex2)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById2)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(AddBreakpoint2)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(RemoveBreakpoint2)(
        THIS_
        _In_ PDEBUG_BREAKPOINT2 Bp
        ) PURE;

    STDMETHOD(AddExtensionWide)(
        THIS_
        _In_ PCWSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPathWide)(
        THIS_
        _In_ PCWSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(CallExtensionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR Function,
        _In_opt_ PCWSTR Arguments
        ) PURE;
    STDMETHOD(GetExtensionFunctionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;

    STDMETHOD(GetEventFilterTextWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    STDMETHOD(GetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Argument
        ) PURE;
    STDMETHOD(GetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;

    STDMETHOD(GetLastEventInformationWide)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    STDMETHOD(GetTextReplacementWide)(
        THIS_
        _In_opt_ PCWSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PWSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PWSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    STDMETHOD(SetTextReplacementWide)(
        THIS_
        _In_ PCWSTR SrcText,
        _In_opt_ PCWSTR DstText
        ) PURE;

    STDMETHOD(SetExpressionSyntaxByNameWide)(
        THIS_
        _In_ PCWSTR AbbrevName
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNamesWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetEventIndexDescriptionWide)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;

    STDMETHOD(GetLogFile2)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2)(
        THIS_
        _In_ PCSTR File,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(GetLogFile2Wide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2Wide)(
        THIS_
        _In_ PCWSTR File,
        _In_ ULONG Flags
        ) PURE;

    // GetSystemVersion always returns the kd
    // major/minor version numbers, which are
    // different than the Win32 version numbers.
    // GetSystemVersionValues can be used
    // to determine the Win32 version values.
    STDMETHOD(GetSystemVersionValues)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Win32Major,
        _Out_ PULONG Win32Minor,
        _Out_opt_ PULONG KdMajor,
        _Out_opt_ PULONG KdMinor
        ) PURE;
    // Strings are selected with DEBUG_SYSVERSTR_*.
    STDMETHOD(GetSystemVersionString)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSystemVersionStringWide)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    // Stack tracing with a full initial context
    // and full context return for each frame.
    // The FrameContextsSize parameter is the total
    // byte size of FrameContexts.  FrameContextsEntrySize
    // gives the byte size of each entry in
    // FrameContexts.
    STDMETHOD(GetContextStackTrace)(
        THIS_
        _In_reads_bytes_opt_(StartContextSize) PVOID StartContext,
        _In_ ULONG StartContextSize,
        _Out_writes_to_opt_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_writes_bytes_opt_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    STDMETHOD(OutputContextStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_reads_bytes_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _In_ ULONG Flags
        ) PURE;

    // Some targets, such as user-mode minidump files,
    // have separate "event of interest" information
    // stored within them.  This method allows
    // access to that information.
    STDMETHOD(GetStoredEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize,
        _Out_opt_ PULONG ContextUsed,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed
        ) PURE;

    // Managed debugging support relies on debugging
    // functionality provided by the Common Language Runtime.
    // This method provides feedback on the engine's
    // use of the runtime debugging APIs.
    STDMETHOD(GetManagedStatus)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    STDMETHOD(GetManagedStatusWide)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PWSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    // Clears and reinitializes the engine's
    // managed code debugging support.
    STDMETHOD(ResetManagedStatus)(
        THIS_
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl5
    STDMETHOD(GetStackTraceEx)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_to_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;

    STDMETHOD(OutputStackTraceEx)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetContextStackTraceEx)(
        THIS_
        _In_reads_bytes_opt_(StartContextSize) PVOID StartContext,
        _In_ ULONG StartContextSize,
        _Out_writes_to_opt_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _Out_writes_bytes_opt_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;

    STDMETHOD(OutputContextStackTraceEx)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_(FramesSize) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _In_reads_bytes_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetBreakpointByGuid)(
        THIS_
        _In_ LPGUID Guid,
        _Out_ PDEBUG_BREAKPOINT3* Bp
        ) PURE;

    // IDebugControl6

    // Returns additional info states for
    STDMETHOD(GetExecutionStatusEx)(
        THIS_
        _Out_ PULONG Status
        ) PURE;

    STDMETHOD(GetSynchronizationStatus)(
        THIS_
        _Out_ PULONG SendsAttempted,
        _Out_ PULONG SecondsSinceLastResponse
        ) PURE;

};

#define DEBUG_EXEC_FLAGS_NONBLOCK 0x00000001

#undef INTERFACE
#define INTERFACE IDebugControl7
DECLARE_INTERFACE_(IDebugControl7, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
    STDMETHOD(GetInterrupt)(
        THIS
        ) PURE;
    // Registers a user interrupt.
    // This method is reentrant.
    STDMETHOD(SetInterrupt)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
    STDMETHOD(GetInterruptTimeout)(
        THIS_
        _Out_ PULONG Seconds
        ) PURE;
    STDMETHOD(SetInterruptTimeout)(
        THIS_
        _In_ ULONG Seconds
        ) PURE;

    STDMETHOD(GetLogFile)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
    STDMETHOD(OpenLogFile)(
        THIS_
        _In_ PCSTR File,
        _In_ BOOL Append
        ) PURE;
    STDMETHOD(CloseLogFile)(
        THIS
        ) PURE;
    // Controls what output is logged.
    STDMETHOD(GetLogMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;
    STDMETHOD(SetLogMask)(
        THIS_
        _In_ ULONG Mask
        ) PURE;

    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
    STDMETHOD(Input)(
        THIS_
        _Out_writes_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
    STDMETHOD(ReturnInput)(
        THIS_
        _In_ PCSTR Buffer
        ) PURE;

    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
    STDMETHODV(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaList)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
    STDMETHODV(ControlledOutput)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCSTR Format,
        _In_ va_list Args
        ) PURE;

    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
    STDMETHODV(OutputPrompt)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaList)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCSTR Format,
        _In_ va_list Args
        ) PURE;
    // Gets the text that would be displayed by OutputPrompt.
    STDMETHOD(GetPromptText)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
    STDMETHOD(OutputCurrentState)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
    STDMETHOD(OutputVersionInformation)(
        THIS_
        _In_ ULONG OutputControl
        ) PURE;

    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
    STDMETHOD(GetNotifyEventHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(SetNotifyEventHandle)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Assemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(Disassemble)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
    STDMETHOD(GetDisassembleEffectiveOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Uses the line prefix if necessary.
    STDMETHOD(OutputDisassembly)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_ PULONG64 EndOffset
        ) PURE;
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
    STDMETHOD(OutputDisassemblyLines)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG PreviousLines,
        _In_ ULONG TotalLines,
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_opt_ PULONG OffsetLine,
        _Out_opt_ PULONG64 StartOffset,
        _Out_opt_ PULONG64 EndOffset,
        _Out_writes_opt_(TotalLines) PULONG64 LineOffsets
        ) PURE;
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
    STDMETHOD(GetNearInstruction)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_ PULONG64 NearOffset
        ) PURE;

    // Offsets can be passed in as zero to use the current
    // thread state.
    STDMETHOD(GetStackTrace)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_to_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    // Does a simple stack trace to determine
    // what the current return address is.
    STDMETHOD(GetReturnOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
    STDMETHOD(OutputStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
    STDMETHOD(GetDebuggeeType)(
        THIS_
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
    STDMETHOD(GetActualProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Returns the type of processor used in the
    // current processor context.
    STDMETHOD(GetExecutingProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    // Query all the possible processor types that
    // may be encountered during this debug session.
    STDMETHOD(GetNumberPossibleExecutingProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPossibleExecutingProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Get the number of actual processors in
    // the machine.
    STDMETHOD(GetNumberProcessors)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
    STDMETHOD(GetSystemVersion)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Major,
        _Out_ PULONG Minor,
        _Out_writes_opt_(ServicePackStringSize) PSTR ServicePackString,
        _In_ ULONG ServicePackStringSize,
        _Out_opt_ PULONG ServicePackStringUsed,
        _Out_ PULONG ServicePackNumber,
        _Out_writes_opt_(BuildStringSize) PSTR BuildString,
        _In_ ULONG BuildStringSize,
        _Out_opt_ PULONG BuildStringUsed
        ) PURE;
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
    STDMETHOD(GetPageSize)(
        THIS_
        _Out_ PULONG Size
        ) PURE;
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
    STDMETHOD(IsPointer64Bit)(
        THIS
        ) PURE;
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
    STDMETHOD(ReadBugCheckData)(
        THIS_
        _Out_ PULONG Code,
        _Out_ PULONG64 Arg1,
        _Out_ PULONG64 Arg2,
        _Out_ PULONG64 Arg3,
        _Out_ PULONG64 Arg4
        ) PURE;

    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
    STDMETHOD(GetNumberSupportedProcessorTypes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSupportedProcessorTypes)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Types
        ) PURE;
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
    STDMETHOD(GetProcessorTypeNames)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
    STDMETHOD(GetEffectiveProcessorType)(
        THIS_
        _Out_ PULONG Type
        ) PURE;
    STDMETHOD(SetEffectiveProcessorType)(
        THIS_
        _In_ ULONG Type
        ) PURE;

    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
    STDMETHOD(GetExecutionStatus)(
        THIS_
        _Out_ PULONG Status
        ) PURE;
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
    STDMETHOD(SetExecutionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
    STDMETHOD(GetCodeLevel)(
        THIS_
        _Out_ PULONG Level
        ) PURE;
    STDMETHOD(SetCodeLevel)(
        THIS_
        _In_ ULONG Level
        ) PURE;

    // Gets and sets engine control flags.
    // These methods are reentrant.
    STDMETHOD(GetEngineOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetEngineOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
    STDMETHOD(GetSystemErrorControl)(
        THIS_
        _Out_ PULONG OutputLevel,
        _Out_ PULONG BreakLevel
        ) PURE;
    STDMETHOD(SetSystemErrorControl)(
        THIS_
        _In_ ULONG OutputLevel,
        _In_ ULONG BreakLevel
        ) PURE;

    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
    STDMETHOD(GetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacro)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCSTR Macro
        ) PURE;

    // Controls the default number radix used
    // in expressions and commands.
    STDMETHOD(GetRadix)(
        THIS_
        _Out_ PULONG Radix
        ) PURE;
    STDMETHOD(SetRadix)(
        THIS_
        _In_ ULONG Radix
        ) PURE;

    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
    STDMETHOD(Evaluate)(
        THIS_
        _In_ PCSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
    STDMETHOD(CoerceValue)(
        THIS_
        _In_ PDEBUG_VALUE In,
        _In_ ULONG OutType,
        _Out_ PDEBUG_VALUE Out
        ) PURE;
    STDMETHOD(CoerceValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_VALUE In,
        _In_reads_(Count) PULONG OutTypes,
        _Out_writes_(Count) PDEBUG_VALUE Out
        ) PURE;

    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
    STDMETHOD(Execute)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR Command,
        _In_ ULONG Flags
        ) PURE;
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
    STDMETHOD(ExecuteCommandFile)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    // Breakpoint interfaces are described
    // elsewhere in this section.
    STDMETHOD(GetNumberBreakpoints)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
    STDMETHOD(GetBreakpointByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
    STDMETHOD(GetBreakpointParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Ids,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_BREAKPOINT_PARAMETERS Params
        ) PURE;
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
    STDMETHOD(AddBreakpoint)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT* Bp
        ) PURE;
    // Breakpoint interface is invalid after this call.
    STDMETHOD(RemoveBreakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Control and use extension DLLs.
    STDMETHOD(AddExtension)(
        THIS_
        _In_ PCSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(RemoveExtension)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPath)(
        THIS_
        _In_ PCSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
    STDMETHOD(CallExtension)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR Function,
        _In_opt_ PCSTR Arguments
        ) PURE;
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // This function cannot be called remotely.
    STDMETHOD(GetExtensionFunction)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
    STDMETHOD(GetWindbgExtensionApis32)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS32 Api
        ) PURE;
    STDMETHOD(GetWindbgExtensionApis64)(
        THIS_
        _Inout_ PWINDBG_EXTENSION_APIS64 Api
        ) PURE;

    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
    STDMETHOD(GetNumberEventFilters)(
        THIS_
        _Out_ PULONG SpecificEvents,
        _Out_ PULONG SpecificExceptions,
        _Out_ PULONG ArbitraryExceptions
        ) PURE;
    // Some filters have descriptive text associated with them.
    STDMETHOD(GetEventFilterText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    // All filters support executing a command when the
    // event occurs.
    STDMETHOD(GetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    STDMETHOD(SetSpecificFilterParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_SPECIFIC_FILTER_PARAMETERS Params
        ) PURE;
    // Some specific filters have arguments to further
    // qualify their operation.
    STDMETHOD(GetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgument)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Argument
        ) PURE;
    // If Codes is non-NULL Start is ignored.
    STDMETHOD(GetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Codes,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
    STDMETHOD(SetExceptionFilterParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_(Count) PDEBUG_EXCEPTION_FILTER_PARAMETERS Params
        ) PURE;
    // Exception filters support an additional command for
    // second-chance events.
    STDMETHOD(GetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommand)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Command
        ) PURE;

    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
    STDMETHOD(WaitForEvent)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Timeout
        ) PURE;

    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
    STDMETHOD(GetLastEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    // IDebugControl2.

    STDMETHOD(GetCurrentTimeDate)(
        THIS_
        _Out_ PULONG TimeDate
        ) PURE;
    // Retrieves the number of seconds since the
    // machine started running.
    STDMETHOD(GetCurrentSystemUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // If the current session is a dump session,
    // retrieves any extended format information.
    STDMETHOD(GetDumpFormatFlags)(
        THIS_
        _Out_ PULONG FormatFlags
        ) PURE;

    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
    STDMETHOD(GetNumberTextReplacements)(
        THIS_
        _Out_ PULONG NumRepl
        ) PURE;
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
    STDMETHOD(GetTextReplacement)(
        THIS_
        _In_opt_ PCSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    // Setting the destination text to
    // NULL removes the alias.
    STDMETHOD(SetTextReplacement)(
        THIS_
        _In_ PCSTR SrcText,
        _In_opt_ PCSTR DstText
        ) PURE;
    STDMETHOD(RemoveTextReplacements)(
        THIS
        ) PURE;
    // Outputs the complete list of current
    // replacements.
    STDMETHOD(OutputTextReplacements)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl3.

    // Control options for assembly and disassembly.
    STDMETHOD(GetAssemblyOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetAssemblyOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // Control the expression syntax.
    STDMETHOD(GetExpressionSyntax)(
        THIS_
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(SetExpressionSyntax)(
        THIS_
        _In_ ULONG Flags
        ) PURE;
    // Look up a syntax by its abbreviated
    // name and set it.
    STDMETHOD(SetExpressionSyntaxByName)(
        THIS_
        _In_ PCSTR AbbrevName
        ) PURE;
    STDMETHOD(GetNumberExpressionSyntaxes)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNames)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    //
    // Some debug sessions have only a single
    // possible event, such as a snapshot dump
    // file; some have dynamic events, such as
    // a live debug session; and others may have
    // multiple events, such as a dump file that
    // contains snapshots from different points
    // in time.  The following methods allow
    // discovery and selection of the available
    // events for a session.
    // Sessions with one or more static events
    // will be able to report all of the events
    // when queried.  Sessions with dynamic events
    // will only report a single event representing
    // the current event.
    // Switching events constitutes execution and
    // changing the current event will alter the
    // execution status to a running state, after
    // which WaitForEvent must be used to process
    // the selected event.
    //

    // GetNumberEvents returns S_OK if this is the
    // complete set of events possible, such as for
    // a static session; or S_FALSE if other events
    // may be possible, such as for a dynamic session.
    STDMETHOD(GetNumberEvents)(
        THIS_
        _Out_ PULONG Events
        ) PURE;
    // Sessions may have descriptive information for
    // the various events available.  The amount of
    // information varies according to the specific
    // session and data.
    STDMETHOD(GetEventIndexDescription)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;
    STDMETHOD(GetCurrentEventIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    // SetNextEventIndex works like seek in that
    // it can set an absolute or relative index.
    // SetNextEventIndex works similarly to SetExecutionStatus
    // by putting the session into a running state, after
    // which the caller must call WaitForEvent.  The
    // current event index only changes when WaitForEvent
    // is called.
    STDMETHOD(SetNextEventIndex)(
        THIS_
        _In_ ULONG Relation,
        _In_ ULONG Value,
        _Out_ PULONG NextIndex
        ) PURE;

    // IDebugControl4.

    STDMETHOD(GetLogFileWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PBOOL Append
        ) PURE;
    STDMETHOD(OpenLogFileWide)(
        THIS_
        _In_ PCWSTR File,
        _In_ BOOL Append
        ) PURE;

    STDMETHOD(InputWide)(
        THIS_
        _Out_writes_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InputSize
        ) PURE;
    STDMETHOD(ReturnInputWide)(
        THIS_
        _In_ PCWSTR Buffer
        ) PURE;

    STDMETHODV(OutputWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputVaListWide)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHODV(ControlledOutputWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(ControlledOutputVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Mask,
        _In_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;

    STDMETHODV(OutputPromptWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        ...
        ) PURE;
    STDMETHOD(OutputPromptVaListWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_opt_ PCWSTR Format,
        _In_ va_list Args
        ) PURE;
    STDMETHOD(GetPromptTextWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;

    STDMETHOD(AssembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ PCWSTR Instr,
        _Out_ PULONG64 EndOffset
        ) PURE;
    STDMETHOD(DisassembleWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DisassemblySize,
        _Out_ PULONG64 EndOffset
        ) PURE;

    STDMETHOD(GetProcessorTypeNamesWide)(
        THIS_
        _In_ ULONG Type,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MacroSize
        ) PURE;
    STDMETHOD(SetTextMacroWide)(
        THIS_
        _In_ ULONG Slot,
        _In_ PCWSTR Macro
        ) PURE;

    STDMETHOD(EvaluateWide)(
        THIS_
        _In_ PCWSTR Expression,
        _In_ ULONG DesiredType,
        _Out_ PDEBUG_VALUE Value,
        _Out_opt_ PULONG RemainderIndex
        ) PURE;

    STDMETHOD(ExecuteWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR Command,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ExecuteCommandFileWide)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ PCWSTR CommandFile,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetBreakpointByIndex2)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(GetBreakpointById2)(
        THIS_
        _In_ ULONG Id,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(AddBreakpoint2)(
        THIS_
        _In_ ULONG Type,
        _In_ ULONG DesiredId,
        _Out_ PDEBUG_BREAKPOINT2* Bp
        ) PURE;
    STDMETHOD(RemoveBreakpoint2)(
        THIS_
        _In_ PDEBUG_BREAKPOINT2 Bp
        ) PURE;

    STDMETHOD(AddExtensionWide)(
        THIS_
        _In_ PCWSTR Path,
        _In_ ULONG Flags,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetExtensionByPathWide)(
        THIS_
        _In_ PCWSTR Path,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(CallExtensionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR Function,
        _In_opt_ PCWSTR Arguments
        ) PURE;
    STDMETHOD(GetExtensionFunctionWide)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ PCWSTR FuncName,
        _Out_ FARPROC* Function
        ) PURE;

    STDMETHOD(GetEventFilterTextWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TextSize
        ) PURE;
    STDMETHOD(GetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetEventFilterCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;
    STDMETHOD(GetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ArgumentSize
        ) PURE;
    STDMETHOD(SetSpecificFilterArgumentWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Argument
        ) PURE;
    STDMETHOD(GetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG CommandSize
        ) PURE;
    STDMETHOD(SetExceptionFilterSecondCommandWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Command
        ) PURE;

    STDMETHOD(GetLastEventInformationWide)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed,
        _Out_writes_opt_(DescriptionSize) PWSTR Description,
        _In_ ULONG DescriptionSize,
        _Out_opt_ PULONG DescriptionUsed
        ) PURE;

    STDMETHOD(GetTextReplacementWide)(
        THIS_
        _In_opt_ PCWSTR SrcText,
        _In_ ULONG Index,
        _Out_writes_opt_(SrcBufferSize) PWSTR SrcBuffer,
        _In_ ULONG SrcBufferSize,
        _Out_opt_ PULONG SrcSize,
        _Out_writes_opt_(DstBufferSize) PWSTR DstBuffer,
        _In_ ULONG DstBufferSize,
        _Out_opt_ PULONG DstSize
        ) PURE;
    STDMETHOD(SetTextReplacementWide)(
        THIS_
        _In_ PCWSTR SrcText,
        _In_opt_ PCWSTR DstText
        ) PURE;

    STDMETHOD(SetExpressionSyntaxByNameWide)(
        THIS_
        _In_ PCWSTR AbbrevName
        ) PURE;
    STDMETHOD(GetExpressionSyntaxNamesWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(FullNameBufferSize) PWSTR FullNameBuffer,
        _In_ ULONG FullNameBufferSize,
        _Out_opt_ PULONG FullNameSize,
        _Out_writes_opt_(AbbrevNameBufferSize) PWSTR AbbrevNameBuffer,
        _In_ ULONG AbbrevNameBufferSize,
        _Out_opt_ PULONG AbbrevNameSize
        ) PURE;

    STDMETHOD(GetEventIndexDescriptionWide)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG Which,
        _In_opt_ PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DescSize
        ) PURE;

    STDMETHOD(GetLogFile2)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2)(
        THIS_
        _In_ PCSTR File,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(GetLogFile2Wide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_ PULONG Flags
        ) PURE;
    STDMETHOD(OpenLogFile2Wide)(
        THIS_
        _In_ PCWSTR File,
        _In_ ULONG Flags
        ) PURE;

    // GetSystemVersion always returns the kd
    // major/minor version numbers, which are
    // different than the Win32 version numbers.
    // GetSystemVersionValues can be used
    // to determine the Win32 version values.
    STDMETHOD(GetSystemVersionValues)(
        THIS_
        _Out_ PULONG PlatformId,
        _Out_ PULONG Win32Major,
        _Out_ PULONG Win32Minor,
        _Out_opt_ PULONG KdMajor,
        _Out_opt_ PULONG KdMinor
        ) PURE;
    // Strings are selected with DEBUG_SYSVERSTR_*.
    STDMETHOD(GetSystemVersionString)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSystemVersionStringWide)(
        THIS_
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;

    // Stack tracing with a full initial context
    // and full context return for each frame.
    // The FrameContextsSize parameter is the total
    // byte size of FrameContexts.  FrameContextsEntrySize
    // gives the byte size of each entry in
    // FrameContexts.
    STDMETHOD(GetContextStackTrace)(
        THIS_
        _In_reads_bytes_opt_(StartContextSize) PVOID StartContext,
        _In_ ULONG StartContextSize,
        _Out_writes_to_opt_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _Out_writes_bytes_opt_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;
    STDMETHOD(OutputContextStackTrace)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_(FramesSize) PDEBUG_STACK_FRAME Frames,
        _In_ ULONG FramesSize,
        _In_reads_bytes_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _In_ ULONG Flags
        ) PURE;

    // Some targets, such as user-mode minidump files,
    // have separate "event of interest" information
    // stored within them.  This method allows
    // access to that information.
    STDMETHOD(GetStoredEventInformation)(
        THIS_
        _Out_ PULONG Type,
        _Out_ PULONG ProcessId,
        _Out_ PULONG ThreadId,
        _Out_writes_bytes_opt_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize,
        _Out_opt_ PULONG ContextUsed,
        _Out_writes_bytes_opt_(ExtraInformationSize) PVOID ExtraInformation,
        _In_ ULONG ExtraInformationSize,
        _Out_opt_ PULONG ExtraInformationUsed
        ) PURE;

    // Managed debugging support relies on debugging
    // functionality provided by the Common Language Runtime.
    // This method provides feedback on the engine's
    // use of the runtime debugging APIs.
    STDMETHOD(GetManagedStatus)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    STDMETHOD(GetManagedStatusWide)(
        THIS_
        _Out_opt_ PULONG Flags,
        _In_ ULONG WhichString,
        _Out_writes_opt_(StringSize) PWSTR String,
        _In_ ULONG StringSize,
        _Out_opt_ PULONG StringNeeded
        ) PURE;
    // Clears and reinitializes the engine's
    // managed code debugging support.
    STDMETHOD(ResetManagedStatus)(
        THIS_
        _In_ ULONG Flags
        ) PURE;

    // IDebugControl5
    STDMETHOD(GetStackTraceEx)(
        THIS_
        _In_ ULONG64 FrameOffset,
        _In_ ULONG64 StackOffset,
        _In_ ULONG64 InstructionOffset,
        _Out_writes_to_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;

    STDMETHOD(OutputStackTraceEx)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_opt_(FramesSize) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetContextStackTraceEx)(
        THIS_
        _In_reads_bytes_opt_(StartContextSize) PVOID StartContext,
        _In_ ULONG StartContextSize,
        _Out_writes_to_opt_(FramesSize,*FramesFilled) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _Out_writes_bytes_opt_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _Out_opt_ PULONG FramesFilled
        ) PURE;

    STDMETHOD(OutputContextStackTraceEx)(
        THIS_
        _In_ ULONG OutputControl,
        _In_reads_(FramesSize) PDEBUG_STACK_FRAME_EX Frames,
        _In_ ULONG FramesSize,
        _In_reads_bytes_(FrameContextsSize) PVOID FrameContexts,
        _In_ ULONG FrameContextsSize,
        _In_ ULONG FrameContextsEntrySize,
        _In_ ULONG Flags
        ) PURE;

    STDMETHOD(GetBreakpointByGuid)(
        THIS_
        _In_ LPGUID Guid,
        _Out_ PDEBUG_BREAKPOINT3* Bp
        ) PURE;

    // IDebugControl6

    // Returns additional info states for
    STDMETHOD(GetExecutionStatusEx)(
        THIS_
        _Out_ PULONG Status
        ) PURE;

    STDMETHOD(GetSynchronizationStatus)(
        THIS_
        _Out_ PULONG SendsAttempted,
        _Out_ PULONG SecondsSinceLastResponse
        ) PURE;

    // IDebugControl7

    STDMETHOD(GetDebuggeeType2)(
        THIS_
        _In_ ULONG Flags,
        _Out_ PULONG Class,
        _Out_ PULONG Qualifier
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugDataSpaces.
//
//----------------------------------------------------------------------------

// Data space indices for callbacks and other methods.
#define DEBUG_DATA_SPACE_VIRTUAL       0
#define DEBUG_DATA_SPACE_PHYSICAL      1
#define DEBUG_DATA_SPACE_CONTROL       2
#define DEBUG_DATA_SPACE_IO            3
#define DEBUG_DATA_SPACE_MSR           4
#define DEBUG_DATA_SPACE_BUS_DATA      5
#define DEBUG_DATA_SPACE_DEBUGGER_DATA 6
// Count of data spaces.
#define DEBUG_DATA_SPACE_COUNT         7

// Indices for ReadDebuggerData interface
#define DEBUG_DATA_KernBase                              24
#define DEBUG_DATA_BreakpointWithStatusAddr              32
#define DEBUG_DATA_SavedContextAddr                      40
#define DEBUG_DATA_KiCallUserModeAddr                    56
#define DEBUG_DATA_KeUserCallbackDispatcherAddr          64
#define DEBUG_DATA_PsLoadedModuleListAddr                72
#define DEBUG_DATA_PsActiveProcessHeadAddr               80
#define DEBUG_DATA_PspCidTableAddr                       88
#define DEBUG_DATA_ExpSystemResourcesListAddr            96
#define DEBUG_DATA_ExpPagedPoolDescriptorAddr           104
#define DEBUG_DATA_ExpNumberOfPagedPoolsAddr            112
#define DEBUG_DATA_KeTimeIncrementAddr                  120
#define DEBUG_DATA_KeBugCheckCallbackListHeadAddr       128
#define DEBUG_DATA_KiBugcheckDataAddr                   136
#define DEBUG_DATA_IopErrorLogListHeadAddr              144
#define DEBUG_DATA_ObpRootDirectoryObjectAddr           152
#define DEBUG_DATA_ObpTypeObjectTypeAddr                160
#define DEBUG_DATA_MmSystemCacheStartAddr               168
#define DEBUG_DATA_MmSystemCacheEndAddr                 176
#define DEBUG_DATA_MmSystemCacheWsAddr                  184
#define DEBUG_DATA_MmPfnDatabaseAddr                    192
#define DEBUG_DATA_MmSystemPtesStartAddr                200
#define DEBUG_DATA_MmSystemPtesEndAddr                  208
#define DEBUG_DATA_MmSubsectionBaseAddr                 216
#define DEBUG_DATA_MmNumberOfPagingFilesAddr            224
#define DEBUG_DATA_MmLowestPhysicalPageAddr             232
#define DEBUG_DATA_MmHighestPhysicalPageAddr            240
#define DEBUG_DATA_MmNumberOfPhysicalPagesAddr          248
#define DEBUG_DATA_MmMaximumNonPagedPoolInBytesAddr     256
#define DEBUG_DATA_MmNonPagedSystemStartAddr            264
#define DEBUG_DATA_MmNonPagedPoolStartAddr              272
#define DEBUG_DATA_MmNonPagedPoolEndAddr                280
#define DEBUG_DATA_MmPagedPoolStartAddr                 288
#define DEBUG_DATA_MmPagedPoolEndAddr                   296
#define DEBUG_DATA_MmPagedPoolInformationAddr           304
#define DEBUG_DATA_MmPageSize                           312
#define DEBUG_DATA_MmSizeOfPagedPoolInBytesAddr         320
#define DEBUG_DATA_MmTotalCommitLimitAddr               328
#define DEBUG_DATA_MmTotalCommittedPagesAddr            336
#define DEBUG_DATA_MmSharedCommitAddr                   344
#define DEBUG_DATA_MmDriverCommitAddr                   352
#define DEBUG_DATA_MmProcessCommitAddr                  360
#define DEBUG_DATA_MmPagedPoolCommitAddr                368
#define DEBUG_DATA_MmExtendedCommitAddr                 376
#define DEBUG_DATA_MmZeroedPageListHeadAddr             384
#define DEBUG_DATA_MmFreePageListHeadAddr               392
#define DEBUG_DATA_MmStandbyPageListHeadAddr            400
#define DEBUG_DATA_MmModifiedPageListHeadAddr           408
#define DEBUG_DATA_MmModifiedNoWritePageListHeadAddr    416
#define DEBUG_DATA_MmAvailablePagesAddr                 424
#define DEBUG_DATA_MmResidentAvailablePagesAddr         432
#define DEBUG_DATA_PoolTrackTableAddr                   440
#define DEBUG_DATA_NonPagedPoolDescriptorAddr           448
#define DEBUG_DATA_MmHighestUserAddressAddr             456
#define DEBUG_DATA_MmSystemRangeStartAddr               464
#define DEBUG_DATA_MmUserProbeAddressAddr               472
#define DEBUG_DATA_KdPrintCircularBufferAddr            480
#define DEBUG_DATA_KdPrintCircularBufferEndAddr         488
#define DEBUG_DATA_KdPrintWritePointerAddr              496
#define DEBUG_DATA_KdPrintRolloverCountAddr             504
#define DEBUG_DATA_MmLoadedUserImageListAddr            512
#define DEBUG_DATA_NtBuildLabAddr                       520
#define DEBUG_DATA_KiNormalSystemCall                   528
#define DEBUG_DATA_KiProcessorBlockAddr                 536
#define DEBUG_DATA_MmUnloadedDriversAddr                544
#define DEBUG_DATA_MmLastUnloadedDriverAddr             552
#define DEBUG_DATA_MmTriageActionTakenAddr              560
#define DEBUG_DATA_MmSpecialPoolTagAddr                 568
#define DEBUG_DATA_KernelVerifierAddr                   576
#define DEBUG_DATA_MmVerifierDataAddr                   584
#define DEBUG_DATA_MmAllocatedNonPagedPoolAddr          592
#define DEBUG_DATA_MmPeakCommitmentAddr                 600
#define DEBUG_DATA_MmTotalCommitLimitMaximumAddr        608
#define DEBUG_DATA_CmNtCSDVersionAddr                   616
#define DEBUG_DATA_MmPhysicalMemoryBlockAddr            624
#define DEBUG_DATA_MmSessionBase                        632
#define DEBUG_DATA_MmSessionSize                        640
#define DEBUG_DATA_MmSystemParentTablePage              648
#define DEBUG_DATA_MmVirtualTranslationBase             656
#define DEBUG_DATA_OffsetKThreadNextProcessor           664
#define DEBUG_DATA_OffsetKThreadTeb                     666
#define DEBUG_DATA_OffsetKThreadKernelStack             668
#define DEBUG_DATA_OffsetKThreadInitialStack            670
#define DEBUG_DATA_OffsetKThreadApcProcess              672
#define DEBUG_DATA_OffsetKThreadState                   674
#define DEBUG_DATA_OffsetKThreadBStore                  676
#define DEBUG_DATA_OffsetKThreadBStoreLimit             678
#define DEBUG_DATA_SizeEProcess                         680
#define DEBUG_DATA_OffsetEprocessPeb                    682
#define DEBUG_DATA_OffsetEprocessParentCID              684
#define DEBUG_DATA_OffsetEprocessDirectoryTableBase     686
#define DEBUG_DATA_SizePrcb                             688
#define DEBUG_DATA_OffsetPrcbDpcRoutine                 690
#define DEBUG_DATA_OffsetPrcbCurrentThread              692
#define DEBUG_DATA_OffsetPrcbMhz                        694
#define DEBUG_DATA_OffsetPrcbCpuType                    696
#define DEBUG_DATA_OffsetPrcbVendorString               698
#define DEBUG_DATA_OffsetPrcbProcessorState             700
#define DEBUG_DATA_OffsetPrcbNumber                     702
#define DEBUG_DATA_SizeEThread                          704
#define DEBUG_DATA_KdPrintCircularBufferPtrAddr         712
#define DEBUG_DATA_KdPrintBufferSizeAddr                720
#define DEBUG_DATA_MmBadPagesDetected                   800
#define DEBUG_DATA_EtwpDebuggerData                     816
#define DEBUG_DATA_PteBase                              864

#define DEBUG_DATA_PaeEnabled                        100000
#define DEBUG_DATA_SharedUserData                    100008
#define DEBUG_DATA_ProductType                       100016
#define DEBUG_DATA_SuiteMask                         100024
#define DEBUG_DATA_DumpWriterStatus                  100032
#define DEBUG_DATA_DumpFormatVersion                 100040
#define DEBUG_DATA_DumpWriterVersion                 100048
#define DEBUG_DATA_DumpPowerState                    100056
#define DEBUG_DATA_DumpMmStorage                     100064
#define DEBUG_DATA_DumpAttributes                    100072
#define DEBUG_DATA_PagingLevels                      100080

//
// Processor information structures.
//

typedef struct _DEBUG_PROCESSOR_IDENTIFICATION_ALPHA
{
    ULONG Type;
    ULONG Revision;
} DEBUG_PROCESSOR_IDENTIFICATION_ALPHA, *PDEBUG_PROCESSOR_IDENTIFICATION_ALPHA;

typedef struct _DEBUG_PROCESSOR_IDENTIFICATION_AMD64
{
    ULONG Family;
    ULONG Model;
    ULONG Stepping;
    CHAR  VendorString[16];
} DEBUG_PROCESSOR_IDENTIFICATION_AMD64, *PDEBUG_PROCESSOR_IDENTIFICATION_AMD64;

typedef struct _DEBUG_PROCESSOR_IDENTIFICATION_IA64
{
    ULONG Model;
    ULONG Revision;
    ULONG Family;
    ULONG ArchRev;
    CHAR  VendorString[16];
} DEBUG_PROCESSOR_IDENTIFICATION_IA64, *PDEBUG_PROCESSOR_IDENTIFICATION_IA64;

typedef struct _DEBUG_PROCESSOR_IDENTIFICATION_X86
{
    ULONG Family;
    ULONG Model;
    ULONG Stepping;
    CHAR  VendorString[16];
} DEBUG_PROCESSOR_IDENTIFICATION_X86, *PDEBUG_PROCESSOR_IDENTIFICATION_X86;

typedef struct _DEBUG_PROCESSOR_IDENTIFICATION_ARM
{
    ULONG Model;
    ULONG Revision;
    CHAR  VendorString[16];
} DEBUG_PROCESSOR_IDENTIFICATION_ARM, *PDEBUG_PROCESSOR_IDENTIFICATION_ARM;

typedef struct _DEBUG_PROCESSOR_IDENTIFICATION_ARM64
{
    ULONG Model;
    ULONG Revision;
    CHAR  VendorString[16];
} DEBUG_PROCESSOR_IDENTIFICATION_ARM64, *PDEBUG_PROCESSOR_IDENTIFICATION_ARM64;

typedef union _DEBUG_PROCESSOR_IDENTIFICATION_ALL
{
    DEBUG_PROCESSOR_IDENTIFICATION_ALPHA Alpha;
    DEBUG_PROCESSOR_IDENTIFICATION_AMD64 Amd64;
    DEBUG_PROCESSOR_IDENTIFICATION_IA64  Ia64;
    DEBUG_PROCESSOR_IDENTIFICATION_X86   X86;
    DEBUG_PROCESSOR_IDENTIFICATION_ARM   Arm;
    DEBUG_PROCESSOR_IDENTIFICATION_ARM64 Arm64;
} DEBUG_PROCESSOR_IDENTIFICATION_ALL, *PDEBUG_PROCESSOR_IDENTIFICATION_ALL;

// Indices for ReadProcessorSystemData.
#define DEBUG_DATA_KPCR_OFFSET                          0
#define DEBUG_DATA_KPRCB_OFFSET                         1
#define DEBUG_DATA_KTHREAD_OFFSET                       2
#define DEBUG_DATA_BASE_TRANSLATION_VIRTUAL_OFFSET      3
#define DEBUG_DATA_PROCESSOR_IDENTIFICATION             4
#define DEBUG_DATA_PROCESSOR_SPEED                      5

#undef INTERFACE
#define INTERFACE IDebugDataSpaces
DECLARE_INTERFACE_(IDebugDataSpaces, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugDataSpaces.
    STDMETHOD(ReadVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
    STDMETHOD(SearchVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Length,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _In_ ULONG PatternGranularity,
        _Out_ PULONG64 MatchOffset
        ) PURE;
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
    STDMETHOD(ReadVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
    STDMETHOD(ReadPointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _Out_writes_(Count) PULONG64 Ptrs
        ) PURE;
    STDMETHOD(WritePointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _In_reads_(Count) PULONG64 Ptrs
        ) PURE;
    // All non-virtual data spaces are only
    // available when kernel debugging.
    STDMETHOD(ReadPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WritePhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadMsr)(
        THIS_
        _In_ ULONG Msr,
        _Out_ PULONG64 Value
        ) PURE;
    STDMETHOD(WriteMsr)(
        THIS_
        _In_ ULONG Msr,
        _In_ ULONG64 Value
        ) PURE;
    STDMETHOD(ReadBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(CheckLowMemory)(
        THIS
        ) PURE;
    STDMETHOD(ReadDebuggerData)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;
    STDMETHOD(ReadProcessorSystemData)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;
};

//
// Handle data types and structures.
//

#define DEBUG_HANDLE_DATA_TYPE_BASIC                 0
#define DEBUG_HANDLE_DATA_TYPE_TYPE_NAME             1
#define DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME           2
#define DEBUG_HANDLE_DATA_TYPE_HANDLE_COUNT          3
#define DEBUG_HANDLE_DATA_TYPE_TYPE_NAME_WIDE        4
#define DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME_WIDE      5
#define DEBUG_HANDLE_DATA_TYPE_MINI_THREAD_1         6
#define DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_1         7
#define DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_2         8
#define DEBUG_HANDLE_DATA_TYPE_PER_HANDLE_OPERATIONS 9
#define DEBUG_HANDLE_DATA_TYPE_ALL_HANDLE_OPERATIONS 10
#define DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_1        11
#define DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_2        12
#define DEBUG_HANDLE_DATA_TYPE_MINI_EVENT_1          13
#define DEBUG_HANDLE_DATA_TYPE_MINI_SECTION_1        14
#define DEBUG_HANDLE_DATA_TYPE_MINI_SEMAPHORE_1      15

typedef struct _DEBUG_HANDLE_DATA_BASIC
{
    ULONG TypeNameSize;
    ULONG ObjectNameSize;
    ULONG Attributes;
    ULONG GrantedAccess;
    ULONG HandleCount;
    ULONG PointerCount;
} DEBUG_HANDLE_DATA_BASIC, *PDEBUG_HANDLE_DATA_BASIC;

#undef INTERFACE
#define INTERFACE IDebugDataSpaces2
DECLARE_INTERFACE_(IDebugDataSpaces2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugDataSpaces.
    STDMETHOD(ReadVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
    STDMETHOD(SearchVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Length,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _In_ ULONG PatternGranularity,
        _Out_ PULONG64 MatchOffset
        ) PURE;
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
    STDMETHOD(ReadVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
    STDMETHOD(ReadPointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _Out_writes_(Count) PULONG64 Ptrs
        ) PURE;
    STDMETHOD(WritePointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _In_reads_(Count) PULONG64 Ptrs
        ) PURE;
    // All non-virtual data spaces are only
    // available when kernel debugging.
    STDMETHOD(ReadPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WritePhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadMsr)(
        THIS_
        _In_ ULONG Msr,
        _Out_ PULONG64 Value
        ) PURE;
    STDMETHOD(WriteMsr)(
        THIS_
        _In_ ULONG Msr,
        _In_ ULONG64 Value
        ) PURE;
    STDMETHOD(ReadBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(CheckLowMemory)(
        THIS
        ) PURE;
    STDMETHOD(ReadDebuggerData)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;
    STDMETHOD(ReadProcessorSystemData)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;

    // IDebugDataSpaces2.

    STDMETHOD(VirtualToPhysical)(
        THIS_
        _In_ ULONG64 Virtual,
        _Out_ PULONG64 Physical
        ) PURE;
    // Returns the physical addresses for the
    // N levels of the systems paging structures.
    // Level zero is the starting base physical
    // address for virtual translations.
    // Levels one-(N-1) will point to the appropriate
    // paging descriptor for the virtual address at
    // the given level of the paging hierarchy.  The
    // exact number of levels depends on many factors.
    // The last level will be the fully translated
    // physical address, matching what VirtualToPhysical
    // returns.  If the address can only be partially
    // translated S_FALSE is returned.
    STDMETHOD(GetVirtualTranslationPhysicalOffsets)(
        THIS_
        _In_ ULONG64 Virtual,
        _Out_writes_opt_(OffsetsSize) PULONG64 Offsets,
        _In_ ULONG OffsetsSize,
        _Out_opt_ PULONG Levels
        ) PURE;

    // System handle data is accessible in certain
    // debug sessions.  The particular data available
    // varies from session to session and platform
    // to platform.
    STDMETHOD(ReadHandleData)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG DataType,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;

    // Fills memory with the given pattern.
    // The fill stops at the first non-writable byte.
    STDMETHOD(FillVirtual)(
        THIS_
        _In_ ULONG64 Start,
        _In_ ULONG Size,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _Out_opt_ PULONG Filled
        ) PURE;
    STDMETHOD(FillPhysical)(
        THIS_
        _In_ ULONG64 Start,
        _In_ ULONG Size,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _Out_opt_ PULONG Filled
        ) PURE;

    // Queries virtual memory mapping information given
    // an address similarly to the Win32 API VirtualQuery.
    // MEMORY_BASIC_INFORMATION64 is defined in crash.h.
    // This method currently only works for user-mode sessions.
    STDMETHOD(QueryVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PMEMORY_BASIC_INFORMATION64 Info
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugDataSpaces3
DECLARE_INTERFACE_(IDebugDataSpaces3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugDataSpaces.
    STDMETHOD(ReadVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
    STDMETHOD(SearchVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Length,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _In_ ULONG PatternGranularity,
        _Out_ PULONG64 MatchOffset
        ) PURE;
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
    STDMETHOD(ReadVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
    STDMETHOD(ReadPointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _Out_writes_(Count) PULONG64 Ptrs
        ) PURE;
    STDMETHOD(WritePointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _In_reads_(Count) PULONG64 Ptrs
        ) PURE;
    // All non-virtual data spaces are only
    // available when kernel debugging.
    STDMETHOD(ReadPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WritePhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadMsr)(
        THIS_
        _In_ ULONG Msr,
        _Out_ PULONG64 Value
        ) PURE;
    STDMETHOD(WriteMsr)(
        THIS_
        _In_ ULONG Msr,
        _In_ ULONG64 Value
        ) PURE;
    STDMETHOD(ReadBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(CheckLowMemory)(
        THIS
        ) PURE;
    STDMETHOD(ReadDebuggerData)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;
    STDMETHOD(ReadProcessorSystemData)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;

    // IDebugDataSpaces2.

    STDMETHOD(VirtualToPhysical)(
        THIS_
        _In_ ULONG64 Virtual,
        _Out_ PULONG64 Physical
        ) PURE;
    // Returns the physical addresses for the
    // N levels of the systems paging structures.
    // Level zero is the starting base physical
    // address for virtual translations.
    // Levels one-(N-1) will point to the appropriate
    // paging descriptor for the virtual address at
    // the given level of the paging hierarchy.  The
    // exact number of levels depends on many factors.
    // The last level will be the fully translated
    // physical address, matching what VirtualToPhysical
    // returns.  If the address can only be partially
    // translated S_FALSE is returned.
    STDMETHOD(GetVirtualTranslationPhysicalOffsets)(
        THIS_
        _In_ ULONG64 Virtual,
        _Out_writes_opt_(OffsetsSize) PULONG64 Offsets,
        _In_ ULONG OffsetsSize,
        _Out_opt_ PULONG Levels
        ) PURE;

    // System handle data is accessible in certain
    // debug sessions.  The particular data available
    // varies from session to session and platform
    // to platform.
    STDMETHOD(ReadHandleData)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG DataType,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;

    // Fills memory with the given pattern.
    // The fill stops at the first non-writable byte.
    STDMETHOD(FillVirtual)(
        THIS_
        _In_ ULONG64 Start,
        _In_ ULONG Size,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _Out_opt_ PULONG Filled
        ) PURE;
    STDMETHOD(FillPhysical)(
        THIS_
        _In_ ULONG64 Start,
        _In_ ULONG Size,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _Out_opt_ PULONG Filled
        ) PURE;

    // Queries virtual memory mapping information given
    // an address similarly to the Win32 API VirtualQuery.
    // MEMORY_BASIC_INFORMATION64 is defined in crash.h.
    // This method currently only works for user-mode sessions.
    STDMETHOD(QueryVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PMEMORY_BASIC_INFORMATION64 Info
        ) PURE;

    // IDebugDataSpaces3.

    // Convenience method for reading an image
    // header from virtual memory.  Given the
    // image base, this method determines where
    // the NT headers are, validates the necessary
    // markers and converts the headers into
    // 64-bit form for consistency.
    // A caller can check whether the headers were
    // originally 32-bit by checking the optional
    // header magic value.
    // This method will not read ROM headers.
    STDMETHOD(ReadImageNtHeaders)(
        THIS_
        _In_ ULONG64 ImageBase,
        _Out_ PIMAGE_NT_HEADERS64 Headers
        ) PURE;

    // Some debug sessions have arbitrary additional
    // data available.  For example, additional dump
    // information files may contain extra information
    // gathered at the same time as the primary dump.
    // Such information is tagged with a unique identifier
    // and can only be retrieved via the tag.
    // Tagged data cannot be partially available; the
    // tagged block is either fully present or completely
    // absent.
    STDMETHOD(ReadTagged)(
        THIS_
        _In_ LPGUID Tag,
        _In_ ULONG Offset,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TotalSize
        ) PURE;
    STDMETHOD(StartEnumTagged)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetNextTagged)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ LPGUID Tag,
        _Out_ PULONG Size
        ) PURE;
    STDMETHOD(EndEnumTagged)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;
};

#define DEBUG_OFFSINFO_VIRTUAL_SOURCE 0x00000001

#define DEBUG_VSOURCE_INVALID              0x00000000
#define DEBUG_VSOURCE_DEBUGGEE             0x00000001
#define DEBUG_VSOURCE_MAPPED_IMAGE         0x00000002
#define DEBUG_VSOURCE_DUMP_WITHOUT_MEMINFO 0x00000003

#define DEBUG_VSEARCH_DEFAULT       0x00000000
#define DEBUG_VSEARCH_WRITABLE_ONLY 0x00000001

#define DEBUG_PHYSICAL_DEFAULT        0x00000000
#define DEBUG_PHYSICAL_CACHED         0x00000001
#define DEBUG_PHYSICAL_UNCACHED       0x00000002
#define DEBUG_PHYSICAL_WRITE_COMBINED 0x00000003

#undef INTERFACE
#define INTERFACE IDebugDataSpaces4
DECLARE_INTERFACE_(IDebugDataSpaces4, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugDataSpaces.

    STDMETHOD(ReadVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
    STDMETHOD(SearchVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Length,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _In_ ULONG PatternGranularity,
        _Out_ PULONG64 MatchOffset
        ) PURE;
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
    STDMETHOD(ReadVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteVirtualUncached)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
    STDMETHOD(ReadPointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _Out_writes_(Count) PULONG64 Ptrs
        ) PURE;
    STDMETHOD(WritePointersVirtual)(
        THIS_
        _In_ ULONG Count,
        _In_ ULONG64 Offset,
        _In_reads_(Count) PULONG64 Ptrs
        ) PURE;
    // All non-virtual data spaces are only
    // available when kernel debugging.
    STDMETHOD(ReadPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WritePhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteControl)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteIo)(
        THIS_
        _In_ ULONG InterfaceType,
        _In_ ULONG BusNumber,
        _In_ ULONG AddressSpace,
        _In_ ULONG64 Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(ReadMsr)(
        THIS_
        _In_ ULONG Msr,
        _Out_ PULONG64 Value
        ) PURE;
    STDMETHOD(WriteMsr)(
        THIS_
        _In_ ULONG Msr,
        _In_ ULONG64 Value
        ) PURE;
    STDMETHOD(ReadBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteBusData)(
        THIS_
        _In_ ULONG BusDataType,
        _In_ ULONG BusNumber,
        _In_ ULONG SlotNumber,
        _In_ ULONG Offset,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(CheckLowMemory)(
        THIS
        ) PURE;
    STDMETHOD(ReadDebuggerData)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;
    STDMETHOD(ReadProcessorSystemData)(
        THIS_
        _In_ ULONG Processor,
        _In_ ULONG Index,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;

    // IDebugDataSpaces2.

    STDMETHOD(VirtualToPhysical)(
        THIS_
        _In_ ULONG64 Virtual,
        _Out_ PULONG64 Physical
        ) PURE;
    // Returns the physical addresses for the
    // N levels of the systems paging structures.
    // Level zero is the starting base physical
    // address for virtual translations.
    // Levels one-(N-1) will point to the appropriate
    // paging descriptor for the virtual address at
    // the given level of the paging hierarchy.  The
    // exact number of levels depends on many factors.
    // The last level will be the fully translated
    // physical address, matching what VirtualToPhysical
    // returns.  If the address can only be partially
    // translated S_FALSE is returned.
    STDMETHOD(GetVirtualTranslationPhysicalOffsets)(
        THIS_
        _In_ ULONG64 Virtual,
        _Out_writes_opt_(OffsetsSize) PULONG64 Offsets,
        _In_ ULONG OffsetsSize,
        _Out_opt_ PULONG Levels
        ) PURE;

    // System handle data is accessible in certain
    // debug sessions.  The particular data available
    // varies from session to session and platform
    // to platform.
    STDMETHOD(ReadHandleData)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG DataType,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG DataSize
        ) PURE;

    // Fills memory with the given pattern.
    // The fill stops at the first non-writable byte.
    STDMETHOD(FillVirtual)(
        THIS_
        _In_ ULONG64 Start,
        _In_ ULONG Size,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _Out_opt_ PULONG Filled
        ) PURE;
    STDMETHOD(FillPhysical)(
        THIS_
        _In_ ULONG64 Start,
        _In_ ULONG Size,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _Out_opt_ PULONG Filled
        ) PURE;

    // Queries virtual memory mapping information given
    // an address similarly to the Win32 API VirtualQuery.
    // MEMORY_BASIC_INFORMATION64 is defined in crash.h.
    // This method currently only works for user-mode sessions.
    STDMETHOD(QueryVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PMEMORY_BASIC_INFORMATION64 Info
        ) PURE;

    // IDebugDataSpaces3.

    // Convenience method for reading an image
    // header from virtual memory.  Given the
    // image base, this method determines where
    // the NT headers are, validates the necessary
    // markers and converts the headers into
    // 64-bit form for consistency.
    // A caller can check whether the headers were
    // originally 32-bit by checking the optional
    // header magic value.
    // This method will not read ROM headers.
    STDMETHOD(ReadImageNtHeaders)(
        THIS_
        _In_ ULONG64 ImageBase,
        _Out_ PIMAGE_NT_HEADERS64 Headers
        ) PURE;

    // Some debug sessions have arbitrary additional
    // data available.  For example, additional dump
    // information files may contain extra information
    // gathered at the same time as the primary dump.
    // Such information is tagged with a unique identifier
    // and can only be retrieved via the tag.
    // Tagged data cannot be partially available; the
    // tagged block is either fully present or completely
    // absent.
    STDMETHOD(ReadTagged)(
        THIS_
        _In_ LPGUID Tag,
        _In_ ULONG Offset,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG TotalSize
        ) PURE;
    STDMETHOD(StartEnumTagged)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetNextTagged)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ LPGUID Tag,
        _Out_ PULONG Size
        ) PURE;
    STDMETHOD(EndEnumTagged)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    // IDebugDataSpaces4.

    // General information about an address in the given data space.
    // Queries are from DEBUG_OFFSINFO_*.
    STDMETHOD(GetOffsetInformation)(
        THIS_
        _In_ ULONG Space,
        _In_ ULONG Which,
        _In_ ULONG64 Offset,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG InfoSize
        ) PURE;

    // Given a particular address, return the
    // next address which has a different validity.
    // For example, in debug sessions such as a live
    // user-mode session where virtual address validity
    // changes from page to page this will return the
    // page after the given page.  In sessions such as
    // a user-mode dump file where validity can change
    // from byte to byte this will return the start of
    // the next region that has different validity.
    STDMETHOD(GetNextDifferentlyValidOffsetVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG64 NextOffset
        ) PURE;

    // Given a particular range of virtual addresses,
    // find the first region which is valid memory.
    STDMETHOD(GetValidRegionVirtual)(
        THIS_
        _In_ ULONG64 Base,
        _In_ ULONG Size,
        _Out_ PULONG64 ValidBase,
        _Out_ PULONG ValidSize
        ) PURE;

    STDMETHOD(SearchVirtual2)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Length,
        _In_ ULONG Flags,
        _In_reads_bytes_(PatternSize) PVOID Pattern,
        _In_ ULONG PatternSize,
        _In_ ULONG PatternGranularity,
        _Out_ PULONG64 MatchOffset
        ) PURE;

    // Attempts to read a multi-byte string
    // starting at the given virtual address.
    // The possible string length, including terminator,
    // is capped at the given max size.
    // If a return buffer is given it will always
    // be terminated.
    STDMETHOD(ReadMultiByteStringVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG MaxBytes,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringBytes
        ) PURE;
    // Reads a multi-byte string and converts
    // it to Unicode using the given code page.
    STDMETHOD(ReadMultiByteStringVirtualWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG MaxBytes,
        _In_ ULONG CodePage,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringBytes
        ) PURE;
    STDMETHOD(ReadUnicodeStringVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG MaxBytes,
        _In_ ULONG CodePage,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringBytes
        ) PURE;
    STDMETHOD(ReadUnicodeStringVirtualWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG MaxBytes,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringBytes
        ) PURE;

    STDMETHOD(ReadPhysical2)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WritePhysical2)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugEventCallbacks.
//
//----------------------------------------------------------------------------

// Interest mask bits.
#define DEBUG_EVENT_BREAKPOINT              0x00000001
#define DEBUG_EVENT_EXCEPTION               0x00000002
#define DEBUG_EVENT_CREATE_THREAD           0x00000004
#define DEBUG_EVENT_EXIT_THREAD             0x00000008
#define DEBUG_EVENT_CREATE_PROCESS          0x00000010
#define DEBUG_EVENT_EXIT_PROCESS            0x00000020
#define DEBUG_EVENT_LOAD_MODULE             0x00000040
#define DEBUG_EVENT_UNLOAD_MODULE           0x00000080
#define DEBUG_EVENT_SYSTEM_ERROR            0x00000100
#define DEBUG_EVENT_SESSION_STATUS          0x00000200
#define DEBUG_EVENT_CHANGE_DEBUGGEE_STATE   0x00000400
#define DEBUG_EVENT_CHANGE_ENGINE_STATE     0x00000800
#define DEBUG_EVENT_CHANGE_SYMBOL_STATE     0x00001000
#define DEBUG_EVENT_SERVICE_EXCEPTION       0x00002000

// SessionStatus flags.
// A debuggee has been discovered for the session.
#define DEBUG_SESSION_ACTIVE                       0x00000000
// The session has been ended by EndSession.
#define DEBUG_SESSION_END_SESSION_ACTIVE_TERMINATE 0x00000001
#define DEBUG_SESSION_END_SESSION_ACTIVE_DETACH    0x00000002
#define DEBUG_SESSION_END_SESSION_PASSIVE          0x00000003
// The debuggee has run to completion.  User-mode only.
#define DEBUG_SESSION_END                          0x00000004
// The target machine has rebooted.  Kernel-mode only.
#define DEBUG_SESSION_REBOOT                       0x00000005
// The target machine has hibernated.  Kernel-mode only.
#define DEBUG_SESSION_HIBERNATE                    0x00000006
// The engine was unable to continue the session.
#define DEBUG_SESSION_FAILURE                      0x00000007

// ChangeDebuggeeState flags.
// The debuggees state has changed generally, such
// as when the debuggee has been executing.
// Argument is zero.
#define DEBUG_CDS_ALL       0xffffffff
// Registers have changed.  If only a single register
// changed, argument is the index of the register.
// Otherwise it is DEBUG_ANY_ID.
#define DEBUG_CDS_REGISTERS 0x00000001
// Data spaces have changed.  If only a single
// space was affected, argument is the data
// space.  Otherwise it is DEBUG_ANY_ID.
#define DEBUG_CDS_DATA      0x00000002
// Inform the GUI clients to refresh debugger windows.
#define DEBUG_CDS_REFRESH   0x00000004

// DEBUG_CDS_REFRESH IDs
#define DEBUG_CDS_REFRESH_EVALUATE                  1
#define DEBUG_CDS_REFRESH_EXECUTE                   2
#define DEBUG_CDS_REFRESH_EXECUTECOMMANDFILE        3
#define DEBUG_CDS_REFRESH_ADDBREAKPOINT             4
#define DEBUG_CDS_REFRESH_REMOVEBREAKPOINT          5
#define DEBUG_CDS_REFRESH_WRITEVIRTUAL              6
#define DEBUG_CDS_REFRESH_WRITEVIRTUALUNCACHED      7
#define DEBUG_CDS_REFRESH_WRITEPHYSICAL             8
#define DEBUG_CDS_REFRESH_WRITEPHYSICAL2            9
#define DEBUG_CDS_REFRESH_SETVALUE                 10
#define DEBUG_CDS_REFRESH_SETVALUE2                11
#define DEBUG_CDS_REFRESH_SETSCOPE                 12
#define DEBUG_CDS_REFRESH_SETSCOPEFRAMEBYINDEX     13
#define DEBUG_CDS_REFRESH_SETSCOPEFROMJITDEBUGINFO 14
#define DEBUG_CDS_REFRESH_SETSCOPEFROMSTOREDEVENT  15
#define DEBUG_CDS_REFRESH_INLINESTEP               16
#define DEBUG_CDS_REFRESH_INLINESTEP_PSEUDO        17

// ChangeEngineState flags.
// The engine state has changed generally.
// Argument is zero.
#define DEBUG_CES_ALL                 0xffffffff
// Current thread changed.  This may imply a change
// of system and process also.  Argument is the ID of the new
// current thread or DEBUG_ANY_ID if no thread is current.
#define DEBUG_CES_CURRENT_THREAD      0x00000001
// Effective processor changed.  Argument is the
// new processor type.
#define DEBUG_CES_EFFECTIVE_PROCESSOR 0x00000002
// Breakpoints changed.  If only a single breakpoint
// changed, argument is the ID of the breakpoint.
// Otherwise it is DEBUG_ANY_ID.
#define DEBUG_CES_BREAKPOINTS         0x00000004
// Code interpretation level changed.  Argument is
// the new level.
#define DEBUG_CES_CODE_LEVEL          0x00000008
// Execution status changed.  Argument is the new
// execution status.
#define DEBUG_CES_EXECUTION_STATUS    0x00000010
// Engine options have changed.  Argument is the new
// options value.
#define DEBUG_CES_ENGINE_OPTIONS      0x00000020
// Log file information has changed.  Argument
// is TRUE if a log file was opened and FALSE if
// a log file was closed.
#define DEBUG_CES_LOG_FILE            0x00000040
// Default number radix has changed.  Argument
// is the new radix.
#define DEBUG_CES_RADIX               0x00000080
// Event filters changed.  If only a single filter
// changed the argument is the filter's index,
// otherwise it is DEBUG_ANY_ID.
#define DEBUG_CES_EVENT_FILTERS       0x00000100
// Process options have changed.  Argument is the new
// options value.
#define DEBUG_CES_PROCESS_OPTIONS     0x00000200
// Extensions have been added or removed.
#define DEBUG_CES_EXTENSIONS          0x00000400
// Systems have been added or removed.  The argument
// is the system ID.  Systems, unlike processes and
// threads, may be created at any time and not
// just during WaitForEvent.
#define DEBUG_CES_SYSTEMS             0x00000800
// Assembly/disassembly options have changed.  Argument
// is the new options value.
#define DEBUG_CES_ASSEMBLY_OPTIONS    0x00001000
// Expression syntax has changed.  Argument
// is the new syntax value.
#define DEBUG_CES_EXPRESSION_SYNTAX   0x00002000
// Text replacements have changed.
#define DEBUG_CES_TEXT_REPLACEMENTS   0x00004000

// ChangeSymbolState flags.
// Symbol state has changed generally, such
// as after reload operations.  Argument is zero.
#define DEBUG_CSS_ALL            0xffffffff
// Modules have been loaded.  If only a
// single module changed, argument is the
// base address of the module.  Otherwise
// it is zero.
#define DEBUG_CSS_LOADS          0x00000001
// Modules have been unloaded.  If only a
// single module changed, argument is the
// base address of the module.  Otherwise
// it is zero.
#define DEBUG_CSS_UNLOADS        0x00000002
// Current symbol scope changed.
#define DEBUG_CSS_SCOPE          0x00000004
// Paths have changed.
#define DEBUG_CSS_PATHS          0x00000008
// Symbol options have changed.  Argument is the new
// options value.
#define DEBUG_CSS_SYMBOL_OPTIONS 0x00000010
// Type options have changed.  Argument is the new
// options value.
#define DEBUG_CSS_TYPE_OPTIONS   0x00000020
// Inform that the current Scope Symbol format has been changed,
// so the client needs to update the symbols on Locals/Watch/..
// and the engine will collapse any expanded child
#define DEBUG_CSS_COLLAPSE_CHILDREN 0x00000040


#undef INTERFACE
#define INTERFACE IDebugEventCallbacks
DECLARE_INTERFACE_(IDebugEventCallbacks, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugEventCallbacks.

    // The engine calls GetInterestMask once when
    // the event callbacks are set for a client.
    STDMETHOD(GetInterestMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;

    // A breakpoint event is generated when
    // a breakpoint exception is received and
    // it can be mapped to an existing breakpoint.
    // The callback method is given a reference
    // to the breakpoint and should release it when
    // it is done with it.
    STDMETHOD(Breakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        ) PURE;

    // Exceptions include breaks which cannot
    // be mapped to an existing breakpoint
    // instance.
    STDMETHOD(Exception)(
        THIS_
        _In_ PEXCEPTION_RECORD64 Exception,
        _In_ ULONG FirstChance
        ) PURE;

    // Any of these values can be zero if they
    // cannot be provided by the engine.
    // Currently the kernel does not return thread
    // or process change events.
    STDMETHOD(CreateThread)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG64 DataOffset,
        _In_ ULONG64 StartOffset
        ) PURE;
    STDMETHOD(ExitThread)(
        THIS_
        _In_ ULONG ExitCode
        ) PURE;

    // Any of these values can be zero if they
    // cannot be provided by the engine.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 Handle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_opt_ PCSTR ModuleName,
        _In_opt_ PCSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp,
        _In_ ULONG64 InitialThreadHandle,
        _In_ ULONG64 ThreadDataOffset,
        _In_ ULONG64 StartOffset
        ) PURE;
    _Analysis_noreturn_
    STDMETHOD(ExitProcess)(
        THIS_
        _In_ ULONG ExitCode
        ) PURE;

    // Any of these values may be zero.
    STDMETHOD(LoadModule)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_opt_ PCSTR ModuleName,
        _In_opt_ PCSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp
        ) PURE;
    STDMETHOD(UnloadModule)(
        THIS_
        _In_opt_ PCSTR ImageBaseName,
        _In_ ULONG64 BaseOffset
        ) PURE;

    STDMETHOD(SystemError)(
        THIS_
        _In_ ULONG Error,
        _In_ ULONG Level
        ) PURE;

    // Session status is synchronous like the other
    // wait callbacks but it is called as the state
    // of the session is changing rather than at
    // specific events so its return value does not
    // influence waiting.  Implementations should just
    // return DEBUG_STATUS_NO_CHANGE.
    // Also, because some of the status
    // notifications are very early or very
    // late in the session lifetime there may not be
    // current processes or threads when the notification
    // is generated.
    STDMETHOD(SessionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // The following callbacks are informational
    // callbacks notifying the provider about
    // changes in debug state.  The return value
    // of these callbacks is ignored.  Implementations
    // can not call back into the engine.

    // Debuggee state, such as registers or data spaces,
    // has changed.
    STDMETHOD(ChangeDebuggeeState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        ) PURE;
    // Engine state has changed.
    STDMETHOD(ChangeEngineState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        ) PURE;
    // Symbol state has changed.
    STDMETHOD(ChangeSymbolState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugEventCallbacksWide
DECLARE_INTERFACE_(IDebugEventCallbacksWide, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugEventCallbacksWide.

    // The engine calls GetInterestMask once when
    // the event callbacks are set for a client.
    STDMETHOD(GetInterestMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;

    // A breakpoint event is generated when
    // a breakpoint exception is received and
    // it can be mapped to an existing breakpoint.
    // The callback method is given a reference
    // to the breakpoint and should release it when
    // it is done with it.
    STDMETHOD(Breakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT2 Bp
        ) PURE;

    // Exceptions include breaks which cannot
    // be mapped to an existing breakpoint
    // instance.
    STDMETHOD(Exception)(
        THIS_
        _In_ PEXCEPTION_RECORD64 Exception,
        _In_ ULONG FirstChance
        ) PURE;

    // Any of these values can be zero if they
    // cannot be provided by the engine.
    // Currently the kernel does not return thread
    // or process change events.
    STDMETHOD(CreateThread)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG64 DataOffset,
        _In_ ULONG64 StartOffset
        ) PURE;
    _Analysis_noreturn_
    STDMETHOD(ExitThread)(
        THIS_
        _In_ ULONG ExitCode
        ) PURE;

    // Any of these values can be zero if they
    // cannot be provided by the engine.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 Handle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_opt_ PCWSTR ModuleName,
        _In_opt_ PCWSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp,
        _In_ ULONG64 InitialThreadHandle,
        _In_ ULONG64 ThreadDataOffset,
        _In_ ULONG64 StartOffset
        ) PURE;
    STDMETHOD(ExitProcess)(
        THIS_
        _In_ ULONG ExitCode
        ) PURE;

    // Any of these values may be zero.
    STDMETHOD(LoadModule)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_opt_ PCWSTR ModuleName,
        _In_opt_ PCWSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp
        ) PURE;
    STDMETHOD(UnloadModule)(
        THIS_
        _In_opt_ PCWSTR ImageBaseName,
        _In_ ULONG64 BaseOffset
        ) PURE;

    STDMETHOD(SystemError)(
        THIS_
        _In_ ULONG Error,
        _In_ ULONG Level
        ) PURE;

    // Session status is synchronous like the other
    // wait callbacks but it is called as the state
    // of the session is changing rather than at
    // specific events so its return value does not
    // influence waiting.  Implementations should just
    // return DEBUG_STATUS_NO_CHANGE.
    // Also, because some of the status
    // notifications are very early or very
    // late in the session lifetime there may not be
    // current processes or threads when the notification
    // is generated.
    STDMETHOD(SessionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // The following callbacks are informational
    // callbacks notifying the provider about
    // changes in debug state.  The return value
    // of these callbacks is ignored.  Implementations
    // can not call back into the engine.

    // Debuggee state, such as registers or data spaces,
    // has changed.
    STDMETHOD(ChangeDebuggeeState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        ) PURE;
    // Engine state has changed.
    STDMETHOD(ChangeEngineState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        ) PURE;
    // Symbol state has changed.
    STDMETHOD(ChangeSymbolState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        ) PURE;
};

typedef struct _DEBUG_EVENT_CONTEXT
{
    ULONG Size;
    ULONG ProcessEngineId;
    ULONG ThreadEngineId;
    ULONG FrameEngineId;
} DEBUG_EVENT_CONTEXT, *PDEBUG_EVENT_CONTEXT;

#undef INTERFACE
#define INTERFACE IDebugEventContextCallbacks
DECLARE_INTERFACE_(IDebugEventContextCallbacks, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugEventContextCallbacks.

    // The engine calls GetInterestMask once when
    // the event callbacks are set for a client.
    STDMETHOD(GetInterestMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;

    // A breakpoint event is generated when
    // a breakpoint exception is received and
    // it can be mapped to an existing breakpoint.
    // The callback method is given a reference
    // to the breakpoint and should release it when
    // it is done with it.
    STDMETHOD(Breakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT2 Bp,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // Exceptions include breaks which cannot
    // be mapped to an existing breakpoint
    // instance.
    STDMETHOD(Exception)(
        THIS_
        _In_ PEXCEPTION_RECORD64 Exception,
        _In_ ULONG FirstChance,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // Any of these values can be zero if they
    // cannot be provided by the engine.
    // Currently the kernel does not return thread
    // or process change events.
    STDMETHOD(CreateThread)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG64 DataOffset,
        _In_ ULONG64 StartOffset,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    STDMETHOD(ExitThread)(
        THIS_
        _In_ ULONG ExitCode,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // Any of these values can be zero if they
    // cannot be provided by the engine.
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 Handle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_opt_ PCWSTR ModuleName,
        _In_opt_ PCWSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp,
        _In_ ULONG64 InitialThreadHandle,
        _In_ ULONG64 ThreadDataOffset,
        _In_ ULONG64 StartOffset,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    STDMETHOD(ExitProcess)(
        THIS_
        _In_ ULONG ExitCode,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // Any of these values may be zero.
    STDMETHOD(LoadModule)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_opt_ PCWSTR ModuleName,
        _In_opt_ PCWSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    STDMETHOD(UnloadModule)(
        THIS_
        _In_opt_ PCWSTR ImageBaseName,
        _In_ ULONG64 BaseOffset,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    STDMETHOD(SystemError)(
        THIS_
        _In_ ULONG Error,
        _In_ ULONG Level,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;

    // Session status is synchronous like the other
    // wait callbacks but it is called as the state
    // of the session is changing rather than at
    // specific events so its return value does not
    // influence waiting.  Implementations should just
    // return DEBUG_STATUS_NO_CHANGE.
    // Also, because some of the status
    // notifications are very early or very
    // late in the session lifetime there may not be
    // current processes or threads when the notification
    // is generated.
    STDMETHOD(SessionStatus)(
        THIS_
        _In_ ULONG Status
        ) PURE;

    // The following callbacks are informational
    // callbacks notifying the provider about
    // changes in debug state.  The return value
    // of these callbacks is ignored.  Implementations
    // can not call back into the engine.

    // Debuggee state, such as registers or data spaces,
    // has changed.
    STDMETHOD(ChangeDebuggeeState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    // Engine state has changed.
    STDMETHOD(ChangeEngineState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument,
        _In_reads_bytes_(ContextSize) PVOID Context,
        _In_ ULONG ContextSize
        ) PURE;
    // Symbol state has changed.
    STDMETHOD(ChangeSymbolState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugInputCallbacks.
//
//----------------------------------------------------------------------------

#undef INTERFACE
#define INTERFACE IDebugInputCallbacks
DECLARE_INTERFACE_(IDebugInputCallbacks, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugInputCallbacks.

    // A call to the StartInput method is a request for
    // a line of input from any client.  The returned input
    // should always be zero-terminated.  The buffer size
    // provided is only a guideline.  A client can return
    // more if necessary and the engine will truncate it
    // before returning from IDebugControl::Input.
    // The return value is ignored.
    STDMETHOD(StartInput)(
        THIS_
        _In_ ULONG BufferSize
        ) PURE;
    // The return value is ignored.
    STDMETHOD(EndInput)(
        THIS
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugOutputCallbacks.
//
//----------------------------------------------------------------------------

#undef INTERFACE
#define INTERFACE IDebugOutputCallbacks
DECLARE_INTERFACE_(IDebugOutputCallbacks, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugOutputCallbacks.

    // This method is only called if the supplied mask
    // is allowed by the clients output control.
    // The return value is ignored.
    STDMETHOD(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Text
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugOutputCallbacksWide
DECLARE_INTERFACE_(IDebugOutputCallbacksWide, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugOutputCallbacksWide.

    // This method is only called if the supplied mask
    // is allowed by the clients output control.
    // The return value is ignored.
    STDMETHOD(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCWSTR Text
        ) PURE;
};

//
// IDebugOutputCallbacks2 interest mask flags.
//

// Indicates that the callback wants notifications
// of all explicit flushes.
#define DEBUG_OUTCBI_EXPLICIT_FLUSH 0x00000001
// Indicates that the callback wants
// content in text form.
#define DEBUG_OUTCBI_TEXT           0x00000002
// Indicates that the callback wants
// content in markup form.
#define DEBUG_OUTCBI_DML            0x00000004

#define DEBUG_OUTCBI_ANY_FORMAT     0x00000006

//
// Different kinds of output callback notifications
// that can be sent to Output2.
//

// Plain text content, flags are below, argument is mask.
#define DEBUG_OUTCB_TEXT           0
// Debugger markup content, flags are below, argument is mask.
#define DEBUG_OUTCB_DML            1
// Notification of an explicit output flush, flags and argument are zero.
#define DEBUG_OUTCB_EXPLICIT_FLUSH 2

//
// Flags for various Output2 callbacks.
//

// The content string was followed by an
// explicit flush.  This flag will be used
// instead of a separate DEBUG_OUTCB_EXPLICIT_FLUSH
// callback when a flush has text to flush,
// thus avoiding two callbacks.
#define DEBUG_OUTCBF_COMBINED_EXPLICIT_FLUSH    0x00000001

// The markup content string has embedded tags.
#define DEBUG_OUTCBF_DML_HAS_TAGS               0x00000002
// The markup content has encoded special characters like ", &, < and >.
#define DEBUG_OUTCBF_DML_HAS_SPECIAL_CHARACTERS 0x00000004

#undef INTERFACE
#define INTERFACE IDebugOutputCallbacks2
DECLARE_INTERFACE_(IDebugOutputCallbacks2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugOutputCallbacks.

    // This method is not used.
    STDMETHOD(Output)(
        THIS_
        _In_ ULONG Mask,
        _In_ PCSTR Text
        ) PURE;

    // IDebugOutputCallbacks2.

    // The engine calls GetInterestMask once when
    // the callbacks are set for a client.
    STDMETHOD(GetInterestMask)(
        THIS_
        _Out_ PULONG Mask
        ) PURE;

    STDMETHOD(Output2)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Flags,
        _In_ ULONG64 Arg,
        _In_opt_ PCWSTR Text
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugRegisters.
//
//----------------------------------------------------------------------------

#define DEBUG_REGISTERS_DEFAULT 0x00000000
#define DEBUG_REGISTERS_INT32   0x00000001
#define DEBUG_REGISTERS_INT64   0x00000002
#define DEBUG_REGISTERS_FLOAT   0x00000004
#define DEBUG_REGISTERS_ALL     0x00000007

#define DEBUG_REGISTER_SUB_REGISTER 0x00000001

typedef struct _DEBUG_REGISTER_DESCRIPTION
{
    // DEBUG_VALUE type.
    ULONG Type;
    ULONG Flags;

    // If this is a subregister the full
    // registers description index is
    // given in SubregMaster.  The length, mask
    // and shift describe how the subregisters
    // bits fit into the full register.
    ULONG SubregMaster;
    ULONG SubregLength;
    ULONG64 SubregMask;
    ULONG SubregShift;

    ULONG Reserved0;
} DEBUG_REGISTER_DESCRIPTION, *PDEBUG_REGISTER_DESCRIPTION;

#undef INTERFACE
#define INTERFACE IDebugRegisters
DECLARE_INTERFACE_(IDebugRegisters, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugRegisters.
    STDMETHOD(GetNumberRegisters)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDescription)(
        THIS_
        _In_ ULONG Register,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PDEBUG_REGISTER_DESCRIPTION Desc
        ) PURE;
    STDMETHOD(GetIndexByName)(
        THIS_
        _In_ PCSTR Name,
        _Out_ PULONG Index
        ) PURE;

    STDMETHOD(GetValue)(
        THIS_
        _In_ ULONG Register,
        _Out_ PDEBUG_VALUE Value
        ) PURE;
    // SetValue makes a best effort at coercing
    // the given value into the given registers
    // value type.  If the given value is larger
    // than the register can hold the least
    // significant bits will be dropped.  Float
    // to int and int to float will be done
    // if necessary.  Subregister bits will be
    // inserted into the master register.
    STDMETHOD(SetValue)(
        THIS_
        _In_ ULONG Register,
        _In_ PDEBUG_VALUE Value
        ) PURE;
    // Gets Count register values.  If Indices is
    // non-NULL it must contain Count register
    // indices which control the registers affected.
    // If Indices is NULL the registers from Start
    // to Start + Count  1 are retrieved.
    STDMETHOD(GetValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_VALUE Values
        ) PURE;
    STDMETHOD(SetValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _In_reads_(Count) PDEBUG_VALUE Values
        ) PURE;

    // Outputs a group of registers in a well-formatted
    // way thats specific to the platforms register set.
    // Uses the line prefix.
    STDMETHOD(OutputRegisters)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Abstracted pieces of processor information.
    // The mapping of these values to architectural
    // registers is architecture-specific and their
    // interpretation and existence may vary.  They
    // are intended to be directly compatible with
    // calls which take this information, such as
    // stack walking.
    STDMETHOD(GetInstructionOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetStackOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetFrameOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
};

//
// The engine maintains several separate
// pieces of context information.  There is
// the current debuggee context, a possible
// override context, such as from .cxr,
// a context for the current scope frame and so on.
//

// Get register information from the debuggee.
#define DEBUG_REGSRC_DEBUGGEE 0x00000000
// Get register information from an explicit
// override context, such as one set by .cxr.
// If there is no override context the request will fail.
#define DEBUG_REGSRC_EXPLICIT 0x00000001
// Get register information from the current scope
// frame.  Note that stack unwinding does not guarantee
// accurate updating of the register context,
// so scope frame register context may not be accurate
// in all cases.
#define DEBUG_REGSRC_FRAME    0x00000002

#undef INTERFACE
#define INTERFACE IDebugRegisters2
DECLARE_INTERFACE_(IDebugRegisters2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugRegisters.

    STDMETHOD(GetNumberRegisters)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetDescription)(
        THIS_
        _In_ ULONG Register,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PDEBUG_REGISTER_DESCRIPTION Desc
        ) PURE;
    STDMETHOD(GetIndexByName)(
        THIS_
        _In_ PCSTR Name,
        _Out_ PULONG Index
        ) PURE;

    STDMETHOD(GetValue)(
        THIS_
        _In_ ULONG Register,
        _Out_ PDEBUG_VALUE Value
        ) PURE;
    // SetValue makes a best effort at coercing
    // the given value into the given registers
    // value type.  If the given value is larger
    // than the register can hold the least
    // significant bits will be dropped.  Float
    // to int and int to float will be done
    // if necessary.  Subregister bits will be
    // inserted into the master register.
    STDMETHOD(SetValue)(
        THIS_
        _In_ ULONG Register,
        _In_ PDEBUG_VALUE Value
        ) PURE;
    // Gets Count register values.  If Indices is
    // non-NULL it must contain Count register
    // indices which control the registers affected.
    // If Indices is NULL the registers from Start
    // to Start + Count  1 are retrieved.
    STDMETHOD(GetValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_VALUE Values
        ) PURE;
    STDMETHOD(SetValues)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _In_reads_(Count) PDEBUG_VALUE Values
        ) PURE;

    // Outputs a group of registers in a well-formatted
    // way thats specific to the platforms register set.
    // Uses the line prefix.
    STDMETHOD(OutputRegisters)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags
        ) PURE;

    // Abstracted pieces of processor information.
    // The mapping of these values to architectural
    // registers is architecture-specific and their
    // interpretation and existence may vary.  They
    // are intended to be directly compatible with
    // calls which take this information, such as
    // stack walking.
    STDMETHOD(GetInstructionOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetStackOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetFrameOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;

    // IDebugRegisters2.

    STDMETHOD(GetDescriptionWide)(
        THIS_
        _In_ ULONG Register,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PDEBUG_REGISTER_DESCRIPTION Desc
        ) PURE;
    STDMETHOD(GetIndexByNameWide)(
        THIS_
        _In_ PCWSTR Name,
        _Out_ PULONG Index
        ) PURE;

    // Pseudo-registers are synthetic values derived
    // by the engine that are presented in a manner
    // similar to regular registers.  They are simple
    // value holders, similar to actual registers.
    // Pseudo-registers are defined for concepts,
    // such as current-instruction-pointer or
    // current-thread-data.  As such they have
    // types appropriate for their data.
    STDMETHOD(GetNumberPseudoRegisters)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetPseudoDescription)(
        THIS_
        _In_ ULONG Register,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 TypeModule,
        _Out_opt_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetPseudoDescriptionWide)(
        THIS_
        _In_ ULONG Register,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 TypeModule,
        _Out_opt_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetPseudoIndexByName)(
        THIS_
        _In_ PCSTR Name,
        _Out_ PULONG Index
        ) PURE;
    STDMETHOD(GetPseudoIndexByNameWide)(
        THIS_
        _In_ PCWSTR Name,
        _Out_ PULONG Index
        ) PURE;
    // Some pseudo-register values are affected
    // by the register source, others are not.
    STDMETHOD(GetPseudoValues)(
        THIS_
        _In_ ULONG Source,
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_VALUE Values
        ) PURE;
    // Many pseudo-registers are read-only and cannot be set.
    STDMETHOD(SetPseudoValues)(
        THIS_
        _In_ ULONG Source,
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _In_reads_(Count) PDEBUG_VALUE Values
        ) PURE;

    // These expanded methods allow selection
    // of the source of register information.
    STDMETHOD(GetValues2)(
        THIS_
        _In_ ULONG Source,
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_VALUE Values
        ) PURE;
    STDMETHOD(SetValues2)(
        THIS_
        _In_ ULONG Source,
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG Indices,
        _In_ ULONG Start,
        _In_reads_(Count) PDEBUG_VALUE Values
        ) PURE;
    STDMETHOD(OutputRegisters2)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Source,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(GetInstructionOffset2)(
        THIS_
        _In_ ULONG Source,
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetStackOffset2)(
        THIS_
        _In_ ULONG Source,
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetFrameOffset2)(
        THIS_
        _In_ ULONG Source,
        _Out_ PULONG64 Offset
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugSymbolGroup
//
//----------------------------------------------------------------------------

// OutputSymbols flags.
// Default output contains
//   <Name>**NAME**<Offset>**OFF**<Value>**VALUE**<Type>**TYPE**
// per symbol.
#define DEBUG_OUTPUT_SYMBOLS_DEFAULT    0x00000000
#define DEBUG_OUTPUT_SYMBOLS_NO_NAMES   0x00000001
#define DEBUG_OUTPUT_SYMBOLS_NO_OFFSETS 0x00000002
#define DEBUG_OUTPUT_SYMBOLS_NO_VALUES  0x00000004
#define DEBUG_OUTPUT_SYMBOLS_NO_TYPES   0x00000010

#define DEBUG_OUTPUT_NAME_END           "**NAME**"
#define DEBUG_OUTPUT_OFFSET_END         "**OFF**"
#define DEBUG_OUTPUT_VALUE_END          "**VALUE**"
#define DEBUG_OUTPUT_TYPE_END           "**TYPE**"

#define DEBUG_OUTPUT_NAME_END_WIDE      L"**NAME**"
#define DEBUG_OUTPUT_OFFSET_END_WIDE    L"**OFF**"
#define DEBUG_OUTPUT_VALUE_END_WIDE     L"**VALUE**"
#define DEBUG_OUTPUT_TYPE_END_WIDE      L"**TYPE**"

#ifdef UNICODE
#define DEBUG_OUTPUT_NAME_END_T DEBUG_OUTPUT_NAME_END_WIDE
#define DEBUG_OUTPUT_OFFSET_END_T DEBUG_OUTPUT_OFFSET_END_WIDE
#define DEBUG_OUTPUT_VALUE_END_T DEBUG_OUTPUT_VALUE_END_WIDE
#define DEBUG_OUTPUT_TYPE_END_T DEBUG_OUTPUT_TYPE_END_WIDE
#else
#define DEBUG_OUTPUT_NAME_END_T DEBUG_OUTPUT_NAME_END
#define DEBUG_OUTPUT_OFFSET_END_T DEBUG_OUTPUT_OFFSET_END
#define DEBUG_OUTPUT_VALUE_END_T DEBUG_OUTPUT_VALUE_END
#define DEBUG_OUTPUT_TYPE_END_T DEBUG_OUTPUT_TYPE_END
#endif

// DEBUG_SYMBOL_PARAMETERS flags.
// Cumulative expansion level, takes four bits.
#define DEBUG_SYMBOL_EXPANSION_LEVEL_MASK 0x0000000f
// Symbols subelements follow.
#define DEBUG_SYMBOL_EXPANDED             0x00000010
// Symbols value is read-only.
#define DEBUG_SYMBOL_READ_ONLY            0x00000020
// Symbol subelements are array elements.
#define DEBUG_SYMBOL_IS_ARRAY             0x00000040
// Symbol is a float value.
#define DEBUG_SYMBOL_IS_FLOAT             0x00000080
// Symbol is a scope argument.
#define DEBUG_SYMBOL_IS_ARGUMENT          0x00000100
// Symbol is a scope argument.
#define DEBUG_SYMBOL_IS_LOCAL             0x00000200

typedef struct _DEBUG_SYMBOL_PARAMETERS
{
    ULONG64 Module;
    ULONG TypeId;
    // ParentSymbol may be DEBUG_ANY_ID when unknown.
    ULONG ParentSymbol;
    // A subelement of a symbol can be a field, such
    // as in structs, unions or classes; or an array
    // element count for arrays.
    ULONG SubElements;
    ULONG Flags;
    ULONG64 Reserved;
} DEBUG_SYMBOL_PARAMETERS, *PDEBUG_SYMBOL_PARAMETERS;

#undef INTERFACE
#define INTERFACE IDebugSymbolGroup
DECLARE_INTERFACE_(IDebugSymbolGroup, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSymbolGroup.
    STDMETHOD(GetNumberSymbols)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // On input Index indicates the desired insertion
    // index.  On output Index contains the actual index.
    // Use DEBUG_ANY_ID to append a symbol to the end.
    STDMETHOD(AddSymbol)(
        THIS_
        _In_ PCSTR Name,
        _Inout_ PULONG Index
        ) PURE;
    STDMETHOD(RemoveSymbolByName)(
        THIS_
        _In_ PCSTR Name
        ) PURE;
    STDMETHOD(RemoveSymbolByIndex)(
        THIS_
        _In_ ULONG Index
        ) PURE;
    STDMETHOD(GetSymbolName)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    STDMETHOD(GetSymbolParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SYMBOL_PARAMETERS Params
        ) PURE;
    STDMETHOD(ExpandSymbol)(
        THIS_
        _In_ ULONG Index,
        _In_ BOOL Expand
        ) PURE;
    // Uses the line prefix.
    STDMETHOD(OutputSymbols)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ ULONG Start,
        _In_ ULONG Count
        ) PURE;
    STDMETHOD(WriteSymbol)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Value
        ) PURE;
    STDMETHOD(OutputAsType)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Type
        ) PURE;
};

#define DEBUG_SYMENT_IS_CODE      0x00000001
#define DEBUG_SYMENT_IS_DATA      0x00000002
#define DEBUG_SYMENT_IS_PARAMETER 0x00000004
#define DEBUG_SYMENT_IS_LOCAL     0x00000008
#define DEBUG_SYMENT_IS_MANAGED   0x00000010
#define DEBUG_SYMENT_IS_SYNTHETIC 0x00000020

typedef struct _DEBUG_SYMBOL_ENTRY
{
    ULONG64 ModuleBase;
    ULONG64 Offset;
    ULONG64 Id;
    ULONG64 Arg64;
    ULONG Size;
    ULONG Flags;
    ULONG TypeId;
    ULONG NameSize;
    ULONG Token;
    ULONG Tag;
    ULONG Arg32;
    ULONG Reserved;
} DEBUG_SYMBOL_ENTRY, *PDEBUG_SYMBOL_ENTRY;

#undef INTERFACE
#define INTERFACE IDebugSymbolGroup2
DECLARE_INTERFACE_(IDebugSymbolGroup2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSymbolGroup.

    STDMETHOD(GetNumberSymbols)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // On input Index indicates the desired insertion
    // index.  On output Index contains the actual index.
    // Use DEBUG_ANY_ID to append a symbol to the end.
    STDMETHOD(AddSymbol)(
        THIS_
        _In_ PCSTR Name,
        _Inout_ PULONG Index
        ) PURE;
    STDMETHOD(RemoveSymbolByName)(
        THIS_
        _In_ PCSTR Name
        ) PURE;
    STDMETHOD(RemoveSymbolByIndex)(
        THIS_
        _In_ ULONG Index
        ) PURE;
    STDMETHOD(GetSymbolName)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    STDMETHOD(GetSymbolParameters)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PDEBUG_SYMBOL_PARAMETERS Params
        ) PURE;
    STDMETHOD(ExpandSymbol)(
        THIS_
        _In_ ULONG Index,
        _In_ BOOL Expand
        ) PURE;
    // Uses the line prefix.
    STDMETHOD(OutputSymbols)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ ULONG Start,
        _In_ ULONG Count
        ) PURE;
    STDMETHOD(WriteSymbol)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Value
        ) PURE;
    STDMETHOD(OutputAsType)(
        THIS_
        _In_ ULONG Index,
        _In_ PCSTR Type
        ) PURE;

    // IDebugSymbolGroup2.

    STDMETHOD(AddSymbolWide)(
        THIS_
        _In_ PCWSTR Name,
        _Inout_ PULONG Index
        ) PURE;
    STDMETHOD(RemoveSymbolByNameWide)(
        THIS_
        _In_ PCWSTR Name
        ) PURE;
    STDMETHOD(GetSymbolNameWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    STDMETHOD(WriteSymbolWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Value
        ) PURE;
    STDMETHOD(OutputAsTypeWide)(
        THIS_
        _In_ ULONG Index,
        _In_ PCWSTR Type
        ) PURE;

    STDMETHOD(GetSymbolTypeName)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    STDMETHOD(GetSymbolTypeNameWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    STDMETHOD(GetSymbolSize)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG Size
        ) PURE;
    // If the symbol has an absolute address
    // this method will retrieve it.
    STDMETHOD(GetSymbolOffset)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG64 Offset
        ) PURE;
    // If the symbol is enregistered this
    // method will return the register index.
    STDMETHOD(GetSymbolRegister)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG Register
        ) PURE;
    STDMETHOD(GetSymbolValueText)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    STDMETHOD(GetSymbolValueTextWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    STDMETHOD(GetSymbolEntryInformation)(
        THIS_
        _In_ ULONG Index,
        _Out_ PDEBUG_SYMBOL_ENTRY Entry
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugSymbols.
//
//----------------------------------------------------------------------------

//
// Information about a module.
//

// Flags.
#define DEBUG_MODULE_LOADED            0x00000000
#define DEBUG_MODULE_UNLOADED          0x00000001
#define DEBUG_MODULE_USER_MODE         0x00000002
#define DEBUG_MODULE_EXE_MODULE        0x00000004
#define DEBUG_MODULE_EXPLICIT          0x00000008
#define DEBUG_MODULE_SECONDARY         0x00000010
#define DEBUG_MODULE_SYNTHETIC         0x00000020
#define DEBUG_MODULE_SYM_BAD_CHECKSUM  0x00010000

// Symbol types.
#define DEBUG_SYMTYPE_NONE     0
#define DEBUG_SYMTYPE_COFF     1
#define DEBUG_SYMTYPE_CODEVIEW 2
#define DEBUG_SYMTYPE_PDB      3
#define DEBUG_SYMTYPE_EXPORT   4
#define DEBUG_SYMTYPE_DEFERRED 5
#define DEBUG_SYMTYPE_SYM      6
#define DEBUG_SYMTYPE_DIA      7

typedef struct _DEBUG_MODULE_PARAMETERS
{
    ULONG64 Base;
    ULONG Size;
    ULONG TimeDateStamp;
    ULONG Checksum;
    ULONG Flags;
    ULONG SymbolType;
    ULONG ImageNameSize;
    ULONG ModuleNameSize;
    ULONG LoadedImageNameSize;
    ULONG SymbolFileNameSize;
    ULONG MappedImageNameSize;
    ULONG64 Reserved[2];
} DEBUG_MODULE_PARAMETERS, *PDEBUG_MODULE_PARAMETERS;

// Scope arguments are function arguments
// and thus only change when the scope
// crosses functions.
#define DEBUG_SCOPE_GROUP_ARGUMENTS    0x00000001
// Scope locals are locals declared in a particular
// scope and are only defined within that scope.
#define DEBUG_SCOPE_GROUP_LOCALS       0x00000002
// All symbols in the scope.
#define DEBUG_SCOPE_GROUP_ALL          0x00000003
// Get Debug Symbols by using Data Model engine
#define DEBUG_SCOPE_GROUP_BY_DATAMODEL 0x00000004
// Valid flags for the set of DEBUG_SCOPE_GROUP
// If you add a new flag, then please add it to DEBUG_SCOPE_GROUP_VALID_FLAGS
#define DEBUG_SCOPE_GROUP_VALID_FLAGS (DEBUG_SCOPE_GROUP_ALL | DEBUG_SCOPE_GROUP_BY_DATAMODEL)


// Typed data output control flags.
#define DEBUG_OUTTYPE_DEFAULT              0x00000000
#define DEBUG_OUTTYPE_NO_INDENT            0x00000001
#define DEBUG_OUTTYPE_NO_OFFSET            0x00000002
#define DEBUG_OUTTYPE_VERBOSE              0x00000004
#define DEBUG_OUTTYPE_COMPACT_OUTPUT       0x00000008
#define DEBUG_OUTTYPE_RECURSION_LEVEL(Max) (((Max) & 0xf) << 4)
#define DEBUG_OUTTYPE_ADDRESS_OF_FIELD     0x00010000
#define DEBUG_OUTTYPE_ADDRESS_AT_END       0x00020000
#define DEBUG_OUTTYPE_BLOCK_RECURSE        0x00200000

// FindSourceFile flags.
#define DEBUG_FIND_SOURCE_DEFAULT      0x00000000
// Returns fully-qualified paths only.  If this
// is not set the path returned may be relative.
#define DEBUG_FIND_SOURCE_FULL_PATH    0x00000001
// Scans all the path elements for a match and
// returns the one that has the most similarity
// between the given file and the matching element.
#define DEBUG_FIND_SOURCE_BEST_MATCH   0x00000002
// Do not search source server paths.
#define DEBUG_FIND_SOURCE_NO_SRCSRV    0x00000004
// Restrict FindSourceFileAndToken to token lookup only.
#define DEBUG_FIND_SOURCE_TOKEN_LOOKUP 0x00000008
// Indicates that the FileToken/FileTokenSize arguments refer to the checksum
// information for the source file obtained from a call to the
// GetSourceFileInformation method with the 'Which' parameter
// set to DEBUG_SRCFILE_SYMBOL_CHECKSUMINFO
#define DEBUG_FIND_SOURCE_WITH_CHECKSUM 0x00000010
// This option is similar to DEBUG_FIND_SOURCE_WITH_CHECKSUM.
// The only difference is that DEBUG_SRCFILE_SYMBOL_CHECKSUMINFO will check
// for a checksum but won't enforce it i.e. if a file is found it may or may not
// match the requested checksum.
// DEBUG_FIND_SOURCE_WITH_CHECKSUM_STRICT eliminates this ambiguity i.e.
// if the file is found for sure it matches the checksum.
// Please note that line endings of the file may change when downloading
// a source file from various source code repositories. This means that the downloaded file
// would have a checksum which depends on file content and the updated line endings.
// The engine will try to match the checksum of the file to the requested checksum.
// If they don't match, the engine will calculate an alternative checksum
// of the file with modified line endings and will try to match it to the requested checksum.
// In summary: DEBUG_FIND_SOURCE_WITH_CHECKSUM_STRICT will return a file if its checksum matches
// to the requested checksum, or if the file's checksum calculated based on updated line endings
// matches the requested checksum.
#define DEBUG_FIND_SOURCE_WITH_CHECKSUM_STRICT 0x00000020


// A special value marking an offset that should not
// be treated as a valid offset.  This is only used
// in special situations where it is unlikely that
// this value would be a valid offset.
#define DEBUG_INVALID_OFFSET ((ULONG64)-1)

// Module index sort order used by GetModuleByIndex() API.
#define MODULE_ORDERS_MASK       0xF0000000
#define MODULE_ORDERS_LOADTIME   0x10000000
#define MODULE_ORDERS_MODULENAME 0x20000000

#undef INTERFACE
#define INTERFACE IDebugSymbols
DECLARE_INTERFACE_(IDebugSymbols, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
    STDMETHOD(GetSymbolOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    STDMETHOD(GetNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
    STDMETHOD(GetOffsetByName)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
    STDMETHOD(GetNearNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
    STDMETHOD(GetNumberModules)(
        THIS_
        _Out_ PULONG Loaded,
        _Out_ PULONG Unloaded
        ) PURE;
    STDMETHOD(GetModuleByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG64 Base
        ) PURE;
    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    STDMETHOD(GetModuleNames)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(ImageNameBufferSize) PSTR ImageNameBuffer,
        _In_ ULONG ImageNameBufferSize,
        _Out_opt_ PULONG ImageNameSize,
        _Out_writes_opt_(ModuleNameBufferSize) PSTR ModuleNameBuffer,
        _In_ ULONG ModuleNameBufferSize,
        _Out_opt_ PULONG ModuleNameSize,
        _Out_writes_opt_(LoadedImageNameBufferSize) PSTR LoadedImageNameBuffer,
        _In_ ULONG LoadedImageNameBufferSize,
        _Out_opt_ PULONG LoadedImageNameSize
        ) PURE;
    STDMETHOD(GetModuleParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG64 Bases,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_MODULE_PARAMETERS Params
        ) PURE;
    // Looks up the module from a <Module>!<Symbol>
    // string.
    STDMETHOD(GetSymbolModule)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    // Returns the string name of a type.
    STDMETHOD(GetTypeName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeId)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetTypeSize)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_ PULONG Size
        ) PURE;
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeId)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
    STDMETHOD(GetOffsetTypeId)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
    STDMETHOD(ReadTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataVirtual)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ReadTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataPhysical)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;

    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
    STDMETHOD(GetScope)(
        THIS_
        _Out_opt_ PULONG64 InstructionOffset,
        _Out_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _Out_writes_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
    STDMETHOD(SetScope)(
        THIS_
        _In_ ULONG64 InstructionOffset,
        _In_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _In_reads_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
    STDMETHOD(ResetScope)(
        THIS
        ) PURE;
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
    STDMETHOD(GetScopeSymbolGroup)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP Update,
        _Out_ PDEBUG_SYMBOL_GROUP* Symbols
        ) PURE;

    // Create a new symbol group.
    STDMETHOD(CreateSymbolGroup)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP* Group
        ) PURE;

    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
    STDMETHOD(StartSymbolMatch)(
        THIS_
        _In_ PCSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Buffer is NULL the match does not
    // advance.
    STDMETHOD(GetNextSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;
    STDMETHOD(EndSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Reload)(
        THIS_
        _In_ PCSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
    STDMETHOD(GetImagePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendImagePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Path routines for source file location
    // methods.
    STDMETHOD(GetSourcePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    // Gets the nth part of the source path.
    STDMETHOD(GetSourcePathElement)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
    STDMETHOD(FindSourceFile)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
    STDMETHOD(GetSourceFileLineOffsets)(
        THIS_
        _In_ PCSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;
};

//
// GetModuleNameString strings.
//

#define DEBUG_MODNAME_IMAGE        0x00000000
#define DEBUG_MODNAME_MODULE       0x00000001
#define DEBUG_MODNAME_LOADED_IMAGE 0x00000002
#define DEBUG_MODNAME_SYMBOL_FILE  0x00000003
#define DEBUG_MODNAME_MAPPED_IMAGE 0x00000004

//
// Type options, used with Get/SetTypeOptions.
//

// Display PUSHORT and USHORT arrays in Unicode.
#define DEBUG_TYPEOPTS_UNICODE_DISPLAY    0x00000001
// Display LONG types in default base instead of decimal.
#define DEBUG_TYPEOPTS_LONGSTATUS_DISPLAY 0x00000002
// Display integer types in default base instead of decimal.
#define DEBUG_TYPEOPTS_FORCERADIX_OUTPUT  0x00000004
// Search for the type/symbol with largest size when
// multiple type/symbol match for a given name
#define DEBUG_TYPEOPTS_MATCH_MAXSIZE      0x00000008

#undef INTERFACE
#define INTERFACE IDebugSymbols2
DECLARE_INTERFACE_(IDebugSymbols2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
    STDMETHOD(GetSymbolOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    STDMETHOD(GetNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
    STDMETHOD(GetOffsetByName)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
    STDMETHOD(GetNearNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
    STDMETHOD(GetNumberModules)(
        THIS_
        _Out_ PULONG Loaded,
        _Out_ PULONG Unloaded
        ) PURE;
    STDMETHOD(GetModuleByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG64 Base
        ) PURE;
    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    STDMETHOD(GetModuleNames)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(ImageNameBufferSize) PSTR ImageNameBuffer,
        _In_ ULONG ImageNameBufferSize,
        _Out_opt_ PULONG ImageNameSize,
        _Out_writes_opt_(ModuleNameBufferSize) PSTR ModuleNameBuffer,
        _In_ ULONG ModuleNameBufferSize,
        _Out_opt_ PULONG ModuleNameSize,
        _Out_writes_opt_(LoadedImageNameBufferSize) PSTR LoadedImageNameBuffer,
        _In_ ULONG LoadedImageNameBufferSize,
        _Out_opt_ PULONG LoadedImageNameSize
        ) PURE;
    STDMETHOD(GetModuleParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG64 Bases,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_MODULE_PARAMETERS Params
        ) PURE;
    // Looks up the module from a <Module>!<Symbol>
    // string.
    STDMETHOD(GetSymbolModule)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    // Returns the string name of a type.
    STDMETHOD(GetTypeName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeId)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetTypeSize)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_ PULONG Size
        ) PURE;
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeId)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
    STDMETHOD(GetOffsetTypeId)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
    STDMETHOD(ReadTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataVirtual)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ReadTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataPhysical)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;

    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
    STDMETHOD(GetScope)(
        THIS_
        _Out_opt_ PULONG64 InstructionOffset,
        _Out_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _Out_writes_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
    STDMETHOD(SetScope)(
        THIS_
        _In_ ULONG64 InstructionOffset,
        _In_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _In_reads_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
    STDMETHOD(ResetScope)(
        THIS
        ) PURE;
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
    STDMETHOD(GetScopeSymbolGroup)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP Update,
        _Out_ PDEBUG_SYMBOL_GROUP* Symbols
        ) PURE;

    // Create a new symbol group.
    STDMETHOD(CreateSymbolGroup)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP* Group
        ) PURE;

    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
    STDMETHOD(StartSymbolMatch)(
        THIS_
        _In_ PCSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Buffer is NULL the match does not
    // advance.
    STDMETHOD(GetNextSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;
    STDMETHOD(EndSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Reload)(
        THIS_
        _In_ PCSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
    STDMETHOD(GetImagePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendImagePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Path routines for source file location
    // methods.
    STDMETHOD(GetSourcePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    // Gets the nth part of the source path.
    STDMETHOD(GetSourcePathElement)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
    STDMETHOD(FindSourceFile)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
    STDMETHOD(GetSourceFileLineOffsets)(
        THIS_
        _In_ PCSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;

    // IDebugSymbols2.

    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // Item is specified as in VerQueryValue.
    // Module version information is only
    // available for loaded modules and may
    // not be available in all debug sessions.
    STDMETHOD(GetModuleVersionInformation)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _In_ PCSTR Item,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG VerInfoSize
        ) PURE;
    // Retrieves any available module name string
    // such as module name or symbol file name.
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // If symbols are deferred an error will
    // be returned.
    // E_NOINTERFACE may be returned, indicating
    // no information exists.
    STDMETHOD(GetModuleNameString)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Returns the string name of a constant type.
    STDMETHOD(GetConstantName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG64 Value,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Gets name of a field in a struct
    // FieldNumber is 0 based index of field in a struct
    STDMETHOD(GetFieldName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG FieldIndex,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Control options for typed values.
    STDMETHOD(GetTypeOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
};

//
// GetModuleBy* flags.
//

// Scan all modules, loaded and unloaded.
#define DEBUG_GETMOD_DEFAULT             0x00000000
// Do not scan loaded modules.
#define DEBUG_GETMOD_NO_LOADED_MODULES   0x00000001
// Do not scan unloaded modules.
#define DEBUG_GETMOD_NO_UNLOADED_MODULES 0x00000002

//
// AddSyntheticModule flags.
//
#define DEBUG_ADDSYNTHMOD_DEFAULT  0x00000000
#define DEBUG_ADDSYNTHMOD_ZEROBASE 0x00000001

//
// AddSyntheticSymbol flags.
//

#define DEBUG_ADDSYNTHSYM_DEFAULT 0x00000000

//
// OutputSymbolByOffset flags.
//

// Use the current debugger settings for symbol output.
#define DEBUG_OUTSYM_DEFAULT            0x00000000
// Always display the offset in addition to any symbol hit.
#define DEBUG_OUTSYM_FORCE_OFFSET       0x00000001
// Display source line information if found.
#define DEBUG_OUTSYM_SOURCE_LINE        0x00000002
// Output symbol hits that don't exactly match.
#define DEBUG_OUTSYM_ALLOW_DISPLACEMENT 0x00000004

//
// GetFunctionEntryByOffset flags.
//

#define DEBUG_GETFNENT_DEFAULT        0x00000000
// The engine provides artificial entries for well-known
// cases.  This flag limits the entry search to only
// the raw entries and disables artificial entry lookup.
#define DEBUG_GETFNENT_RAW_ENTRY_ONLY 0x00000001

typedef struct _DEBUG_MODULE_AND_ID
{
    ULONG64 ModuleBase;
    ULONG64 Id;
} DEBUG_MODULE_AND_ID, *PDEBUG_MODULE_AND_ID;

#define DEBUG_SOURCE_IS_STATEMENT 0x00000001

//
// GetSourceEntriesByLine flags.
//

#define DEBUG_GSEL_DEFAULT         0x00000000
// Do not allow any extra symbols to load during the search.
#define DEBUG_GSEL_NO_SYMBOL_LOADS 0x00000001
// Allow source hits with lower line numbers.
#define DEBUG_GSEL_ALLOW_LOWER     0x00000002
// Allow source hits with higher line numbers.
#define DEBUG_GSEL_ALLOW_HIGHER    0x00000004
// Only return the nearest hits.
#define DEBUG_GSEL_NEAREST_ONLY    0x00000008
// Only return caller sites of the inline function
#define DEBUG_GSEL_INLINE_CALLSITE 0x00000010

typedef struct _DEBUG_SYMBOL_SOURCE_ENTRY
{
    ULONG64 ModuleBase;
    ULONG64 Offset;
    ULONG64 FileNameId;
    ULONG64 EngineInternal;
    ULONG Size;
    ULONG Flags;
    ULONG FileNameSize;
    // Line numbers are one-based.
    // May be DEBUG_ANY_ID if unknown.
    ULONG StartLine;
    ULONG EndLine;
    // Column numbers are one-based byte indices.
    // May be DEBUG_ANY_ID if unknown.
    ULONG StartColumn;
    ULONG EndColumn;
    ULONG Reserved;
} DEBUG_SYMBOL_SOURCE_ENTRY, *PDEBUG_SYMBOL_SOURCE_ENTRY;

#undef INTERFACE
#define INTERFACE IDebugSymbols3
DECLARE_INTERFACE_(IDebugSymbols3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
    STDMETHOD(GetSymbolOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    STDMETHOD(GetNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
    STDMETHOD(GetOffsetByName)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
    STDMETHOD(GetNearNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
    STDMETHOD(GetNumberModules)(
        THIS_
        _Out_ PULONG Loaded,
        _Out_ PULONG Unloaded
        ) PURE;
    STDMETHOD(GetModuleByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG64 Base
        ) PURE;
    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    STDMETHOD(GetModuleNames)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(ImageNameBufferSize) PSTR ImageNameBuffer,
        _In_ ULONG ImageNameBufferSize,
        _Out_opt_ PULONG ImageNameSize,
        _Out_writes_opt_(ModuleNameBufferSize) PSTR ModuleNameBuffer,
        _In_ ULONG ModuleNameBufferSize,
        _Out_opt_ PULONG ModuleNameSize,
        _Out_writes_opt_(LoadedImageNameBufferSize) PSTR LoadedImageNameBuffer,
        _In_ ULONG LoadedImageNameBufferSize,
        _Out_opt_ PULONG LoadedImageNameSize
        ) PURE;
    STDMETHOD(GetModuleParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG64 Bases,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_MODULE_PARAMETERS Params
        ) PURE;
    // Looks up the module from a <Module>!<Symbol>
    // string.
    STDMETHOD(GetSymbolModule)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    // Returns the string name of a type.
    STDMETHOD(GetTypeName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeId)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetTypeSize)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_ PULONG Size
        ) PURE;
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeId)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
    STDMETHOD(GetOffsetTypeId)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
    STDMETHOD(ReadTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataVirtual)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ReadTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataPhysical)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;

    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
    STDMETHOD(GetScope)(
        THIS_
        _Out_opt_ PULONG64 InstructionOffset,
        _Out_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _Out_writes_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
    STDMETHOD(SetScope)(
        THIS_
        _In_ ULONG64 InstructionOffset,
        _In_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _In_reads_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
    STDMETHOD(ResetScope)(
        THIS
        ) PURE;
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
    STDMETHOD(GetScopeSymbolGroup)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP Update,
        _Out_ PDEBUG_SYMBOL_GROUP* Symbols
        ) PURE;

    // Create a new symbol group.
    STDMETHOD(CreateSymbolGroup)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP* Group
        ) PURE;

    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
    STDMETHOD(StartSymbolMatch)(
        THIS_
        _In_ PCSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Buffer is NULL the match does not
    // advance.
    STDMETHOD(GetNextSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;
    STDMETHOD(EndSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Reload)(
        THIS_
        _In_ PCSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
    STDMETHOD(GetImagePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendImagePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Path routines for source file location
    // methods.
    STDMETHOD(GetSourcePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    // Gets the nth part of the source path.
    STDMETHOD(GetSourcePathElement)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
    STDMETHOD(FindSourceFile)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
    STDMETHOD(GetSourceFileLineOffsets)(
        THIS_
        _In_ PCSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;

    // IDebugSymbols2.

    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // Item is specified as in VerQueryValue.
    // Module version information is only
    // available for loaded modules and may
    // not be available in all debug sessions.
    STDMETHOD(GetModuleVersionInformation)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _In_ PCSTR Item,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG VerInfoSize
        ) PURE;
    // Retrieves any available module name string
    // such as module name or symbol file name.
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // If symbols are deferred an error will
    // be returned.
    // E_NOINTERFACE may be returned, indicating
    // no information exists.
    STDMETHOD(GetModuleNameString)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Returns the string name of a constant type.
    STDMETHOD(GetConstantName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG64 Value,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Gets name of a field in a struct
    // FieldNumber is 0 based index of field in a struct
    STDMETHOD(GetFieldName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG FieldIndex,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Control options for typed values.
    STDMETHOD(GetTypeOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // IDebugSymbols3.

    STDMETHOD(GetNameByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByNameWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetNearNameByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PWSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLineWide)(
        THIS_
        _In_ ULONG Line,
        _In_ PCWSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    STDMETHOD(GetModuleByModuleNameWide)(
        THIS_
        _In_ PCWSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    STDMETHOD(GetSymbolModuleWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    STDMETHOD(GetTypeNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeIdWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCWSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetFieldOffsetWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCWSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeIdWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    STDMETHOD(GetScopeSymbolGroup2)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP2 Update,
        _Out_ PDEBUG_SYMBOL_GROUP2* Symbols
        ) PURE;

    STDMETHOD(CreateSymbolGroup2)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP2* Group
        ) PURE;

    STDMETHOD(StartSymbolMatchWide)(
        THIS_
        _In_ PCWSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetNextSymbolMatchWide)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;

    STDMETHOD(ReloadWide)(
        THIS_
        _In_ PCWSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;

    STDMETHOD(GetImagePathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendImagePathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;

    STDMETHOD(GetSourcePathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(GetSourcePathElementWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;
    STDMETHOD(FindSourceFileWide)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    STDMETHOD(GetSourceFileLineOffsetsWide)(
        THIS_
        _In_ PCWSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;

    STDMETHOD(GetModuleVersionInformationWide)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _In_ PCWSTR Item,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG VerInfoSize
        ) PURE;
    STDMETHOD(GetModuleNameStringWide)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    STDMETHOD(GetConstantNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG64 Value,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    STDMETHOD(GetFieldNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG FieldIndex,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Returns S_OK if the engine is using managed
    // debugging support when retriving information
    // for the given module.  This can be expensive
    // to check.
    STDMETHOD(IsManagedModule)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base
        ) PURE;

    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName2)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    STDMETHOD(GetModuleByModuleName2Wide)(
        THIS_
        _In_ PCWSTR Name,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset2)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;

    // A caller can create artificial loaded modules in
    // the engine's module list if desired.
    // These modules only serve as names for
    // a region of addresses.  They cannot have
    // real symbols loaded for them; if that
    // is desired Reload can be used with explicit
    // parameters to create a true module entry.
    // The region must not be in use by any other
    // module.
    // A general reload will discard any synthetic modules.
    STDMETHOD(AddSyntheticModule)(
        THIS_
        _In_ ULONG64 Base,
        _In_ ULONG Size,
        _In_ PCSTR ImagePath,
        _In_ PCSTR ModuleName,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(AddSyntheticModuleWide)(
        THIS_
        _In_ ULONG64 Base,
        _In_ ULONG Size,
        _In_ PCWSTR ImagePath,
        _In_ PCWSTR ModuleName,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(RemoveSyntheticModule)(
        THIS_
        _In_ ULONG64 Base
        ) PURE;

    // Modify the current frame used for scoping.
    // This is equivalent to the '.frame' command.
    STDMETHOD(GetCurrentScopeFrameIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    STDMETHOD(SetScopeFrameByIndex)(
        THIS_
        _In_ ULONG Index
        ) PURE;

    // Recovers JIT_DEBUG_INFO information at the given
    // address from the debuggee and sets current
    // debugger scope context from it.
    // Equivalent to '.jdinfo' command.
    STDMETHOD(SetScopeFromJitDebugInfo)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 InfoOffset
        ) PURE;

    // Switches the current debugger scope to
    // the stored event information.
    // Equivalent to the '.ecxr' command.
    STDMETHOD(SetScopeFromStoredEvent)(
        THIS
        ) PURE;

    // Takes the first symbol hit and outputs it.
    // Controlled with DEBUG_OUTSYM_* flags.
    STDMETHOD(OutputSymbolByOffset)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ ULONG64 Offset
        ) PURE;

    // Function entry information for a particular
    // piece of code can be retrieved by this method.
    // The actual data returned is system-dependent.
    STDMETHOD(GetFunctionEntryByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BufferNeeded
        ) PURE;

    // Given a type which can contain members
    // this method returns the type ID and offset of a
    // particular member within the type.
    // Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldTypeAndOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG ContainerTypeId,
        _In_ PCSTR Field,
        _Out_opt_ PULONG FieldTypeId,
        _Out_opt_ PULONG Offset
        ) PURE;
    STDMETHOD(GetFieldTypeAndOffsetWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG ContainerTypeId,
        _In_ PCWSTR Field,
        _Out_opt_ PULONG FieldTypeId,
        _Out_opt_ PULONG Offset
        ) PURE;

    // Artificial symbols can be created in any
    // existing module as a way to name an address.
    // The address must not already have symbol
    // information.
    // A reload will discard synthetic symbols
    // for all address regions reloaded.
    STDMETHOD(AddSyntheticSymbol)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Size,
        _In_ PCSTR Name,
        _In_ ULONG Flags,
        _Out_opt_ PDEBUG_MODULE_AND_ID Id
        ) PURE;
    STDMETHOD(AddSyntheticSymbolWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Size,
        _In_ PCWSTR Name,
        _In_ ULONG Flags,
        _Out_opt_ PDEBUG_MODULE_AND_ID Id
        ) PURE;
    STDMETHOD(RemoveSyntheticSymbol)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id
        ) PURE;

    // The following methods can return multiple
    // hits for symbol lookups to allow for all
    // possible hits to be returned.
    STDMETHOD(GetSymbolEntriesByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _Out_writes_opt_(IdsCount) PULONG64 Displacements,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    STDMETHOD(GetSymbolEntriesByName)(
        THIS_
        _In_ PCSTR Symbol,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    STDMETHOD(GetSymbolEntriesByNameWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    // Symbol lookup by managed metadata token.
    STDMETHOD(GetSymbolEntryByToken)(
        THIS_
        _In_ ULONG64 ModuleBase,
        _In_ ULONG Token,
        _Out_ PDEBUG_MODULE_AND_ID Id
        ) PURE;

    // Retrieves full symbol entry information from an ID.
    STDMETHOD(GetSymbolEntryInformation)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _Out_ PDEBUG_SYMBOL_ENTRY Info
        ) PURE;
    STDMETHOD(GetSymbolEntryString)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSymbolEntryStringWide)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    // Returns all known memory regions associated
    // with the given symbol.  Simple symbols will
    // have a single region starting from their base.
    // More complicated regions, such as functions
    // with multiple code areas, can have an arbitrarily
    // large number of regions.
    // The quality of information returned is highly
    // dependent on the symbolic information availble.
    STDMETHOD(GetSymbolEntryOffsetRegions)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Flags,
        _Out_writes_opt_(RegionsCount) PDEBUG_OFFSET_REGION Regions,
        _In_ ULONG RegionsCount,
        _Out_opt_ PULONG RegionsAvail
        ) PURE;

    // This method allows navigating within the
    // symbol entry hierarchy.
    STDMETHOD(GetSymbolEntryBySymbolEntry)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID FromId,
        _In_ ULONG Flags,
        _Out_ PDEBUG_MODULE_AND_ID ToId
        ) PURE;

    // The following methods can return multiple
    // hits for source lookups to allow for all
    // possible hits to be returned.
    STDMETHOD(GetSourceEntriesByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;
    STDMETHOD(GetSourceEntriesByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;
    STDMETHOD(GetSourceEntriesByLineWide)(
        THIS_
        _In_ ULONG Line,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;

    STDMETHOD(GetSourceEntryString)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSourceEntryStringWide)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    // Returns all known memory regions associated
    // with the given source entry.  As with
    // GetSymbolEntryOffsetRegions the regions available
    // are variable.
    STDMETHOD(GetSourceEntryOffsetRegions)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Flags,
        _Out_writes_opt_(RegionsCount) PDEBUG_OFFSET_REGION Regions,
        _In_ ULONG RegionsCount,
        _Out_opt_ PULONG RegionsAvail
        ) PURE;

    // This method allows navigating within the
    // source entries.
    STDMETHOD(GetSourceEntryBySourceEntry)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY FromEntry,
        _In_ ULONG Flags,
        _Out_ PDEBUG_SYMBOL_SOURCE_ENTRY ToEntry
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugSymbols4
DECLARE_INTERFACE_(IDebugSymbols4, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
    STDMETHOD(GetSymbolOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    STDMETHOD(GetNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
    STDMETHOD(GetOffsetByName)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
    STDMETHOD(GetNearNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
    STDMETHOD(GetNumberModules)(
        THIS_
        _Out_ PULONG Loaded,
        _Out_ PULONG Unloaded
        ) PURE;
    STDMETHOD(GetModuleByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG64 Base
        ) PURE;
    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    STDMETHOD(GetModuleNames)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(ImageNameBufferSize) PSTR ImageNameBuffer,
        _In_ ULONG ImageNameBufferSize,
        _Out_opt_ PULONG ImageNameSize,
        _Out_writes_opt_(ModuleNameBufferSize) PSTR ModuleNameBuffer,
        _In_ ULONG ModuleNameBufferSize,
        _Out_opt_ PULONG ModuleNameSize,
        _Out_writes_opt_(LoadedImageNameBufferSize) PSTR LoadedImageNameBuffer,
        _In_ ULONG LoadedImageNameBufferSize,
        _Out_opt_ PULONG LoadedImageNameSize
        ) PURE;
    STDMETHOD(GetModuleParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG64 Bases,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_MODULE_PARAMETERS Params
        ) PURE;
    // Looks up the module from a <Module>!<Symbol>
    // string.
    STDMETHOD(GetSymbolModule)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    // Returns the string name of a type.
    STDMETHOD(GetTypeName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeId)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetTypeSize)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_ PULONG Size
        ) PURE;
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeId)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
    STDMETHOD(GetOffsetTypeId)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
    STDMETHOD(ReadTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataVirtual)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ReadTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataPhysical)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;

    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
    STDMETHOD(GetScope)(
        THIS_
        _Out_opt_ PULONG64 InstructionOffset,
        _Out_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _Out_writes_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
    STDMETHOD(SetScope)(
        THIS_
        _In_ ULONG64 InstructionOffset,
        _In_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _In_reads_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
    STDMETHOD(ResetScope)(
        THIS
        ) PURE;
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
    STDMETHOD(GetScopeSymbolGroup)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP Update,
        _Out_ PDEBUG_SYMBOL_GROUP* Symbols
        ) PURE;

    // Create a new symbol group.
    STDMETHOD(CreateSymbolGroup)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP* Group
        ) PURE;

    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
    STDMETHOD(StartSymbolMatch)(
        THIS_
        _In_ PCSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Buffer is NULL the match does not
    // advance.
    STDMETHOD(GetNextSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;
    STDMETHOD(EndSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Reload)(
        THIS_
        _In_ PCSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
    STDMETHOD(GetImagePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendImagePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Path routines for source file location
    // methods.
    STDMETHOD(GetSourcePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    // Gets the nth part of the source path.
    STDMETHOD(GetSourcePathElement)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
    STDMETHOD(FindSourceFile)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
    STDMETHOD(GetSourceFileLineOffsets)(
        THIS_
        _In_ PCSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;

    // IDebugSymbols2.

    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // Item is specified as in VerQueryValue.
    // Module version information is only
    // available for loaded modules and may
    // not be available in all debug sessions.
    STDMETHOD(GetModuleVersionInformation)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _In_ PCSTR Item,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG VerInfoSize
        ) PURE;
    // Retrieves any available module name string
    // such as module name or symbol file name.
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // If symbols are deferred an error will
    // be returned.
    // E_NOINTERFACE may be returned, indicating
    // no information exists.
    STDMETHOD(GetModuleNameString)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Returns the string name of a constant type.
    STDMETHOD(GetConstantName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG64 Value,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Gets name of a field in a struct
    // FieldNumber is 0 based index of field in a struct
    STDMETHOD(GetFieldName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG FieldIndex,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Control options for typed values.
    STDMETHOD(GetTypeOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // IDebugSymbols3.

    STDMETHOD(GetNameByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByNameWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetNearNameByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PWSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLineWide)(
        THIS_
        _In_ ULONG Line,
        _In_ PCWSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    STDMETHOD(GetModuleByModuleNameWide)(
        THIS_
        _In_ PCWSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    STDMETHOD(GetSymbolModuleWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    STDMETHOD(GetTypeNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeIdWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCWSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetFieldOffsetWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCWSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeIdWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    STDMETHOD(GetScopeSymbolGroup2)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP2 Update,
        _Out_ PDEBUG_SYMBOL_GROUP2* Symbols
        ) PURE;

    STDMETHOD(CreateSymbolGroup2)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP2* Group
        ) PURE;

    STDMETHOD(StartSymbolMatchWide)(
        THIS_
        _In_ PCWSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetNextSymbolMatchWide)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;

    STDMETHOD(ReloadWide)(
        THIS_
        _In_ PCWSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;

    STDMETHOD(GetImagePathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendImagePathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;

    STDMETHOD(GetSourcePathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(GetSourcePathElementWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;
    STDMETHOD(FindSourceFileWide)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    STDMETHOD(GetSourceFileLineOffsetsWide)(
        THIS_
        _In_ PCWSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;

    STDMETHOD(GetModuleVersionInformationWide)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _In_ PCWSTR Item,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG VerInfoSize
        ) PURE;
    STDMETHOD(GetModuleNameStringWide)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    STDMETHOD(GetConstantNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG64 Value,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    STDMETHOD(GetFieldNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG FieldIndex,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Returns S_OK if the engine is using managed
    // debugging support when retriving information
    // for the given module.  This can be expensive
    // to check.
    STDMETHOD(IsManagedModule)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base
        ) PURE;

    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName2)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    STDMETHOD(GetModuleByModuleName2Wide)(
        THIS_
        _In_ PCWSTR Name,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset2)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;

    // A caller can create artificial loaded modules in
    // the engine's module list if desired.
    // These modules only serve as names for
    // a region of addresses.  They cannot have
    // real symbols loaded for them; if that
    // is desired Reload can be used with explicit
    // parameters to create a true module entry.
    // The region must not be in use by any other
    // module.
    // A general reload will discard any synthetic modules.
    STDMETHOD(AddSyntheticModule)(
        THIS_
        _In_ ULONG64 Base,
        _In_ ULONG Size,
        _In_ PCSTR ImagePath,
        _In_ PCSTR ModuleName,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(AddSyntheticModuleWide)(
        THIS_
        _In_ ULONG64 Base,
        _In_ ULONG Size,
        _In_ PCWSTR ImagePath,
        _In_ PCWSTR ModuleName,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(RemoveSyntheticModule)(
        THIS_
        _In_ ULONG64 Base
        ) PURE;

    // Modify the current frame used for scoping.
    // This is equivalent to the '.frame' command.
    STDMETHOD(GetCurrentScopeFrameIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    STDMETHOD(SetScopeFrameByIndex)(
        THIS_
        _In_ ULONG Index
        ) PURE;

    // Recovers JIT_DEBUG_INFO information at the given
    // address from the debuggee and sets current
    // debugger scope context from it.
    // Equivalent to '.jdinfo' command.
    STDMETHOD(SetScopeFromJitDebugInfo)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 InfoOffset
        ) PURE;

    // Switches the current debugger scope to
    // the stored event information.
    // Equivalent to the '.ecxr' command.
    STDMETHOD(SetScopeFromStoredEvent)(
        THIS
        ) PURE;

    // Takes the first symbol hit and outputs it.
    // Controlled with DEBUG_OUTSYM_* flags.
    STDMETHOD(OutputSymbolByOffset)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ ULONG64 Offset
        ) PURE;

    // Function entry information for a particular
    // piece of code can be retrieved by this method.
    // The actual data returned is system-dependent.
    STDMETHOD(GetFunctionEntryByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BufferNeeded
        ) PURE;

    // Given a type which can contain members
    // this method returns the type ID and offset of a
    // particular member within the type.
    // Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldTypeAndOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG ContainerTypeId,
        _In_ PCSTR Field,
        _Out_opt_ PULONG FieldTypeId,
        _Out_opt_ PULONG Offset
        ) PURE;
    STDMETHOD(GetFieldTypeAndOffsetWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG ContainerTypeId,
        _In_ PCWSTR Field,
        _Out_opt_ PULONG FieldTypeId,
        _Out_opt_ PULONG Offset
        ) PURE;

    // Artificial symbols can be created in any
    // existing module as a way to name an address.
    // The address must not already have symbol
    // information.
    // A reload will discard synthetic symbols
    // for all address regions reloaded.
    STDMETHOD(AddSyntheticSymbol)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Size,
        _In_ PCSTR Name,
        _In_ ULONG Flags,
        _Out_opt_ PDEBUG_MODULE_AND_ID Id
        ) PURE;
    STDMETHOD(AddSyntheticSymbolWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Size,
        _In_ PCWSTR Name,
        _In_ ULONG Flags,
        _Out_opt_ PDEBUG_MODULE_AND_ID Id
        ) PURE;
    STDMETHOD(RemoveSyntheticSymbol)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id
        ) PURE;

    // The following methods can return multiple
    // hits for symbol lookups to allow for all
    // possible hits to be returned.
    STDMETHOD(GetSymbolEntriesByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _Out_writes_opt_(IdsCount) PULONG64 Displacements,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    STDMETHOD(GetSymbolEntriesByName)(
        THIS_
        _In_ PCSTR Symbol,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    STDMETHOD(GetSymbolEntriesByNameWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    // Symbol lookup by managed metadata token.
    STDMETHOD(GetSymbolEntryByToken)(
        THIS_
        _In_ ULONG64 ModuleBase,
        _In_ ULONG Token,
        _Out_ PDEBUG_MODULE_AND_ID Id
        ) PURE;

    // Retrieves full symbol entry information from an ID.
    STDMETHOD(GetSymbolEntryInformation)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _Out_ PDEBUG_SYMBOL_ENTRY Info
        ) PURE;
    STDMETHOD(GetSymbolEntryString)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSymbolEntryStringWide)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    // Returns all known memory regions associated
    // with the given symbol.  Simple symbols will
    // have a single region starting from their base.
    // More complicated regions, such as functions
    // with multiple code areas, can have an arbitrarily
    // large number of regions.
    // The quality of information returned is highly
    // dependent on the symbolic information availble.
    STDMETHOD(GetSymbolEntryOffsetRegions)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Flags,
        _Out_writes_opt_(RegionsCount) PDEBUG_OFFSET_REGION Regions,
        _In_ ULONG RegionsCount,
        _Out_opt_ PULONG RegionsAvail
        ) PURE;

    // This method allows navigating within the
    // symbol entry hierarchy.
    STDMETHOD(GetSymbolEntryBySymbolEntry)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID FromId,
        _In_ ULONG Flags,
        _Out_ PDEBUG_MODULE_AND_ID ToId
        ) PURE;

    // The following methods can return multiple
    // hits for source lookups to allow for all
    // possible hits to be returned.
    STDMETHOD(GetSourceEntriesByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;
    STDMETHOD(GetSourceEntriesByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;
    STDMETHOD(GetSourceEntriesByLineWide)(
        THIS_
        _In_ ULONG Line,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;

    STDMETHOD(GetSourceEntryString)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSourceEntryStringWide)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    // Returns all known memory regions associated
    // with the given source entry.  As with
    // GetSymbolEntryOffsetRegions the regions available
    // are variable.
    STDMETHOD(GetSourceEntryOffsetRegions)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Flags,
        _Out_writes_opt_(RegionsCount) PDEBUG_OFFSET_REGION Regions,
        _In_ ULONG RegionsCount,
        _Out_opt_ PULONG RegionsAvail
        ) PURE;

    // This method allows navigating within the
    // source entries.
    STDMETHOD(GetSourceEntryBySourceEntry)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY FromEntry,
        _In_ ULONG Flags,
        _Out_ PDEBUG_SYMBOL_SOURCE_ENTRY ToEntry
        ) PURE;

    // IDebugSymbols4
    STDMETHOD(GetScopeEx)(
        THIS_
        _Out_opt_ PULONG64 InstructionOffset,
        _Out_opt_ PDEBUG_STACK_FRAME_EX ScopeFrame,
        _Out_writes_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;

    STDMETHOD(SetScopeEx)(
        THIS_
        _In_ ULONG64 InstructionOffset,
        _In_opt_ PDEBUG_STACK_FRAME_EX ScopeFrame,
        _In_reads_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;

    STDMETHOD(GetNameByInlineContext)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetNameByInlineContextWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByInlineContext)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByInlineContextWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PWSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(OutputSymbolByInlineContext)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext
        ) PURE;
};

#define DEBUG_FRAME_DEFAULT                0
#define DEBUG_FRAME_IGNORE_INLINE 0x00000001

#undef INTERFACE
#define INTERFACE IDebugSymbols5
DECLARE_INTERFACE_(IDebugSymbols5, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
    STDMETHOD(GetSymbolOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetSymbolOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    STDMETHOD(GetNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
    STDMETHOD(GetOffsetByName)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
    STDMETHOD(GetNearNameByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
    STDMETHOD(GetNumberModules)(
        THIS_
        _Out_ PULONG Loaded,
        _Out_ PULONG Unloaded
        ) PURE;
    STDMETHOD(GetModuleByIndex)(
        THIS_
        _In_ ULONG Index,
        _Out_ PULONG64 Base
        ) PURE;
    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    STDMETHOD(GetModuleNames)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(ImageNameBufferSize) PSTR ImageNameBuffer,
        _In_ ULONG ImageNameBufferSize,
        _Out_opt_ PULONG ImageNameSize,
        _Out_writes_opt_(ModuleNameBufferSize) PSTR ModuleNameBuffer,
        _In_ ULONG ModuleNameBufferSize,
        _Out_opt_ PULONG ModuleNameSize,
        _Out_writes_opt_(LoadedImageNameBufferSize) PSTR LoadedImageNameBuffer,
        _In_ ULONG LoadedImageNameBufferSize,
        _Out_opt_ PULONG LoadedImageNameSize
        ) PURE;
    STDMETHOD(GetModuleParameters)(
        THIS_
        _In_ ULONG Count,
        _In_reads_opt_(Count) PULONG64 Bases,
        _In_ ULONG Start,
        _Out_writes_(Count) PDEBUG_MODULE_PARAMETERS Params
        ) PURE;
    // Looks up the module from a <Module>!<Symbol>
    // string.
    STDMETHOD(GetSymbolModule)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    // Returns the string name of a type.
    STDMETHOD(GetTypeName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeId)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetTypeSize)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_ PULONG Size
        ) PURE;
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeId)(
        THIS_
        _In_ PCSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
    STDMETHOD(GetOffsetTypeId)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
    STDMETHOD(ReadTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataVirtual)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataVirtual)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(ReadTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesRead
        ) PURE;
    STDMETHOD(WriteTypedDataPhysical)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_reads_bytes_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BytesWritten
        ) PURE;
    STDMETHOD(OutputTypedDataPhysical)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 Offset,
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG Flags
        ) PURE;

    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
    STDMETHOD(GetScope)(
        THIS_
        _Out_opt_ PULONG64 InstructionOffset,
        _Out_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _Out_writes_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
    STDMETHOD(SetScope)(
        THIS_
        _In_ ULONG64 InstructionOffset,
        _In_opt_ PDEBUG_STACK_FRAME ScopeFrame,
        _In_reads_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
    STDMETHOD(ResetScope)(
        THIS
        ) PURE;
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
    STDMETHOD(GetScopeSymbolGroup)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP Update,
        _Out_ PDEBUG_SYMBOL_GROUP* Symbols
        ) PURE;

    // Create a new symbol group.
    STDMETHOD(CreateSymbolGroup)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP* Group
        ) PURE;

    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
    STDMETHOD(StartSymbolMatch)(
        THIS_
        _In_ PCSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    // If Buffer is NULL the match does not
    // advance.
    STDMETHOD(GetNextSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;
    STDMETHOD(EndSymbolMatch)(
        THIS_
        _In_ ULONG64 Handle
        ) PURE;

    STDMETHOD(Reload)(
        THIS_
        _In_ PCSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
    STDMETHOD(GetImagePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendImagePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;

    // Path routines for source file location
    // methods.
    STDMETHOD(GetSourcePath)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    // Gets the nth part of the source path.
    STDMETHOD(GetSourcePathElement)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePath)(
        THIS_
        _In_ PCSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePath)(
        THIS_
        _In_ PCSTR Addition
        ) PURE;
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
    STDMETHOD(FindSourceFile)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
    STDMETHOD(GetSourceFileLineOffsets)(
        THIS_
        _In_ PCSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;

    // IDebugSymbols2.

    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // Item is specified as in VerQueryValue.
    // Module version information is only
    // available for loaded modules and may
    // not be available in all debug sessions.
    STDMETHOD(GetModuleVersionInformation)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _In_ PCSTR Item,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG VerInfoSize
        ) PURE;
    // Retrieves any available module name string
    // such as module name or symbol file name.
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // If symbols are deferred an error will
    // be returned.
    // E_NOINTERFACE may be returned, indicating
    // no information exists.
    STDMETHOD(GetModuleNameString)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Returns the string name of a constant type.
    STDMETHOD(GetConstantName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG64 Value,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Gets name of a field in a struct
    // FieldNumber is 0 based index of field in a struct
    STDMETHOD(GetFieldName)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG FieldIndex,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Control options for typed values.
    STDMETHOD(GetTypeOptions)(
        THIS_
        _Out_ PULONG Options
        ) PURE;
    STDMETHOD(AddTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(RemoveTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;
    STDMETHOD(SetTypeOptions)(
        THIS_
        _In_ ULONG Options
        ) PURE;

    // IDebugSymbols3.

    STDMETHOD(GetNameByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByNameWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(GetNearNameByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ LONG Delta,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByOffsetWide)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PWSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;
    STDMETHOD(GetOffsetByLineWide)(
        THIS_
        _In_ ULONG Line,
        _In_ PCWSTR File,
        _Out_ PULONG64 Offset
        ) PURE;

    STDMETHOD(GetModuleByModuleNameWide)(
        THIS_
        _In_ PCWSTR Name,
        _In_ ULONG StartIndex,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    STDMETHOD(GetSymbolModuleWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG64 Base
        ) PURE;

    STDMETHOD(GetTypeNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
    // Returns the ID for a type name.
    STDMETHOD(GetTypeIdWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ PCWSTR Name,
        _Out_ PULONG TypeId
        ) PURE;
    STDMETHOD(GetFieldOffsetWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ PCWSTR Field,
        _Out_ PULONG Offset
        ) PURE;

    STDMETHOD(GetSymbolTypeIdWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _Out_ PULONG TypeId,
        _Out_opt_ PULONG64 Module
        ) PURE;

    STDMETHOD(GetScopeSymbolGroup2)(
        THIS_
        _In_ ULONG Flags,
        _In_opt_ PDEBUG_SYMBOL_GROUP2 Update,
        _Out_ PDEBUG_SYMBOL_GROUP2* Symbols
        ) PURE;

    STDMETHOD(CreateSymbolGroup2)(
        THIS_
        _Out_ PDEBUG_SYMBOL_GROUP2* Group
        ) PURE;

    STDMETHOD(StartSymbolMatchWide)(
        THIS_
        _In_ PCWSTR Pattern,
        _Out_ PULONG64 Handle
        ) PURE;
    STDMETHOD(GetNextSymbolMatchWide)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG MatchSize,
        _Out_opt_ PULONG64 Offset
        ) PURE;

    STDMETHOD(ReloadWide)(
        THIS_
        _In_ PCWSTR Module
        ) PURE;

    STDMETHOD(GetSymbolPathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetSymbolPathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendSymbolPathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;

    STDMETHOD(GetImagePathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(SetImagePathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendImagePathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;

    STDMETHOD(GetSourcePathWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG PathSize
        ) PURE;
    STDMETHOD(GetSourcePathElementWide)(
        THIS_
        _In_ ULONG Index,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ElementSize
        ) PURE;
    STDMETHOD(SetSourcePathWide)(
        THIS_
        _In_ PCWSTR Path
        ) PURE;
    STDMETHOD(AppendSourcePathWide)(
        THIS_
        _In_ PCWSTR Addition
        ) PURE;
    STDMETHOD(FindSourceFileWide)(
        THIS_
        _In_ ULONG StartElement,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _Out_opt_ PULONG FoundElement,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG FoundSize
        ) PURE;
    STDMETHOD(GetSourceFileLineOffsetsWide)(
        THIS_
        _In_ PCWSTR File,
        _Out_writes_opt_(BufferLines) PULONG64 Buffer,
        _In_ ULONG BufferLines,
        _Out_opt_ PULONG FileLines
        ) PURE;

    STDMETHOD(GetModuleVersionInformationWide)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _In_ PCWSTR Item,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG VerInfoSize
        ) PURE;
    STDMETHOD(GetModuleNameStringWide)(
        THIS_
        _In_ ULONG Which,
        _In_ ULONG Index,
        _In_ ULONG64 Base,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    STDMETHOD(GetConstantNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG64 Value,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    STDMETHOD(GetFieldNameWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG TypeId,
        _In_ ULONG FieldIndex,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // Returns S_OK if the engine is using managed
    // debugging support when retriving information
    // for the given module.  This can be expensive
    // to check.
    STDMETHOD(IsManagedModule)(
        THIS_
        _In_ ULONG Index,
        _In_ ULONG64 Base
        ) PURE;

    // The module name may not be unique.
    // This method returns the first match.
    STDMETHOD(GetModuleByModuleName2)(
        THIS_
        _In_ PCSTR Name,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    STDMETHOD(GetModuleByModuleName2Wide)(
        THIS_
        _In_ PCWSTR Name,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
    STDMETHOD(GetModuleByOffset2)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG StartIndex,
        _In_ ULONG Flags,
        _Out_opt_ PULONG Index,
        _Out_opt_ PULONG64 Base
        ) PURE;

    // A caller can create artificial loaded modules in
    // the engine's module list if desired.
    // These modules only serve as names for
    // a region of addresses.  They cannot have
    // real symbols loaded for them; if that
    // is desired Reload can be used with explicit
    // parameters to create a true module entry.
    // The region must not be in use by any other
    // module.
    // A general reload will discard any synthetic modules.
    STDMETHOD(AddSyntheticModule)(
        THIS_
        _In_ ULONG64 Base,
        _In_ ULONG Size,
        _In_ PCSTR ImagePath,
        _In_ PCSTR ModuleName,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(AddSyntheticModuleWide)(
        THIS_
        _In_ ULONG64 Base,
        _In_ ULONG Size,
        _In_ PCWSTR ImagePath,
        _In_ PCWSTR ModuleName,
        _In_ ULONG Flags
        ) PURE;
    STDMETHOD(RemoveSyntheticModule)(
        THIS_
        _In_ ULONG64 Base
        ) PURE;

    // Modify the current frame used for scoping.
    // This is equivalent to the '.frame' command.
    STDMETHOD(GetCurrentScopeFrameIndex)(
        THIS_
        _Out_ PULONG Index
        ) PURE;
    STDMETHOD(SetScopeFrameByIndex)(
        THIS_
        _In_ ULONG Index
        ) PURE;

    // Recovers JIT_DEBUG_INFO information at the given
    // address from the debuggee and sets current
    // debugger scope context from it.
    // Equivalent to '.jdinfo' command.
    STDMETHOD(SetScopeFromJitDebugInfo)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG64 InfoOffset
        ) PURE;

    // Switches the current debugger scope to
    // the stored event information.
    // Equivalent to the '.ecxr' command.
    STDMETHOD(SetScopeFromStoredEvent)(
        THIS
        ) PURE;

    // Takes the first symbol hit and outputs it.
    // Controlled with DEBUG_OUTSYM_* flags.
    STDMETHOD(OutputSymbolByOffset)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ ULONG64 Offset
        ) PURE;

    // Function entry information for a particular
    // piece of code can be retrieved by this method.
    // The actual data returned is system-dependent.
    STDMETHOD(GetFunctionEntryByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG BufferNeeded
        ) PURE;

    // Given a type which can contain members
    // this method returns the type ID and offset of a
    // particular member within the type.
    // Field gives the dot-separated path
    // to the field of interest.
    STDMETHOD(GetFieldTypeAndOffset)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG ContainerTypeId,
        _In_ PCSTR Field,
        _Out_opt_ PULONG FieldTypeId,
        _Out_opt_ PULONG Offset
        ) PURE;
    STDMETHOD(GetFieldTypeAndOffsetWide)(
        THIS_
        _In_ ULONG64 Module,
        _In_ ULONG ContainerTypeId,
        _In_ PCWSTR Field,
        _Out_opt_ PULONG FieldTypeId,
        _Out_opt_ PULONG Offset
        ) PURE;

    // Artificial symbols can be created in any
    // existing module as a way to name an address.
    // The address must not already have symbol
    // information.
    // A reload will discard synthetic symbols
    // for all address regions reloaded.
    STDMETHOD(AddSyntheticSymbol)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Size,
        _In_ PCSTR Name,
        _In_ ULONG Flags,
        _Out_opt_ PDEBUG_MODULE_AND_ID Id
        ) PURE;
    STDMETHOD(AddSyntheticSymbolWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Size,
        _In_ PCWSTR Name,
        _In_ ULONG Flags,
        _Out_opt_ PDEBUG_MODULE_AND_ID Id
        ) PURE;
    STDMETHOD(RemoveSyntheticSymbol)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id
        ) PURE;

    // The following methods can return multiple
    // hits for symbol lookups to allow for all
    // possible hits to be returned.
    STDMETHOD(GetSymbolEntriesByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _Out_writes_opt_(IdsCount) PULONG64 Displacements,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    STDMETHOD(GetSymbolEntriesByName)(
        THIS_
        _In_ PCSTR Symbol,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    STDMETHOD(GetSymbolEntriesByNameWide)(
        THIS_
        _In_ PCWSTR Symbol,
        _In_ ULONG Flags,
        _Out_writes_opt_(IdsCount) PDEBUG_MODULE_AND_ID Ids,
        _In_ ULONG IdsCount,
        _Out_opt_ PULONG Entries
        ) PURE;
    // Symbol lookup by managed metadata token.
    STDMETHOD(GetSymbolEntryByToken)(
        THIS_
        _In_ ULONG64 ModuleBase,
        _In_ ULONG Token,
        _Out_ PDEBUG_MODULE_AND_ID Id
        ) PURE;

    // Retrieves full symbol entry information from an ID.
    STDMETHOD(GetSymbolEntryInformation)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _Out_ PDEBUG_SYMBOL_ENTRY Info
        ) PURE;
    STDMETHOD(GetSymbolEntryString)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSymbolEntryStringWide)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    // Returns all known memory regions associated
    // with the given symbol.  Simple symbols will
    // have a single region starting from their base.
    // More complicated regions, such as functions
    // with multiple code areas, can have an arbitrarily
    // large number of regions.
    // The quality of information returned is highly
    // dependent on the symbolic information availble.
    STDMETHOD(GetSymbolEntryOffsetRegions)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID Id,
        _In_ ULONG Flags,
        _Out_writes_opt_(RegionsCount) PDEBUG_OFFSET_REGION Regions,
        _In_ ULONG RegionsCount,
        _Out_opt_ PULONG RegionsAvail
        ) PURE;

    // This method allows navigating within the
    // symbol entry hierarchy.
    STDMETHOD(GetSymbolEntryBySymbolEntry)(
        THIS_
        _In_ PDEBUG_MODULE_AND_ID FromId,
        _In_ ULONG Flags,
        _Out_ PDEBUG_MODULE_AND_ID ToId
        ) PURE;

    // The following methods can return multiple
    // hits for source lookups to allow for all
    // possible hits to be returned.
    STDMETHOD(GetSourceEntriesByOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;
    STDMETHOD(GetSourceEntriesByLine)(
        THIS_
        _In_ ULONG Line,
        _In_ PCSTR File,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;
    STDMETHOD(GetSourceEntriesByLineWide)(
        THIS_
        _In_ ULONG Line,
        _In_ PCWSTR File,
        _In_ ULONG Flags,
        _Out_writes_opt_(EntriesCount) PDEBUG_SYMBOL_SOURCE_ENTRY Entries,
        _In_ ULONG EntriesCount,
        _Out_opt_ PULONG EntriesAvail
        ) PURE;

    STDMETHOD(GetSourceEntryString)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    STDMETHOD(GetSourceEntryStringWide)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Which,
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG StringSize
        ) PURE;
    // Returns all known memory regions associated
    // with the given source entry.  As with
    // GetSymbolEntryOffsetRegions the regions available
    // are variable.
    STDMETHOD(GetSourceEntryOffsetRegions)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY Entry,
        _In_ ULONG Flags,
        _Out_writes_opt_(RegionsCount) PDEBUG_OFFSET_REGION Regions,
        _In_ ULONG RegionsCount,
        _Out_opt_ PULONG RegionsAvail
        ) PURE;

    // This method allows navigating within the
    // source entries.
    STDMETHOD(GetSourceEntryBySourceEntry)(
        THIS_
        _In_ PDEBUG_SYMBOL_SOURCE_ENTRY FromEntry,
        _In_ ULONG Flags,
        _Out_ PDEBUG_SYMBOL_SOURCE_ENTRY ToEntry
        ) PURE;

    // IDebugSymbols4
    STDMETHOD(GetScopeEx)(
        THIS_
        _Out_opt_ PULONG64 InstructionOffset,
        _Out_opt_ PDEBUG_STACK_FRAME_EX ScopeFrame,
        _Out_writes_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;

    STDMETHOD(SetScopeEx)(
        THIS_
        _In_ ULONG64 InstructionOffset,
        _In_opt_ PDEBUG_STACK_FRAME_EX ScopeFrame,
        _In_reads_bytes_opt_(ScopeContextSize) PVOID ScopeContext,
        _In_ ULONG ScopeContextSize
        ) PURE;

    STDMETHOD(GetNameByInlineContext)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_writes_opt_(NameBufferSize) PSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetNameByInlineContextWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_writes_opt_(NameBufferSize) PWSTR NameBuffer,
        _In_ ULONG NameBufferSize,
        _Out_opt_ PULONG NameSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByInlineContext)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(GetLineByInlineContextWide)(
        THIS_
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext,
        _Out_opt_ PULONG Line,
        _Out_writes_opt_(FileBufferSize) PWSTR FileBuffer,
        _In_ ULONG FileBufferSize,
        _Out_opt_ PULONG FileSize,
        _Out_opt_ PULONG64 Displacement
        ) PURE;

    STDMETHOD(OutputSymbolByInlineContext)(
        THIS_
        _In_ ULONG OutputControl,
        _In_ ULONG Flags,
        _In_ ULONG64 Offset,
        _In_ ULONG InlineContext
        ) PURE;

    // IDebugSymbols5
    STDMETHOD(GetCurrentScopeFrameIndexEx)(
        THIS_
        _In_ ULONG Flags,
        _Out_ PULONG Index
        ) PURE;
    STDMETHOD(SetScopeFrameByIndexEx)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG Index
        ) PURE;
};

//----------------------------------------------------------------------------
//
// IDebugSystemObjects
//
//----------------------------------------------------------------------------

#undef INTERFACE
#define INTERFACE IDebugSystemObjects
DECLARE_INTERFACE_(IDebugSystemObjects, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
    STDMETHOD(GetEventThread)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetEventProcess)(
        THIS_
        _Out_ PULONG Id
        ) PURE;

    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
    STDMETHOD(GetCurrentThreadId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetCurrentThreadId)(
        THIS_
        _In_ ULONG Id
        ) PURE;
    // The current process is the process
    // that owns the current thread.
    STDMETHOD(GetCurrentProcessId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
    STDMETHOD(SetCurrentProcessId)(
        THIS_
        _In_ ULONG Id
        ) PURE;

    // Gets the number of threads in the current process.
    STDMETHOD(GetNumberThreads)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
    STDMETHOD(GetTotalNumberThreads)(
        THIS_
        _Out_ PULONG Total,
        _Out_ PULONG LargestProcess
        ) PURE;
    STDMETHOD(GetThreadIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
    STDMETHOD(GetThreadIdByProcessor)(
        THIS_
        _In_ ULONG Processor,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
    STDMETHOD(GetCurrentThreadDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
    STDMETHOD(GetCurrentThreadTeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByTeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentThreadSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
    STDMETHOD(GetCurrentThreadHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;

    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
    STDMETHOD(GetNumberProcesses)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetProcessIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
    STDMETHOD(GetCurrentProcessDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
    STDMETHOD(GetCurrentProcessPeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByPeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentProcessSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
    STDMETHOD(GetCurrentProcessHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger process ID for the given handle.
    STDMETHOD(GetProcessIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
    STDMETHOD(GetCurrentProcessExecutableName)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExeSize
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugSystemObjects2
DECLARE_INTERFACE_(IDebugSystemObjects2, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
    STDMETHOD(GetEventThread)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetEventProcess)(
        THIS_
        _Out_ PULONG Id
        ) PURE;

    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
    STDMETHOD(GetCurrentThreadId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetCurrentThreadId)(
        THIS_
        _In_ ULONG Id
        ) PURE;
    // The current process is the process
    // that owns the current thread.
    STDMETHOD(GetCurrentProcessId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
    STDMETHOD(SetCurrentProcessId)(
        THIS_
        _In_ ULONG Id
        ) PURE;

    // Gets the number of threads in the current process.
    STDMETHOD(GetNumberThreads)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
    STDMETHOD(GetTotalNumberThreads)(
        THIS_
        _Out_ PULONG Total,
        _Out_ PULONG LargestProcess
        ) PURE;
    STDMETHOD(GetThreadIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
    STDMETHOD(GetThreadIdByProcessor)(
        THIS_
        _In_ ULONG Processor,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
    STDMETHOD(GetCurrentThreadDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
    STDMETHOD(GetCurrentThreadTeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByTeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentThreadSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
    STDMETHOD(GetCurrentThreadHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;

    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
    STDMETHOD(GetNumberProcesses)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetProcessIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
    STDMETHOD(GetCurrentProcessDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
    STDMETHOD(GetCurrentProcessPeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByPeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentProcessSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
    STDMETHOD(GetCurrentProcessHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger process ID for the given handle.
    STDMETHOD(GetProcessIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
    STDMETHOD(GetCurrentProcessExecutableName)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExeSize
        ) PURE;

    // IDebugSystemObjects2.

    // Return the number of seconds that the current
    // process has been running.
    STDMETHOD(GetCurrentProcessUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // During kernel sessions the debugger retrieves
    // some information from the system thread and process
    // running on the current processor.  For example,
    // the debugger will retrieve virtual memory translation
    // information for when the debugger needs to
    // carry out its own virtual to physical translations.
    // Occasionally it can be interesting to perform
    // similar operations but on a process which isnt
    // currently running.  The follow methods allow a caller
    // to override the data offsets used by the debugger
    // so that other system threads and processes can
    // be used instead.  These values are defaulted to
    // the thread and process running on the current
    // processor each time the debuggee executes or
    // the current processor changes.
    // The thread and process settings are independent so
    // it is possible to refer to a thread in a process
    // other than the current process and vice versa.
    // Setting an offset of zero will reload the
    // default value.
    STDMETHOD(GetImplicitThreadDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetImplicitThreadDataOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;
    STDMETHOD(GetImplicitProcessDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetImplicitProcessDataOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugSystemObjects3
DECLARE_INTERFACE_(IDebugSystemObjects3, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
    STDMETHOD(GetEventThread)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetEventProcess)(
        THIS_
        _Out_ PULONG Id
        ) PURE;

    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
    STDMETHOD(GetCurrentThreadId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetCurrentThreadId)(
        THIS_
        _In_ ULONG Id
        ) PURE;
    // The current process is the process
    // that owns the current thread.
    STDMETHOD(GetCurrentProcessId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
    STDMETHOD(SetCurrentProcessId)(
        THIS_
        _In_ ULONG Id
        ) PURE;

    // Gets the number of threads in the current process.
    STDMETHOD(GetNumberThreads)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
    STDMETHOD(GetTotalNumberThreads)(
        THIS_
        _Out_ PULONG Total,
        _Out_ PULONG LargestProcess
        ) PURE;
    STDMETHOD(GetThreadIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
    STDMETHOD(GetThreadIdByProcessor)(
        THIS_
        _In_ ULONG Processor,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
    STDMETHOD(GetCurrentThreadDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
    STDMETHOD(GetCurrentThreadTeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByTeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentThreadSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
    STDMETHOD(GetCurrentThreadHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;

    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
    STDMETHOD(GetNumberProcesses)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetProcessIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
    STDMETHOD(GetCurrentProcessDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
    STDMETHOD(GetCurrentProcessPeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByPeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentProcessSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
    STDMETHOD(GetCurrentProcessHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger process ID for the given handle.
    STDMETHOD(GetProcessIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
    STDMETHOD(GetCurrentProcessExecutableName)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExeSize
        ) PURE;

    // IDebugSystemObjects2.

    // Return the number of seconds that the current
    // process has been running.
    STDMETHOD(GetCurrentProcessUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // During kernel sessions the debugger retrieves
    // some information from the system thread and process
    // running on the current processor.  For example,
    // the debugger will retrieve virtual memory translation
    // information for when the debugger needs to
    // carry out its own virtual to physical translations.
    // Occasionally it can be interesting to perform
    // similar operations but on a process which isnt
    // currently running.  The follow methods allow a caller
    // to override the data offsets used by the debugger
    // so that other system threads and processes can
    // be used instead.  These values are defaulted to
    // the thread and process running on the current
    // processor each time the debuggee executes or
    // the current processor changes.
    // The thread and process settings are independent so
    // it is possible to refer to a thread in a process
    // other than the current process and vice versa.
    // Setting an offset of zero will reload the
    // default value.
    STDMETHOD(GetImplicitThreadDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetImplicitThreadDataOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;
    STDMETHOD(GetImplicitProcessDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetImplicitProcessDataOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;

    // IDebugSystemObjects3.

    STDMETHOD(GetEventSystem)(
        THIS_
        _Out_ PULONG Id
        ) PURE;

    STDMETHOD(GetCurrentSystemId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetCurrentSystemId)(
        THIS_
        _In_ ULONG Id
        ) PURE;

    STDMETHOD(GetNumberSystems)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSystemIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Ids
        ) PURE;
    STDMETHOD(GetTotalNumberThreadsAndProcesses)(
        THIS_
        _Out_ PULONG TotalThreads,
        _Out_ PULONG TotalProcesses,
        _Out_ PULONG LargestProcessThreads,
        _Out_ PULONG LargestSystemThreads,
        _Out_ PULONG LargestSystemProcesses
        ) PURE;
    STDMETHOD(GetCurrentSystemServer)(
        THIS_
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(GetSystemByServer)(
        THIS_
        _In_ ULONG64 Server,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetCurrentSystemServerName)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
};

#undef INTERFACE
#define INTERFACE IDebugSystemObjects4
DECLARE_INTERFACE_(IDebugSystemObjects4, IUnknown)
{
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
    STDMETHOD(GetEventThread)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetEventProcess)(
        THIS_
        _Out_ PULONG Id
        ) PURE;

    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
    STDMETHOD(GetCurrentThreadId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetCurrentThreadId)(
        THIS_
        _In_ ULONG Id
        ) PURE;
    // The current process is the process
    // that owns the current thread.
    STDMETHOD(GetCurrentProcessId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
    STDMETHOD(SetCurrentProcessId)(
        THIS_
        _In_ ULONG Id
        ) PURE;

    // Gets the number of threads in the current process.
    STDMETHOD(GetNumberThreads)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
    STDMETHOD(GetTotalNumberThreads)(
        THIS_
        _Out_ PULONG Total,
        _Out_ PULONG LargestProcess
        ) PURE;
    STDMETHOD(GetThreadIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
    STDMETHOD(GetThreadIdByProcessor)(
        THIS_
        _In_ ULONG Processor,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
    STDMETHOD(GetCurrentThreadDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
    STDMETHOD(GetCurrentThreadTeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByTeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentThreadSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
    STDMETHOD(GetCurrentThreadHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
    STDMETHOD(GetThreadIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;

    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
    STDMETHOD(GetNumberProcesses)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetProcessIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_opt_(Count) PULONG Ids,
        _Out_writes_opt_(Count) PULONG SysIds
        ) PURE;
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
    STDMETHOD(GetCurrentProcessDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByDataOffset)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
    STDMETHOD(GetCurrentProcessPeb)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdByPeb)(
        THIS_
        _In_ ULONG64 Offset,
        _Out_ PULONG Id
        ) PURE;
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetCurrentProcessSystemId)(
        THIS_
        _Out_ PULONG SysId
        ) PURE;
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
    STDMETHOD(GetProcessIdBySystemId)(
        THIS_
        _In_ ULONG SysId,
        _Out_ PULONG Id
        ) PURE;
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
    STDMETHOD(GetCurrentProcessHandle)(
        THIS_
        _Out_ PULONG64 Handle
        ) PURE;
    // Looks up a debugger process ID for the given handle.
    STDMETHOD(GetProcessIdByHandle)(
        THIS_
        _In_ ULONG64 Handle,
        _Out_ PULONG Id
        ) PURE;
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
    STDMETHOD(GetCurrentProcessExecutableName)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExeSize
        ) PURE;

    // IDebugSystemObjects2.

    // Return the number of seconds that the current
    // process has been running.
    STDMETHOD(GetCurrentProcessUpTime)(
        THIS_
        _Out_ PULONG UpTime
        ) PURE;

    // During kernel sessions the debugger retrieves
    // some information from the system thread and process
    // running on the current processor.  For example,
    // the debugger will retrieve virtual memory translation
    // information for when the debugger needs to
    // carry out its own virtual to physical translations.
    // Occasionally it can be interesting to perform
    // similar operations but on a process which isnt
    // currently running.  The follow methods allow a caller
    // to override the data offsets used by the debugger
    // so that other system threads and processes can
    // be used instead.  These values are defaulted to
    // the thread and process running on the current
    // processor each time the debuggee executes or
    // the current processor changes.
    // The thread and process settings are independent so
    // it is possible to refer to a thread in a process
    // other than the current process and vice versa.
    // Setting an offset of zero will reload the
    // default value.
    STDMETHOD(GetImplicitThreadDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetImplicitThreadDataOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;
    STDMETHOD(GetImplicitProcessDataOffset)(
        THIS_
        _Out_ PULONG64 Offset
        ) PURE;
    STDMETHOD(SetImplicitProcessDataOffset)(
        THIS_
        _In_ ULONG64 Offset
        ) PURE;

    // IDebugSystemObjects3.

    STDMETHOD(GetEventSystem)(
        THIS_
        _Out_ PULONG Id
        ) PURE;

    STDMETHOD(GetCurrentSystemId)(
        THIS_
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(SetCurrentSystemId)(
        THIS_
        _In_ ULONG Id
        ) PURE;

    STDMETHOD(GetNumberSystems)(
        THIS_
        _Out_ PULONG Number
        ) PURE;
    STDMETHOD(GetSystemIdsByIndex)(
        THIS_
        _In_ ULONG Start,
        _In_ ULONG Count,
        _Out_writes_(Count) PULONG Ids
        ) PURE;
    STDMETHOD(GetTotalNumberThreadsAndProcesses)(
        THIS_
        _Out_ PULONG TotalThreads,
        _Out_ PULONG TotalProcesses,
        _Out_ PULONG LargestProcessThreads,
        _Out_ PULONG LargestSystemThreads,
        _Out_ PULONG LargestSystemProcesses
        ) PURE;
    STDMETHOD(GetCurrentSystemServer)(
        THIS_
        _Out_ PULONG64 Server
        ) PURE;
    STDMETHOD(GetSystemByServer)(
        THIS_
        _In_ ULONG64 Server,
        _Out_ PULONG Id
        ) PURE;
    STDMETHOD(GetCurrentSystemServerName)(
        THIS_
        _Out_writes_opt_(BufferSize) PSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;

    // IDebugSystemObjects4.

    STDMETHOD(GetCurrentProcessExecutableNameWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG ExeSize
        ) PURE;

    STDMETHOD(GetCurrentSystemServerNameWide)(
        THIS_
        _Out_writes_opt_(BufferSize) PWSTR Buffer,
        _In_ ULONG BufferSize,
        _Out_opt_ PULONG NameSize
        ) PURE;
};

//----------------------------------------------------------------------------
//
// Debugger/debuggee communication.
//
// A distinguished exception, DBG_COMMAND_EXCEPTION (0x40010009),
// can be used by a debuggee to communicate with the debugger.
// The arguments of the exception must be:
// 1. Exception ID.
// 2. Command code.
// 3. Size of argument.
// 4. Pointer to argument.
//
// The arguments depend on the command code.
//
//----------------------------------------------------------------------------

#define DEBUG_COMMAND_EXCEPTION_ID 0xdbe00dbe

// Invalid command code.
#define DEBUG_CMDEX_INVALID             0x00000000

//
// The debugger can collect strings for display at the
// next event.  A debuggee can use this to register information
// about a program situation before places where an event
// may occur, such as a risky operation or assertion.
// The strings are automatically flushed on the next
// event continuation.  Strings are kept on a per-thread basis.
//
// When adding, the argument is the string to add.
// Reset has no arguments and clears all strings.
//
#define DEBUG_CMDEX_ADD_EVENT_STRING    0x00000001
#define DEBUG_CMDEX_RESET_EVENT_STRINGS 0x00000002

#ifndef DEBUG_NO_IMPLEMENTATION

FORCEINLINE void
DebugCommandException(ULONG Command, ULONG ArgSize, PVOID Arg)
{
    ULONG_PTR ExArgs[4];

    ExArgs[0] = DEBUG_COMMAND_EXCEPTION_ID;
    ExArgs[1] = Command;
    ExArgs[2] = ArgSize;
    ExArgs[3] = (ULONG_PTR)Arg;
    RaiseException(DBG_COMMAND_EXCEPTION, 0, 4, ExArgs);
}

#endif // #ifndef DEBUG_NO_IMPLEMENTATION

//----------------------------------------------------------------------------
//
// Extension callbacks.
//
//----------------------------------------------------------------------------

// Returns a version with the major version in
// the high word and the minor version in the low word.
#define DEBUG_EXTENSION_VERSION(Major, Minor) \
    ((((Major) & 0xffff) << 16) | ((Minor) & 0xffff))

//
// Descriptive flags returned from extension initialization.
//

// Extension has a !help command which can give
// per-command help.
#define DEBUG_EXTINIT_HAS_COMMAND_HELP 0x00000001

// Initialization routine.  Called once when the extension DLL
// is loaded.  Returns a version and returns flags detailing
// overall qualities of the extension DLL.
// A session may or may not be active at the time the DLL
// is loaded so initialization routines should not expect
// to be able to query session information.
typedef HRESULT (CALLBACK* PDEBUG_EXTENSION_INITIALIZE)
    (_Out_ PULONG Version, _Out_ PULONG Flags);
// Exit routine.  Called once just before attempting to unload
// the extension DLL.  If DebugExtensionCanUnload is present,
// it will be called between the return of this callback and
// an actual unload of the DLL.  If not, the extension DLL
// will be unloaded upon return of this method.  As with
// initialization, a session may or may not be active at the
// time of the call.
typedef void (CALLBACK* PDEBUG_EXTENSION_UNINITIALIZE)
    (void);
// Routine to check if a debug extension can unload after
// the uninitialization call.  If present, this is called
// between the uninitialize callback and actual unload of
// the DLL.  The extension should return either S_OK (if no
// objects are present which would prevent unload of the
// extension) or S_FALSE (if there are still outstanding
// references to model objects in the debugger extension)
//
// This is the debugger's equivalent of DllCanUnloadNow
// for extensions which manipulate the debugger's object
// model.
typedef HRESULT (CALLBACK* PDEBUG_EXTENSION_CANUNLOAD)
    (void);
// Unload routine.  If and only if DebugExtensionCanUnload
// is presnt in the debugger extension, this will be called
// after a successful CanUnload call immediately before the
// debugger actually unloads the extension DLL.
typedef void (CALLBACK* PDEBUG_EXTENSION_UNLOAD)
    (void);

// A debuggee has been discovered for the session.  It
// is not necessarily halted.
#define DEBUG_NOTIFY_SESSION_ACTIVE       0x00000000
// The session no longer has a debuggee.
#define DEBUG_NOTIFY_SESSION_INACTIVE     0x00000001
// The debuggee is halted and accessible.
#define DEBUG_NOTIFY_SESSION_ACCESSIBLE   0x00000002
// The debuggee is running or inaccessible.
#define DEBUG_NOTIFY_SESSION_INACCESSIBLE 0x00000003

typedef void (CALLBACK* PDEBUG_EXTENSION_NOTIFY)
    (_In_ ULONG Notify, _In_ ULONG64 Argument);

// A PDEBUG_EXTENSION_CALL function can return this code
// to indicate that it was unable to handle the request
// and that the search for an extension function should
// continue down the extension DLL chain.
// Taken from STATUS_VALIDATE_CONTINUE.
#define DEBUG_EXTENSION_CONTINUE_SEARCH \
    HRESULT_FROM_NT(0xC0000271L)

// A PDEBUG_EXTENSION_CALL function can return this code
// to indicate that the engine should unload and reload
// the extension binary.  This allows extensions to implement
// auto-update functionality.
#define DEBUG_EXTENSION_RELOAD_EXTENSION \
    HRESULT_FROM_NT(0xC00000EEL)

// Every routine in an extension DLL has the following prototype.
// The extension may be called from multiple clients so it
// should not cache the client value between calls.
typedef HRESULT (CALLBACK* PDEBUG_EXTENSION_CALL)
    (_In_ PDEBUG_CLIENT Client, _In_opt_ PCSTR Args);

//
// KnownStructOutput[Ex] flags
//

// Return names of supported structs.
#define DEBUG_KNOWN_STRUCT_GET_NAMES              1
// Return value output for type.
#define DEBUG_KNOWN_STRUCT_GET_SINGLE_LINE_OUTPUT 2
// Return S_OK if suppressing type name.
#define DEBUG_KNOWN_STRUCT_SUPPRESS_TYPE_NAME     3

// Extensions may export this callback in order to dump structs that
// are well known to them.  The engine calls this to inject extension
// output into dt's struct dump.
typedef HRESULT (CALLBACK* PDEBUG_EXTENSION_KNOWN_STRUCT)
    (_In_ ULONG Flags,
     _In_ ULONG64 Offset,
     _In_opt_ PSTR TypeName,
     _Out_writes_opt_(*BufferChars) PSTR Buffer,
     _Inout_opt_ PULONG BufferChars);
typedef HRESULT (CALLBACK* PDEBUG_EXTENSION_KNOWN_STRUCT_EX)
    (_In_ PDEBUG_CLIENT Client,
     _In_ ULONG Flags,
     _In_ ULONG64 Offset,
     _In_opt_ PCSTR TypeName,
     _Out_writes_opt_(*BufferChars) PSTR Buffer,
     _Inout_opt_ PULONG BufferChars);

// Backwards compatibility with old, incorrect name.
typedef PDEBUG_EXTENSION_KNOWN_STRUCT PDEBUG_ENTENSION_KNOWNSTRUCT;

//
// Extensions can provide pseudo-register values that
// operate similiarly to the debugger's built-in $teb, etc.
//

#define DEBUG_EXT_QVALUE_DEFAULT 0x00000000

typedef HRESULT (CALLBACK* PDEBUG_EXTENSION_QUERY_VALUE_NAMES)
    (_In_ PDEBUG_CLIENT Client,
     _In_ ULONG Flags,
     _Out_writes_(BufferChars) PWSTR Buffer,
     _In_ ULONG BufferChars,
     _Out_ PULONG BufferNeeded);

#define DEBUG_EXT_PVALUE_DEFAULT 0x00000000

#define DEBUG_EXT_PVTYPE_IS_VALUE   0x00000000
#define DEBUG_EXT_PVTYPE_IS_POINTER 0x00000001

typedef HRESULT (CALLBACK* PDEBUG_EXTENSION_PROVIDE_VALUE)
    (_In_ PDEBUG_CLIENT Client,
     _In_ ULONG Flags,
     _In_ PCWSTR Name,
     _Out_ PULONG64 Value,
     _Out_ PULONG64 TypeModBase,
     _Out_ PULONG TypeId,
     _Out_ PULONG TypeFlags);

//----------------------------------------------------------------------------
//
// Extension functions.
//
// Extension functions differ from extension callbacks in that
// they are arbitrary functions exported from an extension DLL
// for other code callers instead of for human invocation from
// debugger commands.  Extension function pointers are retrieved
// for an extension DLL with IDebugControl::GetExtensionFunction.
//
// Extension function names must begin with _EFN_.  Other than that
// they can have any name and prototype.  Extension functions
// must be public exports of their extension DLL.  They should
// have a typedef for their function pointer prototype in an
// extension header so that callers have a header file to include
// with a type that allows a correctly-formed invocation of the
// extension function.
//
// The engine does not perform any validation of calls to
// extension functions.  Once the extension function pointer
// is retrieved with GetExtensionFunction all calls go
// directly between the caller and the extension function and
// are not mediated by the engine.
//
//----------------------------------------------------------------------------

#ifdef __cplusplus
};

//----------------------------------------------------------------------------
//
// Dump stack provider callbacks
//
//----------------------------------------------------------------------------

// If a specific dump stream type is present,
// dbgeng will pass the stream to dump stack
// provider prior to thread enumeration.
// Implemented by dump stack provider
// BeginThreadStackReconstruction
typedef HRESULT (CALLBACK* PDEBUG_STACK_PROVIDER_BEGINTHREADSTACKRECONSTRUCTION)
    (
    _In_ ULONG StreamType,
    _In_reads_(BufferSize) PVOID MiniDumpStreamBuffer,
    _In_ ULONG BufferSize);

// Queries dump stream provider per-thread
// Stack frames and symbolic data are returned
// New inline frames may be provided
// stackdmpprovider must be enabled
// ReconstructStack
typedef HRESULT (CALLBACK* PDEBUG_STACK_PROVIDER_RECONSTRUCTSTACK)
    (
    _In_ ULONG SystemThreadId,
    _In_reads_(CountNativeFrames) PDEBUG_STACK_FRAME_EX NativeFrames,
    _In_ ULONG CountNativeFrames,
    _Outptr_result_buffer_(*StackSymFramesFilled) PSTACK_SYM_FRAME_INFO *StackSymFrames,
    _Out_ PULONG StackSymFramesFilled);

//After ReconstructStack is called and used dbgeng will call the stack provider to free memory
// FreeStackSymFrames
typedef HRESULT (CALLBACK* PDEBUG_STACK_PROVIDER_FREESTACKSYMFRAMES)
    (
    _In_opt_ PSTACK_SYM_FRAME_INFO StackSymFrames);

// Dbgeng is done with thread stack reconstruction
// Dump stack provider may clean up state
// EndThreadStackReconstruction
typedef HRESULT (CALLBACK* PDEBUG_STACK_PROVIDER_ENDTHREADSTACKRECONSTRUCTION)
    (void);


//----------------------------------------------------------------------------
//
// C++ implementation helper classes.
//
//----------------------------------------------------------------------------

#if !defined(DEBUG_NO_IMPLEMENTATION) && !defined(_M_CEE_PURE)

// warning C5204: 'DebugBaseEventCallbacks': class has virtual functions,
// but its trivial destructor is not virtual; instances of objects derived
// from this class may not be destructed correctly.
#pragma warning(push)
#pragma warning(disable:5204)

//
// DebugBaseEventCallbacks provides a do-nothing base implementation
// of IDebugEventCallbacks.  A program can derive their own
// event callbacks class from DebugBaseEventCallbacks and implement
// only the methods they are interested in.  Programs must be
// careful to implement GetInterestMask appropriately.
//
class DebugBaseEventCallbacks : public IDebugEventCallbacks
{
public:
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        )
    {
        *Interface = NULL;

#if _MSC_VER >= 1100
        if (IsEqualIID(InterfaceId, __uuidof(IUnknown)) ||
            IsEqualIID(InterfaceId, __uuidof(IDebugEventCallbacks)))
#else
        if (IsEqualIID(InterfaceId, IID_IUnknown) ||
            IsEqualIID(InterfaceId, IID_IDebugEventCallbacks))
#endif
        {
            *Interface = (IDebugEventCallbacks *)this;
            AddRef();
            return S_OK;
        }
        else
        {
            return E_NOINTERFACE;
        }
    }

    // IDebugEventCallbacks.

    STDMETHOD(Breakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT Bp
        )
    {
        UNREFERENCED_PARAMETER(Bp);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(Exception)(
        THIS_
        _In_ PEXCEPTION_RECORD64 Exception,
        _In_ ULONG FirstChance
        )
    {
        UNREFERENCED_PARAMETER(Exception);
        UNREFERENCED_PARAMETER(FirstChance);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(CreateThread)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG64 DataOffset,
        _In_ ULONG64 StartOffset
        )
    {
        UNREFERENCED_PARAMETER(Handle);
        UNREFERENCED_PARAMETER(DataOffset);
        UNREFERENCED_PARAMETER(StartOffset);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(ExitThread)(
        THIS_
        _In_ ULONG ExitCode
        )
    {
        UNREFERENCED_PARAMETER(ExitCode);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 Handle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_ PCSTR ModuleName,
        _In_ PCSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp,
        _In_ ULONG64 InitialThreadHandle,
        _In_ ULONG64 ThreadDataOffset,
        _In_ ULONG64 StartOffset
        )
    {
        UNREFERENCED_PARAMETER(ImageFileHandle);
        UNREFERENCED_PARAMETER(Handle);
        UNREFERENCED_PARAMETER(BaseOffset);
        UNREFERENCED_PARAMETER(ModuleSize);
        UNREFERENCED_PARAMETER(ModuleName);
        UNREFERENCED_PARAMETER(ImageName);
        UNREFERENCED_PARAMETER(CheckSum);
        UNREFERENCED_PARAMETER(TimeDateStamp);
        UNREFERENCED_PARAMETER(InitialThreadHandle);
        UNREFERENCED_PARAMETER(ThreadDataOffset);
        UNREFERENCED_PARAMETER(StartOffset);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(ExitProcess)(
        THIS_
        _In_ ULONG ExitCode
        )
    {
        UNREFERENCED_PARAMETER(ExitCode);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(LoadModule)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_ PCSTR ModuleName,
        _In_ PCSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp
        )
    {
        UNREFERENCED_PARAMETER(ImageFileHandle);
        UNREFERENCED_PARAMETER(BaseOffset);
        UNREFERENCED_PARAMETER(ModuleSize);
        UNREFERENCED_PARAMETER(ModuleName);
        UNREFERENCED_PARAMETER(ImageName);
        UNREFERENCED_PARAMETER(CheckSum);
        UNREFERENCED_PARAMETER(TimeDateStamp);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(UnloadModule)(
        THIS_
        _In_ PCSTR ImageBaseName,
        _In_ ULONG64 BaseOffset
        )
    {
        UNREFERENCED_PARAMETER(ImageBaseName);
        UNREFERENCED_PARAMETER(BaseOffset);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(SystemError)(
        THIS_
        _In_ ULONG Error,
        _In_ ULONG Level
        )
    {
        UNREFERENCED_PARAMETER(Error);
        UNREFERENCED_PARAMETER(Level);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(SessionStatus)(
        THIS_
        _In_ ULONG Status
        )
    {
        UNREFERENCED_PARAMETER(Status);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(ChangeDebuggeeState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        )
    {
        UNREFERENCED_PARAMETER(Flags);
        UNREFERENCED_PARAMETER(Argument);
        return S_OK;
    }
    STDMETHOD(ChangeEngineState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        )
    {
        UNREFERENCED_PARAMETER(Flags);
        UNREFERENCED_PARAMETER(Argument);
        return S_OK;
    }
    STDMETHOD(ChangeSymbolState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        )
    {
        UNREFERENCED_PARAMETER(Flags);
        UNREFERENCED_PARAMETER(Argument);
        return S_OK;
    }
};

#pragma warning(pop)

// warning C5204: 'DebugBaseEventCallbacksWide': class has virtual functions,
// but its trivial destructor is not virtual; instances of objects derived
// from this class may not be destructed correctly.
#pragma warning(push)
#pragma warning(disable:5204)

class DebugBaseEventCallbacksWide : public IDebugEventCallbacksWide
{
public:
    // IUnknown.
    STDMETHOD(QueryInterface)(
        THIS_
        _In_ REFIID InterfaceId,
        _Out_ PVOID* Interface
        )
    {
        *Interface = NULL;

#if _MSC_VER >= 1100
        if (IsEqualIID(InterfaceId, __uuidof(IUnknown)) ||
            IsEqualIID(InterfaceId, __uuidof(IDebugEventCallbacksWide)))
#else
        if (IsEqualIID(InterfaceId, IID_IUnknown) ||
            IsEqualIID(InterfaceId, IID_IDebugEventCallbacksWide))
#endif
        {
            *Interface = (IDebugEventCallbacksWide *)this;
            AddRef();
            return S_OK;
        }
        else
        {
            return E_NOINTERFACE;
        }
    }

    // IDebugEventCallbacksWide.

    STDMETHOD(Breakpoint)(
        THIS_
        _In_ PDEBUG_BREAKPOINT2 Bp
        )
    {
        UNREFERENCED_PARAMETER(Bp);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(Exception)(
        THIS_
        _In_ PEXCEPTION_RECORD64 Exception,
        _In_ ULONG FirstChance
        )
    {
        UNREFERENCED_PARAMETER(Exception);
        UNREFERENCED_PARAMETER(FirstChance);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(CreateThread)(
        THIS_
        _In_ ULONG64 Handle,
        _In_ ULONG64 DataOffset,
        _In_ ULONG64 StartOffset
        )
    {
        UNREFERENCED_PARAMETER(Handle);
        UNREFERENCED_PARAMETER(DataOffset);
        UNREFERENCED_PARAMETER(StartOffset);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(ExitThread)(
        THIS_
        _In_ ULONG ExitCode
        )
    {
        UNREFERENCED_PARAMETER(ExitCode);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(CreateProcess)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 Handle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_ PCWSTR ModuleName,
        _In_ PCWSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp,
        _In_ ULONG64 InitialThreadHandle,
        _In_ ULONG64 ThreadDataOffset,
        _In_ ULONG64 StartOffset
        )
    {
        UNREFERENCED_PARAMETER(ImageFileHandle);
        UNREFERENCED_PARAMETER(Handle);
        UNREFERENCED_PARAMETER(BaseOffset);
        UNREFERENCED_PARAMETER(ModuleSize);
        UNREFERENCED_PARAMETER(ModuleName);
        UNREFERENCED_PARAMETER(ImageName);
        UNREFERENCED_PARAMETER(CheckSum);
        UNREFERENCED_PARAMETER(TimeDateStamp);
        UNREFERENCED_PARAMETER(InitialThreadHandle);
        UNREFERENCED_PARAMETER(ThreadDataOffset);
        UNREFERENCED_PARAMETER(StartOffset);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(ExitProcess)(
        THIS_
        _In_ ULONG ExitCode
        )
    {
        UNREFERENCED_PARAMETER(ExitCode);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(LoadModule)(
        THIS_
        _In_ ULONG64 ImageFileHandle,
        _In_ ULONG64 BaseOffset,
        _In_ ULONG ModuleSize,
        _In_ PCWSTR ModuleName,
        _In_ PCWSTR ImageName,
        _In_ ULONG CheckSum,
        _In_ ULONG TimeDateStamp
        )
    {
        UNREFERENCED_PARAMETER(ImageFileHandle);
        UNREFERENCED_PARAMETER(BaseOffset);
        UNREFERENCED_PARAMETER(ModuleSize);
        UNREFERENCED_PARAMETER(ModuleName);
        UNREFERENCED_PARAMETER(ImageName);
        UNREFERENCED_PARAMETER(CheckSum);
        UNREFERENCED_PARAMETER(TimeDateStamp);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(UnloadModule)(
        THIS_
        _In_ PCWSTR ImageBaseName,
        _In_ ULONG64 BaseOffset
        )
    {
        UNREFERENCED_PARAMETER(ImageBaseName);
        UNREFERENCED_PARAMETER(BaseOffset);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(SystemError)(
        THIS_
        _In_ ULONG Error,
        _In_ ULONG Level
        )
    {
        UNREFERENCED_PARAMETER(Error);
        UNREFERENCED_PARAMETER(Level);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(SessionStatus)(
        THIS_
        _In_ ULONG Status
        )
    {
        UNREFERENCED_PARAMETER(Status);
        return DEBUG_STATUS_NO_CHANGE;
    }
    STDMETHOD(ChangeDebuggeeState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        )
    {
        UNREFERENCED_PARAMETER(Flags);
        UNREFERENCED_PARAMETER(Argument);
        return S_OK;
    }
    STDMETHOD(ChangeEngineState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        )
    {
        UNREFERENCED_PARAMETER(Flags);
        UNREFERENCED_PARAMETER(Argument);
        return S_OK;
    }
    STDMETHOD(ChangeSymbolState)(
        THIS_
        _In_ ULONG Flags,
        _In_ ULONG64 Argument
        )
    {
        UNREFERENCED_PARAMETER(Flags);
        UNREFERENCED_PARAMETER(Argument);
        return S_OK;
    }
};

#pragma warning(pop)

#endif // #ifndef DEBUG_NO_IMPLEMENTATION

#ifdef DEBUG_UNICODE_MACROS

#ifdef UNICODE

#define IDebugEventCallbacksT IDebugEventCallbacksWide
#define IID_IDebugEventCallbacksT IID_IDebugEventCallbacksWide
#define IDebugOutputCallbacksT IDebugOutputCallbacksWide
#define IID_IDebugOutputCallbacksT IID_IDebugOutputCallbacksWide
#define DebugBaseEventCallbacksT DebugBaseEventCallbacksWide

#define DebugConnectT DebugConnectWide
#define GetSourceFileInformationT GetSourceFileInformationWide
#define FindSourceFileAndTokenT FindSourceFileAndTokenWide
#define GetSymbolInformationT GetSymbolInformationWide
#define GetSymbolInformationExT GetSymbolInformationWideEx
#define GetCommandT GetCommandWide
#define SetCommandT SetCommandWide
#define GetOffsetExpressionT GetOffsetExpressionWide
#define SetOffsetExpressionT SetOffsetExpressionWide
#define GetRunningProcessSystemIdByExecutableNameT GetRunningProcessSystemIdByExecutableNameWide
#define GetRunningProcessDescriptionT GetRunningProcessDescriptionWide
#define CreateProcessT CreateProcessWide
#define CreateProcessAndAttachT CreateProcessAndAttachWide
#define AddDumpInformationFileT AddDumpInformationFileWide
#define GetDumpFileT GetDumpFileWide
#define AttachKernelT AttachKernelWide
#define GetKernelConnectionOptionsT GetKernelConnectionOptionsWide
#define SetKernelConnectionOptionsT SetKernelConnectionOptionsWide
#define StartProcessServerT StartProcessServerWide
#define ConnectProcessServerT ConnectProcessServerWide
#define StartServerT StartServerWide
#define OutputServersT OutputServersWide
#define GetOutputCallbacksT GetOutputCallbacksWide
#define SetOutputCallbacksT SetOutputCallbacksWide
#define GetOutputLinePrefixT GetOutputLinePrefixWide
#define SetOutputLinePrefixT SetOutputLinePrefixWide
#define GetIdentityT GetIdentityWide
#define OutputIdentityT OutputIdentityWide
#define GetEventCallbacksT GetEventCallbacksWide
#define SetEventCallbacksT SetEventCallbacksWide
#define CreateProcess2T CreateProcess2Wide
#define CreateProcessAndAttach2T CreateProcessAndAttach2Wide
#define PushOutputLinePrefixT PushOutputLinePrefixWide
#define GetQuitLockStringT GetQuitLockStringWide
#define SetQuitLockStringT SetQuitLockStringWide
#define GetLogFileT GetLogFileWide
#define OpenLogFileT OpenLogFileWide
#define InputT InputWide
#define ReturnInputT ReturnInputWide
#define OutputT OutputWide
#define OutputVaListT OutputVaListWide
#define ControlledOutputT ControlledOutputWide
#define ControlledOutputVaListT ControlledOutputVaListWide
#define OutputPromptT OutputPromptWide
#define OutputPromptVaListT OutputPromptVaListWide
#define GetPromptTextT GetPromptTextWide
#define AssembleT AssembleWide
#define DisassembleT DisassembleWide
#define GetProcessorTypeNamesT GetProcessorTypeNamesWide
#define GetTextMacroT GetTextMacroWide
#define SetTextMacroT SetTextMacroWide
#define EvaluateT EvaluateWide
#define ExecuteT ExecuteWide
#define ExecuteCommandFileT ExecuteCommandFileWide
#define AddExtensionT AddExtensionWide
#define GetExtensionByPathT GetExtensionByPathWide
#define CallExtensionT CallExtensionWide
#define GetExtensionFunctionT GetExtensionFunctionWide
#define GetEventFilterTextT GetEventFilterTextWide
#define GetEventFilterCommandT GetEventFilterCommandWide
#define SetEventFilterCommandT SetEventFilterCommandWide
#define GetSpecificFilterArgumentT GetSpecificFilterArgumentWide
#define SetSpecificFilterArgumentT SetSpecificFilterArgumentWide
#define GetExceptionFilterSecondCommandT GetExceptionFilterSecondCommandWide
#define SetExceptionFilterSecondCommandT SetExceptionFilterSecondCommandWide
#define GetLastEventInformationT GetLastEventInformationWide
#define GetTextReplacementT GetTextReplacementWide
#define SetTextReplacementT SetTextReplacementWide
#define SetExpressionSyntaxByNameT SetExpressionSyntaxByNameWide
#define GetExpressionSyntaxNamesT GetExpressionSyntaxNamesWide
#define GetEventIndexDescriptionT GetEventIndexDescriptionWide
#define GetLogFile2T GetLogFile2Wide
#define OpenLogFile2T OpenLogFile2Wide
#define GetSystemVersionStringT GetSystemVersionStringWide
#define ReadMultiByteStringVirtualT ReadMultiByteStringVirtualWide
#define ReadUnicodeStringVirtualT ReadUnicodeStringVirtualWide
#define GetDescriptionT GetDescriptionWide
#define GetIndexByNameT GetIndexByNameWide
#define GetPseudoDescriptionT GetPseudoDescriptionWide
#define GetPseudoIndexByNameT GetPseudoIndexByNameWide
#define AddSymbolT AddSymbolWide
#define RemoveSymbolByNameT RemoveSymbolByNameWide
#define GetSymbolNameT GetSymbolNameWide
#define WriteSymbolT WriteSymbolWide
#define OutputAsTypeT OutputAsTypeWide
#define GetSymbolTypeNameT GetSymbolTypeNameWide
#define GetSymbolValueTextT GetSymbolValueTextWide
#define GetNameByOffsetT GetNameByOffsetWide
#define GetNameByInlineContextT GetNameByInlineContextWide
#define GetOffsetByNameT GetOffsetByNameWide
#define GetNearNameByOffsetT GetNearNameByOffsetWide
#define GetLineByOffsetT GetLineByOffsetWide
#define GetLineByInlineContextT GetLineByInlineContextWide
#define GetOffsetByLineT GetOffsetByLineWide
#define GetModuleByModuleNameT GetModuleByModuleNameWide
#define GetModuleByModuleName2T GetModuleByModuleName2Wide
#define GetSymbolModuleT GetSymbolModuleWide
#define GetTypeNameT GetTypeNameWide
#define GetTypeIdT GetTypeIdWide
#define GetFieldOffsetT GetFieldOffsetWide
#define GetSymbolTypeIdT GetSymbolTypeIdWide
#define StartSymbolMatchT StartSymbolMatchWide
#define GetNextSymbolMatchT GetNextSymbolMatchWide
#define ReloadT ReloadWide
#define GetSymbolPathT GetSymbolPathWide
#define SetSymbolPathT SetSymbolPathWide
#define AppendSymbolPathT AppendSymbolPathWide
#define GetImagePathT GetImagePathWide
#define SetImagePathT SetImagePathWide
#define AppendImagePathT AppendImagePathWide
#define GetSourcePathT GetSourcePathWide
#define GetSourcePathElementT GetSourcePathElementWide
#define SetSourcePathT SetSourcePathWide
#define AppendSourcePathT AppendSourcePathWide
#define FindSourceFileT FindSourceFileWide
#define GetSourceFileLineOffsetsT GetSourceFileLineOffsetsWide
#define GetModuleVersionInformationT GetModuleVersionInformationWide
#define GetModuleNameStringT GetModuleNameStringWide
#define GetConstantNameT GetConstantNameWide
#define GetFieldNameT GetFieldNameWide
#define GetFieldTypeAndOffsetT GetFieldTypeAndOffsetWide
#define GetSymbolEntriesByNameT GetSymbolEntriesByNameWide
#define GetSymbolEntryStringT GetSymbolEntryStringWide
#define GetSourceEntriesByLineT GetSourceEntriesByLineWide
#define GetSourceEntryStringT GetSourceEntryStringWide
#define GetCurrentProcessExecutableNameT GetCurrentProcessExecutableNameWide
#define GetCurrentSystemServerNameT GetCurrentSystemServerNameWide

#else // #ifdef UNICODE

#define IDebugEventCallbacksT IDebugEventCallbacks
#define IID_IDebugEventCallbacksT IID_IDebugEventCallbacks
#define IDebugOutputCallbacksT IDebugOutputCallbacks
#define IID_IDebugOutputCallbacksT IID_IDebugOutputCallbacks
#define DebugBaseEventCallbacksT DebugBaseEventCallbacks

#define DebugConnectT DebugConnect
#define GetSourceFileInformationT GetSourceFileInformation
#define FindSourceFileAndTokenT FindSourceFileAndToken
#define GetSymbolInformationT GetSymbolInformation
#define GetCommandT GetCommand
#define SetCommandT SetCommand
#define GetOffsetExpressionT GetOffsetExpression
#define SetOffsetExpressionT SetOffsetExpression
#define GetRunningProcessSystemIdByExecutableNameT GetRunningProcessSystemIdByExecutableName
#define GetRunningProcessDescriptionT GetRunningProcessDescription
#define CreateProcessT CreateProcess
#define CreateProcessAndAttachT CreateProcessAndAttach
#define AddDumpInformationFileT AddDumpInformationFile
#define GetDumpFileT GetDumpFile
#define AttachKernelT AttachKernel
#define GetKernelConnectionOptionsT GetKernelConnectionOptions
#define SetKernelConnectionOptionsT SetKernelConnectionOptions
#define StartProcessServerT StartProcessServer
#define ConnectProcessServerT ConnectProcessServer
#define StartServerT StartServer
#define OutputServersT OutputServers
#define GetOutputCallbacksT GetOutputCallbacks
#define SetOutputCallbacksT SetOutputCallbacks
#define GetOutputLinePrefixT GetOutputLinePrefix
#define SetOutputLinePrefixT SetOutputLinePrefix
#define GetIdentityT GetIdentity
#define OutputIdentityT OutputIdentity
#define GetEventCallbacksT GetEventCallbacks
#define SetEventCallbacksT SetEventCallbacks
#define CreateProcess2T CreateProcess2
#define CreateProcessAndAttach2T CreateProcessAndAttach2
#define PushOutputLinePrefixT PushOutputLinePrefix
#define GetQuitLockStringT GetQuitLockString
#define SetQuitLockStringT SetQuitLockString
#define GetLogFileT GetLogFile
#define OpenLogFileT OpenLogFile
#define InputT Input
#define ReturnInputT ReturnInput
#define OutputT Output
#define OutputVaListT OutputVaList
#define ControlledOutputT ControlledOutput
#define ControlledOutputVaListT ControlledOutputVaList
#define OutputPromptT OutputPrompt
#define OutputPromptVaListT OutputPromptVaList
#define GetPromptTextT GetPromptText
#define AssembleT Assemble
#define DisassembleT Disassemble
#define GetProcessorTypeNamesT GetProcessorTypeNames
#define GetTextMacroT GetTextMacro
#define SetTextMacroT SetTextMacro
#define EvaluateT Evaluate
#define ExecuteT Execute
#define ExecuteCommandFileT ExecuteCommandFile
#define AddExtensionT AddExtension
#define GetExtensionByPathT GetExtensionByPath
#define CallExtensionT CallExtension
#define GetExtensionFunctionT GetExtensionFunction
#define GetEventFilterTextT GetEventFilterText
#define GetEventFilterCommandT GetEventFilterCommand
#define SetEventFilterCommandT SetEventFilterCommand
#define GetSpecificFilterArgumentT GetSpecificFilterArgument
#define SetSpecificFilterArgumentT SetSpecificFilterArgument
#define GetExceptionFilterSecondCommandT GetExceptionFilterSecondCommand
#define SetExceptionFilterSecondCommandT SetExceptionFilterSecondCommand
#define GetLastEventInformationT GetLastEventInformation
#define GetTextReplacementT GetTextReplacement
#define SetTextReplacementT SetTextReplacement
#define SetExpressionSyntaxByNameT SetExpressionSyntaxByName
#define GetExpressionSyntaxNamesT GetExpressionSyntaxNames
#define GetEventIndexDescriptionT GetEventIndexDescription
#define GetLogFile2T GetLogFile2
#define OpenLogFile2T OpenLogFile2
#define GetSystemVersionStringT GetSystemVersionString
#define ReadMultiByteStringVirtualT ReadMultiByteStringVirtual
#define ReadUnicodeStringVirtualT ReadUnicodeStringVirtual
#define GetDescriptionT GetDescription
#define GetIndexByNameT GetIndexByName
#define GetPseudoDescriptionT GetPseudoDescription
#define GetPseudoIndexByNameT GetPseudoIndexByName
#define AddSymbolT AddSymbol
#define RemoveSymbolByNameT RemoveSymbolByName
#define GetSymbolNameT GetSymbolName
#define WriteSymbolT WriteSymbol
#define OutputAsTypeT OutputAsType
#define GetSymbolTypeNameT GetSymbolTypeName
#define GetSymbolValueTextT GetSymbolValueText
#define GetNameByOffsetT GetNameByOffset
#define GetNameByInlineContextT GetNameByInlineContext
#define GetOffsetByNameT GetOffsetByName
#define GetNearNameByOffsetT GetNearNameByOffset
#define GetLineByOffsetT GetLineByOffset
#define GetLineByInlineContextT GetLineByInlineContext
#define GetOffsetByLineT GetOffsetByLine
#define GetModuleByModuleNameT GetModuleByModuleName
#define GetModuleByModuleName2T GetModuleByModuleName2
#define GetSymbolModuleT GetSymbolModule
#define GetTypeNameT GetTypeName
#define GetTypeIdT GetTypeId
#define GetFieldOffsetT GetFieldOffset
#define GetSymbolTypeIdT GetSymbolTypeId
#define StartSymbolMatchT StartSymbolMatch
#define GetNextSymbolMatchT GetNextSymbolMatch
#define ReloadT Reload
#define GetSymbolPathT GetSymbolPath
#define SetSymbolPathT SetSymbolPath
#define AppendSymbolPathT AppendSymbolPath
#define GetImagePathT GetImagePath
#define SetImagePathT SetImagePath
#define AppendImagePathT AppendImagePath
#define GetSourcePathT GetSourcePath
#define GetSourcePathElementT GetSourcePathElement
#define SetSourcePathT SetSourcePath
#define AppendSourcePathT AppendSourcePath
#define FindSourceFileT FindSourceFile
#define GetSourceFileLineOffsetsT GetSourceFileLineOffsets
#define GetModuleVersionInformationT GetModuleVersionInformation
#define GetModuleNameStringT GetModuleNameString
#define GetConstantNameT GetConstantName
#define GetFieldNameT GetFieldName
#define GetFieldTypeAndOffsetT GetFieldTypeAndOffset
#define GetSymbolEntriesByNameT GetSymbolEntriesByName
#define GetSymbolEntryStringT GetSymbolEntryString
#define GetSourceEntriesByLineT GetSourceEntriesByLine
#define GetSourceEntryStringT GetSourceEntryString
#define GetCurrentProcessExecutableNameT GetCurrentProcessExecutableName
#define GetCurrentSystemServerNameT GetCurrentSystemServerName

#endif // #ifdef UNICODE

#endif // #ifdef DEBUG_UNICODE_MACROS

#endif // #ifdef __cplusplus

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_WER) */
#pragma endregion

#endif // #ifndef __DBGENG_H__

