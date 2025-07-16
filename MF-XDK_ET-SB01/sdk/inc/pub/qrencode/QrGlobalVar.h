/************************************************************************
* Filename: GlobalVar.h
* Copyright(c) 2009-20XX, mf, All Rights Reserved
* Author��  dzhanjie@163.com  
* Created�� 2012/08/20
* Describe��ȫ�ֱ���                                         
************************************************************************/

#pragma once

/************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif 
/************************************************************************/
#ifndef NULL
#define NULL	0
#endif

/*������*/
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

 /*��������*/
#define QR_MODE_NUMERAL		0
#define QR_MODE_ALPHABET	1
#define QR_MODE_8BIT		2
#define QR_MODE_HANZI		3

 /*�汾��*/
#define QR_VRESION_S	0  /*1 ~ 9*/
#define QR_VRESION_M	1  /*10 ~ 26*/
#define QR_VRESION_L	2  /*27 ~ 40*/

#define MAX_ALLCODEWORD	 404  /*�����������*/
#define MAX_DATACODEWORD 324  /*�������������(40-L)*/
#define MAX_CODEBLOCK	 200  /*������ֿ���*/
#define MAX_MODULESIZE	 max_module_size  /*ÿ�����ģ����*/

enum
{
	QRErrLevel_L = 0,
	QRErrLevel_M = 1,
	QRErrLevel_Q = 2,
	QRErrLevel_H = 3
}; //QR������


/*������*/
enum
{
	UT_TYPE_1D		= 0xC1,
	UT_TYPE_2D		= 0xC2,
	UT_TYPE_OCR		= 0xC3
};

//��ά������
enum
{
	POS_PDF417			= 0,
	POS_QR              = 1,
	POS_Aztec           = 2,
	POS_DataMatrix      = 3,
};

 /*QR��Ե*/
#define QR_MARGIN	4 

//typedef unsigned char unsigned char;
//typedef unsigned short unsigned short;
////typedef unsigned char * LPBYTE;
//typedef unsigned long unsigned long;
//typedef long long;

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define PACKED
/************************************************************************/
typedef PACKED struct tagRS_BLOCKINFO
{
	int ncRSBlock;		 /*�������*/
	int ncAllCodeWord;	 /*��������*/
	int ncDataCodeWord;	 /*����������*/
	
} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/***********************************
 *QR��Ϣ�ṹ
 **********************************/
typedef struct tagQR_VERSIONINFO
{
	int nVersionNo;	    /*�汾��(1~40)*/
	int ncAllCodeWord;  /*��������*/
	int ncDataCodeWord[4];	/*�ĸ������������������(0 = L, 1 = M, 2 = Q, 3 = H)*/ 
	
	int ncAlignPoint;	 /*У��ͼ����*/
	int nAlignPoint[6];	 /*У��ͼ������ģ�����������*/
	
	RS_BLOCKINFO RS_BlockInfo1[4];  /*RS����Ϣ(1)*/
	RS_BLOCKINFO RS_BlockInfo2[4];  /*RS����Ϣ(2)*/
	
} QR_VERSIONINFO, *LPQR_VERSIONINFO;


/************************************************************************/
#ifdef __cplusplus
}
#endif 


