/**
 * @file mfsdk_lvgl.h
 * @author TIL
 * @brief
 * @date 2023-11-26
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_LVGL_H__
#define __MFSDK_LVGL_H__
#include "mfsdk_define.h"
#include "lvgl/lvgl.h"
#include "libapi_lvgl.h"

typedef status_bar_cb MfSdkStatusBarCb;

typedef enum
{
    MFSDK_LVGL_OPER_SUCC = 0,
    MFSDK_LVGL_OPER_FAIL = -1,
    MFSDK_LVGL_OPER_CANCEL = -2,
    MFSDK_LVGL_OPER_TIMEOUT = -3,
    MFSDK_LVGL_OPER_BACKSPACE = -4,
} MfSdkLvglOper_E;

typedef enum
{
    MFSDK_LVGL_FREETYPE_FONT = 3,
    MFSDK_LVGL_LARGE_FONT = 2,
    MFSDK_LVGL_NORMAL_FONT = 1,
    MFSDK_LVGL_SMALL_FONT = 0,
} MfSdkLvglFont_E;

typedef enum
{
    MFSDK_LVGL_ALIGN_RIGHT = 2,
    MFSDK_LVGL_ALIGN_CENTER = 1,
    MFSDK_LVGL_ALIGN_LEFT = 0,
} MfSdkLvglAlign_E;

typedef enum
{   
    MFSDK_LVGL_INPUT_MODE_NUM = 0,
    MFSDK_LVGL_INPUT_MODE_TEXT = 1,
    MFSDK_LVGL_INPUT_MODE_IP = 2,
    MFSDK_LVGL_INPUT_MODE_PWD = 3,
    MFSDK_LVGL_INPUT_MODE_AMOUNT = 4,
} MfSdkLvglInput_E;
typedef enum
{
	MFSDK_LVGL_INPUTTEXT_IMAGE = 0,
	
}MfSdkLvglImageType_E;


typedef enum {
	MFSDK_LVGL_SB_320_240_BLACK = 0, //320*240
	MFSDK_LVGL_SB_320_240_WHITE = 1, //320*240
	MFSDK_LVGL_SB_480_800_BLACK = 4, //480*800
	MFSDK_LVGL_SB_480_800_WHITE = 5, //480*800
}MfSdkLvglStatusBar_E;

typedef t_menu_text_param MfSdkLvglMenuText_T;
typedef t_menu_icon_param MfSdkLvglMenuIcon_T;
typedef t_lvgl_button MfSdkLvglButton_T;
typedef t_lvgl_buttons MfSdkLvglButtons_T;
typedef t_button_param MfSdkButtonIcon_T;
typedef t_net_menu_param MfSdkLvglNetMenu_T;

typedef enum
{
	MFSDK_LVGL_NETMENU_EXIT_TIMEOUT = -1,
	MFSDK_LVGL_NETMENU_EXIT_CANCEL = 0,
	MFSDK_LVGL_NETMENU_NETINFO_EXIT,
	MFSDK_LVGL_NETMENU_NETSET1_EXIT_TIMEOVER,
	MFSDK_LVGL_NETMENU_NETSET1_EXIT,
	MFSDK_LVGL_NETMENU_NET4G_ALREADY_EXIT,
	MFSDK_LVGL_NETMENU_NET4G_FAILED_NO_SIM,
	MFSDK_LVGL_NETMENU_NET4G_FAILED_EXIT_TIMEOVER,
	MFSDK_LVGL_NETMENU_NET4G_SUCCEED_EXIT,
	MFSDK_LVGL_NETMENU_NETWIFI_FAILED_EXIT_TIMEOVER,
	MFSDK_LVGL_NETMENU_NETWIFI_SUCCEED_EXIT,
	MFSDK_LVGL_NETMENU_NETADDWIFI_EXIT_TIMEOVER,
	MFSDK_LVGL_NETMENU_NETADDWIFI_EXIT,
	MFSDK_LVGL_NETMENU_NETWIFISAVE_EXIT_TIMEOVER,
	MFSDK_LVGL_NETMENU_NETWIFISAVE_EXIT,
	MFSDK_LVGL_NETMENU_NETWIFI_SWITCH_FAILED_EXIT_TIMEOVER,  
	MFSDK_LVGL_NETMENU_NETWIFI_SWITCH_FAILED_EXIT,
	MFSDK_LVGL_NETMENU_NETWIFISCANING_EXIT_TIMEOVER,    
	MFSDK_LVGL_NETMENU_NETWIFISCANING_EXIT,              
	MFSDK_LVGL_NETMENU_NETWIFILIST_EXIT_TIMEOVER,
	MFSDK_LVGL_NETMENU_NETWIFILIST_EXIT,
	MFSDK_LVGL_NETMENU_NETWIFIINPUTPASSWORD_EXIT_TIMEOVER,
	MFSDK_LVGL_NETMENU_NETWIFIINPUTPASSWORD_EXIT,
	MFSDK_LVGL_NETMENU_NETWIFICONNECT_SUCCEED_EXIT,
	MFSDK_LVGL_NETMENU_NETWIFICONNECT_FAILED_EXIT,
}MfSdkLvglNetMenuExitValue_E;


/**
 * @brief 
 * @param[in] int key  callback key value
 */
typedef void (*MfSdkLvglNetKeyProcCb)(int key);

typedef void (*MfSdkLvglImageCb)(lv_obj_t*page,int Type);

typedef int (*MfSdkMenuIconCb)(int pressKeyValue , int selectIndex);

typedef int (*MfSdkDispResultCb)(int dispTimeout);

/**
* @param[in] s32 ret  ref. MfSdkLvglNetMenuExitValue_E
* link API MfSdkLvglNetMenuSetExitCallback
*/
typedef void (*MfSdkLvglNetMenuExitCallback)(s32 ret);

/**
 * @brief lvgl module initialization
 *
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglInit(void);

/**
 * @brief Get the modal lvgl page parent object
 *
 * @return  0, failure
 * @return	Other, lvgl page parent object
 */
LIB_EXPORT lv_obj_t* MfSdkLvglGetPageBody();

/**
 * @brief lvgl module exit
 *
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglExit(void);

/**
 * @brief clear screen
 *
 */
LIB_EXPORT void MfSdkLvglCls(void);

/**
 * @brief enable status bar
 *
 * @param[in] status, status(0 - off, 1 - on)
 */
LIB_EXPORT void MfSdkLvglClsEnableStatusBar(s32 status);

/**
 * @brief enable default status bar icons
 *
 * @param[in] status, status(0 - off, 1 - on)
 */
LIB_EXPORT void MfSdkLvglEnableDefaultStatusBarIcons(s32 status);

/**
 * @brief clear specified line
 *
 * @param[in] lineNo line number(starting from 0)
 */
LIB_EXPORT void MfSdkLvglClearLine(s32 lineNo);

/**
 * @brief get status bar height
 * 
 * @return	height
 */
LIB_EXPORT s32 MfSdkLvglGetStatusBarHeight();

/**
 * @brief create buttons
 *
 * @param[in] x x-shift
 * @param[in] y y-shift
 * @param[in] items create buttons parameter.If items->id < 0 is not clickable
 * @param[in] size items size
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglCreateButtons(MfSdkLvglButtons_T items[], s32 size);
/**
 * @brief clear screen without line 0
 *
 */
LIB_EXPORT void MfSdkLvglClearAll(void);

/**
 * @brief waiting for key pressed
 *
 * @param[in] timeout timeout(second)
 * @return  >=0, key value or button id
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglWaitKey(s32 timeout);
/**
 * @brief waiting for key pressed
 *
 * @param[in] timeout timeout(ms)
 * @return  >=0, key value or button id
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglWaitKeyMs(s32 timeoutMs);

/**
 * @brief Clean the key flag bit before getting the key loop
 *
 */
LIB_EXPORT void MfSdkLvglClrKeyFlag();
/**
 * @brief check if key pressed
 *
 * @return  1, key pressed
 * @return	0, no key pressed
 */
LIB_EXPORT MFSDKBOOL MfSdkLvglCheckKey(void);

/**
 * @brief get key value
 *
 * @return  >=0, Ref. MfSdkKbKeyCode_E
 * @return	Other, failure;
 */
LIB_EXPORT s32 MfSdkLvglGetKey(void);

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
LIB_EXPORT s32 MfSdkLvglDispTextCoord(s32 x, s32 y, s32 font, s8* text);

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
LIB_EXPORT s32 MfSdkLvglDispTextLine(s32 lineNo, s32 font, const s8* text, s32 align, u8 reverse);

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
LIB_EXPORT s32 MfSdkLvglDispMenuText(s32 font, s8* title, MfSdkLvglMenuText_T menus[], s32 size, s32 select, s32 timeout);

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
LIB_EXPORT s32 MfSdkLvglDispMenuIcon(s32 font, s8* title, MfSdkLvglMenuIcon_T menus[], s32 size, s32 timeout);

/**
 * @brief disp buttons
 *
 * @param[in] lineNo line number(starting from 0)
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] buttons button list
 * @param[in] size list size
 * @param[in] timeout timeout(second)
 * @return  >=0, button id
 * @return	Other, failure;
 */
LIB_EXPORT s32 MfSdkLvglDispButton(s32 lineNo, s32 font, MfSdkButtonIcon_T buttons[], s32 size, s32 timeout);

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
LIB_EXPORT s32 MfSdkLvglMessageBox(s32 width, s32 height, s8* msg, s8* btnLeft, s8* btnRight, s32 timeout);

/**
 * @brief disp text list
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] items text list
 * @param[in] size list size
 * @param[in] timeout timeout(second);
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispList(s32 font, s8* title, s8* items[], s32 size, s32 timeout);

/**
 * @brief disp text rollpage
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] buf text buffer
 * @param[in] timeout timeout(second);
 * @return  0, success
 * @return	 Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispRollpage(s32 font, s8* title, s8* buf, s32 timeout);

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
LIB_EXPORT s32 MfSdkLvglInputText(s32 font, s8* title, s8* msg, s8* text, s32 mode, s32 min, s32 max, s32 timeout);
LIB_EXPORT s32 MfSdkLvglInputTextEx(s32 font, s8* title, s8* msg, s8* text, s32 mode, s32 min, s32 max, s32 timeout);

/**
 * @brief disp progress bar
 *
 * @param[in] width width
 * @param[in] height height
 * @param[in] min minimum value
 * @param[in] max maximum value
 * @param[out] bar progress bar handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispBar(s32 width, s32 height, s32 min, s32 max, void** bar);

/**
 * @brief update progress bar
 *
 * @param[in] bar progress bar handle
 * @param[in] value current value
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglUpdateBar(void* bar, s32 value);

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
LIB_EXPORT s32 MfSdkLvglDispLed(s32 x, s32 y, s32 width, s32 height);

/**
 * @brief update led state
 *
 * @param[in] index led index (0 - red, 1 - blue, 2 - green, 3 - yellow)
 * @param[in] state state ( 0 - off, 1 - on)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglUpdateLed(s32 index, s32 state);

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
LIB_EXPORT s32 MfSdkLvglShowQrcode(s32 font, s8* title, s8* qrcode, s32 width, s32 align);

/**
 * @brief show qrcode
 *
 * @param[in] qrcode qrcode data
 * @param[in] qrcodeLen qrcode data length
 * @param[in] width width
 * @param[in] align align type(0 - left, 1 - center, 2 - right)
 * @param[in] y Y offset
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglShowQrcodeEx(s8* qrcode, s32 qrcodeLen, s32 width, s32 align, s32 y);
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
LIB_EXPORT s32 MfSdkLvglShowImage(s32 x, s32 y, s8* fileName, s8* text, s32 id);

/**
 * @brief show image button
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] align align type(0 - left, 1 - center, 2 - right)
 * @param[in] fileName image file name
 * @param[in] text button text
 * @param[in] id button id( >=0 image with click event, <0 no click events)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglShowImageEx(s32 x, s32 y, s32 align, s8* fileName, s8* text, s32 id);
/**
 * @brief show image buff
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] w width
 * @param[in] h height
 * @param[in] buf image buffer
 * @param[in] text button text
 * @param[in] id button id( >=0 image with click event, <0 no click events)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglShowImagebuff(s32 x, s32 y, s32 w, s32 h, s8* buf, s8* text, s32 id);

/**
 * @brief show except for the status bar the screen buff
 *
 * @param[in] buf Screen buff(rgba 32-bit)
 * @return  0, success
 * @return	Other, failure
 * @details MF960 have status bar,screen size is 480*(800-30),buff size is 480*(800-30)*4
 * @details MF960 have not status bar,screen size is 480*(800),buff size is 480*(800)*4
 */
LIB_EXPORT s32 MfSdkLvglShowScreenCanves(s8* buf);
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
LIB_EXPORT s32 MfSdkLvglDrawLine(s32 x, s32 y, s32 w, s32 h);

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
LIB_EXPORT s32 MfSdkLvglDrawBox(s32 x, s32 y, s32 w, s32 h);

/**
 * @brief electronic signature
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] factor factor
 * @param[in] timeout timeout(second)
 * @param[out] imgData image data
 * @param[out] dataSize image data size
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglEsign(s32 font, s8* title, s8* factor, u8 ** imgData, s32* dataSize, s32 timeout);

/**
 * @brief Scan the QR code, barcode
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[out] data code data
 * @param[in] datasize data size
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglScan(s32 font, s8* title, s8* data, s32 datasize, s32 timeout);

/**
 * @brief display dialog
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
LIB_EXPORT s32 MfSdkLvglDispDialog(s32 font, s8* title, s8* msg, s32 timeout, u8 isCountDown, void** handle);
/**
 * @brief display dialog(Title styles different)
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
LIB_EXPORT s32 MfSdkLvglDispDialogEx(s32 font, s8* title, s8* msg, s32 timeout, u8 isCountDown, void** handle);

/**
 * @brief Set title color style 
 *
 * @param[in] bgColor background color
 * @param[in] textColor text color
 */
LIB_EXPORT void MfSdkLvglSetTitleColor(int bgColor, int textColor);
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
LIB_EXPORT s32 MfSdkLvglUpdateDialog(void* handle, s8* title, s8* msg, s32 timeout, u8 isCountDown);

/**
 * @brief close dialog
 *
 * @param[in] handle dialog handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglCloseDialog(void* handle);

/**
 * @brief display text rollpage
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title
 * @param[in] buf text buffer
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispRollpageEx(s32 font, s8* title, s8* buf, s32 timeout);

/**
 * @brief display multiple choice
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
LIB_EXPORT s32 MfSdkLvglDispMultipleChoice(s32 font,const s8* title, MfSdkLvglMenuText_T* choiseArry, s32 choiseSize, s32 select, s32 timeout);

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
LIB_EXPORT s32 MfSdkLvglDispSetSlider(s8* title, s32 width, s32 height, s32 minLevel, s32 maxLevel, s32 startValue, s32 timeout);

/**
 * @brief display set result
 *
 * @param[in] result 1, success; 0, failure
 * @param[in] msg message
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispSetResult(s32 result, s8* msg, s32 timeout);

/**
 * @brief display set result
 *
 * @param[in] result 1, success; 0, failure
 * @param[in] msg message
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispSetResultCallback(s32 result, s8* msg, s32 timeout, MfSdkDispResultCb mfSdkDispResultCb);

/**
 * @brief input pin
 *
 * @param[in] title title
 * @param[in] msg message
 * @param[in] amount amount
 * @param[in] cardID cardID
 * @param[out] pin input pin
 * @param[in] timeout timeout(second)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglInputPin(s8* title, s8* msg, s8* amount, s8* cardID, s8* pin, s32 timeout);

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
LIB_EXPORT s32 MfSdkLvglDispAnimation(s32 imgSize, s8** imgName, s8* msg, s32 interval, void** handle);

/**
 * @brief display animation
 *
 * @param[in] x x
 * @param[in] y y
 * @param[in] align align type(0 - left, 1 - center, 2 - right)
 * @param[in] imgSize images size
 * @param[in] imgName images name
 * @param[in] interval image display interval
 * @param[out] handle animation handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispAnimationEx(s32 x, s32 y, s32 align, s32 imgSize, s8** imgName, s32 interval, void** handle);
/**
 * @brief close animation
 *
 * @param[in] handle animation handle
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglCloseAnimation(void* handle);

/**
 * @brief set callback function for status bar task
 *
 * @param[in] task_cb callback function for status bar task(The loop call callback once a second)
 */
LIB_EXPORT void MfSdkLvglCreateStatusBarTask(MfSdkStatusBarCb task_cb);

/**
 * @brief display status bar icon()
 *
 * @param[in] x x-coordinate
 * @param[in] iconname Icon name
 * @param[in] group icon group(max 5 groups, 0,1,2,3,4)
 * @return  0, success
 * @return	Other, failure
 * @details This API can only be in MfSdkLvglCreateStatusBarTask callback function calls
 */
LIB_EXPORT s32 MfSdkLvglSetStatusBarIcon(s32 x, s8* iconname, s32 group);

/**
 * @brief Quick display status bar icon
 *
 * @param[in] x x-coordinate
 * @param[in] iconname Icon name
 * @param[in] group icon group(max 5 groups, 0,1,2,3,4)
 * @return  0, success
 * @return	Other, failure
 * @details This API is not in MfSdkLvglCreateStatusBarTask callback function calls
 *
 */
LIB_EXPORT s32 MfSdkLvglQuickSetStatusBarIcon(s32 x, s8* iconname, s32 group);
/**
 * @brief set status bar config
 *
 * @param[in] height status bar height
 * @param[in] bgColor status bar background color
 *
 */
LIB_EXPORT void MfSdkLvglSetStatusBar(s32 height, lv_color_t bgColor);

/**
 * @brief Get the LVGL refresh screen buff
 * 
 * @param[in] getUI The callback function for refreshing the screen
 */
LIB_EXPORT void MfSdkLvglGetUiBuff(void (*getUI)(u8 *buf, s32 len));

/**
 * @brief Load png image
 * 
 * @param[in] filename png image path
 * @return  For details, see MfSdkLvglOper_E.
 */
LIB_EXPORT s8 MfSdkLvglLoadPng(const s8 *filename);

/**
 * @brief free png image
 * 
 * @param[in] filename png image path
 * @return  For details, see MfSdkLvglOper_E.
 */
LIB_EXPORT s8 MfSdkLvglFreePng(const s8 *filename);
/**
 * @brief  init LVGL group
 * 
 */
LIB_EXPORT void MfSdkLvglGuiInit(void);
/**
 * @brief obj add to group and set focus obj
 * 
 * @param[in] lv_obj_t* obj
 */
LIB_EXPORT void MfSdkLvglGroupSet(lv_obj_t* obj);

/**
 * @brief Display text.The mf.ttf file must be in the /mf/app path to display text
 * 
 * @param[in] x x-coordinate
 * @param[in] y y-coordinate
 * @param[in] text text.Text must be in utf-8 format
 * @param[in] align align type(0 - left, 1 - center, 2 - right)
 * @param[in] size Font size(0-6)
 * @param[in] fontColor Font color. white=0xffffff
 * @return  For details, see MfSdkLvglOper_E.
 */
LIB_EXPORT s32 MfSdkLvglDispFreetypeText(s32 x, s32 y, s8* text, s32 align, s32 size, s32 fontColor);

/**
 * @brief Network setting Menu
 * 
 * @param[in] lv_obj_t* obj, const s8* font
 */
LIB_EXPORT void MfSdkLvglNetMenu(lv_obj_t* obj, char* font);

/**
 * @brief Network setting Menu with params
 * 
 * @param[in] MfSdkLvglNetMenu_T *netmenu
 */
LIB_EXPORT void MfSdkLvglNetMenuSetting(MfSdkLvglNetMenu_T *netmenu);

/**
 * @brief Network setting Menu key callback func
 * 
 * @param[in] MfSdkLvglNetKeyProcCb pFuncCb
 */
LIB_EXPORT s32 MfSdkLvglNetKeyCbProc(MfSdkLvglNetKeyProcCb pFuncCb);
/**
 * @brief Exit the blocked page (call asynchronously)
 * 
 */
LIB_EXPORT void MfSdkLvglExitWait();
LIB_EXPORT void MfSdkLvglShowImageCallBack(MfSdkLvglImageCb pFuncCb);

/**
 * @brief add font , support add 10 set of font
 * 
 * @param[in] name: font name
 * @param[in] font: font
 */
LIB_EXPORT void MfSdkLvglAddFont(char *name, lv_font_t font);
/**
 * @brief set current font
 * 
 * @param[in] name: font name set to MfSdkLvglAddFont. if want to back to system font . set the name as "", eg:MfSdkLvglSetCurrentFont("");
 * 
 */
LIB_EXPORT void MfSdkLvglSetCurrentFont(char *name);

/**
 * @brief set freetype font
 * 
 * @param[in] index: freetype font index;
 * 
 */
LIB_EXPORT void MfSdkLvglSetFreetypeFont(int index);

/**
 * @brief Compatible with MF70A6
 * 
 * @param[in] MfSdkLvglStatusBar_E params
 * @return lv_obj_t* status bar point
 */
LIB_EXPORT void *MfSdkLvglCreateStatusBar(MfSdkLvglStatusBar_E params);

/**
 * @brief disp image menus
 *
 * @param[in] font font(0 - small,1 - normal,2 - big)
 * @param[in] title title;
 * @param[in] menus menu list
 * @param[in] size list size
 * @param[in] timeoutMs (unit:ms)
  * @param[in] mfSdkMenuIconCb
 * @return  >=0, menu id
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkLvglDispMenuIconCallback(s32 font, s8* title, MfSdkLvglMenuIcon_T menus[], s32 size, s32 timeoutMs ,MfSdkMenuIconCb mfSdkMenuIconCb);

/**
 * @brief Only for SR600mini Netmenu exit callback
 * 
 * @param[in] MfSdkLvglNetMenuExitCallback *pFunCb  eixt value ref. MfSdkLvglNetMenuExitValue_E
 */
LIB_EXPORT void MfSdkLvglNetMenuSetExitCallback(MfSdkLvglNetMenuExitCallback pFunCb);

/**
 * @brief Optimize page sliding effect (Only for M919)
 * @param[in] mod 1:Enable slide mode; 0: Disenable slide mode;
*/
LIB_EXPORT void MfSdkLvglSetPageSlideMode(s32 mod);
#endif /* __MFSDK_LVGL_H__ */

