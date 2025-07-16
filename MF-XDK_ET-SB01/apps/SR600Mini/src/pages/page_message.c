#include "lvgl/lvgl.h"
#include <stdio.h>
#include "pages.h"
#include "page_pub.h"


static lv_obj_t* page_parent = NULL;
static lv_obj_t* page_win = NULL;
static lv_obj_t* lab_title = NULL;
static lv_obj_t* lab_message = NULL;
static lv_task_t* task_meaasge=NULL;
static lv_obj_t* page_subwin = NULL;
static lv_obj_t* load_img = NULL;
static int m_timeover;
static int m_timeovr_reset;

static page_close_page_func m_page_close_page_func = 0;
static tts_play_func m_tts_play_func = 0;
static page_timer_func m_timer_func = 0;
static char m_payload[1024] = {0};
static int m_payloadlen = 0;
static char* imag_path=NULL;

static void _message_close_page(int ret)
{
	APP_TRACE("page_message_show_ex _message_close_page:%d\r\n",ret);
    m_timer_func = 0;	
    if (page_win != 0) 
	{
		if(imag_path)
		{
			lv_free_png_file(imag_path);
			imag_path=NULL;
		}
		if(page_subwin)
		{
			lv_free_png_file(CARDPNG_320X480);
			if(load_img)
			{
				lv_obj_del(load_img);
				load_img = 0;
			}
			lv_obj_del(page_subwin);
			page_subwin = 0;
		}
		if(task_meaasge)
		{
			lv_task_del(task_meaasge);
    		task_meaasge = 0;
		}
		if(0 != lab_message)
		{
			lv_obj_del(lab_message);
			lab_message = 0;
		}
		lv_obj_del(page_win);
        page_win = 0;
		APP_TRACE("page_message_show_ex _message_close_page:%d finish\r\n",ret);
		if (m_page_close_page_func != 0) m_page_close_page_func(ret,page_parent);
        //m_page_close_page_func = 0;
		if (m_tts_play_func != 0)
			m_tts_play_func = 0;
    }
    
}

void wifi_message_close_page()
{
    _message_close_page(PAGE_RET_CANCEL);
}
#if 0
static void _message_btn_event_cb(struct _lv_obj_t* obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) 
	{
       if (obj == btn_canel) 
	   {
           _message_close_page(PAGE_RET_CANCEL);
       }
       else if (obj == btn_confirm) 
	   {
           _message_close_page(PAGE_RET_CONFIRM);
       }

    }
}
#endif
static void _message_event_cb(lv_obj_t* obj, lv_event_t e)
{
	uint32_t key;
	lv_coord_t dist = 62;
	
    if (e == LV_EVENT_KEY) 
	{
        m_timeover = m_timeovr_reset;

        key = page_get_key(0);
		APP_TRACE("_message_event_cb key:%d\r\n",key);
        if (key == MF_LV_KEY_CANCEL_SHORT_PRESS) 
		{
            _message_close_page(PAGE_RET_CANCEL);
        }   
        else if (key == MF_LV_KEY_OK_SHORT_PRESS) 
		{
            _message_close_page(PAGE_RET_CONFIRM);
        }    
        else if (key == MF_LV_KEY_9_SHORT_PRESS) 
		{
		   if(lab_message)
		   {
	           lv_obj_t* page = (lv_obj_t*)lv_obj_get_user_data(lab_message);
	           if (page != NULL) 
			   {
	               lv_page_scroll_ver(page, dist);
	           }
		   }
       }
	   else if (key == MF_LV_KEY_7_SHORT_PRESS) 
	   {
	   		if(lab_message)
			{
			   lv_obj_t* page = (lv_obj_t *)lv_obj_get_user_data(lab_message);
			   if (page != NULL) 
			   {
				   lv_page_scroll_ver(page, -dist);
			   }
	   		}
	   }
    }
}


static void _message_task_func(lv_task_t* task)
{
	if(NULL != m_tts_play_func && NULL != m_payload && m_payloadlen>0)
	{
		m_tts_play_func(m_payload, m_payloadlen);
		memset(m_payload, 0, sizeof(m_payload));
		m_tts_play_func = 0;
		m_payloadlen = 0;
	}

    APP_TRACE("page_message_show_ex _message_task_func:%d\r\n", m_timeover);
	if (m_timeover > 0) 
	{
		m_timeover -= 1000;
		if (m_timeover <= 0) 
		{
            _message_close_page(PAGE_RET_TIMEOVR);
            return;
		}
	}

    if(m_timer_func != 0 && page_win != 0)
	{
        m_timer_func(page_win, lab_message);
    }
}


lv_obj_t* page_message_show_ex(lv_obj_t* parent, void* pfunc, char* title, char* message, char* leftbtn, char* rightbtn, int timeover,int show_back)
{
    int height = 0;

	if(parent == NULL)
	{
		APP_TRACE("page_message_show_ex error is null title:%s\r\n",title);
		return NULL;
	}
	page_parent = parent;
    m_timeover = timeover;
    m_timeovr_reset = timeover;

    m_page_close_page_func = (page_close_page_func)pfunc;

    page_win = page_create_win(parent, _message_event_cb);

    if (title != NULL) 
	{
        lab_title = page_create_title(page_win, title);
        height += page_get_title_height(LCD_DISP_NULL);
    }
	
	APP_TRACE("page_message_show_ex message:%s\r\n",message);
    //lab_message = page_create_msg(page_win, message);
	lab_message = page_ShowTextOut(page_win, message, LV_ALIGN_CENTER, 0, 10, LV_COLOR_BLACK, LV_FONT_MF12);

	if(show_back)
	{
		page_subwin = page_createwin_title(title, LCD_DISP_FRONT);
		if(page_subwin)
		{
			page_ShowTextOut(page_subwin, "CARD NO.", LV_ALIGN_IN_TOP_MID, 0, 120, LV_COLOR_BLACK, LV_FONT_24);
			page_ShowTextOut(page_subwin, message, LV_ALIGN_CENTER, 0, -60, LV_COLOR_BLACK, LV_FONT_24);

			lv_load_png_file(CARDPNG_320X480);
			load_img = lv_img_create(page_subwin, NULL);
			lv_img_set_src(load_img, CARDPNG_320X480);
			lv_obj_align(load_img, NULL, LV_ALIGN_CENTER, 0, 80);
		}
	}
    m_timer_func = 0;

    if (task_meaasge) 
	{
        lv_task_del(task_meaasge);
        task_meaasge = 0;
    }
    task_meaasge = lv_task_create(_message_task_func, 1000, LV_TASK_PRIO_MID, 0);

    return page_win;
}

lv_obj_t* page_message_show_wifi(lv_obj_t* parent, void* pfunc, char* title, char* message, char* leftbtn, char* rightbtn, int timeover,int show_back)
{
    int height = 0;

	if(parent == NULL)
	{
		APP_TRACE("page_message_show_ex error is null title:%s\r\n",title);
		return NULL;
	}
	page_parent = parent;
    m_timeover = timeover;
    m_timeovr_reset = timeover;

    m_page_close_page_func = (page_close_page_func)pfunc;

    page_win = page_create_win(parent, _message_event_cb);

    if (title != NULL) 
	{
        lab_title = page_create_title(page_win, title);
        height += page_get_title_height(LCD_DISP_NULL);
    }
	
	APP_TRACE("page_message_show_ex message:%s\r\n",message);
    //lab_message = page_create_msg(page_win, message);
	page_ShowTextOut(page_win, "Already linked WIFI:", LV_ALIGN_IN_TOP_MID, 0, 16, LV_COLOR_BLACK, LV_FONT_MF12);

	lab_message = lv_label_create(page_win, NULL);
	lv_label_set_long_mode(lab_message, LV_LABEL_LONG_DOT);
	lv_obj_set_width(lab_message, lv_obj_get_width(page_win) - 10);
	page_show_text_font(lab_message, message, LCD_DISP_NULL);
	lv_obj_align(lab_message, NULL, LV_ALIGN_CENTER, 0, 10);

    m_timer_func = 0;

    if (task_meaasge) 
	{
        lv_task_del(task_meaasge);
        task_meaasge = 0;
    }
    task_meaasge = lv_task_create(_message_task_func, 1000, LV_TASK_PRIO_MID, 0);



    return page_win;
}

lv_obj_t* page_message_show(lv_obj_t* parent , void * pfunc , char * title, char * message ,char * leftbtn, char *rightbtn, int timeover)
{
    int height = 0;

	if(parent == NULL)
	{
		APP_TRACE("page_message_show_ex error is null title:%s\r\n",title);
		return NULL;
	}
	page_parent = parent;
    m_timeover = timeover;
    m_timeovr_reset = timeover;

    m_page_close_page_func = (page_close_page_func)pfunc;

    page_win = page_create_win(parent, _message_event_cb);

    if (title != NULL) 
	{
        lab_title = page_create_title(page_win, title);
        height += page_get_title_height(LCD_DISP_NULL);
    }
	
	//APP_TRACE("page_message_show_ex message:%s\r\n",message);
    lab_message = page_create_msg(page_win, message);

    m_timer_func = 0;

    if (task_meaasge) 
	{
        lv_task_del(task_meaasge);
        task_meaasge = 0;
    }
	if(m_timeover)
    	task_meaasge = lv_task_create(_message_task_func, 1000, LV_TASK_PRIO_MID, 0);

    return page_win;
}

