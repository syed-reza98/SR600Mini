#pragma once

#include "pub\osl\inc\osl_log.h"

#define LVGL_TRACE( ...)	osl_log( "lvgl", LOG_LEVEL_WARN , __VA_ARGS__ )
#define LVGL_TRACE_BUFF_TIP(a,b,c) 	osl_log_buff_tip("lvgl",LOG_LEVEL_TRACE,a,b , c ,1 );
#define LVGL_FILE_TRACE( ...)	osl_log( "lvgl", LOG_LEVEL_WARN , __VA_ARGS__ )




