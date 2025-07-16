/*! \file osl_file_comm.h
	\brief �ļ�����
*	\author lx
*	\date 2014/02/08
*/
#ifndef _FILE_COMM_H_
#define _FILE_COMM_H_

#include "pub\pub.h"

#ifdef __cplusplus
extern "C"{
#endif


/**
* @brief �����ļ���
* @param dir_name �ļ�������
* @return 1�ɹ�
*/
LIB_EXPORT int Dir_Create(char * dir_name);

/**
* @brief ɾ���ļ���
* @param dir_name �ļ�������
* @return 1�ɹ�
*/
LIB_EXPORT int Delete_Create(char * dir_name);

/**
* @brief �����ļ�
* @param file_name �ļ�����
* @return 1�ɹ�
*/
LIB_EXPORT int File_Create(char * file_name);
/**
* @brief ɾ���ļ�
* @param file_name �ļ�����
* @return 
*/
LIB_EXPORT int File_Delete(char * file_name);
/**
* @brief ��ȡһ������
* @param hfile �ļ����
* @param read_start ��ʼλ��
* @param read_buff ������
* @param read_size ��ȡ����
* @return �Ѷ��ĳ���
*/
LIB_EXPORT int File_ReadBlock( int hfile, int read_start, char * read_buff, int read_size);
/**
* @brief ��ȡһ������
* @param file_name �ļ�����
* @param read_start ��ʼλ��
* @param read_buff ������
* @param read_size ��ȡ����
* @return �Ѷ��ĳ���
*/
LIB_EXPORT int File_ReadBlockByName(char * file_name,int read_start,char * read_buff,int read_size);
/**
* @brief дһ������
* @param hfile �ļ����
* @param write_start ��ʼλ��
* @param write_buff ������
* @param write_size д����
* @return ��д�ĳ���
*/
LIB_EXPORT int File_WriteBlock(int hfile,int write_start, char * write_buff,int write_size);
/**
* @brief дһ������
* @param file_name �ļ�����
* @param write_start ��ʼλ��
* @param write_buff ������
* @param write_size д����
* @return ��д�ĳ���
*/
LIB_EXPORT int File_WriteBlockByName(char * file_name,int write_start, char * write_buff,int write_size);
/**
* @brief ���һ������
* @param hfile �ļ����
* @param write_buff ������
* @param write_size д����
* @return ��д�ĳ���
*/
LIB_EXPORT int File_AppendBlock(int hfile,char * write_buff,int write_size);
/**
* @brief ���һ������
* @param file_name �ļ�����
* @param write_buff ������
* @param write_size д����
* @return ��д�ĳ���
*/
LIB_EXPORT int File_AppendBlockByName(char * file_name,char * write_buff,int write_size);
/**
* @brief �ļ��Ƿ����
* @param file_name �ļ�����
* @return 1����
*/
LIB_EXPORT int File_Exist(char *file_name);
/**
* @brief ��ȡ�ļ�����
* @param hfile �ļ����
* @return ����
*/
LIB_EXPORT int File_GetLength(int hfile);
/**
* @brief ����ļ�
* @param hfile �ļ����
* @param file_length ��䵽����
* @param fill_char �����ַ�
* @return 1�ɹ�
*/
LIB_EXPORT int File_SetLength(int hfile, unsigned int file_length, char fill_char);
/**
* @brief д�ļ�
* @param file_name �ļ�����
* @param write_buff ������
* @param write_size ����
* @return 1�ɹ�
*/
LIB_EXPORT int File_Write(char * file_name,char * write_buff,int write_size);
/**
* @brief ���ļ�
* @param file_name �ļ�����
* @param read_buff ������
* @param read_size ����
* @return 1�ɹ�
*/
LIB_EXPORT int File_Read(char * file_name,char * read_buff,int read_size);
/**
* @brief ���һ������
* @param file_name �ļ�����
* @param write_buff ������
* @param write_size ����
* @return 1�ɹ�
*/
LIB_EXPORT int File_Append(char * file_name,char * write_buff,int write_size);
/**
* @brief ��ȡ�ļ�����
* @param file_name �ļ�����
* @return ����
*/
LIB_EXPORT int File_GetLengthByName(char * file_name);
/**
* @brief ��ȡ����ʣ��ռ�
* @return ʣ��ռ�
*/
LIB_EXPORT int File_GetDataFreeSpace();
/**
* @brief ��ȡ�ļ���
* @param pPath ·��
* @return  �ļ���ָ��
*/
LIB_EXPORT char * File_GetFileName(char * pPath);
/**
* @brief ��ȡ�����ļ�����
* @param FileName �ļ�����
* @param pDst ������
* @return ��ȡ�Ĵ�С
*/
LIB_EXPORT int File_GetData(const char * FileName, void * pDst);
/**
* @brief ��ȡ�ļ���С
* @param FilePath �ļ�����
* @return 
*/
LIB_EXPORT int File_GetFileLength(const char * FilePath);
/**
* @brief ����ļ�����
* @param name �ļ�����
* @param flag 0-16���� 1-�ַ���ʽ
* @return 
*/
LIB_EXPORT void File_Trace(char *name , int flag);

/**
* @brief ����ļ�����
* @param pszSrcFn		[IN]	Դ�ļ���
* @param pDestFn		[IN]	Ŀ���ļ���
* @return 0 ʧ��  1 �ɹ�
*/
LIB_EXPORT  int File_Copy(const char* pszSrcFn, const char* pDestFn);

#ifdef __cplusplus
}
#endif	

#endif
