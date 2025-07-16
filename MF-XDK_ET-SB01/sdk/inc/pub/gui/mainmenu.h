#pragma once

/*! \file mainmenu.h
	\brief ���˵�
*	\author lx
*	\date 2014/02/07
*/

#include "pub/pub.h"



#define MENU_ITEM_COUNT(a)		sizeof(a)/sizeof(st_main_menu_item_def)


typedef struct __st_main_menu_item_def{
	char *parent;	
	char *name;		
	char *id;		
}st_main_menu_item_def;

/**
* @brief ��ӻص�����
* @param pfunc �ص�����
* @return 
*/
LIB_EXPORT int main_menu_func_add(void * pfunc);

/**
* @brief �Ƴ��ص�����
* @param pfunc �ص�����
* @return 
*/
LIB_EXPORT int main_menu_func_del(void * pfunc);


/**
* @brief ��Ӳ˵��б�
* @param menu_item �˵��б�
* @param count �˵��б�����
* @return 
*/
LIB_EXPORT int main_menu_item_add_list(st_main_menu_item_def * menu_item , int count);
/**
* @brief ��Ӳ˵���
* @param parent ���˵�id
* @param name �˵�����
* @param id �˵�id
* @return 
*/
LIB_EXPORT int main_menu_item_add(const st_main_menu_item_def * menu_item);
/**
* @brief ɾ���˵���
* @param name �˵�����
* @param id �˵�id
* @return 
*/
LIB_EXPORT int main_menu_item_del(char *name ,char *id);
LIB_EXPORT int main_menu_item_del_ex(char *name ,char *id ,char * parent);
/**
* @brief ��ʾ�˵�
* @param id �˵�id
* @param timeover ��ʱʱ��
* @return 
*/
LIB_EXPORT int main_menu_show(char * title, char *id , int timeover);




