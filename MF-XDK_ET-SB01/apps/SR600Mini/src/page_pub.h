#pragma once
#include "lvgl/lvgl.h"
#include "pages/pages.h"
#include "pages/page_list.h"
#include "font/font_manage.h"
#include "libapi_xpos/inc/mfsdk_sys.h"
#include "libapi_xpos/inc/mfsdk_lcd.h"
#include "libapi_xpos/inc/mfsdk_aud.h"
#include "libapi_xpos/inc/mfsdk_comm.h"
#include "libapi_xpos/inc/mfsdk_power.h"
#define MAINPNG "P:exdata/main.png"
#define LOGOPNG "P:exdata/logo.png"
#define SUCCPNG "P:exdata/succ.png"
#define FAILPNG "P:exdata/fail.png"
#define SUCCESSPNG "P:exdata/success.png"
#define RFPNG "P:exdata/rf.png"
#define RFPNG2 "P:exdata/rf2.png"
#define RFPNG3 "P:exdata/rf3.png"
#define POSPNG "P:exdata/pos.png"
#define RFCARDPNG "P:exdata/rfcard.png"
#define RFIDLOGOPNG "P:exdata/rfidlog.png"
#define ICPNG "P:exdata/ic.png"
#define ICPNG2 "P:exdata/ic2.png"
#define ICPNG3 "P:exdata/ic3.png"
#define LOADPNG "P:exdata/load.png"
#define LOWPOWERPNG "P:exdata/lowpower.png"
#define SHUTDOWNRPNG "P:exdata/shutdown.png"
#define CARDPNG "P:exdata/card.png"

#define MAINPNG_320X480 "P:exdata/mainb.png"
#define LOGOPNG_320X480 "P:exdata/logob.png"
#define SUCCPNG_320X480 "P:exdata/succb.png"
//#define FAILPNG_320X480 "P:exdata/failb.png"
#define LOWPOWERPNG_320X480 "P:exdata/lowpoweb.png"
#define SHUTDOWNRPNG_320X480 "P:exdata/shutdowb.png"
#define CARDPNG_320X480 "P:exdata/cardb.png"
#define LCD_IS_320_480	(MFSDK_SYS_LCD_TYPE_320_480 == MfSdkSysGetLcdType())
#define LCD_IS_128_32	(MFSDK_SYS_LCD_TYPE_128_32 == MfSdkSysGetLcdType())
//#define LCD_IS_128_32	(1)

#define TTS_VOLUME_MIN			"volmin.mp3"		
#define TTS_VOLUME_MAX			"volmax.mp3"		
#define TTS_VOLUME_NOR			"volnor.mp3"
#define TTS_VOLUME_BEEP			"volbeep.mp3"
#define TTS_BUTTON_M	        "buttonM"		// 

// child thread lock of lvgl
#define LV_THREAD_LOCK(function) do{lv_start_lock(1); \
	function; \
	lv_start_lock(0);\
}while(0)

int network_page_get_key();
lv_obj_t* page_createwin_title(char *title, int type);
int page_get_key();
int page_pin_get_key(int option);
void PageNetMenuKeyProc(int key);
void page_group_create();
void page_group_set_obj(lv_obj_t* obj);
lv_obj_t*  page_ShowTextOut(lv_obj_t * parent, char *str, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs, lv_color_t color, lv_font_t* font);
lv_obj_t* page_text_show(lv_obj_t* parent, char* title, char* text, int timeout);
lv_obj_t* page_text_show_cb(lv_obj_t* parent, void* pfunc, char* title, char* text, int timeout);
lv_obj_t*  page_ShowText_Font(lv_obj_t * parent, char *str, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs, lv_color_t color, lv_font_t* font);
lv_obj_t*  page_ShowText_MultiFont(lv_obj_t * parent, MessageStingID index, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs, lv_color_t color, lv_font_t* font);

