#ifndef __RF_RUPAY_API__
#define __RF_RUPAY_API__


#include "emv_interface.h"

//结果码
#define RUPAY_RET_SUCC							0		//交易成功
#define RUPAY_RET_TERMINAL						1		//交易中止
#define RUPAY_RET_SELECT_NEXT					2		//选择下一条应用
#define RUPAY_RET_TRY_AGAIN						3		//重新挥卡
#define RUPAY_RET_TURN_NEXT                       4       //继续下一个流程


LIB_EXPORT extern int RuPay_iTranFlow(STEMVPROC *stProc);
LIB_EXPORT extern int RuPay_iDestroy(void);
LIB_EXPORT extern int RuPay_Compelte(STEMVPROC *stProc);
LIB_EXPORT extern int RuPay_AppUnBlock(STEMVPROC *stProc);
LIB_EXPORT extern int RuPay_RF_PreProcess(STEMVPROC *stProc);
LIB_EXPORT extern int RUPAY_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
LIB_EXPORT extern int RuPay_Rf_2TAP_iTrans(STEMVPROC *stProc);

#endif

