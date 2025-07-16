#ifndef __LIB_VCPS__
#define __LIB_VCPS__

#include "emv_interface.h"

#ifdef __cplusplus
extern "C"{
#endif
/**< --------------------------------------------------------------------------------------------------*/

/**< --------------------------------------------------------------------------------------------------*/

typedef struct {
	char PreProcess;
	char KeyRev;
	char Except;
}ST_SDK_PROC;

LIB_EXPORT extern int Vcps_Sel_App_issuser();
LIB_EXPORT extern int Vcps_Init_Issuser_Res(STEMVPROC *stProc);

#ifdef __cplusplus
}
#endif


#endif