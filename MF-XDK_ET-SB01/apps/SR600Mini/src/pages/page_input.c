#include "lvgl/lvgl.h"
#include <stdio.h>
#include "pages.h"
#include "page_pub.h"
#include "page_main.h"
#include "lvgl/lvgl/src/lv_font/lv_font.h"
#include "page_menu.h"


static lv_obj_t* page_win = NULL;
static lv_obj_t* lab_title = NULL;
static lv_obj_t* lab_tip = NULL;
static lv_obj_t* lab_buff = NULL;
static lv_task_t* task_input = NULL;
static lv_task_t* input_body = NULL;

static char* m_buff = NULL;
static int m_maxnum = 0;
static int m_minnum = 0;
static int m_mode = 0;
static int m_timeover = 0;
static int m_timeovr_reset = 0;
static int m_limit_lenth = 0;
static char* m_title;

static page_close_page_func m_page_close_page_func = 0;

static const char* keybuff[11] = {
	"0 ","1QZqz","2ABCabc","3DEFdef","4GHIghi",
	"5JKLjkl","6MNOmno","7PRSprs","8TUVtuv","9WXYwxy",
	".,'?!\"-*@/\\:_;+&%#$=()<>^"
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

static void amountFormat(char *amountStr, char*amountFormat)
{
	sprintf(amountFormat , "%0.2f", ATOLL(amountStr)/100.0);
}

int GetKeyStatus(int key)
{
	return (key-MF_LV_KEY_QUIT_SHORT_PRESS)%4;
}

int GetKeyValue(int key)
{
	int keyvalue = 0;
	if( key >= MF_LV_KEY_0_SHORT_PRESS && key <= MF_LV_KEY_0_TRIPLE_PRESS) 
		keyvalue = '0';
	else if( key >= MF_LV_KEY_1_SHORT_PRESS && key <= MF_LV_KEY_9_TRIPLE_PRESS)
		keyvalue = (key-MF_LV_KEY_1_SHORT_PRESS)/4+'1';
	return keyvalue;
}

static void _input_close_page(int ret)
{
	if (page_win != 0) 
	{
		if(lab_title != 0)
		{
			lv_obj_del(lab_title);
			lab_title = 0;
		}
		if(lab_tip != 0)
		{
			lv_obj_del(lab_tip);
			lab_tip = 0;
		}
		if(lab_buff != 0)
		{
			lv_obj_del(lab_buff);
			lab_buff = 0;
		}
		lv_obj_del(page_win);
		page_win = 0;
		m_buff = NULL;
		lv_task_del(task_input);
		if (m_page_close_page_func != 0) m_page_close_page_func(ret,input_body);
	}
	
}

static void _input_set_text()
{
    char buff[256] = { 0 };
    int size;

    if (m_mode == PAGE_INPUT_MODE_PWD) 
	{
		size = strlen(m_buff);
		if (size > 0) memset(buff, '*', size);
		m_buff[size] = 0;
		page_show_text_font(lab_buff, buff, 0);
    }
    else 
	{
		amountFormat(m_buff, buff);
        page_show_text_font(lab_buff, buff, 0);
		lv_obj_align(lab_buff, NULL, LV_ALIGN_IN_TOP_MID, 0, LINE_OFFSET_2);
    }
    
}

static void showAmountLed(char *amtstr)
{
	char amountDisp[16] = {0};
	if(NULL == amtstr) return;
	memset(amountDisp, 0, sizeof(amountDisp));
	sprintf(amountDisp , "%0.2f", ATOLL(amtstr)/100.0);
	APP_TRACE("amountDisp = %s\r\n", amountDisp);
	//MfSdkGuiLedAmount(amountDisp);
}

static void AmtStringRemoveHighZero(char* str, int lenth) 
{
    long long amt = atoi(str);
	memset(str, 0, lenth);
	sprintf(str, "%lld", amt);
}

static void _input_win_event_cb(lv_obj_t* obj, lv_event_t e)
{
	int i = 0;
	uint32_t key;
    int size;

    if (e == LV_EVENT_KEY) 
	{
		m_timeover = m_timeovr_reset;
        key = page_get_key(0);
        size = strlen(m_buff);

		APP_TRACE("m_buff = %s\r\n", m_buff);
		APP_TRACE("m_maxnum = %d\r\n", m_maxnum);
		APP_TRACE("size = %d\r\n", size);
		APP_TRACE("key = %x\r\n", key);
        if (key >= MF_LV_KEY_1_SHORT_PRESS && key <= MF_LV_KEY_0_TRIPLE_PRESS)
		{
			int keyValue = GetKeyValue(key);
			APP_TRACE("keyValue == %d\r\n", keyValue);
            if (0 == GetKeyStatus(key)) 
			{
				if(size < m_maxnum)
				{
	                sprintf(m_buff, "%s%c", m_buff, keyValue);
					AmtStringRemoveHighZero(m_buff, strlen(m_buff));
	                _input_set_text();
					showAmountLed(m_buff);
				}
				else
				{
					m_limit_lenth = 1;
				    page_show_text_font(lab_tip, "Exceed the limit", 0);
					PubMultiPlay((const s8*)"exdlimit.mp3");
				}
            }
        } 
		else if (key == MF_LV_KEY_CANCEL_SHORT_PRESS) 
		{
			if (size > 0) 
			{
				m_buff[size - 1] = 0;
				_input_set_text();
				showAmountLed(m_buff);

				if(1 == m_limit_lenth)
				{
					m_limit_lenth = 0;
				    page_show_text_font(lab_tip, "OK to continue", 0);
				}
			}
			else
	            _input_close_page(PAGE_RET_CANCEL);
		}
		else if (key == MF_LV_KEY_OK_SHORT_PRESS) 
		{
			if(size >= m_minnum && ATOLL(m_buff) > 0)
	            _input_close_page(PAGE_RET_CONFIRM);
		}
        else if (key == MF_LV_KEY_CANCEL_LONG_PRESS)
		{
			APP_TRACE("PAGE_RET_CANCEL\r\n");
            _input_close_page(PAGE_RET_CANCEL);
        }
    }
}

static void _input_task_func(lv_task_t* task)
{
	if (m_timeover > 0) 
	{
		m_timeover -= 1000;
		if (m_timeover <= 0) 
		{
			_input_close_page(PAGE_RET_TIMEOVR);
		}
	}
}
static void back_navigation_event_cb(lv_obj_t* btn, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) 
	{        		
		if(!btn) return ;
		APP_TRACE("back_navigation_event_cb obj:%p",btn);
		 _input_close_page(PAGE_RET_CANCEL);
    }
}
lv_obj_t* page_input_show_ex(lv_obj_t* parent , void* pfunc, char * title, char * buff, int minnum, int maxnum, int mode, int timeover,int show_back)
{
	char amtini[16]={0};
	m_timeover = timeover;
	m_timeovr_reset = timeover;
	input_body = parent;

    m_buff = buff;
    m_maxnum = maxnum;
	m_minnum = minnum;
    m_mode = mode;
    m_title = title;
    m_page_close_page_func = (page_close_page_func)pfunc;
	m_limit_lenth= 0;

	page_win = page_create_win(parent, _input_win_event_cb);
    lab_title = page_create_title(page_win, title);
	if(m_buff)
	{
		if(PAGE_INPUT_MODE_AMOUNT == mode)
			sprintf(amtini , "%0.2f", ATOLL(m_buff)/100.0);
		else
			strcat(amtini, m_buff);
		lab_buff = page_ShowTextOut(page_win, amtini, LV_ALIGN_IN_TOP_MID, 0, LINE_OFFSET_2, LV_COLOR_BLACK, LV_FONT_MF12);
	}
	lab_tip = page_ShowTextOut(page_win, "OK to continue", LV_ALIGN_IN_BOTTOM_MID, 0, 0, LV_COLOR_BLACK, LV_FONT_MF12);

	task_input = lv_task_create(_input_task_func, 1000, LV_TASK_PRIO_MID, 0);

    return page_win;
}

