#ifndef _TOOL_
#define _TOOL_

#include "apppub/inc/mf_basic.h"
#include "apppub/inc/pub_def.h"
#include "emv_interface.h"

/*	9F10�з��صĽ��ױ�ʶ*/
#define	IAD_AAC(x )				(( *((x) + 4) & 0x30) == 0x00 )
#define	IAD_TC(x )				(( *((x) + 4) & 0x30) == 0x10 )
#define	IAD_ARQC(x )			(( *((x) + 4) & 0x30) == 0x20 )
#define IAD_FCHECK(x)			( *((x) + 5) & 0x20) 		/*��ƬƵ�ȼ�鳬��λ:
														�����ֽ𵥱ʽ����޶�
														�����ֽ�����
														��Ȩ������ CTTA ���� CTTAUL
														���С�ڵ����ֽ�������ֵ*/

LIB_EXPORT unsigned long long BcdtoUint64( unsigned char *pszBcdBuf,  int nBufLen);
LIB_EXPORT int IntTo4Bcd(char *psBcd, int *pnBcdLen, int nNum);
LIB_EXPORT int Rf_Get_Amt(unsigned char cTransType);
LIB_EXPORT int Emv_Get_Amt();
LIB_EXPORT int VisaGetAmount(unsigned char cTransType);

LIB_EXPORT int GetPanFromTrack(const char *pszTrack,int nMaxTrackLen,int *nPanLen,char *sPan);
/******************************************************************************
 *  	��������:	RecoverTrack2: 
 *	��������:	��ԭ���ŵ��ȼ�����Ϊ���ŵ�����
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
LIB_EXPORT int RecoverTrack2(char *psInTrack2,int nLen,char *psOutTrack2,int *nOutLen);
/******************************************************************************
 *  	��������:	GetExpiryFromTrack2: 
 *	��������:	�Ӷ��ŵ����ݻ�ȡ��Ч��
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
LIB_EXPORT int GetExpiryFromTrack2(const char *pszTrack,int nMaxTrackLen,char *sExpiry);

LIB_EXPORT int Emv_Input_Amt(unsigned char cTransType);

LIB_EXPORT YESORNO BeforeDate(uchar *pszDate,int nlen);
LIB_EXPORT YESORNO AfterDate(uchar *pszDate);

LIB_EXPORT int CheckAppVer();
LIB_EXPORT int CheckAUC();

LIB_EXPORT int CheckAppData();

LIB_EXPORT int CheckExpireDate();
LIB_EXPORT int CheckEffecDate();

//�ǽ�ͨ�ýӿ�
LIB_EXPORT YESORNO rf_GetICTransPropIsSet(int nMask);
LIB_EXPORT YESORNO rf_GetTmTransPropIsSet(int nMask);
LIB_EXPORT void rf_SetTmTransProp( int iSetMask);

LIB_EXPORT int rf_get_pan_len(char*sData, int nLen);
LIB_EXPORT int rf_aflcheck(char *szData,int nDataLen);
LIB_EXPORT int rf_aflcheck_visa(char *szData,int nDataLen);
LIB_EXPORT int rf_check_pan(char*pszTrack,int nMaxTrackLen);
LIB_EXPORT int rf_quic_ccid(char*szIssAppData,YESORNO*bccid);

LIB_EXPORT YESORNO dpas_GetCardPropRequireIsSet(int nMask);
LIB_EXPORT void dpas_SetCardPropRequire( int iSetMask);

LIB_EXPORT void pure_set_tag_bit(char *tag,int iSetMask);
LIB_EXPORT YESORNO pure_get_tag_bit(char *tag,int nMask);

#endif
