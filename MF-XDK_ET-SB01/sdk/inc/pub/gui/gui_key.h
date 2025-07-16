#pragma once
#include "pub/pub.h"

#define KEY_0		'0'
#define KEY_1		'1'
#define KEY_2		'2'
#define KEY_3		'3'
#define KEY_4		'4'
#define KEY_5		'5'
#define KEY_6		'6'
#define KEY_7		'7'
#define KEY_8		'8'
#define KEY_9		'9'
#define KEY_XING	'*'
#define KEY_JING	'#'


#define KEY_A		'A'
#define KEY_B		'B'
#define KEY_C		'C'
#define KEY_D		'D'
#define KEY_E		'E'
#define KEY_F		'F'
#define KEY_G		'G'
#define KEY_H		'H'
#define KEY_I		'I'
#define KEY_J		'J'
#define KEY_K		'K'

#define KEY_CONTROL		0x80

#define KEY_UP			(KEY_CONTROL + 0x1)
#define KEY_DOWN		(KEY_CONTROL + 0x2)
#define KEY_LEFT		(KEY_CONTROL + 0x3)
#define KEY_RIGHT		(KEY_CONTROL + 0x4)
#define KEY_BACKSPACE	(KEY_CONTROL + 0x5)
#define KEY_DELETE		(KEY_CONTROL + 0x6)
#define KEY_TAB			(KEY_CONTROL + 0x7)
#define KEY_ENTER		(KEY_CONTROL + 0x8)
#define KEY_HOME		(KEY_CONTROL + 0x9)

#define KEY_END			(KEY_CONTROL + 0xA)
#define KEY_SHIFT		(KEY_CONTROL + 0xB)
#define KEY_ESCAPE		(KEY_CONTROL + 0xC)
#define KEY_INSERT		(KEY_CONTROL + 0xD)
#define KEY_CANCEL 		(KEY_CONTROL + 0xE)

#define KEY_FUNC		(KEY_CONTROL + 0x10)
#define KEY_OK			(KEY_CONTROL + 0x11)
#define KEY_QUIT		(KEY_CONTROL + 0x12)
#define KEY_F1			(KEY_CONTROL + 0x13)
#define KEY_F2			(KEY_CONTROL + 0x14)
#define KEY_POWER		(KEY_CONTROL + 0x15)

#define KEY_IM_UP		(KEY_CONTROL + 0x16)
#define KEY_IM_DOWN		(KEY_CONTROL + 0x17)

#define KEY_F10			(KEY_CONTROL + 0x20)
#define KEY_F11			(KEY_CONTROL + 0x21)
#define KEY_F12			(KEY_CONTROL + 0x22)
#define KEY_F13			(KEY_CONTROL + 0x23)
#define KEY_F14			(KEY_CONTROL + 0x24)
#define KEY_TOTAL		(KEY_CONTROL + 0x25)
#define KEY_F3			(KEY_CONTROL + 0x26)
#define KEY_ADD			(KEY_CONTROL + 0x27)
#define KEY_EX_F1		(KEY_CONTROL + 0x28)
#define KEY_EX_F2		(KEY_CONTROL + 0x29)



typedef struct __st_gui_key_event {
	int keycode;
	int status;		/*1 down, 0 up*/
}gui_key_event;

LIB_EXPORT int gui_key_getevent(gui_key_event *key_event);
LIB_EXPORT int gui_key_getcode();
LIB_EXPORT void gui_key_set_pc(int gui_key,int state);
LIB_EXPORT int gui_key_proc_func_add(void * pfunc);