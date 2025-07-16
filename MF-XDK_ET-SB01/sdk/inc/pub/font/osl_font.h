/*! \file osl_font.h
	\brief ϵͳ�ֿ�
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "pub\pub.h"

//english font
#define	FONT_COURIER  		0
#define FONT_FIXEDSYS		1
#define	FONT_SANSSERIF		2
#define	FONT_SYSTEM			3
#define	FONT_TERMINAL		4
#define FONT_VGAROM			5
#define FONT_CUSTOM_16			6
#define FONT_CUSTOM_24			7
#define FONT_CUSTOM_32			8
#define FONT_EN_MAX			9

//chinese font
#define FONT_HZGBX12		0
#define FONT_HZGBX16		1
#define FONT_HZGBX24		2
#define FONT_HZGBX32		3


#define FONT_CN_MAX			4



typedef struct
{
    const char*     name;           /* font name */
    char            max_width;      /* max width in pixels */
    char            ave_width;      /* average width in pixels */
    int             height;         /* height in pixels */
    int             descent;        /* pixels below the base line */
    unsigned char   first_char;     /* first character in this font */
    unsigned char   last_char;      /* last character in this font */
    unsigned char   def_char;       /* default character in this font */
    const unsigned short* offset;   /* character glyph offsets into bitmap data or 0 */
    const unsigned char*  width;    /* character widths or 0 */
    const unsigned char*  bits;     /* 8-bit right-padded bitmap data */
    int             font_size;      /* used by mmap */
} VBFINFO;


/**
* @brief ��ȡӢ���ֿ�ṹ
* @param font_id �ֿ�id
* @return �ֿ�ṹ
*/
LIB_EXPORT VBFINFO * osl_GetFontEn(int font_id);
/**
* @brief ��ȡ�����ֿ�ṹ
* @param font_id �ֿ�id
* @return �ֿ�ṹ
*/
LIB_EXPORT VBFINFO * osl_GetFontCn(int font_id);
/**
* @brief �ֿ��ʼ��
* @param 
* @return 
*/
LIB_EXPORT int osl_Font_init(void);




