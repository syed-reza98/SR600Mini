/**
 * @file page_input_psw.h
 * @author CHAR
 * @brief 
 * @date 2023-12-5
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __PAGE_INPUT_PSW_H__
#define __PAGE_INPUT_PSW_H__
#include "lvgl/lvgl.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

LIB_EXPORT lv_obj_t* page_input_show_psw(lv_obj_t* parent , void* pfunc, char * title, char* tag, char * buff, int minlen, int maxlen, int mode, int timeover);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __PAGE_INPUT_PSW_H__ */
