#ifndef __QUICS_API__
#define __QUICS_API__

#include "emv_interface.h"
#include "funcp.h"

#ifdef __cplusplus
extern "C"{
#endif

LIB_EXPORT int Quis_Rf_PreProcess(STEMVPROC *stProc);
LIB_EXPORT int Q_Rf_PreProcess(STEMVPROC *stProc,char *pszAid,char nAidLen);
LIB_EXPORT int quics_Sel_App(char cTransType,int nEmvTransSerial,char *pcTransMode,ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT int quics_iFlow(STEMVPROC *stProc);
LIB_EXPORT void Quics_ParsePanFromTrack(void);

#ifdef __cplusplus
}
#endif


#endif