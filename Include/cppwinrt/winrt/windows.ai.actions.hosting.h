// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_Hosting_H
#define WINRT_Windows_AI_Actions_Hosting_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.230511.6"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.230511.6"
#include "winrt/Windows.AI.Actions.h"
#include "winrt/impl/Windows.AI.Actions.2.h"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.AI.Actions.Hosting.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionCatalog<D>::GetAllActions() const
    {
        uint32_t result_impl_size{};
        void** result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionCatalog)->GetAllActions(&result_impl_size, &result));
        return com_array<winrt::Windows::AI::Actions::Hosting::ActionDefinition>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionCatalog<D>::Changed(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::AI::Actions::Hosting::ActionCatalog, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        winrt::event_token token{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionCatalog)->add_Changed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_AI_Actions_Hosting_IActionCatalog<D>::Changed_revoker consume_Windows_AI_Actions_Hosting_IActionCatalog<D>::Changed(auto_revoke_t, winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::AI::Actions::Hosting::ActionCatalog, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Changed_revoker>(this, Changed(handler));
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionCatalog<D>::Changed(winrt::event_token const& token) const noexcept
    {
        WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionCatalog)->remove_Changed(impl::bind_in(token));
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionDefinition<D>::Id() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionDefinition)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionDefinition<D>::Description() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionDefinition)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionDefinition<D>::IconFullPath() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionDefinition)->get_IconFullPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionDefinition<D>::PackageFamilyName() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionDefinition)->get_PackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionDefinition<D>::GetInputs() const
    {
        uint32_t result_impl_size{};
        void** result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionDefinition)->GetInputs(&result_impl_size, &result));
        return com_array<winrt::Windows::AI::Actions::Hosting::ActionEntityRegistrationInfo>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionDefinition<D>::GetOutputs() const
    {
        uint32_t result_impl_size{};
        void** result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionDefinition)->GetOutputs(&result_impl_size, &result));
        return com_array<winrt::Windows::AI::Actions::Hosting::ActionEntityRegistrationInfo>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionDefinition<D>::GetOverloads() const
    {
        uint32_t result_impl_size{};
        void** result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionDefinition)->GetOverloads(&result_impl_size, &result));
        return com_array<winrt::Windows::AI::Actions::Hosting::ActionOverload>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo<D>::Name() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo<D>::Name(param::hstring const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo)->put_Name(*(void**)(&value)));
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo<D>::Kind() const
    {
        winrt::Windows::AI::Actions::ActionEntityKind value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo<D>::Kind(winrt::Windows::AI::Actions::ActionEntityKind const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo)->put_Kind(static_cast<int32_t>(value)));
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionOverload<D>::DescriptionTemplate() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionOverload)->get_DescriptionTemplate(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionOverload<D>::GetInputs() const
    {
        uint32_t result_impl_size{};
        void** result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionOverload)->GetInputs(&result_impl_size, &result));
        return com_array<winrt::Windows::AI::Actions::Hosting::ActionEntityRegistrationInfo>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_AI_Actions_Hosting_IActionOverload<D>::InvokeAsync(winrt::Windows::AI::Actions::ActionInvocationContext const& context) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Hosting::IActionOverload)->InvokeAsync(*(void**)(&context), &operation));
        return winrt::Windows::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::Hosting::IActionCatalog> : produce_base<D, winrt::Windows::AI::Actions::Hosting::IActionCatalog>
    {
        int32_t __stdcall GetAllActions(uint32_t* __resultSize, void*** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetAllActions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Changed(void* handler, winrt::event_token* token) noexcept final try
        {
            zero_abi<winrt::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<winrt::event_token>(this->shim().Changed(*reinterpret_cast<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::AI::Actions::Hosting::ActionCatalog, winrt::Windows::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Changed(winrt::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Changed(*reinterpret_cast<winrt::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::Hosting::IActionDefinition> : produce_base<D, winrt::Windows::AI::Actions::Hosting::IActionDefinition>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IconFullPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().IconFullPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInputs(uint32_t* __resultSize, void*** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetInputs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOutputs(uint32_t* __resultSize, void*** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetOutputs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOverloads(uint32_t* __resultSize, void*** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetOverloads());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo> : produce_base<D, winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo>
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
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::AI::Actions::ActionEntityKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Kind(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Kind(*reinterpret_cast<winrt::Windows::AI::Actions::ActionEntityKind const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::Hosting::IActionOverload> : produce_base<D, winrt::Windows::AI::Actions::Hosting::IActionOverload>
    {
        int32_t __stdcall get_DescriptionTemplate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DescriptionTemplate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInputs(uint32_t* __resultSize, void*** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetInputs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InvokeAsync(void* context, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<winrt::Windows::Foundation::IAsyncAction>(this->shim().InvokeAsync(*reinterpret_cast<winrt::Windows::AI::Actions::ActionInvocationContext const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
WINRT_EXPORT namespace winrt::Windows::AI::Actions::Hosting
{
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::IActionCatalog> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::IActionDefinition> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::IActionOverload> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::ActionCatalog> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::ActionDefinition> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::ActionEntityRegistrationInfo> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::AI::Actions::Hosting::ActionOverload> : winrt::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
