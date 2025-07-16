#ifndef __AMEX_LOCAL_API__
#define __AMEX_LOCAL_API__

#include "struct_tlv.h"
#include "printfdebug.h"
#include "define.h"
#include "tool.h"
#include "icc_op.h"
//#include "emv_rf.h"
#include "data.h"
#include "emv_interface.h"
#include "Amex_Api.h"


#define AMEX_ERR_PRO_RES  (-1000)
#define AMEX_ERR_ACT_ANY  (-2000)

#define AMEX_ERR_PRO_RES_APP_NO_ALLOW 				(AMEX_ERR_PRO_RES-1)
#define AMEX_ERR_ACT_ANY_FM1_80_INVALID_DATALEN 	(AMEX_ERR_ACT_ANY-1)

typedef  enum
{
	AMEX_SDA_SELECT,
	AMEX_CDA_SELECT,
	AMEX_DDA_SELECT,
	AMEX_DEAFAULT,
	
}AMEX_OFF_AUTH_MODE;


typedef struct
{
	int Reader_Floor_limit_exceeded;
	int Reader_cvm_limit_exceeded;
	int Reader_Application_not_allowd;
	int Reader_req_online;
	int Reader_req_cvm;
	int Reader_zero_allow;
	int Reader_state_allow;
}AMEX_Prepre_flag;

typedef struct DATE_TIME
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}AMEX_DATE_TIME;
int AMEX_iFindCAPKDataBy(void);
AMEX_Prepre_flag *AMEX_iGetPreProflag(void);
void  AMEX_iSetPreProflag(AMEX_Prepre_flag uc_amex_prepro_flag);
void  AMEX_initPreProflag(void);
int AMEX_Init_App(void);
int AMEX_Read_AppData(char *cTransMode);
int AMEX_ReadData_checkMandatoryData(void);
//int AMEX_iIsTermSupportContactTranc(void);
int AMEX_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
//AMEX_TRANS_MODE AMEX_GetTranMode(void);
int AMEX_MS_MODE_vCheckATC(void);
int AMEX_GetRestart_Flag(void);
void AMEX_SetRestart_Flag(int i);
int AMEX_OffAuth(void);
int AEMX_iProce_Restrict(void);
int AMEX_act_analy(STEMVPROC *stProc);
void AMEX_risk_mana(YESORNO bForceOnline,char cTransMode);
void AMEX_ucSetDefaultConfigData(void);
//int AMEX_GetRestart_Flag(void);
int  AMEX_iGetUnable_Online(void);
int  AMEX_iGetDelayAuth_Support(void);
int  AMEX_iGetDRL_Support(void);
int AMEX_iCardholder_Verify(STEMVPROC *stProc);
int  AMEX_iGetMsOnlyMode_Support(void);
int  AMEX_iGetBlackPAN_Support(void);
YESORNO AMEX_Term_SupportSign(void);
YESORNO AMEX_Term_SupportMobileCVM(void);
YESORNO AMEX_Term_SupportOnLine(void);
YESORNO AMEX_Card_SupportOnLine(void);
int AMEX_Card_SupportContactTranc(void);
void AMEX_iSetOffAuth_Mode(AMEX_OFF_AUTH_MODE amex_offauth_mode);
AMEX_OFF_AUTH_MODE AMEX_GetOffAuth_Mode(void);
void set_mobile_flag(int flag);
int get_mobile_flag();
#endif