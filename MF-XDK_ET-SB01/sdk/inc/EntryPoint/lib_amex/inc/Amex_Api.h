#ifndef __RF_AMEX_API__
#define __RF_AMEX_API__

#include "emv_interface.h"

//??????
#define AMEX_RET_SUCC							0		
#define AMEX_RET_TERMINAL						1		
#define AMEX_RET_SELECT_NEXT					2		
#define AMEX_RET_TRY_AGAIN						3		
#define AMEX_RET_TRY_AGAIN_GAC6904_AND_MOBILE_CVM						4		
#define AMEX_RET_GOTOTHER						5		
#define AMEX_RET_GOTOTHER_MAG						6		

typedef enum
{
	 AMEX_TC=0,
	 AMEX_ARQC,
	 AMEX_AAC,
	 AMEX_AAR,
	 AMEX_AAC_FAIL_AAC,
}AMEX_CID;


// #define AMEX_3_1  AEMX3.1

typedef  enum
{
	AMEX_MS_MODE,
	AMEX_EMV_MODE,
	AMEX_ERR_MODE,
}AMEX_TRANS_MODE;

LIB_EXPORT int AMEX_Rf_PreProcess(STEMVPROC *stProc);
LIB_EXPORT int AMEX_Compelte(STEMVPROC *stProc);
LIB_EXPORT int AMEX_iTranFlow(STEMVPROC *stProc);
LIB_EXPORT int AMEX_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT void AMEX_SetRestart_Flag(int i);
LIB_EXPORT int AMEX_GetRestart_Flag(void);
LIB_EXPORT AMEX_TRANS_MODE AMEX_GetTranMode(void);
LIB_EXPORT void AMEX_vSetUnable_Online(int IsUnableOnline);
LIB_EXPORT void AMEX_vSetDRL_Support(int IsDRL_Support);
LIB_EXPORT void AMEX_vSetDelayAuth_Support(int IsDelayAuth_Support);
LIB_EXPORT void AMEX_vSetOnlyMsMode_Support(int IsMsMode_Support);
LIB_EXPORT void AMEX_vSetBlackPAN_Support(int IsDRL_Support);
LIB_EXPORT int AMEX_Term_SupportContactTranc(void);
LIB_EXPORT void AMEX_vSetnoRespond(int isNoRespond);
LIB_EXPORT int AMEX_getNorespond(void);
//LIB_EXPORT YESORNO AMEX_Term_SupportOnLine(void);


#define AMEX_MS_MODE_9F39  ("\x91")
#define AMEX_EMV_MODE_9F39  ("\x07")

//int AMEX_act_analy(STEMVPROC *stProc);
//void AMEX_risk_mana(YESORNO bForceOnline,char cTransMode);

#define AMEX_LOG
#ifdef AMEX_LOG
#define AMEX_DBG 		Debug_fprintf
#define AMEX_DBG_HEX 	DebugPrintBuf
#define AMEX_DBG_TLV 	DebugPrintTlv
#else
#define AMEX_DBG(...)  		
#define AMEX_DBG_HEX(...)  	
#define AMEX_DBG_TLV(...)  	
#endif

#endif

