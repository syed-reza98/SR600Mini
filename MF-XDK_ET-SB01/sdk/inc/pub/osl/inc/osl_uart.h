/*! \file osl_uart.h
	\brief �������ݷ���
*	\author lx
*	\date 2014/02/08
*/
#pragma once
#include "pub/pub.h"
#include "pub\pub.h"

#include "driver\uart.h"
#include "pub/pub.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
* @brief �������ݷ���
* @param nCom ���ں�
* @param pBuffer ������
* @param nLength ����
* @return �ѷ��͵ĳ���
*/
LIB_EXPORT int osl_uart_send(unsigned int nCom, unsigned char *pBuffer, unsigned int nLength);


#ifdef __cplusplus
}
#endif	