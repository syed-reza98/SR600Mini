#pragma once
#include "libapi_xpos/inc/libapi_pub.h"
#include "libapi_xpos/inc/def.h"
#include "lvgl/lvgl.h"
/**
 * @file emvapi.h
 * @author chenyue(Ronaldo)
 * @brief reference to emvapi
 * @date 2023-05-22
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#define MODE_API_UNKNOW			0x00			///< unknown api mode
#define	MODE_API_PBOC			0x01			///< pboc
#define MODE_API_VCPS			0x02			///< vcps
#define MODE_API_QPBOC			MODE_API_VCPS	///< qpboc
#define MODE_API_MSD			0x04			///< msd
//#define MODE_API_PBOC_EC		0x10		
//#define	MODE_API_RF				0x20	
//#define	MODE_API_DPAS			0x30		
#define	MODE_API_AMEX			0x40	///< AMEX	
#define MODE_API_M_CHIP			0x21	///< MasterCard CHIP mode
#define MODE_API_M_STRIPE		0x22	///< MasterCard MagStripe mode
#define MODE_API_R_LEGACY		0x23	///< RUPAY LEGACY mode
#define MODE_API_R_NON_LEGACY	0x24	///< RUPAY NON LEGACY mode
#define MODE_API_EMV_MODE		0x25	///< EMV_MODE 	(for AMEX)
#define MODE_API_MS_MODE		0x26	///< MS_MODE	(for AMEX)
#define MODE_API_MOBILE_MODE		0x27	///< mobile_MODE	(for amex)

//card_type value of card_out
enum {
	READ_CARD_RET_CANCEL,		///< cancel
	READ_CARD_RET_MAGNETIC,		///< msd
	READ_CARD_RET_IC,			///< ic
	READ_CARD_RET_RF,			///< rf
	READ_CARD_RET_TIMEOVER,		///< timeout
	READ_CARD_RET_FAIL			///< failure
};

//card_mode of card_in
enum {
	READ_CARD_MODE_MAG = 0x01,	///< magstripe
	READ_CARD_MODE_IC = 0x02,	///< ic
	READ_CARD_MODE_RF = 0x04	///< rf
};
//emv_card_end : ret input
enum {
	EMVCARD_RET_QUIT,		///< quit
	EMVCARD_RET_INPUT,		///< input
	EMVCARD_RET_MAGTEK,		///< magstripe card
	EMVCARD_RET_ICC,		///< ICC
	EMVCARD_RET_RFID,		///< RF
	EMVCARD_RET_TIME_OVER,	// timeout
	EMVCARD_RET_RFS,		///< two or more RF card
};

enum {
	EMV_CODE_SUCC = 0,
	EMV_CODE_NO_APP = 1,					///< icc card without any application available
	EMV_CODE_ERR_POWERUP = 2,				///< card not responding or chip not present
	EMV_CODE_CAPK_NOFOUND = 3,				///< card CAPK not found
	EMV_CODE_APDU_NORETURN = 4,				///< APDU not returned
	EMV_CODE_APP_BLOCK = 5,					///< app block
	EMV_CODE_CARD_BLOCK = 6,				///< card block
	EMV_CODE_RFID_PRE_AMTLIMIT = 7,			///< amount substantially transaction limit(RFID)
	EMV_CODE_RFID_NO_APP = 8,				///< rfid card without any application available
	EMV_CODE_AP_SP_COMM_ERR = 9,			///< ap and sp communication timeout
	EMV_CODE_SW_NOT_9000,					///< sw of apdu is not 9000
	EMV_CODE_PAGE_TIMEOUT,					///< emv page timeout
	EMV_CODE_ICC_MOVE,						///< IC card was moved

	EMV_CODE_OTHER = 99,					///< other err
};

#define EMVAPI_RET_TC	 	0				///< TC Approval
#define EMVAPI_RET_ARQC	 	1				///< Request Online
#define EMVAPI_RET_AAC	 	-11				///< Transaction rejection
#define EMVAPI_RET_AAR	 	-2				///< Termination of transaction
#define EMVAPI_RET_CANCEL	-3				///< User Cancel
#define EMVAPI_RET_TIMEOUT	-4				///< Transaction timeout
#define EMVAPI_RET_FORCEIC	-5				///< Transaction force IC
#define EMVAPI_RET_OTHER	-6				///< Contactless turn to other interface
#define EMVAPI_RET_FALLBACk	-7				///< Fallback
#define EMVAPI_RET_SEEPHONE -8				///< visa "See Phone and Retry"
#define EMVAPI_RET_CARDAPP_BLOCK	-9		///< app block
#define EMVAPI_RET_CARDA_BLOCK	-10			///< card block
#define EMVAPI_RET_CARD_NO_APP		-12		///< card without any application available
#define EMVAPI_RET_CARD_ERR_POWERUP	-13		///< card not responding or chip not present
#define EMVAPI_RET_CARD_INVDATA		-14		///< card behaves correctly but has invalid or inconsistent data.
#define EMVAPI_RET_CARD_APPNAUT		-15		///< card returned error 6985
#define EMVAPI_RET_CARD_CAPK_NOFOUND -16	///< card CAPK not found
#define EMVAPI_RET_CARD_APDU_NORETURN -17	///< APDU not returned
#define EMVAPI_RET_KERNEL_NOT_SUPPORT	-18		//
#define EMVAPI_RET_CARD_HAVEPROBLEMS  -1	///< the card does not behave as expected and the transaction be terminated

#define EMVAPI_RET_AMTLIMIT  (-19)  		///<Contactless transaction amout more than or equal transaction limit amount
#define EMVAPI_RET_RETRY	 (-20) 			///<RF RETRY

#define EMVAPI_RET_SUCC		0				///< process success
typedef struct __st_read_card_in {
	char title[32];		///< title of card reading pages
	int trans_type;		///< Transaction Type refer DE3.1(ISO 8583). example 0x00 as SALE;
	char amt[32];		///< Amount 9F02
	char other_amt[32];	///< Cash back Amount 9F03
	int card_mode;		///< READ_CARD_MODE_MAG , READ_CARD_MODE_IC , READ_CARD_MODE_RF
	int card_timeover;	///< Time over of  card reading page,normally 60000;
	int pin_input;		///< 0x01: enter the PIN interface according to the emv_read_card internal; 0x02:forces the PIN interface  of online transactions; 0x03:force pin; 0x00: will not require pin processing in emv_read_card
	int mag_mode;		///< For magnetic stripe cards. 0x01: The application determines whether to enter the PIN interface according to the service_code; 0x00:require a PIN from emv_read_card internal
	int pin_min_len;	///< min length of pin 
	int pin_max_len;	///< max length of PIN,range 4-12
	int pin_timeover;	///< Time over of PIN inputting page,normally 60000;
	int key_pid;		///< SEC_DUKPT_FIELD,SEC_MKSK_FIELD,SEC_FIXED_FIELD,SEC_AES_FIELD
	int pin_dukpt_gid;	///< group ID of DUKPT mode, used for PIN encryption; gid<0 means not support;
	int des_mode;		///< DES_MODE_ECB,DES_MODE_CBC
	int data_dukpt_gid;	///< group ID of DUKPT mode, used for track or account data encryption; gid<0 means not support;
	int pin_mksk_gid;	///< group ID of MKSK mode, used for PIN encryption; gid<0 means not support;
	int forceIC;		///< 0x00:not forced chip read priority; 0x01:chip card takes priority over magnetic stripe
	int show_PAN;		///< 0x00:not show PAN during card reading; 0x01:show PAN during card reading; 0x02 show section PAN during card reading;
	int bByPassPin;		///< 0x00  NotSupport ByPassPin	0x01 Support ByPassPin
	char ic_tags[256];	///< ASCII code; TAGs need get value from card reading; example:9F0282...;NULL value, will get default TAG list
	char card_page_msg[50];		///< Message of card reading page
	int ic_online_resp;			///< 0:not support; 1:chip card reading support online response processing
	int ic_offline_free_sign;	///< 0--default(The SDK automatically releases EMV data internally)  1--App development manually releases EMV resources
	int nTransSerial_9f41;		///< Transcation Sequence Counter of chip card reading
	int pin_format;				///< refer to SEC_PIN_FORMAX in libapi_security.h
	char sDccCurrency[2];		///< DCC Currency
	char iAidStoreSign;			///< 0--default(Public storage)  1--Separate storage of contact and contactless AID
	int force_online_flag;		///< 0:no forced online; 1:forced online(TVR) 2:foced online (request ARQC in case of TC)
	char force_aac;				///< 0---cannot forceAAC   1---Force return AAC 
	char forceOutIcData;		///< 0---cannot force out ic data   1---Force pack out ic data(st_read_card_out.ic_data)
	unsigned int track_format;	///< Track data encryption format. 0---normal   1---SBI encryption format 
}st_read_card_in;

#define TRACK_MAX_LENTH		144
typedef struct __st_read_card_out {
	int card_type;			///< 0x01 READ_CARD_RET_MAGNETIC 0x02 READ_CARD_RET_IC 0x03 READ_CARD_RET_RF,  
	char exp_data[8];		///< Expiration Date of card
	char ic_data[1024];		///< HEX code, TLV data of card_in.ic_tags
	int ic_data_len;		///< Length of ic_data
	char pan[32];			///< PAN of card
	char pan_sn[8];			///< 5F34 PAN Sequence Number,DE23(ISO 8583)
	char pin_block[32];		///< PINBLOCK
	char pin_ksn[10];		///< KSN of PIN encryption KEY in DUKPT mode
	char data_ksn[10];		///< KSN of track or account data encryption KEY in DUKPT mode
	int  pin_len;			///< Length of online PIN plaintext, return 0 when bypass PIN
	char track2[TRACK_MAX_LENTH];	///< plaintext of track2 when data_dukpt_gid<0; encryption track2 when data_dukpt_gid>=0
	int track2_len;					///< length of track2
	char track3[TRACK_MAX_LENTH];	///< plaintext of track3 when data_dukpt_gid<0; encryption track3 when data_dukpt_gid>=0
	int track3_len;					///< length of track3
	char vChName[45 + 1];			///< Card holder Name
	int nEmvMode;					///< refer to MODE_API_XX
	char signature_flag;			///< 0x01 Need signature;0x00 No signature
	char service_code[3 + 1];		///< service code of card
	int nNFCType;					///< NFC type;0:card type; non-0:mobile or other type;
	int emvCode;					///< emv kernel error code
	int nClsCVMflag;				///< contactless cvm method : 0x02->onlinepin  0x03->signiture 0x05->On device cardholder verification
	char track1[TRACK_MAX_LENTH];//plaintext of track1 when data_dukpt_gid<0; encryption track1 when data_dukpt_gid>=0;
	int track1_len;		//length of track1
}st_read_card_out;
#define  UMAX_RUPAY_SERVICE_COUNT   20		//The maximum number of service supported by card terminals
#define  UMAX_RUPAY_PRMACQKEY_COUNT	20		//The maximum number of service prmacqkey supported by card terminals
//RUPAYSERVICE  structure
typedef struct
{
	char ucServiceId[2];		 //service id
	char auServiceQualifier[5];	 //service qualifier
	char auServiceData[96];      //service data
	int iServiceLen;			 //service data length
}RUPAYSERVICEDATA;


//RUPAYSERVICELIST structure
typedef struct
{
	char bServiceCount;	//number of rupay service
	RUPAYSERVICEDATA ServiceData[UMAX_RUPAY_SERVICE_COUNT];
}RUPAYSERVICELIST;

//RUPAYPRMACQKEY structure
typedef struct
{
	char ucServiceId[2];		//service id
	char ucPRMacqKeyIndex;		//service PRMacqKey Index
	char ucPRMacqKey[16];		//service PRMacqKey
	char ucPRMacqKeyLen;		//service PRMacqKey length
	char ucPRMacqKCV[3];		//service PRMacqKCV
}RUPAYPRMACQKEY;
//RUPAYPRMACQKEYLIST  structure
typedef struct
{
	char bPRMacqKeyCount;	//number of rupay PRMacqKey
	RUPAYPRMACQKEY PRMacqKey[UMAX_RUPAY_PRMACQKEY_COUNT];
}RUPAYPRMACQKEYLIST;

/**
 * @brief
 * 
 * @return  emv page handler
 */
LIB_EXPORT lv_obj_t* emv_get_page_win();

/**
 * @brief lvgl read card page
 * 
 * @param[in] parent lvgl parent obj
 * @param[in] pfunc The callback function at the end of the read card
 * @param[in] card_in input card info
 * @param[in] card_out output card info
 * @return lvgl pagewin 
 */
LIB_EXPORT lv_obj_t* emv_read_card_page(lv_obj_t* parent, void*  pfunc, st_read_card_in* card_in, st_read_card_out* card_out);

#define SUCC 0
#define FAIL (-1)

/**
 * @brief Init EMV relate data and file
 * 
 */
LIB_EXPORT void EMV_iKernelInit(void);

/**
 * @brief Init EMV terminal parameter
 * 
 * @param[in] ptermconfig input terminal parameter
 * @return 0,success
 * @return other,fail
 */
LIB_EXPORT int EMV_TermConfigInit(TERMCONFIG* ptermconfig);

/**
 * @brief Clear AID parameter File
 * 
 * @return 0,success
 * @return other,fail
 */
LIB_EXPORT int EMV_PrmClearAIDPrmFile(void);

/**
 * @brief Set AID parameter 
 * 
 * @param[in] pTerminalApps input  AID parameter 
 * @return 0,success
 * @return other,fail
 */
LIB_EXPORT int EMV_PrmSetAIDPrm(TERMINALAPPLIST* pTerminalApps);

/**
 * @brief set display app list callbacn function
 * 
 * @param[in] SelecAppDisplay  ,nAidNum:aid number,select_choic:select the list
 * @param[in] SelecAppDisplay stICCAID:aid list
 * @param[in] SelecAppDisplay nAidNum:aid number
 * @param[in] SelecAppDisplay select_choic:select the list
 * @param[out] SelecAppDisplay return 0,success; -17:timeout; -7:cancel
 * @return Nothing
 */
LIB_EXPORT void EMV_SetSelectAppCallback(int (*SelecAppDisplay)(AID_STRU *stICCAID,int nAidNum,int *select_choic));

/**
 * @brief set input offline pin callback function
 * 
 * @param[in] InputOffPin psCardNo Card number
 * @param[in] InputOffPin psAmt amount
 * @param[in] InputOffPin cMsgType:0x01-last pin 0x02-again pin 0x03-first pin
 * @param[out] InputOffPin psPin:(Entered password) 
 * @param[out] InputOffPin return length of pin:SUCC;-4:timeout; -7:CANCEL; -18:EMPTY;  
 * @return Nothing
 */
LIB_EXPORT void EMV_OfflinePinCallback(int (*InputOffPin)(char *psCardNo,char *psAmt,char cMsgType,char *psPin));

/**
 * @brief Set the onine PIN interface
 * 
 * @param[in] InputOnlinePin (char *psCardNo,char *psAmt,char *psPin)//Enter password interface function pointer
 * @param[in] InputOnlinePin char *psCardNo   (PAN)
 * @param[in] InputOnlinePin char *psAmt      (Amount)
 * @param[out] InputOnlinePin char *psPin      (Entered password)
 * @param[out] InputOnlinePin 0:SUCC;	  -4:timeout; -7:CANCEL; -18:EMPTY;  
 * @return Nothing
 */
LIB_EXPORT void EMV_OnlinePinCallback(int (*InputOnlinePin)(char *psCardNo,char *psAmt,char *psPin));

/**
 * @brief offline pin retry Count
 * 
 * @param[in] DispOffPin nRetryCount : 0 -SUCCESS   1-last Retry >2- try again   -1:pin is block
 * @param[out] DispOffPin char *psPin      (Entered password)
 * @return Nothing
 */
LIB_EXPORT void EMV_SetDispOffPin(void (*DispOffPin)(int nRetryCount));

/**
 * @brief prepare to read card
 * 
 * @param[in] card_in input card info
 * @return 0,success
 * @return other,fail
 */
LIB_EXPORT int emv_card_begin(st_read_card_in *card_in);

/**
 * @brief set input offline pin callback function
 * 
 * @param[in] InputOffPin psCardNo Card number
 * @param[in] InputOffPin psAmt amount
 * @param[in] InputOffPin cMsgType:0x01-last pin 0x02-again pin 0x03-first pin
 * @param[out] InputOffPin return length of pin:SUCC;-4:timeout; -7:CANCEL; -18:EMPTY;
 * @return Nothing
 * @details need be used with the sec_set_pin_mode function
 */
LIB_EXPORT void EMV_OfflinePinCallbackEx(int (*InputOffPin)(char* psCardNo, char* psAmt, char cMsgType));

/**
 * @brief Set the onine PIN interface
 *
 * @param[in] InputOnlinePin (char *psCardNo,char *psAmt,char *psPin)//Enter password interface function pointer
 * @param[in] InputOnlinePin char *psCardNo   (PAN)
 * @param[in] InputOnlinePin char *psAmt      (Amount)
 * @param[out] InputOnlinePin 0:SUCC;  -4:timeout; -7:CANCEL; -18:EMPTY;
 * @return Nothing
 * @details need be used with the sec_set_pin_mode function
 */
LIB_EXPORT void EMV_OnlinePinCallbackEx(int (*InputOnlinePin)(char* psCardNo, char* psAmt));
/**
 * @brief detection card by a loop
 * 
 * @param[in] card_mode card_mode: 0x01:mag , 0x02:IC,0x04:RF , 0x07:all
 * @param[out] trackInfo card_magtek_track_info:Track message, swipe card data
 * @param[in] timeout timeout(The unit is s)
 * @return card_type 
 * @return 1, ms card
 * @return 2,icc 
 * @return 3,rfid 
 * @return -2,cancel
 * @return -3,timeout
  * @return -4,Multiple cards
 * @return Other,fail 
 */
LIB_EXPORT int emv_card_loop(int card_mode, card_magtek_track_info* trackInfo, int timeout);

/**
 * @brief kernel process
 * 
 * @param[in] ret card_type
 * @param[in] card_in the same value as emv_card_begin
 * @param[out] card_out IC data and pinblock . refer to st_read_card_out struct
 * @return 0, EMVAPI_RET_TC			//TC
 * @return 1, EMVAPI_RET_ARQC		//ARQC
 * @return -1, EMVAPI_RET_AAC		//AAC
 * @return -2, EMVAPI_RET_AAR		//Terminate
 * @return -3, EMVAPI_RET_CANCEL	//Cancel 
 */
LIB_EXPORT int emv_card_end( int ret, st_read_card_in *card_in,st_read_card_out *card_out);

/**
 * @brief contact transaction  will stop after read app data . contactless and MAGTEK transaction will complete whole transaction
 * 
 * @param[in] ret cardType: EMVCARD_RET_ICC or EMVCARD_RET_RFID
 * @param[in] card_in the parameter of EMV trans
 * @param[out] card_out card_out out buffer of EMV trans
 * @return 0, EMVAPI_RET_TC			//TC
 * @return 1, EMVAPI_RET_ARQC		//ARQC
 * @return -1, EMVAPI_RET_AAC		//AAC
 * @return -2, EMVAPI_RET_AAR		//Terminate
 * @return -3, EMVAPI_RET_CANCEL	//Cancel 
 */
LIB_EXPORT int emv_get_card(int ret, st_read_card_in *card_in,st_read_card_out *card_out);

/**
 * @brief Only for contact . continue to Chip flow 
 * 
 * @param[in] ret cardType: EMVCARD_RET_ICC or EMVCARD_RET_RFID
 * @param[in] card_in the parameter of EMV trans
 * @param[out] card_out ut buffer of EMV trans
 * @return 0, EMVAPI_RET_TC			//TC
 * @return 1, EMVAPI_RET_ARQC		//ARQC
 * @return -1, EMVAPI_RET_AAC		//AAC
 * @return -2, EMVAPI_RET_AAR		//Terminate
 * @return -3, EMVAPI_RET_CANCEL	//Cancel 
 */
LIB_EXPORT int emv_GoOnChip(int ret, st_read_card_in *card_in,st_read_card_out *card_out);

/**
 * @brief get emv status
 * 
 * @param[in] emv_status callback function
 * @param[out] emv_status nStatus:1-Select app 2-GetProcessingOptions 3-read app data 4-Offline data authentication 
 * @param[out] emv_status nStatus:5-Process_Restricty 6-CARD HOLDER VERIFY 7- risk manage
 * @param[out] emv_status nStatus:8-Generate action analy  9-transaction complete
 * @return Nothing
 */
LIB_EXPORT void EMV_StatusCallback(int (*emv_status)(int nStatus));
LIB_EXPORT void EMV_EmvEndCallback(int (*BeforePinCallBack)(void));
/**
 * @brief Get all aid into memory
 * 
 * @param[out] pTerminalApps The AID buffer
 * @return 0, UEMV_PRM_OK
 * @return -3,UEMV_PRM_NOT_FOUND
 * @return other,UEMV_PRM_FAIL
 */
LIB_EXPORT int EMV_PrmGetAIDPrm(TERMINALAPPLIST *pTerminalApps);

/**
 * @brief Delete the specific AID
 * 
 * @param[in] AID AID
 * @param[in] AID_Len AID_Len
 * @return 0,UEMV_PRM_OK
 * @return -3,UEMV_PRM_NOT_FOUND
 * @return other,UEMV_PRM_FAIL
 */
LIB_EXPORT int EMV_PrmDelAIDPrm(byte *AID, byte AID_Len);

/**********************************capk part**************************************/

/**
 * @brief Save CAPK into device
 * 
 * @param[in] ppkKey The CAPK buffer
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 * @return -2, UEMV_PRM_CAPK_CHK_HASH_FAIL
 * @return -8, UEMV_PRM_ERR
 */
LIB_EXPORT int EMV_PrmSetCAPK(CAPUBLICKEY *ppkKey);

/**
 * @brief Get the specific index of CAPK
 * 
 * @param[out] ppkKey CAPK buffer
 * @param[in] RID RID of CAPK
 * @param[in] PKIndex Index of CAPK
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 * @return -3, UEMV_PRM_NOT_FOUND
 */
LIB_EXPORT int EMV_PrmGetCAPK(CAPUBLICKEY *ppkKey, byte *RID, byte PKIndex);

/**
 * @brief Delete the specific index of CAPK
 * 
 * @param[in] RID RID of CAPK
 * @param[in] PKIndex Index of CAPK	
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 * @return -3, UEMV_PRM_NOT_FOUND
 */
LIB_EXPORT int EMV_PrmDelCAPK(byte *RID, byte PKIndex);

/**
 * @brief Clear all CAPK from device
 * 
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 */
LIB_EXPORT int EMV_PrmClearCAPKFile(void);

/**
 * @brief Getting the specified tag value from the resource data
 * 
 * @param[in] psTag Afferent tag 
 * @param[in] psSrc Resource data
 * @param[in] nSrcLen Resource data length
 * @param[out] psBuf Returns the tag value
 * @param[out] nBufLen Returns the length of the tag value
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 */
LIB_EXPORT int EMV_GetDataByTag(byte *psTag, byte *psSrc, int nSrcLen,byte *psBuf, int *nBufLen);

/**
 * @brief Process of pack emv tag
 * 
 * @param[in] pTagName tag name
 * @param[in] TagValue tag value 
 * @param[in] iTagValueLen tag value length
 * @param[out] psBuf Returns TLV packed data
 * @param[out] nBufLen Returns length of packed data
 * @return 0, UEMV_PRM_OK
 * @return other, UEMV_PRM_FAIL
 */
LIB_EXPORT int EMV_PackTLVData(byte *pTagName,byte *TagValue, int iTagValueLen, byte *psBuf,int *nBufLen);

/**
 * @brief Set TLV for EMV 
 * 
 * @param[in] Tag TAG
 * @param[out] Len Length
 * @param[out] Value Value buffer
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 * @return -3, UEMV_PRM_NOT_FOUND
 */
LIB_EXPORT int EMV_GetKernelData (char *Tag, int *Len, byte *Value);

/**
 * @brief Set TLV from EMV buffer
 *
 * @param[in] pszTag TAG
 * @param[in] pszData Value buffer
 * @param[in] nLen Length
 * @param[in] bOverride 1,override tlv;0,no override
 * @return 0, UEMV_PRM_OK
 * @return Other, UEMV_PRM_FAIL
 */
LIB_EXPORT int EMV_SaveKernelData(char* pszTag, char* pszData, int nLen, int bOverride);

/**
 * @brief clear drl file in device
 * 
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 */
LIB_EXPORT int EMV_PrmClearDRLFile(void);

/**
 * @brief Set drl buffer into device
 * 
 * @param[in] stDRL drl buffer
 * @return 0, UEMV_PRM_OK
 * @return -1, UEMV_PRM_FAIL
 * @return -8, UEMV_PRM_ERR //Wrong parameter
 */
LIB_EXPORT int EMV_PrmSetDRL(TERMDRL stDRL);

/**
 * @brief Match error code
 * 
 * @param[in] iErrcode Error code
 * @return 1,Match 
 * @return 0,no Match 
 */
LIB_EXPORT unsigned int EMV_MatchErrCode(unsigned int iErrcode);

/**
 * @brief Process of emv online resp proc and pack tlv data
 * 
 * @param[in] nOnlineRes 0--online success(Any return in the server is success)  -1--online fail  
 * @param[in] sResp39 Online Response Code
 * @param[in] sField55 ASCC code;contain 91/8A/71/72 Tag Data
 * @param[in] emvtags ASCC code;the tags want to get
 * @param[out] packvalue HEX code,the tlv data match emvtags 
 * @param[out] packlen length of packvalue
 * @return 	0,EMVAPI_RET_TC	 	 //TC
 * @return	-1,EMVAPI_RET_AAC	 //AAC
 * @return	-2,EMVAPI_RET_AAR	 //Terminate 
 * @note Don't need to call EMV_online_cardemv_free() 
 */
LIB_EXPORT int emv_onlineresp_proc_pack(int nOnlineRes,char *sResp39,char *sField55,char*emvtags, char*packvalue,int*packlen);
LIB_EXPORT int emv_online_resp_proc(int nOnlineRes,char *sResp39,char *sField55,int nFieldLen);

/**
 * @brief Release EMV data based on card reading status
 * 
 * @return Nothing
 * @deprecated  Recommended use EMV_card_free
 */
LIB_EXPORT void EMV_online_cardemv_free(void);

/**
 * @brief Release EMV data 
 *
 * @param[in] type READ_CARD_RET_IC:free icc card data; READ_CARD_RET_RF:free rfid card data
 * @return 	0,free success
 * @return	Other,free fail
 */
LIB_EXPORT int EMV_card_free(int type);
/**
 * @brief Process online pin entering and output encrypted PIN block
 * 
 * @param[in] key_pid SEC_MKSK_FIELD,SEC_DUKPT_FIELD;refer to libapi_security.h
 * @param[in] pin_gid index of key;match with key_pid
 * @param[in] amt amount
 * @param[in] pan pan of this transaction
 * @param[out] pin_len length of pin
 * @param[out] pin_ksn ksn of KF_DUKPT mode;
 * @param[out] pin_block  encrypted PIN
 * @return 		0,EMVAPI_RET_SUCC
 * @return 		-4,EMVAPI_RET_TIMEOUT	 
 * @return 		-3,EMVAPI_RET_CANCEL	 
 */
LIB_EXPORT int emvapi_onlinpin_proc_page(int key_pid,int pin_gid,char*amt,char *pan, int*pin_len,char*pin_ksn, char*pin_block);

/**
 * @brief Add card Blacklist
 * 
 * @param[in] BlackCard Black card info
 * @param[in] cCoverFlag 1,override tlv;0,no override
 * @return 	0,success
 * @return 	Other,fail
 */
LIB_EXPORT int EMV_add_card_blacklist(BlackCard stBlackCard, int cCoverFlag);

/**
 * @brief Delete card Blacklist
 *
 * @param[in] BlackCard Black card info
 * @return 	0,success
 * @return 	Other,fail
 */
LIB_EXPORT int EMV_del_add_card_blacklist(BlackCard stBlackCard);
/**
 * @brief EMV version
 *
 * @param[out] pszVersion: version
 */
LIB_EXPORT void  EMV_GetVersion(char *pszVersion);
/**
 * @brief entry version
 *
 * @param[out] pszVersion: version
 */
LIB_EXPORT void  EMV_GetEntryVersion(char *pszVersion);
/**
 * @brief contactless version
 *
 * @param[in] KernelType 0-unionPay 1-VISA 2-mastercard 3-AMEX 4-DPAS 5-RUPAY,
 * @param[out] pszVersion version
 */
LIB_EXPORT void EMV_GetContactlessVersion(int KernelType,char *pszVersion);

/**
 * @brief get aid num
 *
 * @param[out] nNum aid num
 */
LIB_EXPORT void Emv_GetAID_Num(int* nNum);

/**
 * @brief get aid parameter
 *
 * @param[in] index aid index
 * @param[out] buf aid parameter
 * @return 	0,success
 * @return 	Other,fail
 */
LIB_EXPORT int EMV_GetAID_Prm(int index, char* buf);


typedef int (*page_close_page_func)(int ret, lv_obj_t* obj);

LIB_EXPORT lv_obj_t* emv_get_page_win();


LIB_EXPORT long long get_emv_other_amnt();

LIB_EXPORT lv_obj_t* emv_get_page_win_tip();

LIB_EXPORT int getReadCardTick();
LIB_EXPORT void setReadCardTick(int tick);
LIB_EXPORT int getReadCardEndTick();
LIB_EXPORT void setReadCardEndTick(int tick);
/**
 * @brief set amount before gpo
 * 
 */
LIB_EXPORT void Emv_CallbackEventSetAmtBeforeGpo(void);

/**
 * @brief
 * 
 * @return 0x01 or 0x00
 */
LIB_EXPORT int Emv_CallbackEventGetAmtBeforeGpo(void);

/**
 * @brief  clear emv callback event
 * 
 */
LIB_EXPORT void Emv_CallbackEventClear(void);

