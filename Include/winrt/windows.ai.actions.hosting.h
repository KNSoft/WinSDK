
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif /*COM_NO_WINDOWS_H*/
#ifndef __windows2Eai2Eactions2Ehosting_h__
#define __windows2Eai2Eactions2Ehosting_h__
#ifndef __windows2Eai2Eactions2Ehosting_p_h__
#define __windows2Eai2Eactions2Ehosting_p_h__


#pragma once

//
// Deprecated attribute support
//

#pragma push_macro("DEPRECATED")
#undef DEPRECATED

#if !defined(DISABLE_WINRT_DEPRECATION)
#if defined(__cplusplus)
#if __cplusplus >= 201402
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#elif defined(_MSC_VER)
#if _MSC_VER >= 1900
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#else
#define DEPRECATED(x) __declspec(deprecated(x))
#define DEPRECATEDENUMERATOR(x)
#endif // _MSC_VER >= 1900
#else // Not Standard C++ or MSVC, ignore the construct.
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  // C++ deprecation
#else // C - disable deprecation
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif
#else // Deprecation is disabled
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  /* DEPRECATED */

// Disable Deprecation for this header, MIDL verifies that cross-type access is acceptable
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#pragma warning(push)
#pragma warning(disable: 4996)
#endif

// Ensure that the setting of the /ns_prefix command line switch is consistent for all headers.
// If you get an error from the compiler indicating "warning C4005: 'CHECK_NS_PREFIX_STATE': macro redefinition", this
// indicates that you have included two different headers with different settings for the /ns_prefix MIDL command line switch
#if !defined(DISABLE_NS_PREFIX_CHECKS)
#define CHECK_NS_PREFIX_STATE "always"
#endif // !defined(DISABLE_NS_PREFIX_CHECKS)


#pragma push_macro("MIDL_CONST_ID")
#undef MIDL_CONST_ID
#define MIDL_CONST_ID const __declspec(selectany)


//  API Contract Inclusion Definitions
#if !defined(SPECIFIC_API_CONTRACT_DEFINITIONS)
#if !defined(WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION)
#define WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0x130000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.AI.Actions.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    interface IActionCatalog;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog ABI::Windows::AI::Actions::Hosting::IActionCatalog

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    interface IActionDefinition;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition ABI::Windows::AI::Actions::Hosting::IActionDefinition

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    interface IActionEntityRegistrationInfo;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo ABI::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    interface IActionOverload;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload ABI::Windows::AI::Actions::Hosting::IActionOverload

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    class ActionCatalog;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_USE
#define DEF___FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("6fc189b6-f223-5959-8676-db86049c04d9"))
ITypedEventHandler<ABI::Windows::AI::Actions::Hosting::ActionCatalog*, IInspectable*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::AI::Actions::Hosting::ActionCatalog*, ABI::Windows::AI::Actions::Hosting::IActionCatalog*>, IInspectable*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.AI.Actions.Hosting.ActionCatalog, Object>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::AI::Actions::Hosting::ActionCatalog*, IInspectable*> __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_t;
#define __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_USE */

#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                typedef enum ActionEntityKind : int ActionEntityKind;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class ActionInvocationContext;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionInvocationContext;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext ABI::Windows::AI::Actions::IActionInvocationContext

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IAsyncAction;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIAsyncAction ABI::Windows::Foundation::IAsyncAction

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IClosable;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIClosable ABI::Windows::Foundation::IClosable

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    class ActionDefinition;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    class ActionEntityRegistrationInfo;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    class ActionOverload;
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionCatalog
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionCatalog
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionCatalog[] = L"Windows.AI.Actions.Hosting.IActionCatalog";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    MIDL_INTERFACE("dbe7c537-66ea-5394-9085-4fc19d78375c")
                    IActionCatalog : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetAllActions(
                            UINT32* resultLength,
                            ABI::Windows::AI::Actions::Hosting::IActionDefinition*** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE add_Changed(
                            __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable* handler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_Changed(
                            EventRegistrationToken token
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IActionCatalog = __uuidof(IActionCatalog);
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionDefinition
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionDefinition
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionDefinition[] = L"Windows.AI.Actions.Hosting.IActionDefinition";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    MIDL_INTERFACE("fe766add-924d-5231-855e-dac9e82c7e6c")
                    IActionDefinition : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Id(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Description(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_IconFullPath(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_PackageFamilyName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetInputs(
                            UINT32* resultLength,
                            ABI::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo*** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetOutputs(
                            UINT32* resultLength,
                            ABI::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo*** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetOverloads(
                            UINT32* resultLength,
                            ABI::Windows::AI::Actions::Hosting::IActionOverload*** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IActionDefinition = __uuidof(IActionDefinition);
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionEntityRegistrationInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionEntityRegistrationInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo[] = L"Windows.AI.Actions.Hosting.IActionEntityRegistrationInfo";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    MIDL_INTERFACE("c3b92bdb-03c3-5a9e-b049-002fa0405699")
                    IActionEntityRegistrationInfo : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Name(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE put_Name(
                            HSTRING value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Kind(
                            ABI::Windows::AI::Actions::ActionEntityKind* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE put_Kind(
                            ABI::Windows::AI::Actions::ActionEntityKind value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IActionEntityRegistrationInfo = __uuidof(IActionEntityRegistrationInfo);
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionOverload
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionOverload
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionOverload[] = L"Windows.AI.Actions.Hosting.IActionOverload";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                namespace Hosting {
                    MIDL_INTERFACE("5d184610-d09d-5375-9849-505c359dca01")
                    IActionOverload : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_DescriptionTemplate(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetInputs(
                            UINT32* resultLength,
                            ABI::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo*** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE InvokeAsync(
                            ABI::Windows::AI::Actions::IActionInvocationContext* context,
                            ABI::Windows::Foundation::IAsyncAction** operation
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IActionOverload = __uuidof(IActionOverload);
                } /* Hosting */
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionCatalog
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionCatalog ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionCatalog_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionCatalog_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionCatalog[] = L"Windows.AI.Actions.Hosting.ActionCatalog";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionDefinition
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionDefinition ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionDefinition_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionDefinition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionDefinition[] = L"Windows.AI.Actions.Hosting.ActionDefinition";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionEntityRegistrationInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionEntityRegistrationInfo ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionEntityRegistrationInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionEntityRegistrationInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionEntityRegistrationInfo[] = L"Windows.AI.Actions.Hosting.ActionEntityRegistrationInfo";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionOverload
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionOverload ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionOverload_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionOverload_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionOverload[] = L"Windows.AI.Actions.Hosting.ActionOverload";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog;

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition;

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo;

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload;

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable;

typedef struct __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectableVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable* This,
        __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* sender,
        IInspectable* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectableVtbl;

interface __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectableVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable_INTERFACE_DEFINED__
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

typedef enum __x_ABI_CWindows_CAI_CActions_CActionEntityKind __x_ABI_CWindows_CAI_CActions_CActionEntityKind;

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIAsyncAction __x_ABI_CWindows_CFoundation_CIAsyncAction;

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIClosable __x_ABI_CWindows_CFoundation_CIClosable;

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionCatalog
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionCatalog
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionCatalog[] = L"Windows.AI.Actions.Hosting.IActionCatalog";
typedef struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalogVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAllActions)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition*** result);
    HRESULT (STDMETHODCALLTYPE* add_Changed)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This,
        __FITypedEventHandler_2_Windows__CAI__CActions__CHosting__CActionCatalog_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_Changed)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog* This,
        EventRegistrationToken token);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalogVtbl;

interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalogVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_GetAllActions(This, resultLength, result) \
    ((This)->lpVtbl->GetAllActions(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_add_Changed(This, handler, token) \
    ((This)->lpVtbl->add_Changed(This, handler, token))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_remove_Changed(This, token) \
    ((This)->lpVtbl->remove_Changed(This, token))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionDefinition
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionDefinition
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionDefinition[] = L"Windows.AI.Actions.Hosting.IActionDefinition";
typedef struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinitionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Id)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_IconFullPath)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_PackageFamilyName)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* GetInputs)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo*** result);
    HRESULT (STDMETHODCALLTYPE* GetOutputs)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo*** result);
    HRESULT (STDMETHODCALLTYPE* GetOverloads)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload*** result);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinitionVtbl;

interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinitionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_get_Id(This, value) \
    ((This)->lpVtbl->get_Id(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_get_IconFullPath(This, value) \
    ((This)->lpVtbl->get_IconFullPath(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_get_PackageFamilyName(This, value) \
    ((This)->lpVtbl->get_PackageFamilyName(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_GetInputs(This, resultLength, result) \
    ((This)->lpVtbl->GetInputs(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_GetOutputs(This, resultLength, result) \
    ((This)->lpVtbl->GetOutputs(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_GetOverloads(This, resultLength, result) \
    ((This)->lpVtbl->GetOverloads(This, resultLength, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionDefinition_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionEntityRegistrationInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionEntityRegistrationInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo[] = L"Windows.AI.Actions.Hosting.IActionEntityRegistrationInfo";
typedef struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Name)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Name)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_Kind)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        enum __x_ABI_CWindows_CAI_CActions_CActionEntityKind* value);
    HRESULT (STDMETHODCALLTYPE* put_Kind)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo* This,
        enum __x_ABI_CWindows_CAI_CActions_CActionEntityKind value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfoVtbl;

interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_get_Name(This, value) \
    ((This)->lpVtbl->get_Name(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_put_Name(This, value) \
    ((This)->lpVtbl->put_Name(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_get_Kind(This, value) \
    ((This)->lpVtbl->get_Kind(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_put_Kind(This, value) \
    ((This)->lpVtbl->put_Kind(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.Hosting.IActionOverload
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.Hosting.ActionOverload
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_Hosting_IActionOverload[] = L"Windows.AI.Actions.Hosting.IActionOverload";
typedef struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverloadVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_DescriptionTemplate)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* GetInputs)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CActions_CHosting_CIActionEntityRegistrationInfo*** result);
    HRESULT (STDMETHODCALLTYPE* InvokeAsync)(__x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload* This,
        __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* context,
        __x_ABI_CWindows_CFoundation_CIAsyncAction** operation);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverloadVtbl;

interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverloadVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_get_DescriptionTemplate(This, value) \
    ((This)->lpVtbl->get_DescriptionTemplate(This, value))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_GetInputs(This, resultLength, result) \
    ((This)->lpVtbl->GetInputs(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_InvokeAsync(This, context, operation) \
    ((This)->lpVtbl->InvokeAsync(This, context, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CHosting_CIActionOverload_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionCatalog
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionCatalog ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionCatalog_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionCatalog_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionCatalog[] = L"Windows.AI.Actions.Hosting.ActionCatalog";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionDefinition
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionDefinition ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionDefinition_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionDefinition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionDefinition[] = L"Windows.AI.Actions.Hosting.ActionDefinition";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionEntityRegistrationInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionEntityRegistrationInfo ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionEntityRegistrationInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionEntityRegistrationInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionEntityRegistrationInfo[] = L"Windows.AI.Actions.Hosting.ActionEntityRegistrationInfo";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.Hosting.ActionOverload
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.Hosting.IActionOverload ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionOverload_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_Hosting_ActionOverload_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_Hosting_ActionOverload[] = L"Windows.AI.Actions.Hosting.ActionOverload";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Eai2Eactions2Ehosting_p_h__

#endif // __windows2Eai2Eactions2Ehosting_h__
