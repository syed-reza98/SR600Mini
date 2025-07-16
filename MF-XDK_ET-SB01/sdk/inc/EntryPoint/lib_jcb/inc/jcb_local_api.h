#ifndef __RF_JCB_LOCAL_API__
#define __RF_JCB_LOCAL_API__

#include "emv_api.h"
#include "tvrtsiaip.h"
#include "emv_interface.h"
#include "emv_tag.h"
#include "icc_op.h"
#include "define.h"
#include "funcp.h"
#include "tool.h"
#include "dol.h"


/********公共处理接口*******/
int JCB_iGetTLV(char *pszTag,char *pszData,int *nDataLen);
int JCB_iSetTLV(char *pszTag,char *pszData,int nDataLen,YESORNO bOverride);
void JCB_iSetTranMode(int iTranMode);
int JCB_iGetTranMode(void);
int JCB_iIsCardSupportODA(void);
int JCB_iIsTerminalSupportODA(void);
int JCB_iIsRequestCDA(void);
int JCB_iCheckODAData(void);
int JCB_iReadRecordMandatoryDataCheck(int iTranMode);
int JCB_iIsCapkExist(void);
int Jcb_Pack_Cdol1(char * pszCdol1, int nDolLen,char * pszDolData,int *nDolDataLen);
int JCB_iCardHolderVerify(int *piCvmFlag);
int JCB_iOffAuthCDAFirst(void);
int JCB_iOffAuthCDASecond(char *pszGacRes, int nGacLen);
void JCB_vTranFlowOutComeProc(int iResult,int iEmvRet,int iIsSignature);
void JCB_vInitOutComeData(void);
void JCB_vGetCurrentAid(char *pAid,int *piLen);
int JCB_iFinalSelectEx(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
int JCB_iGetOnlineType(void);
int JCB_iSetTLVList(char *pszTLVList,int nDataLen);

/********EMV流程处理接口*******/
int JCB_iInitAppProc(void);
int JCB_iReadAppData(void);
int JCB_iTermRiskManager(int iTranMode);
int JCB_iProcessRestrict(char cTranMode);
int JCB_iTerminalActAnaly(int iTranMode,E_GAC *pTermAcType);
int JCB_iGACProcess_EMV(E_GAC stTermAcType,char *pOutRespData,int *piOutDataLen);
int JCB_iGACProcess_Legacy(E_GAC stTermAcType);
int JCB_iGACProcess_Magstripe(E_GAC stTermAcType);
int JCB_iEcho_proc(char *pOutBuf,int iLen);
int JCB_Torn_InitAppProc(void);

void JCB_OC_vApproved(int iIsSign);
void JCB_OC_OnlineRequest(void);
void JCB_OC_OnlineRequest_TwoPresent(void);
void JCB_OC_OnlineRequest_PresentAndHold(void);
void JCB_OC_vDeclined(void);
void JCB_OC_vTryAnotherInterface(void);
void JCB_OC_vEndApplication(void);
void JCB_OC_vEndApplication_restart(void);
void JCB_OC_vEndApplication_restart_OnDevice(void);
void JCB_OC_vSelectNext(void);


#endif
