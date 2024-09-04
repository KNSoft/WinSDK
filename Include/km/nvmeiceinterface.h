/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Abstract:

    This header defines the public NVME_ICE_INTERFACE interface, which NVMe ICE
    drivers can expose to facilitate offloading crypto for NVMe devices.

Environment:

    Kernel mode

--*/

#pragma once

#include <guiddef.h>
#include <nvme.h>
#ifndef _NTSTORPORTP_
#include <storport.h>
#endif // !defined _NTSTORPORTP_

//
// GUID_DEVINTERFACE_NVME_ICE is the device interface class for NVMe ICE devices.
//
// {0d08b5d3-4ffe-4017-8c99-ea62f389648c}
//
DEFINE_GUID( GUID_DEVINTERFACE_NVME_ICE, 0x0d08b5d3, 0x4ffe, 0x4017, 0x8c, 0x99, 0xea, 0x62, 0xf3, 0x89, 0x64, 0x8c);

//
// GUID_NVME_ICE_INTERFACE is the interface that is exposed by NVMe ICE drivers.
//
// {ff05a26d-65df-4437-819b-3a7b20b41d42}
//
DEFINE_GUID( GUID_NVME_ICE_INTERFACE, 0xff05a26d, 0x65df, 0x4437, 0x81, 0x9b, 0x3a, 0x7b, 0x20, 0xb4, 0x1d, 0x42);

typedef struct NVME_PCI_ADDRESS {

    // PCI SBDF of device.
    ULONG Function: 3;
    ULONG Device: 5;
    ULONG Bus: 8;
    ULONG Segment: 16;

} NVME_PCI_ADDRESS;

#pragma warning(push)
#pragma warning(disable:4201) // nameless struct/unions

#define NVME_ICE_CAPABILITIES_VERSION_1               1

typedef struct NVME_ICE_CAPABILITIES {

    // Version of struct
    USHORT Version;

    // Size of struct
    USHORT Size;

    // Supported page sizes. Multiple bits may be set.
    union {
        struct {
            UCHAR PageSize4K : 1;
            UCHAR PageSize2M : 1;
            UCHAR Reserved : 6;
        };
        _Field_range_(>, 0) UCHAR AsUchar;
    } PageSizeBitmask;

    // Supported data alignments. Multiple bits may be set.
    union {
        struct {
            UCHAR Alignment4B : 1;
            UCHAR Alignment8B : 1;
            UCHAR Alignment16B : 1;
            UCHAR Reserved : 5;
        };
        _Field_range_(>, 0) UCHAR AsUchar;
    } DataTransferAlignmentBitmask;

    // Compliant security standards at the hardware level. Multiple bits may be set.
    union {
        struct {
            UCHAR FIPS : 1;
            UCHAR Reserved : 7;
        };
        UCHAR AsUchar;
    } SecurityComplianceBitmask;

    UCHAR Reserved;

    // Maximum supported transfer size in KB
    USHORT MaxTransferSizeKBytes;

    // Contains supported crypto configurations
    STOR_CRYPTO_CAPABILITIES_DATA CryptoCapabilitiesData;

} NVME_ICE_CAPABILITIES;

#pragma warning(pop)

/*++

PQUERY_CAPABILITIES

Routine Description:

    Returns information about the capabilities of a SoC that supports NVMe ICE.

Arguments:

    InterfaceContext - The Context member of the NVME_ICE_INTERFACE structure.
    PciAddress       - The PCI SBDF of the NVMe device.
    Capabilities     - The capabilities of the SoC. Can be NULL to query CapabilitiesSize.
    CapabilitiesSize - On input, provides size of the Capabilities struct or can be
                       0 when querying required size. On output, contains actual size of
                       Capabilities struct or required size.

Return Value:

    STOR_STATUS_SUCCESS on success.
    STOR_STATUS_BUFFER_TOO_SMALL if Capabilities is NULL or if CapabilitiesSize is too small.
    STOR_STATUS_INVALID_DEVICE_REQUEST if NVMe device is not supported.
    A STOR_STATUS error code otherwise.

--*/
_IRQL_requires_(PASSIVE_LEVEL)
typedef
ULONG
(__stdcall *PQUERY_CAPABILITIES)(
    _In_ const PVOID InterfaceContext,
    _In_ const NVME_PCI_ADDRESS* PciAddress,
    _Out_ NVME_ICE_CAPABILITIES* Capabilities,
    _Inout_ PULONG CapabilitiesSize
    );

#define NVME_ICE_CONFIGURE_CAPABILITY_DATA_VERSION_1  1

typedef struct NVME_ICE_CONFIGURE_CAPABILITY_DATA {

    // IN: Version of struct
    USHORT Version;

    // IN: Size of struct
    USHORT Size;

    // IN: Crypto capability to configure as reported by QueryCapabilities.
    USHORT ReportedCryptoCapabilityIndex;

    // IN: Chosen maximum supported transfer size in KB
    USHORT MaxTransferSizeKBytes;

    // IN: Chosen size of an LBA in bytes
    ULONG LBASize;

    // IN: Chosen size of PRP Page Size in bytes
    ULONG PRPPageSize;

    // OUT: Index of configured capability to be used with ProgramKey.
    USHORT ConfiguredCryptoCapabilityIndex;

} NVME_ICE_CONFIGURE_CAPABILITY_DATA;

/*++

PCONFIGURE_CAPABILITY

Routine Description:

    Configures a capability returned by QueryCapabilities. Subsequent calls with identical
    input parameters must return the same ConfiguredCryptoCapabilityIndex. If this function needs
    to perform any memory allocations then it must ensure that those memory allocations do not fail.

Arguments:

    InterfaceContext - The Context member of the NVME_ICE_INTERFACE structure.
    CapabilityData   - The configuration data to be set to the provided capability.

Return Value:

    STOR_STATUS_SUCCESS on success.
    STOR_STATUS_BUSY on transient error. This suggests a retry.
    A STOR_STATUS error code otherwise.

--*/
_IRQL_requires_max_(DISPATCH_LEVEL)
typedef
ULONG
(__stdcall *PCONFIGURE_CAPABILITY)(
    _In_ const PVOID InterfaceContext,
    _Inout_ NVME_ICE_CONFIGURE_CAPABILITY_DATA* CapabilityData
    );

#define NVME_ICE_PROGRAM_KEY_DATA_VERSION_1           1

typedef struct NVME_ICE_PROGRAM_KEY_DATA {

    // IN: Version of struct
    USHORT Version;

    // IN: Size of struct
    USHORT Size;

    // IN: The key's size
    USHORT KeyContentSize;

    // IN: Capability to use for this key as provided by ConfigureCapability.
    USHORT ConfiguredCryptoCapabilityIndex;

    // IN_OUT: If NULL, driver is expected to return an unused key handle.
    //         If non-NULL, driver is expected to replace key associated with provided handle with new key.
    PVOID KeyHandle;

    // IN: Contains the key
    _Field_size_bytes_(KeyContentSize) UCHAR KeyContent[ANYSIZE_ARRAY];

} NVME_ICE_PROGRAM_KEY_DATA;

/*++

PPROGRAM_KEY

Routine Description:

    Programs a key to a SoC that supports NVMe ICE. If this function needs to perform any memory
    allocations then it must ensure that those memory allocations do not fail.

Arguments:

    InterfaceContext - The Context member of the NVME_ICE_INTERFACE structure.
    KeyData          - The key data to be programmed to the SoC.
    KeyDataSize      - Provides size of KeyData struct.

Return Value:

    STOR_STATUS_SUCCESS on success.
    STOR_STATUS_BUSY on transient error. This suggests a retry.
    A STOR_STATUS error code otherwise.

--*/
_IRQL_requires_max_(DISPATCH_LEVEL)
typedef
ULONG
(__stdcall *PPROGRAM_KEY)(
    _In_ const PVOID InterfaceContext,
    _Inout_ NVME_ICE_PROGRAM_KEY_DATA* KeyData,
    _In_ PULONG KeyDataSize
    );

#define NVME_ICE_IO_DESCRIPTOR_VERSION_1              1

typedef struct NVME_ICE_IO_DESCRIPTOR {

    // IN: Version of struct
    USHORT Version;

    // IN: Size of struct
    USHORT Size;

    // IN: Number of LBAs in request
    _Field_range_(>, 0) ULONG LBACount;

    // IN: Number of PRPs in request
    _Field_range_(>, 0) ULONG PRPCount;

    // IN: Key handle to use for this I/O as provided by ProgramKey.
    PVOID KeyHandle;

    // IN: Initialization Vector to use for crypto
    UCHAR IV[16];

    // OUT: Context to be passed back to driver on completion. If no work is
    //      required, set value to NULL.
    PVOID IOContext;

    //
    // PRP1, PRP2, and PRPEntries are all IN_OUT. They contain the page addresses for
    // this request, but have different usages depending on the value of PRPCount.
    //
    // If PRPCount == 1:
    //     PRP1 points to the singular PRP. PRP2 and PRPEntries are NULL.
    // If PRPCount == 2:
    //     PRP1 and PRP2 each point to PRPs. PRPEntries is NULL.
    // If PRPCount > 2:
    //     PRP1 points to a singular PRP and PRPEntries points to an array of the remaining
    //     PRPCount-1 PRPs. PRP2 is NULL.
    //
    PNVME_PRP_ENTRY PRP1;
    PNVME_PRP_ENTRY PRP2;
    PNVME_PRP_ENTRY PRPEntries;

} NVME_ICE_IO_DESCRIPTOR;

/*++

PIO_START

Routine Description:

    Starts a crypto I/O on a SoC that supports NVMe ICE. If this function needs to perform any memory
    allocations then it must ensure that those memory allocations do not fail.

Arguments:

    InterfaceContext - The Context member of the NVME_ICE_INTERFACE structure.
    IODescriptor     - Parameters to be used for crypto I/O.

Return Value:

    STOR_STATUS_SUCCESS on success.
    STOR_STATUS_BUSY on transient error. This suggests a retry.
    A STOR_STATUS error code otherwise.

--*/
_IRQL_requires_max_(DISPATCH_LEVEL)
typedef
ULONG
(__stdcall *PIO_START)(
    _In_ const PVOID InterfaceContext,
    _Inout_ NVME_ICE_IO_DESCRIPTOR* IODescriptor
    );

/*++

PIO_COMPLETE

Routine Description:

    Completes a crypto I/O on a SoC that supports NVMe ICE. If this function needs to perform any memory
    allocations then it must ensure that those memory allocations do not fail.

Arguments:

    InterfaceContext - The Context member of the NVME_ICE_INTERFACE structure.
    IOContext        - Specifies which I/O to complete as returned from IOStart. If no work is
                       required, set value to NULL.

Return Value:

    STOR_STATUS_SUCCESS on success.
    A STOR_STATUS error code otherwise.

--*/
_IRQL_requires_(DISPATCH_LEVEL)
typedef
ULONG
(__stdcall *PIO_COMPLETE)(
    _In_ const PVOID InterfaceContext,
    _In_ const PVOID IOContext
    );

#define NVME_ICE_INTERFACE_VERSION_1                  1

typedef struct NVME_ICE_INTERFACE {

    //
    // Generic interface header
    //
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;

    //
    // Required NVMe ICE interface functions
    //
    PQUERY_CAPABILITIES QueryCapabilities;
    PCONFIGURE_CAPABILITY ConfigureCapability;
    PPROGRAM_KEY ProgramKey;

    //
    // Optional NVMe ICE interface functions
    //
    PIO_START IOStart;
    PIO_COMPLETE IOComplete;

} NVME_ICE_INTERFACE;
