#pragma once

#ifdef __cplusplus
extern "C"{
#endif
#include "pub/pub.h"
#include "lvgl/lvgl.h"

LIB_EXPORT void message_close_imagepage(int ret);
LIB_EXPORT lv_obj_t* page_image_show(lv_obj_t * parent, char *path, int timeout);

#ifdef __cplusplus
}
#endif