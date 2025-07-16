/**
 * @file mfsdk_sys.h
 * @author Jerry
 * @brief 
 * @date 2023-11-28
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_EMV_H__
#define __MFSDK_EMV_H__

#include "mfsdk_define.h"
#include "def.h"
#include "lvgl/lvgl.h"
#include "emvapi.h"

#define MODE_API_UNKNOW			0x00			///< unknown api mode
#define	MODE_API_PBOC			0x01			///< pboc
#define MODE_API_VCPS			0x02			///< vcps
#define MODE_API_MSD			0x04			///< msd	
#define	MODE_API_AMEX			0x40			///< AMEX	
#define MODE_API_M_CHIP			0x21			///< MasterCard CHIP mode
#define MODE_API_M_STRIPE		0x22			///< MasterCard MagStripe mode
#define MODE_API_R_LEGACY		0x23			///< RUPAY LEGACY mode
#define MODE_API_R_NON_LEGACY	0x24			///< RUPAY NON LEGACY mode
#define MODE_API_EMV_MODE		0x25			///< EMV_MODE (for AMEX)
#define MODE_API_MS_MODE		0x26			///< MS_MODE	(for AMEX)
#define MODE_API_MOBILE_MODE	0x27			///< mobile_MODE	(for amex)

// application TLV TAG

#define APP_TAG_DF8A01_AIDOTHERTLV				"\xDF\x8A\x01"		// aid other tlv
#define APP_TAG_DF8A02_FORCEONLINE 				"\xDF\x81\x02"      //0:no forced online; 1:forced online(TVR) 2:foced online (request ARQC in case of TC)
#define DEF_TAG_AID_MCHIP_OTHER_PARAM      		"\xDF\x84\x06"      //AID other Contact
#define DEF_TAG_AID_RF_OTHER_PARAM          		"\xDF\x84\x07"      //AID other contactless
#define DEF_TAG_TAP_MODE         				"\xDF\x84\x08"      //tap mode (1-long tap  2-second tap)
#define DEF_TAG_CONTACTLESS_REFUN_CONFIG    	"\xDF\x84\x0A"      // Contactless Refund Config
#define APP_TAG_DF810C_KERNELID					"\xDF\x81\x0C"	    // Kernel ID

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
#define SDK_TRACK_MAX_LENTH		144

enum
{
	SDK_QPBOC_VER=0,
	SDK_VISA_VER,
	SDK_MASTER_VER,
	SDK_AMEX_VER,
	SDK_DPAS_VER,
	SDK_RUPAY_VER,
}SDK_KERNEL_VER;
enum
{
	SDK_KERNELID_MASTER = 0x02,
	SDK_KERNEID_VISA,
	SDK_KERNELID_AMEX,
	SDK_KERNELID_JCB,
	SDK_KERNELID_DISCOVER,
	SDK_KERNELID_UNIONPAY,
	SDK_KERNELID_SIBS,
	SDK_KERNELID_PURE,
	
}SDK_KERNEL_ID;

enum
{
	MFSDK_EMV_MSG_SELECT_APP,
	MFSDK_EMV_MSG_ONLINE_PIN,
	MFSDK_EMV_MSG_OFFLINE_PIN,
	MFSDK_EMV_MSG_OFFLINE_PIN_RETRY_COUNT,
	MFSDK_EMV_MSG_DISPLAY_CARD_NO, // display card no.
	MFSDK_EMV_MSG_SET_PUREAMT_BEFOREGPO, 
}CALLBACK_MSG;

enum
{
	MFSDK_EMV_CARD_RET_QUIT,	///< quit
	MFSDK_EMV_CARD_RET_INPUT,	///< input
	MFSDK_EMV_CARD_MAGTEK,		///< magstripe card
	MFSDK_EMV_CARD_ICC,			///< ICC
	MFSDK_EMV_CARD_RFID,		///< RF
}MfSdkEmvReadCardMode_E;

enum
{
	MFSDK_EMV_CARD_PROC_RET_TC = 0,	   ///< TC (offine approve)
	MFSDK_EMV_CARD_PROC_RET_ARQC = 1,  ///< ARQC(online require)
	MFSDK_EMV_CARD_PROC_RET_AAC = -11, ///< AAC(offline declined)
	MFSDK_EMV_CARD_PROC_RET_TERM = - 2,  ///< Terminate
	MFSDK_EMV_CARD_PROC_RET_CANCEL = -3, // User cancel
	MFSDK_EMV_CARD_PROC_RET_TIMEOUT = -4,	//Timeout
	MFSDK_EMV_CARD_PROC_RET_FORCEIC = -5,	//Transaction force IC
	MFSDK_EMV_CARD_PROC_RET_OTHER = -6,		//Contactless turn to other interface
	MFSDK_EMV_CARD_PROC_RET_FALLBACK = -7,	// Fallback
	MFSDK_EMV_CARD_PROC_RET_SEEPHONE = -8,		// See Phone and Retry
	MFSDK_EMV_CARD_PROC_RET_APPBLOCK = -9,	//app block
	MFSDK_EMV_CARD_PROC_RET_CARDBLOCK = -10,	//Card block
	MFSDK_EMV_CARD_PROC_RET_NOAPP = -12,		//card without any application available
	MFSDK_EMV_CARD_PROC_RET_ERR_POWERUP = -13, //card not responding or chip not present
	MFSDK_EMV_CARD_PROC_RET_INVDATA = -14,		//card behaves correctly but has invalid or inconsistent data.
	MFSDK_EMV_CARD_PROC_RET_APPNAUT = -15,		//card returned error 6985
	MFSDK_EMV_CARD_PROC_RET_CAPK_NOFOUND = -16,	//card CAPK not found
	MFSDK_EMV_CARD_PROC_RET_APDU_NORETURN = -17,	//APDU not returned
	MFSDK_EMV_CARD_PROC_RET_HAVEPROBLEMS = -1,		//the card does not behave as expected and the transaction be terminated
} MfSdkEmvCardProcRet_E;


enum {
	MFSDK_READ_CARD_MODE_MAG = 0x01,	///< magstripe
	MFSDK_READ_CARD_MODE_IC = 0x02,	///< ic
	MFSDK_READ_CARD_MODE_RF = 0x04	///< rf
}MfSdkCardMode;

typedef struct
{
	u8 cTranType;				// 00 sale 09 cashback
	u8 szAmt[12+1];				
	u8 szOtherAmt[12+1];
	u8 cReadCardMode;			// refer to MfSdkCardMode . Can be combined , 0x07 is all 
	u8 cPinInput;				// 0x01: enter the PIN interface according to the emv_read_card internal; 0x02:forces the PIN interface  of online transactions; 0x03:force pin; 0x00: will not require pin processing in emv_read_card
	u8 cPinMinLen;
	u8 cPinMaxLen;
	u8 cKeyPid;					// SEC_DUKPT_FIELD,SEC_MKSK_FIELD,SEC_FIXED_FIELD				
	u8 cDukptPinIndex;
	s8 cDukptDataIndex;
	u8 cDesMode;				//DES_MODE_ECB,DES_MODE_CBC
	u8 cMKSKPinIndex;
	u8 cPinFormat;				//refer to SEC_PIN_FORMAX in libapi_security.h
	u8 cBypassPin;
	u8 cTCFreeFlag;			// 0: TC free emv data inside SDK .1 : TC App manually free EMV data
}sdk_read_card_in;

typedef struct
{
	u8 cCardType;
	u8 szPan[22];
	u8 szPinBlock[16+1];
	u8 szPinKSN[10+1];
	u8 szDataKSN[10+1];
	u8 szTrack2[SDK_TRACK_MAX_LENTH];
	u8 cTrack2Len;
	u8 szTrack3[SDK_TRACK_MAX_LENTH];
	u8 cTrack3Len;
	u8 cEmvClsMode;
	u8 szServiceCode[3+1];///< service code of card
	u8 cClsCvmMethod;
	u16 nErrCode;	
}sdk_read_card_out;

typedef struct {
	u8 szRid[5];					//tag 9f06
	u8 cCapkIndex;					//tag 9f22
	u8 szCapkExpire[4];				//tag df05
	u8 cCapkHashFlag;				//tag df06
	u8 cCapkFlag;					//tag df07
	u8 szCapkMod[248];				//tag df02
	u8 cCapkModLen;					//szCAPKMod len
	u8 szCapkExponent[3];			//tag df04
	u8 cCapkExpLen;					//szCAPKExponent len   
	u8 szCapkCheckSum3[20];			//tag df03
	u8 cCheckSumLen;				//szCAPKCheckSum3 len
}MfSdkEmvCapkInfo_T;

typedef st_read_card_in  MfSdkEmvReadCardIn_T;
typedef st_read_card_out MfSdkEmvReadCardOut_T;
typedef card_magtek_track_info MfSdkEmvTrackInfo_T;
typedef AID_STRU MfSdkEmvAidSt_T;

typedef int(*MfSdkEmvSelecAppDisplay)(MfSdkEmvAidSt_T *stICCAID,int nAidNum,int *select_choic);

typedef int (*MfSdkEmvInputOffPin)(char *psCardNo,char *psAmt,char cMsgType,char *psPin);

typedef int (*MfSdkEmvInputOnlinePin)(char *psCardNo,char *psAmt,char *psPin);

typedef void (*MfSdkReadPage)(void);

typedef int (*MfSdkRuPay2ndPage)(void);

typedef int (*MfSdkDpas2ndPage)(void);
/**
 * @brief
 * add CHAR 2024.01.16 10:19
 * @param[out] u8*pOutData   out data Format:TLV
 * @param[in] s32 iOutData  pOutData buffer size
 * @return pOutData length  0/more than 0
 */
typedef int (*MfSdkPreprocessSetOtherDataCb)(u8*pOutData ,s32 iOutData);

/**
 * @brief Emv kernel initialize , Initialize once on boot.
 * 
 * @return None
 */
LIB_EXPORT void MfSdkEmvKernelInit(void);

/**
 * @brief
 * 
 * @param[in] u8* ConfigBuff :terminal parameters (all configutions are in TLV format)
 * @param[in] s32 BuffLen
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvTerminalConfigInit(u8* ConfigBuff,s32 BuffLen);
/**
 * @brief Detect if ICC / RFIC/ MAG are present
 * 
 * @param[in] s32 cardMode: 0x01:mag, 0x02:ICC,0x04:RFIC,0x07:All
 * @param[in] s32 timeout:timeout(The unit is second)
 * @return CardType: 1: ms card, 2: ICC, 3:RFIC, -2:cancel,-3:timeOut, -4:Multiple cards
 */
LIB_EXPORT s32 MfSdkEmvCardLoop(s32 cardMode,s32 timeout);

/**
 * @brief Detect if ICC / RFIC/ MAG are present
 * @param[in] cardMode cardMode: 0x01:mag, 0x02:ICC,0x04:RFIC,0x07:All
 * @param[in] exitCb exit callback, return 1 to exit detect
 * @param[in] timeoutS timeout(The unit is second)
 * @return 1: MAG card, 2: ICC, 3:RFIC, -2:cancel,-3:timeOut, -4:Multiple cards
*/
LIB_EXPORT s32 MfSdkEmvDetectCardLoop(s32 cardMode, s32(*exitCb)(), s32 timeoutS);
/**
 * @brief: kernel card reading process
 * 
 * @param[in] s32 ret: cardType: value of "MfSdkEmvReadCardMode_E"
 * @param[in] u8* inBuff: Transaction configure parameters(default set NULL)
 * @param[in] s32 inLen: Transaction configure parameters length(default set 0)
 * @param[out] sdk_read_card_out * st_out: out data 
 * @return 0: TC (offine approve), 
 * @return 1: ARQC(online require) ,
 * @return -11 :AAC(offline declined), 
 * @return -2:Terminate,see MfSdkEmvCardProcRet_E
 */
LIB_EXPORT s32 MfSdkEmvCardProc(s32 ret,sdk_read_card_in st_in,u8* inBuff,s32 inLen,sdk_read_card_out * st_out);
/**
 * @brief: Only for BC
 * 
 * @param[in] s32 ret
 * @param[in] u8* inBuff
 * @param[out] u8*outBuff
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvGetCard(s32 ret,u8* inBuff,u8*outBuff);
/**
 * @brief: Only for BC
 * 
 * @param[in] s32 ret
 * @param[in] u8* inBuff
 * @param[out] u8*outBuff
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvGoOnChip(s32 ret,u8* inBuff,u8*outBuff);
//aid 
/**
 * @brief: Add one aid
 * 
 * @param[in] u8* AidBuff:aid data in TLV format
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvSetAid(u8* AidBuff,s32 BuffLen);
/**
 * @brief: del one aod
 * 
 * @param[in] u8* Aid
 * @param[in] u8 aidLength
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvDeleteOneAid(u8* Aid,u8 aidLength);
/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT void MfSdkEmvClearAllAid(void);
//get aid list to be continue...

/**
 * @brief The total number of aids
 * 
 * @return aid total 
 */
LIB_EXPORT s32 MfSdkEmvGetAidNum(void);


//capk
/**
 * @brief: add one capk
 * 
 * @param[in] u8 * CapkBuff: TLV format 
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvSetCapk(u8 * CapkBuff,s32 BuffLen);
/**
 * @brief:delete one capk
 * 
 * @param[in] u8* RID
 * @param[in] u8 PKIndex
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvDeleteOneCapk(u8* RID,u8 PKIndex);
/**
 * @brief Delete All Capk
 * 
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvDeleteAllCapk(void);
// get capk list to be continue..
/**
 * @brief The total number of capks
 * 
 * @return capk total 
 */
LIB_EXPORT s32 MfSdkEmvGetCapkNum(void);

/**
 * @brief get capk info by index
 *
 * @param[out] stCapk	capk info
 * @param[in] nRecNum index
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvGetCapkByIndex(MfSdkEmvCapkInfo_T* stCapk, s32 nRecNum);
/**
 * @brief: Get tag data from TLV string(hex format)
 * 
 * @param[in] u8* Tag
 * @param[in] u8* Src
 * @param[in] s32 ScrLen
 * @param[out] u8* OutBuff
 * @param[out] s32* OutLen
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvGetDataByTag(u8* Tag,u8* Src,s32 ScrLen,u8* OutBuff,s32* OutLen);
/**
 * @brief: Packed TLV string to an array
 * 
 * @param[in] u8* Tag
 * @param[in] u8* TagValue
 * @param[in] s32 ValueLen
 * @param[out] u8* OutBuff
 * @param[out] s32* OutLen
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvPackTLVData(u8* Tag,u8* TagValue,s32 ValueLen,u8* OutBuff,s32* OutLen);
/**
 * @brief:Get tag value from Kernel
 * 
 * @param[in] u8* Tag
 * @param[out] s32* OutValueLen
 * @param[out] u8* OutValue
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvGetKernelData(u8* Tag,s32* OutValueLen,u8* OutValue);
/**
 * @brief: set tag value to kernel
 * 
 * @param[in] u8* Tag
 * @param[in] u8* SetData
 * @param[in] s32 DataLen
 * @param[in] s32 bOverRide: 1 Overwrite, 0 Prohibit Overwrite
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvSetKernelData(u8* Tag,u8* SetData,s32 DataLen,s32 bOverRide);
/**
 * @brief
 * 
 * @param[] TERMDRL stDRL
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvSetDRL(TERMDRL stDRL);
/**
 * @brief: clear all DRL 
 * 
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvClearDRLFile();
/**
 * @brief
 * 
 * @param[] u32 iErrcode
 * @return 1:Match, 0:no Match 
 */
LIB_EXPORT s32 MfSdkEmvMatchErrCode(u32 iErrcode);
/**
 * @brief:Process of emv online resp proc and pack tlv data
 * 
 * @param[in] s32 nOnlineRes: 0--online success(Any return in the server is success)  -1--online fail  
 * @param[in] s8* sField39:Online Response Code
 * @param[in] u8* sField55:ASICll format;contain 91/8A/71/72 Tag Data
 * @param[in] u8* EmvTag: ASICll format;the tags want to get. eg:(9F26828A)
 * @param[out] u8* PackValue:HEX fromat,the tlv data match emvtags 
 * @param[out] s32* packLen:packlen length of packvalue
 * @return 0: TC (offine approve),-1 :AAC(offline declined), -2/other:Terminate
 */
LIB_EXPORT s32 MfSdkEmvOnlineRespPack(s32 nOnlineRes,s8* sField39,u8* sField55,u8* EmvTag,u8* PackValue,s32* packLen);
/**
 * @brief: Free kernel data
 * 
 * @param[in] s32 Type:2:free icc card data; 3:free rfic card data
 * @return 0: success . other : failed
 */
LIB_EXPORT s32 MfSdkEmvCardFree(s32 Type);
/**
 * @brief
 * 
 * @param[in] BlackCard stBlackCard
 * @param[in] s32 cCoverFlag
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvAddCardBlackList(BlackCard stBlackCard,s32 cCoverFlag);
/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvDelCardBlackList(BlackCard stBlackCard);

/**
 * @brief
 * 
 * @return KernelVersion
 */
LIB_EXPORT s8* MfSdkEmvGetKernelVersion(void);

/**
 * @brief
 * 
 * @param[out] s8 *Version:EMV version
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvGetVersion(s8 *Version);
/**
 * @brief
 * 
 * @param[] s8* Version: Entry Version
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvGetEntryVersion(s8* Version);
/**
 * @brief: Get separate contactless version. 
 * 
 * @param[in] s32 KernelType: refer to SDK_KERNEL_VER
 * @param[out] s8* Version
 * @return 
 */
LIB_EXPORT s32 MfSdkEmvGetContactlessVersion(s32 KernelType,s8* Version);
/**
 * @brief: According to MsgType to set different callback function
 * 
 * @param[in] callback (emv callback)
 * @param[out] MsgType : refer to CALLBACK_MSG
 * @param[out] Indata:Different msg types have different input parameters
 			MFSDK_EMV_MSG_SELECT_APP:TLV format (tag 4F(aid)+50(app lable)+9f12(APP Preferred Name)+87(APP Priority Indicator))	
 			MFSDK_EMV_MSG_ONLINE_PIN:TLV format(tag 5A(card number)+9F02(amount))
 			MFSDK_EMV_MSG_OFFLINE_PIN:TLV format(tag 5A(card number)+9F02(amount))
 			MFSDK_EMV_MSG_OFFLINE_PIN_RETRY_COUNT:one byte pin retry count
 			MFSDK_EMV_MSG_SET_PUREAMT_BEFOREGPO:
 * @param[out] InLen: length of input parameters . 
 * @param[in] OutData: Different msg types have different output parameters
 			MFSDK_EMV_MSG_SELECT_APP:one byte select index 
 			MFSDK_EMV_MSG_ONLINE_PIN: nothing(If use external pinpad,need return the PIN str)
 			MFSDK_EMV_MSG_OFFLINE_PIN: nothing(If use external pinpad,need return the PIN str)
 			MFSDK_EMV_MSG_OFFLINE_PIN_RETRY_COUNT: NULL
 			MFSDK_EMV_MSG_SET_PUREAMT_BEFOREGPO: tlv hex data which need to reset:eg: "\x9F\x02\x06\x00\x00\x00\x00\x00\x01"
 * @param[in] Outlen: length of output parameters .
 * @return callback return: 
 * 			MFSDK_EMV_MSG_SELECT_APP: 0 success. Other fail
 			MFSDK_EMV_MSG_ONLINE_PIN: 0 success. -4:timeout. -7:CANCEL. -18:EMPTY.
 			MFSDK_EMV_MSG_OFFLINE_PIN: 0 success. -4:timeout. -7:CANCEL. -18:EMPTY.
 			MFSDK_EMV_MSG_OFFLINE_PIN_RETRY_COUNT: 0 success.
 			MFSDK_EMV_MSG_SET_PUREAMT_BEFOREGPO:0 success
 * 
 */
LIB_EXPORT void MfSdkEmvSetCallBackFunction(s32 (*callback)(s32 MsgType,u8* Indata,s32 InLen,u8* OutData,s32* Outlen)); 
/**
 * @brief
 * 
 * @param[in] lv_obj_t *parent
 * @param[in] void*pfunc
 * @param[in] MfSdkEmvReadCardIn_T *pCardIn
 * @param[out] MfSdkEmvReadCardOut_T *pCardOut
 * @return  lv_obj_t
 */
LIB_EXPORT lv_obj_t*MfSdkEmvReadCardPage(lv_obj_t *parent,void*pfunc,MfSdkEmvReadCardIn_T *pCardIn, MfSdkEmvReadCardOut_T *pCardOut);

/**
 * @brief Mutil App select
 * 
 * @param[in] MfSdkEmvSelecAppDisplay pFunc
 */
LIB_EXPORT void MfSdkEmvSetSelectAppCallback(MfSdkEmvSelecAppDisplay pFunc);

/**
 * @brief offline pin callback
 * 
 * @param[in] MfSdkEmvInputOffPin pFunc
 */
LIB_EXPORT void MfSdkEmvOfflinePinCallback(MfSdkEmvInputOffPin pFunc);
/**
 * @brief online pin callback
 * 
 * @param[in] MfSdkEmvInputOnlinePin pFunc
 */
LIB_EXPORT void MfSdkEmvOnlinePinCallback(MfSdkEmvInputOnlinePin pFunc);
/**
 * @brief
 * 
 * @param[in] MfSdkReadPage pFunc,display read card processing
 */
LIB_EXPORT void MfSdkEmvSetReadPageCallback(MfSdkReadPage pFunc);

/**
 * @brief
 * 
 * @param[in] MfSdkRuPay2ndPage pFunc, second tap UI 
 */
LIB_EXPORT void MfSdkEmvSetRuPay2ndTapCallback(MfSdkRuPay2ndPage pFunc);

/**
 * @brief
 * 
 * @param[in] MfSdkDpas2ndPage pFunc, second tap UI 
 */
LIB_EXPORT void MfSdkEmvSetDpas2ndTapCallback(MfSdkDpas2ndPage pFunc);

/**
 * @brief
 * 
 * @return EMV lvgl page handler
 */
LIB_EXPORT lv_obj_t* MfSdkEmvGetPageWin(void);

/**
 * @brief set contactless other data callback  * 
 */

LIB_EXPORT void MfSdkEmvSetPreprocessOtherDataCallback(MfSdkPreprocessSetOtherDataCb pFuncCallback);

LIB_EXPORT lv_obj_t* MfSdkEmvGetPageWinTip(void);

/**
 * @brief Get read card information
 *
 * @param[out] outBuf buff(>4096) ,ASCII format
 * @param[in] bufLen buff len.
 * 
 * @return >=0 , buff String length
 * @return <0 , fail
 */
LIB_EXPORT s32 MfSdkEmvGetProcInfo(s8* outBuf, s32 bufLen);

/**
 * @brief set amount before gpo
 * 
 */
LIB_EXPORT void MfSdkEmvCallbackEventSetAmtBeforeGpo(void);

/**
 * @brief
 * 
 * @return 0x01 or 0x00
 */
LIB_EXPORT s32 MfSdkEmvCallbackEventGetAmtBeforeGpo(void);

/**
 * @brief  clear emv callback event
 * 
 */
LIB_EXPORT void MfSdkEmvCallbackEventClear(void);

/**
 * @brief Get EMV(contact) kernel L2 cert version
 * 
 * @return EMV(contact) kernel L2 cert version 
 */
 
LIB_EXPORT char* MfSdkEmvGetEmvL2Version(void);

/**
 * @brief Get EMV(contact) kernel L2 cert kernel name
 * 
 * @return SR600mini : "MF_EMV_KERNEL"
 */
LIB_EXPORT char* MfSdkEmvGetEmvL2KernelName(void);

/**
 * @brief aid params init  ref. MfSdkEmvGetAidsFree
 * 
 * @return aids pointer
 */
LIB_EXPORT	void *MfSdkEmvGetAidsInit(void);

/**
 * @brief Get Aid tlv
 * 
 * @param[in] void *pTerminalApps
 * @param[in] s32 index , aid index  index must less than  MfSdkEmvGetAidNum();
 * @param[out] u8 *outAidsTlv ,  aid tlv out buffer
 * @param[in] s32 outAidsTlvLength, outAidsTlv size min value 1024
 * @return > 0 aid tlv length
 * @return other ref. MfSdkRet_E
 */
LIB_EXPORT s32 MfSdkEmvGetAid(void *pTerminalApps, s32 index , u8 *outAidsTlv,s32 outAidsTlvLength);

/**
 * @brief free aids param pointer
 * 
 * @param[in] void *pTerminalApps
 */
LIB_EXPORT void MfSdkEmvGetAidsFree(void *pTerminalApps);

	/**
	 * @brief
	 * 
	 * @param[in] u8* pBerTlvData
	 * @param[in] s32 length
	 * @return ref. MfSdkRet_E
	 */
LIB_EXPORT s32 MfSdkEmvSetTlv2Kernel(u8* pBerTlvData , s32 length);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

