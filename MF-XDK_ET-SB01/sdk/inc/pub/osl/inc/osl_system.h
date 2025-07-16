/*! \file osl_system.h
	\brief 系统功能
*	\author lx
*	\date 2014/02/08
*/
#ifndef _OSL_SYSTEM_H_____
#define _OSL_SYSTEM_H_____

#include "pub\pub.h"

#ifdef OS_LINUX
	#define EX_FLASH_BASE_ADDR	(0x0)
#else
	#define EX_FLASH_BASE_ADDR	(0x0)
#endif



typedef struct __st_et330_data{
	int nReset;		//参数否被初始化过,
	char factdata[256];		//出厂数据保存位置
	int usb_mode;   //usb模式
	int read_mode;	//读取模式
	int	bandrate;	//波特率
	char prefix[16];  //码全缀
	char Suffix[16];   //码后缀
	int  keyopen;	 //按键声音
	int  code_mode;	//码模式
	int  ledopen;	//灯
	int  interval_time;	//间隔时间
	char data[128];
}st_et330_data;


#define FLASH_BLOCK_SIZE						4096

#define EXT_FLASH_DEV_DATA1_ADDR				(EX_FLASH_BASE_ADDR + 0x000000)
#define EXT_FLASH_DEV_DATA2_ADDR				(EX_FLASH_BASE_ADDR + 0x001000)
#define EXT_FLASH_SWITCH_LOG_ADDR				(EX_FLASH_BASE_ADDR + 0x002000)

#define EXT_FLASH_TMS_MD5_ADDR					(EX_FLASH_BASE_ADDR + 0x010000)
#define EXT_FLASH_TMS_AREA_ADDR					(EX_FLASH_BASE_ADDR + 0x011000)
#define EXT_FLASH_HZ_12_ADDR					(EX_FLASH_BASE_ADDR + 0x091000)
#define EXT_FLASH_HZ_16_ADDR					(EX_FLASH_BASE_ADDR + 0x11E000)
#define EXT_FLASH_ASC_12_24_ADDR				(EX_FLASH_BASE_ADDR + 0x1DA000)
#define EXT_FLASH_ASC_16_32_ADDR				(EX_FLASH_BASE_ADDR + 0x1DD000)
#define EXT_FLASH_UC2GBK_ADDR					(EX_FLASH_BASE_ADDR + 0x1E2000)
#define EXT_FLASH_GBK2UC_ADDR					(EX_FLASH_BASE_ADDR + 0x1FB000)
#define EXT_FLASH_ASC_06_12_ADDR				(EX_FLASH_BASE_ADDR + 0x213000)

#define EXT_FLASH_HZ_24_ADDR					(EX_FLASH_BASE_ADDR + 0x20C000)
#define EXT_FLASH_HZ_32_ADDR					(EX_FLASH_BASE_ADDR + 0x3B1000)

#if OS_M56
	#define FLASH_APP1_ADDR							(0x290000)
	#define FLASH_READ_BASE							(0x88000000)	

	#define FLASH_APP2_ADDR							(FLASH_APP1_ADDR + 0 * 1024)
	#define FLASH_APP2_END_ADDR						(FLASH_APP2_ADDR + 600 * 1024)

	#define FLASH_BASE_ADDR							(FLASH_APP2_ADDR + 640  * 1024)
	#define FLASH_OTP_ADDR							(FLASH_BASE_ADDR - FLASH_BLOCK_SIZE)					 //4k
	#define FLASH_SYSTEM_ADDR						(FLASH_OTP_ADDR - FLASH_BLOCK_SIZE)  // 16k
#elif OS_EC100Y | CPU_EC600U

	#define FLASH_APP1_ADDR							(0x290000)
	#define FLASH_READ_BASE							(0x88000000)	

	#define FLASH_APP2_ADDR							(FLASH_APP1_ADDR + 0 * 1024)
	#define FLASH_APP2_END_ADDR						(FLASH_APP2_ADDR + 600 * 1024)

	#define FLASH_BASE_ADDR							osl_get_base_addr()
	#define FLASH_OTP_ADDR							(FLASH_BASE_ADDR - FLASH_BLOCK_SIZE)					 //4k
	#define FLASH_SYSTEM_ADDR						(FLASH_OTP_ADDR - FLASH_BLOCK_SIZE)  // 16k
	#define FLASH_MKSK_KEY_ADDR						(FLASH_SYSTEM_ADDR - FLASH_BLOCK_SIZE * 4)		// 4 * 4k
//	#define FLASH_DUKPT_KEY_ADDR					osl_get_dukpt_addr()	// 1 * 4k
	//#define FLASH_RSA_KEY_ADDR						(osl_get_dukpt_addr() - FLASH_BLOCK_SIZE * 1)	// 1 * 4k
	//#define FLASH_RSA_FILE_ADDR						(FLASH_RSA_KEY_ADDR - FLASH_BLOCK_SIZE * 1)		// 5 * 4k
	//#define FLASH_NEW_DUKPT_KEY_ADDR				(FLASH_RSA_FILE_ADDR - FLASH_BLOCK_SIZE * 5)	// 2 * 4K
#else
	#define FLASH_APP1_ADDR							(0x290000)
	#define FLASH_READ_BASE							(0x88000000)	

	#define FLASH_APP2_ADDR							(FLASH_APP1_ADDR + 0 * 1024)
	#define FLASH_APP2_END_ADDR						(FLASH_APP2_ADDR + 600 * 1024)

	#define FLASH_BASE_ADDR							(0 + 1024  * 1024)
	#define FLASH_OTP_ADDR							(FLASH_BASE_ADDR - FLASH_BLOCK_SIZE)					 //4k
	#define FLASH_SYSTEM_ADDR						(FLASH_OTP_ADDR - FLASH_BLOCK_SIZE)  // 16k
#ifdef WIN32
	#define FLASH_MKSK_KEY_ADDR						(FLASH_SYSTEM_ADDR + FLASH_BLOCK_SIZE * 4)		// 4 * 4k
	#define FLASH_DUKPT_KEY_ADDR					(FLASH_MKSK_KEY_ADDR + FLASH_BLOCK_SIZE * 4)	// 1 * 4k
	#define FLASH_RSA_KEY_ADDR						(FLASH_DUKPT_KEY_ADDR + FLASH_BLOCK_SIZE * 1)	// 1 * 4k
	#define FLASH_RSA_FILE_ADDR						(FLASH_RSA_KEY_ADDR + FLASH_BLOCK_SIZE * 1)		// 5 * 4k
	#define FLASH_NEW_DUKPT_KEY_ADDR				(FLASH_RSA_FILE_ADDR + FLASH_BLOCK_SIZE * 5)	// 2 * 4K
#endif 

#endif


#ifdef __cplusplus
extern "C"{
#endif




/**
* @brief 获取程序路径
* @param outpath 路径
* @param nMaxLen 路径大小
* @return 
*/
LIB_EXPORT void osl_getAppPath( char *outpath ,int nMaxLen);

//
/**
* @brief 文件名前面填充程序路径
* @param szFileName 文件名
* @param outpath 路径
* @param nMaxLen 路径大小
* @return 填充好的路径
*/
LIB_EXPORT const char * osl_fillAppPath( const char *szFileName,char *outpath ,int nMaxLen);


//设置序列号
#ifdef WIN32
LIB_EXPORT void osl_setTerminalID(char* tid );
#endif

LIB_EXPORT void osl_setTerminalID_ex(char* tid ,int flag);

LIB_EXPORT int osl_check_sn_sig();
LIB_EXPORT int osl_check_pk_sig();
LIB_EXPORT int osl_check_sc_sig();
LIB_EXPORT int osl_check_data_sig();
LIB_EXPORT int osl_check_tms_lock();
LIB_EXPORT void osl_setTmsLock(int flag);

//读取序列号
/**
* @brief 读取序列号
* @param outdata
* @param nMaxLen
* @return 
*/
LIB_EXPORT const char* osl_getTerminalID( char *outdata ,int nMaxLen );


//读取带厂商编号+终端类型 序列号（银联21号文）
/**
* @brief 读取序列号
* @param outdata
* @param nMaxLen
* @return 
*/
LIB_EXPORT int get_vendor_TerminalID(char*outdata ,int nMaxLen);

//读取公钥开关和厂品代码
/**
* @brief 读取公钥代码
* @param outdata
* @param nMaxLen
* @return 
*/
LIB_EXPORT int osl_getKeyPubID( char *outdata ,int nMaxLen );
/**
* @brief 读取公钥数据
* @param buff 获取公钥buff
* @param len 公钥buff长度
* @return 
*/
LIB_EXPORT void osl_getKeyPub(char *buff, int len);
/**
* @brief 设置公钥数据
* @param buff 公钥buff
* @param len 公钥buff长度
* @return 
*/
LIB_EXPORT void osl_setKeyPub(char *buff, int len );
/**
* @brief 读取log数据
* @param buff 缓冲区指针
* @param index 偏移值
* @param len 缓冲区长度
* @return 
*/
LIB_EXPORT void osl_get_log_data(char * buff , int len);
/**
* @brief 设置log数据
* @param buff 缓冲区指针
* @param len 缓冲区长度
* @return 
*/
LIB_EXPORT void osl_set_log_data(char * buff , int len);

/**
* @brief 设置imei
* @param imei 缓冲区指针
* @return 
*/
LIB_EXPORT int osl_set_imei(char *imei);
/**
* @brief 校验imei
* @param imei 缓冲区指针
* @return 0:成功 -1:失败
*/
LIB_EXPORT int osl_check_imei(char *imei);

/**
* @brief 设置开启安全
* @param val (1:开启 0:关闭)
* @return 0:成功 其他:失败
*/
LIB_EXPORT int osl_set_sc_enable(int val);
/**
* @brief 读取安全开关
* @return 1:开启 0:关闭
*/
LIB_EXPORT int osl_get_sc_enable();

/**
* @brief 设置sn秘钥
* @return 
*/
LIB_EXPORT void osl_set_snkey(char *key,int mode);
/**
* @brief 读取sn秘钥
* @return 
*/
LIB_EXPORT int osl_get_snkey(char *key);
/**
* @brief 设置sn秘钥模式
* @return 
*/
LIB_EXPORT int osl_get_snkey_mode();
/**
* @brief 读取sn秘钥校验
* @return 
*/
LIB_EXPORT int osl_get_snkey_check();
/**
* @brief 读取模块类型
* @return 
*/
int osl_get_module_type();
/**
* @brief 设置模块类型
* @return 
*/
int osl_set_module_type(int val);

/**
* @brief 设置psn
* @return 
*/
LIB_EXPORT int osl_set_psn(char * psn);
/**
* @brief 读取psn
* @return 
*/
LIB_EXPORT void osl_get_psn(char * psn);

/**
* @brief 读取appm标签
* @return 
*/
LIB_EXPORT int osl_get_appm_flag();
/**
* @brief 设置appm标签
* @return 
*/
LIB_EXPORT int osl_set_appm_flag(int val);

LIB_EXPORT int osl_get_log_switch();
LIB_EXPORT void osl_set_log_switch(int val);

LIB_EXPORT void osl_get_mkey(char * key, int size);
LIB_EXPORT void osl_set_mkey(char * key, int size);



/**
* @brief 设置应用是否忙
* @param val 忙状态
* @return 
*/
LIB_EXPORT void osl_set_app_busy(char val);
/**
* @brief 读取应用是否忙
* @return 忙状态
*/
LIB_EXPORT char osl_get_app_busy();

/**
* @brief 关机
* @return 
*/
LIB_EXPORT void osl_power_off();
/**
* @brief 重启
* @return
*/
LIB_EXPORT void osl_power_reset();
/**
* @brief 设置系统认证模式
* @return
*/
LIB_EXPORT void osl_system_authorize(int val);
/**
* @brief 设置xgui刷新锁 (lvgl版本已废弃)
* @return
*/
LIB_EXPORT int osl_refresh_lock(int status);
/**
* @brief 读取芯片设置的标签
* @return
*/
LIB_EXPORT int osl_get_onchip_flag();

void osl_get_ts(int * left, int *right, int *top, int *bottom);
void osl_set_ts(int left, int right, int top, int bottom);

LIB_EXPORT int osl_get_scan_support();
LIB_EXPORT void osl_set_scan_support(int scan_support);

/**
* @brief 获取序列号
* @param[out] outdata 缓冲区指针
* @param[in] nMaxLen  缓冲区大小
* @return 
*/
LIB_EXPORT const char* osl_getTerminalID_real( char *outdata ,int nMaxLen );
/**
* @brief 获取设备类型
* @return 设备类型 02：传统POS 03：mPOS 04：智能POS 
*/
LIB_EXPORT const char* get_vendor_type();//设备类型 02：传统POS 03：mPOS 04：智能POS 
/**
* @brief 获取终端入网认证编号
* @return 终端入网认证编号 MF90入网编号P3278
*/
LIB_EXPORT const char* get_vendor_code();//终端入网认证编号 MF90入网编号P3278
/**
* @brief 获取加密随机因子
* @return 6:成功 -1:失败
*/
LIB_EXPORT int get_vendor_factor(char*SrcFactor,int nSrclen,char *sEnFactor);//加密随机因子

/**
* @brief 设置屏幕点亮(仅限制系统内部使用，应用调用osl_auxlcd_backlight)
* @param[in] 1:点亮屏幕 0:灭屏幕
* @return 
*/
LIB_EXPORT void osl_set_backlight_flag(int flag);
/**
* @brief 获取屏幕点亮状态(仅限制系统内部使用)
* @param[in] 1:点亮屏幕 0:灭屏幕
* @return 
*/
LIB_EXPORT int osl_get_backlight_flag();

LIB_EXPORT void osl_get_cpuid(char *cpuid);

void osl_set_lcd_color_bit(int bit);
int osl_get_lcd_color_bit();

LIB_EXPORT void osl_get_et330_data(st_et330_data * et330_data);
LIB_EXPORT void osl_set_et330_data(st_et330_data * et330_data);


LIB_EXPORT void osl_task_create(void * pfun, int prio);
LIB_EXPORT void osl_task_create_ex(void * pfun, int prio, char * stk, int task_size);
LIB_EXPORT void osl_system_start(void * pfun);

LIB_EXPORT void osl_send_data_set_func(void * func);
LIB_EXPORT int osl_simu_show_msg(char * msg, int breakline);

/**
* @brief 设置串口休眠状态(休眠状态，应用可以使用该串口)
* @param[in] 1:休眠 0:未休眠
* @return 
*/
LIB_EXPORT void osl_proc_set_comm_pause(int mode);
/**
* @brief 获取串口休眠状态(休眠状态，应用可以使用该串口)
* @return 1:休眠 0:未休眠
*/
LIB_EXPORT int osl_proc_get_comm_pause();


LIB_EXPORT int osl_simu_uart_send(char * data , int size);
LIB_EXPORT int osl_simu_uart_recv(char * buff , int size);
LIB_EXPORT int osl_simu_uart_count();
LIB_EXPORT int osl_simu_uart_set_recv(char * buff , int size);
LIB_EXPORT int osl_simu_uart_init();

LIB_EXPORT void osl_set_otp_data(int otp);
LIB_EXPORT int osl_get_otp_data();


LIB_EXPORT void osl_get_cmsn(char * cmsn);

LIB_EXPORT int osl_set_cmsn(char * cmsn);
LIB_EXPORT void osl_get_cmcode(char * cmcode);


/**
* @brief 获取蓝牙名称
* @return 
*/
LIB_EXPORT void osl_get_blename(char *blename);

/**
* @brief 设置蓝牙名称
* @return 
*/
LIB_EXPORT void osl_set_blename(char *blename);


/**
* @brief 获取蓝牙地址
* @param[in] bleaddr 读取地址缓冲区
* @return 
*/
LIB_EXPORT void osl_get_bleaddr(char *bleaddr,int size);

LIB_EXPORT void osl_set_bleaddr(char *bleaddr,int size);


LIB_EXPORT int osl_get_blenvm(char *blenvm,int size);

LIB_EXPORT void osl_set_bleanvm(char *blenvm,int size);

LIB_EXPORT void* osl_malloc(int size);
LIB_EXPORT int  osl_free(char* p);

LIB_EXPORT int osl_lock_lcd();
LIB_EXPORT int osl_unlock_lcd();
/**
* @brief 设置网络模式为4G模式
* @return 
*/
LIB_EXPORT int osl_set_4G_mode();

LIB_EXPORT int osl_get_dukpt_addr();

LIB_EXPORT int osl_get_new_dukpt_adr();

LIB_EXPORT int osl_get_rsa_addr();

LIB_EXPORT int osl_get_rsa_file_addr();


/**
* @brief 设置重启进入APP1 模式
* @param[in] val 1 重启进入APP1 
* @return 
*/
LIB_EXPORT void osl_set_start_app1(int val);
LIB_EXPORT int osl_get_start_app1();

/**
* @brief 设置当前程序APP1模式
* @param[in] val 1进入 APP1模式
* @return 
*/
LIB_EXPORT void  osl_set_app1_mode(int mode);
/**
* @brief 获取当前程序模式
* @param[in] val 1 APP1程序
* @return 
*/
LIB_EXPORT int  osl_get_app1_mode();

LIB_EXPORT int osl_get_switch_mode();

LIB_EXPORT int osl_set_switch_mode(int flag);

LIB_EXPORT int osl_key_lock();
LIB_EXPORT int osl_key_unlock();

LIB_EXPORT int  osl_start_play_wait(int timeover);

#ifdef __cplusplus
}
#endif

#endif