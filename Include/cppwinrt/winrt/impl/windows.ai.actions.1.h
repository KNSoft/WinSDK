// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_1_H
#define WINRT_Windows_AI_Actions_1_H
#include "winrt/impl/Windows.AI.Actions.0.h"
WINRT_EXPORT namespace winrt::Windows::AI::Actions
{
    struct __declspec(empty_bases) IActionEntity :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionEntity>
    {
        IActionEntity(std::nullptr_t = nullptr) noexcept {}
        IActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionEntityDisplayInfo :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionEntityDisplayInfo>
    {
        IActionEntityDisplayInfo(std::nullptr_t = nullptr) noexcept {}
        IActionEntityDisplayInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionEntityFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionEntityFactory>
    {
        IActionEntityFactory(std::nullptr_t = nullptr) noexcept {}
        IActionEntityFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionEntityFactory2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionEntityFactory2>
    {
        IActionEntityFactory2(std::nullptr_t = nullptr) noexcept {}
        IActionEntityFactory2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionEntityFactoryFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionEntityFactoryFactory>
    {
        IActionEntityFactoryFactory(std::nullptr_t = nullptr) noexcept {}
        IActionEntityFactoryFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionInvocationContext :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionInvocationContext>
    {
        IActionInvocationContext(std::nullptr_t = nullptr) noexcept {}
        IActionInvocationContext(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionRuntime :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionRuntime>
    {
        IActionRuntime(std::nullptr_t = nullptr) noexcept {}
        IActionRuntime(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActionRuntimeFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IActionRuntimeFactory>
    {
        IActionRuntimeFactory(std::nullptr_t = nullptr) noexcept {}
        IActionRuntimeFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDocumentActionEntity :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDocumentActionEntity>
    {
        IDocumentActionEntity(std::nullptr_t = nullptr) noexcept {}
        IDocumentActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileActionEntity :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IFileActionEntity>
    {
        IFileActionEntity(std::nullptr_t = nullptr) noexcept {}
        IFileActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INamedActionEntity :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<INamedActionEntity>
    {
        INamedActionEntity(std::nullptr_t = nullptr) noexcept {}
        INamedActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoActionEntity :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhotoActionEntity>
    {
        IPhotoActionEntity(std::nullptr_t = nullptr) noexcept {}
        IPhotoActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextActionEntity :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ITextActionEntity>
    {
        ITextActionEntity(std::nullptr_t = nullptr) noexcept {}
        ITextActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
