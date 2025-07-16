/**
 * @file mfsdk_define.h
 * @author CHAR
 * @brief
 * @date 2023-11-17
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_DEFINE_H__
#define __MFSDK_DEFINE_H__
#include <stdint.h>
#include "libapi_pub.h"

#if defined(__GNUC__) || defined(__clang__)
    #define MFSDK_DEPRECATED(msg) __attribute__((deprecated("This function is deprecated.Use new API " msg)))
#elif defined(_MSC_VER)
    #define MFSDK_DEPRECATED(msg) __declspec(deprecated("This function is deprecated.Use new API " msg))
#else
    #define MFSDK_DEPRECATED(msg)
#endif


//unused variable CHAR 2023.11.24 9:17
#define MFSDK_UNUSED(x) ((void)(x))
/*
   if __cond__ == true will return __retValue__ ;
   CHAR 2023.11.16 9:1
 */
#define MFSDK_COND_RET(__cond__,__retValue__) do{ if(__cond__) { return __retValue__; } }while(0)

#define MFSDK_FALSE (0)
#define MFSDK_TRUE (1)

typedef int MFSDKBOOL;

typedef uint64_t u64;
typedef int64_t s64;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;


typedef enum
{
	MFSDK_RET_FAILED = -3, //failed
	MFSDK_RET_BOUNDS = -2, //Array out-of-bounds
	MFSDK_RET_PARM_ERROR = -1, //check param
	MFSDK_RET_OK = 0,
}MfSdkRet_E;

#endif /* __MFSDK_DEFINE_H__ */

