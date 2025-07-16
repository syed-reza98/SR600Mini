/**
 * @file mfsdk_aud.h
 * @author CHAR
 * @brief 
 * @date 2023-11-18
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_AUD_H__
#define __MFSDK_AUD_H__

#include "mfsdk_define.h"
typedef enum 
{
	MFSDK_AUD_PLAY_UNIT_MIN = 0,
	MFSDK_AUD_PLAY_UNIT_TEN = MFSDK_AUD_PLAY_UNIT_MIN,
	MFSDK_AUD_PLAY_UNIT_HUNDRED,
	MFSDK_AUD_PLAY_UNIT_THOUSAND,
	MFSDK_AUD_PLAY_UNIT_TEN_THOUSAND,
	MFSDK_AUD_PLAY_UNIT_YUAN,
	MFSDK_AUD_PLAY_UNIT_MAX
}MfSdkAudPlayUnit_T;

typedef enum
{
    MFSDK_AUD_PAY_MIN = 0,
    MFSDK_AUD_PAY_PROCESSING = MFSDK_AUD_PAY_MIN,
    MFSDK_AUD_PAY_FAIL,
    MFSDK_AUD_PAY_SUCCESS,
    MFSDK_AUD_PAY_SCAN_SUCCESS,
    MFSDK_AUD_PAY_VOID_SUCCESS,
    MFSDK_AUD_PAY_MAX,
}MfSdkAudPayResult_E;

typedef enum
{
    MFSDK_AUD_PLAY_NUM_MIN = 0,
    MFSDK_AUD_PLAY_NUM_ZERO = MFSDK_AUD_PLAY_NUM_MIN,
    MFSDK_AUD_PLAY_NUM_ONE,
    MFSDK_AUD_PLAY_NUM_TWO,
    MFSDK_AUD_PLAY_NUM_THREE,
    MFSDK_AUD_PLAY_NUM_FOUR,
    MFSDK_AUD_PLAY_NUM_FIVE,
    MFSDK_AUD_PLAY_NUM_SIX,
    MFSDK_AUD_PLAY_NUM_SEVEN,
    MFSDK_AUD_PLAY_NUM_EIGHT,
    MFSDK_AUD_PLAY_NUM_NINE,
    MFSDK_AUD_PLAY_NUM_DOT,
    MFSDK_AUD_PLAY_NUM_MAX
}MfSdkAudPlayNum_E;

typedef enum
{
    MFSDK_AUD_PAY_TYPE_MIN = 0,
    MFSDK_AUD_PAY_TYPE_WECHAT = MFSDK_AUD_PAY_TYPE_MIN,
    MFSDK_AUD_PAY_TYPE_ALIPAY,
    MFSDK_AUD_PAY_TYPE_UNIONPAY,
    MFSDK_AUD_PAY_TYPE_CARD,
    MFSDK_AUD_PAY_TYPE_SCAN = 7,
    MFSDK_AUD_PAY_TYPE_MAX
}MfSdkAudPlayPayType_E;

typedef enum
{
    MFSDK_AUD_RET_FAILED = -3,     //failed
    MFSDK_AUD_RET_BOUNDS = -2,     //Array out-of-bounds
    MFSDK_AUD_RET_PARM_ERROR = -1,     //check param
    MFSDK_AUD_RET_OK = 0,
}MfSdkAudRet_E;


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/**
 * @brief
 * 
 * @param[in] s8 *msg
 */
LIB_EXPORT void MfSdkAudPlayVoice(s8 *msg);

/**
 * @brief
 *
 * @param[in] s32 amount
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayAmt(s32 amount);
/**
 * @brief play battery level
 * 
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayBatteryLevel(void);
/**
 * @brief
 *  pub_tts_play and  pub_tts_playOpt
 * @param[in] const s8 * folder
 * @param[in] const s8 * sndfile
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayFile(const s8 * folder, const s8 * sndfile);

/**
 * @brief
 * 
 * @param[in] const s8 * sndfile
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlay(const s8 * sndfile);

/**
 * @brief
 *
 * @param[in] MfSdkAudPlayNum_E index
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayNum(MfSdkAudPlayNum_E index);
/**
 * @brief
 * 
 * @param[in] s32 num
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayNumber(s32 num);
/**
 * @brief
 *
 * @param[in] MfSdkAudPayResult_E index
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayPayResult(MfSdkAudPayResult_E index);
/**
 * @brief
 *
 * @param[in] MfSdkAudPlayPayType_E payType
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayPayType(MfSdkAudPlayPayType_E payType);
/**
 * @brief
 *
 * @param[in] MfSdkAudPlayUnit_T index  Ref. MfSdkAudPlayUnit_T
 * @return Ref. MfSdkAudRet_E
 */
LIB_EXPORT s32 MfSdkAudPlayUnit(MfSdkAudPlayUnit_T index);
/**
 * @brief
 *
 * @return MFSDK_TRUE success
 * @return MFSDK_FALSE fail
 */
LIB_EXPORT MFSDKBOOL MfSdkAudTtsState(void);

/**
 * @brief Deprecated
 *
 */
LIB_EXPORT void MfSdkAudBatchBegin(void);
/**
 * @brief Deprecated
 * 
 */
LIB_EXPORT void MfSdkAudBathcEnd(void);
/**
 * @brief
 * 
 */
LIB_EXPORT void MfSdkAudClear(void);
/**
* @brief tts TTS
* @param[in] msg  Text Message
* @return 
*/
LIB_EXPORT s32 MfSdkAudTtsPlay(s8 *msg);

/**
 * @brief set audio volume
 * 
 * @param[in] s32 val
 */
LIB_EXPORT void MfSdkAudSetVolume(s32 val);
/**
 * @brief Set the volume when playing voice
 * 
 * @param[in] s32 val
 */
LIB_EXPORT void MfSdkAudSetVolumeRunning(s32 val);
/**
 * @brief Get the volume size
 * 
 * @return volume
 */
LIB_EXPORT s32 MfSdkAudGetVolume();
/**
 * @brief
 * 
 * @param[in] s32 val
 */
LIB_EXPORT void MfSdkAudSetSpeed(s32 val);
/**
 * @brief 
 *	Wait for network registration 
 *	after boot before playback (Boot-up lag issue).
 * 
 * @param[in] s32 val_ms unit:ms
 */
LIB_EXPORT void MfSdkAudPlayWait(s32 val_ms);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_AUD_H__ */
