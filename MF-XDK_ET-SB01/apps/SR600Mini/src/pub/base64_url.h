/**
 * @file bass64_url.h
 * @author CHAR
 * @brief 
 * @date 2024-3-19
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __BASS64_URL_H__
#define __BASS64_URL_H__
#include "pub/pub.h"
typedef enum
{
    B64_URL_ENC,
    B64_URL_DEC,
}Base64UrlType_E;

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

LIB_EXPORT int Base64UrlDec(const unsigned char* src, int ilen, unsigned char* dst, int iDst);
LIB_EXPORT int Base64UrlDestLength(Base64UrlType_E type, int dstLength);
LIB_EXPORT int Base64UrlEnc(const unsigned char* src, int ilen, unsigned char* dst, int iDst);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BASS64_URL_H__ */
