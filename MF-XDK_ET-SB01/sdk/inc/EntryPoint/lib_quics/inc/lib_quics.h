#ifndef __LIB_QUICS__
#define __LIB_QUICS__

#include "emv_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**< --------------------------------------------------------------------------------------------------*/
/*QUICS函数API及专用参数*/
#define RET_SHANKA				-99		//闪卡失败返回值
#define RET_NOT_SAMECARD		-98		//闪卡判断不是原卡
#define RET_DEL_RECORD			-97		//删除闪卡记录，保留失败交易记录 提示交易失败
#define	RET_SHANKA_ERR			-96		//提示读卡失败，保留闪卡记录和失败交易记录
#define RET_SHANKA_SUCC			-100	//删除闪卡记录，删除失败交易记录 交易成功
#define	BIN_LEN					3
typedef struct {
	char sFaildata[512];//闪卡保存的IC数据
	int ndatalen;
	char cRecordNo;//记录卡号的记录号
	char cSfi;//记录卡号的SFI
	char clRecordNo;//闪卡的记录号
	char clSfi;//闪卡的SFI
	unsigned int nFailtick;//闪卡失败时间
}ST_QFAIL_DATA;

typedef struct {
	char nCardlen;
	char szBIN[BIN_LEN];	/**<BIN表*/
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
	char bTest;//测试开关
	char bSet;//是否被设置过 正式应用上不被设置，则按照默认值配置 从而不影响正常使用
}ST_QPBOC_PROC;
LIB_EXPORT extern int Qpboc_set(ST_QPBOC_PROC*qparam);
LIB_EXPORT extern int Qpass_add_begin(int binType, int max);
LIB_EXPORT extern int Qpass_add_end(int binType);
LIB_EXPORT extern int Qpass_IsInBin(char* sCard,int binType);//卡号是否在卡BIN表内 
LIB_EXPORT extern int Qpass_Add_Bin(ST_BIN_DATA *pBin, int binType);
LIB_EXPORT extern int UpCard_Deal(char* pszPan, char* pszTrack2, char* pszTrack3, char* pszExpDate, char* pszField55, int* pnField55Len);

/**< 读取PBOC LOG*/
LIB_EXPORT extern int PBOC_ReadTransLog(const char cSfi, const char cRecordNo, char * psResponse, int * pnDataLen);

#ifdef __cplusplus
}
#endif


#endif
