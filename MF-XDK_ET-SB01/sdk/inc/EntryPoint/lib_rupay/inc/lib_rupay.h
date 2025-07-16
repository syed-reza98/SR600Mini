#ifndef __RP_LIB__
#define __RP_LIB__


#include "emv_interface.h"

/*rupay������ר�ò���*/
typedef struct
{
	char ucServiceId[2];		 //����ID
	char auServiceQualifier[5];	 //��������
	char auServiceData[96];      //��������
	int iServiceLen;			 //�������ݳ���
}RuPay_stServiceData;

typedef struct  
{
	char ucServiceId[2];
	char ucPRMacqKeyIndex;
	char ucPRMacqKey[16];		//8��16�ֽ�
	char ucPRMacqKeyLen;		//����
	char ucPRMacqKCV[3];
	char ucIsLegacyCard;	
	char ucIsCheckIndex;
}RuPay_Term_stPRMacqKey;

/**RuPay��������*/
LIB_EXPORT extern int RuPay_iInitServiceFile(void);
LIB_EXPORT extern int RuPay_iAddService(RuPay_stServiceData stRupayService,YESORNO cCoverFlag);
LIB_EXPORT extern int RuPay_iDelService(char *pServiceId);
LIB_EXPORT extern int RuPay_iGetServiceNum(void);
LIB_EXPORT extern int RuPay_iGetServiceByIndex(RuPay_stServiceData *stService,int nRecNum);

/*RuPay PRMacqKey����*/
LIB_EXPORT extern int RuPay_iInitPRMacqKeyFile(void);
LIB_EXPORT extern int RuPay_iAddPRMacqKey(RuPay_Term_stPRMacqKey stPRMacqKey,YESORNO cCoverFlag);
LIB_EXPORT extern int RuPay_iDelPRMacqKey(RuPay_Term_stPRMacqKey stPRMacqKey);
LIB_EXPORT extern int RuPay_iGetPRMacqKeyNum(void);
LIB_EXPORT extern int RuPay_iGetPRMacqKeyByIndex(RuPay_Term_stPRMacqKey *stPrmacqKey,int nRecNum);


LIB_EXPORT extern void RuPay_iSetTermServiceList(RuPay_stServiceData *pServiceList,int iListCount);
LIB_EXPORT extern void RuPay_iSetTermPRMacqKeyList(RuPay_Term_stPRMacqKey *pPRMacqKeyList,int iListCount);
LIB_EXPORT extern int RuPay_iIsExecFullOnline(char *pOnlineRespData,int iRespDataLen);

/******************************************************************************
 *  ��������:RuPay_iDefault_act_analy
 *	��������:Ĭ����Ϊ���������terminal unable to go online, partial online,�ṩ��Ӧ��
 *	��ڲ���:
 *	���ڲ���:
 * 	����ֵ  :
 ******************************************************************************/
LIB_EXPORT extern int RuPay_iDefault_act_analy(void);
LIB_EXPORT extern int RuPay_iIsAppBlock(void);
#endif
