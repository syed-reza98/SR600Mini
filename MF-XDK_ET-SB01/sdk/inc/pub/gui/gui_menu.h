#pragma once

#include "pub/pub.h"

#define MAX_ITEM_NUM	10

#define MENU_RET_QUIT		-1
#define MENU_RET_HANDOFF	-2
#define MENU_RET_TIMEOVER	-3

typedef struct __st_menu_data{
	char title[64];
	int timeover;
	int itemcount;
	int select;
	char * item[MAX_ITEM_NUM];
	unsigned int id[MAX_ITEM_NUM];
}xmenu;


LIB_EXPORT void menu_create(xmenu * pmenu, char *title, int timeover);
LIB_EXPORT void menu_append(xmenu * pmenu, char *text, int id);
LIB_EXPORT int menu_domodal(xmenu * pmenu);
LIB_EXPORT void menu_set_select(xmenu * pmenu,int index);
LIB_EXPORT void menu_delete(xmenu * pmenu);
LIB_EXPORT int menu_select_page(char * title, char * items[], int itemcount, int def, int timeover);