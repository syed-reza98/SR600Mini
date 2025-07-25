#ifndef __EMV_LOCAL_API__
#define __EMV_LOCAL_API__ 

#include <data.h>
#include <emv_interface.h>
#include <define.h>

#ifdef __cplusplus
extern "C"{
#endif


/**< --------------------------emv_act_analy-------------------------------------------------------------*/
#define MAXLEN_ISSAPPDATA 32
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_cardholder_verify-----------------------------------------------------*/
/**< ---------------------------------------------------------------------------------------------------*/

/**< ---------------------------------emv_ec-------------------------------------------------------------*/
#define LEN_EC_IAC 6
#define LEN_EC_BALANCE 6
#define LEN_EC_THRESHOLD 6
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_off_auth-------------------------------------------------------------*/
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_off_auth_sm-----------------------------------------------------------*/
typedef struct
{
	uchar ucXa[64+1];
	uchar ucYa[64+1];
}STSM;
/**< ---------------------------------------------------------------------------------------------------*/


/**< ---------------------------------------------------------------------------------------------------*/
//内部调用API接口
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_act_analy-------------------------------------------------------------*/
extern int GetGACData(char *pszData, int nLen, YESORNO cCDAFlag);
extern int SM_CDA_GAC(int nGacStep, char *pszGacRes, int nGacLen);
extern int Emv_act_analy(STEMVPROC *stProc);
/**< ---------------------------------------------------------------------------------------------------*/


/**< --------------------------emv_cardholder_verify-----------------------------------------------------*/
//外部调用API接口
extern int Emv_Ch_Verify(STEMVPROC *stProc);
/**< ---------------------------------------------------------------------------------------------------*/


/**< --------------------------emv_complete-------------------------------------------------------------*/
//外部调用API接口
extern int Emv_Compelte(STEMVPROC *stProc);
/**< ---------------------------------------------------------------------------------------------------*/


/**< --------------------------emv_ec------------------------------------------------------------------*/
extern int EC_GetOnlinePin();
//外部调用API接口

extern int EC_ReadData(char *cTransMode);
extern int EC_GetGacType(E_GAC *eGacType,char cTransMode);
/**< ---------------------------------------------------------------------------------------------------*/


/**< --------------------------emv_init_app-------------------------------------------------------------*/
//外部调用API接口
extern int Emv_Init_App();
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_off_auth-------------------------------------------------------------*/
extern int CDA_GAC(int nGacStep, char *pszGacRes, int nGacLen);
extern int GetPinPk(XM_RSA_PUBLIC_KEY *pk);
extern int GetCAPK_EX(STRSA *pk);
extern int GetCAPK(STRSA *pk);
extern int GetCertInfo(char cCertType,STCERT *stCert);
extern int GetAuthData(unsigned char cCertType,char *pszData,int *nLen);
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_off_auth_sm-----------------------------------------------------------*/
extern int CalcSM2(STSM *stSm,unsigned char *r, unsigned char *s, unsigned char *msg, unsigned int msglen);
extern int Emv_SM_OffAuth();

/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_proce_restrict--------------------------------------------------------*/
extern void Emv_Process_Restrict();
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_read_data------------------------------------------------------------*/

/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_risk_mana------------------------------------------------------------*/
extern void Emv_risk_mana(YESORNO bForceOnline,char cTransMode);
/**< ---------------------------------------------------------------------------------------------------*/

/**< --------------------------emv_sel_app-------------------------------------------------------------*/
extern int Emv_Sel_App(char cTransType,int nEmvTransSerial,E_INPUTAMT eInputAMT);
/**< ---------------------------------------------------------------------------------------------------*/

void set_RequestCDA(YESORNO bvalue);
YESORNO get_RequestCDA(void);


#ifdef __cplusplus
}
#endif

#endif
