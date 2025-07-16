/*! \file fifo_func.h
*	\brief ���й���ʵ��
*	\author lx
*	\date 2014/02/07
*/

#ifndef _FIFOFUNC_H_
#define _FIFOFUNC_H_

#include "pub\pub.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************************��׼��ͷ�ļ�**********************************/

/*******************************�Ǳ�׼��ͷ�ļ�**********************************/

/*********************************ȫ�ֺ궨��***********************************/

/********************************ȫ������ԭ��**********************************/

//! ���нṹ
typedef struct 
{
	unsigned int Outp;					///<����ָ��
	unsigned int Inp;					///<���ָ��
	unsigned char * pBuff;				///<���ݻ�����
	unsigned int nSize;					///<���д�С
	int pEvent;							///<�����ź���	
}FIFO_DATA;

/********************************ȫ�ֺ���ԭ��**********************************/

/**
* @brief �ı���д�С
* @param pstFifo ����ָ��
* @param nSzie	���д�С				
* @return 1�ɹ� 0ʧ��
*/
LIB_EXPORT int API_FifoResize(FIFO_DATA * pstFifo , int nSzie);

/**
* @brief ��������
* @param pstFifo ����ָ��
* @param nSzie ���д�С
* @return 1�ɹ� 0ʧ��
*/
LIB_EXPORT int API_FifoCreate(FIFO_DATA * pstFifo ,  int nSzie );

/**
* @brief ��ʼ������
* @param pstFifo	����ָ��
* @return void
*/
LIB_EXPORT void API_FifoInit(FIFO_DATA* pstFifo);
/**
* @brief ��ȡ����
* @param pstFifo ����ָ��
* @param pData ���ݻ���
* @param nLen Ҫ���ȡ����
* @return ʵ�ʶ�ȡ����
*/
LIB_EXPORT int API_FifoGet(FIFO_DATA* pstFifo,unsigned char * pData  , int nLen);
/**
* @brief ����д��
* @param pstFifo ����ָ��
* @param pData ���ݻ���
* @param nLen Ҫ��д�볤��
* @return ʵ��д�볤��
*/
LIB_EXPORT int API_FifoPut(FIFO_DATA* pstFifo, unsigned char * pData , int nLen);
/**
* @brief �����Ƿ���
* @param pstFifo ����ָ��
* @return 1�� 0����
*/
LIB_EXPORT int API_FifoIsFull(FIFO_DATA* pstFifo);
/**
* @brief �����Ƿ���
* @param pstFifo ����ָ��
* @return 1�� 0�ǿ�
*/
LIB_EXPORT int API_FifoIsEmpty(FIFO_DATA* pstFifo);
/**
* @brief ��ȡ������������
* @param pstFifo ����ָ��
* @return ��������
*/
LIB_EXPORT int API_GetFifoNum(FIFO_DATA* pstFifo);


LIB_EXPORT int API_GetFifoSize(FIFO_DATA* pstFifo);
#ifdef __cplusplus
}
#endif

#endif//_FIFOFUNC_H_


