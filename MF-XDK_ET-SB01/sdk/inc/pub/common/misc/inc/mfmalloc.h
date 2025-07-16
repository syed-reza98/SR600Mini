/*! \file mfmalloc.h
	\brief �ڴ����ӿ�
*	\author lx
*	\date 2014/02/07
*/

#pragma once


#include <pub/pub.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
	#define OUTPUT_FILE_SRC
#else
	#define OUTPUT_FILE_SRC
#endif

#ifdef OUTPUT_FILE_SRC
	#define BUILD_SRC_FILF	__FILE__
	#define BUILD_SRC_LINE	__LINE__
#else
	#define BUILD_SRC_FILF	""
	#define BUILD_SRC_LINE	0
#endif

	
#define MALLOC(a)		mf_malloc(a,BUILD_SRC_FILF , BUILD_SRC_LINE)
#define FREE(a)			mf_free(a, BUILD_SRC_FILF, BUILD_SRC_LINE)
#define REALLOC(a,b)	mf_realloc(a, b, BUILD_SRC_FILF, BUILD_SRC_LINE)
#define STRDUP(a)		mf_strdup(a, BUILD_SRC_FILF, BUILD_SRC_LINE)

/**
* @brief ����MALLOC log����
* @param val 1 �� 0 ��
* @return void
*/
LIB_EXPORT void set_malloc_log(int val);
LIB_EXPORT void * mf_malloc(int size ,char * pcFileName, int nLine);
LIB_EXPORT void mf_free(void *p,char * pcFileName, int nLine);
LIB_EXPORT void mf_malloc_trace(void);
LIB_EXPORT void *mf_realloc(void *p,int newsize, char * pcFileName , int nLine);
LIB_EXPORT void *mf_calloc(int num, int size, char * pcFileName , int nLine);
LIB_EXPORT char *mf_strdup(const char *p, char * pcFileName , int nLine);


LIB_EXPORT int mf_free_head_size();

LIB_EXPORT int mf_malloc_max();
LIB_EXPORT int  mf_min_head_size();


#ifndef _xnmalloc_c
#define malloc		MALLOC
#define free		FREE

#undef realloc
#define realloc(a, b)	mf_realloc(a, b, BUILD_SRC_FILF, BUILD_SRC_LINE)

#undef calloc
#define calloc(a, b)	mf_calloc(a, b, BUILD_SRC_FILF, BUILD_SRC_LINE)

//#ifdef CPU_M56
	#undef strdup
	#define strdup(a)		mf_strdup(a, BUILD_SRC_FILF, BUILD_SRC_LINE)
//#endif

#endif


#ifdef __cplusplus
}
#endif

