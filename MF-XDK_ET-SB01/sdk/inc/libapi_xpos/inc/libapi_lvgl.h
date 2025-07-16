
#ifndef _LIBAPI_LVGL_H__
#define _LIBAPI_LVGL_H__

/**
 * @file libapi_lvgl.h
 * @author chenyue (Ronaldo)
 * @brief modal lvgl
 * @date 2023-05-19
 * 
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 * 
 */

#include "lvgl/src/lv_misc/lv_color.h"

typedef void (*status_bar_cb)();

#define LVGL_OPER_SUCC			0
#define LVGL_OPER_FAIL			-1
#define LVGL_OPER_CANCEL		-2
#define LVGL_OPER_TIMEOUT		-3
#define LVGL_OPER_BACKSPACE		-4
#define LVGL_OPER_EXIT			-99

#define LVGL_LARGE_FONT			2
#define LVGL_NORMAL_FONT		1
#define LVGL_SMALL_FONT			0

#define LVGL_ALIGN_RIGHT		2
#define LVGL_ALIGN_CENTER		1
#define LVGL_ALIGN_LEFT			0

#define LVGL_INPUT_MODE_NUM		0
#define LVGL_INPUT_MODE_TEXT	1
#define LVGL_INPUT_MODE_IP		2
#define LVGL_INPUT_MODE_PWD		3
#define LVGL_INPUT_MODE_AMOUNT	4

#define LVGL_HIDDEN_4G_ICON 0x01
#define LVGL_HIDDEN_WIFI_ICON 0x02
#define LVGL_HIDDEN_BATTERY 0x04
#define LVGL_HIDDEN_TIME 0x08

typedef struct {
	int id;			///< menu id
	char* text;		///< menu name
}t_menu_text_param;

typedef struct {
	int id;			///< menu id
	int width;		///< image width
	int height;		///< image height
	char* icon;		///< image file name
	char* text;		///< menu name
}t_menu_icon_param;

typedef struct {
	int id;			///< button id
	int width;		///< button width
	int height;		///< button height
	char* text;		///< button name
}t_button_param;

typedef struct {
	int id;
	int width;
	int height;
	int align;
	int font;
	char* text;
	char* icon;
	lv_color_t bgColor;
	lv_color_t textColor;
}t_lvgl_button;
typedef struct {
	int x;
	int y;
	int id;
	int align;
	char* icon;
}t_lvgl_buttons;
typedef struct {
	lv_obj_t* obj;		///< menu obj
	int height;			///< menu height offset
	char* font;		///< menu font
}t_net_menu_param;
/**
 * @brief lvgl module initialization
 *
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_init(void);

/**
 * @brief Get the modal lvgl page parent object
 *
 * @return  0, failure
 * @return	Other, lvgl page parent object
 */
LIB_EXPORT lv_obj_t* lvgl_get_page_body();

/**
 * @brief lvgl module exit
 *
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_exit(void);

/**
 * @brief clear screen
 *
 */
LIB_EXPORT void lvgl_cls(void);

/**
 * @brief enable status bar
 * 
 * @param[in] status, status(0 - off, 1 - on)
 */
LIB_EXPORT void lvgl_enable_status_bar(int status);

/**
 * @brief enable default status bar icons
 *
 * @param[in] status, status(0 - off, 1 - on)
 */
LIB_EXPORT void lvgl_enable_default_status_bar_icons(int status);

/**
 * @brief clear specified line
 *
 * @param[in] lineNo line number(starting from 0)
 */
LIB_EXPORT void lvgl_clear_line(int lineNo);

/**
 * @brief clear screen without line 0
 *
 */
LIB_EXPORT void lvgl_clear_all(void);

/**
 * @brief waiting for key pressed
 *
 * @param[in] timeout timeout(second)
 * @return  >=0, key value or button id
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_wait_key(int timeout);
LIB_EXPORT void lvgl_clear_key_flag();
LIB_EXPORT int lvgl_wait_key_ms(int timeout);
/**
 * @brief check key pressed
 *
 * @return  1, Yes
 * @return	0, No
 */
LIB_EXPORT int lvgl_check_key(void);

/**
 * @brief get key value
 *
 * @param[in] timeout timeout(second)
 * @return  >=0, key value
 * @return	Other, failure;
 */
LIB_EXPORT int lvgl_get_key(void);

/**
 * @brief disp text by coordinate
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] text text
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_text_coord(int x, int y, int font, char* text);

/**
 * @brief disp text by line number
 *
 * @param[in] lineNo line number(starting from 0)
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] text text
 * @param[in] align align type(0 - left, 1 - center, 2 - right)
 * @param[in] reverse reverse mode(1 - yes, 0 - no)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_text_line(int lineNo, int font, char* text, int align, unsigned char reverse);

/**
 * @brief disp text menus
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] menus menu list
 * @param[in] size list size
 * @param[in] select default menu id
 * @param[in] timeout timeout(second)
 * @return  >=0, menu id
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_menu_text(int font, char* title, t_menu_text_param menus[], int size, int select, int timeout);

/**
 * @brief disp image menus
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title;
 * @param[in] menus menu list
 * @param[in] size list size
 * @param[in] timeout timeout(second)
 * @return  >=0, menu id
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_menu_icon(int font, char *title, t_menu_icon_param menus[], int size, int timeout);

/**
 * @brief disp buttons
 *
 * @param[in] lineNo line number(starting from 0)
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] buttons button list
 * @param[in] size list size
 * @param[in] timeout timeout(second)
 * @return  >=0, button id
 * @return	Other, failure;
 */
LIB_EXPORT int lvgl_disp_button(int lineNo, int font, t_button_param buttons[], int size, int timeout);

/**
 * @brief disp message box
 *
 * @param[in] width width
 * @param[in] height height
 * @param[in] msg message
 * @param[in] btnLeft left button text
 * @param[in] btnRight  right button text
 * @param[in] timeout timeout(second)
 * @return  >=0, button id (0 - left, 1 - right)
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_message_box(int width, int height, char* msg, char* btnLeft, char* btnRight, int timeout);

/**
 * @brief disp text list
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] msg message
 * @param[in] items text list
 * @param[in] size list size
 * @param[in] timeout timeout(second);
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_list(int font, char* title, char* items[], int size, int timeout);

 /**
  * @brief disp text rollpage
  *
  * @param[in] font font(0 - small,1 - normal,2 - big)
  * @param[in] title title
  * @param[in] buf text buf
  * @param[in] timeout timeout(second);
  * @return  0, success
  * @return	 Other, failure
  */
LIB_EXPORT int lvgl_disp_rollpage(int font, char* title, char* buf, int timeout);

/**
 * @brief input text
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] text default text
 * @param[in] mode mode ( 0 - number, 1 - text, 2 - IP, 3 - password, 4 - amount)
 * @param[in] min minimum length
 * @param[in] max maximum length
 * @param[in] timeout timeout(second)
 * @param[out] text text
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_input_text(int font, char* title, char* msg, char* text, int mode, int min, int max, int timeout);
LIB_EXPORT int lvgl_input_text_ex(int font, char* title, char* msg, char* text, int mode, int min, int max, int timeout);

/**
 * @brief disp progress bar
 *
 * @param[in] width width
 * @param[in] height height
 * @param[in] min minimum value
 * @param[in] max maximum value
 * @param[in] timeout timeout(second)
 * @param[out] bar progress bar handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_bar(int width, int height, int min, int max, void** bar);

/**
 * @brief update progress bar
 *
 * @param[in] bar progress bar handle
 * @param[in] value current value
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_update_bar(void* bar, int value);

/**
 * @brief disp led(Create 4 leds,0 - red, 1 - blue, 2 - green, 3 - yellow)
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] width width
 * @param[in] height height
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_led(int x, int y, int width, int height);

/**
 * @brief update led state
 *
 * @param[in] index led index (0 - red, 1 - blue, 2 - green, 3 - yellow)
 * @param[in] state state ( 0 - off, 1 - on)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_update_led(int index, int state);

/**
 * @brief show qrcode
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] qrcode qrcode text
 * @param[in] width width
 * @param[in] align align type(0 - left, 1 - center, 2 - right)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_show_qrcode(int font, char* title, char* qrcode, int width, int align);
LIB_EXPORT int lvgl_show_qrcode_ex(char* qrcode, int qrcodeLen, int width, int align, int y);
/**
 * @brief show image button
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] fileName image file name
 * @param[in] text button text
 * @param[in] id button id( >=0 image with click event, <0 no click events)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_show_image(int x, int y, char* fileName, char* text, int id);
LIB_EXPORT int lvgl_show_image_ex(int x, int y, int align, char* fileName, char* text, int id);
/**
 * @brief show image buff 
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] w width
 * @param[in] h height
 * @param[in] buf image buff
 * @param[in] text button text
 * @param[in] id button id( >=0 image with click event, <0 no click events)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_show_imagebuff(int x, int y, int w, int h, char* buf, char* text, int id);

/**
 * @brief show except for the status bar the screen buff
 *
 * @param[in] buf Screen buff(rgba 32-bit)
 * @return  0, success
 * @return	Other, failure
 * @details MF960 have status bar,screen size is 480*(800-30),buff size is 480*(800-30)*4
 * @details MF960 have not status bar,screen size is 480*(800),buff size is 480*(800)*4
 */
LIB_EXPORT int lvgl_show_screen_canves(char* buf);
/**
 * @brief draw line
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] w width
 * @param[in] h height
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_draw_line(int x, int y, int w, int h);

/**
 * @brief draw box
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] w width
 * @param[in] h height
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_draw_box(int x, int y, int w, int h);

/**
 * @brief electronic signature
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] factor factor
 * @param[out] imgData Signature img data(call lvgl_cls will free imgData)
 * @param[out] dataSize factor
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_esign(int font, char* title, char* factor, unsigned char** imgData, int* dataSize, int timeout);
LIB_EXPORT int lvgl_create_buttons(t_lvgl_buttons items[], int size);
/**
 * @brief Scan the QR code, barcode
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[out] code data
 * @param[in] datasize data size
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_scan(int font, char* title, char* data, int datasize, int timeout);

/**
 * @brief disp dialog
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] msg message
 * @param[in] timeout timeout(second)
 * @param[in] isCountDown countdown mode (1 - Yes, 0 - No)
 * @param[out] handle dialog handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_dialog(int font, char* title, char* msg, int timeout, unsigned char isCountDown, void** handle);
LIB_EXPORT int lvgl_disp_dialog_ex(int font, char* title, char* msg, int timeout, unsigned char isCountDown, void** handle);
LIB_EXPORT void lvgl_set_title_color(int bgColor, int textColor);
/**
 * @brief update dialog
 *
 * @param[in] handle dialog handle
 * @param[in] title title
 * @param[in] msg message
 * @param[in] timeout timeout(second)
 * @param[in] isCountDown countdown mode (1 - Yes, 0 - No)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_update_dialog(void* handle, char* title, char* msg, int timeout, unsigned char isCountDown);

/**
 * @brief close dialog
 *
 * @param[in] handle dialog handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_close_dialog(void* handle);

/**
 * @brief disp text rollpage
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] buf text buf
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_rollpage_ex(int font, char* title, char* buf, int timeout);

/**
 * @brief disp multiple choice
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] choiseArry list
 * @param[in] choiseSize list size
 * @param[in] select default list id
 * @param[in] timeout timeout(second)
 * @return  >=0, list id
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_multiple_choice(int font, char* title, t_menu_text_param* choiseArry, int choiseSize, int select, int timeout);

/**
 * @brief set slider
 *
 * @param[in] title title
 * @param[in] width slider width
 * @param[in] height slider height
 * @param[in] minLevel minimum slider value
 * @param[in] maxLevel maximum slider value
 * @param[in] startValue startValue slider initial value
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_set_slider(char* title, int width, int height, int minLevel, int maxLevel, int startValue, int timeout);

/**
 * @brief display set result
 *
 * @param[in] result 1, success; 0, failure
 * @param[in] msg message
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_set_result(int result, char *msg, int timeout);

/**
 * @brief display set result
 *
 * @param[in] result 1, success; 0, failure
 * @param[in] msg message
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
//LIB_EXPORT int lvgl_disp_set_result_callback(int result, char* msg, int timeout, MfSdkDispResultCb mfSdkDispResultCb);

/**
 * @brief input pin
 *
 * @param[in] title title
 * @param[in] msg message
 * @param[in] amount amount
 * @param[in] cardID cardID
 * @param[out] pin input pin
 * @param[out] figure pin figure
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_input_pin(char* title, char* msg, char* amount, char* cardID, char* pin, int timeout);

/**
 * @brief display animation
 *
 * @param[in] imgSize images size
 * @param[in] imgName images name
 * @param[in] msg message
 * @param[in] interval image display interval
 * @param[out] handle animation handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_animation(int imgSize, char** imgName, char* msg, int interval, void** handle);
LIB_EXPORT int lvgl_disp_animation_ex(int x, int y, int align, int imgSize, char** imgName, int interval, void** handle);
/**
 * @brief display animation
 *
 * @param[in] handle animation handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_close_animation(void* handle);

/**
 * @brief set callback function for status bar task
 *
 * @param[in] task_cb callback function for status bar task(loop)
 */
LIB_EXPORT void lvgl_create_status_bar_task(status_bar_cb task_cb);
LIB_EXPORT int lvgl_quick_set_status_bar_icon(int x, char* iconname, int group);
/**
 * @brief display status bar icon
 *
 * @param[in] x x-coordinate
 * @param[in] iconname Icon name
 * @param[in] group icon group(max 5 groups, 0,1,2,3,4)
 * @return  0, success
 * @return	Other, failure
 * 
 */
LIB_EXPORT int lvgl_set_status_bar_icon(int x, char* iconname, int group);
LIB_EXPORT int lvgl_set_status_bar_text(int x, char* text, int group, char* font);
LIB_EXPORT void lvgl_set_status_bar_hidden_time(int isHidden);
LIB_EXPORT void lvgl_set_status_bar_power_x(int x);
LIB_EXPORT void lvgl_set_status_bar_gprs_x(int x);
LIB_EXPORT void lvgl_set_status_bar_wifi_x(int x);
/**
 * @brief set status bar config
 *
 * @param[in] height status bar height
 * @param[in] bgColor status bar background color
 *
 */
LIB_EXPORT void lvgl_set_status_bar(int height, lv_color_t bgColor);
LIB_EXPORT int lvgl_get_status_bar_height();
LIB_EXPORT int lvgl_disp_text(int x, int y, char* text, int align, int size, int fontColor);
LIB_EXPORT void lvgl_exit_wait();


typedef int (*pFuncMenuIconCb)(int pressKeyValue , int selectIndex);
/**
 * @brief disp image menus
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title;
 * @param[in] menus menu list
 * @param[in] size list size
 * @param[in] timeoutMs timeoutMs(unit:ms)
 * @param[in] menuIconCb menuIconCb
 * @return  >=0, menu id
 * @return	Other, failure
 */
LIB_EXPORT int lvgl_disp_menu_iconA(int font, char *title, t_menu_icon_param menus[], int size, unsigned int timeoutMs, pFuncMenuIconCb menuIconCb);


LIB_EXPORT void* lvgl_create_status_bar();

#endif



