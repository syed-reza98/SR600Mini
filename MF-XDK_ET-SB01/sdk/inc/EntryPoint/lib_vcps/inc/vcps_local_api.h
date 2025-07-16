#ifndef __VCPS_LOCAL_API__
#define __VCPS_LOCAL_API__

#include "icc_op.h"
#include "tool.h"
#include "lib_vcps.h"

#ifdef __cplusplus
extern "C"{
#endif


typedef struct {
    char rf_issuser_aid_data[32];
    int rf_issuser_aid_len;
}ST_ISSUER_AID;

ST_ISSUER_AID* get_issuer_aid(void);
//仅vcps内部调用 local api 接口
int vcps_cvm_proc(STEMVPROC *stProc,int barqc);
//int vcps_LC_PreProcess(unsigned char cTransType);
int vcps_Read_AppData(char *cTransMode);
int vcps_Init_App(char *pcTransMode);
int vcps_Process_Restrict(int iadtype,unsigned char cTransType);
int vcps_drl_flow();


#ifdef __cplusplus
}
#endif


#endif
