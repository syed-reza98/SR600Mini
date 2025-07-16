#ifndef __RF_SIBS_LOCAL_API__
#define __RF_SIBS_LOCAL_API__

#include "define.h"
#include "data.h"
#include "emv_interface.h"
#include "emv_tag.h"
#include "funcp.h"

typedef struct tagDATE_TIME_T
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}SIBS_DATE_TIME;


int SIBS_iTransFlow(STEMVPROC *stProc);
int SIBS_iTransFlow_Simple(STEMVPROC *stProc);

/****************交易步骤************************/
int SIBS_iInitApp();
int SIBS_iReadRecord();
int SIBS_OffAuth();
int SIBS_OffAuth_CDA_First();
int CDA_AC_SIBS(char *pszGacRes, int nGacLen);
int SIBS_Process_Restrict();
int SIBS_CardHolderVerify(STEMVPROC *stProc,int *piCvmFlag);
int SIBS_risk_mana();
int SIBS_term_act_analy(E_GAC *pTermAcType);
int SIBS_card_act_analy(E_GAC eGacType,STEMVPROC *stProc);



/****************常用接口************************/
int SIBS_iSupportOdv(void);
int SIBS_iSupportCDA(void);
int SIBS_iIsSupportContact(void);

void SIBS_vSendOut(uchar ucType, uchar ucFlag);
void SIBS_OC_vApproved(void);
void SIBS_OC_Declined(void);
void SIBS_OC_vOnlineRequest(void);
void SIBS_OC_vTryAnotherInterface(void);
void SIBS_OC_vEndAppRestart(void);
void SIBS_OC_vTryAgain(void);
void SIBS_OC_vSelectNext(void);

#endif