/*! \file fifo_func.h
*	\brief 队列功能实现
*	\author lx
*	\date 2014/02/07
*/

#ifndef _FIFOFUNC_H_
#define _FIFOFUNC_H_

#include "pub\pub.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************************标准库头文件**********************************/

/*******************************非标准库头文件**********************************/

/*********************************全局宏定义***********************************/

/********************************全局数据原型**********************************/

//! 队列结构
typedef struct 
{
	unsigned int Outp;					///<出队指针
	unsigned int Inp;					///<入队指针
	unsigned char * pBuff;				///<数据缓冲区
	unsigned int nSize;					///<队列大小
	int pEvent;							///<互斥信号量	
}FIFO_DATA;

/********************************全局函数原型**********************************/

/**
* @brief 改变队列大小
* @param pstFifo 队列指针
* @param nSzie	队列大小				
* @return 1成功 0失败
*/
LIB_EXPORT int API_FifoResize(FIFO_DATA * pstFifo , int nSzie);

/**
* @brief 创建队列
* @param pstFifo 队列指针
* @param nSzie 队列大小
* @return 1成功 0失败
*/
LIB_EXPORT int API_FifoCreate(FIFO_DATA * pstFifo ,  int nSzie );

/**
* @brief 初始化队列
* @param pstFifo	队列指针
* @return void
*/
LIB_EXPORT void API_FifoInit(FIFO_DATA* pstFifo);
/**
* @brief 读取数据
* @param pstFifo 队列指针
* @param pData 数据缓冲
* @param nLen 要求读取长度
* @return 实际读取长度
*/
LIB_EXPORT int API_FifoGet(FIFO_DATA* pstFifo,unsigned char * pData  , int nLen);
/**
* @brief 数据写入
* @param pstFifo 队列指针
* @param pData 数据缓冲
* @param nLen 要求写入长度
* @return 实际写入长度
*/
LIB_EXPORT int API_FifoPut(FIFO_DATA* pstFifo, unsigned char * pData , int nLen);
/**
* @brief 队列是否满
* @param pstFifo 队列指针
* @return 1满 0非满
*/
LIB_EXPORT int API_FifoIsFull(FIFO_DATA* pstFifo);
/**
* @brief 队列是否满
* @param pstFifo 队列指针
* @return 1空 0非空
*/
LIB_EXPORT int API_FifoIsEmpty(FIFO_DATA* pstFifo);
/**
* @brief 获取队列数据数量
* @param pstFifo 队列指针
* @return 数据数量
*/
LIB_EXPORT int API_GetFifoNum(FIFO_DATA* pstFifo);


LIB_EXPORT int API_GetFifoSize(FIFO_DATA* pstFifo);
#ifdef __cplusplus
}
#endif

#endif//_FIFOFUNC_H_


