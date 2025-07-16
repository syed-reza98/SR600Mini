#pragma once
#include "lvgl/lvgl.h"
#include "../pages/pages.h"
#define TIMEOVER	60000
#define TIMEOVER_AUTO	500


#define LV_EVENT_PROCESS		(100)
enum 
{
	PAY_STEP_START = LV_EVENT_PROCESS,
	PAY_STEP_INPUT_AMOUNT,
	PAY_STEP_INPUT_CARD,
	PAY_STEP_READ_CARD,
	PAY_STEP_DISP_CARD,
	PAY_STEP_INPUT_PIN,
	PAY_STEP_EMV,
	PAY_STEP_PACK,
	PAY_STEP_UNPACK,
	PAY_STEP_COMM,
	PAY_STEP_MSG,
};

typedef struct __st_card_info {
	char title[32];
	char pan[32];
	char amt[32];
	char expdate[32];
}st_card_info;

typedef struct __st_pay_data
{
	int step;
	int mode;
	char *title;
	char amount[32];
	char pin[12];
	char cardnum[32];
	//char track2[128];
	//char track3[128];
	st_comm_data comm_data;
	char orderSn[256];
	char retmsg[256];
} st_pay_data;

st_pay_data * get_card_pay_data();
int getTransacationStatus();
void PayClosePage();
char *get_card_title();
void func_pay(lv_obj_t * parent, int mode);
s32 PayPagePowerLock(char *sfun);
void PayPagePowerUnlock(char *sfun);

