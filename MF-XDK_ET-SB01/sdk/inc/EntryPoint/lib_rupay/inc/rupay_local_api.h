#ifndef __RF_RUPAY_LOCAL_API__
#define __RF_RUPAY_LOCAL_API__

#include "emv_api.h"
#include "tvrtsiaip.h"
#include "emv_interface.h"
#include "emv_tag.h"
#include "icc_op.h"
#include "define.h"
#include "funcp.h"
#include "tool.h"
#include "dol.h"


int Rupay_Init_App(void);
int RuPay_Read_AppData(char ucTapSign);
int RuPay_iQddaAuth();
void RuPay_ProcessRestrict_Step(void);
int rupay_recover_ac_proc(void);
int RuPay_Ch_Verify(int *piCvmFlag);
void RuPay_risk_mana(YESORNO bForceOnline,int iExceptFile);
int RuPay_first_term_act_analy(E_GAC *pTermAcType);
int Rupay_GAC1_Proc(E_GAC pTermAcType);
//int RuPay_second_act_analy(E_GAC *pTermAcType);
int RuPay_second_act_analy(int iOnlineResp,E_GAC *pTermAcType);
int RuPay_iGetGACData(unsigned char *pszData, int nLen);
//int RUPAY_ADF_iSelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
int RuPay_ADF_A5_iMatchTag(char *pTag,int iTagLen);
int RuPay_ADF_BF0C_iMatchTag(char *pTag,int iTagLen);
int RuPay_ReadRecord_iMandoryData(void);
int RP_TORN_vGetServicePanAndPsn(void);
int RuPay_i2TapTranProcForNotSameCard_2th(STEMVPROC *stProc);
void RuPay_v2TapDataVerify(void);
void RuPay_vSetExceedCvmSign(int iSign);
void RuPay_vSetNoCvmSupportSign(void);
int RuPay_iIsTerminalAndCardSupportNocvmMethod(void);
//临时服务： 针对PRMiss, PRMacq and PRMicc 全0设置
void RuPay_vSetTemporaryServicesKey(void);
void RuPay_vTranAmountAdjust(void);
int RuPay_iIsLegacyMode(void);
void RuPay_vSetAppBlockSign(void);
void RuPay_vClearAppBlockSign(void);
/*------------------------------------>rupay_flow.h<--------------------------相关接口*/
//数据结构体
typedef struct
{
	uchar auData[512];
	uint uiDataLen;
}RuPay_tTLVString;


typedef struct
{
	uchar ucIsExistMatchService;				//判断服务列表是否有匹配一样的服务ID
	uchar ucIsServiceTransaction;				//服务交易
	uchar ucIsGpoRespondDF33;					//GPO过程卡片是否返回DF33服务相关数据
	uchar ucTermAcType;
	uchar ucExceptionFile;
	uchar ucOdc;
	uchar ucAdvice;
	uchar ucTornCardSwitch;
	uchar ucTornSign;
	uchar ucIsPlant;
	uchar ucTranMode;
	uchar ucIsPreviousPRMiccExist_2TAP;
	uchar ucIsPRMiccSame_2TAP;
	uchar ucIsGPOdataSame_2TAP;
	uchar ucIsSfiDf61Exist_2TAP;
	uchar ucPRMacqIndex_NonLegacy;
	uchar ucAppBlockSign;
	uchar ucDF07ExistSign;
	uchar ucIsRemoveNoCvmFlag;
}RUPAY_tParam;


//Service Related Data
typedef struct
{
	char cServiceIndex;
	char cServiceId[2];
	char cServiceControl[2];
	unsigned char cKcv[3];
	char cPRMacqKeyIndex;
	char cRFU[4];
	char cLastServiceUpdateAtc[2];
	char cLastServiceUpdateDateTime[6];
	char cServiceAtc[2];
	char cServiceBalance[6];
	char cServiceCurrency[2];
	char cServiceDataLength;
	char cServiceData[96];		//33-128 Var. Service Data (max 96 bytes) 
}RP_Service_Related_Data; 

//Service dir Data
typedef struct
{
	char cSeviceVer;
	char cRFU;
	char cLable[10];
	char cLimit;
	char cCounter;
	char cSFI;
	char cDF50;
	char cDF12;
	char cServiceList[128];		//2+2 = 服务数据
}RP_Service_Dir_Data; 

//Term PRMacq key data
typedef struct  
{
	char cServiceId[2];
	char cServiceCtrl[2];
}RP_IC_SERVICE_LIST_DATA;

typedef struct tagDATE_TIME_T
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}RP_DATE_TIME;


void RuPay_OWHFI_vCaculateServiceSummary(int tTermAcType);	 //OWHF-I (I for Integrity – Service Summary Calculation) 
void RuPay_OWHFA_vCaculateSignature(char acReqCertType);	 //OWHF-A (A for Authentication – Signature Calculation
//get 2-tap aid
void RuPay_vGetCurrentAid_2Tap(char *pAid,int *piLen);
int RuPay_iGetCardSupportServiceList(char cSFI,RP_Service_Dir_Data stServiceList[], int *iServiceCount);
int RuPay_iRecoverRRData_1th_2Tap(void);
int RuPay_RR_iSaveData_1th_2Tap_Flow(void);
void RuPay_iFree2TapResource(void);

#endif
