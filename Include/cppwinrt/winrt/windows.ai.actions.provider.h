// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_Provider_H
#define WINRT_Windows_AI_Actions_Provider_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.230511.6"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.230511.6"
#include "winrt/Windows.AI.Actions.h"
#include "winrt/impl/Windows.AI.Actions.2.h"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.AI.Actions.Provider.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_Windows_AI_Actions_Provider_IActionProvider<D>::InvokeAsync(winrt::Windows::AI::Actions::ActionInvocationContext const& context) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::AI::Actions::Provider::IActionProvider)->InvokeAsync(*(void**)(&context), &operation));
        return winrt::Windows::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, winrt::Windows::AI::Actions::Provider::IActionProvider> : produce_base<D, winrt::Windows::AI::Actions::Provider::IActionProvider>
    {
        int32_t __stdcall InvokeAsync(void* context, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<winrt::Windows::Foundation::IAsyncAction>(this->shim().InvokeAsync(*reinterpret_cast<winrt::Windows::AI::Actions::ActionInvocationContext const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
WINRT_EXPORT namespace winrt::Windows::AI::Actions::Provider
{
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Windows::AI::Actions::Provider::IActionProvider> : winrt::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
