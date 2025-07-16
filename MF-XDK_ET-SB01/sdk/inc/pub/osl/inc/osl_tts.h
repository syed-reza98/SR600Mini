#include "pub/pub.h"
#pragma once

LIB_EXPORT void osl_tts_init();
LIB_EXPORT void osl_tts_power_lock();
LIB_EXPORT void osl_tts_power_unlock();
LIB_EXPORT void osl_tts_batch_begin();
LIB_EXPORT void osl_tts_batch_end();
LIB_EXPORT int osl_tts_play(char * sndfile);
LIB_EXPORT void osl_tts_beep(int hz, int ms);
LIB_EXPORT void osl_tts_set_play_func(void * func);
//获取语录语音的播放状态
LIB_EXPORT int osl_tts_state();
LIB_EXPORT void osl_tts_clear();

LIB_EXPORT void  osl_play_gprs();
LIB_EXPORT void osl_play_wifi();

LIB_EXPORT void osl_PCM_OpenStream();
LIB_EXPORT void osl_PCM_CloseStream();
LIB_EXPORT void osl_tts_stop();


 LIB_EXPORT int osl_tts_paly_mp3_buff(char *pbuf,int size);

//用tts播报

LIB_EXPORT int  osl_tts_play2(char *msg);

/**
 * @brief 获取音量系数
 * @return 音量系数
*/
LIB_EXPORT int osl_get_volume_coefficient();
/**
 * @brief 设置音量大小
 * @return 
*/
LIB_EXPORT void osl_tts_set_volume(int volume);

/**
 * @brief 设置音量系数
 * @param val
 * @return 
*/
LIB_EXPORT void osl_set_volume_coefficient(int val);