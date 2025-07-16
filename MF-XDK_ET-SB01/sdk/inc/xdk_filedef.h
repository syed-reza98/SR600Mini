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
#ifndef O_RDONLY
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
#endif
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



	
#define FILE_WRITE_FLAG		(O_RDWR|O_CREAT|O_BINARY)
#define FILE_CREAT_FLAG		(O_RDWR|O_TRUNC|O_CREAT|O_BINARY)
#define FILE_WRITE_MODE		(S_IREAD| S_IWRITE)
#define FILE_READ_FLAG		(O_RDONLY|O_BINARY)
#define FILE_READ_MODE		(S_IREAD)

#define CHECK_INIT_FILE	"fileinit.dat"


/**
* @brief Open the file
* @param name File name
* @param flag Open the sign
* @param mode Open mode
* @return <0 fail >=0 file handle
*/
LIB_EXPORT int mf_file_open(const char * name , int flag , int mode);
/**
* @brief File Location
* @param fp File handle
* @param pos position
* @param flag sign
* @return Location of movement
*/
LIB_EXPORT int mf_file_lseek(int fp , int pos  , int flag);
/**
* @brief Writing Documents
* @param fp File handle
* @param buff Buffer
* @param size length
* @return Written length
*/
LIB_EXPORT int mf_file_write(int fp ,const void * buff , unsigned int size);
LIB_EXPORT int mf_file_write2(int fp ,const void * buff , unsigned int size , int sync);
/**
* @brief read file
* @param fp file handle
* @param buff buffer
* @param size length
* @return Read Length
*/
LIB_EXPORT int mf_file_read(int fp , void * buff , unsigned int size);
/**
* @brief Close files
* @param fp file handle
* @return 
*/
LIB_EXPORT int mf_file_close(int fp );
/**
* @brief Delete files
* @param name File name
* @return 
*/
LIB_EXPORT int mf_file_unlink(const char * name);







#ifdef __cplusplus
}
#endif	

#endif	//_FILEDEF_H_


