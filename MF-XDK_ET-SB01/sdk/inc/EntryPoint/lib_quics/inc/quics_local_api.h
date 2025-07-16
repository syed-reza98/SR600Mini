#ifndef __QUICS_LOCAL_API__
#define __QUICS_LOCAL_API__

#include "lib_quics.h"
#include "emv_interface.h"
#include "funcp.h"
#include "tracedef.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef enum
{
	EMV_NO='0',
	EMV_YES='1'
}EMV_YESORNO;

#define QUICS_RET_SELECT_NEXT					2		//选择下一条应用

int Qpass_GetBin(ST_BIN_DATA *pBin,int binType);
int Qpass_Shankadata(ST_QFAIL_DATA *stFail_data,int nIndex);
int Qpass_Shanka(ST_QFAIL_DATA *stFail_data,int nQfailcount);
int quics_oda(char *cTransMode);
void oda_judge(void);
void oda_tag_set(void);




int quics_Init_App(char *pcTransMode);
ST_QPBOC_PROC * get_Qpass_param();

#ifdef __cplusplus
}
#endif


#endif
