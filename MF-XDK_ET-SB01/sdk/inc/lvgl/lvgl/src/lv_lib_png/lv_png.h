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
#define PNG_MAX_NUM		  200//PNG图片最大同时载入数量

//PNG解码格式
typedef struct {
	uint8_t* img_data;//图形数据
	uint32_t Width;//图片的宽度
	uint32_t Height;//图片的高度
    int8_t file_name[60];//文件名称最长59字节
}PNG_Decode_Struct;

//extern PNG_Decode_Struct  PNG_DS[PNG_MAX_NUM];

/**
 * Register the PNG decoder functions in LittlevGL
 */
void lv_png_init(void);
//提前加载png图片
char lv_load_png_file(const char* filename);
char lv_free_png_file(const char* filename);
/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_PNG_H*/
