#ifndef __LIB_EMV__
#define __LIB_EMV__

#include "pub/pub.h"
//#include "lib_emvpub/inc/emv_interface.h"
#include "EntryPoint/lib_emvpub/inc/emv_interface.h"

#ifdef WIN32
#endif
#ifdef __cplusplus
extern "C"{
#endif

/**<EMV函数API*/
LIB_EXPORT extern int EMV_Start(STEMVPROC *stProc);
LIB_EXPORT extern int EMV_Trans(STEMVPROC *stProc);
LIB_EXPORT extern int EMV_Final(STEMVPROC *stProc);
LIB_EXPORT extern int EMV_End();

//转存授权金额
LIB_EXPORT extern int EMV_SetAuthAmt(char *psAmt);
/**< 获取EMV版本号*/
LIB_EXPORT extern void EMV_Version(char *pszVersion);
//LIB_EXPORT extern void EMV_Pinpad_Version(char *pszVersion);

#ifdef __cplusplus
}
#endif

#endif