#pragma once
#include "pub/pub.h"

void tdownload_refrush( const char *url, const char *newmd5, int qzsj );
void tdownload_clean();




void beginwaitbusy(const char *flag,int waitcount);
void endwaitbusy();
void tms_comm_page_tip(char * title , char * msg );



typedef void (*ptms_progress_callback)(int, int);//��һ�������ǵ�ǰֵ,�ڶ��ݲ�����ֵ��
LIB_EXPORT void set_tms_progress_callback(ptms_progress_callback pfun);


/**
 * tms����״̬
 */
LIB_EXPORT int  get_tms_update_state();