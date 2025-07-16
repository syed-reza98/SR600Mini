/*! \file osl_time.h
	\brief ϵͳʱ�亯��
*	\author lx
*	\date 2014/02/08
*/

#pragma once

#include "pub\pub.h"
#ifdef __cplusplus
extern "C"{
#endif
typedef struct tagDATE_TIME_T
{
	int nYear;
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
}DATE_TIME_T;

//#define _TRACE_TICK_BEGIN	unsigned int tick1= osl_GetTick();
//#define _TRACE_TICK_END(a)	printf( #a ":%d\r\n" , osl_GetTick() - tick1);

LIB_EXPORT int osl_GetLevelSec(int timeover ,unsigned int tick1);

/**
* @brief ����ʱ���
* @param tick1 ��ʼʱ��
* @return ʱ���
*/
LIB_EXPORT int osl_GetTickDiff(unsigned int tick1);

/**
* @brief ����Ƿ�ʱ
* @param tick1 ��ʼʱ��
* @param timeover ��ʱʱ��
* @return 1��ʱ
*/
LIB_EXPORT int osl_CheckTimeover(unsigned int tick1 , unsigned int timeover);
/**
* @brief ��ȡ��ǰʱ��
* @param 
* @return 
*/
LIB_EXPORT unsigned int osl_GetTick(void);
/**
* @brief ����һ��ʱ��
* @param ms ʱ��
* @return 
*/
LIB_EXPORT void osl_Sleep(int ms);
/**
* @brief ��ȡϵͳ����ʱ��
* @param pstDateTime ����ʱ��ָ��
* @return 
*/
LIB_EXPORT int osl_GetDateTime(DATE_TIME_T * pstDateTime);
/**
* @brief ����ϵͳ����ʱ��
* @param pstDateTime ����ʱ��ָ��
* @return 
*/
LIB_EXPORT int osl_SetDateTime(const DATE_TIME_T * pstDateTime);

// ��1970.1.1����
LIB_EXPORT unsigned int osl_GetLongDate();
#ifdef __cplusplus
}
#endif