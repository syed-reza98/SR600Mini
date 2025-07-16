/**
 * @file mfsdk_mag.h
 * @author CHAR
 * @brief 
 * @date 2023-11-26
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_MAG_H__
#define __MFSDK_MAG_H__
#include "mfsdk_define.h"
typedef card_magtek_track_info MfSdkMagTraceInfo_T;
typedef enum
{
	MFSDK_MAG_RET_FAILED = -3, //failed
	MFSDK_MAG_RET_BOUNDS = -2, //Array out-of-bounds
	MFSDK_MAG_RET_PARM_ERROR = -1, //check param
	MFSDK_MAG_RET_OK = 0,
}MfSdkMagRet_E;


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/**
 * @brief Magstripe Card Detect
 * 
 * @param[out] MfSdkMagTraceInfo_T *trackinfo
 * @return 
 */
LIB_EXPORT s32 MfSdkMagStripeDetect(MfSdkMagTraceInfo_T *trackinfo);
/**
 * @brief
 * 
 */
LIB_EXPORT void MfSdkMagtekClose(void);
/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT s32 MfSdkMagTekFlush(void);
/**
 * @brief
 * 
 */
LIB_EXPORT void MfSdkMagtekOpen(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_MAG_H__ */
