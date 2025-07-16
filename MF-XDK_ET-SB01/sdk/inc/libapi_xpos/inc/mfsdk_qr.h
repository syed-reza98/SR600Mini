/**
 * @file mfsdk_qr.h
 * @author CHAR
 * @brief 
 * @date 2023-11-29
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_QR_H__
#define __MFSDK_QR_H__
#include "mfsdk_define.h"
typedef enum
{
	MFSDK_QR_RET_DECODE_FAILED = -4, //decode failed
	MFSDK_QR_RET_FAILED = -3, //failed
	MFSDK_QR_RET_BOUNDS = -2, //Array out-of-bounds
	MFSDK_QR_RET_PARM_ERROR = -1, //check param
	MFSDK_QR_RET_OK = 0,
}MfSdkQrRet_E;

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief Get scan data
 *
 * @param[out] code scan data
 * @param[in] size scan size
 * @return	MFSDK_QR_RET_FAILED, not found camera
 * @return	MFSDK_QR_RET_DECODE_FAILED decode failed 
 * @return	> 0, decode data length
 */
LIB_EXPORT s32 MfSdkQrDecode(s8* code, s32 size);
/**
 * @brief Close scaner
 *
 * @return	MFSDK_QR_RET_OK,success
 * @return	Other,fail
 */
LIB_EXPORT s32 MfSdkQrScannerClose(void);
/**
 * @brief Get scan image
 *
 * @return	scan image
 * @details (MF960:480*640) , (H9Pro:320*240)
 */
LIB_EXPORT s8* MfSdkQrScannerGetImg(void);
/**
 * @brief open scaner
 *
 * @return	MFSDK_QR_RET_OK,success
 * @return	Other,fail
 */
LIB_EXPORT s32 MfSdkQrScannerOpen(void);

/**
 * @brief Set scaner preview position
 *
 * @param[in] x x offset
 * @param[in] y y offset
 */
LIB_EXPORT void MfSdkQrSetScanBoxPosition(s32 x, s32 y);
/**
 * @brief Start scanner
 *
 * @return	MFSDK_QR_RET_OK,success
 * @return	Other,fail
 */
LIB_EXPORT s32 MfSdkQrScannerStart(void);
/**
 * @brief Stop scaner
 *
 * @return	MFSDK_QR_RET_OK,success
 * @return	Other,fail
 */
LIB_EXPORT s32 MfSdkQrScannerStop(void);
/**
 * @brief Set scaner preview
 *
 * @param[in] value 1:open 0:close
 */
LIB_EXPORT void MfSdkQrScannerSetPreview(int value);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_QR_H__ */
