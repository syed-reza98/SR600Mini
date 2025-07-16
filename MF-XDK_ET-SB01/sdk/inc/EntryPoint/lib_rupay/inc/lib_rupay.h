#ifndef __RP_LIB__
#define __RP_LIB__


#include "emv_interface.h"

/*rupay函数及专用参数*/
typedef struct
{
	char ucServiceId[2];		 //服务ID
	char auServiceQualifier[5];	 //服务性能
	char auServiceData[96];      //服务数据
	int iServiceLen;			 //服务数据长度
}RuPay_stServiceData;

typedef struct  
{
	char ucServiceId[2];
	char ucPRMacqKeyIndex;
	char ucPRMacqKey[16];		//8或16字节
	char ucPRMacqKeyLen;		//长度
	char ucPRMacqKCV[3];
	char ucIsLegacyCard;	
	char ucIsCheckIndex;
}RuPay_Term_stPRMacqKey;

/**RuPay服务数据*/
LIB_EXPORT extern int RuPay_iInitServiceFile(void);
LIB_EXPORT extern int RuPay_iAddService(RuPay_stServiceData stRupayService,YESORNO cCoverFlag);
LIB_EXPORT extern int RuPay_iDelService(char *pServiceId);
LIB_EXPORT extern int RuPay_iGetServiceNum(void);
LIB_EXPORT extern int RuPay_iGetServiceByIndex(RuPay_stServiceData *stService,int nRecNum);

/*RuPay PRMacqKey数据*/
LIB_EXPORT extern int RuPay_iInitPRMacqKeyFile(void);
LIB_EXPORT extern int RuPay_iAddPRMacqKey(RuPay_Term_stPRMacqKey stPRMacqKey,YESORNO cCoverFlag);
LIB_EXPORT extern int RuPay_iDelPRMacqKey(RuPay_Term_stPRMacqKey stPRMacqKey);
LIB_EXPORT extern int RuPay_iGetPRMacqKeyNum(void);
LIB_EXPORT extern int RuPay_iGetPRMacqKeyByIndex(RuPay_Term_stPRMacqKey *stPrmacqKey,int nRecNum);


LIB_EXPORT extern void RuPay_iSetTermServiceList(RuPay_stServiceData *pServiceList,int iListCount);
LIB_EXPORT extern void RuPay_iSetTermPRMacqKeyList(RuPay_Term_stPRMacqKey *pPRMacqKeyList,int iListCount);
LIB_EXPORT extern int RuPay_iIsExecFullOnline(char *pOnlineRespData,int iRespDataLen);

/******************************************************************************
 *  函数名称:RuPay_iDefault_act_analy
 *	函数介绍:默认行为分析，针对terminal unable to go online, partial online,提供给应用
 *	入口参数:
 *	出口参数:
 * 	返回值  :
 ******************************************************************************/
LIB_EXPORT extern int RuPay_iDefault_act_analy(void);
LIB_EXPORT extern int RuPay_iIsAppBlock(void);
#endif
