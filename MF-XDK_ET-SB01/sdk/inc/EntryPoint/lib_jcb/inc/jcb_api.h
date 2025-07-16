#ifndef __RF_JCB_API__
#define __RF_JCB_API__


#include "emv_interface.h"

//�����
#define JCB_RET_SUCC							0		//���׳ɹ�
#define JCB_RET_FAIL							1		//����ʧ��
#define JCB_RET_TERMINAL						2		//������ֹ
#define JCB_RET_SELECT_NEXT						3		//ѡ����һ��Ӧ��
#define JCB_RET_TRY_AGAIN						4		//���»ӿ�
#define JCB_RET_CDV_TRY_AGAIN					5		//���»ӿ�
#define JCB_RET_TRY_ANOTHER_INTERFAGE			6		//������������
#define JCB_RET_DATA_FORMAT_ERR					7		//���ݸ�ʽ����
#define JCB_RET_REFUSE							8		//���׾ܾ�
#define JCB_RET_SW_NOT_9000						9

//����ģʽ
#define  JCB_TRANMODE_UNDEFINE	0
#define  JCB_TRANMODE_EMV		1
#define  JCB_TRANMODE_MAG		2
#define  JCB_TRANMODE_LEGACY	3


LIB_EXPORT extern int JCB_iTranFlow(STEMVPROC *stProc);
LIB_EXPORT extern int JCB_iFinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT extern int JCB_iCompelte(STEMVPROC *stProc);

#endif

