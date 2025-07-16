#ifndef __PURE_API__
#define __PURE_API__

#include "emv_interface.h"
#include "funcp.h"
#ifdef __cplusplus
extern "C"{
#endif
#define PURE_RET_SUCC							0		
#define PURE_RET_TERMINAL						1		
#define PURE_RET_SELECT_NEXT					2		
#define PURE_RET_TRY_AGAIN						3		
#define PURE_RET_TRY_AGAIN_GAC6904_AND_MOBILE_CVM		4		
#define PURE_RET_GOTOTHER						5		
#define PURE_RET_GOTOTHER_MAG						6		
#define PURE_RET_STOP								7
typedef  enum
{
	PURE_MS_MODE,
	PURE_EMV_MODE,
}PURE_TRANS_MODE;


typedef  enum
{
	PURE_AAC = 1,
	PURE_ARQC,
	PURE_TC,
}PURE_CCID_MODE;

typedef  enum
{
    PURE_NONE,
	PURE_SDA,
	PURE_CDA,
	PURE_DDA,
}PURE_OFFLINE_CAM_MODE;

typedef enum
{
	PURE_SELECT_NEXT = 1,
	PURE_END_APP,
	PURE_END_APPLICATION_FOR_RETRIEVAL,
	PURE_END_APPLICATION_FOR_PUT_DATA,
	PURE_END_APPLICATION_FOR_OFFLINE_AUTH,
	PURE_APPROVED,
	PURE_DECLINE,	
	PURE_TRY_ANOTHER_INTERFACE,
	PURE_ONLINE_REQ_NONE_TAP,
	PURE_ONLINE_REQ_2ND_TAP,
	PURE_ONLINE_REQ_LONG_TAP,
	PURE_END_APPLICATION_FOR_CDCVM,
	PURE_END_APPLICATION_AFTER_ONLINE,
	PURE_TRY_AGAIN,
	PURE_END_APPLICATION_FOR_TRANS_CANCLE,
	PURE_APPROVED_AFTRE_SCRIPT,
	PURE_DECLINE_AFTRE_SCRIPT,
	PURE_END_APP_PRE_ERR,
	PURE_END_APP_DEFAULT,
}PURE_TRANS_RESULT;


typedef struct 
{
  char FCI[512];
  int FCIlen;
  char sz9F37[4+1];
  char szIAD[32+1];
  int IADlen;
  
}PURE_TORN_DATA;

#define PURE_NA_F0					0xF0
#define PURE_NA_FF					0xFF

//OPS Status B1
#define  EP_OPS_APPROVED     	(0x10)
#define  EP_OPS_DECLINED 	 	(0x20)
#define  EP_OPS_ONLINE_REQ 		(0x30)
#define  EP_OPS_END_APPLICATION (0x40)
#define  EP_OPS_SELECT_NEXT     (0x50)
#define  EP_OPS_TRY_ANOTHER_FACE (0x60)
#define  EP_OPS_TRY_AGAIN		 (0x70)
#define  EP_OPS_NA				 (0xF0)

//OPS Start  B2
 
#define EP_OPS_START_A   (0x00)
#define EP_OPS_START_B   (0x10)
#define EP_OPS_START_C   (0x20)
#define EP_OPS_START_D   (0x30)
#define EP_OPS_START_NA   (0xF0)


//OPS B3

#define EP_OPS_ONLINE_REQ_DATA_NA 	(0xF0)
#define EP_OPS_ONLINE_REQ_DATA_EMV  (0x00)
#define EP_OPS_ONLINE_REQ_DATA_MAG  (0x10)
#define EP_OPS_ONLINE_REQ_DATA_ANY  (0xFF)

//OPS B4

#define EP_OPS_CVM_NO_CVM    		(0x00)
#define EP_OPS_CVM_OBTAIN_SIGN    	(0x10)
#define EP_OPS_CVM_ONLINE_PAN	    (0x20)
#define EP_OPS_CVM_CONFIRMATION_CODE_VERIFIED    (0x30)
#define EP_OPS_CVM_NA    			(0xF0)

//OPS B5

//OPS b6

#define EP_OPS_ALT_INTERFACE_PRE  (0xF0)
#define EP_OPS_ALT_CONTACT_CHIP  (0xE0)

//OPS b7

#define EP_OPS_FILD_OFF_REQ  (0xFF)





#define UIRD_OUTCOME_FLAG  (0x80)
#define UIRD_RESTART_FLAG  (0x40)
#define DATA_RECORD_FLAG   (0x20)
#define DIS_DATA_FLAG  	   (0x10)
#define RECEIPT_FLAG 	   (0x08)


typedef struct PURE_OUTCOME
{
	unsigned char status;
	unsigned char Start;
	unsigned char Online_Prespond_Data;
	unsigned char cvm;
	unsigned char present;
	unsigned char Alternate_Interface;
	unsigned char Field_Off_Req;
	unsigned char Removal_Time;
  
}PURE_OUTCOME_PARAM;
typedef struct PURE_PRESENT
{
	unsigned char DataRecPresent;
	unsigned char OutComePresent;
	unsigned char DisDataPresent;
	unsigned char RESTARTPresent;
}PURE_PRESENT_FLAG;
typedef enum
{
	EN_DATAREC = 0,
	EN_OUTCOME,
	EN_DISDATA,
	EN_RESTRATE,
}EN_FLAG;


//uird B1
#define EP_UIRD_CARD_READ_OK 		(0x17)
#define EP_UIRD_TRY_AGAIN			(0x21)		//Present Card Again
#define EP_UIRD_APPROVED			(0x03)		//Approved
#define EP_UIRD_APPROVED_SIGN		(0x1A)		//Approved – Please Sign
#define EP_UIRD_DECILINE			(0x07)		//Not Authorized
#define EP_UIRD_ERR_OTHERCARD		(0x1C)		//Insert, Swipe or Try another card
#define EP_UIRD_INSERT_CARD			(0x1D)
#define EP_UIRD_SEE_PHONE			(0x20)			//See Phone for Instructions
#define EP_UIRD_AUTHORISINE_PLEASEWAIT	(0x1B)	//Authorizing Please Wait
#define EP_UIRD_CLEAR_DISPLAY		(0x1E)
#define EP_UIRD_NA					(0xFF)


#define EP_UIRD_PURE_PLEASE_ENTER_PIN				(0x09)		//Please Enter your PIN
#define EP_UIRD_PURE_PLEASE_REMOVE_CARD				(0x10)		//Please remove card
#define EP_UIRD_PURE_PLEASE_WELCOME					(0x14)
#define EP_UIRD_PURE_PLEASE_PRESENT_CARD			(0x15)
#define EP_UIRD_PURE_PLEASE_PROCESSING				(0x16)		//Processing
#define EP_UIRD_PURE_PLEASE_INSERT_OR_SWIPE_CARD	(0x18)		//Please insert or swipe card
#define EP_UIRD_PURE_PLEASE_PLEASE_ONE_CARD			(0x19)												

#define EP_UIRD_STATIC_NOT_READY				(0x00)
#define EP_UIRD_STATIC_IDLE						(0x01)
#define EP_UIRD_STATIC_READY_TO_READY			(0x02)
#define EP_UIRD_STATIC_PROCESSING				(0x03)
#define EP_UIRD_STATIC_CARD_READ_SUCC			(0x04)
#define EP_UIRD_STATIC_PROCESSING_ERR			(0x05)
#define EP_UIRD_STATIC_NA						(0xFF)


#define EP_UIRD_VQ_NONE				(0x00)
#define EP_UIRD_VQ_AMOUNT			(0x10)
#define EP_UIRD_VQ_BALANCE			(0x20)



typedef struct PURE_UIRD_STR
{
  unsigned char Message_ID;
  unsigned char Static;
  unsigned char HoldTime[3];
  unsigned char Language_Preference[8];
  unsigned char ValueQualifier;
  unsigned char Value[6];
  unsigned char CurrencyCode[2];
}PURE_UIRD;




#define TRANS_TYPE_AUTH_APPLI  	0x90
#define TRANS_TYPE_GET_DATA  	0x78
#define TRANS_TYPE_PUT_DATA  	0x79
#define PURE_SELECT_RET_NEXT		0x02

#define PURE_SEND_OPS                         0x01
#define PURE_SEND_RECORD                      0x02
#define PURE_SEND_DISCRE                      0x03
#define PURE_SEND_OUT_UIRD                    0x04
#define PURE_SEND_RESTART_UIRD				0x05
#define PURE_SEND_SEPARA_UIRD					0x06



#define CVM0_CON_CARDHOLDER_VERFICATION_METHOD   0x24  //pure 新增的CVM选项

LIB_EXPORT int PURE_Rf_PreProcess(STEMVPROC *stProc,int aidCount);
LIB_EXPORT int PURE_Compelte(STEMVPROC *stProc);
LIB_EXPORT int PURE_iTranFlow(STEMVPROC *stProc);
LIB_EXPORT int PURE_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);

LIB_EXPORT PURE_TRANS_MODE PURE_GetTranMode(void);

LIB_EXPORT void PURE_vSetBlackPAN_Support(int IsDRL_Support);
LIB_EXPORT int PURE_Term_SupportContactTranc(void);
LIB_EXPORT	 int PURE_select_cur_proflag(char *szTAG4f,int nlen);
LIB_EXPORT void pure_select_next();
LIB_EXPORT void PURE_Set_Trans_Reslut(int st_pure_trans_result);

#define PURE_DBG 		Debug_fprintf
#define PURE_DBG_HEX 	DebugPrintBuf
#define PURE_DBG_TLV 	DebugPrintTlv

#ifdef __cplusplus
}
#endif
#endif

