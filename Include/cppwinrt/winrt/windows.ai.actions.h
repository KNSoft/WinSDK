// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_H
#define WINRT_Windows_AI_Actions_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.230511.6"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.230511.6"
#include "winrt/impl/Windows.AI.Actions.Hosting.2.h"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.AI.Actions.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_Windows_AI_Actions_IActionEntity<D>::Kind() const
    {
        winrt::Windows::AI::Actions::ActionEntityKind value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionEntity)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionEntity<D>::DisplayInfo() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionEntity)->get_DisplayInfo(&value));
        return winrt::Windows::AI::Actions::ActionEntityDisplayInfo{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionEntityDisplayInfo<D>::Title() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionEntityDisplayInfo)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionEntityFactory2<D>::CreateFileEntity(param::hstring const& path) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionEntityFactory2)->CreateFileEntity(*(void**)(&path), &result));
        return winrt::Windows::AI::Actions::FileActionEntity{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionEntityFactory2<D>::CreateDocumentEntity(param::hstring const& path) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionEntityFactory2)->CreateDocumentEntity(*(void**)(&path), &result));
        return winrt::Windows::AI::Actions::DocumentActionEntity{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionEntityFactory2<D>::CreatePhotoEntity(param::hstring const& path) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionEntityFactory2)->CreatePhotoEntity(*(void**)(&path), &result));
        return winrt::Windows::AI::Actions::PhotoActionEntity{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionEntityFactory2<D>::CreateTextEntity(param::hstring const& text) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionEntityFactory2)->CreateTextEntity(*(void**)(&text), &result));
        return winrt::Windows::AI::Actions::TextActionEntity{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::ActionName() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->get_ActionName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::EntityFactory() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->get_EntityFactory(&value));
        return winrt::Windows::AI::Actions::ActionEntityFactory{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::InvokerAumid() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->get_InvokerAumid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::SetInputEntity(param::hstring const& inputName, winrt::Windows::AI::Actions::ActionEntity const& inputValue) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->SetInputEntity(*(void**)(&inputName), *(void**)(&inputValue)));
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::GetInputEntities() const
    {
        uint32_t result_impl_size{};
        void** result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->GetInputEntities(&result_impl_size, &result));
        return com_array<winrt::Windows::AI::Actions::NamedActionEntity>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::SetOutputEntity(param::hstring const& outputName, winrt::Windows::AI::Actions::ActionEntity const& outputValue) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->SetOutputEntity(*(void**)(&outputName), *(void**)(&outputValue)));
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::GetOutputEntities() const
    {
        uint32_t result_impl_size{};
        void** result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->GetOutputEntities(&result_impl_size, &result));
        return com_array<winrt::Windows::AI::Actions::NamedActionEntity>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::Result() const
    {
        winrt::Windows::AI::Actions::ActionInvocationResult value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->get_Result(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::Result(winrt::Windows::AI::Actions::ActionInvocationResult const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->put_Result(static_cast<int32_t>(value)));
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::ExtendedError() const
    {
        winrt::hresult value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionInvocationContext<D>::ExtendedError(winrt::hresult const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionInvocationContext)->put_ExtendedError(impl::bind_in(value)));
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionRuntime<D>::ActionCatalog() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionRuntime)->get_ActionCatalog(&value));
        return winrt::Windows::AI::Actions::Hosting::ActionCatalog{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionRuntime<D>::EntityFactory() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionRuntime)->get_EntityFactory(&value));
        return winrt::Windows::AI::Actions::ActionEntityFactory{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IActionRuntime<D>::CreateInvocationContext(param::hstring const& actionName) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IActionRuntime)->CreateInvocationContext(*(void**)(&actionName), &result));
        return winrt::Windows::AI::Actions::ActionInvocationContext{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IDocumentActionEntity<D>::FullPath() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IDocumentActionEntity)->get_FullPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_IFileActionEntity<D>::FullPath() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IFileActionEntity)->get_FullPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_INamedActionEntity<D>::Name() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::INamedActionEntity)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_INamedActionEntity<D>::Name(param::hstring const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::INamedActionEntity)->put_Name(*(void**)(&value)));
    }
    template <typename D> auto consume_Windows_AI_Actions_INamedActionEntity<D>::Entity() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::INamedActionEntity)->get_Entity(&value));
        return winrt::Windows::AI::Actions::ActionEntity{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_INamedActionEntity<D>::Entity(winrt::Windows::AI::Actions::ActionEntity const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::INamedActionEntity)->put_Entity(*(void**)(&value)));
    }
    template <typename D> auto consume_Windows_AI_Actions_IPhotoActionEntity<D>::FullPath() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::IPhotoActionEntity)->get_FullPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_ITextActionEntity<D>::Text() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::ITextActionEntity)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionEntity> : produce_base<D, winrt::Windows::AI::Actions::IActionEntity>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::ActionEntityKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::ActionEntityDisplayInfo>(this->shim().DisplayInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionEntityDisplayInfo> : produce_base<D, winrt::Windows::AI::Actions::IActionEntityDisplayInfo>
    {
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionEntityFactory> : produce_base<D, winrt::Windows::AI::Actions::IActionEntityFactory>
    {
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionEntityFactory2> : produce_base<D, winrt::Windows::AI::Actions::IActionEntityFactory2>
    {
        int32_t __stdcall CreateFileEntity(void* path, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::AI::Actions::FileActionEntity>(this->shim().CreateFileEntity(*reinterpret_cast<hstring const*>(&path)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDocumentEntity(void* path, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::AI::Actions::DocumentActionEntity>(this->shim().CreateDocumentEntity(*reinterpret_cast<hstring const*>(&path)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePhotoEntity(void* path, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::AI::Actions::PhotoActionEntity>(this->shim().CreatePhotoEntity(*reinterpret_cast<hstring const*>(&path)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTextEntity(void* text, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::AI::Actions::TextActionEntity>(this->shim().CreateTextEntity(*reinterpret_cast<hstring const*>(&text)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionEntityFactoryFactory> : produce_base<D, winrt::Windows::AI::Actions::IActionEntityFactoryFactory>
    {
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionInvocationContext> : produce_base<D, winrt::Windows::AI::Actions::IActionInvocationContext>
    {
        int32_t __stdcall get_ActionName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ActionName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EntityFactory(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::ActionEntityFactory>(this->shim().EntityFactory());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InvokerAumid(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().InvokerAumid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInputEntity(void* inputName, void* inputValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInputEntity(*reinterpret_cast<hstring const*>(&inputName), *reinterpret_cast<winrt::Windows::AI::Actions::ActionEntity const*>(&inputValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInputEntities(uint32_t* __resultSize, void*** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetInputEntities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetOutputEntity(void* outputName, void* outputValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetOutputEntity(*reinterpret_cast<hstring const*>(&outputName), *reinterpret_cast<winrt::Windows::AI::Actions::ActionEntity const*>(&outputValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOutputEntities(uint32_t* __resultSize, void*** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetOutputEntities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Result(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::ActionInvocationResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Result(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Result(*reinterpret_cast<winrt::Windows::AI::Actions::ActionInvocationResult const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(winrt::hresult* value) noexcept final try
        {
            zero_abi<winrt::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ExtendedError(winrt::hresult value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExtendedError(*reinterpret_cast<winrt::hresult const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionRuntime> : produce_base<D, winrt::Windows::AI::Actions::IActionRuntime>
    {
        int32_t __stdcall get_ActionCatalog(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::Hosting::ActionCatalog>(this->shim().ActionCatalog());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EntityFactory(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::ActionEntityFactory>(this->shim().EntityFactory());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInvocationContext(void* actionName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::AI::Actions::ActionInvocationContext>(this->shim().CreateInvocationContext(*reinterpret_cast<hstring const*>(&actionName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IActionRuntimeFactory> : produce_base<D, winrt::Windows::AI::Actions::IActionRuntimeFactory>
    {
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IDocumentActionEntity> : produce_base<D, winrt::Windows::AI::Actions::IDocumentActionEntity>
    {
        int32_t __stdcall get_FullPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FullPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IFileActionEntity> : produce_base<D, winrt::Windows::AI::Actions::IFileActionEntity>
    {
        int32_t __stdcall get_FullPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FullPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::INamedActionEntity> : produce_base<D, winrt::Windows::AI::Actions::INamedActionEntity>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Entity(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::ActionEntity>(this->shim().Entity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Entity(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Entity(*reinterpret_cast<winrt::Windows::AI::Actions::ActionEntity const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::IPhotoActionEntity> : produce_base<D, winrt::Windows::AI::Actions::IPhotoActionEntity>
    {
        int32_t __stdcall get_FullPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FullPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::ITextActionEntity> : produce_base<D, winrt::Windows::AI::Actions::ITextActionEntity>
    {
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
WINRT_EXPORT namespace winrt::Windows::AI::Actions
{
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Windows::AI::Actions::IActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IActionEntityDisplayInfo> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IActionEntityFactory> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IActionEntityFactory2> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IActionEntityFactoryFactory> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IActionInvocationContext> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IActionRuntime> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IActionRuntimeFactory> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IDocumentActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IFileActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::INamedActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::IPhotoActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::ITextActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::ActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::ActionEntityDisplayInfo> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::ActionEntityFactory> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::ActionInvocationContext> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::ActionRuntime> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::DocumentActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::FileActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::NamedActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::PhotoActionEntity> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::TextActionEntity> : winrt::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
