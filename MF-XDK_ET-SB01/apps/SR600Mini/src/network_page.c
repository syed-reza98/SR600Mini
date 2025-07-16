#include "network_page.h"
#include "page_main.h"
#include "lvgl/lvgl.h"
#include "page_pub.h"
#include "pages/pages.h"

static int start_time=0;
static lv_obj_t* networkwin = NULL;
static lv_obj_t* btn_gprs = NULL;
static lv_obj_t* btn_wifi = NULL;
static lv_obj_t* page_net_list = NULL;
static network_param_t network_param = { 0 };

static lv_task_t* task_list = NULL;
char* listnet[] = {"1.4G", "2.WIFI"};

static void list_net_close_page(int ret);

void tts_sleep()
{
	while (MfSdkAudTtsState() == 1)//Broadcasting
	{
		MfSdkSysSleep(500);
	}
	MfSdkSysSleep(1000);
}

static int page_show_return_func(int ret, lv_obj_t* obj)
{
	APP_TRACE("page_show_return_func\r\n");
	MfSdkPowerReset();	
	return 0;
}

/**
 * @brief check_network_task_func
 * @param task
 */
static void check_network_task_func(lv_task_t* task)
{
	
	int ret = -1;
	static bool is_wifi_start_config = false;

	if (MfSdkSysCheckTick(start_time, 60000*2) == 1)
	{
		if (network_param.currentKey == MF_LV_KEY_DOWN_SHORT_PRESS)
		PubMultiPlay((const s8 *)"cfail.mp3");
		tts_sleep();
		
		MfSdkPowerReset();
	}
	//Check the distribution network
	if (network_param.ischecking_network \
		|| (MfSdkCommGetNetSelect() == MFSDK_COMM_NET_ONLY_WIFI \
		&& is_wifi_start_config == false))
	{
		if (is_wifi_start_config == false)
		{
			network_param.ischecking_network = true;
			network_param.isgprs_network = false;
			MfSdkCommWifiStartConfig();
		}
		is_wifi_start_config = true;
		ret = MfSdkCommWifiCheckState();
		APP_TRACE("MfSdkCommWifiCheckState ret = %d\r\n", ret);
		if (ret == 1)
		{
			PubMultiPlay((const s8 *)"csuc.mp3");
			tts_sleep();
			//MfSdkPowerReset();			
			list_net_close_page(0);
			page_text_show_cb(get_subpage(), page_show_return_func,"N/W Config Updated", "Restarting device", 3000);
		}
		else if (ret == -1)
		{
			PubMultiPlay("cfail.mp3");
			tts_sleep();
			MfSdkPowerReset();
		}
	}
	//gprs mode
	if (network_param.isgprs_network)
	{
		is_wifi_start_config = false;
		MfSdkCommSet4gMode();
		PubMultiPlay((const s8 *)"gprs.mp3");
		network_param.ischecking_network = false;
		network_param.isgprs_network = false;
	}

}


static void list_net_close_page(int ret)
{

	if (networkwin != 0) {
		if (task_list)
		{
			lv_task_del(task_list);
			task_list = NULL;
		}
		if(btn_gprs)
		{
			lv_obj_del(btn_gprs);
			btn_gprs = NULL;
		}
		if(btn_wifi)
		{
			lv_obj_del(btn_wifi);
			btn_wifi = NULL;
		}
		if(page_net_list)
		{
			lv_obj_del(page_net_list);
			page_net_list = NULL;
		}

		lv_obj_del(networkwin);
		networkwin = 0;
		//if (m_page_close_page_func != 0) m_page_close_page_func(ret, list_body);
	}
}

static lv_obj_t* list_menu_net_add(lv_obj_t* list_page, char* text, bool isSel)
{
	static lv_style_t style;
	lv_obj_t* btn = lv_label_create(list_page, NULL);

	//page_show_text_font(btn, text, LCD_DISP_NULL);
	lv_select_disp(1);
	lv_obj_set_style_local_text_font(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_FONT_MF12);
	lv_label_set_text(btn, text);
	lv_label_set_long_mode(btn, LV_LABEL_LONG_CROP);
	lv_label_set_align(btn, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_size(btn, lv_obj_get_width(list_page), page_get_btn_height());
	if(isSel)
	{
		lv_style_reset(&style);
		lv_style_init(&style);
		lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
		lv_obj_add_style(btn, LV_LABEL_PART_MAIN, &style);
		lv_obj_set_style_local_radius(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
		lv_obj_set_style_local_bg_opa(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
	    lv_obj_set_style_local_bg_color(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);

		lv_obj_set_style_local_text_color(btn, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
		lv_obj_set_style_local_bg_color(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	}
	else
	{
		lv_style_reset(&style);		
		lv_style_init(&style);
		lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
		lv_obj_add_style(btn, LV_LABEL_PART_MAIN, &style);
		lv_obj_set_style_local_radius(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
		lv_obj_set_style_local_bg_opa(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
	    lv_obj_set_style_local_bg_color(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);

		lv_obj_set_style_local_text_color(btn, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
		lv_obj_set_style_local_bg_color(btn, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	}
	//lv_obj_set_event_cb(btn, _list_menu_cb);
	lv_obj_set_user_data(btn, (lv_obj_user_data_t)text);

	return btn;
}

static void list_menu_netlist_event_cb(struct _lv_obj_t* obj, lv_event_t event)
{
	int key = 0;
	
	if (!obj) return;

	if (event == LV_EVENT_KEY) 
	{
		MfSdkLcdBackLight(MFSDK_LCD_ON);
		key = network_page_get_key();

		if (key == MF_LV_KEY_UP_SHORT_PRESS || key == MF_LV_KEY_9_SHORT_PRESS || key == MF_LV_KEY_1_SHORT_PRESS)//up key
		{
			lv_obj_del(btn_gprs);
			lv_obj_del(btn_wifi);
			btn_gprs = list_menu_net_add(page_net_list, listnet[0], true);
			btn_wifi = list_menu_net_add(page_net_list, listnet[1], false);
			network_param.isgprs_network = true;
			network_param.ischecking_network = false;
			network_param.currentKey = MF_LV_KEY_UP_SHORT_PRESS;
			
		}
		else if (key == MF_LV_KEY_DOWN_SHORT_PRESS || key == MF_LV_KEY_7_SHORT_PRESS || key == MF_LV_KEY_2_SHORT_PRESS)//down key
		{
			lv_obj_del(btn_gprs);
			lv_obj_del(btn_wifi);
			btn_gprs = list_menu_net_add(page_net_list, listnet[0], false);
			btn_wifi = list_menu_net_add(page_net_list, listnet[1], true);
			network_param.currentKey = MF_LV_KEY_DOWN_SHORT_PRESS;

			PubMultiPlay((const s8 *)"wifi.mp3");
			
			//wifi configure network
			if (network_param.ischecking_network)
				return;
			network_param.ischecking_network = true;
			network_param.isgprs_network = false;
		}
		else if (key == MF_LV_KEY_QUIT_SHORT_PRESS || key == MF_LV_KEY_OK_SHORT_PRESS)
		{
			list_net_close_page(PAGE_RET_CONFIRM);
			MfSdkPowerReset();
		}
		/*else if (key == MF_LV_KEY_CANCEL_SHORT_PRESS)
		{
			list_net_close_page(PAGE_RET_CANCEL);
		}*/
		
	}
}

void network_page_win()
{
	int title_height = 0;

	page_select_disp(LCD_DISP_BEHIND);

	title_height = page_get_title_height(LCD_DISP_NULL);

	//m_page_close_page_func = (page_close_page_func)pfunc;

	if (networkwin != NULL)
	{
		lv_obj_clean(networkwin);
		lv_obj_del(networkwin);
	}
	lv_obj_t* parent = lv_scr_act();

	networkwin = page_create_win(parent, list_menu_netlist_event_cb);
	page_ShowTextOut(networkwin, "Net Configure", LV_ALIGN_IN_TOP_MID, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);
	page_net_list = page_list_create(networkwin, 0, title_height, 0, 0);

	lv_obj_set_size(page_net_list, lv_obj_get_width(networkwin), lv_obj_get_height(networkwin) - title_height);
	lv_obj_set_user_data(networkwin, (lv_obj_user_data_t)page_net_list);
	lv_obj_align(page_net_list, networkwin, LV_ALIGN_IN_TOP_LEFT, 0, title_height);


	if (MfSdkCommGetNetMode() == MFSDK_COMM_NET_ONLY_WIRELESS)
	{
		btn_gprs = list_menu_net_add(page_net_list, listnet[0], true);
		btn_wifi = list_menu_net_add(page_net_list, listnet[1], false);
	}
	else
	{
		btn_gprs = list_menu_net_add(page_net_list, listnet[0], false);
		btn_wifi = list_menu_net_add(page_net_list, listnet[1], true);
	}

	if (task_list == NULL)
	{
		start_time = MfSdkSysGetTick();
		task_list = lv_task_create(check_network_task_func, 500, LV_TASK_PRIO_MID, &network_param);	
	}

	return;
}

