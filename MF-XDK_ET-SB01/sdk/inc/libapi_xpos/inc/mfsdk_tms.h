/******************************************************************************

  Copyright (C), 2015-2050, Fujian MoreFun Electronic Technology Co., Ltd.

 ******************************************************************************
  File Name     : mfsdk_tms.h
  Version       : Initial Draft
  Author        : CHAR
  Created       : 2023/11/16
  Last Modified :
  Description   : mfsdk_tms.c header file
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

#ifndef __MFSDK_TMS_H__
#define __MFSDK_TMS_H__
#include "mfsdk_define.h"
typedef enum
{
	MFSDK_TMS_RET_FAILED = -3, //failed 
	MFSDK_TMS_RET_BOUNDS = -2, //Array out-of-bounds 
	MFSDK_TMS_RET_PARM_ERROR = -1, //check param
	MFSDK_TMS_RET_OK = 0, //success
}MfSdkTmsRet_E;

typedef enum
{
	MFSDK_TMS_UPGRADE_DATA = 0, //0 upgrade data only
	MFSDK_TMS_UPGRADE_APP, //1 upgrade application	
}MfSdkTmsUpdateType_E;

typedef enum
{
	MFSDK_TMS_APP_NOT_BUSY = 0,
	MFSDK_TMS_APP_STATE_BUSY,
}MfSdkTmsAppState_E;

typedef enum
{
	MFSDK_TMS_OTA_LOCAL_FLASH = 0,   //download OTA package in Flash
	MFSDK_TMS_OTA_LOCAL_RAM,        //download OTA package in RAM
}MfSdkTmsOtaLocal_E;

typedef enum 
{
	MFSDK_TMS_ACTION_DOWNLOADING = 0,	//tms downloading
	MFSDK_TMS_ACTION_UPDATEING,	//Prepare to upgrade the downloaded program
	MFSDK_TMS_ACTION_CALLBACK,    //App add tms download progress callback
}MfSdkTmsAction_E;

enum {
	MFSDK_TMS_WAIT_TASK = 0,			// wait task
	MFSDK_TMS_WAIT_NETWORK_LINK,		// wait network link
	MFSDK_TMS_NETWORK_ANOMALY,		// network anomaly
	MFSDK_TMS_CONNETING,				// conneting
	MFSDK_TMS_CONNET_FAILED,			// connect failed
	MFSDK_TMS_REQUEST,				// request
	MFSDK_TMS_RECEIVING,				// receiving
	MFSDK_TMS_RECEIVED,				// received
	MFSDK_TMS_LOGON_FAILURE,			// logon faliure
	MFSDK_TMS_ILLEGAL_EQUIPMENT, 	// illegal equipment
	MFSDK_TMS_FAILURE_SEND,			// failure send
	MFSDK_TMS_FAILURE_RECV,			//failure recv
	MFSDK_TMS_DOWNLOAD,				// dowmload
	MFSDK_TMS_DOWNLOADING,			// downloading
	MFSDK_TMS_DOWNLOAD_LIMIT,		// download limit
	MFSDK_TMS_ERROR_FORMAT,			// error format
	MFSDK_TMS_MD5_ERROR_TRY,			// md5 error try
	MFSDK_TMS_DOWNLOAD_COMPLETED,	// download completed
	MFSDK_TMS_DOWNLOAD_CANCEL,		// download cancel
	MFSDK_TMS_VALIDATION_FAILURE,   //  validation failure  
	MFSDK_TMS_VERIFICATION_SIGNATURE,   //verification signature
	MFSDK_TMS_NONEED_TO_UPDATE,		// no need to update
	MFSDK_TMS_NEW_VERSION,			// new version
	MFSDK_TMS_UPDATING,				// updating
	MFSDK_TMS_WIFI_UPGRADE,			// wifi upgrade
	MFSDK_TMS_UPDATE_SUCCESS,		// update success
	MFSDK_TMS_UPDATE_FAILED,			// update failed
	MFSDK_TMS_REBOOTING,				// rebooting
}MfSdkTmsResult_E;




#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief
 * @param[in] int current value
 * @param[in] int total value
 */
typedef void (*MfSdkTmsProgressCb)(int, int);
/**
 * @brief
 * @param[in] int result type
 */
typedef void (*MfSdkTmsResultCb)(int);
/**
 * @brief
 * @param[in] int result type
 * @return 1 : continue
 */
typedef s32 (*MfSdkTmsActionCb)(MfSdkTmsAction_E type);
/**
 * @brief Set TMS progress callback function
 * 
 * @param[in] MfSdkTmsProgressCb *pFunCallback
 */
LIB_EXPORT void MfSdkTmsSetProgressCallback(MfSdkTmsProgressCb pFunCallback);
/**
 * @brief
 * tms result callback
 * @param[in] MfSdkTmsResultCb pFunCallback
 */
LIB_EXPORT void MfSdkTmsSetResultCallback(MfSdkTmsResultCb pFunCallback);

/**
 * @brief TMS heartBeat 
 * 
 * @return MFSDK_TMS_RET_OK 
 */
LIB_EXPORT s32 MfSdkTmsHeartBeat();

/**
 * @brief
 * 
 */
LIB_EXPORT void MfSdkTmsUpdate(void);
/**
 * @brief
 * 
 * @param[in] const s8* file
 * @param[in] s32 flag  
 * @return 
 */
LIB_EXPORT s32 MfSdkTmsUpdateFile(const s8* file, MfSdkTmsUpdateType_E flag);

/**
 * @brief  Set TMS state
 * 
 * @param[in] MfSdkTmsAppState_E nBusyState nBusyState:1 app busy, not deal TMS; 0 app not busy, can deal TMS
 */
LIB_EXPORT void MfSdkTmsAppBusy(MfSdkTmsAppState_E nBusyState);

/**
 * @brief Disable check time from tms server
 * 
 */
LIB_EXPORT void MfSdkTmsCheckTimeDisable();

/**
 * @brief Gets the current tms message
 * 
 * @return  tms msg string
 */
LIB_EXPORT s8 *MfSdkTmsGetMsg();

/**
 * @brief Get tms result information
 * 
 * @return  tms result string
 */
LIB_EXPORT s8 *MfSdkTmsGetResult();

/**
 * @brief Whether the tms upgrade verifies the signature
 *
 * @param flag 1:Enable , 0:Disable
 */
LIB_EXPORT void MfSdkTmsSetSig(s32 flag);

/**
 * @brief update OTA
 * 
 * @param[in] char *filename download file path and name eg. "exdata\\down.tmp"
 * @param[in] char *flag  fix string "ota.bin"
 * @return MFSDK_TMS_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkTmsUpdateOta(char *filename,char *flag);

/**
 * @brief Set TMS connect retry count
 * 
 */
LIB_EXPORT void MfSdkTmsSetConnectRetryCnt(u32 count);

/**
 * @brief Set TMS error retry count
 * 
 */
LIB_EXPORT void MfSdkTmsSetErrorRetryCnt(u32 count);

/**
 * @brief Whether to synchronize TMS time (enabled by default)
 * 
 * @param[in] MFSDKBOOL b  MFSDK_TRUE:enable ,MFSDK_FALSE:disable
 */
LIB_EXPORT void MfSdkTmsEnableSyncTime(MFSDKBOOL b);

/**
 * @brief Whether to enable the TMS service
 * 
 * @param[in] MFSDKBOOL b  MFSDK_TRUE-enable , MFSDK_FALSE-disable
 */
LIB_EXPORT void MfSdkTmsEnable(MFSDKBOOL b);
/**
 * @brief Set TMS action progress callback function
 *
 * @param[in] pFunCallback Callback
 * @return For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkTmsSetActionCallback(MfSdkTmsActionCb pFunCallback);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_TMS_H__ */
