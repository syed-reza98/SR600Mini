#include "lvgl/lvgl.h"
#include <stdio.h>
#include "pages.h"
#include "card/func_pay.h"
#include "page_pub.h"

#define IC_CARD_SOCKET	0
#define CHECK_TIMER		(200)
#define POS_OFFSET		(50)
#define RFCARD_OFFSET		(POS_OFFSET-30)

static lv_obj_t* emv_page_win = NULL;
static lv_obj_t* lab_message = NULL;
static lv_obj_t* page_win = NULL;
static lv_obj_t* lab_title = NULL;
static lv_obj_t* lab_buff = NULL;
static lv_obj_t* page_subwin =NULL;
static lv_obj_t* img = NULL;
static lv_obj_t* img_card = NULL;
static lv_obj_t* img_rfidlog = NULL;

static lv_task_t* task_card = NULL;
static lv_task_t* task_card_disp = NULL;
//static struct magtek_track_info * m_trackinfo;
static int m_timeover = 0; 
static int exit_time = 0;
static int g_mode = 0;
static int g_title = 0;
const char* image_name = NULL;
static int imgShowChange = 0;

static page_close_page_func m_page_close_page_func = 0;

void card_close_subpage()
{
	if(page_subwin != NULL)
	{
		if(TRANSTYPE_IC == g_mode)
		{
			lv_free_png_file(ICPNG);
			lv_free_png_file(ICPNG2);
			lv_free_png_file(ICPNG3);
		}
		else if(TRANSTYPE_RF == g_mode)
		{
			if(MFSDK_TRUE == MfSdkNfcIsAroundFrontLcd())
			{
				lv_free_png_file(POSPNG);
				lv_free_png_file(RFCARDPNG);
				lv_free_png_file(RFIDLOGOPNG);
			}
			else
			{
				lv_free_png_file(RFPNG);
				lv_free_png_file(RFPNG2);
				lv_free_png_file(RFPNG3);
			}
		}
		if (img_card != NULL) 
		{
			lv_obj_del(img_card);
			img_card = NULL;
		}
		if(img_rfidlog != NULL)
		{
			lv_obj_del(img_rfidlog);
			img_rfidlog = NULL;
		}
		if (img != NULL) 
		{
            lv_obj_del(img);
            img = NULL;
		}
		if (task_card_disp) 
		{
			lv_task_del(task_card_disp);
			task_card_disp = NULL;
		}
        lv_obj_del(page_subwin);
        page_subwin = NULL;
		imgShowChange = 0;
	}
}
static void _card_close_page(int ret)
{
    if (ret == CARD_RET_TIMEOVER) 
	{
        if (page_win != NULL) 
		{
            if (lab_buff)
                lv_label_set_text(lab_buff,"read card timeout!");
            exit_time = 3000;
        }
    }
    else 
	{
        if (page_win != NULL) 
		{
			if (lab_title != NULL)
			{
	            lv_obj_del(lab_title);
	            lab_title = NULL;
			}
			if (lab_buff != NULL) 
			{
	            lv_obj_del(lab_buff);
	            lab_buff = NULL;
			}
            lv_obj_del(page_win);
            page_win = NULL;
            if (task_card)
			{
                lv_task_del(task_card);
                task_card = NULL;
            }

			if (ret == CARD_RET_CANCEL || ret == CARD_RET_TIMEOVER)
			{
				if(TRANSTYPE_RF == g_mode)
					MfSdkNfcClose();
				card_close_subpage();
			}
			
            if (m_page_close_page_func != 0) m_page_close_page_func(ret, NULL);
            m_page_close_page_func = 0;
        }
    }
}
void free_readcard_page()
{
    _card_close_page(CARD_RET_CANCEL);
}

static void _card_event_cb(lv_obj_t* obj, lv_event_t e)
{
	uint32_t key;

    if (e == LV_EVENT_KEY) 
	{
        key = page_get_key();
		APP_TRACE("_card_event_cb ret == %d\r\n", key);
		if (key == MF_LV_KEY_CANCEL_SHORT_PRESS)
		{
	        _card_close_page(CARD_RET_CANCEL);
		}
    }
}

static void _card_disp_task_func(lv_task_t* task)
{
	if (g_mode == TRANSTYPE_IC)
	{
		switch (imgShowChange)
		{
		case 0:
			lv_img_set_src(img, ICPNG2);
			break;
		case 1:
			lv_img_set_src(img, ICPNG3);
			break;
		case 2:
			lv_img_set_src(img, ICPNG);
			break;
		default:
			break;
		}
	}
	else if (g_mode == TRANSTYPE_RF)
	{
		if(MFSDK_TRUE == MfSdkNfcIsAroundFrontLcd())
		{
			switch (imgShowChange)
			{
			case 0:
				lv_obj_align_x(img_card, NULL, LV_ALIGN_CENTER, -60);
				break;
			case 1:
				lv_obj_align_x(img_card, NULL, LV_ALIGN_CENTER, 0);
				break;
			case 2:
				lv_obj_align_x(img_card, NULL, LV_ALIGN_CENTER, -90);
				break;
			default:
				break;
			}
		}
		else
		{
			switch (imgShowChange)
			{
			case 0:
				lv_img_set_src(img, RFPNG2);
				break;
			case 1:
				lv_img_set_src(img, RFPNG3);
				break;
			case 2:
				lv_img_set_src(img, RFPNG);
				break;
			default:
				break;
			}
		}
	}

	if (imgShowChange == 2)
		imgShowChange = 0;
	else
		imgShowChange++;
}

static void _card_task_func(lv_task_t* task)
{
    int ret;

	if(TRANSTYPE_RF == g_mode)
	{
	    ret = MfSdkNfcDetect();
	    APP_TRACE("mf_rfid_tcl_open ret = %d\r\n", ret);
	    if (ret >= 0) 
		{
	        _card_close_page(CARD_RET_RFIC);
	        return;
	    }
	}
	else if(TRANSTYPE_IC == g_mode)
	{
		ret = MfSdkIccInsertDetect() == MFSDK_ICC_RET_OK ? 1 : 0;	
	    APP_TRACE("icc_present ret = %d\r\n", ret);
		if (ret  == 1) 
		{
			_card_close_page(CARD_RET_ICC);
			return;
		}
	}
	
    if (m_timeover > 0) 
	{
        APP_TRACE("mf_rfid_tcl_open m_timeover = %d\r\n", m_timeover);
        m_timeover -= CHECK_TIMER;
        if (m_timeover <= 0) 
		{
            _card_close_page(CARD_RET_TIMEOVER);
        }
    }
    if (exit_time > 0) 
	{
        APP_TRACE("mf_rfid_tcl_open exit_time = %d\r\n", exit_time);
        exit_time -= CHECK_TIMER;
        if (exit_time <= 0) 
		{
            _card_close_page(CARD_RET_CANCEL);
        }
    }

}
static void back_navigation_event_cb(lv_obj_t* btn, lv_event_t event)
{
	if (event == LV_EVENT_CLICKED) 
	{
		if (!btn) return;
		_card_close_page(CARD_RET_CANCEL);
	}
}

lv_obj_t* GetEmvPageWinTip()
{
	APP_TRACE("lab_message :%d",lab_message);
	return lab_message;
}

lv_obj_t* app_emv_get_page_win()
{
	APP_TRACE("app_emv_get_page_win :%d",emv_page_win);
	return emv_page_win;
}

void emvreadcardtiprelease(void)
{
	 if (emv_page_win != NULL)
	 {
		APP_TRACE("page_read_card_show page_create_win 01 emv_page_win=%p \r\n",emv_page_win);
		if(lab_message  != NULL)
		{
			lv_obj_del(lab_message);	
			lab_message = NULL;
		}
		lv_obj_del(emv_page_win);	
		emv_page_win = NULL;
	 }
}

static lv_style_t g_styleTitle = { 0 };
static lv_style_t* PageStyleGetTitle(void)
{
	lv_style_t* style = &g_styleTitle;
	if (style->map == 0) 
	{
		lv_style_init(style);
		lv_style_set_text_font(style, LV_STATE_DEFAULT, LV_FONT_MF12);
		lv_style_set_pad_top(style, LV_STATE_DEFAULT, 0);
		lv_style_set_text_color(style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	}
	return style;
}

lv_obj_t* page_read_card_show(lv_obj_t* parent, char* title, char* text, int timeout)
{
	if (parent == NULL) {
		return NULL;
	}
	
	APP_TRACE("page_read_card_show page_create_win 00 emv_page_win=%p \r\n",emv_page_win);

	emvreadcardtiprelease();	

	emv_page_win = lv_obj_create(parent, NULL);	
	lv_obj_reset_style_list(emv_page_win, LV_OBJ_PART_MAIN);
	lv_obj_set_style_local_bg_opa(emv_page_win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_0);
	lv_obj_set_size(emv_page_win, lv_obj_get_width(parent), lv_obj_get_height(parent));
	lv_obj_set_style_local_bg_color(emv_page_win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0xf3f4f6));//PAY_DEMO_BASE_CLOR
	//gui_group_set_obj(emv_page_win);

	lv_obj_t*lab_title = lv_label_create(emv_page_win, NULL);
	lv_label_set_long_mode(lab_title, LV_LABEL_LONG_CROP);
	lv_obj_set_width(lab_title, lv_obj_get_width(emv_page_win));
	lv_obj_set_height(lab_title, 14);
	lv_label_set_align(lab_title, LV_LABEL_ALIGN_CENTER);
	lv_label_set_text(lab_title, title);
	lv_obj_set_style_local_text_font(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_FONT_MF12);
	lv_obj_align(lab_title, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);
	lv_obj_add_style(lab_title, LV_LABEL_PART_MAIN, PageStyleGetTitle());
	lv_obj_set_style_local_radius(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_bg_opa(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
    lv_obj_set_style_local_bg_color(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_TITLE_COLOR);
	
	lab_message = lv_label_create(emv_page_win, NULL);
	lv_label_set_long_mode(lab_message, LV_LABEL_LONG_EXPAND);
	lv_obj_set_style_local_text_font(lab_message, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_FONT_MF12);
	lv_label_set_text(lab_message, text);
	lv_obj_align(lab_message, NULL, LV_ALIGN_CENTER, 0, 10);
	lv_obj_set_width(lab_message, lv_obj_get_width(emv_page_win) - 10);

    return emv_page_win;
}


lv_obj_t* page_card_showamt(lv_obj_t* parent, void* pfunc, char* title, void* trackinfo, char* amtstr, int mode, int timeover, int show_back)
{
	int posOffset = POS_OFFSET;
    char amt_format[32] = { 0 };
    char msg[64] = { 0 };
    long long  amt = 0;
	
    amt = atoll (amtstr);
    APP_TRACE("[%s] = %s\r\n", __FUNCTION__, amtstr);
    APP_TRACE("[%s] = %lld\r\n", __FUNCTION__, amt);
    //m_trackinfo = (struct magtek_track_info *)trackinfo;

    m_timeover = timeover;
    exit_time = 0;
	g_mode = mode;
	g_title = title;
    m_page_close_page_func = (page_close_page_func)pfunc;

    if (page_win != NULL)
    {
        lv_obj_del(page_win);
    }

	if(TRANSTYPE_IC == mode)
	{
	    PubMultiPlay((const s8*)"picard.mp3");
	    strcpy(msg, "Please insert card");
	}
	else if(TRANSTYPE_RF == mode)
	{
		MfSdkNfcLed(MFSDK_NFC_LED_BLUE, MFSDK_NFC_LED_ON);
	    PubMultiPlay((const s8*)"pwcard.mp3");
		if(1 == show_back)
		    strcpy(msg, "Please tap card again");
		else
	    	strcpy(msg, "Please tap card");
	}
	else
	{
		MfSdkNfcLed(MFSDK_NFC_LED_BLUE, MFSDK_NFC_LED_ON);
		strcpy(msg, "Please tap/insert card");
	}

    page_win = page_create_win(parent, _card_event_cb);
    lv_obj_set_size(page_win, lv_obj_get_width(parent), lv_obj_get_height(parent));
    lab_title = page_create_title(page_win, title);

	//amont label
    sprintf(amt_format, "%0.2f", amt/100.00);
	set_amt_timer(0);
	LedShowMessage(amt_format);	
	//lv_select_disp(0);
	page_ShowTextOut(page_win, amt_format, LV_ALIGN_IN_TOP_MID, 0, LINE_OFFSET_2, LV_COLOR_BLACK, LV_FONT_MF12);

	lab_buff = page_ShowTextOut(page_win, msg, LV_ALIGN_IN_BOTTOM_MID, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);

	page_subwin = page_createwin_title(title, LCD_DISP_FRONT);
	if(page_subwin)
	{
		page_ShowTextOut(page_subwin, "Amount:", LV_ALIGN_CENTER, 0, -130, LV_COLOR_BLACK, LV_FONT_24);
		page_ShowTextOut(page_subwin, amt_format, LV_ALIGN_CENTER, 0, -100, LV_COLOR_RED, LV_FONT_24);

		if(TRANSTYPE_IC == mode)
		{
			lv_load_png_file(ICPNG);
			lv_load_png_file(ICPNG2);
			lv_load_png_file(ICPNG3);
			image_name = ICPNG;
		}
		else if(TRANSTYPE_RF == mode)
		{
			if(MFSDK_TRUE == MfSdkNfcIsAroundFrontLcd())
			{
				lv_load_png_file(POSPNG);
				lv_load_png_file(RFCARDPNG);
				lv_load_png_file(RFIDLOGOPNG);
				image_name = POSPNG;

				posOffset+=50;
			}
			else
			{
				lv_load_png_file(RFPNG);
				lv_load_png_file(RFPNG2);
				lv_load_png_file(RFPNG3);
				image_name = RFPNG;
			}
		}

		img = lv_img_create(page_subwin, NULL);
		lv_img_set_src(img, image_name);
		lv_obj_align(img, NULL, LV_ALIGN_CENTER, 0, posOffset);
		
		if(TRANSTYPE_RF == mode && MFSDK_TRUE == MfSdkNfcIsAroundFrontLcd())
		{
			img_rfidlog = lv_img_create(page_subwin, NULL);
			lv_img_set_src(img_rfidlog, RFIDLOGOPNG);
			lv_obj_align(img_rfidlog, NULL, LV_ALIGN_IN_TOP_MID, 0, 160);
			img_card = lv_img_create(page_subwin, NULL);
			lv_img_set_src(img_card, RFCARDPNG);
			lv_obj_align(img_card, NULL, LV_ALIGN_CENTER, -90, posOffset-30);
		}

		page_ShowTextOut(page_subwin, msg, LV_ALIGN_IN_BOTTOM_MID, 0, -20, LV_COLOR_BLACK, LV_FONT_24);
		task_card_disp = lv_task_create(_card_disp_task_func, 1000, LV_TASK_PRIO_MID, 0);
	}

    task_card = lv_task_create(_card_task_func, CHECK_TIMER, LV_TASK_PRIO_HIGHEST, 0);

    return page_win;
}
