#ifndef __DPAS_API__
#define __DPAS_API__ 

#include "emv_interface.h"
#include "funcp.h"

#ifdef __cplusplus
extern "C"{
#endif

#define DPAS_ZIP_RID	 "\xA0\x00\x00\x03\x24"	
#define DPAS_RID  "\xA0\x00\x00\x01\x52"

typedef  enum
{
	DPAS_EMV_MODE,
	DPAS_MS_MODE,
	DPAS_ZIP_MODE,
}DPAS_TRANS_MODE;



#define DPAS_RET_SUCC									0		
#define DPAS_RET_TERMINAL								1		
#define DPAS_RET_SELECT_NEXT							2		
#define DPAS_RET_TRY_AGAIN								3		
#define DPAS_RET_GOTOTHER_MOBILE_CVM		            4		
#define DPAS_RET_GOTOTHER								5		
#define DPAS_RET_GOTOTHER_MAG							6
#define DPAS_RET_GPO_6986							    7
#define DPAS_RET_GPO_6987							    8


LIB_EXPORT int Dpas_Rf_PreProcess(STEMVPROC *stProc,ST_RF_ICCAID *stICCAID);

LIB_EXPORT int Dpas_Rf_Trans(STEMVPROC *stProc);

LIB_EXPORT int Dpas_Rf_Compelte(STEMVPROC *stProc);

LIB_EXPORT int DPAS_And_ZIP_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT int DPAS_Term_SupportContactTranc(void);

LIB_EXPORT int Dpas_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT void DPAS_SetTranMode(DPAS_TRANS_MODE szDPAS_trans_mode);
LIB_EXPORT DPAS_TRANS_MODE DPAS_GetTranMode(void);
LIB_EXPORT int DPAS_Rf_Compelte(STEMVPROC *stProc);
LIB_EXPORT void DPAS_vSetSecondTAPTime(int DPAS_secondeTapTime);
LIB_EXPORT int  DPAS_iGetSecondTAPTime(void);
LIB_EXPORT  int DPAS_Init_Issuser_Res(STEMVPROC *stProc);

LIB_EXPORT void  Dpas_set_Deferred_Authorization(int flag);

LIB_EXPORT int Dpas_get_Deferred_Authorization();

LIB_EXPORT void Dpas_set_Data_Storage(int flag);
LIB_EXPORT void Dpas_set_Extended_Logging(int flag);
LIB_EXPORT void Dpas_set_Tearing_Recovery(int flag);
LIB_EXPORT int Dpas_get_Data_Storage();
LIB_EXPORT int Dpas_get_Extended_Logging();



LIB_EXPORT int DPAS_iGetCAPK(STRSA *pk);
LIB_EXPORT int DPAS_iFindCAPK(void);

#define DPAS_LOG
#ifdef DPAS_LOG
#define DPAS_DBG 		Debug_fprintf
#define DPAS_DBG_HEX 	DebugPrintBuf
#define DPAS_DBG_TLV 	DebugPrintTlv
#else
#define DPAS_DBG(...)  		
#define DPAS_DBG_HEX(...)  	
#define DPAS_DBG_TLV(...)  	
#endif




#ifdef __cplusplus
}
#endif


#endif
