#ifndef __RF_PAYPASS_API__
#define __RF_PAYPASS_API__

#include "emv_interface.h"

//#define MASTER_TEST 1

//返回码
#define PP_RET_SUCC							0
#define PP_RET_TERMINAL						1		//交易中止
#define PP_RET_SELECT_NEXT					2		//选择下一条应用
#define PP_RET_MAGSTRIPE_NOT_SUPPORTED		3		//磁条模式不支持,交易中止
#define PP_RET_TRAN_AMOUNT_NOT_EXIST		4		//交易金额不存在，交易中止
#define PP_RET_TRY_AGAIN					5		//重新挥卡
#define PP_RET_TRY_AGAIN_CDV				6		//移动设备重新挥卡
#define PP_RET_ERR_TRY_OTH					7		//尝试其他界面，交易中止
#define PP_RET_PDOL_MISS					8		//PDOL MISS 交易中止
#define PP_RET_FIRST_WRITE_FLAG_TIME_OUT    9		//第一次写标志为空，交易中止
#define PP_RET_USER_STOP					10		//用户取消，交易中止
	
LIB_EXPORT int PP_iFreeTranRelateBuf(void);
LIB_EXPORT int PayPass_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);//PAYPASS ADF流程
LIB_EXPORT void PayPass_iAppSelectErrProc(OUTCOME_ERR_TYPE iErrorCode,int iStep);

//PPSE阶段错误码处理
LIB_EXPORT int PP_PPSE_ErrorProcess(int iResultCode);

//停止型号处理
LIB_EXPORT int PP_iCheckStopSignal(int iStep);

LIB_EXPORT int PayPass_iDataInit(void);

#endif