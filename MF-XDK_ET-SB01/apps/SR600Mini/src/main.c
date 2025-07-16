#include "page_pub.h"
#include "tracedef.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "lvgl/src/lv_lib_png/lv_png.h"
#include "libapi_xpos/inc/libapi_system.h"
#include "libapi_xpos/inc/mfsdk_define.h"
#include "libapi_xpos/inc/mfsdk_nfc.h"
#include "libapi_xpos/inc/mfsdk_lcd.h"
#include "libapi_xpos/inc/mfsdk_gui.h"
#include "libapi_xpos/inc/mfsdk_log.h"
#include "libapi_xpos/inc/mfsdk_fs.h"
#include "libapi_xpos/inc/mfsdk_tms.h"
#include "libapi_xpos/inc/mfsdk_aud.h"
#include "libapi_xpos/inc/mfsdk_comm.h"
#include "libapi_xpos/inc/mfsdk_sys.h"

#include "delfileinit.h"
#include "page_main.h"
#include "player_proc.h"
#include "pages/power_page.h"
#include "sdk_readcard.h"
#include "pub/queue_pub.h"
#include "pub/http.h"
#include "pages/tms_page.h"
#include "pub/gui/osl_key.h"
#include "pub/cJSON.h"

#define APP_VER                         "V1.7.7"
#define APP_VER_STR                     ((const s8*)"Q@#%Q@#%"APP_VER)

static int tts_system_play_fun(int type, void *data)
{
	int ret = 1;

	switch(type)
	{
		case MFSDK_SYS_POWER_SHUTDOWN: // X_Power_ShutDown:
		{
			//PubMultiPlay((const s8 *)"shut.mp3");
			break;
		}

		case MFSDK_SYS_POWER_LOW: //X_Power_Low:
		{
			PubMultiPlay((const s8 *)"lowc.mp3");
			break;
		}

		case MFSDK_SYS_POWER_CHARGE://  X_Power_Charge:
		{
			MfSdkLcdBackLight(MFSDK_LCD_ON);
			break;
		}

		case MFSDK_SYS_POWER_OUT:// X_Power_Out:
		{
			//PubMultiPlay((const s8 *)"disc.mp3");
			break;
		}

		case MFSDK_SYS_NET_GPRS_MODE://X_Net_Gprs_Mode:
		{
			//PubMultiPlay((const s8 *)"gprs.mp3");
			break;
		}

		case MFSDK_SYS_NET_WIFI_MODE://X_Net_Wifi_Mode:
		{
			PubMultiPlay((const s8 *)"wifi.mp3");
			break;
		}

		case MFSDK_SYS_NET_CONFIG_MODE://X_Net_Config_Mode:
		{
			PubMultiPlay((const s8 *)"cnet.mp3");
			break;
		}

		case MFSDK_SYS_WIFI_AIRKISS_CONFIG:// X_Wifi_AirKiss_Config:
		{
			break;
		}

		case MFSDK_SYS_WIFI_AP_CONFIG://X_Wifi_AP_Config:
		{
			break;
		}

		case MFSDK_SYS_WIFI_CONFIG_SUCCESS:// X_Wifi_Config_Success:
		{
			PubMultiPlay((const s8 *)"csuc.mp3");
			break;
		}

		case MFSDK_SYS_WIFI_CONFIG_FAIL:// X_Wifi_Config_Fail:
		{
			PubMultiPlay((const s8 *)"cfail.mp3");
			break;
		}

		case MFSDK_SYS_TMS_UPDATE_START://X_Tms_Update_Start:
		{
			PubMultiPlay((const s8 *)"updating.mp3");
			while(MfSdkAudTtsState() == 1)
			{
				MfSdkSysSleep(100);
			}
			lv_start_lock(1);
			app_tms_page_show(0);
			lv_start_lock(0);
			break;
		}

		case MFSDK_SYS_TMS_DOWN_FINISH_SUCC:// Tms_Down_Finish_Succ:
		{
			PubMultiPlay((const s8 *)"updasuc.mp3");

			while(MfSdkAudTtsState() == 1)
			{
				MfSdkSysSleep(100);
			}

			break;
		}
		default:
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

void cJSON_SetMemoryCb()
{
    static cJSON_Hooks s_hooks;
    s_hooks.free_fn = MfSdkMemFree;
    s_hooks.malloc_fn = MfSdkMemMalloc;
    cJSON_InitHooks(&s_hooks);
}

void app_lv_init()
{
	lv_drv_init();
	MfSdkSysFontInit();

	page_select_disp(LCD_DISP_FRONT);
}

static void MqttParamInit()
{
	//set_keepAliveInterval(300);//set heartbeat interval
	int keepAliveInterval = get_keepAliveInterval();
	//set RTC timer
	MfSdkLcdSetPowerDownTime(keepAliveInterval);
	LanguageInit();
	MfSdkPowerSetBacklightTime(60);
	//set_setting_int(MQTT_PLATFORM, 0);
	MqttPlatformInit();
}

static void KeyParamInit()
{
	//short_press_delay set 1:enable button double-click function
	MfSdkKbKeySetParam(MF_KEY_OK, 500, 2000, 0);
	MfSdkKbKeySetParam(MF_KEY_QUIT, 500, 2000, 0);
	MfSdkKbKeySetParam(MF_KEY_UP, 500, 2000, 0);
	MfSdkKbKeySetParam(MF_KEY_DOWN, 500, 2000, 0);
	MfSdkKbKeySetParam(MF_KEY_CANCEL, 500, 1500, 0);
}

static void ApiCallBack()
{
	cJSON_SetMemoryCb();
    MfSdkSysTtsSystemSetFunc(tts_system_play_fun);
	MfSdkTmsSetProgressCallback(TmsDownloadFunc);
	MfSdkTmsSetResultCallback(TmsShowResultFunc);
	MfSdkPowerPageCb(app_power_page_show);
    MfSdkPowerResumeProc(mqtt_power_resume_proc);
	MfSdkLvglNetKeyCbProc(PageNetMenuKeyProc);
}

static void _app_work_task()
{
	APP_TRACE("**************app start**************\r\n");
    MfSdkFsSetPath((const s8 *)"exdata");
	MfSdkSysLogoInit((s8*)"exdata\\logo.bin");
	MfSdkSysMasterLogoInit((s8*)"exdata\\mainlogo.bin");
	MfSdkTmsSetConnectRetryCnt(1);
	MfSdkTmsSetErrorRetryCnt(0);
	ApiCallBack();

	MfSdkSysTaskAppInit();
	//Disable to sleep when connected to external power
	MfSdkPowerSleepSwitch(MFSDK_POWER_ACONLINE_SLEEP_DN);
	//display all comm port
	MfSdkSysConsoleSwitch(MFSDK_SYS_CONSOLE_AP);
	
	#if UART_EN
	//1:open log  0:close log
	MfSdkLogOutputSwitch(MFSDK_FALSE);
	MfSdkCommUartInit();
	#endif

	MfSdkSysPubDriverInit();
	app_lv_init();
	KeyParamInit();
	
	sdk_readcard_init();
    MfSdkCommMbedtlsInit(1, 0);
	MqttParamInit();
	delfile_init();
	messageId_ini();
	fifo_init();
	play_start();//tts initialization
	player_proc_init();

    MfSdkCommSetWifiName(0);
	MainPage();
}

MfSdkCommApnInfo_T apn_list[] = 
{
	{"cmnet1","","","CHN-CT"},
	{"3gnet1","","","CHN-UNICOM"},
};

MfSdkCommApinfoMcc_T apn_mcc_list[] = 
{
	{"cmnet1","","","460","00"},
};

static int CommSetAPN()
{
    MfSdkCommSetApnList(apn_list,sizeof(apn_list)/sizeof(MfSdkCommApnInfo_T));
    //MfSdkCommSetApnListMcc(apn_mcc_list,sizeof(apn_mcc_list)/sizeof(MfSdkCommApinfoMcc_T));
}

void app_main(int p)
{
	//CommSetAPN();
	//MfSdkTmsEnable(0);
    MfSdkSysStart(APP_VER_STR, _app_work_task);
}



