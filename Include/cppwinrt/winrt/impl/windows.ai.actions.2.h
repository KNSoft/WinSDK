// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_2_H
#define WINRT_Windows_AI_Actions_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.AI.Actions.1.h"
WINRT_EXPORT namespace winrt::Windows::AI::Actions
{
    struct __declspec(empty_bases) ActionEntity : winrt::Windows::AI::Actions::IActionEntity,
        impl::require<ActionEntity, winrt::Windows::Foundation::IClosable>
    {
        ActionEntity(std::nullptr_t) noexcept {}
        ActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IActionEntity(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActionEntityDisplayInfo : winrt::Windows::AI::Actions::IActionEntityDisplayInfo,
        impl::require<ActionEntityDisplayInfo, winrt::Windows::Foundation::IClosable>
    {
        ActionEntityDisplayInfo(std::nullptr_t) noexcept {}
        ActionEntityDisplayInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IActionEntityDisplayInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActionEntityFactory : winrt::Windows::AI::Actions::IActionEntityFactory2,
        impl::require<ActionEntityFactory, winrt::Windows::Foundation::IClosable>
    {
        ActionEntityFactory(std::nullptr_t) noexcept {}
        ActionEntityFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IActionEntityFactory2(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActionInvocationContext : winrt::Windows::AI::Actions::IActionInvocationContext,
        impl::require<ActionInvocationContext, winrt::Windows::Foundation::IClosable>
    {
        ActionInvocationContext(std::nullptr_t) noexcept {}
        ActionInvocationContext(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IActionInvocationContext(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActionRuntime : winrt::Windows::AI::Actions::IActionRuntime,
        impl::require<ActionRuntime, winrt::Windows::Foundation::IClosable>
    {
        ActionRuntime(std::nullptr_t) noexcept {}
        ActionRuntime(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IActionRuntime(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DocumentActionEntity : winrt::Windows::AI::Actions::IDocumentActionEntity,
        impl::base<DocumentActionEntity, winrt::Windows::AI::Actions::ActionEntity>,
        impl::require<DocumentActionEntity, winrt::Windows::AI::Actions::IActionEntity, winrt::Windows::Foundation::IClosable>
    {
        DocumentActionEntity(std::nullptr_t) noexcept {}
        DocumentActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IDocumentActionEntity(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileActionEntity : winrt::Windows::AI::Actions::IFileActionEntity,
        impl::base<FileActionEntity, winrt::Windows::AI::Actions::ActionEntity>,
        impl::require<FileActionEntity, winrt::Windows::AI::Actions::IActionEntity, winrt::Windows::Foundation::IClosable>
    {
        FileActionEntity(std::nullptr_t) noexcept {}
        FileActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IFileActionEntity(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NamedActionEntity : winrt::Windows::AI::Actions::INamedActionEntity,
        impl::require<NamedActionEntity, winrt::Windows::Foundation::IClosable>
    {
        NamedActionEntity(std::nullptr_t) noexcept {}
        NamedActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::INamedActionEntity(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoActionEntity : winrt::Windows::AI::Actions::IPhotoActionEntity,
        impl::base<PhotoActionEntity, winrt::Windows::AI::Actions::ActionEntity>,
        impl::require<PhotoActionEntity, winrt::Windows::AI::Actions::IActionEntity, winrt::Windows::Foundation::IClosable>
    {
        PhotoActionEntity(std::nullptr_t) noexcept {}
        PhotoActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::IPhotoActionEntity(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TextActionEntity : winrt::Windows::AI::Actions::ITextActionEntity,
        impl::base<TextActionEntity, winrt::Windows::AI::Actions::ActionEntity>,
        impl::require<TextActionEntity, winrt::Windows::AI::Actions::IActionEntity, winrt::Windows::Foundation::IClosable>
    {
        TextActionEntity(std::nullptr_t) noexcept {}
        TextActionEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::AI::Actions::ITextActionEntity(ptr, take_ownership_from_abi) {}
    };
}
#endif
