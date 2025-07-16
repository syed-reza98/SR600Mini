/*! \file osl_timer.h
	\brief ��ʱ��
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "pub\pub.h"

#include "osl_timerdatastruct.h"




/**
* @brief ��ʼ����ʱ������
* @param 
* @return 
*/
LIB_EXPORT unsigned int osl_TimerInit(void);


/**
* @brief ����һ����ʱ��
* @param ������
* @param pParam ����
* @param nPeriod ��ʱ����
* @param nMode ģʽ
* @param pnErrorCode ������
* @return 0ʧ�� ����0��ʱ�����
*/
LIB_EXPORT unsigned int osl_TimerCreate(TIMERFUNCTION pWorkFunction, void* pParam, unsigned int nPeriod, unsigned int nMode, unsigned int *pnErrorCode);


/**
* @brief ɾ��ָ���Ķ�ʱ��
* @param nTimerNo ��ʱ�����
* @return 0�ɹ�
*/
LIB_EXPORT unsigned int osl_TimerDelete (unsigned int nTimerNo);		


/**
* @brief ʹ��ָ���Ķ�ʱ��
* @param nTimerNo ��ʱ�����
* @return 0�ɹ�
*/
LIB_EXPORT unsigned int osl_TimerEnable (unsigned int nTimerNo);


/**
* @brief ��λָ���Ķ�ʱ��
* @param nTimerNo ��ʱ�����
* @return 0�ɹ�
*/
LIB_EXPORT unsigned int osl_TimerReset (unsigned int nTimerNo);

//
/**
* @brief ����ָ���Ķ�ʱ���Ķ�ʱ����
* @param nTimerNo ��ʱ�����
* @param nPeriod ��ʱ����
* @return 0�ɹ�
*/
LIB_EXPORT unsigned int osl_TimerSetPeriod(unsigned int nTimerNo, unsigned int nPeriod);
/**
* @brief ���ö�ʱ����ǰʱ��
* @param nTimerNo ��ʱ�����
* @param nCurTime ��ǰʱ��
* @return 0�ɹ�
*/
LIB_EXPORT unsigned int osl_TimerSetCurTime(unsigned int nTimerNo, unsigned int nCurTime);

/**
* @brief ��ȡ��ʱ����ǰʱ��
* @param nTimerNo ��ʱ�����
* @return ��ǰʱ��
*/
LIB_EXPORT unsigned int osl_TimerGetCurTime(unsigned int nTimerNo);


/**
* @brief ��ָֹ���Ķ�ʱ��
* @param nTimerNo ��ʱ�����
* @return 0�ɹ�
*/
LIB_EXPORT unsigned int osl_TimerDisable (unsigned int nTimerNo);
/**
* @brief ��ȡ��ʱ��״̬
* @param nTimerNo ��ʱ�����
* @return 0ֹͣ
*/
LIB_EXPORT unsigned int osl_TimerGetStatus (unsigned int nTimerNo);










