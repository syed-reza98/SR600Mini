#ifndef __VCPS_API__
#define __VCPS_API__

#include "emv_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

LIB_EXPORT int Vcps_Rf_PreProcess(STEMVPROC *stProc);
LIB_EXPORT int Vcps_iFlow(STEMVPROC *stProc);
LIB_EXPORT int vcps_Sel_App(ST_RF_ICCAID *stICCAID, unsigned char transtype, int nEmvTransSerial,char *pcTransMode,STEMVPROC *stProc);
LIB_EXPORT int vcps_Compelte(STEMVPROC *stProc);
LIB_EXPORT void Vcps_ParsePanFromTrack(void);
#ifdef __cplusplus
}
#endif


#endif