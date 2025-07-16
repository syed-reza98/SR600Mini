#ifndef __PURE_LOCAL_API__
#define __PURE_LOCAL_API__

#include "struct_tlv.h"
#include "printfdebug.h"
#include "define.h"
#include "tool.h"
#include "icc_op.h"
#include "data.h"
#include "emv_interface.h"
#include "pure_api.h"
#include "tvrtsiaip.h"
#include "emv_tag.h"
#include "funcp.h"
#include "dol.h"
#define BCD2BIN(val)    (((val) & 0x0f) + ((val)>>4)*10)
#define BIN2BCD(val)    ((((val)/10)<<4) + (val)%10)


typedef enum
{

	PURE_ISS_SUCC,
	PURE_ISS_FAIL,
	PURE_ISS_71_AND_72,
	PURE_ISS_71,
	PURE_ISS_72,	
}PURE_ISS_RESULT;

typedef struct
{
	int Reader_Floor_limit_exceeded;
	int Reader_cvm_limit_exceeded;
	int Reader_Application_not_allowd;
	int Reader_req_online;
	int Reader_req_cvm;
	int Reader_zero_allow;
	int Reader_state_allow;
}PURE_Prepre_flag;

typedef struct 
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}PURE_DATE_TIME;

typedef enum
{
	PURE_NONE_TAP,
	PURE_2ND_TAP,
	PURE_LONG_TAP,
}PURE_ONLINE_TAP;
typedef struct
{
	unsigned char sztag[4];
	int nTagLen;
}PURE_TAG_STU;

void PURE_set_all_proflag(PURE_Prepre_flag * p_pro_flag,int num);
void PURE_get_all_proflag(PURE_Prepre_flag * p_pro_flag,int num);

int PURE_iFindCAPKDataBy(void);
void PURE_iGetPreProflag(PURE_Prepre_flag *uc_amex_prepro_flag);
void  PURE_iSetPreProflag(PURE_Prepre_flag uc_amex_prepro_flag);
void  PURE_initPreProflag(void);
int PURE_Init_App(void);
int PURE_Read_AppData(char *cTransMode);
int PURE_ReadData_checkMandatoryData(void);
int PURE_OffAuth(void);
int PURE_iProce_Restrict(void);
int PURE_first_act_analy(STEMVPROC *stProc);
void PURE_risk_mana(YESORNO bForceOnline,char cTransMode);
void PURE_ucSetDefaultConfigData(void);
int  PURE_iGetUnable_Online(void);
int  PURE_iGetDelayAuth_Support(void);
int PURE_iGetBlackPAN_Support(void);
YESORNO PURE_Term_SupportSign(void);
YESORNO PURE_Term_SupportMobileCVM(void);
YESORNO PURE_Term_SupportOnLine(void);
int PURE_Card_SupportContactTranc(void);
void PURE_vSetCCIDmode(PURE_CCID_MODE stPure_ccid_mode);
PURE_CCID_MODE PURE_GetCCIDmode(void);
void PURE_vSetCAMSelect(PURE_OFFLINE_CAM_MODE st_CAM_mode);
PURE_OFFLINE_CAM_MODE PURE_GetCAMSelect(void);
void PURE_vSetEcho_Trans_Indicator(int st_PURE_Echo_Trans_Indicator);
int PURE_iGetEcho_Trans_Indicator(void);
void PURE_vSetEcho_Support_Indicator(int st_PURE_Echo_Support_Indicator);
int PURE_iGetEcho_Support_Indicator(void);
void PURE_vSetCOMM_Problem_Indicator(int st_PURE_Comm_Problem_Indicator);
int PURE_iGetCOMM_Problem_Indicator(void);
void PURE_Offline_CAM_Checking(void);
int PURE_Offline_CAM_Selection(void);
void PURE_vSetOnLineTapMode(PURE_ONLINE_TAP onLineTapMode);
PURE_OUTCOME_PARAM* PURE_Get_Outcome();
void PURE_Outcome_vSet_cvm(char CVM_mode);
void PURE_vSet_Outcome(PURE_OUTCOME_PARAM st_pure_outcome_param);
void PURE_vInit_Outcome();
char PURE_Outcome_Get_cvm();
void PURE_vSetCompletion_ID(int Completion_id);
int PURE_iGetCompletion_ID();
int PURE_Second_act_analy(E_GAC eGacType);
int PURE_Get_Trans_Reslut();
PURE_ISS_RESULT PURE_Proc55Field(char *pszField55,int nFieldLen,int *pszScriptNo);

void PURE_vSendOut(uchar ucType);
int PURE_Outcome_Setting(int st_pure_trans_result);
void PURE_SET_MSG_PRESENT(int flag, int value);
void PURE_INIT_PRESENT_FLAG();

void DEL_readapp_data();
int check_track2(char *track2,int len);

int PURE_check_date_format();

void pure_ParsePanFromTrack(void);
void PURE_SendsepUIRD(int type);


int PURE_Get_Trans_Reslut();

#endif