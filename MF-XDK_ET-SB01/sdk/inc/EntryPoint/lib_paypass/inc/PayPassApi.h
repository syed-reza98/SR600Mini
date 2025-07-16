#ifndef __RF_PAYPASS_API__
#define __RF_PAYPASS_API__

#include "emv_interface.h"

//#define MASTER_TEST 1

//������
#define PP_RET_SUCC							0
#define PP_RET_TERMINAL						1		//������ֹ
#define PP_RET_SELECT_NEXT					2		//ѡ����һ��Ӧ��
#define PP_RET_MAGSTRIPE_NOT_SUPPORTED		3		//����ģʽ��֧��,������ֹ
#define PP_RET_TRAN_AMOUNT_NOT_EXIST		4		//���׽����ڣ�������ֹ
#define PP_RET_TRY_AGAIN					5		//���»ӿ�
#define PP_RET_TRY_AGAIN_CDV				6		//�ƶ��豸���»ӿ�
#define PP_RET_ERR_TRY_OTH					7		//�����������棬������ֹ
#define PP_RET_PDOL_MISS					8		//PDOL MISS ������ֹ
#define PP_RET_FIRST_WRITE_FLAG_TIME_OUT    9		//��һ��д��־Ϊ�գ�������ֹ
#define PP_RET_USER_STOP					10		//�û�ȡ����������ֹ
	
LIB_EXPORT int PP_iFreeTranRelateBuf(void);
LIB_EXPORT int PayPass_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);//PAYPASS ADF����
LIB_EXPORT void PayPass_iAppSelectErrProc(OUTCOME_ERR_TYPE iErrorCode,int iStep);

//PPSE�׶δ����봦��
LIB_EXPORT int PP_PPSE_ErrorProcess(int iResultCode);

//ֹͣ�ͺŴ���
LIB_EXPORT int PP_iCheckStopSignal(int iStep);

LIB_EXPORT int PayPass_iDataInit(void);

#endif