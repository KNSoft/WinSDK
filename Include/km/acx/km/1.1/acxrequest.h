/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    AcxRequest.h

Abstract:

    This is the interfaces for the Audio Class eXtension request object

Environment:

    Kernel-mode.

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _ACXREQUEST_H_
#define _ACXREQUEST_H_

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



#if (NTDDI_VERSION >= NTDDI_WIN2K)




//
// ACX request structures.
//
typedef enum _ACX_REQUEST_TYPE {
    AcxRequestTypeUnknown           = 0,
    AcxRequestTypeAny               = 1,
    AcxRequestTypeCreate            = 2,
    AcxRequestTypeProperty          = 3,
    AcxRequestTypeMethod            = 4,
    AcxRequestTypeEvent             = 5,
    AcxRequestTypeResetState        = 6,
    AcxRequestTypeMax
} ACX_REQUEST_TYPE, *PACX_REQUEST_TYPE;

typedef enum _ACX_PROPERTY_VERB {
    AcxPropertyVerbNone             = 0,
    AcxPropertyVerbGet              = 1,
    AcxPropertyVerbSet              = 2,
    AcxPropertyVerbBasicSupport     = 3,
    AcxPropertyVerbSetSupport       = 4,
    AcxPropertyVerbMax
} ACX_PROPERTY_VERB, *PACX_PROPERTY_VERB;

typedef enum _ACX_METHOD_VERB {
    AcxMethodVerbNone               = 0,
    AcxMethodVerbSend               = 1,
    AcxMethodVerbBasicSupport       = 2,
    AcxMethodVerbSetSupport         = 3,
    AcxMethodVerbMax
} ACX_METHOD_VERB, *PACX_METHOD_VERB;

typedef enum _ACX_EVENT_VERB {
    AcxEventVerbNone                = 0,
    AcxEventVerbEnable              = 1,
    AcxEventVerbDisable             = 2,
    AcxEventVerbBasicSupport        = 3,
    AcxEventVerbSetSupport          = 4,
    AcxEventVerbMax
} ACX_EVENT_VERB, *PACX_EVENT_VERB;

typedef enum _ACX_ITEM_TYPE {
    AcxItemTypeDefault              = 0, // default type for the specified handle.
    AcxItemTypeCircuit              = 0,
    AcxItemTypeStream               = 0,
    AcxItemTypeFactoryCircuit       = 0,
    AcxItemTypePin                  = 1,
    AcxItemTypeElement              = 2,
    AcxItemTypeMax
} ACX_ITEM_TYPE, *PACX_ITEM_TYPE;

typedef struct _ACX_REQUEST_PARAMETERS {
    USHORT  Size;

    UCHAR   MajorFunction;
    UCHAR   MinorFunction;

    ACX_REQUEST_TYPE Type;

    //
    // The following user parameters are based on the service that is being
    // invoked. Drivers can determine which set to use based on the above type.
    //
    union {
        //
        // System service parameters for: Property
        //
        struct {
            GUID                Set;
            ULONG               Id;
            ACX_PROPERTY_VERB   Verb;
            ACX_ITEM_TYPE       ItemType;
            ULONG               ItemId;
            PVOID               Control;
            ULONG               ControlCb;
            PVOID               Value;
            ULONG               ValueCb;
        } Property;

        //
        // System service parameters for: Method
        //
        struct {
            GUID                Set;
            ULONG               Id;
            ACX_METHOD_VERB     Verb;
            ACX_ITEM_TYPE       ItemType;
            ULONG               ItemId;
            PVOID               Args;
            ULONG               ArgsCb;
            PVOID               Result;
            ULONG               ResultCb;
        } Method;

        //
        // System service parameters for: EnableEvent/DisableEvent
        //
        struct {
            GUID                Set;
            ULONG               Id;
            ACX_EVENT_VERB      Verb;
            ACX_ITEM_TYPE       ItemType;
            ULONG               ItemId;
            PVOID               Data;
            ULONG               DataCb;
            ACXEVENTDATA        EventData;
        } Event;

        //
        // System service parameters for: Create
        //
        struct {
            PVOID               Control;
            ULONG               ControlCb;
        } Create;
    } Parameters;

} ACX_REQUEST_PARAMETERS, *PACX_REQUEST_PARAMETERS;

VOID
FORCEINLINE
ACX_REQUEST_PARAMETERS_INIT(
    _Out_ PACX_REQUEST_PARAMETERS Parameters
    )
{
    RtlZeroMemory(Parameters, sizeof(ACX_REQUEST_PARAMETERS));
    Parameters->Size = (USHORT)ACX_STRUCTURE_SIZE(ACX_REQUEST_PARAMETERS);
}

VOID
FORCEINLINE
ACX_REQUEST_PARAMETERS_INIT_PROPERTY(
    _Out_ PACX_REQUEST_PARAMETERS Params,
    _In_  const GUID              Set,
    _In_  ULONG                   Id,
    _In_  ACX_PROPERTY_VERB       Verb,
    _In_  ACX_ITEM_TYPE           ItemType,
    _In_  ULONG                   ItemId,
    _In_  PVOID                   Control,
    _In_  ULONG                   ControlCb,
    _In_  PVOID                   Value,
    _In_  ULONG                   ValueCb
    )
{
    RtlZeroMemory(Params, sizeof(ACX_REQUEST_PARAMETERS));
    Params->Size = (USHORT)ACX_STRUCTURE_SIZE(ACX_REQUEST_PARAMETERS);

    Params->MajorFunction = IRP_MJ_DEVICE_CONTROL;
    Params->MinorFunction = 0;

    Params->Type = AcxRequestTypeProperty;

    Params->Parameters.Property.Set         = Set;
    Params->Parameters.Property.Id          = Id;
    Params->Parameters.Property.Verb        = Verb;
    Params->Parameters.Property.ItemType    = ItemType;
    Params->Parameters.Property.ItemId      = ItemId;
    Params->Parameters.Property.Control     = Control;
    Params->Parameters.Property.ControlCb   = ControlCb;
    Params->Parameters.Property.Value       = Value;
    Params->Parameters.Property.ValueCb     = ValueCb;
}

VOID
FORCEINLINE
ACX_REQUEST_PARAMETERS_INIT_METHOD(
    _Out_ PACX_REQUEST_PARAMETERS Params,
    _In_  const GUID              Set,
    _In_  ULONG                   Id,
    _In_  ACX_METHOD_VERB         Verb,
    _In_  ACX_ITEM_TYPE           ItemType,
    _In_  ULONG                   ItemId,
    _In_  PVOID                   Args,
    _In_  ULONG                   ArgsCb,
    _In_  PVOID                   Result,
    _In_  ULONG                   ResultCb
    )
{
    RtlZeroMemory(Params, sizeof(ACX_REQUEST_PARAMETERS));
    Params->Size = (USHORT)ACX_STRUCTURE_SIZE(ACX_REQUEST_PARAMETERS);

    Params->MajorFunction = IRP_MJ_DEVICE_CONTROL;
    Params->MinorFunction = 0;

    Params->Type = AcxRequestTypeMethod;

    Params->Parameters.Method.Set         = Set;
    Params->Parameters.Method.Id          = Id;
    Params->Parameters.Method.Verb        = Verb;
    Params->Parameters.Method.ItemType    = ItemType;
    Params->Parameters.Method.ItemId      = ItemId;
    Params->Parameters.Method.Args        = Args;
    Params->Parameters.Method.ArgsCb      = ArgsCb;
    Params->Parameters.Method.Result      = Result;
    Params->Parameters.Method.ResultCb    = ResultCb;
}

VOID
FORCEINLINE
ACX_REQUEST_PARAMETERS_INIT_EVENT(
    _Out_ PACX_REQUEST_PARAMETERS Params,
    _In_  const GUID              Set,
    _In_  ULONG                   Id,
    _In_  ACX_EVENT_VERB          Verb,
    _In_  ACX_ITEM_TYPE           ItemType,
    _In_  ULONG                   ItemId,
    _In_  PVOID                   Data,
    _In_  ULONG                   DataCb,
    _In_opt_ ACXEVENTDATA         EventData  // Internal, set to NULL.
    )
{
    RtlZeroMemory(Params, sizeof(ACX_REQUEST_PARAMETERS));
    Params->Size = (USHORT)ACX_STRUCTURE_SIZE(ACX_REQUEST_PARAMETERS);

    Params->MajorFunction = IRP_MJ_DEVICE_CONTROL;
    Params->MinorFunction = 0;

    Params->Type = AcxRequestTypeEvent;

    Params->Parameters.Event.Set      	= Set;
    Params->Parameters.Event.Id         = Id;
    Params->Parameters.Event.Verb       = Verb;
    Params->Parameters.Event.ItemType   = ItemType;
    Params->Parameters.Event.ItemId     = ItemId;
    Params->Parameters.Event.Data       = Data;
    Params->Parameters.Event.DataCb     = DataCb;
    Params->Parameters.Event.EventData  = EventData;
}

typedef
_Function_class_(EVT_ACX_OBJECT_PREPROCESS_REQUEST)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
NTAPI
EVT_ACX_OBJECT_PREPROCESS_REQUEST(
    _In_
    ACXOBJECT Object,
    _In_
    ACXCONTEXT DriverContext,
    _In_
    WDFREQUEST Request
    );

typedef EVT_ACX_OBJECT_PREPROCESS_REQUEST *PFN_ACX_OBJECT_PREPROCESS_REQUEST;

typedef
_Function_class_(EVT_ACX_OBJECT_PROCESS_REQUEST)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
NTAPI
EVT_ACX_OBJECT_PROCESS_REQUEST(
    _In_
    ACXOBJECT Object,
    _In_
    WDFREQUEST Request
    );

typedef EVT_ACX_OBJECT_PROCESS_REQUEST *PFN_ACX_OBJECT_PROCESS_REQUEST;

typedef
_Function_class_(EVT_ACX_OBJECT_PROCESS_EVENT_REQUEST)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
NTAPI
EVT_ACX_OBJECT_PROCESS_EVENT_REQUEST(
    _In_
    ACXOBJECT Object,
    _In_
    ACXEVENT Event,
    _In_
    ACX_EVENT_VERB Verb,
    _In_opt_
    ACXEVENTDATA EventData,
    _In_opt_
    WDFREQUEST Request
    );

typedef EVT_ACX_OBJECT_PROCESS_EVENT_REQUEST *PFN_ACX_OBJECT_PROCESS_EVENT_REQUEST;

#define AcxCircuitId                ((ULONG)(-1))
#define AcxStreamId                 ((ULONG)(-1))

#define AcxItemIdAny                ((ULONG)(-1))
#define AcxItemIdUnknown            ((ULONG)(-1))
#define AcxItemIdNone               ((ULONG)(-1))

#define AcxItemFlagsAny             ((ULONG)(-1))

typedef struct _ACX_PROPERTY_ITEM {
    const GUID *                            Set;
    ULONG                                   Id;
    ULONG                                   Flags;
    PFN_ACX_OBJECT_PROCESS_REQUEST          EvtAcxObjectProcessRequest;
    PVOID                                   Reserved;
    ULONG                                   ControlCb;
    ULONG                                   ValueCb;
    ULONG                                   ValueType;
} ACX_PROPERTY_ITEM, *PACX_PROPERTY_ITEM;

#define ACX_PROPERTY_ITEM_FLAG_NONE             0x00000000
#define ACX_PROPERTY_ITEM_FLAG_GET              0x00000001 // KSPROPERTY_TYPE_GET
#define ACX_PROPERTY_ITEM_FLAG_SET              0x00000002 // KSPROPERTY_TYPE_SET
#define ACX_PROPERTY_ITEM_FLAG_BASICSUPPORT     0x00000200 // KSPROPERTY_TYPE_BASICSUPPORT

typedef struct _ACX_METHOD_ITEM {
    const GUID *                            Set;
    ULONG                                   Id;
    ULONG                                   Flags;
    PFN_ACX_OBJECT_PROCESS_REQUEST          EvtAcxObjectProcessRequest;
    PVOID                                   Reserved;
    ULONG                                   ArgsCb;
    ULONG                                   ResultCb;
    ULONG                                   ResultType;
} ACX_METHOD_ITEM, *PACX_METHOD_ITEM;

#define ACX_METHOD_ITEM_FLAG_NONE               0x00000000
#define ACX_METHOD_ITEM_FLAG_SEND               0x00000001 // KSMETHOD_TYPE_SEND
#define ACX_METHOD_ITEM_FLAG_BASICSUPPORT       0x00000200 // KSMETHOD_TYPE_BASICSUPPORT

typedef struct _ACX_EVENT_ITEM {
    const GUID *                            Set;
    ULONG                                   Id;
    ULONG                                   Flags;
    PFN_ACX_OBJECT_PROCESS_EVENT_REQUEST    EvtAcxObjectProcessRequest;
    PVOID                                   Reserved;
} ACX_EVENT_ITEM, *PACX_EVENT_ITEM;

#define ACX_EVENT_ITEM_FLAG_NONE                0x00000000
#define ACX_EVENT_ITEM_FLAG_ENABLE              0x00000001 // KSEVENT_TYPE_ENABLE
#define ACX_EVENT_ITEM_FLAG_BASICSUPPORT        0x00000200 // KSEVENT_TYPE_BASICSUPPORT


//
// ACX Function: AcxRequestGetParameters
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_ACXREQUESTGETPARAMETERS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFREQUEST Request,
    _Out_
    PACX_REQUEST_PARAMETERS Parameters
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
AcxRequestGetParameters(
    _In_
    WDFREQUEST Request,
    _Out_
    PACX_REQUEST_PARAMETERS Parameters
    )
{
    ((PFN_ACXREQUESTGETPARAMETERS) AcxFunctions[AcxRequestGetParametersTableIndex])(AcxDriverGlobals, Request, Parameters);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


WDF_EXTERN_C_END

#endif // _ACXREQUEST_H_

