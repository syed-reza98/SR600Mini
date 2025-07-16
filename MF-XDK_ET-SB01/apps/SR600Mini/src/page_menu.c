#include "page_menu.h"
#include "page_main.h"
#include "pages/pages.h"
#include "page_pub.h"
#include "player_proc.h"
#include "card/func_pay.h"
#include "pages/page_menu_list.h"
#include "pages/tms_page.h"
#include "libapi_xpos/inc/mfsdk_ver.h"
#include "libapi_xpos/inc/libapi_comm.h"

static lv_obj_t* page_version = NULL;

static char* listitem[] = {"QRCODE", "TAP SALE", "DIP SALE", "TMS UPDATE", "VERSION", "NET SET", "SETTINGS"};

char * get_trans_title(int transType)
{
	if(transType >TRANSTYPE_NULL && transType < TRANSTYPE_MAX)
	{
		return listitem[transType-1];
	}
	else
	{
		return "";
	}
}

static int ShowVersion_func(int ret, lv_obj_t* obj)
{
	if (page_version != NULL)
	{
		lv_obj_del(page_version);
		page_version = 0;
	}
	return ret;
}

static void ShowVersion(char *title)
{
	char msg[256] = {0};
	char deviceName[64] = {0};
	const s8 *appVer = MfSdkVerGetAppVer();
	const s8 *dataVer = MfSdkVerGetDataVersion();
	const s8 *sysversion = MfSdkVerGetSysVer();
	const s8 *libversion = libapi_version();
	const s8 *spVer = MfSdkVerGetSpVer();
	//const char *bootVer = MfSdkVerGetBootVer();
	const s8 *halVer = MfSdkVerGetDriverVer();

	//MfSdkSysVersion();
	if (page_version != NULL)
	{
		lv_obj_clean(page_version);
		lv_obj_del(page_version);
	}
	
	page_select_disp(LCD_DISP_BEHIND);
	lv_obj_t * parent = lv_scr_act();
	page_version = lv_obj_create(parent, NULL);
	lv_obj_set_size(page_version, lv_obj_get_width(parent), lv_obj_get_height(parent));

	memset(msg, 0, sizeof(msg));
	MfSdkSysGetTerminalSn((s8*)deviceName,sizeof(deviceName));
	snprintf(msg, sizeof(msg), "SN:%s\r\nAppVer:%5.5s-%s\r\nSysVer:%s_%s\r\nDriver:%s\r\nSp:%s\r\nDataVer:%s", 
		deviceName, appVer, strstr((char *)appVer,"V"), sysversion, libversion, halVer, spVer, dataVer);
	page_message_show(page_version, ShowVersion_func, title, msg, "", "", 60*1000);

	return;
}

static lv_obj_t* page_setting = NULL;
static int SettingPageClose(int ret, lv_obj_t* obj)
{
	if (page_setting != NULL)
	{
		lv_obj_del(page_setting);
		page_setting = 0;
	}
	return ret;
}

void SettingPage(char *title)
{
    char ip[64] = { 0 };
    int port = MQTT_PORT;	
    char httpip[64] = { 0 };
    int httpport = HTTP_PORT;	
	char msg[256] = {0};

	MfSdkSysVersion();
	if (page_setting != NULL)
	{
		lv_obj_clean(page_setting);
		lv_obj_del(page_setting);
	}
	
	page_select_disp(LCD_DISP_BEHIND);
	lv_obj_t * parent = lv_scr_act();
	page_setting = lv_obj_create(parent, NULL);
	lv_obj_set_size(page_setting, lv_obj_get_width(parent), lv_obj_get_height(parent));

    get_setting_str(COMM_HOST_IP, ip, sizeof(ip));
    if (strlen(ip) < 3)
    {
        strcpy(ip, MQTT_HOST);
        port = MQTT_PORT;
    }
	else
	{
	    port = get_setting_int(COMM_HOST_PORT);
	}
	
    get_setting_str(COMM_HTTP_IP, httpip, sizeof(httpip));
    if (strlen(httpip) < 3)
    {
        strcpy(httpip, HTTP_HOST);
        httpport = HTTP_PORT;
    }
	else
	{
	    httpport = get_setting_int(COMM_HTTP_PORT);
	}

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "Mqtt:%s:%d\r\nHttp:%s:%d\r\nKeepalive:%ds\r\n", ip, port, httpip, httpport, get_keepAliveInterval());
	page_message_show(page_setting, SettingPageClose, title, msg, "", "", 60*1000);

	return;
}

static void MqttSelect()
{
	char *msg = NULL;
	int type = get_setting_int(MQTT_PLATFORM);
	
	if(0 == type)
	{
		type = 1;
		msg="AWS";
	}
	else if(1 == type)
	{
		type = 0;
		msg="MQTT";
	}
	set_setting_int(MQTT_PLATFORM, type);
	page_text_show(get_subpage(), "PLATFORM", msg, 3000);

	return;
}

static lv_obj_t* backlight_obj = NULL;
static char* backlight_timer_list[] = { "light on", "300s", "120s", "60s", "30s", "15s", "10s"};

static int BackLightTimerSettingCb(int ret)
{
	int backlight = 60;
	static int screenontime_values[] = { 0x0fffffff, 300, 120, 60, 30, 15, 10 };
	int cnt = sizeof(screenontime_values)/sizeof(screenontime_values[0]);
	if (ret >= 0 && ret < cnt) 
	{
		backlight = screenontime_values[ret];
		APP_TRACE("MfSdkPowerSetBacklightTime=%d\r\n", backlight);
		MfSdkLcdBackLight(MFSDK_LCD_ON);
		MfSdkPowerSetBacklightTime(backlight);
		MfSdkPowerSupertimeReset();
	}
	if (backlight_obj != NULL)
	{
		lv_obj_clean(backlight_obj);
		lv_obj_del(backlight_obj);
	}
	MfSdkLcdArrowDisplay(0,1);
	MfSdkLcdArrowDisplay(1,1);
	
	return 0;
}

static void BackLightTimerSetting(lv_obj_t* parent)
{
	int index = 0;
	int cnt = sizeof(backlight_timer_list)/sizeof(backlight_timer_list[0]);
	if (backlight_obj != NULL)
	{
		lv_obj_clean(backlight_obj);
		lv_obj_del(backlight_obj);
	}
	
	backlight_obj = lv_obj_create(lv_scr_act(), NULL);
	lv_obj_set_size(backlight_obj, lv_obj_get_width(parent), lv_obj_get_height(parent));

	page_list_show_ex(backlight_obj, BackLightTimerSettingCb, "BackLight",
					backlight_timer_list, cnt, index, 60 * 1000, 0);
}

static int SpVersionCheck()
{
	int ret = MFSDK_FALSE;
	s8* pSPntagver = "MZ01B-V3.63";
	s8* pSPver = (s8*)MfSdkVerGetSpVer();
	
	APP_TRACE("SP ver:%s\r\n", pSPver == NULL ? "" : (char*)pSPver);
	if( pSPver != NULL && ( strlen((char*)pSPver) >= strlen(pSPntagver) \
		&& memcmp(pSPver, pSPntagver, strlen(pSPntagver)) >=0) )
	{
		ret = MFSDK_TRUE;
	}
	return ret;
}

static int menu_list_select_func(int ret, lv_obj_t* obj)
{
	
	APP_TRACE("_menu_list_select_func:%d\r\n", ret);
	if (PAGE_RET_CANCEL == ret || PAGE_RET_TIMEOVR == ret)
		return ret;
	
	if(TRANSTYPE_QR == ret)
	{
        func_pay(get_subpage(), TRANSTYPE_QR);
	}
	else if(TRANSTYPE_RF == ret) //rf
	{
        func_pay(get_subpage(), TRANSTYPE_RF);
	}
	else if(TRANSTYPE_IC == ret) //IC
	{
        func_pay(get_subpage(), TRANSTYPE_IC);
	}
	else if(TRANSTYPE_TMS == ret)
	{
		TmsUpdateFunc();
	}
	else if(TRANSTYPE_VER == ret)
	{
		ShowVersion(0);
	}
	else if(TRANSTYPE_NETSET == ret)
	{
		//func_wifi_show_ex();
		MfSdkLvglNetMenu(get_subpage(), "mf_12_custom");
	}
	else if(TRANSTYPE_SET == ret)
	{
		//MqttSelect();
		SettingPage(0);
	}
	else if(TRANSTYPE_KEYDL == ret)
	{
		//KeyDownloadPage(get_subpage());
	}

	return ret;
}

void MainMenu()
{
	int count = sizeof(listitem)/sizeof(listitem[0]);

	page_select_disp(LCD_DISP_BEHIND);
	page_menu_list_show_ex(get_subpage(), menu_list_select_func, 0, listitem, count, 0, 0, 0);

	return;
}

