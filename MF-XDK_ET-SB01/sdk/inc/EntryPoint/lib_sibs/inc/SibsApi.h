#ifndef __RF_SIBS_API__
#define __RF_SIBS_API__

#include "emv_interface.h"

//������
#define SIBS_RET_SUCC						0
#define SIBS_RET_TERMINAL					1		//������ֹ
#define SIBS_RET_SELECT_NEXT				2		//ѡ����һ��Ӧ��
#define SIBS_RET_TRY_AGAIN					3		//���»ӿ�
#define SIBS_RET_TRY_AGAIN_CDV				4		//�ƶ��豸���»ӿ�
#define SIBS_RET_ERR_TRY_OTH				5		//�����������棬������ֹ

	
LIB_EXPORT int SIBS_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);	

#endif