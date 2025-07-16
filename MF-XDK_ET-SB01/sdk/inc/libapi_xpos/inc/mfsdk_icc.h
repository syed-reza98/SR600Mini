/**
 * @file MfSdk_icc.h
 * @author CHAR
 * @brief 
 * @date 2023-11-26
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_ICC_H__
#define __MFSDK_ICC_H__
#include "mfsdk_define.h"
/*APDU max bytes stream */
#define MFSDK_ICC_APDU_MAX (300)

typedef enum
{
	MFSDK_ICC_SLOT_MIN = 0,
	MFSDK_ICC_SLOT_NFC = MFSDK_ICC_SLOT_MIN, //rfid
	MFSDK_ICC_SLOT_NFC_EXTERN , //rfid extern
	MFSDK_ICC_SLOT_ICC, //contact ic card slot
	MFSDK_ICC_SLOT_ICC_EXTERN, //contact ic card slot extern
	MFSDK_ICC_SLOT_PSAM1,
	MFSDK_ICC_SLOT_PSAM2,
	MFSDK_ICC_SLOT_PSAM3,
	MFSDK_ICC_SLOT_PSAM4,
	MFSDK_ICC_SLOT_PSAM5,
	MFSDK_ICC_SLOT_PSAM6,
	MFSDK_ICC_SLOT_MAX
}MfSdkIccSlot_E;

typedef enum
{
	MFSDK_ICC_RET_MUTILCARD = -5, // more than one card
	MFSDK_ICC_RET_NOCARD = -4, // dont find card
	MFSDK_ICC_RET_FAILED = -3, //failed
	MFSDK_ICC_RET_BOUNDS = -2, //Array out-of-bounds
	MFSDK_ICC_RET_PARM_ERROR = -1, //check param
	MFSDK_ICC_RET_OK = 0,
}MfSdkIccRet_E;

typedef ICCAPDU MfSdkIccApdu_T;

typedef enum
{
	MFSDK_ICC_TYPE_CPUCARD = 0,

}MfSdkIccType_E;


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/**
 * @brief
 * 
 * @param[in] MfSdkIccSlot_E iSlotType
 * @return MFSDK_ICC_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkIccClose(MfSdkIccSlot_E iSlotType);
/**
 * @brief
 * 
 * @param[in] s32 iCardType Ref. MfSdkIccType_E
 * @param[in] MfSdkIccSlot_E iSlotType
 * @param[in] MfSdkIccApdu_T *Apdu
 * @return  Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccComm(s32 iCardType,MfSdkIccSlot_E iSlotType, MfSdkIccApdu_T *Apdu);
/**
 * @brief
 * 
 * @param[in] s32 iCardType Ref. MfSdkIccType_E
 * @param[in] MfSdkIccSlot_E iSlotType
 * @param[in] u8 *psATR
 * @param[in] s32*pnATRLen
 * @return Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccGetCardATR(s32 iCardType, MfSdkIccSlot_E iSlotType, u8 *psATR, s32*pnATRLen);
/**
 * @brief
 * 
 * @param[in] MfSdkIccSlot_E iSlotType
 * @return Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccGetCardStatus(MfSdkIccSlot_E iSlotType);
/**
 * @brief
 * 
 * @param[out] u8 *pszVer
 * @return Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccGetModuleVer(u8 *pszVer);
/**
 * @brief
 * 
 * @return Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccInsertDetect(void);
/**
 * @brief apdu bytes stream
 * 
 * @param[in] MfSdkIccSlot_E iSlotType
 * @param[in] u8* pC_Apdu bytes stream
 * @param[in] s32 cLength
 * @param[out] u8* pR_Apdu
 * @param[in] s32 rLength
 * @return > 0 R_Apdu length
 * @return MFSDK_ICC_RET_PARM_ERROR  params error
 * @return MFSDK_ICC_RET_BOUNDS rLength < card response length
 */
LIB_EXPORT s32 MfSdkIccApdu(MfSdkIccSlot_E iSlotType, u8* pC_Apdu, s32 cLength,u8* pR_Apdu,s32 rLength);

/**
 * @brief
 * 
 * @param[in] MfSdkIccSlot_E iSlotType
 * @return Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccOpen(MfSdkIccSlot_E iSlotType);
/**
 * @brief
 * 
 * @param[in] s32 iCardType Ref. MfSdkIccType_E
 * @param[in] MfSdkIccSlot_E iSlotType
 * @return Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccPowerOff(s32 iCardType, MfSdkIccSlot_E iSlotType);

/**
 * @brief
 * 
 * @param[in] s32 iCardType
 * @param[in] MfSdkIccSlot_E iSlotType
 * @param[out] u8 *atrstr
 * @param[in] s32 buflen
 * @return > 0 atr length
 * @return other fail
 */
LIB_EXPORT s32 MfSdkIccPowerUp(s32 iCardType, MfSdkIccSlot_E iSlotType ,u8 *atrstr,s32 buflen);

/**
 * @brief
 * 
 * @param[in] s32 iCardType Ref. MfSdkIccType_E
 * @param[in] MfSdkIccSlot_E iSlotType
 * @return Ref. MfSdkIccRet_E
 */
LIB_EXPORT s32 MfSdkIccPowerOn(s32 iCardType, MfSdkIccSlot_E iSlotType);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_ICC_H__ */
