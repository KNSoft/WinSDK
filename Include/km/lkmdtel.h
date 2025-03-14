/*++
Copyright (c) Microsoft Corporation

Module Name:

    lkmdtel.h

Abstract:

    Telemetry Library for creating WER live dumps

--*/

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#ifdef __cplusplus
extern "C" {
#endif

#if (NTDDI_VERSION >= NTDDI_WINBLUE)

//
// Note: The driver should call ExInitializeDriverRuntime during driver
// initialization, before calling APIs in this library. While it is safe
// to call on any platform, if compiling for Windows 10 version 2004 and later,
// the call will prevent double zeroing of the allocations since the OS returns
// a zeroed allocation already and ExAllocatePoolZero will also zero it.
//

#define POOL_ZERO_DOWN_LEVEL_SUPPORT

//
// Prototypes
//

_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
LkmdTelCloseHandle(
    _In_ HANDLE TelemetryHandle
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
HANDLE
LkmdTelCreateReport(
    _In_ PWCHAR ReportType,
    _In_ ULONG BugCheckCode,
    _In_ ULONG_PTR BugCheckParam1,
    _In_ ULONG_PTR BugCheckParam2,
    _In_ ULONG_PTR BugCheckParam3,
    _In_ ULONG_PTR BugCheckParam4
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
LkmdTelSetSecondaryData(
    _In_ HANDLE TelemetryHandle,
    _In_ LPCGUID SecondaryDataGuid,
    _In_ ULONG SecondaryDataSize,
    _In_reads_bytes_(SecondaryDataSize) PVOID SecondaryDataBuffer
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
LkmdTelSubmitReport(
    _In_ HANDLE  TelemetryHandle
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
LkmdTelInsertTriageDataBlock (
    _In_ HANDLE TelemetryHandle,
    _In_reads_bytes_(TriageDataSize) PVOID TriageData,
    _In_ ULONG TriageDataSize
    );

#endif // (NTDDI_VERSION >= NTDDI_WINBLUE)

#ifdef __cplusplus
    }
#endif

