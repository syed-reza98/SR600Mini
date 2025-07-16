/**
 * @file lv_png.h
 *
 */

#ifndef LV_PNG_H
#define LV_PNG_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
#define PNG_MAX_NUM		  200//PNGͼƬ���ͬʱ��������

//PNG�����ʽ
typedef struct {
	uint8_t* img_data;//ͼ������
	uint32_t Width;//ͼƬ�Ŀ��
	uint32_t Height;//ͼƬ�ĸ߶�
    int8_t file_name[60];//�ļ������59�ֽ�
}PNG_Decode_Struct;

//extern PNG_Decode_Struct  PNG_DS[PNG_MAX_NUM];

/**
 * Register the PNG decoder functions in LittlevGL
 */
void lv_png_init(void);
//��ǰ����pngͼƬ
char lv_load_png_file(const char* filename);
char lv_free_png_file(const char* filename);
/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_PNG_H*/
