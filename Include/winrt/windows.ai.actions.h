
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
#ifndef __windows2Eai2Eactions_h__
#define __windows2Eai2Eactions_h__
#ifndef __windows2Eai2Eactions_p_h__
#define __windows2Eai2Eactions_p_h__


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
#include "Windows.AI.Actions.Hosting.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntity_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionEntity ABI::Windows::AI::Actions::IActionEntity

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionEntityDisplayInfo;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo ABI::Windows::AI::Actions::IActionEntityDisplayInfo

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionEntityFactory;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory ABI::Windows::AI::Actions::IActionEntityFactory

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionEntityFactory2;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2 ABI::Windows::AI::Actions::IActionEntityFactory2

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionEntityFactoryFactory;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory ABI::Windows::AI::Actions::IActionEntityFactoryFactory

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_FWD_DEFINED__

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

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionRuntime;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime ABI::Windows::AI::Actions::IActionRuntime

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IActionRuntimeFactory;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory ABI::Windows::AI::Actions::IActionRuntimeFactory

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IDocumentActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity ABI::Windows::AI::Actions::IDocumentActionEntity

#endif // ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IFileActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity ABI::Windows::AI::Actions::IFileActionEntity

#endif // ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface INamedActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity ABI::Windows::AI::Actions::INamedActionEntity

#endif // ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface IPhotoActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity ABI::Windows::AI::Actions::IPhotoActionEntity

#endif // ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                interface ITextActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity ABI::Windows::AI::Actions::ITextActionEntity

#endif // ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_FWD_DEFINED__

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
                typedef enum ActionEntityKind : int ActionEntityKind;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                typedef enum ActionInvocationResult : int ActionInvocationResult;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class ActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class ActionEntityDisplayInfo;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class ActionEntityFactory;
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

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class DocumentActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class FileActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class NamedActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class PhotoActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                class TextActionEntity;
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.AI.Actions.ActionEntityKind
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                enum ActionEntityKind : int
                {
                    ActionEntityKind_None = 0,
                    ActionEntityKind_Document = 1,
                    ActionEntityKind_File = 2,
                    ActionEntityKind_Photo = 3,
                    ActionEntityKind_Text = 4,
                };
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Struct Windows.AI.Actions.ActionInvocationResult
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                enum ActionInvocationResult : int
                {
                    ActionInvocationResult_Success = 0,
                    ActionInvocationResult_UserCanceled = 1,
                    ActionInvocationResult_Unsupported = 2,
                    ActionInvocationResult_Unavailable = 3,
                };
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntity[] = L"Windows.AI.Actions.IActionEntity";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("445e700f-2122-5668-9a16-4cab2982c5f4")
                IActionEntity : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Kind(
                        ABI::Windows::AI::Actions::ActionEntityKind* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DisplayInfo(
                        ABI::Windows::AI::Actions::IActionEntityDisplayInfo** value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IActionEntity = __uuidof(IActionEntity);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityDisplayInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntityDisplayInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityDisplayInfo[] = L"Windows.AI.Actions.IActionEntityDisplayInfo";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("057a9ede-03e1-55c6-acba-c7056216735a")
                IActionEntityDisplayInfo : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Title(
                        HSTRING* value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IActionEntityDisplayInfo = __uuidof(IActionEntityDisplayInfo);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityFactory[] = L"Windows.AI.Actions.IActionEntityFactory";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("9cb752a0-5bf8-5be2-916e-b00eff80088d")
                IActionEntityFactory : public IInspectable
                {
                public:
                };

                MIDL_CONST_ID IID& IID_IActionEntityFactory = __uuidof(IActionEntityFactory);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityFactory;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityFactory2
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntityFactory
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityFactory2[] = L"Windows.AI.Actions.IActionEntityFactory2";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("ea2fb6a5-ec6d-5180-9d30-bc663b84e7b8")
                IActionEntityFactory2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateFileEntity(
                        HSTRING path,
                        ABI::Windows::AI::Actions::IFileActionEntity** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateDocumentEntity(
                        HSTRING path,
                        ABI::Windows::AI::Actions::IDocumentActionEntity** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreatePhotoEntity(
                        HSTRING path,
                        ABI::Windows::AI::Actions::IPhotoActionEntity** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateTextEntity(
                        HSTRING text,
                        ABI::Windows::AI::Actions::ITextActionEntity** result
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IActionEntityFactory2 = __uuidof(IActionEntityFactory2);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityFactoryFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntityFactory
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityFactoryFactory[] = L"Windows.AI.Actions.IActionEntityFactoryFactory";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("c9147d8f-88a0-5ec0-a564-47e2a1081412")
                IActionEntityFactoryFactory : public IInspectable
                {
                public:
                };

                MIDL_CONST_ID IID& IID_IActionEntityFactoryFactory = __uuidof(IActionEntityFactoryFactory);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionInvocationContext
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionInvocationContext
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionInvocationContext[] = L"Windows.AI.Actions.IActionInvocationContext";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("8d8de82e-bf94-51a4-a0e9-dc5014948184")
                IActionInvocationContext : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ActionName(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_EntityFactory(
                        ABI::Windows::AI::Actions::IActionEntityFactory2** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_InvokerAumid(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetInputEntity(
                        HSTRING inputName,
                        ABI::Windows::AI::Actions::IActionEntity* inputValue
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetInputEntities(
                        UINT32* resultLength,
                        ABI::Windows::AI::Actions::INamedActionEntity*** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetOutputEntity(
                        HSTRING outputName,
                        ABI::Windows::AI::Actions::IActionEntity* outputValue
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetOutputEntities(
                        UINT32* resultLength,
                        ABI::Windows::AI::Actions::INamedActionEntity*** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Result(
                        ABI::Windows::AI::Actions::ActionInvocationResult* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Result(
                        ABI::Windows::AI::Actions::ActionInvocationResult value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExtendedError(
                        HRESULT* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ExtendedError(
                        HRESULT value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IActionInvocationContext = __uuidof(IActionInvocationContext);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionInvocationContext;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionRuntime
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionRuntime
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntime_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionRuntime[] = L"Windows.AI.Actions.IActionRuntime";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("206efa2c-c909-508a-b4b0-9482be96db9c")
                IActionRuntime : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ActionCatalog(
                        ABI::Windows::AI::Actions::Hosting::IActionCatalog** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_EntityFactory(
                        ABI::Windows::AI::Actions::IActionEntityFactory2** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateInvocationContext(
                        HSTRING actionName,
                        ABI::Windows::AI::Actions::IActionInvocationContext** result
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IActionRuntime = __uuidof(IActionRuntime);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionRuntime;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntime_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionRuntimeFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionRuntime
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionRuntimeFactory[] = L"Windows.AI.Actions.IActionRuntimeFactory";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("d3f366e9-8dc9-50a0-8040-e5c14fa609d6")
                IActionRuntimeFactory : public IInspectable
                {
                public:
                };

                MIDL_CONST_ID IID& IID_IActionRuntimeFactory = __uuidof(IActionRuntimeFactory);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IDocumentActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.DocumentActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IDocumentActionEntity[] = L"Windows.AI.Actions.IDocumentActionEntity";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("56715297-960b-59ff-af4b-ece1098b2e36")
                IDocumentActionEntity : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_FullPath(
                        HSTRING* value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IDocumentActionEntity = __uuidof(IDocumentActionEntity);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IFileActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.FileActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IFileActionEntity[] = L"Windows.AI.Actions.IFileActionEntity";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("f20ab43f-4c80-5904-bd42-3e6248babfcf")
                IFileActionEntity : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_FullPath(
                        HSTRING* value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IFileActionEntity = __uuidof(IFileActionEntity);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIFileActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.INamedActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.NamedActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_INamedActionEntity[] = L"Windows.AI.Actions.INamedActionEntity";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("1aaebeef-435b-5a0d-8182-05fe4dd47712")
                INamedActionEntity : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Name(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Name(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Entity(
                        ABI::Windows::AI::Actions::IActionEntity** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Entity(
                        ABI::Windows::AI::Actions::IActionEntity* value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_INamedActionEntity = __uuidof(INamedActionEntity);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CINamedActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IPhotoActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.PhotoActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IPhotoActionEntity[] = L"Windows.AI.Actions.IPhotoActionEntity";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("425123b3-20ef-51a6-b35f-8414384765c5")
                IPhotoActionEntity : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_FullPath(
                        HSTRING* value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_IPhotoActionEntity = __uuidof(IPhotoActionEntity);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.ITextActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.TextActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CITextActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_ITextActionEntity[] = L"Windows.AI.Actions.ITextActionEntity";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Actions {
                MIDL_INTERFACE("3c4ec25f-5adb-5f73-b8f3-080fbeadd612")
                ITextActionEntity : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Text(
                        HSTRING* value
                        ) = 0;
                };

                MIDL_CONST_ID IID& IID_ITextActionEntity = __uuidof(ITextActionEntity);
            } /* Actions */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CITextActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CITextActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionEntity ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionEntity[] = L"Windows.AI.Actions.ActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionEntityDisplayInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionEntityDisplayInfo ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionEntityDisplayInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionEntityDisplayInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionEntityDisplayInfo[] = L"Windows.AI.Actions.ActionEntityDisplayInfo";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionEntityFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionEntityFactory2 ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionEntityFactory_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionEntityFactory_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionEntityFactory[] = L"Windows.AI.Actions.ActionEntityFactory";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionInvocationContext
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionInvocationContext ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionInvocationContext_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionInvocationContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionInvocationContext[] = L"Windows.AI.Actions.ActionInvocationContext";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionRuntime
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionRuntime ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionRuntime_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionRuntime_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionRuntime[] = L"Windows.AI.Actions.ActionRuntime";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.DocumentActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IDocumentActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_DocumentActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_DocumentActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_DocumentActionEntity[] = L"Windows.AI.Actions.DocumentActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.FileActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IFileActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_FileActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_FileActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_FileActionEntity[] = L"Windows.AI.Actions.FileActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.NamedActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.INamedActionEntity ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_NamedActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_NamedActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_NamedActionEntity[] = L"Windows.AI.Actions.NamedActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.PhotoActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IPhotoActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_PhotoActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_PhotoActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_PhotoActionEntity[] = L"Windows.AI.Actions.PhotoActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.TextActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.ITextActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_TextActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_TextActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_TextActionEntity[] = L"Windows.AI.Actions.TextActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntity_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionEntity __x_ABI_CWindows_CAI_CActions_CIActionEntity;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2 __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionRuntime __x_ABI_CWindows_CAI_CActions_CIActionRuntime;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory;

#endif // ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity;

#endif // ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIFileActionEntity __x_ABI_CWindows_CAI_CActions_CIFileActionEntity;

#endif // ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CINamedActionEntity __x_ABI_CWindows_CAI_CActions_CINamedActionEntity;

#endif // ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity;

#endif // ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CITextActionEntity __x_ABI_CWindows_CAI_CActions_CITextActionEntity;

#endif // ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#ifndef ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog;

#endif // ____x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIClosable __x_ABI_CWindows_CFoundation_CIClosable;

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__

typedef enum __x_ABI_CWindows_CAI_CActions_CActionEntityKind __x_ABI_CWindows_CAI_CActions_CActionEntityKind;

typedef enum __x_ABI_CWindows_CAI_CActions_CActionInvocationResult __x_ABI_CWindows_CAI_CActions_CActionInvocationResult;

/*
 *
 * Struct Windows.AI.Actions.ActionEntityKind
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CAI_CActions_CActionEntityKind
{
    ActionEntityKind_None = 0,
    ActionEntityKind_Document = 1,
    ActionEntityKind_File = 2,
    ActionEntityKind_Photo = 3,
    ActionEntityKind_Text = 4,
};
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Struct Windows.AI.Actions.ActionInvocationResult
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CAI_CActions_CActionInvocationResult
{
    ActionInvocationResult_Success = 0,
    ActionInvocationResult_UserCanceled = 1,
    ActionInvocationResult_Unsupported = 2,
    ActionInvocationResult_Unavailable = 3,
};
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntity[] = L"Windows.AI.Actions.IActionEntity";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionEntityVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Kind)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This,
        enum __x_ABI_CWindows_CAI_CActions_CActionEntityKind* value);
    HRESULT (STDMETHODCALLTYPE* get_DisplayInfo)(__x_ABI_CWindows_CAI_CActions_CIActionEntity* This,
        __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo** value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionEntityVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionEntity
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionEntityVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_get_Kind(This, value) \
    ((This)->lpVtbl->get_Kind(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntity_get_DisplayInfo(This, value) \
    ((This)->lpVtbl->get_DisplayInfo(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityDisplayInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntityDisplayInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityDisplayInfo[] = L"Windows.AI.Actions.IActionEntityDisplayInfo";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Title)(__x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfoVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_get_Title(This, value) \
    ((This)->lpVtbl->get_Title(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityDisplayInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityFactory[] = L"Windows.AI.Actions.IActionEntityFactory";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory* This,
        TrustLevel* trustLevel);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityFactory;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityFactory2
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntityFactory
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityFactory2[] = L"Windows.AI.Actions.IActionEntityFactory2";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateFileEntity)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        HSTRING path,
        __x_ABI_CWindows_CAI_CActions_CIFileActionEntity** result);
    HRESULT (STDMETHODCALLTYPE* CreateDocumentEntity)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        HSTRING path,
        __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity** result);
    HRESULT (STDMETHODCALLTYPE* CreatePhotoEntity)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        HSTRING path,
        __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity** result);
    HRESULT (STDMETHODCALLTYPE* CreateTextEntity)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2* This,
        HSTRING text,
        __x_ABI_CWindows_CAI_CActions_CITextActionEntity** result);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2Vtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_CreateFileEntity(This, path, result) \
    ((This)->lpVtbl->CreateFileEntity(This, path, result))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_CreateDocumentEntity(This, path, result) \
    ((This)->lpVtbl->CreateDocumentEntity(This, path, result))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_CreatePhotoEntity(This, path, result) \
    ((This)->lpVtbl->CreatePhotoEntity(This, path, result))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_CreateTextEntity(This, text, result) \
    ((This)->lpVtbl->CreateTextEntity(This, text, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionEntityFactoryFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionEntityFactory
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionEntityFactoryFactory[] = L"Windows.AI.Actions.IActionEntityFactoryFactory";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory* This,
        TrustLevel* trustLevel);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactoryVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionEntityFactoryFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionInvocationContext
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionInvocationContext
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionInvocationContext[] = L"Windows.AI.Actions.IActionInvocationContext";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionInvocationContextVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ActionName)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_EntityFactory)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2** value);
    HRESULT (STDMETHODCALLTYPE* get_InvokerAumid)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* SetInputEntity)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        HSTRING inputName,
        __x_ABI_CWindows_CAI_CActions_CIActionEntity* inputValue);
    HRESULT (STDMETHODCALLTYPE* GetInputEntities)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CActions_CINamedActionEntity*** result);
    HRESULT (STDMETHODCALLTYPE* SetOutputEntity)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        HSTRING outputName,
        __x_ABI_CWindows_CAI_CActions_CIActionEntity* outputValue);
    HRESULT (STDMETHODCALLTYPE* GetOutputEntities)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CActions_CINamedActionEntity*** result);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        enum __x_ABI_CWindows_CAI_CActions_CActionInvocationResult* value);
    HRESULT (STDMETHODCALLTYPE* put_Result)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        enum __x_ABI_CWindows_CAI_CActions_CActionInvocationResult value);
    HRESULT (STDMETHODCALLTYPE* get_ExtendedError)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        HRESULT* value);
    HRESULT (STDMETHODCALLTYPE* put_ExtendedError)(__x_ABI_CWindows_CAI_CActions_CIActionInvocationContext* This,
        HRESULT value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionInvocationContextVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionInvocationContextVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_get_ActionName(This, value) \
    ((This)->lpVtbl->get_ActionName(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_get_EntityFactory(This, value) \
    ((This)->lpVtbl->get_EntityFactory(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_get_InvokerAumid(This, value) \
    ((This)->lpVtbl->get_InvokerAumid(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_SetInputEntity(This, inputName, inputValue) \
    ((This)->lpVtbl->SetInputEntity(This, inputName, inputValue))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_GetInputEntities(This, resultLength, result) \
    ((This)->lpVtbl->GetInputEntities(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_SetOutputEntity(This, outputName, outputValue) \
    ((This)->lpVtbl->SetOutputEntity(This, outputName, outputValue))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_GetOutputEntities(This, resultLength, result) \
    ((This)->lpVtbl->GetOutputEntities(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_put_Result(This, value) \
    ((This)->lpVtbl->put_Result(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_get_ExtendedError(This, value) \
    ((This)->lpVtbl->get_ExtendedError(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_put_ExtendedError(This, value) \
    ((This)->lpVtbl->put_ExtendedError(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionInvocationContext;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionInvocationContext_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionRuntime
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionRuntime
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntime_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntime_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionRuntime[] = L"Windows.AI.Actions.IActionRuntime";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionRuntimeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ActionCatalog)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This,
        __x_ABI_CWindows_CAI_CActions_CHosting_CIActionCatalog** value);
    HRESULT (STDMETHODCALLTYPE* get_EntityFactory)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This,
        __x_ABI_CWindows_CAI_CActions_CIActionEntityFactory2** value);
    HRESULT (STDMETHODCALLTYPE* CreateInvocationContext)(__x_ABI_CWindows_CAI_CActions_CIActionRuntime* This,
        HSTRING actionName,
        __x_ABI_CWindows_CAI_CActions_CIActionInvocationContext** result);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionRuntimeVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionRuntime
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionRuntimeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_get_ActionCatalog(This, value) \
    ((This)->lpVtbl->get_ActionCatalog(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_get_EntityFactory(This, value) \
    ((This)->lpVtbl->get_EntityFactory(This, value))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntime_CreateInvocationContext(This, actionName, result) \
    ((This)->lpVtbl->CreateInvocationContext(This, actionName, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionRuntime;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntime_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IActionRuntimeFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.ActionRuntime
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IActionRuntimeFactory[] = L"Windows.AI.Actions.IActionRuntimeFactory";
typedef struct __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory* This,
        TrustLevel* trustLevel);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactoryVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIActionRuntimeFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IDocumentActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.DocumentActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IDocumentActionEntity[] = L"Windows.AI.Actions.IDocumentActionEntity";
typedef struct __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntityVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_FullPath)(__x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntityVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntityVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_get_FullPath(This, value) \
    ((This)->lpVtbl->get_FullPath(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIDocumentActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IFileActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.FileActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IFileActionEntity[] = L"Windows.AI.Actions.IFileActionEntity";
typedef struct __x_ABI_CWindows_CAI_CActions_CIFileActionEntityVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIFileActionEntity* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIFileActionEntity* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIFileActionEntity* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIFileActionEntity* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIFileActionEntity* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIFileActionEntity* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_FullPath)(__x_ABI_CWindows_CAI_CActions_CIFileActionEntity* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIFileActionEntityVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIFileActionEntity
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIFileActionEntityVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIFileActionEntity_get_FullPath(This, value) \
    ((This)->lpVtbl->get_FullPath(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIFileActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIFileActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.INamedActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.NamedActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_INamedActionEntity[] = L"Windows.AI.Actions.INamedActionEntity";
typedef struct __x_ABI_CWindows_CAI_CActions_CINamedActionEntityVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Name)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Name)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_Entity)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        __x_ABI_CWindows_CAI_CActions_CIActionEntity** value);
    HRESULT (STDMETHODCALLTYPE* put_Entity)(__x_ABI_CWindows_CAI_CActions_CINamedActionEntity* This,
        __x_ABI_CWindows_CAI_CActions_CIActionEntity* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CINamedActionEntityVtbl;

interface __x_ABI_CWindows_CAI_CActions_CINamedActionEntity
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CINamedActionEntityVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_get_Name(This, value) \
    ((This)->lpVtbl->get_Name(This, value))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_put_Name(This, value) \
    ((This)->lpVtbl->put_Name(This, value))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_get_Entity(This, value) \
    ((This)->lpVtbl->get_Entity(This, value))

#define __x_ABI_CWindows_CAI_CActions_CINamedActionEntity_put_Entity(This, value) \
    ((This)->lpVtbl->put_Entity(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CINamedActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CINamedActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.IPhotoActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.PhotoActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_IPhotoActionEntity[] = L"Windows.AI.Actions.IPhotoActionEntity";
typedef struct __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntityVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_FullPath)(__x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntityVtbl;

interface __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntityVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_get_FullPath(This, value) \
    ((This)->lpVtbl->get_FullPath(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CIPhotoActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Actions.ITextActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Actions.TextActionEntity
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CActions_CITextActionEntity_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CActions_CITextActionEntity_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Actions_ITextActionEntity[] = L"Windows.AI.Actions.ITextActionEntity";
typedef struct __x_ABI_CWindows_CAI_CActions_CITextActionEntityVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CActions_CITextActionEntity* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CActions_CITextActionEntity* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CActions_CITextActionEntity* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CActions_CITextActionEntity* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CActions_CITextActionEntity* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CActions_CITextActionEntity* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Text)(__x_ABI_CWindows_CAI_CActions_CITextActionEntity* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CActions_CITextActionEntityVtbl;

interface __x_ABI_CWindows_CAI_CActions_CITextActionEntity
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CActions_CITextActionEntityVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CActions_CITextActionEntity_get_Text(This, value) \
    ((This)->lpVtbl->get_Text(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CActions_CITextActionEntity;
#endif /* !defined(____x_ABI_CWindows_CAI_CActions_CITextActionEntity_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionEntity ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionEntity[] = L"Windows.AI.Actions.ActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionEntityDisplayInfo
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionEntityDisplayInfo ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionEntityDisplayInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionEntityDisplayInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionEntityDisplayInfo[] = L"Windows.AI.Actions.ActionEntityDisplayInfo";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionEntityFactory
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionEntityFactory2 ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionEntityFactory_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionEntityFactory_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionEntityFactory[] = L"Windows.AI.Actions.ActionEntityFactory";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionInvocationContext
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionInvocationContext ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionInvocationContext_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionInvocationContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionInvocationContext[] = L"Windows.AI.Actions.ActionInvocationContext";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.ActionRuntime
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IActionRuntime ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_ActionRuntime_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_ActionRuntime_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_ActionRuntime[] = L"Windows.AI.Actions.ActionRuntime";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.DocumentActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IDocumentActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_DocumentActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_DocumentActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_DocumentActionEntity[] = L"Windows.AI.Actions.DocumentActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.FileActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IFileActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_FileActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_FileActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_FileActionEntity[] = L"Windows.AI.Actions.FileActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.NamedActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.INamedActionEntity ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_NamedActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_NamedActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_NamedActionEntity[] = L"Windows.AI.Actions.NamedActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.PhotoActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.IPhotoActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_PhotoActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_PhotoActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_PhotoActionEntity[] = L"Windows.AI.Actions.PhotoActionEntity";
#endif
#endif // WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Actions.TextActionEntity
 *
 * Introduced to Windows.AI.Actions.ActionsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Actions.ITextActionEntity ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_ACTIONS_ACTIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Actions_TextActionEntity_DEFINED
#define RUNTIMECLASS_Windows_AI_Actions_TextActionEntity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Actions_TextActionEntity[] = L"Windows.AI.Actions.TextActionEntity";
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
#endif // __windows2Eai2Eactions_p_h__

#endif // __windows2Eai2Eactions_h__
