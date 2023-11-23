#ifndef UAPI_TYPES_H
#define UAPI_TYPES_H

typedef char s8_t;
typedef volatile char vs8_t;
typedef unsigned char u8_t;
typedef volatile unsigned char vu8_t;

typedef short int s16_t;
typedef volatile short int vs16_t;
typedef unsigned short int u16_t;
typedef volatile unsigned short int vu16_t;

typedef int s32_t;
typedef volatile int vs32_t;
typedef unsigned int u32_t;
typedef volatile unsigned int vu32_t;

typedef long int s64_t;
typedef volatile long int vs64_t;
typedef unsigned long int u64_t;
typedef volatile unsigned long int vu64_t;

typedef long long int s128_t;
typedef volatile long long int vs128_t;
typedef unsigned long long int u128_t;
typedef volatile unsigned long long int vu128_t;

typedef float f32_t;
typedef double f64_t;

typedef long double f128_t;

typedef int bool_t;
typedef unsigned int size_t;

#define true 1
#define false 0

#define NULL 0

#endif