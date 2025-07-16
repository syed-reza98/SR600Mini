#pragma once
#include "lvgl/lvgl.h"

#define UART_EN		(0)//1: open uart(disable log output) 0: close uart

void MainPage();
lv_obj_t* get_mainpage();
void play_start();
lv_obj_t* get_subpage();
void LedShowTimerClear();
void LedShowMessage(char *msg);
void set_amt_timer(int val);

