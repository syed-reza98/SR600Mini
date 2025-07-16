#ifndef _DEV_FILE_H
#define _DEV_FILE_H

#include "pub/pub.h"

#define FILE_NOCREATEINDEX 0x00	/*�����������ļ�*/
#define FILE_CREATEINDEX 0x01		/*���������ļ�*/
#define MAX_FILENAME_LEN 256		/*�ļ�����󳤶�*/

typedef struct tagRecFile
{
	unsigned int unMaxOneRecLen;	/*���ĵ�����¼����*/  
	unsigned int unIndex1Start;	/*�����ֶ�1����ʼλ��*/
	unsigned int unIndex1Len;		/*�����ֶ�1�ĳ���*/
	unsigned int unIndex2Start; 	/*�����ֶ�2����ʼλ��*/
	unsigned int unIndex2Len;		/*�����ֶ�2�ĳ���*/
	char cIsIndex;				/*�Ƿ���Ҫ���������ļ���0x00��������0x01����*/
	char szFileName[MAX_FILENAME_LEN+1];		/*��¼�ļ���,��Ч�ļ�¼�ļ�������Ϊ8*/
	char s[2];
}STRECFILE;

/******************************************************************************
*	�������ƣ�Ex_File_CreatFile
*	�������ܣ������ļ�
*	����������
*	��ڲ�����const STRECFILE *pstRecFile �ļ�ͷ��Ϣ
*	���ڲ�����
*	����ֵ  ��
*				SUCC �ɹ�
*				FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_CreatFile(const STRECFILE *pstRecFile);
/******************************************************************************
*	�������ƣ�Ex_File_DelFile
*	�������ܣ�ɾ���ļ�
*	����������
*	��ڲ�����const char *pszFileName ��ˮ�ļ���
*	���ڲ�����
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_DelFile (const char *pszFileName);
/******************************************************************************
*	�������ƣ�Ex_File_GetRecSum
*	�������ܣ����ļ������ļ�����ȡ�ļ���¼����
*	����������
*	��ڲ�����
*		const char *pszFileName ��ˮ�ļ���
*	���ڲ�����
*		int *pnRecSum ָ���¼������ָ��
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_GetRecSum (const char *pszFileName, int *pnRecSum);
/******************************************************************************
*	�������ƣ�Ex_File_AddRecByName
*	�������ܣ�������ˮ��¼�����ڴ�����¼��ָ������Ҫ���������ļ��Ļ���Ӧ����������¼��
*	����������
*	��ڲ�����
*		const char *pszFileName ��ˮ�ļ���
*		const char *pszRec �������ˮ��¼
*	���ڲ�������
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_AddRecByName (const char *pszFileName, const char *pszRec);
/******************************************************************************
*	�������ƣ�Ex_File_UpdateRecByName
*	�������ܣ����¼�¼
*	�����������޸ļ�¼����ָ���ļ�¼λ����дָ���ļ�¼��
*				   ͬʱ���ڴ�����¼��ָ������Ҫ���������ļ���
*				   ����Ӧ����������¼��
*	��ڲ�����
*		const char *pszFileName ��¼�ļ�����
*		const int nRecNo Ҫ�޸ĵļ�¼��
*		char *psRec ��¼ָ��
*	���ڲ�����
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_UpdateRecByName (const char *pszFileName, const int nRecNo, const char *psRec);
/******************************************************************************
*	�������ƣ�Ex_File_ReadRecByName
*	�������ܣ�����¼�Ŷ�ȡ������¼
*	����������
*	��ڲ�����
*		const char *pszFileName ��¼�ļ�����
*		const int nRecNo Ҫ�޸ĵļ�¼��
*		char *psRec ��¼ָ��
*	���ڲ�����
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_ReadRecByName(const char *pszFileName, const int nRecNo, char *psRec);
/******************************************************************************
*	�������ƣ�DelRecByFileName
*	�������ܣ�������ɾ����¼
*	�������������������ֶ�1/�����ֶ�2��ָ���ļ�¼�ſ�ʼ���Ҳ�ɾ����¼��
*				   ��ͬʱָ�������ֶ�1/�����ֶ�2����Ҫͬʱ����������
*				   �����ļ�¼�������ָ��ʱ��NULL,���������������ļ�¼
*				   �����ظ�������������һ����¼��
*	��ڲ�����
*		const char *pszFileName ��¼�ļ�����
* 		const char *psIndexStr1 �����ֶ�1
*		const char *psIndexStr2 �����ֶ�2
*	���ڲ�����
*		��
*	����ֵ  ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_DelRecByName(const char *pszFileName, const char *psIndexStr1,const char *psIndexStr2);
/******************************************************************************
*	�������ƣ�Ex_File_ReadRecByHandle
*	�������ܣ�����¼�Ŷ���ˮ��¼��
*	����������
*	��ڲ�����
*		const int nFileHandle �򿪵��ļ����
*		const int nRecNo Ҫ�ҵļ�¼��
*	���ڲ�����
*		char *psRec ��¼ָ��
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_ReadRecByHandle (const int nFileHandle, const int nRecNo, char *psRec , const char *pszName);
/******************************************************************************
*	�������ƣ�Ex_File_UpdateRecByHandle
*	�������ܣ����¼�¼
*	�����������޸ļ�¼����ָ���ļ�¼λ����дָ���ļ�¼��
*				   ͬʱ���ڴ�����¼��ָ������Ҫ���������ļ���
*				   ����Ӧ����������¼��
*	��ڲ�����
*		int  nFileHandle ��¼�ļ����
*		const int nRecNo Ҫ�޸ĵļ�¼��
*		char *psRec ��¼ָ��
*	���ڲ�����
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_UpdateRecByHandle (int nFileHandle, const int nRecNo, const char *psRec);
/******************************************************************************
*	�������ƣ�Ex_File_FindRec
*	�������ܣ����������Ҽ�¼
*	�������������������ֶ�1/�����ֶ�2��ָ���ļ�¼�ſ�ʼ���Ҽ�¼��
*				   ��ͬʱָ�������ֶ�1/�����ֶ�2����Ҫͬʱ����������
*				   �����ļ�¼�������ָ��ʱ��NULL,���������������ļ�¼
*				   �����ظ�������������һ����¼��
*	��ڲ�����
*		const char *pszFileName ��¼�ļ�����
* 		const char *psIndexStr1 �����ֶ�1
*		const char *psIndexStr2 �����ֶ�2
*		const int nBeginRecNo ָ���Ŀ�ʼ��¼��
*	���ڲ�����
*		char *psRec ��¼ָ��
*		int *pnRecNo ���������ļ�¼��
*	����ֵ  ��
*		SUCC �ɹ�
*		FAIL   ʧ��
*******************************************************************************/
LIB_EXPORT extern int Ex_File_FindRec(const char *pszFileName, const char *psIndexStr1,
			   const char *psIndexStr2,const int nBeginRecNo, char *psRec, int *pnRecNo);
/******************************************************************************
 *  	��������:	Ex_File_GetParam: 
 *	��������:	�Ӳ����ļ��ж�ȡ������Ϣ
 *	��ڲ���:	nOff ����ƫ�Ƶ�ַ
 					nLen �������ݳ���
 *	���ڲ���:     pszOutData ����ַ���ָ��
 * 	����ֵ  :		
 ******************************************************************************/
LIB_EXPORT int Ex_File_GetParam(char *pszFileName,char *pszOutData, int nOff, int nLen);
//�Ӵ�ͷ�Ĳ����ļ��ж�ȡ������Ϣ
LIB_EXPORT int Ex_FileHead_GetParam(char *pszFileName,char *pszOutData, int nOff, int nLen);
/******************************************************************************
 *  	��������:	Ex_File_SaveParam: 
 *	��������:	��������������ļ���
 *	��ڲ���:	pszFileName �ļ���
 					nOff ����ƫ�Ƶ�ַ
 					nLen �������ݳ���
 					pszInData ������ַ���ָ��
 *	���ڲ���:     
 * 	����ֵ  :		SUCC
 					FAIL
 ******************************************************************************/
LIB_EXPORT extern int Ex_File_SaveParam(char *pszFileName,char *pszInData, int nOff, int nLen);
#endif