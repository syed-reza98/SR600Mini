#ifndef __RF_JCB_API__
#define __RF_JCB_API__


#include "emv_interface.h"

//结果码
#define JCB_RET_SUCC							0		//交易成功
#define JCB_RET_FAIL							1		//交易失败
#define JCB_RET_TERMINAL						2		//交易中止
#define JCB_RET_SELECT_NEXT						3		//选择下一条应用
#define JCB_RET_TRY_AGAIN						4		//重新挥卡
#define JCB_RET_CDV_TRY_AGAIN					5		//重新挥卡
#define JCB_RET_TRY_ANOTHER_INTERFAGE			6		//尝试其他界面
#define JCB_RET_DATA_FORMAT_ERR					7		//数据格式错误
#define JCB_RET_REFUSE							8		//交易拒绝
#define JCB_RET_SW_NOT_9000						9

//交易模式
#define  JCB_TRANMODE_UNDEFINE	0
#define  JCB_TRANMODE_EMV		1
#define  JCB_TRANMODE_MAG		2
#define  JCB_TRANMODE_LEGACY	3


LIB_EXPORT extern int JCB_iTranFlow(STEMVPROC *stProc);
LIB_EXPORT extern int JCB_iFinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT extern int JCB_iCompelte(STEMVPROC *stProc);

#endif

