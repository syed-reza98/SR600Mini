#ifndef __LIBAPI_SYSTEM_MF_L_PLATFORM_HEADER__
#define __LIBAPI_SYSTEM_MF_L_PLATFORM_HEADER__

/**
 * @file libapi_system.h
 * @author caijh(Eric)
 * @brief System related functions
 * @date 2023-05-23
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#include "libapi_pub.h"
#include "lvgl/lvgl.h"
#include <time.h>

#define MD5_BLOCK_SIZE 1024

#define DEVICE_MF960	CPU_EC8521			///<mf960
#define DEVICE_H9U		CPU_EC600U			///<h9u
#define DEVICE_H9N		CPU_EC25			///<h9n
#define DEVICE_H9L		CPU_V133			///<h9l
#define DEVICE_H9PRO	CPU_X2600_H9Pro		///<h9pro
#define DEVICE_960B		CPU_X2600_MF960		///<960b
/**
 * @brief device type
 * 
 */
typedef enum {
	SDK_DEVICE_TYPE_70N = 20,			///<70n
	SDK_DEVICE_TYPE_H9N = 18,			///<h9n
	SDK_DEVICE_TYPE_H9L = 41,			///<h9l 
	SDK_DEVICE_TYPE_70N2 = 42,			///<70n2 
	SDK_DEVICE_TYPE_MF960 = 51,			///<mf960 
	SDK_DEVICE_TYPE_H9U = 53,			///<h9u
	SDK_DEVICE_TYPE_H9PRO = 61,			///<h9pro
	SDK_DEVICE_TYPE_960B = 65,			///<960b
}sdk_device_type;
typedef void (*api_app_start)();

#define  DEVICE_TYPE_MF67		13
#define  DEVICE_TYPE_MF68		199
#define  DEVICE_TYPE_MF69		14
#define  DEVICE_TYPE_MF66B		17
#define  DEVICE_TYPE_MF66S		29
#define  DEVICE_TYPE_MP70		10
#define  DEVICE_TYPE_H9			11
#define  DEVICE_TYPE_ET330		25
#define  DEVICE_TYPE_ET350		26
#define  DEVICE_TYPE_ET380		27
/**
 * @brief lcd type
 *
 */
typedef enum {
	SDK_LCD_TYPE_GET_FILE = -1,			///<get file
	SDK_LCD_TYPE_GET_FAIL = SDK_LCD_TYPE_GET_FILE,
	SDK_LCD_TYPE_480_800 = 0,			///<mf960
	SDK_LCD_TYPE_320_240,				///<h9u/h9l/h9n

	SDK_LCD_TYPE_240_240 = 11,
	SDK_LCD_TYPE_320_480,
}sdk_lcd_type;


/**
 * @brief Get version number of system class module
 *
 * @param[out] pszVer Module version number
 * @return  0, Success
 * @return	Other, Failure
 */
LIB_EXPORT int Sys_GetModuleVer(char *pszVer);

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
LIB_EXPORT int Sys_Init(int Argc,char **Argv,char *AppName);
LIB_EXPORT int Sys_Curl_Init(int Argc,char **Argv,char *AppName);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:The manufacturer sets the individual parameter settings and 
		invokes the individual settings function of each manufacturer.
Input : Nothing
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_Config(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get terminal information
Input : Nothing
Output : terminal  Reference TERMINALINFO
return: USYS_FAIL     = -1,  Fail
		USYS_SUCCES   = 0, Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetTerminalInfo(TERMINALINFO *terminal);
/**
 * @brief system running
 *
 * @return  0, Success
 * @return	Other, Failure
 */
LIB_EXPORT int Sys_Run();

/**
 * @brief Get SysTime
 *
 * @param[out] DateTime "YYYYMMDDHHMMSS" 14 bytes
 * @return  0, Success
 * @return	Other, Failure
 */
LIB_EXPORT int Sys_GetDateTime(byte *DateTime);

/**
 * @brief Set SysTime
 *
 * @param[in] DateTime "YYYYMMDDHHMMSS" 14 bytes
 * @return  USYS_PARAERROR = -2, Parameter Error
 * @return  USYS_FAIL =	-1, Failure
 * @return  USYS_SUCCES = 0, Success
 * @details Internal judgment of time format in API
 */
LIB_EXPORT int Sys_SetDateTime(byte *DateTime);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Scan button, non blocking
Input : Nothing
Output : Nothing
return: KEY_VALUE
		0 No key
		USYS_FAIL     = -1,  Fail
Remarks: Non enumKEY_VALUE defined keys return uniformly to 0
*************************************************************************************/
LIB_EXPORT int Sys_CheckKey(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Clear key buffer
Input : Nothing
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_ClrKey(void);
/**
 * @brief Open timer and set timer time
 *
 * @param[in] TimerMs Timer time
 * @return  >= 0, Successfully return timer handle 
 * @return	Other, Failure
 */
LIB_EXPORT unsigned int Sys_TimerOpen(uint TimerMs);

/**
 * @brief Check whether the timing time is up to
 *
 * @param[in] iHandle Timer
 * @return  >=0, Remaining time, unit milliseconds (0 indicates timed time),	Success
 * @return  Other,	Failure
 */
LIB_EXPORT int Sys_TimerCheck(int iHandle);

/**
 * @brief Off Timer
 *
 * @param[in] iHandle Timer
 * @return  0, Success
 * @return  Other,	Failure
 */
LIB_EXPORT int Sys_TimerClose(int iHandle);
LIB_EXPORT unsigned int Sys_GetTick();

/*****************************************************************************
* Procedure: Sys_GetTickDiff
* Function:	
** Parameters:    	Input: tick1 start tick 
* Result:	
* Descriptions:	Get time difference
** Created By:		CHAR20231115
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************/
LIB_EXPORT int Sys_GetTickDiff(unsigned int tick1);
/**
 * @brief Delay blocking
 *
 * @param[in] uiMs Delay time unit MS
 */
LIB_EXPORT void Sys_Delay(uint uiMs);

/**
 * @brief Real time of battery power
 *
 * @return  USYS_FAIL =	-1, Failure
 * @return  0-5 (5 indicates maximum), Success
 * @return  Other,	Failure
 */
LIB_EXPORT int Sys_GetBatter(void);

/**
 * @brief Charging state
 *
 * @return  0,	Charging with charger
 * @return  -1,	Not	Charging
 */
LIB_EXPORT int Sys_Batter_Charge(void);

/**
 * @brief Terminal goes to sleep state
 *
 * @param[in] Time Entering dormancy time, unit seconds
 * @return  0, Success
 * @return  -1, Failure
 * @details The application needs to detect the status of 
		    wireless network registration after wakeup
 */
LIB_EXPORT int Sys_Sleep(uint Time);

/**
 * @brief Terminal reboot
 *
 * @return  0, Success
 * @return  -1, Failure
 */
LIB_EXPORT int Sys_Reboot(void);

/**
 * @brief Check for timeout
 *
 * @param[in] tick Starting time
 * @param[in] timeover Timeout period
 * @return  0, within the effective time
 * @return  1, timeout
 */
LIB_EXPORT int Sys_CheckTick(int tick, int timeover);

/**
 * @brief Calculate time difference
 *
 * @param[in] tick Starting time
 * @return  >=0, Time difference
 * @return  Other, Failure
 */
LIB_EXPORT int Sys_DiffTick(int tick);

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
LIB_EXPORT int Sys_SetScrBackLight(byte mode);

/**
 * @brief Get terminal serial number
 *
 * @param[out] Sn Serial number
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int Sys_GetTermSn(char *Sn);

/**
 * @brief Open Scan
 *
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int Sys_scaner_open();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Start scanning
Input : Nothing
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_scaner_start();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:stop scanning
Input : pfun
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_scaner_stop();
/**
 * @brief Close Scan
 *
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int Sys_scaner_close();

/**
 * @brief Setting Application Version Number
 *
 * @param[in] pszVer Application Version Number
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int Sys_SetAppVer(char *pszVer);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Setting Application Version Number
Input : appvision Application Version Number
Output : Nothing 
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_setAppVision(char *appvision);
/**
 * @brief Initialization driver
 *
 */
LIB_EXPORT void Sys_driverlib_init();

/**
 * @brief Brighten the backlight by pressing the key
 *
 */
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Judging whether there is a secondary liquid crystal
Input : Nothing
Output : Nothing 
return: Return 1 has a secondary liquid crystal
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int  Sys_get_sublcd_probe();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Switching liquid crystal
Input : index=0 Main liquid crystal  ,index =1 Paraliquid crystal
Output : Nothing 
return: Return 1 has a secondary liquid crystal
Remarks: Nothing
*************************************************************************************/

LIB_EXPORT void Sys_lcd_set_index(int index);
LIB_EXPORT void  Sys_power_key_set_light();

/**
 * @brief Get the shutdown time
 *
 * @return  Shutdown time
 */
LIB_EXPORT  int Sys_lcd_PowerDownTime();

/**
 * @brief Set the shutdown time
 *
 * @param[in] ntime Shutdown time
 */
LIB_EXPORT  void Sys_lcd_SetPowerDownTime(int ntime);

/**
 * @brief Get Backlight time
 *
 * @return  Backlight time
 */
LIB_EXPORT  int Sys_lcd_BackLightTime();

/**
 * @brief Set Backlight time
 *
 * @param[in] ntime Backlight time
 */
LIB_EXPORT  void Sys_lcd_SetBackLightTime(int ntime);

/**
 * @brief Get Front Screen Backlight time (for MP70A6)
 *
 * @return  Backlight time
 */
LIB_EXPORT int Sys_lcd_GetFrontBackLightTime();

/**
 * @brief Set Front Screen Backlight time (for MP70A6)
 *
 * @param[in] ntime Backlight time
 */
LIB_EXPORT void Sys_lcd_SetFrontBackLightTime(int ntime);

/**
 * @brief Get Rear Screen Backlight time (for MP70A6)
 *
 * @return  Backlight time
 */
LIB_EXPORT int Sys_lcd_GetRearBackLightTime();

/**
 * @brief Set Rear Screen Backlight time (for MP70A6)
 *
 * @param[in] ntime Backlight time
 */
LIB_EXPORT void Sys_lcd_SetRearBackLightTime(int ntime);

/**
 * @brief Get app version
 *
 * @return  The app version
 */
LIB_EXPORT const char * Sys_GetAppVer();
#define SYS_DEVICE_TYPE_H9G		18
#define SYS_DEVICE_TYPE_M70G    20
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get Device Type
Input : 
Output :
return: Device Type H9 or MP70
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetDeviceType();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Get power supply
Input : 
Output :
return: Successful  0-5 (5 indicates maximum).
		USYS_FAIL           = -1,    Fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_get_power();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Get Key Sound
Input : 
Output :
return:  Key Sound value
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetKeySound();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Set Key Sound
Input : val :Key Sound value
Output :
return:  
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_SetKeySound(int val);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Get powerdown time
Input : 
Output :
return: powerdown time 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetPowerDownTime();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Set powerdown time
Input : val : powerdown time
Output :
return:  
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_SetPowerDownTime(int val);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Set backlight time
Input : 
Output :
return:   backlight time
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetBackLightTime();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Set backlight time
Input : val : backlight time
Output :
return:  
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_SetBackLightTime(int val);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Set tts volume
Input : val : tts volume
Output :
return:  
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_SetTtsVolume(int val);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Set tts volum for voice broadcasting currently
Input : val : tts volume
Output :
return:
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_SetTtsVolume_Running(int val);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Get tts volume
Input : 
Output :
return:  tts volume
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetTtsVolume();



/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Set tts speed(0-4)
Input : val : tts speed
Output :
return:  
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_SetTtsSpeed(int val);




/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Write flash data
Input :		pdata: write Data content
			size: data size
Output :
return:  
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_WriteFlashData(char * pdata, int size);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions: Read flash data
Input :		size : data size 
Output :	pdata: read Data content
return:  
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_ReadFlashData(char * pdata, int size);

/**
 * @brief Create system task
 *
 * @param[in] pfun Processing function of task
 * @param[in] prio Task priority
 * @param[in] Stack of task
 * @param[in] Stack size
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int Sys_TaskCreate( void *pfun , int prio, char * stk, int task_size );

/**
 * @brief Get Device Type
 *
 * @return  reference enum sdk_device_type
 */
LIB_EXPORT int Sys_GetDeviceType();

/**
 * @brief Set TMS state
 *
 * @param[in] nBusyState 1 - app busy, not deal TMS; 0 - app not busy, can deal TMS
 */
LIB_EXPORT void Sys_tms_AppBusy(int nBusyState);

/**
 * @brief Set TMS state
 *
 */
LIB_EXPORT void Sys_tms_update();

/**
 * @brief Whether to enable the TMS service,unsupport
 * 
 * @param[in] int enable   1-enable, 0 -disable
 */
LIB_EXPORT void Sys_tms_Enable(int enable);



LIB_EXPORT void Sys_set_log_data(char * buff , int len);
LIB_EXPORT void Sys_init();
LIB_EXPORT void Sys_magtek_open();
LIB_EXPORT void Sys_magtek_close();
LIB_EXPORT int Sys_Enercy_Time();
LIB_EXPORT int Sys_Enercy_SetTime( int nTime );
/**
 * @brief Unpack zip file and upgrade, then reboot
 *
 */
LIB_EXPORT void Sys_zip_update();

/**
 * @brief Set device language, must set the right font priority
 *
 * @param[in] nLanguageType 0 - Chinese, 1 - English, 2 - Persian
 */
LIB_EXPORT void Sys_set_language(int nLanguageType);
LIB_EXPORT unsigned int Sys_TimerCreate(void *pfunc, void* pParam, unsigned int nPeriod, unsigned int nMode, unsigned int *pnErrorCode);
LIB_EXPORT unsigned int Sys_TimerEnable (unsigned int nTimerNo);
LIB_EXPORT int Sys_model_type();
//LIB_EXPORT const char * Sys_getDeviceVision();
LIB_EXPORT void Sys_get_psn(char * psn);
/**
 * @brief Get the current time
 *
 * @return  Current time
 */
LIB_EXPORT unsigned int Sys_getTick();

/**
 * @brief power off
 *
 */
LIB_EXPORT void Sys_power_off();

#ifndef WIN32
void osl_log(const char* module, int level, const char* fmt, ...);
void osl_log_buff_tip(const char* module, int level, const void* Buffer, int nSize, char* tip, int breakline);
#endif // !WIN32

/**
 * @brief trace log
 *
 * @details eg:SYS_TRACE("%s %d","morefun",123);
 */
#define SYS_TRACE( ...)	osl_log((const char*)"app", 2 , __VA_ARGS__ )		///< output log string

 /**
  * @brief trace log(hex)
  *
  * @details eg:SYS_TRACE_BUFF(buf,16,"buf content");
  */
#define SYS_TRACE_BUFF(buff,size,tip) 	osl_log_buff_tip((const char*)"app",2,buff, size , tip ,1 );		///< output log buffer, hex mode
enum{
	X_Power_ShutDown,
	X_Power_Low,
	X_Power_Charge,
	X_Power_Out,		
	X_Net_Config_Mode,
	X_Net_Gprs_Mode,
	X_Net_Wifi_Mode,
	X_Wifi_AirKiss_Config,
	X_Wifi_AP_Config,
	X_Wifi_Config_Success,
	X_Wifi_Config_Fail,
	X_Tms_Update_Start,//Tms Update Start
	X_Tms_Update_Unzip,//Tms Update Unzip
	X_Tms_Update_Succ,//Tms Update Succ
	X_Tms_Update_Fail,//Tms Update Fail
	X_Tms_Sign_Succ,//Tms Sign Succ
	X_Tms_Sign_Fail,//Tms Sign Fail
	X_Tms_Down_Finish_Succ,//Tms Down Finish Succ
	X_Tms_Down_Finish_Fail,//Tms Down Finish Fail
	X_Tms_Down_Finish_Pause,//Tms Down Finish Pause
	X_Tms_Down_Finish_Continue,//Tms Finish Continue
	X_Tms_Down_Finish_Stop,//Tms FinishStop
	X_Low_Battery_Shutdown,//Low Battery Shutdown
	X_RTC_TIME_SET,//RTC SET TIME
};
typedef int (*api_tts_system_play)( int type, void *data);

LIB_EXPORT void Sys_ttsSystemSetFunc( api_tts_system_play playproc);


LIB_EXPORT void Sys_TtsPlay(const char *file);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:TMS upgrade
Input : file:Upgrade file name
		flag:1 upgrade application and data, 0 upgrade data only
		
Output : Nothing
return: 0,     success
		Other, failure	
*************************************************************************************/

LIB_EXPORT int Sys_tms_update_ex(const char *file, int flag);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Get file MD5
Input : pszFilePath:md5 file name
		pOutMD5:Returns the MD5 value of the file
		
Output : Nothing
return: 1,     success
		Other, failure	
*************************************************************************************/

LIB_EXPORT int Sys_md5_File( const char* pszFilePath,  unsigned char * pOutMD5);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lw
Functions:power off
Input : pszFilePath:
		
Output : Nothing
return: void	
*************************************************************************************/

LIB_EXPORT void Sys_power_off();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lw
Functions:log show version
Input : pszFilePath:
		
Output : Nothing
return: void	
*************************************************************************************/

LIB_EXPORT void Sys_Version();
/**
 * @brief Screen Calibration
 *
 */
LIB_EXPORT  void Sys_lcd_calibration();

/**
 * @brief LCD set brightness
 *
 * @param[in] light The range is between 10 and 255
 */
LIB_EXPORT  void Sys_auxlcd_set_brightness(int light);

/**
 * @brief LCD get brightness
 *
 * @return  light (The range is between 10 and 255)
 */
LIB_EXPORT  int Sys_auxlcd_get_brightness();

/**
 * @brief Sub LCD set brightness
 *
 * @param[in] light The range is between 5 and 255
 */
LIB_EXPORT  int Sys_sub_auxlcd_set_brightness(int light);

/**
 * @brief Sub LCD get brightness
 *
 * @return  light (The range is between 5 and 255)
 */
LIB_EXPORT  int Sys_sub_auxlcd_get_brightness();

/**
 * @brief Initialization of the display interface by long pressing the power key
 *
 */
LIB_EXPORT  void Sys_power_page_init();

/**
 * @brief Open Task
 *
 * @param[in] pfunc Processing function of task
 */
LIB_EXPORT void Sys_task_app_set(void* pfunc);

/**
 * @brief View boot version
 *
 * @return  Boot version
 */
LIB_EXPORT char* Sys_boot_ver();

/**
 * @brief View hal version
 *
 * @return  Hal version
 */
LIB_EXPORT char* Sys_hal_ver();

/**
 * @brief View kernel version
 *
 * @return  Kernel version
 */
LIB_EXPORT char* Sys_kernel_ver();

/**
 * @brief View device version
 *
 * @return  Device version
 */
LIB_EXPORT char* Sys_getDeviceVision();

/**
 * @brief Switch network switching mode
 *
 * @param[in] ret 0 - 4G, 1 - WIFI
 */
LIB_EXPORT void Sys_set_net_mode(int ret);

/**
 * @brief Read network mode
 *
 * @return  0 - 4G
 * @return  1 - WIFI
 */
LIB_EXPORT int Sys_get_net_mode();

/**
 * @brief Buzzer
 *
 * @param[in] nMillisecond time
 */
LIB_EXPORT void Sys_BuzzerSound(int nMillisecond);

/**
 * @brief Play audio
 *
 * @param[in] file Mp3 file name
 */
LIB_EXPORT void Sys_TtsPlay(const char* file);

/**
 * @brief print
 *
 * @param[in] pbuff Print buff
 */
LIB_EXPORT void Sys_print_add(const char* pbuff);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Initializing serial port
Input : Nothing

Output : Nothing
return: void
*************************************************************************************/

LIB_EXPORT void Sys_uart_init(void);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Receiving serial port data
Input : rbuf:Pointer to receive data
		rlen:Length of the received data
		timeout:Function timeout

Output : Nothing
return: Length of reception
*************************************************************************************/

LIB_EXPORT unsigned int Sys_uart_recv(char* rbuf, int rlen, int timeout);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Send serial port data
Input : sbuf:Pointer to which data is to be sent
		slen:Length of the data to be sent

Output : Nothing
return: Length of send
*************************************************************************************/

LIB_EXPORT unsigned int Sys_uart_send(char* sbuf, int slen);
/**
 * @brief Set the sleep mode time
 *
 * @param[in] time_num Sleep mode time(Unit: second)
 */
LIB_EXPORT void Sys_set_powertime(int time_num);

/**
 * @brief Set the storage mode
 *
 * @param[in] mode Storage location,Reference enum FILELOCATION
 */
LIB_EXPORT void Sys_file_set_path(int mode);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Set the time from sleep to wake up of the device
Input : time_num:Sleep mode time(Unit: second)

Output : Nothing
return: void
*************************************************************************************/
LIB_EXPORT void Sys_set_sleep_to_wake_time(int time_num);
/**
 * @brief ntag analog card initialization
 *
 * @return	0, Success
 * @return	Other, Failure
 */
LIB_EXPORT int Sys_rfid_emulate_init(void);

/**
 * @brief ntag analog card config
 *
 * @param[in] Pointer to memory card information
 * @param[in] The length of card information
 * @param[in] cardblock A two-dimensional array pointer for storing card block data
 * @param[in] block_cap The number of blocks that the card can support
 * @return	0, Success
 * @return	Other, Failure
 */
LIB_EXPORT int Sys_rfid_emulate_config(unsigned char* cardinfo, int infolen, unsigned char(*cardblock)[4], unsigned int block_cap);

/**
 * @brief ntag analog card execution processing
 *
 * @return	Nothing
 */
LIB_EXPORT void Sys_rfid_emulate_process(void);

/**
 * @brief ntag deinitialization of analog cards
 *
 * @return	0, Success
 * @return	Other, Failure
 */
LIB_EXPORT int Sys_rfid_emulate_deinit(void);

/**
 * @brief Gets the top-level lvgl obj
 *
 * @return  The top-level lvgl obj
 */
LIB_EXPORT lv_obj_t* Sys_gui_group_get_obj();

/**
 * @brief Disable check time from tms server
 *
 */
LIB_EXPORT void Sys_tms_CheckTime_disable();

/**
 * @brief Get the screen lcd type
 * 
 * @return reference enum sdk_lcd_type
 */
LIB_EXPORT int Sys_get_lcd_type();
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Check whether 389 has a front display
Input : Nothing

Output : Nothing
return: 1:have front display;0:Nothing
*************************************************************************************/
LIB_EXPORT int Sys_get_is_lcd(void);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:http download message configuration 
Input : useAgent Whether to use User-Agent for http download(0 - 1)
Output : Nothing
return: Nothing
eg: Sys_http_download_useAgent(1);
Sys_http_download(4,"https://sgb-mf.oss-ap-southeast-1.aliyuncs.com/apk/uploads/20230806/29690df2.bin", "exdata//mftest.bin")
*************************************************************************************/
LIB_EXPORT void Sys_http_download_useAgent(int useAgent);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:http download file
Input : sock_index  socket used by the device(0 - 4)
		url Download link
		fullpathfilename Save path
Output : Nothing
return: 0:success; Other:fail
eg: Sys_http_download(4,"https://sgb-mf.oss-ap-southeast-1.aliyuncs.com/apk/uploads/20230806/29690df2.bin", "exdata//mftest.bin")
*************************************************************************************/
LIB_EXPORT int Sys_http_download(int sock_index, const char* url, const char* fullpathfilename);
 
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions: Unzip packet
Input : szFileName  Path of the compressed package
		folder Unzip to the specified folder
		del 1:Delete the zip package after the decompression is complete; 0:The zip package is not deleted after the decompression is successful
Output : Nothing
return: 0:success; Other:fail
eg: Sys_Unzip_File_Func("exdata\\images.zip","exdata",1);
*************************************************************************************/
LIB_EXPORT int Sys_Unzip_File_Func(char* szFileName, char* folder, int del);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ware
Functions: logo init
Input : logoPath  Path of the logo.bin file
Output : Nothing
return: 0:success; Other:fail
eg: Sys_logo_init("exdata\\logo.bin");
*************************************************************************************/
LIB_EXPORT int Sys_logo_init(char *logoPath);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ware
Functions: get time stamp
Input : Nothing
Output : Nothing
return: time_t lt(time stamp)
*************************************************************************************/
LIB_EXPORT time_t Sys_getTimeStamp();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions: Set other network injection processes
Input : Nothing
Output : Nothing
return: Nothing
details: Called before Sys_Start.Resolved the jiociot sim card network injection failure
*************************************************************************************/
LIB_EXPORT void Sys_net_set_datacall_type();
/*****************************************************************************
* Procedure: Sys_EraseSecureArea
* Function:
* Parameters:           unsigned int addr  0 / 4*1024
* Result:
* Descriptions:	Secure area size 8KB
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Sys_EraseSecureArea(unsigned int addr);

/*****************************************************************************
* Procedure: Sys_WriteSecureArea
* Function:
* Parameters:           unsigned int addr  0--8191
                               unsigned char *pData
                               int iDataLength
* Result:	Ref. enum FileRet,success: UFILE_SUCCESS,fail: UFILE_FAIL
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Sys_WriteSecureArea(unsigned int addr, unsigned char *pData, int iDataLength);

/*****************************************************************************
* Procedure: Sys_ReadSecureArea
* Function:
* Parameters:           unsigned int addr  0--8191
                               unsigned char *pData
                               int iDataLength
* Result:
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/

LIB_EXPORT int Sys_ReadSecureArea(unsigned int addr, unsigned char *pData, int iDataLength);


/**
 * @brief Get the screen lcd type
 * 
 * @return reference enum sdk_lcd_type
 */
LIB_EXPORT int Sys_get_lcd_type();

LIB_EXPORT int Sys_tms_update_ex(const char *file, int flag);

LIB_EXPORT int Sys_TmsHeart(void);
LIB_EXPORT void Sys_TmsSetProgressCallback(void* pFunCallback);

LIB_EXPORT int Sys_GetKeySound(void);
LIB_EXPORT void Sys_SetKeySound(int val);
typedef  unsigned int (*TIMER_FUNCTION)(void*);

LIB_EXPORT unsigned int Sys_TimerTask_Create(TIMER_FUNCTION pWorkFunction, unsigned int nPeriod);
LIB_EXPORT unsigned int Sys_TimerTask_Reset(unsigned int nTimerNo);
LIB_EXPORT unsigned int Sys_TimerTask_Enable(unsigned int nTimerNo);
LIB_EXPORT unsigned int Sys_TimerTask_Delete(unsigned int nTimerNo);
LIB_EXPORT unsigned int Sys_TimerTask_Disable(unsigned int nTimerNo);
LIB_EXPORT void Sys_KeySetParam(int key, int short_press_time, int long_press_time, int short_press_delay);
/**
 * @brief Segment code  screen
 * 
 * @param[in] s32 status
 * @return 
 */
LIB_EXPORT int Sys_SegmentBackLight(int status);
LIB_EXPORT time_t Sys_getTimeStamp();
/**
 * @brief Get battery capacity percentage
 *
 * @return  0-100,  Success
 * @return  Other,	Failure
 */
LIB_EXPORT int Sys_GetBatter_Capacity(void);

/**
 * @brief Get tick diff
 *
 * @param[in] tick1 timestamp from Sys_getTick
 * @return  The diff tick from tick1
 */
LIB_EXPORT int Sys_GetTickDiff(unsigned int tick1);

/**
 * @brief Check timeover from tick1
 *
 * @param[in] tick1 timestamp from Sys_getTick
 * @param[in] timeover time of ms
 * @return  0, timeover
 * @return	Other, not timeover
 */
LIB_EXPORT int Sys_CheckTimeover(unsigned int tick1, unsigned int timeover);
/**
 * @brief Setting the device sleep mode
 *
 * @param[in] mod 0,Disable the device sleep mode;1,Enable the device sleep mode
 * @details only for H9G, H9L, H9N
 */
LIB_EXPORT void Sys_SetPowerSuspend(int mod);
/**
* @brief Get the buffer that scaned
*
* @return  >0, the lenghth of buffer
* @return  Other, Failure
*/
LIB_EXPORT int Sys_scaner_get_buff(char* buff);
#endif /*__LIBAPI_SYSTEM_MF_L_PLATFORM_HEADER__*/
