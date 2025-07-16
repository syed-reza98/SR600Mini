/**
 * @file mfsdk_sys.h
 * @author CHAR
 * @brief 
 * @date 2023-11-20
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_SYS_H__
#define __MFSDK_SYS_H__
#include <time.h>
#include "mfsdk_define.h"

#define MFSDK_SYS_DEVICE_MF960		CPU_EC8521			///<mf960
#define MFSDK_SYS_DEVICE_H9N		CPU_EC25			///<h9n
#define MFSDK_SYS_DEVICE_H9L		CPU_V133			///<h9l
#define MFSDK_SYS_DEVICE_H9PRO		CPU_X2600_H9Pro		///<h9pro
#define MFSDK_SYS_DEVICE_960B		CPU_X2600_MF960		///<960b

typedef enum
{
	MFSDK_SYS_RET_FAILED = -3, //failed
	MFSDK_SYS_RET_BOUNDS = -2, //Array out-of-bounds
	MFSDK_SYS_RET_PARM_ERROR = -1, //check param
	MFSDK_SYS_RET_OK = 0,
}MfSdkSysRet_E;

typedef enum 
{
	MFSDK_SYS_LCD_TYPE_GET_FILE	= -1,			///<get file
	MFSDK_SYS_LCD_TYPE_480_800 = 0,			///<mf960
	MFSDK_SYS_LCD_TYPE_320_240,				///<h9u/h9l/h9n
	MFSDK_SYS_LCD_TYPE_240_240 = 11,
	MFSDK_SYS_LCD_TYPE_320_480,
	MFSDK_SYS_LCD_TYPE_128_32,
}MfSdkSysLcdType_E;

typedef enum 
{
	MFSDK_SYS_POWER_SHUTDOWN,
	MFSDK_SYS_POWER_LOW,
	MFSDK_SYS_POWER_CHARGE,
	MFSDK_SYS_POWER_OUT,		
	MFSDK_SYS_NET_CONFIG_MODE,
	MFSDK_SYS_NET_GPRS_MODE,
	MFSDK_SYS_NET_WIFI_MODE,
	MFSDK_SYS_WIFI_AIRKISS_CONFIG,
	MFSDK_SYS_WIFI_AP_CONFIG,
	MFSDK_SYS_WIFI_CONFIG_SUCCESS,
	MFSDK_SYS_WIFI_CONFIG_FAIL,
	MFSDK_SYS_TMS_UPDATE_START,//Tms Update Start
	MFSDK_SYS_TMS_UPDATE_UNZIP,//Tms Update Unzip
	MFSDK_SYS_TMS_UPDATE_SUCC,//Tms Update Succ
	MFSDK_SYS_TMS_UPDATE_FAIL,//Tms Update Fail
	MFSDK_SYS_TMS_SIGN_SUCC,//Tms Sign Succ
	MFSDK_SYS_TMS_SIGN_FAIL,//Tms Sign Fail
	MFSDK_SYS_TMS_DOWN_FINISH_SUCC,//Tms Down Finish Succ
	MFSDK_SYS_TMS_DOWN_FINISH_FAIL,//Tms Down Finish Fail
	MFSDK_SYS_TMS_DOWN_FINISH_PAUSE,//Tms Down Finish Pause
	MFSDK_SYS_TMS_DOWN_FINISH_CONTINUE,//Tms Finish Continue
	MFSDK_SYS_TMS_DOWN_FINISH_STOP,//Tms FinishStop
	MFSDK_SYS_LOW_BATTERY_SHUTDOWN,//Low Battery Shutdown
	MFSDK_SYS_RTC_TIME_SET,//RTC SET TIME
	MFSDK_SYS_POWER_FULL,//Battery full
}MfSdkSysState_E;


typedef enum
{
	MFSDK_SYS_DEV_MODEL_UNKNOWN = -1,
	MFSDK_SYS_DEV_MODEL_M60A = 0,
	MFSDK_SYS_DEV_MODEL_M60B,
	MFSDK_SYS_DEV_MODEL_M90L,
	MFSDK_SYS_DEV_MODEL_M60C,
	MFSDK_SYS_DEV_MODEL_MP60,
	MFSDK_SYS_DEV_MODEL_70N,
	MFSDK_SYS_DEV_MODEL_70N2,
	MFSDK_SYS_DEV_MODEL_M90,
	MFSDK_SYS_DEV_MODEL_H9,
	MFSDK_SYS_DEV_MODEL_H9A,
	MFSDK_SYS_DEV_MODEL_H9L,
	MFSDK_SYS_DEV_MODEL_H9N,
	MFSDK_SYS_DEV_MODEL_H9U,
	MFSDK_SYS_DEV_MODEL_H9PRO,
	MFSDK_SYS_DEV_MODEL_ET389,
	MFSDK_SYS_DEV_MODEL_ET389PRO,
	MFSDK_SYS_DEV_MODEL_MF919,
	MFSDK_SYS_DEV_MODEL_MF960,
	MFSDK_SYS_DEV_MODEL_MF960B,
	MFSDK_SYS_DEV_MODEL_70N3,
    MFSDK_SYS_DEV_MODEL_SR600MINI,
	MFSDK_SYS_DEV_MODEL_MP70A30,
	MFSDK_SYS_DEV_MODEL_MP70N5,
	MFSDK_SYS_DEV_MODEL_MP70A20,
	MFSDK_SYS_DEV_MODEL_MP70MIS,
	MFSDK_SYS_DEV_MODEL_MP70A5,
	MFSDK_SYS_DEV_MODEL_H9PROA30,
	MFSDK_SYS_DEV_MODEL_MP70A6,
	MFSDK_SYS_DEV_MODEL_Z990,
	MFSDK_SYS_DEV_MODEL_YQ06G,
}MfSdkSysDevType_E;

typedef enum
{
	MFSDK_SYS_COMM_CMD_SLEEP = 0,
	MFSDK_SYS_COMM_CMD_RESUME,
}MfSdkSysCommCmd_T;


typedef enum
{
	MFSDK_SYS_CONSOLE_AP = 1, // Display all port
	MFSDK_SYS_CONSOLE_CDC = 2, //  Only display NMEA port
	MFSDK_SYS_CONSOLE_CDC_ACM = 3, //  acm ap cp port
}MfSdkSysConsole_E;

typedef struct
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}MfSdkSysTime_T;

typedef struct
{
	int capacity;
    int voltage_level;
	int status;
}MfSdkBatterAttr_T;

typedef struct{
	u32 total_size;	///< memory heap total size
	u32 avail_size;	///< available size. The actual allocatable size may be less than this
	u32 max_block_size; ///< maximum allocatable block size
}MfSdkSysHeap_T;


typedef TERMINALINFO MfSdkSysTermInfo_T;

/*
*/
typedef void* MfSdkSysThreadMutex;

/**
 * @brief
 * @param[in] int type Ref. MfSdkSysState_E
 * @param[in] void *data 
 * @return 
 */
typedef int (*MfSdkSysPlayCallback)( int type, void *data);
typedef void (*MfSdkSysAppStartCallback)(void);

/**
 * @brief freetype font init callback
 * @param[in] void  
 * @return 
 */
typedef void (*MfSdkFreeTypeInitCb)(void);

typedef void (*MfSdkSysCommonCallback)(MfSdkSysCommCmd_T cmd, u8* data, s32 length);

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief
 * 
 * @return Ref. MfSdkSysDevType_E
 */
LIB_EXPORT s32 MfSdkSysGetDevModel(void);
/**
 * @brief
 * 
 * @return device model name 
 */
LIB_EXPORT char* MfSdkSysGetDevModelName(void);
/**
 * @brief 
 * 
 * @param[in] s32 model Ref. MfSdkSysDevType_E
 * @return MFSDK_TRUE - yes
 * @return MFSDK_FALSE - no
 */
LIB_EXPORT MFSDKBOOL MfSdkSysDevIs(s32 model);

/**
 * @brief get hardware version
 * 
 * @return hard version
 */
LIB_EXPORT s32 MfSdkSysGetHardwareVer(void);
/**
 * @brief
 * 
 * @param[in] MfSdkTime_T *pTime 
 * @return Ref. MfSdkSysTime_T
 */
LIB_EXPORT s32 MfSdkSysGetTime(MfSdkSysTime_T *pTime);

/**
 * @brief
 * 
 * @return 1-lock 0-unlock
 */
LIB_EXPORT s32 MfSdkSysAppIsLock();
/**
 * @brief LCD get brightness
 *
 * @return  light (The range is between 10 and 255)
 */
LIB_EXPORT s32 MfSdkSysAuxlcdGetBrightness();
/**
 * @brief LCD set brightness
 *
 * @param[in] light The range is between 10 and 255
 */
LIB_EXPORT void MfSdkSysAuxlcdSetBrightness(s32 light);
/**
 * @brief Sub LCD get brightness
 *
 * @return  light (The range is between 10 and 255)
 */
LIB_EXPORT s32 MfSdkSysSubAuxlcdGetBrightness();
/**
 * @brief Sub LCD set brightness
 *
 * @param[in] light The range is between 10 and 255
 */
LIB_EXPORT void MfSdkSysSubAuxlcdSetBrightness(s32 light);

/**
 * @brief Charging state
 * 
 * @return MFSDK_SYS_RET_OK charging
 * @return other not charging
 */
LIB_EXPORT s32 MfSdkSysBatterCharge(void);
/**
 * @brief Battery state
 * 
 * @param[out] batterystatus battery status
 * 
 * @return 1 charging
 * @return 0 not charging
 * @return -1 fail
 */
LIB_EXPORT s32 MfSdkSysGetBatterStatus(MfSdkBatterAttr_T* batterystatus);

/**
 * @brief Buzzer
 *
 * @param[in] nMillisecond time
 */
LIB_EXPORT void MfSdkSysBuzzerSound(s32 nMillisecond);
/**
 * @brief Scan button, non blocking
 *
 * @return KEY_VALUE
 * @return 0 No key
 * @return -1 Fail
 */
LIB_EXPORT s32 MfSdkSysCheckKey(void);
/**
 * @brief Check for timeout
 *
 * @param[in] tick Starting time
 * @param[in] timeover Timeout period
 * @return  0, within the effective time
 * @return  1, timeout
 */
LIB_EXPORT s32 MfSdkSysCheckTick(s32 tick, s32 timeover);
/**
 * @brief Not implemented
 * 
 */
LIB_EXPORT void MfSdkSysClrKey(void);
/**
 * @brief The manufacturer sets the individual parameter settings and
 * 		  invokes the individual settings function of each manufacturer.
 * 
 */
LIB_EXPORT void MfSdkSysConfig(void);
/**
 * @brief Initialization of system and initialization of application layer
 *
 * @param[in] Argc Reusing main function parameter Argc
 * @param[in] Argv Reusing main function parameter Argv
 * @param[in] AppName Application name
 * @return  1, For the first time since the program was updated
 * @return	2, Program is not run for the first time
 * @return  Other, Failure
 * @details Not to be processed without access to ginseng
			Inside the function calls the private API of the manufacturer.
			The API returns to the first operation only when the program is newly installed,
			and the update is not the first operation.
 */
LIB_EXPORT s32 MfSdkSysCurlInit(s32 Argc, s8** Argv, s8* AppName);
/**
 * @brief Delay blocking
 *
 * @param[in] uiMs Delay time unit MS
 */
LIB_EXPORT void MfSdkSysDelay(u32 uiMs);
/**
 * @brief Energy-saving time
 * 
 * @param[in] s32 nTime  unit second
 * @return 
 */
LIB_EXPORT s32 MfSdkSysEnergySetTime(s32 nTime);
/**
 * @brief Get Energy-saving time
 * 
 * @return Energy-saving time(unit:second)
 */
LIB_EXPORT s32 MfSdkSysEnergyTime();
/**
 * @brief
 * Secure area size 8KB  
 * @param[in] u32 addr , 0 / 4*1024
 * @return MFSDK_SYS_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkSysEraseSecureArea(u32 addr);
/**
 * @brief Set the storage mode
 *
 * @param[in] mode Storage location,Reference enum FILELOCATION
 */
LIB_EXPORT void MfSdkSysFileSetPath(s32 mode);

/**
 * @brief Get power supply
 * 
 * @return 0-5 battery level 
 * @return -1 fail
 */
LIB_EXPORT s32 MfSdkSysGetBatterLevel(void);
/**
 * @brief Get SysTime
 *
 * @param[out] DateTime "YYYYMMDDHHMMSS" 14 bytes
 * @return  0, Success
 * @return	Other, Failure
 */
LIB_EXPORT s32 MfSdkSysGetDateTime(u8* DateTime);


/**
 * @brief Check whether 389 has a front display
 * 
 * @return 1:have front display;
 * @return 0:have no front display
 */
LIB_EXPORT s32 MfSdkSysGetIsLcd(void);
/**
 * @brief Get the screen LCD type
 * 
 * @return Ref. MfSdkSysLcdType_E
 */
LIB_EXPORT s32 MfSdkSysGetLcdType();
/**
 * @brief
 * 
 * @param[out] s8* psn
 */
LIB_EXPORT void MfSdkSysGetPsn(s8* psn);
/**
 * @brief Get terminal information
 * 
 * @param[out] MfSdkSysTermInfo_T* terminal Reference TERMINALINFO
 * @return MFSDK_SYS_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkSysGetTerminalInfo(MfSdkSysTermInfo_T* terminal);
/**
 * @brief
 * no safe please use API MfSdkSysGetTerminalSn
 * @param[out] s8* Sn sn
 * @return MFSDK_SYS_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkSysGetTermSn(s8* Sn);
/**
 * @brief Get terminal sn
 * 
 * @param[out] s8*pData 
 * @param[in] s32 length
 * @return 
 */
LIB_EXPORT const s8* MfSdkSysGetTerminalSn(s8*pData,s32 length);
/**
 * @brief Get the current time
 * 
 * @return Get time tick unit ms.
 */
LIB_EXPORT u32 MfSdkSysGetTick();
/**
 * @brief Calculate time difference
 * 
 * @param[in] s32 tick1, tick1 start tick
 * @return Time difference
 */
LIB_EXPORT s32 MfSdkSysGetTickDiff(s32 tick1);
/**
 * @brief get time stamp
 * 
 * @return time_t lt(time stamp)
 */
LIB_EXPORT time_t MfSdkSysGetTimeStamp();
/**
 * @brief
 * 
 * @return lvgl object  lv_obj_t
 */
LIB_EXPORT void* MfSdkSysGuiGroupGetObj();

/**
 * @brief http download file
 * 
 * @param[in] s32 sock_index socket used by the device Ref. MfSdkCommSocketIndex_E
 * @param[in] const s8* url Download link
 * @param[in] const s8* fullpathfilename Save path
 * @return  MFSDK_SYS_RET_OK success
 * @return  other fail
 */
LIB_EXPORT s32 MfSdkSysHttpDownload(s32 sock_index, const s8* url, const s8* fullpathfilename);
/**
 * @brief Http download message configuration
 * 
 * @param[in] s32 useAgent UseAgent Whether to use User-Agent for http download(0 - 1)
 */
LIB_EXPORT void MfSdkSysHttpDownloadUseAgent(s32 useAgent);
/**
 * @brief Initialization of system and initialization of application layer Nothing
 * 
 * @param[in] s32 Argc Reusing main function parameter Argc
 * @param[in] s8** Argv Reusing main function parameter Argv
 * @param[in] s8* AppName Application name
 * @return < 0 fail
 * @return 1 - for the first time since the program was updated.
 * @return 2 - Program is not run for the first time.
 * Remarks: Not to be processed without access.
 *			Inside the function calls the private API of the manufacturer.
 *		The API returns to the first operation only when the program is newly installed,
 *		and the update is not the first operation.
 */
LIB_EXPORT s32 MfSdkSysInit(s32 Argc, s8** Argv, s8* AppName);
/**
 * @brief Screen Calibration
 *
 */
LIB_EXPORT void MfSdkSysLcdCalibration();
/**
 * @brief logo init
 * 
 * @param[in] s8* logoPath Path of the logo.bin file
 * @return MFSDK_SYS_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkSysLogoInit(s8* logoPath);

/**
 * @brief master screen logo init
 * 
 * @param[in] s8* logoPath Path of the logo.bin file
 * @return MFSDK_SYS_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkSysMasterLogoInit(s8* logoPath);

/**
 * @brief
 * 
 * @param[in] s8* logoPath
 * @param[in] MFSDKBOOL bDelete Whether to delete logo file MFSDK_TRUE-yes, MFSDK_FALSE-no
 * @return MFSDK_SYS_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkSysLogoInitA(s8* logoPath,MFSDKBOOL bDelete);

/**
 * @brief
 * 
 * @return 0-wireless ,1- MODEM
 */
LIB_EXPORT s32 MfSdkSysModelType();
/**
 * @brief Set other network injection processes
 *Called before Sys_Start.Resolved the jiociot sim card network injection failure 
 * 
 */
LIB_EXPORT void MfSdkSysNetSetDatacallType();
/**
 * @brief print buff add
 *
 * @param[in] pbuff Print buff
 */
LIB_EXPORT void MfSdkSysPrintAdd(const s8* pbuff);
/**
 * @brief Read flash data
 * 
 * @param[out] s8* pdata read Data content
 * @param[in] s32 size  data size
 */
LIB_EXPORT void MfSdkSysReadFlashData(s8* pdata, s32 size);
/**
 * @brief
 * 
 * @param[in] u32 addr , Read data start offset 0-8191
 * @param[out] u8* pData 
 * @param[in] s32 iDataLength
 * @return < 0 ,fail
 * @return other read data length
 */
LIB_EXPORT s32 MfSdkSysReadSecureArea(u32 addr, u8* pData, s32 iDataLength);
/**
 * @brief Terminal reboot
 *
 * @return  MFSDK_SYS_RET_OK, Success
 * @return  -1, Failure
 */
LIB_EXPORT s32 MfSdkSysReboot(void);
/**
 * @brief ntag analog card config
 *
 * @param[in] cardinfo Pointer to memory card information
 * @param[in] infolen The length of card information
 * @param[in] cardblock A two-dimensional array pointer for storing card block data
 * @param[in] block_cap The number of blocks that the card can support
 * @return	MFSDK_SYS_RET_OK, Success
 * @return	Other, Failure
 */
LIB_EXPORT s32 MfSdkSysRfidEmulateConfig(u8* cardinfo, s32 infolen, u8(*cardblock)[4], u32 block_cap);
/**
 * @brief ntag deinitialization of analog cards
 *
 * @return	MFSDK_SYS_RET_OK, Success
 * @return	Other, Failure
 */
LIB_EXPORT s32 MfSdkSysRfidEmulateDeinit(void);
/**
 * @brief ntag analog card initialization
 *
 * @return	MFSDK_SYS_RET_OK, Success
 * @return	Other, Failure
 */
LIB_EXPORT s32 MfSdkSysRfidEmulateInit(void);
/**
 * @brief ntag analog card execution processing
 *
 * @return	Nothing
 */
LIB_EXPORT void MfSdkSysRfidEmulateProcess(void);
/**
 * @brief system running
 *
 * @return  MFSDK_SYS_RET_OK, Success
 * @return	Other, Failure
 */
LIB_EXPORT s32 MfSdkSysRun();

/**
 * @brief Set SysTime
 *
 * @param[in] DateTime "YYYYMMDDHHMMSS" 14 bytes
 * @return  USYS_PARAERROR = -2, Parameter Error
 * @return  USYS_FAIL =	-1, Failure
 * @return  USYS_SUCCES = 0, Success
 * @details Internal judgment of time format in API
 */
LIB_EXPORT s32 MfSdkSysSetDateTime(u8* DateTime);
/**
 * @brief Set device language, must set the right font priority
 *
 * @param[in] nLanguageType 0 - Chinese, 1 - English, 2 - Persian
 */
LIB_EXPORT void MfSdkSysSetLanguage(s32 nLanguageType);
/**
 * @brief Log set
 *
 */
LIB_EXPORT void MfSdkSysSetLogData(s8* buff, s32 len);
/**
 * @brief Set screen backlight mode
 *
 * @param[in] mode Backlight mode:
			  0 - turn off backlight,
			  1 - system automatically controls,
			  2 - backlight is always bright.
 * @return  0, Success
 * @return  Other, Failure
 * @details Mode=1 indicates that the backlight is automatically
			controlled by the system, with a default of 1.
 */
LIB_EXPORT s32 MfSdkSysSetScrBackLight(byte mode);

/**
 * @brief Terminal goes to sleep state
 *
 * @param[in] Time Entering dormancy time, unit milliseconds
 * @return  0, Success
 * @return  -1, Failure
 * @details This API is a delay feature
 */
LIB_EXPORT s32 MfSdkSysSleep(u32 Time);
/**
 * @brief
 * 
 * @param[in] const s8* app_ver Application version
 * @param[in] MfSdkSysAppStartCallback apprun ,Application task
 */
LIB_EXPORT void MfSdkSysStart(const s8* app_ver, MfSdkSysAppStartCallback apprun);
/**
 * @brief Open Task
 *
 * @param[in] pfunc Processing function of task  void (*pFunc)(void)
 */
LIB_EXPORT void MfSdkSysTaskAppSet(void* pfunc);
/**
 * @brief Create system task
 *
 * @param[in] pfun Processing function of task
 * @param[in] prio Task priority 0~4
 * @param[in] param task param
 * @param[in] task_size Stack size
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkSysTaskCreate(void (*pfun)(void* param), s32 prio, void* param, s32 task_size);

/**
 * @brief Check whether the timing time is up to
 *
 * @param[in] iHandle Timer
 * @return  >=0, Remaining time, unit milliseconds (0 indicates timed time),	Success
 * @return  Other,	Failure
 */
LIB_EXPORT s32 MfSdkSysTimerCheck(s32 iHandle);
/**
 * @brief Off Timer
 *
 * @param[in] iHandle Timer
 * @return  0, Success
 * @return  Other,	Failure
 */
LIB_EXPORT s32 MfSdkSysTimerClose(s32 iHandle);
/**
 * @brief Create a timer
 * 
 * @param[in] void* pfunc  callback (unsigned int ( *func)(void *))
 * @param[in] void* pParam  params
 * @param[in] u32 nPeriod period
 * @param[in] u32 nMode  mode 
 * @param[in] u32* pnErrorCode error code
 * @return  0 fail
 * @return > 0  timer handle
 */
LIB_EXPORT u32 MfSdkSysTimerCreate(void* pfunc, void* pParam, u32 nPeriod, u32 nMode, u32* pnErrorCode);
/**
 * @brief Enable timer
 * 
 * @param[in] u32 nTimerNo  timer handle
 * @return 0 success
 * @return other fail
 */
LIB_EXPORT u32 MfSdkSysTimerEnable(u32 nTimerNo);
/**
 * @brief Delete timer 
 * 
 * @param[in] u32 nTimerNo  timer handle
 * @return 0 success
 * @return other fail
 */
LIB_EXPORT u32 MfSdkSysTimerDelete(u32 nTimerNo);
/**
 * @brief Open timer and set timer time
 *
 * @param[in] TimerMs Timer time
 * @return  >= 0, Successfully return timer handle
 * @return	Other, Failure
 */
LIB_EXPORT u32 MfSdkSysTimerOpen(u32 TimerMs);
/**
 * @brief system tts callback eg. batter low, wifi mode etc.
 * 
 * @param[in] MfSdkSysPlayCallback playproc
 */
LIB_EXPORT void MfSdkSysTtsSystemSetFunc(MfSdkSysPlayCallback playproc);
/**
 * @brief Unzip packet
 * 
 * @param[in] s8* szFileName,Path of the compressed package
 * @param[in] s8* folder , Unzip to the specified folder
 * @param[in] s32 del MFSDK_TRUE:Delete the zip package after the decompression is complete; 
 *					  MFSDK_FALSE:The zip package is not deleted after the decompression is successful
 * @return  MFSDK_SYS_RET_OK  success
 * @return  MFSDK_SYS_RET_PARM_ERROR  fail
 * @return  MFSDK_SYS_RET_FAILED fail
 * MfSdkSysUnzipFileFunc("exdata\\images.zip","exdata",MFSDK_TRUE);
 */
LIB_EXPORT s32 MfSdkSysUnzipFileFunc(s8* szFileName, s8* folder, MFSDKBOOL del);
/**
 * @brief get system version and trace out to log tool
 * 
 */
LIB_EXPORT void MfSdkSysVersion();
/**
 * @brief
 * 
 * @param[in] s8* pdata, write data stream
 * @param[in] s32 size ,write data stream length
 */
LIB_EXPORT void MfSdkSysWriteFlashData(s8* pdata, s32 size);
/**
 * @brief
 * 
 * @param[in] u32 addr 0--8191
 * @param[in] u8* pData ,write data stream
 * @param[in] s32 iDataLength , write data stream length
 * @return MFSDK_SYS_RET_OK
 * @return MFSDK_SYS_RET_PARM_ERROR
 * @return MFSDK_SYS_RET_FAILED
 */
LIB_EXPORT s32 MfSdkSysWriteSecureArea(u32 addr, u8* pData, s32 iDataLength);
/**
 * @brief  TMS update(Unpack zip file and upgrade, then reboot)
 * @details By calling this API, the device unzips data/mf.zip.
 * 
 */
LIB_EXPORT void MfSdkSysZipUpdate();
/**
 * @brief Initialization driver
 * 
 */
LIB_EXPORT void MfSdkSysDriverLibInit();

/**
 * @brief if SoundBox support NFC should init
 * 
 * @return MFSDK_SYS_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkSysTaskAppInit(void);

/**
 * @brief Init Driver
 * 
 * @return MFSDK_SYS_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkSysPubDriverInit(void);
/**
 * @brief Init font library
 * 
 * @return MFSDK_SYS_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkSysFontInit(void);

/**
 * @brief
 * 
 * @param[in] MfSdkSysConsole_E switchE
 */
LIB_EXPORT void MfSdkSysConsoleSwitch(MfSdkSysConsole_E switchE);

/**
 * @brief
 * 
 * @param[out] MfSdkSysThreadMutex *mutex
 * @return ref. MfSdkSysRet_E
 * eg.
 * MfSdkSysThreadMutex metex = NULL;
 * MfSdkSysThreadMutexInit(&metex);
 */
LIB_EXPORT s32 MfSdkSysThreadMutexInit(MfSdkSysThreadMutex *mutex);

/**
 * @brief
 * 
 * @param[in] MfSdkSysThreadMutex *mutex
 * @param[in] void* param  fixed NULL
 * @return ref. MfSdkSysRet_E
 */
LIB_EXPORT s32 MfSdkSysThreadMutexLock(MfSdkSysThreadMutex *mutex ,void* param);
	
/**
 * @brief
 * 
 * @param[in] MfSdkSysThreadMutex *mutex
 * @return ref. MfSdkSysRet_E
 */
LIB_EXPORT s32 MfSdkSysThreadMutexUnlock(MfSdkSysThreadMutex *mutex);

/**
 * @brief
 * 
 * @param[in] MfSdkSysThreadMutex *mutex
 * @return ref. MfSdkSysRet_E
 */
LIB_EXPORT s32 MfSdkSysThreadMutexDestroy(MfSdkSysThreadMutex *mutex);

/**
 * @brief Get segment lcd max length of display  6/7/9
 * 
 * @return < 0 failed
 */
LIB_EXPORT s32 MfSdkSysGetSegmentLcdDisplayMaxLength(void);


/**
 * @brief Check whether there is an external flash.
 * 
 * @return MFSDK_FALSE - not external Flash
 * @return MFSDK_TRUE - external flash
 */
LIB_EXPORT MFSDKBOOL MfSdkSysIsExternalFlash(void);

/**
 * @brief Set the time for the device to enter the forced sleep mode after the screen is broken
 *
 * @return ref. MfSdkSysRet_E
 */
LIB_EXPORT s32 MfSdkSysSetForceSleepTime(s32 timeS);

/**
 * @brief Set the shutdown time after the device enters sleep mode
 *
 * @return ref. MfSdkSysRet_E
 */
LIB_EXPORT s32 MfSdkSysSetSleepToPoweroff(s32 timeS);

/**
 * @brief
 * 
 * @param[in] MfSdkSysHeap_T *pHeapInfor
 *
 */
LIB_EXPORT void MfSdkSysGetHeapInformation(MfSdkSysHeap_T *pHeapInfor);

/**
 * @brief not restart the app after it crashes, use crash=reenter
 * 
 * @return ref. MfSdkSysRet_E
 *
 */
LIB_EXPORT s32 MfSdkSysSetRestartEnabledOnce();
/**
 * @brief Only for SR600mini
 * Use a general callback and a general command code to handle the corresponding logic.
 * @param[in] MfSdkSysCommonCallback pfun
 * 
 */
LIB_EXPORT void MfSdkSysCommonCallbackInit(MfSdkSysCommonCallback pfun);
/**
 * @brief
 * 
 * @param[out] char *blename outof buffer
 * @param[in] s32 length  blename size
 * @return MFSDK_SYS_RET_PARM_ERROR params error
 * @return >= 0  BT name length
 */
LIB_EXPORT s32 MfSdkSysGetBtName(char *blename , s32 length);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif /* __MFSDK_SYS_H__ */

