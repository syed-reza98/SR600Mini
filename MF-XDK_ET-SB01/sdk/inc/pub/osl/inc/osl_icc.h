#pragma once

#include "driver/mf_icc.h"
#include "pub/pub.h"

typedef enum
{
	DEV_ICC_ICCID = ICC_SOCKET1,  //������
	DEV_ICC_PSAM1 = ICC_SOCKET2,  //pasm1
	DEV_ICC_PSAM2 = ICC_SOCKET3	  //pasm2
}ICC_TYPE;


/**
* iccid,psam1,psam2��ȡ�ӿ�
* @param type[IN]: �μ�����
* @param psaIcc[OUT]: ��ȡ�������ݻ�����
* @param return: 
* -1: �豸��ʧ��
* -2: ����λ���ʧ��
* -3: �ϵ�ʧ��
* -4: sim�����ļ�ѡ�����
* -5: ��ȡ���ݴ���
*/
LIB_EXPORT int osl_ReadIcc(ICC_TYPE type, char *pszIcc);	

