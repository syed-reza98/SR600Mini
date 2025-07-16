#ifndef __EMV_RF_ENTRY__
#define __EMV_RF_ENTRY__

#include "emv_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

//#define UNIONPAY_MACRO

LIB_EXPORT int EMV_Rf_PreProcess(STEMVPROC *stProc,EMV_stTermAIDList *pstTermAid,int iAidCount);
LIB_EXPORT int EMV_Rf_Trans(STEMVPROC *stProc);
LIB_EXPORT int EMV_Rf_Final(STEMVPROC *stProc);
LIB_EXPORT int EMV_Rf_End(void);
LIB_EXPORT void Entry_Version(char *pszVersion);
LIB_EXPORT int Entry_get_nfctype(void);

#ifdef __cplusplus
}
#endif

#endif

