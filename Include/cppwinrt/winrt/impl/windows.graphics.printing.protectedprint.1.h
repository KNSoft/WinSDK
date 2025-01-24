// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_Graphics_Printing_ProtectedPrint_1_H
#define WINRT_Windows_Graphics_Printing_ProtectedPrint_1_H
#include "winrt/impl/Windows.Graphics.Printing.ProtectedPrint.0.h"
WINRT_EXPORT namespace winrt::Windows::Graphics::Printing::ProtectedPrint
{
    struct __declspec(empty_bases) IWindowsProtectedPrintInfoStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IWindowsProtectedPrintInfoStatics>
    {
        IWindowsProtectedPrintInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IWindowsProtectedPrintInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
