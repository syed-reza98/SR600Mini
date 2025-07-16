#include "lvgl/lvgl.h"
#include "lvgl/src/lv_lib_png/lv_png.h"
#include "libapi_xpos/inc/mfsdk_tms.h"
#include "page_main.h"
#include "tms_page.h"
#include "tms/inc/tms_pub.h"


#define FRONT_PROCESS_OFFSET	(60)
#define BEHIND_PROCESS_OFFSET	(8)
#define UPDATA_TIP_OFFSET	(-8)

static lv_obj_t * behindparent = NULL;
static lv_obj_t* tms_behind_label = NULL;
static lv_obj_t* behind_tms_bar = NULL;

static lv_obj_t* frontparent = NULL;
static lv_obj_t* tms_front_label = NULL;
static lv_obj_t* tms_bar = NULL;
static lv_task_t *task_timer = NULL;
static lv_obj_t* res_img = NULL;
static lv_obj_t* tip = NULL;

static int g_update_manual = 0;
static int g_disptip = 0;
static int m_timeover = 0;
static int m_result_timeover = 0;
static int m_lowpower_flag = 0;
static int m_lowpower_timeover = 0;

typedef struct
{
	int type;
	char *message;
}st_TmsMessage;

static st_TmsMessage g_TmsMessage[] = 
{
	{TMS_NET_FAIL,				"Net Link Fail"},
	{TMS_SOCKET_FAIL,			"Connect Fail"},
	{TMS_LOGIN_FAIL,			"Server Login Fail"},
	{TMS_LOGIN_FORMAT_ERROR,	"Login Package Error"},
	{TMS_DEVICE_ERROR,			"Illegal Equipment"},
	{TMS_MD5_ERROR,				"MD5 Check Error"},
	{TMS_SIG_ERROR,				"Verification Fail"},
	{TMS_LOW_BATTERY,			"Low Power"},
	{TMS_UPDATE_FAIL,			"Update Fail"},
	{TMS_CONNECT_SERVER_FAIL,	"Connect Fail"},
	{TMS_SEND_SERVER_FAIL,		"Send Fail"},
	{TMS_RECV_SERVER_FAIL,		"Receive Fail"},
	{TMS_UPDATE_SUCCESS,		"Download Success\rRestarting Device"},
	{TMS_UPDATE_NO_TRIGERR,		"No need to update"},
	{TMS_CONNECT_SERVER,		"Connect Server"},
	{TMS_SEND_SERVER,			"Send Data"},
	{TMS_RECV_SERVER,			"Receive Data"},
	{TMS_UPDATING,				"Downloading"},
};

#define ARRAY_SIZE(x)	(sizeof(x)/sizeof(x[0]))

static char* TmsGetMessage(int type)
{
	int i = 0;
	static char* message = NULL;
	
	for(i = 0; i < ARRAY_SIZE(g_TmsMessage); i++)
	{
		if(type == g_TmsMessage[i].type)
		{
			message = g_TmsMessage[i].message;
			break;
		}
	}

	if(message == NULL)
	{
		message = "Unknown Error";
	}

	APP_TRACE("TmsGetMessage message = %s\r\n", message);
	return message;
}

static void tms_proc_close_tip_page()
{
	APP_TRACE("tms_proc_close_tip_page\r\n");
	if (tip != NULL)
	{
		if (res_img != NULL)
		{
			lv_obj_del(res_img);
			res_img = NULL;
		}
		lv_obj_del(tip);
		tip = NULL;
	}
}

static void tms_proc_close_page()
{
	APP_TRACE("tms_proc_close_page\r\n");
	if (task_timer != NULL)
	{
        lv_task_del(task_timer);
		task_timer = NULL;
	}
	if (frontparent != NULL)
	{
		APP_TRACE("frontparent close\r\n");
		if (tms_front_label != NULL)
		{
			lv_obj_del(tms_front_label);
			tms_front_label = NULL;
		}
		if (tms_bar != NULL)
		{
			lv_obj_del(tms_bar);
			tms_bar = NULL;
		}
		tms_proc_close_tip_page();
		lv_obj_del(frontparent);
		frontparent = NULL;
	}
	if (behindparent != NULL)
	{
		APP_TRACE("behindparent close\r\n");
		if (tms_behind_label != NULL)
		{
			lv_obj_del(tms_behind_label);
			tms_behind_label = NULL;
		}
		if (behind_tms_bar != NULL)
		{
			lv_obj_del(behind_tms_bar);
			behind_tms_bar = NULL;
		}
		lv_obj_del(behindparent);
		behindparent = NULL;
	}
	if(LCD_IS_128_32)
	{
		LedShowMessage("WELCOME");
	}

	lv_free_png_file(TMS_PROC_PAGE);
	lv_free_png_file(TMS_TIP_FAIL); 
	lv_free_png_file(TMS_TIP_SUCC);
	page_select_disp(LCD_DISP_BEHIND);
	g_update_manual = 0;
	g_disptip = 0;
	m_timeover = 0;
	m_result_timeover = 0;
}

static void tms_event_cb(lv_obj_t* obj, lv_event_t e)
{
	uint32_t key;

	if (e == LV_EVENT_KEY)
	{
		key = page_get_key();

		if (key == MF_LV_KEY_CANCEL_SHORT_PRESS || key == MF_LV_KEY_OK_SHORT_PRESS)
		{
			tms_proc_close_page();
		}
	}
}

static void update_tms_progress(int progress)
{
	char buff[10] = { 0 };

	tms_proc_close_tip_page();
	
	sprintf(buff, "%d%%", progress);
	LedShowMessage(buff);
	if(tms_behind_label != NULL)
	{
		APP_TRACE("behind process: %s\r\n", buff);
		lv_label_set_text(tms_behind_label, buff);
		if(behind_tms_bar != NULL)
		{
			lv_bar_set_value(behind_tms_bar, progress, LV_ANIM_OFF);
		}
	}
	if(tms_front_label != NULL)
	{
		APP_TRACE("front process: %s\r\n", buff);
		lv_label_set_text(tms_front_label, buff);
		if(tms_bar != NULL)
		{
			lv_bar_set_value(tms_bar, progress, LV_ANIM_OFF);
		}
	}
}

static lv_obj_t* TmsPageCreate()
{

	APP_TRACE("%s behind\r\n", __FUNCTION__);
	
	lv_obj_t * subparent = get_subpage();
	behindparent = page_create_win(subparent, NULL);
	mainpage_create_title(behindparent, "TMS UPDATE");

	tms_behind_label = page_ShowTextOut(behindparent, "", LV_ALIGN_CENTER, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);

	if(!LCD_IS_128_32)
	{
		lv_load_png_file(TMS_PROC_PAGE);
		
		APP_TRACE("%s front\r\n", __FUNCTION__);
		lv_obj_t * parent = get_mainpage();//lv_scr_act();

		frontparent = page_create_win(parent, NULL);
		lv_obj_t * img = lv_img_create(frontparent, NULL);
		lv_img_set_src(img, TMS_PROC_PAGE);
		lv_img_set_auto_size(img, true);
		lv_obj_align(img, NULL, LV_ALIGN_CENTER, 0, -80);

		tms_front_label = page_ShowTextOut(frontparent, "", LV_ALIGN_CENTER, 0, FRONT_PROCESS_OFFSET, LV_COLOR_BLACK, LV_FONT_24);
	}
	return behindparent;
}

static lv_obj_t* tms_create_back_progress_bar(lv_obj_t* parent, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
	lv_obj_t* bar = NULL;
	bar = lv_bar_create(parent, NULL);
	lv_bar_set_range(bar, 0, 100);
	lv_obj_set_size(bar, lv_obj_get_width(parent)-10, 5);
	lv_obj_align(bar, NULL, LV_ALIGN_IN_BOTTOM_MID, x_ofs, y_ofs);
    lv_obj_set_style_local_bg_color(bar, LV_BAR_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_style_local_bg_color(bar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_BLUE);

	return bar;
}

static lv_obj_t* tms_create_progress_bar(lv_obj_t* parent, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
	lv_obj_t* bar = NULL;
	bar = lv_bar_create(parent, NULL);
	lv_bar_set_range(bar, 0, 100);
	lv_obj_set_size(bar, lv_obj_get_width(parent)-60, 10);
	lv_obj_align(bar, NULL, LV_ALIGN_CENTER, x_ofs, y_ofs);
	lv_obj_set_style_local_bg_color(bar, LV_BAR_PART_BG, LV_STATE_DEFAULT, LV_COLOR_GRAY);
	lv_obj_set_style_local_bg_color(bar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_BLUE);

	return bar;
}

void app_tms_page_show(int progress)
{
	char buff[10] = { 0 };

    APP_TRACE("[%s]\r\n", __FUNCTION__);
	if (m_lowpower_flag == 1 && m_result_timeover > 0)
	{
		tms_proc_close_page();
	}

	if(NULL == behindparent)
	{
		TmsPageCreate();
	}
	sprintf(buff, "%d%%", progress);

	if(!LCD_IS_128_32)
	{
		page_ShowTextOut(frontparent, "TMS Upgrading", LV_ALIGN_CENTER, 0, 20, LV_COLOR_BLACK, LV_FONT_16);
		lv_label_set_text(tms_front_label, buff);
		lv_obj_align(tms_front_label, NULL, LV_ALIGN_CENTER, 0, FRONT_PROCESS_OFFSET);

		tms_bar = tms_create_progress_bar(frontparent, LV_ALIGN_CENTER, 0, 100);
		
		page_ShowTextOut(frontparent, "Please wait...", LV_ALIGN_CENTER, 0, 140, LV_COLOR_BLACK, LV_FONT_24);
	}
	
	page_ShowTextOut(behindparent, "TMS Upgrading", LV_ALIGN_CENTER, 0, UPDATA_TIP_OFFSET, LV_COLOR_BLACK, LV_FONT_MF12);
	lv_label_set_text(tms_behind_label, buff);
	lv_obj_align(tms_behind_label, NULL, LV_ALIGN_CENTER, 0, BEHIND_PROCESS_OFFSET);

	//behind_tms_bar = tms_create_back_progress_bar(behindparent, LV_ALIGN_IN_BOTTOM_MID, 0, -5);

	return;
}

void  TmsDownloadFunc(int size, int total_size)
{
    APP_TRACE("[%s] %d/%d \r\n", __FUNCTION__, size, total_size);
    int progress = 100 * size / total_size;
    char tmp[10] = { 0 };

    sprintf(tmp, "%d", progress);
    APP_TRACE("[%s]:[Progress bar:%s] \r\n", __FUNCTION__, tmp);
	lv_start_lock(1);
	update_tms_progress(progress);
	lv_start_lock(0);
}

static void TmsClosePage(int timeover)
{
	m_timeover = timeover;
	APP_TRACE("g_disptip = %d \r\n", g_disptip);
	while (m_timeover && 1 == g_disptip)
	{
		m_timeover-=1000;
		MfSdkSysSleep(1000);
		APP_TRACE("m_timeover = %d \r\n", m_timeover);
	}
	tms_proc_close_page();
}

static void tms_resultpage_task_func(lv_task_t* task)
{
	if (m_result_timeover > 0) 
	{
		m_result_timeover -= 1000;
		if (m_result_timeover <= 0) 
		{
			tms_proc_close_page();
		}
	}
}

static void TmsResultPage(int type, int timeover)
{
	char *msg = TmsGetMessage(type);
	
	if (type != TMS_UPDATE_NO_TRIGERR || g_update_manual == 1)
	{
		APP_TRACE("set g_disptip\r\n");
		g_disptip = 1;
	}
	
	if(NULL != tms_behind_label)
	{
		page_ShowTextOut(behindparent, " ", LV_ALIGN_CENTER, 0, UPDATA_TIP_OFFSET, LV_COLOR_BLACK, LV_FONT_MF12);
		lv_label_set_text(tms_behind_label, msg);
		lv_obj_align(tms_behind_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 32);
	}

	if(!LCD_IS_128_32)
	{
		tip = page_create_win(frontparent, tms_event_cb);
		res_img = lv_img_create(tip, NULL);
		if (type == TMS_UPDATE_SUCCESS || type == TMS_UPDATE_NO_TRIGERR)
		{
			lv_load_png_file(TMS_TIP_SUCC);
			lv_img_set_src(res_img, TMS_TIP_SUCC);
		}
		else
		{
			lv_load_png_file(TMS_TIP_FAIL);
			lv_img_set_src(res_img, TMS_TIP_FAIL);
		}
		lv_img_set_auto_size(res_img, true);
		lv_obj_align(res_img, NULL, LV_ALIGN_CENTER, 0,0);
		page_ShowTextOut(res_img, msg, LV_ALIGN_CENTER, 0, 30, LV_COLOR_BLACK, LV_FONT_24);
	}
	LedShowMessage(msg);
	MfSdkSysSleep(100);
	
	if(tms_front_label != NULL)
	{
		lv_label_set_text(tms_front_label, "");
	}
	
	if(timeover>0)
	{
		m_result_timeover = timeover;
		task_timer = lv_task_create(tms_resultpage_task_func, 1000, LV_TASK_PRIO_MID, 0);
	}

	return;
}

static void TmsShowLowPowerPage(int type)
{
	//APP_TRACE("m_lowpower_flag = %d m_lowpower_timeover = %d\r\n", m_lowpower_flag, m_lowpower_timeover);
	if (0 == m_lowpower_flag)
	{
		APP_TRACE("disp low power page\r\n");
		m_lowpower_timeover = MfSdkSysTimerOpen(60 * 1000);
		m_lowpower_flag = 1;
		TmsPageCreate();
		TmsResultPage(type, 5000);
	}
	else
	{
		if (0 == MfSdkSysTimerCheck(m_lowpower_timeover))
		{
			APP_TRACE("low power page close\r\n");
			tms_proc_close_page();
			m_lowpower_flag = 0;
		}
	}

	return;
}

void  TmsShowResultFunc(int type)
{

	lv_start_lock(1);
	APP_TRACE("TmsShowResultFunc: type = %d update = %d\r\n", type, g_update_manual);
	
	//not display communication process
	if ((type == TMS_CONNECT_SERVER || type == TMS_SEND_SERVER || type == TMS_RECV_SERVER || type == TMS_UPDATE_NO_TRIGERR
		|| type == TMS_CONNECT_SERVER_FAIL || type == TMS_SEND_SERVER_FAIL || type == TMS_RECV_SERVER_FAIL || type == TMS_NET_FAIL)
		&& 0 == g_update_manual)
	{
		tms_proc_close_tip_page();
		APP_TRACE("not display type = %d\r\n", type);
	}
	else if (type == TMS_LOW_BATTERY)
	{
		TmsShowLowPowerPage(type);
	}
	else
	{
		tms_proc_close_tip_page();
		if(NULL == behindparent)
		{
			TmsPageCreate();
		}
		
		if (type == TMS_CONNECT_SERVER || type == TMS_SEND_SERVER || type == TMS_RECV_SERVER) 
		{
			char *msg = TmsGetMessage(type);
			if(tms_front_label != NULL && 1 == g_update_manual)
			{
				lv_label_set_text(tms_front_label, msg);
				lv_obj_align(tms_front_label, NULL, LV_ALIGN_CENTER, 0, FRONT_PROCESS_OFFSET);
			}
			if(tms_behind_label != NULL && 1 == g_update_manual)
			{
				lv_label_set_text(tms_behind_label, msg);
				lv_obj_align(tms_behind_label, NULL, LV_ALIGN_CENTER, 0, BEHIND_PROCESS_OFFSET);
			}
		}
		else if (type == TMS_FINISH)
		{
			TmsClosePage(3000);
		}
		else
		{
			APP_TRACE("type = %d, update = %d\r\n", type, g_update_manual);		
			TmsResultPage(type, 0);
		}
	}
	
	lv_start_lock(0);
}

void TmsUpdateFunc()
{	
	if(0 == g_update_manual)
	{
		if ( MfSdkSysBatterCharge() != MFSDK_SYS_RET_OK && MfSdkPowerGetBatteryPercentage() <= 10) 
		{
			TmsPageCreate();
			TmsResultPage(TMS_LOW_BATTERY, 3000);
			return;
		}
		
	    if (MfSdkCommLinkState() != 1)
	    {
	        APP_TRACE("TransactionProc connect fail\n");
			TmsPageCreate();

			TmsResultPage(TMS_NET_FAIL, 3000);
	    }
		else
		{
			g_update_manual = 1;
			MfSdkTmsHeartBeat();
		}
	}
}

#if 0
static int tms_size = -1;
#define TMS_SIZE	200
void tms_test_func()
{
	int progress = 0;
	if(tms_size == -1)
	{
		TmsPageCreate();
		app_tms_page_show(0);
		tms_size = 0;
	}

	if(tms_size<=TMS_SIZE &&tms_size >=0)
	{
	    progress = 100 * tms_size / TMS_SIZE;
		update_tms_progress(progress);
		tms_size+=10;
	}
}
#endif

