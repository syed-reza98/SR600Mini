/**
 * @file mfsdk_kb.h
 * @author CHAR
 * @brief 
 * @date 2023-11-24
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_KB_H__
#define __MFSDK_KB_H__
#include "mfsdk_define.h"
typedef enum
{
	MFSDK_KB_RET_TIMEOUT = -4, //time over
	MFSDK_KB_RET_FAILED = -3, //failed 
	MFSDK_KB_RET_BOUNDS = -2, //Array out-of-bounds 
	MFSDK_KB_RET_PARM_ERROR = -1, //check param
	MFSDK_KB_RET_OK = 0,
}MfSdkKbRet_E;

typedef enum
{
	MFSDK_VK_INVALID = -1,
		
	MFSDK_VK_0 = 0x30,
	MFSDK_VK_1 = 0x31,
	MFSDK_VK_2 = 0x32,
	MFSDK_VK_3 = 0x33,
	MFSDK_VK_4 = 0x34,
	MFSDK_VK_5 = 0x35,
	MFSDK_VK_6 = 0x36,
	MFSDK_VK_7 = 0x37,
	MFSDK_VK_8 = 0x38,	
	MFSDK_VK_9 = 0x39,

	MFSDK_VK_CTL = 100,
	MFSDK_VK_UP ,
	MFSDK_VK_DOWN,
	MFSDK_VK_LEFT,
	MFSDK_VK_RIGHT,

	MFSDK_VK_F1,
	MFSDK_VK_F2,
	MFSDK_VK_BACKSPACE,
	MFSDK_VK_ESC,
	MFSDK_VK_ENTER,
	MFSDK_VK_XING, // star
	MFSDK_VK_JING, //Hash
}MfSdkKbKeyCode_E;
#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief
 * 
 * @param[in] int key
 * @param[in] int short_press_time
 * @param[in] int long_press_time
 * @param[in] int short_press_delay
 */
LIB_EXPORT void MfSdkKbKeySetParam(int key, int short_press_time, int long_press_time, int short_press_delay);
/**
 * @brief
 * 
 * @return 0-close
 * @return 1-open
 */
LIB_EXPORT s32 MfSdkKbGetKeySound();
/**
 * @brief
 * 
 * @param[in] nOpen 1 open; 0 close
 */
LIB_EXPORT void MfSdkKbSetKeySound(s32 val);

/**
 * @brief Waiting button, waits for the button within the set time, while the Nothing button waits for the timeout.
 *
 * @param[in] TimeOut Waiting timeout time (seconds), 0 means blocking
 * @return	>=0, key value
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkKbWaitKey(s32 TimeOut);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_KB_H__ */
