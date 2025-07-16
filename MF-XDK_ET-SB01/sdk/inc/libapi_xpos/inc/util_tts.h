#pragma once
#include "libapi_pub.h"

void pub_tts_play_num(int num);
void pub_tts_play_unit(int index);
void pub_tts_play_pay(int index);
void pub_tts_play_amt(int amt);
void pub_tts_play_type(int num);

LIB_EXPORT void pub_tts_play_number(int num);

/**
 * @brief Broadcast battery level
*/
LIB_EXPORT void pub_tts_play_battery();

/**
 * @brief Get battery capacity
*/
LIB_EXPORT int get_battery_capacity();

/**
 * @brief Broadcast voice
*/
LIB_EXPORT int pub_tts_play(const char * sndfile);

/**
 * @brief Broadcast voice option
*/
LIB_EXPORT int pub_tts_playOpt(const char * folder, const char * sndfile);

/**
 * @brief Voice broadcast status
*/
LIB_EXPORT int tts_state();
