#pragma once
#ifndef UNEX_TYPES_H
#define UNEX_TYPES_H

#include <stdint.h>

#define INT8    int8_t
#define INT16   int16_t
#define INT32   int32_t
#define INT64   int64_t
#define UINT8   uint8_t
#define UINT16  uint16_t
#define UINT32  uint32_t
#define UINT64  uint64_t
#define FLOAT32 float
#define FLOAT64 double
#define BYTE    uint8_t
#define USIZE   size_t

#ifdef UNEX_USE_SHORT_TYPES
///* Signed integer types *///
typedef INT8 i8;
typedef INT16 i16;
typedef INT32 i32;
typedef INT64 i64;

///* Unsigned integer types *///
typedef UINT8 byte;
typedef UINT8 u8;
typedef UINT16 u16;
typedef UINT32 u32;
typedef UINT64 u64;

///* Floating types *///
typedef FLOAT32 f32;
typedef FLOAT64 f64;
#endif

#ifdef UNEX_USE_LONG_TYPES
///* Signed integer types *///
typedef INT8 int8;
typedef INT16 int16;
typedef INT32 int32;
typedef INT64 int64;

///* Unsigned integer types *///
typedef UINT8 byte;
typedef UINT8 uint8;
typedef UINT16 uint16;
typedef UINT32 uint32;
typedef UINT64 uint64;

///* Floating types *///
typedef FLOAT32 float32;
typedef FLOAT64 float64;
#endif

#endif //UNEX_TYPES_H