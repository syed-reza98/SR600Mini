/**
 * @file mfsdk_lcd.h
 * @author CHAR
 * @brief 
 * @date 2023-11-20
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_LCD_H__
#define __MFSDK_LCD_H__
#include "mfsdk_define.h"
typedef enum
{
	MFSDK_LCD_OFF = 0, //turn off backlight
	MFSDK_LCD_AUTO = 1,// system automatically controls
	MFSDK_LCD_ON = 2, //backlight is always bright
	MFSDK_LCD_LIGHT_UP = 3, //Light up the screen,The MfSdkLcdSetBackLightTime setting time is retimed
}MfSdkLcdStatus_E;

typedef enum
{
	MFSDK_LCD_RET_FAILED = -3, //failed 
	MFSDK_LCD_RET_BOUNDS = -2, //Array out-of-bounds 
	MFSDK_LCD_RET_PARM_ERROR = -1, //check param
	MFSDK_LCD_RET_OK = 0, //success
}MfSdkLcdRet_E;

typedef enum
{
	MFSDK_LCD_BRT_LEVEL_MIN = 0,
	MFSDK_LCD_BRT_LEVEL_1,
	MFSDK_LCD_BRT_LEVEL_2,
	MFSDK_LCD_BRT_LEVEL_3,
	MFSDK_LCD_BRT_LEVEL_4,
	MFSDK_LCD_BRT_LEVEL_MAX,	
}MfSdkLcdBrighnesstLevel_E;

typedef enum
{
	MFSDK_LCD_ARROW_UP = 0, //up arrow
	MFSDK_LCD_ARROW_DOWN = 1, //down arrow
}MfSdkLcdArrow_E;

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief
 * 
 * @param[in] s32 status Ref. MfSdkLcdStatus_E MFSDK_LCD_OFF-OFF,MFSDK_LCD_ON-ON
 * @return Ref. MfSdkLcdRet_E
 */
LIB_EXPORT s32 MfSdkLcdBackLight(s32 status);
/**
 * @brief Segment code LCD
 * 
 * @param[in] s32 status Ref. MfSdkLcdStatus_E MFSDK_LCD_OFF-OFF,MFSDK_LCD_ON-ON
 * @return Ref. MfSdkLcdRet_E
 */
LIB_EXPORT s32 MfSdkLcdSegmentBackLight(s32 status);


/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT s32 MfSdkLcdGetSubProbe();
/**
 * @brief
 * 
 * @param[in] s32 index 
 */
LIB_EXPORT void MfSdkLcdSetIndex(s32 index);
/**
 * @brief Get the shutdown time
 *
 * @return  Shutdown time
 */
LIB_EXPORT s32 MfSdkLcdGetPowerDownTime();
/**
 * @brief Set the shutdown time
 *
 * @param[in] ntime Shutdown time unit: second
 */
LIB_EXPORT void MfSdkLcdSetPowerDownTime(s32 ntime);
/**
 * @brief Get Backlight time
 *
 * @return  Backlight time
 */
LIB_EXPORT s32 MfSdkLcdGetBackLightTime();
/**
 * @brief Set Backlight time
 * The LCD is always on set max value. 
 * @param[in] ntime Backlight time,max value 99999999  unit:second
 */
LIB_EXPORT void MfSdkLcdSetBackLightTime(s32 ntime);
/**
 * @brief Get Front Screen Backlight time (for MP70A6)
 *
 * @return  Backlight time
 */
LIB_EXPORT s32 MfSdkLcdGetFrontBackLightTime();
/**
 * @brief Set Front Screen Backlight time (for MP70A6)
 * The LCD is always on set max value. 
 * @param[in] ntime Backlight time,max value 99999999  unit:second
 */
LIB_EXPORT void MfSdkLcdSetFrontBackLightTime(s32 ntime);
/**
 * @brief Get Rear Screen Backlight time (for MP70A6)
 *
 * @return  Backlight time
 */
LIB_EXPORT s32 MfSdkLcdGetRearBackLightTime();
/**
 * @brief Set Rear Screen Backlight time (for MP70A6)
 * The LCD is always on set max value. 
 * @param[in] ntime Backlight time,max value 99999999  unit:second
 */
LIB_EXPORT void MfSdkLcdSetRearBackLightTime(s32 ntime);
/**
 * @brief Screen Brightness Level Settings
 * 
 * @param[in] MfSdkLcdBrighnesstLevel_E level  0~5
 * @return MFSDK_LCD_RET_OK success
 * @return MFSDK_LCD_RET_FAILED Not support
 * @return MFSDK_LCD_RET_PARM_ERROR level < 0 or level > 5
 */
LIB_EXPORT s32 MfSdkLcdBrightnessLevelSettings(MfSdkLcdBrighnesstLevel_E level);

/**
 * @brief Whether to auto Refresh the LCD
 * 
 * @param[in] MFSDKBOOL bValue	true-enble flush lcd,false-disable flush lcd
 * @return MFSDK_LCD_RET_OK success
 * @return MFSDK_LCD_RET_FAILED Not support
 */
LIB_EXPORT s32 MfSdkLcdAutoFlush(MFSDKBOOL bValue);

/**
 * @brief Return to normal display
 * 
 * @return MFSDK_LCD_RET_OK success
 * @return MFSDK_LCD_RET_FAILED Not support
 */
LIB_EXPORT s32 MfSdkLcdSetNormalDirection();

/**
 * @brief Status Bar Display Up/Down Arrow
 * only support SR600mini
 * @param[in] MfSdkLcdArrow_E index 0:up,1:down
 * @param[in] MFSDKBOOL enable  1:on,0:off
 * @return void
 */
LIB_EXPORT void MfSdkLcdArrowDisplay(MfSdkLcdArrow_E index, MFSDKBOOL enable);

/**
 * @brief Check the screen backlight status
 * @return 1 bright
 * @return 0 Not light
 */
LIB_EXPORT MFSDKBOOL MfSdkLcdBacklightIsBright();

/**
 * @brief Only for SR600mini contrl front LCD backlight
 * 
 * @param[in] MFSDKBOOL bValue, MFSDK_TRUE-always on , MFSDK_FALSE-default
 */
LIB_EXPORT void MfSdkLcdFrontBacklight(MFSDKBOOL bValue);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_LCD_H__ */
