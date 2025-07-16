#pragma once
//xdk_et.h
#ifdef WIN32
#ifdef DLL_EXPORTS
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT __declspec(dllimport)
#endif
#else
#define LIB_EXPORT
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pub/osl/inc/osl_log.h>
#include <pub/osl/inc/osl_time.h>
#include "pub/common/misc/inc/mfmalloc.h"
#include "pub/common/misc/inc/fifo_func.h"
#include "pub/osl/inc/osl_tts_system.h"
//#include "pub/queue_pub.h"
#include "pub/messagedatastruct.h"
#include "pub/power/power.h"
#include "pub/qrencode/QrEncode.h"
#include "pub/message.h"
#include "pub/taskdef.h"
#include "EntryPoint/lib_emvpub/inc/emv_interface.h"
#include "pub/code/Unicode.h"
#include "tms/src/tms_download.h"
#include "xdk_filedef.h"


#define APP_TASK_PRIO_1   21
#define APP_TASK_PRIO_2   22

//////////////////////////////////////////////////////////////////////////
LIB_EXPORT void osl_system_start(void * pfun);

LIB_EXPORT int osl_app_init(int flag);


LIB_EXPORT void osl_task_create(void * pfun, int prio);


LIB_EXPORT void osl_log(const char *module,int level,const char *fmt,...);

LIB_EXPORT int osl_tts_play(char * sndfile);

LIB_EXPORT void osl_set_tts_sound(int volume);

LIB_EXPORT int osl_get_tts_sound();

LIB_EXPORT void osl_Sleep(int ms);


LIB_EXPORT int osl_CheckTimeover(unsigned int tick1 , unsigned int timeover);

LIB_EXPORT unsigned int osl_GetTick(void);

//////////////////////////////////////////////////////////////////////////

#define KEY_CONTROL		0x80
#define KEY_UP			(KEY_CONTROL + 0x1)
#define KEY_DOWN		(KEY_CONTROL + 0x2)
#define KEY_OK			(KEY_CONTROL + 0x11)
#define KEY_QUIT		(KEY_CONTROL + 0x12)

typedef enum{
	POWER_LOWER_TYPE=0,
	Power_SHUTDOWN_TYPE,	
}EMU_POWER_MSG;

//typedef struct __st_gui_key_event {
//	int keycode;
//	int status;		/*1 down, 0 up*/
//}gui_key_event;
//
//
//typedef struct tagDATE_TIME_T
//{
//	int nYear;
//	int nMonth;
//	int nDay;
//	int nHour;
//	int nMinute;
//	int nSecond;
//}DATE_TIME_T;
//
//LIB_EXPORT int gui_key_getevent(gui_key_event *key_event);


//////////////////////////////////////////////////////////////////////////
LIB_EXPORT void wifi_remote_set_page();




//////////////////////////////////////////////////////////////////////////
LIB_EXPORT int mf_sock_create();

LIB_EXPORT int mf_sock_connect(int s,const char * pIp, int nPort);

LIB_EXPORT int mf_sock_send(int s, unsigned char * buff , int size);

LIB_EXPORT int mf_sock_recv(int s, unsigned char * buff, int len, unsigned int timeover);

LIB_EXPORT int mf_sock_close(int s);

LIB_EXPORT const char* osl_getTerminalID( char *outdata ,int nMaxLen );










LIB_EXPORT int  read_profile_string( const char *section, const char *key,char *value, int size,const char *default_value, const char *file);

LIB_EXPORT int  read_profile_int( const char *section, const char *key,int default_value, const char *file);

LIB_EXPORT int  write_profile_string( const char *section, const char *key,const char *value, const char *file);

LIB_EXPORT int  write_profile_int(const char *section, const char *key, int value, const char *file);



LIB_EXPORT void pt_set_down_func_proc( void* download_proc );


LIB_EXPORT void osl_Sleep(int ms);

LIB_EXPORT int osl_GetDateTime(DATE_TIME_T * pstDateTime);

LIB_EXPORT int osl_SetDateTime(const DATE_TIME_T * pstDateTime);

LIB_EXPORT int tms_update(const char *file);




LIB_EXPORT int http_download(const char *url,const char *fullpathfilename,int iscontinue);

//进度处理
typedef int (*http_download_progress)( int current, int total);
LIB_EXPORT int http_download_progress_set(http_download_progress progressfun);
