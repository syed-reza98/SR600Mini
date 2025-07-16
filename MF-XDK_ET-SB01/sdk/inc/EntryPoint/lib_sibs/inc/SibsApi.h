#ifndef __RF_SIBS_API__
#define __RF_SIBS_API__

#include "emv_interface.h"

//返回码
#define SIBS_RET_SUCC						0
#define SIBS_RET_TERMINAL					1		//交易中止
#define SIBS_RET_SELECT_NEXT				2		//选择下一条应用
#define SIBS_RET_TRY_AGAIN					3		//重新挥卡
#define SIBS_RET_TRY_AGAIN_CDV				4		//移动设备重新挥卡
#define SIBS_RET_ERR_TRY_OTH				5		//尝试其他界面，交易中止

	
LIB_EXPORT int SIBS_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);	

#endif