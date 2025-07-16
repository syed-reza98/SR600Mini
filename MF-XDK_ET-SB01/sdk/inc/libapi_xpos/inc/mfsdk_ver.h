/**
 * @file mfsdk_ver.h
 * @author Bone
 * @brief 
 * @date 2023-11-23
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#ifndef __MFSDK_VER_H__
#define __MFSDK_VER_H__
#include "mfsdk_define.h"

/**
 * @brief get data lib version
 *
 * @return version string
 */
LIB_EXPORT s8* MfSdkVerGetDataVersion();


/**
 * @brief get mf OS SDK version
 *
 * @return version string
 */
LIB_EXPORT s8* MfSdkVerMfOsVersion();

/**
 * @brief get app version
 * 
 * @return  app version string
 */
LIB_EXPORT const s8 *MfSdkVerGetAppVer();

/**
 * @brief get boot version
 * 
 * @return  boot version string
 */
LIB_EXPORT const s8 *MfSdkVerGetBootVer();

/**
 * @brief get driver version
 * 
 * @return  driver version string
 */
LIB_EXPORT const s8 *MfSdkVerGetDriverVer();

/**
 * @brief get system version
 * 
 * @return  system version string
 */
LIB_EXPORT const s8* MfSdkVerGetSysVer();

/**
 * @brief get sp version
 * 
 * @return  sp version string
 */
LIB_EXPORT const s8* MfSdkVerGetSpVer();

/**
 * @brief set app version.For tms upload application version
 * 
 * @param[in] pszVer app version string 
 * @return  0 success
 * @return  other fail
 */
LIB_EXPORT s32 MfSdkVerSetAppVersion(s8 *pszVer);

/**
 * @brief get pci hardware version
 * 
 * @return  hardware version
 */
LIB_EXPORT s8 *MfSdkVerGetSecHwVer();

/**
 * @brief get pci firmware version
 * 
 * @return  firmware version
 */
LIB_EXPORT s8 *MfSdkVerGetSecFwVer();

/**
 * @brief get pid 
 *
 * @return  firmware version
 */
LIB_EXPORT s8* MfSdkVerGetPidVer();

/**
 * @brief get mid
 *
 * @return  firmware version
 */
LIB_EXPORT s8* MfSdkVerGetMidVer();

#endif /* __MFSDK_VER_H__ */
