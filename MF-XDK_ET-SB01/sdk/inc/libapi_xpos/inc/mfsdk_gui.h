/**
 * @file mfsdk_gui.h
 * @author CHAR
 * @brief 
 * @date 2023-11-18
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_GUI_H__
#define __MFSDK_GUI_H__
#include "mfsdk_define.h"
#include "libapi_gui.h"

//#define MFSDK_GUI_KEY_CONTROL	KEY_CONTROL	
//#define MFSDK_GUI_KEY_UP		KEY_UP		
//#define MFSDK_GUI_KEY_DOWN		KEY_DOWN		
//#define MFSDK_GUI_KEY_OK		KEY_OK		
//#define MFSDK_GUI_KEY_QUIT		KEY_QUIT		

#define MFSDK_GUI_IME_MODE_T9PY 		GUI_IME_MODE_T9PY					//Allow pinyin input method
#define MFSDK_GUI_IME_MODE_ALPHABET_UP 		GUI_IME_MODE_ALPHABET_UP			//Allow uppercase letters
#define MFSDK_GUI_IME_MODE_ALPHABET_LOW GUI_IME_MODE_ALPHABET_LOW			//Allow lowercase letters	
#define MFSDK_GUI_IME_MODE_NUMBER 		GUI_IME_MODE_NUMBER					//Allow input of numbers
	
#define MFSDK_GUI_LINE_TOP(a) GUI_LINE_TOP(a)
	
#define MFSDK_GUI_GUIFIRST	GUI_GUIFIRST
#define MFSDK_GUI_GUIPAINT	GUI_GUIPAINT
#define MFSDK_GUI_KEYPRESS	GUI_KEYPRESS
#define MFSDK_GUI_SCAN_OK	GUI_SCAN_OK
#define MFSDK_GUI_USR_PROC	GUI_USR_PROC
	
#define MFSDK_GUI_KEY_0		GUI_KEY_0
#define MFSDK_GUI_KEY_1		GUI_KEY_1
#define MFSDK_GUI_KEY_2		GUI_KEY_2
#define MFSDK_GUI_KEY_3		GUI_KEY_3
#define MFSDK_GUI_KEY_4		GUI_KEY_4
#define MFSDK_GUI_KEY_5		GUI_KEY_5
#define MFSDK_GUI_KEY_6		GUI_KEY_6
#define MFSDK_GUI_KEY_7		GUI_KEY_7
#define MFSDK_GUI_KEY_8		GUI_KEY_8
#define MFSDK_GUI_KEY_9		GUI_KEY_9
#define MFSDK_GUI_KEY_STAR 	GUI_KEY_XING     //* ASTERISK
#define MFSDK_GUI_KEY_HASH		GUI_KEY_JING	//#
#define MFSDK_GUI_KEY_CONTROL	GUI_KEY_CONTROL	
#define MFSDK_GUI_KEY_UP		GUI_KEY_UP		
#define MFSDK_GUI_KEY_DOWN		GUI_KEY_DOWN		
#define MFSDK_GUI_KEY_LEFT		GUI_KEY_LEFT		
#define MFSDK_GUI_KEY_RIGHT		GUI_KEY_RIGHT		
#define MFSDK_GUI_KEY_BACKSPACE	GUI_KEY_BACKSPACE	
#define MFSDK_GUI_KEY_OK		GUI_KEY_OK		
#define MFSDK_GUI_KEY_QUIT		GUI_KEY_QUIT		
#define MFSDK_GUI_KEY_F1		GUI_KEY_F1		
#define MFSDK_GUI_KEY_F2		GUI_KEY_F2		
#define MFSDK_GUI_KEY_POWER		GUI_KEY_POWER		
#define MFSDK_GUI_COLOR_BACK	GUI_COLOR_BACK	
#define MFSDK_GUI_COLOR_FORE	GUI_COLOR_FORE	
	
typedef st_gui_rect MfSdkGuiRect_T;
typedef st_gui_point MfSdkGuiPoint_T;
typedef st_gui_menu_item_def MfSdkGuiMenuItemDef_T;
typedef st_gui_message MfSdkGuiMsg_T;
typedef gui_key_event MfSdkGuiKeyEvent_T;
typedef st_gui_sign_procs MfSdkGuiSignProcs_T;
//MfSdkGuiInputPage Parameters
typedef struct 
{
	s8* title; //[in] Title displayed in the middle of the first line
	s8* msgPrompt; //[in] Prompt information
	s8* str; //[out] input data string
	s32 disp_mode; //[in] 0:digit input, 1:character input, 2:password input 
	s32 disp_line; //[in] the number of rows Prompt displayed
	s32 input_line; //[in] the number of rows inputs displayed
	s32 disp_pattern; //[in] Prompt display position, 0 left alignment, 1 center; 2 right alignment
	s32 input_pattern; //[in] inputs display position, 0 left alignment, 1 center; 2 right alignment
	s32 min; //[in] minimum input length
	s32 max; //[in] maximum input length
	s32 timeout; //[in] waiting for input timeout time (seconds)
	void (*extra_paint_func)(void *extra_param); //[in] extra painting function on input page
	void* extra_param; //[in] parameter of extra_paint_func
}MfSdkGuiInputPageParam_T;


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief Set Amount display
 *
 * @param[in] char *msg  text amount eg. 0.00/1.00
 */
LIB_EXPORT void MfSdkGuiLedAmount(char *msg);
/**
 * @brief Show Counter display
 *
 * @param[in] char *msg  3 bytes ascii digit eg. "0"-"999"
 */
LIB_EXPORT void MfSdkGuiLedCounter(char *msg);
/**
 * @brief
 *
 * @param[in] char *msg HHMM eg. "09:00"
 */

LIB_EXPORT void MfSdkGuiLedTime(char *msg);
/**
 * @brief Segment code
 * 
 * @param[in] char *digit_str
 * @return MFSDK_RET_OK
 */
LIB_EXPORT int MfSdkGuiLedDigitShow(char *digit_str);

/**
 * @brief Batch refresh starts
 *
 */
LIB_EXPORT void MfSdkGuiBeginBatchPaint();
/**
 * @brief End of batch refresh
 *
 */
LIB_EXPORT void MfSdkGuiEndBatchPaint();

/**
 * @brief Set the foreground color
 *
 * @param[in] color the foreground color
 */
LIB_EXPORT void MfSdkGuiSetColor(s32 color);
/**
 * @brief Get the foreground color
 *
 * @return  >=0, success, the foreground color
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetColor();
/**
 * @brief Set the background color
 *
 * @param[in] color the background color
 */
LIB_EXPORT void MfSdkGuiSetBgColor(s32 color);
/**
 * @brief Get the background color
 *
 * @return  >=0, success, the background color
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetBgColor();
/**
 * @brief Set to full screen display 
 *
 * @param[in] full is full screen display(1 - Yes, 0 - No)
 */
LIB_EXPORT void MfSdkGuiSetFullScreen(s32 full);
/**
 * @brief Draw a point
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiPixel(s32 x, s32 y);
/**
 * @brief Draw a line
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 */
LIB_EXPORT void MfSdkGuiLineTo(s32 x, s32 y);
/**
 * @brief Gui filled area
 *
 * @param[in] left left border
 * @param[in] top upper boundary
 * @param[in] right right border
 * @param[in] bottom lower boundary
 */
LIB_EXPORT void MfSdkGuiBarRc(s32 left, s32 top, s32 right, s32 bottom);
/**
 * @brief Set the fill color
 *
 * @param[in] color fill color(format 0x00RRGGBB)
 */
LIB_EXPORT void MfSdkGuiSetBarColor(s32 color);
/**
 * @brief Get the fill color
 *
 * @return  >=0, success, the fill color
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetBarColor();
/**
 * @brief Set display font
 *
 * @param[in] font font(0 - 12 lattice, 1 - 16 lattice)
 */
LIB_EXPORT void MfSdkGuiSetFont(s32 font);
/**
 * @brief Get display font
 *
 * @return  >=0, success, the display font
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetFont(void);
/**
 * @brief Set text color
 *
 * @param[in] color text color
 */
LIB_EXPORT void MfSdkGuiSetTextColor(s32 color);

/**
 * @brief Get text color
 *
 * @return  >=0, success, the text color
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetTextColor(void);
/**
 * @brief Set the text background color
 *
 * @param[in] color text background color
 */
LIB_EXPORT void MfSdkGuiSetTextBgColor(s32 color) ;

/**
 * @brief Get the text background color
 *
 * @return  >=0, success, the text background color
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetTextBgColor(void);

/**
 * @brief Clear screen display
 *
 */
LIB_EXPORT void MfSdkGuiClearDc(void);

/**
 * @brief Set text magnification
 *
 * @param[in] size multiple, the default value is 2
 */
LIB_EXPORT void MfSdkGuiSetTextZoom(s32 size) ;
/**
 * @brief Get text magnification
 *
 * @return  0, success, the text magnification
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetTextZoom() ;
/**
 * @brief Draw a point with color
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] color point color
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiSetPixel(s32 x, s32 y, s32 color);
/**
 * @brief Get the color of the point on the screen
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @return  >=0, success, point color
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetPixel(s32 x, s32 y);
/**
 * @brief Display text on the screen ,Show only English
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] text text content
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiTextOut(s32 x, s32 y, char * text);
/**
 * @brief Get the display width of the text 
 *
 * @param[in] text text content
 * @return  >=0, success, the text width
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetTextWidth(char *text);
/**
 * @brief Get the display height of the text 
 *
 * @param[in] text text content
 * @return  >=0, success, the text height
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetTextHeight(char *text);
/**
 * @brief Draw line
 *
 * @param[in] x1 point1 X coordinate
 * @param[in] x2 point2 X coordinate	
 * @param[in] y1 point1 Y coordinate
 * @param[in] y2 point2 Y coordinate
 * @param[in] color color of the line
 */
LIB_EXPORT void MfSdkGuiCline(s32 x1, s32 y1, s32 x2, s32 y2, s32 color);
/**
 * @brief Get screen width
 *
 * @return  >=0, success, the screen width
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetWidth(void);
/**
 * @brief Get screen height
 *
 * @return  >=0, success, the screen height
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiGetHeight(void);
/**
 * @brief Bottom options painting
 *
 * @param[in] left_str The character displayed in the lower left corner
 * @param[in] right_str The character displayed in the lower right corner	
 */
LIB_EXPORT void MfSdkGuiPageOpPaint(char * left_str, char * right_str);
/**
 * @brief Set input method parameters
 *
 * @param[in] def_mode Default input method
 * @param[in] allow_mode Support input method
 * @param[in] password enter password
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiImeSetMode(s32 def_mode, s32 allow_mode, s32 password);
/**
 * @brief Open the input method page
 *
 * @param[in] buffer Input buffer
 * @param[in] max Maximum input character
 * @param[in] help Enter page title
 * @return  0, success, the text length
 * @return  Other, failure
 * @details only for H9G, H9L
 */
LIB_EXPORT s32 MfSdkGuiImeStartInput(char * buffer, s32 max, char * help);

/**
 * @brief Add menu handler
 *
 * @param[in] pfunc menu handler
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiMainMenuFuncAdd(void * pfunc);
/**
 * @brief Del menu handler
 *
 * @param[in] pfunc menu handler
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiMainMenuFuncDel(void * pfunc);
/**
 * @brief Display menu
 *
 * @param[in] id menu id
 * @param[in] timeover overtime time 
 */
LIB_EXPORT void MfSdkGuiMainMenuShow(char *id , s32 timeover);
/**
 * @brief Send a message
 *
 * @param[in] msg_id message id
 * @param[in] wparam parameter 1
 * @param[in] lparam parameter 2
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT u32 MfSdkGuiPostMessage(u32  msg_id, u32 wparam, u32 lparam);
/**
 * @brief Recv a message
 *
 * @param[in] timeover overtime time
 * @param[out] pmsg message structure
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT u32 MfSdkGuiGetMessage(  MfSdkGuiMsg_T * pmsg , s32 timeover);
/**
 * @brief Let the system process the default message
 *
 * @param[in] pmsg message structure
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiProcDefaultMsg( MfSdkGuiMsg_T * pmsg );
/**
 * @brief Display dialog
 *
 * @param[in] title message title
 * @param[in] msg message content
 * @param[in] pszLeftOp bottom left corner
 * @param[in] pszRightOp tip in the lower right corner
 * @param[in] timeover overtime time
 * @return  1, Confirm return
 * @return  2, Cancel back
 * @return  3, Timeout
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiMessageBoxShow(char *title, char *msg , char* pszLeftOp, char* pszRightOp , s32 timeover);

/**
 * @brief Load bmp into memory
 *
 * @param[in] filename image name
 * @param[out] width image width
 * @param[out] height image height
 * @param[out] color image color
 * @return  !=0, success, Image content array, which needs to be released after use
 * @return	0, failure
 */
LIB_EXPORT char *MfSdkGuiLoadBmpEx(char * filename, int *width, int *height, int * color);

/**
 * @brief Load bmp into memory
 *
 * @param[in] filename image name
 * @param[out] width image width
 * @param[out] height image height
 * @return  !=0, success, Image content array, which needs to be released after use
 * @return	0, failure
 */
LIB_EXPORT char *MfSdkGuiLoadBmp(char * filename , s32 *width , s32 *height);
/**
 * @brief Free memory of bmp
 *
 * @param[in] pbmp image content array
 */
LIB_EXPORT void MfSdkGuiBmpFree(char * pbmp);
/**
 * @brief display image
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate	
 * @param[in] pbits image data
 * @param[in] width image width
 * @param[in] height image height
 * @param[in] mode display mode(0 - Positive, 1 - Reverse)
 */
LIB_EXPORT void MfSdkGuiOutBits(s32 x, s32 y, unsigned char *pbits, s32 width , s32 height, s32 mode);
/**
 * @brief display image
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate	
 * @param[in] pbits image data
 * @param[in] width image width
 * @param[in] height image height
 * @param[in] mode display mode(0 - Positive, 1 - Reverse)
 * @param[in] color bit color of the picture(1,4,24)
 */
LIB_EXPORT void MfSdkGuiOutBitsEx(s32 x, s32 y, unsigned char *pbits, s32 width , s32 height, s32 mode , s32 color);
/**
 * @brief display image
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate	
 * @param[in] pbits image data
 * @param[in] width image width
 * @param[in] height image height
 * @param[in] mode display mode(0 - Positive, 1 - Reverse)
 * @param[in] zoom amplification factor
 */
LIB_EXPORT void MfSdkGuiOutBitsZoom(s32 x, s32 y, unsigned char *pbits, s32 width , s32 height, s32 mode, s32 zoom);
/**
 * @brief get text width
 *
 * @param[in] str text content
 * @return >=0, success, the text width
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiTextWidthEx(char * str);
/**
 * @brief Display text on the screen ,Show different languages
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] str text content
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiTextOutEx(s32 x, s32 y,char * str);
/**
 * @brief Setting Text Style
 *
 * @param[in] textStyle	text style(0 - opaque, 1 - transparent)
 */
LIB_EXPORT void MfSdkGuiSetTextStyle(s32 textStyle);

/**
 * @brief select page
 *
 * @param[in] title the title of the select page
 * @param[in] items menu items
 * @param[in] itemscount number of menu items 
 * @param[in] timeover menu timeout
 * @param[in] select default menu item
 * @return >=0, success, index in items of chosen item
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiSelectPageEx(char *title , char *items[],s32 itemscount,s32 timeover, s32 select);
/**
 * @brief select page
 *
 * @param[in] title the title of the select page
 * @param[in] items menu items
 * @param[in] itemscount number of menu items 
 * @param[in] timeover menu timeout
 * @param[in] select default menu item
 * @return >=0, success, index in items of chosen item
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiSelectPageExT(char *title ,char items[][255],s32 itemscount,s32 timeover, s32 select);

/**
 * @brief select page with key trigger callback function
 *
 * @param[in] title the title of the select page
 * @param[in] items menu items
 * @param[in] itemscount number of menu items 
 * @param[in] timeover menu timeout
 * @param[in] select default menu item
 * @param[in] callback_key the key used to trigger the callback (recommend KEY_0 or KEY_BACKSPACE)
 * @param[in] callbackfunc callback function
 * @return >=0, success, index in items of chosen item
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiSelectPageCb(char *title , char *items[],int itemscount,int timeover,int select,char callback_key,int (*callbackfunc)(const void *items[],const int itemscount));

/**
 * @brief set the background color of title 
 *
 * @param[in] color the background color of title 
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void MfSdkGuiTitleColorBackground(s32 color);
/**
 * @brief set the color of title foreground
 *
 * @param[in] color the color of title foreground
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void MfSdkGuiTitleColorForeground(s32 color);
/**
 * @brief Set title font
 *
 * @param[in] font font(0 - 12 lattice, 1 - 16 lattice)
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void MfSdkGuiTitleFont(int font);
/**
 * @brief set the color of menu hightline
 *
 * @param[in] color the color of menu hightline
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void MfSdkGuiMenuHightlineColor( s32 color);
/**
 * @brief Display text in the line center on the screen,Show only English
 *
 * @param[in] pMsg text content
 * @param[in] top top  coordinate
 */
LIB_EXPORT void  MfSdkGuiTextOutLineCenter(char *pMsg , s32 top);
/**
 * @brief Display text in the line right on the screen,Show only English
 *
 * @param[in] pMsg text content
 * @param[in] top top  coordinate
 */
LIB_EXPORT void MfSdkGuiTextOutLineRight(char *pMsg , s32 top);
/**
 * @brief Display text in the line left on the screen,Show only English
 *
 * @param[in] pMsg text content
 * @param[in] top top  coordinate
 */
LIB_EXPORT void MfSdkGuiTextOutLineLeft(char *pMsg, s32 top);
/**
 * @brief Display text in the middle of the screen ,Show only English
 *
 * @param[in] pmsg text content
 */
LIB_EXPORT void MfSdkGuiTextOutWinCenter(char *pmsg);
/**
 * @brief Refresh the specified area
 *
 * @param[in] left left border
 * @param[in] top upper boundary
 * @param[in] right right border
 * @param[in] bottom lower boundary
 * @param[in] color refresh with specified color	
 */
LIB_EXPORT void MfSdkGuiClearRect(s32 left, s32 top, s32 right, s32 bottom, s32 color);
/**
 * @brief Display dialog
 *
 * @param[in] title message title
 * @param[in] msg message content
 * @param[in] pszLeftOp bottom left corner
 * @param[in] pszRightOp tip in the lower right corner
 * @param[in] timeover overtime time
 * @param[in] flag show timeout on title right side(1 - Yes, 0 - No)
 * @param[in] support key value eg:{key0,key1,keyok}
 * @param[out] presskey: return press key value	
 * @return  1, Confirm return
 * @return  2, Cancel back
 * @return  3, Timeout
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkGuiMessageBoxShowEx(char *title, char *msg , char* pszLeftOp, char* pszRightOp , s32 timeover,s32 flag,unsigned char * keylist, s32 * presskey);

/**
 * @brief Set title 
 * 
 * @param[in] char *title
 */
LIB_EXPORT void MfSdkGuiSetTitle(char *title);
/**
 * @brief Highlight a line of text
 *
 * @param[in] x the starting x coordinate of the highlight
 * @param[in] y	the starting y coordinate of the highlight
 * @param[in] y2 the ending y coordinate of the highlight
 * @param[in] text the text want to highlight
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiTextOutHighlight(s32 x, s32 y, s32 y2,char * text);
/**
 * @brief Highlight an area
 *
 * @param[in] x the starting x coordinate of the highlight
 * @param[in] x2 the ending x coordinate of the highlight
 * @param[in] y	the starting y coordinate of the highlight
 * @param[in] y2 the ending y coordinate of the highlight
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiRectHighlight(int x, int x2, int y, int y2);

/**
 * @brief Add default message processing
 *
 * @param[in] pfunc message processing function
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiDefaultMsgFuncAdd(void * pfunc);
/**
 * @brief Add menu item
 *
 * @param[in] menu_item menu item
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiMainMenuItemAdd(MfSdkGuiMenuItemDef_T * menu_item);
/**
 * @brief Delete menu item
 *
 * @param[in] name the value of st_gui_menu_item_def->name 
 * @param[in] id the value of st_gui_menu_item_def->id
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT s32 MfSdkGuiMainMenuItemDel(char *name ,char *id);

/**
 * @brief
 * 
 * @param[out] MfSdkGuiKeyEvent_T *key_event
 * @return 1 - get key value
 * @return other - dont get key value
 */
LIB_EXPORT s32 MfSdkGuiKeyGetEvent(MfSdkGuiKeyEvent_T *key_event);

/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT s32 MfSdkGuiWifiSetPage();

/**
 * @brief Set sign processing function
 *
 * @param[in] MfSdkGuiSignProcs_T procs	the sign processing function  
 */
LIB_EXPORT void MfSdkGuiSetProcs( MfSdkGuiSignProcs_T *procs );

/**
 * @brief Determine whether it has been signed
 *
 * @param[in] index	Signature index
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int MfSdkGuiSignExist( const char *index );

/**
 * @brief Signature processing
 * API: gui_sign_proc and gui_sign_proc2 merge to MfSdkGuiSignProc
 * @param[in] index	Signature index
 * @param[in] date	Device date
 * @param[in] refno	Reference No
 * @param[in] timeout timeout time
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int MfSdkGuiSignProc( const char *index, const char *date, const char *refno, int timeout );

/**
 * @brief Get sign print string
 *
 * @param[in] index	Signature index
 * @return !=0, success, the print string
 * @return 0, failure
 */
LIB_EXPORT const char *MfSdkGuiSignPrint(const char *index);

/**
 * @brief JBIG encoding interface
 *
 * @param[in] index	Signature index
 * @param[out] jbigencode JBIG encoded signature data
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int MfSdkGuiSignEncode( const char *index, char **jbigencode );

/**
 * @brief JBIG results released
 *
 * @param[in] jbigencode the JBIG result
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int MfSdkGuiSignEncodeFree( char *jbigencode );

/**
 * @brief Clean up signature data
 *
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int MfSdkGuiSignClean();

/**
 * @brief Save signature to file
 *
 * @param[in] filename the filename of Signature  
 * @param[in] index Signature index
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int MfSdkGuiSignSavetofile(char *filename, const char *index);
/**
 * @brief set powerfull color
 * @param[in] iColor :
 			  0xFF0000(red)/ 0x00FF00(green) / 0x0000FF(blue)
 */
LIB_EXPORT void MfSdkGuiSetPowerfullColor(unsigned int iColor);

/**
 * @brief
 * 
 * @param[in] void * pfunc
 * @return 
 */
LIB_EXPORT int MfSdkGuiStateFuncAdd(void * pfunc);
/**
 * @brief
 * 
 * @param[in] int left
 * @param[in] int width
 */
LIB_EXPORT void MfSdkGuiCleartState(int left , int width);
/**
 * @brief
 * 
 * @param[in] int x
 * @param[in] int y
 * @param[in] unsigned char *pbits
 * @param[in] int width
 * @param[in] int height
 * @param[in] int mode
 * @param[in] int fc
 * @param[in] int bc
 */
LIB_EXPORT void MfSdkGuiOutStateBitsColor(int x, int y, unsigned char *pbits, int width , int height, int mode , int fc ,int bc);
/**
 * @brief
 * 
 * @param[in] int index
 * @return 
 */
LIB_EXPORT int MfSdkGuiGetDefineColor(int index);

/**
 * @brief set curl socket status icon
 * @param[in] recv_icon recv icon buf
 * @param[in] send_icon send icon buf
 * @param[in] x X-coordinate offset
 * @details icon buf only 30*30 1-bit bmp
 */
LIB_EXPORT void MfSdkGuiSetCurlSocketIcon(char* recv_icon,char* send_icon,int x);

/**
 * @brief Set the screen refresh mode,disable by default
 * @param[in] mod 0:Open the refresh task(It is recommended to set when the code has a large number of pixels
 * @details Called once after the sys_init 
 */
LIB_EXPORT void MfSdkGuiRefreshMod(int mod);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_GUI_H__ */
