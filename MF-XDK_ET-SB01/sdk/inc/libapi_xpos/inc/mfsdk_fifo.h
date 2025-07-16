/**
 * @file mfsdk_fifo.h
 * @author CHAR
 * @brief 
 * @date 2023-11-17
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#ifndef __MFSDK_FIFO_H__
#define __MFSDK_FIFO_H__
#include "mfsdk_define.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
typedef enum
{
	MFSDK_FIFO_FAILED = -3, //failed 
	MFSDK_FIFO_BOUNDS = -2, //Array out-of-bounds 
	MFSDK_FIFO_PARM_ERROR = -1, //check param
	MFSDK_FIFO_OK = 0,
}MfSdkFifoRet_E;


typedef struct 
{
	u32 Outp;		//dequeue pointer
	u32 Inp;		//enqueue pointer
	u8 *pBuff;		//buffer
	u32 nSize;		//FIFO size
	s32 pEvent;		//mutex
}MfSdkFifoData_T;
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T * pstFifo
 * @param[in] s32 nSize fifo size
 * @return MFSDK_TRUE success
 * @return MFSDK_FALSE fail
 */
LIB_EXPORT MFSDKBOOL MfSdkFifoCreate(MfSdkFifoData_T * pstFifo ,  s32 nSize );
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T* pstFifo
 * @param[out] u8 * pData data buffer
 * @param[in] s32 nLen data buffer size
 * @return > 0 - data length
 */
LIB_EXPORT s32 MfSdkFifoGet(MfSdkFifoData_T* pstFifo,u8 * pData  , s32 nLen);
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T* pstFifo
 * @return MFSDK_TRUE success
 * @return MFSDK_FALSE fail 
 */
LIB_EXPORT MFSDKBOOL MfSdkFifoInit(MfSdkFifoData_T* pstFifo);
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T* pstFifo
 * @return MFSDK_TRUE  empty
 * @return MFSDK_FALSE  not  empty
 */
LIB_EXPORT MFSDKBOOL MfSdkFifoIsEmpty(MfSdkFifoData_T* pstFifo);
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T* pstFifo
 * @return MFSDK_TRUE is full
 * @return MFSDK_FALSE not full
 */
LIB_EXPORT MFSDKBOOL MfSdkFifoIsFull(MfSdkFifoData_T* pstFifo);
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T* pstFifo
 * @param[in] u8 * pData push data buffer
 * @param[in] s32 nLen push buffer data length
 * @return > 0 push data length
 * @return MFSDK_FIFO_PARM_ERROR param invalid
 */
LIB_EXPORT s32 MfSdkFifoPut(MfSdkFifoData_T* pstFifo, u8 * pData , s32 nLen);
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T * pstFifo
 * @param[in] s32 nSize
 * @return MFSDK_TRUE success
 * @return MFSDK_FALSE fail
 */
LIB_EXPORT MFSDKBOOL MfSdkFifoResize(MfSdkFifoData_T * pstFifo , s32 nSize);
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T* pstFifo
 * @return > 0 The number of elements in the FIFO
 * @return MFSDK_FIFO_PARM_ERROR param invalid
 */
LIB_EXPORT s32 MfSdkGetFifoNum(MfSdkFifoData_T* pstFifo);
/**
 * @brief
 * 
 * @param[in] MfSdkFifoData_T* pstFifo
 * @return MFSDK_FIFO_PARM_ERROR param invalid
 * @return > 0 ,fifo size
 */
LIB_EXPORT s32 MfSdkGetGetFifoSize(MfSdkFifoData_T* pstFifo);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_FIFO_H__ */
