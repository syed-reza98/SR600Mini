#include "lvgl/lvgl.h"
#include "page_pub.h"
#include "page_main.h"
#include "tracedef.h"
#include "pub/queue_pub.h"
#include "./player_proc.h"


void page_group_set_obj(lv_obj_t* obj)
{
	MfSdkLvglGroupSet(obj);
}

void page_group_create()
{
	MfSdkLvglGuiInit();
}


int network_page_get_key()
{
	uint32_t key;
	const void* d = lv_event_get_data();
	memcpy(&key, d, sizeof(uint32_t));
	APP_TRACE("network_page_get_key key = %d\r\n", key);
	
	return key;
}

extern int tick_get_btn_play;
extern int press_btn_flag;


static int PubKeyRespProc(int key)
{
    int volume = 0;
    char s_play_name[DATA_SIZE + 1] = { 0 };

	
    if (key == MF_LV_KEY_QUIT_LONG_PRESS)
    {
        //mqtt_publish("0");
        PubMultiPlay((const s8 *)"shut.mp3");

        while (MfSdkAudTtsState() == 1)        //Broadcasting
        {
            MfSdkSysSleep(500);
        }

        APP_TRACE("Shutdown---------\t\n");
        MfSdkSysSleep(1000);
		MfSdkPowerOff();
    }
    else if (key == MF_LV_KEY_DOWN_SHORT_PRESS)
    {
        press_btn_flag = 1;
		tick_get_btn_play = MfSdkSysTimerOpen(500);
        volume = MfSdkAudGetVolume();//Sys_GetTtsVolume();

        if (volume < 5)
        {
            volume += 1;
			if(0 == volume)
			{
				MfSdkKbSetKeySound(1);
		        page_text_show(get_subpage(), "VOLUME", "Mute Off", 1000);
			}
			MfSdkAudSetVolumeRunning(volume);
            strcpy(s_play_name, TTS_VOLUME_NOR);
        }
        else
        {
            strcpy(s_play_name, TTS_VOLUME_MAX);
        }
        APP_TRACE("volume:%d\r\n", volume);
        fifo_key_set_zero();
        fifo_key_put((unsigned char*)s_play_name);
    }
    else if (key == MF_LV_KEY_UP_SHORT_PRESS)
    {
        press_btn_flag = 1;
		tick_get_btn_play = MfSdkSysTimerOpen(500);
        volume = MfSdkAudGetVolume();

		//volume = -1, Mute
		if (volume > 0)
		{
            volume -= 1;
			MfSdkAudSetVolumeRunning(volume);
			if (volume > 0)
			{
	            strcpy(s_play_name, TTS_VOLUME_NOR);
	        }
	        else
	        {
	            strcpy(s_play_name, TTS_VOLUME_MIN);
	        }
	        APP_TRACE("volume:%d\r\n", volume);
	        fifo_key_set_zero();
	        fifo_key_put((unsigned char*)s_play_name);
		}
		else if (0 == volume)
		{
			MfSdkKbSetKeySound(0);
			MfSdkAudSetVolumeRunning(-1);
	        page_text_show(get_subpage(), "VOLUME", "Mute ON", 1000);
		}
    }
    else if (key == MF_LV_KEY_FUNC_SHORT_PRESS)
    {
		MfSdkSysVersion();
		APP_TRACE("Free Spcace [%d]\r\n", MfSdkFsGetFreeSpace(""));
		APP_TRACE("Total Spcace [%d]\r\n", MfSdkFsGetTotalSpace(""));

        press_btn_flag = 1;
		tick_get_btn_play = MfSdkSysTimerOpen(500);

        fifo_key_set_zero();
        strcpy(s_play_name, TTS_BUTTON_M);
        fifo_key_put((unsigned char*)s_play_name);
    }
	else if (key == MF_LV_KEY_FUNC_LONG_PRESS)
	{
		while (MfSdkAudTtsState() == 1)//Broadcasting
		{
			MfSdkSysSleep(500);
		}

		PubMultiPlay((const s8*)"cnet.mp3");
		network_page_win();
	}
	else
	{

		//PubMultiPlay((const s8*)TTS_VOLUME_NOR);
	}

	return key;
}

static int PubKeyRespProcNoVolume(int key)
{
    char s_play_name[DATA_SIZE + 1] = { 0 };
	
    if (key == MF_LV_KEY_QUIT_LONG_PRESS)
    {
        PubMultiPlay((const s8 *)"shut.mp3");

        while (MfSdkAudTtsState() == 1)        //Broadcasting
        {
            MfSdkSysSleep(500);
        }

        APP_TRACE("Shutdown---------\t\n");
        MfSdkSysSleep(1000);
		MfSdkPowerOff();
    }
    else if (key == MF_LV_KEY_FUNC_SHORT_PRESS)
    {
		MfSdkSysVersion();
        press_btn_flag = 1;
		tick_get_btn_play = MfSdkSysTimerOpen(500);

        fifo_key_set_zero();
        strcpy(s_play_name, TTS_BUTTON_M);
        fifo_key_put((unsigned char*)s_play_name);
    }
	else if (key == MF_LV_KEY_FUNC_LONG_PRESS)
	{
		while (MfSdkAudTtsState() == 1)//Broadcasting
		{
			MfSdkSysSleep(500);
		}

		PubMultiPlay((const s8*)"cnet.mp3");
		network_page_win();
	}

	return key;
}

int page_get_key()
{
    uint32_t key = -1;
    const void* d = lv_event_get_data();

    memcpy(&key, d, sizeof(uint32_t));
	//MfSdkLcdBackLight(MFSDK_LCD_ON);
    APP_TRACE("page_get_key key = %d\r\n", key);

	PubKeyRespProc(key);
	return key;
}

int page_pin_get_key(int option)
{
    uint32_t key = -1;
    const void* d = lv_event_get_data();

    memcpy(&key, d, sizeof(uint32_t));
	APP_TRACE("%s option = %d, key = %d\r\n", __FUNCTION__, option, key);

	if (0 != option)
	{
		PubKeyRespProcNoVolume(key);
	}
	else
	{
		PubKeyRespProc(key);
	}

	return key;
}

void PageNetMenuKeyProc(int key)
{
	if(key >= MF_LV_KEY_QUIT_SHORT_PRESS)
	{
		PubKeyRespProc(key);
	}	
}

lv_obj_t* page_createwin_title(char *title, int type)
{
	int title_offset=0;
	int title_height=page_get_title_height(type);
	lv_obj_t* parent = 0;
	lv_obj_t* page_subwin =NULL;

	APP_TRACE("page_createwin_title type = %d\r\n", type);
	if(LCD_DISP_FRONT == type)
	{
		if (LCD_IS_128_32)
		{
			return NULL;
		}
		parent = get_mainpage();
		title_offset = page_get_statusbar_height(type);
	}
	else
	{
		page_select_disp(LCD_DISP_BEHIND);
		parent = get_subpage();
	}
	page_subwin = lv_obj_create(parent, NULL);
	lv_obj_set_style_local_bg_color(page_subwin, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_size(page_subwin, lv_obj_get_width(parent), lv_obj_get_height(parent));

	if(NULL != title && NULL != page_subwin)
	{
		lv_obj_t* lab_title = lv_label_create(page_subwin, NULL);
		lv_label_set_long_mode(lab_title, LV_LABEL_LONG_BREAK);
		lv_obj_set_size(lab_title, lv_obj_get_width(page_subwin), title_height);
		lv_label_set_align(lab_title, LV_LABEL_ALIGN_CENTER);

		page_show_text_font(lab_title, title, type);
		lv_obj_align(lab_title, page_subwin, LV_ALIGN_IN_TOP_LEFT, 0, title_offset);
		lv_obj_set_style_local_text_color(lab_title, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);

		lv_obj_set_style_local_radius(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
		lv_obj_set_style_local_bg_opa(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
	    lv_obj_set_style_local_bg_color(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_TITLE_COLOR);
		if(LCD_DISP_FRONT == type)
			lv_obj_set_style_local_text_font(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_FONT_32);
	}
	
	return page_subwin;
}

lv_obj_t*  page_ShowTextOut(lv_obj_t * parent, char *str, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs, lv_color_t color, lv_font_t* font)
{
	if(NULL == parent || NULL == str) return 0;

	APP_TRACE("ShowTextOut = %s \r\n", str);
	lv_obj_t *lab = lv_label_create(parent, NULL);
	lv_label_set_long_mode(lab, LV_LABEL_LONG_EXPAND);
	//lv_label_set_recolor(lab, true);
	lv_label_set_text(lab, str);
	lv_obj_set_style_local_bg_color(lab, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_style_local_text_font(lab, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, font);
	lv_obj_set_style_local_text_color(lab, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, color);
	lv_obj_set_width(lab, lv_obj_get_width(parent));
	lv_obj_align(lab, NULL, align, x_ofs, y_ofs);

	return lab;
}

static lv_obj_t* page_win = NULL;
static lv_task_t* task_meaasge = NULL;
static page_close_page_func m_page_close_page_func = 0;
static void create_msg_close_page(int ret)
{
    //m_timer_func = 0;
    if (page_win != 0)
    {
        if (task_meaasge)
        {
            lv_task_del(task_meaasge);
            task_meaasge = 0;
        }
        lv_obj_del(page_win);
        page_win = 0;
        if (m_page_close_page_func != 0) m_page_close_page_func(ret,NULL);
    }
}

static void _message_close_text_page(lv_task_t* task)
{
    create_msg_close_page(0);
}

static void page_create_msg_cb(lv_obj_t* obj, lv_event_t e)
{
    uint32_t key;

    if (e == LV_EVENT_KEY)
    {
        key = page_get_key();
        APP_TRACE("page_create_msg_cb key:%d\r\n", key);
		if(key == MF_LV_KEY_CANCEL_SHORT_PRESS || key == MF_LV_KEY_OK_SHORT_PRESS)
	        create_msg_close_page(PAGE_RET_CONFIRM);
    }
}

lv_obj_t* page_text_show(lv_obj_t* parent, char* title, char* text, int timeout)
{
    if (parent == NULL)
    {
        return NULL;
    }
	
    if (task_meaasge != 0)
    {
        lv_task_del(task_meaasge);
        task_meaasge = 0;
    }

    if (page_win != 0)
    {
        lv_obj_del(page_win);
        page_win = 0;
    }
    page_win = lv_obj_create(parent, NULL);
	lv_obj_set_style_local_radius(page_win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    page_group_set_obj(page_win);
    lv_obj_set_event_cb(page_win, page_create_msg_cb);
    lv_obj_set_size(page_win, lv_obj_get_width(parent), lv_obj_get_height(parent));
	if(title)
	    page_create_title(page_win, title);
    //lab_text = page_create_msg(page_win, text);

    lv_obj_t*lab_text = lv_label_create(page_win, NULL);
    lv_label_set_long_mode(lab_text, LV_LABEL_LONG_EXPAND);
    page_show_text_font(lab_text, text, LCD_DISP_NULL);
    lv_obj_align(lab_text, NULL, LV_ALIGN_CENTER, 0, 10);
    lv_obj_set_width(lab_text, lv_obj_get_width(page_win));

    if (timeout > 0)
    {
        task_meaasge = lv_task_create(_message_close_text_page, timeout, LV_TASK_PRIO_MID, 0);
    }
    return page_win;
}

lv_obj_t* page_text_show_cb(lv_obj_t* parent, void* pfunc, char* title, char* text, int timeout)
{
    if (parent == NULL)
    {
        return NULL;
    }
	
    if (task_meaasge != 0)
    {
        lv_task_del(task_meaasge);
        task_meaasge = 0;
    }

    if (page_win != 0)
    {
        lv_obj_del(page_win);
        page_win = 0;
    }
    m_page_close_page_func = (page_close_page_func)pfunc;
    page_win = lv_obj_create(parent, NULL);
	lv_obj_set_style_local_radius(page_win, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    page_group_set_obj(page_win);
    lv_obj_set_event_cb(page_win, page_create_msg_cb);
    lv_obj_set_size(page_win, lv_obj_get_width(parent), lv_obj_get_height(parent));
	if(title)
	    page_create_title(page_win, title);

    lv_obj_t*lab_text = lv_label_create(page_win, NULL);
    lv_label_set_long_mode(lab_text, LV_LABEL_LONG_EXPAND);
    page_show_text_font(lab_text, text, LCD_DISP_NULL);
    lv_obj_align(lab_text, NULL, LV_ALIGN_CENTER, 0, 10);
    lv_obj_set_width(lab_text, lv_obj_get_width(page_win));

    if (timeout > 0)
    {
        task_meaasge = lv_task_create(_message_close_text_page, timeout, LV_TASK_PRIO_MID, 0);
    }
    return page_win;
}

//api use for specific font library
lv_obj_t*  page_ShowText_Font(lv_obj_t * parent, char *str, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs, lv_color_t color, lv_font_t* font)
{
	static lv_style_t style;
	if(NULL == parent) return 0;

	lv_obj_t *lab = lv_label_create(parent, NULL);

	lv_style_reset(&style);
	lv_style_init(&style);
	lv_style_set_text_font(&style, LV_STATE_DEFAULT, font);
	lv_obj_add_style(lab, LV_LABEL_PART_MAIN, &style);

	lv_label_set_long_mode(lab, LV_LABEL_LONG_EXPAND);
	lv_label_set_text(lab, str);
	lv_obj_set_style_local_bg_color(lab, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_style_local_text_font(lab, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, font);
	lv_obj_set_style_local_text_color(lab, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, color);
	lv_obj_set_width(lab, lv_obj_get_width(parent));
	lv_obj_align(lab, NULL, align, x_ofs, y_ofs);

	return lab;
}

lv_obj_t*  page_ShowText_MultiFont(lv_obj_t * parent, MessageStingID index, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs, lv_color_t color, lv_font_t* font)
{
	static lv_style_t style;
	char *str = GetDispMessageFromCfg(index);
		
	if(NULL == parent || NULL == str || 0 == strlen(str)) return 0;

	if(1 == MultiFontInit())
		font = GetMultiFont();

	lv_style_reset(&style);
	lv_style_init(&style);
	lv_style_set_text_font(&style, LV_STATE_DEFAULT, font);

	lv_obj_t *lab = lv_label_create(parent, NULL);
	lv_obj_add_style(lab, LV_LABEL_PART_MAIN, &style);
	lv_label_set_long_mode(lab, LV_LABEL_LONG_EXPAND);
	lv_label_set_text(lab, str);
	lv_obj_set_style_local_bg_color(lab, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_style_local_text_font(lab, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, font);
	lv_obj_set_style_local_text_color(lab, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, color);
	lv_obj_set_width(lab, lv_obj_get_width(parent));
	lv_obj_align(lab, NULL, align, x_ofs, y_ofs);

	return lab;
}

