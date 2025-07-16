/**
 * @file mfsdk_log.h
 * @author CHAR
 * @brief 
 * @date 2023-11-17
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#ifndef __MFSDK_LOG_H__
#define __MFSDK_LOG_H__
#include "mfsdk_define.h"

//close log output
#define MFSDK_LOG_CLOSE_OUT (0)
//The logs will be output from the USB port
#define MFSDK_LOG_USB_OUT (1)
//The logs will be output from the wifi port
#define MFSDK_LOG_WIFI_OUT (2)

typedef enum
{
	MFSDK_LOG_LEVEL_TRACE = 0, //trace
	MFSDK_LOG_LEVEL_DEBUG, //debug 
	MFSDK_LOG_LEVEL_INFO, //info
	MFSDK_LOG_LEVEL_WARN, //warning
	MFSDK_LOG_LEVEL_ERROR,//error
	MFSDK_LOG_LEVEL_FATAL,
	MFSDK_LOG_LEVEL_FILE,
}MfSdkLogLevel_E;


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/**
 * @brief set the log output mode
 * 
 * @param[in] s32 val MFSDK_LOG_USB_OUT/MFSDK_LOG_WIFI_OUT
 * @return 
 */
LIB_EXPORT s32 MfSdkLogSoundSet(s32 val);
/**
 * @brief
 * module is "MFSDKLOG"
 * default level :MFSDK_LOG_LEVEL_TRACE
 * @param[in] const char *pTag
 * @param[in] const char *fmt
 * @param[in] ...
 */
LIB_EXPORT void MfSdkLog(const char *pTag,const char *fmt,...);
/**
 * @brief
 * 
 * @param[in] const char* module
 * @param[in] MfSdkLogLevel_E level
 * @param[in] const void* Buffer
 * @param[in] s32 nSize
 * @param[in] char* tip
 * @param[in] s32 breakline
 */
LIB_EXPORT void MfSdkLogTip(const char* module, MfSdkLogLevel_E level, const void* Buffer, s32 nSize, char* tip, s32 breakline);
/**
 * @brief
 * 
 * @param[in] const char* module
 * @param[in] MfSdkLogLevel_E level
 * @param[in] s8*Buffer
 * @param[in] s32 nSize
 */
LIB_EXPORT void MfSdkLogHexBuff(const char* module, MfSdkLogLevel_E level,s8*Buffer, s32 nSize);

/**
 * @brief
 * 
 * @param[in] const char* module
 * @param[in] MfSdkLogLevel_E level
 * @param[in] const char* fmt
 * @param[in] ...
 */
LIB_EXPORT void MfSdkLogLevel(const char* module, MfSdkLogLevel_E level, const char* fmt, ...);

/**
 * @brief default enable
 * 
 * @param[in] MFSDKBOOL enable MFSDK_TRUE: enable output of logs ,MFSDK_FALSE: disenable output of logs
 */
LIB_EXPORT void MfSdkLogOutputSwitch(MFSDKBOOL enable);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_LOG_H__ */

