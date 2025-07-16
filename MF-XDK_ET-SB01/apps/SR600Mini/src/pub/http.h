#ifndef __HTTP_H__
#define __HTTP_H__

#include "pub\taskdef.h"
#include "../card/func_pay.h"
#define HTTP_TASK_PRIO (_APP_TASK_MIN_PRIO + 2)


#define HTTP_BLOCK	1024

#define HTTP_PROC_RUN	-1
#define HTTP_PROC_FAIL	-2
#define HTTP_PROC_SUCC	0
typedef void (*HttpCallbackFunction)(int,char *);
typedef struct {
	char* urlpath_ptr;
	char* SendDate_ptr;
	char* RecData_ptr;
	char  isHttpExist;
	HttpCallbackFunction callbackfunction;
} HttpProcParameter;

HttpProcParameter HttpPtr;
int HttpRequestFree();
int http_proc_init();
#endif
