/**
 * @file mfsdk_nfc.h
 * @author CHAR
 * @brief 
 * @date 2023-11-18
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_NFC_H__
#define __MFSDK_NFC_H__
#include "mfsdk_icc.h"
#include "mfsdk_define.h"
typedef enum
{
	MFSDK_NFC_RET_MUTILCARD = MFSDK_ICC_RET_MUTILCARD, // more than one card
	MFSDK_NFC_RET_NOCARD = MFSDK_ICC_RET_NOCARD, // dont find card
	MFSDK_NFC_RET_FAILED = MFSDK_ICC_RET_FAILED, //failed
	MFSDK_NFC_RET_BOUNDS = MFSDK_ICC_RET_BOUNDS, //Array out-of-bounds
	MFSDK_NFC_RET_PARM_ERROR = MFSDK_ICC_RET_PARM_ERROR, //check param
	MFSDK_NFC_RET_OK = 0,
}MfSdkNfcRet_E;

typedef enum
{
	MFSDK_NFC_LED_BLUE = 0,
	MFSDK_NFC_LED_YELLOW,
	MFSDK_NFC_LED_GREEN,
	MFSDK_NFC_LED_RED,
}MfSdkNfcLed_E;
	
typedef enum
{
	MFSDK_NFC_LED_OFF = 0,
	MFSDK_NFC_LED_ON = 1,		
}MfSdkNfcLedSwitch_E;

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief NFC init
 * 
 * @return MFSDK_NFC_RET_OK success
 * @return MFSDK_NFC_RET_FAILED fail
 */
LIB_EXPORT s32 MfSdkNfcInit(void);
/**
 * @brief
 * 
 * @param[in] u8 *tbuf apdu request command
 * @param[in] u16 tlen  apdu request command length
 * @param[out] u8 **rbuf eg. unsigned char *pTemp &pTemp
 * @param[out] u16 *rlen pdu response length point
 * @return MFSDK_NFC_RET_OK success
 */
LIB_EXPORT s32 MfSdkNfcApdu(u8 *tbuf, u16 tlen, u8 **rbuf, u16 *rlen);
LIB_EXPORT s32 MfSdkNfcClose(void);
LIB_EXPORT s32 MfSdkNfcCtlsComm(s32 iCardType,MfSdkIccApdu_T *Apdu);
LIB_EXPORT s32 MfSdkNfcCtlsPowerDown(void);
LIB_EXPORT s32 MfSdkNfcCtlsPowerUpAndSeek(int iCardType, char *psUID);
/**
 * @brief Check whether the user swipes the card at the terminal
 *
 * @return  MFSDK_NFC_RET_NOCARD
 			MFSDK_NFC_RET_MUTILCARD, multiple card
 * @return  MFSDK_NFC_RET_OK Success
 */
LIB_EXPORT s32 MfSdkNfcDetect(void);

/**
 * @brief 
 * 
 * @param[in] u8 *pC_Apdu CAPDU bytes stream
 * @param[in] s32 clen CAPDU bytes stream length
 * @param[out] u8 *pR_Apdu RAPDU recv buffer
 * @param[in] s32 rlen recv buffer size
 * @return > 0 R_Apdu length
 * @return MFSDK_ICC_RET_PARM_ERROR  params error
 * @return MFSDK_ICC_RET_BOUNDS rLength < card response length
 */
LIB_EXPORT s32 MfSdkNfcApduStream(u8 *pC_Apdu, s32 clen, u8 *pR_Apdu, s32 rlen);

LIB_EXPORT s32 MfSdkNfcGetUid(u8* uid);
/**
 * @brief Check whether the NFC card is detected
 *
 * @return 1 - success
 * @return other - failed
 */
LIB_EXPORT s32 MfSdkNfcIsProbe(void);
LIB_EXPORT s32 MfSdkNfcM1Atqa(void);
LIB_EXPORT s32 MfSdkNfcM1Auth(s32 cmd, s32 block);
LIB_EXPORT s32 MfSdkNfcM1Close(void);
LIB_EXPORT s32 MfSdkNfcM1Decrement(s32 block, s32 operand);
LIB_EXPORT s32 MfSdkNfcM1Increment(s32 block, s32 operand);
LIB_EXPORT s32 MfSdkNfcM1Open(void);
LIB_EXPORT s32 MfSdkNfcM1Read(s32 block, u8* buf, s32 *len);
LIB_EXPORT s32 MfSdkNfcM1Restore(s32 block);
LIB_EXPORT s32 MfSdkNfcM1SetKey(u8 *key);
LIB_EXPORT s32 MfSdkNfcM1Transfer(s32 block);
LIB_EXPORT s32 MfSdkNfcM1Uid(u8 *uid);
LIB_EXPORT s32 MfSdkNfcM1Write(s32 block, u8 *buf, s32 len);
LIB_EXPORT s32 MfSdkNfcOpen(void);
LIB_EXPORT s32 MfSdkNfcReset(u8* pAtr, s32 iAtrLength);

/**
 * @brief ntag set data initialization
 *
 * @param[in] data data
 * @param[in] inDataLen data len
 * @param[in] code data encoding format(example "utf-8"
 * @return MFSDK_NFC_RET_OK success
 * @return MFSDK_NFC_RET_FAILED fail
 */
LIB_EXPORT s32 MfSdkNfcTagEmulateInitSetData(s8* data, s32 inDataLen, s8* code);
/**
 * @brief ntag set url initialization
 *
 * @param[in] url set url
 * @return MFSDK_NFC_RET_OK success
 * @return MFSDK_NFC_RET_FAILED fail
 */
LIB_EXPORT s32 MfSdkNfcTagEmulateInitSetUrl(u8* url);

/**
 * @brief ntag execution processing
 *
 */
LIB_EXPORT void MfSdkNfcTagEmulateProcess(void);

/**
 * @brief ntag deinitialization
 *
 * @return MFSDK_NFC_RET_OK success
 * @return MFSDK_NFC_RET_FAILED fail
 */
LIB_EXPORT s32 MfSdkNfcTagEmulateDeinit(void);

/**
 * @brief led control
 * 
 * @param[in] MfSdkNfcLed_E num  , led color
 * @param[in] MfSdkNfcLedSwitch_E type , switch
 */
LIB_EXPORT void MfSdkNfcLed(MfSdkNfcLed_E num, MfSdkNfcLedSwitch_E type);

/**
 * @brief Check whether the NFC antenna is around the LCD
 * 
 * @return  MFSDK_TRUE  nfc antenna around lcd
 */
LIB_EXPORT MFSDKBOOL MfSdkNfcIsAroundFrontLcd(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_NFC_H__ */
