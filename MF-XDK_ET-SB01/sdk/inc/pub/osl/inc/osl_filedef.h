/*! \file osl_filedef.h
	\brief �ļ�ϵͳ��װ
*	\author lx
*	\date 2014/02/08
*/
//�ļ��궨��
#ifndef _OSL_FILEDEF_H_
#define _OSL_FILEDEF_H_

#ifdef __cplusplus
extern "C"{
#endif


#include "pub\pub.h"



#if WIN32
	#include <io.h>
	#include <fcntl.h>
	#include <sys/stat.h>
	#include <stdio.h>
#elif OS_NOVA
	#include "nova_fs_api.h"
#elif OS_LINUX
	#include <fcntl.h>
	#include <sys/stat.h>
	#include <stdio.h>
#else
	//#include "fatfs\ff.h"
#endif

#if WIN32

#elif OS_NOVA
	#define O_RDONLY		(NOVA_FS_MODE_READ)
	#define O_WRONLY		(NOVA_FS_MODE_WRITE)
	#define O_RDWR			(NOVA_FS_MODE_READ | NOVA_FS_MODE_WRITE)
	#define O_APPEND		(NOVA_FS_MODE_APPEND)

	#define O_CREAT			(NOVA_FS_MODE_CREATE_NEW)	  /* create and open file */
	#define O_TRUNC			(NOVA_FS_MODE_CREATE_ALWAYS)  /* open and truncate */
	#define O_EXCL			(NOVA_FS_MODE_OPEN_EXISTING)  /* open only if file doesn't already exist */

	#define O_BINARY		0x8000 
	#define S_IREAD			0x0100 
	#define S_IWRITE		0x0080 

	#define SEEK_SET        (NOVA_FS_SEEK_BEGIN)			/* seek to an absolute position */
	#define SEEK_CUR        (NOVA_FS_SEEK_CUR)				/* seek relative to current position */
	#define SEEK_END        (NOVA_FS_SEEK_END)				/* seek relative to end of file */



#elif OS_LINUX
	#define O_BINARY		0x0000
#else

	#define O_RDONLY		0x0000  /* open for reading only */
	#define O_WRONLY		0x0001  /* open for writing only */
	#define O_RDWR			0x0002  /* open for reading and writing */
	#define O_APPEND		0x0008  /* writes done at eof */

	#define O_CREAT			0x0100  /* create and open file */
	#define O_TRUNC			0x0200  /* open and truncate */
	#define O_EXCL			0x0400  /* open only if file doesn't already exist */

	#define O_BINARY		0x8000 

	#define S_IREAD			0x0100 
	#define S_IWRITE		0x0080 

	#ifndef SEEK_SET
	#define SEEK_SET        0               /* seek to an absolute position */
	#define SEEK_CUR        1               /* seek relative to current position */
	#define SEEK_END        2               /* seek relative to end of file */
	#endif 

#endif


#if WIN32
#define USE_WIN32_FS	1
#define PATH_MAX_SIZE	512
#elif OS_NOVA
#define USE_NOVA_FS		1
#define PATH_MAX_SIZE	512
#elif OS_LINUX
#define USE_LINUX_FS	1
#define PATH_MAX_SIZE	512
#elif OS_EC100Y | CPU_EC600U

#define USE_EC100Y_FS	1
#define PATH_MAX_SIZE	512


#define C_DISK				"C:"
#define C_ROOT_PATH			""C_DISK"/"

#else
#define USE_FATFS		1
#define PATH_MAX_SIZE	32
#endif


#define FILE_OPEN_FAIL (-1)

#define FILE_INIT			mf_file_init
#define FILE_OPEN			mf_file_open
#define	FILE_CLOSE			mf_file_close 
#define FILE_LSEEK			mf_file_lseek
#define FILE_WRITE			mf_file_write
#define FILE_READ			mf_file_read

#define FILE_UNLINK			mf_file_unlink
#define FILE_DELETE			mf_file_unlink	
//#define FILE_TELL			mf_file_tell
#define FILE_RENAME			mf_file_rename
#define FILE_FLUSH			mf_file_flush
#define FILE_MKDIR			mf_file_mkdir


	
#define FILE_WRITE_FLAG		(O_RDWR|O_CREAT|O_BINARY)
#define FILE_CREAT_FLAG		(O_RDWR|O_TRUNC|O_CREAT|O_BINARY)
#define FILE_WRITE_MODE		(S_IREAD| S_IWRITE)
#define FILE_READ_FLAG		(O_RDONLY|O_BINARY)
#define FILE_READ_MODE		(S_IREAD)

#define CHECK_INIT_FILE	"fileinit.dat"

/**
* @brief �ļ�ϵͳ��ʼ��
* @return 
*/
LIB_EXPORT void mf_file_init();
/**
* @brief ���ļ�
* @param name �ļ�����
* @param flag �򿪱�־
* @param mode ��ģʽ
* @return <0ʧ�� >=0�ļ����
*/
LIB_EXPORT int mf_file_open(const char * name , int flag , int mode);
/**
* @brief �ļ���λ
* @param fp �ļ����
* @param pos λ��
* @param flag ��־
* @return �ƶ���λ��
*/
LIB_EXPORT int mf_file_lseek(int fp , int pos  , int flag);
/**
* @brief д�ļ�
* @param fp �ļ����
* @param buff ������
* @param size ����
* @return ��д�볤��
*/
LIB_EXPORT int mf_file_write(int fp ,const void * buff , unsigned int size);
LIB_EXPORT int mf_file_write2(int fp ,const void * buff , unsigned int size , int sync);
/**
* @brief ���ļ�
* @param fp �ļ����
* @param buff ������
* @param size ����
* @return �Ѷ�ȡ�ĳ���
*/
LIB_EXPORT int mf_file_read(int fp , void * buff , unsigned int size);
/**
* @brief �ر��ļ�
* @param fp �ļ����
* @return 
*/
LIB_EXPORT int mf_file_close(int fp );
/**
* @brief ɾ���ļ�
* @param name �ļ�����
* @return 
*/
LIB_EXPORT int mf_file_unlink(const char * name);
/**
* @brief �������ļ�
* @param oldname ԭ�ļ���
* @param newname ���ļ���
* @return 
*/
LIB_EXPORT int mf_file_rename(const char *oldname ,const char *newname);
/**
* @brief �ļ�ϵͳ�Ƿ��ѳ�ʼ��
* @return 0 δ��ʼ��
*/
LIB_EXPORT int mf_file_get_init();
/**
* @brief ��ʽ���ļ�ϵͳ
* @return 
*/
LIB_EXPORT int mf_file_format();


/**
* @brief ��ȡ�ļ�ϵͳʣ��ռ�
* @return 
*/
LIB_EXPORT int mf_file_space_free(); 

/**
* @brief ��ȡ�ļ�ϵͳ�ռ�
* @return 
*/
LIB_EXPORT int mf_file_total_free();

/**
* @brief �ض��ļ�
* @param fp �ļ����
* @param size �ļ���С
* @return 
*/
LIB_EXPORT int mf_file_truncate(int fp , int size);

/**
* @brief ��������Ŀ¼�����ú�ԭdata��ʼ��·�����滻��data_path
* @param data_path Ŀ¼
* @return 
*/
LIB_EXPORT void mf_file_set_path(char *data_path);

/**
* @brief ����Ŀ¼
* @param data_path Ŀ¼
* @return 
*/
LIB_EXPORT void mf_file_mkdir(char *data_path);

LIB_EXPORT int mf_file_space_task();

LIB_EXPORT void mf_find_dir(char * root , void *pfun);

LIB_EXPORT  int littlefs_test(int sumlen,int datasize);


LIB_EXPORT int osl_remove_file(char* tmppath);

LIB_EXPORT  void littfs_dir();
#if OS_EC100Y |  CPU_EC600U
LIB_EXPORT void * osl_get_lfs();
#endif 
int mf_lock_filesystem(int status);

LIB_EXPORT int osl_remove_file(char* tmppath);


LIB_EXPORT char* str2upper(char *str);

/**
* @brief ɾ��Ƭ�������ļ�
* @param 1:ɾ������DATAĿ¼�������� 2:ɾ����������
* @return 0:�ɹ� ����:ʧ��
*/
LIB_EXPORT int mf_file_clear(int ntype);


LIB_EXPORT int mf_set_disk_name(char* pdiskname);
LIB_EXPORT char* mf_get_disk_name();

LIB_EXPORT int osl_unlock_file();
#ifdef __cplusplus
}
#endif	

#endif	//_FILEDEF_H_


