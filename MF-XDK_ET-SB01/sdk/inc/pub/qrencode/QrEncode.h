/************************************************************************/
// Filename: QrEncode.h

// Describe����Ҫ����CQR_Encode��Ĺ��ܼ���ض���
/************************************************************************/

#pragma once
#include "pub/pub.h"

#ifdef __cplusplus
extern "C"{
#endif 

#include "QrGlobalVar.h"

/************************************************************************/
#define		HorizontalDPI	600
#define		VerticalDPI		600

//Qr����Ĳ���
typedef PACKED struct QRParam
{
	int nVersion;		//�汾��:1~40
	int nLevel;			//������:0-��,1-��,2-�ϸ�,3-���,
	int moudleWidth;	//ģ���ȣ���λ�����أ�
} Param_QR_INFO; 

LIB_EXPORT int mfGeneCodePic(char * chData, int iLen, Param_QR_INFO *QRParam , char * bitmap);
LIB_EXPORT void mfSetQrSize(int size);

#ifdef __cplusplus
}
#endif 

