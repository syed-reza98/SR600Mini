#pragma once

#define TIMER_PRECISION			1
#define TIMER_PRESCALE			64
#define TIMER_MODE_CRITICAL		0xF0AAAA1F
#define TIMER_MODE_NORMAL		0xF0AAAA0F

#define TIMER_STATUS_ENABLE		1
#define TIMER_STATUS_DISABLE 	0

typedef  unsigned int ( *TIMERFUNCTION)(void *);

//��ʱ�����ݽṹ����
typedef struct	__timer_entry_tag{

	unsigned int nTimerNo;	//��ʱ�����
	unsigned int nTaskId;		//��ʱ�����������ȼ�		
	TIMERFUNCTION pWorkFunction;	//��ʱ�������߳�
	void *pParam;		//��ʱ�������̲߳���
	unsigned int nPeriod; //��ʱ����
	unsigned int nCurTime;
	unsigned int nMode;	//��ʱ��ִ��ģʽ
	unsigned int nStatus;	//��ʱ��״̬
} TIMERENTRYTAG;

//��ʱ��������
typedef struct __timer_entry_node{
	TIMERENTRYTAG *pTimerEntry;	
	struct __timer_entry_node *pNext;
}TIMERENTRYNODE;


