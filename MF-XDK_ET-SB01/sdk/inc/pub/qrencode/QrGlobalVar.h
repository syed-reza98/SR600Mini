/************************************************************************
* Filename: GlobalVar.h
* Copyright(c) 2009-20XX, mf, All Rights Reserved
* Author：  dzhanjie@163.com  
* Created： 2012/08/20
* Describe：全局变量                                         
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

/*纠错级别*/
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

 /*数据类型*/
#define QR_MODE_NUMERAL		0
#define QR_MODE_ALPHABET	1
#define QR_MODE_8BIT		2
#define QR_MODE_HANZI		3

 /*版本号*/
#define QR_VRESION_S	0  /*1 ~ 9*/
#define QR_VRESION_M	1  /*10 ~ 26*/
#define QR_VRESION_L	2  /*27 ~ 40*/

#define MAX_ALLCODEWORD	 404  /*最大总码字数*/
#define MAX_DATACODEWORD 324  /*最大数据码字数(40-L)*/
#define MAX_CODEBLOCK	 200  /*最大码字块数*/
#define MAX_MODULESIZE	 max_module_size  /*每边最大模块数*/

enum
{
	QRErrLevel_L = 0,
	QRErrLevel_M = 1,
	QRErrLevel_Q = 2,
	QRErrLevel_H = 3
}; //QR纠错级别


/*大类型*/
enum
{
	UT_TYPE_1D		= 0xC1,
	UT_TYPE_2D		= 0xC2,
	UT_TYPE_OCR		= 0xC3
};

//二维码类型
enum
{
	POS_PDF417			= 0,
	POS_QR              = 1,
	POS_Aztec           = 2,
	POS_DataMatrix      = 3,
};

 /*QR边缘*/
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
	int ncRSBlock;		 /*纠错块数*/
	int ncAllCodeWord;	 /*总码字数*/
	int ncDataCodeWord;	 /*数据码字数*/
	
} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/***********************************
 *QR信息结构
 **********************************/
typedef struct tagQR_VERSIONINFO
{
	int nVersionNo;	    /*版本号(1~40)*/
	int ncAllCodeWord;  /*总码字数*/
	int ncDataCodeWord[4];	/*四个纠错级别的数据码字数(0 = L, 1 = M, 2 = Q, 3 = H)*/ 
	
	int ncAlignPoint;	 /*校正图形数*/
	int nAlignPoint[6];	 /*校正图形中心模块的行列坐标*/
	
	RS_BLOCKINFO RS_BlockInfo1[4];  /*RS块信息(1)*/
	RS_BLOCKINFO RS_BlockInfo2[4];  /*RS块信息(2)*/
	
} QR_VERSIONINFO, *LPQR_VERSIONINFO;


/************************************************************************/
#ifdef __cplusplus
}
#endif 


