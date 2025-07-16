#ifndef __RF_MIR_LOCAL_API__
#define __RF_MIR_LOCAL_API__

#include "define.h"
#include "data.h"
#include "emv_interface.h"
#include "emv_tag.h"
#include "funcp.h"
#include "tvrtsiaip.h"

typedef struct tagDATE_TIME_T
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}MIR_DATE_TIME;

/*******************Transaction Outcomes interface***************/
#define MIR_OP_S_APPROVED                    0x0010
#define MIR_OP_S_DECLINED                    0x0020
#define MIR_OP_S_ONLINE_REQ                  0x0030
#define MIR_OP_S_END                         0x0040
#define MIR_OP_S_SELECT_NEXT                 0x0050
#define MIR_OP_S_TRY_OTH_IFC                 0x0060
#define MIR_OP_S_TRY_AGAIN                   0x0070
#define MIR_OP_S_TWO_PRESENT				 0x0080

#define MIR_OP_START_A					  		0x0100
#define MIR_OP_START_B							0x0110
#define MIR_OP_START_C							0x0120
#define MIR_OP_START_D							0x0130
#define	MIR_OP_START_NA						0x01F0

#define MIR_ORD_EMVDATA						0x0210
#define MIR_ORD_ANY							0x0220
#define MIR_ORD_NA								0x02F0

#define MIR_OP_CVM_NOCVM                     0x0300
#define MIR_OP_CVM_SIGNATURE                 0x0310
#define MIR_OP_CVM_ONLINE_PIN                0x0320
#define MIR_OP_CVM_CCV                       0x0330
#define MIR_OP_CVM_SKIP_CVM					 0x0340
#define MIR_OP_CVM_FAIL_CVM					 0x0350
#define MIR_IP_CVM_NA						 0x03F0

#define MIR_OP_FLAG_UI_OUTCOME               0x0480
#define MIR_OP_FLAG_UI_RESTART               0x0440
#define MIR_OP_FLAG_DATA_RECORD              0x0420
#define MIR_OP_FLAG_DISCRETIONARY            0x0410
#define MIR_OP_FLAG_RECEIPT                  0x0408

#define MIR_OP_AIP_CONTACT					0x0510
#define MIR_OP_AIP_NA						0x05FF


#define MIR_SEND_OPS                         0x01
#define MIR_SEND_RECORD                      0x02
#define MIR_SEND_DISCRE                      0x03
#define MIR_SEND_OUT_UIRD                    0x04

#define MIR_UI_M_CARD_READ_OK				 "\x17"
#define MIR_UI_M_TRY_AGAIN					 "\x21"
#define MIR_UI_M_APPROVED					 "\x03"
#define MIR_UI_M_APPROVED_SIGN			 	 "\x1A"
#define MIR_UI_M_DECLINED				     "\x07"
#define MIR_UI_M_ERR_OTH_CARD			     "\x1C"
#define MIR_UI_M_INSERT_CARD				 "\x1D"
#define MIR_UI_M_SEE_PHONE					 "\x20"
#define MIR_UI_M_AUTH_WAIT					 "\x1B"
#define MIR_UI_M_CLEAR_DISPLAY				 "\x1E"

#define MIR_UI_M_NA						"\xFF"
#define MIR_UI_M_AUTHORPIN					 "\x09"
#define MIR_UI_M_CARDREADOK_REMOVE			 "\x18"

#define MIR_UI_MSG_ID                        0x01
#define MIR_UI_STATUS                        0x02
#define MIR_UI_HOLD_TIME                     0x03
#define MIR_UI_LANGUAGE_PRE                  0x04
#define MIR_UI_VALUE_QUAL                    0x05
#define MIR_UI_VALUE                         0x06
#define MIR_UI_CURRENCY_CODE                 0x07

#define MIR_UI_V_NONE                        "\x00"
#define MIR_UI_V_AMOUNT                      "\x10"
#define MIR_UI_V_BALANCE                     "\x20"

#define MIR_UI_S_NOT_READY                   "\x00"
#define MIR_UI_S_IDLE                        "\x01"
#define MIR_UI_S_READY_TO_READ               "\x02"
#define MIR_UI_S_PROCESSING                  "\x03"
#define MIR_UI_S_CARD_READ_SUCC              "\x04"
#define MIR_UI_S_PROCESS_ERR                 "\x05"


int MIR_iTransFlow_Protocol_02(STEMVPROC* stProc);
int MIR_iTransFlow_Protocol_01(STEMVPROC* stProc);
int MIR_iTransFlow(STEMVPROC* stProc);


/****************交易步骤************************/
int MIR_iPerformTransaction(char* pRespData, int* nDataLen);
int MIR_iCompleteTransaction(char* pRespData, int* nDataLen);
int MIR_iInitApp();
int MIR_iReadRecord();
int Mir_iFindCAPK(void);
int MIR_OffAuth_CDA_First();
int MIR_OffAuth_Protocol_02(char* pszGACData, int nDataLen, STEMVPROC* stProc);
int CDA_AC_MIR(char *pszGacRes, int nGacLen);
int CDA_AC_MIR_02(char *pszPtrRes, int nPtrLen);
int MIR_CdaCheck();
int MIR_Process_Restrict();
int MIR_Process_Restrict_Protocol_02();
int MIR_CardHolderVerify(STEMVPROC *stProc,int *piCvmFlag);
int MIR_CardHolderVerify_Protocol_02(STEMVPROC* stProc, int* piCvmFlag);
int MIR_risk_mana();
int MIR_term_act_analy(E_GAC *pTermAcType);
int MIR_card_act_analy(E_GAC eGacType,STEMVPROC *stProc);
int MIR_card_act_analy_protocol_02(char* pszGACData, int nDataLen, STEMVPROC* stProc);


/****************常用接口************************/
int MIR_iSupportOdv(void);
int MIR_iSupportCDA(void);
int MIR_iGetAEC();
void MIR_vSendOut(uchar ucType, uchar ucFlag);
void MIR_OC_vApproved(void);
void MIR_OC_Declined(void);
void MIR_OC_EndApp(int errorType);
void MIR_OC_vOnlineRequest(void);
void MIR_OC_TwoPresent(void);
void MIR_OC_vTryAnotherInterface(void);
void MIR_OC_vTryAgain(void);
void MIR_OC_vSelectNext(void);
void MIR_vSetOPS(ushort usFlag);
void MIR_vSaveCvmFlag(int iCvmFlag);

/*****************MIR tag****************************/
//ICC TAG
//#define MIR_TAG_IC_DF6F_ODOL		"\xDF\x6F"			//ODOL
//#define MIR_TAG_IC_DF70_AI			"\xDF\x70"			//Application Info
//#define MIR_TAG_IC_DF71_CPR			"\x9F\x71"			//CPR

//Terminal TAG
//#define MIR_TAG_TERMINAL_DF71_TPM	"\xDF\x71"		//Transaction Processing Mode
//#define MIR_TAG_TERMINAL_DF41_TRC	"\xDF\x41"		//Transaction Recovery Counter(TRC)
//#define MIR_TAG_TERMINAL_DF74_TPM	"\xDF\x74"		//Kernel Verification Results(KVR)
//#define MIR_TAG_TERMINAL_9F70_CDAR	"\x9F\x70"		//CDA Result(CDAR)

//自定义TAG
//#define MIR_TAG_TERMINAL_DF8A01_AEC	 "\xDF\x8A\x01"		//Allow Expired Card


/*****************MIR KVR****************************/
///**<KVR第0字节*/
//#define KVR0_APP_VER_NOT_MATCHED							0x0080
//#define KVR0_EXPIRED_APP									0x0040
//#define KVR0_APP_NOT_EFFECTIVE			                    0x0020
//#define KVR0_REQUESTED_SERVICE_NOT_ALLOWED                  0x0010
//#define KVR0_CVM_FAIL		                                0x0008
//#define KVR0_ONLINE_PIN_REQUIRE                             0x0004
//
//
///**<KVR第1字节*/
//#define KVR1_CDA_NOT_PERFORME		                        0x0180
//
///*****************MIR CDAR****************************/
///**<CDAR第0字节*/
//#define CDAR0_ICC_DATA_MISSING								0x0080
//#define CDAR0_CDA_FAILED   									0x0040
//#define CDAR0_ICC_PKC_DECODE_ERROR		                    0x0020
//#define CDAR0_ISS_PKC_REVOKED				                0x0010
//#define CDAR0_ISS_BIN_ERROR		                            0x0008
//#define CDAR0_ISS_PKC_EXPIRED	                            0x0004
//#define CDAR0_ISS_PKC_DECODE_ERROR                          0x0002
//#define CDAR0_CA_PK_NOT_FOUND								0x0001
//
//
///**<CDAR第1字节*/
//#define CDAR1_SDAD_MISSING                         0x0180
//#define CDAR1_EXPIRED_APPLICATION		           0x0140


#endif