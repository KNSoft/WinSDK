// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_Provider_0_H
#define WINRT_Windows_AI_Actions_Provider_0_H
WINRT_EXPORT namespace winrt::Windows::AI::Actions
{
    struct ActionInvocationContext;
}
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct IAsyncAction;
}
WINRT_EXPORT namespace winrt::Windows::AI::Actions::Provider
{
    struct IActionProvider;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::AI::Actions::Provider::IActionProvider>{ using type = interface_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Provider::IActionProvider> = L"Windows.AI.Actions.Provider.IActionProvider";
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::Provider::IActionProvider>{ 0x62906C47,0x3D07,0x55F1,{ 0xAE,0xFA,0x15,0x22,0x50,0x5A,0xFB,0xBE } }; // 62906C47-3D07-55F1-AEFA-1522505AFBBE
    template <> struct abi<winrt::Windows::AI::Actions::Provider::IActionProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InvokeAsync(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_AI_Actions_Provider_IActionProvider
    {
        auto InvokeAsync(winrt::Windows::AI::Actions::ActionInvocationContext const& context) const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::Provider::IActionProvider>
    {
        template <typename D> using type = consume_Windows_AI_Actions_Provider_IActionProvider<D>;
    };
}
#endif
