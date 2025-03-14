// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_Provider_1_H
#define WINRT_Windows_AI_Actions_Provider_1_H
#include "winrt/impl/Windows.AI.Actions.Provider.0.h"
WINRT_EXPORT namespace winrt::Windows::AI::Actions::Provider
{
    struct __declspec(empty_bases) IActionProvider :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionProvider>
    {
        IActionProvider(std::nullptr_t = nullptr) noexcept {}
        IActionProvider(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
