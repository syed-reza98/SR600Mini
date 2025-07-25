#include "lvgl/lvgl.h"
#include <stdio.h>
#include "pages.h"
#include "page_pub.h"

static lv_obj_t* page_parent = NULL;
static lv_obj_t* page_win = NULL;
static lv_obj_t* lab_title = NULL;
static lv_obj_t* lab_message = NULL;
static lv_obj_t* lab_countdown = NULL;
//static lv_obj_t* btn_canel = NULL;
//static lv_obj_t* btn_confirm = NULL;
static lv_task_t* task_meaasge=NULL;
static int m_timeover;
static int m_timeovr_reset;



static page_close_page_func m_page_close_page_func = 0;
static tts_play_func m_tts_play_func = 0;
static page_timer_func m_timer_func = 0;
static unsigned char m_payload[1024] = {0};
static unsigned int m_payloadlen = 0;
static char* g_title = 0;

static void _message_close_page(int ret)
{
	APP_TRACE("http page_message_show_ex _message_close_page:%d\r\n",ret);
    m_timer_func = 0;	
    if (page_win != 0) {	
		if(lab_message){
			lv_obj_del(lab_message);
    		lab_message = 0;
		}
		if(lab_countdown){
			lv_obj_del(lab_countdown);
    		lab_countdown = 0;
		}

		if(task_meaasge){
			lv_task_del(task_meaasge);
    		task_meaasge = 0;
		}
		lv_obj_del(page_win);
        page_win = 0;
		//lab_message = 0;
        //lab_countdown = 0;
		APP_TRACE("http page_message_show_ex _message_close_page:%d finish\r\n",ret);
		if (m_page_close_page_func != 0) m_page_close_page_func(ret,page_parent);
        m_page_close_page_func = 0;
		if (m_tts_play_func != 0)
			m_tts_play_func = 0;
    }
    
}

static void _message_event_cb(lv_obj_t* obj, lv_event_t e)
{
	uint32_t key;
	
    if (e == LV_EVENT_KEY) {
        m_timeover = m_timeovr_reset;

        key = page_get_key();
		APP_TRACE("_message_event_cb key:%d\r\n",key);
        if (key == MF_LV_KEY_CANCEL_SHORT_PRESS) {
            _message_close_page(PAGE_RET_CANCEL);
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
	if (m_timeover > 0) {
		m_timeover -= 1000;
        char countdown[8] = { 0 };
        //lv_obj_set_style_local_text_font(btn1, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
        snprintf(countdown, sizeof(countdown), "(%02ds)", m_timeover / 1000);
        lv_label_set_text(lab_countdown, countdown);
		if (m_timeover <= 0) {
            _message_close_page(PAGE_RET_TIMEOVR);
            return;
		}
	}

    if(m_timer_func != 0 && page_win != 0){
        m_timer_func(page_win, lab_message);
    }
}
static void back_navigation_event_cb(lv_obj_t* btn, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        if (!btn) return;
        APP_TRACE("back_navigation_event_cb obj:%p\r\n", btn);
        _message_close_page(PAGE_RET_CANCEL);
    }
}
void free_http_message_page()
{
    _message_close_page(PAGE_RET_CANCEL);
}
void set_http_tts_play_func(tts_play_func pfunc, unsigned char *payload, unsigned int payloadlen)
{
	if(NULL != pfunc)
		m_tts_play_func = pfunc;
	if(payloadlen > 0 && payloadlen < sizeof(m_payload))
	{
		memcpy(m_payload, payload, payloadlen);
		m_payloadlen = payloadlen;

	}
}
void page_http_update(char* title, char* message)
{
	char temp[32] = {0};
	
	lv_start_lock(1);
	if(NULL != title)
	{
		strcat(temp, title);
	}
    else if(g_title)
    {
		strcat(temp, g_title);
	}
    lv_label_set_text(lab_title, temp);

	if(message)
	{
		lv_label_set_text(lab_message, message);
		lv_obj_align(lab_message, NULL, LV_ALIGN_CENTER, 0, 0);
	}
	lv_start_lock(0);
}

lv_obj_t* page_http_message_show_ex(lv_obj_t* parent, void* pfunc, char* title, char* message, char* leftbtn, char* rightbtn, int timeover,int show_back)
{
    int height = 0;
	if(parent == NULL){
		APP_TRACE("page_message_show_ex error is null title:%s\r\n",title);
		return NULL;
	}
	page_parent = parent;
    m_timeover = timeover;
    m_timeovr_reset = timeover;

    m_page_close_page_func = (page_close_page_func)pfunc;

    page_win = page_create_win(parent, _message_event_cb);

    if (title != NULL) {
		g_title = title;
        lab_title = page_create_title(page_win, title);
        height += page_get_title_height(LCD_DISP_NULL);
    }
	lab_message = page_ShowTextOut(page_win, message, LV_ALIGN_CENTER, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);

    char countdown[8] = { 0 };
    snprintf(countdown, sizeof(countdown), "(%02ds)", timeover / 1000);
	lab_countdown = page_ShowTextOut(page_win, countdown, LV_ALIGN_CENTER, 0, 70, LV_COLOR_BLACK, LV_FONT_MF12);
#if 0
    if (title != NULL && show_back) {
        lv_load_png_file(IMG_NAVIGATION_BACK);
        lv_obj_t* left_imgbtn = lv_img_create(page_win, NULL);
        lv_img_set_src(left_imgbtn, IMG_NAVIGATION_BACK);
        lv_obj_set_click(left_imgbtn, true);
        lv_obj_set_user_data(left_imgbtn, (lv_obj_user_data_t)page_win);
        lv_obj_set_event_cb(left_imgbtn, back_navigation_event_cb);
        lv_obj_align(left_imgbtn, NULL, LV_ALIGN_IN_TOP_LEFT, 16, 6);
    }
#endif
    m_timer_func = 0;

    if (task_meaasge) {
        lv_task_del(task_meaasge);
        task_meaasge = 0;
    }
    task_meaasge = lv_task_create(_message_task_func, 1000, LV_TASK_PRIO_MID, 0);

    return page_win;
}

lv_obj_t* page_http_message_show(lv_obj_t* parent , void * pfunc , char * title, char * message ,char * leftbtn, char *rightbtn, int timeover)
{
    return page_http_message_show_ex(parent,pfunc,title,message,leftbtn,rightbtn,timeover,0);
}

void page_http_message_set_timer_func(void* pfunc)
{
    m_timer_func = pfunc;
}
