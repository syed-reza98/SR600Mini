//#include "xdk_et.h"
#include "page_main.h"
#include "uart_pub.h"
//#include "pub/messagedatastruct.h"

#include "tracedef.h"
#include "network_page.h"
#include "page_card.h"
#include "page_pub.h"
#include "player_proc.h"
#include "card/func_pay.h"
#include "pages/pages.h"
#include "func_wifi.h"
#include "pub/queue_pub.h"
#include "libapi_xpos/inc/libapi_comm.h"
#include "libapi_xpos/inc/mfsdk_ver.h"
#include "page_menu.h"
#include "pages/page_status_bar.h"
#include "tms/inc/tms_pub.h"

static MfSdkSysTime_T m_stDateTime = { 0 };


static lv_obj_t* mainpage = NULL;
static lv_obj_t* lab_time = NULL;
static lv_obj_t* lab_year = NULL;
static lv_obj_t* lab_message = NULL;
static lv_obj_t* menupage = NULL;
static lv_obj_t* page_state = NULL;

static int amt_time=0;
int tick_get_btn_play = 0;
int press_btn_flag = 0;
static int amt_timer_en = 0;

void set_amt_timer(int val)
{
	amt_timer_en = val;
	return;
}

lv_obj_t* get_mainpage()
{
	return mainpage;
}

lv_obj_t* get_subpage()
{
	return menupage;
}

void LedShowTimerClear()
{
	if (LCD_IS_128_32)
		amt_time = MfSdkSysGetTick();
	return;
}

void LedShowMessage(char *msg)
{
	if (LCD_IS_128_32)
	{
		if(lab_message)
		{
			APP_TRACE("%s, msg = %s\r\n", __FUNCTION__, msg);
			lv_label_set_text(lab_message, msg);
			lv_obj_align(lab_message, NULL, LV_ALIGN_CENTER, 0, 0);
		}
	}
	return;
}

static int play_net_mode()
{
    if (MfSdkCommGetNetMode() == MFSDK_COMM_NET_ONLY_WIRELESS)     //gprs
    {
        PubMultiPlay((const s8 *)"gprs.mp3");
    }
    else
    {
        PubMultiPlay((const s8 *)"wifimode.mp3");
    }
    return 0;
}

static void playMbtn()
{
	int netlinkstate = MfSdkCommLinkState();

	AppPlayBatteryLevel();
	//MfSdkAudPlayBatteryLevel();

	play_net_mode();

	MfSdkSysSleep(1000);

	APP_TRACE("net_func_link_state = %d\r\n", netlinkstate);
	if (0 == netlinkstate)
	{
		PubMultiPlay((const s8 *)"netf.mp3");
	}
	else
	{
		mqtt_play_state(get_mqtt_con_state());
	}
	return;
}

static void btn_play_deweight(lv_task_t* task)
{
	char s_getdata[DATA_SIZE + 1] = { 0 };
	
	if (fifo_checkEmpty() == false)
	{
		play_proc_with_fifo();
	}

	if (MfSdkSysTimerCheck(tick_get_btn_play) == 0 && press_btn_flag == 1) 
	{
		fifo_get_last_one(s_getdata);
		APP_TRACE("fifo_get s_getdata is %s", s_getdata);

		if (strcmp(s_getdata, TTS_BUTTON_M) == 0) 
		{
			playMbtn();
		}
		else if (strcmp(s_getdata, TTS_VOLUME_MIN) == 0) 
		{
			PubMultiPlay((const s8 *)TTS_VOLUME_MIN);
		}
		else if (strcmp(s_getdata, TTS_VOLUME_MAX) == 0) 
		{
			PubMultiPlay((const s8 *)TTS_VOLUME_MAX);
		}
		else if (strcmp(s_getdata, TTS_VOLUME_NOR) == 0) 
		{
			//PubMultiPlay((const s8 *)TTS_VOLUME_NOR);
		}
		press_btn_flag = 0;
	}
	return;
}

static void update_time_task_func(lv_task_t* task)
{

	char str[32] = { 0 };
	char sztime[32] = { 0 };
	MfSdkSysTime_T stDateTime = { 0 };
	MfSdkSysGetTime(&stDateTime);

	if (m_stDateTime.nSecond == 0 || stDateTime.nHour != m_stDateTime.nHour || m_stDateTime.nMinute != stDateTime.nMinute)
	{
		sprintf(sztime, "%02d:%02d", stDateTime.nHour, stDateTime.nMinute);
		memcpy(&m_stDateTime, &stDateTime, sizeof(MfSdkSysTime_T));
		sprintf(str, "%04d-%02d-%02d", stDateTime.nYear, stDateTime.nMonth, stDateTime.nDay);
		if(NULL != lab_time)
			lv_label_set_text(lab_time, sztime);
		if(NULL != lab_year)
			lv_label_set_text(lab_year, str);
		MfSdkGuiLedTime(sztime);
	}
	if (MfSdkSysCheckTick(amt_time, 60000) == 1 && tms_isupdate() == 0 && amt_timer_en == 1)
	{
		//MfSdkGuiLedAmount((char*)"0.00");
		LedShowMessage("WELCOME");
		LedShowTimerClear();
	}

	#if UART_EN
	uart_proc();
	#endif
	return;
}

static void page_sub_show()
{
	page_select_disp(LCD_DISP_BEHIND);

	lv_obj_t* subpage = lv_scr_act();
    menupage = page_create_win(subpage, NULL);

	lv_task_create(update_time_task_func, 1000, LV_TASK_PRIO_MID, 0);
	lv_task_create(btn_play_deweight, 50, LV_TASK_PRIO_MID, 0);

	return;
}

static void page_state_show()
{	
	if(NULL != page_state) return;

	page_state = lv_layer_top();
	lv_obj_reset_style_list(page_state, LV_OBJ_PART_MAIN);
	lv_obj_set_size(page_state, lv_obj_get_width(page_state), page_get_statusbar_height(LCD_DISP_FRONT));
	lv_obj_set_style_local_bg_opa(page_state, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
	lv_obj_set_style_local_bg_color(page_state, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_GREY);
	state_signal_page_init(page_state, LV_ALIGN_IN_TOP_LEFT, 10, 2);
	state_power_page_init(page_state, LV_ALIGN_IN_TOP_RIGHT, -10, 4);

	return;
}

static void page_main_show()
{

	MfSdkSysTime_T stDateTime = { 0 };
	char strTime[64] = { 0 };
	char str[64] = { 0 };
	char app_ver[64] = { 0 };
	lv_obj_t* img = NULL;
	
	LV_FONT_DECLARE(font_size36);

	page_select_disp(LCD_DISP_FRONT);
	mainpage = lv_scr_act();
	lv_obj_set_style_local_bg_color(mainpage, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);

	APP_TRACE("lcdtype = %d\r\n", MfSdkSysGetLcdType());
	amt_time = MfSdkSysGetTick();
	if (LCD_IS_128_32)
	{
		amt_timer_en = 1;
		lab_message = page_ShowTextOut(mainpage, "WELCOME", LV_ALIGN_CENTER, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);
		return;
	}
	
	img = lv_img_create(mainpage, NULL);
	lv_obj_set_size(img, lv_obj_get_width(mainpage), lv_obj_get_height(mainpage)-page_get_title_height(LCD_DISP_FRONT));

	if (LCD_IS_320_480)
	{
		lv_load_png_file(MAINPNG_320X480);
		lv_img_set_src(img, MAINPNG_320X480);
	}
	else
	{
		lv_load_png_file(MAINPNG);
		lv_img_set_src(img, MAINPNG);
	}

	//time label
	MfSdkSysGetTime(&stDateTime);
	sprintf(strTime,"%02d:%02d",stDateTime.nHour,stDateTime.nMinute);
	//lab_time = page_ShowTextOut(mainpage, strTime, LV_ALIGN_IN_TOP_MID, 0, 80, LV_COLOR_BLACK, LV_FONT_32);
	lab_time = page_ShowText_Font(mainpage, strTime, LV_ALIGN_IN_TOP_MID, 0, 60, LV_COLOR_BLACK, &font_size36);

	//data label
	sprintf(str, "%04d-%02d-%02d", stDateTime.nYear, stDateTime.nMonth, stDateTime.nDay);
	lab_year = page_ShowTextOut(mainpage, str, LV_ALIGN_IN_TOP_MID, 0, 130, LV_COLOR_BLACK, LV_FONT_16);

	//ver label
	sprintf(app_ver, "(Ver: %s)", strstr((char *)MfSdkVerGetAppVer(), "V"));
	page_ShowTextOut(mainpage, app_ver, LV_ALIGN_IN_BOTTOM_MID, 0, -50, LV_COLOR_BLACK, LV_FONT_12);
	//page_ShowText_MultiFont(mainpage, 0, LV_ALIGN_IN_BOTTOM_MID, 0, -120, LV_COLOR_BLACK, LV_FONT_24);

	//page_ShowTextOut(mainpage, "Free Type 24", LV_ALIGN_IN_BOTTOM_MID, 0, -10, LV_COLOR_BLACK, MF_FONT_SIZE_24);

	return;
}

void play_start()
{
	PubMultiPlay((const s8 *)"welc.mp3");
}

void MainPage()
{	
	APP_TRACE("MainPage\r\n");

	page_group_create();

	//status bar
	if (!LCD_IS_128_32)
	{
		page_state_show();
	}
	page_main_show();
	page_sub_show();
	MainMenu();

	lv_start();
}

