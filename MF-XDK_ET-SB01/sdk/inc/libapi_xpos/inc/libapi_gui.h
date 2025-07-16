#pragma once

#include "libapi_pub.h"

#define GUI_IME_MODE_T9PY			(1<<0)		//Allow pinyin input method
#define GUI_IME_MODE_ALPHABET_UP	(1<<1)		//Allow uppercase letters
#define GUI_IME_MODE_ALPHABET_LOW	(1<<2)		//Allow lowercase letters	
#define GUI_IME_MODE_NUMBER			(1<<3)		//Allow input of numbers


#define GUI_LINE_TOP(a)		(33 * a)
//#define GUI_LINE_TOP(a)						xgui_GetLineTop(a)

#define GUI_GUIFIRST				0x000A0000
#define GUI_GUIPAINT				0x000A0001
#define GUI_KEYPRESS				0x00050001
#define GUI_SCAN_OK					0x000E0021
#define GUI_USR_PROC				0x000EFF00

#define GUI_KEY_0		'0'
#define GUI_KEY_1		'1'
#define GUI_KEY_2		'2'
#define GUI_KEY_3		'3'
#define GUI_KEY_4		'4'
#define GUI_KEY_5		'5'
#define GUI_KEY_6		'6'
#define GUI_KEY_7		'7'
#define GUI_KEY_8		'8'
#define GUI_KEY_9		'9'
#define GUI_KEY_XING	'*'
#define GUI_KEY_JING		'#'

#define GUI_KEY_CONTROL		0x80

#define GUI_KEY_UP			(GUI_KEY_CONTROL + 0x1)
#define GUI_KEY_DOWN		(GUI_KEY_CONTROL + 0x2)
#define GUI_KEY_LEFT		(GUI_KEY_CONTROL + 0x3)
#define GUI_KEY_RIGHT		(GUI_KEY_CONTROL + 0x4)
#define GUI_KEY_BACKSPACE	(GUI_KEY_CONTROL + 0x5)

#define GUI_KEY_OK			(GUI_KEY_CONTROL + 0x11)
#define GUI_KEY_QUIT		(GUI_KEY_CONTROL + 0x12)
#define GUI_KEY_F1			(GUI_KEY_CONTROL + 0x13)
#define GUI_KEY_F2			(GUI_KEY_CONTROL + 0x14)
#define GUI_KEY_POWER		(GUI_KEY_CONTROL + 0x15)

#define GUI_COLOR_BACK		(0xCCCCCC)
#define GUI_COLOR_FORE		(0x222222)

#define GUI_STATE_BMP_COLOR			gui_GetDefineColor(0)		
#define GUI_STATE_BACK_FILL_COLOR	gui_GetDefineColor(1)		


typedef struct __st_gui_rect{
	int    left;	
	int    top;		
	int    right;	
	int    bottom;	
} st_gui_rect;


typedef struct __st_gui_point{
	int    x;	
	int    y;		
} st_gui_point;


typedef struct __st_gui_menu_item_def{
	char *parent;	
	char *name;		
	char *id;		
}st_gui_menu_item_def;


typedef struct __st_gui_message{
	void * dest;				///< reserved
	unsigned int message_id;	///< message id
	unsigned int wparam;		///< message param1
	unsigned int lparam;		///< message param2
	unsigned int time;			///< message time
}st_gui_message;


typedef struct _st_gui_sign_procs{
	int (*page_paint)(const char *m_watermark);		///< Draw sign page and watermark
	int (*page_getbackcount)();  
	int (*page_usecancel)();						///< Whether to allow cancellation
	int (*page_usecancelask)();						///< Whether to cancel prompt
	int (*page_getwatermark)( char *outwatermark);	///< Cancel get watermark
	int (*page_getwritepointcount)();				///< Minimum number of trajectory points
	int (*page_usesigntype)();						///< Whether to use the cashier confirmation page
	int (*page_use320_130)();						///< Whether the picture uses 320*130 resolution
	int (*page_getpointupcount)();					///< Minimum number of strokes
	int (*page_buffwidth)();						///< Width of image
	int (*page_buffheight)();						///< Height of image
}st_gui_sign_procs;

#define GUI_LCD_LIGHT_MAX		99999999
#define GUI_MENU_ITEM_COUNT(a)	sizeof(a)/sizeof(st_gui_menu_item_def)

#define KEY_CONTROL		0x80
#define KEY_UP			(KEY_CONTROL + 0x1)
#define KEY_DOWN		(KEY_CONTROL + 0x2)
#define KEY_OK			(KEY_CONTROL + 0x11)
#define KEY_QUIT		(KEY_CONTROL + 0x12)

typedef struct __st_gui_key_event {
	int keycode;
	int status;		/*1 down, 0 up*/
}gui_key_event;

/**
 * @brief Batch refresh starts
 *
 */
LIB_EXPORT void gui_begin_batch_paint();


/**
 * @brief End of batch refresh
 *
 */
LIB_EXPORT void gui_end_batch_paint();

/**
 * @brief Set the foreground color
 *
 * @param[in] color the foreground color
 */
LIB_EXPORT void gui_set_color(int color);

/**
 * @brief Get the foreground color
 *
 * @return  >=0, success, the foreground color
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_color();

/**
 * @brief Set the background color
 *
 * @param[in] color the background color
 */
LIB_EXPORT void gui_set_bg_color(int color);

/**
 * @brief Get the background color
 *
 * @return  >=0, success, the background color
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_bg_color();

/**
 * @brief Set to full screen display 
 *
 * @param[in] full is full screen displayr(1 - Yes, 0 - No)
 */
LIB_EXPORT void gui_set_full_screen(int full);

/**
 * @brief Draw a point
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_pixel(int x, int y);

/**
 * @brief Draw a line
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 */
LIB_EXPORT void gui_line_to(int x, int y);

/**
 * @brief Gui filled area
 *
 * @param[in] left left border
 * @param[in] top upper boundary
 * @param[in] right right border
 * @param[in] bottom lower boundary
 */
LIB_EXPORT void gui_bar_rc(int left, int top, int right, int bottom);

/**
 * @brief Set the fill color
 *
 * @param[in] color fill color(format 0x00RRGGBB)
 */
LIB_EXPORT void gui_set_bar_color(int color);

/**
 * @brief Get the fill color
 *
 * @return  >=0, success, the fill color
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_bar_color();


/**
 * @brief Set display font
 *
 * @param[in] font font(0 - 12 lattice, 1 - 16 lattice)
 */
LIB_EXPORT void gui_set_font(int font);

/**
 * @brief Get display font
 *
 * @return  >=0, success, the display font
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_font(void);

/**
 * @brief Set text color
 *
 * @param[in] color text color
 */
LIB_EXPORT void gui_set_text_color(int color);

/**
 * @brief Get text color
 *
 * @return  >=0, success, the text color
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_text_color(void);

/**
 * @brief Set the text background color
 *
 * @param[in] color text background color
 */
LIB_EXPORT void gui_set_text_bg_color(int color) ;

/**
 * @brief Get the text background color
 *
 * @return  >=0, success, the text background color
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_text_bg_color(void);

/**
 * @brief Clear screen display
 *
 */
LIB_EXPORT void gui_clear_dc(void);

/**
 * @brief Set text magnification
 *
 * @param[in] size multiple, the default value is 2
 */
LIB_EXPORT void gui_set_text_zoom(int size) ;

/**
 * @brief Get text magnification
 *
 * @return  0, success, the text magnification
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_text_zoom() ;

/**
 * @brief Draw a point with color
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] color point color
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_set_pixel(int x, int y, int color);

/**
 * @brief Get the color of the point on the screen
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @return  >=0, success, point color
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_pixel(int x, int y);

/**
 * @brief Display text on the screen ,Show only English
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] text text content
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_text_out(int x, int y, char * text);

/**
 * @brief Display text on the screen ,Show different languages
 *
 * @param[in] x horizontal coordinate
 * @param[in] y vertical coordinate
 * @param[in] str text content
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_text_out_ex(int x, int y,char * str);

/**
 * @brief Get the display width of the text 
 *
 * @param[in] text text content
 * @return  >=0, success, the text width
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_text_width(char *text);

/**
 * @brief Get the display height of the text 
 *
 * @param[in] text text content
 * @return  >=0, success, the text height
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_text_height(char *text);

/**
 * @brief Draw line
 *
 * @param[in] x1 point1 X coordinate
 * @param[in] x2 point2 X coordinate	
 * @param[in] y1 point1 Y coordinate
 * @param[in] y2 point2 Y coordinate
 */
LIB_EXPORT void gui_cline(int x1, int y1, int x2, int y2, int color);

/**
 * @brief Get screen width
 *
 * @return  >=0, success, the screen width
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_width(void);

/**
 * @brief Get screen height
 *
 * @return  >=0, success, the screen height
 * @return	Other, failure
 */
LIB_EXPORT int gui_get_height(void);

/**
 * @brief Get screen height
 *
 * @param[in] left_str The character displayed in the lower left corner
 * @param[in] right_str The character displayed in the lower right corner	
 */
LIB_EXPORT void gui_page_op_paint(char * left_str, char * right_str);

/**
 * @brief Set input method parameters
 *
 * @param[in] def_mode Default input method
 * @param[in] allow_mode Support input method
 * @param[in] password enter password
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_ime_set_mode(int def_mode, int allow_mode, int password);


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
LIB_EXPORT int gui_ime_start_input(char * buffer, int max, char * help);


/**
 * @brief Add menu handler
 *
 * @param[in] pfunc menu handler
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_main_menu_func_add(void * pfunc);

/**
 * @brief Del menu handler
 *
 * @param[in] pfunc menu handler
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_main_menu_func_del(void * pfunc);

/**
 * @brief Display menu
 *
 * @param[in] id menu id
 * @param[in] timeover overtime time 
 */
LIB_EXPORT void gui_main_menu_show(char *id , int timeover);

/**
 * @brief Send a message
 *
 * @param[in] msg_id message id
 * @param[in] wparam parameter 1
 * @param[in] lparam parameter 2
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT unsigned int gui_post_message(unsigned int msg_id, unsigned int wparam, unsigned int lparam);

/**
 * @brief Recv a message
 *
 * @param[in] timeover overtime time
 * @param[out] pmsg message structure
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT unsigned int gui_get_message( st_gui_message * pmsg , int timeover);

/**
 * @brief Let the system process the default message
 *
 * @param[in] pmsg message structure
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int gui_proc_default_msg( st_gui_message * pmsg );

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
LIB_EXPORT int gui_messagebox_show(char *title, char *msg , char* pszLeftOp, char* pszRightOp , int timeover);

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
LIB_EXPORT int gui_messagebox_showEx(char *title, char *msg , char* pszLeftOp, char* pszRightOp , int timeover,int flag,unsigned char * keylist, int * presskey);

/**
 * @brief Load bmp into memory
 *
 * @param[in] filename image name
 * @param[out] width image width
 * @param[out] height image height
 * @return  !=0, success, Image content array, which needs to be released after use
 * @return	0, failure
 */
LIB_EXPORT char * gui_load_bmp(char * filename , int *width , int *height);

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
LIB_EXPORT char * gui_load_bmp_ex(char * filename , int *width , int *height, int * color);

/**
 * @brief Free memory of bmp
 *
 * @param[in] pbmp image content array
 */
LIB_EXPORT void gui_bmp_free(char * pbmp);

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
LIB_EXPORT void gui_out_bits(int x, int y, unsigned char *pbits, int width , int height, int mode);

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
LIB_EXPORT void gui_out_bits_ex(int x, int y, unsigned char *pbits, int width , int height, int mode , int color);

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
LIB_EXPORT void gui_out_bits_zoom(int x, int y, unsigned char *pbits, int width , int height, int mode, int zoom);

/**
 * @brief get text width
 *
 * @param[in] str text content
 * @return >=0, success, the text width
 * @return Other, failure
 */
LIB_EXPORT int gui_text_width_ex(char * str);

/**
 * @brief Setting Text Style
 *
 * @param[in] textStyle	text style(0 - opaque, 1 - transparent)
 */
LIB_EXPORT void gui_settextstyle(int textStyle);

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
LIB_EXPORT int gui_select_page_ex(char *title, char *items[], int itemscount, int timeover, int select);

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
LIB_EXPORT int gui_select_page_ex_t(char *title, char items[][255], int itemscount, int timeover, int select);

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
LIB_EXPORT int gui_select_page_cb(char *title , char *items[],int itemscount,int timeover,int select,char callback_key,int (*callbackfunc)(const void *items[],const int itemscount));


/**
 * @brief set the color of title background
 *
 * @param[in] color the color of title background
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void gui_titlecolorback(int color);

/**
 * @brief set the color of title foreground
 *
 * @param[in] color the color of title foreground
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void gui_titlecolorfore(int color);

/**
 * @brief Set title font
 *
 * @param[in] font font(0 - 12 lattice, 1 - 16 lattice)
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void gui_titlefont( int font );

/**
 * @brief set the color of menu hightline
 *
 * @param[in] color the color of menu hightline
 * @dtails only for H9G, H9L
 */
LIB_EXPORT void gui_menuhightlinecolor( int color);


LIB_EXPORT void gui_set_title(char *tilte);

/**
 * @brief Display text in the line center on the screen,Show only English
 *
 * @param[in] pMsg text content
 * @param[in] top top  coordinate
 */
LIB_EXPORT void  gui_textout_line_center(char *pMsg , int top);

/**
 * @brief Display text in the line left on the screen,Show only English
 *
 * @param[in] pMsg text content
 * @param[in] top top  coordinate
 */
LIB_EXPORT void  gui_textout_line_left(char *pMsg , int top);

/**
 * @brief Display text in the line right on the screen,Show only English
 *
 * @param[in] pMsg text content
 * @param[in] top top  coordinate
 */
LIB_EXPORT void  gui_textout_line_right(char *pMsg , int top);

/**
 * @brief Display text in the middle of the screen ,Show only English
 *
 * @param[in] pMsg text content
 */
LIB_EXPORT void gui_text_out_win_center(char *pmsg);

/**
 * @brief Refresh the specified area
 *
 * @param[in] left left border
 * @param[in] top upper boundary
 * @param[in] right right border
 * @param[in] bottom lower boundary
 * @param[in] color refresh with specified color	
 */
LIB_EXPORT void gui_clear_rect(int left, int top, int right, int bottom, int color);

/**
 * @brief Display title on the screen
 *
 * @param[in] title the title want to display	
 */
LIB_EXPORT void gui_setTitle(char *title);

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
LIB_EXPORT int gui_text_out_heghlight(int x, int y, int y2,char * text);

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
LIB_EXPORT int gui_rect_heghlight(int x, int x2, int y, int y2);

/**
 * @brief Add default message processing
 *
 * @param[in] pfunc message processing function
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_default_msg_func_add(void * pfunc);

/**
 * @brief Add menu item
 *
 * @param[in] menu_item menu item
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_main_menu_item_add(st_gui_menu_item_def * menu_item);

/**
 * @brief Delete menu item
 *
 * @param[in] name the value of st_gui_menu_item_def->name 
 * @param[in] id the value of st_gui_menu_item_def->id
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_main_menu_item_del(char *name ,char *id);

/**
 * @brief Set sign processing function
 *
 * @param[in] procs	the sign processing function
 */
LIB_EXPORT void gui_setprocs( st_gui_sign_procs *procs );

/**
 * @brief Determine whether it has been signed
 *
 * @param[in] index	Signature index
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_sign_exist( const char *index );

/**
 * @brief Signature processing
 *
 * @param[in] index	Signature index
 * @param[in] date	Device date
 * @param[in] refno	Reference No
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_sign_proc( const char *index, const char *date, const char *refno );

/**
 * @brief Signature processing
 *
 * @param[in] index	Signature index
 * @param[in] date	Device date
 * @param[in] refno	Reference No
 * @param[in] timeout timeout time
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_sign_proc2( const char *index, const char *date, const char *refno, int timeout );

/**
 * @brief Get sign print string
 *
 * @param[in] index	Signature index
 * @return !=0, success, the print string
 * @return 0, failure
 */
LIB_EXPORT const char * gui_sign_print(const char *index);

/**
 * @brief JBIG encoding interface
 *
 * @param[in] index	Signature index
 * @param[out] jbigencode JBIG encoded signature data
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_sign_encode( const char *index, char **jbigencode );

/**
 * @brief JBIG results released
 *
 * @param[in] jbigencode the JBIG result
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_sign_encode_free( char *jbigencode );

/**
 * @brief Clean up signature data
 *
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_sign_clean();

/**
 * @brief Save signature to file
 *
 * @param[in] filename the filename of Signature  
 * @param[in] index Signature index
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT int gui_sign_savetofile(char *filename, const char *index);
/**
 * @brief set powerfull color
 * @param[in] iColor :
 			  0xFF0000(red)/ 0x00FF00(green) / 0x0000FF(blue)
 * @return 0, success
 * @return Other, failure
 */
LIB_EXPORT void gui_set_powerfull_color(unsigned int iColor);

LIB_EXPORT int gui_state_func_add(void * pfunc);
LIB_EXPORT void gui_cleart_state(int left , int width);
LIB_EXPORT void gui_out_state_bits_color(int x, int y, unsigned char *pbits, int width , int height, int mode , int fc ,int bc);
LIB_EXPORT int gui_GetDefineColor(int index);

/**
 * @brief set curl socket status icon
 * @param[in] recv_icon recv icon buf
 * @param[in] send_icon send icon buf
 * @param[in] x X-coordinate offset
 * @details icon buf only 30*30 1-bit bmp
 */
LIB_EXPORT void gui_set_curl_socket_icon(char* recv_icon,char* send_icon,int x);


LIB_EXPORT int gui_set_status_bar_text(int x, char* text, int group, char* font);
LIB_EXPORT void gui_set_status_bar_hidden_time(int isHidden);
LIB_EXPORT void gui_set_status_bar_power_x(int x);
LIB_EXPORT void gui_set_status_bar_gprs_x(int x);
LIB_EXPORT void gui_set_status_bar_wifi_x(int x);