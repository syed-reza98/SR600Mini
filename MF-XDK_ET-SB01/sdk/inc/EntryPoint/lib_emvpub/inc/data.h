#ifndef __EMV_DATA__
#define __EMV_DATA__ 
#include "define.h"
#include "emv_interface.h"

#define LEN_RANDOM 4

typedef struct {
	unsigned char szDF_84[16+1];			/*	DF��*/
	int nDFLen;							/**<�ļ�������*/
	unsigned char szFCI_A5[MAXLEN_ICCRESP+1];	/*	FCI����*/
	int nFCILen;							/**<FCI���ݳ���*/
}ST_ICFILE;


//#define AID_MAX_NUM  50
#define AID_MAX_NUM  25
//#define REC_CERT_MAX_NUM	100
#define REC_CERT_MAX_NUM	70   //������Ҫ��Ĭ������60��

LIB_EXPORT int InitEmvData(char *pszData,int nLen);
LIB_EXPORT void FreeEmvData(void);
LIB_EXPORT YESORNO TagIsTermData(char *pszTag,int nLen);
LIB_EXPORT YESORNO TagIsTermData_pure(char *pszTag,int nLen);
LIB_EXPORT int SaveEmvTlvData(TlvData elem,YESORNO bOverride);
LIB_EXPORT int SetEmvData(int nIndex,char cTransType,int nEmvTransSerial);
LIB_EXPORT int DelEmvData(char *pszTag,int nTaglen);
LIB_EXPORT int ClearHashTableData(void);

LIB_EXPORT void Rf_FreeEmvData(void);

LIB_EXPORT int EMV_iTermSupportAidCount(void);
LIB_EXPORT void EMV_vDisplayTermSupportAid(void);

LIB_EXPORT int EMV_GetCurrentKid(void);
LIB_EXPORT int EMV_iSetCurrentKid(int iKernelId);

LIB_EXPORT void SaveTransType(char cTransType);

LIB_EXPORT char IsEcOnly();

LIB_EXPORT void Emv_SetErrCode(unsigned int iCode);
LIB_EXPORT void Emv_vSetSW1SW2(int iSW1SW2);
LIB_EXPORT int Emv_iGetSW1SW2(void);
LIB_EXPORT int EMV_iGetL1ErrorCode(void);
LIB_EXPORT void EMV_iSetL1ErrorCode(int iErrorCode);

LIB_EXPORT int Emv_Is_AIDList();
LIB_EXPORT int EMV_vGetCurrentCapk(ST_CAPK *pstCapk);

LIB_EXPORT int Init_PP_Data(void);
LIB_EXPORT void set_pp_actLen(int nvalue);
LIB_EXPORT int get_pp_actLen(void);
LIB_EXPORT int PP_SaveEmvTlvDataForUnknown(TlvData elem,int iType);

LIB_EXPORT int Rf_InitEmvData(char *pszData,int nLen,EMV_stTermAIDList *pstTermAid,int iAidCount);

LIB_EXPORT void Emv_SetErrFLOW(unsigned int iErrorFLOW);
LIB_EXPORT void Emv_SetErrCode(unsigned int iCode);

LIB_EXPORT int quics_fddaerr_reason(char cReason);

#endif