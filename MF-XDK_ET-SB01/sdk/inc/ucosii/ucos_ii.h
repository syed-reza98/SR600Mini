/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*
*                            (c) Copyright 1992-2003, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* File : uCOS_II.H
* By   : Jean J. Labrosse
*********************************************************************************************************
*/

#include "pub\pub.h"

#ifndef  OS_uCOS_II_H
#define  OS_uCOS_II_H


#define	OS_ERR					200
#define	OS_NO_ERR               0

#define ERROR_NO_ERROR OS_NO_ERR
#define TIMEOUT_NOWAIT -1
#define TIMEOUT_INFINITE 0

#define OS_TICKS_PER_SEC	1000u

#ifndef OS_NOVA

	typedef signed char		INT8S;

typedef unsigned char		INT8U;

	typedef short int			INT16;

	typedef signed short int	INT16S;

typedef unsigned short 	INT16U;

	typedef int				INT32;

	typedef unsigned int		INT32U;

	typedef signed int			INT32S;

#endif

typedef struct os_stk_data {
	unsigned int  OSFree;                    /* Number of FREE bytes on the stack                            */
	unsigned int  OSUsed;                    /* Number of bytes used on the stack                            */
} OS_STK_DATA;

/*
*********************************************************************************************************
*                              TASK STATUS (Bit definition for OSTCBStat)
*********************************************************************************************************
*/
#define  OS_STAT_RDY            0x00        /* Ready to run                                            */
#define  OS_STAT_SEM            0x01        /* Pending on semaphore                                    */
#define  OS_STAT_MBOX           0x02        /* Pending on mailbox                                      */
#define  OS_STAT_Q              0x04        /* Pending on queue                                        */
#define  OS_STAT_SUSPEND        0x08        /* Task is suspended                                       */
#define  OS_STAT_MUTEX          0x10        /* Pending on mutual exclusion semaphore                   */
#define  OS_STAT_FLAG           0x20        /* Pending on event flag group                             */

/*
*********************************************************************************************************
*                                        OS_EVENT types
*********************************************************************************************************
*/
#define  OS_EVENT_TYPE_UNUSED      0
#define  OS_EVENT_TYPE_MBOX        1
#define  OS_EVENT_TYPE_Q           2
#define  OS_EVENT_TYPE_SEM         3
#define  OS_EVENT_TYPE_MUTEX       4
#define  OS_EVENT_TYPE_FLAG        5

/*
*********************************************************************************************************
*                                         EVENT FLAGS
*********************************************************************************************************
*/
#define  OS_FLAG_WAIT_CLR_ALL      0        /* Wait for ALL    the bits specified to be CLR (i.e. 0)   */ 
#define  OS_FLAG_WAIT_CLR_AND      0

#define  OS_FLAG_WAIT_CLR_ANY      1        /* Wait for ANY of the bits specified to be CLR (i.e. 0)   */
#define  OS_FLAG_WAIT_CLR_OR       1

#define  OS_FLAG_WAIT_SET_ALL      2        /* Wait for ALL    the bits specified to be SET (i.e. 1)   */ 
#define  OS_FLAG_WAIT_SET_AND      2

#define  OS_FLAG_WAIT_SET_ANY      3        /* Wait for ANY of the bits specified to be SET (i.e. 1)   */
#define  OS_FLAG_WAIT_SET_OR       3


#define  OS_FLAG_CONSUME        0x80        /* Consume the flags if condition(s) satisfied             */


#define  OS_FLAG_CLR               0
#define  OS_FLAG_SET               1

/*
*********************************************************************************************************
*                                   Values for OSTickStepState
*
* Note(s): This feature is used by uC/OS-View.
*********************************************************************************************************
*/

#define  OS_TICK_STEP_DIS          0        /* Stepping is disabled, tick runs as mormal               */
#define  OS_TICK_STEP_WAIT         1        /* Waiting for uC/OS-View to set OSTickStepState to _ONCE  */
#define  OS_TICK_STEP_ONCE         2        /* Process tick once and wait for next cmd from uC/OS-View */

/*
*********************************************************************************************************
*       Possible values for 'opt' argument of OSSemDel(), OSMboxDel(), OSQDel() and OSMutexDel()
*********************************************************************************************************
*/
#define  OS_DEL_NO_PEND            0
#define  OS_DEL_ALWAYS             1

/*
*********************************************************************************************************
*                                     OS???PostOpt() OPTIONS
*
* These #defines are used to establish the options for OSMboxPostOpt() and OSQPostOpt().
*********************************************************************************************************
*/
#define  OS_POST_OPT_NONE       0x00        /* Post to highest priority task waiting                   */
#define  OS_POST_OPT_BROADCAST  0x01        /* Broadcast message to ALL tasks waiting                  */  
#define  OS_POST_OPT_FRONT      0x02        /* Post to highest priority task waiting                   */

/*
*********************************************************************************************************
*                                 TASK OPTIONS (see OSTaskCreateExt()) 
*********************************************************************************************************
*/
#define  OS_TASK_OPT_STK_CHK  0x0001        /* Enable stack checking for the task                      */
#define  OS_TASK_OPT_STK_CLR  0x0002        /* Clear the stack when the task is create                 */
#define  OS_TASK_OPT_SAVE_FP  0x0004        /* Save the contents of any floating-point registers       */

/*
*********************************************************************************************************
*                                             ERROR CODES
*********************************************************************************************************
*/
#define OS_Q_NEED_CONTEXT 3		//softmcu added 0613 //add by xcb
#define OS_SEM_NEED_CONTEXT 4		//softmcu added 1205 //add by xcb
 

#define OS_ERR_EVENT_TYPE             1u
#define OS_ERR_PEND_ISR               2u
#define OS_ERR_POST_NULL_PTR          3u
#define OS_ERR_PEVENT_NULL            4u
#define OS_ERR_POST_ISR               5u
#define OS_ERR_QUERY_ISR              6u
#define OS_ERR_INVALID_OPT            7u
#define OS_ERR_TASK_WAITING           8u

#define OS_TIMEOUT                   10u
#define OS_TASK_NOT_EXIST            11u
#define OS_ERR_EVENT_NAME_TOO_LONG   12u
#define OS_ERR_FLAG_NAME_TOO_LONG    13u
#define OS_ERR_TASK_NAME_TOO_LONG    14u
#define OS_ERR_PNAME_NULL            15u

#define OS_MBOX_FULL                 20u

//#define OS_Q_FULL                    30u
//#define OS_Q_EMPTY                   31u

#define OS_PRIO_EXIST                40u
#define OS_PRIO_ERR                  41u
#define OS_PRIO_INVALID              42u

#define OS_SEM_OVF                   50u

#define OS_TASK_DEL_ERR              60u
#define OS_TASK_DEL_IDLE             61u
#define OS_TASK_DEL_REQ              62u
#define OS_TASK_DEL_ISR              63u

#define OS_NO_MORE_TCB               70u

#define OS_TIME_NOT_DLY              80u
#define OS_TIME_INVALID_MINUTES      81u
#define OS_TIME_INVALID_SECONDS      82u
#define OS_TIME_INVALID_MILLI        83u
#define OS_TIME_ZERO_DLY             84u

#define OS_TASK_SUSPEND_PRIO         90u
#define OS_TASK_SUSPEND_IDLE         91u

#define OS_TASK_RESUME_PRIO         100u
#define OS_TASK_NOT_SUSPENDED       101u

#define OS_MEM_INVALID_PART         110u
#define OS_MEM_INVALID_BLKS         111u
#define OS_MEM_INVALID_SIZE         112u
#define OS_MEM_NO_FREE_BLKS         113u
#define OS_MEM_FULL                 114u
#define OS_MEM_INVALID_PBLK         115u
#define OS_MEM_INVALID_PMEM         116u
#define OS_MEM_INVALID_PDATA        117u
#define OS_MEM_INVALID_ADDR         118u
#define OS_MEM_NAME_TOO_LONG        119u

#define OS_ERR_NOT_MUTEX_OWNER      120u

#define OS_TASK_OPT_ERR             130u

#define OS_ERR_DEL_ISR              140u
#define OS_ERR_CREATE_ISR           141u

#define OS_FLAG_INVALID_PGRP        150u
#define OS_FLAG_ERR_WAIT_TYPE       151u
#define OS_FLAG_ERR_NOT_RDY         152u
#define OS_FLAG_INVALID_OPT         153u
#define OS_FLAG_GRP_DEPLETED        154u

/*$PAGE*/
/*
*********************************************************************************************************
*                                          EVENT CONTROL BLOCK
*********************************************************************************************************
*/

typedef struct event{
	void* pExt;
	void* handle;
}OS_EVENT;


/*
*********************************************************************************************************
*                                       EVENT FLAGS CONTROL BLOCK
*********************************************************************************************************
*/

typedef struct os_flag_grp {                /* Event Flag Group                                        */
	void* hEventGroup[32];
	unsigned int				uiCurrent_events;		 /* Current event flags    */
} OS_FLAG_GRP;    

    
typedef int OS_FLAGS;   

typedef struct os_flag_node {               /* Event Flag Wait List Node                               */
    void         *OSFlagNodeNext;           /* Pointer to next     NODE in wait list                   */
    void         *OSFlagNodePrev;           /* Pointer to previous NODE in wait list                   */
    void         *OSFlagNodeTCB;            /* Pointer to TCB of waiting task                          */  
    void         *OSFlagNodeFlagGrp;        /* Pointer to Event Flag Group                             */  
    OS_FLAGS      OSFlagNodeFlags;          /* Event flag to wait on                                   */  
    unsigned char         OSFlagNodeWaitType;       /* Type of wait:                                           */
                                            /*      OS_FLAG_WAIT_AND                                   */
                                            /*      OS_FLAG_WAIT_ALL                                   */
                                            /*      OS_FLAG_WAIT_OR                                    */
                                            /*      OS_FLAG_WAIT_ANY                                   */
} OS_FLAG_NODE;

/*
*********************************************************************************************************
*                                         EVENT FLAGS MANAGEMENT
*********************************************************************************************************
*/

LIB_EXPORT OS_FLAGS			OSFlagAccept(OS_FLAG_GRP *pgrp, OS_FLAGS flags, unsigned char wait_type, unsigned char *err);
LIB_EXPORT OS_FLAG_GRP		*OSFlagCreate(OS_FLAGS flags, unsigned char *err);
LIB_EXPORT OS_FLAG_GRP		*OSFlagDel(OS_FLAG_GRP *pgrp, unsigned char opt, unsigned char *err);
LIB_EXPORT unsigned char	OSFlagNameGet(OS_FLAG_GRP *pgrp, char *pname, unsigned char *err);
LIB_EXPORT void				OSFlagNameSet(OS_FLAG_GRP *pgrp, char *pname, unsigned char *err);
LIB_EXPORT OS_FLAGS			OSFlagPend(OS_FLAG_GRP *pgrp, OS_FLAGS flags, unsigned char wait_type, unsigned short timeout, unsigned char *err);
LIB_EXPORT OS_FLAGS			OSFlagPendGetFlagsRdy(void);
//OS_FLAGS      OSFlagPost(OS_FLAG_GRP *pgrp, OS_FLAGS flags, unsigned char operation, unsigned char *err);
LIB_EXPORT OS_FLAGS			OSFlagQuery(OS_FLAG_GRP *pgrp, unsigned char *err);

LIB_EXPORT	unsigned char   OSTaskStkChk(unsigned char            prio,OS_STK_DATA     *p_stk_data);

/*
*********************************************************************************************************
*                                        MESSAGE MAILBOX MANAGEMENT
*********************************************************************************************************
*/

LIB_EXPORT void				*OSMboxAccept(OS_EVENT *pevent);
LIB_EXPORT OS_EVENT			*OSMboxCreate(void *msg);
LIB_EXPORT OS_EVENT			*OSMboxDel(OS_EVENT *pevent, unsigned char opt, unsigned char *err);
LIB_EXPORT void				*OSMboxPend(OS_EVENT *pevent, unsigned short timeout, unsigned char *err);
LIB_EXPORT unsigned char    OSMboxPost(OS_EVENT *pevent, void *msg);
LIB_EXPORT unsigned char    OSMboxPostOpt(OS_EVENT *pevent, void *msg, unsigned char opt);

/*$PAGE*/
/*
*********************************************************************************************************
*                                         MESSAGE QUEUE MANAGEMENT
*********************************************************************************************************
*/

//void         *OSQAccept(OS_EVENT *pevent, unsigned char *err);
//
//OS_EVENT     *OSQCreate(void **start, unsigned short size);
//
//OS_EVENT     *OSQDel(OS_EVENT *pevent, unsigned char opt, unsigned char *err);
//
//unsigned char         OSQFlush(OS_EVENT *pevent);
//
//void         *OSQPend(OS_EVENT *pevent, unsigned short timeout, unsigned char *err);
//
//unsigned char         OSQPost(OS_EVENT *pevent, void *msg);
//
//unsigned char         OSQPostFront(OS_EVENT *pevent, void *msg);
//
//unsigned char         OSQPostOpt(OS_EVENT *pevent, void *msg, unsigned char opt);
//
//unsigned char         OSQQuery(OS_EVENT *pevent, OS_Q_DATA *p_q_data);


LIB_EXPORT unsigned short   OSSemAccept(OS_EVENT *pevent);
LIB_EXPORT OS_EVENT			*OSSemCreate(unsigned short cnt);
LIB_EXPORT OS_EVENT			*OSSemDel(OS_EVENT *pevent, unsigned char opt, unsigned char *err);
LIB_EXPORT void				OSSemPend(OS_EVENT *pevent, unsigned short timeout, unsigned char *err);
LIB_EXPORT unsigned char    OSSemPost(OS_EVENT *pevent);


LIB_EXPORT void				OSSemPend_Timeout(OS_EVENT* pevent, unsigned short timeout, unsigned char* err);
LIB_EXPORT void OSSemClear(OS_EVENT* pevent);


/*$PAGE*/
/*
*********************************************************************************************************
*                                            TASK MANAGEMENT
*********************************************************************************************************
*/

typedef unsigned int OS_STK;

LIB_EXPORT void				OSInit(void);
LIB_EXPORT void				OSStart(void);
LIB_EXPORT unsigned char    OSTaskChangePrio(unsigned char oldprio, unsigned char newprio);
LIB_EXPORT unsigned char    OSTaskCreate(void (*task)(void *pd), void *p_arg, OS_STK *ptos, unsigned char prio);
LIB_EXPORT unsigned char	OSTaskCreateExt(void  (*task)(void *pd),void   *p_arg,OS_STK *ptos,unsigned char   prio,unsigned short  id,OS_STK *pbos,unsigned int  stk_size,void   *pext,unsigned short  opt);
LIB_EXPORT unsigned char	OSTaskCreateExt_1(void  (*task)(void* pd), void* p_arg, OS_STK* ptos, int   prio, int   id, OS_STK* pbos, unsigned int  stk_size, void* pext, unsigned short  opt);
LIB_EXPORT unsigned char    OSTaskDel(unsigned char prio);
LIB_EXPORT unsigned char	OSTaskDelReq(unsigned char prio);
LIB_EXPORT unsigned char	OSTaskNameGet(unsigned char prio, char *pname, unsigned char *err);
LIB_EXPORT void				OSTaskNameSet(unsigned char prio, char *pname, unsigned char *err);
LIB_EXPORT unsigned char    OSTaskResume(unsigned char prio);
LIB_EXPORT unsigned char    OSTaskSuspend(unsigned char prio);

LIB_EXPORT int OSTimeGet(void);

/*$PAGE*/
/*
*********************************************************************************************************
*                                            TIME MANAGEMENT
*********************************************************************************************************
*/

LIB_EXPORT void     OSTimeDly(unsigned short ticks);
LIB_EXPORT void     OSTimeTick(void);

LIB_EXPORT int		OSGetTaskId();
/*
*********************************************************************************************************
*                                             MISCELLANEOUS
*********************************************************************************************************
*/

#endif