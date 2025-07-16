#pragma once
/*! \file osl_BaseParam.h
	\brief ��������
*	\author lx
*	\date 2014/02/07
*/
#include "pub/pub.h"

#define TS_DATA_FILE		"data\\ts_data.ini"
#define SYSTEM_PROFILE		"data\\sysCfg.ini"		//ϵͳ�����ļ�����
#define TAMPER_INI_FILENAME	"data\\Tamper.ini"

#if OS_LINUX | WIN32
#define DATAVERSION_FILENAME  "xxxx\\data.ini"    //���ݰ汾��
#else
#define DATAVERSION_FILENAME  "data\\data.ini"    //���ݰ汾��
#endif
#define APP2DATAVERSION_FILENAME  "exdata\\data.ini"    //app2���ݰ汾��

#define BASEPARAM_SECTION	"BaseParam"			//�ڻ��������������ļ��еĶ�����
#define LCDCONTRAST			"lcdContrast"		//Һ���Աȶ�,0~63
#define KEYSOUNDOPEN		"keySoundOpen"		//����������,0��1��
#define TTSSOUNDOPEN		"ttsSoundOpen"		//tts����,0��1��


#define RESET_SECTION	    "ResetParam"		//����ģʽ�ֶ�
#define RESET_MODE	        "resetmode"		 

	 

#define TTSMAXVOLUME		"ttsMaxVolum"		//�������λ
#define LCDLIGHTTIME		"lcdLightTime"		//����ʱ��������Ϊ��λ
#define ENERCYTIME          "enercyTime"		//����ʱ��
#define POWER_DOWN_TIME		"PowrDownTime"		//�ػ�ʱ��
#define NET_MODE			"netMode"			//����ģʽ
#define POWER_SECTION		"Power"				//��Դ�������������ļ��еĶ�����
#define POWER_KEY_DOWN_TIME	"PowerKeyDownTime"		//��Դ�����¹ػ�ʱ��

#define TS_PARAM_SECTION	"param_section"
#define TS_LEFT_KEY			"ts_left_key"
#define TS_RIGHT_KEY		"ts_right_key"
#define TS_TOP_KEY			"ts_top_key"
#define TS_BOTTOM_KEY		"ts_bottom_key"
#define KEY_DOWNLOAD_STATE	"key_downlaod_state"


#define COPSNAME			"CopsName"		//��Ӫ������

#define  HAL_LOG_OUT		"hal_log_out"

#define LCD_LIGHT_MAX	99999999


LIB_EXPORT void osl_ts_get(int *left , int *right , int * top, int * bottom);
LIB_EXPORT void osl_ts_set(int left , int right , int top, int bottom);


LIB_EXPORT char* osl_get_app2_device_version();
LIB_EXPORT char* osl_get_app2_app_version();


#define DEVICE_VISION	 osl_getDeviceVision()  //ϵͳ�汾��


/**
* @brief ��ȡϵͳ�汾��
* @return ϵͳ�汾��
*/
LIB_EXPORT const char * osl_getDeviceVision();



#define APP_VISION	 osl_getAppVision()  //Ӧ�ð汾��
#define APP2_VISION osl_get_app2_app_version();//app2Ӧ�ð汾��



/**
* @brief ��ȡӦ�ð汾��
* @return Ӧ�ð汾��
*/
LIB_EXPORT const char * osl_getAppVision();
/**
* @brief ����Ӧ�ð汾��
* @param Ӧ�ð汾��
* @return 
*/
LIB_EXPORT void osl_setAppVision(const char *appvision);


LIB_EXPORT char* osl_get_app2_hal_version();
#define DATA_VISION	 osl_GetDataVision()  //Ӧ�ð汾��

/**
* @brief ��ȡӦ�ð汾��
* @return 
*/
LIB_EXPORT  const char * osl_GetDataVision(); //��ȡ���ݰ汾��
/*
* [BaseParam]
* lcdContrast=60
* keySoundOpen=1
* lcdLightTime=120
*
*ֱ��ͨ��read_profile_int����write_profile_intд
*/


/**
* @brief ����������
* @param ʱ��
* @return 
*/
LIB_EXPORT int osl_BuzzerSound(int nMillisecond);


/**
* @brief �����Ƿ���������
* @param 1�� 0��
* @return 
*/
LIB_EXPORT int osl_SwitchKeySound(int nOpen);

LIB_EXPORT void osl_set_tts_sound(int nOpen);
LIB_EXPORT int osl_get_tts_sound();


/**
* @brief ��ȡ��ǰ�������Ƿ���
* @return 1�� 0��
*/
LIB_EXPORT int osl_IsKeySoundOpen();


/**
* @brief Һ������ʱ����Ϊ��λ
* @return ����ʱ��
*/
LIB_EXPORT int osl_lcd_BackLightTime();


LIB_EXPORT int osl_get_lcd_contrast();
LIB_EXPORT int osl_set_lcd_contrast(int val);



/**
* @brief ����Һ������ʱ������Ϊ��λ
* @param nTime ����ʱ��
* @return 
*/
LIB_EXPORT int osl_lcd_SetBackLightTime(int nTime);

/**
* @brief ������Կģʽ
* @param nTime ����ʱ��
* @return 
*/

LIB_EXPORT void osl_set_key_mode(int mode);
/**
* @brief ��ȡӲ���豸�ͺ�
* @return 
*/
LIB_EXPORT int osl_GetDeviceType();
LIB_EXPORT const char *osl_getDeviceTypeName();
LIB_EXPORT int osl_is_qmpos();
LIB_EXPORT int osl_get_is_mh();
LIB_EXPORT int osl_get_is_k21();
LIB_EXPORT int osl_get_is_m90();
LIB_EXPORT int osl_get_is_printer();
LIB_EXPORT int osl_get_is_power2quit();
LIB_EXPORT int osl_get_is_dual_module();
LIB_EXPORT int osl_get_is_m66();
LIB_EXPORT int osl_get_is_m67();
LIB_EXPORT int osl_get_is_m68();
LIB_EXPORT int osl_get_is_m69();
LIB_EXPORT int osl_get_is_m66b();
LIB_EXPORT int osl_get_is_128k_ram();
LIB_EXPORT int osl_get_is_et389();
LIB_EXPORT  int osl_get_is_1903();


LIB_EXPORT int osl_get_is_yq04a();


enum{
	DEV_MODE_QR = 0,		// ����
	DEV_MODE_SCAN,			// ɨ��ǹ
};

// �豸
LIB_EXPORT int osl_get_dev_mode();
LIB_EXPORT int osl_get_is_m90_key_map();
LIB_EXPORT int osl_get_is_56r();
LIB_EXPORT int osl_get_is_h9a();

/**
* ����Ӳ���豸�ͺ�
*@return �豸�ͺ� 
* 
*/
LIB_EXPORT int ols_SetDeviceType(int  nDeviceType);

//! ͨѶģ������
enum{
	MODEL_WIRELESS = 0,		///<����
	MODEL_MODEM,			///<����
	MODEL_WIFI,				///<wifi
	MODEL_WIN32_SOCK,	///<ģ����
};


enum{
	MODEL_MODE_ONLY_WIRELESS = 0,		// �� ����
	MODEL_MODE_ONLY_WIFI,				// �� wifi
	MODEL_MODE_FRIST_WIRELESS,		// ���� ����
	MODEL_MODE_FRIST_WIFI,				// ���� wifi
};


/**
* @brief osl_model_type
* @return MODEL_WIRELESS ���� MODEL_MODEM����
*/
LIB_EXPORT int osl_model_type();
LIB_EXPORT void osl_model_set(int type);
LIB_EXPORT void osl_set_model_type_func(void * pfun);

/**
* @brief ��ʼ����ȫ���
* @return 
*/
LIB_EXPORT void osl_initTamper();
/**
* @brief ���ý���ʱ������Ϊ��λ
* @param nTime ʱ��
* @return 
*/
LIB_EXPORT int osl_Enercy_SetTime( int nTime );

/**
* @brief ����ʱ����Ϊ��λ
* @return ����ʱ��
*/
LIB_EXPORT int osl_Enercy_Time();

/**
* @brief �ػ�ʱ����Ϊ��λ
* @return �ػ�ʱ��
*/
LIB_EXPORT int osl_lcd_PowerDownTime();

/**
* @brief ���ùػ�ʱ�䣬��Ϊ��λ
* @param nTime ʱ��
* @return 
*/
LIB_EXPORT int osl_lcd_SetPowerDownTime( int nTime );

/**
* @brief ��ȡ����(0:���� 1:Ӣ��)
* @return 
*/

LIB_EXPORT int osl_get_language();
/**
* @brief ��������(0:���� 1:Ӣ��)
* @return 
*/
LIB_EXPORT void osl_set_language(int val);

/**
* @brief ��ȡ�������ͣ�0:���� 1:wifi��
* @return 
*/
LIB_EXPORT int osl_get_net_mode();
/**
* @brief �����������ͣ�0:���� 1:wifi��
* @return 
*/
LIB_EXPORT void osl_set_net_mode(int mode);


LIB_EXPORT int osl_lcd_color_bit();
LIB_EXPORT  int osl_set_cmcode(char * cmcode);

LIB_EXPORT char * osl_get_cmmode();


LIB_EXPORT void osl_set_cops_name(char *copsname );

LIB_EXPORT void osl_get_cops_name(char *copsname,int len );


LIB_EXPORT int osl_get_max_sound();

LIB_EXPORT int osl_get_is_yq05a();
LIB_EXPORT int osl_get_is_yq06b();
LIB_EXPORT int osl_get_is_mz01b();

LIB_EXPORT int  osl_get_is_fw_ctrl();


LIB_EXPORT int osl_get_is_lcd();

LIB_EXPORT int osl_get_is_yq06a();





/**
 * @brief ��������ģʽ
 * @param mode
 * @return
*/
LIB_EXPORT int osl_set_reset_mode(int mode);

/**
 * @brief ��ȡ����ģʽ
 * @param mode
 * @return
*/
LIB_EXPORT int osl_get_reset_mode(int mode);

/**
 * @brief ��ȡ�����ý�������ģʽ
 * @param mode
 * @return ����ģʽ
*/
LIB_EXPORT int atc_product_get_mode();
LIB_EXPORT int atc_product_set_mode(int mode); 


LIB_EXPORT int osl_get_is_yq04b();
LIB_EXPORT int osl_get_is_yq04c();

LIB_EXPORT int osl_get_is_ET380A();
/**
 *@brief: �ж��Ƿ���yq09b�ͺ��豸
 *@input:
 *@output:
 *@return:
 *@date:2023/08/30
 *@author:xh
**/
LIB_EXPORT int osl_get_is_yq09b();

/**
 *@brief: �ж��Ƿ���yq09c�ͺ��豸
 *@input:
 *@output:
 *@return:
 *@date:2023/10/30
 *@author:xh
**/
LIB_EXPORT int osl_get_is_yq09c();


