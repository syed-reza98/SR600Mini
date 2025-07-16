/**
 * @file page_normal_list.h
 * @author CHAR
 * @brief 
 * @date 2023-12-2
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __PAGE_MENUL_LIST_H__
#define __PAGE_MENUL_LIST_H__

#include "lvgl/lvgl.h"
#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

LIB_EXPORT lv_obj_t* page_menu_list_show_ex(lv_obj_t* parent, void* pfunc, char* title, char* listitem[], int count, int index, int timeover, int show_back);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __PAGE_MENUL_LIST_H__ */
