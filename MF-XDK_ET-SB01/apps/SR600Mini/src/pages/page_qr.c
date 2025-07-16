#include "lvgl/lvgl.h"
#include "page_pub.h"
#include "page_qr.h"
#include "pages.h"
#include "libapi_xpos/inc/mfsdk_tms.h"

//#define QR_HEIGHT 240
#define PAY_DEMO_BASE_COLOR 0xF3F4F6

static int g_PowerLock = QRPAGE_LOCK_DEF;
static int m_timeover = 0;
static int exit_time = 0;
static page_close_page_func m_page_close_page_func = 0;
static lv_obj_t* page_win = NULL;
static lv_obj_t* text_label2 = NULL;
static lv_task_t* task_qrcode = NULL;
static lv_obj_t* paymentqr = NULL;
static lv_obj_t* sub_win = NULL;

void SetPowerLock (int value)
{
	g_PowerLock = value;
	APP_TRACE("[%s] g_PowerLock = %d\r\n", __FUNCTION__, g_PowerLock);
	return;
}

int GetPowerLock (void)
{
	APP_TRACE("[%s] g_PowerLock = %d\r\n", __FUNCTION__, g_PowerLock);
	return g_PowerLock;
}

void LockStatusCheck()
{
	APP_TRACE("[%s] g_PowerLock = %d\r\n", __FUNCTION__, g_PowerLock);
	if(QRPAGE_LOCK_ON == g_PowerLock)
	{
		AppPowerUnlockApp("qr");
		AppPowerLockApp((char*)"qr");
	}
	else if(QRPAGE_LOCK_DEF == g_PowerLock)
	{
		AppPowerLockApp((char*)"qr");
		SetPowerLock(QRPAGE_LOCK_ON);
	}

}

void _close_qrcode_page(int ret)
{
    if (ret == CARD_RET_TIMEOVER) 
	{
        if (page_win != NULL) 
		{
            if (text_label2)
                lv_label_set_text(text_label2,"timeout!");
            exit_time = 5000;
        }
    }
    else 
	{
		if(task_qrcode)
		{
			lv_task_del(task_qrcode);
    		task_qrcode = 0;
		}
		if(sub_win)
		{
			lv_obj_del(sub_win);
			sub_win = 0;
		}
		if (page_win != 0) 
		{
			if(text_label2)
			{
				lv_obj_del(text_label2);
		        text_label2 = 0;
			}
			if (paymentqr)
			{
				lv_qrcode_delete(paymentqr);
				paymentqr = 0;
			}
			lv_obj_del(page_win);
	        page_win = 0;
	    }
	} 
    
}

void close_qrcode_page(int ret)
{
	APP_TRACE("close_qrcode_page\r\n");
	_close_qrcode_page(ret);

	if (CARD_RET_TIMEOVER != ret)
	{
		if(QRPAGE_LOCK_ON == GetPowerLock())
		{
			AppPowerUnlockApp("qr");
		}
		SetPowerLock(QRPAGE_LOCK_DEF);

    	if (m_page_close_page_func != 0) m_page_close_page_func(ret, NULL);
    	m_page_close_page_func = 0;
		MfSdkTmsAppBusy(MFSDK_TMS_APP_NOT_BUSY);
	}
}

static void _qrcode_task_func(lv_task_t* task)
{

    //MfSdkPowerSupertimeReset();
    if (m_timeover > 0) 
	{
        APP_TRACE("mf_rfid_tcl_open m_timeover = %d\r\n", m_timeover);
        m_timeover -= 1000;
        if (m_timeover <= 0) 
		{
			close_qrcode_page(CARD_RET_TIMEOVER);
        }
    }
    if (exit_time > 0) 
	{
        APP_TRACE("mf_rfid_tcl_open exit_time = %d\r\n", exit_time);
        exit_time -= 1000;
        if (exit_time <= 0) 
		{
			close_qrcode_page(CARD_RET_CANCEL);
        }
    }

}

static void _page_code_event_cb(lv_obj_t* obj, lv_event_t e)
{
	uint32_t key;

    if (e == LV_EVENT_KEY) 
	{
        key = page_get_key();
		APP_TRACE("_page_code_event_cb ret == %d\r\n", key);
		if (key == MF_LV_KEY_CANCEL_SHORT_PRESS)
		{
			close_qrcode_page(CARD_RET_CANCEL);
			//MfSdkGuiLedAmount("0.00");
		}
    }
}

lv_obj_t* page_show_qrcode(lv_obj_t* parent, void *pfunc, char* title, char* tip, char* data, int timeout)
{
	int left = 30;
	lv_obj_t* win = NULL;

	if(parent == NULL || strlen(data) <= 0)
	{
		APP_TRACE("parent is null!\r\n");
		return NULL;
	}
	_close_qrcode_page(0);
	MfSdkTmsAppBusy(MFSDK_TMS_APP_STATE_BUSY);

	APP_TRACE("%s\r\n", __FUNCTION__);
	exit_time = 0;
    m_timeover = timeout;
    m_page_close_page_func = (page_close_page_func)pfunc;

	LockStatusCheck();

	PubMultiPlay((const s8*)"pscode.mp3");
	
	page_select_disp(LCD_DISP_FRONT);
	page_win = lv_obj_create(parent, NULL);
	win = page_win;
	lv_obj_set_event_cb(win, _page_code_event_cb);
	lv_obj_set_style_local_bg_color(win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(PAY_DEMO_BASE_COLOR));
	lv_obj_set_style_local_radius(win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_size(win, lv_obj_get_width(parent), lv_obj_get_height(parent));

    page_create_title(win, "QRCODE");
	page_ShowTextOut(win, "Amount:", LV_ALIGN_IN_TOP_MID, 0, 80, LV_COLOR_BLACK, LV_FONT_24);
	page_ShowTextOut(win, title, LV_ALIGN_IN_TOP_MID, 0, 110, LV_COLOR_RED, LV_FONT_24);
	text_label2 = page_ShowTextOut(win, tip, LV_ALIGN_IN_BOTTOM_MID, 0, -20, LV_COLOR_BLACK, LV_FONT_24);

	page_group_set_obj(win);
#if 1
	page_select_disp(LCD_DISP_BEHIND);
	lv_obj_t* subparent = get_subpage();//get_page_win();
	sub_win = lv_obj_create(subparent, NULL);
	lv_obj_set_size(sub_win, lv_obj_get_width(subparent), lv_obj_get_height(subparent));
	page_create_title(sub_win, "QRCODE");
	page_ShowTextOut(sub_win, title, LV_ALIGN_CENTER, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);
	page_ShowTextOut(sub_win, tip, LV_ALIGN_IN_BOTTOM_MID, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);
#else
	sub_win = page_createwin_title(title, LCD_DISP_BEHIND);
	if(sub_win)
	{
		lv_obj_set_size(sub_win, lv_obj_get_width(sub_win), lv_obj_get_height(sub_win));
		page_create_title(sub_win, "QRCODE");
		page_ShowTextOut(sub_win, title, LV_ALIGN_CENTER, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);
		page_ShowTextOut(sub_win, tip, LV_ALIGN_IN_BOTTOM_MID, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);
	}
#endif
	/*Create a QR code*/
	paymentqr = lv_qrcode_create(win, lv_obj_get_width(parent)-2*left, LV_COLOR_BLACK, LV_COLOR_WHITE);
	lv_obj_align(paymentqr, win, LV_ALIGN_CENTER, 0, 40);

	/*Set data*/
	lv_qrcode_update(paymentqr, data, strlen(data));

    if(timeout>0)
	    task_qrcode = lv_task_create(_qrcode_task_func, 1000, LV_TASK_PRIO_MID, 0);

	return win;
}

lv_obj_t* page_show_qrcode_ex(lv_obj_t* parent, void *pfunc, char* title, char* tip, char* data, int timeout)
{
	lv_obj_t* win = NULL;

	if(parent == NULL || strlen(data) <= 0)
	{
		APP_TRACE("parent is null!\r\n");
		return NULL;
	}
	_close_qrcode_page(0);

	APP_TRACE("%s\r\n", __FUNCTION__);
	exit_time = 0;
    m_timeover = timeout;
    m_page_close_page_func = (page_close_page_func)pfunc;

	LockStatusCheck();

	//PubMultiPlay((const s8*)"pscode.mp3");
	
	page_select_disp(LCD_DISP_BEHIND);
	page_win = lv_obj_create(parent, NULL);
	win = page_win;
	lv_obj_set_event_cb(win, _page_code_event_cb);
	lv_obj_set_style_local_bg_color(win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_style_local_radius(win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_size(win, lv_obj_get_width(parent), lv_obj_get_height(parent));

	page_group_set_obj(win);
	/*Create a QR code*/
	paymentqr = lv_qrcode_create(win, lv_obj_get_height(parent), LV_COLOR_BLACK, LV_COLOR_WHITE);
	lv_obj_align(paymentqr, win, LV_ALIGN_CENTER, 0, 0);

	/*Set data*/
	lv_qrcode_update(paymentqr, data, strlen(data));

    if(timeout>0)
	    task_qrcode = lv_task_create(_qrcode_task_func, 1000, LV_TASK_PRIO_MID, 0);

	return win;
}

void show_page_qrcode(lv_obj_t* parent, void *pfunc, char*amount, char*qrcode, int timeover)
{
	//QR code display
	if(NULL != parent && strlen(qrcode)>0)
	{
		message_close_show_image(0);
		page_show_qrcode(parent, pfunc, amount, "Please Scan", qrcode, timeover);
	}
	
	return;
}

