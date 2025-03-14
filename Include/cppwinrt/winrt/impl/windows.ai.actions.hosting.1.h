// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_Hosting_1_H
#define WINRT_Windows_AI_Actions_Hosting_1_H
#include "winrt/impl/Windows.AI.Actions.Hosting.0.h"
WINRT_EXPORT namespace winrt::Windows::AI::Actions::Hosting
{
    struct __declspec(empty_bases) IActionCatalog :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionCatalog>
    {
        IActionCatalog(std::nullptr_t = nullptr) noexcept {}
        IActionCatalog(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionDefinition :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionDefinition>
    {
        IActionDefinition(std::nullptr_t = nullptr) noexcept {}
        IActionDefinition(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionEntityRegistrationInfo :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionEntityRegistrationInfo>
    {
        IActionEntityRegistrationInfo(std::nullptr_t = nullptr) noexcept {}
        IActionEntityRegistrationInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionOverload :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionOverload>
    {
        IActionOverload(std::nullptr_t = nullptr) noexcept {}
        IActionOverload(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
