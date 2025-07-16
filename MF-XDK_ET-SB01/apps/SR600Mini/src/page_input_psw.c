#include "lvgl/lvgl.h"
#include "libapi_xpos/inc/mfsdk_ped.h"
#include "pages/pages.h"
//#include "lvgl/lvgl/src/lv_font/lv_font.h"
#include "pages/pages.h"
#include "card/func_pay.h"
#include "tracedef.h"

static lv_obj_t* page_win = NULL;
static lv_obj_t* white_bkg = NULL;
static lv_obj_t* lab_buff = NULL;
static lv_task_t* task_input = NULL;
static lv_task_t* task_timeover = NULL;
static lv_obj_t* input_body = NULL;
static lv_obj_t* time_count = NULL;

static char* m_buff = NULL;
//static int m_maxlen;
//static int m_minlen;
//static int m_showback;
static int m_mode = 0;
static int m_timeover = 0;
static int m_timeovr_reset = 0;
static int max_timeover = 0;
MfSdkPedPinModCfg_T cfg;

static page_close_page_func m_page_close_page_func = 0;
#define PIN_OFFSET	8


static const char* keybuff[11] = 
{
	"0 ","1QZqz","2ABCabc","3DEFdef","4GHIghi",
	"5JKLjkl","6MNOmno","7PRSprs","8TUVtuv","9WXYwxy",
	".,'?!\"-*@/\\:_;+&%#$=()<>"
};

static char _input_newchar(char oldchar)
{
	int i, j;
	int size;
	char ch = oldchar;
	for (i = 0; i < 11; i++) 
	{
		size = strlen(keybuff[i]);
		for (j = 0; j < size; j++) 
		{
			if (oldchar == keybuff[i][j]) 
			{
				j = (j + 1) % size;
				ch = keybuff[i][j];
				return ch;
			}
		}
	}
	return oldchar;
}

static void _input_close_page(int ret)
{
	if (NULL != task_input)
	{
		lv_task_del(task_input);
		task_input = 0;
	}
	if (NULL != task_timeover)
	{
		lv_task_del(task_timeover);
		task_timeover = 0;
	}
	if (white_bkg != 0) 
	{
		lv_obj_del(white_bkg);
		white_bkg = 0;
		if (m_page_close_page_func != 0) m_page_close_page_func(ret, input_body);
	}
	memset(&cfg, 0, sizeof(MfSdkPedPinModCfg_T));
}

static int getPinKeyLenth()
{
	int size = 0;
	
	if (0 != cfg.mode)
	{
		MfSdkPedGetPinModeStatus(&size);
		APP_TRACE("MfSdkPedGetPinModeStatus: %d\r\n", size);
	}
	else
	{
		size = strlen(m_buff);
	}

	return size;
}

static void _input_set_text()
{
    char buff[256] = { 0 };
    int size;

    if (m_mode == PAGE_INPUT_MODE_PWD) 
	{
		size = getPinKeyLenth();
		memset(buff, 0, sizeof(buff));
		if (size > 0) memset(buff, '*', size);
		
		page_show_text_font(lab_buff, buff, LCD_DISP_NULL);
		lv_obj_align(lab_buff, NULL, LV_ALIGN_CENTER, 0, PIN_OFFSET);
    }
	else
	{
		page_show_text_font(lab_buff, m_buff, LCD_DISP_NULL);
	}
    
}

static void _input_win_event_cb(lv_obj_t* obj, lv_event_t e)
{
	uint32_t key = -1;
	int size;
	char time_set[20] = { 0 };
	
	if (e == LV_EVENT_KEY) 
	{
		m_timeover = m_timeovr_reset;
		if (m_mode == PAGE_INPUT_MODE_PWD)
		{
			lv_task_reset(task_input);
			snprintf(time_set, sizeof(time_set), "(%02ds)", m_timeover / 1000);
			page_show_text_font(time_count, time_set, LCD_DISP_NULL);
		}
		key = page_pin_get_key(cfg.mode);
		size = getPinKeyLenth();

		APP_TRACE("m_buff = %s\r\n", m_buff);
		APP_TRACE("size = %d\r\n", size);
		APP_TRACE("key = %d\r\n", key);
		if (key >= MF_LV_KEY_1_SHORT_PRESS && key <= MF_LV_KEY_0_TRIPLE_PRESS)		
		{
			int keyValue = GetKeyValue(key);
			APP_TRACE("keyValue == %d\r\n", keyValue);
			if (size < cfg.max) 
			{
				sprintf(m_buff, "%s%c", m_buff, keyValue);
				_input_set_text();                
			}
		}
		else if (key == MF_LV_KEY_UP_SHORT_PRESS || key == MF_LV_KEY_BACKSPACE_SHORT_PRESS)
		{
			if (size < cfg.max) 
			{
				sprintf(m_buff, "%s%c", m_buff, '*');
				_input_set_text();
			}
		} 
		else if (key == MF_LV_KEY_CANCEL_SHORT_PRESS) 
		{
			if (size > 0) 
			{
				m_buff[size - 1] = 0;
				_input_set_text();
			}
			else
				_input_close_page(PAGE_RET_CANCEL);
		}
        else if (key == MF_LV_KEY_CANCEL_LONG_PRESS)
		{
            _input_close_page(PAGE_RET_CANCEL);
        }
		else if (key == MF_LV_KEY_OK_SHORT_PRESS)
		{
			if (size >= cfg.min || (0 == size && cfg.isBypass == 1))
			{
				_input_close_page(size);
			}
		}
    }
}

static void _input_task_func(lv_task_t* task)
{
	char time_set[20] = { 0 };
	if (m_timeover > 0) 
	{
		m_timeover -= 1000;
		if (m_mode == PAGE_INPUT_MODE_PWD || m_mode == PAGE_INPUT_MODE_AMOUNT)
		{
			snprintf(time_set, sizeof(time_set), "(%02ds)", m_timeover / 1000);
			page_show_text_font(time_count, time_set, LCD_DISP_NULL);
		}

		if (m_timeover <= 0) 
		{
			_input_close_page(PAGE_RET_TIMEOVR);
		}
	}
}
static void _timeover_task_func(lv_task_t* task)
{

	if (max_timeover > 0) 
	{
		max_timeover -= 1000;
		if (m_mode == PAGE_INPUT_MODE_PWD || m_mode == PAGE_INPUT_MODE_AMOUNT) 
		{
			if (max_timeover <= 0) 
			{
				APP_TRACE("[%s] _timeover_task_func end:%d\r\n", __FUNCTION__, max_timeover);
				_input_close_page(PAGE_RET_TIMEOVR);
			}
		}
	}
}

lv_obj_t* page_input_show_psw(lv_obj_t* parent , void* pfunc, char * title, char* tag, char * buff, int minlen, int maxlen, int mode, int timeover)
{
	char timeset[16] = { 0 };
	m_timeover = timeover;
	m_timeovr_reset = timeover;
	input_body = parent;
	m_buff = buff;
	//m_minlen = minlen;
	//m_maxlen = maxlen;
	//m_showback = show_back;
	m_mode = mode;
	m_page_close_page_func = (page_close_page_func)pfunc;

	memset(&cfg, 0, sizeof(MfSdkPedPinModCfg_T));
	cfg.mode = 0;
	cfg.min = minlen;
	cfg.max = maxlen;
	cfg.isBypass = ((TRANSTYPE_RF == get_card_pay_data()->mode)?0:1);
	cfg.flag = 1;
	cfg.fid = MFSDK_SEC_MKSK_FIELD;
	cfg.gid = 0;
	cfg.format = MFSDK_SEC_PIN_FORMAT0;
	if(0 != cfg.mode)
	{
		MfSdkPedSetPinModeCfg(cfg);//set secure mode
	}

	if (mode == PAGE_INPUT_MODE_PWD)
	{
		max_timeover = 90000;
	}
	else if (mode == PAGE_INPUT_MODE_AMOUNT)
	{
		max_timeover = 60000;
	}

	page_win = parent;

	white_bkg = page_create_win(parent, _input_win_event_cb);
	page_create_title(white_bkg, title);

	lv_obj_t* line = lv_obj_create(white_bkg, NULL);
	lv_obj_set_size(line, CELL_WIDTH - 30, 2);
	//lv_obj_set_style_local_bg_color(line, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x87CEFA));
	//lv_obj_set_style_local_border_color(line, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x87CEFA));
	lv_obj_align(line, white_bkg, LV_ALIGN_IN_TOP_MID, 0, 48);

	if(tag)
	{
		page_ShowTextOut(white_bkg, tag, LV_ALIGN_IN_TOP_MID, 0, 16, LV_COLOR_BLACK, LV_FONT_MF12);
	}

	lab_buff = page_ShowTextOut(white_bkg, "", LV_ALIGN_CENTER, 0, PIN_OFFSET, LV_COLOR_BLACK, LV_FONT_MF12);
	if (mode == PAGE_INPUT_MODE_PWD || m_mode == PAGE_INPUT_MODE_AMOUNT) 
	{		
		snprintf(timeset, sizeof(timeset), "(%02ds)", timeover / 1000);
		time_count = page_ShowTextOut(white_bkg, timeset, LV_ALIGN_IN_BOTTOM_MID, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);
	}
	
	_input_set_text();
	if(timeover>0)
		task_input = lv_task_create(_input_task_func, 1000, LV_TASK_PRIO_MID, 0);
	APP_TRACE("[%s] _timeover_task_func start:%d\r\n",__FUNCTION__, max_timeover);
	if (m_mode == PAGE_INPUT_MODE_PWD || m_mode == PAGE_INPUT_MODE_AMOUNT) 
	{
		if(max_timeover>0)
			task_timeover = lv_task_create(_timeover_task_func, 1000, LV_TASK_PRIO_HIGHEST, 0);
	}
	
    return page_win;
}

