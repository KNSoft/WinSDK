/***
*   arm64_neon.h - declarations/definitions for ARM64 NEON specific intrinsics
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This include file contains the declarations for ARM64 NEON intrinsic functions
*
****/

#pragma once

//#include <stdint.h>
#include <sal.h>

#if !defined (_M_ARM64) && !defined(_M_HYBRID_X86_ARM64) && !defined(_M_ARM64EC)
#error This header is specific to ARM64 targets
#endif  /* !defined (_M_ARM64) */


#if defined (__cplusplus)
extern "C" {
#endif  /* defined (__cplusplus) */


///////////////////////////////////////////////////////////////////////////////
//
#if !defined (_ADVSIMD_ALIGN)
#if defined (__midl)
#define _ADVSIMD_ALIGN(x)
#else  /* defined (__midl) */
#define _ADVSIMD_ALIGN(x) __declspec(align(x))
#endif  /* defined (__midl) */
#endif  /* !defined (_ADVSIMD_ALIGN) */

#ifndef DUMMYNEONSTRUCT
#define DUMMYNEONSTRUCT s
#endif  /* DUMMYNEONSTRUCT */

///////////////////////////////////////////////////////////////////////////////
//
// ARM64 Advanced SIMD 32bit type
//
typedef union __declspec(intrin_type) _ADVSIMD_ALIGN(4) __n32
{
    unsigned __int32    n32_u32[1];
    unsigned __int16    n32_u16[2];
    unsigned __int8     n32_u8[4];
    __int32             n32_i32[1];
    __int16             n32_i16[2];
    __int8              n32_i8[4];
    float               n32_f32[1];
} __n32;


///////////////////////////////////////////////////////////////////////////////
//
// ARM64 Advanced SIMD 16bit type
//
typedef union __declspec(intrin_type) _ADVSIMD_ALIGN(2) __n16
{
    unsigned __int16    n16_u16[1];
    unsigned __int8     n16_u8[2];
    __int16             n16_i16[1];
    __int8              n16_i8[2];
} __n16;


///////////////////////////////////////////////////////////////////////////////
//
// ARM64 Advanced SIMD 8bit type
//
typedef union __declspec(intrin_type) __n8
{
    unsigned __int8     n8_u8[1];
    __int8              n8_i8[1];
} __n8;


///////////////////////////////////////////////////////////////////////////////
//
// ARM64 Advanced SIMD 64bit type
//
typedef union __declspec(intrin_type) _ADVSIMD_ALIGN(8) __n64
{
    unsigned __int64    n64_u64[1];
    unsigned __int32    n64_u32[2];
    unsigned __int16    n64_u16[4];
    unsigned __int8     n64_u8[8];
    __int64             n64_i64[1];
    __int32             n64_i32[2];
    __int16             n64_i16[4];
    __int8              n64_i8[8];
    float               n64_f32[2];
    double              n64_f64[1];
} __n64;


///////////////////////////////////////////////////////////////////////////////
//
// ARM64 Advanced SIMD 128bit type
//
typedef union __declspec(intrin_type) _ADVSIMD_ALIGN(16) __n128
{
     unsigned __int64   n128_u64[2];
     unsigned __int32   n128_u32[4];
     unsigned __int16   n128_u16[8];
     unsigned __int8    n128_u8[16];
     __int64            n128_i64[2];
     __int32            n128_i32[4];
     __int16            n128_i16[8];
     __int8             n128_i8[16];
     float              n128_f32[4];
    double              n128_f64[2];

    struct
    {
        __n64  low64;
        __n64  high64;
    } DUMMYNEONSTRUCT;

} __n128;

typedef struct __n64x2
{
    __n64 val[2];
} __n64x2;

typedef struct __n64x3
{
    __n64 val[3];
} __n64x3;

typedef struct __n64x4
{
    __n64 val[4];
} __n64x4;

typedef struct __n128x2
{
    __n128 val[2];
} __n128x2;

typedef struct __n128x3
{
    __n128 val[3];
} __n128x3;

typedef struct __n128x4
{
    __n128 val[4];
} __n128x4;

///////////////////////////////////////////////////////////////////////////////
//
typedef unsigned __int8  poly8_t;
typedef unsigned __int16 poly16_t;

typedef float float32_t;


///////////////////////////////////////////////////////////////////////////////
//
__inline __n64 *__int8ToN64( __int8 *p)       { return (__n64 *)p; }
__inline __n64 *__int16ToN64( __int16 *p)     { return (__n64 *)p; }
__inline __n64 *__int32ToN64( __int32 *p)     { return (__n64 *)p; }
__inline __n64 *__int64ToN64( __int64 *p)     { return (__n64 *)p; }
__inline __n64 *__uint8ToN64( unsigned __int8 *p)     { return (__n64 *)p; }
__inline __n64 *__uint16ToN64( unsigned __int16 *p)   { return (__n64 *)p; }
__inline __n64 *__uint32ToN64( unsigned __int32 *p)   { return (__n64 *)p; }
__inline __n64 *__uint64ToN64( unsigned __int64 *p)   { return (__n64 *)p; }
__inline __n64 *__poly8ToN64( poly8_t *p)     { return (__n64 *)p; }
__inline __n64 *__poly16ToN64( poly16_t *p)   { return (__n64 *)p; }
__inline __n64 *__float32ToN64( float32_t *p) { return (__n64 *)p; }

__inline const __n64 *__int8ToN64_c( const __int8 *p)       { return (const __n64 *)p; }
__inline const __n64 *__int16ToN64_c( const __int16 *p)     { return (const __n64 *)p; }
__inline const __n64 *__int32ToN64_c( const __int32 *p)     { return (const __n64 *)p; }
__inline const __n64 *__int64ToN64_c( const __int64 *p)     { return (const __n64 *)p; }
__inline const __n64 *__uint8ToN64_c( const unsigned __int8 *p)     { return (const __n64 *)p; }
__inline const __n64 *__uint16ToN64_c( const unsigned __int16 *p)   { return (const __n64 *)p; }
__inline const __n64 *__uint32ToN64_c( const unsigned __int32 *p)   { return (const __n64 *)p; }
__inline const __n64 *__uint64ToN64_c( const unsigned __int64 *p)   { return (const __n64 *)p; }
__inline const __n64 *__poly8ToN64_c( const poly8_t *p)     { return (const __n64 *)p; }
__inline const __n64 *__poly16ToN64_c( const poly16_t *p)   { return (const __n64 *)p; }
__inline const __n64 *__float32ToN64_c( const float32_t *p) { return (const __n64 *)p; }

__inline __int32 __int8ToInt32(__int8 i)      { return (__int32)i; }
__inline __int32 __int16ToInt32(__int16 i)    { return (__int32)i; }
__inline __int32 __int32ToInt32(__int32 i)    { return (__int32)i; }
__inline __int64 __int64ToInt64(__int64 i)    { return (__int64)i; }

__inline __int32 __uint8ToInt32(unsigned __int8 i)    { return (__int32)i; }
__inline __int32 __uint16ToInt32(unsigned __int16 i)  { return (__int32)i; }
__inline __int32 __uint32ToInt32(unsigned __int32 i)  { return (__int32)i; }
__inline __int64 __uint64ToInt64(unsigned __int64 i)  { return (__int64)i; }

__inline __int32 __poly8ToInt32(poly8_t i)    { return (__int32)i; }
__inline __int32 __poly16ToInt32(poly16_t i)  { return (__int32)i; }

///////////////////////////////////////////////////////////////////////////////
// explicit types

typedef __n64    float32x2_t;
typedef __n64x2  float32x2x2_t;
typedef __n64x3  float32x2x3_t;
typedef __n64x4  float32x2x4_t;
typedef __n64    int8x8_t;
typedef __n64x2  int8x8x2_t;
typedef __n64x3  int8x8x3_t;
typedef __n64x4  int8x8x4_t;
typedef __n64    int16x4_t;
typedef __n64x2  int16x4x2_t;
typedef __n64x3  int16x4x3_t;
typedef __n64x4  int16x4x4_t;
typedef __n64    int32x2_t;
typedef __n64x2  int32x2x2_t;
typedef __n64x3  int32x2x3_t;
typedef __n64x4  int32x2x4_t;
typedef __n64    int64x1_t;
typedef __n64x2  int64x1x2_t;
typedef __n64x3  int64x1x3_t;
typedef __n64x4  int64x1x4_t;
typedef __n64    poly8x8_t;
typedef __n64x2  poly8x8x2_t;
typedef __n64x3  poly8x8x3_t;
typedef __n64x4  poly8x8x4_t;
typedef __n64    poly16x4_t;
typedef __n64x2  poly16x4x2_t;
typedef __n64x3  poly16x4x3_t;
typedef __n64x4  poly16x4x4_t;
typedef __n64    uint8x8_t;
typedef __n64x2  uint8x8x2_t;
typedef __n64x3  uint8x8x3_t;
typedef __n64x4  uint8x8x4_t;
typedef __n64    uint16x4_t;
typedef __n64x2  uint16x4x2_t;
typedef __n64x3  uint16x4x3_t;
typedef __n64x4  uint16x4x4_t;
typedef __n64    uint32x2_t;
typedef __n64x2  uint32x2x2_t;
typedef __n64x3  uint32x2x3_t;
typedef __n64x4  uint32x2x4_t;
typedef __n64    uint64x1_t;
typedef __n64x2  uint64x1x2_t;
typedef __n64x3  uint64x1x3_t;
typedef __n64x4  uint64x1x4_t;
typedef __n128   float32x4_t;
typedef __n128x2 float32x4x2_t;
typedef __n128x3 float32x4x3_t;
typedef __n128x4 float32x4x4_t;
typedef __n128   int8x16_t;
typedef __n128x2 int8x16x2_t;
typedef __n128x3 int8x16x3_t;
typedef __n128x4 int8x16x4_t;
typedef __n128   int16x8_t;
typedef __n128x2 int16x8x2_t;
typedef __n128x3 int16x8x3_t;
typedef __n128x4 int16x8x4_t;
typedef __n128   int32x4_t;
typedef __n128x2 int32x4x2_t;
typedef __n128x3 int32x4x3_t;
typedef __n128x4 int32x4x4_t;
typedef __n128   int64x2_t;
typedef __n128x2 int64x2x2_t;
typedef __n128x3 int64x2x3_t;
typedef __n128x4 int64x2x4_t;
typedef __n128   poly8x16_t;
typedef __n128x2 poly8x16x2_t;
typedef __n128x3 poly8x16x3_t;
typedef __n128x4 poly8x16x4_t;
typedef __n128   poly16x8_t;
typedef __n128x2 poly16x8x2_t;
typedef __n128x3 poly16x8x3_t;
typedef __n128x4 poly16x8x4_t;
typedef __n128   uint8x16_t;
typedef __n128x2 uint8x16x2_t;
typedef __n128x3 uint8x16x3_t;
typedef __n128x4 uint8x16x4_t;
typedef __n128   uint16x8_t;
typedef __n128x2 uint16x8x2_t;
typedef __n128x3 uint16x8x3_t;
typedef __n128x4 uint16x8x4_t;
typedef __n128   uint32x4_t;
typedef __n128x2 uint32x4x2_t;
typedef __n128x3 uint32x4x3_t;
typedef __n128x4 uint32x4x4_t;
typedef __n128   uint64x2_t;
typedef __n128x2 uint64x2x2_t;
typedef __n128x3 uint64x2x3_t;
typedef __n128x4 uint64x2x4_t;
typedef __n64 float16x4_t;

///////////////////////////////////////////////////////////////////////////////
// prototypes

// DUP - register (core register to Neon register)
__n64  neon_dupr8(__int32);
__n64  neon_dupr16(__int32);
__n64  neon_dupr32(__int32);
__n64  neon_duprf32(float);
__n64  neon_dupr64(__int64);
__n64  neon_duprf64(double);
__n128 neon_dupqr8(__int32);
__n128 neon_dupqr16(__int32);
__n128 neon_dupqr32(__int32);
__n128 neon_dupqr64(__int64);
__n128 neon_dupqrf32(float);
__n128 neon_dupqrf64(double);
#define vdup_n_f32(reg)       neon_duprf32(reg)
#define vdup_n_p16(reg)       neon_dupr16(reg)
#define vdup_n_p8(reg)        neon_dupr8(reg)
#define vdup_n_s16(reg)       neon_dupr16(reg)
#define vdup_n_s32(reg)       neon_dupr32(reg)
#define vdup_n_s64(reg)       neon_dupr64(reg)
#define vdup_n_s8(reg)        neon_dupr8(reg)
#define vdup_n_u16(reg)       neon_dupr16(reg)
#define vdup_n_u32(reg)       neon_dupr32(reg)
#define vdup_n_u64(reg)       neon_dupr64(reg)
#define vdup_n_u8(reg)        neon_dupr8(reg)
#define vdupq_n_f32(reg)      neon_dupqrf32(reg)
#define vdupq_n_p16(reg)      neon_dupqr16(reg)
#define vdupq_n_p8(reg)       neon_dupqr8(reg)
#define vdupq_n_s16(reg)      neon_dupqr16(reg)
#define vdupq_n_s32(reg)      neon_dupqr32(reg)
#define vdupq_n_s64(reg)      neon_dupqr64(reg)
#define vdupq_n_s8(reg)       neon_dupqr8(reg)
#define vdupq_n_u16(reg)      neon_dupqr16(reg)
#define vdupq_n_u32(reg)      neon_dupqr32(reg)
#define vdupq_n_u64(reg)      neon_dupqr64(reg)
#define vdupq_n_u8(reg)       neon_dupqr8(reg)
#define vmov_n_f32(reg)       neon_duprf32(reg)
#define vmov_n_p16(reg)       neon_dupr16(reg)
#define vmov_n_p8(reg)        neon_dupr8(reg)
#define vmov_n_s16(reg)       neon_dupr16(reg)
#define vmov_n_s32(reg)       neon_dupr32(reg)
#define vmov_n_s64(reg)       neon_dupr64(reg)
#define vmov_n_s8(reg)        neon_dupr8(reg)
#define vmov_n_u16(reg)       neon_dupr16(reg)
#define vmov_n_u32(reg)       neon_dupr32(reg)
#define vmov_n_u64(reg)       neon_dupr64(reg)
#define vmov_n_u8(reg)        neon_dupr8(reg)
#define vmovq_n_f32(reg)      neon_dupqrf32(reg)
#define vmovq_n_p16(reg)      neon_dupqr16(reg)
#define vmovq_n_p8(reg)       neon_dupqr8(reg)
#define vmovq_n_s16(reg)      neon_dupqr16(reg)
#define vmovq_n_s32(reg)      neon_dupqr32(reg)
#define vmovq_n_s64(reg)      neon_dupqr64(reg)
#define vmovq_n_s8(reg)       neon_dupqr8(reg)
#define vmovq_n_u16(reg)      neon_dupqr16(reg)
#define vmovq_n_u32(reg)      neon_dupqr32(reg)
#define vmovq_n_u64(reg)      neon_dupqr64(reg)
#define vmovq_n_u8(reg)       neon_dupqr8(reg)

// DUP - element  (vector element into vector)
__n64  neon_dupe8(__n64, const __int32);
__n64  neon_dupe16(__n64, const __int32);
__n64  neon_dupe32(__n64, const __int32);
__n64  neon_dupe8q(__n128, const __int32);
__n64  neon_dupe16q(__n128, const __int32);
__n64  neon_dupe32q(__n128, const __int32);
__n128  neon_dupqe8(__n64, const __int32);
__n128  neon_dupqe16(__n64, const __int32);
__n128  neon_dupqe32(__n64, const __int32);
__n128  neon_dupqe64(__n64, const __int32);
__n128  neon_dupqe8q(__n128, const __int32);
__n128  neon_dupqe16q(__n128, const __int32);
__n128  neon_dupqe32q(__n128, const __int32);
__n128  neon_dupqe64q(__n128, const __int32);
#define vdup_lane_f32(reg, lane)       neon_dupe32(reg, lane)
#define vdup_lane_p16(reg, lane)       neon_dupe16(reg, lane)
#define vdup_lane_p8(reg, lane)        neon_dupe8(reg, lane)
#define vdup_lane_s16(reg, lane)       neon_dupe16(reg, lane)
#define vdup_lane_s32(reg, lane)       neon_dupe32(reg, lane)
#define vdup_lane_s64(Dn, lane)        ( __static_assert(lane == 0, "invalid lane index"), neon_dups64(Dn, lane))
#define vdup_lane_s8(reg, lane)        neon_dupe8(reg, lane)
#define vdup_lane_u16(reg, lane)       neon_dupe16(reg, lane)
#define vdup_lane_u32(reg, lane)       neon_dupe32(reg, lane)
#define vdup_lane_u64(Dn, lane)        ( __static_assert(lane == 0, "invalid lane index"), neon_dups64(Dn, lane))
#define vdup_lane_u8(reg, lane)        neon_dupe8(reg, lane)
#define vdupq_lane_f32(reg, lane)      neon_dupqe32(reg, lane)
#define vdupq_lane_p16(reg, lane)      neon_dupqe16(reg, lane)
#define vdupq_lane_p8(reg, lane)       neon_dupqe8(reg, lane)
#define vdupq_lane_s16(reg, lane)      neon_dupqe16(reg, lane)
#define vdupq_lane_s32(reg, lane)      neon_dupqe32(reg, lane)
#define vdupq_lane_s64(reg, lane)      neon_dupqe64(reg, lane)
#define vdupq_lane_s8(reg, lane)       neon_dupqe8(reg, lane)
#define vdupq_lane_u16(reg, lane)      neon_dupqe16(reg, lane)
#define vdupq_lane_u32(reg, lane)      neon_dupqe32(reg, lane)
#define vdupq_lane_u64(reg, lane)      neon_dupqe64(reg, lane)
#define vdupq_lane_u8(reg, lane)       neon_dupqe8(reg, lane)

// DUP - scalar  (vector element into scalar)
__n8   neon_dups8 (__n64, const __int32);
__n16  neon_dups16(__n64, const __int32);
float  neon_dups32(__n64, const __int32);
__n64  neon_dups64(__n64, const __int32);
__n8   neon_dups8q (__n128, const __int32);
__n16  neon_dups16q(__n128, const __int32);
float  neon_dups32q(__n128, const __int32);
__n64  neon_dups64q(__n128, const __int32);
#define movs8(reg, lane)   neon_dups8(reg, lane)
#define movs16(reg, lane)  neon_dups16(reg, lane)
#define movs32(reg, lane)  neon_dups32(reg, lane)
#define movs64(reg, lane)  neon_dups64(reg, lane)
#define movs8q(reg, lane)  neon_dupq8q(reg, lane)
#define movs16q(reg, lane) neon_dupq16q(reg, lane)
#define movs32q(reg, lane) neon_dups32q(reg, lane)
#define movs64q(reg, lane) neon_dups64q(reg, lane)
#define vget_lane_f32(Dm, lane)     neon_dups32(Dm, lane)
#define vgetq_lane_f32(Dm, lane)    neon_dups32q(Dm, lane)

// FMOV - to/from general, top half of 128 bits
// The only two forms are these:
//  FMOV <Vd>.D[1], <Xn>
//  FMOV <Xd>, <Vn>.D[1]
__n128 fmov_top_half_core(__n128, __int64);
__int64 fmov_core_top_half(__n128);

// FMOV - immediate
__n64  neon_fmovi2s(const float);
__n128 neon_fmovi4s(const float);
__n128 neon_fmovi2d(const float);

// MOVI, MVNI
__n64 neon_movidw(const __int64);          // bytemask one doubleword
__n128 neon_moviqdw(const __int64);        // bytemask per doubleword
__n64 neon_movib(const int);               // per byte
__n128 neon_moviqb(const int);             // per byte
__n64 neon_movi_shift1w(const int, const int);   // shift ones per word
__n128 neon_moviq_shift1w(const int, const int); // shift ones per word
__n64 neon_movih(const int);               // per halfword
__n128 neon_moviqh(const int);             // per halfword
__n64 neon_movi_shift0h(const int, const int);   // shift zeroes per halfword
__n128 neon_moviq_shift0h(const int, const int); // shift zeroes per halfword
__n64 neon_moviw(const int);               // per word
__n128 neon_moviqw(const int);             // per word
__n64 neon_movi_shift0w(const int, const int);   // shift zeroes per word
__n128 neon_moviq_shift0w(const int, const int); // shift zeroes per word
__n64 neon_mvni_shift1w(const int, const int);   // shift ones per word
__n128 neon_mvniq_shift1w(const int, const int); // shift ones per word
__n64 neon_mvnih(const int);               // per halfword
__n128 neon_mvniqh(const int);             // per halfword
__n64 neon_mvni_shift0h(const int, const int);   // shift zeroes per halfword
__n128 neon_mvniq_shift0h(const int, const int); // shift zeroes per halfword
__n64 neon_mvniw(const int);               // per word
__n128 neon_mvniqw(const int);             // per word
__n64 neon_mvni_shift0w(const int, const int);   // shift zeroes per word
__n128 neon_mvniq_shift0w(const int, const int); // shift zeroes per word

// SMOV/UMOV - (move scalar into core)
__int8  neon_smov8   (__n64, const __int32);
__int8  neon_smovq8  (__n128, const __int32);
__int64 neon_smov64_8   (__n64, const __int32);
__int64 neon_smov64_q8  (__n128, const __int32);
__int16 neon_smov16  (__n64, const __int32);
__int16 neon_smovq16 (__n128, const __int32);
__int64 neon_smov64_16  (__n64, const __int32);
__int64 neon_smov64_q16 (__n128, const __int32);
__int64 neon_smov64_32  (__n64, const __int32);
__int64 neon_smov64_q32 (__n128, const __int32);
unsigned __int8  neon_umov8   (__n64, const __int32);
unsigned __int8  neon_umovq8  (__n128, const __int32);
unsigned __int16 neon_umov16  (__n64, const __int32);
unsigned __int16 neon_umovq16 (__n128, const __int32);
unsigned __int32 neon_umov32  (__n64, const __int32);
unsigned __int32 neon_umovq32 (__n128, const __int32);
unsigned __int64 neon_umov64  (__n64, const __int32);
unsigned __int64 neon_umovq64 (__n128, const __int32);
#define vget_lane_p8(Dm, lane)   neon_smov8(Dm, lane)
#define vget_lane_s8(Dm, lane)   neon_smov8(Dm, lane)
#define vget_lane_u8(Dm, lane)   neon_umov8(Dm, lane)
#define vget_lane_p16(Dm, lane)  neon_smov16(Dm, lane)
#define vget_lane_s16(Dm, lane)  neon_smov16(Dm, lane)
#define vget_lane_u16(Dm, lane)  neon_umov16(Dm, lane)
#define vget_lane_s32(Dm, lane)  neon_umov32(Dm, lane)  // there's no smov32 into 32bit core reg (only into 64bit core reg)
                                                        // umov32 is equivalent though because src/dst type size is the same
#define vget_lane_s64(Dm, lane)  neon_umov64(Dm, lane)  // there's no smov64, umov64 is equivalent though because src/dst type size is the same
#define vget_lane_u32(Dm, lane)  neon_umov32(Dm, lane)
#define vget_lane_u64(Dm, lane)  neon_umov64(Dm, lane)
#define vgetq_lane_p8(Dm, lane)  neon_smovq8(Dm, lane)
#define vgetq_lane_s8(Dm, lane)  neon_smovq8(Dm, lane)
#define vgetq_lane_u8(Dm, lane)  neon_umovq8(Dm, lane)
#define vgetq_lane_p16(Dm, lane) neon_smovq16(Dm, lane)
#define vgetq_lane_s16(Dm, lane) neon_smovq16(Dm, lane)
#define vgetq_lane_u16(Dm, lane) neon_umovq16(Dm, lane)
#define vgetq_lane_s32(Dm, lane) neon_umovq32(Dm, lane)  // there's no smov32 into 32bit core reg (only into 64bit core reg)
                                                         // umov32 is equivalent though because src/dst type size is the same
#define vgetq_lane_s64(Dm, lane) neon_umovq64(Dm, lane)  // there's no smov64, umov64 is equivalent though because src/dst type size is the same
#define vgetq_lane_u32(Dm, lane) neon_umovq32(Dm, lane)
#define vgetq_lane_u64(Dm, lane) neon_umovq64(Dm, lane)

// INS register
__n64  neon_insr8   (__n64, const __int32, __int32);
__n64  neon_insr16  (__n64, const __int32, __int32);
__n64  neon_insr32  (__n64, const __int32, __int32);
__n64  neon_insr64  (__n64, const __int32, __int64);
__n64  neon_insrf32 (__n64, const __int32, float);
__n64  neon_insrf64 (__n64, const __int32, double);
__n128 neon_insqr8  (__n128, const __int32, __int32);
__n128 neon_insqr16 (__n128, const __int32, __int32);
__n128 neon_insqr32 (__n128, const __int32, __int32);
__n128 neon_insqr64 (__n128, const __int32, __int64);
__n128 neon_insqrf32(__n128, const __int32, float);
__n128 neon_insqrf64(__n128, const __int32, double);
#define movr8(opeqneonreg, lane, corereg)    neon_insr8(opeqneonreg, lane, corereg)
#define movr16(opeqneonreg, lane, corereg)   neon_insr16(opeqneonreg, lane, corereg)
#define movr32(opeqneonreg, lane, corereg)   neon_insr32(opeqneonreg, lane, corereg)
#define movr64(opeqneonreg, lane, corereg)   neon_insr64(opeqneonreg, lane, corereg)
#define movrf32(opeqneonreg, lane, corereg)  neon_insrf32(opeqneonreg, lane, corereg)
#define movrf64(opeqneonreg, lane, corereg)  neon_insrf64(opeqneonreg, lane, corereg)
#define movqr8(opeqneonreg, lane, corereg)   neon_insqr8(opeqneonreg, lane, corereg)
#define movqr16(opeqneonreg, lane, corereg)  neon_insqr16(opeqneonreg, lane, corereg)
#define movqr32(opeqneonreg, lane, corereg)  neon_insqr32(opeqneonreg, lane, corereg)
#define movqr64(opeqneonreg, lane, corereg)  neon_insqr64(opeqneonreg, lane, corereg)
#define movqrf32(opeqneonreg, lane, corereg) neon_insqrf32(opeqneonreg, lane, corereg)
#define movqrf64(opeqneonreg, lane, corereg) neon_insqrf64(opeqneonreg, lane, corereg)
#define vset_lane_f32(corereg, opeqneonreg, lane)  neon_insrf32(opeqneonreg, lane, corereg)
#define vset_lane_f64(corereg, opeqneonreg, lane)  neon_insrf64(opeqneonreg, lane, corereg)
#define vset_lane_p16(corereg, opeqneonreg, lane)  neon_insr16(opeqneonreg, lane, corereg)
#define vset_lane_p8(corereg, opeqneonreg, lane)   neon_insr8(opeqneonreg, lane, corereg)
#define vset_lane_s16(corereg, opeqneonreg, lane)  neon_insr16(opeqneonreg, lane, corereg)
#define vset_lane_s32(corereg, opeqneonreg, lane)  neon_insr32(opeqneonreg, lane, corereg)
#define vset_lane_s64(corereg, opeqneonreg, lane)  neon_insr64(opeqneonreg, lane, corereg)
#define vset_lane_s8(corereg, opeqneonreg, lane)   neon_insr8(opeqneonreg, lane, corereg)
#define vset_lane_u16(corereg, opeqneonreg, lane)  neon_insr16(opeqneonreg, lane, corereg)
#define vset_lane_u32(corereg, opeqneonreg, lane)  neon_insr32(opeqneonreg, lane, corereg)
#define vset_lane_u64(corereg, opeqneonreg, lane)  neon_insr64(opeqneonreg, lane, corereg)
#define vset_lane_u8(corereg, opeqneonreg, lane)   neon_insr8(opeqneonreg, lane, corereg)
#define vsetq_lane_f32(corereg, opeqneonreg, lane) neon_insqrf32(opeqneonreg, lane, corereg)
#define vsetq_lane_f64(corereg, opeqneonreg, lane) neon_insqrf64(opeqneonreg, lane, corereg)
#define vsetq_lane_p16(corereg, opeqneonreg, lane) neon_insqr16(opeqneonreg, lane, corereg)
#define vsetq_lane_p8(corereg, opeqneonreg, lane)  neon_insqr8(opeqneonreg, lane, corereg)
#define vsetq_lane_s16(corereg, opeqneonreg, lane) neon_insqr16(opeqneonreg, lane, corereg)
#define vsetq_lane_s32(corereg, opeqneonreg, lane) neon_insqr32(opeqneonreg, lane, corereg)
#define vsetq_lane_s64(corereg, opeqneonreg, lane) neon_insqr64(opeqneonreg, lane, corereg)
#define vsetq_lane_s8(corereg, opeqneonreg, lane)  neon_insqr8(opeqneonreg, lane, corereg)
#define vsetq_lane_u16(corereg, opeqneonreg, lane) neon_insqr16(opeqneonreg, lane, corereg)
#define vsetq_lane_u32(corereg, opeqneonreg, lane) neon_insqr32(opeqneonreg, lane, corereg)
#define vsetq_lane_u64(corereg, opeqneonreg, lane) neon_insqr64(opeqneonreg, lane, corereg)
#define vsetq_lane_u8(corereg, opeqneonreg, lane)  neon_insqr8(opeqneonreg, lane, corereg)

// INS element
__n64  neon_inse8    (__n64, const __int32, __n64, const __int32);
__n128 neon_insqe8q  (__n128, const __int32, __n128, const __int32);
__n64  neon_inse16   (__n64, const __int32, __n64, const __int32);
__n128 neon_insqe16q (__n128, const __int32, __n128, const __int32);
__n64  neon_inse32   (__n64, const __int32, __n64, const __int32);
__n128 neon_insqe32q (__n128, const __int32, __n128, const __int32);
__n64  neon_inse64   (__n64, const __int32, __n64, const __int32);
__n128 neon_insqe64q (__n128, const __int32, __n128, const __int32);
#define move8(opeqneonreg, laneDst, neonSrc, laneSrc)    neon_inse8(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe8(opeqneonreg, laneDst, neonSrc, laneSrc)   neon_insqe8(opeqneoneg, laneDst, neonSrc, laneSrc)
#define move8q(opeqneonreg, laneDst, neonSrc, laneSrc)   neon_inse8q(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe8q(opeqneonreg, laneDst, neonSrc, laneSrc)  neon_insqe8q(opeqneoneg, laneDst, neonSrc, laneSrc)
#define move16(opeqneonreg, laneDst, neonSrc, laneSrc)   neon_inse16(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe16(opeqneonreg, laneDst, neonSrc, laneSrc)  neon_insqe16(opeqneoneg, laneDst, neonSrc, laneSrc)
#define move16q(opeqneonreg, laneDst, neonSrc, laneSrc)  neon_inse16q(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe16q(opeqneonreg, laneDst, neonSrc, laneSrc) neon_insqe16q(opeqneoneg, laneDst, neonSrc, laneSrc)
#define move32(opeqneonreg, laneDst, neonSrc, laneSrc)   neon_inse32(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe32(opeqneonreg, laneDst, neonSrc, laneSrc)  neon_insqe32(opeqneoneg, laneDst, neonSrc, laneSrc)
#define move32q(opeqneonreg, laneDst, neonSrc, laneSrc)  neon_inse32q(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe32q(opeqneonreg, laneDst, neonSrc, laneSrc) neon_insqe32q(opeqneoneg, laneDst, neonSrc, laneSrc)
#define move64(opeqneonreg, laneDst, neonSrc, laneSrc)   neon_inse64(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe64(opeqneonreg, laneDst, neonSrc, laneSrc)  neon_insqe64(opeqneoneg, laneDst, neonSrc, laneSrc)
#define move64q(opeqneonreg, laneDst, neonSrc, laneSrc)  neon_inse64q(opeqneoneg, laneDst, neonSrc, laneSrc)
#define movqe64q(opeqneonreg, laneDst, neonSrc, laneSrc) neon_insqe64q(opeqneoneg, laneDst, neonSrc, laneSrc)

// NOT, MVN
__n64  neon_not  (__n64);
__n128 neon_notq (__n128);
#define mvn(src) neon_not(src)
#define mvnq(src) neon_notq(src)
#define vmvn_p16(reg)  neon_not(reg)
#define vmvn_p8(reg)   neon_not(reg)
#define vmvn_s16(reg)  neon_not(reg)
#define vmvn_s32(reg)  neon_not(reg)
#define vmvn_s8(reg)   neon_not(reg)
#define vmvn_u16(reg)  neon_not(reg)
#define vmvn_u32(reg)  neon_not(reg)
#define vmvn_u8(reg)   neon_not(reg)
#define vmvnq_p16(reg) neon_notq(reg)
#define vmvnq_p8(reg)  neon_notq(reg)
#define vmvnq_s16(reg) neon_notq(reg)
#define vmvnq_s32(reg) neon_notq(reg)
#define vmvnq_s8(reg)  neon_notq(reg)
#define vmvnq_u16(reg) neon_notq(reg)
#define vmvnq_u32(reg) neon_notq(reg)
#define vmvnq_u8(reg)  neon_notq(reg)

// FNEG/NEG/SQNEG
__n64 neon_fneg32(__n64);
__n128 neon_fnegq32(__n128);
__n128 neon_fnegq64(__n128);
__n64 neon_neg8(__n64);
__n128 neon_negq8(__n128);
__n64 neon_neg16(__n64);
__n128 neon_negq16(__n128);
__n64 neon_neg32(__n64);
__n128 neon_negq32(__n128);
__n128 neon_negq64(__n128);
__n64 neon_sqneg8(__n64);
__n128 neon_sqnegq8(__n128);
__n64 neon_sqneg16(__n64);
__n128 neon_sqnegq16(__n128);
__n64 neon_sqneg32(__n64);
__n128 neon_sqnegq32(__n128);
__n128 neon_sqnegq64(__n128);
__n8  neon_sqnegs8(__n8);
__n16 neon_sqnegs16(__n16);
float neon_sqnegs32(float);
__n64 neon_sqnegs64(__n64);
__n64 neon_negs64(__n64);
#define vneg_f32(reg) neon_fneg32(reg)
#define vnegq_f32(reg) neon_fnegq32(reg)
#define vneg_s8(reg) neon_neg8(reg)
#define vnegq_s8(reg) neon_negq8(reg)
#define vqneg_s8(reg) neon_sqneg8(reg)
#define vqnegq_s8(reg) neon_sqnegq8(reg)
#define vneg_s16(reg) neon_neg16(reg)
#define vnegq_s16(reg) neon_negq16(reg)
#define vqneg_s16(reg) neon_sqneg16(reg)
#define vqnegq_s16(reg) neon_sqnegq16(reg)
#define vneg_s32(reg) neon_neg32(reg)
#define vnegq_s32(reg) neon_negq32(reg)
#define vqneg_s32(reg) neon_sqneg32(reg)
#define vqnegq_s32(reg) neon_sqnegq32(reg)

// FABS/ABS/SQABS
__n64 neon_fabs32(__n64);
__n128 neon_fabsq32(__n128);
__n128 neon_fabsq64(__n128);
__n64 neon_abs8(__n64);
__n128 neon_absq8(__n128);
__n64 neon_abs16(__n64);
__n128 neon_absq16(__n128);
__n64 neon_abs32(__n64);
__n128 neon_absq32(__n128);
__n128 neon_absq64(__n128);
__n64 neon_sqabs8(__n64);
__n128 neon_sqabsq8(__n128);
__n64 neon_sqabs16(__n64);
__n128 neon_sqabsq16(__n128);
__n64 neon_sqabs32(__n64);
__n128 neon_sqabsq32(__n128);
__n128 neon_sqabsq64(__n128);
__n8  neon_sqabss8(__n8);
__n16 neon_sqabss16(__n16);
float neon_sqabss32(float);
__n64 neon_sqabss64(__n64);
__n64 neon_abss64(__n64);
#define vabs_f32(reg) neon_fabs32(reg)
#define vabsq_f32(reg) neon_fabsq32(reg)
#define vabs_s8(reg) neon_abs8(reg)
#define vabsq_s8(reg) neon_absq8(reg)
#define vqabs_s8(reg) neon_sqabs8(reg)
#define vqabsq_s8(reg) neon_sqabsq8(reg)
#define vabs_s16(reg) neon_abs16(reg)
#define vabsq_s16(reg) neon_absq16(reg)
#define vqabs_s16(reg) neon_sqabs16(reg)
#define vqabsq_s16(reg) neon_sqabsq16(reg)
#define vabs_s32(reg) neon_abs32(reg)
#define vabsq_s32(reg) neon_absq32(reg)
#define vqabs_s32(reg) neon_sqabs32(reg)
#define vqabsq_s32(reg) neon_sqabsq32(reg)

// ADD, FADD, SQADD, UQADD, SUQADD, USQADD
__n64  neon_fadd32(__n64, __n64);
__n128 neon_faddq32(__n128, __n128);
__n128 neon_faddq64(__n128, __n128);
__n64  neon_add8(__n64, __n64);
__n128 neon_addq8(__n128, __n128);
__n64  neon_add16(__n64, __n64);
__n128 neon_addq16(__n128, __n128);
__n64  neon_add32(__n64, __n64);
__n128 neon_addq32(__n128, __n128);
__n128 neon_addq64(__n128, __n128);
__n64  neon_sqadd8(__n64, __n64);
__n128 neon_sqaddq8(__n128, __n128);
__n64  neon_sqadd16(__n64, __n64);
__n128 neon_sqaddq16(__n128, __n128);
__n64  neon_sqadd32(__n64, __n64);
__n128 neon_sqaddq32(__n128, __n128);
__n128 neon_sqaddq64(__n128, __n128);
__n64  neon_uqadd8(__n64, __n64);
__n128 neon_uqaddq8(__n128, __n128);
__n64  neon_uqadd16(__n64, __n64);
__n128 neon_uqaddq16(__n128, __n128);
__n64  neon_uqadd32(__n64, __n64);
__n128 neon_uqaddq32(__n128, __n128);
__n128 neon_uqaddq64(__n128, __n128);
__n64  neon_suqadd8(__n64, __n64);
__n128 neon_suqaddq8(__n128, __n128);
__n64  neon_suqadd16(__n64, __n64);
__n128 neon_suqaddq16(__n128, __n128);
__n64  neon_suqadd32(__n64, __n64);
__n128 neon_suqaddq32(__n128, __n128);
__n128 neon_suqaddq64(__n128, __n128);
__n64  neon_usqadd8(__n64, __n64);
__n128 neon_usqaddq8(__n128, __n128);
__n64  neon_usqadd16(__n64, __n64);
__n128 neon_usqaddq16(__n128, __n128);
__n64  neon_usqadd32(__n64, __n64);
__n128 neon_usqaddq32(__n128, __n128);
__n128 neon_usqaddq64(__n128, __n128);
__n64 neon_adds64(__n64, __n64);
__n64 neon_sqadds64(__n64, __n64);
float neon_sqadds32(float, float);
__n16 neon_sqadds16(__n16, __n16);
__n8  neon_sqadds8(__n8, __n8);
__n64 neon_uqadds64(__n64, __n64);
float neon_uqadds32(float, float);
__n16 neon_uqadds16(__n16, __n16);
__n8  neon_uqadds8(__n8, __n8);
__n8  neon_suqadds8(__n8, __n8);
__n16 neon_suqadds16(__n16, __n16);
float neon_suqadds32(float, float);
__n64 neon_suqadds64(__n64, __n64);
__n8  neon_usqadds8(__n8, __n8);
__n16 neon_usqadds16(__n16, __n16);
float neon_usqadds32(float, float);
__n64 neon_usqadds64(__n64, __n64);
#define vadd_s8(src1, src2)    neon_add8(src1, src2)
#define vadd_u8(src1, src2)    neon_add8(src1, src2)
#define vadd_s16(src1, src2)   neon_add16(src1, src2)
#define vadd_u16(src1, src2)   neon_add16(src1, src2)
#define vadd_s32(src1, src2)   neon_add32(src1, src2)
#define vadd_u32(src1, src2)   neon_add32(src1, src2)
#define vadd_f32(src1, src2)   neon_fadd32(src1, src2)
#define vadd_s64(src1, src2)   neon_adds64(src1, src2)
#define vadd_u64(src1, src2)   neon_adds64(src1, src2)
#define vaddq_s8(src1, src2)   neon_addq8(src1, src2)
#define vaddq_u8(src1, src2)   neon_addq8(src1, src2)
#define vaddq_s16(src1, src2)  neon_addq16(src1, src2)
#define vaddq_u16(src1, src2)  neon_addq16(src1, src2)
#define vaddq_s32(src1, src2)  neon_addq32(src1, src2)
#define vaddq_u32(src1, src2)  neon_addq32(src1, src2)
#define vaddq_f32(src1, src2)  neon_faddq32(src1, src2)
#define vaddq_s64(src1, src2)  neon_addq64(src1, src2)
#define vaddq_u64(src1, src2)  neon_addq64(src1, src2)
#define vqadd_s8(src1, src2)   neon_sqadd8(src1, src2)
#define vqadd_u8(src1, src2)   neon_uqadd8(src1, src2)
#define vqadd_s16(src1, src2)  neon_sqadd16(src1, src2)
#define vqadd_u16(src1, src2)  neon_uqadd16(src1, src2)
#define vqadd_s32(src1, src2)  neon_sqadd32(src1, src2)
#define vqadd_u32(src1, src2)  neon_uqadd32(src1, src2)
#define vqadd_s64(src1, src2)  neon_sqadds64(src1, src2)
#define vqadd_u64(src1, src2)  neon_uqadds64(src1, src2)
#define vqaddq_s8(src1, src2)  neon_sqaddq8(src1, src2)
#define vqaddq_u8(src1, src2)  neon_uqaddq8(src1, src2)
#define vqaddq_s16(src1, src2) neon_sqaddq16(src1, src2)
#define vqaddq_u16(src1, src2) neon_uqaddq16(src1, src2)
#define vqaddq_s32(src1, src2) neon_sqaddq32(src1, src2)
#define vqaddq_u32(src1, src2) neon_uqaddq32(src1, src2)
#define vqaddq_s64(src1, src2) neon_sqaddq64(src1, src2)
#define vqaddq_u64(src1, src2) neon_uqaddq64(src1, src2)

// SUB, FSUB, SQSUB, UQSUB
__n64  neon_fsub32(__n64, __n64);
__n128 neon_fsubq32(__n128, __n128);
__n128 neon_fsubq64(__n128, __n128);
__n64  neon_sub8(__n64, __n64);
__n128 neon_subq8(__n128, __n128);
__n64  neon_sub16(__n64, __n64);
__n128 neon_subq16(__n128, __n128);
__n64  neon_sub32(__n64, __n64);
__n128 neon_subq32(__n128, __n128);
__n128 neon_subq64(__n128, __n128);
__n64  neon_sqsub8(__n64, __n64);
__n128 neon_sqsubq8(__n128, __n128);
__n64  neon_sqsub16(__n64, __n64);
__n128 neon_sqsubq16(__n128, __n128);
__n64  neon_sqsub32(__n64, __n64);
__n128 neon_sqsubq32(__n128, __n128);
__n128 neon_sqsubq64(__n128, __n128);
__n64  neon_uqsub8(__n64, __n64);
__n128 neon_uqsubq8(__n128, __n128);
__n64  neon_uqsub16(__n64, __n64);
__n128 neon_uqsubq16(__n128, __n128);
__n64  neon_uqsub32(__n64, __n64);
__n128 neon_uqsubq32(__n128, __n128);
__n128 neon_uqsubq64(__n128, __n128);
__n64 neon_subs64(__n64, __n64);
__n64 neon_sqsubs64(__n64, __n64);
float neon_sqsubs32(float, float);
__n16 neon_sqsubs16(__n16, __n16);
__n8  neon_sqsubs8(__n8, __n8);
__n64 neon_uqsubs64(__n64, __n64);
float neon_uqsubs32(float, float);
__n16 neon_uqsubs16(__n16, __n16);
__n8  neon_uqsubs8(__n8, __n8);
#define vsub_s8(src1, src2)    neon_sub8(src1, src2)
#define vsub_u8(src1, src2)    neon_sub8(src1, src2)
#define vsub_s16(src1, src2)   neon_sub16(src1, src2)
#define vsub_u16(src1, src2)   neon_sub16(src1, src2)
#define vsub_s32(src1, src2)   neon_sub32(src1, src2)
#define vsub_u32(src1, src2)   neon_sub32(src1, src2)
#define vsub_f32(src1, src2)   neon_fsub32(src1, src2)
#define vsub_s64(src1, src2)   neon_subs64(src1, src2)
#define vsub_u64(src1, src2)   neon_subs64(src1, src2)
#define vsubq_s8(src1, src2)   neon_subq8(src1, src2)
#define vsubq_u8(src1, src2)   neon_subq8(src1, src2)
#define vsubq_s16(src1, src2)  neon_subq16(src1, src2)
#define vsubq_u16(src1, src2)  neon_subq16(src1, src2)
#define vsubq_s32(src1, src2)  neon_subq32(src1, src2)
#define vsubq_u32(src1, src2)  neon_subq32(src1, src2)
#define vsubq_f32(src1, src2)  neon_fsubq32(src1, src2)
#define vsubq_s64(src1, src2)  neon_subq64(src1, src2)
#define vsubq_u64(src1, src2)  neon_subq64(src1, src2)
#define vqsub_s8(src1, src2)   neon_sqsub8(src1, src2)
#define vqsub_u8(src1, src2)   neon_uqsub8(src1, src2)
#define vqsub_s16(src1, src2)  neon_sqsub16(src1, src2)
#define vqsub_u16(src1, src2)  neon_uqsub16(src1, src2)
#define vqsub_s32(src1, src2)  neon_sqsub32(src1, src2)
#define vqsub_u32(src1, src2)  neon_uqsub32(src1, src2)
#define vqsub_s64(src1, src2)  neon_sqsubs64(src1, src2)
#define vqsub_u64(src1, src2)  neon_uqsubs64(src1, src2)
#define vqsubq_s8(src1, src2)  neon_sqsubq8(src1, src2)
#define vqsubq_u8(src1, src2)  neon_uqsubq8(src1, src2)
#define vqsubq_s16(src1, src2) neon_sqsubq16(src1, src2)
#define vqsubq_u16(src1, src2) neon_uqsubq16(src1, src2)
#define vqsubq_s32(src1, src2) neon_sqsubq32(src1, src2)
#define vqsubq_u32(src1, src2) neon_uqsubq32(src1, src2)
#define vqsubq_s64(src1, src2) neon_sqsubq64(src1, src2)
#define vqsubq_u64(src1, src2) neon_uqsubq64(src1, src2)

// SH(R)ADD, UH(R)ADD and SUB
__n64  neon_shadd8(__n64, __n64);
__n64  neon_shadd16(__n64, __n64);
__n64  neon_shadd32(__n64, __n64);
__n128 neon_shaddq8(__n128, __n128);
__n128 neon_shaddq16(__n128, __n128);
__n128 neon_shaddq32(__n128, __n128);
__n64  neon_srhadd8(__n64, __n64);
__n64  neon_srhadd16(__n64, __n64);
__n64  neon_srhadd32(__n64, __n64);
__n128 neon_srhaddq8(__n128, __n128);
__n128 neon_srhaddq16(__n128, __n128);
__n128 neon_srhaddq32(__n128, __n128);
__n64  neon_uhadd8(__n64, __n64);
__n64  neon_uhadd16(__n64, __n64);
__n64  neon_uhadd32(__n64, __n64);
__n128 neon_uhaddq8(__n128, __n128);
__n128 neon_uhaddq16(__n128, __n128);
__n128 neon_uhaddq32(__n128, __n128);
__n64  neon_urhadd8(__n64, __n64);
__n64  neon_urhadd16(__n64, __n64);
__n64  neon_urhadd32(__n64, __n64);
__n128 neon_urhaddq8(__n128, __n128);
__n128 neon_urhaddq16(__n128, __n128);
__n128 neon_urhaddq32(__n128, __n128);
__n64  neon_shsub8(__n64, __n64);
__n64  neon_shsub16(__n64, __n64);
__n64  neon_shsub32(__n64, __n64);
__n128 neon_shsubq8(__n128, __n128);
__n128 neon_shsubq16(__n128, __n128);
__n128 neon_shsubq32(__n128, __n128);
__n64  neon_uhsub8(__n64, __n64);
__n64  neon_uhsub16(__n64, __n64);
__n64  neon_uhsub32(__n64, __n64);
__n128 neon_uhsubq8(__n128, __n128);
__n128 neon_uhsubq16(__n128, __n128);
__n128 neon_uhsubq32(__n128, __n128);
#define vhadd_s8(src1, src2)    neon_shadd8(src1, src2)
#define vhadd_s16(src1, src2)   neon_shadd16(src1, src2)
#define vhadd_s32(src1, src2)   neon_shadd32(src1, src2)
#define vhaddq_s8(src1, src2)   neon_shaddq8(src1, src2)
#define vhaddq_s16(src1, src2)  neon_shaddq16(src1, src2)
#define vhaddq_s32(src1, src2)  neon_shaddq32(src1, src2)
#define vrhadd_s8(src1, src2)   neon_srhadd8(src1, src2)
#define vrhadd_s16(src1, src2)  neon_srhadd16(src1, src2)
#define vrhadd_s32(src1, src2)  neon_srhadd32(src1, src2)
#define vrhaddq_s8(src1, src2)  neon_srhaddq8(src1, src2)
#define vrhaddq_s16(src1, src2) neon_srhaddq16(src1, src2)
#define vrhaddq_s32(src1, src2) neon_srhaddq32(src1, src2)
#define vhadd_u8(src1, src2)    neon_uhadd8(src1, src2)
#define vhadd_u16(src1, src2)   neon_uhadd16(src1, src2)
#define vhadd_u32(src1, src2)   neon_uhadd32(src1, src2)
#define vhaddq_u8(src1, src2)   neon_uhaddq8(src1, src2)
#define vhaddq_u16(src1, src2)  neon_uhaddq16(src1, src2)
#define vhaddq_u32(src1, src2)  neon_uhaddq32(src1, src2)
#define vrhadd_u8(src1, src2)   neon_urhadd8(src1, src2)
#define vrhadd_u16(src1, src2)  neon_urhadd16(src1, src2)
#define vrhadd_u32(src1, src2)  neon_urhadd32(src1, src2)
#define vrhaddq_u8(src1, src2)  neon_urhaddq8(src1, src2)
#define vrhaddq_u16(src1, src2) neon_urhaddq16(src1, src2)
#define vrhaddq_u32(src1, src2) neon_urhaddq32(src1, src2)
#define vhsub_s8(src1, src2)    neon_shsub8(src1, src2)
#define vhsub_s16(src1, src2)   neon_shsub16(src1, src2)
#define vhsub_s32(src1, src2)   neon_shsub32(src1, src2)
#define vhsubq_s8(src1, src2)   neon_shsubq8(src1, src2)
#define vhsubq_s16(src1, src2)  neon_shsubq16(src1, src2)
#define vhsubq_s32(src1, src2)  neon_shsubq32(src1, src2)
#define vhsub_u8(src1, src2)    neon_uhsub8(src1, src2)
#define vhsub_u16(src1, src2)   neon_uhsub16(src1, src2)
#define vhsub_u32(src1, src2)   neon_uhsub32(src1, src2)
#define vhsubq_u8(src1, src2)   neon_uhsubq8(src1, src2)
#define vhsubq_u16(src1, src2)  neon_uhsubq16(src1, src2)
#define vhsubq_u32(src1, src2)  neon_uhsubq32(src1, src2)

// ADDP/FADDP
__n64  neon_addp8  (__n64, __n64);
__n64  neon_addp16 (__n64, __n64);
__n64  neon_addp32 (__n64, __n64);
__n64  neon_addps64(__n64);
__n128 neon_addpq8 (__n128, __n128);
__n128 neon_addpq16(__n128, __n128);
__n128 neon_addpq32(__n128, __n128);
__n128 neon_addpq64(__n128, __n128);
__n64  neon_faddp32(__n64, __n64);
float  neon_faddps32(__n64);
__n128 neon_faddpq32 (__n128, __n128);
__n128 neon_faddpq64 (__n128, __n128);
__n64 neon_faddpsq64(__n128);
#define vpadd_s8(src1, src2)  neon_addp8(src1, src2)
#define vpadd_u8(src1, src2)  neon_addp8(src1, src2)
#define vpadd_s16(src1, src2) neon_addp16(src1, src2)
#define vpadd_u16(src1, src2) neon_addp16(src1, src2)
#define vpadd_s32(src1, src2) neon_addp32(src1, src2)
#define vpadd_u32(src1, src2) neon_addp32(src1, src2)
#define vpadd_f32(src1, src2) neon_faddp32(src1, src2)
#define vpaddq_f32(src1, src2) neon_faddpq32(src1, src2)

// ADDV/SADDLV/UADDLV
__n8  neon_addv8(__n64);
__n8  neon_addvq8(__n128);
__n16 neon_addv16(__n64);
__n16 neon_addvq16(__n128);
float neon_addvq32(__n128);
__n16 neon_saddlv8(__n64);
__n16 neon_saddlvq8(__n128);
float neon_saddlv16(__n64);
float neon_saddlvq16(__n128);
__n64 neon_saddlvq32(__n128);
__n16 neon_uaddlv8(__n64);
__n16 neon_uaddlvq8(__n128);
float neon_uaddlv16(__n64);
float neon_uaddlvq16(__n128);
__n64 neon_uaddlvq32(__n128);

// SADALP/UADALP/SADDLP/UADDLP
__n64 neon_saddlp8(__n64);
__n128 neon_saddlpq8(__n128);
__n64 neon_saddlp16(__n64);
__n128 neon_saddlpq16(__n128);
__n64 neon_saddlp32(__n64);
__n128 neon_saddlpq32(__n128);
__n64 neon_uaddlp8(__n64);
__n128 neon_uaddlpq8(__n128);
__n64 neon_uaddlp16(__n64);
__n128 neon_uaddlpq16(__n128);
__n64 neon_uaddlp32(__n64);
__n128 neon_uaddlpq32(__n128);
__n64 neon_sadalp8(__n64, __n64);
__n128 neon_sadalpq8(__n128, __n128);
__n64 neon_sadalp16(__n64, __n64);
__n128 neon_sadalpq16(__n128, __n128);
__n64 neon_sadalp32(__n64, __n64);
__n128 neon_sadalpq32(__n128, __n128);
__n64 neon_uadalp8(__n64, __n64);
__n128 neon_uadalpq8(__n128, __n128);
__n64 neon_uadalp16(__n64, __n64);
__n128 neon_uadalpq16(__n128, __n128);
__n64 neon_uadalp32(__n64, __n64);
__n128 neon_uadalpq32(__n128, __n128);
#define vpaddl_s8(src)          neon_saddlp8(src)
#define vpaddlq_s8(src)         neon_saddlpq8(src)
#define vpaddl_s16(src)         neon_saddlp16(src)
#define vpaddlq_s16(src)        neon_saddlpq16(src)
#define vpaddl_s32(src)         neon_saddlp32(src)
#define vpaddlq_s32(src)        neon_saddlpq32(src)
#define vpaddl_u8(src)          neon_uaddlp8(src)
#define vpaddlq_u8(src)         neon_uaddlpq8(src)
#define vpaddl_u16(src)         neon_uaddlp16(src)
#define vpaddlq_u16(src)        neon_uaddlpq16(src)
#define vpaddl_u32(src)         neon_uaddlp32(src)
#define vpaddlq_u32(src)        neon_uaddlpq32(src)
#define vpadal_s8(src1, src2)   neon_sadalp8(src1, src2)  
#define vpadalq_s8(src1, src2)  neon_sadalpq8(src1, src2) 
#define vpadal_s16(src1, src2)  neon_sadalp16(src1, src2) 
#define vpadalq_s16(src1, src2) neon_sadalpq16(src1, src2)
#define vpadal_s32(src1, src2)  neon_sadalp32(src1, src2) 
#define vpadalq_s32(src1, src2) neon_sadalpq32(src1, src2)
#define vpadal_u8(src1, src2)   neon_uadalp8(src1, src2)  
#define vpadalq_u8(src1, src2)  neon_uadalpq8(src1, src2) 
#define vpadal_u16(src1, src2)  neon_uadalp16(src1, src2) 
#define vpadalq_u16(src1, src2) neon_uadalpq16(src1, src2)
#define vpadal_u32(src1, src2)  neon_uadalp32(src1, src2) 
#define vpadalq_u32(src1, src2) neon_uadalpq32(src1, src2)

// AESE/AESD/AESMC/AESIMC
__n128 neon_aese(__n128, __n128);
__n128 neon_aesd(__n128, __n128);
__n128 neon_aesmc(__n128);
__n128 neon_aesimc(__n128);
#define aese_p8(src1, src2)   neon_aese(src1, src2)
#define aese_s8(src1, src2)   neon_aese(src1, src2)
#define aese_u8(src1, src2)   neon_aese(src1, src2)
#define vaeseq_u8(src1, src2) neon_aese(src1, src2)
#define aesd_p8(src1, src2)   neon_aesd(src1, src2)
#define aesd_s8(src1, src2)   neon_aesd(src1, src2)
#define aesd_u8(src1, src2)   neon_aesd(src1, src2)
#define vaesdq_u8(src1, src2) neon_aesd(src1, src2)
#define aesmc_p8(src)  neon_aesmc(src)
#define aesmc_s8(src)  neon_aesmc(src)
#define aesmc_u8(src)  neon_aesmc(src)
#define vaesmcq_u8(src) neon_aesmc(src)
#define aesimc_p8(src) neon_aesimc(src)
#define aesimc_s8(src) neon_aesimc(src)
#define aesimc_u8(src) neon_aesimc(src)
#define vaesimcq_u8(src) neon_aesimc(src)

// AND/BIC/BIF/BIT/BSL/EOR/ORN/ORR
__n64  neon_and(__n64, __n64);
__n128 neon_andq(__n128, __n128);
__n64  neon_eor(__n64, __n64);
__n128 neon_eorq(__n128, __n128);
__n64  neon_orn(__n64, __n64);
__n128 neon_ornq(__n128, __n128);
__n64  neon_orr(__n64, __n64);
__n128 neon_orrq(__n128, __n128);
__n64  neon_bic(__n64, __n64);
__n128 neon_bicq(__n128, __n128);
__n64  neon_bif(__n64, __n64, __n64);
__n128 neon_bifq(__n128, __n128, __n128);
__n64  neon_bit(__n64, __n64, __n64);
__n128 neon_bitq(__n128, __n128, __n128);
__n64  neon_bsl(__n64, __n64, __n64);
__n128 neon_bslq(__n128, __n128, __n128);
#define vand_s8(src1, src2)   neon_and(src1, src2)
#define vand_u8(src1, src2)   neon_and(src1, src2)
#define vand_s16(src1, src2)  neon_and(src1, src2)
#define vand_u16(src1, src2)  neon_and(src1, src2)
#define vand_s32(src1, src2)  neon_and(src1, src2)
#define vand_u32(src1, src2)  neon_and(src1, src2)
#define vand_s64(src1, src2)  neon_and(src1, src2)
#define vand_u64(src1, src2)  neon_and(src1, src2)
#define vandq_s8(src1, src2)  neon_andq(src1, src2)
#define vandq_u8(src1, src2)  neon_andq(src1, src2)
#define vandq_s16(src1, src2) neon_andq(src1, src2)
#define vandq_u16(src1, src2) neon_andq(src1, src2)
#define vandq_s32(src1, src2) neon_andq(src1, src2)
#define vandq_u32(src1, src2) neon_andq(src1, src2)
#define vandq_s64(src1, src2) neon_andq(src1, src2)
#define vandq_u64(src1, src2) neon_andq(src1, src2)
#define veor_s8(src1, src2)   neon_eor(src1, src2)
#define veor_u8(src1, src2)   neon_eor(src1, src2)
#define veor_s16(src1, src2)  neon_eor(src1, src2)
#define veor_u16(src1, src2)  neon_eor(src1, src2)
#define veor_s32(src1, src2)  neon_eor(src1, src2)
#define veor_u32(src1, src2)  neon_eor(src1, src2)
#define veor_s64(src1, src2)  neon_eor(src1, src2)
#define veor_u64(src1, src2)  neon_eor(src1, src2)
#define veorq_s8(src1, src2)  neon_eorq(src1, src2)
#define veorq_u8(src1, src2)  neon_eorq(src1, src2)
#define veorq_s16(src1, src2) neon_eorq(src1, src2)
#define veorq_u16(src1, src2) neon_eorq(src1, src2)
#define veorq_s32(src1, src2) neon_eorq(src1, src2)
#define veorq_u32(src1, src2) neon_eorq(src1, src2)
#define veorq_s64(src1, src2) neon_eorq(src1, src2)
#define veorq_u64(src1, src2) neon_eorq(src1, src2)
#define vorr_s8(src1, src2)   neon_orr(src1, src2)
#define vorr_u8(src1, src2)   neon_orr(src1, src2)
#define vorr_s16(src1, src2)  neon_orr(src1, src2)
#define vorr_u16(src1, src2)  neon_orr(src1, src2)
#define vorr_s32(src1, src2)  neon_orr(src1, src2)
#define vorr_u32(src1, src2)  neon_orr(src1, src2)
#define vorr_s64(src1, src2)  neon_orr(src1, src2)
#define vorr_u64(src1, src2)  neon_orr(src1, src2)
#define vorrq_s8(src1, src2)  neon_orrq(src1, src2)
#define vorrq_u8(src1, src2)  neon_orrq(src1, src2)
#define vorrq_s16(src1, src2) neon_orrq(src1, src2)
#define vorrq_u16(src1, src2) neon_orrq(src1, src2)
#define vorrq_s32(src1, src2) neon_orrq(src1, src2)
#define vorrq_u32(src1, src2) neon_orrq(src1, src2)
#define vorrq_s64(src1, src2) neon_orrq(src1, src2)
#define vorrq_u64(src1, src2) neon_orrq(src1, src2)
#define vorn_s8(src1, src2)   neon_orn(src1, src2)
#define vorn_u8(src1, src2)   neon_orn(src1, src2)
#define vorn_s16(src1, src2)  neon_orn(src1, src2)
#define vorn_u16(src1, src2)  neon_orn(src1, src2)
#define vorn_s32(src1, src2)  neon_orn(src1, src2)
#define vorn_u32(src1, src2)  neon_orn(src1, src2)
#define vorn_s64(src1, src2)  neon_orn(src1, src2)
#define vorn_u64(src1, src2)  neon_orn(src1, src2)
#define vornq_s8(src1, src2)  neon_ornq(src1, src2)
#define vornq_u8(src1, src2)  neon_ornq(src1, src2)
#define vornq_s16(src1, src2) neon_ornq(src1, src2)
#define vornq_u16(src1, src2) neon_ornq(src1, src2)
#define vornq_s32(src1, src2) neon_ornq(src1, src2)
#define vornq_u32(src1, src2) neon_ornq(src1, src2)
#define vornq_s64(src1, src2) neon_ornq(src1, src2)
#define vornq_u64(src1, src2) neon_ornq(src1, src2)
#define vbic_s8(src1, src2)   neon_bic(src1, src2)
#define vbic_u8(src1, src2)   neon_bic(src1, src2)
#define vbic_s16(src1, src2)  neon_bic(src1, src2)
#define vbic_u16(src1, src2)  neon_bic(src1, src2)
#define vbic_s32(src1, src2)  neon_bic(src1, src2)
#define vbic_u32(src1, src2)  neon_bic(src1, src2)
#define vbic_s64(src1, src2)  neon_bic(src1, src2)
#define vbic_u64(src1, src2)  neon_bic(src1, src2)
#define vbicq_s8(src1, src2)  neon_bicq(src1, src2)
#define vbicq_u8(src1, src2)  neon_bicq(src1, src2)
#define vbicq_s16(src1, src2) neon_bicq(src1, src2)
#define vbicq_u16(src1, src2) neon_bicq(src1, src2)
#define vbicq_s32(src1, src2) neon_bicq(src1, src2)
#define vbicq_u32(src1, src2) neon_bicq(src1, src2)
#define vbicq_s64(src1, src2) neon_bicq(src1, src2)
#define vbicq_u64(src1, src2) neon_bicq(src1, src2)
#define vbif_s8(src1, src2, src3)   neon_bif(src1, src2, src3)
#define vbif_u8(src1, src2, src3)   neon_bif(src1, src2, src3)
#define vbif_s16(src1, src2, src3)  neon_bif(src1, src2, src3)
#define vbif_u16(src1, src2, src3)  neon_bif(src1, src2, src3)
#define vbif_s32(src1, src2, src3)  neon_bif(src1, src2, src3)
#define vbif_u32(src1, src2, src3)  neon_bif(src1, src2, src3)
#define vbif_s64(src1, src2, src3)  neon_bif(src1, src2, src3)
#define vbif_u64(src1, src2, src3)  neon_bif(src1, src2, src3)
#define vbifq_s8(src1, src2, src3)  neon_bifq(src1, src2, src3)
#define vbifq_u8(src1, src2, src3)  neon_bifq(src1, src2, src3)
#define vbifq_s16(src1, src2, src3) neon_bifq(src1, src2, src3)
#define vbifq_u16(src1, src2, src3) neon_bifq(src1, src2, src3)
#define vbifq_s32(src1, src2, src3) neon_bifq(src1, src2, src3)
#define vbifq_u32(src1, src2, src3) neon_bifq(src1, src2, src3)
#define vbifq_s64(src1, src2, src3) neon_bifq(src1, src2, src3)
#define vbifq_u64(src1, src2, src3) neon_bifq(src1, src2, src3)
#define vbit_s8(src1, src2, src3)   neon_bit(src1, src2, src3)
#define vbit_u8(src1, src2, src3)   neon_bit(src1, src2, src3)
#define vbit_s16(src1, src2, src3)  neon_bit(src1, src2, src3)
#define vbit_u16(src1, src2, src3)  neon_bit(src1, src2, src3)
#define vbit_s32(src1, src2, src3)  neon_bit(src1, src2, src3)
#define vbit_u32(src1, src2, src3)  neon_bit(src1, src2, src3)
#define vbit_s64(src1, src2, src3)  neon_bit(src1, src2, src3)
#define vbit_u64(src1, src2, src3)  neon_bit(src1, src2, src3)
#define vbitq_s8(src1, src2, src3)  neon_bitq(src1, src2, src3)
#define vbitq_u8(src1, src2, src3)  neon_bitq(src1, src2, src3)
#define vbitq_s16(src1, src2, src3) neon_bitq(src1, src2, src3)
#define vbitq_u16(src1, src2, src3) neon_bitq(src1, src2, src3)
#define vbitq_s32(src1, src2, src3) neon_bitq(src1, src2, src3)
#define vbitq_u32(src1, src2, src3) neon_bitq(src1, src2, src3)
#define vbitq_s64(src1, src2, src3) neon_bitq(src1, src2, src3)
#define vbitq_u64(src1, src2, src3) neon_bitq(src1, src2, src3)
#define vbsl_s8(src1, src2, src3)   neon_bsl(src1, src2, src3)
#define vbsl_u8(src1, src2, src3)   neon_bsl(src1, src2, src3)
#define vbsl_s16(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbsl_u16(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbsl_s32(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbsl_f32(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbsl_u32(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbsl_s64(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbsl_f64(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbsl_u64(src1, src2, src3)  neon_bsl(src1, src2, src3)
#define vbslq_s8(src1, src2, src3)  neon_bslq(src1, src2, src3)
#define vbslq_u8(src1, src2, src3)  neon_bslq(src1, src2, src3)
#define vbslq_s16(src1, src2, src3) neon_bslq(src1, src2, src3)
#define vbslq_u16(src1, src2, src3) neon_bslq(src1, src2, src3)
#define vbslq_s32(src1, src2, src3) neon_bslq(src1, src2, src3)
#define vbslq_f32(src1, src2, src3) neon_bslq(src1, src2, src3)
#define vbslq_u32(src1, src2, src3) neon_bslq(src1, src2, src3)
#define vbslq_s64(src1, src2, src3) neon_bslq(src1, src2, src3)
#define vbslq_u64(src1, src2, src3) neon_bslq(src1, src2, src3)
#define vbslq_f64(src1, src2, src3) neon_bslq(src1, src2, src3)

// BIC/ORR immediate
__n64  neon_bich(__n64, const int);
__n64  neon_bicw(__n64, const int);
__n64  neon_bic_shifth(__n64, const int, const int);
__n64  neon_bic_shiftw(__n64, const int, const int);
__n128 neon_bicqh(__n128, const int);
__n128 neon_bicqw(__n128, const int);
__n128 neon_bicq_shifth(__n128, const int, const int);
__n128 neon_bicq_shiftw(__n128, const int, const int);
__n64  neon_orrh(__n64, const int);
__n64  neon_orrw(__n64, const int);
__n64  neon_orr_shifth(__n64, const int, const int);
__n64  neon_orr_shiftw(__n64, const int, const int);
__n128 neon_orrqh(__n128, const int);
__n128 neon_orrqw(__n128, const int);
__n128 neon_orrq_shifth(__n128, const int, const int);
__n128 neon_orrq_shiftw(__n128, const int, const int);

// RBIT/REV16/REV32/REV64
__n64 neon_rbit(__n64);
__n128 neon_rbitq(__n128);
__n64 neon_rev16(__n64);
__n128 neon_rev16q(__n128);
__n64 neon_rev32_8(__n64);
__n128 neon_rev32q_8(__n128);
__n64 neon_rev32_16(__n64);
__n128 neon_rev32q_16(__n128);
__n64 neon_rev64_8(__n64);
__n128 neon_rev64q_8(__n128);
__n64 neon_rev64_16(__n64);
__n128 neon_rev64q_16(__n128);
__n64 neon_rev64_32(__n64);
__n128 neon_rev64q_32(__n128);
#define vrev16_p8(src)  neon_rev16(src)
#define vrev16_s8(src)  neon_rev16(src)
#define vrev16_u8(src)  neon_rev16(src)
#define vrev32_p8(src)  neon_rev32_8(src)
#define vrev32_s8(src)  neon_rev32_8(src)
#define vrev32_u8(src)  neon_rev32_8(src)
#define vrev32_p16(src) neon_rev32_16(src)
#define vrev32_s16(src) neon_rev32_16(src)
#define vrev32_u16(src) neon_rev32_16(src)
#define vrev64_p8(src)   neon_rev64_8(src)
#define vrev64_s8(src)   neon_rev64_8(src)
#define vrev64_u8(src)   neon_rev64_8(src)
#define vrev64_p16(src)  neon_rev64_16(src)
#define vrev64_s16(src)  neon_rev64_16(src)
#define vrev64_u16(src)  neon_rev64_16(src)
#define vrev64_s32(src)  neon_rev64_32(src)
#define vrev64_u32(src)  neon_rev64_32(src)
#define vrev64_f32(src)  neon_rev64_32(src)
#define vrev16q_p8(src)  neon_rev16q(src)
#define vrev16q_s8(src)  neon_rev16q(src)
#define vrev16q_u8(src)  neon_rev16q(src)
#define vrev32q_p8(src)  neon_rev32q_8(src)
#define vrev32q_s8(src)  neon_rev32q_8(src)
#define vrev32q_u8(src)  neon_rev32q_8(src)
#define vrev32q_p16(src) neon_rev32q_16(src)
#define vrev32q_s16(src) neon_rev32q_16(src)
#define vrev32q_u16(src) neon_rev32q_16(src)
#define vrev64q_p8(src)  neon_rev64q_8(src)
#define vrev64q_s8(src)  neon_rev64q_8(src)
#define vrev64q_u8(src)  neon_rev64q_8(src)
#define vrev64q_p16(src) neon_rev64q_16(src)
#define vrev64q_s16(src) neon_rev64q_16(src)
#define vrev64q_u16(src) neon_rev64q_16(src)
#define vrev64q_s32(src) neon_rev64q_32(src)
#define vrev64q_u32(src) neon_rev64q_32(src)
#define vrev64q_f32(src) neon_rev64q_32(src)

// CNT/CLS/CLZ
__n64  neon_cnt(__n64);
__n128 neon_cntq(__n128);
__n64  neon_cls8(__n64);
__n128 neon_clsq8(__n128);
__n64  neon_cls16(__n64);
__n128 neon_clsq16(__n128);
__n64  neon_cls32(__n64);
__n128 neon_clsq32(__n128);
__n64  neon_clz8(__n64);
__n128 neon_clzq8(__n128);
__n64  neon_clz16(__n64);
__n128 neon_clzq16(__n128);
__n64  neon_clz32(__n64);
__n128 neon_clzq32(__n128);
#define vcnt_p8(src) neon_cnt(src)
#define vcnt_s8(src) neon_cnt(src)
#define vcnt_u8(src) neon_cnt(src)
#define vcntq_p8(src) neon_cntq(src)
#define vcntq_s8(src) neon_cntq(src)
#define vcntq_u8(src) neon_cntq(src)
#define vcls_s8(src) neon_cls8(src)
#define vcls_s16(src) neon_cls16(src)
#define vcls_s32(src) neon_cls32(src)
#define vclsq_s8(src) neon_clsq8(src)
#define vclsq_s16(src) neon_clsq16(src)
#define vclsq_s32(src) neon_clsq32(src)
#define vclz_s8(src) neon_clz8(src)
#define vclz_s16(src) neon_clz16(src)
#define vclz_s32(src) neon_clz32(src)
#define vclz_u8(src) neon_clz8(src)
#define vclz_u16(src) neon_clz16(src)
#define vclz_u32(src) neon_clz32(src)
#define vclzq_s8(src) neon_clzq8(src)
#define vclzq_s16(src) neon_clzq16(src)
#define vclzq_s32(src) neon_clzq32(src)
#define vclzq_u8(src) neon_clzq8(src)
#define vclzq_u16(src) neon_clzq16(src)
#define vclzq_u32(src) neon_clzq32(src)

// FMAX/FMAXNM/FMAXNMP/FMAXNMV/FMAXP/FMAXV/SMAX/SMAXP/SMAXV/UMAX/UMAXP/UMAXV
__n64 neon_fmax32(__n64, __n64);
__n128 neon_fmaxq32(__n128, __n128);
__n128 neon_fmaxq64(__n128, __n128);
__n64 neon_fmaxnm32(__n64, __n64);
__n128 neon_fmaxnmq32(__n128, __n128);
__n128 neon_fmaxnmq64(__n128, __n128);
__n64 neon_fmaxnmp32(__n64, __n64);
__n128 neon_fmaxnmpq32(__n128, __n128);
__n128 neon_fmaxnmpq64(__n128, __n128);
float neon_fmaxnmps32(__n128);
double neon_fmaxnmps64(__n128);
float neon_fmaxnmv(__n128);
__n64 neon_fmaxp32(__n64, __n64);
__n128 neon_fmaxpq32(__n128, __n128);
__n128 neon_fmaxpq64(__n128, __n128);
float neon_fmaxps32(__n128);
double neon_fmaxps64(__n128);
float neon_fmaxv(__n128);
__n64 neon_smax8(__n64, __n64);
__n64 neon_smax16(__n64, __n64);
__n64 neon_smax32(__n64, __n64);
__n128 neon_smaxq8(__n128, __n128);
__n128 neon_smaxq16(__n128, __n128);
__n128 neon_smaxq32(__n128, __n128);
__n64 neon_smaxp8(__n64, __n64);
__n64 neon_smaxp16(__n64, __n64);
__n64 neon_smaxp32(__n64, __n64);
__n128 neon_smaxpq8(__n128, __n128);
__n128 neon_smaxpq16(__n128, __n128);
__n128 neon_smaxpq32(__n128, __n128);
__n8 neon_smaxv8(__n64);
__n8 neon_smaxvq8(__n128);
__n16 neon_smaxv16(__n64);
__n16 neon_smaxvq16(__n128);
float neon_smaxvq32(__n128);
__n64 neon_umax8(__n64, __n64);
__n64 neon_umax16(__n64, __n64);
__n64 neon_umax32(__n64, __n64);
__n128 neon_umaxq8(__n128, __n128);
__n128 neon_umaxq16(__n128, __n128);
__n128 neon_umaxq32(__n128, __n128);
__n64 neon_umaxp8(__n64, __n64);
__n64 neon_umaxp16(__n64, __n64);
__n64 neon_umaxp32(__n64, __n64);
__n128 neon_umaxpq8(__n128, __n128);
__n128 neon_umaxpq16(__n128, __n128);
__n128 neon_umaxpq32(__n128, __n128);
__n8 neon_umaxv8(__n64);
__n8 neon_umaxvq8(__n128);
__n16 neon_umaxv16(__n64);
__n16 neon_umaxvq16(__n128);
float neon_umaxvq32(__n128);
#define vmax_f32(src1, src2)    neon_fmax32(src1, src2)
#define vmaxnm_f32(src1, src2)  neon_fmaxnm32(src1, src2)
#define vmaxq_f32(src1, src2)   neon_fmaxq32(src1, src2)
#define vmaxnmq_f32(src1, src2) neon_fmaxnmq32(src1, src2)
#define vmax_s8(src1, src2)   neon_smax8(src1, src2)
#define vmax_s16(src1, src2)  neon_smax16(src1, src2)
#define vmax_s32(src1, src2)  neon_smax32(src1, src2)
#define vmax_u8(src1, src2)   neon_umax8(src1, src2)
#define vmax_u16(src1, src2)  neon_umax16(src1, src2)
#define vmax_u32(src1, src2)  neon_umax32(src1, src2)
#define vmaxq_s8(src1, src2)  neon_smaxq8(src1, src2)
#define vmaxq_s16(src1, src2) neon_smaxq16(src1, src2)
#define vmaxq_s32(src1, src2) neon_smaxq32(src1, src2)
#define vmaxq_u8(src1, src2)  neon_umaxq8(src1, src2)
#define vmaxq_u16(src1, src2) neon_umaxq16(src1, src2)
#define vmaxq_u32(src1, src2) neon_umaxq32(src1, src2)
#define vpmax_f32(src1, src2) neon_fmaxp32(src1, src2)
#define vpmax_s8(src1, src2)  neon_smaxp8(src1, src2)
#define vpmax_s16(src1, src2) neon_smaxp16(src1, src2)
#define vpmax_s32(src1, src2) neon_smaxp32(src1, src2)
#define vpmax_u8(src1, src2)  neon_umaxp8(src1, src2)
#define vpmax_u16(src1, src2) neon_umaxp16(src1, src2)
#define vpmax_u32(src1, src2) neon_umaxp32(src1, src2)

// FMIN/FMINNM/FMINNMP/FMINNMV/FMINP/FMINV/SMIN/SMINP/SMINV/UMIN/UMINP/UMINV
__n64 neon_fmin32(__n64, __n64);
__n128 neon_fminq32(__n128, __n128);
__n128 neon_fminq64(__n128, __n128);
__n64 neon_fminnm32(__n64, __n64);
__n128 neon_fminnmq32(__n128, __n128);
__n128 neon_fminnmq64(__n128, __n128);
__n64 neon_fminnmp32(__n64, __n64);
__n128 neon_fminnmpq32(__n128, __n128);
__n128 neon_fminnmpq64(__n128, __n128);
float neon_fminnmps32(__n128);
double neon_fminnmps64(__n128);
float neon_fminnmv(__n128);
__n64 neon_fminp32(__n64, __n64);
__n128 neon_fminpq32(__n128, __n128);
__n128 neon_fminpq64(__n128, __n128);
float neon_fminps32(__n128);
double neon_fminps64(__n128);
float neon_fminv(__n128);
__n64 neon_smin8(__n64, __n64);
__n64 neon_smin16(__n64, __n64);
__n64 neon_smin32(__n64, __n64);
__n128 neon_sminq8(__n128, __n128);
__n128 neon_sminq16(__n128, __n128);
__n128 neon_sminq32(__n128, __n128);
__n64 neon_sminp8(__n64, __n64);
__n64 neon_sminp16(__n64, __n64);
__n64 neon_sminp32(__n64, __n64);
__n128 neon_sminpq8(__n128, __n128);
__n128 neon_sminpq16(__n128, __n128);
__n128 neon_sminpq32(__n128, __n128);
__n8 neon_sminv8(__n64);
__n8 neon_sminvq8(__n128);
__n16 neon_sminv16(__n64);
__n16 neon_sminvq16(__n128);
float neon_sminvq32(__n128);
__n64 neon_umin8(__n64, __n64);
__n64 neon_umin16(__n64, __n64);
__n64 neon_umin32(__n64, __n64);
__n128 neon_uminq8(__n128, __n128);
__n128 neon_uminq16(__n128, __n128);
__n128 neon_uminq32(__n128, __n128);
__n64 neon_uminp8(__n64, __n64);
__n64 neon_uminp16(__n64, __n64);
__n64 neon_uminp32(__n64, __n64);
__n128 neon_uminpq8(__n128, __n128);
__n128 neon_uminpq16(__n128, __n128);
__n128 neon_uminpq32(__n128, __n128);
__n8 neon_uminv8(__n64);
__n8 neon_uminvq8(__n128);
__n16 neon_uminv16(__n64);
__n16 neon_uminvq16(__n128);
float neon_uminvq32(__n128);
#define vmin_f32(src1, src2) neon_fmin32(src1, src2)
#define vminnm_f32(src1, src2) neon_fminnm32(src1, src2)
#define vminq_f32(src1, src2) neon_fminq32(src1, src2)
#define vminnmq_f32(src1, src2) neon_fminnmq32(src1, src2)
#define vmin_s8(src1, src2)  neon_smin8(src1, src2)
#define vmin_s16(src1, src2) neon_smin16(src1, src2)
#define vmin_s32(src1, src2) neon_smin32(src1, src2)
#define vmin_u8(src1, src2)  neon_umin8(src1, src2)
#define vmin_u16(src1, src2) neon_umin16(src1, src2)
#define vmin_u32(src1, src2) neon_umin32(src1, src2)
#define vminq_s8(src1, src2)  neon_sminq8(src1, src2)
#define vminq_s16(src1, src2) neon_sminq16(src1, src2)
#define vminq_s32(src1, src2) neon_sminq32(src1, src2)
#define vminq_u8(src1, src2)  neon_uminq8(src1, src2)
#define vminq_u16(src1, src2) neon_uminq16(src1, src2)
#define vminq_u32(src1, src2) neon_uminq32(src1, src2)
#define vpmin_f32(src1, src2) neon_fminp32(src1, src2)
#define vpmin_s8(src1, src2)  neon_sminp8(src1, src2)
#define vpmin_s16(src1, src2) neon_sminp16(src1, src2)
#define vpmin_s32(src1, src2) neon_sminp32(src1, src2)
#define vpmin_u8(src1, src2)  neon_uminp8(src1, src2)
#define vpmin_u16(src1, src2) neon_uminp16(src1, src2)
#define vpmin_u32(src1, src2) neon_uminp32(src1, src2)

// EXT
__n64  neon_ext8(__n64, __n64, const int);
__n64  neon_ext16(__n64, __n64, const int);
__n64  neon_ext32(__n64, __n64, const int);
__n64  neon_ext64(__n64, __n64, const int);
__n128 neon_extq8(__n128, __n128, const int);
__n128 neon_extq16(__n128, __n128, const int);
__n128 neon_extq32(__n128, __n128, const int);
__n128 neon_extq64(__n128, __n128, const int);
#define vext_s8(src1, src2, pos)  neon_ext8(src1, src2, pos) 
#define vext_u8(src1, src2, pos)  neon_ext8(src1, src2, pos) 
#define vext_s16(src1, src2, pos)  neon_ext16(src1, src2, pos) 
#define vext_u16(src1, src2, pos)  neon_ext16(src1, src2, pos) 
#define vext_s32(src1, src2, pos)  neon_ext32(src1, src2, pos) 
#define vext_u32(src1, src2, pos)  neon_ext32(src1, src2, pos) 
#define vext_s64(src1, src2, pos)  neon_ext64(src1, src2, pos) 
#define vext_u64(src1, src2, pos)  neon_ext64(src1, src2, pos) 
#define vext_p8(src1, src2, pos)  neon_ext8(src1, src2, pos) 
#define vext_p16(src1, src2, pos)  neon_ext16(src1, src2, pos) 
#define vext_p64(src1, src2, pos)  neon_ext64(src1, src2, pos) 
#define vext_f32(src1, src2, pos)  neon_ext32(src1, src2, pos) 
#define vext_f64(src1, src2, pos)  neon_ext64(src1, src2, pos) 
#define vextq_s8(src1, src2, pos)  neon_extq8(src1, src2, pos) 
#define vextq_u8(src1, src2, pos)  neon_extq8(src1, src2, pos) 
#define vextq_s16(src1, src2, pos)  neon_extq16(src1, src2, pos) 
#define vextq_u16(src1, src2, pos)  neon_extq16(src1, src2, pos) 
#define vextq_s32(src1, src2, pos)  neon_extq32(src1, src2, pos) 
#define vextq_u32(src1, src2, pos)  neon_extq32(src1, src2, pos) 
#define vextq_s64(src1, src2, pos)  neon_extq64(src1, src2, pos) 
#define vextq_u64(src1, src2, pos)  neon_extq64(src1, src2, pos) 
#define vextq_p8(src1, src2, pos)  neon_extq8(src1, src2, pos) 
#define vextq_p16(src1, src2, pos)  neon_extq16(src1, src2, pos) 
#define vextq_p64(src1, src2, pos)  neon_extq64(src1, src2, pos) 
#define vextq_f32(src1, src2, pos)  neon_extq32(src1, src2, pos) 
#define vextq_f64(src1, src2, pos)  neon_extq64(src1, src2, pos) 

// FABD/SABD/SABA/UABD/UABA
__n64  neon_fabd32(__n64, __n64);
__n128 neon_fabdq32(__n128, __n128);
__n128 neon_fabdq64(__n128, __n128);
float  neon_fabds32(float, float);
double neon_fabds64(double, double);
__n64  neon_sabd8(__n64, __n64);
__n64  neon_sabd16(__n64, __n64);
__n64  neon_sabd32(__n64, __n64);
__n128 neon_sabdq8(__n128, __n128);
__n128 neon_sabdq16(__n128, __n128);
__n128 neon_sabdq32(__n128, __n128);
__n64  neon_saba8(__n64, __n64, __n64);
__n64  neon_saba16(__n64, __n64, __n64);
__n64  neon_saba32(__n64, __n64, __n64);
__n128 neon_sabaq8(__n128, __n128, __n128);
__n128 neon_sabaq16(__n128, __n128, __n128);
__n128 neon_sabaq32(__n128, __n128, __n128);
__n64  neon_uabd8(__n64, __n64);
__n64  neon_uabd16(__n64, __n64);
__n64  neon_uabd32(__n64, __n64);
__n128 neon_uabdq8(__n128, __n128);
__n128 neon_uabdq16(__n128, __n128);
__n128 neon_uabdq32(__n128, __n128);
__n64  neon_uaba8(__n64, __n64, __n64);
__n64  neon_uaba16(__n64, __n64, __n64);
__n64  neon_uaba32(__n64, __n64, __n64);
__n128 neon_uabaq8(__n128, __n128, __n128);
__n128 neon_uabaq16(__n128, __n128, __n128);
__n128 neon_uabaq32(__n128, __n128, __n128);
#define vabd_f32(src1, src2) neon_fabd32(src1, src2)
#define vabds_f32(src1, src2) neon_fabds32(src1, src2)
#define vabd_f64(src1, src2) neon_fabds64(src1, src2)
#define vabdq_f32(src1, src2) neon_fabdq32(src1, src2)
#define vabd_s8(src1, src2) neon_sabd8(src1, src2)
#define vabd_s16(src1, src2) neon_sabd16(src1, src2)
#define vabd_s32(src1, src2) neon_sabd32(src1, src2)
#define vabd_u8(src1, src2) neon_uabd8(src1, src2)
#define vabd_u16(src1, src2) neon_uabd16(src1, src2)
#define vabd_u32(src1, src2) neon_uabd32(src1, src2)
#define vabdq_s8(src1, src2) neon_sabdq8(src1, src2)
#define vabdq_s16(src1, src2) neon_sabdq16(src1, src2)
#define vabdq_s32(src1, src2) neon_sabdq32(src1, src2)
#define vabdq_u8(src1, src2) neon_uabdq8(src1, src2)
#define vabdq_u16(src1, src2) neon_uabdq16(src1, src2)
#define vabdq_u32(src1, src2) neon_uabdq32(src1, src2)
#define vabdq_f64(src1, src2) neon_uabdq64(src1, src2)
#define vaba_s8(src1, src2, src3) neon_saba8(src1, src2, src3)
#define vaba_s16(src1, src2, src3) neon_saba16(src1, src2, src3)
#define vaba_s32(src1, src2, src3) neon_saba32(src1, src2, src3)
#define vaba_u8(src1, src2, src3) neon_uaba8(src1, src2, src3)
#define vaba_u16(src1, src2, src3) neon_uaba16(src1, src2, src3)
#define vaba_u32(src1, src2, src3) neon_uaba32(src1, src2, src3)
#define vabaq_s8(src1, src2, src3) neon_sabaq8(src1, src2, src3)
#define vabaq_s16(src1, src2, src3) neon_sabaq16(src1, src2, src3)
#define vabaq_s32(src1, src2, src3) neon_sabaq32(src1, src2, src3)
#define vabaq_u8(src1, src2, src3) neon_uabaq8(src1, src2, src3)
#define vabaq_u16(src1, src2, src3) neon_uabaq16(src1, src2, src3)
#define vabaq_u32(src1, src2, src3) neon_uabaq32(src1, src2, src3)

// FDIV
__n64  neon_fdiv32(__n64, __n64);
__n128 neon_fdivq32(__n128, __n128);
__n128 neon_fdivq64(__n128, __n128);
#define vdiv_f32(src1, src2) neon_fdiv32(src1, src2)
#define vdivq_f32(src1, src2) neon_fdivq32(src1, src2)

// FSQRT/FRSQRTE/URSQRTE/FRSQRTS
__n64  neon_fsqrt32(__n64);
__n128 neon_fsqrtq32(__n128);
__n128 neon_fsqrtq64(__n128);
__n64  neon_frsqrte32(__n64);
__n128 neon_frsqrteq32(__n128);
__n128 neon_frsqrteq64(__n128);
float  neon_frsqrtes32(float);
double neon_frsqrtes64(double);
__n64  neon_ursqrte32(__n64);
__n128 neon_ursqrteq32(__n128);
__n64  neon_frsqrts32(__n64, __n64);
__n128 neon_frsqrtsq32(__n128, __n128);
__n128 neon_frsqrtsq64(__n128, __n128);
float  neon_frsqrtss32(float, float);
double neon_frsqrtss64(double, double);
#define vrsqrte_f32(src)         neon_frsqrte32(src)
#define vrsqrte_u32(src)         neon_ursqrte32(src)
#define vrsqrteq_f32(src)        neon_frsqrteq32(src)
#define vrsqrteq_u32(src)        neon_ursqrteq32(src)
#define vrsqrts_f32(src1, src2)  neon_frsqrts32(src1, src2)
#define vrsqrtsq_f32(src1, src2) neon_frsqrtsq32(src1, src2)

// PMUL/MUL/MLA/MLS/SQDMULH/SQRDMULH/FMUL/FMLA/FMLS/FMULX
__n64  neon_pmul(__n64, __n64);
__n128 neon_pmulq(__n128, __n128);
__n128 neon_pmull_8(__n64, __n64);
__n128 neon_pmull_q8(__n128, __n128);
__n128 neon_pmull2_8(__n128, __n128);
__n128 neon_pmull_64(__n64, __n64);
__n128 neon_pmull_q64(__n128, __n128);
__n128 neon_pmull2_64(__n128, __n128);
__n64  neon_fmulvind32 (__n64,  __n64,  const int);
__n128 neon_fmulqvind32(__n128, __n64, const int);
__n128 neon_fmulqvind32q(__n128, __n128, const int);
__n128 neon_fmulqvind64(__n128, __n128, const int);
__n64  neon_fmul32 (__n64,  __n64);
__n128 neon_fmulq32(__n128, __n128);
__n128 neon_fmulq64(__n128, __n128);
float  neon_fmulsind32(float, __n128, const int);
double neon_fmulsind64(double, __n128, const int);
__n64  neon_fmlavind32 (__n64, __n64,  __n64,  const int);
__n128 neon_fmlaqvind32(__n128, __n128, __n64, const int);
__n128 neon_fmlaqvind32q(__n128, __n128, __n128, const int);
__n128 neon_fmlaqvind64(__n128, __n128, __n128, const int);
__n64  neon_fmla32 (__n64, __n64,  __n64);
__n128 neon_fmlaq32(__n128, __n128, __n128);
__n128 neon_fmlaq64(__n128, __n128, __n128);
float  neon_fmlasind32(float,  float, __n128, const int);
double neon_fmlasind64(double, double, __n128, const int);
__n64  neon_fmlsvind32 (__n64,  __n64,  __n64,  const int);
__n128 neon_fmlsqvind32(__n128, __n128, __n64, const int);
__n128 neon_fmlsqvind32q(__n128, __n128, __n128, const int);
__n128 neon_fmlsqvind64(__n128, __n128, __n128, const int);
__n64  neon_fmls32 (__n64,  __n64,  __n64);
__n128 neon_fmlsq32(__n128, __n128, __n128);
__n128 neon_fmlsq64(__n128, __n128, __n128);
float  neon_fmlssind32(float,  float, __n128, const int);
double neon_fmlssind64(double, double, __n128, const int);
__n64  neon_fmulxvind32 (__n64,  __n64,  const int);
__n128 neon_fmulxqvind32(__n128, __n64, const int);
__n128 neon_fmulxqvind32q(__n128, __n128, const int);
__n128 neon_fmulxqvind64(__n128, __n128, const int);
__n64  neon_fmulx32 (__n64,  __n64);
__n128 neon_fmulxq32(__n128, __n128);
__n128 neon_fmulxq64(__n128, __n128);
float  neon_fmulxsind32(float, __n128, const int);
double neon_fmulxsind64(double, __n128, const int);
float  neon_fmulxs32(float,  float);
double neon_fmulxs64(double, double);
__n64  neon_mulvind16 (__n64,  __n64,  const int);
__n64  neon_mulvind32 (__n64,  __n64,  const int);
__n128 neon_mulqvind16(__n128, __n64, const int);
__n128 neon_mulqvind32(__n128, __n64, const int);
__n128 neon_mulqvind16q(__n128, __n128, const int);
__n128 neon_mulqvind32q(__n128, __n128, const int);
__n64  neon_mul8  (__n64,  __n64);
__n64  neon_mul16 (__n64,  __n64);
__n64  neon_mul32 (__n64,  __n64);
__n128 neon_mulq8 (__n128, __n128);
__n128 neon_mulq16(__n128, __n128);
__n128 neon_mulq32(__n128, __n128);
__n64  neon_mlsvind16 (__n64,  __n64,  __n64,  const int);
__n64  neon_mlsvind32 (__n64,  __n64,  __n64,  const int);
__n128 neon_mlsqvind16(__n128, __n128, __n64, const int);
__n128 neon_mlsqvind32(__n128, __n128, __n64, const int);
__n128 neon_mlsqvind16q(__n128, __n128, __n128, const int);
__n128 neon_mlsqvind32q(__n128, __n128, __n128, const int);
__n64  neon_mls8  (__n64,  __n64,  __n64);
__n64  neon_mls16 (__n64,  __n64,  __n64);
__n64  neon_mls32 (__n64,  __n64,  __n64);
__n128 neon_mlsq8 (__n128, __n128, __n128);
__n128 neon_mlsq16(__n128, __n128, __n128);
__n128 neon_mlsq32(__n128, __n128, __n128);
__n64  neon_mlavind16 (__n64,  __n64,  __n64,  const int);
__n64  neon_mlavind32 (__n64,  __n64,  __n64,  const int);
__n128 neon_mlaqvind16(__n128, __n128, __n64, const int);
__n128 neon_mlaqvind32(__n128, __n128, __n64, const int);
__n128 neon_mlaqvind16q(__n128, __n128, __n128, const int);
__n128 neon_mlaqvind32q(__n128, __n128, __n128, const int);
__n64  neon_mla8  (__n64,  __n64,  __n64);
__n64  neon_mla16 (__n64,  __n64,  __n64);
__n64  neon_mla32 (__n64,  __n64,  __n64);
__n128 neon_mlaq8 (__n128, __n128, __n128);
__n128 neon_mlaq16(__n128, __n128, __n128);
__n128 neon_mlaq32(__n128, __n128, __n128);
__n64  neon_sqdmulhvind16 (__n64,  __n64,  const int);
__n64  neon_sqdmulhvind32 (__n64,  __n64,  const int);
__n128 neon_sqdmulhqvind16(__n128, __n64, const int);
__n128 neon_sqdmulhqvind32(__n128, __n64, const int);
__n128 neon_sqdmulhqvind16q(__n128, __n128, const int);
__n128 neon_sqdmulhqvind32q(__n128, __n128, const int);
__n64  neon_sqdmulh16 (__n64,  __n64);
__n64  neon_sqdmulh32 (__n64,  __n64);
__n128 neon_sqdmulhq16(__n128, __n128);
__n128 neon_sqdmulhq32(__n128, __n128);
__n16  neon_sqdmulhsind16(__n16, __n128, const int);
float  neon_sqdmulhsind32(float, __n128, const int);
__n16  neon_sqdmulhs16 (__n16,  __n16);
float  neon_sqdmulhs32 (float,  float);
__n64  neon_sqrdmulhvind16 (__n64,  __n64,  const int);
__n64  neon_sqrdmulhvind32 (__n64,  __n64,  const int);
__n128 neon_sqrdmulhqvind16(__n128, __n64, const int);
__n128 neon_sqrdmulhqvind32(__n128, __n64, const int);
__n128 neon_sqrdmulhqvind16q(__n128, __n128, const int);
__n128 neon_sqrdmulhqvind32q(__n128, __n128, const int);
__n64  neon_sqrdmulh16 (__n64,  __n64);
__n64  neon_sqrdmulh32 (__n64,  __n64);
__n128 neon_sqrdmulhq16(__n128, __n128);
__n128 neon_sqrdmulhq32(__n128, __n128);
__n16  neon_sqrdmulhsind16(__n16, __n128, const int);
float  neon_sqrdmulhsind32(float, __n128, const int);
__n16  neon_sqrdmulhs16 (__n16,  __n16);
float  neon_sqrdmulhs32 (float,  float);
#define vmul_p8(src1, src2) neon_pmul(src1, src2)
#define vmull_p8(src1, src2) neon_pmull_8(src1, src2)
#define vmullq_p8(src1, src2) neon_pmull_q8(src1, src2)
#define vmull_high_p8(src1, src2) neon_pmull2_8(src1, src2)
#define vmull_p64(src1, src2) neon_pmull_64(src1, src2)
#define vmullq_p64(src1, src2) neon_pmull_q64(src1, src2)
#define vmull_high_p64(src1, src2) neon_pmull2_64(src1, src2)
#define vmul_f32(src1, src2) neon_fmul32(src1, src2)
#define vmul_s16(src1, src2) neon_mul16(src1, src2)
#define vmul_s32(src1, src2) neon_mul32(src1, src2)
#define vmul_s8(src1, src2) neon_mul8(src1, src2)
#define vmul_u16(src1, src2) neon_mul16(src1, src2)
#define vmul_u32(src1, src2) neon_mul32(src1, src2)
#define vmul_u8(src1, src2) neon_mul8(src1, src2)
#define vmulq_p8(src1, src2) neon_pmulq(src1, src2)
#define vmulq_f32(src1, src2) neon_fmulq32(src1, src2)
#define vmulq_s16(src1, src2) neon_mulq16(src1, src2)
#define vmulq_s32(src1, src2) neon_mulq32(src1, src2)
#define vmulq_s8(src1, src2) neon_mulq8(src1, src2)
#define vmulq_u16(src1, src2) neon_mulq16(src1, src2)
#define vmulq_u32(src1, src2) neon_mulq32(src1, src2)
#define vmulq_u8(src1, src2) neon_mulq8(src1, src2)
#define vmul_lane_f32(src1, src2, lane) neon_fmulvind32(src1, src2, lane)
#define vmul_lane_s16(src1, src2, lane) neon_mulvind16(src1, src2, lane)
#define vmul_lane_s32(src1, src2, lane) neon_mulvind32(src1, src2, lane)
#define vmul_lane_u16(src1, src2, lane) neon_mulvind16(src1, src2, lane)
#define vmul_lane_u32(src1, src2, lane) neon_mulvind32(src1, src2, lane)
#define vmulq_lane_f32(src1, src2, lane) neon_fmulqvind32(src1, src2, lane)
#define vmulq_lane_s16(src1, src2, lane) neon_mulqvind16(src1, src2, lane)
#define vmulq_lane_s32(src1, src2, lane) neon_mulqvind32(src1, src2, lane)
#define vmulq_lane_u16(src1, src2, lane) neon_mulqvind16(src1, src2, lane)
#define vmulq_lane_u32(src1, src2, lane) neon_mulqvind32(src1, src2, lane)
#define vqdmulh_lane_s16(src1, src2, lane) neon_sqdmulhvind16(src1, src2, lane)
#define vqdmulh_lane_s32(src1, src2, lane) neon_sqdmulhvind32(src1, src2, lane)
#define vqrdmulh_lane_s16(src1, src2, lane) neon_sqrdmulhvind16(src1, src2, lane)
#define vqrdmulh_lane_s32(src1, src2, lane) neon_sqrdmulhvind32(src1, src2, lane)
#define vqdmulhq_lane_s16(src1, src2, lane) neon_sqdmulhqvind16(src1, src2, lane)
#define vqdmulhq_lane_s32(src1, src2, lane) neon_sqdmulhqvind32(src1, src2, lane)
#define vqrdmulhq_lane_s16(src1, src2, lane) neon_sqrdmulhqvind16(src1, src2, lane)
#define vqrdmulhq_lane_s32(src1, src2, lane) neon_sqrdmulhqvind32(src1, src2, lane)
#define vqdmulh_s16(src1, src2) neon_sqdmulh16(src1, src2)
#define vqdmulh_s32(src1, src2) neon_sqdmulh32(src1, src2)
#define vqrdmulh_s16(src1, src2) neon_sqrdmulh16(src1, src2)
#define vqrdmulh_s32(src1, src2) neon_sqrdmulh32(src1, src2)
#define vqdmulhq_s16(src1, src2) neon_sqdmulhq16(src1, src2)
#define vqdmulhq_s32(src1, src2) neon_sqdmulhq32(src1, src2)
#define vqrdmulhq_s16(src1, src2) neon_sqrdmulhq16(src1, src2)
#define vqrdmulhq_s32(src1, src2) neon_sqrdmulhq32(src1, src2)
#define vmla_lane_f32(dst, src1, src2, lane) neon_fmlavind32(dst, src1, src2, lane)
#define vmla_lane_s16(dst, src1, src2, lane) neon_mlavind16(dst, src1, src2, lane)
#define vmla_lane_s32(dst, src1, src2, lane) neon_mlavind32(dst, src1, src2, lane)
#define vmla_lane_u16(dst, src1, src2, lane) neon_mlavind16(dst, src1, src2, lane)
#define vmla_lane_u32(dst, src1, src2, lane) neon_mlavind32(dst, src1, src2, lane)
#define vmls_lane_f32(dst, src1, src2, lane) neon_fmlsvind32(dst, src1, src2, lane)
#define vmls_lane_s16(dst, src1, src2, lane) neon_mlsvind16(dst, src1, src2, lane)
#define vmls_lane_s32(dst, src1, src2, lane) neon_mlsvind32(dst, src1, src2, lane)
#define vmls_lane_u16(dst, src1, src2, lane) neon_mlsvind16(dst, src1, src2, lane)
#define vmls_lane_u32(dst, src1, src2, lane) neon_mlsvind32(dst, src1, src2, lane)
#define vmlaq_lane_f32(dst, src1, src2, lane) neon_fmlaqvind32(dst, src1, src2, lane)
#define vmlaq_lane_s16(dst, src1, src2, lane) neon_mlaqvind16(dst, src1, src2, lane)
#define vmlaq_lane_s32(dst, src1, src2, lane) neon_mlaqvind32(dst, src1, src2, lane)
#define vmlaq_lane_u16(dst, src1, src2, lane) neon_mlaqvind16(dst, src1, src2, lane)
#define vmlaq_lane_u32(dst, src1, src2, lane) neon_mlaqvind32(dst, src1, src2, lane)
#define vmlsq_lane_f32(dst, src1, src2, lane) neon_fmlsqvind32(dst, src1, src2, lane)
#define vmlsq_lane_s16(dst, src1, src2, lane) neon_mlsqvind16(dst, src1, src2, lane)
#define vmlsq_lane_s32(dst, src1, src2, lane) neon_mlsqvind32(dst, src1, src2, lane)
#define vmlsq_lane_u16(dst, src1, src2, lane) neon_mlsqvind16(dst, src1, src2, lane)
#define vmlsq_lane_u32(dst, src1, src2, lane) neon_mlsqvind32(dst, src1, src2, lane)
#define vmla_f32(dst, src1, src2) neon_fmla32(dst, src1, src2)
#define vmls_f32(dst, src1, src2) neon_fmls32(dst, src1, src2)
#define vmlaq_f32(dst, src1, src2) neon_fmlaq32(dst, src1, src2)
#define vmlsq_f32(dst, src1, src2) neon_fmlsq32(dst, src1, src2)
#define vmla_s16(dst, src1, src2) neon_mla16(dst, src1, src2)
#define vmla_s32(dst, src1, src2) neon_mla32(dst, src1, src2)
#define vmla_s8(dst, src1, src2) neon_mla8(dst, src1, src2)
#define vmla_u16(dst, src1, src2) neon_mla16(dst, src1, src2)
#define vmla_u32(dst, src1, src2) neon_mla32(dst, src1, src2)
#define vmla_u8(dst, src1, src2) neon_mla8(dst, src1, src2)
#define vmls_s16(dst, src1, src2) neon_mls16(dst, src1, src2)
#define vmls_s32(dst, src1, src2) neon_mls32(dst, src1, src2)
#define vmls_s8(dst, src1, src2) neon_mls8(dst, src1, src2)
#define vmls_u16(dst, src1, src2) neon_mls16(dst, src1, src2)
#define vmls_u32(dst, src1, src2) neon_mls32(dst, src1, src2)
#define vmls_u8(dst, src1, src2) neon_mls8(dst, src1, src2)
#define vmlaq_s16(dst, src1, src2) neon_mlaq16(dst, src1, src2)
#define vmlaq_s32(dst, src1, src2) neon_mlaq32(dst, src1, src2)
#define vmlaq_s8(dst, src1, src2) neon_mlaq8(dst, src1, src2)
#define vmlaq_u16(dst, src1, src2) neon_mlaq16(dst, src1, src2)
#define vmlaq_u32(dst, src1, src2) neon_mlaq32(dst, src1, src2)
#define vmlaq_u8(dst, src1, src2) neon_mlaq8(dst, src1, src2)
#define vmlsq_s16(dst, src1, src2) neon_mlsq16(dst, src1, src2)
#define vmlsq_s32(dst, src1, src2) neon_mlsq32(dst, src1, src2)
#define vmlsq_s8(dst, src1, src2) neon_mlsq8(dst, src1, src2)
#define vmlsq_u16(dst, src1, src2) neon_mlsq16(dst, src1, src2)
#define vmlsq_u32(dst, src1, src2) neon_mlsq32(dst, src1, src2)
#define vmlsq_u8(dst, src1, src2) neon_mlsq8(dst, src1, src2)
#define vfmaq_f32(dst, src1, src2) neon_fmlaq32(dst, src1, src2)
#define vfmsq_f32(dst, src1, src2) neon_fmlsq32(dst, src1, src2)

//  Multiply by scalar
#define vmul_n_s16(Vd, Rt)             vmul_lane_s16((Vd), vmov_n_s16(Rt), 0)
#define vmul_n_s32(Vd, Rt)             vmul_lane_s32((Vd), vmov_n_s32(Rt), 0)
#define vmul_n_u16(Vd, Rt)             vmul_lane_u16((Vd), vmov_n_u16(Rt), 0)
#define vmul_n_u32(Vd, Rt)             vmul_lane_u32((Vd), vmov_n_u32(Rt), 0)
#define vmul_n_f32(Vd, Rt)             vmul_lane_f32((Vd), vmov_n_f32(Rt), 0)
#define vmulq_n_s16(Vd, Rt)            vmulq_lane_s16((Vd), vmov_n_s16(Rt), 0)
#define vmulq_n_s32(Vd, Rt)            vmulq_lane_s32((Vd), vmov_n_s32(Rt), 0)
#define vmulq_n_u16(Vd, Rt)            vmulq_lane_u16((Vd), vmov_n_u16(Rt), 0)
#define vmulq_n_u32(Vd, Rt)            vmulq_lane_u32((Vd), vmov_n_u32(Rt), 0)
#define vmulq_n_f32(Vd, Rt)            vmulq_lane_f32((Vd), vmov_n_f32(Rt), 0)
#define vqdmulh_n_s16(Vd, Rt)          vqdmulh_lane_s16((Vd), vmov_n_s16(Rt), 0)
#define vqdmulh_n_s32(Vd, Rt)          vqdmulh_lane_s32((Vd), vmov_n_s32(Rt), 0)
#define vqdmulhq_n_s16(Vd, Rt)         vqdmulhq_lane_s16((Vd), vmov_n_s16(Rt), 0)
#define vqdmulhq_n_s32(Vd, Rt)         vqdmulhq_lane_s32((Vd), vmov_n_s32(Rt), 0)
#define vqrdmulh_n_s16(Vd, Rt)         vqrdmulh_lane_s16((Vd), vmov_n_s16(Rt), 0)
#define vqrdmulh_n_s32(Vd, Rt)         vqrdmulh_lane_s32((Vd), vmov_n_s32(Rt), 0)
#define vqrdmulhq_n_s16(Vd, Rt)        vqrdmulhq_lane_s16((Vd), vmov_n_s16(Rt), 0)
#define vqrdmulhq_n_s32(Vd, Rt)        vqrdmulhq_lane_s32((Vd), vmov_n_s32(Rt), 0)
//  Multiply by scalar with accumulate
#define vmla_n_s16(Vd, Vn, Rt)         vmla_lane_s16((Vd), (Vn), vmov_n_s16(Rt), 0)
#define vmla_n_s32(Vd, Vn, Rt)         vmla_lane_s32((Vd), (Vn), vmov_n_s32(Rt), 0)
#define vmla_n_u16(Vd, Vn, Rt)         vmla_lane_u16((Vd), (Vn), vmov_n_u16(Rt), 0)
#define vmla_n_u32(Vd, Vn, Rt)         vmla_lane_u32((Vd), (Vn), vmov_n_u32(Rt), 0)
#define vmla_n_f32(Vd, Vn, Rt)         vmla_lane_f32((Vd), (Vn), vmov_n_f32(Rt), 0)
#define vmlaq_n_s16(Vd, Vn, Rt)        vmlaq_lane_s16((Vd), (Vn), vmov_n_s16(Rt), 0)
#define vmlaq_n_s32(Vd, Vn, Rt)        vmlaq_lane_s32((Vd), (Vn), vmov_n_s32(Rt), 0)
#define vmlaq_n_f32(Vd, Vn, Rt)        vmlaq_lane_f32((Vd), (Vn), vmov_n_f32(Rt), 0)
#define vmlaq_n_u16(Vd, Vn, Rt)        vmlaq_lane_u16((Vd), (Vn), vmov_n_u16(Rt), 0)
#define vmlaq_n_u32(Vd, Vn, Rt)        vmlaq_lane_u32((Vd), (Vn), vmov_n_u32(Rt), 0)
#define vmls_n_s16(Vd, Vn, Rt)         vmls_lane_s16((Vd), (Vn), vmov_n_s16(Rt), 0)
#define vmls_n_s32(Vd, Vn, Rt)         vmls_lane_s32((Vd), (Vn), vmov_n_s32(Rt), 0)
#define vmls_n_u16(Vd, Vn, Rt)         vmls_lane_u16((Vd), (Vn), vmov_n_u16(Rt), 0)
#define vmls_n_u32(Vd, Vn, Rt)         vmls_lane_u32((Vd), (Vn), vmov_n_u32(Rt), 0)
#define vmls_n_f32(Vd, Vn, Rt)         vmls_lane_f32((Vd), (Vn), vmov_n_f32(Rt), 0)
#define vmlsq_n_s16(Vd, Vn, Rt)        vmlsq_lane_s16((Vd), (Vn), vmov_n_s16(Rt), 0)
#define vmlsq_n_s32(Vd, Vn, Rt)        vmlsq_lane_s32((Vd), (Vn), vmov_n_s32(Rt), 0)
#define vmlsq_n_u16(Vd, Vn, Rt)        vmlsq_lane_u16((Vd), (Vn), vmov_n_u16(Rt), 0)
#define vmlsq_n_u32(Vd, Vn, Rt)        vmlsq_lane_u32((Vd), (Vn), vmov_n_u32(Rt), 0)
#define vmlsq_n_f32(Vd, Vn, Rt)        vmlsq_lane_f32((Vd), (Vn), vmov_n_f32(Rt), 0)

// SMULL(2)/UMULL(2)/SMLAL(2)/UMLAL(2)/SMLSL(2)/UMLSL(2)/SQDMULL(2)/SQDMLAL(2)/SQDMLSL(2)
__n128 neon_smull_8(__n64, __n64);
__n128 neon_smull_16(__n64, __n64);
__n128 neon_smull_32(__n64, __n64);
__n128 neon_smull2_8(__n128, __n128);
__n128 neon_smull2_16(__n128, __n128);
__n128 neon_smull2_32(__n128, __n128);
__n128 neon_smull_i16(__n64, __n64, const int);
__n128 neon_smull_i32(__n64, __n64, const int);
__n128 neon_smull2_i16(__n128, __n64, const int);
__n128 neon_smull2_i32(__n128, __n64, const int);
__n128 neon_smull_qi16(__n64, __n128, const int);
__n128 neon_smull_qi32(__n64, __n128, const int);
__n128 neon_smull2_qi16(__n128, __n128, const int);
__n128 neon_smull2_qi32(__n128, __n128, const int);
__n128 neon_umull_8(__n64, __n64);
__n128 neon_umull_16(__n64, __n64);
__n128 neon_umull_32(__n64, __n64);
__n128 neon_umull2_8(__n128, __n128);
__n128 neon_umull2_16(__n128, __n128);
__n128 neon_umull2_32(__n128, __n128);
__n128 neon_umull_i16(__n64, __n64, const int);
__n128 neon_umull_i32(__n64, __n64, const int);
__n128 neon_umull2_i16(__n128, __n64, const int);
__n128 neon_umull2_i32(__n128, __n64, const int);
__n128 neon_umull_qi16(__n64, __n128, const int);
__n128 neon_umull_qi32(__n64, __n128, const int);
__n128 neon_umull2_qi16(__n128, __n128, const int);
__n128 neon_umull2_qi32(__n128, __n128, const int);
#define vmull_s8(src1, src2) neon_smull_8(src1, src2) 
#define vmull_s16(src1, src2) neon_smull_16(src1, src2) 
#define vmull_s32(src1, src2) neon_smull_32(src1, src2) 
#define vmull_high_s8(src1, src2) neon_smull2_8(src1, src2) 
#define vmull_high_s16(src1, src2) neon_smull2_16(src1, src2) 
#define vmull_high_s32(src1, src2) neon_smull2_32(src1, src2) 
#define vmull_lane_s16(src1, src2, src3) neon_smull_i16(src1, src2, src3) 
#define vmull_lane_s32(src1, src2, src3) neon_smull_i32(src1, src2, src3) 
#define vmull_high_lane_s16(src1, src2, src3) neon_smull2_i16(src1, src2, src3) 
#define vmull_high_lane_s32(src1, src2, src3) neon_smull2_i32(src1, src2, src3) 
#define vmull_laneq_s16(src1, src2, src3) neon_smull_qi16(src1, src2, src3) 
#define vmull_laneq_s32(src1, src2, src3) neon_smull_qi32(src1, src2, src3) 
#define vmull_high_laneq_s16(src1, src2, src3) neon_smull2_qi16(src1, src2, src3) 
#define vmull_high_laneq_s32(src1, src2, src3) neon_smull2_qi32(src1, src2, src3) 
#define vmull_u8(src1, src2) neon_umull_8(src1, src2) 
#define vmull_u16(src1, src2) neon_umull_16(src1, src2) 
#define vmull_u32(src1, src2) neon_umull_32(src1, src2) 
#define vmull_high_u8(src1, src2) neon_umull2_8(src1, src2) 
#define vmull_high_u16(src1, src2) neon_umull2_16(src1, src2) 
#define vmull_high_u32(src1, src2) neon_umull2_32(src1, src2) 
#define vmull_lane_u16(src1, src2, src3) neon_umull_i16(src1, src2, src3) 
#define vmull_lane_u32(src1, src2, src3) neon_umull_i32(src1, src2, src3) 
#define vmull_high_lane_u16(src1, src2, src3) neon_umull2_i16(src1, src2, src3) 
#define vmull_high_lane_u32(src1, src2, src3) neon_umull2_i32(src1, src2, src3) 
#define vmull_laneq_u16(src1, src2, src3) neon_umull_qi16(src1, src2, src3) 
#define vmull_laneq_u32(src1, src2, src3) neon_umull_qi32(src1, src2, src3) 
#define vmull_high_laneq_u16(src1, src2, src3) neon_umull2_qi16(src1, src2, src3) 
#define vmull_high_laneq_u32(src1, src2, src3) neon_umull2_qi32(src1, src2, src3) 
#define vmull_n_s16(src1, src2) vmull_lane_s16(src1, vmov_n_s16(src2), 0)
#define vmull_n_s32(src1, src2) vmull_lane_s32(src1, vmov_n_s32(src2), 0)
#define vmull_high_n_s16(src1, src2) vmull_high_lane_s16(src1, vmov_n_s16(src2), 0)
#define vmull_high_n_s32(src1, src2) vmull_high_lane_s32(src1, vmov_n_s32(src2), 0)
#define vmull_n_u16(src1, src2) vmull_lane_u16(src1, vmov_n_u16(src2), 0)
#define vmull_n_u32(src1, src2) vmull_lane_u32(src1, vmov_n_u32(src2), 0)
#define vmull_high_n_u16(src1, src2) vmull_high_lane_u16(src1, vmov_n_u16(src2), 0)
#define vmull_high_n_u32(src1, src2) vmull_high_lane_u32(src1, vmov_n_u32(src2), 0)
__n128 neon_smlal_8(__n128, __n64, __n64);
__n128 neon_smlal_16(__n128, __n64, __n64);
__n128 neon_smlal_32(__n128, __n64, __n64);
__n128 neon_smlal2_8(__n128, __n64, __n128);
__n128 neon_smlal2_16(__n128, __n128, __n128);
__n128 neon_smlal2_32(__n128, __n128, __n128);
__n128 neon_smlal_i16(__n128, __n64, __n64, const int);
__n128 neon_smlal_i32(__n128, __n64, __n64, const int);
__n128 neon_smlal2_i16(__n128, __n128, __n64, const int);
__n128 neon_smlal2_i32(__n128, __n128, __n64, const int);
__n128 neon_smlal_qi16(__n128, __n64, __n128, const int);
__n128 neon_smlal_qi32(__n128, __n64, __n128, const int);
__n128 neon_smlal2_qi16(__n128, __n128, __n128, const int);
__n128 neon_smlal2_qi32(__n128, __n128, __n128, const int);
__n128 neon_umlal_8(__n128, __n64, __n64);
__n128 neon_umlal_16(__n128, __n64, __n64);
__n128 neon_umlal_32(__n128, __n64, __n64);
__n128 neon_umlal2_8(__n128, __n128, __n128);
__n128 neon_umlal2_16(__n128, __n128, __n128);
__n128 neon_umlal2_32(__n128, __n128, __n128);
__n128 neon_umlal_i16(__n128, __n64, __n64, const int);
__n128 neon_umlal_i32(__n128, __n64, __n64, const int);
__n128 neon_umlal2_i16(__n128, __n128, __n64, const int);
__n128 neon_umlal2_i32(__n128, __n128, __n64, const int);
__n128 neon_umlal_qi16(__n128, __n64, __n128, const int);
__n128 neon_umlal_qi32(__n128, __n64, __n128, const int);
__n128 neon_umlal2_qi16(__n128, __n128, __n128, const int);
__n128 neon_umlal2_qi32(__n128, __n128, __n128, const int);
#define vmlal_s8(src1, src2, src3) neon_smlal_8(src1, src2, src3)
#define vmlal_s16(src1, src2, src3) neon_smlal_16(src1, src2, src3)
#define vmlal_s32(src1, src2, src3) neon_smlal_32(src1, src2, src3)
#define vmlal_high_s8(src1, src2, src3) neon_smlal2_8(src1, src2, src3)
#define vmlal_high_s16(src1, src2, src3) neon_smlal2_16(src1, src2, src3)
#define vmlal_high_s32(src1, src2, src3) neon_smlal2_32(src1, src2, src3)
#define vmlal_lane_s16(src1, src2, src3, src4) neon_smlal_i16(src1, src2, src3, src4)
#define vmlal_lane_s32(src1, src2, src3, src4) neon_smlal_i32(src1, src2, src3, src4)
#define vmlal_high_lane_s16(src1, src2, src3, src4) neon_smlal2_i16(src1, src2, src3, src4)
#define vmlal_high_lane_s32(src1, src2, src3, src4) neon_smlal2_i32(src1, src2, src3, src4)
#define vmlal_laneq_s16(src1, src2, src3, src4) neon_smlal_qi16(src1, src2, src3, src4)
#define vmlal_laneq_s32(src1, src2, src3, src4) neon_smlal_qi32(src1, src2, src3, src4)
#define vmlal_high_laneq_s16(src1, src2, src3, src4) neon_smlal2_qi16(src1, src2, src3, src4)
#define vmlal_high_laneq_s32(src1, src2, src3, src4) neon_smlal2_qi32(src1, src2, src3, src4)
#define vmlal_u8(src1, src2, src3) neon_umlal_8(src1, src2, src3)
#define vmlal_u16(src1, src2, src3) neon_umlal_16(src1, src2, src3)
#define vmlal_u32(src1, src2, src3) neon_umlal_32(src1, src2, src3)
#define vmlal_high_u8(src1, src2, src3) neon_umlal2_8(src1, src2, src3)
#define vmlal_high_u16(src1, src2, src3) neon_umlal2_16(src1, src2, src3)
#define vmlal_high_u32(src1, src2, src3) neon_umlal2_32(src1, src2, src3)
#define vmlal_lane_u16(src1, src2, src3, src4) neon_umlal_i16(src1, src2, src3, src4)
#define vmlal_lane_u32(src1, src2, src3, src4) neon_umlal_i32(src1, src2, src3, src4)
#define vmlal_high_lane_u16(src1, src2, src3, src4) neon_umlal2_i16(src1, src2, src3, src4)
#define vmlal_high_lane_u32(src1, src2, src3, src4) neon_umlal2_i32(src1, src2, src3, src4)
#define vmlal_laneq_u16(src1, src2, src3, src4) neon_umlal_qi16(src1, src2, src3, src4)
#define vmlal_laneq_u32(src1, src2, src3, src4) neon_umlal_qi32(src1, src2, src3, src4)
#define vmlal_high_laneq_u16(src1, src2, src3, src4) neon_umlal2_qi16(src1, src2, src3, src4)
#define vmlal_high_laneq_u32(src1, src2, src3, src4) neon_umlal2_qi32(src1, src2, src3, src4)
#define vmlal_n_s16(src1, src2, src3) vmlal_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vmlal_n_s32(src1, src2, src3) vmlal_lane_s32(src1, src2, vmov_n_s32(src3), 0)
#define vmlal_high_n_s16(src1, src2, src3) vmlal_high_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vmlal_high_n_s32(src1, src2, src3) vmlal_high_lane_s32(src1, src2, vmov_n_s32(src3), 0)
#define vmlal_n_u16(src1, src2, src3) vmlal_lane_u16(src1, src2, vmov_n_u16(src3), 0)
#define vmlal_n_u32(src1, src2, src3) vmlal_lane_u32(src1, src2, vmov_n_u32(src3), 0)
#define vmlal_high_n_u16(src1, src2, src3) vmlal_high_lane_u16(src1, src2, vmov_n_u16(src3), 0)
#define vmlal_high_n_u32(src1, src2, src3) vmlal_high_lane_u32(src1, src2, vmov_n_u32(src3), 0)
__n128 neon_smlsl_8(__n128, __n64, __n64);
__n128 neon_smlsl_16(__n128, __n64, __n64);
__n128 neon_smlsl_32(__n128, __n64, __n64);
__n128 neon_smlsl2_8(__n128, __n128, __n128);
__n128 neon_smlsl2_16(__n128, __n128, __n128);
__n128 neon_smlsl2_32(__n128, __n128, __n128);
__n128 neon_smlsl_i16(__n128, __n64, __n64, const int);
__n128 neon_smlsl_i32(__n128, __n64, __n64, const int);
__n128 neon_smlsl2_i16(__n128, __n128, __n64, const int);
__n128 neon_smlsl2_i32(__n128, __n128, __n64, const int);
__n128 neon_smlsl_qi16(__n128, __n64, __n128, const int);
__n128 neon_smlsl_qi32(__n128, __n64, __n128, const int);
__n128 neon_smlsl2_qi16(__n128, __n128, __n128, const int);
__n128 neon_smlsl2_qi32(__n128, __n128, __n128, const int);
__n128 neon_umlsl_8(__n128, __n64, __n64);
__n128 neon_umlsl_16(__n128, __n64, __n64);
__n128 neon_umlsl_32(__n128, __n64, __n64);
__n128 neon_umlsl2_8(__n128, __n128, __n128);
__n128 neon_umlsl2_16(__n128, __n128, __n128);
__n128 neon_umlsl2_32(__n128, __n128, __n128);
__n128 neon_umlsl_i16(__n128, __n64, __n64, const int);
__n128 neon_umlsl_i32(__n128, __n64, __n64, const int);
__n128 neon_umlsl2_i16(__n128, __n128, __n64, const int);
__n128 neon_umlsl2_i32(__n128, __n128, __n64, const int);
__n128 neon_umlsl_qi16(__n128, __n64, __n128, const int);
__n128 neon_umlsl_qi32(__n128, __n64, __n128, const int);
__n128 neon_umlsl2_qi16(__n128, __n128, __n128, const int);
__n128 neon_umlsl2_qi32(__n128, __n128, __n128, const int);
#define vmlsl_s8(src1, src2, src3) neon_smlsl_8(src1, src2, src3)           
#define vmlsl_s16(src1, src2, src3) neon_smlsl_16(src1, src2, src3)           
#define vmlsl_s32(src1, src2, src3) neon_smlsl_32(src1, src2, src3)           
#define vmlsl_high_s8(src1, src2, src3) neon_smlsl2_8(src1, src2, src3)           
#define vmlsl_high_s16(src1, src2, src3) neon_smlsl2_16(src1, src2, src3)           
#define vmlsl_high_s32(src1, src2, src3) neon_smlsl2_32(src1, src2, src3)           
#define vmlsl_lane_s16(src1, src2, src3, src4) neon_smlsl_i16(src1, src2, src3, src4)     
#define vmlsl_lane_s32(src1, src2, src3, src4) neon_smlsl_i32(src1, src2, src3, src4)     
#define vmlsl_high_lane_s16(src1, src2, src3, src4) neon_smlsl2_i16(src1, src2, src3, src4)     
#define vmlsl_high_lane_s32(src1, src2, src3, src4) neon_smlsl2_i32(src1, src2, src3, src4)     
#define vmlsl_laneq_s16(src1, src2, src3, src4) neon_smlsl_qi16(src1, src2, src3, src4)     
#define vmlsl_laneq_s32(src1, src2, src3, src4) neon_smlsl_qi32(src1, src2, src3, src4)     
#define vmlsl_high_laneq_s16(src1, src2, src3, src4) neon_smlsl2_qi16(src1, src2, src3, src4)     
#define vmlsl_high_laneq_s32(src1, src2, src3, src4) neon_smlsl2_qi32(src1, src2, src3, src4)     
#define vmlsl_u8(src1, src2, src3) neon_umlsl_8(src1, src2, src3)           
#define vmlsl_u16(src1, src2, src3) neon_umlsl_16(src1, src2, src3)           
#define vmlsl_u32(src1, src2, src3) neon_umlsl_32(src1, src2, src3)           
#define vmlsl_high_u8(src1, src2, src3) neon_umlsl2_8(src1, src2, src3)           
#define vmlsl_high_u16(src1, src2, src3) neon_umlsl2_16(src1, src2, src3)           
#define vmlsl_high_u32(src1, src2, src3) neon_umlsl2_32(src1, src2, src3)           
#define vmlsl_lane_u16(src1, src2, src3, src4) neon_umlsl_i16(src1, src2, src3, src4)     
#define vmlsl_lane_u32(src1, src2, src3, src4) neon_umlsl_i32(src1, src2, src3, src4)     
#define vmlsl_high_lane_u16(src1, src2, src3, src4) neon_umlsl2_i16(src1, src2, src3, src4)     
#define vmlsl_high_lane_u32(src1, src2, src3, src4) neon_umlsl2_i32(src1, src2, src3, src4)     
#define vmlsl_laneq_u16(src1, src2, src3, src4) neon_umlsl_qi16(src1, src2, src3, src4)     
#define vmlsl_laneq_u32(src1, src2, src3, src4) neon_umlsl_qi32(src1, src2, src3, src4)     
#define vmlsl_high_laneq_u16(src1, src2, src3, src4) neon_umlsl2_qi16(src1, src2, src3, src4)     
#define vmlsl_high_laneq_u32(src1, src2, src3, src4) neon_umlsl2_qi32(src1, src2, src3, src4)     
#define vmlsl_n_s16(src1, src2, src3) vmlsl_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vmlsl_n_s32(src1, src2, src3) vmlsl_lane_s32(src1, src2, vmov_n_s32(src3), 0)
#define vmlsl_high_n_s16(src1, src2, src3) vmlsl_high_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vmlsl_high_n_s32(src1, src2, src3) vmlsl_high_lane_s32(src1, src2, vmov_n_s32(src3), 0)
#define vmlsl_n_u16(src1, src2, src3) vmlsl_lane_u16(src1, src2, vmov_n_u16(src3), 0)
#define vmlsl_n_u32(src1, src2, src3) vmlsl_lane_u32(src1, src2, vmov_n_u32(src3), 0)
#define vmlsl_high_n_u16(src1, src2, src3) vmlsl_high_lane_u16(src1, src2, vmov_n_u16(src3), 0)
#define vmlsl_high_n_u32(src1, src2, src3) vmlsl_high_lane_u32(src1, src2, vmov_n_u32(src3), 0)
__n128 neon_sqdmull_16(__n64, __n64);
__n128 neon_sqdmull_32(__n64, __n64);
__n128 neon_sqdmull2_16(__n128, __n128);
__n128 neon_sqdmull2_32(__n128, __n128);
__n128 neon_sqdmull_i16(__n64, __n64, const int);
__n128 neon_sqdmull_i32(__n64, __n64, const int);
__n128 neon_sqdmull2_i16(__n128, __n64, const int);
__n128 neon_sqdmull2_i32(__n128, __n64, const int);
__n128 neon_sqdmull_qi16(__n64, __n128, const int);
__n128 neon_sqdmull_qi32(__n64, __n128, const int);
__n128 neon_sqdmull2_qi16(__n128, __n128, const int);
__n128 neon_sqdmull2_qi32(__n128, __n128, const int);
#define vqdmull_s16(src1, src2) neon_sqdmull_16(src1, src2)        
#define vqdmull_s32(src1, src2) neon_sqdmull_32(src1, src2)        
#define vqdmull_high_s16(src1, src2) neon_sqdmull2_16(src1, src2)        
#define vqdmull_high_s32(src1, src2) neon_sqdmull2_32(src1, src2)        
#define vqdmull_lane_s16(src1, src2, src3) neon_sqdmull_i16(src1, src2, src3)  
#define vqdmull_lane_s32(src1, src2, src3) neon_sqdmull_i32(src1, src2, src3)  
#define vqdmull_high_lane_s16(src1, src2, src3) neon_sqdmull2_i16(src1, src2, src3)  
#define vqdmull_high_lane_s32(src1, src2, src3) neon_sqdmull2_i32(src1, src2, src3)  
#define vqdmull_laneq_s16(src1, src2, src3) neon_sqdmull_qi16(src1, src2, src3)  
#define vqdmull_laneq_s32(src1, src2, src3) neon_sqdmull_qi32(src1, src2, src3)  
#define vqdmull_high_laneq_s16(src1, src2, src3) neon_sqdmull2_qi16(src1, src2, src3)  
#define vqdmull_high_laneq_s32(src1, src2, src3) neon_sqdmull2_qi32(src1, src2, src3)  
#define vqdmull_n_s16(src1, src2) vqdmull_lane_s16(src1, vmov_n_s16(src2), 0)
#define vqdmull_n_s32(src1, src2) vqdmull_lane_s32(src1, vmov_n_s32(src2), 0)
#define vqdmull_high_n_s16(src1, src2) vqdmull_high_lane_s16(src1, vmov_n_s16(src2), 0)
#define vqdmull_high_n_s32(src1, src2) vqdmull_high_lane_s32(src1, vmov_n_s32(src2), 0)
float neon_sqdmullh_16(__n16, __n16);
__n64 neon_sqdmulls_32(float, float);
float neon_sqdmullh_i16(__n16, __n64, const int);
__n64 neon_sqdmulls_i32(float, __n64, const int);
float neon_sqdmullh_qi16(__n16, __n128, const int);
__n64 neon_sqdmulls_qi32(float, __n128, const int);
__n128 neon_sqdmlal_16(__n128, __n64, __n64);
__n128 neon_sqdmlal_32(__n128, __n64, __n64);
__n128 neon_sqdmlal2_16(__n128, __n128, __n128);
__n128 neon_sqdmlal2_32(__n128, __n128, __n128);
__n128 neon_sqdmlal_i16(__n128, __n64, __n64, const int);
__n128 neon_sqdmlal_i32(__n128, __n64, __n64, const int);
__n128 neon_sqdmlal2_i16(__n128, __n128, __n64, const int);
__n128 neon_sqdmlal2_i32(__n128, __n128, __n64, const int);
__n128 neon_sqdmlal_qi16(__n128, __n64, __n128, const int);
__n128 neon_sqdmlal_qi32(__n128, __n64, __n128, const int);
__n128 neon_sqdmlal2_qi16(__n128, __n128, __n128, const int);
__n128 neon_sqdmlal2_qi32(__n128, __n128, __n128, const int);
#define vqdmullh_s16(src1, src2) neon_sqdmullh_16(src1, src2)             
#define vqdmulls_s32(src1, src2) neon_sqdmulls_32(src1, src2)             
#define vqdmullh_lane_s16(src1, src2, src3) neon_sqdmullh_i16(src1, src2, src3)       
#define vqdmulls_lane_s32(src1, src2, src3) neon_sqdmulls_i32(src1, src2, src3)       
#define vqdmullh_laneq_s16(src1, src2, src3) neon_sqdmullh_qi16(src1, src2, src3)       
#define vqdmulls_laneq_s32(src1, src2, src3) neon_sqdmulls_qi32(src1, src2, src3)       
#define vqdmlal_s16(src1, src2, src3) neon_sqdmlal_16(src1, src2, src3)       
#define vqdmlal_s32(src1, src2, src3) neon_sqdmlal_32(src1, src2, src3)       
#define vqdmlal_high_s16(src1, src2, src3) neon_sqdmlal2_16(src1, src2, src3)       
#define vqdmlal_high_s32(src1, src2, src3) neon_sqdmlal2_32(src1, src2, src3)       
#define vqdmlal_lane_s16(src1, src2, src3, src4) neon_sqdmlal_i16(src1, src2, src3, src4) 
#define vqdmlal_lane_s32(src1, src2, src3, src4) neon_sqdmlal_i32(src1, src2, src3, src4) 
#define vqdmlal_high_lane_s16(src1, src2, src3, src4) neon_sqdmlal2_i16(src1, src2, src3, src4) 
#define vqdmlal_high_lane_s32(src1, src2, src3, src4) neon_sqdmlal2_i32(src1, src2, src3, src4) 
#define vqdmlal_laneq_s16(src1, src2, src3, src4) neon_sqdmlal_qi16(src1, src2, src3, src4) 
#define vqdmlal_laneq_s32(src1, src2, src3, src4) neon_sqdmlal_qi32(src1, src2, src3, src4) 
#define vqdmlal_high_laneq_s16(src1, src2, src3, src4) neon_sqdmlal2_qi16(src1, src2, src3, src4) 
#define vqdmlal_high_laneq_s32(src1, src2, src3, src4) neon_sqdmlal2_qi32(src1, src2, src3, src4) 
#define vqdmlal_n_s16(src1, src2, src3) vqdmlal_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vqdmlal_n_s32(src1, src2, src3) vqdmlal_lane_s32(src1, src2, vmov_n_s32(src3), 0)
#define vqdmlal_high_n_s16(src1, src2, src3) vqdmlal_high_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vqdmlal_high_n_s32(src1, src2, src3) vqdmlal_high_lane_s32(src1, src2, vmov_n_s32(src3), 0)
float  neon_sqdmlalh_16(float, __n16, __n16);
__n64  neon_sqdmlals_32(__n64, float, float);
float  neon_sqdmlalh_i16(float, __n16, __n64, const int);
__n64  neon_sqdmlals_i32(__n64, float, __n64, const int);
float  neon_sqdmlalh_qi16(float, __n16, __n128, const int);
__n64  neon_sqdmlals_qi32(__n64, float, __n128, const int);
__n128 neon_sqdmlsl_16(__n128, __n64, __n64);
__n128 neon_sqdmlsl_32(__n128, __n64, __n64);
__n128 neon_sqdmlsl2_16(__n128, __n128, __n128);
__n128 neon_sqdmlsl2_32(__n128, __n128, __n128);
__n128 neon_sqdmlsl_i16(__n128, __n64, __n64, const int);
__n128 neon_sqdmlsl_i32(__n128, __n64, __n64, const int);
__n128 neon_sqdmlsl2_i16(__n128, __n128, __n64, const int);
__n128 neon_sqdmlsl2_i32(__n128, __n128, __n64, const int);
__n128 neon_sqdmlsl_qi16(__n128, __n64, __n128, const int);
__n128 neon_sqdmlsl_qi32(__n128, __n64, __n128, const int);
__n128 neon_sqdmlsl2_qi16(__n128, __n128, __n128, const int);
__n128 neon_sqdmlsl2_qi32(__n128, __n128, __n128, const int);
#define vqdmlalh_s16(src1, src2, src3) neon_sqdmlalh_16(src1, src2, src3)        
#define vqdmlals_s32(src1, src2, src3) neon_sqdmlals_32(src1, src2, src3)        
#define vqdmlalh_lane_s16(src1, src2, src3, src4) neon_sqdmlalh_i16(src1, src2, src3, src4)  
#define vqdmlals_lane_s32(src1, src2, src3, src4) neon_sqdmlals_i32(src1, src2, src3, src4)  
#define vqdmlalh_laneq_s16(src1, src2, src3, src4) neon_sqdmlalh_qi16(src1, src2, src3, src4)  
#define vqdmlals_laneq_s32(src1, src2, src3, src4) neon_sqdmlals_qi32(src1, src2, src3, src4)  
#define vqdmlsl_s16(src1, src2, src3) neon_sqdmlsl_16(src1, src2, src3)        
#define vqdmlsl_s32(src1, src2, src3) neon_sqdmlsl_32(src1, src2, src3)        
#define vqdmlsl_high_s16(src1, src2, src3) neon_sqdmlsl2_16(src1, src2, src3)        
#define vqdmlsl_high_s32(src1, src2, src3) neon_sqdmlsl2_32(src1, src2, src3)        
#define vqdmlsl_lane_s16(src1, src2, src3, src4) neon_sqdmlsl_i16(src1, src2, src3, src4)  
#define vqdmlsl_lane_s32(src1, src2, src3, src4) neon_sqdmlsl_i32(src1, src2, src3, src4)  
#define vqdmlsl_high_lane_s16(src1, src2, src3, src4) neon_sqdmlsl2_i16(src1, src2, src3, src4)  
#define vqdmlsl_high_lane_s32(src1, src2, src3, src4) neon_sqdmlsl2_i32(src1, src2, src3, src4)  
#define vqdmlsl_laneq_s16(src1, src2, src3, src4) neon_sqdmlsl_qi16(src1, src2, src3, src4)  
#define vqdmlsl_laneq_s32(src1, src2, src3, src4) neon_sqdmlsl_qi32(src1, src2, src3, src4)  
#define vqdmlsl_high_laneq_s16(src1, src2, src3, src4) neon_sqdmlsl2_qi16(src1, src2, src3, src4)  
#define vqdmlsl_high_laneq_s32(src1, src2, src3, src4) neon_sqdmlsl2_qi32(src1, src2, src3, src4)  
#define vqdmlsl_n_s16(src1, src2, src3) vqdmlsl_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vqdmlsl_n_s32(src1, src2, src3) vqdmlsl_lane_s32(src1, src2, vmov_n_s32(src3), 0)
#define vqdmlsl_high_n_s16(src1, src2, src3) vqdmlsl_high_lane_s16(src1, src2, vmov_n_s16(src3), 0)
#define vqdmlsl_high_n_s32(src1, src2, src3) vqdmlsl_high_lane_s32(src1, src2, vmov_n_s32(src3), 0)
float neon_sqdmlslh_16(float, __n16, __n16);
__n64 neon_sqdmlsls_32(__n64, float, float);
float neon_sqdmlslh_i16(float, __n16, __n64, const int);
__n64 neon_sqdmlsls_i32(__n64, float, __n64, const int);
float neon_sqdmlslh_qi16(float, __n16, __n128, const int);
__n64 neon_sqdmlsls_qi32(__n64, float, __n128, const int);
#define vqdmlslh_s16(src1, src2, src3) neon_sqdmlslh_16(src1, src2, src3)      
#define vqdmlsls_s32(src1, src2, src3) neon_sqdmlsls_32(src1, src2, src3)      
#define vqdmlslh_lane_s16(src1, src2, src3, src) neon_sqdmlslh_i16(src1, src2, src3, src) 
#define vqdmlsls_lane_s32(src1, src2, src3, src) neon_sqdmlsls_i32(src1, src2, src3, src) 
#define vqdmlslh_laneq_s16(src1, src2, src3, src) neon_sqdmlslh_qi16(src1, src2, src3, src) 
#define vqdmlsls_laneq_s32(src1, src2, src3, src) neon_sqdmlsls_qi32(src1, src2, src3, src) 

// CMEQ/CMGE/CMGT/CMHI/CMHS/CMLE/CMLT/CMTST/FACGE/FACGT/FCMEQ/FCMGE/FCMGT/FCMLE/FCMLT/
__n64 neon_facge32(__n64, __n64);
__n128 neon_facgeq32(__n128, __n128);
__n128 neon_facgeq64(__n128, __n128);
float neon_facges32(float, float);
double neon_facges64(double, double);
__n64 neon_facgt32(__n64, __n64);
__n128 neon_facgtq32(__n128, __n128);
__n128 neon_facgtq64(__n128, __n128);
float neon_facgts32(float, float);
double neon_facgts64(double, double);
__n64 neon_fcmeq32(__n64, __n64);
__n128 neon_fcmeqq32(__n128, __n128);
__n128 neon_fcmeqq64(__n128, __n128);
__n64 neon_fcmeqz32(__n64);
__n128 neon_fcmeqzq32(__n128);
__n128 neon_fcmeqzq64(__n128);
float neon_fcmeqs32(float, float);
double neon_fcmeqs64(double, double);
float neon_fcmeqzs32(float);
double neon_fcmeqzs64(double);
__n64 neon_fcmge32(__n64, __n64);
__n128 neon_fcmgeq32(__n128, __n128);
__n128 neon_fcmgeq64(__n128, __n128);
__n64 neon_fcmgez32(__n64);
__n128 neon_fcmgezq32(__n128);
__n128 neon_fcmgezq64(__n128);
float neon_fcmges32(float, float);
double neon_fcmges64(double, double);
float neon_fcmgezs32(float);
double neon_fcmgezs64(double);
__n64 neon_fcmgt32(__n64, __n64);
__n128 neon_fcmgtq32(__n128, __n128);
__n128 neon_fcmgtq64(__n128, __n128);
__n64 neon_fcmgtz32(__n64);
__n128 neon_fcmgtzq32(__n128);
__n128 neon_fcmgtzq64(__n128);
float neon_fcmgts32(float, float);
double neon_fcmgts64(double, double);
float neon_fcmgtzs32(float);
double neon_fcmgtzs64(double);
__n64 neon_fcmlez32(__n64);
__n128 neon_fcmlezq32(__n128);
__n128 neon_fcmlezq64(__n128);
float neon_fcmlezs32(float);
double neon_fcmlezs64(double);
__n64 neon_fcmltz32(__n64);
__n128 neon_fcmltzq32(__n128);
__n128 neon_fcmltzq64(__n128);
float neon_fcmltzs32(float);
double neon_fcmltzs64(double);
__n64 neon_cmeq8(__n64, __n64);
__n128 neon_cmeqq8(__n128, __n128);
__n64 neon_cmeq16(__n64, __n64);
__n128 neon_cmeqq16(__n128, __n128);
__n64 neon_cmeq32(__n64, __n64);
__n128 neon_cmeqq32(__n128, __n128);
__n128 neon_cmeqq64(__n128, __n128);
__n64 neon_cmeqz8(__n64);
__n128 neon_cmeqzq8(__n128);
__n64 neon_cmeqz16(__n64);
__n128 neon_cmeqzq16(__n128);
__n64 neon_cmeqz32(__n64);
__n128 neon_cmeqzq32(__n128);
__n128 neon_cmeqzq64(__n128);
double neon_cmeqs64(double, double);
double neon_cmeqzs64(double);
__n64 neon_cmge8(__n64, __n64);
__n128 neon_cmgeq8(__n128, __n128);
__n64 neon_cmge16(__n64, __n64);
__n128 neon_cmgeq16(__n128, __n128);
__n64 neon_cmge32(__n64, __n64);
__n128 neon_cmgeq32(__n128, __n128);
__n128 neon_cmgeq64(__n128, __n128);
__n64 neon_cmgez8(__n64);
__n128 neon_cmgezq8(__n128);
__n64 neon_cmgez16(__n64);
__n128 neon_cmgezq16(__n128);
__n64 neon_cmgez32(__n64);
__n128 neon_cmgezq32(__n128);
__n128 neon_cmgezq64(__n128);
double neon_cmges64(double, double);
double neon_cmgezs64(double);
__n64 neon_cmgt8(__n64, __n64);
__n128 neon_cmgtq8(__n128, __n128);
__n64 neon_cmgt16(__n64, __n64);
__n128 neon_cmgtq16(__n128, __n128);
__n64 neon_cmgt32(__n64, __n64);
__n128 neon_cmgtq32(__n128, __n128);
__n128 neon_cmgtq64(__n128, __n128);
__n64 neon_cmgtz8(__n64);
__n128 neon_cmgtzq8(__n128);
__n64 neon_cmgtz16(__n64);
__n128 neon_cmgtzq16(__n128);
__n64 neon_cmgtz32(__n64);
__n128 neon_cmgtzq32(__n128);
__n128 neon_cmgtzq64(__n128);
double neon_cmgts64(double, double);
double neon_cmgtzs64(double);
__n64 neon_cmhi8(__n64, __n64);
__n128 neon_cmhiq8(__n128, __n128);
__n64 neon_cmhi16(__n64, __n64);
__n128 neon_cmhiq16(__n128, __n128);
__n64 neon_cmhi32(__n64, __n64);
__n128 neon_cmhiq32(__n128, __n128);
__n128 neon_cmhiq64(__n128, __n128);
double neon_cmhis64(double, double);
__n64 neon_cmhs8(__n64, __n64);
__n128 neon_cmhsq8(__n128, __n128);
__n64 neon_cmhs16(__n64, __n64);
__n128 neon_cmhsq16(__n128, __n128);
__n64 neon_cmhs32(__n64, __n64);
__n128 neon_cmhsq32(__n128, __n128);
__n128 neon_cmhsq64(__n128, __n128);
double neon_cmhss64(double, double);
__n64 neon_cmlez8(__n64);
__n128 neon_cmlezq8(__n128);
__n64 neon_cmlez16(__n64);
__n128 neon_cmlezq16(__n128);
__n64 neon_cmlez32(__n64);
__n128 neon_cmlezq32(__n128);
__n128 neon_cmlezq64(__n128);
double neon_cmlezs64(double);
__n64 neon_cmltz8(__n64);
__n128 neon_cmltzq8(__n128);
__n64 neon_cmltz16(__n64);
__n128 neon_cmltzq16(__n128);
__n64 neon_cmltz32(__n64);
__n128 neon_cmltzq32(__n128);
__n128 neon_cmltzq64(__n128);
double neon_cmltzs64(double);
__n64 neon_cmtst8(__n64, __n64);
__n128 neon_cmtstq8(__n128, __n128);
__n64 neon_cmtst16(__n64, __n64);
__n128 neon_cmtstq16(__n128, __n128);
__n64 neon_cmtst32(__n64, __n64);
__n128 neon_cmtstq32(__n128, __n128);
__n128 neon_cmtstq64(__n128, __n128);
double neon_cmtsts64(double, double);
#define vceq_z_f32_ex(src) neon_fcmeqz32(src)
#define vceq_z_s16_ex(src) neon_cmeqz16(src)
#define vceq_z_s32_ex(src) neon_cmeqz32(src)
#define vceq_z_s8_ex(src) neon_cmeqz8(src)
#define vceq_z_u16_ex(src) neon_cmeqz16(src)
#define vceq_z_u32_ex(src) neon_cmeqz32(src)
#define vceq_z_u8_ex(src) neon_cmeqz8(src)
#define vceqq_z_f32_ex(src) neon_fcmeqzq32(src)
#define vceqq_z_s16_ex(src) neon_cmeqzq16(src)
#define vceqq_z_s32_ex(src) neon_cmeqzq32(src)
#define vceqq_z_s8_ex(src) neon_cmeqzq8(src)
#define vceqq_z_u16_ex(src) neon_cmeqzq16(src)
#define vceqq_z_u32_ex(src) neon_cmeqzq32(src)
#define vceqq_z_u8_ex(src) neon_cmeqzq8(src)
#define vceq_f32(src1, src2) neon_fcmeq32(src1, src2)
#define vceq_p8(src1, src2) neon_cmeq8(src1, src2)
#define vceq_s16(src1, src2) neon_cmeq16(src1, src2)
#define vceq_s32(src1, src2) neon_cmeq32(src1, src2)
#define vceq_s8(src1, src2) neon_cmeq8(src1, src2)
#define vceq_u16(src1, src2) neon_cmeq16(src1, src2)
#define vceq_u32(src1, src2) neon_cmeq32(src1, src2)
#define vceq_u8(src1, src2) neon_cmeq8(src1, src2)
#define vceqq_f32(src1, src2) neon_fcmeqq32(src1, src2)
#define vceqq_p8(src1, src2) neon_cmeqq8(src1, src2)
#define vceqq_s16(src1, src2) neon_cmeqq16(src1, src2)
#define vceqq_s32(src1, src2) neon_cmeqq32(src1, src2)
#define vceqq_s8(src1, src2) neon_cmeqq8(src1, src2)
#define vceqq_u16(src1, src2) neon_cmeqq16(src1, src2)
#define vceqq_u32(src1, src2) neon_cmeqq32(src1, src2)
#define vceqq_u8(src1, src2) neon_cmeqq8(src1, src2)
#define vcge_z_f32_ex(src) neon_fcmgez32(src)
#define vcge_z_s16_ex(src) neon_cmgez16(src)
#define vcge_z_s32_ex(src) neon_cmgez32(src)
#define vcge_z_s8_ex(src) neon_cmgez8(src)
#define vcge_z_u16_ex(src) neon_cmgez16(src)
#define vcge_z_u32_ex(src) neon_cmgez32(src)
#define vcge_z_u8_ex(src) neon_cmgez8(src)
#define vcgeq_z_f32_ex(src) neon_fcmgezq32(src)
#define vcgeq_z_s16_ex(src) neon_cmgezq16(src)
#define vcgeq_z_s32_ex(src) neon_cmgezq32(src)
#define vcgeq_z_s8_ex(src) neon_cmgezq8(src)
#define vcgeq_z_u16_ex(src) neon_cmgezq16(src)
#define vcgeq_z_u32_ex(src) neon_cmgezq32(src)
#define vcgeq_z_u8_ex(src) neon_cmgezq8(src)
#define vcge_f32(src1, src2) neon_fcmge32(src1, src2)
#define vcge_p8(src1, src2) neon_cmge8(src1, src2)
#define vcge_s16(src1, src2) neon_cmge16(src1, src2)
#define vcge_s32(src1, src2) neon_cmge32(src1, src2)
#define vcge_s8(src1, src2) neon_cmge8(src1, src2)
#define vcge_u16(src1, src2) neon_cmge16(src1, src2)
#define vcge_u32(src1, src2) neon_cmge32(src1, src2)
#define vcge_u8(src1, src2) neon_cmge8(src1, src2)
#define vcgeq_f32(src1, src2) neon_fcmgeq32(src1, src2)
#define vcgeq_p8(src1, src2) neon_cmgeq8(src1, src2)
#define vcgeq_s16(src1, src2) neon_cmgeq16(src1, src2)
#define vcgeq_s32(src1, src2) neon_cmgeq32(src1, src2)
#define vcgeq_s8(src1, src2) neon_cmgeq8(src1, src2)
#define vcgeq_u16(src1, src2) neon_cmgeq16(src1, src2)
#define vcgeq_u32(src1, src2) neon_cmgeq32(src1, src2)
#define vcgeq_u8(src1, src2) neon_cmgeq8(src1, src2)
#define vcle_z_f32_ex(src) neon_fcmlez32(src)
#define vcle_z_s16_ex(src) neon_cmlez16(src)
#define vcle_z_s32_ex(src) neon_cmlez32(src)
#define vcle_z_s8_ex(src) neon_cmlez8(src)
#define vcleq_z_f32_ex(src) neon_fcmlezq32(src)
#define vcleq_z_s16_ex(src) neon_cmlezq16(src)
#define vcleq_z_s32_ex(src) neon_cmlezq32(src)
#define vcleq_z_s8_ex(src) neon_cmlezq8(src)
// vcle register form is alias with vcge with reversed operands
#define vcle_f32(src1, src2) neon_fcmge32(src2, src1)
#define vcle_p8(src1, src2) neon_cmge8(src2, src1)
#define vcle_s16(src1, src2) neon_cmge16(src2, src1)
#define vcle_s32(src1, src2) neon_cmge32(src2, src1)
#define vcle_s8(src1, src2) neon_cmge8(src2, src1)
#define vcle_u16(src1, src2) neon_cmge16(src2, src1)
#define vcle_u32(src1, src2) neon_cmge32(src2, src1)
#define vcle_u8(src1, src2) neon_cmge8(src2, src1)
#define vcleq_f32(src1, src2) neon_fcmgeq32(src2, src1)
#define vcleq_p8(src1, src2) neon_cmgeq8(src2, src1)
#define vcleq_s16(src1, src2) neon_cmgeq16(src2, src1)
#define vcleq_s32(src1, src2) neon_cmgeq32(src2, src1)
#define vcleq_s8(src1, src2) neon_cmgeq8(src2, src1)
#define vcleq_u16(src1, src2) neon_cmgeq16(src2, src1)
#define vcleq_u32(src1, src2) neon_cmgeq32(src2, src1)
#define vcleq_u8(src1, src2) neon_cmgeq8(src2, src1)
#define vcgt_z_f32_ex(src) neon_fcmgtz32(src)
#define vcgt_z_s16_ex(src) neon_cmgtz16(src)
#define vcgt_z_s32_ex(src) neon_cmgtz32(src)
#define vcgt_z_s8_ex(src) neon_cmgtz8(src)
#define vcgt_z_u16_ex(src) neon_cmgtz16(src)
#define vcgt_z_u32_ex(src) neon_cmgtz32(src)
#define vcgt_z_u8_ex(src) neon_cmgtz8(src)
#define vcgtq_z_f32_ex(src) neon_fcmgtzq32(src)
#define vcgtq_z_s16_ex(src) neon_cmgtzq16(src)
#define vcgtq_z_s32_ex(src) neon_cmgtzq32(src)
#define vcgtq_z_s8_ex(src) neon_cmgtzq8(src)
#define vcgtq_z_u16_ex(src) neon_cmgtzq16(src)
#define vcgtq_z_u32_ex(src) neon_cmgtzq32(src)
#define vcgtq_z_u8_ex(src) neon_cmgtzq8(src)
#define vcgt_f32(src1, src2) neon_fcmgt32(src1, src2)
#define vcgt_p8(src1, src2) neon_cmgt8(src1, src2)
#define vcgt_s16(src1, src2) neon_cmgt16(src1, src2)
#define vcgt_s32(src1, src2) neon_cmgt32(src1, src2)
#define vcgt_s8(src1, src2) neon_cmgt8(src1, src2)
#define vcgt_u16(src1, src2) neon_cmgt16(src1, src2)
#define vcgt_u32(src1, src2) neon_cmgt32(src1, src2)
#define vcgt_u8(src1, src2) neon_cmgt8(src1, src2)
#define vcgtq_f32(src1, src2) neon_fcmgtq32(src1, src2)
#define vcgtq_p8(src1, src2) neon_cmgtq8(src1, src2)
#define vcgtq_s16(src1, src2) neon_cmgtq16(src1, src2)
#define vcgtq_s32(src1, src2) neon_cmgtq32(src1, src2)
#define vcgtq_s8(src1, src2) neon_cmgtq8(src1, src2)
#define vcgtq_u16(src1, src2) neon_cmgtq16(src1, src2)
#define vcgtq_u32(src1, src2) neon_cmgtq32(src1, src2)
#define vcgtq_u8(src1, src2) neon_cmgtq8(src1, src2)
#define vclt_z_f32_ex(src) neon_fcmltz32(src)
#define vclt_z_s16_ex(src) neon_cmltz16(src)
#define vclt_z_s32_ex(src) neon_cmltz32(src)
#define vclt_z_s8_ex(src) neon_cmltz8(src)
#define vcltq_z_f32_ex(src) neon_fcmltzq32(src)
#define vcltq_z_s16_ex(src) neon_cmltzq16(src)
#define vcltq_z_s32_ex(src) neon_cmltzq32(src)
#define vcltq_z_s8_ex(src) neon_cmltzq8(src)
// vclt register form is alias with vcgt with reversed operands
#define vclt_f32(src1, src2) neon_fcmgt32(src2, src1)
#define vclt_p8(src1, src2) neon_cmgt8(src2, src1)
#define vclt_s16(src1, src2) neon_cmgt16(src2, src1)
#define vclt_s32(src1, src2) neon_cmgt32(src2, src1)
#define vclt_s8(src1, src2) neon_cmgt8(src2, src1)
#define vclt_u16(src1, src2) neon_cmgt16(src2, src1)
#define vclt_u32(src1, src2) neon_cmgt32(src2, src1)
#define vclt_u8(src1, src2) neon_cmgt8(src2, src1)
#define vcltq_f32(src1, src2) neon_fcmgtq32(src2, src1)
#define vcltq_p8(src1, src2) neon_cmgtq8(src2, src1)
#define vcltq_s16(src1, src2) neon_cmgtq16(src2, src1)
#define vcltq_s32(src1, src2) neon_cmgtq32(src2, src1)
#define vcltq_s8(src1, src2) neon_cmgtq8(src2, src1)
#define vcltq_u16(src1, src2) neon_cmgtq16(src2, src1)
#define vcltq_u32(src1, src2) neon_cmgtq32(src2, src1)
#define vcltq_u8(src1, src2) neon_cmgtq8(src2, src1)
#define vacge_f32(src1, src2) neon_facge32(src1, src2)
#define vacgt_f32(src1, src2) neon_facgt32(src1, src2)
// vacle register form is alias with vacge with operands reversed
#define vacle_f32(src1, src2) neon_facge32(src2, src1)
#define vaclt_f32(src1, src2) neon_facgt32(src2, src1)
#define vacgeq_f32(src1, src2) neon_facgeq32(src1, src2)
#define vacgtq_f32(src1, src2) neon_facgtq32(src1, src2)
#define vacleq_f32(src1, src2) neon_facgeq32(src2, src1)
#define vacltq_f32(src1, src2) neon_facgtq32(src2, src1)

// FCVTAS/FCVTAU/FCVTMS/FCVTMU/FCVTNS/FCVTPS/FCVTPU/FCVTZS/FCVTZU/SCVTF/UCVTF
__n64  neon_fcvtas32(__n64);
__n128 neon_fcvtasq32(__n128);
__n128 neon_fcvtasq64(__n128);
float  neon_fcvtass32(float);
double neon_fcvtass64(double);
__n64  neon_fcvtau32(__n64);
__n128 neon_fcvtauq32(__n128);
__n128 neon_fcvtauq64(__n128);
float  neon_fcvtaus32(float);
double neon_fcvtaus64(double);
__n64  neon_fcvtms32(__n64);
__n128 neon_fcvtmsq32(__n128);
__n128 neon_fcvtmsq64(__n128);
float  neon_fcvtmss32(float);
double neon_fcvtmss64(double);
__n64  neon_fcvtmu32(__n64);
__n128 neon_fcvtmuq32(__n128);
__n128 neon_fcvtmuq64(__n128);
float  neon_fcvtmus32(float);
double neon_fcvtmus64(double);
__n64  neon_fcvtns32(__n64);
__n128 neon_fcvtnsq32(__n128);
__n128 neon_fcvtnsq64(__n128);
float  neon_fcvtnss32(float);
double neon_fcvtnss64(double);
__n64  neon_fcvtnu32(__n64);
__n128 neon_fcvtnuq32(__n128);
__n128 neon_fcvtnuq64(__n128);
float  neon_fcvtnus32(float);
double neon_fcvtnus64(double);
__n64  neon_fcvtps32(__n64);
__n128 neon_fcvtpsq32(__n128);
__n128 neon_fcvtpsq64(__n128);
float  neon_fcvtpss32(float);
double neon_fcvtpss64(double);
__n64  neon_fcvtpu32(__n64);
__n128 neon_fcvtpuq32(__n128);
__n128 neon_fcvtpuq64(__n128);
float  neon_fcvtpus32(float);
double neon_fcvtpus64(double);
__n64  neon_fcvtzs32(__n64);
__n128 neon_fcvtzsq32(__n128);
__n128 neon_fcvtzsq64(__n128);
float  neon_fcvtzss32(float);
double neon_fcvtzss64(double);
__n64  neon_fcvtzu32(__n64);
__n128 neon_fcvtzuq32(__n128);
__n128 neon_fcvtzuq64(__n128);
float  neon_fcvtzus32(float);
double neon_fcvtzus64(double);
__n64  neon_scvtf32(__n64);
__n128 neon_scvtfq32(__n128);
__n128 neon_scvtfq64(__n128);
float  neon_scvtfs32(float);
double neon_scvtfs64(double);
__n64  neon_ucvtf32(__n64);
__n128 neon_ucvtfq32(__n128);
__n128 neon_ucvtfq64(__n128);
float  neon_ucvtfs32(float);
double neon_ucvtfs64(double);
__n64  neon_fcvtzsfp32(__n64, const int);
__n128 neon_fcvtzsfpq32(__n128, const int);
__n128 neon_fcvtzsfpq64(__n128, const int);
float  neon_fcvtzsfps32(float, const int);
double neon_fcvtzsfps64(double, const int);
__n64  neon_fcvtzufp32(__n64, const int);
__n128 neon_fcvtzufpq32(__n128, const int);
__n128 neon_fcvtzufpq64(__n128, const int);
float  neon_fcvtzufps32(float, const int);
double neon_fcvtzufps64(double, const int);
__n64  neon_scvtffp32(__n64, const int);
__n128 neon_scvtffpq32(__n128, const int);
__n128 neon_scvtffpq64(__n128, const int);
float  neon_scvtffps32(float, const int);
double neon_scvtffps64(double, const int);
__n64  neon_ucvtffp32(__n64, const int);
__n128 neon_ucvtffpq32(__n128, const int);
__n128 neon_ucvtffpq64(__n128, const int);
float  neon_ucvtffps32(float, const int);
double neon_ucvtffps64(double, const int);
#define vcvt_n_f32_s32(src1, src2)  neon_scvtffp32(src1, src2)
#define vcvt_n_f32_u32(src1, src2)  neon_ucvtffp32(src1, src2)
#define vcvt_n_s32_f32(src1, src2)  neon_fcvtzsfp32(src1, src2)
#define vcvt_n_u32_f32(src1, src2)  neon_fcvtzufp32(src1, src2)
#define vcvtq_n_f32_s32(src1, src2) neon_scvtffpq32(src1, src2)
#define vcvtq_n_f32_u32(src1, src2) neon_ucvtffpq32(src1, src2)
#define vcvtq_n_s32_f32(src1, src2) neon_fcvtzsfpq32(src1, src2)
#define vcvtq_n_u32_f32(src1, src2) neon_fcvtzufpq32(src1, src2)
#define vcvta_s32_f32(src)  neon_fcvtas32(src)
#define vcvta_u32_f32(src)  neon_fcvtau32(src)
#define vcvtm_s32_f32(src)  neon_fcvtms32(src)
#define vcvtm_u32_f32(src)  neon_fcvtmu32(src)
#define vcvtn_s32_f32(src)  neon_fcvtns32(src)
#define vcvtn_u32_f32(src)  neon_fcvtnu32(src)
#define vcvtp_s32_f32(src)  neon_fcvtps32(src)
#define vcvtp_u32_f32(src)  neon_fcvtpu32(src)
#define vcvtaq_s32_f32(src) neon_fcvtasq32(src)
#define vcvtaq_u32_f32(src) neon_fcvtauq32(src)
#define vcvtmq_s32_f32(src) neon_fcvtmsq32(src)
#define vcvtmq_u32_f32(src) neon_fcvtmuq32(src)
#define vcvtnq_s32_f32(src) neon_fcvtnsq32(src)
#define vcvtnq_u32_f32(src) neon_fcvtnuq32(src)
#define vcvtpq_s32_f32(src) neon_fcvtpsq32(src)
#define vcvtpq_u32_f32(src) neon_fcvtpuq32(src)
#define vcvt_f32_s32(src)  neon_scvtf32(src)
#define vcvt_f32_u32(src)  neon_ucvtf32(src)
#define vcvt_s32_f32(src)  neon_fcvtzs32(src)
#define vcvt_u32_f32(src)  neon_fcvtzu32(src)
#define vcvtq_f32_s32(src) neon_scvtfq32(src)
#define vcvtq_f32_u32(src) neon_ucvtfq32(src)
#define vcvtq_s32_f32(src) neon_fcvtzsq32(src)
#define vcvtq_u32_f32(src) neon_fcvtzuq32(src)

// FRECPE/FRECPS/FRECPX/URECPE
__n64  neon_frecpe32 (__n64);
__n128 neon_frecpeq32(__n128);
__n128 neon_frecpeq64(__n128);
float  neon_frecpes32(float);
double neon_frecpes64(double);
__n64  neon_frecps32 (__n64, __n64);
__n128 neon_frecpsq32(__n128, __n128);
__n128 neon_frecpsq64(__n128, __n128);
float  neon_frecpss32(float, float);
double neon_frecpss64(double, double);
__n64  neon_urecpe32 (__n64);
__n128 neon_urecpeq32(__n128);
float  neon_frecpx32(float);
double neon_frecpx64(double);
#define vrecpe_f32(src)         neon_frecpe32(src)
#define vrecpe_u32(src)         neon_urecpe32(src)
#define vrecpeq_f32(src)        neon_frecpeq32(src)
#define vrecpeq_u32(src)        neon_urecpeq32(src)
#define vrecps_f32(src1, src2)  neon_frecps32(src1, src2)
#define vrecpsq_f32(src1, src2) neon_frecpsq32(src1, src2)

// ZIP1/ZIP2/UZP1/UZP2/TRN1/TRN2
__n64 neon_zip1_8(__n64 _Dd, __n64 _Dm);
__n128 neon_zip1_q8(__n128 _Qd, __n128 _Qm);
__n64 neon_zip1_16(__n64 _Dd, __n64 _Dm);
__n128 neon_zip1_q16(__n128 _Qd, __n128 _Qm);
__n64 neon_zip1_32(__n64 _Dd, __n64 _Dm);
__n128 neon_zip1_q32(__n128 _Qd, __n128 _Qm);
__n128 neon_zip1_q64(__n128 _Qd, __n128 _Qm);
__n64 neon_zip2_8(__n64 _Dd, __n64 _Dm);
__n128 neon_zip2_q8(__n128 _Qd, __n128 _Qm);
__n64 neon_zip2_16(__n64 _Dd, __n64 _Dm);
__n128 neon_zip2_q16(__n128 _Qd, __n128 _Qm);
__n64 neon_zip2_32(__n64 _Dd, __n64 _Dm);
__n128 neon_zip2_q32(__n128 _Qd, __n128 _Qm);
__n128 neon_zip2_q64(__n128 _Qd, __n128 _Qm);
__n64 neon_uzp1_8(__n64 _Dd, __n64 _Dm);
__n128 neon_uzp1_q8(__n128 _Qd, __n128 _Qm);
__n64 neon_uzp1_16(__n64 _Dd, __n64 _Dm);
__n128 neon_uzp1_q16(__n128 _Qd, __n128 _Qm);
__n64 neon_uzp1_32(__n64 _Dd, __n64 _Dm);
__n128 neon_uzp1_q32(__n128 _Qd, __n128 _Qm);
__n128 neon_uzp1_q64(__n128 _Qd, __n128 _Qm);
__n64 neon_uzp2_8(__n64 _Dd, __n64 _Dm);
__n128 neon_uzp2_q8(__n128 _Qd, __n128 _Qm);
__n64 neon_uzp2_16(__n64 _Dd, __n64 _Dm);
__n128 neon_uzp2_q16(__n128 _Qd, __n128 _Qm);
__n64 neon_uzp2_32(__n64 _Dd, __n64 _Dm);
__n128 neon_uzp2_q32(__n128 _Qd, __n128 _Qm);
__n128 neon_uzp2_q64(__n128 _Qd, __n128 _Qm);
__n64 neon_trn1_8(__n64 _Dd, __n64 _Dm);
__n128 neon_trn1_q8(__n128 _Qd, __n128 _Qm);
__n64 neon_trn1_16(__n64 _Dd, __n64 _Dm);
__n128 neon_trn1_q16(__n128 _Qd, __n128 _Qm);
__n64 neon_trn1_32(__n64 _Dd, __n64 _Dm);
__n128 neon_trn1_q32(__n128 _Qd, __n128 _Qm);
__n128 neon_trn1_q64(__n128 _Qd, __n128 _Qm);
__n64 neon_trn2_8(__n64 _Dd, __n64 _Dm);
__n128 neon_trn2_q8(__n128 _Qd, __n128 _Qm);
__n64 neon_trn2_16(__n64 _Dd, __n64 _Dm);
__n128 neon_trn2_q16(__n128 _Qd, __n128 _Qm);
__n64 neon_trn2_32(__n64 _Dd, __n64 _Dm);
__n128 neon_trn2_q32(__n128 _Qd, __n128 _Qm);
__n128 neon_trn2_q64(__n128 _Qd, __n128 _Qm);
__n64x2 neon_zip_8(__n64 _Dd, __n64 _Dm);
__n128x2 neon_zip_q8(__n128 _Qd, __n128 _Qm);
__n64x2 neon_zip_16(__n64 _Dd, __n64 _Dm);
__n128x2 neon_zip_q16(__n128 _Qd, __n128 _Qm);
__n64x2 neon_zip_32(__n64 _Dd, __n64 _Dm);
__n128x2 neon_zip_q32(__n128 _Qd, __n128 _Qm);
__n128x2 neon_zip_q64(__n128 _Qd, __n128 _Qm);
__n64x2 neon_uzp_8(__n64 _Dd, __n64 _Dm);
__n128x2 neon_uzp_q8(__n128 _Qd, __n128 _Qm);
__n64x2 neon_uzp_16(__n64 _Dd, __n64 _Dm);
__n128x2 neon_uzp_q16(__n128 _Qd, __n128 _Qm);
__n64x2 neon_uzp_32(__n64 _Dd, __n64 _Dm);
__n128x2 neon_uzp_q32(__n128 _Qd, __n128 _Qm);
__n128x2 neon_uzp_q64(__n128 _Qd, __n128 _Qm);
__n64x2 neon_trn_8(__n64 _Dd, __n64 _Dm);
__n128x2 neon_trn_q8(__n128 _Qd, __n128 _Qm);
__n64x2 neon_trn_16(__n64 _Dd, __n64 _Dm);
__n128x2 neon_trn_q16(__n128 _Qd, __n128 _Qm);
__n64x2 neon_trn_32(__n64 _Dd, __n64 _Dm);
__n128x2 neon_trn_q32(__n128 _Qd, __n128 _Qm);
__n128x2 neon_trn_q64(__n128 _Qd, __n128 _Qm);
#define vzip_p16(src1, src2) neon_zip_16(src1, src2)
#define vzip_p8(src1, src2) neon_zip_8(src1, src2)
#define vzip_s16(src1, src2) neon_zip_16(src1, src2)
#define vzip_s8(src1, src2) neon_zip_8(src1, src2)
#define vzip_u16(src1, src2) neon_zip_16(src1, src2)
#define vzip_u8(src1, src2) neon_zip_8(src1, src2)
#define vzip_f32(src1, src2) neon_zip_32(src1, src2)
#define vzip_s32(src1, src2) neon_zip_32(src1, src2)
#define vzip_u32(src1, src2) neon_zip_32(src1, src2)
#define vzipq_f32(src1, src2) neon_zip_q32(src1, src2)
#define vzipq_p16(src1, src2) neon_zip_q16(src1, src2)
#define vzipq_p8(src1, src2) neon_zip_q8(src1, src2)
#define vzipq_s16(src1, src2) neon_zip_q16(src1, src2)
#define vzipq_s32(src1, src2) neon_zip_q32(src1, src2)
#define vzipq_s8(src1, src2) neon_zip_q8(src1, src2)
#define vzipq_u16(src1, src2) neon_zip_q16(src1, src2)
#define vzipq_u32(src1, src2) neon_zip_q32(src1, src2)
#define vzipq_u8(src1, src2) neon_zip_q8(src1, src2)
#define vuzp_p16(src1, src2) neon_uzp_16(src1, src2)
#define vuzp_p8(src1, src2) neon_uzp_8(src1, src2)
#define vuzp_s16(src1, src2) neon_uzp_16(src1, src2)
#define vuzp_s8(src1, src2) neon_uzp_8(src1, src2)
#define vuzp_u16(src1, src2) neon_uzp_16(src1, src2)
#define vuzp_u8(src1, src2) neon_uzp_8(src1, src2)
#define vuzp_f32(src1, src2) neon_uzp_32(src1, src2)
#define vuzp_s32(src1, src2) neon_uzp_32(src1, src2)
#define vuzp_u32(src1, src2) neon_uzp_32(src1, src2)
#define vuzpq_f32(src1, src2) neon_uzp_q32(src1, src2)
#define vuzpq_p16(src1, src2) neon_uzp_q16(src1, src2)
#define vuzpq_p8(src1, src2) neon_uzp_q8(src1, src2)
#define vuzpq_s16(src1, src2) neon_uzp_q16(src1, src2)
#define vuzpq_s32(src1, src2) neon_uzp_q32(src1, src2)
#define vuzpq_s8(src1, src2) neon_uzp_q8(src1, src2)
#define vuzpq_u16(src1, src2) neon_uzp_q16(src1, src2)
#define vuzpq_u32(src1, src2) neon_uzp_q32(src1, src2)
#define vuzpq_u8(src1, src2) neon_uzp_q8(src1, src2)
#define vtrn_p16(src1, src2) neon_trn_16(src1, src2)
#define vtrn_p8(src1, src2) neon_trn_8(src1, src2)
#define vtrn_s16(src1, src2) neon_trn_16(src1, src2)
#define vtrn_s8(src1, src2) neon_trn_8(src1, src2)
#define vtrn_u16(src1, src2) neon_trn_16(src1, src2)
#define vtrn_u8(src1, src2) neon_trn_8(src1, src2)
#define vtrn_f32(src1, src2) neon_trn_32(src1, src2)
#define vtrn_s32(src1, src2) neon_trn_32(src1, src2)
#define vtrn_u32(src1, src2) neon_trn_32(src1, src2)
#define vtrnq_f32(src1, src2) neon_trn_q32(src1, src2)
#define vtrnq_p16(src1, src2) neon_trn_q16(src1, src2)
#define vtrnq_p8(src1, src2) neon_trn_q8(src1, src2)
#define vtrnq_s16(src1, src2) neon_trn_q16(src1, src2)
#define vtrnq_s32(src1, src2) neon_trn_q32(src1, src2)
#define vtrnq_s8(src1, src2) neon_trn_q8(src1, src2)
#define vtrnq_u16(src1, src2) neon_trn_q16(src1, src2)
#define vtrnq_u32(src1, src2) neon_trn_q32(src1, src2)
#define vtrnq_u8(src1, src2) neon_trn_q8(src1, src2)

__n64 neon_frinta_32(__n64);
__n128 neon_frinta_q32(__n128);
__n128 neon_frinta_q64(__n128);
__n64 neon_frinti_32(__n64);
__n128 neon_frinti_q32(__n128);
__n128 neon_frinti_q64(__n128);
__n64 neon_frintm_32(__n64);
__n128 neon_frintm_q32(__n128);
__n128 neon_frintm_q64(__n128);
__n64 neon_frintn_32(__n64);
__n128 neon_frintn_q32(__n128);
__n128 neon_frintn_q64(__n128);
__n64 neon_frintp_32(__n64);
__n128 neon_frintp_q32(__n128);
__n128 neon_frintp_q64(__n128);
__n64 neon_frintx_32(__n64);
__n128 neon_frintx_q32(__n128);
__n128 neon_frintx_q64(__n128);
__n64 neon_frintz_32(__n64);
__n128 neon_frintz_q32(__n128);
__n128 neon_frintz_q64(__n128);
#define vrndi_f32(src) neon_frinti_32(src)
#define vrnda_f32(src) neon_frinta_32(src)
#define vrndm_f32(src) neon_frintm_32(src)
#define vrndn_f32(src) neon_frintn_32(src)
#define vrndp_f32(src) neon_frintp_32(src)
#define vrndx_f32(src) neon_frintx_32(src)
#define vrndiq_f32(src) neon_frinti_q32(src)
#define vrndaq_f32(src) neon_frinta_q32(src)
#define vrndmq_f32(src) neon_frintm_q32(src)
#define vrndnq_f32(src) neon_frintn_q32(src)
#define vrndpq_f32(src) neon_frintp_q32(src)
#define vrndxq_f32(src) neon_frintx_q32(src)
#define vrnd_f32(src) neon_frintz_32(src)
#define vrndq_f32(src) neon_frintz_q32(src)

// SHA1C/SHA1M/SHA1P/SHA256H2/SHA256H/SHA1SU0/SHA256SU1/SHA1SU1/SHA256SU0/SHA1H/
__n128 neon_sha1c(__n128, __n128, __n128);
__n128 neon_sha1m(__n128, __n128, __n128);
__n128 neon_sha1p(__n128, __n128, __n128);
__n128 neon_sha256h2(__n128, __n128, __n128);
__n128 neon_sha256h(__n128, __n128, __n128);
__n128 neon_sha1su0(__n128, __n128, __n128);
__n128 neon_sha256su1(__n128, __n128, __n128);
__n128 neon_sha1su1(__n128, __n128);
__n128 neon_sha256su0(__n128, __n128);
__n128 neon_sha1h(__n128);
#define sha1c_f32(src1, src2, src3) neon_sha1c(src1, src2, src3)
#define sha1c_s32(src1, src2, src3) neon_sha1c(src1, src2, src3)
#define sha1c_u32(src1, src2, src3) neon_sha1c(src1, src2, src3)
#define vsha1cq_u32(src1, src2, src3) neon_sha1c(src1, src2, src3)
#define sha1p_f32(src1, src2, src3) neon_sha1p(src1, src2, src3)
#define sha1p_s32(src1, src2, src3) neon_sha1p(src1, src2, src3)
#define sha1p_u32(src1, src2, src3) neon_sha1p(src1, src2, src3)
#define vsha1pq_u32(src1, src2, src3) neon_sha1p(src1, src2, src3)
#define sha1m_f32(src1, src2, src3) neon_sha1m(src1, src2, src3)
#define sha1m_s32(src1, src2, src3) neon_sha1m(src1, src2, src3)
#define sha1m_u32(src1, src2, src3) neon_sha1m(src1, src2, src3)
#define vsha1mq_u32(src1, src2, src3) neon_sha1m(src1, src2, src3)
#define sha1su1_f32(src1, src2)   neon_sha1su1(src1, src2)
#define sha1su1_s32(src1, src2)   neon_sha1su1(src1, src2)
#define sha1su1_u32(src1, src2)   neon_sha1su1(src1, src2)
#define vsha1su1q_u32(src1, src2) neon_sha1su1(src1, src2)
#define sha256su0_f32(src1, src2) neon_sha256su0(src1, src2)
#define sha256su0_s32(src1, src2) neon_sha256su0(src1, src2)
#define sha256su0_u32(src1, src2) neon_sha256su0(src1, src2)
#define vsha256su0q_u32(src1, src2) neon_sha256su0(src1, src2)
#define sha1su0_f32(src1, src2, src3)   neon_sha1su0(src1, src2, src3)
#define sha1su0_s32(src1, src2, src3)   neon_sha1su0(src1, src2, src3)
#define sha1su0_u32(src1, src2, src3)   neon_sha1su0(src1, src2, src3)
#define vsha1su0q_u32(src1, src2, src3) neon_sha1su0(src1, src2, src3)
#define sha256h_f32(src1, src2, src3)   neon_sha256h(src1, src2, src3)
#define sha256h_s32(src1, src2, src3)   neon_sha256h(src1, src2, src3)
#define sha256h_u32(src1, src2, src3)   neon_sha256h(src1, src2, src3)
#define sha256h2_f32(src1, src2, src3)  neon_sha256h2(src1, src2, src3)
#define sha256h2_s32(src1, src2, src3)  neon_sha256h2(src1, src2, src3)
#define sha256h2_u32(src1, src2, src3)  neon_sha256h2(src1, src2, src3)
#define vsha256hq_u32(src1, src2, src3) neon_sha256h(src1, src2, src3)
#define vsha256h2q_u32(src1, src2, src3) neon_sha256h2(src1, src2, src3)
#define sha256su1_f32(src1, src2, src3) neon_sha256su1(src1, src2, src3)
#define sha256su1_s32(src1, src2, src3) neon_sha256su1(src1, src2, src3)
#define sha256su1_u32(src1, src2, src3) neon_sha256su1(src1, src2, src3)
#define vsha256su1q_u32(src1, src2, src3) neon_sha256su1(src1, src2, src3)
#define sha1h_f32(src) neon_sha1h(src)
#define sha1h_s32(src) neon_sha1h(src)
#define sha1h_u32(src) neon_sha1h(src)
#define vsha1h_u32(src)  neon_sha1h(src)

// SRI/SRSHR/SSHR/SSRA/USHR/URSRA/USRA/URSHR/SRSRA/SHL/SLI/SQSHLU/SQSHL/UQSHL/SQRSHL/URSHL/SRSHL/USHL/UQRSHL/SSHL
__n64  neon_srii8  (__n64,  __n64,  const int);
__n128 neon_sriiq8 (__n128, __n128, const int);
__n64  neon_srii16 (__n64,  __n64,  const int);
__n128 neon_sriiq16(__n128, __n128, const int);
__n64  neon_srii32 (__n64,  __n64,  const int);
__n128 neon_sriiq32(__n128, __n128, const int);
__n128 neon_sriiq64(__n128, __n128, const int);
__n64  neon_sriis64(__n64,  __n64,  const int);
__n64  neon_srshri8  (__n64,  const int);
__n128 neon_srshriq8 (__n128, const int);
__n64  neon_srshri16 (__n64,  const int);
__n128 neon_srshriq16(__n128, const int);
__n64  neon_srshri32 (__n64,  const int);
__n128 neon_srshriq32(__n128, const int);
__n128 neon_srshriq64(__n128, const int);
__n64  neon_srshris64(__n64,  const int);
__n64  neon_sshri8  (__n64,  const int);
__n128 neon_sshriq8 (__n128, const int);
__n64  neon_sshri16 (__n64,  const int);
__n128 neon_sshriq16(__n128, const int);
__n64  neon_sshri32 (__n64,  const int);
__n128 neon_sshriq32(__n128, const int);
__n128 neon_sshriq64(__n128, const int);
__n64  neon_sshris64(__n64,  const int);
__n64  neon_ssrai8  (__n64,  __n64,  const int);
__n128 neon_ssraiq8 (__n128, __n128, const int);
__n64  neon_ssrai16 (__n64,  __n64,  const int);
__n128 neon_ssraiq16(__n128, __n128, const int);
__n64  neon_ssrai32 (__n64,  __n64,  const int);
__n128 neon_ssraiq32(__n128, __n128, const int);
__n128 neon_ssraiq64(__n128, __n128, const int);
__n64  neon_ssrais64(__n64,  __n64,  const int);
__n64  neon_ushri8  (__n64,  const int);
__n128 neon_ushriq8 (__n128, const int);
__n64  neon_ushri16 (__n64,  const int);
__n128 neon_ushriq16(__n128, const int);
__n64  neon_ushri32 (__n64,  const int);
__n128 neon_ushriq32(__n128, const int);
__n128 neon_ushriq64(__n128, const int);
__n64  neon_ushris64(__n64,  const int);
__n64  neon_ursrai8  (__n64,  __n64,  const int);
__n128 neon_ursraiq8 (__n128, __n128, const int);
__n64  neon_ursrai16 (__n64,  __n64,  const int);
__n128 neon_ursraiq16(__n128, __n128, const int);
__n64  neon_ursrai32 (__n64,  __n64,  const int);
__n128 neon_ursraiq32(__n128, __n128, const int);
__n128 neon_ursraiq64(__n128, __n128, const int);
__n64  neon_ursrais64(__n64,  __n64,  const int);
__n64  neon_usrai8  (__n64,  __n64,  const int);
__n128 neon_usraiq8 (__n128, __n128, const int);
__n64  neon_usrai16 (__n64,  __n64,  const int);
__n128 neon_usraiq16(__n128, __n128, const int);
__n64  neon_usrai32 (__n64,  __n64,  const int);
__n128 neon_usraiq32(__n128, __n128, const int);
__n128 neon_usraiq64(__n128, __n128, const int);
__n64  neon_usrais64(__n64,  __n64,  const int);
__n64  neon_urshri8  (__n64,  const int);
__n128 neon_urshriq8 (__n128, const int);
__n64  neon_urshri16 (__n64,  const int);
__n128 neon_urshriq16(__n128, const int);
__n64  neon_urshri32 (__n64,  const int);
__n128 neon_urshriq32(__n128, const int);
__n128 neon_urshriq64(__n128, const int);
__n64  neon_urshris64(__n64,  const int);
__n64  neon_srsrai8  (__n64,  __n64,  const int);
__n128 neon_srsraiq8 (__n128, __n128, const int);
__n64  neon_srsrai16 (__n64,  __n64,  const int);
__n128 neon_srsraiq16(__n128, __n128, const int);
__n64  neon_srsrai32 (__n64,  __n64,  const int);
__n128 neon_srsraiq32(__n128, __n128, const int);
__n128 neon_srsraiq64(__n128, __n128, const int);
__n64  neon_srsrais64(__n64,  __n64,  const int);
__n64  neon_shli8  (__n64,  const int);
__n128 neon_shliq8 (__n128, const int);
__n64  neon_shli16 (__n64,  const int);
__n128 neon_shliq16(__n128, const int);
__n64  neon_shli32 (__n64,  const int);
__n128 neon_shliq32(__n128, const int);
__n128 neon_shliq64(__n128, const int);
__n64  neon_shlis64(__n64,  const int);
__n64  neon_slii8  (__n64,  __n64,  const int);
__n128 neon_sliiq8 (__n128, __n128, const int);
__n64  neon_slii16 (__n64,  __n64,  const int);
__n128 neon_sliiq16(__n128, __n128, const int);
__n64  neon_slii32 (__n64,  __n64,  const int);
__n128 neon_sliiq32(__n128, __n128, const int);
__n128 neon_sliiq64(__n128, __n128, const int);
__n64  neon_sliis64(__n64,  __n64,  const int);
__n64  neon_sqshlui8  (__n64,  const int);
__n128 neon_sqshluiq8 (__n128, const int);
__n64  neon_sqshlui16 (__n64,  const int);
__n128 neon_sqshluiq16(__n128, const int);
__n64  neon_sqshlui32 (__n64,  const int);
__n128 neon_sqshluiq32(__n128, const int);
__n128 neon_sqshluiq64(__n128, const int);
__n8   neon_sqshluis8(__n8,  const int);
__n16  neon_sqshluis16(__n16, const int);
float  neon_sqshluis32(float, const int);
__n64  neon_sqshluis64(__n64, const int);
__n64  neon_sqshli8  (__n64,  const int);
__n128 neon_sqshliq8 (__n128, const int);
__n64  neon_sqshli16 (__n64,  const int);
__n128 neon_sqshliq16(__n128, const int);
__n64  neon_sqshli32 (__n64,  const int);
__n128 neon_sqshliq32(__n128, const int);
__n128 neon_sqshliq64(__n128, const int);
__n64  neon_sqshl8  (__n64,  __n64);
__n128 neon_sqshlq8 (__n128, __n128);
__n64  neon_sqshl16 (__n64,  __n64);
__n128 neon_sqshlq16(__n128, __n128);
__n64  neon_sqshl32 (__n64,  __n64);
__n128 neon_sqshlq32(__n128, __n128);
__n128 neon_sqshlq64(__n128, __n128);
__n8   neon_sqshlis8(__n8,  const int);
__n16  neon_sqshlis16(__n16, const int);
float  neon_sqshlis32(float, const int);
__n64  neon_sqshlis64(__n64, const int);
__n8   neon_sqshls8(__n8,  __n8);
__n16  neon_sqshls16(__n16, __n16);
float  neon_sqshls32(float, float);
__n64  neon_sqshls64(__n64, __n64);
__n64  neon_uqshli8  (__n64,  const int);
__n128 neon_uqshliq8 (__n128, const int);
__n64  neon_uqshli16 (__n64,  const int);
__n128 neon_uqshliq16(__n128, const int);
__n64  neon_uqshli32 (__n64,  const int);
__n128 neon_uqshliq32(__n128, const int);
__n128 neon_uqshliq64(__n128, const int);
__n64  neon_uqshl8  (__n64,  __n64);
__n128 neon_uqshlq8 (__n128, __n128);
__n64  neon_uqshl16 (__n64,  __n64);
__n128 neon_uqshlq16(__n128, __n128);
__n64  neon_uqshl32 (__n64,  __n64);
__n128 neon_uqshlq32(__n128, __n128);
__n128 neon_uqshlq64(__n128, __n128);
__n8   neon_uqshlis8(__n8,  const int);
__n16  neon_uqshlis16(__n16, const int);
float  neon_uqshlis32(float, const int);
__n64  neon_uqshlis64(__n64, const int);
__n8   neon_uqshls8(__n8,  __n8);
__n16  neon_uqshls16(__n16, __n16);
float  neon_uqshls32(float, float);
__n64  neon_uqshls64(__n64, __n64);
__n64  neon_sqrshl8  (__n64,  __n64);
__n128 neon_sqrshlq8 (__n128, __n128);
__n64  neon_sqrshl16 (__n64,  __n64);
__n128 neon_sqrshlq16(__n128, __n128);
__n64  neon_sqrshl32 (__n64,  __n64);
__n128 neon_sqrshlq32(__n128, __n128);
__n128 neon_sqrshlq64(__n128, __n128);
__n8   neon_sqrshls8(__n8,  __n8);
__n16  neon_sqrshls16(__n16, __n16);
float  neon_sqrshls32(float, float);
__n64  neon_sqrshls64(__n64, __n64);
__n64  neon_urshl8  (__n64,  __n64);
__n128 neon_urshlq8 (__n128, __n128);
__n64  neon_urshl16 (__n64,  __n64);
__n128 neon_urshlq16(__n128, __n128);
__n64  neon_urshl32 (__n64,  __n64);
__n128 neon_urshlq32(__n128, __n128);
__n128 neon_urshlq64(__n128, __n128);
__n64  neon_urshls64(__n64, __n64);
__n64  neon_srshl8  (__n64,  __n64);
__n128 neon_srshlq8 (__n128, __n128);
__n64  neon_srshl16 (__n64,  __n64);
__n128 neon_srshlq16(__n128, __n128);
__n64  neon_srshl32 (__n64,  __n64);
__n128 neon_srshlq32(__n128, __n128);
__n128 neon_srshlq64(__n128, __n128);
__n64  neon_srshls64(__n64, __n64);
__n64  neon_ushl8  (__n64,  __n64);
__n128 neon_ushlq8 (__n128, __n128);
__n64  neon_ushl16 (__n64,  __n64);
__n128 neon_ushlq16(__n128, __n128);
__n64  neon_ushl32 (__n64,  __n64);
__n128 neon_ushlq32(__n128, __n128);
__n128 neon_ushlq64(__n128, __n128);
__n64  neon_ushls64(__n64, __n64);
__n64  neon_uqrshl8  (__n64,  __n64);
__n128 neon_uqrshlq8 (__n128, __n128);
__n64  neon_uqrshl16 (__n64,  __n64);
__n128 neon_uqrshlq16(__n128, __n128);
__n64  neon_uqrshl32 (__n64,  __n64);
__n128 neon_uqrshlq32(__n128, __n128);
__n128 neon_uqrshlq64(__n128, __n128);
__n8   neon_uqrshls8(__n8, __n8);
__n16  neon_uqrshls16(__n16, __n16);
float  neon_uqrshls32(float, float);
__n64  neon_uqrshls64(__n64, __n64);
__n64  neon_sshl8  (__n64,  __n64);
__n128 neon_sshlq8 (__n128, __n128);
__n64  neon_sshl16 (__n64,  __n64);
__n128 neon_sshlq16(__n128, __n128);
__n64  neon_sshl32 (__n64,  __n64);
__n128 neon_sshlq32(__n128, __n128);
__n128 neon_sshlq64(__n128, __n128);
__n64  neon_sshls64(__n64, __n64);
#define vsri_n_p16(src1, src2, src3) neon_srii16(src1, src2, src3) 
#define vsri_n_p8(src1, src2, src3) neon_srii8(src1, src2, src3)  
#define vsri_n_s16(src1, src2, src3) neon_srii16(src1, src2, src3)
#define vsri_n_s32(src1, src2, src3) neon_srii32(src1, src2, src3)
#define vsri_n_s8(src1, src2, src3) neon_srii8(src1, src2, src3)
#define vsri_n_u16(src1, src2, src3) neon_srii16(src1, src2, src3)
#define vsri_n_u32(src1, src2, src3) neon_srii32(src1, src2, src3)
#define vsri_n_u8(src1, src2, src3) neon_srii8(src1, src2, src3)
#define vsriq_n_p16(src1, src2, src3) neon_sriiq16(src1, src2, src3) 
#define vsriq_n_p8(src1, src2, src3) neon_sriiq8(src1, src2, src3)  
#define vsriq_n_s16(src1, src2, src3) neon_sriiq16(src1, src2, src3)
#define vsriq_n_s32(src1, src2, src3) neon_sriiq32(src1, src2, src3)
#define vsriq_n_s64(src1, src2, src3) neon_sriiq64(src1, src2, src3)
#define vsriq_n_s8(src1, src2, src3) neon_sriiq8(src1, src2, src3)
#define vsriq_n_u16(src1, src2, src3) neon_sriiq16(src1, src2, src3)
#define vsriq_n_u32(src1, src2, src3) neon_sriiq32(src1, src2, src3)
#define vsriq_n_u64(src1, src2, src3) neon_sriiq64(src1, src2, src3)
#define vsriq_n_u8(src1, src2, src3) neon_sriiq8(src1, src2, src3)
#define vrshr_n_s16(src1, src2) neon_srshri16(src1, src2)
#define vrshr_n_s32(src1, src2) neon_srshri32(src1, src2)
#define vrshr_n_s8(src1, src2) neon_srshri8(src1, src2)
#define vrshr_n_u16(src1, src2) neon_urshri16(src1, src2)
#define vrshr_n_u32(src1, src2) neon_urshri32(src1, src2)
#define vrshr_n_u8(src1, src2) neon_urshri8(src1, src2)
#define vshr_n_s16(src1, src2) neon_sshri16(src1, src2)
#define vshr_n_s32(src1, src2) neon_sshri32(src1, src2)
#define vshr_n_s8(src1, src2) neon_sshri8(src1, src2)
#define vshr_n_u16(src1, src2) neon_ushri16(src1, src2)
#define vshr_n_u32(src1, src2) neon_ushri32(src1, src2)
#define vshr_n_u64(src1, src2) neon_ushris64(src1, src2)
#define vshr_n_u8(src1, src2) neon_ushri8(src1, src2)
#define vrshrq_n_s16(src1, src2) neon_srshriq16(src1, src2)
#define vrshrq_n_s32(src1, src2) neon_srshriq32(src1, src2)
#define vrshrq_n_s64(src1, src2) neon_srshriq64(src1, src2)
#define vrshrq_n_s8(src1, src2) neon_srshriq8(src1, src2)
#define vrshrq_n_u16(src1, src2) neon_urshriq16(src1, src2)
#define vrshrq_n_u32(src1, src2) neon_urshriq32(src1, src2)
#define vrshrq_n_u64(src1, src2) neon_urshriq64(src1, src2)
#define vrshrq_n_u8(src1, src2) neon_urshriq8(src1, src2)
#define vshrq_n_s16(src1, src2) neon_sshriq16(src1, src2)
#define vshrq_n_s32(src1, src2) neon_sshriq32(src1, src2)
#define vshrq_n_s64(src1, src2) neon_sshriq64(src1, src2)
#define vshrq_n_s8(src1, src2) neon_sshriq8(src1, src2)
#define vshrq_n_u16(src1, src2) neon_ushriq16(src1, src2)
#define vshrq_n_u32(src1, src2) neon_ushriq32(src1, src2)
#define vshrq_n_u64(src1, src2) neon_ushriq64(src1, src2)
#define vshrq_n_u8(src1, src2) neon_ushriq8(src1, src2) 
#define vrsra_n_s16(src1, src2, src3) neon_srsrai16(src1, src2, src3) 
#define vrsra_n_s32(src1, src2, src3) neon_srsrai32(src1, src2, src3) 
#define vrsra_n_s8(src1, src2, src3) neon_srsrai8(src1, src2, src3) 
#define vrsra_n_u16(src1, src2, src3) neon_ursrai16(src1, src2, src3) 
#define vrsra_n_u32(src1, src2, src3) neon_ursrai32(src1, src2, src3) 
#define vrsra_n_u8(src1, src2, src3) neon_ursrai8(src1, src2, src3) 
#define vsra_n_s16(src1, src2, src3) neon_ssrai16(src1, src2, src3) 
#define vsra_n_s32(src1, src2, src3) neon_ssrai32(src1, src2, src3) 
#define vsra_n_s8(src1, src2, src3) neon_ssrai8(src1, src2, src3) 
#define vsra_n_u16(src1, src2, src3) neon_usrai16(src1, src2, src3) 
#define vsra_n_u32(src1, src2, src3) neon_usrai32(src1, src2, src3) 
#define vsra_n_u8(src1, src2, src3) neon_usrai8(src1, src2, src3) 
#define vrsraq_n_s16(src1, src2, src3) neon_srsraiq16(src1, src2, src3) 
#define vrsraq_n_s32(src1, src2, src3) neon_srsraiq32(src1, src2, src3) 
#define vrsraq_n_s64(src1, src2, src3) neon_srsraiq64(src1, src2, src3) 
#define vrsraq_n_s8(src1, src2, src3) neon_srsraiq8(src1, src2, src3) 
#define vrsraq_n_u16(src1, src2, src3) neon_ursraiq16(src1, src2, src3) 
#define vrsraq_n_u32(src1, src2, src3) neon_ursraiq32(src1, src2, src3) 
#define vrsraq_n_u64(src1, src2, src3) neon_ursraiq64(src1, src2, src3) 
#define vrsraq_n_u8(src1, src2, src3) neon_ursraiq8(src1, src2, src3) 
#define vsraq_n_s16(src1, src2, src3) neon_ssraiq16(src1, src2, src3) 
#define vsraq_n_s32(src1, src2, src3) neon_ssraiq32(src1, src2, src3) 
#define vsraq_n_s64(src1, src2, src3) neon_ssraiq64(src1, src2, src3) 
#define vsraq_n_s8(src1, src2, src3) neon_ssraiq8(src1, src2, src3) 
#define vsraq_n_u16(src1, src2, src3) neon_usraiq16(src1, src2, src3) 
#define vsraq_n_u32(src1, src2, src3) neon_usraiq32(src1, src2, src3) 
#define vsraq_n_u64(src1, src2, src3) neon_usraiq64(src1, src2, src3) 
#define vsraq_n_u8(src1, src2, src3) neon_usraiq8(src1, src2, src3) 
#define vqshl_n_s16(src1, src2) neon_sqshli16(src1, src2) 
#define vqshl_n_s32(src1, src2) neon_sqshli32(src1, src2) 
#define vqshl_n_s8(src1, src2) neon_sqshli8(src1, src2) 
#define vqshl_n_u16(src1, src2) neon_uqshli16(src1, src2) 
#define vqshl_n_u32(src1, src2) neon_uqshli32(src1, src2) 
#define vqshl_n_u8(src1, src2) neon_uqshli8(src1, src2) 
#define vqshlq_n_s16(src1, src2) neon_sqshliq16(src1, src2) 
#define vqshlq_n_s32(src1, src2) neon_sqshliq32(src1, src2) 
#define vqshlq_n_s64(src1, src2) neon_sqshliq64(src1, src2) 
#define vqshlq_n_s8(src1, src2) neon_sqshliq8(src1, src2) 
#define vqshlq_n_u16(src1, src2) neon_uqshliq16(src1, src2) 
#define vqshlq_n_u32(src1, src2) neon_uqshliq32(src1, src2) 
#define vqshlq_n_u64(src1, src2) neon_uqshliq64(src1, src2) 
#define vqshlq_n_u8(src1, src2) neon_uqshliq8(src1, src2) 
#define vqshlu_n_s16(src1, src2) neon_sqshlui16(src1, src2) 
#define vqshlu_n_s32(src1, src2) neon_sqshlui32(src1, src2) 
#define vqshlu_n_s8(src1, src2) neon_sqshlui8(src1, src2) 
#define vqshluq_n_s16(src1, src2) neon_sqshluiq16(src1, src2) 
#define vqshluq_n_s32(src1, src2) neon_sqshluiq32(src1, src2) 
#define vqshluq_n_s64(src1, src2) neon_sqshluiq64(src1, src2) 
#define vqshluq_n_s8(src1, src2) neon_sqshluiq8(src1, src2) 
#define vshl_n_s16(src1, src2) neon_shli16(src1, src2) 
#define vshl_n_s32(src1, src2) neon_shli32(src1, src2) 
#define vshl_n_s8(src1, src2) neon_shli8(src1, src2) 
#define vshl_n_u16(src1, src2) neon_shli16(src1, src2) 
#define vshl_n_u32(src1, src2) neon_shli32(src1, src2) 
#define vshl_n_u8(src1, src2) neon_shliq8(src1, src2) 
#define vshlq_n_s16(src1, src2) neon_shliq16(src1, src2) 
#define vshlq_n_s32(src1, src2) neon_shliq32(src1, src2) 
#define vshlq_n_s64(src1, src2) neon_shliq64(src1, src2) 
#define vshlq_n_s8(src1, src2) neon_shliq8(src1, src2) 
#define vshlq_n_u16(src1, src2) neon_shliq16(src1, src2) 
#define vshlq_n_u32(src1, src2) neon_shliq32(src1, src2) 
#define vshlq_n_u64(src1, src2) neon_shliq64(src1, src2) 
#define vshlq_n_u8(src1, src2) neon_shliq8(src1, src2) 
#define vqrshl_s16(src1, src2) neon_sqrshl16(src1, src2) 
#define vqrshl_s32(src1, src2) neon_sqrshl32(src1, src2) 
#define vqrshl_s8(src1, src2) neon_sqrshl8(src1, src2) 
#define vqrshl_u16(src1, src2) neon_uqrshl16(src1, src2) 
#define vqrshl_u32(src1, src2) neon_uqrshl32(src1, src2) 
#define vqrshl_u8(src1, src2) neon_uqrshl8(src1, src2) 
#define vqshl_s16(src1, src2) neon_sqshl16(src1, src2) 
#define vqshl_s32(src1, src2) neon_sqshl32(src1, src2) 
#define vqshl_s8(src1, src2) neon_sqshl8(src1, src2) 
#define vqshl_u16(src1, src2) neon_uqshl16(src1, src2) 
#define vqshl_u32(src1, src2) neon_uqshl32(src1, src2) 
#define vqshl_u8(src1, src2) neon_uqshl8(src1, src2) 
#define vrshl_s16(src1, src2) neon_srshl16(src1, src2) 
#define vrshl_s32(src1, src2) neon_srshl32(src1, src2) 
#define vrshl_s8(src1, src2) neon_srshl8(src1, src2) 
#define vrshl_u16(src1, src2) neon_urshl16(src1, src2) 
#define vrshl_u32(src1, src2) neon_urshl32(src1, src2) 
#define vrshl_u8(src1, src2) neon_urshl8(src1, src2) 
#define vshl_s16(src1, src2) neon_sshl16(src1, src2) 
#define vshl_s32(src1, src2) neon_sshl32(src1, src2) 
#define vshl_s8(src1, src2) neon_sshl8(src1, src2) 
#define vshl_u16(src1, src2) neon_ushl16(src1, src2) 
#define vshl_u32(src1, src2) neon_ushl32(src1, src2) 
#define vshl_u8(src1, src2) neon_ushl8(src1, src2) 
#define vqrshlq_s16(src1, src2) neon_sqrshlq16(src1, src2) 
#define vqrshlq_s32(src1, src2) neon_sqrshlq32(src1, src2) 
#define vqrshlq_s64(src1, src2) neon_sqrshlq64(src1, src2) 
#define vqrshlq_s8(src1, src2) neon_sqrshlq8(src1, src2) 
#define vqrshlq_u16(src1, src2) neon_uqrshlq16(src1, src2) 
#define vqrshlq_u32(src1, src2) neon_uqrshlq32(src1, src2) 
#define vqrshlq_u64(src1, src2) neon_uqrshlq64(src1, src2) 
#define vqrshlq_u8(src1, src2) neon_uqrshlq8(src1, src2) 
#define vqshlq_s16(src1, src2) neon_sqshlq16(src1, src2) 
#define vqshlq_s32(src1, src2) neon_sqshlq32(src1, src2) 
#define vqshlq_s64(src1, src2) neon_sqshlq64(src1, src2) 
#define vqshlq_s8(src1, src2) neon_sqshlq8(src1, src2) 
#define vqshlq_u16(src1, src2) neon_uqshlq16(src1, src2) 
#define vqshlq_u32(src1, src2) neon_uqshlq32(src1, src2) 
#define vqshlq_u64(src1, src2) neon_uqshlq64(src1, src2) 
#define vqshlq_u8(src1, src2) neon_uqshlq8(src1, src2) 
#define vrshlq_s16(src1, src2) neon_srshlq16(src1, src2) 
#define vrshlq_s32(src1, src2) neon_srshlq32(src1, src2) 
#define vrshlq_s64(src1, src2) neon_srshlq64(src1, src2) 
#define vrshlq_s8(src1, src2) neon_srshlq8(src1, src2) 
#define vrshlq_u16(src1, src2) neon_urshlq16(src1, src2) 
#define vrshlq_u32(src1, src2) neon_urshlq32(src1, src2) 
#define vrshlq_u64(src1, src2) neon_urshlq64(src1, src2) 
#define vrshlq_u8(src1, src2) neon_urshlq8(src1, src2) 
#define vshlq_s16(src1, src2) neon_sshlq16(src1, src2) 
#define vshlq_s32(src1, src2) neon_sshlq32(src1, src2) 
#define vshlq_s64(src1, src2) neon_sshlq64(src1, src2) 
#define vshlq_s8(src1, src2) neon_sshlq8(src1, src2) 
#define vshlq_u16(src1, src2) neon_ushlq16(src1, src2) 
#define vshlq_u32(src1, src2) neon_ushlq32(src1, src2) 
#define vshlq_u64(src1, src2) neon_ushlq64(src1, src2) 
#define vshlq_u8(src1, src2) neon_ushlq8(src1, src2) 
#define vsli_n_p16(src1, src2, src3) neon_slii16(src1, src2, src3) 
#define vsli_n_p8(src1, src2, src3) neon_slii8(src1, src2, src3) 
#define vsli_n_s16(src1, src2, src3) neon_slii16(src1, src2, src3) 
#define vsli_n_s32(src1, src2, src3) neon_slii32(src1, src2, src3) 
#define vsli_n_s8(src1, src2, src3) neon_slii8(src1, src2, src3) 
#define vsli_n_u16(src1, src2, src3) neon_slii16(src1, src2, src3) 
#define vsli_n_u32(src1, src2, src3) neon_slii32(src1, src2, src3) 
#define vsli_n_u8(src1, src2, src3) neon_slii8(src1, src2, src3) 
#define vsliq_n_p16(src1, src2, src3) neon_sliiq16(src1, src2, src3) 
#define vsliq_n_p8(src1, src2, src3) neon_sliiq8(src1, src2, src3) 
#define vsliq_n_s16(src1, src2, src3) neon_sliiq16(src1, src2, src3) 
#define vsliq_n_s32(src1, src2, src3) neon_sliiq32(src1, src2, src3) 
#define vsliq_n_s64(src1, src2, src3) neon_sliiq64(src1, src2, src3) 
#define vsliq_n_s8(src1, src2, src3) neon_sliiq8(src1, src2, src3) 
#define vsliq_n_u16(src1, src2, src3) neon_sliiq16(src1, src2, src3) 
#define vsliq_n_u32(src1, src2, src3) neon_sliiq32(src1, src2, src3) 
#define vsliq_n_u64(src1, src2, src3) neon_sliiq64(src1, src2, src3) 
#define vsliq_n_u8(src1, src2, src3) neon_sliiq8(src1, src2, src3) 

// TBL/TBX
__n64  neon_tbx4_q8(__n64 src1, __n128x4 reglist, __n64 src2);
__n128 neon_tbx4_qq8(__n128 src1, __n128x4 reglist, __n128 src2);
__n64  neon_tbx3_q8(__n64 src1, __n128x3 reglist, __n64 src2);
__n128 neon_tbx3_qq8(__n128 src1, __n128x3 reglist, __n128 src2);
__n64  neon_tbx2_q8(__n64 src1, __n128x2 reglist, __n64 src2);
__n128 neon_tbx2_qq8(__n128 src1, __n128x2 reglist, __n128 src2);
__n64  neon_tbx1_q8(__n64 src1, __n128 reglist, __n64 src2);
__n128 neon_tbx1_qq8(__n128 src1, __n128 reglist, __n128 src2);
__n64  neon_tbl4_q8(__n128x4 reglist, __n64 src2);
__n128 neon_tbl4_qq8(__n128x4 reglist, __n128 src2);
__n64  neon_tbl3_q8(__n128x3 reglist, __n64 src2);
__n128 neon_tbl3_qq8(__n128x3 reglist, __n128 src2);
__n64  neon_tbl2_q8(__n128x2 reglist, __n64 src2);
__n128 neon_tbl2_qq8(__n128x2 reglist, __n128 src2);
__n64  neon_tbl1_q8(__n128 reglist, __n64 src2);
__n128 neon_tbl1_qq8(__n128 reglist, __n128 src2);
#define neon_tbx4_8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), vget_lane_s64(src2.val[3], 0)}, src3)
#define neon_tbx3_8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), 0}, src3)
#define neon_tbx2_8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0)}, src3)
#define neon_tbx1_8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_s64(src2, 0), 0}, src3)
#define neon_tbl4_8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), vget_lane_s64(src1.val[3], 0)}, src2)
#define neon_tbl3_8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), 0}, src2)
#define neon_tbl2_8(src1, src2) neon_tbl1_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0)}, src2)
#define neon_tbl1_8(src1, src2) neon_tbl1_q8({vget_lane_s64(src1, 0), 0}, src2)
#define vtbx4_p8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), vget_lane_s64(src2.val[3], 0)}, src3)
#define vtbx4_s8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), vget_lane_s64(src2.val[3], 0)}, src3)
#define vtbx4_u8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), vget_lane_s64(src2.val[3], 0)}, src3)
#define vtbx3_p8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), 0}, src3)
#define vtbx3_s8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), 0}, src3)
#define vtbx3_u8(src1, src2, src3) neon_tbx2_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0), vget_lane_s64(src2.val[2], 0), 0}, src3)
#define vtbx2_p8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0)}, src3)
#define vtbx2_s8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0)}, src3)
#define vtbx2_u8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_s64(src2.val[0], 0), vget_lane_s64(src2.val[1], 0)}, src3)
#define vtbx1_p8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_s64(src2, 0), 0}, src3)
#define vtbx1_s8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_s64(src2, 0), 0}, src3)
#define vtbx1_u8(src1, src2, src3) neon_tbx1_q8(src1, {vget_lane_u64(src2, 0), 0}, src3)
#define vtbl4_p8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), vget_lane_s64(src1.val[3], 0)}, src2)
#define vtbl4_s8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), vget_lane_s64(src1.val[3], 0)}, src2)
#define vtbl4_u8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), vget_lane_s64(src1.val[3], 0)}, src2)
#define vtbl3_p8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), 0}, src2)
#define vtbl3_s8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), 0}, src2)
#define vtbl3_u8(src1, src2) neon_tbl2_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0), vget_lane_s64(src1.val[2], 0), 0}, src2)
#define vtbl2_p8(src1, src2) neon_tbl1_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0)}, src2)
#define vtbl2_s8(src1, src2) neon_tbl1_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0)}, src2)
#define vtbl2_u8(src1, src2) neon_tbl1_q8({vget_lane_s64(src1.val[0], 0), vget_lane_s64(src1.val[1], 0)}, src2)
#define vtbl1_p8(src1, src2) neon_tbl1_q8({vget_lane_s64(src1, 0), 0}, src2)
#define vtbl1_s8(src1, src2) neon_tbl1_q8({vget_lane_s64(src1, 0), 0}, src2)
#define vtbl1_u8(src1, src2) neon_tbl1_q8({vget_lane_u64(src1, 0), 0}, src2)

// LD4R/LD4/LD3R/LD3/LD2R/LD2
__n64x4 neon_ld4r_8(const __int8 * ptr);
__n128x4 neon_ld4r_q8(const __int8 * ptr);
__n64x4 neon_ld4r_16(const __int16 * ptr);
__n128x4 neon_ld4r_q16(const __int16 * ptr);
__n64x4 neon_ld4r_32(const __int32 * ptr);
__n128x4 neon_ld4r_q32(const __int32 * ptr);
__n64x4 neon_ld4r_64(const __int64 * ptr);
__n128x4 neon_ld4r_q64(const __int64 * ptr);
__n64x4 neon_ld4m_8(const __int8 * ptr);
__n128x4 neon_ld4m_q8(const __int8 * ptr);
__n64x4 neon_ld4m_16(const __int16 * ptr);
__n128x4 neon_ld4m_q16(const __int16 * ptr);
__n64x4 neon_ld4m_32(const __int32 * ptr);
__n128x4 neon_ld4m_q32(const __int32 * ptr);
__n128x4 neon_ld4m_q64(const __int64 * ptr);
__n64x4 neon_ld4s_8(const __int8 * ptr, __n64x4 src, const int lane);
__n128x4 neon_ld4s_q8(const __int8 * ptr, __n128x4 src, const int lane);
__n64x4 neon_ld4s_16(const __int16 * ptr, __n64x4 src, const int lane);
__n128x4 neon_ld4s_q16(const __int16 * ptr, __n128x4 src, const int lane);
__n64x4 neon_ld4s_32(const __int32 * ptr, __n64x4 src, const int lane);
__n128x4 neon_ld4s_q32(const __int32 * ptr, __n128x4 src, const int lane);
__n64x4 neon_ld4s_64(const __int64 * ptr, __n64x4 src, const int lane);
__n128x4 neon_ld4s_q64(const __int64 * ptr, __n128x4 src, const int lane);
__n64x3 neon_ld3r_8(const __int8 * ptr);
__n128x3 neon_ld3r_q8(const __int8 * ptr);
__n64x3 neon_ld3r_16(const __int16 * ptr);
__n128x3 neon_ld3r_q16(const __int16 * ptr);
__n64x3 neon_ld3r_32(const __int32 * ptr);
__n128x3 neon_ld3r_q32(const __int32 * ptr);
__n64x3 neon_ld3r_64(const __int64 * ptr);
__n128x3 neon_ld3r_q64(const __int64 * ptr);
__n64x3 neon_ld3m_8(const __int8 * ptr);
__n128x3 neon_ld3m_q8(const __int8 * ptr);
__n64x3 neon_ld3m_16(const __int16 * ptr);
__n128x3 neon_ld3m_q16(const __int16 * ptr);
__n64x3 neon_ld3m_32(const __int32 * ptr);
__n128x3 neon_ld3m_q32(const __int32 * ptr);
__n128x3 neon_ld3m_q64(const __int64 * ptr);
__n64x3 neon_ld3s_8(const __int8 * ptr, __n64x3 src, const int lane);
__n128x3 neon_ld3s_q8(const __int8 * ptr, __n128x3 src, const int lane);
__n64x3 neon_ld3s_16(const __int16 * ptr, __n64x3 src, const int lane);
__n128x3 neon_ld3s_q16(const __int16 * ptr, __n128x3 src, const int lane);
__n64x3 neon_ld3s_32(const __int32 * ptr, __n64x3 src, const int lane);
__n128x3 neon_ld3s_q32(const __int32 * ptr, __n128x3 src, const int lane);
__n64x3 neon_ld3s_64(const __int64 * ptr, __n64x3 src, const int lane);
__n128x3 neon_ld3s_q64(const __int64 * ptr, __n128x3 src, const int lane);
__n64x2 neon_ld2r_8(const __int8 * ptr);
__n128x2 neon_ld2r_q8(const __int8 * ptr);
__n64x2 neon_ld2r_16(const __int16 * ptr);
__n128x2 neon_ld2r_q16(const __int16 * ptr);
__n64x2 neon_ld2r_32(const __int32 * ptr);
__n128x2 neon_ld2r_q32(const __int32 * ptr);
__n64x2 neon_ld2r_64(const __int64 * ptr);
__n128x2 neon_ld2r_q64(const __int64 * ptr);
__n64x2 neon_ld2m_8(const __int8 * ptr);
__n128x2 neon_ld2m_q8(const __int8 * ptr);
__n64x2 neon_ld2m_16(const __int16 * ptr);
__n128x2 neon_ld2m_q16(const __int16 * ptr);
__n64x2 neon_ld2m_32(const __int32 * ptr);
__n128x2 neon_ld2m_q32(const __int32 * ptr);
__n128x2 neon_ld2m_q64(const __int64 * ptr);
__n64x2 neon_ld2s_8(const __int8 * ptr, __n64x2 src, const int lane);
__n128x2 neon_ld2s_q8(const __int8 * ptr, __n128x2 src, const int lane);
__n64x2 neon_ld2s_16(const __int16 * ptr, __n64x2 src, const int lane);
__n128x2 neon_ld2s_q16(const __int16 * ptr, __n128x2 src, const int lane);
__n64x2 neon_ld2s_32(const __int32 * ptr, __n64x2 src, const int lane);
__n128x2 neon_ld2s_q32(const __int32 * ptr, __n128x2 src, const int lane);
__n64x2 neon_ld2s_64(const __int64 * ptr, __n64x2 src, const int lane);
__n128x2 neon_ld2s_q64(const __int64 * ptr, __n128x2 src, const int lane);
__n64 neon_ld1r_8(const __int8 * ptr);
__n128 neon_ld1r_q8(const __int8 * ptr);
__n64 neon_ld1r_16(const __int16 * ptr);
__n128 neon_ld1r_q16(const __int16 * ptr);
__n64 neon_ld1r_32(const __int32 * ptr);
__n128 neon_ld1r_q32(const __int32 * ptr);
__n64 neon_ld1r_64(const __int64 * ptr);
__n128 neon_ld1r_q64(const __int64 * ptr);
__n64 neon_ld1m_8(const __int8 * ptr);
__n128 neon_ld1m_q8(const __int8 * ptr);
__n64 neon_ld1m_16(const __int16 * ptr);
__n128 neon_ld1m_q16(const __int16 * ptr);
__n64 neon_ld1m_32(const __int32 * ptr);
__n128 neon_ld1m_q32(const __int32 * ptr);
__n64 neon_ld1m_64(const __int64 * ptr);
__n128 neon_ld1m_q64(const __int64 * ptr);
__n64x2 neon_ld1m2_8(const __int8 * ptr);
__n128x2 neon_ld1m2_q8(const __int8 * ptr);
__n64x2 neon_ld1m2_16(const __int16 * ptr);
__n128x2 neon_ld1m2_q16(const __int16 * ptr);
__n64x2 neon_ld1m2_32(const __int32 * ptr);
__n128x2 neon_ld1m2_q32(const __int32 * ptr);
__n64x2 neon_ld1m2_64(const __int64 * ptr);
__n128x2 neon_ld1m2_q64(const __int64 * ptr);
__n64x3 neon_ld1m3_8(const __int8 * ptr);
__n128x3 neon_ld1m3_q8(const __int8 * ptr);
__n64x3 neon_ld1m3_16(const __int16 * ptr);
__n128x3 neon_ld1m3_q16(const __int16 * ptr);
__n64x3 neon_ld1m3_32(const __int32 * ptr);
__n128x3 neon_ld1m3_q32(const __int32 * ptr);
__n64x3 neon_ld1m3_64(const __int64 * ptr);
__n128x3 neon_ld1m3_q64(const __int64 * ptr);
__n64x4 neon_ld1m4_8(const __int8 * ptr);
__n128x4 neon_ld1m4_q8(const __int8 * ptr);
__n64x4 neon_ld1m4_16(const __int16 * ptr);
__n128x4 neon_ld1m4_q16(const __int16 * ptr);
__n64x4 neon_ld1m4_32(const __int32 * ptr);
__n128x4 neon_ld1m4_q32(const __int32 * ptr);
__n64x4 neon_ld1m4_64(const __int64 * ptr);
__n128x4 neon_ld1m4_q64(const __int64 * ptr);
__n64 neon_ld1s_8(const __int8 * ptr, __n64 src, const int lane);
__n128 neon_ld1s_q8(const __int8 * ptr, __n128 src, const int lane);
__n64 neon_ld1s_16(const __int16 * ptr, __n64 src, const int lane);
__n128 neon_ld1s_q16(const __int16 * ptr, __n128 src, const int lane);
__n64 neon_ld1s_32(const __int32 * ptr, __n64 src, const int lane);
__n128 neon_ld1s_q32(const __int32 * ptr, __n128 src, const int lane);
__n64 neon_ld1s_64(const __int64 * ptr, __n64 src, const int lane);
__n128 neon_ld1s_q64(const __int64 * ptr, __n128 src, const int lane);
#define vld4_dup_f32(src) neon_ld4r_32((__int32*)src)
#define vld4_dup_p16(src) neon_ld4r_16((__int16*)src)
#define vld4_dup_p8(src) neon_ld4r_8((__int8*)src)
#define vld4_dup_s16(src) neon_ld4r_16((__int16*)src)
#define vld4_dup_s32(src) neon_ld4r_32((__int32*)src)
#define vld4_dup_s8(src) neon_ld4r_8((__int8*)src)
#define vld4_dup_u16(src) neon_ld4r_16((__int16*)src)
#define vld4_dup_u32(src) neon_ld4r_32((__int32*)src)
#define vld4_dup_u8(src) neon_ld4r_8((__int8*)src)
#define vld4_dup_s64(src) neon_ld4r_64((__int64*)src)
#define vld4_dup_u64(src) neon_ld4r_64((__int64*)src)
#define vld4_f32(src) neon_ld4m_32((__int32*)src)
#define vld4_p16(src) neon_ld4m_16((__int16*)src)
#define vld4_p8(src) neon_ld4m_8((__int8*)src)
#define vld4_s16(src) neon_ld4m_16((__int16*)src)
#define vld4_s32(src) neon_ld4m_32((__int32*)src)
#define vld4_s8(src) neon_ld4m_8((__int8*)src)
#define vld4_u16(src) neon_ld4m_16((__int16*)src)
#define vld4_u32(src) neon_ld4m_32((__int32*)src)
#define vld4_u8(src) neon_ld4m_8((__int8*)src)
#define vld4_s64(src) neon_ld1m4_64((__int64*)src)
#define vld4_u64(src) neon_ld1m4_64((__int64*)src)
#define vld4q_dup_f32(src) neon_ld4r_q32((__int32*)src)
#define vld4q_dup_p16(src) neon_ld4r_q16((__int16*)src)
#define vld4q_dup_p8(src) neon_ld4r_q8((__int8*)src)
#define vld4q_dup_s16(src) neon_ld4r_q16((__int16*)src)
#define vld4q_dup_s32(src) neon_ld4r_q32((__int32*)src)
#define vld4q_dup_s8(src) neon_ld4r_q8((__int8*)src)
#define vld4q_dup_u16(src) neon_ld4r_q16((__int16*)src)
#define vld4q_dup_u32(src) neon_ld4r_q32((__int32*)src)
#define vld4q_dup_u8(src) neon_ld4r_q8((__int8*)src)
#define vld4q_dup_s64(src) neon_ld4r_q64((__int64*)src)
#define vld4q_dup_u64(src) neon_ld4r_q64((__int64*)src)
#define vld4q_f32(src) neon_ld4m_q32((__int32*)src)
#define vld4q_p16(src) neon_ld4m_q16((__int16*)src)
#define vld4q_p8(src) neon_ld4m_q8((__int8*)src)
#define vld4q_s16(src) neon_ld4m_q16((__int16*)src)
#define vld4q_s32(src) neon_ld4m_q32((__int32*)src)
#define vld4q_s8(src) neon_ld4m_q8((__int8*)src)
#define vld4q_u16(src) neon_ld4m_q16((__int16*)src)
#define vld4q_u32(src) neon_ld4m_q32((__int32*)src)
#define vld4q_u8(src) neon_ld4m_q8((__int8*)src)
#define vld4q_s64(src) neon_ld4m_q64((__int64*)src)
#define vld4q_u64(src) neon_ld4m_q64((__int64*)src)
#define vld4_lane_f32(src1, src2, src3) neon_ld4s_32((__int32*)src1, src2, src3)
#define vld4_lane_p16(src1, src2, src3) neon_ld4s_16((__int16*)src1, src2, src3)
#define vld4_lane_p8(src1, src2, src3) neon_ld4s_8((__int8*)src1, src2, src3)
#define vld4_lane_s16(src1, src2, src3) neon_ld4s_16((__int16*)src1, src2, src3)
#define vld4_lane_s32(src1, src2, src3) neon_ld4s_32((__int32*)src1, src2, src3)
#define vld4_lane_s64(src1, src2, src3) neon_ld4s_64((__int64*)src1, src2, src3)
#define vld4_lane_s8(src1, src2, src3) neon_ld4s_8((__int8*)src1, src2, src3)
#define vld4_lane_u16(src1, src2, src3) neon_ld4s_16((__int16*)src1, src2, src3)
#define vld4_lane_u32(src1, src2, src3) neon_ld4s_32((__int32*)src1, src2, src3)
#define vld4_lane_u8(src1, src2, src3) neon_ld4s_8((__int8*)src1, src2, src3)
#define vld4q_lane_f32(src1, src2, src3) neon_ld4s_q32((__int32*)src1, src2, src3)
#define vld4q_lane_p8(src1, src2, src3) neon_ld4s_q8((__int8*)src1, src2, src3)
#define vld4q_lane_p16(src1, src2, src3) neon_ld4s_q16((__int16*)src1, src2, src3)
#define vld4q_lane_s16(src1, src2, src3) neon_ld4s_q16((__int16*)src1, src2, src3)
#define vld4q_lane_s32(src1, src2, src3) neon_ld4s_q32((__int32*)src1, src2, src3)
#define vld4q_lane_s64(src1, src2, src3) neon_ld4s_q64((__int64*)src1, src2, src3)
#define vld4q_lane_u16(src1, src2, src3) neon_ld4s_q16((__int16*)src1, src2, src3)
#define vld4q_lane_u32(src1, src2, src3) neon_ld4s_q32((__int32*)src2, src3)
#define vld3_dup_f32(src) neon_ld3r_32((__int32*)src)
#define vld3_dup_p16(src) neon_ld3r_16((__int16*)src)
#define vld3_dup_p8(src) neon_ld3r_8((__int8*)src)
#define vld3_dup_s16(src) neon_ld3r_16((__int16*)src)
#define vld3_dup_s32(src) neon_ld3r_32((__int32*)src)
#define vld3_dup_s8(src) neon_ld3r_8((__int8*)src)
#define vld3_dup_u16(src) neon_ld3r_16((__int16*)src)
#define vld3_dup_u32(src) neon_ld3r_32((__int32*)src)
#define vld3_dup_u8(src) neon_ld3r_8((__int8*)src)
#define vld3_dup_s64(src) neon_ld3r_64((__int64*)src)
#define vld3_dup_u64(src) neon_ld3r_64((__int64*)src)
#define vld3_f32(src) neon_ld3m_32((__int32*)src)
#define vld3_p16(src) neon_ld3m_16((__int16*)src)
#define vld3_p8(src) neon_ld3m_8((__int8*)src)
#define vld3_s16(src) neon_ld3m_16((__int16*)src)
#define vld3_s32(src) neon_ld3m_32((__int32*)src)
#define vld3_s8(src) neon_ld3m_8((__int8*)src)
#define vld3_u16(src) neon_ld3m_16((__int16*)src)
#define vld3_u32(src) neon_ld3m_32((__int32*)src)
#define vld3_u8(src) neon_ld3m_8((__int8*)src)
#define vld3_s64(src) neon_ld1m3_64((__int64*)src)
#define vld3_u64(src) neon_ld1m3_64((__int64*)src)
#define vld3q_dup_f32(src) neon_ld3r_q32((__int32*)src)
#define vld3q_dup_p16(src) neon_ld3r_q16((__int16*)src)
#define vld3q_dup_p8(src) neon_ld3r_q8((__int8*)src)
#define vld3q_dup_s16(src) neon_ld3r_q16((__int16*)src)
#define vld3q_dup_s32(src) neon_ld3r_q32((__int32*)src)
#define vld3q_dup_s8(src) neon_ld3r_q8((__int8*)src)
#define vld3q_dup_u16(src) neon_ld3r_q16((__int16*)src)
#define vld3q_dup_u32(src) neon_ld3r_q32((__int32*)src)
#define vld3q_dup_u8(src) neon_ld3r_q8((__int8*)src)
#define vld3q_dup_s64(src) neon_ld3r_q64((__int64*)src)
#define vld3q_dup_u64(src) neon_ld3r_q64((__int64*)src)
#define vld3q_f32(src) neon_ld3m_q32((__int32*)src)
#define vld3q_p16(src) neon_ld3m_q16((__int16*)src)
#define vld3q_p8(src) neon_ld3m_q8((__int8*)src)
#define vld3q_s16(src) neon_ld3m_q16((__int16*)src)
#define vld3q_s32(src) neon_ld3m_q32((__int32*)src)
#define vld3q_s8(src) neon_ld3m_q8((__int8*)src)
#define vld3q_u16(src) neon_ld3m_q16((__int16*)src)
#define vld3q_u32(src) neon_ld3m_q32((__int32*)src)
#define vld3q_u8(src) neon_ld3m_q8((__int8*)src)
#define vld3q_s64(src) neon_ld3m_q64((__int64*)src)
#define vld3q_u64(src) neon_ld3m_q64((__int64*)src)
#define vld3_lane_f32(src1, src2, src3) neon_ld3s_32((__int32*)src1, src2, src3)
#define vld3_lane_p16(src1, src2, src3) neon_ld3s_16((__int16*)src1, src2, src3)
#define vld3_lane_p8(src1, src2, src3) neon_ld3s_8((__int8*)src1, src2, src3)
#define vld3_lane_s16(src1, src2, src3) neon_ld3s_16((__int16*)src1, src2, src3)
#define vld3_lane_s32(src1, src2, src3) neon_ld3s_32((__int32*)src1, src2, src3)
#define vld3_lane_s64(src1, src2, src3) neon_ld3s_64((__int64*)src1, src2, src3)
#define vld3_lane_s8(src1, src2, src3) neon_ld3s_8((__int8*)src1, src2, src3)
#define vld3_lane_u16(src1, src2, src3) neon_ld3s_16((__int16*)src1, src2, src3)
#define vld3_lane_u32(src1, src2, src3) neon_ld3s_32((__int32*)src1, src2, src3)
#define vld3_lane_u8(src1, src2, src3) neon_ld3s_8((__int8*)src1, src2, src3)
#define vld3q_lane_f32(src1, src2, src3) neon_ld3s_q32((__int32*)src1, src2, src3)
#define vld3q_lane_p8(src1, src2, src3) neon_ld3s_q8((__int8*)src1, src2, src3)
#define vld3q_lane_p16(src1, src2, src3) neon_ld3s_q16((__int16*)src1, src2, src3)
#define vld3q_lane_s16(src1, src2, src3) neon_ld3s_q16((__int16*)src1, src2, src3)
#define vld3q_lane_s32(src1, src2, src3) neon_ld3s_q32((__int32*)src1, src2, src3)
#define vld3q_lane_s64(src1, src2, src3) neon_ld3s_q64((__int64*)src1, src2, src3)
#define vld3q_lane_u16(src1, src2, src3) neon_ld3s_q16((__int16*)src1, src2, src3)
#define vld3q_lane_u32(src1, src2, src3) neon_ld3s_q32((__int32*)src2, src3)
#define vld2_dup_f32(src) neon_ld2r_32((__int32*)src)
#define vld2_dup_p16(src) neon_ld2r_16((__int16*)src)
#define vld2_dup_p8(src) neon_ld2r_8((__int8*)src)
#define vld2_dup_s16(src) neon_ld2r_16((__int16*)src)
#define vld2_dup_s32(src) neon_ld2r_32((__int32*)src)
#define vld2_dup_s8(src) neon_ld2r_8((__int8*)src)
#define vld2_dup_u16(src) neon_ld2r_16((__int16*)src)
#define vld2_dup_u32(src) neon_ld2r_32((__int32*)src)
#define vld2_dup_u8(src) neon_ld2r_8((__int8*)src)
#define vld2_dup_s64(src) neon_ld2r_64((__int64*)src)
#define vld2_dup_u64(src) neon_ld2r_64((__int64*)src)
#define vld2_f32(src) neon_ld2m_32((__int32*)src)
#define vld2_p16(src) neon_ld2m_16((__int16*)src)
#define vld2_p8(src) neon_ld2m_8((__int8*)src)
#define vld2_s16(src) neon_ld2m_16((__int16*)src)
#define vld2_s32(src) neon_ld2m_32((__int32*)src)
#define vld2_s8(src) neon_ld2m_8((__int8*)src)
#define vld2_u16(src) neon_ld2m_16((__int16*)src)
#define vld2_u32(src) neon_ld2m_32((__int32*)src)
#define vld2_u8(src) neon_ld2m_8((__int8*)src)
#define vld2_s64(src) neon_ld1m2_64((__int64*)src)
#define vld2_u64(src) neon_ld1m2_64((__int64*)src)
#define vld2q_dup_f32(src) neon_ld2r_q32((__int32*)src)
#define vld2q_dup_p16(src) neon_ld2r_q16((__int16*)src)
#define vld2q_dup_p8(src) neon_ld2r_q8((__int8*)src)
#define vld2q_dup_s16(src) neon_ld2r_q16((__int16*)src)
#define vld2q_dup_s32(src) neon_ld2r_q32((__int32*)src)
#define vld2q_dup_s8(src) neon_ld2r_q8((__int8*)src)
#define vld2q_dup_u16(src) neon_ld2r_q16((__int16*)src)
#define vld2q_dup_u32(src) neon_ld2r_q32((__int32*)src)
#define vld2q_dup_u8(src) neon_ld2r_q8((__int8*)src)
#define vld2q_dup_s64(src) neon_ld2r_q64((__int64*)src)
#define vld2q_dup_u64(src) neon_ld2r_q64((__int64*)src)
#define vld2q_f32(src) neon_ld2m_q32((__int32*)src)
#define vld2q_p16(src) neon_ld2m_q16((__int16*)src)
#define vld2q_p8(src) neon_ld2m_q8((__int8*)src)
#define vld2q_s16(src) neon_ld2m_q16((__int16*)src)
#define vld2q_s32(src) neon_ld2m_q32((__int32*)src)
#define vld2q_s8(src) neon_ld2m_q8((__int8*)src)
#define vld2q_u16(src) neon_ld2m_q16((__int16*)src)
#define vld2q_u32(src) neon_ld2m_q32((__int32*)src)
#define vld2q_u8(src) neon_ld2m_q8((__int8*)src)
#define vld2q_s64(src) neon_ld2m_q64((__int64*)src)
#define vld2q_u64(src) neon_ld2m_q64((__int64*)src)
#define vld2_lane_f32(src1, src2, src3) neon_ld2s_32((__int32*)src1, src2, src3)
#define vld2_lane_p16(src1, src2, src3) neon_ld2s_16((__int16*)src1, src2, src3)
#define vld2_lane_p8(src1, src2, src3) neon_ld2s_8((__int8*)src1, src2, src3)
#define vld2_lane_s16(src1, src2, src3) neon_ld2s_16((__int16*)src1, src2, src3)
#define vld2_lane_s32(src1, src2, src3) neon_ld2s_32((__int32*)src1, src2, src3)
#define vld2_lane_s64(src1, src2, src3) neon_ld2s_64((__int64*)src1, src2, src3)
#define vld2_lane_s8(src1, src2, src3) neon_ld2s_8((__int8*)src1, src2, src3)
#define vld2_lane_u16(src1, src2, src3) neon_ld2s_16((__int16*)src1, src2, src3)
#define vld2_lane_u32(src1, src2, src3) neon_ld2s_32((__int32*)src1, src2, src3)
#define vld2_lane_u8(src1, src2, src3) neon_ld2s_8((__int8*)src1, src2, src3)
#define vld2q_lane_f32(src1, src2, src3) neon_ld2s_q32((__int32*)src1, src2, src3)
#define vld2q_lane_p8(src1, src2, src3) neon_ld2s_q8((__int8*)src1, src2, src3)
#define vld2q_lane_p16(src1, src2, src3) neon_ld2s_q16((__int16*)src1, src2, src3)
#define vld2q_lane_s16(src1, src2, src3) neon_ld2s_q16((__int16*)src1, src2, src3)
#define vld2q_lane_s32(src1, src2, src3) neon_ld2s_q32((__int32*)src1, src2, src3)
#define vld2q_lane_s64(src1, src2, src3) neon_ld2s_q64((__int64*)src1, src2, src3)
#define vld2q_lane_u16(src1, src2, src3) neon_ld2s_q16((__int16*)src1, src2, src3)
#define vld2q_lane_u32(src1, src2, src3) neon_ld2s_q32((__int32*)src2, src3)
#define vld1_dup_f32(src) neon_ld1r_32((__int32*)src)
#define vld1_dup_p16(src) neon_ld1r_16((__int16*)src)
#define vld1_dup_p8(src) neon_ld1r_8((__int8*)src)
#define vld1_dup_s16(src) neon_ld1r_16((__int16*)src)
#define vld1_dup_s32(src) neon_ld1r_32((__int32*)src)
#define vld1_dup_s8(src) neon_ld1r_8((__int8*)src)
#define vld1_dup_u16(src) neon_ld1r_16((__int16*)src)
#define vld1_dup_u32(src) neon_ld1r_32((__int32*)src)
#define vld1_dup_u8(src) neon_ld1r_8((__int8*)src)
#define vld1_dup_s64(src) neon_ld1r_64((__int64*)src)
#define vld1_dup_u64(src) neon_ld1r_64((__int64*)src)
#define vld1_f32(src) neon_ld1m_32((__int32*)src)
#define vld1_p16(src) neon_ld1m_16((__int16*)src)
#define vld1_p8(src) neon_ld1m_8((__int8*)src)
#define vld1_s16(src) neon_ld1m_16((__int16*)src)
#define vld1_s32(src) neon_ld1m_32((__int32*)src)
#define vld1_s8(src) neon_ld1m_8((__int8*)src)
#define vld1_u16(src) neon_ld1m_16((__int16*)src)
#define vld1_u32(src) neon_ld1m_32((__int32*)src)
#define vld1_u8(src) neon_ld1m_8((__int8*)src)
#define vld1_s64(src) neon_ld1m_64((__int64*)src)
#define vld1_u64(src) neon_ld1m_64((__int64*)src)
#define vld1_f64(src) neon_ld1m_64((__int64*)src)
#define vld1_f32_x2(src) neon_ld1m2_32((__int32*)src)
#define vld1_p16_x2(src) neon_ld1m2_16((__int16*)src)
#define vld1_p8_x2(src) neon_ld1m2_8((__int8*)src)
#define vld1_s16_x2(src) neon_ld1m2_16((__int16*)src)
#define vld1_s32_x2(src) neon_ld1m2_32((__int32*)src)
#define vld1_s8_x2(src) neon_ld1m2_8((__int8*)src)
#define vld1_u16_x2(src) neon_ld1m2_16((__int16*)src)
#define vld1_u32_x2(src) neon_ld1m2_32((__int32*)src)
#define vld1_u8_x2(src) neon_ld1m2_8((__int8*)src)
#define vld1_s64_x2(src) neon_ld1m2_64((__int64*)src)
#define vld1_u64_x2(src) neon_ld1m2_64((__int64*)src)
#define vld1_f64_x2(src) neon_ld1m2_64((__int64*)src)
#define vld1_f32_x3(src) neon_ld1m3_32((__int32*)src)
#define vld1_p16_x3(src) neon_ld1m3_16((__int16*)src)
#define vld1_p8_x3(src) neon_ld1m3_8((__int8*)src)
#define vld1_s16_x3(src) neon_ld1m3_16((__int16*)src)
#define vld1_s32_x3(src) neon_ld1m3_32((__int32*)src)
#define vld1_s8_x3(src) neon_ld1m3_8((__int8*)src)
#define vld1_u16_x3(src) neon_ld1m3_16((__int16*)src)
#define vld1_u32_x3(src) neon_ld1m3_32((__int32*)src)
#define vld1_u8_x3(src) neon_ld1m3_8((__int8*)src)
#define vld1_s64_x3(src) neon_ld1m3_64((__int64*)src)
#define vld1_u64_x3(src) neon_ld1m3_64((__int64*)src)
#define vld1_f64_x3(src) neon_ld1m3_64((__int64*)src)
#define vld1_f32_x4(src) neon_ld1m4_32((__int32*)src)
#define vld1_p16_x4(src) neon_ld1m4_16((__int16*)src)
#define vld1_p8_x4(src) neon_ld1m4_8((__int8*)src)
#define vld1_s16_x4(src) neon_ld1m4_16((__int16*)src)
#define vld1_s32_x4(src) neon_ld1m4_32((__int32*)src)
#define vld1_s8_x4(src) neon_ld1m4_8((__int8*)src)
#define vld1_u16_x4(src) neon_ld1m4_16((__int16*)src)
#define vld1_u32_x4(src) neon_ld1m4_32((__int32*)src)
#define vld1_u8_x4(src) neon_ld1m4_8((__int8*)src)
#define vld1_s64_x4(src) neon_ld1m4_64((__int64*)src)
#define vld1_u64_x4(src) neon_ld1m4_64((__int64*)src)
#define vld1_f64_x4(src) neon_ld1m4_64((__int64*)src)
#define vld1q_dup_f32(src) neon_ld1r_q32((__int32*)src)
#define vld1q_dup_p16(src) neon_ld1r_q16((__int16*)src)
#define vld1q_dup_p8(src) neon_ld1r_q8((__int8*)src)
#define vld1q_dup_s16(src) neon_ld1r_q16((__int16*)src)
#define vld1q_dup_s32(src) neon_ld1r_q32((__int32*)src)
#define vld1q_dup_s8(src) neon_ld1r_q8((__int8*)src)
#define vld1q_dup_u16(src) neon_ld1r_q16((__int16*)src)
#define vld1q_dup_u32(src) neon_ld1r_q32((__int32*)src)
#define vld1q_dup_u8(src) neon_ld1r_q8((__int8*)src)
#define vld1q_dup_s64(src) neon_ld1r_q64((__int64*)src)
#define vld1q_dup_u64(src) neon_ld1r_q64((__int64*)src)
#define vld1q_f32(src) neon_ld1m_q32((__int32*)src)
#define vld1q_p16(src) neon_ld1m_q16((__int16*)src)
#define vld1q_p8(src) neon_ld1m_q8((__int8*)src)
#define vld1q_s16(src) neon_ld1m_q16((__int16*)src)
#define vld1q_s32(src) neon_ld1m_q32((__int32*)src)
#define vld1q_s8(src) neon_ld1m_q8((__int8*)src)
#define vld1q_u16(src) neon_ld1m_q16((__int16*)src)
#define vld1q_u32(src) neon_ld1m_q32((__int32*)src)
#define vld1q_u8(src) neon_ld1m_q8((__int8*)src)
#define vld1q_s64(src) neon_ld1m_q64((__int64*)src)
#define vld1q_u64(src) neon_ld1m_q64((__int64*)src)
#define vld1q_f32_x2(src) neon_ld1m2_q32((__int32*)src)
#define vld1q_p16_x2(src) neon_ld1m2_q16((__int16*)src)
#define vld1q_p8_x2(src) neon_ld1m2_q8((__int8*)src)
#define vld1q_s16_x2(src) neon_ld1m2_q16((__int16*)src)
#define vld1q_s32_x2(src) neon_ld1m2_q32((__int32*)src)
#define vld1q_s8_x2(src) neon_ld1m2_q8((__int8*)src)
#define vld1q_u16_x2(src) neon_ld1m2_q16((__int16*)src)
#define vld1q_u32_x2(src) neon_ld1m2_q32((__int32*)src)
#define vld1q_u8_x2(src) neon_ld1m2_q8((__int8*)src)
#define vld1q_s64_x2(src) neon_ld1m2_q64((__int64*)src)
#define vld1q_u64_x2(src) neon_ld1m2_q64((__int64*)src)
#define vld1q_f32_x3(src) neon_ld1m3_q32((__int32*)src)
#define vld1q_p16_x3(src) neon_ld1m3_q16((__int16*)src)
#define vld1q_p8_x3(src) neon_ld1m3_q8((__int8*)src)
#define vld1q_s16_x3(src) neon_ld1m3_q16((__int16*)src)
#define vld1q_s32_x3(src) neon_ld1m3_q32((__int32*)src)
#define vld1q_s8_x3(src) neon_ld1m3_q8((__int8*)src)
#define vld1q_u16_x3(src) neon_ld1m3_q16((__int16*)src)
#define vld1q_u32_x3(src) neon_ld1m3_q32((__int32*)src)
#define vld1q_u8_x3(src) neon_ld1m3_q8((__int8*)src)
#define vld1q_s64_x3(src) neon_ld1m3_q64((__int64*)src)
#define vld1q_u64_x3(src) neon_ld1m3_q64((__int64*)src)
#define vld1q_f32_x4(src) neon_ld1m4_q32((__int32*)src)
#define vld1q_p16_x4(src) neon_ld1m4_q16((__int16*)src)
#define vld1q_p8_x4(src) neon_ld1m4_q8((__int8*)src)
#define vld1q_s16_x4(src) neon_ld1m4_q16((__int16*)src)
#define vld1q_s32_x4(src) neon_ld1m4_q32((__int32*)src)
#define vld1q_s8_x4(src) neon_ld1m4_q8((__int8*)src)
#define vld1q_u16_x4(src) neon_ld1m4_q16((__int16*)src)
#define vld1q_u32_x4(src) neon_ld1m4_q32((__int32*)src)
#define vld1q_u8_x4(src) neon_ld1m4_q8((__int8*)src)
#define vld1q_s64_x4(src) neon_ld1m4_q64((__int64*)src)
#define vld1q_u64_x4(src) neon_ld1m4_q64((__int64*)src)
#define vld1_lane_f32(src1, src2, src3) neon_ld1s_32((__int32*)src1, src2, src3)
#define vld1_lane_p16(src1, src2, src3) neon_ld1s_16((__int16*)src1, src2, src3)
#define vld1_lane_p8(src1, src2, src3) neon_ld1s_8((__int8*)src1, src2, src3)
#define vld1_lane_s16(src1, src2, src3) neon_ld1s_16((__int16*)src1, src2, src3)
#define vld1_lane_s32(src1, src2, src3) neon_ld1s_32((__int32*)src1, src2, src3)
#define vld1_lane_s64(src1, src2, src3) neon_ld1s_64((__int64*)src1, src2, src3)
#define vld1_lane_s8(src1, src2, src3) neon_ld1s_8((__int8*)src1, src2, src3)
#define vld1_lane_u16(src1, src2, src3) neon_ld1s_16((__int16*)src1, src2, src3)
#define vld1_lane_u32(src1, src2, src3) neon_ld1s_32((__int32*)src1, src2, src3)
#define vld1_lane_u8(src1, src2, src3) neon_ld1s_8((__int8*)src1, src2, src3)
#define vld1q_lane_f32(src1, src2, src3) neon_ld1s_q32((__int32*)src1, src2, src3)
#define vld1q_lane_p8(src1, src2, src3) neon_ld1s_q8((__int8*)src1, src2, src3)
#define vld1q_lane_p16(src1, src2, src3) neon_ld1s_q16((__int16*)src1, src2, src3)
#define vld1q_lane_s16(src1, src2, src3) neon_ld1s_q16((__int16*)src1, src2, src3)
#define vld1q_lane_s32(src1, src2, src3) neon_ld1s_q32((__int32*)src1, src2, src3)
#define vld1q_lane_s64(src1, src2, src3) neon_ld1s_q64((__int64*)src1, src2, src3)
#define vld1q_lane_u16(src1, src2, src3) neon_ld1s_q16((__int16*)src1, src2, src3)
#define vld1q_lane_u32(src1, src2, src3) neon_ld1s_q32((__int32*)src1, src2, src3)
#define vld4_dup_f32_ex(src, align) neon_ld4r_32((__int32*)src)
#define vld4_dup_p16_ex(src, align) neon_ld4r_16((__int16*)src)
#define vld4_dup_p8_ex(src, align) neon_ld4r_8((__int8*)src)
#define vld4_dup_s16_ex(src, align) neon_ld4r_16((__int16*)src)
#define vld4_dup_s32_ex(src, align) neon_ld4r_32((__int32*)src)
#define vld4_dup_s8_ex(src, align) neon_ld4r_8((__int8*)src)
#define vld4_dup_u16_ex(src, align) neon_ld4r_16((__int16*)src)
#define vld4_dup_u32_ex(src, align) neon_ld4r_32((__int32*)src)
#define vld4_dup_u8_ex(src, align) neon_ld4r_8((__int8*)src)
#define vld4_dup_s64_ex(src, align) neon_ld4r_64((__int64*)src)
#define vld4_dup_u64_ex(src, align) neon_ld4r_64((__int64*)src)
#define vld4_f32_ex(src, align) neon_ld4m_32((__int32*)src)
#define vld4_p16_ex(src, align) neon_ld4m_16((__int16*)src)
#define vld4_p8_ex(src, align) neon_ld4m_8((__int8*)src)
#define vld4_s16_ex(src, align) neon_ld4m_16((__int16*)src)
#define vld4_s32_ex(src, align) neon_ld4m_32((__int32*)src)
#define vld4_s8_ex(src, align) neon_ld4m_8((__int8*)src)
#define vld4_u16_ex(src, align) neon_ld4m_16((__int16*)src)
#define vld4_u32_ex(src, align) neon_ld4m_32((__int32*)src)
#define vld4_u8_ex(src, align) neon_ld4m_8((__int8*)src)
#define vld4_s64_ex(src, align) neon_ld1m4_64((__int64*)src)
#define vld4_u64_ex(src, align) neon_ld1m4_64((__int64*)src)
#define vld4q_dup_f32_ex(src, align) neon_ld4r_q32((__int32*)src)
#define vld4q_dup_p16_ex(src, align) neon_ld4r_q16((__int16*)src)
#define vld4q_dup_p8_ex(src, align) neon_ld4r_q8((__int8*)src)
#define vld4q_dup_s16_ex(src, align) neon_ld4r_q16((__int16*)src)
#define vld4q_dup_s32_ex(src, align) neon_ld4r_q32((__int32*)src)
#define vld4q_dup_s8_ex(src, align) neon_ld4r_q8((__int8*)src)
#define vld4q_dup_u16_ex(src, align) neon_ld4r_q16((__int16*)src)
#define vld4q_dup_u32_ex(src, align) neon_ld4r_q32((__int32*)src)
#define vld4q_dup_u8_ex(src, align) neon_ld4r_q8((__int8*)src)
#define vld4q_dup_s64_ex(src, align) neon_ld4r_q64((__int64*)src)
#define vld4q_dup_u64_ex(src, align) neon_ld4r_q64((__int64*)src)
#define vld4q_f32_ex(src, align) neon_ld4m_q32((__int32*)src)
#define vld4q_p16_ex(src, align) neon_ld4m_q16((__int16*)src)
#define vld4q_p8_ex(src, align) neon_ld4m_q8((__int8*)src)
#define vld4q_s16_ex(src, align) neon_ld4m_q16((__int16*)src)
#define vld4q_s32_ex(src, align) neon_ld4m_q32((__int32*)src)
#define vld4q_s8_ex(src, align) neon_ld4m_q8((__int8*)src)
#define vld4q_u16_ex(src, align) neon_ld4m_q16((__int16*)src)
#define vld4q_u32_ex(src, align) neon_ld4m_q32((__int32*)src)
#define vld4q_u8_ex(src, align) neon_ld4m_q8((__int8*)src)
#define vld4q_s64_ex(src, align) neon_ld4m_q64((__int64*)src)
#define vld4q_u64_ex(src, align) neon_ld4m_q64((__int64*)src)
#define vld4_lane_f32_ex(src1, src2, src3) neon_ld4s_32((__int32*)src1, src2, src3)
#define vld4_lane_p16_ex(src1, src2, src3) neon_ld4s_16((__int16*)src1, src2, src3)
#define vld4_lane_p8_ex(src1, src2, src3) neon_ld4s_8((__int8*)src1, src2, src3)
#define vld4_lane_s16_ex(src1, src2, src3) neon_ld4s_16((__int16*)src1, src2, src3)
#define vld4_lane_s32_ex(src1, src2, src3) neon_ld4s_32((__int32*)src1, src2, src3)
#define vld4_lane_s64_ex(src1, src2, src3) neon_ld4s_64((__int64*)src1, src2, src3)
#define vld4_lane_s8_ex(src1, src2, src3) neon_ld4s_8((__int8*)src1, src2, src3)
#define vld4_lane_u16_ex(src1, src2, src3) neon_ld4s_16((__int16*)src1, src2, src3)
#define vld4_lane_u32_ex(src1, src2, src3) neon_ld4s_32((__int32*)src1, src2, src3)
#define vld4_lane_u8_ex(src1, src2, src3) neon_ld4s_8((__int8*)src1, src2, src3)
#define vld4q_lane_f32_ex(src1, src2, src3) neon_ld4s_q32((__int32*)src1, src2, src3)
#define vld4q_lane_p8_ex(src1, src2, src3) neon_ld4s_q8((__int8*)src1, src2, src3)
#define vld4q_lane_p16_ex(src1, src2, src3) neon_ld4s_q16((__int16*)src1, src2, src3)
#define vld4q_lane_s16_ex(src1, src2, src3) neon_ld4s_q16((__int16*)src1, src2, src3)
#define vld4q_lane_s32_ex(src1, src2, src3) neon_ld4s_q32((__int32*)src1, src2, src3)
#define vld4q_lane_s64_ex(src1, src2, src3) neon_ld4s_q64((__int64*)src1, src2, src3)
#define vld4q_lane_u16_ex(src1, src2, src3) neon_ld4s_q16((__int16*)src1, src2, src3)
#define vld4q_lane_u32_ex(src1, src2, src3) neon_ld4s_q32((__int32*)src1, src2, src3)
#define vld3_dup_f32_ex(src, align) neon_ld3r_32((__int32*)src)
#define vld3_dup_p16_ex(src, align) neon_ld3r_16((__int16*)src)
#define vld3_dup_p8_ex(src, align) neon_ld3r_8((__int8*)src)
#define vld3_dup_s16_ex(src, align) neon_ld3r_16((__int16*)src)
#define vld3_dup_s32_ex(src, align) neon_ld3r_32((__int32*)src)
#define vld3_dup_s8_ex(src, align) neon_ld3r_8((__int8*)src)
#define vld3_dup_u16_ex(src, align) neon_ld3r_16((__int16*)src)
#define vld3_dup_u32_ex(src, align) neon_ld3r_32((__int32*)src)
#define vld3_dup_u8_ex(src, align) neon_ld3r_8((__int8*)src)
#define vld3_dup_s64_ex(src, align) neon_ld3r_64((__int64*)src)
#define vld3_dup_u64_ex(src, align) neon_ld3r_64((__int64*)src)
#define vld3_f32_ex(src, align) neon_ld3m_32((__int32*)src)
#define vld3_p16_ex(src, align) neon_ld3m_16((__int16*)src)
#define vld3_p8_ex(src, align) neon_ld3m_8((__int8*)src)
#define vld3_s16_ex(src, align) neon_ld3m_16((__int16*)src)
#define vld3_s32_ex(src, align) neon_ld3m_32((__int32*)src)
#define vld3_s8_ex(src, align) neon_ld3m_8((__int8*)src)
#define vld3_u16_ex(src, align) neon_ld3m_16((__int16*)src)
#define vld3_u32_ex(src, align) neon_ld3m_32((__int32*)src)
#define vld3_u8_ex(src, align) neon_ld3m_8((__int8*)src)
#define vld3_s64_ex(src, align) neon_ld1m3_64((__int64*)src)
#define vld3_u64_ex(src, align) neon_ld1m3_64((__int64*)src)
#define vld3q_dup_f32_ex(src, align) neon_ld3r_q32((__int32*)src)
#define vld3q_dup_p16_ex(src, align) neon_ld3r_q16((__int16*)src)
#define vld3q_dup_p8_ex(src, align) neon_ld3r_q8((__int8*)src)
#define vld3q_dup_s16_ex(src, align) neon_ld3r_q16((__int16*)src)
#define vld3q_dup_s32_ex(src, align) neon_ld3r_q32((__int32*)src)
#define vld3q_dup_s8_ex(src, align) neon_ld3r_q8((__int8*)src)
#define vld3q_dup_u16_ex(src, align) neon_ld3r_q16((__int16*)src)
#define vld3q_dup_u32_ex(src, align) neon_ld3r_q32((__int32*)src)
#define vld3q_dup_u8_ex(src, align) neon_ld3r_q8((__int8*)src)
#define vld3q_dup_s64_ex(src, align) neon_ld3r_q64((__int64*)src)
#define vld3q_dup_u64_ex(src, align) neon_ld3r_q64((__int64*)src)
#define vld3q_f32_ex(src, align) neon_ld3m_q32((__int32*)src)
#define vld3q_p16_ex(src, align) neon_ld3m_q16((__int16*)src)
#define vld3q_p8_ex(src, align) neon_ld3m_q8((__int8*)src)
#define vld3q_s16_ex(src, align) neon_ld3m_q16((__int16*)src)
#define vld3q_s32_ex(src, align) neon_ld3m_q32((__int32*)src)
#define vld3q_s8_ex(src, align) neon_ld3m_q8((__int8*)src)
#define vld3q_u16_ex(src, align) neon_ld3m_q16((__int16*)src)
#define vld3q_u32_ex(src, align) neon_ld3m_q32((__int32*)src)
#define vld3q_u8_ex(src, align) neon_ld3m_q8((__int8*)src)
#define vld3q_s64_ex(src, align) neon_ld3m_q64((__int64*)src)
#define vld3q_u64_ex(src, align) neon_ld3m_q64((__int64*)src)
#define vld3_lane_f32_ex(src1, src2, src3) neon_ld3s_32((__int32*)src1, src2, src3)
#define vld3_lane_p16_ex(src1, src2, src3) neon_ld3s_16((__int16*)src1, src2, src3)
#define vld3_lane_p8_ex(src1, src2, src3) neon_ld3s_8((__int8*)src1, src2, src3)
#define vld3_lane_s16_ex(src1, src2, src3) neon_ld3s_16((__int16*)src1, src2, src3)
#define vld3_lane_s32_ex(src1, src2, src3) neon_ld3s_32((__int32*)src1, src2, src3)
#define vld3_lane_s64_ex(src1, src2, src3) neon_ld3s_64((__int64*)src1, src2, src3)
#define vld3_lane_s8_ex(src1, src2, src3) neon_ld3s_8((__int8*)src1, src2, src3)
#define vld3_lane_u16_ex(src1, src2, src3) neon_ld3s_16((__int16*)src1, src2, src3)
#define vld3_lane_u32_ex(src1, src2, src3) neon_ld3s_32((__int32*)src1, src2, src3)
#define vld3_lane_u8_ex(src1, src2, src3) neon_ld3s_8((__int8*)src1, src2, src3)
#define vld3q_lane_f32_ex(src1, src2, src3) neon_ld3s_q32((__int32*)src1, src2, src3)
#define vld3q_lane_p8_ex(src1, src2, src3) neon_ld3s_q8((__int8*)src1, src2, src3)
#define vld3q_lane_p16_ex(src1, src2, src3) neon_ld3s_q16((__int16*)src1, src2, src3)
#define vld3q_lane_s16_ex(src1, src2, src3) neon_ld3s_q16((__int16*)src1, src2, src3)
#define vld3q_lane_s32_ex(src1, src2, src3) neon_ld3s_q32((__int32*)src1, src2, src3)
#define vld3q_lane_s64_ex(src1, src2, src3) neon_ld3s_q64((__int64*)src1, src2, src3)
#define vld3q_lane_u16_ex(src1, src2, src3) neon_ld3s_q16((__int16*)src1, src2, src3)
#define vld3q_lane_u32_ex(src1, src2, src3) neon_ld3s_q32((__int32*)src1, src2, src3)
#define vld2_dup_f32_ex(src, align) neon_ld2r_32((__int32*)src)
#define vld2_dup_p16_ex(src, align) neon_ld2r_16((__int16*)src)
#define vld2_dup_p8_ex(src, align) neon_ld2r_8((__int8*)src)
#define vld2_dup_s16_ex(src, align) neon_ld2r_16((__int16*)src)
#define vld2_dup_s32_ex(src, align) neon_ld2r_32((__int32*)src)
#define vld2_dup_s8_ex(src, align) neon_ld2r_8((__int8*)src)
#define vld2_dup_u16_ex(src, align) neon_ld2r_16((__int16*)src)
#define vld2_dup_u32_ex(src, align) neon_ld2r_32((__int32*)src)
#define vld2_dup_u8_ex(src, align) neon_ld2r_8((__int8*)src)
#define vld2_dup_s64_ex(src, align) neon_ld2r_64((__int64*)src)
#define vld2_dup_u64_ex(src, align) neon_ld2r_64((__int64*)src)
#define vld2_f32_ex(src, align) neon_ld2m_32((__int32*)src)
#define vld2_p16_ex(src, align) neon_ld2m_16((__int16*)src)
#define vld2_p8_ex(src, align) neon_ld2m_8((__int8*)src)
#define vld2_s16_ex(src, align) neon_ld2m_16((__int16*)src)
#define vld2_s32_ex(src, align) neon_ld2m_32((__int32*)src)
#define vld2_s8_ex(src, align) neon_ld2m_8((__int8*)src)
#define vld2_u16_ex(src, align) neon_ld2m_16((__int16*)src)
#define vld2_u32_ex(src, align) neon_ld2m_32((__int32*)src)
#define vld2_u8_ex(src, align) neon_ld2m_8((__int8*)src)
#define vld2_s64_ex(src, align) neon_ld1m2_64((__int64*)src)
#define vld2_u64_ex(src, align) neon_ld1m2_64((__int64*)src)
#define vld2q_dup_f32_ex(src, align) neon_ld2r_q32((__int32*)src)
#define vld2q_dup_p16_ex(src, align) neon_ld2r_q16((__int16*)src)
#define vld2q_dup_p8_ex(src, align) neon_ld2r_q8((__int8*)src)
#define vld2q_dup_s16_ex(src, align) neon_ld2r_q16((__int16*)src)
#define vld2q_dup_s32_ex(src, align) neon_ld2r_q32((__int32*)src)
#define vld2q_dup_s8_ex(src, align) neon_ld2r_q8((__int8*)src)
#define vld2q_dup_u16_ex(src, align) neon_ld2r_q16((__int16*)src)
#define vld2q_dup_u32_ex(src, align) neon_ld2r_q32((__int32*)src)
#define vld2q_dup_u8_ex(src, align) neon_ld2r_q8((__int8*)src)
#define vld2q_dup_s64_ex(src, align) neon_ld2r_q64((__int64*)src)
#define vld2q_dup_u64_ex(src, align) neon_ld2r_q64((__int64*)src)
#define vld2q_f32_ex(src, align) neon_ld2m_q32((__int32*)src)
#define vld2q_p16_ex(src, align) neon_ld2m_q16((__int16*)src)
#define vld2q_p8_ex(src, align) neon_ld2m_q8((__int8*)src)
#define vld2q_s16_ex(src, align) neon_ld2m_q16((__int16*)src)
#define vld2q_s32_ex(src, align) neon_ld2m_q32((__int32*)src)
#define vld2q_s8_ex(src, align) neon_ld2m_q8((__int8*)src)
#define vld2q_u16_ex(src, align) neon_ld2m_q16((__int16*)src)
#define vld2q_u32_ex(src, align) neon_ld2m_q32((__int32*)src)
#define vld2q_u8_ex(src, align) neon_ld2m_q8((__int8*)src)
#define vld2q_s64_ex(src, align) neon_ld2m_q64((__int64*)src)
#define vld2q_u64_ex(src, align) neon_ld2m_q64((__int64*)src)
#define vld2_lane_f32_ex(src1, src2, src3) neon_ld2s_32((__int32*)src1, src2, src3)
#define vld2_lane_p16_ex(src1, src2, src3) neon_ld2s_16((__int16*)src1, src2, src3)
#define vld2_lane_p8_ex(src1, src2, src3) neon_ld2s_8((__int8*)src1, src2, src3)
#define vld2_lane_s16_ex(src1, src2, src3) neon_ld2s_16((__int16*)src1, src2, src3)
#define vld2_lane_s32_ex(src1, src2, src3) neon_ld2s_32((__int32*)src1, src2, src3)
#define vld2_lane_s64_ex(src1, src2, src3) neon_ld2s_64((__int64*)src1, src2, src3)
#define vld2_lane_s8_ex(src1, src2, src3) neon_ld2s_8((__int8*)src1, src2, src3)
#define vld2_lane_u16_ex(src1, src2, src3) neon_ld2s_16((__int16*)src1, src2, src3)
#define vld2_lane_u32_ex(src1, src2, src3) neon_ld2s_32((__int32*)src1, src2, src3)
#define vld2_lane_u8_ex(src1, src2, src3) neon_ld2s_8((__int8*)src1, src2, src3)
#define vld2q_lane_f32_ex(src1, src2, src3) neon_ld2s_q32((__int32*)src1, src2, src3)
#define vld2q_lane_p8_ex(src1, src2, src3) neon_ld2s_q8((__int8*)src1, src2, src3)
#define vld2q_lane_p16_ex(src1, src2, src3) neon_ld2s_q16((__int16*)src1, src2, src3)
#define vld2q_lane_s16_ex(src1, src2, src3) neon_ld2s_q16((__int16*)src1, src2, src3)
#define vld2q_lane_s32_ex(src1, src2, src3) neon_ld2s_q32((__int32*)src1, src2, src3)
#define vld2q_lane_s64_ex(src1, src2, src3) neon_ld2s_q64((__int64*)src1, src2, src3)
#define vld2q_lane_u16_ex(src1, src2, src3) neon_ld2s_q16((__int16*)src1, src2, src3)
#define vld2q_lane_u32_ex(src1, src2, src3) neon_ld2s_q32((__int32*)src1, src2, src3)
#define vld1_dup_f32_ex(src, align) neon_ld1r_32((__int32*)src)
#define vld1_dup_p16_ex(src, align) neon_ld1r_16((__int16*)src)
#define vld1_dup_p8_ex(src, align) neon_ld1r_8((__int8*)src)
#define vld1_dup_s16_ex(src, align) neon_ld1r_16((__int16*)src)
#define vld1_dup_s32_ex(src, align) neon_ld1r_32((__int32*)src)
#define vld1_dup_s8_ex(src, align) neon_ld1r_8((__int8*)src)
#define vld1_dup_u16_ex(src, align) neon_ld1r_16((__int16*)src)
#define vld1_dup_u32_ex(src, align) neon_ld1r_32((__int32*)src)
#define vld1_dup_u8_ex(src, align) neon_ld1r_8((__int8*)src)
#define vld1_dup_s64_ex(src, align) neon_ld1r_64((__int64*)src)
#define vld1_dup_u64_ex(src, align) neon_ld1r_64((__int64*)src)
#define vld1_f32_ex(src, align) neon_ld1m_32((__int32*)src)
#define vld1_p16_ex(src, align) neon_ld1m_16((__int16*)src)
#define vld1_p8_ex(src, align) neon_ld1m_8((__int8*)src)
#define vld1_s16_ex(src, align) neon_ld1m_16((__int16*)src)
#define vld1_s32_ex(src, align) neon_ld1m_32((__int32*)src)
#define vld1_s8_ex(src, align) neon_ld1m_8((__int8*)src)
#define vld1_u16_ex(src, align) neon_ld1m_16((__int16*)src)
#define vld1_u32_ex(src, align) neon_ld1m_32((__int32*)src)
#define vld1_u8_ex(src, align) neon_ld1m_8((__int8*)src)
#define vld1_s64_ex(src, align) neon_ld1m_64((__int64*)src)
#define vld1_u64_ex(src, align) neon_ld1m_64((__int64*)src)
#define vld1_f64_ex(src, align) neon_ld1m_64((__int64*)src)
#define vld1_f32_x2_ex(src, align) neon_ld1m2_32((__int32*)src)
#define vld1_p16_x2_ex(src, align) neon_ld1m2_16((__int16*)src)
#define vld1_p8_x2_ex(src, align) neon_ld1m2_8((__int8*)src)
#define vld1_s16_x2_ex(src, align) neon_ld1m2_16((__int16*)src)
#define vld1_s32_x2_ex(src, align) neon_ld1m2_32((__int32*)src)
#define vld1_s8_x2_ex(src, align) neon_ld1m2_8((__int8*)src)
#define vld1_u16_x2_ex(src, align) neon_ld1m2_16((__int16*)src)
#define vld1_u32_x2_ex(src, align) neon_ld1m2_32((__int32*)src)
#define vld1_u8_x2_ex(src, align) neon_ld1m2_8((__int8*)src)
#define vld1_s64_x2_ex(src, align) neon_ld1m2_64((__int64*)src)
#define vld1_u64_x2_ex(src, align) neon_ld1m2_64((__int64*)src)
#define vld1_f64_x2_ex(src, align) neon_ld1m2_64((__int64*)src)
#define vld1_f32_x3_ex(src, align) neon_ld1m3_32((__int32*)src)
#define vld1_p16_x3_ex(src, align) neon_ld1m3_16((__int16*)src)
#define vld1_p8_x3_ex(src, align) neon_ld1m3_8((__int8*)src)
#define vld1_s16_x3_ex(src, align) neon_ld1m3_16((__int16*)src)
#define vld1_s32_x3_ex(src, align) neon_ld1m3_32((__int32*)src)
#define vld1_s8_x3_ex(src, align) neon_ld1m3_8((__int8*)src)
#define vld1_u16_x3_ex(src, align) neon_ld1m3_16((__int16*)src)
#define vld1_u32_x3_ex(src, align) neon_ld1m3_32((__int32*)src)
#define vld1_u8_x3_ex(src, align) neon_ld1m3_8((__int8*)src)
#define vld1_s64_x3_ex(src, align) neon_ld1m3_64((__int64*)src)
#define vld1_u64_x3_ex(src, align) neon_ld1m3_64((__int64*)src)
#define vld1_f64_x3_ex(src, align) neon_ld1m3_64((__int64*)src)
#define vld1_f32_x4_ex(src, align) neon_ld1m4_32((__int32*)src)
#define vld1_p16_x4_ex(src, align) neon_ld1m4_16((__int16*)src)
#define vld1_p8_x4_ex(src, align) neon_ld1m4_8((__int8*)src)
#define vld1_s16_x4_ex(src, align) neon_ld1m4_16((__int16*)src)
#define vld1_s32_x4_ex(src, align) neon_ld1m4_32((__int32*)src)
#define vld1_s8_x4_ex(src, align) neon_ld1m4_8((__int8*)src)
#define vld1_u16_x4_ex(src, align) neon_ld1m4_16((__int16*)src)
#define vld1_u32_x4_ex(src, align) neon_ld1m4_32((__int32*)src)
#define vld1_u8_x4_ex(src, align) neon_ld1m4_8((__int8*)src)
#define vld1_s64_x4_ex(src, align) neon_ld1m4_64((__int64*)src)
#define vld1_u64_x4_ex(src, align) neon_ld1m4_64((__int64*)src)
#define vld1_f64_x4_ex(src, align) neon_ld1m4_64((__int64*)src)
#define vld1q_dup_f32_ex(src, align) neon_ld1r_q32((__int32*)src)
#define vld1q_dup_p16_ex(src, align) neon_ld1r_q16((__int16*)src)
#define vld1q_dup_p8_ex(src, align) neon_ld1r_q8((__int8*)src)
#define vld1q_dup_s16_ex(src, align) neon_ld1r_q16((__int16*)src)
#define vld1q_dup_s32_ex(src, align) neon_ld1r_q32((__int32*)src)
#define vld1q_dup_s8_ex(src, align) neon_ld1r_q8((__int8*)src)
#define vld1q_dup_u16_ex(src, align) neon_ld1r_q16((__int16*)src)
#define vld1q_dup_u32_ex(src, align) neon_ld1r_q32((__int32*)src)
#define vld1q_dup_u8_ex(src, align) neon_ld1r_q8((__int8*)src)
#define vld1q_dup_s64_ex(src, align) neon_ld1r_q64((__int64*)src)
#define vld1q_dup_u64_ex(src, align) neon_ld1r_q64((__int64*)src)
#define vld1q_f32_ex(src, align) neon_ld1m_q32((__int32*)src)
#define vld1q_p16_ex(src, align) neon_ld1m_q16((__int16*)src)
#define vld1q_p8_ex(src, align) neon_ld1m_q8((__int8*)src)
#define vld1q_s16_ex(src, align) neon_ld1m_q16((__int16*)src)
#define vld1q_s32_ex(src, align) neon_ld1m_q32((__int32*)src)
#define vld1q_s8_ex(src, align) neon_ld1m_q8((__int8*)src)
#define vld1q_u16_ex(src, align) neon_ld1m_q16((__int16*)src)
#define vld1q_u32_ex(src, align) neon_ld1m_q32((__int32*)src)
#define vld1q_u8_ex(src, align) neon_ld1m_q8((__int8*)src)
#define vld1q_s64_ex(src, align) neon_ld1m_q64((__int64*)src)
#define vld1q_u64_ex(src, align) neon_ld1m_q64((__int64*)src)
#define vld1q_f32_x2_ex(src, align) neon_ld1m2_q32((__int32*)src)
#define vld1q_p16_x2_ex(src, align) neon_ld1m2_q16((__int16*)src)
#define vld1q_p8_x2_ex(src, align) neon_ld1m2_q8((__int8*)src)
#define vld1q_s16_x2_ex(src, align) neon_ld1m2_q16((__int16*)src)
#define vld1q_s32_x2_ex(src, align) neon_ld1m2_q32((__int32*)src)
#define vld1q_s8_x2_ex(src, align) neon_ld1m2_q8((__int8*)src)
#define vld1q_u16_x2_ex(src, align) neon_ld1m2_q16((__int16*)src)
#define vld1q_u32_x2_ex(src, align) neon_ld1m2_q32((__int32*)src)
#define vld1q_u8_x2_ex(src, align) neon_ld1m2_q8((__int8*)src)
#define vld1q_s64_x2_ex(src, align) neon_ld1m2_q64((__int64*)src)
#define vld1q_u64_x2_ex(src, align) neon_ld1m2_q64((__int64*)src)
#define vld1q_f32_x3_ex(src, align) neon_ld1m3_q32((__int32*)src)
#define vld1q_p16_x3_ex(src, align) neon_ld1m3_q16((__int16*)src)
#define vld1q_p8_x3_ex(src, align) neon_ld1m3_q8((__int8*)src)
#define vld1q_s16_x3_ex(src, align) neon_ld1m3_q16((__int16*)src)
#define vld1q_s32_x3_ex(src, align) neon_ld1m3_q32((__int32*)src)
#define vld1q_s8_x3_ex(src, align) neon_ld1m3_q8((__int8*)src)
#define vld1q_u16_x3_ex(src, align) neon_ld1m3_q16((__int16*)src)
#define vld1q_u32_x3_ex(src, align) neon_ld1m3_q32((__int32*)src)
#define vld1q_u8_x3_ex(src, align) neon_ld1m3_q8((__int8*)src)
#define vld1q_s64_x3_ex(src, align) neon_ld1m3_q64((__int64*)src)
#define vld1q_u64_x3_ex(src, align) neon_ld1m3_q64((__int64*)src)
#define vld1q_f32_x4_ex(src, align) neon_ld1m4_q32((__int32*)src)
#define vld1q_p16_x4_ex(src, align) neon_ld1m4_q16((__int16*)src)
#define vld1q_p8_x4_ex(src, align) neon_ld1m4_q8((__int8*)src)
#define vld1q_s16_x4_ex(src, align) neon_ld1m4_q16((__int16*)src)
#define vld1q_s32_x4_ex(src, align) neon_ld1m4_q32((__int32*)src)
#define vld1q_s8_x4_ex(src, align) neon_ld1m4_q8((__int8*)src)
#define vld1q_u16_x4_ex(src, align) neon_ld1m4_q16((__int16*)src)
#define vld1q_u32_x4_ex(src, align) neon_ld1m4_q32((__int32*)src)
#define vld1q_u8_x4_ex(src, align) neon_ld1m4_q8((__int8*)src)
#define vld1q_s64_x4_ex(src, align) neon_ld1m4_q64((__int64*)src)
#define vld1q_u64_x4_ex(src, align) neon_ld1m4_q64((__int64*)src)
#define vld1_lane_f32_ex(src1, src2, src3) neon_ld1s_32((__int32*)src1, src2, src3)
#define vld1_lane_p16_ex(src1, src2, src3) neon_ld1s_16((__int16*)src1, src2, src3)
#define vld1_lane_p8_ex(src1, src2, src3) neon_ld1s_8((__int8*)src1, src2, src3)
#define vld1_lane_s16_ex(src1, src2, src3) neon_ld1s_16((__int16*)src1, src2, src3)
#define vld1_lane_s32_ex(src1, src2, src3) neon_ld1s_32((__int32*)src1, src2, src3)
#define vld1_lane_s64_ex(src1, src2, src3) neon_ld1s_64((__int64*)src1, src2, src3)
#define vld1_lane_s8_ex(src1, src2, src3) neon_ld1s_8((__int8*)src1, src2, src3)
#define vld1_lane_u16_ex(src1, src2, src3) neon_ld1s_16((__int16*)src1, src2, src3)
#define vld1_lane_u32_ex(src1, src2, src3) neon_ld1s_32((__int32*)src1, src2, src3)
#define vld1_lane_u8_ex(src1, src2, src3) neon_ld1s_8((__int8*)src1, src2, src3)
#define vld1q_lane_f32_ex(src1, src2, src3) neon_ld1s_q32((__int32*)src1, src2, src3)
#define vld1q_lane_p8_ex(src1, src2, src3) neon_ld1s_q8((__int8*)src1, src2, src3)
#define vld1q_lane_p16_ex(src1, src2, src3) neon_ld1s_q16((__int16*)src1, src2, src3)
#define vld1q_lane_s16_ex(src1, src2, src3) neon_ld1s_q16((__int16*)src1, src2, src3)
#define vld1q_lane_s32_ex(src1, src2, src3) neon_ld1s_q32((__int32*)src1, src2, src3)
#define vld1q_lane_s64_ex(src1, src2, src3) neon_ld1s_q64((__int64*)src1, src2, src3)
#define vld1q_lane_u16_ex(src1, src2, src3) neon_ld1s_q16((__int16*)src1, src2, src3)
#define vld1q_lane_u32_ex(src1, src2, src3) neon_ld1s_q32((__int32*)src1, src2, src3)

// ST1/ST2/ST3/ST4
void neon_st4m_8(__int8 * ptr, __n64x4 src);
void neon_st4m_q8(__int8 * ptr, __n128x4 src);
void neon_st4m_16(__int16 * ptr, __n64x4 src);
void neon_st4m_q16(__int16 * ptr, __n128x4 src);
void neon_st4m_32(__int32 * ptr, __n64x4 src);
void neon_st4m_q32(__int32 * ptr, __n128x4 src);
void neon_st4m_q64(__int64 * ptr, __n128x4 src);
void neon_st4s_8(__int8 * ptr, __n64x4 src, const int lane);
void neon_st4s_q8(__int8 * ptr, __n128x4 src, const int lane);
void neon_st4s_16(__int16 * ptr, __n64x4 src, const int lane);
void neon_st4s_q16(__int16 * ptr, __n128x4 src, const int lane);
void neon_st4s_32(__int32 * ptr, __n64x4 src, const int lane);
void neon_st4s_q32(__int32 * ptr, __n128x4 src, const int lane);
void neon_st4s_64(__int64 * ptr, __n64x4 src, const int lane);
void neon_st4s_q64(__int64 * ptr, __n128x4 src, const int lane);
void neon_st3m_8(__int8 * ptr, __n64x3 src);
void neon_st3m_q8(__int8 * ptr, __n128x3 src);
void neon_st3m_16(__int16 * ptr, __n64x3 src);
void neon_st3m_q16(__int16 * ptr, __n128x3 src);
void neon_st3m_32(__int32 * ptr, __n64x3 src);
void neon_st3m_q32(__int32 * ptr, __n128x3 src);
void neon_st3m_q64(__int64 * ptr, __n128x3 src);
void neon_st3s_8(__int8 * ptr, __n64x3 src, const int lane);
void neon_st3s_q8(__int8 * ptr, __n128x3 src, const int lane);
void neon_st3s_16(__int16 * ptr, __n64x3 src, const int lane);
void neon_st3s_q16(__int16 * ptr, __n128x3 src, const int lane);
void neon_st3s_32(__int32 * ptr, __n64x3 src, const int lane);
void neon_st3s_q32(__int32 * ptr, __n128x3 src, const int lane);
void neon_st3s_64(__int64 * ptr, __n64x3 src, const int lane);
void neon_st3s_q64(__int64 * ptr, __n128x3 src, const int lane);
void neon_st2m_8(__int8 * ptr, __n64x2 src);
void neon_st2m_q8(__int8 * ptr, __n128x2 src);
void neon_st2m_16(__int16 * ptr, __n64x2 src);
void neon_st2m_q16(__int16 * ptr, __n128x2 src);
void neon_st2m_32(__int32 * ptr, __n64x2 src);
void neon_st2m_q32(__int32 * ptr, __n128x2 src);
void neon_st2m_q64(__int64 * ptr, __n128x2 src);
void neon_st2s_8(__int8 * ptr, __n64x2 src, const int lane);
void neon_st2s_q8(__int8 * ptr, __n128x2 src, const int lane);
void neon_st2s_16(__int16 * ptr, __n64x2 src, const int lane);
void neon_st2s_q16(__int16 * ptr, __n128x2 src, const int lane);
void neon_st2s_32(__int32 * ptr, __n64x2 src, const int lane);
void neon_st2s_q32(__int32 * ptr, __n128x2 src, const int lane);
void neon_st2s_64(__int64 * ptr, __n64x2 src, const int lane);
void neon_st2s_q64(__int64 * ptr, __n128x2 src, const int lane);
void neon_st1m_8(__int8 * ptr, __n64 src);
void neon_st1m_q8(__int8 * ptr, __n128 src);
void neon_st1m_16(__int16 * ptr, __n64 src);
void neon_st1m_q16(__int16 * ptr, __n128 src);
void neon_st1m_32(__int32 * ptr, __n64 src);
void neon_st1m_q32(__int32 * ptr, __n128 src);
void neon_st1m_64(__int64 * ptr, __n64 src);
void neon_st1m_q64(__int64 * ptr, __n128 src);
void neon_st1m2_8(__int8 * ptr, __n64x2 src);
void neon_st1m2_q8(__int8 * ptr, __n128x2 src);
void neon_st1m2_16(__int16 * ptr, __n64x2 src);
void neon_st1m2_q16(__int16 * ptr, __n128x2 src);
void neon_st1m2_32(__int32 * ptr, __n64x2 src);
void neon_st1m2_q32(__int32 * ptr, __n128x2 src);
void neon_st1m2_64(__int64 * ptr, __n64x2 src);
void neon_st1m2_q64(__int64 * ptr, __n128x2 src);
void neon_st1m3_8(__int8 * ptr, __n64x3 src);
void neon_st1m3_q8(__int8 * ptr, __n128x3 src);
void neon_st1m3_16(__int16 * ptr, __n64x3 src);
void neon_st1m3_q16(__int16 * ptr, __n128x3 src);
void neon_st1m3_32(__int32 * ptr, __n64x3 src);
void neon_st1m3_q32(__int32 * ptr, __n128x3 src);
void neon_st1m3_64(__int64 * ptr, __n64x3 src);
void neon_st1m3_q64(__int64 * ptr, __n128x3 src);
void neon_st1m4_8(__int8 * ptr, __n64x4 src);
void neon_st1m4_q8(__int8 * ptr, __n128x4 src);
void neon_st1m4_16(__int16 * ptr, __n64x4 src);
void neon_st1m4_q16(__int16 * ptr, __n128x4 src);
void neon_st1m4_32(__int32 * ptr, __n64x4 src);
void neon_st1m4_q32(__int32 * ptr, __n128x4 src);
void neon_st1m4_64(__int64 * ptr, __n64x4 src);
void neon_st1m4_q64(__int64 * ptr, __n128x4 src);
void neon_st1s_8(__int8 * ptr, __n64 src, const int lane);
void neon_st1s_q8(__int8 * ptr, __n128 src, const int lane);
void neon_st1s_16(__int16 * ptr, __n64 src, const int lane);
void neon_st1s_q16(__int16 * ptr, __n128 src, const int lane);
void neon_st1s_32(__int32 * ptr, __n64 src, const int lane);
void neon_st1s_q32(__int32 * ptr, __n128 src, const int lane);
void neon_st1s_64(__int64 * ptr, __n64 src, const int lane);
void neon_st1s_q64(__int64 * ptr, __n128 src, const int lane);
#define vst4_f32(src1, src2) neon_st4m_32((__int32*)src1, src2)
#define vst4_p16(src1, src2) neon_st4m_16((__int16*)src1, src2)
#define vst4_p8(src1, src2) neon_st4m_8((__int8*)src1, src2)
#define vst4_s16(src1, src2) neon_st4m_16((__int16*)src1, src2)
#define vst4_s32(src1, src2) neon_st4m_32((__int32*)src1, src2)
#define vst4_s8(src1, src2) neon_st4m_8((__int8*)src1, src2)
#define vst4_u16(src1, src2) neon_st4m_16((__int16*)src1, src2)
#define vst4_u32(src1, src2) neon_st4m_32((__int32*)src1, src2)
#define vst4_u8(src1, src2) neon_st4m_8((__int8*)src1, src2)
#define vst4_s64(src1, src2) neon_st1m4_64((__int64*)src1, src2)
#define vst4_u64(src1, src2) neon_st1m4_64((__int64*)src1, src2)
#define vst4q_f32(src1, src2) neon_st4m_q32((__int32*)src1, src2)
#define vst4q_p16(src1, src2) neon_st4m_q16((__int16*)src1, src2)
#define vst4q_p8(src1, src2) neon_st4m_q8((__int8*)src1, src2)
#define vst4q_s16(src1, src2) neon_st4m_q16((__int16*)src1, src2)
#define vst4q_s32(src1, src2) neon_st4m_q32((__int32*)src1, src2)
#define vst4q_s8(src1, src2) neon_st4m_q8((__int8*)src1, src2)
#define vst4q_u16(src1, src2) neon_st4m_q16((__int16*)src1, src2)
#define vst4q_u32(src1, src2) neon_st4m_q32((__int32*)src1, src2)
#define vst4q_u8(src1, src2) neon_st4m_q8((__int8*)src1, src2)
#define vst4q_s64(src1, src2) neon_st4m_q64((__int64*)src1, src2)
#define vst4q_u64(src1, src2) neon_st4m_q64((__int64*)src1, src2)
#define vst4_lane_f32(src1, src2, src3) neon_st4s_32((__int32*)src1, src2, src3)
#define vst4_lane_p16(src1, src2, src3) neon_st4s_16((__int16*)src1, src2, src3)
#define vst4_lane_p8(src1, src2, src3) neon_st4s_8((__int8*)src1, src2, src3)
#define vst4_lane_s16(src1, src2, src3) neon_st4s_16((__int16*)src1, src2, src3)
#define vst4_lane_s32(src1, src2, src3) neon_st4s_32((__int32*)src1, src2, src3)
#define vst4_lane_s64(src1, src2, src3) neon_st4s_64((__int64*)src1, src2, src3)
#define vst4_lane_s8(src1, src2, src3) neon_st4s_8((__int8*)src1, src2, src3)
#define vst4_lane_u16(src1, src2, src3) neon_st4s_16((__int16*)src1, src2, src3)
#define vst4_lane_u32(src1, src2, src3) neon_st4s_32((__int32*)src1, src2, src3)
#define vst4_lane_u8(src1, src2, src3) neon_st4s_8((__int8*)src1, src2, src3)
#define vst4q_lane_f32(src1, src2, src3) neon_st4s_q32((__int32*)src1, src2, src3)
#define vst4q_lane_p8(src1, src2, src3) neon_st4s_q8((__int8*)src1, src2, src3)
#define vst4q_lane_p16(src1, src2, src3) neon_st4s_q16((__int16*)src1, src2, src3)
#define vst4q_lane_s16(src1, src2, src3) neon_st4s_q16((__int16*)src1, src2, src3)
#define vst4q_lane_s32(src1, src2, src3) neon_st4s_q32((__int32*)src1, src2, src3)
#define vst4q_lane_s64(src1, src2, src3) neon_st4s_q64((__int64*)src1, src2, src3)
#define vst4q_lane_u16(src1, src2, src3) neon_st4s_q16((__int16*)src1, src2, src3)
#define vst4q_lane_u32(src1, src2, src3) neon_st4s_q32((__int32*)src1, src2, src3)
#define vst3_f32(src1, src2) neon_st3m_32((__int32*)src1, src2)
#define vst3_p16(src1, src2) neon_st3m_16((__int16*)src1, src2)
#define vst3_p8(src1, src2) neon_st3m_8((__int8*)src1, src2)
#define vst3_s16(src1, src2) neon_st3m_16((__int16*)src1, src2)
#define vst3_s32(src1, src2) neon_st3m_32((__int32*)src1, src2)
#define vst3_s8(src1, src2) neon_st3m_8((__int8*)src1, src2)
#define vst3_u16(src1, src2) neon_st3m_16((__int16*)src1, src2)
#define vst3_u32(src1, src2) neon_st3m_32((__int32*)src1, src2)
#define vst3_u8(src1, src2) neon_st3m_8((__int8*)src1, src2)
#define vst3_s64(src1, src2) neon_st1m3_64((__int64*)src1, src2)
#define vst3_u64(src1, src2) neon_st1m3_64((__int64*)src1, src2)
#define vst3q_f32(src1, src2) neon_st3m_q32((__int32*)src1, src2)
#define vst3q_p16(src1, src2) neon_st3m_q16((__int16*)src1, src2)
#define vst3q_p8(src1, src2) neon_st3m_q8((__int8*)src1, src2)
#define vst3q_s16(src1, src2) neon_st3m_q16((__int16*)src1, src2)
#define vst3q_s32(src1, src2) neon_st3m_q32((__int32*)src1, src2)
#define vst3q_s8(src1, src2) neon_st3m_q8((__int8*)src1, src2)
#define vst3q_u16(src1, src2) neon_st3m_q16((__int16*)src1, src2)
#define vst3q_u32(src1, src2) neon_st3m_q32((__int32*)src1, src2)
#define vst3q_u8(src1, src2) neon_st3m_q8((__int8*)src1, src2)
#define vst3q_s64(src1, src2) neon_st3m_q64((__int64*)src1, src2)
#define vst3q_u64(src1, src2) neon_st3m_q64((__int64*)src1, src2)
#define vst3_lane_f32(src1, src2, src3) neon_st3s_32((__int32*)src1, src2, src3)
#define vst3_lane_p16(src1, src2, src3) neon_st3s_16((__int16*)src1, src2, src3)
#define vst3_lane_p8(src1, src2, src3) neon_st3s_8((__int8*)src1, src2, src3)
#define vst3_lane_s16(src1, src2, src3) neon_st3s_16((__int16*)src1, src2, src3)
#define vst3_lane_s32(src1, src2, src3) neon_st3s_32((__int32*)src1, src2, src3)
#define vst3_lane_s64(src1, src2, src3) neon_st3s_64((__int64*)src1, src2, src3)
#define vst3_lane_s8(src1, src2, src3) neon_st3s_8((__int8*)src1, src2, src3)
#define vst3_lane_u16(src1, src2, src3) neon_st3s_16((__int16*)src1, src2, src3)
#define vst3_lane_u32(src1, src2, src3) neon_st3s_32((__int32*)src1, src2, src3)
#define vst3_lane_u8(src1, src2, src3) neon_st3s_8((__int8*)src1, src2, src3)
#define vst3q_lane_f32(src1, src2, src3) neon_st3s_q32((__int32*)src1, src2, src3)
#define vst3q_lane_p8(src1, src2, src3) neon_st3s_q8((__int8*)src1, src2, src3)
#define vst3q_lane_p16(src1, src2, src3) neon_st3s_q16((__int16*)src1, src2, src3)
#define vst3q_lane_s16(src1, src2, src3) neon_st3s_q16((__int16*)src1, src2, src3)
#define vst3q_lane_s32(src1, src2, src3) neon_st3s_q32((__int32*)src1, src2, src3)
#define vst3q_lane_s64(src1, src2, src3) neon_st3s_q64((__int64*)src1, src2, src3)
#define vst3q_lane_u16(src1, src2, src3) neon_st3s_q16((__int16*)src1, src2, src3)
#define vst3q_lane_u32(src1, src2, src3) neon_st3s_q32((__int32*)src1, src2, src3)
#define vst2_f32(src1, src2) neon_st2m_32((__int32*)src1, src2)
#define vst2_p16(src1, src2) neon_st2m_16((__int16*)src1, src2)
#define vst2_p8(src1, src2) neon_st2m_8((__int8*)src1, src2)
#define vst2_s16(src1, src2) neon_st2m_16((__int16*)src1, src2)
#define vst2_s32(src1, src2) neon_st2m_32((__int32*)src1, src2)
#define vst2_s8(src1, src2) neon_st2m_8((__int8*)src1, src2)
#define vst2_u16(src1, src2) neon_st2m_16((__int16*)src1, src2)
#define vst2_u32(src1, src2) neon_st2m_32((__int32*)src1, src2)
#define vst2_u8(src1, src2) neon_st2m_8((__int8*)src1, src2)
#define vst2_s64(src1, src2) neon_st1m2_64((__int64*)src1, src2)
#define vst2_u64(src1, src2) neon_st1m2_64((__int64*)src1, src2)
#define vst2q_f32(src1, src2) neon_st2m_q32((__int32*)src1, src2)
#define vst2q_p16(src1, src2) neon_st2m_q16((__int16*)src1, src2)
#define vst2q_p8(src1, src2) neon_st2m_q8((__int8*)src1, src2)
#define vst2q_s16(src1, src2) neon_st2m_q16((__int16*)src1, src2)
#define vst2q_s32(src1, src2) neon_st2m_q32((__int32*)src1, src2)
#define vst2q_s8(src1, src2) neon_st2m_q8((__int8*)src1, src2)
#define vst2q_u16(src1, src2) neon_st2m_q16((__int16*)src1, src2)
#define vst2q_u32(src1, src2) neon_st2m_q32((__int32*)src1, src2)
#define vst2q_u8(src1, src2) neon_st2m_q8((__int8*)src1, src2)
#define vst2q_s64(src1, src2) neon_st2m_q64((__int64*)src1, src2)
#define vst2q_u64(src1, src2) neon_st2m_q64((__int64*)src1, src2)
#define vst2_lane_f32(src1, src2, src3) neon_st2s_32((__int32*)src1, src2, src3)
#define vst2_lane_p16(src1, src2, src3) neon_st2s_16((__int16*)src1, src2, src3)
#define vst2_lane_p8(src1, src2, src3) neon_st2s_8((__int8*)src1, src2, src3)
#define vst2_lane_s16(src1, src2, src3) neon_st2s_16((__int16*)src1, src2, src3)
#define vst2_lane_s32(src1, src2, src3) neon_st2s_32((__int32*)src1, src2, src3)
#define vst2_lane_s64(src1, src2, src3) neon_st2s_64((__int64*)src1, src2, src3)
#define vst2_lane_s8(src1, src2, src3) neon_st2s_8((__int8*)src1, src2, src3)
#define vst2_lane_u16(src1, src2, src3) neon_st2s_16((__int16*)src1, src2, src3)
#define vst2_lane_u32(src1, src2, src3) neon_st2s_32((__int32*)src1, src2, src3)
#define vst2_lane_u8(src1, src2, src3) neon_st2s_8((__int8*)src1, src2, src3)
#define vst2q_lane_f32(src1, src2, src3) neon_st2s_q32((__int32*)src1, src2, src3)
#define vst2q_lane_p8(src1, src2, src3) neon_st2s_q8((__int8*)src1, src2, src3)
#define vst2q_lane_p16(src1, src2, src3) neon_st2s_q16((__int16*)src1, src2, src3)
#define vst2q_lane_s16(src1, src2, src3) neon_st2s_q16((__int16*)src1, src2, src3)
#define vst2q_lane_s32(src1, src2, src3) neon_st2s_q32((__int32*)src1, src2, src3)
#define vst2q_lane_s64(src1, src2, src3) neon_st2s_q64((__int64*)src1, src2, src3)
#define vst2q_lane_u16(src1, src2, src3) neon_st2s_q16((__int16*)src1, src2, src3)
#define vst2q_lane_u32(src1, src2, src3) neon_st2s_q32((__int32*)src1, src2, src3)
#define vst1_f32(src1, src2) neon_st1m_32((__int32*)src1, src2)
#define vst1_p16(src1, src2) neon_st1m_16((__int16*)src1, src2)
#define vst1_p8(src1, src2) neon_st1m_8((__int8*)src1, src2)
#define vst1_s16(src1, src2) neon_st1m_16((__int16*)src1, src2)
#define vst1_s32(src1, src2) neon_st1m_32((__int32*)src1, src2)
#define vst1_s8(src1, src2) neon_st1m_8((__int8*)src1, src2)
#define vst1_u16(src1, src2) neon_st1m_16((__int16*)src1, src2)
#define vst1_u32(src1, src2) neon_st1m_32((__int32*)src1, src2)
#define vst1_u8(src1, src2) neon_st1m_8((__int8*)src1, src2)
#define vst1_s64(src1, src2) neon_st1m_64((__int64*)src1, src2)
#define vst1_u64(src1, src2) neon_st1m_64((__int64*)src1, src2)
#define vst1q_f32(src1, src2) neon_st1m_q32((__int32*)src1, src2)
#define vst1q_p16(src1, src2) neon_st1m_q16((__int16*)src1, src2)
#define vst1q_p8(src1, src2) neon_st1m_q8((__int8*)src1, src2)
#define vst1q_s16(src1, src2) neon_st1m_q16((__int16*)src1, src2)
#define vst1q_s32(src1, src2) neon_st1m_q32((__int32*)src1, src2)
#define vst1q_s8(src1, src2) neon_st1m_q8((__int8*)src1, src2)
#define vst1q_u16(src1, src2) neon_st1m_q16((__int16*)src1, src2)
#define vst1q_u32(src1, src2) neon_st1m_q32((__int32*)src1, src2)
#define vst1q_u8(src1, src2) neon_st1m_q8((__int8*)src1, src2)
#define vst1q_s64(src1, src2) neon_st1m_q64((__int64*)src1, src2)
#define vst1q_u64(src1, src2) neon_st1m_q64((__int64*)src1, src2)
#define vst1_f32_x2(src1, src2) neon_st1m2_32((__int32*)src1, src2)
#define vst1_p16_x2(src1, src2) neon_st1m2_16((__int16*)src1, src2)
#define vst1_p8_x2(src1, src2) neon_st1m2_8((__int8*)src1, src2)
#define vst1_s16_x2(src1, src2) neon_st1m2_16((__int16*)src1, src2)
#define vst1_s32_x2(src1, src2) neon_st1m2_32((__int32*)src1, src2)
#define vst1_s8_x2(src1, src2) neon_st1m2_8((__int8*)src1, src2)
#define vst1_u16_x2(src1, src2) neon_st1m2_16((__int16*)src1, src2)
#define vst1_u32_x2(src1, src2) neon_st1m2_32((__int32*)src1, src2)
#define vst1_u8_x2(src1, src2) neon_st1m2_8((__int8*)src1, src2)
#define vst1_s64_x2(src1, src2) neon_st1m2_64((__int64*)src1, src2)
#define vst1_u64_x2(src1, src2) neon_st1m2_64((__int64*)src1, src2)
#define vst1q_f32_x2(src1, src2) neon_st1m2_q32((__int32*)src1, src2)
#define vst1q_p16_x2(src1, src2) neon_st1m2_q16((__int16*)src1, src2)
#define vst1q_p8_x2(src1, src2) neon_st1m2_q8((__int8*)src1, src2)
#define vst1q_s16_x2(src1, src2) neon_st1m2_q16((__int16*)src1, src2)
#define vst1q_s32_x2(src1, src2) neon_st1m2_q32((__int32*)src1, src2)
#define vst1q_s8_x2(src1, src2) neon_st1m2_q8((__int8*)src1, src2)
#define vst1q_u16_x2(src1, src2) neon_st1m2_q16((__int16*)src1, src2)
#define vst1q_u32_x2(src1, src2) neon_st1m2_q32((__int32*)src1, src2)
#define vst1q_u8_x2(src1, src2) neon_st1m2_q8((__int8*)src1, src2)
#define vst1q_s64_x2(src1, src2) neon_st1m2_q64((__int64*)src1, src2)
#define vst1q_u64_x2(src1, src2) neon_st1m2_q64((__int64*)src1, src2)
#define vst1_f32_x3(src1, src2) neon_st1m3_32((__int32*)src1, src2)
#define vst1_p16_x3(src1, src2) neon_st1m3_16((__int16*)src1, src2)
#define vst1_p8_x3(src1, src2) neon_st1m3_8((__int8*)src1, src2)
#define vst1_s16_x3(src1, src2) neon_st1m3_16((__int16*)src1, src2)
#define vst1_s32_x3(src1, src2) neon_st1m3_32((__int32*)src1, src2)
#define vst1_s8_x3(src1, src2) neon_st1m3_8((__int8*)src1, src2)
#define vst1_u16_x3(src1, src2) neon_st1m3_16((__int16*)src1, src2)
#define vst1_u32_x3(src1, src2) neon_st1m3_32((__int32*)src1, src2)
#define vst1_u8_x3(src1, src2) neon_st1m3_8((__int8*)src1, src2)
#define vst1_s64_x3(src1, src2) neon_st1m3_64((__int64*)src1, src2)
#define vst1_u64_x3(src1, src2) neon_st1m3_64((__int64*)src1, src2)
#define vst1q_f32_x3(src1, src2) neon_st1m3_q32((__int32*)src1, src2)
#define vst1q_p16_x3(src1, src2) neon_st1m3_q16((__int16*)src1, src2)
#define vst1q_p8_x3(src1, src2) neon_st1m3_q8((__int8*)src1, src2)
#define vst1q_s16_x3(src1, src2) neon_st1m3_q16((__int16*)src1, src2)
#define vst1q_s32_x3(src1, src2) neon_st1m3_q32((__int32*)src1, src2)
#define vst1q_s8_x3(src1, src2) neon_st1m3_q8((__int8*)src1, src2)
#define vst1q_u16_x3(src1, src2) neon_st1m3_q16((__int16*)src1, src2)
#define vst1q_u32_x3(src1, src2) neon_st1m3_q32((__int32*)src1, src2)
#define vst1q_u8_x3(src1, src2) neon_st1m3_q8((__int8*)src1, src2)
#define vst1q_s64_x3(src1, src2) neon_st1m3_q64((__int64*)src1, src2)
#define vst1q_u64_x3(src1, src2) neon_st1m3_q64((__int64*)src1, src2)
#define vst1_f32_x4(src1, src2) neon_st1m4_32((__int32*)src1, src2)
#define vst1_p16_x4(src1, src2) neon_st1m4_16((__int16*)src1, src2)
#define vst1_p8_x4(src1, src2) neon_st1m4_8((__int8*)src1, src2)
#define vst1_s16_x4(src1, src2) neon_st1m4_16((__int16*)src1, src2)
#define vst1_s32_x4(src1, src2) neon_st1m4_32((__int32*)src1, src2)
#define vst1_s8_x4(src1, src2) neon_st1m4_8((__int8*)src1, src2)
#define vst1_u16_x4(src1, src2) neon_st1m4_16((__int16*)src1, src2)
#define vst1_u32_x4(src1, src2) neon_st1m4_32((__int32*)src1, src2)
#define vst1_u8_x4(src1, src2) neon_st1m4_8((__int8*)src1, src2)
#define vst1_s64_x4(src1, src2) neon_st1m4_64((__int64*)src1, src2)
#define vst1_u64_x4(src1, src2) neon_st1m4_64((__int64*)src1, src2)
#define vst1q_f32_x4(src1, src2) neon_st1m4_q32((__int32*)src1, src2)
#define vst1q_p16_x4(src1, src2) neon_st1m4_q16((__int16*)src1, src2)
#define vst1q_p8_x4(src1, src2) neon_st1m4_q8((__int8*)src1, src2)
#define vst1q_s16_x4(src1, src2) neon_st1m4_q16((__int16*)src1, src2)
#define vst1q_s32_x4(src1, src2) neon_st1m4_q32((__int32*)src1, src2)
#define vst1q_s8_x4(src1, src2) neon_st1m4_q8((__int8*)src1, src2)
#define vst1q_u16_x4(src1, src2) neon_st1m4_q16((__int16*)src1, src2)
#define vst1q_u32_x4(src1, src2) neon_st1m4_q32((__int32*)src1, src2)
#define vst1q_u8_x4(src1, src2) neon_st1m4_q8((__int8*)src1, src2)
#define vst1q_s64_x4(src1, src2) neon_st1m4_q64((__int64*)src1, src2)
#define vst1q_u64_x4(src1, src2) neon_st1m4_q64((__int64*)src1, src2)
#define vst1_lane_f32(src1, src2, src3) neon_st1s_32((__int32*)src1, src2, src3)
#define vst1_lane_p16(src1, src2, src3) neon_st1s_16((__int16*)src1, src2, src3)
#define vst1_lane_p8(src1, src2, src3) neon_st1s_8((__int8*)src1, src2, src3)
#define vst1q_lane_s8(src1, src2, src3) neon_st1s_q8((__int16*)src1, src2, src3)
#define vst1_lane_s16(src1, src2, src3) neon_st1s_16((__int16*)src1, src2, src3)
#define vst1_lane_s32(src1, src2, src3) neon_st1s_32((__int32*)src1, src2, src3)
#define vst1_lane_s64(src1, src2, src3) neon_st1s_64((__int64*)src1, src2, src3)
#define vst1_lane_s8(src1, src2, src3) neon_st1s_8((__int8*)src1, src2, src3)
#define vst1_lane_u16(src1, src2, src3) neon_st1s_16((__int16*)src1, src2, src3)
#define vst1_lane_u32(src1, src2, src3) neon_st1s_32((__int32*)src1, src2, src3)
#define vst1_lane_u8(src1, src2, src3) neon_st1s_8((__int8*)src1, src2, src3)
#define vst1q_lane_f32(src1, src2, src3) neon_st1s_q32((__int32*)src1, src2, src3)
#define vst1q_lane_p8(src1, src2, src3) neon_st1s_q8((__int8*)src1, src2, src3)
#define vst1q_lane_p16(src1, src2, src3) neon_st1s_q16((__int16*)src1, src2, src3)
#define vst1q_lane_s16(src1, src2, src3) neon_st1s_q16((__int16*)src1, src2, src3)
#define vst1q_lane_s32(src1, src2, src3) neon_st1s_q32((__int32*)src1, src2, src3)
#define vst1q_lane_s64(src1, src2, src3) neon_st1s_q64((__int64*)src1, src2, src3)
#define vst1q_lane_u8(src1, src2, src3) neon_st1s_q8((__int8*)src1, src2, src3)
#define vst1q_lane_u16(src1, src2, src3) neon_st1s_q16((__int16*)src1, src2, src3)
#define vst1q_lane_u32(src1, src2, src3) neon_st1s_q32((__int32*)src1, src2, src3)
#define vst4_f32_ex(src1, src2, align) neon_st4m_32((__int32*)src1, src2)
#define vst4_p16_ex(src1, src2, align) neon_st4m_16((__int16*)src1, src2)
#define vst4_p8_ex(src1, src2, align) neon_st4m_8((__int8*)src1, src2)
#define vst4_s16_ex(src1, src2, align) neon_st4m_16((__int16*)src1, src2)
#define vst4_s32_ex(src1, src2, align) neon_st4m_32((__int32*)src1, src2)
#define vst4_s8_ex(src1, src2, align) neon_st4m_8((__int8*)src1, src2)
#define vst4_u16_ex(src1, src2, align) neon_st4m_16((__int16*)src1, src2)
#define vst4_u32_ex(src1, src2, align) neon_st4m_32((__int32*)src1, src2)
#define vst4_u8_ex(src1, src2, align) neon_st4m_8((__int8*)src1, src2)
#define vst4_s64_ex(src1, src2, align) neon_st1m4_64((__int64*)src1, src2)
#define vst4_u64_ex(src1, src2, align) neon_st1m4_64((__int64*)src1, src2)
#define vst4q_f32_ex(src1, src2, align) neon_st4m_q32((__int32*)src1, src2)
#define vst4q_p16_ex(src1, src2, align) neon_st4m_q16((__int16*)src1, src2)
#define vst4q_p8_ex(src1, src2, align) neon_st4m_q8((__int8*)src1, src2)
#define vst4q_s16_ex(src1, src2, align) neon_st4m_q16((__int16*)src1, src2)
#define vst4q_s32_ex(src1, src2, align) neon_st4m_q32((__int32*)src1, src2)
#define vst4q_s8_ex(src1, src2, align) neon_st4m_q8((__int8*)src1, src2)
#define vst4q_u16_ex(src1, src2, align) neon_st4m_q16((__int16*)src1, src2)
#define vst4q_u32_ex(src1, src2, align) neon_st4m_q32((__int32*)src1, src2)
#define vst4q_u8_ex(src1, src2, align) neon_st4m_q8((__int8*)src1, src2)
#define vst4q_s64_ex(src1, src2, align) neon_st4m_q64((__int64*)src1, src2)
#define vst4q_u64_ex(src1, src2, align) neon_st4m_q64((__int64*)src1, src2)
#define vst4_lane_f32_ex(src1, src2, src3, align) neon_st4s_32((__int32*)src1, src2, src3)
#define vst4_lane_p16_ex(src1, src2, src3, align) neon_st4s_16((__int16*)src1, src2, src3)
#define vst4_lane_p8_ex(src1, src2, src3, align) neon_st4s_8((__int8*)src1, src2, src3)
#define vst4_lane_s16_ex(src1, src2, src3, align) neon_st4s_16((__int16*)src1, src2, src3)
#define vst4_lane_s32_ex(src1, src2, src3, align) neon_st4s_32((__int32*)src1, src2, src3)
#define vst4_lane_s64_ex(src1, src2, src3, align) neon_st4s_64((__int64*)src1, src2, src3)
#define vst4_lane_s8_ex(src1, src2, src3, align) neon_st4s_8((__int8*)src1, src2, src3)
#define vst4_lane_u16_ex(src1, src2, src3, align) neon_st4s_16((__int16*)src1, src2, src3)
#define vst4_lane_u32_ex(src1, src2, src3, align) neon_st4s_32((__int32*)src1, src2, src3)
#define vst4_lane_u8_ex(src1, src2, src3, align) neon_st4s_8((__int8*)src1, src2, src3)
#define vst4q_lane_f32_ex(src1, src2, src3, align) neon_st4s_q32((__int32*)src1, src2, src3)
#define vst4q_lane_p8_ex(src1, src2, src3, align) neon_st4s_q8((__int8*)src1, src2, src3)
#define vst4q_lane_p16_ex(src1, src2, src3, align) neon_st4s_q16((__int16*)src1, src2, src3)
#define vst4q_lane_s16_ex(src1, src2, src3, align) neon_st4s_q16((__int16*)src1, src2, src3)
#define vst4q_lane_s32_ex(src1, src2, src3, align) neon_st4s_q32((__int32*)src1, src2, src3)
#define vst4q_lane_s64_ex(src1, src2, src3, align) neon_st4s_q64((__int64*)src1, src2, src3)
#define vst4q_lane_u16_ex(src1, src2, src3, align) neon_st4s_q16((__int16*)src1, src2, src3)
#define vst4q_lane_u32_ex(src1, src2, src3, align) neon_st4s_q32((__int32*)src1, src2, src3)
#define vst3_f32_ex(src1, src2, align) neon_st3m_32((__int32*)src1, src2)
#define vst3_p16_ex(src1, src2, align) neon_st3m_16((__int16*)src1, src2)
#define vst3_p8_ex(src1, src2, align) neon_st3m_8((__int8*)src1, src2)
#define vst3_s16_ex(src1, src2, align) neon_st3m_16((__int16*)src1, src2)
#define vst3_s32_ex(src1, src2, align) neon_st3m_32((__int32*)src1, src2)
#define vst3_s8_ex(src1, src2, align) neon_st3m_8((__int8*)src1, src2)
#define vst3_u16_ex(src1, src2, align) neon_st3m_16((__int16*)src1, src2)
#define vst3_u32_ex(src1, src2, align) neon_st3m_32((__int32*)src1, src2)
#define vst3_u8_ex(src1, src2, align) neon_st3m_8((__int8*)src1, src2)
#define vst3_s64_ex(src1, src2, align) neon_st1m3_64((__int64*)src1, src2)
#define vst3_u64_ex(src1, src2, align) neon_st1m3_64((__int64*)src1, src2)
#define vst3q_f32_ex(src1, src2, align) neon_st3m_q32((__int32*)src1, src2)
#define vst3q_p16_ex(src1, src2, align) neon_st3m_q16((__int16*)src1, src2)
#define vst3q_p8_ex(src1, src2, align) neon_st3m_q8((__int8*)src1, src2)
#define vst3q_s16_ex(src1, src2, align) neon_st3m_q16((__int16*)src1, src2)
#define vst3q_s32_ex(src1, src2, align) neon_st3m_q32((__int32*)src1, src2)
#define vst3q_s8_ex(src1, src2, align) neon_st3m_q8((__int8*)src1, src2)
#define vst3q_u16_ex(src1, src2, align) neon_st3m_q16((__int16*)src1, src2)
#define vst3q_u32_ex(src1, src2, align) neon_st3m_q32((__int32*)src1, src2)
#define vst3q_u8_ex(src1, src2, align) neon_st3m_q8((__int8*)src1, src2)
#define vst3q_s64_ex(src1, src2, align) neon_st3m_q64((__int64*)src1, src2)
#define vst3q_u64_ex(src1, src2, align) neon_st3m_q64((__int64*)src1, src2)
#define vst3_lane_f32_ex(src1, src2, src3, align) neon_st3s_32((__int32*)src1, src2, src3)
#define vst3_lane_p16_ex(src1, src2, src3, align) neon_st3s_16((__int16*)src1, src2, src3)
#define vst3_lane_p8_ex(src1, src2, src3, align) neon_st3s_8((__int8*)src1, src2, src3)
#define vst3_lane_s16_ex(src1, src2, src3, align) neon_st3s_16((__int16*)src1, src2, src3)
#define vst3_lane_s32_ex(src1, src2, src3, align) neon_st3s_32((__int32*)src1, src2, src3)
#define vst3_lane_s64_ex(src1, src2, src3, align) neon_st3s_64((__int64*)src1, src2, src3)
#define vst3_lane_s8_ex(src1, src2, src3, align) neon_st3s_8((__int8*)src1, src2, src3)
#define vst3_lane_u16_ex(src1, src2, src3, align) neon_st3s_16((__int16*)src1, src2, src3)
#define vst3_lane_u32_ex(src1, src2, src3, align) neon_st3s_32((__int32*)src1, src2, src3)
#define vst3_lane_u8_ex(src1, src2, src3, align) neon_st3s_8((__int8*)src1, src2, src3)
#define vst3q_lane_f32_ex(src1, src2, src3, align) neon_st3s_q32((__int32*)src1, src2, src3)
#define vst3q_lane_p8_ex(src1, src2, src3, align) neon_st3s_q8((__int8*)src1, src2, src3)
#define vst3q_lane_p16_ex(src1, src2, src3, align) neon_st3s_q16((__int16*)src1, src2, src3)
#define vst3q_lane_s16_ex(src1, src2, src3, align) neon_st3s_q16((__int16*)src1, src2, src3)
#define vst3q_lane_s32_ex(src1, src2, src3, align) neon_st3s_q32((__int32*)src1, src2, src3)
#define vst3q_lane_s64_ex(src1, src2, src3, align) neon_st3s_q64((__int64*)src1, src2, src3)
#define vst3q_lane_u16_ex(src1, src2, src3, align) neon_st3s_q16((__int16*)src1, src2, src3)
#define vst3q_lane_u32_ex(src1, src2, src3, align) neon_st3s_q32((__int32*)src1, src2, src3)
#define vst2_f32_ex(src1, src2, align) neon_st2m_32((__int32*)src1, src2)
#define vst2_p16_ex(src1, src2, align) neon_st2m_16((__int16*)src1, src2)
#define vst2_p8_ex(src1, src2, align) neon_st2m_8((__int8*)src1, src2)
#define vst2_s16_ex(src1, src2, align) neon_st2m_16((__int16*)src1, src2)
#define vst2_s32_ex(src1, src2, align) neon_st2m_32((__int32*)src1, src2)
#define vst2_s8_ex(src1, src2, align) neon_st2m_8((__int8*)src1, src2)
#define vst2_u16_ex(src1, src2, align) neon_st2m_16((__int16*)src1, src2)
#define vst2_u32_ex(src1, src2, align) neon_st2m_32((__int32*)src1, src2)
#define vst2_u8_ex(src1, src2, align) neon_st2m_8((__int8*)src1, src2)
#define vst2_s64_ex(src1, src2, align) neon_st1m2_64((__int64*)src1, src2)
#define vst2_u64_ex(src1, src2, align) neon_st1m2_64((__int64*)src1, src2)
#define vst2q_f32_ex(src1, src2, align) neon_st2m_q32((__int32*)src1, src2)
#define vst2q_p16_ex(src1, src2, align) neon_st2m_q16((__int16*)src1, src2)
#define vst2q_p8_ex(src1, src2, align) neon_st2m_q8((__int8*)src1, src2)
#define vst2q_s16_ex(src1, src2, align) neon_st2m_q16((__int16*)src1, src2)
#define vst2q_s32_ex(src1, src2, align) neon_st2m_q32((__int32*)src1, src2)
#define vst2q_s8_ex(src1, src2, align) neon_st2m_q8((__int8*)src1, src2)
#define vst2q_u16_ex(src1, src2, align) neon_st2m_q16((__int16*)src1, src2)
#define vst2q_u32_ex(src1, src2, align) neon_st2m_q32((__int32*)src1, src2)
#define vst2q_u8_ex(src1, src2, align) neon_st2m_q8((__int8*)src1, src2)
#define vst2q_s64_ex(src1, src2, align) neon_st2m_q64((__int64*)src1, src2)
#define vst2q_u64_ex(src1, src2, align) neon_st2m_q64((__int64*)src1, src2)
#define vst2_lane_f32_ex(src1, src2, src3, align) neon_st2s_32((__int32*)src1, src2, src3)
#define vst2_lane_p16_ex(src1, src2, src3, align) neon_st2s_16((__int16*)src1, src2, src3)
#define vst2_lane_p8_ex(src1, src2, src3, align) neon_st2s_8((__int8*)src1, src2, src3)
#define vst2_lane_s16_ex(src1, src2, src3, align) neon_st2s_16((__int16*)src1, src2, src3)
#define vst2_lane_s32_ex(src1, src2, src3, align) neon_st2s_32((__int32*)src1, src2, src3)
#define vst2_lane_s64_ex(src1, src2, src3, align) neon_st2s_64((__int64*)src1, src2, src3)
#define vst2_lane_s8_ex(src1, src2, src3, align) neon_st2s_8((__int8*)src1, src2, src3)
#define vst2_lane_u16_ex(src1, src2, src3, align) neon_st2s_16((__int16*)src1, src2, src3)
#define vst2_lane_u32_ex(src1, src2, src3, align) neon_st2s_32((__int32*)src1, src2, src3)
#define vst2_lane_u8_ex(src1, src2, src3, align) neon_st2s_8((__int8*)src1, src2, src3)
#define vst2q_lane_f32_ex(src1, src2, src3, align) neon_st2s_q32((__int32*)src1, src2, src3)
#define vst2q_lane_p8_ex(src1, src2, src3, align) neon_st2s_q8((__int8*)src1, src2, src3)
#define vst2q_lane_p16_ex(src1, src2, src3, align) neon_st2s_q16((__int16*)src1, src2, src3)
#define vst2q_lane_s16_ex(src1, src2, src3, align) neon_st2s_q16((__int16*)src1, src2, src3)
#define vst2q_lane_s32_ex(src1, src2, src3, align) neon_st2s_q32((__int32*)src1, src2, src3)
#define vst2q_lane_s64_ex(src1, src2, src3, align) neon_st2s_q64((__int64*)src1, src2, src3)
#define vst2q_lane_u16_ex(src1, src2, src3, align) neon_st2s_q16((__int16*)src1, src2, src3)
#define vst2q_lane_u32_ex(src1, src2, src3, align) neon_st2s_q32((__int32*)src1, src2, src3)
#define vst1_f32_ex(src1, src2, align) neon_st1m_32((__int32*)src1, src2)
#define vst1_p16_ex(src1, src2, align) neon_st1m_16((__int16*)src1, src2)
#define vst1_p8_ex(src1, src2, align) neon_st1m_8((__int8*)src1, src2)
#define vst1_s16_ex(src1, src2, align) neon_st1m_16((__int16*)src1, src2)
#define vst1_s32_ex(src1, src2, align) neon_st1m_32((__int32*)src1, src2)
#define vst1_s8_ex(src1, src2, align) neon_st1m_8((__int8*)src1, src2)
#define vst1_u16_ex(src1, src2, align) neon_st1m_16((__int16*)src1, src2)
#define vst1_u32_ex(src1, src2, align) neon_st1m_32((__int32*)src1, src2)
#define vst1_u8_ex(src1, src2, align) neon_st1m_8((__int8*)src1, src2)
#define vst1_s64_ex(src1, src2, align) neon_st1m_64((__int64*)src1, src2)
#define vst1_u64_ex(src1, src2, align) neon_st1m_64((__int64*)src1, src2)
#define vst1q_f32_ex(src1, src2, align) neon_st1m_q32((__int32*)src1, src2)
#define vst1q_p16_ex(src1, src2, align) neon_st1m_q16((__int16*)src1, src2)
#define vst1q_p8_ex(src1, src2, align) neon_st1m_q8((__int8*)src1, src2)
#define vst1q_s16_ex(src1, src2, align) neon_st1m_q16((__int16*)src1, src2)
#define vst1q_s32_ex(src1, src2, align) neon_st1m_q32((__int32*)src1, src2)
#define vst1q_s8_ex(src1, src2, align) neon_st1m_q8((__int8*)src1, src2)
#define vst1q_u16_ex(src1, src2, align) neon_st1m_q16((__int16*)src1, src2)
#define vst1q_u32_ex(src1, src2, align) neon_st1m_q32((__int32*)src1, src2)
#define vst1q_u8_ex(src1, src2, align) neon_st1m_q8((__int8*)src1, src2)
#define vst1q_s64_ex(src1, src2, align) neon_st1m_q64((__int64*)src1, src2)
#define vst1q_u64_ex(src1, src2, align) neon_st1m_q64((__int64*)src1, src2)
#define vst1_f32_x2_ex(src1, src2, align) neon_st1m2_32((__int32*)src1, src2)
#define vst1_p16_x2_ex(src1, src2, align) neon_st1m2_16((__int16*)src1, src2)
#define vst1_p8_x2_ex(src1, src2, align) neon_st1m2_8((__int8*)src1, src2)
#define vst1_s16_x2_ex(src1, src2, align) neon_st1m2_16((__int16*)src1, src2)
#define vst1_s32_x2_ex(src1, src2, align) neon_st1m2_32((__int32*)src1, src2)
#define vst1_s8_x2_ex(src1, src2, align) neon_st1m2_8((__int8*)src1, src2)
#define vst1_u16_x2_ex(src1, src2, align) neon_st1m2_16((__int16*)src1, src2)
#define vst1_u32_x2_ex(src1, src2, align) neon_st1m2_32((__int32*)src1, src2)
#define vst1_u8_x2_ex(src1, src2, align) neon_st1m2_8((__int8*)src1, src2)
#define vst1_s64_x2_ex(src1, src2, align) neon_st1m2_64((__int64*)src1, src2)
#define vst1_u64_x2_ex(src1, src2, align) neon_st1m2_64((__int64*)src1, src2)
#define vst1q_f32_x2_ex(src1, src2, align) neon_st1m2_q32((__int32*)src1, src2)
#define vst1q_p16_x2_ex(src1, src2, align) neon_st1m2_q16((__int16*)src1, src2)
#define vst1q_p8_x2_ex(src1, src2, align) neon_st1m2_q8((__int8*)src1, src2)
#define vst1q_s16_x2_ex(src1, src2, align) neon_st1m2_q16((__int16*)src1, src2)
#define vst1q_s32_x2_ex(src1, src2, align) neon_st1m2_q32((__int32*)src1, src2)
#define vst1q_s8_x2_ex(src1, src2, align) neon_st1m2_q8((__int8*)src1, src2)
#define vst1q_u16_x2_ex(src1, src2, align) neon_st1m2_q16((__int16*)src1, src2)
#define vst1q_u32_x2_ex(src1, src2, align) neon_st1m2_q32((__int32*)src1, src2)
#define vst1q_u8_x2_ex(src1, src2, align) neon_st1m2_q8((__int8*)src1, src2)
#define vst1q_s64_x2_ex(src1, src2, align) neon_st1m2_q64((__int64*)src1, src2)
#define vst1q_u64_x2_ex(src1, src2, align) neon_st1m2_q64((__int64*)src1, src2)
#define vst1_f32_x3_ex(src1, src2, align) neon_st1m3_32((__int32*)src1, src2)
#define vst1_p16_x3_ex(src1, src2, align) neon_st1m3_16((__int16*)src1, src2)
#define vst1_p8_x3_ex(src1, src2, align) neon_st1m3_8((__int8*)src1, src2)
#define vst1_s16_x3_ex(src1, src2, align) neon_st1m3_16((__int16*)src1, src2)
#define vst1_s32_x3_ex(src1, src2, align) neon_st1m3_32((__int32*)src1, src2)
#define vst1_s8_x3_ex(src1, src2, align) neon_st1m3_8((__int8*)src1, src2)
#define vst1_u16_x3_ex(src1, src2, align) neon_st1m3_16((__int16*)src1, src2)
#define vst1_u32_x3_ex(src1, src2, align) neon_st1m3_32((__int32*)src1, src2)
#define vst1_u8_x3_ex(src1, src2, align) neon_st1m3_8((__int8*)src1, src2)
#define vst1_s64_x3_ex(src1, src2, align) neon_st1m3_64((__int64*)src1, src2)
#define vst1_u64_x3_ex(src1, src2, align) neon_st1m3_64((__int64*)src1, src2)
#define vst1q_f32_x3_ex(src1, src2, align) neon_st1m3_q32((__int32*)src1, src2)
#define vst1q_p16_x3_ex(src1, src2, align) neon_st1m3_q16((__int16*)src1, src2)
#define vst1q_p8_x3_ex(src1, src2, align) neon_st1m3_q8((__int8*)src1, src2)
#define vst1q_s16_x3_ex(src1, src2, align) neon_st1m3_q16((__int16*)src1, src2)
#define vst1q_s32_x3_ex(src1, src2, align) neon_st1m3_q32((__int32*)src1, src2)
#define vst1q_s8_x3_ex(src1, src2, align) neon_st1m3_q8((__int8*)src1, src2)
#define vst1q_u16_x3_ex(src1, src2, align) neon_st1m3_q16((__int16*)src1, src2)
#define vst1q_u32_x3_ex(src1, src2, align) neon_st1m3_q32((__int32*)src1, src2)
#define vst1q_u8_x3_ex(src1, src2, align) neon_st1m3_q8((__int8*)src1, src2)
#define vst1q_s64_x3_ex(src1, src2, align) neon_st1m3_q64((__int64*)src1, src2)
#define vst1q_u64_x3_ex(src1, src2, align) neon_st1m3_q64((__int64*)src1, src2)
#define vst1_f32_x4_ex(src1, src2, align) neon_st1m4_32((__int32*)src1, src2)
#define vst1_p16_x4_ex(src1, src2, align) neon_st1m4_16((__int16*)src1, src2)
#define vst1_p8_x4_ex(src1, src2, align) neon_st1m4_8((__int8*)src1, src2)
#define vst1_s16_x4_ex(src1, src2, align) neon_st1m4_16((__int16*)src1, src2)
#define vst1_s32_x4_ex(src1, src2, align) neon_st1m4_32((__int32*)src1, src2)
#define vst1_s8_x4_ex(src1, src2, align) neon_st1m4_8((__int8*)src1, src2)
#define vst1_u16_x4_ex(src1, src2, align) neon_st1m4_16((__int16*)src1, src2)
#define vst1_u32_x4_ex(src1, src2, align) neon_st1m4_32((__int32*)src1, src2)
#define vst1_u8_x4_ex(src1, src2, align) neon_st1m4_8((__int8*)src1, src2)
#define vst1_s64_x4_ex(src1, src2, align) neon_st1m4_64((__int64*)src1, src2)
#define vst1_u64_x4_ex(src1, src2, align) neon_st1m4_64((__int64*)src1, src2)
#define vst1q_f32_x4_ex(src1, src2, align) neon_st1m4_q32((__int32*)src1, src2)
#define vst1q_p16_x4_ex(src1, src2, align) neon_st1m4_q16((__int16*)src1, src2)
#define vst1q_p8_x4_ex(src1, src2, align) neon_st1m4_q8((__int8*)src1, src2)
#define vst1q_s16_x4_ex(src1, src2, align) neon_st1m4_q16((__int16*)src1, src2)
#define vst1q_s32_x4_ex(src1, src2, align) neon_st1m4_q32((__int32*)src1, src2)
#define vst1q_s8_x4_ex(src1, src2, align) neon_st1m4_q8((__int8*)src1, src2)
#define vst1q_u16_x4_ex(src1, src2, align) neon_st1m4_q16((__int16*)src1, src2)
#define vst1q_u32_x4_ex(src1, src2, align) neon_st1m4_q32((__int32*)src1, src2)
#define vst1q_u8_x4_ex(src1, src2, align) neon_st1m4_q8((__int8*)src1, src2)
#define vst1q_s64_x4_ex(src1, src2, align) neon_st1m4_q64((__int64*)src1, src2)
#define vst1q_u64_x4_ex(src1, src2, align) neon_st1m4_q64((__int64*)src1, src2)
#define vst1_lane_f32_ex(src1, src2, src3, align) neon_st1s_32((__int32*)src1, src2, src3)
#define vst1_lane_p16_ex(src1, src2, src3, align) neon_st1s_16((__int16*)src1, src2, src3)
#define vst1_lane_p8_ex(src1, src2, src3, align) neon_st1s_8((__int8*)src1, src2, src3)
#define vst1_lane_s16_ex(src1, src2, src3, align) neon_st1s_16((__int16*)src1, src2, src3)
#define vst1_lane_s32_ex(src1, src2, src3, align) neon_st1s_32((__int32*)src1, src2, src3)
#define vst1_lane_s64_ex(src1, src2, src3, align) neon_st1s_64((__int64*)src1, src2, src3)
#define vst1_lane_s8_ex(src1, src2, src3, align) neon_st1s_8((__int8*)src1, src2, src3)
#define vst1_lane_u16_ex(src1, src2, src3, align) neon_st1s_16((__int16*)src1, src2, src3)
#define vst1_lane_u32_ex(src1, src2, src3, align) neon_st1s_32((__int32*)src1, src2, src3)
#define vst1_lane_u8_ex(src1, src2, src3, align) neon_st1s_8((__int8*)src1, src2, src3)
#define vst1q_lane_f32_ex(src1, src2, src3, align) neon_st1s_q32((__int32*)src1, src2, src3)
#define vst1q_lane_p8_ex(src1, src2, src3, align) neon_st1s_q8((__int8*)src1, src2, src3)
#define vst1q_lane_p16_ex(src1, src2, src3, align) neon_st1s_q16((__int16*)src1, src2, src3)
#define vst1q_lane_s8_ex(src1, src2, src3, align) neon_st1s_q8((__int16*)src1, src2, src3)
#define vst1q_lane_s16_ex(src1, src2, src3, align) neon_st1s_q16((__int16*)src1, src2, src3)
#define vst1q_lane_s32_ex(src1, src2, src3, align) neon_st1s_q32((__int32*)src1, src2, src3)
#define vst1q_lane_s64_ex(src1, src2, src3, align) neon_st1s_q64((__int64*)src1, src2, src3)
#define vst1q_lane_u8_ex(src1, src2, src3, align) neon_st1s_q8((__int8*)src1, src2, src3)
#define vst1q_lane_u16_ex(src1, src2, src3, align) neon_st1s_q16((__int16*)src1, src2, src3)
#define vst1q_lane_u32_ex(src1, src2, src3, align) neon_st1s_q32((__int32*)src1, src2, src3)

// FCVTL/FCVTL2/FCVTN/FCVTN2/FCVTXN/FCVTXN2
__n128 neon_fcvtl_32(__n64);
__n128 neon_fcvtl2_32(__n128);
__n128 neon_fcvtl_64(__n64);
__n128 neon_fcvtl2_64(__n128);
__n64  neon_fcvtn_32(__n128);
__n128 neon_fcvtn2_32(__n64, __n128);
__n64  neon_fcvtn_64(__n128);
__n128 neon_fcvtn2_64(__n64, __n128);
__n64  neon_fcvtxn_64(__n128);
__n128 neon_fcvtxn2_64(__n64, __n128);
float  neon_fcvtxns_64(double);
#define vcvt_f32_f16(src) neon_fcvtl_32(src)
#define vcvt_high_f32_f16(src) neon_fcvtl2_32(src)
#define vcvt_f64_f32(src) neon_fcvtl_64(src)
#define vcvt_high_f64_f32(src) neon_fcvtl2_64(src)
#define vcvt_f16_f32(src) neon_fcvtn_32(src)
#define vcvt_high_f16_f32(src1, src2) neon_fcvtn2_32(src1, src2)
#define vcvt_f32_f64(src) neon_fcvtn_64(src)
#define vcvt_high_f32_f64(src1, src2) neon_fcvtn2_64(src1, src2)
#define vcvtx_f32_f64(src) neon_fcvtxn_64(src)
#define vcvtx_high_f32_f64(src1, src2) neon_fcvtxn2_64(src1, src2)
#define vcvtxd_f32_f64(src) neon_fcvtxns_64(src)

// SQXTN/SQXTUN/UQXTN/XTN
__n64 neon_sqxtn_16(__n128);
__n64 neon_sqxtn_32(__n128);
__n64 neon_sqxtn_64(__n128);
__n128 neon_sqxtn2_16(__n64, __n128);
__n128 neon_sqxtn2_32(__n64, __n128);
__n128 neon_sqxtn2_64(__n64, __n128);
__n8  neon_sqxtns_16(__n16);
__n16 neon_sqxtns_32(float);
float neon_sqxtns_64(__n64);
__n64 neon_sqxtun_16(__n128);
__n64 neon_sqxtun_32(__n128);
__n64 neon_sqxtun_64(__n128);
__n128 neon_sqxtun2_16(__n64, __n128);
__n128 neon_sqxtun2_32(__n64, __n128);
__n128 neon_sqxtun2_64(__n64, __n128);
__n8  neon_sqxtuns_16(__n16);
__n16 neon_sqxtuns_32(float);
float neon_sqxtuns_64(__n64);
__n64 neon_uqxtn_16(__n128);
__n64 neon_uqxtn_32(__n128);
__n64 neon_uqxtn_64(__n128);
__n128 neon_uqxtn2_16(__n64, __n128);
__n128 neon_uqxtn2_32(__n64, __n128);
__n128 neon_uqxtn2_64(__n64, __n128);
__n8  neon_uqxtns_16(__n16);
__n16 neon_uqxtns_32(float);
float neon_uqxtns_64(__n64);
__n64 neon_xtn_16(__n128);
__n64 neon_xtn_32(__n128);
__n64 neon_xtn_64(__n128);
__n128 neon_xtn2_16(__n64, __n128);
__n128 neon_xtn2_32(__n64, __n128);
__n128 neon_xtn2_64(__n64, __n128);
#define vqmovn_s16(src) neon_sqxtn_16(src)
#define vqmovn_s32(src) neon_sqxtn_32(src)
#define vqmovn_s64(src) neon_sqxtn_64(src)
#define vqmovn_high_s16(src1, src2) neon_sqxtn2_16(src1, src2)
#define vqmovn_high_s32(src1, src2) neon_sqxtn2_32(src1, src2)
#define vqmovn_high_s64(src1, src2) neon_sqxtn2_64(src1, src2)
#define vqmovnh_s16(src) neon_sqxtns_16(src)
#define vqmovns_s32(src) neon_sqxtns_32(src)
#define vqmovnd_s64(src) neon_sqxtns_64(src)
#define vqmovun_s16(src) neon_sqxtun_16(src)
#define vqmovun_s32(src) neon_sqxtun_32(src)
#define vqmovun_s64(src) neon_sqxtun_64(src)
#define vqmovun_high_s16(src1, src2) neon_sqxtun2_16(src1, src2)
#define vqmovun_high_s32(src1, src2) neon_sqxtun2_32(src1, src2)
#define vqmovun_high_s64(src1, src2) neon_sqxtun2_64(src1, src2)
#define vqmovunh_s16(src) neon_sqxtuns_16(src)
#define vqmovuns_s32(src) neon_sqxtuns_32(src)
#define vqmovund_s64(src) neon_sqxtuns_64(src)
#define vqmovn_u16(src) neon_uqxtn_16(src)
#define vqmovn_u32(src) neon_uqxtn_32(src)
#define vqmovn_u64(src) neon_uqxtn_64(src)
#define vqmovn_high_u16(src1, src2) neon_uqxtn2_16(src1, src2)
#define vqmovn_high_u32(src1, src2) neon_uqxtn2_32(src1, src2)
#define vqmovn_high_u64(src1, src2) neon_uqxtn2_64(src1, src2)
#define vqmovnh_u16(src) neon_uqxtns_16(src)
#define vqmovns_u32(src) neon_uqxtns_32(src)
#define vqmovnd_u64(src) neon_uqxtns_64(src)
#define vmovn_s16(src) neon_xtn_16(src)
#define vmovn_s32(src) neon_xtn_32(src)
#define vmovn_s64(src) neon_xtn_64(src)
#define vmovn_u16(src) neon_xtn_16(src)
#define vmovn_u32(src) neon_xtn_32(src)
#define vmovn_u64(src) neon_xtn_64(src)

// SHLL/SSHLL/USHLL
__n128 neon_sshll_8  (__n64, const int);
__n128 neon_sshll2_8 (__n128, const int);
__n128 neon_sshll_16 (__n64, const int);
__n128 neon_sshll2_16(__n128, const int);
__n128 neon_sshll_32 (__n64, const int);
__n128 neon_sshll2_32(__n128, const int);
__n128 neon_ushll_8  (__n64, const int);
__n128 neon_ushll2_8 (__n128, const int);
__n128 neon_ushll_16 (__n64, const int);
__n128 neon_ushll2_16(__n128, const int);
__n128 neon_ushll_32 (__n64, const int);
__n128 neon_ushll2_32(__n128, const int);
#define vshll_n_s8(src1, src2) neon_sshll_8(src1, src2)
#define vshll_n_s16(src1, src2) neon_sshll_16(src1, src2)
#define vshll_n_s32(src1, src2) neon_sshll_32(src1, src2)
#define vshll_n_u8(src1, src2) neon_ushll_8(src1, src2)
#define vshll_n_u16(src1, src2) neon_ushll_16(src1, src2)
#define vshll_n_u32(src1, src2) neon_ushll2_32(src1, src2)
#define vshll_high_n_s8(src1, src2) neon_sshll2_8(src1, src2)
#define vshll_high_n_s16(src1, src2) neon_sshll2_16(src1, src2)
#define vshll_high_n_s32(src1, src2) neon_sshll2_32(src1, src2)
#define vshll_high_n_u8(src1, src2) neon_ushll2_8(src1, src2)
#define vshll_high_n_u16(src1, src2) neon_ushll2_16(src1, src2)
#define vshll_high_n_u32(src1, src2) neon_ushll2_32(src1, src2)
#define vmovl_s8(src1) neon_sshll_8(src1, 0)
#define vmovl_s16(src1) neon_sshll_16(src1, 0)
#define vmovl_s32(src1) neon_sshll_32(src1, 0)
#define vmovl_u8(src1) neon_ushll_8(src1, 0)
#define vmovl_u16(src1) neon_ushll_16(src1, 0)
#define vmovl_u32(src1) neon_ushll2_32(src1, 0)
#define vmovl_high_s8(src1) neon_sshll2_8(src1, 0)
#define vmovl_high_s16(src1) neon_sshll2_16(src1, 0)
#define vmovl_high_s32(src1) neon_sshll2_32(src1, 0)
#define vmovl_high_u8(src1) neon_ushll2_8(src1, 0)
#define vmovl_high_u16(src1) neon_ushll2_16(src1, 0)
#define vmovl_high_u32(src1) neon_ushll2_32(src1, 0)

// SHRN/RSHRN/SQSHRN/SQRSHRN/UQSHRN/UQRSHRN/SQSHRUN/SQRSHRUN
__n64  neon_shrn_16     (__n128, const int);
__n128 neon_shrn2_16    (__n64, __n128, const int);
__n64  neon_shrn_32     (__n128, const int);
__n128 neon_shrn2_32    (__n64, __n128, const int);
__n64  neon_shrn_64     (__n128, const int);
__n128 neon_shrn2_64    (__n64, __n128, const int);
__n64  neon_rshrn_16    (__n128, const int);
__n128 neon_rshrn2_16   (__n64, __n128, const int);
__n64  neon_rshrn_32    (__n128, const int);
__n128 neon_rshrn2_32   (__n64, __n128, const int);
__n64  neon_rshrn_64    (__n128, const int);
__n128 neon_rshrn2_64   (__n64, __n128, const int);
__n64  neon_sqshrn_16   (__n128, const int);
__n128 neon_sqshrn2_16  (__n64, __n128, const int);
__n64  neon_sqshrn_32   (__n128, const int);
__n128 neon_sqshrn2_32  (__n64, __n128, const int);
__n64  neon_sqshrn_64   (__n128, const int);
__n128 neon_sqshrn2_64  (__n64, __n128, const int);
__n64  neon_sqrshrn_16  (__n128, const int);
__n128 neon_sqrshrn2_16 (__n64, __n128, const int);
__n64  neon_sqrshrn_32  (__n128, const int);
__n128 neon_sqrshrn2_32 (__n64, __n128, const int);
__n64  neon_sqrshrn_64  (__n128, const int);
__n128 neon_sqrshrn2_64 (__n64, __n128, const int);
__n64  neon_uqshrn_16   (__n128, const int);
__n128 neon_uqshrn2_16  (__n64, __n128, const int);
__n64  neon_uqshrn_32   (__n128, const int);
__n128 neon_uqshrn2_32  (__n64, __n128, const int);
__n64  neon_uqshrn_64   (__n128, const int);
__n128 neon_uqshrn2_64  (__n64, __n128, const int);
__n64  neon_uqrshrn_16  (__n128, const int);
__n128 neon_uqrshrn2_16 (__n64, __n128, const int);
__n64  neon_uqrshrn_32  (__n128, const int);
__n128 neon_uqrshrn2_32 (__n64, __n128, const int);
__n64  neon_uqrshrn_64  (__n128, const int);
__n128 neon_uqrshrn2_64 (__n64, __n128, const int);
__n64  neon_sqshrun_16  (__n128, const int);
__n128 neon_sqshrun2_16 (__n64, __n128, const int);
__n64  neon_sqshrun_32  (__n128, const int);
__n128 neon_sqshrun2_32 (__n64, __n128, const int);
__n64  neon_sqshrun_64  (__n128, const int);
__n128 neon_sqshrun2_64 (__n64, __n128, const int);
__n64  neon_sqrshrun_16 (__n128, const int);
__n128 neon_sqrshrun2_16(__n64, __n128, const int);
__n64  neon_sqrshrun_32 (__n128, const int);
__n128 neon_sqrshrun2_32(__n64, __n128, const int);
__n64  neon_sqrshrun_64 (__n128, const int);
__n128 neon_sqrshrun2_64(__n64, __n128, const int);
__n8   neon_sqshrn_s16  (__n16, const int);
__n16  neon_sqshrn_s32  (float, const int);
float  neon_sqshrn_s64  (__n64, const int);
__n8   neon_sqrshrn_s16 (__n16, const int);
__n16  neon_sqrshrn_s32 (float, const int);
float  neon_sqrshrn_s64 (__n64, const int);
__n8   neon_uqshrn_s16  (__n16, const int);
__n16  neon_uqshrn_s32  (float, const int);
float  neon_uqshrn_s64  (__n64, const int);
__n8   neon_uqrshrn_s16 (__n16, const int);
__n16  neon_uqrshrn_s32 (float, const int);
float  neon_uqrshrn_s64 (__n64, const int);
__n8   neon_sqshrun_s16 (__n16, const int);
__n16  neon_sqshrun_s32 (float, const int);
float  neon_sqshrun_s64 (__n64, const int);
__n8   neon_sqrshrun_s16(__n16, const int);
__n16  neon_sqrshrun_s32(float, const int);
float  neon_sqrshrun_s64(__n64, const int);
#define vshrn_n_s16(src1, src2) neon_shrn_16(src1, src2)
#define vshrn_n_s32(src1, src2) neon_shrn_32(src1, src2)
#define vshrn_n_s64(src1, src2) neon_shrn_64(src1, src2)
#define vshrn_n_u16(src1, src2) neon_shrn_16(src1, src2)
#define vshrn_n_u32(src1, src2) neon_shrn_32(src1, src2)
#define vshrn_n_u64(src1, src2) neon_shrn_64(src1, src2)
#define vshrn_high_n_s16(src1, src2, src3) neon_shrn2_16(src1, src2, src3)
#define vshrn_high_n_s32(src1, src2, src3) neon_shrn2_32(src1, src2, src3)
#define vshrn_high_n_s64(src1, src2, src3) neon_shrn2_64(src1, src2, src3)
#define vshrn_high_n_u16(src1, src2, src3) neon_shrn2_16(src1, src2, src3)
#define vshrn_high_n_u32(src1, src2, src3) neon_shrn2_32(src1, src2, src3)
#define vshrn_high_n_u64(src1, src2, src3) neon_shrn2_64(src1, src2, src3)
#define vrshrn_n_s16(src1, src2) neon_rshrn_16(src1, src2)
#define vrshrn_n_s32(src1, src2) neon_rshrn_32(src1, src2)
#define vrshrn_n_s64(src1, src2) neon_rshrn_64(src1, src2)
#define vrshrn_n_u16(src1, src2) neon_rshrn_16(src1, src2)
#define vrshrn_n_u32(src1, src2) neon_rshrn_32(src1, src2)
#define vrshrn_n_u64(src1, src2) neon_rshrn_64(src1, src2)
#define vrshrn_high_n_s16(src1, src2, src3) neon_rshrn2_16(src1, src2, src3)
#define vrshrn_high_n_s32(src1, src2, src3) neon_rshrn2_32(src1, src2, src3)
#define vrshrn_high_n_s64(src1, src2, src3) neon_rshrn2_64(src1, src2, src3)
#define vrshrn_high_n_u16(src1, src2, src3) neon_rshrn2_16(src1, src2, src3)
#define vrshrn_high_n_u32(src1, src2, src3) neon_rshrn2_32(src1, src2, src3)
#define vrshrn_high_n_u64(src1, src2, src3) neon_rshrn2_64(src1, src2, src3)
#define vqshrn_n_s16(src1, src2) neon_sqshrn_16(src1, src2)
#define vqshrn_n_s32(src1, src2) neon_sqshrn_32(src1, src2)
#define vqshrn_n_s64(src1, src2) neon_sqshrn_64(src1, src2)
#define vqshrn_n_u16(src1, src2) neon_uqshrn_16(src1, src2)
#define vqshrn_n_u32(src1, src2) neon_uqshrn_32(src1, src2)
#define vqshrn_n_u64(src1, src2) neon_uqshrn_64(src1, src2)
#define vqshrn_high_n_s16(src1, src2, src3) neon_sqshrn2_16(src1, src2, src3)
#define vqshrn_high_n_s32(src1, src2, src3) neon_sqshrn2_32(src1, src2, src3)
#define vqshrn_high_n_s64(src1, src2, src3) neon_sqshrn2_64(src1, src2, src3)
#define vqshrn_high_n_u16(src1, src2, src3) neon_uqshrn2_16(src1, src2, src3)
#define vqshrn_high_n_u32(src1, src2, src3) neon_uqshrn2_32(src1, src2, src3)
#define vqshrn_high_n_u64(src1, src2, src3) neon_uqshrn2_64(src1, src2, src3)
#define vqrshrn_n_s16(src1, src2) neon_sqrshrn_16(src1, src2)
#define vqrshrn_n_s32(src1, src2) neon_sqrshrn_32(src1, src2)
#define vqrshrn_n_s64(src1, src2) neon_sqrshrn_64(src1, src2)
#define vqrshrn_n_u16(src1, src2) neon_uqrshrn_16(src1, src2)
#define vqrshrn_n_u32(src1, src2) neon_uqrshrn_32(src1, src2)
#define vqrshrn_n_u64(src1, src2) neon_uqrshrn_64(src1, src2)
#define vqrshrn_high_n_s16(src1, src2, src3) neon_sqrshrn2_16(src1, src2, src3)
#define vqrshrn_high_n_s32(src1, src2, src3) neon_sqrshrn2_32(src1, src2, src3)
#define vqrshrn_high_n_s64(src1, src2, src3) neon_sqrshrn2_64(src1, src2, src3)
#define vqrshrn_high_n_u16(src1, src2, src3) neon_uqrshrn2_16(src1, src2, src3)
#define vqrshrn_high_n_u32(src1, src2, src3) neon_uqrshrn2_32(src1, src2, src3)
#define vqrshrn_high_n_u64(src1, src2, src3) neon_uqrshrn2_64(src1, src2, src3)
#define vqshrun_n_s16(src1, src2) neon_sqshrun_16(src1, src2)
#define vqshrun_n_s32(src1, src2) neon_sqshrun_32(src1, src2)
#define vqshrun_n_s64(src1, src2) neon_sqshrun_64(src1, src2)
#define vqshrun_high_n_s16(src1, src2, src3) neon_sqshrun2_16(src1, src2, src3)
#define vqshrun_high_n_s32(src1, src2, src3) neon_sqshrun2_32(src1, src2, src3)
#define vqshrun_high_n_s64(src1, src2, src3) neon_sqshrun2_64(src1, src2, src3)
#define vqrshrun_n_s16(src1, src2) neon_sqrshrun_16(src1, src2)
#define vqrshrun_n_s32(src1, src2) neon_sqrshrun_32(src1, src2)
#define vqrshrun_n_s64(src1, src2) neon_sqrshrun_64(src1, src2)
#define vqrshrun_high_n_s16(src1, src2, src3) neon_sqrshrun2_16(src1, src2, src3)
#define vqrshrun_high_n_s32(src1, src2, src3) neon_sqrshrun2_32(src1, src2, src3)
#define vqrshrun_high_n_s64(src1, src2, src3) neon_sqrshrun2_64(src1, src2, src3)
#define vqshrnh_n_s16(src1, src2) neon_sqshrn_s16(src1, src2)
#define vqshrnh_n_s32(src1, src2) neon_sqshrn_s32(src1, src2)
#define vqshrnh_n_s64(src1, src2) neon_sqshrn_s64(src1, src2)
#define vqrshrnh_n_s16(src1, src2) neon_sqrshrn_s16(src1, src2)
#define vqrshrnh_n_s32(src1, src2) neon_sqrshrn_s32(src1, src2)
#define vqrshrnh_n_s64(src1, src2) neon_sqrshrn_s64(src1, src2)
#define vqshrunh_n_s16(src1, src2) neon_sqshrun_s16(src1, src2)
#define vqshrunh_n_s32(src1, src2) neon_sqshrun_s32(src1, src2)
#define vqshrunh_n_s64(src1, src2) neon_sqshrun_s64(src1, src2)
#define vqrshrunh_n_s16(src1, src2) neon_sqrshrun_s16(src1, src2)
#define vqrshrunh_n_s32(src1, src2) neon_sqrshrun_s32(src1, src2)
#define vqrshrunh_n_s64(src1, src2) neon_sqrshrun_s64(src1, src2)

// ADDHN/RADDHN/SADDW/UADDW/SADDL/UADDL
__n64  neon_addhn_16   (__n128, __n128);
__n128 neon_addhn2_16  (__n64, __n128, __n128);
__n64  neon_addhn_32   (__n128, __n128);
__n128 neon_addhn2_32  (__n64, __n128, __n128);
__n64  neon_addhn_64   (__n128, __n128);
__n128 neon_addhn2_64  (__n64, __n128, __n128);
__n64  neon_raddhn_16  (__n128, __n128);
__n128 neon_raddhn2_16 (__n64, __n128, __n128);
__n64  neon_raddhn_32  (__n128, __n128);
__n128 neon_raddhn2_32 (__n64, __n128, __n128);
__n64  neon_raddhn_64  (__n128, __n128);
__n128 neon_raddhn2_64 (__n64, __n128, __n128);
__n128 neon_saddw_8    (__n128, __n64);
__n128 neon_saddw2_8   (__n128, __n128);
__n128 neon_saddw_16   (__n128, __n64);
__n128 neon_saddw2_16  (__n128, __n128);
__n128 neon_saddw_32   (__n128, __n64);
__n128 neon_saddw2_32  (__n128, __n128);
__n128 neon_uaddw_8    (__n128, __n64);
__n128 neon_uaddw2_8   (__n128, __n128);
__n128 neon_uaddw_16   (__n128, __n64);
__n128 neon_uaddw2_16  (__n128, __n128);
__n128 neon_uaddw_32   (__n128, __n64);
__n128 neon_uaddw2_32  (__n128, __n128);
__n128 neon_saddl_8    (__n64, __n64);
__n128 neon_saddl2_8   (__n128, __n128);
__n128 neon_saddl_16   (__n64, __n64);
__n128 neon_saddl2_16  (__n128, __n128);
__n128 neon_saddl_32   (__n64, __n64);
__n128 neon_saddl2_32  (__n128, __n128);
__n128 neon_uaddl_8    (__n64, __n64);
__n128 neon_uaddl2_8   (__n128, __n128);
__n128 neon_uaddl_16   (__n64, __n64);
__n128 neon_uaddl2_16  (__n128, __n128);
__n128 neon_uaddl_32   (__n64, __n64);
__n128 neon_uaddl2_32  (__n128, __n128);
#define vaddhn_s16(src1, src2) neon_addhn_16(src1, src2)
#define vaddhn_s32(src1, src2) neon_addhn_32(src1, src2)
#define vaddhn_s64(src1, src2) neon_addhn_64(src1, src2)
#define vaddhn_u16(src1, src2) neon_addhn_16(src1, src2)
#define vaddhn_u32(src1, src2) neon_addhn_32(src1, src2)
#define vaddhn_u64(src1, src2) neon_addhn_64(src1, src2)
#define vaddhn_high_s16(src1, src2, src3) neon_addhn2_16(src1, src2, src3)
#define vaddhn_high_s32(src1, src2, src3) neon_addhn2_32(src1, src2, src3)
#define vaddhn_high_s64(src1, src2, src3) neon_addhn2_64(src1, src2, src3)
#define vaddhn_high_u16(src1, src2, src3) neon_addhn2_16(src1, src2, src3)
#define vaddhn_high_u32(src1, src2, src3) neon_addhn2_32(src1, src2, src3)
#define vaddhn_high_u64(src1, src2, src3) neon_addhn2_64(src1, src2, src3)
#define vraddhn_s16(src1, src2) neon_raddhn_16(src1, src2)
#define vraddhn_s32(src1, src2) neon_raddhn_32(src1, src2)
#define vraddhn_s64(src1, src2) neon_raddhn_64(src1, src2)
#define vraddhn_u16(src1, src2) neon_raddhn_16(src1, src2)
#define vraddhn_u32(src1, src2) neon_raddhn_32(src1, src2)
#define vraddhn_u64(src1, src2) neon_raddhn_64(src1, src2)
#define vraddhn_high_s16(src1, src2, src3) neon_raddhn2_16(src1, src2, src3)
#define vraddhn_high_s32(src1, src2, src3) neon_raddhn2_32(src1, src2, src3)
#define vraddhn_high_s64(src1, src2, src3) neon_raddhn2_64(src1, src2, src3)
#define vraddhn_high_u16(src1, src2, src3) neon_raddhn2_16(src1, src2, src3)
#define vraddhn_high_u32(src1, src2, src3) neon_raddhn2_32(src1, src2, src3)
#define vraddhn_high_u64(src1, src2, src3) neon_raddhn2_64(src1, src2, src3)
#define vaddw_s8(src1, src2) neon_saddw_8(src1, src2)
#define vaddw_s16(src1, src2) neon_saddw_16(src1, src2)
#define vaddw_s32(src1, src2) neon_saddw_32(src1, src2)
#define vaddw_u8(src1, src2) neon_uaddw_8(src1, src2)
#define vaddw_u16(src1, src2) neon_uaddw_16(src1, src2)
#define vaddw_u32(src1, src2) neon_uaddw_32(src1, src2)
#define vaddl_s8(src1, src2) neon_saddl_8(src1, src2)
#define vaddl_s16(src1, src2) neon_saddl_16(src1, src2)
#define vaddl_s32(src1, src2) neon_saddl_32(src1, src2)
#define vaddl_u8(src1, src2) neon_uaddl_8(src1, src2)
#define vaddl_u16(src1, src2) neon_uaddl_16(src1, src2)
#define vaddl_u32(src1, src2) neon_uaddl_32(src1, src2)
#define vaddw_high_s8(src1, src2) neon_saddw2_8(src1, src2)
#define vaddw_high_s16(src1, src2) neon_saddw2_16(src1, src2)
#define vaddw_high_s32(src1, src2) neon_saddw2_32(src1, src2)
#define vaddw_high_u8(src1, src2) neon_uaddw2_8(src1, src2)
#define vaddw_high_u16(src1, src2) neon_uaddw2_16(src1, src2)
#define vaddw_high_u32(src1, src2) neon_uaddw2_32(src1, src2)
#define vaddl_high_s8(src1, src2) neon_saddl2_8(src1, src2)
#define vaddl_high_s16(src1, src2) neon_saddl2_16(src1, src2)
#define vaddl_high_s32(src1, src2) neon_saddl2_32(src1, src2)
#define vaddl_high_u8(src1, src2) neon_uaddl2_8(src1, src2)
#define vaddl_high_u16(src1, src2) neon_uaddl2_16(src1, src2)
#define vaddl_high_u32(src1, src2) neon_uaddl2_32(src1, src2)

// SUBHN/RSUBHN/SSUBW/USUBW/SSUBL/USUBL
__n64  neon_subhn_16(__n128, __n128);
__n128 neon_subhn2_16(__n64, __n128, __n128);
__n64  neon_subhn_32(__n128, __n128);
__n128 neon_subhn2_32(__n64, __n128, __n128);
__n64  neon_subhn_64(__n128, __n128);
__n128 neon_subhn2_64(__n64, __n128, __n128);
__n64  neon_rsubhn_16(__n128, __n128);
__n128 neon_rsubhn2_16(__n64, __n128, __n128);
__n64  neon_rsubhn_32(__n128, __n128);
__n128 neon_rsubhn2_32(__n64, __n128, __n128);
__n64  neon_rsubhn_64(__n128, __n128);
__n128 neon_rsubhn2_64(__n64, __n128, __n128);
__n128 neon_ssubw_8(__n128, __n64);
__n128 neon_ssubw2_8(__n128, __n128);
__n128 neon_ssubw_16(__n128, __n64);
__n128 neon_ssubw2_16(__n128, __n128);
__n128 neon_ssubw_32(__n128, __n64);
__n128 neon_ssubw2_32(__n128, __n128);
__n128 neon_usubw_8(__n128, __n64);
__n128 neon_usubw2_8(__n128, __n128);
__n128 neon_usubw_16(__n128, __n64);
__n128 neon_usubw2_16(__n128, __n128);
__n128 neon_usubw_32(__n128, __n64);
__n128 neon_usubw2_32(__n128, __n128);
__n128 neon_ssubl_8(__n64, __n64);
__n128 neon_ssubl2_8(__n128, __n128);
__n128 neon_ssubl_16(__n64, __n64);
__n128 neon_ssubl2_16(__n128, __n128);
__n128 neon_ssubl_32(__n64, __n64);
__n128 neon_ssubl2_32(__n128, __n128);
__n128 neon_usubl_8(__n64, __n64);
__n128 neon_usubl2_8(__n128, __n128);
__n128 neon_usubl_16(__n64, __n64);
__n128 neon_usubl2_16(__n128, __n128);
__n128 neon_usubl_32(__n64, __n64);
__n128 neon_usubl2_32(__n128, __n128);
#define vsubhn_s16(src1, src2) neon_subhn_16(src1, src2)
#define vsubhn_s32(src1, src2) neon_subhn_32(src1, src2)
#define vsubhn_s64(src1, src2) neon_subhn_64(src1, src2)
#define vsubhn_u16(src1, src2) neon_subhn_16(src1, src2)
#define vsubhn_u32(src1, src2) neon_subhn_32(src1, src2)
#define vsubhn_u64(src1, src2) neon_subhn_64(src1, src2)
#define vsubhn_high_s16(src1, src2, src3) neon_subhn2_16(src1, src2, src3)
#define vsubhn_high_s32(src1, src2, src3) neon_subhn2_32(src1, src2, src3)
#define vsubhn_high_s64(src1, src2, src3) neon_subhn2_64(src1, src2, src3)
#define vsubhn_high_u16(src1, src2, src3) neon_subhn2_16(src1, src2, src3)
#define vsubhn_high_u32(src1, src2, src3) neon_subhn2_32(src1, src2, src3)
#define vsubhn_high_u64(src1, src2, src3) neon_subhn2_64(src1, src2, src3)
#define vrsubhn_s16(src1, src2) neon_rsubhn_16(src1, src2)
#define vrsubhn_s32(src1, src2) neon_rsubhn_32(src1, src2)
#define vrsubhn_s64(src1, src2) neon_rsubhn_64(src1, src2)
#define vrsubhn_u16(src1, src2) neon_rsubhn_16(src1, src2)
#define vrsubhn_u32(src1, src2) neon_rsubhn_32(src1, src2)
#define vrsubhn_u64(src1, src2) neon_rsubhn_64(src1, src2)
#define vrsubhn_high_s16(src1, src2, src3) neon_rsubhn2_16(src1, src2, src3)
#define vrsubhn_high_s32(src1, src2, src3) neon_rsubhn2_32(src1, src2, src3)
#define vrsubhn_high_s64(src1, src2, src3) neon_rsubhn2_64(src1, src2, src3)
#define vrsubhn_high_u16(src1, src2, src3) neon_rsubhn2_16(src1, src2, src3)
#define vrsubhn_high_u32(src1, src2, src3) neon_rsubhn2_32(src1, src2, src3)
#define vrsubhn_high_u64(src1, src2, src3) neon_rsubhn2_64(src1, src2, src3)
#define vsubw_s8(src1, src2) neon_ssubw_8(src1, src2)
#define vsubw_s16(src1, src2) neon_ssubw_16(src1, src2)
#define vsubw_s32(src1, src2) neon_ssubw_32(src1, src2)
#define vsubw_u8(src1, src2) neon_usubw_8(src1, src2)
#define vsubw_u16(src1, src2) neon_usubw_16(src1, src2)
#define vsubw_u32(src1, src2) neon_usubw_32(src1, src2)
#define vsubl_s8(src1, src2) neon_ssubl_8(src1, src2)
#define vsubl_s16(src1, src2) neon_ssubl_16(src1, src2)
#define vsubl_s32(src1, src2) neon_ssubl_32(src1, src2)
#define vsubl_u8(src1, src2) neon_usubl_8(src1, src2)
#define vsubl_u16(src1, src2) neon_usubl_16(src1, src2)
#define vsubl_u32(src1, src2) neon_usubl_32(src1, src2)
#define vsubw_high_s8(src1, src2) neon_ssubw2_8(src1, src2)
#define vsubw_high_s16(src1, src2) neon_ssubw2_16(src1, src2)
#define vsubw_high_s32(src1, src2) neon_ssubw2_32(src1, src2)
#define vsubw_high_u8(src1, src2) neon_usubw2_8(src1, src2)
#define vsubw_high_u16(src1, src2) neon_usubw2_16(src1, src2)
#define vsubw_high_u32(src1, src2) neon_usubw2_32(src1, src2)
#define vsubl_high_s8(src1, src2) neon_ssubl2_8(src1, src2)
#define vsubl_high_s16(src1, src2) neon_ssubl2_16(src1, src2)
#define vsubl_high_s32(src1, src2) neon_ssubl2_32(src1, src2)
#define vsubl_high_u8(src1, src2) neon_usubl2_8(src1, src2)
#define vsubl_high_u16(src1, src2) neon_usubl2_16(src1, src2)
#define vsubl_high_u32(src1, src2) neon_usubl2_32(src1, src2)

// SABAL/UABAL/SABDL/UABDL
__n128 neon_sabal_8  (__n128, __n64, __n64);
__n128 neon_sabal2_8 (__n128, __n128, __n128);
__n128 neon_sabal_16 (__n128, __n64, __n64);
__n128 neon_sabal2_16(__n128, __n128, __n128);
__n128 neon_sabal_32 (__n128, __n64, __n64);
__n128 neon_sabal2_32(__n128, __n128, __n128);
__n128 neon_uabal_8  (__n128, __n64, __n64);
__n128 neon_uabal2_8 (__n128, __n128, __n128);
__n128 neon_uabal_16 (__n128, __n64, __n64);
__n128 neon_uabal2_16(__n128, __n128, __n128);
__n128 neon_uabal_32 (__n128, __n64, __n64);
__n128 neon_uabal2_32(__n128, __n128, __n128);
__n128 neon_sabdl_8  (__n64, __n64);
__n128 neon_sabdl2_8 (__n128, __n128);
__n128 neon_sabdl_16 (__n64, __n64);
__n128 neon_sabdl2_16(__n128, __n128);
__n128 neon_sabdl_32 (__n64, __n64);
__n128 neon_sabdl2_32(__n128, __n128);
__n128 neon_uabdl_8  (__n64, __n64);
__n128 neon_uabdl2_8 (__n128, __n128);
__n128 neon_uabdl_16 (__n64, __n64);
__n128 neon_uabdl2_16(__n128, __n128);
__n128 neon_uabdl_32 (__n64, __n64);
__n128 neon_uabdl2_32(__n128, __n128);
#define vabal_s8(src1, src2, src3) neon_sabal_8(src1, src2, src3)
#define vabal_s16(src1, src2, src3) neon_sabal_16(src1, src2, src3)
#define vabal_s32(src1, src2, src3) neon_sabal_32(src1, src2, src3)
#define vabal_u8(src1, src2, src3) neon_uabal_8(src1, src2, src3)
#define vabal_u16(src1, src2, src3) neon_uabal_16(src1, src2, src3)
#define vabal_u32(src1, src2, src3) neon_uabal_32(src1, src2, src3)
#define vabal_high_s8(src1, src2, src3) neon_sabal2_8(src1, src2, src3)
#define vabal_high_s16(src1, src2, src3) neon_sabal2_16(src1, src2, src3)
#define vabal_high_s32(src1, src2, src3) neon_sabal2_32(src1, src2, src3)
#define vabal_high_u8(src1, src2, src3) neon_uabal2_8(src1, src2, src3)
#define vabal_high_u16(src1, src2, src3) neon_uabal2_16(src1, src2, src3)
#define vabal_high_u32(src1, src2, src3) neon_uabal2_32(src1, src2, src3)
#define vabdl_s8(src1, src2) neon_sabdl_8(src1, src2)
#define vabdl_s16(src1, src2) neon_sabdl_16(src1, src2)
#define vabdl_s32(src1, src2) neon_sabdl_32(src1, src2)
#define vabdl_u8(src1, src2) neon_uabdl_8(src1, src2)
#define vabdl_u16(src1, src2) neon_uabdl_16(src1, src2)
#define vabdl_u32(src1, src2) neon_uabdl_32(src1, src2)
#define vabdl_high_s8(src1, src2) neon_sabdl2_8(src1, src2)
#define vabdl_high_s16(src1, src2) neon_sabdl2_16(src1, src2)
#define vabdl_high_s32(src1, src2) neon_sabdl2_32(src1, src2)
#define vabdl_high_u8(src1, src2) neon_uabdl2_8(src1, src2)
#define vabdl_high_u16(src1, src2) neon_uabdl2_16(src1, src2)
#define vabdl_high_u32(src1, src2) neon_uabdl2_32(src1, src2)

// vget_low/vget_high/vcombine
#define vget_high_u8(src) neon_dups64q(src, 1)
#define vget_high_s8(src) neon_dups64q(src, 1)
#define vget_low_u8(src) neon_dups64q(src, 0)
#define vget_low_s8(src) neon_dups64q(src, 0)
#define vget_high_u16(src) neon_dups64q(src, 1)
#define vget_high_s16(src) neon_dups64q(src, 1)
#define vget_low_u16(src) neon_dups64q(src, 0)
#define vget_low_s16(src) neon_dups64q(src, 0)
#define vget_high_u32(src) neon_dups64q(src, 1)
#define vget_high_s32(src) neon_dups64q(src, 1)
#define vget_low_u32(src) neon_dups64q(src, 0)
#define vget_low_s32(src) neon_dups64q(src, 0)
#define vget_high_u64(src) neon_dups64q(src, 1)
#define vget_high_s64(src) neon_dups64q(src, 1)
#define vget_low_u64(src) neon_dups64q(src, 0)
#define vget_low_s64(src) neon_dups64q(src, 0)
#define vget_high_p8(src) neon_dups64q(src, 1)
#define vget_high_p16(src) neon_dups64q(src, 1)
#define vget_high_p64(src) neon_dups64q(src, 1)
#define vget_low_p8(src) neon_dups64q(src, 0)
#define vget_low_p16(src) neon_dups64q(src, 0)
#define vget_low_p64(src) neon_dups64q(src, 0)
#define vget_high_f32(src) neon_dups64q(src, 1)
#define vget_high_f16(src) neon_dups64q(src, 1)
#define vget_high_f64(src) neon_dups64q(src, 1)
#define vget_low_f32(src) neon_dups64q(src, 0)
#define vget_low_f16(src) neon_dups64q(src, 0)
#define vget_low_f64(src) neon_dups64q(src, 0)
#define vcombine_u8(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_s8(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_p8(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_u16(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_s16(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_p16(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_f16(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_u32(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_s32(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_f32(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_u64(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_s64(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_p64(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))
#define vcombine_f64(low, high) neon_insqr64(neon_dupqr64(vget_lane_u64(low, 0)), 1, vget_lane_u64(high, 0))

// VCREATE
__n64 vcreate(__int64 src);
#define vcreate_s8(src) vcreate(src)
#define vcreate_s16(src) vcreate(src)
#define vcreate_s32(src) vcreate(src)
#define vcreate_s64(src) vcreate(src)
#define vcreate_u8(src) vcreate(src)
#define vcreate_u16(src) vcreate(src)
#define vcreate_u32(src) vcreate(src)
#define vcreate_u64(src) vcreate(src)
#define vcreate_p64(src) vcreate(src)
#define vcreate_p16(src) vcreate(src)
#define vcreate_p8(src) vcreate(src)
#define vcreate_f16(src) vcreate(src)
#define vcreate_f32(src) vcreate(src)
#define vcreate_f64(src) vcreate(src)


#define vreinterpret_f32_s8(a)         (a)
#define vreinterpret_f32_s16(a)        (a)
#define vreinterpret_f32_s32(a)        (a)
#define vreinterpret_f32_s64(a)        (a)
#define vreinterpret_f32_p8(a)         (a)
#define vreinterpret_f32_p16(a)        (a)
#define vreinterpret_f32_u8(a)         (a)
#define vreinterpret_f32_u16(a)        (a)
#define vreinterpret_f32_u32(a)        (a)
#define vreinterpret_f32_u64(a)        (a)
#define vreinterpret_s8_f32(a)         (a)
#define vreinterpret_s8_s16(a)         (a)
#define vreinterpret_s8_s32(a)         (a)
#define vreinterpret_s8_s64(a)         (a)
#define vreinterpret_s8_p8(a)          (a)
#define vreinterpret_s8_p16(a)         (a)
#define vreinterpret_s8_u8(a)          (a)
#define vreinterpret_s8_u16(a)         (a)
#define vreinterpret_s8_u32(a)         (a)
#define vreinterpret_s8_u64(a)         (a)
#define vreinterpret_s16_f32(a)        (a)
#define vreinterpret_s16_s8(a)         (a)
#define vreinterpret_s16_s32(a)        (a)
#define vreinterpret_s16_s64(a)        (a)
#define vreinterpret_s16_p8(a)         (a)
#define vreinterpret_s16_p16(a)        (a)
#define vreinterpret_s16_u8(a)         (a)
#define vreinterpret_s16_u16(a)        (a)
#define vreinterpret_s16_u32(a)        (a)
#define vreinterpret_s16_u64(a)        (a)
#define vreinterpret_s32_f32(a)        (a)
#define vreinterpret_s32_s8(a)         (a)
#define vreinterpret_s32_s16(a)        (a)
#define vreinterpret_s32_s64(a)        (a)
#define vreinterpret_s32_p8(a)         (a)
#define vreinterpret_s32_p16(a)        (a)
#define vreinterpret_s32_u8(a)         (a)
#define vreinterpret_s32_u16(a)        (a)
#define vreinterpret_s32_u32(a)        (a)
#define vreinterpret_s32_u64(a)        (a)
#define vreinterpret_s64_f32(a)        (a)
#define vreinterpret_s64_s8(a)         (a)
#define vreinterpret_s64_s16(a)        (a)
#define vreinterpret_s64_s32(a)        (a)
#define vreinterpret_s64_p8(a)         (a)
#define vreinterpret_s64_p16(a)        (a)
#define vreinterpret_s64_u8(a)         (a)
#define vreinterpret_s64_u16(a)        (a)
#define vreinterpret_s64_u32(a)        (a)
#define vreinterpret_s64_u64(a)        (a)
#define vreinterpret_p8_f32(a)         (a)
#define vreinterpret_p8_s8(a)          (a)
#define vreinterpret_p8_s16(a)         (a)
#define vreinterpret_p8_s32(a)         (a)
#define vreinterpret_p8_s64(a)         (a)
#define vreinterpret_p8_p16(a)         (a)
#define vreinterpret_p8_u8(a)          (a)
#define vreinterpret_p8_u16(a)         (a)
#define vreinterpret_p8_u32(a)         (a)
#define vreinterpret_p8_u64(a)         (a)
#define vreinterpret_p16_f32(a)        (a)
#define vreinterpret_p16_s8(a)         (a)
#define vreinterpret_p16_s16(a)        (a)
#define vreinterpret_p16_s32(a)        (a)
#define vreinterpret_p16_s64(a)        (a)
#define vreinterpret_p16_p8(a)         (a)
#define vreinterpret_p16_u8(a)         (a)
#define vreinterpret_p16_u16(a)        (a)
#define vreinterpret_p16_u32(a)        (a)
#define vreinterpret_p16_u64(a)        (a)
#define vreinterpret_u8_f32(a)         (a)
#define vreinterpret_u8_s8(a)          (a)
#define vreinterpret_u8_s16(a)         (a)
#define vreinterpret_u8_s32(a)         (a)
#define vreinterpret_u8_s64(a)         (a)
#define vreinterpret_u8_p8(a)          (a)
#define vreinterpret_u8_p16(a)         (a)
#define vreinterpret_u8_u16(a)         (a)
#define vreinterpret_u8_u32(a)         (a)
#define vreinterpret_u8_u64(a)         (a)
#define vreinterpret_u16_f32(a)        (a)
#define vreinterpret_u16_s8(a)         (a)
#define vreinterpret_u16_s16(a)        (a)
#define vreinterpret_u16_s32(a)        (a)
#define vreinterpret_u16_s64(a)        (a)
#define vreinterpret_u16_p8(a)         (a)
#define vreinterpret_u16_p16(a)        (a)
#define vreinterpret_u16_u8(a)         (a)
#define vreinterpret_u16_u32(a)        (a)
#define vreinterpret_u16_u64(a)        (a)
#define vreinterpret_u32_f32(a)        (a)
#define vreinterpret_u32_s8(a)         (a)
#define vreinterpret_u32_s16(a)        (a)
#define vreinterpret_u32_s32(a)        (a)
#define vreinterpret_u32_s64(a)        (a)
#define vreinterpret_u32_p8(a)         (a)
#define vreinterpret_u32_p16(a)        (a)
#define vreinterpret_u32_u8(a)         (a)
#define vreinterpret_u32_u16(a)        (a)
#define vreinterpret_u32_u64(a)        (a)
#define vreinterpret_u64_f32(a)        (a)
#define vreinterpret_u64_s8(a)         (a)
#define vreinterpret_u64_s16(a)        (a)
#define vreinterpret_u64_s32(a)        (a)
#define vreinterpret_u64_s64(a)        (a)
#define vreinterpret_u64_p8(a)         (a)
#define vreinterpret_u64_p16(a)        (a)
#define vreinterpret_u64_u8(a)         (a)
#define vreinterpret_u64_u16(a)        (a)
#define vreinterpret_u64_u32(a)        (a)
#define vreinterpretq_f32_s8(a)        (a)
#define vreinterpretq_f32_s16(a)       (a)
#define vreinterpretq_f32_s32(a)       (a)
#define vreinterpretq_f32_s64(a)       (a)
#define vreinterpretq_f32_p8(a)        (a)
#define vreinterpretq_f32_p16(a)       (a)
#define vreinterpretq_f32_u8(a)        (a)
#define vreinterpretq_f32_u16(a)       (a)
#define vreinterpretq_f32_u32(a)       (a)
#define vreinterpretq_f32_u64(a)       (a)
#define vreinterpretq_s8_f32(a)        (a)
#define vreinterpretq_s8_s16(a)        (a)
#define vreinterpretq_s8_s32(a)        (a)
#define vreinterpretq_s8_s64(a)        (a)
#define vreinterpretq_s8_p8(a)         (a)
#define vreinterpretq_s8_p16(a)        (a)
#define vreinterpretq_s8_u8(a)         (a)
#define vreinterpretq_s8_u16(a)        (a)
#define vreinterpretq_s8_u32(a)        (a)
#define vreinterpretq_s8_u64(a)        (a)
#define vreinterpretq_s16_f32(a)       (a)
#define vreinterpretq_s16_s8(a)        (a)
#define vreinterpretq_s16_s32(a)       (a)
#define vreinterpretq_s16_s64(a)       (a)
#define vreinterpretq_s16_p8(a)        (a)
#define vreinterpretq_s16_p16(a)       (a)
#define vreinterpretq_s16_u8(a)        (a)
#define vreinterpretq_s16_u16(a)       (a)
#define vreinterpretq_s16_u32(a)       (a)
#define vreinterpretq_s16_u64(a)       (a)
#define vreinterpretq_s32_f32(a)       (a)
#define vreinterpretq_s32_s8(a)        (a)
#define vreinterpretq_s32_s16(a)       (a)
#define vreinterpretq_s32_s64(a)       (a)
#define vreinterpretq_s32_p8(a)        (a)
#define vreinterpretq_s32_p16(a)       (a)
#define vreinterpretq_s32_u8(a)        (a)
#define vreinterpretq_s32_u16(a)       (a)
#define vreinterpretq_s32_u32(a)       (a)
#define vreinterpretq_s32_u64(a)       (a)
#define vreinterpretq_s64_f32(a)       (a)
#define vreinterpretq_s64_s8(a)        (a)
#define vreinterpretq_s64_s16(a)       (a)
#define vreinterpretq_s64_s32(a)       (a)
#define vreinterpretq_s64_p8(a)        (a)
#define vreinterpretq_s64_p16(a)       (a)
#define vreinterpretq_s64_u8(a)        (a)
#define vreinterpretq_s64_u16(a)       (a)
#define vreinterpretq_s64_u32(a)       (a)
#define vreinterpretq_s64_u64(a)       (a)
#define vreinterpretq_p8_f32(a)        (a)
#define vreinterpretq_p8_s8(a)         (a)
#define vreinterpretq_p8_s16(a)        (a)
#define vreinterpretq_p8_s32(a)        (a)
#define vreinterpretq_p8_s64(a)        (a)
#define vreinterpretq_p8_p16(a)        (a)
#define vreinterpretq_p8_u8(a)         (a)
#define vreinterpretq_p8_u16(a)        (a)
#define vreinterpretq_p8_u32(a)        (a)
#define vreinterpretq_p8_u64(a)        (a)
#define vreinterpretq_p16_f32(a)       (a)
#define vreinterpretq_p16_s8(a)        (a)
#define vreinterpretq_p16_s16(a)       (a)
#define vreinterpretq_p16_s32(a)       (a)
#define vreinterpretq_p16_s64(a)       (a)
#define vreinterpretq_p16_p8(a)        (a)
#define vreinterpretq_p16_u8(a)        (a)
#define vreinterpretq_p16_u16(a)       (a)
#define vreinterpretq_p16_u32(a)       (a)
#define vreinterpretq_p16_u64(a)       (a)
#define vreinterpretq_u8_f32(a)        (a)
#define vreinterpretq_u8_s8(a)         (a)
#define vreinterpretq_u8_s16(a)        (a)
#define vreinterpretq_u8_s32(a)        (a)
#define vreinterpretq_u8_s64(a)        (a)
#define vreinterpretq_u8_p8(a)         (a)
#define vreinterpretq_u8_p16(a)        (a)
#define vreinterpretq_u8_u16(a)        (a)
#define vreinterpretq_u8_u32(a)        (a)
#define vreinterpretq_u8_u64(a)        (a)
#define vreinterpretq_u16_f32(a)       (a)
#define vreinterpretq_u16_s8(a)        (a)
#define vreinterpretq_u16_s16(a)       (a)
#define vreinterpretq_u16_s32(a)       (a)
#define vreinterpretq_u16_s64(a)       (a)
#define vreinterpretq_u16_p8(a)        (a)
#define vreinterpretq_u16_p16(a)       (a)
#define vreinterpretq_u16_u8(a)        (a)
#define vreinterpretq_u16_u32(a)       (a)
#define vreinterpretq_u16_u64(a)       (a)
#define vreinterpretq_u32_f32(a)       (a)
#define vreinterpretq_u32_s8(a)        (a)
#define vreinterpretq_u32_s16(a)       (a)
#define vreinterpretq_u32_s32(a)       (a)
#define vreinterpretq_u32_s64(a)       (a)
#define vreinterpretq_u32_p8(a)        (a)
#define vreinterpretq_u32_p16(a)       (a)
#define vreinterpretq_u32_u8(a)        (a)
#define vreinterpretq_u32_u16(a)       (a)
#define vreinterpretq_u32_u64(a)       (a)
#define vreinterpretq_u64_f32(a)       (a)
#define vreinterpretq_u64_s8(a)        (a)
#define vreinterpretq_u64_s16(a)       (a)
#define vreinterpretq_u64_s32(a)       (a)
#define vreinterpretq_u64_s64(a)       (a)
#define vreinterpretq_u64_p8(a)        (a)
#define vreinterpretq_u64_p16(a)       (a)
#define vreinterpretq_u64_u8(a)        (a)
#define vreinterpretq_u64_u16(a)       (a)
#define vreinterpretq_u64_u32(a)       (a)
#define vreinterpret_f16_u16(a)        (a)
#define vreinterpret_u16_f16(a)        (a)

#if defined (__cplusplus)
}
#endif  /* defined (__cplusplus) */


///////////////////////////////////////////////////////////////////////////////
//
// VLDx/VSTx alignment specifications
//


#define _NEON_ALIGN16(a)         \
    (                            \
    ((a) == 8) ? 0 :             \
    ((a) == 16) ? 1 :            \
    -1)

#define _NEON_ALIGN32(a)         \
    (                            \
    ((a) == 8) ? 0 :             \
    ((a) == 32) ? 1 :            \
    -1)

#define _NEON_ALIGN64(a)         \
    (                            \
    ((a) == 8) ? 0 :             \
    ((a) == 64) ? 1 :            \
    -1)

#define _NEON_ALIGN64_128(a)     \
    (                            \
    ((a) == 8) ? 0 :             \
    ((a) == 64) ? 1 :            \
    ((a) == 128) ? 2 :           \
    -1)


#define _NEON_ALIGN64_128_256(a) \
    (                            \
    ((a) == 8) ? 0 :             \
    ((a) == 64) ? 1 :            \
    ((a) == 128) ? 2 :           \
    ((a) == 256) ? 3 :           \
    -1)



/* 88bf0570-3001-4e78-a5f2-be5765546192 */ 
