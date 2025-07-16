/**
 * @file page_rfcard.h
 * @author CHAR
 * @brief 
 * @date 2023-12-2
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __PAGE_RFCARD_H__
#define __PAGE_RFCARD_H__
#include "lvgl/lvgl.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

LIB_EXPORT void free_readcard_page();
lv_obj_t* page_read_card_show(lv_obj_t* parent, char* title, char* text, int timeout);
LIB_EXPORT lv_obj_t* page_card_showamt(lv_obj_t* parent, void* pfunc, char* title, void* trackinfo, char* amtstr, int mode, int timeover, int show_back);
void card_close_subpage();
lv_obj_t* app_emv_get_page_win();
lv_obj_t* GetEmvPageWinTip(void);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __PAGE_RFCARD_H__ */
