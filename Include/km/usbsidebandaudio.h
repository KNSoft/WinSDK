/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

 USBSidebandAudio.h

Abstract:

    This module defines the types, constants, and functions that are
    exposed to device drivers that interact with the Windows USB Audio
    Driver.

--*/

#pragma once

//
// The interface class GUID for USB SIDEBAND AUDIO bypass
// Suitable for BADD USB Audio devices
//
// {02BAA4B5-33B5-4D97-AE4F-E86DDE17536F}
//
DEFINE_GUID (GUID_DEVINTERFACE_USB_SIDEBAND_AUDIO_HS_HCIBYPASS,
    0x2baa4b5, 0x33b5, 0x4d97, 0xae, 0x4f, 0xe8, 0x6d, 0xde, 0x17, 0x53, 0x6f);

//
// Sideband Audio parameters Set
// Microsoft USB Audio Sideband Set of Parameters
// {17E71B09-4F0D-4813-B330-5C9247DFCE17}
DEFINE_GUID(SIDEBANDAUDIO_PARAMS_SET_USBAUDIO,
    0x17e71b09, 0x4f0d, 0x4813, 0xb3, 0x30, 0x5c, 0x92, 0x47, 0xdf, 0xce, 0x17);

//
// SIDEBANDAUDIO_EP_USB_TRANSPORT_RESOURCE_TYPE
//
//  Describes the type of transport resource
//
//
typedef enum _SIDEBANDAUDIO_EP_USB_TRANSPORT_RESOURCE_TYPE
{
    // USB Interface Descriptor
    SIOP_TYPE_USBAUD_USBD_INTERFACE_DESCRIPTOR,

    // USBD_ENDPOINT_DESCRIPTOR
    SIOP_TYPE_USBAUD_EP_USBD_ENDPOINT_DESCRIPTOR,

    // USBD_ENDPOINT_OFFLOAD_INFORMATION
    SIOP_TYPE_USBAUD_EP_USBD_ENDPOINT_OFFLOAD_INFORMATION,

    // SIDEBANDAUDIO_EP_USBAUDIO_TRANSPORT_RESOURCES
    SIOP_TYPE_USBAUD_EP_USBAUDIO_TRANSPORT_RESOURCES,

    // USB Offload Resource ID
    SIOP_TYPE_USBAUD_EP_OFFLOAD_RESOURCE_ID,

    // Feedback Endpoint USBD_ENDPOINT_DESCRIPTOR
    SIOP_TYPE_USBAUD_FB_EP_USBD_ENDPOINT_DESCRIPTOR,

    // Feedback Endpoint USBD_ENDPOINT_OFFLOAD_INFORMATION
    SIOP_TYPE_USBAUD_FB_EP_USBD_ENDPOINT_OFFLOAD_INFORMATION,

    // Feedback Endpoint SIDEBANDAUDIO_EP_USBAUDIO_TRANSPORT_RESOURCES
    SIOP_TYPE_USBAUD_FB_EP_USBAUDIO_TRANSPORT_RESOURCES,

    // Feedback Endpoint USB Offload Resource ID
    SIOP_TYPE_USBAUD_FB_EP_OFFLOAD_RESOURCE_ID,

    // USBD_ENDPOINT_DESCRIPTOR for specific format
    SIOP_TYPE_USBAUD_ENDPOINT_DESCRIPTOR_PER_FORMAT,

    SBUSBAUD_EP_TRANSPORT_RESOURCE_TYPE_INVALID,

}SIDEBANDAUDIO_EP_USB_TRANSPORT_RESOURCE_TYPE;

typedef struct _SIDEBANDAUDIO_EP_USBAUDIO_TRANSPORT_RESOURCES
{
    // From USB class-specific AC interface descriptor
    USHORT      bcdAudioSpec;

    // Delay introduced by the data path
    UCHAR       bDelay;

    // From Audio Format Type I Descriptor
    UCHAR       bSlotSize;
}SIDEBANDAUDIO_EP_USBAUDIO_TRANSPORT_RESOURCES, *PSIDEBANDAUDIO_EP_USBAUDIO_TRANSPORT_RESOURCES;

//
// Sideband Audio parameters Set
// Microsoft USB Audio Sideband USB controller Set of Parameters
// {7FE4A3DB-B637-4168-B853-4317079560D2}
DEFINE_GUID(SIDEBANDAUDIO_PARAMS_SET_USB_CONTROLLER,
    0x7fe4a3db, 0xb637, 0x4168, 0xb8, 0x53, 0x43, 0x17, 0x7, 0x95, 0x60, 0xd2);

//
// SIDEBANDAUDIO_USB_CONTROLLER_CONFIG_INFO_TYPE
//
//  Describes the type of transport resource
//
//
typedef enum _SIDEBANDAUDIO_USB_CONTROLLER_CONFIG_INFO_TYPE
{
    // Device behind hub
    SIOP_TYPE_USBAUD_CONTROLLER_CONFIG_INFO_DEVICE_BEHIND_HUB,

    SBUSBAUD_CONTROLLER_CONFIG_INFO_TYPE_INVALID,

}SIDEBANDAUDIO_USB_CONTROLLER_CONFIG_INFO_TYPE;

