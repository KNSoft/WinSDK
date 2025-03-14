/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991  Microsoft Corporation

Module Name:

    bugcodes.mc

Abstract:

    This module contains the definition of the system bug check codes.

Notes:

    No message strings should be added to the bugcodes' entries. Their
    symbolic names take the place of message strings.

--*/

#ifndef _BUGCODES_
#define _BUGCODES_


//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: HARDWARE_PROFILE_UNDOCKED_STRING
//
// MessageText:
//
// Undocked Profile
//
#define HARDWARE_PROFILE_UNDOCKED_STRING ((ULONG)0x40010001L)

//
// MessageId: HARDWARE_PROFILE_DOCKED_STRING
//
// MessageText:
//
// Docked Profile
//
#define HARDWARE_PROFILE_DOCKED_STRING   ((ULONG)0x40010002L)

//
// MessageId: HARDWARE_PROFILE_UNKNOWN_STRING
//
// MessageText:
//
// Profile
//
#define HARDWARE_PROFILE_UNKNOWN_STRING  ((ULONG)0x40010003L)

//
// MessageId: WINDOWS_NT_BANNER
//
// MessageText:
//
// Microsoft (R) Windows (R) Version %hs (Build %u%hs)
//
#define WINDOWS_NT_BANNER                ((ULONG)0x4000007EL)

//
// MessageId: WINDOWS_NT_CSD_STRING
//
// MessageText:
//
// Service Pack
//
#define WINDOWS_NT_CSD_STRING            ((ULONG)0x40000087L)

//
// MessageId: WINDOWS_NT_INFO_STRING
//
// MessageText:
//
// %u System Processor [%u MB Memory] %Z
//
#define WINDOWS_NT_INFO_STRING           ((ULONG)0x40000088L)

//
// MessageId: WINDOWS_NT_MP_STRING
//
// MessageText:
//
// MultiProcessor Kernel
//
#define WINDOWS_NT_MP_STRING             ((ULONG)0x40000089L)

//
// MessageId: THREAD_TERMINATE_HELD_MUTEX
//
// MessageText:
//
// A kernel thread terminated while holding a mutex
//
#define THREAD_TERMINATE_HELD_MUTEX      ((ULONG)0x4000008AL)

//
// MessageId: WINDOWS_NT_INFO_STRING_PLURAL
//
// MessageText:
//
// %u System Processors [%u MB Memory] %Z
//
#define WINDOWS_NT_INFO_STRING_PLURAL    ((ULONG)0x4000009DL)

//
// MessageId: WINDOWS_NT_RC_STRING
//
// MessageText:
//
// RC
//
#define WINDOWS_NT_RC_STRING             ((ULONG)0x4000009EL)

//
// MessageId: APC_INDEX_MISMATCH
//
// MessageText:
//
//  APC_INDEX_MISMATCH
//
#define APC_INDEX_MISMATCH               ((ULONG)0x00000001L)

//
// MessageId: DEVICE_QUEUE_NOT_BUSY
//
// MessageText:
//
//  DEVICE_QUEUE_NOT_BUSY
//
#define DEVICE_QUEUE_NOT_BUSY            ((ULONG)0x00000002L)

//
// MessageId: INVALID_AFFINITY_SET
//
// MessageText:
//
//  INVALID_AFFINITY_SET
//
#define INVALID_AFFINITY_SET             ((ULONG)0x00000003L)

//
// MessageId: INVALID_DATA_ACCESS_TRAP
//
// MessageText:
//
//  INVALID_DATA_ACCESS_TRAP
//
#define INVALID_DATA_ACCESS_TRAP         ((ULONG)0x00000004L)

//
// MessageId: INVALID_PROCESS_ATTACH_ATTEMPT
//
// MessageText:
//
//  INVALID_PROCESS_ATTACH_ATTEMPT
//
#define INVALID_PROCESS_ATTACH_ATTEMPT   ((ULONG)0x00000005L)

//
// MessageId: INVALID_PROCESS_DETACH_ATTEMPT
//
// MessageText:
//
//  INVALID_PROCESS_DETACH_ATTEMPT
//
#define INVALID_PROCESS_DETACH_ATTEMPT   ((ULONG)0x00000006L)

//
// MessageId: INVALID_SOFTWARE_INTERRUPT
//
// MessageText:
//
//  INVALID_SOFTWARE_INTERRUPT
//
#define INVALID_SOFTWARE_INTERRUPT       ((ULONG)0x00000007L)

//
// MessageId: IRQL_NOT_DISPATCH_LEVEL
//
// MessageText:
//
//  IRQL_NOT_DISPATCH_LEVEL
//
#define IRQL_NOT_DISPATCH_LEVEL          ((ULONG)0x00000008L)

//
// MessageId: IRQL_NOT_GREATER_OR_EQUAL
//
// MessageText:
//
//  IRQL_NOT_GREATER_OR_EQUAL
//
#define IRQL_NOT_GREATER_OR_EQUAL        ((ULONG)0x00000009L)

//
// MessageId: IRQL_NOT_LESS_OR_EQUAL
//
// MessageText:
//
//  IRQL_NOT_LESS_OR_EQUAL
//
#define IRQL_NOT_LESS_OR_EQUAL           ((ULONG)0x0000000AL)

//
// MessageId: NO_EXCEPTION_HANDLING_SUPPORT
//
// MessageText:
//
//  NO_EXCEPTION_HANDLING_SUPPORT
//
#define NO_EXCEPTION_HANDLING_SUPPORT    ((ULONG)0x0000000BL)

//
// MessageId: MAXIMUM_WAIT_OBJECTS_EXCEEDED
//
// MessageText:
//
//  MAXIMUM_WAIT_OBJECTS_EXCEEDED
//
#define MAXIMUM_WAIT_OBJECTS_EXCEEDED    ((ULONG)0x0000000CL)

//
// MessageId: MUTEX_LEVEL_NUMBER_VIOLATION
//
// MessageText:
//
//  MUTEX_LEVEL_NUMBER_VIOLATION
//
#define MUTEX_LEVEL_NUMBER_VIOLATION     ((ULONG)0x0000000DL)

//
// MessageId: NO_USER_MODE_CONTEXT
//
// MessageText:
//
//  NO_USER_MODE_CONTEXT
//
#define NO_USER_MODE_CONTEXT             ((ULONG)0x0000000EL)

//
// MessageId: SPIN_LOCK_ALREADY_OWNED
//
// MessageText:
//
//  SPIN_LOCK_ALREADY_OWNED
//
#define SPIN_LOCK_ALREADY_OWNED          ((ULONG)0x0000000FL)

//
// MessageId: SPIN_LOCK_NOT_OWNED
//
// MessageText:
//
//  SPIN_LOCK_NOT_OWNED
//
#define SPIN_LOCK_NOT_OWNED              ((ULONG)0x00000010L)

//
// MessageId: THREAD_NOT_MUTEX_OWNER
//
// MessageText:
//
//  THREAD_NOT_MUTEX_OWNER
//
#define THREAD_NOT_MUTEX_OWNER           ((ULONG)0x00000011L)

//
// MessageId: TRAP_CAUSE_UNKNOWN
//
// MessageText:
//
//  TRAP_CAUSE_UNKNOWN
//
#define TRAP_CAUSE_UNKNOWN               ((ULONG)0x00000012L)

//
// MessageId: EMPTY_THREAD_REAPER_LIST
//
// MessageText:
//
//  EMPTY_THREAD_REAPER_LIST
//
#define EMPTY_THREAD_REAPER_LIST         ((ULONG)0x00000013L)

//
// MessageId: CREATE_DELETE_LOCK_NOT_LOCKED
//
// MessageText:
//
//  CREATE_DELETE_LOCK_NOT_LOCKED
//
#define CREATE_DELETE_LOCK_NOT_LOCKED    ((ULONG)0x00000014L)

//
// MessageId: LAST_CHANCE_CALLED_FROM_KMODE
//
// MessageText:
//
//  LAST_CHANCE_CALLED_FROM_KMODE
//
#define LAST_CHANCE_CALLED_FROM_KMODE    ((ULONG)0x00000015L)

//
// MessageId: CID_HANDLE_CREATION
//
// MessageText:
//
//  CID_HANDLE_CREATION
//
#define CID_HANDLE_CREATION              ((ULONG)0x00000016L)

//
// MessageId: CID_HANDLE_DELETION
//
// MessageText:
//
//  CID_HANDLE_DELETION
//
#define CID_HANDLE_DELETION              ((ULONG)0x00000017L)

//
// MessageId: REFERENCE_BY_POINTER
//
// MessageText:
//
//  REFERENCE_BY_POINTER
//
#define REFERENCE_BY_POINTER             ((ULONG)0x00000018L)

//
// MessageId: BAD_POOL_HEADER
//
// MessageText:
//
//  BAD_POOL_HEADER
//
#define BAD_POOL_HEADER                  ((ULONG)0x00000019L)

//
// MessageId: MEMORY_MANAGEMENT
//
// MessageText:
//
//  MEMORY_MANAGEMENT
//
#define MEMORY_MANAGEMENT                ((ULONG)0x0000001AL)

//
// MessageId: PFN_SHARE_COUNT
//
// MessageText:
//
//  PFN_SHARE_COUNT
//
#define PFN_SHARE_COUNT                  ((ULONG)0x0000001BL)

//
// MessageId: PFN_REFERENCE_COUNT
//
// MessageText:
//
//  PFN_REFERENCE_COUNT
//
#define PFN_REFERENCE_COUNT              ((ULONG)0x0000001CL)

//
// MessageId: NO_SPIN_LOCK_AVAILABLE
//
// MessageText:
//
//  NO_SPIN_LOCK_AVAILABLE
//
#define NO_SPIN_LOCK_AVAILABLE           ((ULONG)0x0000001DL)

//
// MessageId: KMODE_EXCEPTION_NOT_HANDLED
//
// MessageText:
//
//  KMODE_EXCEPTION_NOT_HANDLED
//
#define KMODE_EXCEPTION_NOT_HANDLED      ((ULONG)0x0000001EL)

//
// MessageId: SHARED_RESOURCE_CONV_ERROR
//
// MessageText:
//
//  SHARED_RESOURCE_CONV_ERROR
//
#define SHARED_RESOURCE_CONV_ERROR       ((ULONG)0x0000001FL)

//
// MessageId: KERNEL_APC_PENDING_DURING_EXIT
//
// MessageText:
//
//  KERNEL_APC_PENDING_DURING_EXIT
//
#define KERNEL_APC_PENDING_DURING_EXIT   ((ULONG)0x00000020L)

//
// MessageId: QUOTA_UNDERFLOW
//
// MessageText:
//
//  QUOTA_UNDERFLOW
//
#define QUOTA_UNDERFLOW                  ((ULONG)0x00000021L)

//
// MessageId: FILE_SYSTEM
//
// MessageText:
//
//  FILE_SYSTEM
//
#define FILE_SYSTEM                      ((ULONG)0x00000022L)

//
// MessageId: FAT_FILE_SYSTEM
//
// MessageText:
//
//  FAT_FILE_SYSTEM
//
#define FAT_FILE_SYSTEM                  ((ULONG)0x00000023L)

//
// MessageId: NTFS_FILE_SYSTEM
//
// MessageText:
//
//  NTFS_FILE_SYSTEM
//
#define NTFS_FILE_SYSTEM                 ((ULONG)0x00000024L)

//
// MessageId: NPFS_FILE_SYSTEM
//
// MessageText:
//
//  NPFS_FILE_SYSTEM
//
#define NPFS_FILE_SYSTEM                 ((ULONG)0x00000025L)

//
// MessageId: CDFS_FILE_SYSTEM
//
// MessageText:
//
//  CDFS_FILE_SYSTEM
//
#define CDFS_FILE_SYSTEM                 ((ULONG)0x00000026L)

//
// MessageId: RDR_FILE_SYSTEM
//
// MessageText:
//
//  RDR_FILE_SYSTEM
//
#define RDR_FILE_SYSTEM                  ((ULONG)0x00000027L)

//
// MessageId: CORRUPT_ACCESS_TOKEN
//
// MessageText:
//
//  CORRUPT_ACCESS_TOKEN
//
#define CORRUPT_ACCESS_TOKEN             ((ULONG)0x00000028L)

//
// MessageId: SECURITY_SYSTEM
//
// MessageText:
//
//  SECURITY_SYSTEM
//
#define SECURITY_SYSTEM                  ((ULONG)0x00000029L)

//
// MessageId: INCONSISTENT_IRP
//
// MessageText:
//
//  INCONSISTENT_IRP
//
#define INCONSISTENT_IRP                 ((ULONG)0x0000002AL)

//
// MessageId: PANIC_STACK_SWITCH
//
// MessageText:
//
//  PANIC_STACK_SWITCH
//
#define PANIC_STACK_SWITCH               ((ULONG)0x0000002BL)

//
// MessageId: PORT_DRIVER_INTERNAL
//
// MessageText:
//
//  PORT_DRIVER_INTERNAL
//
#define PORT_DRIVER_INTERNAL             ((ULONG)0x0000002CL)

//
// MessageId: SCSI_DISK_DRIVER_INTERNAL
//
// MessageText:
//
//  SCSI_DISK_DRIVER_INTERNAL
//
#define SCSI_DISK_DRIVER_INTERNAL        ((ULONG)0x0000002DL)

//
// MessageId: DATA_BUS_ERROR
//
// MessageText:
//
//  DATA_BUS_ERROR
//
#define DATA_BUS_ERROR                   ((ULONG)0x0000002EL)

//
// MessageId: INSTRUCTION_BUS_ERROR
//
// MessageText:
//
//  INSTRUCTION_BUS_ERROR
//
#define INSTRUCTION_BUS_ERROR            ((ULONG)0x0000002FL)

//
// MessageId: SET_OF_INVALID_CONTEXT
//
// MessageText:
//
//  SET_OF_INVALID_CONTEXT
//
#define SET_OF_INVALID_CONTEXT           ((ULONG)0x00000030L)

//
// MessageId: PHASE0_INITIALIZATION_FAILED
//
// MessageText:
//
//  PHASE0_INITIALIZATION_FAILED
//
#define PHASE0_INITIALIZATION_FAILED     ((ULONG)0x00000031L)

//
// MessageId: PHASE1_INITIALIZATION_FAILED
//
// MessageText:
//
//  PHASE1_INITIALIZATION_FAILED
//
#define PHASE1_INITIALIZATION_FAILED     ((ULONG)0x00000032L)

//
// MessageId: UNEXPECTED_INITIALIZATION_CALL
//
// MessageText:
//
//  UNEXPECTED_INITIALIZATION_CALL
//
#define UNEXPECTED_INITIALIZATION_CALL   ((ULONG)0x00000033L)

//
// MessageId: CACHE_MANAGER
//
// MessageText:
//
//  CACHE_MANAGER
//
#define CACHE_MANAGER                    ((ULONG)0x00000034L)

//
// MessageId: NO_MORE_IRP_STACK_LOCATIONS
//
// MessageText:
//
//  NO_MORE_IRP_STACK_LOCATIONS
//
#define NO_MORE_IRP_STACK_LOCATIONS      ((ULONG)0x00000035L)

//
// MessageId: DEVICE_REFERENCE_COUNT_NOT_ZERO
//
// MessageText:
//
//  DEVICE_REFERENCE_COUNT_NOT_ZERO
//
#define DEVICE_REFERENCE_COUNT_NOT_ZERO  ((ULONG)0x00000036L)

//
// MessageId: FLOPPY_INTERNAL_ERROR
//
// MessageText:
//
//  FLOPPY_INTERNAL_ERROR
//
#define FLOPPY_INTERNAL_ERROR            ((ULONG)0x00000037L)

//
// MessageId: SERIAL_DRIVER_INTERNAL
//
// MessageText:
//
//  SERIAL_DRIVER_INTERNAL
//
#define SERIAL_DRIVER_INTERNAL           ((ULONG)0x00000038L)

//
// MessageId: SYSTEM_EXIT_OWNED_MUTEX
//
// MessageText:
//
//  SYSTEM_EXIT_OWNED_MUTEX
//
#define SYSTEM_EXIT_OWNED_MUTEX          ((ULONG)0x00000039L)

//
// MessageId: SYSTEM_UNWIND_PREVIOUS_USER
//
// MessageText:
//
//  SYSTEM_UNWIND_PREVIOUS_USER
//
#define SYSTEM_UNWIND_PREVIOUS_USER      ((ULONG)0x0000003AL)

//
// MessageId: SYSTEM_SERVICE_EXCEPTION
//
// MessageText:
//
//  SYSTEM_SERVICE_EXCEPTION
//
#define SYSTEM_SERVICE_EXCEPTION         ((ULONG)0x0000003BL)

//
// MessageId: INTERRUPT_UNWIND_ATTEMPTED
//
// MessageText:
//
//  INTERRUPT_UNWIND_ATTEMPTED
//
#define INTERRUPT_UNWIND_ATTEMPTED       ((ULONG)0x0000003CL)

//
// MessageId: INTERRUPT_EXCEPTION_NOT_HANDLED
//
// MessageText:
//
//  INTERRUPT_EXCEPTION_NOT_HANDLED
//
#define INTERRUPT_EXCEPTION_NOT_HANDLED  ((ULONG)0x0000003DL)

//
// MessageId: MULTIPROCESSOR_CONFIGURATION_NOT_SUPPORTED
//
// MessageText:
//
//  MULTIPROCESSOR_CONFIGURATION_NOT_SUPPORTED
//
#define MULTIPROCESSOR_CONFIGURATION_NOT_SUPPORTED ((ULONG)0x0000003EL)

//
// MessageId: NO_MORE_SYSTEM_PTES
//
// MessageText:
//
//  NO_MORE_SYSTEM_PTES
//
#define NO_MORE_SYSTEM_PTES              ((ULONG)0x0000003FL)

//
// MessageId: TARGET_MDL_TOO_SMALL
//
// MessageText:
//
//  TARGET_MDL_TOO_SMALL
//
#define TARGET_MDL_TOO_SMALL             ((ULONG)0x00000040L)

//
// MessageId: MUST_SUCCEED_POOL_EMPTY
//
// MessageText:
//
//  MUST_SUCCEED_POOL_EMPTY
//
#define MUST_SUCCEED_POOL_EMPTY          ((ULONG)0x00000041L)

//
// MessageId: ATDISK_DRIVER_INTERNAL
//
// MessageText:
//
//  ATDISK_DRIVER_INTERNAL
//
#define ATDISK_DRIVER_INTERNAL           ((ULONG)0x00000042L)

//
// MessageId: NO_SUCH_PARTITION
//
// MessageText:
//
//  NO_SUCH_PARTITION
//
#define NO_SUCH_PARTITION                ((ULONG)0x00000043L)

//
// MessageId: MULTIPLE_IRP_COMPLETE_REQUESTS
//
// MessageText:
//
//  MULTIPLE_IRP_COMPLETE_REQUESTS
//
#define MULTIPLE_IRP_COMPLETE_REQUESTS   ((ULONG)0x00000044L)

//
// MessageId: INSUFFICIENT_SYSTEM_MAP_REGS
//
// MessageText:
//
//  INSUFFICIENT_SYSTEM_MAP_REGS
//
#define INSUFFICIENT_SYSTEM_MAP_REGS     ((ULONG)0x00000045L)

//
// MessageId: DEREF_UNKNOWN_LOGON_SESSION
//
// MessageText:
//
//  DEREF_UNKNOWN_LOGON_SESSION
//
#define DEREF_UNKNOWN_LOGON_SESSION      ((ULONG)0x00000046L)

//
// MessageId: REF_UNKNOWN_LOGON_SESSION
//
// MessageText:
//
//  REF_UNKNOWN_LOGON_SESSION
//
#define REF_UNKNOWN_LOGON_SESSION        ((ULONG)0x00000047L)

//
// MessageId: CANCEL_STATE_IN_COMPLETED_IRP
//
// MessageText:
//
//  CANCEL_STATE_IN_COMPLETED_IRP
//
#define CANCEL_STATE_IN_COMPLETED_IRP    ((ULONG)0x00000048L)

//
// MessageId: PAGE_FAULT_WITH_INTERRUPTS_OFF
//
// MessageText:
//
//  PAGE_FAULT_WITH_INTERRUPTS_OFF
//
#define PAGE_FAULT_WITH_INTERRUPTS_OFF   ((ULONG)0x00000049L)

//
// MessageId: IRQL_GT_ZERO_AT_SYSTEM_SERVICE
//
// MessageText:
//
//  IRQL_GT_ZERO_AT_SYSTEM_SERVICE
//
#define IRQL_GT_ZERO_AT_SYSTEM_SERVICE   ((ULONG)0x0000004AL)

//
// MessageId: STREAMS_INTERNAL_ERROR
//
// MessageText:
//
//  STREAMS_INTERNAL_ERROR
//
#define STREAMS_INTERNAL_ERROR           ((ULONG)0x0000004BL)

//
// MessageId: FATAL_UNHANDLED_HARD_ERROR
//
// MessageText:
//
//  FATAL_UNHANDLED_HARD_ERROR
//
#define FATAL_UNHANDLED_HARD_ERROR       ((ULONG)0x0000004CL)

//
// MessageId: NO_PAGES_AVAILABLE
//
// MessageText:
//
//  NO_PAGES_AVAILABLE
//
#define NO_PAGES_AVAILABLE               ((ULONG)0x0000004DL)

//
// MessageId: PFN_LIST_CORRUPT
//
// MessageText:
//
//  PFN_LIST_CORRUPT
//
#define PFN_LIST_CORRUPT                 ((ULONG)0x0000004EL)

//
// MessageId: NDIS_INTERNAL_ERROR
//
// MessageText:
//
//  NDIS_INTERNAL_ERROR
//
#define NDIS_INTERNAL_ERROR              ((ULONG)0x0000004FL)

//
// MessageId: PAGE_FAULT_IN_NONPAGED_AREA
//
// MessageText:
//
//  PAGE_FAULT_IN_NONPAGED_AREA
//
#define PAGE_FAULT_IN_NONPAGED_AREA      ((ULONG)0x00000050L)

#define PAGE_FAULT_IN_NONPAGED_AREA_M ((ULONG)0x10000050L)
//
// MessageId: REGISTRY_ERROR
//
// MessageText:
//
//  REGISTRY_ERROR
//
#define REGISTRY_ERROR                   ((ULONG)0x00000051L)

//
// MessageId: MAILSLOT_FILE_SYSTEM
//
// MessageText:
//
//  MAILSLOT_FILE_SYSTEM
//
#define MAILSLOT_FILE_SYSTEM             ((ULONG)0x00000052L)

//
// MessageId: NO_BOOT_DEVICE
//
// MessageText:
//
//  NO_BOOT_DEVICE
//
#define NO_BOOT_DEVICE                   ((ULONG)0x00000053L)

//
// MessageId: LM_SERVER_INTERNAL_ERROR
//
// MessageText:
//
//  LM_SERVER_INTERNAL_ERROR
//
#define LM_SERVER_INTERNAL_ERROR         ((ULONG)0x00000054L)

//
// MessageId: DATA_COHERENCY_EXCEPTION
//
// MessageText:
//
//  DATA_COHERENCY_EXCEPTION
//
#define DATA_COHERENCY_EXCEPTION         ((ULONG)0x00000055L)

//
// MessageId: INSTRUCTION_COHERENCY_EXCEPTION
//
// MessageText:
//
//  INSTRUCTION_COHERENCY_EXCEPTION
//
#define INSTRUCTION_COHERENCY_EXCEPTION  ((ULONG)0x00000056L)

//
// MessageId: XNS_INTERNAL_ERROR
//
// MessageText:
//
//  XNS_INTERNAL_ERROR
//
#define XNS_INTERNAL_ERROR               ((ULONG)0x00000057L)

//
// MessageId: VOLMGRX_INTERNAL_ERROR
//
// MessageText:
//
//  VOLMGRX_INTERNAL_ERROR
//
#define VOLMGRX_INTERNAL_ERROR           ((ULONG)0x00000058L)

//
// MessageId: PINBALL_FILE_SYSTEM
//
// MessageText:
//
//  PINBALL_FILE_SYSTEM
//
#define PINBALL_FILE_SYSTEM              ((ULONG)0x00000059L)

//
// MessageId: CRITICAL_SERVICE_FAILED
//
// MessageText:
//
//  CRITICAL_SERVICE_FAILED
//
#define CRITICAL_SERVICE_FAILED          ((ULONG)0x0000005AL)

//
// MessageId: SET_ENV_VAR_FAILED
//
// MessageText:
//
//  SET_ENV_VAR_FAILED
//
#define SET_ENV_VAR_FAILED               ((ULONG)0x0000005BL)

//
// MessageId: HAL_INITIALIZATION_FAILED
//
// MessageText:
//
//  HAL_INITIALIZATION_FAILED
//
#define HAL_INITIALIZATION_FAILED        ((ULONG)0x0000005CL)

//
// MessageId: UNSUPPORTED_PROCESSOR
//
// MessageText:
//
//  UNSUPPORTED_PROCESSOR
//
#define UNSUPPORTED_PROCESSOR            ((ULONG)0x0000005DL)

//
// MessageId: OBJECT_INITIALIZATION_FAILED
//
// MessageText:
//
//  OBJECT_INITIALIZATION_FAILED
//
#define OBJECT_INITIALIZATION_FAILED     ((ULONG)0x0000005EL)

//
// MessageId: SECURITY_INITIALIZATION_FAILED
//
// MessageText:
//
//  SECURITY_INITIALIZATION_FAILED
//
#define SECURITY_INITIALIZATION_FAILED   ((ULONG)0x0000005FL)

//
// MessageId: PROCESS_INITIALIZATION_FAILED
//
// MessageText:
//
//  PROCESS_INITIALIZATION_FAILED
//
#define PROCESS_INITIALIZATION_FAILED    ((ULONG)0x00000060L)

//
// MessageId: HAL1_INITIALIZATION_FAILED
//
// MessageText:
//
//  HAL1_INITIALIZATION_FAILED
//
#define HAL1_INITIALIZATION_FAILED       ((ULONG)0x00000061L)

//
// MessageId: OBJECT1_INITIALIZATION_FAILED
//
// MessageText:
//
//  OBJECT1_INITIALIZATION_FAILED
//
#define OBJECT1_INITIALIZATION_FAILED    ((ULONG)0x00000062L)

//
// MessageId: SECURITY1_INITIALIZATION_FAILED
//
// MessageText:
//
//  SECURITY1_INITIALIZATION_FAILED
//
#define SECURITY1_INITIALIZATION_FAILED  ((ULONG)0x00000063L)

//
// MessageId: SYMBOLIC_INITIALIZATION_FAILED
//
// MessageText:
//
//  SYMBOLIC_INITIALIZATION_FAILED
//
#define SYMBOLIC_INITIALIZATION_FAILED   ((ULONG)0x00000064L)

//
// MessageId: MEMORY1_INITIALIZATION_FAILED
//
// MessageText:
//
//  MEMORY1_INITIALIZATION_FAILED
//
#define MEMORY1_INITIALIZATION_FAILED    ((ULONG)0x00000065L)

//
// MessageId: CACHE_INITIALIZATION_FAILED
//
// MessageText:
//
//  CACHE_INITIALIZATION_FAILED
//
#define CACHE_INITIALIZATION_FAILED      ((ULONG)0x00000066L)

//
// MessageId: CONFIG_INITIALIZATION_FAILED
//
// MessageText:
//
//  CONFIG_INITIALIZATION_FAILED
//
#define CONFIG_INITIALIZATION_FAILED     ((ULONG)0x00000067L)

//
// MessageId: FILE_INITIALIZATION_FAILED
//
// MessageText:
//
//  FILE_INITIALIZATION_FAILED
//
#define FILE_INITIALIZATION_FAILED       ((ULONG)0x00000068L)

//
// MessageId: IO1_INITIALIZATION_FAILED
//
// MessageText:
//
//  IO1_INITIALIZATION_FAILED
//
#define IO1_INITIALIZATION_FAILED        ((ULONG)0x00000069L)

//
// MessageId: LPC_INITIALIZATION_FAILED
//
// MessageText:
//
//  LPC_INITIALIZATION_FAILED
//
#define LPC_INITIALIZATION_FAILED        ((ULONG)0x0000006AL)

//
// MessageId: PROCESS1_INITIALIZATION_FAILED
//
// MessageText:
//
//  PROCESS1_INITIALIZATION_FAILED
//
#define PROCESS1_INITIALIZATION_FAILED   ((ULONG)0x0000006BL)

//
// MessageId: REFMON_INITIALIZATION_FAILED
//
// MessageText:
//
//  REFMON_INITIALIZATION_FAILED
//
#define REFMON_INITIALIZATION_FAILED     ((ULONG)0x0000006CL)

//
// MessageId: SESSION1_INITIALIZATION_FAILED
//
// MessageText:
//
//  SESSION1_INITIALIZATION_FAILED
//
#define SESSION1_INITIALIZATION_FAILED   ((ULONG)0x0000006DL)

//
// MessageId: BOOTPROC_INITIALIZATION_FAILED
//
// MessageText:
//
//  BOOTPROC_INITIALIZATION_FAILED
//
#define BOOTPROC_INITIALIZATION_FAILED   ((ULONG)0x0000006EL)

//
// MessageId: VSL_INITIALIZATION_FAILED
//
// MessageText:
//
//  VSL_INITIALIZATION_FAILED
//
#define VSL_INITIALIZATION_FAILED        ((ULONG)0x0000006FL)

//
// MessageId: SOFT_RESTART_FATAL_ERROR
//
// MessageText:
//
//  SOFT_RESTART_FATAL_ERROR
//
#define SOFT_RESTART_FATAL_ERROR         ((ULONG)0x00000070L)

//
// MessageId: ASSIGN_DRIVE_LETTERS_FAILED
//
// MessageText:
//
//  ASSIGN_DRIVE_LETTERS_FAILED
//
#define ASSIGN_DRIVE_LETTERS_FAILED      ((ULONG)0x00000072L)

//
// MessageId: CONFIG_LIST_FAILED
//
// MessageText:
//
//  CONFIG_LIST_FAILED
//
#define CONFIG_LIST_FAILED               ((ULONG)0x00000073L)

//
// MessageId: BAD_SYSTEM_CONFIG_INFO
//
// MessageText:
//
//  BAD_SYSTEM_CONFIG_INFO
//
#define BAD_SYSTEM_CONFIG_INFO           ((ULONG)0x00000074L)

//
// MessageId: CANNOT_WRITE_CONFIGURATION
//
// MessageText:
//
//  CANNOT_WRITE_CONFIGURATION
//
#define CANNOT_WRITE_CONFIGURATION       ((ULONG)0x00000075L)

//
// MessageId: PROCESS_HAS_LOCKED_PAGES
//
// MessageText:
//
//  PROCESS_HAS_LOCKED_PAGES
//
#define PROCESS_HAS_LOCKED_PAGES         ((ULONG)0x00000076L)

//
// MessageId: KERNEL_STACK_INPAGE_ERROR
//
// MessageText:
//
//  KERNEL_STACK_INPAGE_ERROR
//
#define KERNEL_STACK_INPAGE_ERROR        ((ULONG)0x00000077L)

//
// MessageId: PHASE0_EXCEPTION
//
// MessageText:
//
//  PHASE0_EXCEPTION
//
#define PHASE0_EXCEPTION                 ((ULONG)0x00000078L)

//
// MessageId: MISMATCHED_HAL
//
// MessageText:
//
//  MISMATCHED_HAL
//
#define MISMATCHED_HAL                   ((ULONG)0x00000079L)

//
// MessageId: KERNEL_DATA_INPAGE_ERROR
//
// MessageText:
//
//  KERNEL_DATA_INPAGE_ERROR
//
#define KERNEL_DATA_INPAGE_ERROR         ((ULONG)0x0000007AL)

//
// MessageId: INACCESSIBLE_BOOT_DEVICE
//
// MessageText:
//
//  INACCESSIBLE_BOOT_DEVICE
//
#define INACCESSIBLE_BOOT_DEVICE         ((ULONG)0x0000007BL)

//
// MessageId: BUGCODE_NDIS_DRIVER
//
// MessageText:
//
//  BUGCODE_NDIS_DRIVER
//
#define BUGCODE_NDIS_DRIVER              ((ULONG)0x0000007CL)

//
// MessageId: INSTALL_MORE_MEMORY
//
// MessageText:
//
//  INSTALL_MORE_MEMORY
//
#define INSTALL_MORE_MEMORY              ((ULONG)0x0000007DL)

//
// MessageId: SYSTEM_THREAD_EXCEPTION_NOT_HANDLED
//
// MessageText:
//
//  SYSTEM_THREAD_EXCEPTION_NOT_HANDLED
//
#define SYSTEM_THREAD_EXCEPTION_NOT_HANDLED ((ULONG)0x0000007EL)

#define SYSTEM_THREAD_EXCEPTION_NOT_HANDLED_M ((ULONG)0x1000007EL)
//
// MessageId: UNEXPECTED_KERNEL_MODE_TRAP
//
// MessageText:
//
//  UNEXPECTED_KERNEL_MODE_TRAP
//
#define UNEXPECTED_KERNEL_MODE_TRAP      ((ULONG)0x0000007FL)

#define UNEXPECTED_KERNEL_MODE_TRAP_M ((ULONG)0x1000007FL)
//
// MessageId: NMI_HARDWARE_FAILURE
//
// MessageText:
//
//  NMI_HARDWARE_FAILURE
//
#define NMI_HARDWARE_FAILURE             ((ULONG)0x00000080L)

//
// MessageId: SPIN_LOCK_INIT_FAILURE
//
// MessageText:
//
//  SPIN_LOCK_INIT_FAILURE
//
#define SPIN_LOCK_INIT_FAILURE           ((ULONG)0x00000081L)

//
// MessageId: DFS_FILE_SYSTEM
//
// MessageText:
//
//  DFS_FILE_SYSTEM
//
#define DFS_FILE_SYSTEM                  ((ULONG)0x00000082L)

//
// MessageId: OFS_FILE_SYSTEM
//
// MessageText:
//
//  OFS_FILE_SYSTEM
//
#define OFS_FILE_SYSTEM                  ((ULONG)0x00000083L)

//
// MessageId: RECOM_DRIVER
//
// MessageText:
//
//  RECOM_DRIVER
//
#define RECOM_DRIVER                     ((ULONG)0x00000084L)

//
// MessageId: SETUP_FAILURE
//
// MessageText:
//
//  SETUP_FAILURE
//
#define SETUP_FAILURE                    ((ULONG)0x00000085L)

//
// MessageId: AUDIT_FAILURE
//
// MessageText:
//
//  AUDIT_FAILURE
//
#define AUDIT_FAILURE                    ((ULONG)0x00000086L)

//
// MessageId: MBR_CHECKSUM_MISMATCH
//
// MessageText:
//
//  MBR_CHECKSUM_MISMATCH
//
#define MBR_CHECKSUM_MISMATCH            ((ULONG)0x0000008BL)

//
// MessageId: KERNEL_MODE_EXCEPTION_NOT_HANDLED
//
// MessageText:
//
//  KERNEL_MODE_EXCEPTION_NOT_HANDLED
//
#define KERNEL_MODE_EXCEPTION_NOT_HANDLED ((ULONG)0x0000008EL)

#define KERNEL_MODE_EXCEPTION_NOT_HANDLED_M ((ULONG)0x1000008EL)
//
// MessageId: PP0_INITIALIZATION_FAILED
//
// MessageText:
//
//  PP0_INITIALIZATION_FAILED
//
#define PP0_INITIALIZATION_FAILED        ((ULONG)0x0000008FL)

//
// MessageId: PP1_INITIALIZATION_FAILED
//
// MessageText:
//
//  PP1_INITIALIZATION_FAILED
//
#define PP1_INITIALIZATION_FAILED        ((ULONG)0x00000090L)

//
// MessageId: WIN32K_INIT_OR_RIT_FAILURE
//
// MessageText:
//
//  WIN32K_INIT_OR_RIT_FAILURE
//
#define WIN32K_INIT_OR_RIT_FAILURE       ((ULONG)0x00000091L)

//
// MessageId: UP_DRIVER_ON_MP_SYSTEM
//
// MessageText:
//
//  UP_DRIVER_ON_MP_SYSTEM
//
#define UP_DRIVER_ON_MP_SYSTEM           ((ULONG)0x00000092L)

//
// MessageId: INVALID_KERNEL_HANDLE
//
// MessageText:
//
//  INVALID_KERNEL_HANDLE
//
#define INVALID_KERNEL_HANDLE            ((ULONG)0x00000093L)

//
// MessageId: KERNEL_STACK_LOCKED_AT_EXIT
//
// MessageText:
//
//  KERNEL_STACK_LOCKED_AT_EXIT
//
#define KERNEL_STACK_LOCKED_AT_EXIT      ((ULONG)0x00000094L)

//
// MessageId: PNP_INTERNAL_ERROR
//
// MessageText:
//
//  PNP_INTERNAL_ERROR
//
#define PNP_INTERNAL_ERROR               ((ULONG)0x00000095L)

//
// MessageId: INVALID_WORK_QUEUE_ITEM
//
// MessageText:
//
//  INVALID_WORK_QUEUE_ITEM
//
#define INVALID_WORK_QUEUE_ITEM          ((ULONG)0x00000096L)

//
// MessageId: BOUND_IMAGE_UNSUPPORTED
//
// MessageText:
//
//  BOUND_IMAGE_UNSUPPORTED
//
#define BOUND_IMAGE_UNSUPPORTED          ((ULONG)0x00000097L)

//
// MessageId: END_OF_NT_EVALUATION_PERIOD
//
// MessageText:
//
//  END_OF_NT_EVALUATION_PERIOD
//
#define END_OF_NT_EVALUATION_PERIOD      ((ULONG)0x00000098L)

//
// MessageId: INVALID_REGION_OR_SEGMENT
//
// MessageText:
//
//  INVALID_REGION_OR_SEGMENT
//
#define INVALID_REGION_OR_SEGMENT        ((ULONG)0x00000099L)

//
// MessageId: SYSTEM_LICENSE_VIOLATION
//
// MessageText:
//
//  SYSTEM_LICENSE_VIOLATION
//
#define SYSTEM_LICENSE_VIOLATION         ((ULONG)0x0000009AL)

//
// MessageId: UDFS_FILE_SYSTEM
//
// MessageText:
//
//  UDFS_FILE_SYSTEM
//
#define UDFS_FILE_SYSTEM                 ((ULONG)0x0000009BL)

//
// MessageId: MACHINE_CHECK_EXCEPTION
//
// MessageText:
//
//  MACHINE_CHECK_EXCEPTION
//
#define MACHINE_CHECK_EXCEPTION          ((ULONG)0x0000009CL)

//
// MessageId: USER_MODE_HEALTH_MONITOR
//
// MessageText:
//
//  USER_MODE_HEALTH_MONITOR
//
#define USER_MODE_HEALTH_MONITOR         ((ULONG)0x0000009EL)

//
// MessageId: DRIVER_POWER_STATE_FAILURE
//
// MessageText:
//
//  DRIVER_POWER_STATE_FAILURE
//
#define DRIVER_POWER_STATE_FAILURE       ((ULONG)0x0000009FL)

//
// MessageId: INTERNAL_POWER_ERROR
//
// MessageText:
//
//  INTERNAL_POWER_ERROR
//
#define INTERNAL_POWER_ERROR             ((ULONG)0x000000A0L)

//
// MessageId: PCI_BUS_DRIVER_INTERNAL
//
// MessageText:
//
//  PCI_BUS_DRIVER_INTERNAL
//
#define PCI_BUS_DRIVER_INTERNAL          ((ULONG)0x000000A1L)

//
// MessageId: MEMORY_IMAGE_CORRUPT
//
// MessageText:
//
//  MEMORY_IMAGE_CORRUPT
//
#define MEMORY_IMAGE_CORRUPT             ((ULONG)0x000000A2L)

//
// MessageId: ACPI_DRIVER_INTERNAL
//
// MessageText:
//
//  ACPI_DRIVER_INTERNAL
//
#define ACPI_DRIVER_INTERNAL             ((ULONG)0x000000A3L)

//
// MessageId: CNSS_FILE_SYSTEM_FILTER
//
// MessageText:
//
//  CNSS_FILE_SYSTEM_FILTER
//
#define CNSS_FILE_SYSTEM_FILTER          ((ULONG)0x000000A4L)

//
// MessageId: ACPI_BIOS_ERROR
//
// MessageText:
//
//  ACPI_BIOS_ERROR
//
#define ACPI_BIOS_ERROR                  ((ULONG)0x000000A5L)

//
// MessageId: FP_EMULATION_ERROR
//
// MessageText:
//
//  FP_EMULATION_ERROR
//
#define FP_EMULATION_ERROR               ((ULONG)0x000000A6L)

//
// MessageId: BAD_EXHANDLE
//
// MessageText:
//
//  BAD_EXHANDLE
//
#define BAD_EXHANDLE                     ((ULONG)0x000000A7L)

//
// MessageId: BOOTING_IN_SAFEMODE_MINIMAL
//
// MessageText:
//
//  BOOTING_IN_SAFEMODE_MINIMAL
//
#define BOOTING_IN_SAFEMODE_MINIMAL      ((ULONG)0x000000A8L)

//
// MessageId: BOOTING_IN_SAFEMODE_NETWORK
//
// MessageText:
//
//  BOOTING_IN_SAFEMODE_NETWORK
//
#define BOOTING_IN_SAFEMODE_NETWORK      ((ULONG)0x000000A9L)

//
// MessageId: BOOTING_IN_SAFEMODE_DSREPAIR
//
// MessageText:
//
//  BOOTING_IN_SAFEMODE_DSREPAIR
//
#define BOOTING_IN_SAFEMODE_DSREPAIR     ((ULONG)0x000000AAL)

//
// MessageId: SESSION_HAS_VALID_POOL_ON_EXIT
//
// MessageText:
//
//  SESSION_HAS_VALID_POOL_ON_EXIT
//
#define SESSION_HAS_VALID_POOL_ON_EXIT   ((ULONG)0x000000ABL)

//
// MessageId: HAL_MEMORY_ALLOCATION
//
// MessageText:
//
//  HAL_MEMORY_ALLOCATION
//
#define HAL_MEMORY_ALLOCATION            ((ULONG)0x000000ACL)

//
// MessageId: VIDEO_DRIVER_DEBUG_REPORT_REQUEST
//
// MessageText:
//
//  VIDEO_DRIVER_DEBUG_REPORT_REQUEST
//
#define VIDEO_DRIVER_DEBUG_REPORT_REQUEST ((ULONG)0x400000ADL)

//
// MessageId: BGI_DETECTED_VIOLATION
//
// MessageText:
//
//  BGI_DETECTED_VIOLATION
//
#define BGI_DETECTED_VIOLATION           ((ULONG)0x000000B1L)

//
// MessageId: VIDEO_DRIVER_INIT_FAILURE
//
// MessageText:
//
//  VIDEO_DRIVER_INIT_FAILURE
//
#define VIDEO_DRIVER_INIT_FAILURE        ((ULONG)0x000000B4L)

//
// MessageId: BOOTLOG_LOADED
//
// MessageText:
//
//  BOOTLOG_LOADED
//
#define BOOTLOG_LOADED                   ((ULONG)0x000000B5L)

//
// MessageId: BOOTLOG_NOT_LOADED
//
// MessageText:
//
//  BOOTLOG_NOT_LOADED
//
#define BOOTLOG_NOT_LOADED               ((ULONG)0x000000B6L)

//
// MessageId: BOOTLOG_ENABLED
//
// MessageText:
//
//  BOOTLOG_ENABLED
//
#define BOOTLOG_ENABLED                  ((ULONG)0x000000B7L)

//
// MessageId: ATTEMPTED_SWITCH_FROM_DPC
//
// MessageText:
//
//  ATTEMPTED_SWITCH_FROM_DPC
//
#define ATTEMPTED_SWITCH_FROM_DPC        ((ULONG)0x000000B8L)

//
// MessageId: CHIPSET_DETECTED_ERROR
//
// MessageText:
//
//  CHIPSET_DETECTED_ERROR
//
#define CHIPSET_DETECTED_ERROR           ((ULONG)0x000000B9L)

//
// MessageId: SESSION_HAS_VALID_VIEWS_ON_EXIT
//
// MessageText:
//
//  SESSION_HAS_VALID_VIEWS_ON_EXIT
//
#define SESSION_HAS_VALID_VIEWS_ON_EXIT  ((ULONG)0x000000BAL)

//
// MessageId: NETWORK_BOOT_INITIALIZATION_FAILED
//
// MessageText:
//
//  NETWORK_BOOT_INITIALIZATION_FAILED
//
#define NETWORK_BOOT_INITIALIZATION_FAILED ((ULONG)0x000000BBL)

//
// MessageId: NETWORK_BOOT_DUPLICATE_ADDRESS
//
// MessageText:
//
//  NETWORK_BOOT_DUPLICATE_ADDRESS
//
#define NETWORK_BOOT_DUPLICATE_ADDRESS   ((ULONG)0x000000BCL)

//
// MessageId: INVALID_HIBERNATED_STATE
//
// MessageText:
//
//  INVALID_HIBERNATED_STATE
//
#define INVALID_HIBERNATED_STATE         ((ULONG)0x000000BDL)

//
// MessageId: ATTEMPTED_WRITE_TO_READONLY_MEMORY
//
// MessageText:
//
//  ATTEMPTED_WRITE_TO_READONLY_MEMORY
//
#define ATTEMPTED_WRITE_TO_READONLY_MEMORY ((ULONG)0x000000BEL)

//
// MessageId: MUTEX_ALREADY_OWNED
//
// MessageText:
//
//  MUTEX_ALREADY_OWNED
//
#define MUTEX_ALREADY_OWNED              ((ULONG)0x000000BFL)

//
// MessageId: PCI_CONFIG_SPACE_ACCESS_FAILURE
//
// MessageText:
//
//  PCI_CONFIG_SPACE_ACCESS_FAILURE
//
#define PCI_CONFIG_SPACE_ACCESS_FAILURE  ((ULONG)0x000000C0L)

//
// MessageId: SPECIAL_POOL_DETECTED_MEMORY_CORRUPTION
//
// MessageText:
//
//  SPECIAL_POOL_DETECTED_MEMORY_CORRUPTION
//
#define SPECIAL_POOL_DETECTED_MEMORY_CORRUPTION ((ULONG)0x000000C1L)

//
// MessageId: BAD_POOL_CALLER
//
// MessageText:
//
//  BAD_POOL_CALLER
//
#define BAD_POOL_CALLER                  ((ULONG)0x000000C2L)

//
// MessageId: SYSTEM_IMAGE_BAD_SIGNATURE
//
// MessageText:
//
//  SYSTEM_IMAGE_BAD_SIGNATURE
//
#define SYSTEM_IMAGE_BAD_SIGNATURE       ((ULONG)0x000000C3L)

//
// MessageId: DRIVER_VERIFIER_DETECTED_VIOLATION
//
// MessageText:
//
//  DRIVER_VERIFIER_DETECTED_VIOLATION
//
#define DRIVER_VERIFIER_DETECTED_VIOLATION ((ULONG)0x000000C4L)

//
// MessageId: DRIVER_CORRUPTED_EXPOOL
//
// MessageText:
//
//  DRIVER_CORRUPTED_EXPOOL
//
#define DRIVER_CORRUPTED_EXPOOL          ((ULONG)0x000000C5L)

//
// MessageId: DRIVER_CAUGHT_MODIFYING_FREED_POOL
//
// MessageText:
//
//  DRIVER_CAUGHT_MODIFYING_FREED_POOL
//
#define DRIVER_CAUGHT_MODIFYING_FREED_POOL ((ULONG)0x000000C6L)

//
// MessageId: TIMER_OR_DPC_INVALID
//
// MessageText:
//
//  TIMER_OR_DPC_INVALID
//
#define TIMER_OR_DPC_INVALID             ((ULONG)0x000000C7L)

//
// MessageId: IRQL_UNEXPECTED_VALUE
//
// MessageText:
//
//  IRQL_UNEXPECTED_VALUE
//
#define IRQL_UNEXPECTED_VALUE            ((ULONG)0x000000C8L)

//
// MessageId: DRIVER_VERIFIER_IOMANAGER_VIOLATION
//
// MessageText:
//
//  DRIVER_VERIFIER_IOMANAGER_VIOLATION
//
#define DRIVER_VERIFIER_IOMANAGER_VIOLATION ((ULONG)0x000000C9L)

//
// MessageId: PNP_DETECTED_FATAL_ERROR
//
// MessageText:
//
//  PNP_DETECTED_FATAL_ERROR
//
#define PNP_DETECTED_FATAL_ERROR         ((ULONG)0x000000CAL)

//
// MessageId: DRIVER_LEFT_LOCKED_PAGES_IN_PROCESS
//
// MessageText:
//
//  DRIVER_LEFT_LOCKED_PAGES_IN_PROCESS
//
#define DRIVER_LEFT_LOCKED_PAGES_IN_PROCESS ((ULONG)0x000000CBL)

//
// MessageId: PAGE_FAULT_IN_FREED_SPECIAL_POOL
//
// MessageText:
//
//  PAGE_FAULT_IN_FREED_SPECIAL_POOL
//
#define PAGE_FAULT_IN_FREED_SPECIAL_POOL ((ULONG)0x000000CCL)

//
// MessageId: PAGE_FAULT_BEYOND_END_OF_ALLOCATION
//
// MessageText:
//
//  PAGE_FAULT_BEYOND_END_OF_ALLOCATION
//
#define PAGE_FAULT_BEYOND_END_OF_ALLOCATION ((ULONG)0x000000CDL)

//
// MessageId: DRIVER_UNLOADED_WITHOUT_CANCELLING_PENDING_OPERATIONS
//
// MessageText:
//
//  DRIVER_UNLOADED_WITHOUT_CANCELLING_PENDING_OPERATIONS
//
#define DRIVER_UNLOADED_WITHOUT_CANCELLING_PENDING_OPERATIONS ((ULONG)0x000000CEL)

//
// MessageId: TERMINAL_SERVER_DRIVER_MADE_INCORRECT_MEMORY_REFERENCE
//
// MessageText:
//
//  TERMINAL_SERVER_DRIVER_MADE_INCORRECT_MEMORY_REFERENCE
//
#define TERMINAL_SERVER_DRIVER_MADE_INCORRECT_MEMORY_REFERENCE ((ULONG)0x000000CFL)

//
// MessageId: DRIVER_CORRUPTED_MMPOOL
//
// MessageText:
//
//  DRIVER_CORRUPTED_MMPOOL
//
#define DRIVER_CORRUPTED_MMPOOL          ((ULONG)0x000000D0L)

//
// MessageId: DRIVER_IRQL_NOT_LESS_OR_EQUAL
//
// MessageText:
//
//  DRIVER_IRQL_NOT_LESS_OR_EQUAL
//
#define DRIVER_IRQL_NOT_LESS_OR_EQUAL    ((ULONG)0x000000D1L)

//
// MessageId: BUGCODE_ID_DRIVER
//
// MessageText:
//
//  BUGCODE_ID_DRIVER
//
#define BUGCODE_ID_DRIVER                ((ULONG)0x000000D2L)

//
// MessageId: DRIVER_PORTION_MUST_BE_NONPAGED
//
// MessageText:
//
//  DRIVER_PORTION_MUST_BE_NONPAGED
//
#define DRIVER_PORTION_MUST_BE_NONPAGED  ((ULONG)0x000000D3L)

//
// MessageId: SYSTEM_SCAN_AT_RAISED_IRQL_CAUGHT_IMPROPER_DRIVER_UNLOAD
//
// MessageText:
//
//  SYSTEM_SCAN_AT_RAISED_IRQL_CAUGHT_IMPROPER_DRIVER_UNLOAD
//
#define SYSTEM_SCAN_AT_RAISED_IRQL_CAUGHT_IMPROPER_DRIVER_UNLOAD ((ULONG)0x000000D4L)

//
// MessageId: DRIVER_PAGE_FAULT_IN_FREED_SPECIAL_POOL
//
// MessageText:
//
//  DRIVER_PAGE_FAULT_IN_FREED_SPECIAL_POOL
//
#define DRIVER_PAGE_FAULT_IN_FREED_SPECIAL_POOL ((ULONG)0x000000D5L)

//
// MessageId: DRIVER_PAGE_FAULT_BEYOND_END_OF_ALLOCATION
//
// MessageText:
//
//  DRIVER_PAGE_FAULT_BEYOND_END_OF_ALLOCATION
//
#define DRIVER_PAGE_FAULT_BEYOND_END_OF_ALLOCATION ((ULONG)0x000000D6L)

#define DRIVER_PAGE_FAULT_BEYOND_END_OF_ALLOCATION_M ((ULONG)0x100000D6L)
//
// MessageId: DRIVER_UNMAPPING_INVALID_VIEW
//
// MessageText:
//
//  DRIVER_UNMAPPING_INVALID_VIEW
//
#define DRIVER_UNMAPPING_INVALID_VIEW    ((ULONG)0x000000D7L)

//
// MessageId: DRIVER_USED_EXCESSIVE_PTES
//
// MessageText:
//
//  DRIVER_USED_EXCESSIVE_PTES
//
#define DRIVER_USED_EXCESSIVE_PTES       ((ULONG)0x000000D8L)

//
// MessageId: LOCKED_PAGES_TRACKER_CORRUPTION
//
// MessageText:
//
//  LOCKED_PAGES_TRACKER_CORRUPTION
//
#define LOCKED_PAGES_TRACKER_CORRUPTION  ((ULONG)0x000000D9L)

//
// MessageId: SYSTEM_PTE_MISUSE
//
// MessageText:
//
//  SYSTEM_PTE_MISUSE
//
#define SYSTEM_PTE_MISUSE                ((ULONG)0x000000DAL)

//
// MessageId: DRIVER_CORRUPTED_SYSPTES
//
// MessageText:
//
//  DRIVER_CORRUPTED_SYSPTES
//
#define DRIVER_CORRUPTED_SYSPTES         ((ULONG)0x000000DBL)

//
// MessageId: DRIVER_INVALID_STACK_ACCESS
//
// MessageText:
//
//  DRIVER_INVALID_STACK_ACCESS
//
#define DRIVER_INVALID_STACK_ACCESS      ((ULONG)0x000000DCL)

//
// MessageId: POOL_CORRUPTION_IN_FILE_AREA
//
// MessageText:
//
//  POOL_CORRUPTION_IN_FILE_AREA
//
#define POOL_CORRUPTION_IN_FILE_AREA     ((ULONG)0x000000DEL)

//
// MessageId: IMPERSONATING_WORKER_THREAD
//
// MessageText:
//
//  IMPERSONATING_WORKER_THREAD
//
#define IMPERSONATING_WORKER_THREAD      ((ULONG)0x000000DFL)

//
// MessageId: ACPI_BIOS_FATAL_ERROR
//
// MessageText:
//
//  ACPI_BIOS_FATAL_ERROR
//
#define ACPI_BIOS_FATAL_ERROR            ((ULONG)0x000000E0L)

//
// MessageId: WORKER_THREAD_RETURNED_AT_BAD_IRQL
//
// MessageText:
//
//  WORKER_THREAD_RETURNED_AT_BAD_IRQL
//
#define WORKER_THREAD_RETURNED_AT_BAD_IRQL ((ULONG)0x000000E1L)

//
// MessageId: MANUALLY_INITIATED_CRASH
//
// MessageText:
//
//  MANUALLY_INITIATED_CRASH
//
#define MANUALLY_INITIATED_CRASH         ((ULONG)0x000000E2L)

//
// MessageId: RESOURCE_NOT_OWNED
//
// MessageText:
//
//  RESOURCE_NOT_OWNED
//
#define RESOURCE_NOT_OWNED               ((ULONG)0x000000E3L)

//
// MessageId: WORKER_INVALID
//
// MessageText:
//
//  WORKER_INVALID
//
#define WORKER_INVALID                   ((ULONG)0x000000E4L)

//
// MessageId: POWER_FAILURE_SIMULATE
//
// MessageText:
//
//  POWER_FAILURE_SIMULATE
//
#define POWER_FAILURE_SIMULATE           ((ULONG)0x000000E5L)

//
// MessageId: DRIVER_VERIFIER_DMA_VIOLATION
//
// MessageText:
//
//  DRIVER_VERIFIER_DMA_VIOLATION
//
#define DRIVER_VERIFIER_DMA_VIOLATION    ((ULONG)0x000000E6L)

//
// MessageId: INVALID_FLOATING_POINT_STATE
//
// MessageText:
//
//  INVALID_FLOATING_POINT_STATE
//
#define INVALID_FLOATING_POINT_STATE     ((ULONG)0x000000E7L)

//
// MessageId: INVALID_CANCEL_OF_FILE_OPEN
//
// MessageText:
//
//  INVALID_CANCEL_OF_FILE_OPEN
//
#define INVALID_CANCEL_OF_FILE_OPEN      ((ULONG)0x000000E8L)

//
// MessageId: ACTIVE_EX_WORKER_THREAD_TERMINATION
//
// MessageText:
//
//  ACTIVE_EX_WORKER_THREAD_TERMINATION
//
#define ACTIVE_EX_WORKER_THREAD_TERMINATION ((ULONG)0x000000E9L)

//
// MessageId: SAVER_UNSPECIFIED
//
// MessageText:
//
//  SAVER_UNSPECIFIED
//
#define SAVER_UNSPECIFIED                ((ULONG)0x0000F000L)

//
// MessageId: SAVER_BLANKSCREEN
//
// MessageText:
//
//  SAVER_BLANKSCREEN
//
#define SAVER_BLANKSCREEN                ((ULONG)0x0000F002L)

//
// MessageId: SAVER_INPUT
//
// MessageText:
//
//  SAVER_INPUT
//
#define SAVER_INPUT                      ((ULONG)0x0000F003L)

//
// MessageId: SAVER_WATCHDOG
//
// MessageText:
//
//  SAVER_WATCHDOG
//
#define SAVER_WATCHDOG                   ((ULONG)0x0000F004L)

//
// MessageId: SAVER_STARTNOTVISIBLE
//
// MessageText:
//
//  SAVER_STARTNOTVISIBLE
//
#define SAVER_STARTNOTVISIBLE            ((ULONG)0x0000F005L)

//
// MessageId: SAVER_NAVIGATIONMODEL
//
// MessageText:
//
//  SAVER_NAVIGATIONMODEL
//
#define SAVER_NAVIGATIONMODEL            ((ULONG)0x0000F006L)

//
// MessageId: SAVER_OUTOFMEMORY
//
// MessageText:
//
//  SAVER_OUTOFMEMORY
//
#define SAVER_OUTOFMEMORY                ((ULONG)0x0000F007L)

//
// MessageId: SAVER_GRAPHICS
//
// MessageText:
//
//  SAVER_GRAPHICS
//
#define SAVER_GRAPHICS                   ((ULONG)0x0000F008L)

//
// MessageId: SAVER_NAVSERVERTIMEOUT
//
// MessageText:
//
//  SAVER_NAVSERVERTIMEOUT
//
#define SAVER_NAVSERVERTIMEOUT           ((ULONG)0x0000F009L)

//
// MessageId: SAVER_CHROMEPROCESSCRASH
//
// MessageText:
//
//  SAVER_CHROMEPROCESSCRASH
//
#define SAVER_CHROMEPROCESSCRASH         ((ULONG)0x0000F00AL)

//
// MessageId: SAVER_NOTIFICATIONDISMISSAL
//
// MessageText:
//
//  SAVER_NOTIFICATIONDISMISSAL
//
#define SAVER_NOTIFICATIONDISMISSAL      ((ULONG)0x0000F00BL)

//
// MessageId: SAVER_SPEECHDISMISSAL
//
// MessageText:
//
//  SAVER_SPEECHDISMISSAL
//
#define SAVER_SPEECHDISMISSAL            ((ULONG)0x0000F00CL)

//
// MessageId: SAVER_CALLDISMISSAL
//
// MessageText:
//
//  SAVER_CALLDISMISSAL
//
#define SAVER_CALLDISMISSAL              ((ULONG)0x0000F00DL)

//
// MessageId: SAVER_APPBARDISMISSAL
//
// MessageText:
//
//  SAVER_APPBARDISMISSAL
//
#define SAVER_APPBARDISMISSAL            ((ULONG)0x0000F00EL)

//
// MessageId: SAVER_RILADAPTATIONCRASH
//
// MessageText:
//
//  SAVER_RILADAPTATIONCRASH
//
#define SAVER_RILADAPTATIONCRASH         ((ULONG)0x0000F00FL)

//
// MessageId: SAVER_APPLISTUNREACHABLE
//
// MessageText:
//
//  SAVER_APPLISTUNREACHABLE
//
#define SAVER_APPLISTUNREACHABLE         ((ULONG)0x0000F010L)

//
// MessageId: SAVER_REPORTNOTIFICATIONFAILURE
//
// MessageText:
//
//  SAVER_REPORTNOTIFICATIONFAILURE
//
#define SAVER_REPORTNOTIFICATIONFAILURE  ((ULONG)0x0000F011L)

//
// MessageId: SAVER_UNEXPECTEDSHUTDOWN
//
// MessageText:
//
//  SAVER_UNEXPECTEDSHUTDOWN
//
#define SAVER_UNEXPECTEDSHUTDOWN         ((ULONG)0x0000F012L)

//
// MessageId: SAVER_RPCFAILURE
//
// MessageText:
//
//  SAVER_RPCFAILURE
//
#define SAVER_RPCFAILURE                 ((ULONG)0x0000F013L)

//
// MessageId: SAVER_AUXILIARYFULLDUMP
//
// MessageText:
//
//  SAVER_AUXILIARYFULLDUMP
//
#define SAVER_AUXILIARYFULLDUMP          ((ULONG)0x0000F014L)

//
// MessageId: SAVER_ACCOUNTPROVSVCINITFAILURE
//
// MessageText:
//
//  SAVER_ACCOUNTPROVSVCINITFAILURE
//
#define SAVER_ACCOUNTPROVSVCINITFAILURE  ((ULONG)0x0000F015L)

//
// MessageId: SAVER_MTBFCOMMANDTIMEOUT
//
// MessageText:
//
//  SAVER_MTBFCOMMANDTIMEOUT
//
#define SAVER_MTBFCOMMANDTIMEOUT         ((ULONG)0x00000315L)

//
// MessageId: SAVER_MTBFCOMMANDHANG
//
// MessageText:
//
//  SAVER_MTBFCOMMANDHANG
//
#define SAVER_MTBFCOMMANDHANG            ((ULONG)0x0000F101L)

//
// MessageId: SAVER_MTBFPASSBUGCHECK
//
// MessageText:
//
//  SAVER_MTBFPASSBUGCHECK
//
#define SAVER_MTBFPASSBUGCHECK           ((ULONG)0x0000F102L)

//
// MessageId: SAVER_MTBFIOERROR
//
// MessageText:
//
//  SAVER_MTBFIOERROR
//
#define SAVER_MTBFIOERROR                ((ULONG)0x0000F103L)

//
// MessageId: SAVER_RENDERTHREADHANG
//
// MessageText:
//
//  SAVER_RENDERTHREADHANG
//
#define SAVER_RENDERTHREADHANG           ((ULONG)0x0000F200L)

//
// MessageId: SAVER_RENDERMOBILEUIOOM
//
// MessageText:
//
//  SAVER_RENDERMOBILEUIOOM
//
#define SAVER_RENDERMOBILEUIOOM          ((ULONG)0x0000F201L)

//
// MessageId: SAVER_DEVICEUPDATEUNSPECIFIED
//
// MessageText:
//
//  SAVER_DEVICEUPDATEUNSPECIFIED
//
#define SAVER_DEVICEUPDATEUNSPECIFIED    ((ULONG)0x0000F300L)

//
// MessageId: SAVER_AUDIODRIVERHANG
//
// MessageText:
//
//  SAVER_AUDIODRIVERHANG
//
#define SAVER_AUDIODRIVERHANG            ((ULONG)0x0000F400L)

//
// MessageId: SAVER_BATTERYPULLOUT
//
// MessageText:
//
//  SAVER_BATTERYPULLOUT
//
#define SAVER_BATTERYPULLOUT             ((ULONG)0x0000F500L)

//
// MessageId: SAVER_MEDIACORETESTHANG
//
// MessageText:
//
//  SAVER_MEDIACORETESTHANG
//
#define SAVER_MEDIACORETESTHANG          ((ULONG)0x0000F600L)

//
// MessageId: SAVER_RESOURCEMANAGEMENT
//
// MessageText:
//
//  SAVER_RESOURCEMANAGEMENT
//
#define SAVER_RESOURCEMANAGEMENT         ((ULONG)0x0000F700L)

//
// MessageId: SAVER_CAPTURESERVICE
//
// MessageText:
//
//  SAVER_CAPTURESERVICE
//
#define SAVER_CAPTURESERVICE             ((ULONG)0x0000F800L)

//
// MessageId: SAVER_WAITFORSHELLREADY
//
// MessageText:
//
//  SAVER_WAITFORSHELLREADY
//
#define SAVER_WAITFORSHELLREADY          ((ULONG)0x0000F900L)

//
// MessageId: SAVER_NONRESPONSIVEPROCESS
//
// MessageText:
//
//  SAVER_NONRESPONSIVEPROCESS
//
#define SAVER_NONRESPONSIVEPROCESS       ((ULONG)0x00000194L)

//
// MessageId: SAVER_SICKAPPLICATION
//
// MessageText:
//
//  SAVER_SICKAPPLICATION
//
#define SAVER_SICKAPPLICATION            ((ULONG)0x00008866L)

//
// MessageId: THREAD_STUCK_IN_DEVICE_DRIVER
//
// MessageText:
//
//  THREAD_STUCK_IN_DEVICE_DRIVER
//
#define THREAD_STUCK_IN_DEVICE_DRIVER    ((ULONG)0x000000EAL)

#define THREAD_STUCK_IN_DEVICE_DRIVER_M ((ULONG)0x100000EAL)
//
// MessageId: DIRTY_MAPPED_PAGES_CONGESTION
//
// MessageText:
//
//  DIRTY_MAPPED_PAGES_CONGESTION
//
#define DIRTY_MAPPED_PAGES_CONGESTION    ((ULONG)0x000000EBL)

//
// MessageId: SESSION_HAS_VALID_SPECIAL_POOL_ON_EXIT
//
// MessageText:
//
//  SESSION_HAS_VALID_SPECIAL_POOL_ON_EXIT
//
#define SESSION_HAS_VALID_SPECIAL_POOL_ON_EXIT ((ULONG)0x000000ECL)

//
// MessageId: UNMOUNTABLE_BOOT_VOLUME
//
// MessageText:
//
//  UNMOUNTABLE_BOOT_VOLUME
//
#define UNMOUNTABLE_BOOT_VOLUME          ((ULONG)0x000000EDL)

//
// MessageId: CRITICAL_PROCESS_DIED
//
// MessageText:
//
//  CRITICAL_PROCESS_DIED
//
#define CRITICAL_PROCESS_DIED            ((ULONG)0x000000EFL)

//
// MessageId: STORAGE_MINIPORT_ERROR
//
// MessageText:
//
//  STORAGE_MINIPORT_ERROR
//
#define STORAGE_MINIPORT_ERROR           ((ULONG)0x000000F0L)

//
// MessageId: SCSI_VERIFIER_DETECTED_VIOLATION
//
// MessageText:
//
//  SCSI_VERIFIER_DETECTED_VIOLATION
//
#define SCSI_VERIFIER_DETECTED_VIOLATION ((ULONG)0x000000F1L)

//
// MessageId: HARDWARE_INTERRUPT_STORM
//
// MessageText:
//
//  HARDWARE_INTERRUPT_STORM
//
#define HARDWARE_INTERRUPT_STORM         ((ULONG)0x000000F2L)

//
// MessageId: DISORDERLY_SHUTDOWN
//
// MessageText:
//
//  DISORDERLY_SHUTDOWN
//
#define DISORDERLY_SHUTDOWN              ((ULONG)0x000000F3L)

//
// MessageId: CRITICAL_OBJECT_TERMINATION
//
// MessageText:
//
//  CRITICAL_OBJECT_TERMINATION
//
#define CRITICAL_OBJECT_TERMINATION      ((ULONG)0x000000F4L)

//
// MessageId: FLTMGR_FILE_SYSTEM
//
// MessageText:
//
//  FLTMGR_FILE_SYSTEM
//
#define FLTMGR_FILE_SYSTEM               ((ULONG)0x000000F5L)

//
// MessageId: PCI_VERIFIER_DETECTED_VIOLATION
//
// MessageText:
//
//  PCI_VERIFIER_DETECTED_VIOLATION
//
#define PCI_VERIFIER_DETECTED_VIOLATION  ((ULONG)0x000000F6L)

//
// MessageId: DRIVER_OVERRAN_STACK_BUFFER
//
// MessageText:
//
//  DRIVER_OVERRAN_STACK_BUFFER
//
#define DRIVER_OVERRAN_STACK_BUFFER      ((ULONG)0x000000F7L)

//
// MessageId: RAMDISK_BOOT_INITIALIZATION_FAILED
//
// MessageText:
//
//  RAMDISK_BOOT_INITIALIZATION_FAILED
//
#define RAMDISK_BOOT_INITIALIZATION_FAILED ((ULONG)0x000000F8L)

//
// MessageId: DRIVER_RETURNED_STATUS_REPARSE_FOR_VOLUME_OPEN
//
// MessageText:
//
//  DRIVER_RETURNED_STATUS_REPARSE_FOR_VOLUME_OPEN
//
#define DRIVER_RETURNED_STATUS_REPARSE_FOR_VOLUME_OPEN ((ULONG)0x000000F9L)

//
// MessageId: HTTP_DRIVER_CORRUPTED
//
// MessageText:
//
//  HTTP_DRIVER_CORRUPTED
//
#define HTTP_DRIVER_CORRUPTED            ((ULONG)0x000000FAL)

//
// MessageId: RECURSIVE_MACHINE_CHECK
//
// MessageText:
//
//  RECURSIVE_MACHINE_CHECK
//
#define RECURSIVE_MACHINE_CHECK          ((ULONG)0x000000FBL)

//
// MessageId: ATTEMPTED_EXECUTE_OF_NOEXECUTE_MEMORY
//
// MessageText:
//
//  ATTEMPTED_EXECUTE_OF_NOEXECUTE_MEMORY
//
#define ATTEMPTED_EXECUTE_OF_NOEXECUTE_MEMORY ((ULONG)0x000000FCL)

//
// MessageId: DIRTY_NOWRITE_PAGES_CONGESTION
//
// MessageText:
//
//  DIRTY_NOWRITE_PAGES_CONGESTION
//
#define DIRTY_NOWRITE_PAGES_CONGESTION   ((ULONG)0x000000FDL)

//
// MessageId: BUGCODE_USB_DRIVER
//
// MessageText:
//
//  BUGCODE_USB_DRIVER
//
#define BUGCODE_USB_DRIVER               ((ULONG)0x000000FEL)

//
// MessageId: BC_BLUETOOTH_VERIFIER_FAULT
//
// MessageText:
//
//  BC_BLUETOOTH_VERIFIER_FAULT
//
#define BC_BLUETOOTH_VERIFIER_FAULT      ((ULONG)0x00000BFEL)

//
// MessageId: BC_BTHMINI_VERIFIER_FAULT
//
// MessageText:
//
//  BC_BTHMINI_VERIFIER_FAULT
//
#define BC_BTHMINI_VERIFIER_FAULT        ((ULONG)0x00000BFFL)

//
// MessageId: RESERVE_QUEUE_OVERFLOW
//
// MessageText:
//
//  RESERVE_QUEUE_OVERFLOW
//
#define RESERVE_QUEUE_OVERFLOW           ((ULONG)0x000000FFL)

//
// MessageId: LOADER_BLOCK_MISMATCH
//
// MessageText:
//
//  LOADER_BLOCK_MISMATCH
//
#define LOADER_BLOCK_MISMATCH            ((ULONG)0x00000100L)

//
// MessageId: CLOCK_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  CLOCK_WATCHDOG_TIMEOUT
//
#define CLOCK_WATCHDOG_TIMEOUT           ((ULONG)0x00000101L)

//
// MessageId: DPC_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  DPC_WATCHDOG_TIMEOUT
//
#define DPC_WATCHDOG_TIMEOUT             ((ULONG)0x00000102L)

//
// MessageId: MUP_FILE_SYSTEM
//
// MessageText:
//
//  MUP_FILE_SYSTEM
//
#define MUP_FILE_SYSTEM                  ((ULONG)0x00000103L)

//
// MessageId: AGP_INVALID_ACCESS
//
// MessageText:
//
//  AGP_INVALID_ACCESS
//
#define AGP_INVALID_ACCESS               ((ULONG)0x00000104L)

//
// MessageId: AGP_GART_CORRUPTION
//
// MessageText:
//
//  AGP_GART_CORRUPTION
//
#define AGP_GART_CORRUPTION              ((ULONG)0x00000105L)

//
// MessageId: AGP_ILLEGALLY_REPROGRAMMED
//
// MessageText:
//
//  AGP_ILLEGALLY_REPROGRAMMED
//
#define AGP_ILLEGALLY_REPROGRAMMED       ((ULONG)0x00000106L)

//
// MessageId: KERNEL_EXPAND_STACK_ACTIVE
//
// MessageText:
//
//  KERNEL_EXPAND_STACK_ACTIVE
//
#define KERNEL_EXPAND_STACK_ACTIVE       ((ULONG)0x00000107L)

//
// MessageId: THIRD_PARTY_FILE_SYSTEM_FAILURE
//
// MessageText:
//
//  THIRD_PARTY_FILE_SYSTEM_FAILURE
//
#define THIRD_PARTY_FILE_SYSTEM_FAILURE  ((ULONG)0x00000108L)

//
// MessageId: CRITICAL_STRUCTURE_CORRUPTION
//
// MessageText:
//
//  CRITICAL_STRUCTURE_CORRUPTION
//
#define CRITICAL_STRUCTURE_CORRUPTION    ((ULONG)0x00000109L)

//
// MessageId: APP_TAGGING_INITIALIZATION_FAILED
//
// MessageText:
//
//  APP_TAGGING_INITIALIZATION_FAILED
//
#define APP_TAGGING_INITIALIZATION_FAILED ((ULONG)0x0000010AL)

//
// MessageId: DFSC_FILE_SYSTEM
//
// MessageText:
//
//  DFSC_FILE_SYSTEM
//
#define DFSC_FILE_SYSTEM                 ((ULONG)0x0000010BL)

//
// MessageId: FSRTL_EXTRA_CREATE_PARAMETER_VIOLATION
//
// MessageText:
//
//  FSRTL_EXTRA_CREATE_PARAMETER_VIOLATION
//
#define FSRTL_EXTRA_CREATE_PARAMETER_VIOLATION ((ULONG)0x0000010CL)

//
// MessageId: WDF_VIOLATION
//
// MessageText:
//
//  WDF_VIOLATION
//
#define WDF_VIOLATION                    ((ULONG)0x0000010DL)

//
// MessageId: VIDEO_MEMORY_MANAGEMENT_INTERNAL
//
// MessageText:
//
//  VIDEO_MEMORY_MANAGEMENT_INTERNAL
//
#define VIDEO_MEMORY_MANAGEMENT_INTERNAL ((ULONG)0x0000010EL)

//
// MessageId: DRIVER_INVALID_CRUNTIME_PARAMETER
//
// MessageText:
//
//  DRIVER_INVALID_CRUNTIME_PARAMETER
//
#define DRIVER_INVALID_CRUNTIME_PARAMETER ((ULONG)0x00000110L)

//
// MessageId: RECURSIVE_NMI
//
// MessageText:
//
//  RECURSIVE_NMI
//
#define RECURSIVE_NMI                    ((ULONG)0x00000111L)

//
// MessageId: MSRPC_STATE_VIOLATION
//
// MessageText:
//
//  MSRPC_STATE_VIOLATION
//
#define MSRPC_STATE_VIOLATION            ((ULONG)0x00000112L)

//
// MessageId: VIDEO_DXGKRNL_FATAL_ERROR
//
// MessageText:
//
//  VIDEO_DXGKRNL_FATAL_ERROR
//
#define VIDEO_DXGKRNL_FATAL_ERROR        ((ULONG)0x00000113L)

//
// MessageId: VIDEO_SHADOW_DRIVER_FATAL_ERROR
//
// MessageText:
//
//  VIDEO_SHADOW_DRIVER_FATAL_ERROR
//
#define VIDEO_SHADOW_DRIVER_FATAL_ERROR  ((ULONG)0x00000114L)

//
// MessageId: AGP_INTERNAL
//
// MessageText:
//
//  AGP_INTERNAL
//
#define AGP_INTERNAL                     ((ULONG)0x00000115L)

//
// MessageId: VIDEO_TDR_FAILURE
//
// MessageText:
//
//  VIDEO_TDR_FAILURE
//
#define VIDEO_TDR_FAILURE                ((ULONG)0x00000116L)

//
// MessageId: VIDEO_TDR_TIMEOUT_DETECTED
//
// MessageText:
//
//  VIDEO_TDR_TIMEOUT_DETECTED
//
#define VIDEO_TDR_TIMEOUT_DETECTED       ((ULONG)0x00000117L)

//
// MessageId: NTHV_GUEST_ERROR
//
// MessageText:
//
//  NTHV_GUEST_ERROR
//
#define NTHV_GUEST_ERROR                 ((ULONG)0x00000118L)

//
// MessageId: VIDEO_SCHEDULER_INTERNAL_ERROR
//
// MessageText:
//
//  VIDEO_SCHEDULER_INTERNAL_ERROR
//
#define VIDEO_SCHEDULER_INTERNAL_ERROR   ((ULONG)0x00000119L)

//
// MessageId: EM_INITIALIZATION_ERROR
//
// MessageText:
//
//  EM_INITIALIZATION_ERROR
//
#define EM_INITIALIZATION_ERROR          ((ULONG)0x0000011AL)

//
// MessageId: DRIVER_RETURNED_HOLDING_CANCEL_LOCK
//
// MessageText:
//
//  DRIVER_RETURNED_HOLDING_CANCEL_LOCK
//
#define DRIVER_RETURNED_HOLDING_CANCEL_LOCK ((ULONG)0x0000011BL)

//
// MessageId: ATTEMPTED_WRITE_TO_CM_PROTECTED_STORAGE
//
// MessageText:
//
//  ATTEMPTED_WRITE_TO_CM_PROTECTED_STORAGE
//
#define ATTEMPTED_WRITE_TO_CM_PROTECTED_STORAGE ((ULONG)0x0000011CL)

//
// MessageId: EVENT_TRACING_FATAL_ERROR
//
// MessageText:
//
//  EVENT_TRACING_FATAL_ERROR
//
#define EVENT_TRACING_FATAL_ERROR        ((ULONG)0x0000011DL)

//
// MessageId: TOO_MANY_RECURSIVE_FAULTS
//
// MessageText:
//
//  TOO_MANY_RECURSIVE_FAULTS
//
#define TOO_MANY_RECURSIVE_FAULTS        ((ULONG)0x0000011EL)

//
// MessageId: INVALID_DRIVER_HANDLE
//
// MessageText:
//
//  INVALID_DRIVER_HANDLE
//
#define INVALID_DRIVER_HANDLE            ((ULONG)0x0000011FL)

//
// MessageId: BITLOCKER_FATAL_ERROR
//
// MessageText:
//
//  BITLOCKER_FATAL_ERROR
//
#define BITLOCKER_FATAL_ERROR            ((ULONG)0x00000120L)

//
// MessageId: DRIVER_VIOLATION
//
// MessageText:
//
//  DRIVER_VIOLATION
//
#define DRIVER_VIOLATION                 ((ULONG)0x00000121L)

//
// MessageId: WHEA_INTERNAL_ERROR
//
// MessageText:
//
//  WHEA_INTERNAL_ERROR
//
#define WHEA_INTERNAL_ERROR              ((ULONG)0x00000122L)

//
// MessageId: CRYPTO_SELF_TEST_FAILURE
//
// MessageText:
//
//  CRYPTO_SELF_TEST_FAILURE
//
#define CRYPTO_SELF_TEST_FAILURE         ((ULONG)0x00000123L)

//
// MessageId: WHEA_UNCORRECTABLE_ERROR
//
// MessageText:
//
//  WHEA_UNCORRECTABLE_ERROR
//
#define WHEA_UNCORRECTABLE_ERROR         ((ULONG)0x00000124L)

//
// MessageId: NMR_INVALID_STATE
//
// MessageText:
//
//  NMR_INVALID_STATE
//
#define NMR_INVALID_STATE                ((ULONG)0x00000125L)

//
// MessageId: NETIO_INVALID_POOL_CALLER
//
// MessageText:
//
//  NETIO_INVALID_POOL_CALLER
//
#define NETIO_INVALID_POOL_CALLER        ((ULONG)0x00000126L)

//
// MessageId: PAGE_NOT_ZERO
//
// MessageText:
//
//  PAGE_NOT_ZERO
//
#define PAGE_NOT_ZERO                    ((ULONG)0x00000127L)

//
// MessageId: WORKER_THREAD_RETURNED_WITH_BAD_IO_PRIORITY
//
// MessageText:
//
//  WORKER_THREAD_RETURNED_WITH_BAD_IO_PRIORITY
//
#define WORKER_THREAD_RETURNED_WITH_BAD_IO_PRIORITY ((ULONG)0x00000128L)

//
// MessageId: WORKER_THREAD_RETURNED_WITH_BAD_PAGING_IO_PRIORITY
//
// MessageText:
//
//  WORKER_THREAD_RETURNED_WITH_BAD_PAGING_IO_PRIORITY
//
#define WORKER_THREAD_RETURNED_WITH_BAD_PAGING_IO_PRIORITY ((ULONG)0x00000129L)

//
// MessageId: MUI_NO_VALID_SYSTEM_LANGUAGE
//
// MessageText:
//
//  MUI_NO_VALID_SYSTEM_LANGUAGE
//
#define MUI_NO_VALID_SYSTEM_LANGUAGE     ((ULONG)0x0000012AL)

//
// MessageId: FAULTY_HARDWARE_CORRUPTED_PAGE
//
// MessageText:
//
//  FAULTY_HARDWARE_CORRUPTED_PAGE
//
#define FAULTY_HARDWARE_CORRUPTED_PAGE   ((ULONG)0x0000012BL)

//
// MessageId: EXFAT_FILE_SYSTEM
//
// MessageText:
//
//  EXFAT_FILE_SYSTEM
//
#define EXFAT_FILE_SYSTEM                ((ULONG)0x0000012CL)

//
// MessageId: VOLSNAP_OVERLAPPED_TABLE_ACCESS
//
// MessageText:
//
//  VOLSNAP_OVERLAPPED_TABLE_ACCESS
//
#define VOLSNAP_OVERLAPPED_TABLE_ACCESS  ((ULONG)0x0000012DL)

//
// MessageId: INVALID_MDL_RANGE
//
// MessageText:
//
//  INVALID_MDL_RANGE
//
#define INVALID_MDL_RANGE                ((ULONG)0x0000012EL)

//
// MessageId: VHD_BOOT_INITIALIZATION_FAILED
//
// MessageText:
//
//  VHD_BOOT_INITIALIZATION_FAILED
//
#define VHD_BOOT_INITIALIZATION_FAILED   ((ULONG)0x0000012FL)

//
// MessageId: DYNAMIC_ADD_PROCESSOR_MISMATCH
//
// MessageText:
//
//  DYNAMIC_ADD_PROCESSOR_MISMATCH
//
#define DYNAMIC_ADD_PROCESSOR_MISMATCH   ((ULONG)0x00000130L)

//
// MessageId: INVALID_EXTENDED_PROCESSOR_STATE
//
// MessageText:
//
//  INVALID_EXTENDED_PROCESSOR_STATE
//
#define INVALID_EXTENDED_PROCESSOR_STATE ((ULONG)0x00000131L)

//
// MessageId: RESOURCE_OWNER_POINTER_INVALID
//
// MessageText:
//
//  RESOURCE_OWNER_POINTER_INVALID
//
#define RESOURCE_OWNER_POINTER_INVALID   ((ULONG)0x00000132L)

//
// MessageId: DPC_WATCHDOG_VIOLATION
//
// MessageText:
//
//  DPC_WATCHDOG_VIOLATION
//
#define DPC_WATCHDOG_VIOLATION           ((ULONG)0x00000133L)

//
// MessageId: DRIVE_EXTENDER
//
// MessageText:
//
//  DRIVE_EXTENDER
//
#define DRIVE_EXTENDER                   ((ULONG)0x00000134L)

//
// MessageId: REGISTRY_FILTER_DRIVER_EXCEPTION
//
// MessageText:
//
//  REGISTRY_FILTER_DRIVER_EXCEPTION
//
#define REGISTRY_FILTER_DRIVER_EXCEPTION ((ULONG)0x00000135L)

//
// MessageId: VHD_BOOT_HOST_VOLUME_NOT_ENOUGH_SPACE
//
// MessageText:
//
//  VHD_BOOT_HOST_VOLUME_NOT_ENOUGH_SPACE
//
#define VHD_BOOT_HOST_VOLUME_NOT_ENOUGH_SPACE ((ULONG)0x00000136L)

//
// MessageId: WIN32K_HANDLE_MANAGER
//
// MessageText:
//
//  WIN32K_HANDLE_MANAGER
//
#define WIN32K_HANDLE_MANAGER            ((ULONG)0x00000137L)

//
// MessageId: GPIO_CONTROLLER_DRIVER_ERROR
//
// MessageText:
//
//  GPIO_CONTROLLER_DRIVER_ERROR
//
#define GPIO_CONTROLLER_DRIVER_ERROR     ((ULONG)0x00000138L)

//
// MessageId: KERNEL_SECURITY_CHECK_FAILURE
//
// MessageText:
//
//  KERNEL_SECURITY_CHECK_FAILURE
//
#define KERNEL_SECURITY_CHECK_FAILURE    ((ULONG)0x00000139L)

//
// MessageId: KERNEL_MODE_HEAP_CORRUPTION
//
// MessageText:
//
//  KERNEL_MODE_HEAP_CORRUPTION
//
#define KERNEL_MODE_HEAP_CORRUPTION      ((ULONG)0x0000013AL)

//
// MessageId: PASSIVE_INTERRUPT_ERROR
//
// MessageText:
//
//  PASSIVE_INTERRUPT_ERROR
//
#define PASSIVE_INTERRUPT_ERROR          ((ULONG)0x0000013BL)

//
// MessageId: INVALID_IO_BOOST_STATE
//
// MessageText:
//
//  INVALID_IO_BOOST_STATE
//
#define INVALID_IO_BOOST_STATE           ((ULONG)0x0000013CL)

//
// MessageId: CRITICAL_INITIALIZATION_FAILURE
//
// MessageText:
//
//  CRITICAL_INITIALIZATION_FAILURE
//
#define CRITICAL_INITIALIZATION_FAILURE  ((ULONG)0x0000013DL)

//
// MessageId: ERRATA_WORKAROUND_UNSUCCESSFUL
//
// MessageText:
//
//  ERRATA_WORKAROUND_UNSUCCESSFUL
//
#define ERRATA_WORKAROUND_UNSUCCESSFUL   ((ULONG)0x0000013EL)

//
// MessageId: REGISTRY_CALLBACK_DRIVER_EXCEPTION
//
// MessageText:
//
//  REGISTRY_CALLBACK_DRIVER_EXCEPTION
//
#define REGISTRY_CALLBACK_DRIVER_EXCEPTION ((ULONG)0x0000013FL)

//
// MessageId: STORAGE_DEVICE_ABNORMALITY_DETECTED
//
// MessageText:
//
//  STORAGE_DEVICE_ABNORMALITY_DETECTED
//
#define STORAGE_DEVICE_ABNORMALITY_DETECTED ((ULONG)0x00000140L)

//
// MessageId: VIDEO_ENGINE_TIMEOUT_DETECTED
//
// MessageText:
//
//  VIDEO_ENGINE_TIMEOUT_DETECTED
//
#define VIDEO_ENGINE_TIMEOUT_DETECTED    ((ULONG)0x00000141L)

//
// MessageId: VIDEO_TDR_APPLICATION_BLOCKED
//
// MessageText:
//
//  VIDEO_TDR_APPLICATION_BLOCKED
//
#define VIDEO_TDR_APPLICATION_BLOCKED    ((ULONG)0x00000142L)

//
// MessageId: PROCESSOR_DRIVER_INTERNAL
//
// MessageText:
//
//  PROCESSOR_DRIVER_INTERNAL
//
#define PROCESSOR_DRIVER_INTERNAL        ((ULONG)0x00000143L)

//
// MessageId: BUGCODE_USB3_DRIVER
//
// MessageText:
//
//  BUGCODE_USB3_DRIVER
//
#define BUGCODE_USB3_DRIVER              ((ULONG)0x00000144L)

//
// MessageId: SECURE_BOOT_VIOLATION
//
// MessageText:
//
//  SECURE_BOOT_VIOLATION
//
#define SECURE_BOOT_VIOLATION            ((ULONG)0x00000145L)

//
// MessageId: NDIS_NET_BUFFER_LIST_INFO_ILLEGALLY_TRANSFERRED
//
// MessageText:
//
//  NDIS_NET_BUFFER_LIST_INFO_ILLEGALLY_TRANSFERRED
//
#define NDIS_NET_BUFFER_LIST_INFO_ILLEGALLY_TRANSFERRED ((ULONG)0x00000146L)

//
// MessageId: ABNORMAL_RESET_DETECTED
//
// MessageText:
//
//  ABNORMAL_RESET_DETECTED
//
#define ABNORMAL_RESET_DETECTED          ((ULONG)0x00000147L)

//
// MessageId: IO_OBJECT_INVALID
//
// MessageText:
//
//  IO_OBJECT_INVALID
//
#define IO_OBJECT_INVALID                ((ULONG)0x00000148L)

//
// MessageId: REFS_FILE_SYSTEM
//
// MessageText:
//
//  REFS_FILE_SYSTEM
//
#define REFS_FILE_SYSTEM                 ((ULONG)0x00000149L)

//
// MessageId: KERNEL_WMI_INTERNAL
//
// MessageText:
//
//  KERNEL_WMI_INTERNAL
//
#define KERNEL_WMI_INTERNAL              ((ULONG)0x0000014AL)

//
// MessageId: SOC_SUBSYSTEM_FAILURE
//
// MessageText:
//
//  SOC_SUBSYSTEM_FAILURE
//
#define SOC_SUBSYSTEM_FAILURE            ((ULONG)0x0000014BL)

//
// MessageId: FATAL_ABNORMAL_RESET_ERROR
//
// MessageText:
//
//  FATAL_ABNORMAL_RESET_ERROR
//
#define FATAL_ABNORMAL_RESET_ERROR       ((ULONG)0x0000014CL)

//
// MessageId: EXCEPTION_SCOPE_INVALID
//
// MessageText:
//
//  EXCEPTION_SCOPE_INVALID
//
#define EXCEPTION_SCOPE_INVALID          ((ULONG)0x0000014DL)

//
// MessageId: SOC_CRITICAL_DEVICE_REMOVED
//
// MessageText:
//
//  SOC_CRITICAL_DEVICE_REMOVED
//
#define SOC_CRITICAL_DEVICE_REMOVED      ((ULONG)0x0000014EL)

//
// MessageId: PDC_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  PDC_WATCHDOG_TIMEOUT
//
#define PDC_WATCHDOG_TIMEOUT             ((ULONG)0x0000014FL)

//
// MessageId: TCPIP_AOAC_NIC_ACTIVE_REFERENCE_LEAK
//
// MessageText:
//
//  TCPIP_AOAC_NIC_ACTIVE_REFERENCE_LEAK
//
#define TCPIP_AOAC_NIC_ACTIVE_REFERENCE_LEAK ((ULONG)0x00000150L)

//
// MessageId: UNSUPPORTED_INSTRUCTION_MODE
//
// MessageText:
//
//  UNSUPPORTED_INSTRUCTION_MODE
//
#define UNSUPPORTED_INSTRUCTION_MODE     ((ULONG)0x00000151L)

//
// MessageId: INVALID_PUSH_LOCK_FLAGS
//
// MessageText:
//
//  INVALID_PUSH_LOCK_FLAGS
//
#define INVALID_PUSH_LOCK_FLAGS          ((ULONG)0x00000152L)

//
// MessageId: KERNEL_LOCK_ENTRY_LEAKED_ON_THREAD_TERMINATION
//
// MessageText:
//
//  KERNEL_LOCK_ENTRY_LEAKED_ON_THREAD_TERMINATION
//
#define KERNEL_LOCK_ENTRY_LEAKED_ON_THREAD_TERMINATION ((ULONG)0x00000153L)

//
// MessageId: UNEXPECTED_STORE_EXCEPTION
//
// MessageText:
//
//  UNEXPECTED_STORE_EXCEPTION
//
#define UNEXPECTED_STORE_EXCEPTION       ((ULONG)0x00000154L)

//
// MessageId: OS_DATA_TAMPERING
//
// MessageText:
//
//  OS_DATA_TAMPERING
//
#define OS_DATA_TAMPERING                ((ULONG)0x00000155L)

//
// MessageId: WINSOCK_DETECTED_HUNG_CLOSESOCKET_LIVEDUMP
//
// MessageText:
//
//  WINSOCK_DETECTED_HUNG_CLOSESOCKET_LIVEDUMP
//
#define WINSOCK_DETECTED_HUNG_CLOSESOCKET_LIVEDUMP ((ULONG)0x00000156L)

//
// MessageId: KERNEL_THREAD_PRIORITY_FLOOR_VIOLATION
//
// MessageText:
//
//  KERNEL_THREAD_PRIORITY_FLOOR_VIOLATION
//
#define KERNEL_THREAD_PRIORITY_FLOOR_VIOLATION ((ULONG)0x00000157L)

//
// MessageId: ILLEGAL_IOMMU_PAGE_FAULT
//
// MessageText:
//
//  ILLEGAL_IOMMU_PAGE_FAULT
//
#define ILLEGAL_IOMMU_PAGE_FAULT         ((ULONG)0x00000158L)

//
// MessageId: HAL_ILLEGAL_IOMMU_PAGE_FAULT
//
// MessageText:
//
//  HAL_ILLEGAL_IOMMU_PAGE_FAULT
//
#define HAL_ILLEGAL_IOMMU_PAGE_FAULT     ((ULONG)0x00000159L)

//
// MessageId: SDBUS_INTERNAL_ERROR
//
// MessageText:
//
//  SDBUS_INTERNAL_ERROR
//
#define SDBUS_INTERNAL_ERROR             ((ULONG)0x0000015AL)

//
// MessageId: WORKER_THREAD_RETURNED_WITH_SYSTEM_PAGE_PRIORITY_ACTIVE
//
// MessageText:
//
//  WORKER_THREAD_RETURNED_WITH_SYSTEM_PAGE_PRIORITY_ACTIVE
//
#define WORKER_THREAD_RETURNED_WITH_SYSTEM_PAGE_PRIORITY_ACTIVE ((ULONG)0x0000015BL)

//
// MessageId: PDC_WATCHDOG_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  PDC_WATCHDOG_TIMEOUT_LIVEDUMP
//
#define PDC_WATCHDOG_TIMEOUT_LIVEDUMP    ((ULONG)0x0000015CL)

//
// MessageId: SOC_SUBSYSTEM_FAILURE_LIVEDUMP
//
// MessageText:
//
//  SOC_SUBSYSTEM_FAILURE_LIVEDUMP
//
#define SOC_SUBSYSTEM_FAILURE_LIVEDUMP   ((ULONG)0x0000015DL)

//
// MessageId: BUGCODE_NDIS_DRIVER_LIVE_DUMP
//
// MessageText:
//
//  BUGCODE_NDIS_DRIVER_LIVE_DUMP
//
#define BUGCODE_NDIS_DRIVER_LIVE_DUMP    ((ULONG)0x0000015EL)

//
// MessageId: CONNECTED_STANDBY_WATCHDOG_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CONNECTED_STANDBY_WATCHDOG_TIMEOUT_LIVEDUMP
//
#define CONNECTED_STANDBY_WATCHDOG_TIMEOUT_LIVEDUMP ((ULONG)0x0000015FL)

//
// MessageId: WIN32K_ATOMIC_CHECK_FAILURE
//
// MessageText:
//
//  WIN32K_ATOMIC_CHECK_FAILURE
//
#define WIN32K_ATOMIC_CHECK_FAILURE      ((ULONG)0x00000160L)

//
// MessageId: LIVE_SYSTEM_DUMP
//
// MessageText:
//
//  LIVE_SYSTEM_DUMP
//
#define LIVE_SYSTEM_DUMP                 ((ULONG)0x00000161L)

//
// MessageId: KERNEL_AUTO_BOOST_INVALID_LOCK_RELEASE
//
// MessageText:
//
//  KERNEL_AUTO_BOOST_INVALID_LOCK_RELEASE
//
#define KERNEL_AUTO_BOOST_INVALID_LOCK_RELEASE ((ULONG)0x00000162L)

//
// MessageId: WORKER_THREAD_TEST_CONDITION
//
// MessageText:
//
//  WORKER_THREAD_TEST_CONDITION
//
#define WORKER_THREAD_TEST_CONDITION     ((ULONG)0x00000163L)

//
// MessageId: WIN32K_CRITICAL_FAILURE
//
// MessageText:
//
//  WIN32K_CRITICAL_FAILURE
//
#define WIN32K_CRITICAL_FAILURE          ((ULONG)0x00000164L)

//
// MessageId: CLUSTER_CSV_STATUS_IO_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSV_STATUS_IO_TIMEOUT_LIVEDUMP
//
#define CLUSTER_CSV_STATUS_IO_TIMEOUT_LIVEDUMP ((ULONG)0x00000165L)

//
// MessageId: CLUSTER_RESOURCE_CALL_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_RESOURCE_CALL_TIMEOUT_LIVEDUMP
//
#define CLUSTER_RESOURCE_CALL_TIMEOUT_LIVEDUMP ((ULONG)0x00000166L)

//
// MessageId: CLUSTER_CSV_SNAPSHOT_DEVICE_INFO_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSV_SNAPSHOT_DEVICE_INFO_TIMEOUT_LIVEDUMP
//
#define CLUSTER_CSV_SNAPSHOT_DEVICE_INFO_TIMEOUT_LIVEDUMP ((ULONG)0x00000167L)

//
// MessageId: CLUSTER_CSV_STATE_TRANSITION_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSV_STATE_TRANSITION_TIMEOUT_LIVEDUMP
//
#define CLUSTER_CSV_STATE_TRANSITION_TIMEOUT_LIVEDUMP ((ULONG)0x00000168L)

//
// MessageId: CLUSTER_CSV_VOLUME_ARRIVAL_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSV_VOLUME_ARRIVAL_LIVEDUMP
//
#define CLUSTER_CSV_VOLUME_ARRIVAL_LIVEDUMP ((ULONG)0x00000169L)

//
// MessageId: CLUSTER_CSV_VOLUME_REMOVAL_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSV_VOLUME_REMOVAL_LIVEDUMP
//
#define CLUSTER_CSV_VOLUME_REMOVAL_LIVEDUMP ((ULONG)0x0000016AL)

//
// MessageId: CLUSTER_CSV_CLUSTER_WATCHDOG_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSV_CLUSTER_WATCHDOG_LIVEDUMP
//
#define CLUSTER_CSV_CLUSTER_WATCHDOG_LIVEDUMP ((ULONG)0x0000016BL)

//
// MessageId: INVALID_RUNDOWN_PROTECTION_FLAGS
//
// MessageText:
//
//  INVALID_RUNDOWN_PROTECTION_FLAGS
//
#define INVALID_RUNDOWN_PROTECTION_FLAGS ((ULONG)0x0000016CL)

//
// MessageId: INVALID_SLOT_ALLOCATOR_FLAGS
//
// MessageText:
//
//  INVALID_SLOT_ALLOCATOR_FLAGS
//
#define INVALID_SLOT_ALLOCATOR_FLAGS     ((ULONG)0x0000016DL)

//
// MessageId: ERESOURCE_INVALID_RELEASE
//
// MessageText:
//
//  ERESOURCE_INVALID_RELEASE
//
#define ERESOURCE_INVALID_RELEASE        ((ULONG)0x0000016EL)

//
// MessageId: CLUSTER_CSV_STATE_TRANSITION_INTERVAL_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSV_STATE_TRANSITION_INTERVAL_TIMEOUT_LIVEDUMP
//
#define CLUSTER_CSV_STATE_TRANSITION_INTERVAL_TIMEOUT_LIVEDUMP ((ULONG)0x0000016FL)

//
// MessageId: CLUSTER_CSV_CLUSSVC_DISCONNECT_WATCHDOG
//
// MessageText:
//
//  CLUSTER_CSV_CLUSSVC_DISCONNECT_WATCHDOG
//
#define CLUSTER_CSV_CLUSSVC_DISCONNECT_WATCHDOG ((ULONG)0x00000170L)

//
// MessageId: CRYPTO_LIBRARY_INTERNAL_ERROR
//
// MessageText:
//
//  CRYPTO_LIBRARY_INTERNAL_ERROR
//
#define CRYPTO_LIBRARY_INTERNAL_ERROR    ((ULONG)0x00000171L)

//
// MessageId: SECURE_KERNEL_HIBERNATE_ERROR
//
// MessageText:
//
//  SECURE_KERNEL_HIBERNATE_ERROR
//
#define SECURE_KERNEL_HIBERNATE_ERROR    ((ULONG)0x00000172L)

//
// MessageId: COREMSGCALL_INTERNAL_ERROR
//
// MessageText:
//
//  COREMSGCALL_INTERNAL_ERROR
//
#define COREMSGCALL_INTERNAL_ERROR       ((ULONG)0x00000173L)

//
// MessageId: COREMSG_INTERNAL_ERROR
//
// MessageText:
//
//  COREMSG_INTERNAL_ERROR
//
#define COREMSG_INTERNAL_ERROR           ((ULONG)0x00000174L)

//
// MessageId: PREVIOUS_FATAL_ABNORMAL_RESET_ERROR
//
// MessageText:
//
//  PREVIOUS_FATAL_ABNORMAL_RESET_ERROR
//
#define PREVIOUS_FATAL_ABNORMAL_RESET_ERROR ((ULONG)0x00000175L)

//
// MessageId: STORAGE_STACK_FATAL_ERROR
//
// MessageText:
//
//  STORAGE_STACK_FATAL_ERROR
//
#define STORAGE_STACK_FATAL_ERROR        ((ULONG)0x00000176L)

//
// MessageId: ELAM_DRIVER_DETECTED_FATAL_ERROR
//
// MessageText:
//
//  ELAM_DRIVER_DETECTED_FATAL_ERROR
//
#define ELAM_DRIVER_DETECTED_FATAL_ERROR ((ULONG)0x00000178L)

//
// MessageId: CLUSTER_CLUSPORT_STATUS_IO_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CLUSPORT_STATUS_IO_TIMEOUT_LIVEDUMP
//
#define CLUSTER_CLUSPORT_STATUS_IO_TIMEOUT_LIVEDUMP ((ULONG)0x00000179L)

//
// MessageId: PROFILER_CONFIGURATION_ILLEGAL
//
// MessageText:
//
//  PROFILER_CONFIGURATION_ILLEGAL
//
#define PROFILER_CONFIGURATION_ILLEGAL   ((ULONG)0x0000017BL)

//
// MessageId: PDC_LOCK_WATCHDOG_LIVEDUMP
//
// MessageText:
//
//  PDC_LOCK_WATCHDOG_LIVEDUMP
//
#define PDC_LOCK_WATCHDOG_LIVEDUMP       ((ULONG)0x0000017CL)

//
// MessageId: PDC_UNEXPECTED_REVOCATION_LIVEDUMP
//
// MessageText:
//
//  PDC_UNEXPECTED_REVOCATION_LIVEDUMP
//
#define PDC_UNEXPECTED_REVOCATION_LIVEDUMP ((ULONG)0x0000017DL)

//
// MessageId: MICROCODE_REVISION_MISMATCH
//
// MessageText:
//
//  MICROCODE_REVISION_MISMATCH
//
#define MICROCODE_REVISION_MISMATCH      ((ULONG)0x0000017EL)

//
// MessageId: HYPERGUARD_INITIALIZATION_FAILURE
//
// MessageText:
//
//  HYPERGUARD_INITIALIZATION_FAILURE
//
#define HYPERGUARD_INITIALIZATION_FAILURE ((ULONG)0x0000017FL)

//
// MessageId: WVR_LIVEDUMP_REPLICATION_IOCONTEXT_TIMEOUT
//
// MessageText:
//
//  WVR_LIVEDUMP_REPLICATION_IOCONTEXT_TIMEOUT
//
#define WVR_LIVEDUMP_REPLICATION_IOCONTEXT_TIMEOUT ((ULONG)0x00000180L)

//
// MessageId: WVR_LIVEDUMP_STATE_TRANSITION_TIMEOUT
//
// MessageText:
//
//  WVR_LIVEDUMP_STATE_TRANSITION_TIMEOUT
//
#define WVR_LIVEDUMP_STATE_TRANSITION_TIMEOUT ((ULONG)0x00000181L)

//
// MessageId: WVR_LIVEDUMP_RECOVERY_IOCONTEXT_TIMEOUT
//
// MessageText:
//
//  WVR_LIVEDUMP_RECOVERY_IOCONTEXT_TIMEOUT
//
#define WVR_LIVEDUMP_RECOVERY_IOCONTEXT_TIMEOUT ((ULONG)0x00000182L)

//
// MessageId: WVR_LIVEDUMP_APP_IO_TIMEOUT
//
// MessageText:
//
//  WVR_LIVEDUMP_APP_IO_TIMEOUT
//
#define WVR_LIVEDUMP_APP_IO_TIMEOUT      ((ULONG)0x00000183L)

//
// MessageId: WVR_LIVEDUMP_MANUALLY_INITIATED
//
// MessageText:
//
//  WVR_LIVEDUMP_MANUALLY_INITIATED
//
#define WVR_LIVEDUMP_MANUALLY_INITIATED  ((ULONG)0x00000184L)

//
// MessageId: WVR_LIVEDUMP_STATE_FAILURE
//
// MessageText:
//
//  WVR_LIVEDUMP_STATE_FAILURE
//
#define WVR_LIVEDUMP_STATE_FAILURE       ((ULONG)0x00000185L)

//
// MessageId: WVR_LIVEDUMP_CRITICAL_ERROR
//
// MessageText:
//
//  WVR_LIVEDUMP_CRITICAL_ERROR
//
#define WVR_LIVEDUMP_CRITICAL_ERROR      ((ULONG)0x00000186L)

//
// MessageId: VIDEO_DWMINIT_TIMEOUT_FALLBACK_BDD
//
// MessageText:
//
//  VIDEO_DWMINIT_TIMEOUT_FALLBACK_BDD
//
#define VIDEO_DWMINIT_TIMEOUT_FALLBACK_BDD ((ULONG)0x00000187L)

//
// MessageId: CLUSTER_CSVFS_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_CSVFS_LIVEDUMP
//
#define CLUSTER_CSVFS_LIVEDUMP           ((ULONG)0x00000188L)

//
// MessageId: BAD_OBJECT_HEADER
//
// MessageText:
//
//  BAD_OBJECT_HEADER
//
#define BAD_OBJECT_HEADER                ((ULONG)0x00000189L)

//
// MessageId: SILO_CORRUPT
//
// MessageText:
//
//  SILO_CORRUPT
//
#define SILO_CORRUPT                     ((ULONG)0x0000018AL)

//
// MessageId: SECURE_KERNEL_ERROR
//
// MessageText:
//
//  SECURE_KERNEL_ERROR
//
#define SECURE_KERNEL_ERROR              ((ULONG)0x0000018BL)

//
// MessageId: HYPERGUARD_VIOLATION
//
// MessageText:
//
//  HYPERGUARD_VIOLATION
//
#define HYPERGUARD_VIOLATION             ((ULONG)0x0000018CL)

//
// MessageId: SECURE_FAULT_UNHANDLED
//
// MessageText:
//
//  SECURE_FAULT_UNHANDLED
//
#define SECURE_FAULT_UNHANDLED           ((ULONG)0x0000018DL)

//
// MessageId: KERNEL_PARTITION_REFERENCE_VIOLATION
//
// MessageText:
//
//  KERNEL_PARTITION_REFERENCE_VIOLATION
//
#define KERNEL_PARTITION_REFERENCE_VIOLATION ((ULONG)0x0000018EL)

//
// MessageId: SYNTHETIC_EXCEPTION_UNHANDLED
//
// MessageText:
//
//  SYNTHETIC_EXCEPTION_UNHANDLED
//
#define SYNTHETIC_EXCEPTION_UNHANDLED    ((ULONG)0x0000018FL)

//
// MessageId: WIN32K_CRITICAL_FAILURE_LIVEDUMP
//
// MessageText:
//
//  WIN32K_CRITICAL_FAILURE_LIVEDUMP
//
#define WIN32K_CRITICAL_FAILURE_LIVEDUMP ((ULONG)0x00000190L)

//
// MessageId: PF_DETECTED_CORRUPTION
//
// MessageText:
//
//  PF_DETECTED_CORRUPTION
//
#define PF_DETECTED_CORRUPTION           ((ULONG)0x00000191L)

//
// MessageId: KERNEL_AUTO_BOOST_LOCK_ACQUISITION_WITH_RAISED_IRQL
//
// MessageText:
//
//  KERNEL_AUTO_BOOST_LOCK_ACQUISITION_WITH_RAISED_IRQL
//
#define KERNEL_AUTO_BOOST_LOCK_ACQUISITION_WITH_RAISED_IRQL ((ULONG)0x00000192L)

//
// MessageId: VIDEO_DXGKRNL_LIVEDUMP
//
// MessageText:
//
//  VIDEO_DXGKRNL_LIVEDUMP
//
#define VIDEO_DXGKRNL_LIVEDUMP           ((ULONG)0x00000193L)

//
// MessageId: KERNEL_STORAGE_SLOT_IN_USE
//
// MessageText:
//
//  KERNEL_STORAGE_SLOT_IN_USE
//
#define KERNEL_STORAGE_SLOT_IN_USE       ((ULONG)0x00000199L)

//
// MessageId: SMB_SERVER_LIVEDUMP
//
// MessageText:
//
//  SMB_SERVER_LIVEDUMP
//
#define SMB_SERVER_LIVEDUMP              ((ULONG)0x00000195L)

//
// MessageId: LOADER_ROLLBACK_DETECTED
//
// MessageText:
//
//  LOADER_ROLLBACK_DETECTED
//
#define LOADER_ROLLBACK_DETECTED         ((ULONG)0x00000196L)

//
// MessageId: WIN32K_SECURITY_FAILURE
//
// MessageText:
//
//  WIN32K_SECURITY_FAILURE
//
#define WIN32K_SECURITY_FAILURE          ((ULONG)0x00000197L)

//
// MessageId: UFX_LIVEDUMP
//
// MessageText:
//
//  UFX_LIVEDUMP
//
#define UFX_LIVEDUMP                     ((ULONG)0x00000198L)

//
// MessageId: WORKER_THREAD_RETURNED_WHILE_ATTACHED_TO_SILO
//
// MessageText:
//
//  WORKER_THREAD_RETURNED_WHILE_ATTACHED_TO_SILO
//
#define WORKER_THREAD_RETURNED_WHILE_ATTACHED_TO_SILO ((ULONG)0x0000019AL)

//
// MessageId: TTM_FATAL_ERROR
//
// MessageText:
//
//  TTM_FATAL_ERROR
//
#define TTM_FATAL_ERROR                  ((ULONG)0x0000019BL)

//
// MessageId: WIN32K_POWER_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  WIN32K_POWER_WATCHDOG_TIMEOUT
//
#define WIN32K_POWER_WATCHDOG_TIMEOUT    ((ULONG)0x0000019CL)

//
// MessageId: CLUSTER_SVHDX_LIVEDUMP
//
// MessageText:
//
//  CLUSTER_SVHDX_LIVEDUMP
//
#define CLUSTER_SVHDX_LIVEDUMP           ((ULONG)0x0000019DL)

//
// MessageId: BUGCODE_NETADAPTER_DRIVER
//
// MessageText:
//
//  BUGCODE_NETADAPTER_DRIVER
//
#define BUGCODE_NETADAPTER_DRIVER        ((ULONG)0x0000019EL)

//
// MessageId: PDC_PRIVILEGE_CHECK_LIVEDUMP
//
// MessageText:
//
//  PDC_PRIVILEGE_CHECK_LIVEDUMP
//
#define PDC_PRIVILEGE_CHECK_LIVEDUMP     ((ULONG)0x0000019FL)

//
// MessageId: TTM_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  TTM_WATCHDOG_TIMEOUT
//
#define TTM_WATCHDOG_TIMEOUT             ((ULONG)0x000001A0L)

//
// MessageId: WIN32K_CALLOUT_WATCHDOG_LIVEDUMP
//
// MessageText:
//
//  WIN32K_CALLOUT_WATCHDOG_LIVEDUMP
//
#define WIN32K_CALLOUT_WATCHDOG_LIVEDUMP ((ULONG)0x000001A1L)

//
// MessageId: WIN32K_CALLOUT_WATCHDOG_BUGCHECK
//
// MessageText:
//
//  WIN32K_CALLOUT_WATCHDOG_BUGCHECK
//
#define WIN32K_CALLOUT_WATCHDOG_BUGCHECK ((ULONG)0x000001A2L)

//
// MessageId: CALL_HAS_NOT_RETURNED_WATCHDOG_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  CALL_HAS_NOT_RETURNED_WATCHDOG_TIMEOUT_LIVEDUMP
//
#define CALL_HAS_NOT_RETURNED_WATCHDOG_TIMEOUT_LIVEDUMP ((ULONG)0x000001A3L)

//
// MessageId: DRIPS_SW_HW_DIVERGENCE_LIVEDUMP
//
// MessageText:
//
//  DRIPS_SW_HW_DIVERGENCE_LIVEDUMP
//
#define DRIPS_SW_HW_DIVERGENCE_LIVEDUMP  ((ULONG)0x000001A4L)

//
// MessageId: USB_DRIPS_BLOCKER_SURPRISE_REMOVAL_LIVEDUMP
//
// MessageText:
//
//  USB_DRIPS_BLOCKER_SURPRISE_REMOVAL_LIVEDUMP
//
#define USB_DRIPS_BLOCKER_SURPRISE_REMOVAL_LIVEDUMP ((ULONG)0x000001A5L)

//
// MessageId: BLUETOOTH_ERROR_RECOVERY_LIVEDUMP
//
// MessageText:
//
//  BLUETOOTH_ERROR_RECOVERY_LIVEDUMP
//
#define BLUETOOTH_ERROR_RECOVERY_LIVEDUMP ((ULONG)0x000001A6L)

//
// MessageId: SMB_REDIRECTOR_LIVEDUMP
//
// MessageText:
//
//  SMB_REDIRECTOR_LIVEDUMP
//
#define SMB_REDIRECTOR_LIVEDUMP          ((ULONG)0x000001A7L)

//
// MessageId: VIDEO_DXGKRNL_BLACK_SCREEN_LIVEDUMP
//
// MessageText:
//
//  VIDEO_DXGKRNL_BLACK_SCREEN_LIVEDUMP
//
#define VIDEO_DXGKRNL_BLACK_SCREEN_LIVEDUMP ((ULONG)0x000001A8L)

//
// MessageId: DIRECTED_FX_TRANSITION_LIVEDUMP
//
// MessageText:
//
//  DIRECTED_FX_TRANSITION_LIVEDUMP
//
#define DIRECTED_FX_TRANSITION_LIVEDUMP  ((ULONG)0x000001A9L)

//
// MessageId: EXCEPTION_ON_INVALID_STACK
//
// MessageText:
//
//  EXCEPTION_ON_INVALID_STACK
//
#define EXCEPTION_ON_INVALID_STACK       ((ULONG)0x000001AAL)

//
// MessageId: UNWIND_ON_INVALID_STACK
//
// MessageText:
//
//  UNWIND_ON_INVALID_STACK
//
#define UNWIND_ON_INVALID_STACK          ((ULONG)0x000001ABL)

//
// MessageId: VIDEO_MINIPORT_FAILED_LIVEDUMP
//
// MessageText:
//
//  VIDEO_MINIPORT_FAILED_LIVEDUMP
//
#define VIDEO_MINIPORT_FAILED_LIVEDUMP   ((ULONG)0x000001B0L)

//
// MessageId: VIDEO_MINIPORT_BLACK_SCREEN_LIVEDUMP
//
// MessageText:
//
//  VIDEO_MINIPORT_BLACK_SCREEN_LIVEDUMP
//
#define VIDEO_MINIPORT_BLACK_SCREEN_LIVEDUMP ((ULONG)0x000001B8L)

//
// MessageId: DRIVER_VERIFIER_DETECTED_VIOLATION_LIVEDUMP
//
// MessageText:
//
//  DRIVER_VERIFIER_DETECTED_VIOLATION_LIVEDUMP
//
#define DRIVER_VERIFIER_DETECTED_VIOLATION_LIVEDUMP ((ULONG)0x000001C4L)

//
// MessageId: IO_THREADPOOL_DEADLOCK_LIVEDUMP
//
// MessageText:
//
//  IO_THREADPOOL_DEADLOCK_LIVEDUMP
//
#define IO_THREADPOOL_DEADLOCK_LIVEDUMP  ((ULONG)0x000001C5L)

//
// MessageId: FAST_ERESOURCE_PRECONDITION_VIOLATION
//
// MessageText:
//
//  FAST_ERESOURCE_PRECONDITION_VIOLATION
//
#define FAST_ERESOURCE_PRECONDITION_VIOLATION ((ULONG)0x000001C6L)

//
// MessageId: STORE_DATA_STRUCTURE_CORRUPTION
//
// MessageText:
//
//  STORE_DATA_STRUCTURE_CORRUPTION
//
#define STORE_DATA_STRUCTURE_CORRUPTION  ((ULONG)0x000001C7L)

//
// MessageId: MANUALLY_INITIATED_POWER_BUTTON_HOLD
//
// MessageText:
//
//  MANUALLY_INITIATED_POWER_BUTTON_HOLD
//
#define MANUALLY_INITIATED_POWER_BUTTON_HOLD ((ULONG)0x000001C8L)

//
// MessageId: USER_MODE_HEALTH_MONITOR_LIVEDUMP
//
// MessageText:
//
//  USER_MODE_HEALTH_MONITOR_LIVEDUMP
//
#define USER_MODE_HEALTH_MONITOR_LIVEDUMP ((ULONG)0x000001C9L)

//
// MessageId: SYNTHETIC_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  SYNTHETIC_WATCHDOG_TIMEOUT
//
#define SYNTHETIC_WATCHDOG_TIMEOUT       ((ULONG)0x000001CAL)

//
// MessageId: INVALID_SILO_DETACH
//
// MessageText:
//
//  INVALID_SILO_DETACH
//
#define INVALID_SILO_DETACH              ((ULONG)0x000001CBL)

//
// MessageId: EXRESOURCE_TIMEOUT_LIVEDUMP
//
// MessageText:
//
//  EXRESOURCE_TIMEOUT_LIVEDUMP
//
#define EXRESOURCE_TIMEOUT_LIVEDUMP      ((ULONG)0x000001CCL)

//
// MessageId: INVALID_CALLBACK_STACK_ADDRESS
//
// MessageText:
//
//  INVALID_CALLBACK_STACK_ADDRESS
//
#define INVALID_CALLBACK_STACK_ADDRESS   ((ULONG)0x000001CDL)

//
// MessageId: INVALID_KERNEL_STACK_ADDRESS
//
// MessageText:
//
//  INVALID_KERNEL_STACK_ADDRESS
//
#define INVALID_KERNEL_STACK_ADDRESS     ((ULONG)0x000001CEL)

//
// MessageId: HARDWARE_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  HARDWARE_WATCHDOG_TIMEOUT
//
#define HARDWARE_WATCHDOG_TIMEOUT        ((ULONG)0x000001CFL)

//
// MessageId: ACPI_FIRMWARE_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  ACPI_FIRMWARE_WATCHDOG_TIMEOUT
//
#define ACPI_FIRMWARE_WATCHDOG_TIMEOUT   ((ULONG)0x000001D0L)

//
// MessageId: TELEMETRY_ASSERTS_LIVEDUMP
//
// MessageText:
//
//  TELEMETRY_ASSERTS_LIVEDUMP
//
#define TELEMETRY_ASSERTS_LIVEDUMP       ((ULONG)0x000001D1L)

//
// MessageId: WORKER_THREAD_INVALID_STATE
//
// MessageText:
//
//  WORKER_THREAD_INVALID_STATE
//
#define WORKER_THREAD_INVALID_STATE      ((ULONG)0x000001D2L)

//
// MessageId: WFP_INVALID_OPERATION
//
// MessageText:
//
//  WFP_INVALID_OPERATION
//
#define WFP_INVALID_OPERATION            ((ULONG)0x000001D3L)

//
// MessageId: UCMUCSI_LIVEDUMP
//
// MessageText:
//
//  UCMUCSI_LIVEDUMP
//
#define UCMUCSI_LIVEDUMP                 ((ULONG)0x000001D4L)

//
// MessageId: DRIVER_PNP_WATCHDOG
//
// MessageText:
//
//  DRIVER_PNP_WATCHDOG
//
#define DRIVER_PNP_WATCHDOG              ((ULONG)0x000001D5L)

//
// MessageId: WORKER_THREAD_RETURNED_WITH_NON_DEFAULT_WORKLOAD_CLASS
//
// MessageText:
//
//  WORKER_THREAD_RETURNED_WITH_NON_DEFAULT_WORKLOAD_CLASS
//
#define WORKER_THREAD_RETURNED_WITH_NON_DEFAULT_WORKLOAD_CLASS ((ULONG)0x000001D6L)

//
// MessageId: EFS_FATAL_ERROR
//
// MessageText:
//
//  EFS_FATAL_ERROR
//
#define EFS_FATAL_ERROR                  ((ULONG)0x000001D7L)

//
// MessageId: UCMUCSI_FAILURE
//
// MessageText:
//
//  UCMUCSI_FAILURE
//
#define UCMUCSI_FAILURE                  ((ULONG)0x000001D8L)

//
// MessageId: HAL_IOMMU_INTERNAL_ERROR
//
// MessageText:
//
//  HAL_IOMMU_INTERNAL_ERROR
//
#define HAL_IOMMU_INTERNAL_ERROR         ((ULONG)0x000001D9L)

//
// MessageId: HAL_BLOCKED_PROCESSOR_INTERNAL_ERROR
//
// MessageText:
//
//  HAL_BLOCKED_PROCESSOR_INTERNAL_ERROR
//
#define HAL_BLOCKED_PROCESSOR_INTERNAL_ERROR ((ULONG)0x000001DAL)

//
// MessageId: IPI_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  IPI_WATCHDOG_TIMEOUT
//
#define IPI_WATCHDOG_TIMEOUT             ((ULONG)0x000001DBL)

//
// MessageId: DMA_COMMON_BUFFER_VECTOR_ERROR
//
// MessageText:
//
//  DMA_COMMON_BUFFER_VECTOR_ERROR
//
#define DMA_COMMON_BUFFER_VECTOR_ERROR   ((ULONG)0x000001DCL)

//
// MessageId: BUGCODE_MBBADAPTER_DRIVER
//
// MessageText:
//
//  BUGCODE_MBBADAPTER_DRIVER
//
#define BUGCODE_MBBADAPTER_DRIVER        ((ULONG)0x000001DDL)

//
// MessageId: BUGCODE_WIFIADAPTER_DRIVER
//
// MessageText:
//
//  BUGCODE_WIFIADAPTER_DRIVER
//
#define BUGCODE_WIFIADAPTER_DRIVER       ((ULONG)0x000001DEL)

//
// MessageId: PROCESSOR_START_TIMEOUT
//
// MessageText:
//
//  PROCESSOR_START_TIMEOUT
//
#define PROCESSOR_START_TIMEOUT          ((ULONG)0x000001DFL)

//
// MessageId: INVALID_ALTERNATE_SYSTEM_CALL_HANDLER_REGISTRATION
//
// MessageText:
//
//  INVALID_ALTERNATE_SYSTEM_CALL_HANDLER_REGISTRATION
//
#define INVALID_ALTERNATE_SYSTEM_CALL_HANDLER_REGISTRATION ((ULONG)0x000001E0L)

//
// MessageId: DEVICE_DIAGNOSTIC_LOG_LIVEDUMP
//
// MessageText:
//
//  DEVICE_DIAGNOSTIC_LOG_LIVEDUMP
//
#define DEVICE_DIAGNOSTIC_LOG_LIVEDUMP   ((ULONG)0x000001E1L)

//
// MessageId: AZURE_DEVICE_FW_DUMP
//
// MessageText:
//
//  AZURE_DEVICE_FW_DUMP
//
#define AZURE_DEVICE_FW_DUMP             ((ULONG)0x000001E2L)

//
// MessageId: BREAKAWAY_CABLE_TRANSITION
//
// MessageText:
//
//  BREAKAWAY_CABLE_TRANSITION
//
#define BREAKAWAY_CABLE_TRANSITION       ((ULONG)0x000001E3L)

//
// MessageId: VIDEO_DXGKRNL_SYSMM_FATAL_ERROR
//
// MessageText:
//
//  VIDEO_DXGKRNL_SYSMM_FATAL_ERROR
//
#define VIDEO_DXGKRNL_SYSMM_FATAL_ERROR  ((ULONG)0x000001E4L)

//
// MessageId: DRIVER_VERIFIER_TRACKING_LIVE_DUMP
//
// MessageText:
//
//  DRIVER_VERIFIER_TRACKING_LIVE_DUMP
//
#define DRIVER_VERIFIER_TRACKING_LIVE_DUMP ((ULONG)0x000001E5L)

//
// MessageId: CRASHDUMP_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  CRASHDUMP_WATCHDOG_TIMEOUT
//
#define CRASHDUMP_WATCHDOG_TIMEOUT       ((ULONG)0x000001E6L)

//
// MessageId: REGISTRY_LIVE_DUMP
//
// MessageText:
//
//  REGISTRY_LIVE_DUMP
//
#define REGISTRY_LIVE_DUMP               ((ULONG)0x000001E7L)

//
// MessageId: INVALID_THREAD_AFFINITY_STATE
//
// MessageText:
//
//  INVALID_THREAD_AFFINITY_STATE
//
#define INVALID_THREAD_AFFINITY_STATE    ((ULONG)0x000001E8L)

//
// MessageId: ILLEGAL_ATS_INITIALIZATION
//
// MessageText:
//
//  ILLEGAL_ATS_INITIALIZATION
//
#define ILLEGAL_ATS_INITIALIZATION       ((ULONG)0x000001E9L)

//
// MessageId: SECURE_PCI_CONFIG_SPACE_ACCESS_VIOLATION
//
// MessageText:
//
//  SECURE_PCI_CONFIG_SPACE_ACCESS_VIOLATION
//
#define SECURE_PCI_CONFIG_SPACE_ACCESS_VIOLATION ((ULONG)0x000001EAL)

//
// MessageId: DAM_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  DAM_WATCHDOG_TIMEOUT
//
#define DAM_WATCHDOG_TIMEOUT             ((ULONG)0x000001EBL)

//
// MessageId: HANDLE_LIVE_DUMP
//
// MessageText:
//
//  HANDLE_LIVE_DUMP
//
#define HANDLE_LIVE_DUMP                 ((ULONG)0x000001ECL)

//
// MessageId: HANDLE_ERROR_ON_CRITICAL_THREAD
//
// MessageText:
//
//  HANDLE_ERROR_ON_CRITICAL_THREAD
//
#define HANDLE_ERROR_ON_CRITICAL_THREAD  ((ULONG)0x000001EDL)

//
// MessageId: MPSDRV_QUERY_USER
//
// MessageText:
//
//  MPSDRV_QUERY_USER
//
#define MPSDRV_QUERY_USER                ((ULONG)0x400001EEL)

//
// MessageId: VMBUS_LIVEDUMP
//
// MessageText:
//
//  VMBUS_LIVEDUMP
//
#define VMBUS_LIVEDUMP                   ((ULONG)0x400001EFL)

//
// MessageId: USB4_HARDWARE_VIOLATION
//
// MessageText:
//
//  USB4_HARDWARE_VIOLATION
//
#define USB4_HARDWARE_VIOLATION          ((ULONG)0x000001F0L)

//
// MessageId: KASAN_ENLIGHTENMENT_VIOLATION
//
// MessageText:
//
//  KASAN_ENLIGHTENMENT_VIOLATION
//
#define KASAN_ENLIGHTENMENT_VIOLATION    ((ULONG)0x000001F1L)

//
// MessageId: KASAN_ILLEGAL_ACCESS
//
// MessageText:
//
//  KASAN_ILLEGAL_ACCESS
//
#define KASAN_ILLEGAL_ACCESS             ((ULONG)0x000001F2L)

//
// MessageId: IORING
//
// MessageText:
//
//  IORING
//
#define IORING                           ((ULONG)0x000001F3L)

//
// MessageId: MDL_CACHE
//
// MessageText:
//
//  MDL_CACHE
//
#define MDL_CACHE                        ((ULONG)0x000001F4L)

//
// MessageId: APPLICATION_HANG_KERNEL_LIVEDUMP
//
// MessageText:
//
//  APPLICATION_HANG_KERNEL_LIVEDUMP
//
#define APPLICATION_HANG_KERNEL_LIVEDUMP ((ULONG)0x000001F5L)

//
// MessageId: MISALIGNED_POINTER_PARAMETER
//
// MessageText:
//
//  MISALIGNED_POINTER_PARAMETER
//
#define MISALIGNED_POINTER_PARAMETER     ((ULONG)0x000001F6L)

//
// MessageId: MSSECCORE_ASSERTION_FAILURE
//
// MessageText:
//
//  MSSECCORE_ASSERTION_FAILURE
//
#define MSSECCORE_ASSERTION_FAILURE      ((ULONG)0x000001F7L)

//
// MessageId: INVALID_MINIMAL_PROCESS_STATE
//
// MessageText:
//
//  INVALID_MINIMAL_PROCESS_STATE
//
#define INVALID_MINIMAL_PROCESS_STATE    ((ULONG)0x000001F8L)

//
// MessageId: PREVIOUS_MODE_MISMATCH
//
// MessageText:
//
//  PREVIOUS_MODE_MISMATCH
//
#define PREVIOUS_MODE_MISMATCH           ((ULONG)0x000001F9L)

//
// MessageId: SMB_SRV_REQUEST_VALIDATION_FAILURE
//
// MessageText:
//
//  SMB_SRV_REQUEST_VALIDATION_FAILURE
//
#define SMB_SRV_REQUEST_VALIDATION_FAILURE ((ULONG)0x000001FAL)

//
// MessageId: IOMMU_INTERRUPT_REMAPPING_FAULT
//
// MessageText:
//
//  IOMMU_INTERRUPT_REMAPPING_FAULT
//
#define IOMMU_INTERRUPT_REMAPPING_FAULT  ((ULONG)0x000001FBL)

//
// MessageId: WIN32K_CALLOUT_UNREGISTER_FAILED
//
// MessageText:
//
//  WIN32K_CALLOUT_UNREGISTER_FAILED
//
#define WIN32K_CALLOUT_UNREGISTER_FAILED ((ULONG)0x000001FCL)

//
// MessageId: HAL_SPE_INTERNAL_ERROR
//
// MessageText:
//
//  HAL_SPE_INTERNAL_ERROR
//
#define HAL_SPE_INTERNAL_ERROR           ((ULONG)0x000001FDL)

//
// MessageId: SMB_CLIENT_REQUEST_VALIDATION_FAILURE
//
// MessageText:
//
//  SMB_CLIENT_REQUEST_VALIDATION_FAILURE
//
#define SMB_CLIENT_REQUEST_VALIDATION_FAILURE ((ULONG)0x000001FEL)

//
// MessageId: CPU_SCHEDULER_INTERNAL_ERROR
//
// MessageText:
//
//  CPU_SCHEDULER_INTERNAL_ERROR
//
#define CPU_SCHEDULER_INTERNAL_ERROR     ((ULONG)0x00000200L)

//
// MessageId: PROCESS_TERMINATE_LIKELY_DEADLOCK
//
// MessageText:
//
//  PROCESS_TERMINATE_LIKELY_DEADLOCK
//
#define PROCESS_TERMINATE_LIKELY_DEADLOCK ((ULONG)0x00000201L)

//
// MessageId: UNEXPECTED_CODEPATH
//
// MessageText:
//
//  UNEXPECTED_CODEPATH
//
#define UNEXPECTED_CODEPATH              ((ULONG)0x00000202L)

//
// MessageId: INVALID_EXTENSION_STATE
//
// MessageText:
//
//  INVALID_EXTENSION_STATE
//
#define INVALID_EXTENSION_STATE          ((ULONG)0x00000203L)

//
// MessageId: XBOX_VMCTRL_CS_TIMEOUT
//
// MessageText:
//
//  XBOX_VMCTRL_CS_TIMEOUT
//
#define XBOX_VMCTRL_CS_TIMEOUT           ((ULONG)0x00000356L)

//
// MessageId: XBOX_CORRUPTED_IMAGE
//
// MessageText:
//
//  XBOX_CORRUPTED_IMAGE
//
#define XBOX_CORRUPTED_IMAGE             ((ULONG)0x00000357L)

//
// MessageId: XBOX_INVERTED_FUNCTION_TABLE_OVERFLOW
//
// MessageText:
//
//  XBOX_INVERTED_FUNCTION_TABLE_OVERFLOW
//
#define XBOX_INVERTED_FUNCTION_TABLE_OVERFLOW ((ULONG)0x00000358L)

//
// MessageId: XBOX_CORRUPTED_IMAGE_BASE
//
// MessageText:
//
//  XBOX_CORRUPTED_IMAGE_BASE
//
#define XBOX_CORRUPTED_IMAGE_BASE        ((ULONG)0x00000359L)

//
// MessageId: XBOX_XDS_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  XBOX_XDS_WATCHDOG_TIMEOUT
//
#define XBOX_XDS_WATCHDOG_TIMEOUT        ((ULONG)0x0000035AL)

//
// MessageId: XBOX_SHUTDOWN_WATCHDOG_TIMEOUT
//
// MessageText:
//
//  XBOX_SHUTDOWN_WATCHDOG_TIMEOUT
//
#define XBOX_SHUTDOWN_WATCHDOG_TIMEOUT   ((ULONG)0x0000035BL)

//
// MessageId: XBOX_CANNOT_MANAGE_PARTITION_MEMORY
//
// MessageText:
//
//  XBOX_CANNOT_MANAGE_PARTITION_MEMORY
//
#define XBOX_CANNOT_MANAGE_PARTITION_MEMORY ((ULONG)0x0000035DL)

//
// MessageId: XBOX_360_SYSTEM_CRASH
//
// MessageText:
//
//  XBOX_360_SYSTEM_CRASH
//
#define XBOX_360_SYSTEM_CRASH            ((ULONG)0x00000360L)

//
// MessageId: XBOX_360_SYSTEM_CRASH_RESERVED
//
// MessageText:
//
//  XBOX_360_SYSTEM_CRASH_RESERVED
//
#define XBOX_360_SYSTEM_CRASH_RESERVED   ((ULONG)0x00000420L)

//
// MessageId: XBOX_SECURITY_FAILUE
//
// MessageText:
//
//  XBOX_SECURITY_FAILUE
//
#define XBOX_SECURITY_FAILUE             ((ULONG)0x00000421L)

//
// MessageId: KERNEL_CFG_INIT_FAILURE
//
// MessageText:
//
//  KERNEL_CFG_INIT_FAILURE
//
#define KERNEL_CFG_INIT_FAILURE          ((ULONG)0x00000422L)

//
// MessageId: MANUALLY_INITIATED_POWER_BUTTON_HOLD_LIVE_DUMP
//
// MessageText:
//
//  MANUALLY_INITIATED_POWER_BUTTON_HOLD_LIVE_DUMP
//
#define MANUALLY_INITIATED_POWER_BUTTON_HOLD_LIVE_DUMP ((ULONG)0x000011C8L)

//
// MessageId: HYPERVISOR_ERROR
//
// MessageText:
//
//  HYPERVISOR_ERROR
//
#define HYPERVISOR_ERROR                 ((ULONG)0x00020001L)

//
// MessageId: XBOX_MANUALLY_INITIATED_CRASH
//
// MessageText:
//
//  XBOX_MANUALLY_INITIATED_CRASH
//
#define XBOX_MANUALLY_INITIATED_CRASH    ((ULONG)0x00030006L)

//
// MessageId: MANUALLY_INITIATED_BLACKSCREEN_HOTKEY_LIVE_DUMP
//
// MessageText:
//
//  MANUALLY_INITIATED_BLACKSCREEN_HOTKEY_LIVE_DUMP
//
#define MANUALLY_INITIATED_BLACKSCREEN_HOTKEY_LIVE_DUMP ((ULONG)0x000021C8L)

#define WINLOGON_FATAL_ERROR ((ULONG)0xC000021AL)
#define MANUALLY_INITIATED_CRASH1 ((ULONG)0xDEADDEAD)
#define BUGCHECK_CONTEXT_MODIFIER 0x80000000
#endif // _BUGCODES_
