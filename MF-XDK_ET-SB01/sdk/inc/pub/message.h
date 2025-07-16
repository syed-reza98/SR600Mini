/*! \file message.h
	\brief ��Ϣ����
*	\author lx
*	\date 2014/02/08
*/
#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "pub/pub.h"

#ifdef __cplusplus
extern "C"{
#endif
	

#include "messagedatastruct.h"

#define XM_LONG_TIMEOVER		0x7fffffff

#define XM_CREATE

//��Դ����Ϣ
#define XM_POWERFIRST			0x00000000 
#define XM_POWERDOWN			0x00000001
#define XM_POWNLOWER			0x00000002
#define XM_UNZIPFILE			0x00000003
#define XM_FINISHFILE		    0x00000004
#define XM_POWERENERGY			0x00000005 //����ҳ��
#define XM_POWERENERGYEXIT		0x00000006 //����ҳ��
#define XM_POWERLOWDOWN			0x00000007	// ��ѹ�ػ�

#define XM_POWERLAST			0x0000FFFF


//ϵͳ����Ϣ
#define XM_SYSTEMFIRST			0x00010000
#define XM_SYSTEM_TC35			0x00010001
#define XM_SYSTEM_SWITCH		0x00010002
#define XM_SYSTEM_MODULE		0x00010003

#define XM_SYSTEMLAST			0x0001FFFF

//�ֱ�����Ϣ
#define XM_HOOKFIRST			0x00040000
#define XM_HOOKPRESS			0x00040001
#define XM_HOOKLAST				0x0004FFFF
	
//��������Ϣ
#define XM_KEYFIRST				0x00050000
#define XM_KEYPRESS				0x00050001
#define XM_KEYLAST				0x0005FFFF


//��������Ϣ
#define XM_UARTFIRST			0x00060000
#define XM_UARTLAST				0x0006FFFF


//ָ������Ϣ
#define XM_POINTERFIRST			0x00070000
#define XM_POINTERUP			0x00070001
#define XM_POINTERDOWN			0x00070002
#define XM_POINTERMOVE			0x00070003

#define XM_POINTERLAST			0x0007FFFF


//GUI����Ϣ
#define XM_GUIFIRST				0x000A0000
#define XM_GUIPAINT				0x000A0001
#define XM_GUITEXTOUT			0x000A0002
#define XM_GUIDRAWMENU			0x000A0003	//�ػ��˵�
#define XM_GUIDRAWTEXT			0x000A0004	//�ػ��ı�
#define XM_GUIDRAWCURSOR		0x000A0005	//�ػ����

#define XM_GUIEXITWIN			0x000A1000	//�˳�

#define XM_GUILAST				0x000AFFFF




//�û�����Ϣ
#define XM_USERFIRST			0x000E0000

#define XM_GPRS_TIP				0x000E0010
#define XM_PRODUCT_TEST			0x000E0011

#define XM_SCAN_OK				0x000E0021

#define XM_USERLAST				0x000EFFFF



/**
* @brief ��ʼ����Ϣ����
* @param 
* @return 
*/
LIB_EXPORT unsigned int xgui_Message_init(void);	
/**
* @brief ������Ϣ����������
* @param nMsgID ��Ϣid
* @param wParam ��Ϣ����
* @param lParam ��Ϣ����
* @return 0�ɹ�
*/
LIB_EXPORT unsigned int xgui_PostMessage(unsigned int nMsgID,unsigned int wParam, unsigned int lParam);			

unsigned int xgui_GetMessage(PMESSAGE pMsg, unsigned int wMsgFilterMin, unsigned int wMsgFilterMax );	
/**
* @brief ��ϵͳ��Ϣ����ȡһ����Ϣ�����û����Ϣ��ȴ���ʱ
* @param pMsg ��Ϣ�ṹ
* @param timeover ��ʱʱ��
* @return ��ȡ���
*/
LIB_EXPORT unsigned int xgui_GetMessageWithTime( PMESSAGE pMsg , int timeover);
				   
#ifdef __cplusplus
}
#endif
#endif







