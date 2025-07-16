/**
 * @file mfsdk_mem.h
 * @author CHAR
 * @brief 
 * @date 2023-11-18
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_MEM_H__
#define __MFSDK_MEM_H__
#include "mfsdk_define.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/**
 * @brief ref. standard free
 * 
 * @param[in] void *ptr
 */
LIB_EXPORT void MfSdkMemFree(void *ptr);
/**
 * @brief Ref. standard malloc
 * 
 * @param[in] s32 size
 * @return NULL failed
 * @return other success 
 */
LIB_EXPORT void *MfSdkMemMalloc(s32 size);


/**
 * @brief
 * 
 * @param[in] s32 nitems
 * @param[in] s32 size
 * @return NULL failed
 * @return other success
 */
LIB_EXPORT void *MfSdkMemCalloc(s32 nitems, s32 size);


/**
 * @brief ref. standard remalloc
 * 
 * @param[in] ptr ptr
 * @param[in] size size
 * @return NULL failed
 * @return other success 
 */
LIB_EXPORT void *MfSdkMemRealloc(void *ptr, s32 size);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_MEM_H__ */
