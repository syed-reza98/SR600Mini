#pragma once

#ifdef __cplusplus
extern "C"{
#endif
#include "pub/pub.h"
#include "lvgl/lvgl.h"
#include "pub/qrencode/QrEncode.h"

LIB_EXPORT void message_close_page(int ret);
LIB_EXPORT lv_obj_t* page_code(lv_obj_t* parent, Param_QR_INFO *pQr_info, char* title, char* tip, char* data, int maxwidth, int qr_offset, int zoom, int tip_offset, int left, int color, int font, int timeout);

#ifdef __cplusplus
}
#endif
