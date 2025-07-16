/******************************************************************************

  Copyright (C), 2015-2050, Fujian MoreFun Electronic Technology Co., Ltd.

 ******************************************************************************
  File Name     : mfsdk_power.h
  Version       : Initial Draft
  Author        : CHAR
  Created       : 2023/11/16
  Last Modified :
  Description   : mfsdk_power.c header file
  Function List :
  History       :
  1.Date        : 2023/11/16
    Author      : CHAR
    Modification: Created file

******************************************************************************/

/*----------------------------------------------*
 * external variables                           *
 *----------------------------------------------*/

/*----------------------------------------------*
 * external routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * internal routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * project-wide global variables                *
 *----------------------------------------------*/

/*----------------------------------------------*
 * module-wide global variables                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * constants                                    *
 *----------------------------------------------*/

/*----------------------------------------------*
 * macros                                       *
 *----------------------------------------------*/

/*----------------------------------------------*
 * routines' implementations                    *
 *----------------------------------------------*/

#ifndef __MFSDK_POWER_H__
#define __MFSDK_POWER_H__
#include "mfsdk_define.h"
#include "lvgl/lvgl.h"

typedef enum
{
	MFSDK_POWER_RET_UNSUPPORT = -4, // dont support 
	MFSDK_POWER_RET_FAILED = -3, //failed 
	MFSDK_POWER_RET_BOUNDS = -2, //Array out-of-bounds 
	MFSDK_POWER_RET_PARM_ERROR = -1, //check param
	MFSDK_POWER_RET_OK = 0, //success
}MfSdkPowerRet_E;
typedef enum{	
	MFSDK_POWER_POWER_MANAGER_REBOOT,
	MFSDK_POWER_POWER_MANAGER_SHUTDOWN,
	MFSDK_POWER_MANAGER_ENTER_PAGE = 4,
}MfSdkPowerManagerType_E;

typedef enum {
	MFSDK_POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN = 0,
	MFSDK_POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL,
	MFSDK_POWER_SUPPLY_CAPACITY_LEVEL_LOW,
	MFSDK_POWER_SUPPLY_CAPACITY_LEVEL_NORMAL,
	MFSDK_POWER_SUPPLY_CAPACITY_LEVEL_HIGH,
	MFSDK_POWER_SUPPLY_CAPACITY_LEVEL_FULL,
}MfSdkPowerCapacityLevel_E;

typedef enum
{
  MFSDK_POWER_LOW_BATTERY_REMID = 0,
  MFSDK_POWER_LOW_BATTERY_SHUTDOWN,
}
MfSdkPowerPageParm_E;

typedef enum
{
	MFSDK_POWER_ACONLINE_SLEEP_DN = 0, // Unable to sleep when connected to external power
	MFSDK_POWER_ACONLINE_SLEEP_EN = 1, //  Enable to sleep when connected to external power
}MfSdkPowerSleep_E;

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

typedef s32 (*MfSdkPowerResumeProcCb)(s32 ret);
typedef s32 (*MfSdkPowerManagerCb)(MfSdkPowerManagerType_E type);
typedef void(*MfSdkPowerPageCbFunc)(int);
/**
 * @brief set resume callback
 * 
 * @param[in] MfSdkPowerResumeProcCb pFuncCb
 * @return MFSDK_POWER_RET_OK success
 */
LIB_EXPORT s32 MfSdkPowerResumeProc(MfSdkPowerResumeProcCb pFuncCb);

/**
 * @brief set power manager callback
 * 
 * @param[in] cb power manager callback
 */
LIB_EXPORT void MfSdkPowerManagerSetFunc(MfSdkPowerManagerCb cb);
/**
 * @brief
 *
 * @param[in] char *sfun
 * @return MFSDK_POWER_RET_OK success
 */
LIB_EXPORT s32 MfSdkPowerLockApp(char *sfun);

/**
 * @brief
 * 
 */
LIB_EXPORT void MfSdkPowerUnlockApp(void);
/**
 * @brief 
 * The device can enter idle mode when there is no network connection.
 * @param[in] s32 taskid
 * @return MFSDK_POWER_RET_OK
 */
LIB_EXPORT s32 MfSdkPowerTaskInit(s32 taskid);
/**
 * @brief
 * 
 * @param[in] s32 taskid
 * @param[in] s32 ms Sleep is possible within xx ms
 * @return Ref. MfSdkPowerRet_E
 */
LIB_EXPORT s32 MfSdkPowerTaskSuspend(s32 taskid , s32 ms);

/**
 * @brief reset
 * 
 * @return MFSDK_POWER_RET_OK
 */
LIB_EXPORT s32 MfSdkPowerReset(void);

/**
 * @brief Set the low battery page
 * 
 * @param[in] void* fun
 * @return MFSDK_POWER_RET_OK success
 * @return MFSDK_POWER_RET_PARM_ERROR  fun==null
 */
LIB_EXPORT s32 MfSdkPowerPageCb(MfSdkPowerPageCbFunc fun);

/**
 * @brief
 * 
 * @param[in] void* state status bar obj
 * @param[in] lv_align_t align
 * @param[in] lv_coord_t x_ofs
 * @param[in] lv_coord_t y_ofs
 * @return 
 */
LIB_EXPORT s32 MfSdkPowerPageInit(void* state, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);

/**
 * @brief Set the sleep mode time
 *
 * @param[in] time_num Sleep mode time(unit: second)
 */
LIB_EXPORT void MfSdkPowerSetTime(s32 time_num);

/**
 * @brief poweroff
 * 
 */
LIB_EXPORT void MfSdkPowerOff(void);

/**
 * @brief
 * 
 */
LIB_EXPORT void  MfSdkPowerKeySetLight();

/**
 * @brief
 * 
 * @return MFSDK_POWER_RET_FAILED fail
 * @return 0-100
 * @return 101 CHARGING
 */
LIB_EXPORT s32 MfSdkPowerGetBatteryPercentage();

/**
 * @brief set turn off backlight time 
 * 
 * @param[in] s32 seconds ,default value 60s ,unit: second
 * @return MFSDK_POWER_RET_OK success
 * @return MFSDK_POWER_RET_UNSUPPORT not support
 */
LIB_EXPORT s32 MfSdkPowerSetBacklightTime(s32 seconds);

/**
 * @brief reset backlight time
 * 
 * @return MFSDK_POWER_RET_OK success
 * @return MFSDK_POWER_RET_UNSUPPORT not support
 */
LIB_EXPORT s32 MfSdkPowerSupertimeReset(void);

/**
 * @brief Reset the sleep timer
 * 
 * @return MFSDK_POWER_RET_OK  success
 * @return MFSDK_POWER_RET_UNSUPPORT not support
 */
LIB_EXPORT s32 MfSdkPowerSwitchResetTick(void);

/**
 * @brief
 * 
 * @param[in] MfSdkPowerSleep_E switchE
 * MFSDK_POWER_ACONLINE_SLEEP_EN:enable, MFSDK_POWER_ACONLINE_SLEEP_DN:disable
 */
LIB_EXPORT void MfSdkPowerSleepSwitch(MfSdkPowerSleep_E switchE);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_POWER_H__ */
