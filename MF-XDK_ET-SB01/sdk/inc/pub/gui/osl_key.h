#pragma once
#include "pub\pub.h"

enum {
	MF_KEY_QUIT,
	MF_KEY_OK,
	MF_KEY_UP,
	MF_KEY_DOWN,
	MF_KEY_LEFT,
	MF_KEY_RIGHT,
	MF_KEY_TOTAL,
	MF_KEY_BACKSPACE,
	MF_KEY_0,
	MF_KEY_1,
	MF_KEY_2,
	MF_KEY_3,
	MF_KEY_4,
	MF_KEY_5,
	MF_KEY_6,
	MF_KEY_7,
	MF_KEY_8,
	MF_KEY_9,
	MF_KEY_XING,
	MF_KEY_JING,
	MF_KEY_F1,
	MF_KEY_F2,
	MF_KEY_CANCEL,
	MF_KEY_ADD,
	MF_KEY_FUNC,
	MF_KEY_ENTER,
//	MF_KEY_4,
//	MF_KEY_5,
//	MF_KEY_6,
//	MF_KEY_7,
//	MF_KEY_8,
//	MF_KEY_9,
};

enum {
	KEY_STATUS_SHORT_PRESS,				// �̰�
	KEY_STATUS_LONG_PRESS,				// ����
	KEY_STATUS_DOUBLE_PRESS,			// ˫�� 
	KEY_STATUS_UP_PRESS,				// ����
	KEY_STATUS_TRIPLE_PRESS,			// ����
	KEY_STATUS_COMBIN_PRESS				// ��ϼ�
};


typedef struct __st_key_event {
	int keycode;
	int status;		
}st_key_event;

LIB_EXPORT void osl_key_set_pc(int gui_key, int state);
LIB_EXPORT void osl_key_init();
LIB_EXPORT int osl_key_get_event(st_key_event* key_event);
LIB_EXPORT void osl_key_lvgl_mode(int mode);

// short_press_time �̰�����ʱ�䣬˫��ʹ��
// long_press_time  ����ʱ��
// short_press_delay �̰��Ƿ���ʱ�ͳ�,���û��ʱ˫��ǰ�����һ���̰�
LIB_EXPORT void osl_key_set_parameter(int key, int short_press_time, int long_press_time, int short_press_delay);

// �����Ƿ�֧��3��
LIB_EXPORT void osl_key_set_triple_press(int key, int triple_press_flag);


LIB_EXPORT int osl_key_get_num();