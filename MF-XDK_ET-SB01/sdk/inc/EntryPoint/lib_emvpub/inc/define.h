#ifndef _DEFINE_H_
#define _DEFINE_H_

#include<string.h> 
#include<ctype.h>  
//modified by zhiyu 0923
//#include<malloc.h>  
#include<limits.h>  
#include<stdio.h>   
#include<stdlib.h>  
#include<math.h>  
#include<time.h>
/**<api*/

#include "mf_basic.h"
#include "pub_define.h"

#include "emv_tag.h"
#include "emv_err_code.h"

/**<publib*/
#include "struct_hashtable.h"
#include "ex_convert.h"
#include "dev_file.h"
#include "printfdebug.h"


//����malloc��ͷ�ļ� add by zhiyu 0929 
#include "pub/common/misc/inc/mfmalloc.h"

//typedef unsigned char BYTE;

//#define EMV_PINPAD_VERSION	"EMV4.3G_PINPAD-V1.01"
//#define  L2_APPROVE  1  //1 - L2��֤ʱ�궨�忪��   0-Ĭ���ύ�����ã�SVNֻ�ϴ�Ϊ0�İ汾����ǰ������Ӧ�÷����п�Ƭ����tagһ��������ֹ

//#define AUTO_APPROVE	1 //�Զ������Կ��� ����BCTC�Ĳ��Ժ�̨ʱ������
//#define DPAS_APPROVE	1



#define MAXLEN_PAN 19
#define MAXLEN_TRACK2 37

#define MAXLEN_FILE		255
#define MAXDOL_LEN		256
#define MAXLEN_ICCRESP  MAXDOL_LEN//512 
 
#define TABLESIZE(table)    (sizeof(table)/sizeof(table[0]))

typedef enum {
	GAC_AAC = 0,	
	GAC_ARQC,
	GAC_TC,
	GAC_AAR,
	GAC_TOTAL
}E_GAC;
typedef enum{
	DRL_VISA = 0,
	DRL_AMEX
}DRL_TYPE;

#define FALSE 0
#define TRUE (!FALSE)


#define SUCC		0
#define FAIL		(-1)
#define QUIT		(-2)
#define TIMEOUT		(-3)
#define GOTO		(-4)
#define UNKNOW		(-5)
//#define UNSUPPORT	(-6)
//#define TERMINATE	(-7)
//#define GOTOCONTACT (-8)
//#define GOTOOTHER	(-9)
//#define	GOTOUPCARD	(-10)
//#define GOTO_TRYAGAIN		(-11)		//���»ӿ�
//#define GOTO_CDV_TRYAGAIN	(-12)		//�ƶ��豸���»ӿ�
#define L1_ERROR	(-13)				//L1������--����L1������,L1�Ĵ������Ǹ�ֵ,���ܻ��nRet�ظ�
#define GOTO_DPAS_ZIP	(-14)
#define GOTO_DPAS_MS	(-15)
//#define GOTOOTHERCARD	(-16)
#define RP_GOTO_2_TAP	(-17)
#define EMV_ERR_ICCOP_ERR (-18) //APDUδ�յ����أ�L1�����Ҫ����Ѱ��
#define EC_ONLY_ERR_RET	(-19)	// �жϵ��������ֽ𷵻�
#define EMV_ERR_INITAPP	(-20)	//��ʼ��Ӧ�ô��� 


#define EQ(a,b) ((a)==(b))  
#define LT(a,b) ((a)<(b))  
#define LQ(a,b) ((a)<=(b))
#define GETBIT(Data,bit)     ((Data&(1<<(bit-1)))>>(bit-1))

#define SETBIT(Data,bit)     (((Data |(1<<(bit-1))))

#define CLRBIT(Data,bit)   ((Data &(~(1<<(bit-1)))))


//#define MAXLEN_AUTHDATA   1500  
#define MAXLEN_AUTHDATA   (2048+512)		//paypass�����ѻ�ǩ������2048--�ָ�IC����Կ����hash�ռ�2048+512

#define MAXNUM_AIDCONTAIN  100	//�ն�֧�ֵ�AID��������
#define MAXNUM_AIDLIST 22		//��ѡ�б�AID��������


#ifdef WIN32
//#define __func__ "func" 
#endif

typedef enum {
	ERR_NONE = 0,	
	ERR_PARAM,	
	ERR_COMM,		
	ERR_MEM,		

	ERR_TIMEOUT,	
	ERR_INTR,	

	ERR_UNSUPPORT,	
	ERR_USR_CANCEL,	

	ERR_I2C,			

	ERR_KEY_INVALID,	
	ERR_KEY_FETCH,	
	ERR_KEY_SAVE,		
	ERR_AUTH_FAILED,	
	ERR_COND_NOTMET,	
	ERR_KEY_LIMIT,		

	ERR_RSA_FAILED,	
	ERR_ICC_DEV,		
	ERR_OFFLINE_PIN_FAILED,	
	ERR_PIN_EMPTY,	

	ERR_CONNECT, 
	ERR_SENDDATA, 
	ERR_NODATA, 
	ERR_MEMOPER, 
	ERR_DATATOOBIG, 

	ERR_MAX
}ERR_CODE;

//char szEmvData[8000];

/**< --------------------------emv_off_auth-------------------------------------------------------------*/
#define MAXLEN_MODULUS 		248
#define CERT_HEADER		0x6A	/**<֤������ͷ*/
#define CERT_TAILER		0xBC	/**<����β*/

/**<֤�����ͣ����е�4�ֽ�Ϊ֤���ʽ*/
#define TYPE_CERT_ISSPK		0x02		/**<�����й�Կ֤���ʽ*/
#define TYPE_CERT_SSAD		0x03		/**<ǩ����̬Ӧ�����ݸ�ʽ*/
#define TYPE_CERT_ICCPK		0x04		/**<IC����Կ֤���ʽ*/
#define TYPE_CERT_DSD		0x05		/**<��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_FDSD		0x06		/**<���ٶ�̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_ODADSD		0x95		/**<ODA��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_CDSD		0x25		/**<������֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_PIN		0x24		/**<PIN֤���ʽ*/
#define TYPE_CERT_QDDA		0x26		/**RUPAY QDDA��֤*/

#define	TYPE_CERT_SM_ISSPK	0x12		/**< ����SM2�㷨�ķ����й�Կ֤���ʽ*/
#define	TYPE_CERT_SM_SSAD	0x13		/**< SM2ǩ����̬Ӧ�ø�ʽ*/
#define TYPE_CERT_SM_ICCPK	0x14		/**<SM2�㷨IC����Կ֤���ʽ*/
#define TYPE_CERT_SM_DSD	0x15		/**<SM2�㷨��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_SM_ODADSD	0xA5		/**SM2<ODA��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_SM_FDSD	0x16		/**<���ٶ�̬��֤��̬ǩ�����ݸ�ʽ*/
#define ALG_PK_NONE	Ox00
#define ALG_PK_RSA		0x01
#define ALG_PK_SM2		0x04

#define ALG_HASH_SHA1	0x01
#define ALG_HASH_SM3	0x07

typedef struct
{
	char cIndex; 				/**<ע�����Ĺ�Կ����*/
	char szCert[248];		/**<��Կ֤��*/
	int	 nCertLen;		/**<��Կ֤�鳤��*/
	char szpkRemainder[248];	/**<��Կ����*/
	int	nRemainderLen;		/**<��Կ�����*/
	char	szIsspkExp[3];			/**<��Կָ��*/
	int	nExpLen;			/**<��Կָ������*/
	char	szpan[10];			/**<IC�����ʺ�*/
	int	nPanLen;			/**<���ʺų���*/
}STCERT;

typedef struct
{
	uchar uiLen;
	uchar ucModulus[MAXLEN_MODULUS];  
	uchar ucExponent[3];
}STRSA;

/**< --------------------------emv_cardholder_verify-----------------------------------------------------*/
#define MAXLEN_CVM	252

#define CVM0_CON_FAIL				0x00	/**<CVM����ʧ��*/
#define CVM0_CON_PLAINPIN			0x01	/**<IC�����е�����PIN��֤*/
#define CVM0_CON_ONLINEPIN			0x02	/**<��������PIN��֤*/
#define CVM0_CON_PLAINPIN_SIG		0x03	/**<IC�����е�����PIN��֤��ǩ����ֽ�ϣ�*/
#define CVM0_CON_ENCIPHPIN			0x04	/**<IC�����еļ���PIN��֤*/
#define CVM0_CON_ENCIPHPIN_SIG		0x05	/**<IC�����еļ���PIN��֤��ǩ����ֽ�ϣ�*/
#define CVM0_CON_SIG				0x1E	/**<ǩ����ֽ�ϣ�*/
#define CVM0_CON_NOCVM				0x1F	/**<����CVM*/
#define CVM0_CON_CERT				0x20	/**<�ֿ��˳�ʾ֤��*/
#define CVM0_CON_CONFIRM_CODE       0x24    /**pure*/

#define CVM1_CON_ALL		0x00	/**<����*/
#define CVM1_CON_ATM		0x01	/**<ATM������ֽ����*/
#define CVM1_CON_NOCASH	0x02	/**<��������ֽ����*/
#define CVM1_CON_CVM		0x03	/**<����ն�֧��CVM*/
#define CVM1_CON_MANUAL	0x04	/**<������˹�ֵ���ֽ���*/
#define CVM1_CON_CASHBACK	0x05	/**<����Ƿ��ֽ���*/
#define CVM1_CON_LX			0x06	/**<���������Ӧ�ñ��ֽ�������ֵС��X*/
#define CVM1_CON_GX		0x07	/**<���������Ӧ�ñ��ֽ�������ֵ����X*/
#define CVM1_CON_LY			0x08	/**<���������Ӧ�ñ��ֽ�������ֵС��Y*/
#define CVM1_CON_GY		0x09	/**<���������Ӧ�ñ��ֽ�������ֵ����Y*/

#define VERIFY_PLAIN	0x00	/**<����PIN��֤*/
#define VERIFY_ENCYPT	0x01	/**<����PIN��֤*/

/**<CVM�����3�ֽ�*/
#define CVM_RESULT_SUCC	0x02		/**<�ɹ�*/
#define CVM_RESULT_FAIL	0x01		/**<ʧ��*/
#define CVM_RESULT_UNKNOW	0x00		/**<δ֪(ǩ��)*/

#define CVMR3_UNKNOW_ONLINE		0x10	/**<����*/	
#define CVMR3_UNKNOW_SIGNATRUE	0x20	/**<ǩ��*/
#define CVMR3_UNKNOW_OTHER		0x30	/**<����*/

#define VISA_AAC	1
#define	VISA_ARQC	2
#define	VISA_TC		3
#define	VISA_OTHER	4//ת��������

#define SCRIPT_RES_SIZE		10//���ű�����
#define MAXLEN_ISSSCRIPT 256


#define ISS_IDD_ECBAL			0x01	/**< �����ֽ����*/
#define ISS_IDD_CTTA			0x02	/**< �ۻ������ܶ�*/
#define ISS_IDD_ECBAL_CTTA		0x03	/**< �����ֽ�����CTTA*/
#define ISS_IDD_CTTA_CTTAL		0x04	/**< CTTA��CTTAL*/
#define ISS_IDD_OFFBAL			0x05	/**< �����ѻ����ѽ��*/



#define EMV_RF_PROP_MSD			0x0080		/**< 1:֧�ַǽӴ����� (MSD) ,0:��֧��*/
#define EMV_RF_PROP_PBOCCLSS		0x0040		/**< 1:֧�ַǽӴ�PBOC,0:��֧��*/
#define EMV_RF_PROP_QPBOC			0x0020		/**< 1:֧�ַǽӴ�qPBOC,0:��֧��*/
#define EMV_RF_PROP_PBOC			0x0010		/**< 1:֧�ֽӴ�PBOC,0:��֧��*/
#define EMV_RF_PROP_OFFLINE_ONLY	0x0008		/**< 1:��д����֧���ѻ�
											    		0:��д��������������*/
#define EMV_RF_PROP_ONLINEPIN		0x0004		/**< 1:֧������PIN,0:��֧��*/
#define EMV_RF_PROP_SIGNATURE		0x0002		/**< 1:֧��ǩ��,0:��֧��*/
#define EMV_RF_PROP_ODA			0x0001	//��1�ֽڵ�1λ֧��ODA

#define EMV_RF_PROP_ONLINE			0x0180		/**< 1:Ҫ����������,0:��Ҫ��*/			
#define EMV_RF_PROP_CVM			0x0140		/**< 1:Ҫ��CVM,0:��Ҫ��*/
#define EMV_RF_TM_CDCVM			0x0240		/**< 1:֧��CDCVM,0:��֧��*/
#define EMV_RF_PROP_FDDA        0x80000000  /**< �ն�֧��01�汾��FDDA **/
#define EMV_RF_PROP_ISSUSER_SCRIPT    0x0280  // �����нű��Ƿ�֧�� �ֽ�3λ8
#define EMV_RF_PROP_MOBILE    0x0240  //mobile 

#define UN_RF_PROP_ONLINEPIN		0xFFFB		/**< 1:֧������PIN,0:��֧��*/
#define UN_RF_PROP_SIGNATURE		0xFFFD		/**< 1:֧��ǩ��,0:��֧��*/


/*9F6C �����صĿ�Ƭ��������*/
#define VISA_CARD_CASH_DECLIEN			0x0004	/**< VISA - (�޷���Ӧ����;���ƻ��ֽ�Ӧ����Ч�����ֽ����л�����������)Switch Interface for Cash Transactions(Application Usage Control - Cash Transactions),��VISA 'Req 5.76'*/
#define VISA_CARD_CASHBACK_DECLIEN		0x0002	/**< VISA - Switch Interface for Cashback Transactions(Application Usage Control - Cashback Transactions'*/
#define EMV_CARD_PROP_ONLINEPIN			0x0080	/**< ��Ҫ����PIN*/
#define EMV_CARD_PROP_SIANATURE			0x0040	/**< ��Ҫǩ��*/
#define EMV_CARD_PROP_DAFAIL_ONLINE		0x0020	/**< ����ѻ�������֤ʧ�ܶ��ҿ�������Ҫ������*/
#define EMV_CARD_PROP_DAFAIL_PBOCTERMIN	0x0010	/**< ����ѻ�������֤ʧ�ܶ����ն�֧��PBOC����ֹ*/
#define EMV_CARD_PROP_EXPIR_ONLINE		0x0008	/**< ���Ӧ�ù��ڣ���������*/
#define EMV_CARD_PROP_CDCVM				0x0180		/**< CDCVM�Ƿ�ִ�У� 1-CDCVM��ִ�У�0-CDCVMδִ��*/
#define EMV_CARD_PROP_ISSUSER_SCRIPT	0x0140		// �����нű��Ƿ�֧�֣��ֽ�2 λ7

//PURE TTPI �ڶ��ֽ�����
#define PURE_PROP_ONLINE			0x0180		//require online
#define PURE_PROP_CVM				0x0140		//require Cvm
#define PURE_PROP_STATIC_CHECK	0x0120		//static check require
#define PURE_PROP_ZERO_CHECK		0x0110		//zero check require

#endif