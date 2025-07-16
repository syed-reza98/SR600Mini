#ifndef __LIB_PAYPASS__
#define __LIB_PAYPASS__

#include "emv_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

LIB_EXPORT int PayPass_iSetTLV(char *pszTag,char *pszData,int nLen);
LIB_EXPORT int PayPass_iSetTLVList(char *pszTLVList,int nDataLen);

#ifdef __cplusplus
}
#endif

#endif