/**
* @file  tms_pub.h
* @brief  tms�ӿ�(����tms��ʼ�������������ļ��Ȳ���)
* @author lx
* @date   2021/06/24
*/
#pragma once

#include <pub/pub.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief    tms��ʼ������������̨TMS
* @details   tms��ʼ�����������߳̽����Ƿ���ҪTMS�������
* @return    �̴߳����ɹ�������ķ���
* - 0 ��ʼ���ɹ�
* - ���� ʧ��
*/
	LIB_EXPORT int tms_init();

/**
* @brief    ���������غõ��ļ�
* @details   ���������غõ��ļ�
* @param[const char *]  file    �����������ļ���
* @return    �������
* - 0 �ɹ�
* - ����ʧ��
*/
	LIB_EXPORT int tms_update(const char* file);
	LIB_EXPORT int tms_update_app2();

	/*************************************************************************************
	Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
	Author:lxz
	Functions:TMS upgrade
	Input : file��Upgrade file name
			flag��1 upgrade application and data, 0 upgrade data only

	Output : Nothing
	return: 0,     success
			Other, failure
	*************************************************************************************/

	LIB_EXPORT int tms_update_ex(const char* file, int flag);

/**
* @enum eTMSACTION
* @brief tms�������ػ�����������Ķ�����־
*/
	typedef enum eTMSACTION {
		TA_DOWNLOADING,	//׼��������������
		TA_UPDATEING,	//׼���������غõĳ���
	}TMSACTION;

	typedef enum
	{
		TMS_NET_FAIL = -100,				//�����쳣
		TMS_SOCKET_FAIL,			//�����������쳣
		TMS_LOGIN_FAIL,				//��¼ʧ��
		TMS_LOGIN_FORMAT_ERROR,		//���ص�¼������
		TMS_DEVICE_ERROR,			//�豸���Ϸ�
		TMS_MD5_ERROR,				//������md5У��ʧ��
		TMS_SIG_ERROR,				//������У��ʧ��
		TMS_LOW_BATTERY,			//�豸�͵���
		TMS_UPDATE_FAIL,			//����ʧ��
		TMS_CONNECT_SERVER_FAIL,//
		TMS_SEND_SERVER_FAIL,
		TMS_RECV_SERVER_FAIL,
		TMS_UPDATE_SUCCESS = 0,     //tms�����ɹ�
		TMS_UPDATE_NO_TRIGERR,      //��TMS��������	
		TMS_CONNECT_SERVER,//���ӷ�����
		TMS_SEND_SERVER,//���ͷ�������Ϣ
		TMS_RECV_SERVER,//���շ�������Ϣ
		TMS_UPDATING,//TMS������
		TMS_FINISH = 999
	}enum_tms_state;



	//����  0 ȡ����Ӧ����  1 �����Ӧ����
	typedef int (*tms_action)(TMSACTION type);

	//�������
	typedef int (*_tms_result_proc)(enum_tms_state type);


/**
* @brief   ���tms�¼�����ص�
* @param[tms_action] proc   �ص��¼�
* @return   
* - 0    ��ӳɹ�
* - ���� ���ʧ��
*/
	LIB_EXPORT int tms_set_actionproc(tms_action proc);

	//endtime �봦���������ʱ�������˳�
	typedef int (*_tms_proc)(int endtime);

/**
* @brief   ����ʹ��tms�̺߳�̨������
* @param[_tms_proc]  proc    tms��̨������庯��
* @return  NULL
*/
	LIB_EXPORT void	tms_setproc(_tms_proc proc);

/**
* @brief  ��������
*/
	LIB_EXPORT int tms_init2();
/**
* @brief   tms������
* @param[ const char *]  file   �ļ�
* @return  �����
* - 0  �ɹ�
* - -1 ʧ��
*/
	LIB_EXPORT int tms_check_update(const char* file);
/**
* @brief    tms����
* @details   tms�����¼�������������Ͱ������ջذ��������ж��Ƿ���Ҫ��������
* @return    �����
* -   0  ����Ҫ����
* -   1  ��Ҫ����������������
* -  -1  δ�ܽ��յ����������İ�������Ҫ����
* -  -2  �յ��İ���ʽ����
* -  -3  �Ƿ��豸
*/
	LIB_EXPORT int tms_heart();
/**
* @brief   �����������  �к�̨��ʹ���߳� �޺�̨��ʹ��tms_heart
* @return  NULL
*/
	LIB_EXPORT int tms_heart2();

/**
* @brief  TMS��������
* @return  1 ���������ң� ����ֵ δ����
*/
	LIB_EXPORT int tms_isupdate();


	LIB_EXPORT void enable_tms_update(int flag);


	LIB_EXPORT void tdownload_proc();


#ifdef __cplusplus
}
#endif	