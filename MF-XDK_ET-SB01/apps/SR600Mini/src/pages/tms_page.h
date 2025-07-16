#pragma once
#include "pages.h"

#define TMS_PROC_PAGE	"P:exdata/tmsproc.png"
#define TMS_TIP_SUCC	"P:exdata/tmssucc.png"
#define TMS_TIP_FAIL	"P:exdata/tmsfail.png"

void app_tms_page_show(int progress);
void  TmsDownloadFunc(int size, int total_size);
void  TmsShowResultFunc(int type);
void TmsUpdateFunc();

