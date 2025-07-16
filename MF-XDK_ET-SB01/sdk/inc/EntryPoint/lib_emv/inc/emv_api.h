#ifndef __EMV_API__
#define __EMV_API__

#include <data.h>
#include <emv_interface.h>
#include <define.h>
#include "funcp.h"

#ifdef __cplusplus
extern "C"{
#endif

#define RET_SELECT_NEXT					2		//选择下一条应用
/**< ---------------------------------------------------------------------------------------------------*/
//外部调用API接口
/**< ---------------------------------------------------------------------------------------------------*/
/**< --------------------------emv_cardholder_verify-----------------------------------------------------*/
LIB_EXPORT int ProcessCVM(char cCC0,YESORNO bProcess);
LIB_EXPORT int CheckCVMList(char *pszCVM,int nNum);
LIB_EXPORT int GetOnlinePin(void);
/**< --------------------------emv_ec------------------------------------------------------------------*/
/**< --------------------------emv_off_auth-------------------------------------------------------------*/
LIB_EXPORT int OffAuth_DDA(unsigned char cCertType);
LIB_EXPORT int OffAuth_SDA();
LIB_EXPORT int OffAuth_SM_DDA(char cCertType);
LIB_EXPORT int OffAuth_CDA_First();
LIB_EXPORT int get_sm_terminal(void);
LIB_EXPORT int Emv_OffAuth();
LIB_EXPORT int RetrievePk(char cCertType,STRSA *stInPK,STRSA *IssPk);
LIB_EXPORT int RetrieveData(unsigned char cCertType,STRSA *stInPK);
LIB_EXPORT int RSARecover(const STRSA *stPk,char *pszCert,int nCertLen,char *pszData,int *nLen);
LIB_EXPORT int CheckCert(unsigned char cCertType,uchar *pszCert, int nCertLen,STCERT *stInCert);
LIB_EXPORT int CheckExceptionFile();
/**< --------------------------emv_proce_restrict--------------------------------------------------------*/

/**< --------------------------emv_read_data------------------------------------------------------------*/
LIB_EXPORT int Emv_Read_AppData(char *cTransMode);
/**< --------------------------emv_sel_app-------------------------------------------------------------*/
LIB_EXPORT int SelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
LIB_EXPORT int LC_rf_SelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
LIB_EXPORT int GetICCAID(pTlvData tlv,int nNum,ST_ICCAID *stICCAID,YESORNO bIssCodeIndex);
LIB_EXPORT void SortAIDList(ST_ICCAID stICCAID[],int nAIDNum);
LIB_EXPORT void Rf_SortAIDList(ST_RF_ICCAID stICCAID[],int nAIDNum);

/**< --------------------------emv_complete-------------------------------------------------------------*/
LIB_EXPORT void ProcIssScript(int nFlag,char *pszScriptRes,int *nLen);

LIB_EXPORT int ParseIssData(void);
LIB_EXPORT int EC_GetECBalance();

//非接公用API
LIB_EXPORT int rf_pin_proc(char *cSignature);
LIB_EXPORT int Rf_GetGPOData(char *pszDol,int nDolLen);
LIB_EXPORT int RF_CheckExceptionFile();
LIB_EXPORT int Rf_Amount_Check();
LIB_EXPORT void CalcTCHash(void);
LIB_EXPORT int PraseGAC(int nGacStep,E_GAC eGacType,char *pszGACData,int nDataLen,STEMVPROC *stProc);
LIB_EXPORT int InterpretCid_Low(uchar cid);
LIB_EXPORT int PBOC_ReadLog(void);
LIB_EXPORT int Upload_PBOC_ReadLog(void);

#ifdef __cplusplus
}
#endif

#endif
