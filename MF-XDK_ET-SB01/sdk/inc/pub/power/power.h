#include "pub/pub.h"

#pragma once
#ifdef __cplusplus
extern "C"{
#endif
LIB_EXPORT int power_lock_suspend();	// ����ǰ����
LIB_EXPORT void power_unlock_suspend(); // ������ɽ���

LIB_EXPORT int power_lock_app(char * sfun);		// ����Ӧ�ò���
LIB_EXPORT void power_unlock_app();		// �˳�Ӧ�ò���


LIB_EXPORT int  power_battery_votal();


LIB_EXPORT int power_play_battery_state();


LIB_EXPORT int  power_reset();

LIB_EXPORT int power_init();

LIB_EXPORT int power_led_red(int state);


LIB_EXPORT int power_led_green(int state);

LIB_EXPORT int power_led_set_flg(int flag);

//���λ���tick
LIB_EXPORT int power_resume_tick();


//�߳�Ĭ�ϲ�����ģʽ
LIB_EXPORT int  power_task_init( int taskid );
//�߳�����
LIB_EXPORT int power_task_suspend(int taskid , int ms);

LIB_EXPORT int power_supertime_reset();
//���߻���
typedef int (*_power_resume_proc)(int ret);
LIB_EXPORT int power_resume_proc(_power_resume_proc proc);

LIB_EXPORT void power_uart_atc_lock(int flag);
LIB_EXPORT void power_uart_wifi_lock(int flag);
LIB_EXPORT void power_uart_power_lock(int flag);
LIB_EXPORT int power_app_set_led(int state);
LIB_EXPORT int power_app_get_led();




LIB_EXPORT int power_resesocket_timeout();



/**
 *@brief: ����tts ����״̬tick
 *@input:
 *@output:
 *@return:
 *@date:2023/07/13
**/
LIB_EXPORT int power_reset_tts_finish_timeout();


LIB_EXPORT  void power_wifi_rev_lock();

LIB_EXPORT  void power_wifi_rev_unlock();



/**
 *@brief: ���������������߻���ʱ��
 *@input:���ߵ�ʱ��(��λ��)
 *@output:
 *@return:
 *@date:2023/06/05
**/
void set_gsm_power_time(int time_num);


#ifdef __cplusplus
}
#endif
