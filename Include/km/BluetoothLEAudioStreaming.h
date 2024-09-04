/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

 BluetoothLEAudioStreaming.h

Abstract:

    This module defines the types needed for audio drivers to indicate support for Bluetooth LE Audio Streaming.

--*/

#pragma once

//
// {5C52FDB5-722A-4AB7-A342-70163B7E9B5C}
// ACX circuit component ID definition for LE Audio render endpoints
//
DEFINE_GUID(GUID_BLUETOOTH_LEAUDIO_RENDER_COMPONENT_ID, 0x5c52fdb5, 0x722a, 0x4ab7, 0xa3, 0x42, 0x70, 0x16, 0x3b, 0x7e, 0x9b, 0x5c);

//
// {1DFF2EE3-AE89-441C-BDE3-24F885C55DF8}
// ACX circuit component ID definition for LE audio capture endpoints
//
DEFINE_GUID(GUID_BLUETOOTH_LEAUDIO_CAPTURE_COMPONENT_ID, 0x1dff2ee3, 0xae89, 0x441c, 0xbd, 0xe3, 0x24, 0xf8, 0x85, 0xc5, 0x5d, 0xf8);

//
// GUID_BLUETOOTH_LEAUDIO_SUPPORT_INTERFACE
// Published by the audio driver to indicate that it is configured for Bluetooth LE Audio streaming.
//
// {BA02FA1B-0FD0-4A0F-A748-4FAE2E2D2F67}
DEFINE_GUID(GUID_BLUETOOTH_LEAUDIO_SUPPORT_INTERFACE, 0xba02fa1b, 0x0fd0, 0x4a0f, 0xa7, 0x48, 0x4f, 0xae, 0x2e, 0x2d, 0x2f, 0x67);

#define GUID_BLUETOOTH_LEAUDIO_SUPPORT_INTERFACE_DEFINED