#pragma once
#ifndef UNEX_TYPES_H
#define UNEX_TYPES_H
#include <stdint.h>

#ifdef UNEX_USE_SHORT_TYPES
///* Signed integer types *///
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

///* Unsigned integer types *///
typedef uint8_t byte;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

///* Floating types *///
typedef float f32;
typedef double f64;
#endif

#ifdef UNEX_USE_LONG_TYPES
///* Signed integer types *///
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

///* Unsigned integer types *///
typedef uint8_t byte;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

///* Floating types *///
typedef float float32;
typedef double float64;
#endif

#ifndef UNEX_USE_SHORT_TYPES
#ifndef UNEX_USE_LONG_TYPES
///* Integer type macros *///
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
#else
///* Integer type macros *///
#define INT8    int8
#define INT16   int16
#define INT32   int32
#define INT64   int64
#define UINT8   uint8
#define UINT16  uint16
#define UINT32  uint32
#define UINT64  uint64
#define FLOAT32 float32
#define FLOAT64 float64
#define BYTE    byte
#endif
#else
///* Integer type macros *///
#define INT8    i8
#define INT16   i16
#define INT32   i32
#define INT64   i64
#define UINT8   u8
#define UINT16  u16
#define UINT32  u32
#define UINT64  u64
#define FLOAT32 f32
#define FLOAT64 f64
#define BYTE    byte
#endif

#define SIZE size_t

#endif //UNEX_TYPES_H