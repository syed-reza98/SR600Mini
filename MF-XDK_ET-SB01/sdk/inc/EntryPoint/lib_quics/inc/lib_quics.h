#ifndef __LIB_QUICS__
#define __LIB_QUICS__

#include "emv_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**< --------------------------------------------------------------------------------------------------*/
/*QUICS����API��ר�ò���*/
#define RET_SHANKA				-99		//����ʧ�ܷ���ֵ
#define RET_NOT_SAMECARD		-98		//�����жϲ���ԭ��
#define RET_DEL_RECORD			-97		//ɾ��������¼������ʧ�ܽ��׼�¼ ��ʾ����ʧ��
#define	RET_SHANKA_ERR			-96		//��ʾ����ʧ�ܣ�����������¼��ʧ�ܽ��׼�¼
#define RET_SHANKA_SUCC			-100	//ɾ��������¼��ɾ��ʧ�ܽ��׼�¼ ���׳ɹ�
#define	BIN_LEN					3
typedef struct {
	char sFaildata[512];//���������IC����
	int ndatalen;
	char cRecordNo;//��¼���ŵļ�¼��
	char cSfi;//��¼���ŵ�SFI
	char clRecordNo;//�����ļ�¼��
	char clSfi;//������SFI
	unsigned int nFailtick;//����ʧ��ʱ��
}ST_QFAIL_DATA;

typedef struct {
	char nCardlen;
	char szBIN[BIN_LEN];	/**<BIN��*/
	char cResv;
}ST_BIN_DATA;

typedef struct {
	char bQpboc_path;
	int  nQfail_time;
	int	 nQfail_totaltime;
	//char bQpass;
	long long lQpass_Amount;
	char bQbina;
	char bQbinb;
	char bQsign;
	long long lQsign_Amount;
	char bEctype;
	char bCdcvm;
	char bQuick;
	int nQfailcount;
	char bTest;//���Կ���
	char bSet;//�Ƿ����ù� ��ʽӦ���ϲ������ã�����Ĭ��ֵ���� �Ӷ���Ӱ������ʹ��
}ST_QPBOC_PROC;
LIB_EXPORT extern int Qpboc_set(ST_QPBOC_PROC*qparam);
LIB_EXPORT extern int Qpass_add_begin(int binType, int max);
LIB_EXPORT extern int Qpass_add_end(int binType);
LIB_EXPORT extern int Qpass_IsInBin(char* sCard,int binType);//�����Ƿ��ڿ�BIN���� 
LIB_EXPORT extern int Qpass_Add_Bin(ST_BIN_DATA *pBin, int binType);
LIB_EXPORT extern int UpCard_Deal(char* pszPan, char* pszTrack2, char* pszTrack3, char* pszExpDate, char* pszField55, int* pnField55Len);

/**< ��ȡPBOC LOG*/
LIB_EXPORT extern int PBOC_ReadTransLog(const char cSfi, const char cRecordNo, char * psResponse, int * pnDataLen);

#ifdef __cplusplus
}
#endif


#endif
