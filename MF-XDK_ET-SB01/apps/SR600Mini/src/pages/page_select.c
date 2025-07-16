#include "page_select.h"
#include "page_pub.h"
#include "pages/pages.h"

static lv_task_t* task_list = NULL;
static lv_obj_t* selectwin = NULL;
static lv_obj_t* page_select_list = NULL;
static lv_obj_t* btn1 = NULL;
static lv_obj_t* btn2 = NULL;

static char *key_string = NULL;
static int select_param = 0;
static int m_timeover = -1;

#define SWITCH_OFF	(0)
#define SWITCH_ON	(1)

static void list_select_close_page(int ret)
{
	m_timeover = 0;
	if(PAGE_RET_CONFIRM == ret)
	{
		set_setting_int(key_string, select_param);
	}
	
	if (task_list)
	{
		lv_task_del(task_list);
		task_list = NULL;
	}
	
	if (selectwin != 0) 
	{
		if(btn1)
		{
			lv_obj_del(btn1);
			btn1 = NULL;
		}
		if(btn2)
		{
			lv_obj_del(btn2);
			btn2 = NULL;
		}
		if(page_select_list)
		{
			lv_obj_del(page_select_list);
			page_select_list = NULL;
		}

		lv_obj_del(selectwin);
		selectwin = 0;
		//if (m_page_close_page_func != 0) m_page_close_page_func(ret, list_body);
	}
}

static void select_check_task_func(lv_task_t* task)
{
	if (m_timeover > 0)
	{
		APP_TRACE("select_check_task_func:%d\r\n", m_timeover);
		m_timeover -= 1000;
		if (m_timeover <= 0) 
		{
			list_select_close_page(PAGE_RET_TIMEOVR);
		}
	}
}

static void list_disp_focus(lv_obj_t* btn, int sel)
{
	lv_color_t text_color = LV_COLOR_BLACK;
	lv_color_t bg_color = LV_COLOR_WHITE;
	
	if(SWITCH_ON == sel)
	{
		text_color = LV_COLOR_WHITE;
		bg_color = LV_COLOR_BLACK;
	}
	lv_obj_set_style_local_text_color(btn, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, text_color);
    lv_obj_set_style_local_bg_color(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, bg_color);
}

static void list_select_event_cb(struct _lv_obj_t* obj, lv_event_t event)
{
	int key = 0;
	
	if (event == LV_EVENT_KEY) 
	{
		key = page_get_key();

		if (key == MF_LV_KEY_F2_SHORT_PRESS || key == MF_LV_KEY_9_SHORT_PRESS || key == MF_LV_KEY_1_SHORT_PRESS)//up key
		{
			select_param = SWITCH_OFF;
			list_disp_focus(btn1, SWITCH_ON);
			list_disp_focus(btn2, SWITCH_OFF);
		}
		else if (key == MF_LV_KEY_F1_SHORT_PRESS || key == MF_LV_KEY_7_SHORT_PRESS || key == MF_LV_KEY_2_SHORT_PRESS)//down key
		{
			select_param = SWITCH_ON;
			list_disp_focus(btn1, SWITCH_OFF);
			list_disp_focus(btn2, SWITCH_ON);
		}
		else if (key == MF_LV_KEY_OK_SHORT_PRESS)
		{
			list_select_close_page(PAGE_RET_CONFIRM);
		}		
		else if (key == MF_LV_KEY_CANCEL_SHORT_PRESS)
		{
			list_select_close_page(PAGE_RET_CANCEL);
		}		
	}
}

static lv_obj_t* list_select_item_add(lv_obj_t* list_page, char* text, bool isSel)
{	
	lv_obj_t* btn = lv_label_create(list_page, NULL);
	lv_obj_set_style_local_text_font(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_FONT_MF12);
	lv_label_set_text(btn, text);
	lv_label_set_long_mode(btn, LV_LABEL_LONG_CROP);
	lv_label_set_align(btn, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_size(btn, lv_obj_get_width(list_page), page_get_btn_height());
	
	lv_obj_set_style_local_radius(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_bg_opa(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
	list_disp_focus(btn, isSel);

	lv_obj_set_user_data(btn, (lv_obj_user_data_t)text);

	return btn;
}

//char* itemlist[] = {"1.Off", "2.On"};
void create_select_page(lv_obj_t* parent, char *title, char*key, char* item[], int count, int timeover)
{
	int title_height = page_get_title_height(LCD_DISP_NULL);

	if (selectwin != NULL)
	{
		lv_obj_clean(selectwin);
		lv_obj_del(selectwin);
	}

	key_string = key;
	select_param = get_setting_int(key);
	if(timeover > 0)
		m_timeover = timeover;
	//m_page_close_page_func = (page_close_page_func)pfunc;

	selectwin = page_create_win(parent, list_select_event_cb);
	
	lv_obj_t* page_list = page_list_create(selectwin, title, title_height, 0, 0);
	page_select_list = page_list;
	lv_obj_set_size(page_list, lv_obj_get_width(selectwin), lv_obj_get_height(selectwin) - title_height);
	lv_obj_set_user_data(selectwin, (lv_obj_user_data_t)page_list);
	lv_obj_align(page_list, selectwin, LV_ALIGN_IN_TOP_LEFT, 0, title_height);

	if (SWITCH_ON == select_param)
	{
		btn1 = list_select_item_add(page_list, item[0], SWITCH_OFF);
		btn2 = list_select_item_add(page_list, item[1], SWITCH_ON);
	}
	else
	{
		btn1 = list_select_item_add(page_list, item[0], SWITCH_ON);
		btn2 = list_select_item_add(page_list, item[1], SWITCH_OFF);
	}

	if (task_list == NULL)
	{
		task_list = lv_task_create(select_check_task_func, 1000, LV_TASK_PRIO_MID, 0);
	}

	return;
}

