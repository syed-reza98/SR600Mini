#include <stdio.h>
#include "lvgl/lvgl.h"
#include "pages.h"

static page_close_page_func m_page_close_page_func = 0;
static lv_obj_t* page_win = NULL;
static lv_obj_t* page_list = NULL;
static lv_obj_t* lab_title = NULL;
static lv_task_t* task_list = NULL;
static lv_obj_t* list_body = NULL;

static int m_timeover = 0;
static int m_timeovr_reset = 0;
static int exit_time = 0;


static void _menu_list_close_page(int ret)
{
	if (page_win != 0) 
	{
		if (task_list)
		{
			lv_task_del(task_list);
			task_list = NULL;
		}
		//lv_obj_del(page_win);
		//page_win = 0;
		m_timeover = 0;
		exit_time = 0;
		if (m_page_close_page_func != 0) m_page_close_page_func(ret, list_body);
	}
}

static void _menu_list_btn_click(lv_obj_t* page_list, lv_obj_t* btn)
{
	int index = 0;
    if(page_list == NULL) { return ; }
		

	if (btn != 0) 
	{
		index = lv_list_get_btn_index(page_list, btn)+1;
		_menu_list_close_page(index);
	}
}

static lv_obj_t* _menu_list_get_index_btn(lv_obj_t* page_list, int key)
{
	lv_obj_t* btn = 0;
	lv_obj_t* btn_ret = 0;
	//const char* text;
	int index = 0;

	while (true) {
		btn = lv_list_get_next_btn(page_list, btn);
		index++;
		if (btn == NULL) break;
		if (index == key) 
		{
			//text = (const char*)lv_obj_get_user_data(btn);
			//APP_TRACE("_list_get_index_btn:%d.%s\r\n", index, text);
			btn_ret = btn;
			break;
		}
	}

	return btn_ret;
}

static void _menu_list_win_event_cb(struct _lv_obj_t* obj, lv_event_t event)
{
	lv_obj_t* page_list = NULL;
	lv_obj_t* btn;
	uint32_t key;
	
	if (!obj) return;
	page_list = (lv_obj_t*)lv_obj_get_user_data(page_win);

	if (event == LV_EVENT_KEY) 
	{
		m_timeover = m_timeovr_reset;
		key = page_get_key();
		APP_TRACE("list key:%d\r\n", key);

		if (key == MF_LV_KEY_OK_SHORT_PRESS) 
		{
			APP_TRACE("OK key:%d\r\n", key);
			btn = lv_list_get_btn_selected(page_list);
			APP_TRACE("lv_list_get_btn_selected\r\n");
			_menu_list_btn_click(page_list, btn);
		}
		else if (key == MF_LV_KEY_9_SHORT_PRESS) 
		{
			btn = lv_list_get_btn_selected(page_list);
			if (btn != 0) 
			{
				btn = lv_list_get_prev_btn(page_list, btn);
				if (btn != 0) 
				{
					lv_obj_set_style_local_text_color(btn, LV_LABEL_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_WHITE);
					lv_list_focus_btn(page_list, btn);
					lv_list_get_btn_index(page_list, btn);
				}
			}
		}
		else if (key == MF_LV_KEY_7_SHORT_PRESS) 
		{
			btn = lv_list_get_btn_selected(page_list);
			if (btn != 0) 
			{
				btn = lv_list_get_next_btn(page_list, btn);
				if (btn != 0) 
				{
					lv_obj_set_style_local_text_color(btn, LV_LABEL_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_WHITE);
					lv_list_focus_btn(page_list, btn);
					lv_list_get_btn_index(page_list, btn);
				}
			}

		}
		#if 0
		if (key >= MF_LV_KEY_1_SHORT_PRESS && key <= MF_LV_KEY_6_TRIPLE_PRESS || key == MF_LV_KEY_8_SHORT_PRESS) 
		{
			int keyValue = GetKeyValue(key);
			APP_TRACE("keyValue == %d\r\n", keyValue);
			if (0 == GetKeyStatus(key)) 
			{
				btn = _menu_list_get_index_btn(page_list, keyValue - 0x30);
				_menu_list_btn_click(page_list, btn);
			}
		}
		#endif
		/*else if (key == MF_LV_KEY_CANCEL_SHORT_PRESS) 
		{
			_menu_list_close_page(PAGE_RET_CANCEL);
		}*/
	}
}


static void _menu_list_btn_cb(lv_obj_t* obj, lv_event_t event)
{
	if (event == LV_EVENT_CLICKED) 
	{
		_menu_list_btn_click(page_list, obj);
	}
}

static lv_obj_t* _menu_list_btn_add(lv_obj_t* list_page, char* text, int index)
{
	char msg[128] = { 0 };

	lv_obj_t* btn = lv_list_add_btn(list_page, 0, 0);
	lv_btn_set_layout(btn, LV_LAYOUT_OFF);
	lv_obj_set_size(btn, lv_obj_get_width(list_page), page_get_btn_height());
	lv_obj_set_style_local_pad_ver(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 1);

	lv_obj_t* textlab = lv_label_create(btn, 0);
	lv_obj_set_size(textlab, lv_obj_get_width(list_page), 12);
	sprintf(msg, "%d. %s", index+1, text);
	lv_label_set_text(textlab, msg);
	lv_label_set_long_mode(textlab, LV_LABEL_LONG_DOT);
	
	if(LCD_DISP_BEHIND == get_disp_select())
		lv_obj_set_style_local_text_font(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_FONT_MF12);
	else
		lv_obj_set_style_local_text_font(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_FONT_16);
	lv_obj_set_event_cb(btn, _menu_list_btn_cb);
	lv_obj_set_user_data(btn, (lv_obj_user_data_t)text);

	return btn;
}

static void _menu_list_task_func(lv_task_t* task)
{
	if (m_timeover > 0) 
	{
		APP_TRACE("_menu_list_task_func:%d\r\n", m_timeover);
		m_timeover -= 1000;
		if (m_timeover <= 0) 
		{
			_menu_list_close_page(PAGE_RET_TIMEOVR);
		}
	}
	if (exit_time > 0) 
	{
		APP_TRACE("_menu_list_task_func exit_time = %d\r\n", exit_time);
		exit_time -= 1000;
		if (exit_time <= 0) 
		{
			_menu_list_close_page(CARD_RET_CANCEL);
		}
	}
}

lv_obj_t* page_menu_list_show_ex(lv_obj_t* parent, void* pfunc, char* title, char* listitem[], int count, int index, int timeover, int show_back)
{
	int i;
	int title_height = 0;
	lv_obj_t* btn;

	if(m_timeover <= 0)
		m_timeover = timeover;
	m_timeovr_reset = timeover;

	m_page_close_page_func = (page_close_page_func)pfunc;
	list_body = parent;
	if(0 != page_win)
	{
		lv_obj_del(page_win);
		page_win = 0;
	}

	page_win = page_create_win(parent, _menu_list_win_event_cb);

	if(title)
	{
		lv_obj_t* lab_title = lv_label_create(parent, NULL);
		lv_label_set_long_mode(lab_title, LV_LABEL_LONG_BREAK);
		lv_obj_set_size(lab_title, lv_obj_get_width(parent), page_get_title_height(LCD_DISP_NULL));
		lv_label_set_align(lab_title, LV_LABEL_ALIGN_CENTER);

		page_show_text_font(lab_title, title, LCD_DISP_NULL);
		lv_obj_align(lab_title, parent, LV_ALIGN_IN_TOP_LEFT, 0, 0);
		lv_obj_set_style_local_text_color(lab_title, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
		lv_obj_add_style(lab_title, LV_LABEL_PART_MAIN, page_style_get_title(LCD_DISP_BEHIND));

		lv_obj_set_style_local_radius(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
		lv_obj_set_style_local_bg_opa(lab_title, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
	    title_height = page_get_title_height(LCD_DISP_NULL);
	}

	page_list = lv_list_create(page_win, NULL);
	lv_obj_set_style_local_bg_color(page_list, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);

	lv_obj_set_size(page_list, lv_obj_get_width(page_win), lv_obj_get_height(page_win) - title_height - page_get_statusbar_height(LCD_DISP_NULL));
	lv_obj_set_user_data(page_win, (lv_obj_user_data_t)page_list);
	lv_obj_align(page_list, page_win, LV_ALIGN_IN_TOP_LEFT, 0, title_height + page_get_statusbar_height(LCD_DISP_NULL));

	for (i = 0; i < count; i++) 
	{
		btn = _menu_list_btn_add(page_list, listitem[i], i);
		if (i == 0 || i == index) 
		{
			lv_list_focus_btn(page_list, btn);
			lv_obj_set_style_local_text_color(btn, LV_LABEL_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_WHITE);
		}
	}

	if (task_list == NULL)
		task_list = lv_task_create(_menu_list_task_func, 1000, LV_TASK_PRIO_MID, 0);

	return page_win;
}


