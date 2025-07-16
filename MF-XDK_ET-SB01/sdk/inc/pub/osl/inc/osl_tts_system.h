#pragma once

#include "pub/pub.h"

enum{
	Power_ShutDown,
	Power_Low,
	Power_Charge,
	Power_Out,		
	Net_Config_Mode,
	Net_Gprs_Mode,
	Net_Wifi_Mode,
	Wifi_AirKiss_Config,
	Wifi_AP_Config,
	Wifi_Config_Success,
	Wifi_Config_Fail,
	Tms_Update_Start,//Tms Update Start
	Tms_Update_Unzip,//Tms Update Unzip
	Tms_Update_Succ,//Tms Update Succ
	Tms_Update_Fail,//Tms Update Fail
	Tms_Sign_Succ,//Tms Sign Succ
	Tms_Sign_Fail,//Tms Sign Fail
	Tms_Down_Finish_Succ,//Tms Down Finish Succ
	Tms_Down_Finish_Fail,//Tms Down Finish Fail
	Tms_Down_Finish_Pause,//Tms Down Finish Pause
	Tms_Down_Finish_Continue,//tms Down Finish Continue
	Tms_Down_Finish_Stop,//tms Down Finish Stop
	Low_Battery_Shutdown,//Low Battery Shutdown
	RTC_TIME_SET,//RTC TIME SET

};

typedef int (*_tts_system_play)( int type, void *data);

LIB_EXPORT void osl_tts_system_set_func( _tts_system_play playproc);

LIB_EXPORT int osl_tts_system_play( int type, void *data);