#ifndef __LIBAPI_SYSTEM_MF_R_PLATFORM_HEADER__
#define __LIBAPI_SYSTEM_MF_R_PLATFORM_HEADER__
#include "libapi_pub.h"
#include <lvgl/lvgl.h>
#include <time.h>
#include "tms/src/tms_download.h"
#include "pub/osl/inc/osl_log.h"

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



enum {
	SDK_LCD_TYPE_GET_FILE = -1,			///<get file
	SDK_LCD_TYPE_GET_FAIL = SDK_LCD_TYPE_GET_FILE,
	SDK_LCD_TYPE_480_800 = 0,			///<mf960
	SDK_LCD_TYPE_320_240,				///<h9u/h9l/h9n

	SDK_LCD_TYPE_240_240 = 11,
	SDK_LCD_TYPE_320_480,
	SDK_LCD_TYPE_128_32,
}sdk_lcd_type;


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions: Get version number of system class module
Input : Nothing
Output : pszVer   Module version number
return: > 0 Successfully returns module version number length
		USYS_FAIL     = -1,    
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetModuleVer(char *pszVer);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Initialization of system and initialization of application layer Nothing
Input : Argc: Reusing main function parameter Argc
		Argv: Reusing main function parameter Argv
		AppName:Application name

Output : Nothing
return: USYS_FAIL     = -1,  Fail
		USYS_FIRST    = 1,   for the first time since the program was updated.
		USYS_NOFIRST  = 2    Program is not run for the first time.

Remarks: Not to be processed without access to ginseng
		Inside the function calls the private API of the manufacturer.
		The API returns to the first operation only when the program is newly installed, 
		and the update is not the first operation.
*************************************************************************************/
LIB_EXPORT int Sys_Init(int Argc,char **Argv,char *AppName);

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
		USYS_SUCCES   = 0,Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetTerminalInfo(TERMINALINFO *terminal);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get SysTime
Input : Nothing
Output : DateTime:"YYYYMMDDHHMMSS" 14 Bytes?
return: USYS_FAIL     = -1,  Fail
		USYS_SUCCES   = 0,Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetDateTime(byte *DateTime);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Set SysTime
Input : DateTime:"YYYYMMDDHHMMSS" 14Byte
Output : Nothing
return: USYS_PARAERROR = -2,   //Parameter Error
		USYS_FAIL     = -1,  Fail
		USYS_SUCCES   = 0,Success
Remarks: Internal judgment of time format in API
*************************************************************************************/
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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Open timer and set timer time.
Input : TimerMs
Output : Nothing
return: Return timer handle successfully
		USYS_FAIL           = -1,    Fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_TimerOpen(uint TimerMs);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Check whether the timing time is up to
Input : iHandle:Timer
Output : Nothing
return: Successfully returned, remaining time, unit milliseconds (0 indicates timed time).
		USYS_FAIL           = -1,    Fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_TimerCheck(int iHandle);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Off Timer
Input : iHandle : Timer
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_TimerClose(int iHandle);
LIB_EXPORT unsigned int Sys_GetTick();

/**
 * @brief Check for timeout
 *
 * @param[in] tick Starting time
 * @param[in] timeover Timeout period
 * @return  0, within the effective time
 * @return  1, timeout
 */
LIB_EXPORT int Sys_CheckTick(int tick, int timeover);

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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Delay blocking
Input : uiMs:Delay time unit MS
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_Delay(uint uiMs);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions: Real time display of battery power
Input : isDisp:0- does not display, 1- display
Output : Nothing
return: Successful  0-100 (100 indicates maximum).
		USYS_FAIL           = -1,    Fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetBatter(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Terminal goes to sleep state
Input : Time: Entering dormancy time, unit seconds
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 Success
Remarks: The application needs to detect the status of 
		wireless network registration after wakeup.
*************************************************************************************/
LIB_EXPORT int Sys_Sleep(uint Time);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Terminal reboot
Input : Nothing
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 Success
Remarks: 
*************************************************************************************/
LIB_EXPORT int Sys_Reboot(void);

/**
 * @brief
 * 
 * @param[out] byte *psFirmwareInfo
 * @param[out] int *pnLen
 * @return USYS_SUCCESS
 */
LIB_EXPORT int Sys_GetFirmwareInfo(byte *psFirmwareInfo, int *pnLen);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Set screen backlight mode
Input : mode Backlight mode
			0- turn off backlight
			1- system automatically controls
			2- backlight is always bright
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 	Success
Remarks: Mode=1 indicates that the backlight is automatically 
				controlled by the system, with a default of 1.
*************************************************************************************/
LIB_EXPORT int Sys_SetScrBackLight(byte mode);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get terminal serial number
Input : Nothing
Output : Sn Serial number
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetTermSn(char *Sn);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Open Scan
Input : Nothing
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
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


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Close Scan
Input : pfun
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_scaner_close();



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


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Initialization driver
Input : Nothing
Output : Nothing 
return: none
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_driverlib_init();


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


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Brighten the backlight by pressing the key
Input : Nothing
Output : Nothing 
return: Return 1 has a secondary liquid crystal
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void  Sys_power_key_set_light();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Get the shutdown time
Input : Nothing
Output : Nothing 
return: Return shutdown time
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT  int Sys_lcd_PowerDownTime();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Set the shutdown time
Input : ntime  shutdown time
Output : Nothing 
return: 
Remarks: Nothing
*************************************************************************************/

LIB_EXPORT  void Sys_lcd_SetPowerDownTime(int ntime);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Get  Backlight time
Input : Nothing
Output : Nothing 
return: Return Backlight time
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT  int Sys_lcd_BackLightTime();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Set Backlight time
Input : ntime  Backlight time
Output : Nothing 
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT  void Sys_lcd_SetBackLightTime(int ntime);

/**
 * @brief
 * 
 * @param[in] unsigned char prio
 * @return 
 */
LIB_EXPORT unsigned char Sys_TaskDel(unsigned char prio);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:linzhu
Functions:Get app version
Input : 
Output :
return: the app version
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT const char * Sys_GetAppVer();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:linw
Functions:Get boot version
Input : 
Output :
return: the boot version
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT char* Sys_boot_ver();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:linw
Functions:Get driver version
Input : 
Output :
return: the driver version
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT char* Sys_hal_ver();

/**
 * @brief View kernel version
 *
 * @return  Kernel version
 */
LIB_EXPORT char* Sys_kernel_ver(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:linw
Functions:Get sp version
Input : 
Output :
return: the sp version
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT char* Sys_sp_ver();

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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:Set TMS state
Input : nBusyState:1 app busy, not deal TMS; 0 app not busy, can deal TMS
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_tms_AppBusy(int nBusyState);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:run tms update task
Input : 
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_tms_update();

/**
 * @brief Whether to enable the TMS service
 * 
 * @param[in] int enable   1-enable, 0 -disable
 */
LIB_EXPORT void Sys_tms_Enable(int enable);

/**
 * @brief task run once
 * 
 * @param[in] void * pfunc
 */
LIB_EXPORT void Sys_task_app_set(void * pfunc);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ware
Functions:creat thread task for app
Input : prio:0~4
Output :
return: 0:succ, -1:fail
Remarks: Provide 5 thread creation
		For ET380, 0 has the highest priority. The higher the parameter value, the lower the priority
		For ET389, 0 has the lowest priority. The higher the parameter value, the higher the priority
*************************************************************************************/
LIB_EXPORT int Sys_TaskCreate( void(*pfun)(void *param) , int prio, char * stk, int task_size );

LIB_EXPORT void Sys_set_log_data(char * buff , int len);
LIB_EXPORT void Sys_init();
LIB_EXPORT void Sys_magtek_open();
LIB_EXPORT void Sys_magtek_close();
LIB_EXPORT int Sys_Enercy_Time();
LIB_EXPORT int Sys_Enercy_SetTime( int nTime );

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:set device language
Input :nLanguageType; 0,Chinese;1,English;2,Persian 
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_set_language(int nLanguageType);
LIB_EXPORT unsigned int Sys_TimerCreate(void *pfunc, void* pParam, unsigned int nPeriod, unsigned int nMode, unsigned int *pnErrorCode);
LIB_EXPORT unsigned int Sys_TimerEnable (unsigned int nTimerNo);
LIB_EXPORT int Sys_model_type();
LIB_EXPORT const char * Sys_getDeviceVision();
LIB_EXPORT const char * Sys_getSysVersion();
LIB_EXPORT void Sys_get_psn(char * psn);
		  
#define SYS_TRACE( ...)	osl_log( "lib", 0 , __VA_ARGS__ )
#define SYS_TRACE_BUFF(buff,size,tip) 	osl_log_buff_tip("lib",0,buff, size , tip ,1 );


typedef void (*api_app_start)();
LIB_EXPORT void Sys_Start(const char *app_ver,api_app_start apprun);

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
	X_Tms_Update_Start,//tms upgrading
	X_Tms_Update_Unzip,//tms unzipping
	X_Tms_Update_Succ,//tms success
	X_Tms_Update_Fail,//tms fail
	X_Tms_Sign_Succ,//tms verify signed success
	X_Tms_Sign_Fail//tms verify signed fail

};
typedef int (*api_tts_system_play)( int type, void *data);

LIB_EXPORT void Sys_ttsSystemSetFunc( api_tts_system_play playproc);


LIB_EXPORT void Sys_TtsPlay(const char *file);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:TMS upgrade
Input : file:Upgrade file name
		flag:upgrade application and data, 0 upgrade data only
		
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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Set the sleep mode time
Input : time_num:Sleep mode time(Unit: second)

Output : Nothing
return: void
*************************************************************************************/
LIB_EXPORT void Sys_set_powertime(int time_num);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Set the time from sleep to wake up of the device
Input : time_num:Sleep mode time(Unit: second)

Output : Nothing
return: void
*************************************************************************************/
LIB_EXPORT void Sys_set_sleep_to_wake_time(int time_num);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:ntag correlation function
*************************************************************************************/
LIB_EXPORT int Sys_rfid_emulate_init(void);
LIB_EXPORT int Sys_rfid_emulate_config(unsigned char* cardinfo, int infolen, unsigned char(*cardblock)[4], unsigned int block_cap);
LIB_EXPORT void Sys_rfid_emulate_process(void);
LIB_EXPORT int Sys_rfid_emulate_deinit(void);

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
Functions: master screen logo init
Input : logoPath  Path of the logo.bin file
Output : Nothing
return: 0:success; Other:fail
eg: Sys_logo_init("exdata\\logo.bin");
*************************************************************************************/
LIB_EXPORT int Sys_master_logo_init(char *logoPath , int bDelete);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ware
Functions: logo init
Input : logoPath  Path of the logo.bin file
Input : bDelete Whether to delete logo file 1-yes, 0-no
Output : Nothing
return: 0:success; Other:fail
eg: Sys_logo_init("exdata\\logo.bin");
*************************************************************************************/
LIB_EXPORT int Sys_logo_initA(char *logoPath , int bDelete);

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

LIB_EXPORT void Sys_tms_CheckTime_disable(void);

LIB_EXPORT void Sys_TmsSetProgressCallback(void* pFunCallback);

LIB_EXPORT void Sys_KeySetParam(int key, int short_press_time, int long_press_time, int short_press_delay);

/**
 * @brief Segment code  screen
 * 
 * @param[in] s32 status
 * @return 
 */
LIB_EXPORT int Sys_SegmentBackLight(int status);

LIB_EXPORT int Sys_Curl_Init(int Argc,char **Argv,char *AppName);

LIB_EXPORT lv_obj_t* Sys_gui_group_get_obj(void);

#endif /*__LIBAPI_SYSTEM_MF_R_PLATFORM_HEADER__*/
