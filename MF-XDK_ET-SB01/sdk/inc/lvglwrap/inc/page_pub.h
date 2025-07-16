#pragma once
#ifdef __cplusplus
extern "C"{
#endif
#include "pub/pub.h"
#include "lvgl/lvgl.h"

enum {
	PAGE_RET_TIMEOVR = -2,
	PAGE_RET_CANCEL = -1,
	PAGE_RET_CONFIRM = 0,
};
LIB_EXPORT lv_obj_t*  lvShowTextOut(lv_obj_t * parent, char *str, lv_color_t color);

#ifdef __cplusplus
}
#endif
