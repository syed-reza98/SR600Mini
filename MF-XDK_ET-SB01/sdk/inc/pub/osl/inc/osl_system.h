/*! \file osl_system.h
	\brief ϵͳ����
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
	int nReset;		//�����񱻳�ʼ����,
	char factdata[256];		//�������ݱ���λ��
	int usb_mode;   //usbģʽ
	int read_mode;	//��ȡģʽ
	int	bandrate;	//������
	char prefix[16];  //��ȫ׺
	char Suffix[16];   //���׺
	int  keyopen;	 //��������
	int  code_mode;	//��ģʽ
	int  ledopen;	//��
	int  interval_time;	//���ʱ��
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
* @brief ��ȡ����·��
* @param outpath ·��
* @param nMaxLen ·����С
* @return 
*/
LIB_EXPORT void osl_getAppPath( char *outpath ,int nMaxLen);

//
/**
* @brief �ļ���ǰ��������·��
* @param szFileName �ļ���
* @param outpath ·��
* @param nMaxLen ·����С
* @return ���õ�·��
*/
LIB_EXPORT const char * osl_fillAppPath( const char *szFileName,char *outpath ,int nMaxLen);


//�������к�
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

//��ȡ���к�
/**
* @brief ��ȡ���к�
* @param outdata
* @param nMaxLen
* @return 
*/
LIB_EXPORT const char* osl_getTerminalID( char *outdata ,int nMaxLen );


//��ȡ�����̱��+�ն����� ���кţ�����21���ģ�
/**
* @brief ��ȡ���к�
* @param outdata
* @param nMaxLen
* @return 
*/
LIB_EXPORT int get_vendor_TerminalID(char*outdata ,int nMaxLen);

//��ȡ��Կ���غͳ�Ʒ����
/**
* @brief ��ȡ��Կ����
* @param outdata
* @param nMaxLen
* @return 
*/
LIB_EXPORT int osl_getKeyPubID( char *outdata ,int nMaxLen );
/**
* @brief ��ȡ��Կ����
* @param buff ��ȡ��Կbuff
* @param len ��Կbuff����
* @return 
*/
LIB_EXPORT void osl_getKeyPub(char *buff, int len);
/**
* @brief ���ù�Կ����
* @param buff ��Կbuff
* @param len ��Կbuff����
* @return 
*/
LIB_EXPORT void osl_setKeyPub(char *buff, int len );
/**
* @brief ��ȡlog����
* @param buff ������ָ��
* @param index ƫ��ֵ
* @param len ����������
* @return 
*/
LIB_EXPORT void osl_get_log_data(char * buff , int len);
/**
* @brief ����log����
* @param buff ������ָ��
* @param len ����������
* @return 
*/
LIB_EXPORT void osl_set_log_data(char * buff , int len);

/**
* @brief ����imei
* @param imei ������ָ��
* @return 
*/
LIB_EXPORT int osl_set_imei(char *imei);
/**
* @brief У��imei
* @param imei ������ָ��
* @return 0:�ɹ� -1:ʧ��
*/
LIB_EXPORT int osl_check_imei(char *imei);

/**
* @brief ���ÿ�����ȫ
* @param val (1:���� 0:�ر�)
* @return 0:�ɹ� ����:ʧ��
*/
LIB_EXPORT int osl_set_sc_enable(int val);
/**
* @brief ��ȡ��ȫ����
* @return 1:���� 0:�ر�
*/
LIB_EXPORT int osl_get_sc_enable();

/**
* @brief ����sn��Կ
* @return 
*/
LIB_EXPORT void osl_set_snkey(char *key,int mode);
/**
* @brief ��ȡsn��Կ
* @return 
*/
LIB_EXPORT int osl_get_snkey(char *key);
/**
* @brief ����sn��Կģʽ
* @return 
*/
LIB_EXPORT int osl_get_snkey_mode();
/**
* @brief ��ȡsn��ԿУ��
* @return 
*/
LIB_EXPORT int osl_get_snkey_check();
/**
* @brief ��ȡģ������
* @return 
*/
int osl_get_module_type();
/**
* @brief ����ģ������
* @return 
*/
int osl_set_module_type(int val);

/**
* @brief ����psn
* @return 
*/
LIB_EXPORT int osl_set_psn(char * psn);
/**
* @brief ��ȡpsn
* @return 
*/
LIB_EXPORT void osl_get_psn(char * psn);

/**
* @brief ��ȡappm��ǩ
* @return 
*/
LIB_EXPORT int osl_get_appm_flag();
/**
* @brief ����appm��ǩ
* @return 
*/
LIB_EXPORT int osl_set_appm_flag(int val);

LIB_EXPORT int osl_get_log_switch();
LIB_EXPORT void osl_set_log_switch(int val);

LIB_EXPORT void osl_get_mkey(char * key, int size);
LIB_EXPORT void osl_set_mkey(char * key, int size);



/**
* @brief ����Ӧ���Ƿ�æ
* @param val æ״̬
* @return 
*/
LIB_EXPORT void osl_set_app_busy(char val);
/**
* @brief ��ȡӦ���Ƿ�æ
* @return æ״̬
*/
LIB_EXPORT char osl_get_app_busy();

/**
* @brief �ػ�
* @return 
*/
LIB_EXPORT void osl_power_off();
/**
* @brief ����
* @return
*/
LIB_EXPORT void osl_power_reset();
/**
* @brief ����ϵͳ��֤ģʽ
* @return
*/
LIB_EXPORT void osl_system_authorize(int val);
/**
* @brief ����xguiˢ���� (lvgl�汾�ѷ���)
* @return
*/
LIB_EXPORT int osl_refresh_lock(int status);
/**
* @brief ��ȡоƬ���õı�ǩ
* @return
*/
LIB_EXPORT int osl_get_onchip_flag();

void osl_get_ts(int * left, int *right, int *top, int *bottom);
void osl_set_ts(int left, int right, int top, int bottom);

LIB_EXPORT int osl_get_scan_support();
LIB_EXPORT void osl_set_scan_support(int scan_support);

/**
* @brief ��ȡ���к�
* @param[out] outdata ������ָ��
* @param[in] nMaxLen  ��������С
* @return 
*/
LIB_EXPORT const char* osl_getTerminalID_real( char *outdata ,int nMaxLen );
/**
* @brief ��ȡ�豸����
* @return �豸���� 02����ͳPOS 03��mPOS 04������POS 
*/
LIB_EXPORT const char* get_vendor_type();//�豸���� 02����ͳPOS 03��mPOS 04������POS 
/**
* @brief ��ȡ�ն�������֤���
* @return �ն�������֤��� MF90�������P3278
*/
LIB_EXPORT const char* get_vendor_code();//�ն�������֤��� MF90�������P3278
/**
* @brief ��ȡ�����������
* @return 6:�ɹ� -1:ʧ��
*/
LIB_EXPORT int get_vendor_factor(char*SrcFactor,int nSrclen,char *sEnFactor);//�����������

/**
* @brief ������Ļ����(������ϵͳ�ڲ�ʹ�ã�Ӧ�õ���osl_auxlcd_backlight)
* @param[in] 1:������Ļ 0:����Ļ
* @return 
*/
LIB_EXPORT void osl_set_backlight_flag(int flag);
/**
* @brief ��ȡ��Ļ����״̬(������ϵͳ�ڲ�ʹ��)
* @param[in] 1:������Ļ 0:����Ļ
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
* @brief ���ô�������״̬(����״̬��Ӧ�ÿ���ʹ�øô���)
* @param[in] 1:���� 0:δ����
* @return 
*/
LIB_EXPORT void osl_proc_set_comm_pause(int mode);
/**
* @brief ��ȡ��������״̬(����״̬��Ӧ�ÿ���ʹ�øô���)
* @return 1:���� 0:δ����
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
* @brief ��ȡ��������
* @return 
*/
LIB_EXPORT void osl_get_blename(char *blename);

/**
* @brief ������������
* @return 
*/
LIB_EXPORT void osl_set_blename(char *blename);


/**
* @brief ��ȡ������ַ
* @param[in] bleaddr ��ȡ��ַ������
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
* @brief ��������ģʽΪ4Gģʽ
* @return 
*/
LIB_EXPORT int osl_set_4G_mode();

LIB_EXPORT int osl_get_dukpt_addr();

LIB_EXPORT int osl_get_new_dukpt_adr();

LIB_EXPORT int osl_get_rsa_addr();

LIB_EXPORT int osl_get_rsa_file_addr();


/**
* @brief ������������APP1 ģʽ
* @param[in] val 1 ��������APP1 
* @return 
*/
LIB_EXPORT void osl_set_start_app1(int val);
LIB_EXPORT int osl_get_start_app1();

/**
* @brief ���õ�ǰ����APP1ģʽ
* @param[in] val 1���� APP1ģʽ
* @return 
*/
LIB_EXPORT void  osl_set_app1_mode(int mode);
/**
* @brief ��ȡ��ǰ����ģʽ
* @param[in] val 1 APP1����
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