// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_Hosting_0_H
#define WINRT_Windows_AI_Actions_Hosting_0_H
WINRT_EXPORT namespace winrt::Windows::AI::Actions
{
    enum class ActionEntityKind : int32_t;
    struct ActionInvocationContext;
}
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
WINRT_EXPORT namespace winrt::Windows::AI::Actions::Hosting
{
    struct IActionCatalog;
    struct IActionDefinition;
    struct IActionEntityRegistrationInfo;
    struct IActionOverload;
    struct ActionCatalog;
    struct ActionDefinition;
    struct ActionEntityRegistrationInfo;
    struct ActionOverload;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::AI::Actions::Hosting::IActionCatalog>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::Hosting::IActionDefinition>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::Hosting::IActionOverload>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::Hosting::ActionCatalog>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::Hosting::ActionDefinition>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::Hosting::ActionEntityRegistrationInfo>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::Hosting::ActionOverload>{ using type = class_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::ActionCatalog> = L"Windows.AI.Actions.Hosting.ActionCatalog";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::ActionDefinition> = L"Windows.AI.Actions.Hosting.ActionDefinition";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::ActionEntityRegistrationInfo> = L"Windows.AI.Actions.Hosting.ActionEntityRegistrationInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::ActionOverload> = L"Windows.AI.Actions.Hosting.ActionOverload";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::IActionCatalog> = L"Windows.AI.Actions.Hosting.IActionCatalog";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::IActionDefinition> = L"Windows.AI.Actions.Hosting.IActionDefinition";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo> = L"Windows.AI.Actions.Hosting.IActionEntityRegistrationInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::Hosting::IActionOverload> = L"Windows.AI.Actions.Hosting.IActionOverload";
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::Hosting::IActionCatalog>{ 0xDBE7C537,0x66EA,0x5394,{ 0x90,0x85,0x4F,0xC1,0x9D,0x78,0x37,0x5C } }; // DBE7C537-66EA-5394-9085-4FC19D78375C
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::Hosting::IActionDefinition>{ 0xFE766ADD,0x924D,0x5231,{ 0x85,0x5E,0xDA,0xC9,0xE8,0x2C,0x7E,0x6C } }; // FE766ADD-924D-5231-855E-DAC9E82C7E6C
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo>{ 0xC3B92BDB,0x03C3,0x5A9E,{ 0xB0,0x49,0x00,0x2F,0xA0,0x40,0x56,0x99 } }; // C3B92BDB-03C3-5A9E-B049-002FA0405699
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::Hosting::IActionOverload>{ 0x5D184610,0xD09D,0x5375,{ 0x98,0x49,0x50,0x5C,0x35,0x9D,0xCA,0x01 } }; // 5D184610-D09D-5375-9849-505C359DCA01
    template <> struct default_interface<winrt::Windows::AI::Actions::Hosting::ActionCatalog>{ using type = winrt::Windows::AI::Actions::Hosting::IActionCatalog; };
    template <> struct default_interface<winrt::Windows::AI::Actions::Hosting::ActionDefinition>{ using type = winrt::Windows::AI::Actions::Hosting::IActionDefinition; };
    template <> struct default_interface<winrt::Windows::AI::Actions::Hosting::ActionEntityRegistrationInfo>{ using type = winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo; };
    template <> struct default_interface<winrt::Windows::AI::Actions::Hosting::ActionOverload>{ using type = winrt::Windows::AI::Actions::Hosting::IActionOverload; };
    template <> struct abi<winrt::Windows::AI::Actions::Hosting::IActionCatalog>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAllActions(uint32_t* __resultSize, void***) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::Hosting::IActionDefinition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_IconFullPath(void**) noexcept = 0;
            virtual int32_t __stdcall get_PackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall GetInputs(uint32_t* __resultSize, void***) noexcept = 0;
            virtual int32_t __stdcall GetOutputs(uint32_t* __resultSize, void***) noexcept = 0;
            virtual int32_t __stdcall GetOverloads(uint32_t* __resultSize, void***) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Kind(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::Hosting::IActionOverload>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DescriptionTemplate(void**) noexcept = 0;
            virtual int32_t __stdcall GetInputs(uint32_t* __resultSize, void***) noexcept = 0;
            virtual int32_t __stdcall InvokeAsync(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_AI_Actions_Hosting_IActionCatalog
    {
        auto GetAllActions() const;
        auto Changed(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::AI::Actions::Hosting::ActionCatalog, winrt::Windows::Foundation::IInspectable> const& handler) const;
        using Changed_revoker = impl::event_revoker<winrt::Windows::AI::Actions::Hosting::IActionCatalog, &impl::abi_t<winrt::Windows::AI::Actions::Hosting::IActionCatalog>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::AI::Actions::Hosting::ActionCatalog, winrt::Windows::Foundation::IInspectable> const& handler) const;
        auto Changed(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<winrt::Windows::AI::Actions::Hosting::IActionCatalog>
    {
        template <typename D> using type = consume_Windows_AI_Actions_Hosting_IActionCatalog<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_Hosting_IActionDefinition
    {
        [[nodiscard]] auto Id() const;
        [[nodiscard]] auto Description() const;
        [[nodiscard]] auto IconFullPath() const;
        [[nodiscard]] auto PackageFamilyName() const;
        auto GetInputs() const;
        auto GetOutputs() const;
        auto GetOverloads() const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::Hosting::IActionDefinition>
    {
        template <typename D> using type = consume_Windows_AI_Actions_Hosting_IActionDefinition<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo
    {
        [[nodiscard]] auto Name() const;
        auto Name(param::hstring const& value) const;
        [[nodiscard]] auto Kind() const;
        auto Kind(winrt::Windows::AI::Actions::ActionEntityKind const& value) const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::Hosting::IActionEntityRegistrationInfo>
    {
        template <typename D> using type = consume_Windows_AI_Actions_Hosting_IActionEntityRegistrationInfo<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_Hosting_IActionOverload
    {
        [[nodiscard]] auto DescriptionTemplate() const;
        auto GetInputs() const;
        auto InvokeAsync(winrt::Windows::AI::Actions::ActionInvocationContext const& context) const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::Hosting::IActionOverload>
    {
        template <typename D> using type = consume_Windows_AI_Actions_Hosting_IActionOverload<D>;
    };
}
#endif
