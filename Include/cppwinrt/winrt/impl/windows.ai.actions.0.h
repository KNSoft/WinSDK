// C++/WinRT v2.0.230511.6

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#ifndef WINRT_Windows_AI_Actions_0_H
#define WINRT_Windows_AI_Actions_0_H
WINRT_EXPORT namespace winrt::Windows::AI::Actions::Hosting
{
    struct ActionCatalog;
}
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct HResult;
}
WINRT_EXPORT namespace winrt::Windows::AI::Actions
{
    enum class ActionEntityKind : int32_t
    {
        None = 0,
        Document = 1,
        File = 2,
        Photo = 3,
        Text = 4,
    };
    enum class ActionInvocationResult : int32_t
    {
        Success = 0,
        UserCanceled = 1,
        Unsupported = 2,
        Unavailable = 3,
    };
    struct IActionEntity;
    struct IActionEntityDisplayInfo;
    struct IActionEntityFactory;
    struct IActionEntityFactory2;
    struct IActionEntityFactoryFactory;
    struct IActionInvocationContext;
    struct IActionRuntime;
    struct IActionRuntimeFactory;
    struct IDocumentActionEntity;
    struct IFileActionEntity;
    struct INamedActionEntity;
    struct IPhotoActionEntity;
    struct ITextActionEntity;
    struct ActionEntity;
    struct ActionEntityDisplayInfo;
    struct ActionEntityFactory;
    struct ActionInvocationContext;
    struct ActionRuntime;
    struct DocumentActionEntity;
    struct FileActionEntity;
    struct NamedActionEntity;
    struct PhotoActionEntity;
    struct TextActionEntity;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::AI::Actions::IActionEntity>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IActionEntityDisplayInfo>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IActionEntityFactory>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IActionEntityFactory2>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IActionEntityFactoryFactory>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IActionInvocationContext>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IActionRuntime>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IActionRuntimeFactory>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IDocumentActionEntity>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IFileActionEntity>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::INamedActionEntity>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::IPhotoActionEntity>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::ITextActionEntity>{ using type = interface_category; };
    template <> struct category<winrt::Windows::AI::Actions::ActionEntity>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::ActionEntityDisplayInfo>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::ActionEntityFactory>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::ActionInvocationContext>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::ActionRuntime>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::DocumentActionEntity>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::FileActionEntity>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::NamedActionEntity>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::PhotoActionEntity>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::TextActionEntity>{ using type = class_category; };
    template <> struct category<winrt::Windows::AI::Actions::ActionEntityKind>{ using type = enum_category; };
    template <> struct category<winrt::Windows::AI::Actions::ActionInvocationResult>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ActionEntity> = L"Windows.AI.Actions.ActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ActionEntityDisplayInfo> = L"Windows.AI.Actions.ActionEntityDisplayInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ActionEntityFactory> = L"Windows.AI.Actions.ActionEntityFactory";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ActionInvocationContext> = L"Windows.AI.Actions.ActionInvocationContext";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ActionRuntime> = L"Windows.AI.Actions.ActionRuntime";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::DocumentActionEntity> = L"Windows.AI.Actions.DocumentActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::FileActionEntity> = L"Windows.AI.Actions.FileActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::NamedActionEntity> = L"Windows.AI.Actions.NamedActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::PhotoActionEntity> = L"Windows.AI.Actions.PhotoActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::TextActionEntity> = L"Windows.AI.Actions.TextActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ActionEntityKind> = L"Windows.AI.Actions.ActionEntityKind";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ActionInvocationResult> = L"Windows.AI.Actions.ActionInvocationResult";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionEntity> = L"Windows.AI.Actions.IActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionEntityDisplayInfo> = L"Windows.AI.Actions.IActionEntityDisplayInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionEntityFactory> = L"Windows.AI.Actions.IActionEntityFactory";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionEntityFactory2> = L"Windows.AI.Actions.IActionEntityFactory2";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionEntityFactoryFactory> = L"Windows.AI.Actions.IActionEntityFactoryFactory";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionInvocationContext> = L"Windows.AI.Actions.IActionInvocationContext";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionRuntime> = L"Windows.AI.Actions.IActionRuntime";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IActionRuntimeFactory> = L"Windows.AI.Actions.IActionRuntimeFactory";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IDocumentActionEntity> = L"Windows.AI.Actions.IDocumentActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IFileActionEntity> = L"Windows.AI.Actions.IFileActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::INamedActionEntity> = L"Windows.AI.Actions.INamedActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::IPhotoActionEntity> = L"Windows.AI.Actions.IPhotoActionEntity";
    template <> inline constexpr auto& name_v<winrt::Windows::AI::Actions::ITextActionEntity> = L"Windows.AI.Actions.ITextActionEntity";
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionEntity>{ 0x445E700F,0x2122,0x5668,{ 0x9A,0x16,0x4C,0xAB,0x29,0x82,0xC5,0xF4 } }; // 445E700F-2122-5668-9A16-4CAB2982C5F4
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionEntityDisplayInfo>{ 0x057A9EDE,0x03E1,0x55C6,{ 0xAC,0xBA,0xC7,0x05,0x62,0x16,0x73,0x5A } }; // 057A9EDE-03E1-55C6-ACBA-C7056216735A
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionEntityFactory>{ 0x9CB752A0,0x5BF8,0x5BE2,{ 0x91,0x6E,0xB0,0x0E,0xFF,0x80,0x08,0x8D } }; // 9CB752A0-5BF8-5BE2-916E-B00EFF80088D
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionEntityFactory2>{ 0xEA2FB6A5,0xEC6D,0x5180,{ 0x9D,0x30,0xBC,0x66,0x3B,0x84,0xE7,0xB8 } }; // EA2FB6A5-EC6D-5180-9D30-BC663B84E7B8
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionEntityFactoryFactory>{ 0xC9147D8F,0x88A0,0x5EC0,{ 0xA5,0x64,0x47,0xE2,0xA1,0x08,0x14,0x12 } }; // C9147D8F-88A0-5EC0-A564-47E2A1081412
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionInvocationContext>{ 0x8D8DE82E,0xBF94,0x51A4,{ 0xA0,0xE9,0xDC,0x50,0x14,0x94,0x81,0x84 } }; // 8D8DE82E-BF94-51A4-A0E9-DC5014948184
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionRuntime>{ 0x206EFA2C,0xC909,0x508A,{ 0xB4,0xB0,0x94,0x82,0xBE,0x96,0xDB,0x9C } }; // 206EFA2C-C909-508A-B4B0-9482BE96DB9C
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IActionRuntimeFactory>{ 0xD3F366E9,0x8DC9,0x50A0,{ 0x80,0x40,0xE5,0xC1,0x4F,0xA6,0x09,0xD6 } }; // D3F366E9-8DC9-50A0-8040-E5C14FA609D6
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IDocumentActionEntity>{ 0x56715297,0x960B,0x59FF,{ 0xAF,0x4B,0xEC,0xE1,0x09,0x8B,0x2E,0x36 } }; // 56715297-960B-59FF-AF4B-ECE1098B2E36
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IFileActionEntity>{ 0xF20AB43F,0x4C80,0x5904,{ 0xBD,0x42,0x3E,0x62,0x48,0xBA,0xBF,0xCF } }; // F20AB43F-4C80-5904-BD42-3E6248BABFCF
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::INamedActionEntity>{ 0x1AAEBEEF,0x435B,0x5A0D,{ 0x81,0x82,0x05,0xFE,0x4D,0xD4,0x77,0x12 } }; // 1AAEBEEF-435B-5A0D-8182-05FE4DD47712
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::IPhotoActionEntity>{ 0x425123B3,0x20EF,0x51A6,{ 0xB3,0x5F,0x84,0x14,0x38,0x47,0x65,0xC5 } }; // 425123B3-20EF-51A6-B35F-8414384765C5
    template <> inline constexpr guid guid_v<winrt::Windows::AI::Actions::ITextActionEntity>{ 0x3C4EC25F,0x5ADB,0x5F73,{ 0xB8,0xF3,0x08,0x0F,0xBE,0xAD,0xD6,0x12 } }; // 3C4EC25F-5ADB-5F73-B8F3-080FBEADD612
    template <> struct default_interface<winrt::Windows::AI::Actions::ActionEntity>{ using type = winrt::Windows::AI::Actions::IActionEntity; };
    template <> struct default_interface<winrt::Windows::AI::Actions::ActionEntityDisplayInfo>{ using type = winrt::Windows::AI::Actions::IActionEntityDisplayInfo; };
    template <> struct default_interface<winrt::Windows::AI::Actions::ActionEntityFactory>{ using type = winrt::Windows::AI::Actions::IActionEntityFactory2; };
    template <> struct default_interface<winrt::Windows::AI::Actions::ActionInvocationContext>{ using type = winrt::Windows::AI::Actions::IActionInvocationContext; };
    template <> struct default_interface<winrt::Windows::AI::Actions::ActionRuntime>{ using type = winrt::Windows::AI::Actions::IActionRuntime; };
    template <> struct default_interface<winrt::Windows::AI::Actions::DocumentActionEntity>{ using type = winrt::Windows::AI::Actions::IDocumentActionEntity; };
    template <> struct default_interface<winrt::Windows::AI::Actions::FileActionEntity>{ using type = winrt::Windows::AI::Actions::IFileActionEntity; };
    template <> struct default_interface<winrt::Windows::AI::Actions::NamedActionEntity>{ using type = winrt::Windows::AI::Actions::INamedActionEntity; };
    template <> struct default_interface<winrt::Windows::AI::Actions::PhotoActionEntity>{ using type = winrt::Windows::AI::Actions::IPhotoActionEntity; };
    template <> struct default_interface<winrt::Windows::AI::Actions::TextActionEntity>{ using type = winrt::Windows::AI::Actions::ITextActionEntity; };
    template <> struct abi<winrt::Windows::AI::Actions::IActionEntity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IActionEntityDisplayInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IActionEntityFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IActionEntityFactory2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateFileEntity(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDocumentEntity(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePhotoEntity(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTextEntity(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IActionEntityFactoryFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IActionInvocationContext>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActionName(void**) noexcept = 0;
            virtual int32_t __stdcall get_EntityFactory(void**) noexcept = 0;
            virtual int32_t __stdcall get_InvokerAumid(void**) noexcept = 0;
            virtual int32_t __stdcall SetInputEntity(void*, void*) noexcept = 0;
            virtual int32_t __stdcall GetInputEntities(uint32_t* __resultSize, void***) noexcept = 0;
            virtual int32_t __stdcall SetOutputEntity(void*, void*) noexcept = 0;
            virtual int32_t __stdcall GetOutputEntities(uint32_t* __resultSize, void***) noexcept = 0;
            virtual int32_t __stdcall get_Result(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Result(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(winrt::hresult*) noexcept = 0;
            virtual int32_t __stdcall put_ExtendedError(winrt::hresult) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IActionRuntime>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActionCatalog(void**) noexcept = 0;
            virtual int32_t __stdcall get_EntityFactory(void**) noexcept = 0;
            virtual int32_t __stdcall CreateInvocationContext(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IActionRuntimeFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IDocumentActionEntity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FullPath(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IFileActionEntity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FullPath(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::INamedActionEntity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_Entity(void**) noexcept = 0;
            virtual int32_t __stdcall put_Entity(void*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::IPhotoActionEntity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FullPath(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::AI::Actions::ITextActionEntity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionEntity
    {
        [[nodiscard]] auto Kind() const;
        [[nodiscard]] auto DisplayInfo() const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionEntity>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionEntity<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionEntityDisplayInfo
    {
        [[nodiscard]] auto Title() const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionEntityDisplayInfo>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionEntityDisplayInfo<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionEntityFactory
    {
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionEntityFactory>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionEntityFactory<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionEntityFactory2
    {
        auto CreateFileEntity(param::hstring const& path) const;
        auto CreateDocumentEntity(param::hstring const& path) const;
        auto CreatePhotoEntity(param::hstring const& path) const;
        auto CreateTextEntity(param::hstring const& text) const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionEntityFactory2>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionEntityFactory2<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionEntityFactoryFactory
    {
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionEntityFactoryFactory>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionEntityFactoryFactory<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionInvocationContext
    {
        [[nodiscard]] auto ActionName() const;
        [[nodiscard]] auto EntityFactory() const;
        [[nodiscard]] auto InvokerAumid() const;
        auto SetInputEntity(param::hstring const& inputName, winrt::Windows::AI::Actions::ActionEntity const& inputValue) const;
        auto GetInputEntities() const;
        auto SetOutputEntity(param::hstring const& outputName, winrt::Windows::AI::Actions::ActionEntity const& outputValue) const;
        auto GetOutputEntities() const;
        [[nodiscard]] auto Result() const;
        auto Result(winrt::Windows::AI::Actions::ActionInvocationResult const& value) const;
        [[nodiscard]] auto ExtendedError() const;
        auto ExtendedError(winrt::hresult const& value) const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionInvocationContext>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionInvocationContext<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionRuntime
    {
        [[nodiscard]] auto ActionCatalog() const;
        [[nodiscard]] auto EntityFactory() const;
        auto CreateInvocationContext(param::hstring const& actionName) const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionRuntime>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionRuntime<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IActionRuntimeFactory
    {
    };
    template <> struct consume<winrt::Windows::AI::Actions::IActionRuntimeFactory>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IActionRuntimeFactory<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IDocumentActionEntity
    {
        [[nodiscard]] auto FullPath() const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IDocumentActionEntity>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IDocumentActionEntity<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IFileActionEntity
    {
        [[nodiscard]] auto FullPath() const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IFileActionEntity>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IFileActionEntity<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_INamedActionEntity
    {
        [[nodiscard]] auto Name() const;
        auto Name(param::hstring const& value) const;
        [[nodiscard]] auto Entity() const;
        auto Entity(winrt::Windows::AI::Actions::ActionEntity const& value) const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::INamedActionEntity>
    {
        template <typename D> using type = consume_Windows_AI_Actions_INamedActionEntity<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_IPhotoActionEntity
    {
        [[nodiscard]] auto FullPath() const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::IPhotoActionEntity>
    {
        template <typename D> using type = consume_Windows_AI_Actions_IPhotoActionEntity<D>;
    };
    template <typename D>
    struct consume_Windows_AI_Actions_ITextActionEntity
    {
        [[nodiscard]] auto Text() const;
    };
    template <> struct consume<winrt::Windows::AI::Actions::ITextActionEntity>
    {
        template <typename D> using type = consume_Windows_AI_Actions_ITextActionEntity<D>;
    };
}
#endif
