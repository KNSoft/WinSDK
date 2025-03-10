/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    videoagp.h

Abstract:
    Video miniport AGP support.

Notes:

Revision History:

--*/

#ifndef __VIDEOAGP_H__
#define __VIDEOAGP_H__

//
// AGP is no longer supported
//
#if defined(FKG_FORCED_USAGE) || defined(WINPHONE) || defined(BUILD_WINDOWS)
# define VIDEOAGP_DEPRECATED
#else
# define VIDEOAGP_DEPRECATED __declspec(deprecated)
#endif

#define VIDEO_AGP_RATE_1X       1
#define VIDEO_AGP_RATE_2X       2
#define VIDEO_AGP_RATE_4X       4
#define VIDEO_AGP_RATE_8X       8

typedef enum
{
    VpNonCached = 0,
    VpWriteCombined,
    VpCached
} VIDEO_PORT_CACHE_TYPE;

typedef
PHYSICAL_ADDRESS
(STDAPICALLTYPE *PAGP_RESERVE_PHYSICAL)(
    IN PVOID HwDeviceExtension,
    IN ULONG Pages,
    IN VIDEO_PORT_CACHE_TYPE Caching,
    OUT PVOID *PhysicalReserveContext
    );

typedef
VOID
(STDAPICALLTYPE *PAGP_RELEASE_PHYSICAL)(
    IN PVOID HwDeviceExtension,
    IN PVOID PhysicalReserveContext
    );

typedef
BOOLEAN
(STDAPICALLTYPE *PAGP_COMMIT_PHYSICAL)(
    IN PVOID HwDeviceExtension,
    IN PVOID PhysicalReserveContext,
    IN ULONG Pages,
    IN ULONG Offset
    );

typedef
VOID
(STDAPICALLTYPE *PAGP_FREE_PHYSICAL)(
    IN PVOID HwDeviceExtension,
    IN PVOID PhysicalReserveContext,
    IN ULONG Pages,
    IN ULONG Offset
    );

typedef
PVOID
(STDAPICALLTYPE *PAGP_RESERVE_VIRTUAL)(
    IN PVOID HwDeviceExtension,
    IN HANDLE ProcessHandle,
    IN PVOID PhysicalReserveContext,
    OUT PVOID *VirtualReserveContext
    );

typedef
VOID
(STDAPICALLTYPE *PAGP_RELEASE_VIRTUAL)(
    IN PVOID HwDeviceExtension,
    IN PVOID VirtualReserveContext
    );

typedef
PVOID
(STDAPICALLTYPE *PAGP_COMMIT_VIRTUAL)(
    IN PVOID HwDeviceExtension,
    IN PVOID VirtualReserveContext,
    IN ULONG Pages,
    IN ULONG Offset
    );

typedef
VOID
(STDAPICALLTYPE *PAGP_FREE_VIRTUAL)(
    IN PVOID HwDeviceExtension,
    IN PVOID VirtualReserveContext,
    IN ULONG Pages,
    IN ULONG Offset
    );

typedef
BOOLEAN
(STDAPICALLTYPE *PAGP_SET_RATE)(
    IN PVOID HwDeviceExtension,
    IN ULONG AgpRate
    );

typedef struct _VIDEO_PORT_AGP_SERVICES
{
    PAGP_RESERVE_PHYSICAL AgpReservePhysical;
    PAGP_RELEASE_PHYSICAL AgpReleasePhysical;
    PAGP_COMMIT_PHYSICAL  AgpCommitPhysical;
    PAGP_FREE_PHYSICAL    AgpFreePhysical;

    PAGP_RESERVE_VIRTUAL  AgpReserveVirtual;
    PAGP_RELEASE_VIRTUAL  AgpReleaseVirtual;
    PAGP_COMMIT_VIRTUAL   AgpCommitVirtual;
    PAGP_FREE_VIRTUAL     AgpFreeVirtual;
    ULONGLONG AllocationLimit;

} VIDEO_PORT_AGP_SERVICES, *PVIDEO_PORT_AGP_SERVICES;

VIDEOAGP_DEPRECATED
_IRQL_requires_max_(PASSIVE_LEVEL) 
__drv_preferredFunction("VideoPortQueryServices", "Obsolete") 
BOOLEAN
STDAPICALLTYPE
VideoPortGetAgpServices(
    IN PVOID HwDeviceExtension,
    IN PVIDEO_PORT_AGP_SERVICES AgpServices
    );

#endif // ifndef __VIDEOAGP_H__
