#ifndef __FONT_MANAGE_H__
#define __FONT_MANAGE_H__

#include "lvgl/lvgl.h"

typedef enum 
{
	MSG_STRING_WELCOME = 0,
	MSG_STRING_AMOUNT = 1,
	MSG_STRING_QRCODE,
	MSG_STRING_MAX,
}MessageStingID;


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

lv_font_t* GetMultiFont();
uint8_t * AppFontAddr();
char* GetDispMessageMap(const char *str);
char* GetDispMessageFromCfg(MessageStingID index);
uint8_t * AppFontReadBin(int offset);
int MultiFontInit();

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __FONT_MANAGE_H__ */

