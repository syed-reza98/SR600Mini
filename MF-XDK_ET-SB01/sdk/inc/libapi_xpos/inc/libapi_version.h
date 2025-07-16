#pragma once

#include "libapi_pub.h"

/**
 * @file libapi_version.h
 * @author chenyue(Ronaldo)
 * @brief get version functions
 * @date 2023-05-19
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

/**
 * @brief get libapi lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * libapi_version();

/**
 * @brief get data lib version
 *
 * @return version string
 */
LIB_EXPORT char* libapi_GetDataVision();

/**
 * @brief get apppub lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * apppub_version();

/**
 * @brief get apppub2 lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * apppub2_version();

/**
 * @brief get atc lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * atc_version();

/**
 * @brief get json lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * json_version();

/**
 * @brief get network lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * net_version();

/**
 * @brief get power lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * power_version();

/**
 * @brief get producttest lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * producttest_version();

/**
 * @brief get pub lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * pub_version();

/**
 * @brief get sqlite lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * sqlite_version();

/**
 * @brief get switchcheck lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * switchcheck_version();

/**
 * @brief get tms lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * tms_version();

/**
 * @brief get wifi lib version
 * 
 * @return version string 
 */
LIB_EXPORT const char * wifi_version();
LIB_EXPORT const char * xgui_version();
/**
 * @brief get mfos SDK version
 *
 * @return version string
 */
LIB_EXPORT char* libapi_MFOSVersion(); 