#ifndef __DPAS_LOCAL_API__
#define __DPAS_LOCAL_API__ 

#include "emv_interface.h"
#include "data.h"


#ifdef __cplusplus
extern "C"{
#endif
#define DPAS_ERR_PRO_RES  (-3000)

#define DPAS_ERR_PRO_RES_FM1_NO80_NO77 	(DPAS_ERR_PRO_RES-1)


#define DPAS_CARD_PROQ_ONLINEPIN			0x0080	/**< 需要联机PIN*/ 
#define DPAS_CARD_PROQ_SIANATURE			0x0040	/**< 需要签名*/
#define DPAS_CARD_PROQ_PID_LIMIT			0x0020	/**< PID Limit reached*/
#define DPAS_CARD_PROQ_CVM_PERFORMED		0x0010	/**< Consumer Device CVM Performed*/
#define DPAS_CARD_PROQ_OTHER_INTERFACE		0x0180		/**<Switch other interface if unable to process online*/
#define DPAS_CARD_PROQ_ONLINE_CDAFAILED		0x0140		// Process online if CDA failed
#define DPAS_CARD_PROQ_DECLINE_OROTHER		0x0120		/**<Decline/switch other interface if CDA failed*/
#define DPAS_CARD_PROQ_ISSUSER_SCRIPT		0x0110		// Issuer Update Processing supported
#define DPAS_CARD_PROQ_ONLINE				0x0108		/**< Process online if card expired*/
#define DPAS_CARD_PROQ_DECLINE				0x0104		// Decline if card expired
#define DPAS_CARD_PROQ_FALLBACK_SIGNATURE	0x0102		/**<CVM Fallback to Signature allowed*/
#define DPAS_CARD_PROQ_FALLBACK_CVM			0x0101		// CVM Fallback to No CVM allowed

int Dpas_cvm_proc(char *bSignatrue,int barqc);
int Dpas_Ms_Zip(int *nEmvRes,char *cTransMode);
int ZIP_ADF_iSelectIcFile(char cSelMode,ST_RF_ICCAID *stICCAID,ST_ICFILE *stIcFile);
int DPAS_ADF_iSelectIcFile(char cSelMode,ST_RF_ICCAID *stICCAID,ST_ICFILE *stIcFile,YESORNO isScriptAvailable);
YESORNO dpas_get_IsSelected(void);
int Dpas_RF_Sel_App(char cTransType,int nEmvTransSerial,char *pcTransMode,YESORNO isScriptAvailable);
int Dpas_Term_Action_Analysis();
int Dpas_Rf_Offline(STEMVPROC *stProc,char *cTransMode);
ST_ICCAID* dpas_get_ICCAID(void);
ST_RF_ICCAID* DPAS_get_ICCAID(void);
void DPAS_Set_ICCAID(ST_RF_ICCAID *szRF_ICCAID);





#define GOTO_SELECT_DPAS_MS_MODE    0x11
#define GOTO_SELECT_ZIP_MODE        0x12
#define GOTO_SELECT_ZIP_MODE		0x13


typedef struct
{
	int Reader_Floor_limit_exceeded;
	int Reader_cvm_limit_exceeded;
	int Reader_Application_not_allowd;
	int Reader_req_online;
	int Reader_req_cvm;
	int Reader_zero_allow;
	int Reader_state_allow;
}DPAS_Prepre_flag;

typedef struct
{
	int Data_Storage_Enabled;
	int Extended_Logging_Enabled;
	int Tearing_Recovery_Enabled;
}DPAS_func_flag;

typedef struct DATE_TIME
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}DPAS_DATE_TIME;

typedef struct 
{
	unsigned char szAID[17];
	unsigned char nAidLen;
	unsigned char szDF3B[100];
	unsigned char nDF3BLen;
	unsigned char szPdolData[255];
	unsigned char nPdolLen;
	unsigned char p1;
}TEARING_LOG;

typedef struct DS_CONTAIN
{
	unsigned char szContainID[5];
	unsigned char ContainType;
	unsigned char recordNum;
	int nContentlen;
	unsigned char szContent[160];
}ds_contain_t;

typedef struct DS_CARDID
{
	char szDF3B[100];
	int nDF3BLen;
	char szDF3A[10];
	int nDF3Alen;
}ds_cardId;




DPAS_Prepre_flag *DPAS_iGetPreProflag(void);
void  DPAS_iSetPreProflag(DPAS_Prepre_flag uc_amex_prepro_flag);
void  DPAS_initPreProflag(void);
//void DPAS_SetTranMode(DPAS_TRANS_MODE szDPAS_trans_mode);
//DPAS_TRANS_MODE DPAS_GetTranMode(void);
void DPAS_InitTermData_Before_GPO(void);
void DPAS_vGenerateUnNumber(void);
void DPAS_vSetTermDataAndTime(void);
void DPAS_vSet81Amount(void);
int DPAS_iGetAndCheckGPO(char *pszDol,int nDolLen);
int DPAS_vCheckData_After_GPO(void);
void DPAS_risk_mana(YESORNO bForceOnline,char cTransMode);
int Dpas_Process_Restrict(void);
int DPAS_OffAuth(void);
int Dpas_CDA_Check(void);
int dpas_check_pan(char*pszTrack,int nMaxTrackLen);
int DPAS_act_analy(STEMVPROC *stProc);
int DPAS_iCardholder_Verify(STEMVPROC *stProc);
//int DPAS_Term_SupportContactTranc(void);



void Dpas_init_func_flag();
void Dpas_check_func_flag();
int DPAS_ADF_BF0C_iMatchTag(char *pTag,int iTagLen);

void dpas_get_cardid(ds_cardId * outID);
DPAS_func_flag Dpas_get_func_flag();



#ifdef __cplusplus
}
#endif


#endif
