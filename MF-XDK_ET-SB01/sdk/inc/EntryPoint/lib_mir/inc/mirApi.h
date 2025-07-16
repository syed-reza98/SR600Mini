#ifndef __RF_MIR_API__
#define __RF_MIR_API__

#include "emv_interface.h"

//������
#define MIR_RET_SUCC						0
#define MIR_RET_TERMINAL					1		//������ֹ
#define MIR_RET_SELECT_NEXT				2		//ѡ����һ��Ӧ��
#define MIR_RET_TRY_AGAIN					3		//���»ӿ�
#define MIR_RET_TRY_AGAIN_CDV				4		//�ƶ��豸���»ӿ�
#define MIR_RET_ERR_TRY_OTH				5		//�����������棬������ֹ

	
LIB_EXPORT int MIR_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT int MIR_iPPSEErrorProcess(int iResultCode);

#endif