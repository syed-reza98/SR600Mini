/*! \file tlv_func.h
	\brief tlv����
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "pub\pub.h"

typedef struct _st_tlv_tag{
	int len;
	unsigned char tag;
	unsigned char *val;
}st_tlv_tag;


typedef struct _st_tlv_tag_list{
	struct _st_tlv_tag tlv_tag;
	struct _st_tlv_tag_list * next;
}st_tlv_tag_list;

typedef struct _st_tlv_data{
	int datalen;
	int bufflen;
	unsigned char * buff;
	st_tlv_tag_list tag_list;
}st_tlv_data;

/**
* @brief ����һ��tlv
* @param tlv_data tlvָ��
* @param len ����
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_creat_buff(st_tlv_data * tlv_data , int len);
/**
* @brief �������ݵ�tlv
* @param tlv_data tlvָ��
* @param buff ������
* @param len ����
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_set_buff(st_tlv_data * tlv_data , unsigned char * buff , int len);
/**
* @brief ɾ��tlv�е�һ��tag
* @param tlv_data tlvָ��
* @param tag ��ǩ
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_del_tag(st_tlv_data * tlv_data , unsigned char tag);
/**
* @brief ���һ�����ݵ�tlv
* @param tlv_data tlvָ��
* @param tag ��ǩ
* @param buff ������
* @param len ���ݳ���
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_add_tag_bin(st_tlv_data * tlv_data , unsigned char tag , unsigned char * buff , int len);
/**
* @brief ���һ���ַ���
* @param tlv_data tlvָ��
* @param tag ��ǩ
* @param buff �ַ���
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_add_tag_str(st_tlv_data * tlv_data , unsigned char tag , unsigned char * buff);
/**
* @brief ���һ������
* @param tlv_data tlvָ��
* @param tag ��ǩ
* @param val ֵ
* @param n ��䳤��
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_add_tag_int(st_tlv_data * tlv_data , unsigned char tag , int val , int n);
/**
* @brief ���һ��������
* @param tlv_data tlvָ��
* @param tag ��ǩ
* @param val ֵ
* @param n ��䳤��
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_add_tag_long(st_tlv_data * tlv_data , unsigned char tag , long long val , int n);
/**
* @brief �ͷ�һ��tlv
* @param tlv_data tlvָ��
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_free_buff(st_tlv_data * tlv_data);

/**
* @brief �����б���tlv
* @param tlv_src ԭʼtlvָ��
* @param tlv_des Ŀ��tlvָ��
* @param tag_list ��ǩ�б� 0xff����
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_copy_tag_by_list(st_tlv_data * tlv_src , st_tlv_data * tlv_des , unsigned char *tag_list);

/**
* @brief ��ȡһ����ǩֵ��ʹ�ú�ʹ��tlv_free_tag�ͷ�
* @param tlv_data tlvָ��
* @param tag ��ǩ
* @param tlv_tag ��ǩֵ
* @return >0�ɹ�
*/
LIB_EXPORT int tlv_get_tag(st_tlv_data * tlv_data , unsigned char tag , st_tlv_tag * tlv_tag);
LIB_EXPORT int tlv_get_tag_by_index(st_tlv_data * tlv_data , int index , st_tlv_tag * tlv_tag);
/**
* @brief �ͷ�tlv��ǩ
* @param tlv_tag ��ǩ
* @return 0�ɹ�
*/
LIB_EXPORT int tlv_free_tag(st_tlv_tag * tlv_tag);

/**
* @brief ��ȡtlv�е����б�ǩ�б�
* @param tlv_data tlvָ��
* @param tag_list ��ǩ�б�
* @param size �б��С
* @return ʵ���б�����
*/
LIB_EXPORT int tlv_get_tag_index_list(st_tlv_data * tlv_data , unsigned char *tag_list , int size);


/**
* @brief ��ȡһ����ǩֵ��ʹ�ú����ͷ�tlv_data��ͳһ�ͷ�
* @param tlv_data tlvָ��
* @param index ��ǩ
* @return ��ǩֵ
*/
LIB_EXPORT st_tlv_tag * tlv_get_tag_item(st_tlv_data * tlv_data , int index);

LIB_EXPORT int tlv_get_tag_item_list(st_tlv_data * tlv_data , unsigned char *tag_list);
LIB_EXPORT int tlv_free_tag_item_list(st_tlv_tag_list *tlv_tag_item_list);



LIB_EXPORT int tlv_add_tlvitem(st_tlv_data * tlv_data , unsigned char tag , st_tlv_data *tlvsub );
LIB_EXPORT int tlv_get_tlvitem(st_tlv_data * tlv_data , unsigned char tag , st_tlv_data *tlvsub );