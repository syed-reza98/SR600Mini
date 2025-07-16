#include "pub/pub.h"

#pragma once
#ifdef __cplusplus
extern "C"{
#endif
LIB_EXPORT int power_lock_suspend();	// 休眠前锁定
LIB_EXPORT void power_unlock_suspend(); // 休眠完成解锁

LIB_EXPORT int power_lock_app(char * sfun);		// 进入应用操作
LIB_EXPORT void power_unlock_app();		// 退出应用操作


LIB_EXPORT int  power_battery_votal();


LIB_EXPORT int power_play_battery_state();


LIB_EXPORT int  power_reset();

LIB_EXPORT int power_init();

LIB_EXPORT int power_led_red(int state);


LIB_EXPORT int power_led_green(int state);

LIB_EXPORT int power_led_set_flg(int flag);

//本次唤醒tick
LIB_EXPORT int power_resume_tick();


//线程默认不休眠模式
LIB_EXPORT int  power_task_init( int taskid );
//线程休眠
LIB_EXPORT int power_task_suspend(int taskid , int ms);

LIB_EXPORT int power_supertime_reset();
//休眠唤醒
typedef int (*_power_resume_proc)(int ret);
LIB_EXPORT int power_resume_proc(_power_resume_proc proc);

LIB_EXPORT void power_uart_atc_lock(int flag);
LIB_EXPORT void power_uart_wifi_lock(int flag);
LIB_EXPORT void power_uart_power_lock(int flag);
LIB_EXPORT int power_app_set_led(int state);
LIB_EXPORT int power_app_get_led();




LIB_EXPORT int power_resesocket_timeout();



/**
 *@brief: 重置tts 结束状态tick
 *@input:
 *@output:
 *@return:
 *@date:2023/07/13
**/
LIB_EXPORT int power_reset_tts_finish_timeout();


LIB_EXPORT  void power_wifi_rev_lock();

LIB_EXPORT  void power_wifi_rev_unlock();



/**
 *@brief: 设置网络数据休眠唤醒时间
 *@input:休眠的时间(单位秒)
 *@output:
 *@return:
 *@date:2023/06/05
**/
void set_gsm_power_time(int time_num);


#ifdef __cplusplus
}
#endif
