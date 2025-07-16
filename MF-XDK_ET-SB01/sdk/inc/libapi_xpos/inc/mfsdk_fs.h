/**
 * @file mfsdk_fs.h
 * @author CHAR
 * @brief 
 * @date 2023-11-18
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_FS_H__
#define __MFSDK_FS_H__
#include "mfsdk_define.h"

typedef DBSEARCOND MfSdkFsDbSearCond_T;
typedef enum
{
	MFSDK_FS_RET_CREATE_FAIL = -20,//create error
	MFSDK_FS_RET_OPEN_FAIL = -19, //open error
	MFSDK_FS_RET_READ_FAIL = -18, //read error,
	MFSDK_FS_RET_WRITE_FAIL = -17, //write error,
	MFSDK_FS_RET_SEEK_FAIL = -18, //seek error,
	MFSDK_FS_RET_DELETE_FAIL = -16, //delete error,
	MFSDK_FS_RET_REMOVE_FAIL = -15, //remove error,
    MFSDK_FS_RET_NO_RECORD = -10,                 ///< Record not found
    MFSDK_FS_RET_CLOSE_FAIL	= -8,              ///< Close file error
    MFSDK_FS_RET_NOEXIST = -4,     //no found file
    MFSDK_FS_RET_FAILED = -3,     //failed
    MFSDK_FS_RET_BOUNDS = -2,     //Array out-of-bounds
    MFSDK_FS_RET_PARM_ERROR = -1,     //check param
    MFSDK_FS_RET_OK = 0,
}MfSdkFsRet_E;

#define MFSDK_FS_SEEK_SET (FILE_SEEK_SET)      ///< To the file header
#define MFSDK_FS_SEEK_CUR (FILE_SEEK_CUR)      ///< To the current location
#define MFSDK_FS_SEEK_END (FILE_SEEK_END)      ///< To the end of the file

#define MFSDK_FS_RDONLY	(FILE_RDONLY)	 	///< Read-only, there is no return error
#define MFSDK_FS_WRONLY	(FILE_WRONLY)    	///< Write only, there is no return error
#define MFSDK_FS_RDWR	(FILE_RDWR)      	///< Read and write, there is no return error
#define MFSDK_FS_APPEND	(FILE_APPEND)     ///< Append, create if it does not exist, pointer to the end of the file when it exists
#define MFSDK_FS_CREAT	(FILE_CREAT)      ///< Create, delete rebuild when it already exists

#define MFSDK_FS_PRIVATE (FILE_PRIVATE)  	///< Private, this file is stored in the current sub-application directory, other sub-applications are inaccessible
#define MFSDK_FS_PUBLIC  (FILE_PUBLIC)   	///< Publicly, this file is stored in a public location and accessible to all sub-applications

typedef enum
{
	MFSDK_FS_FLAG_WRITE, // read and write
	MFSDK_FS_FLAG_CREAT, // if file does not exist create it ,if file exist will be truncated to length 0.
	MFSDK_FS_FLAG_READ, // only read
}MfSdkFsFlag_E;
typedef enum
{
	MFSDK_FS_MODE_READ, // only read
	MFSDK_FS_MODE_WRITE,// read and write
}MfSdkFsMode_E;

typedef struct
{
    s32 d_ino;            ///< inode number, file system implementation can use it for any purpose
    u8 d_type;		  ///<  8-file,other- dir type of file
    char d_name[256];     ///< file name
}MfSdkDirent_T;

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief set file path
 * 
 * @param[in] const s8 *pPath path
 * @return MFSDK_FS_RET_OK success
 */
LIB_EXPORT s32 MfSdkFsSetPath(const s8 *pPath);
/**
 * @brief check if file exist
 * 
 * @param[in] const s8 *FileName  file path and name 
 * @return MFSDK_FS_RET_OK , The file exists
 * @return MFSDK_FS_RET_NOEXIST , The file does not exist 
 */
LIB_EXPORT s32 MfSdkFsCheckPath(const s8 *FileName);
/**
 * @brief delete all files
 * 
 * @return MFSDK_FS_RET_OK, success
 */
LIB_EXPORT s32 MfSdkFsClean();
/**
 * @brief Close the file
 * 
 * @param[in] FILE_HANDLE handle  file handler
 * @return MFSDK_FS_RET_OK close success
 * @return MFSDK_FS_RET_CLOSE_FAIL fail
 * @return MFSDK_FS_RET_PARM_ERROR file handler invalid
 */
LIB_EXPORT s32 MfSdkFsClose(FILE_HANDLE handle);
/**
 * @brief File truncation
 * 
 * @param[in] FILE_HANDLE handle file handler
 * @param[in] u32 size truncate size
 * @return MFSDK_FS_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkFsDelete(FILE_HANDLE handle, u32 size);
/**
 * @brief File system remaining space
 * For example: MfSdkFsGetFreeSpace("");
 * @param[in] const s8 *drive default ""
 * @return >0 success, the remaining space unit:KB
 * @return -1 fail
 */
LIB_EXPORT long MfSdkFsGetFreeSpace(const s8 *drive);

/**
 * @brief File system total space
 * For example: MfSdkFsGetTotalSpace("");
 * @param[in] const s8 *drive default ""
 * @return >0 success, the remaining space unit:KB
 * @return -1 fail
 */
LIB_EXPORT long MfSdkFsGetTotalSpace(const s8 *drive);

/**
 * @brief Get File module version
 * 
 * @param[out] char *pszVer
 * @return MFSDK_FS_RET_OK, success
 * @return Other, fail
 */
LIB_EXPORT s32 MfSdkFsGetModuleVer(char *pszVer);
/**
 * @brief Locating file pointer
 * 
 * @param[in] FILE_HANDLE handle file handler
 * @param[in] long offset
 * @param[in] s32 origin start position
 * @return >= 0 success, offset position
 * @return Other fail
 */
LIB_EXPORT long MfSdkFsLseek(FILE_HANDLE handle, long offset, s32 origin);
/**
 * @brief mkdir
 * 
 * @param[in] s8* dirName
 * @return MFSDK_FS_RET_OK success
 */
LIB_EXPORT s32 MfSdkFsMkdir(s8* dirName);
/**
 * @brief file open
 * 
 * @param[in] const s8* name File Name End with NULL
 * @param[in] s32 flag Open the file flag Ref.MfSdkFsFlag_E
 * @param[in] s32 mode Open the file mode and refer to the MfSdkFsMode_E definition.
 * @return >=0 , success ,file handler
 * @return Other ,fail
 */
LIB_EXPORT s32 MfSdkFsOpen(const s8* name, s32 flag, s32 mode);
/**
 * @brief 
 * 
 * @param[] s8* path
 * @return MFSDK_FS_RET_OK success
 */
LIB_EXPORT s32 MfSdkFsPathClean(s8* path);
/**
 * @brief file read
 * 
 * @param[in] FILE_HANDLE handle file handler
 * @param[out] char *buffer read buffer
 * @param[in] s32 size read size
 * @return  File read successfully: the return value is equal to the number of bytes actually read.
 * @return  MFSDK_FS_RET_READ_FAIL  fail
 */
LIB_EXPORT s32 MfSdkFsRead(FILE_HANDLE handle, char *buffer, s32 size);
/**
 * @brief Read a line of text and support
 * @param[in] pFile File Handle
 * @param[out] pLineBuff Line Buff Size
 * @param[in] LineBuffSize Text data read
 * @return MFSDK_FS_RET_FAILED
 * @return MFSDK_FS_RET_OK
 * @details For text files, read one row of data from the current location and jump to the next line.
*/

LIB_EXPORT s32 MfSdkFsReadLine(FILE_HANDLE pFile, s8 *pLineBuff,u32 LineBuffSize);
/**
 * @brief read int value in initialization file
 * 
 * @param[in] const s8* section  name of the section containing the key name
 * @param[in] const s8* key name of the key pairs to value
 * @param[in] s32 default_value   default value of result
 * @param[in] const s8* file path of the initialization file
 * @return  profile int value,if read fail, return default value
 */
LIB_EXPORT s32 MfSdkFsReadProfileInt(const s8* section, const s8* key, s32 default_value, const s8* file);
/**
 * @brief  read string in initialization file
 * 
 * @param[in] const s8* section name of the section containing the key name
 * @param[in] const s8* key name of the key pairs to value 
 * @param[out] s8* value pointer to the buffer that receives the retrieved string
 * @param[in] s32 size size of result's buffer 
 * @param[in] const s8* default_value default value of result
 * @param[in] const s8* file path of the initialization file
 * @return 1 : read success;  0 : read fail
 */
LIB_EXPORT s32 MfSdkFsReadProfileString(const s8* section, const s8* key, s8* value, s32 size, const s8* default_value, const s8* file);

/**
 * @brief
 * 
 * @param[in] const s8 * filename  remove
 * @return Ref. MfSdkFsRet_E
 */
LIB_EXPORT s32 MfSdkFsUnlink(const s8 * filename);
/**
 * @brief File writing
 * @param[in] handle File handle to be written
 * @param[in] buffer Data to be written
 * @param[in] size data sizeto be written
 * @return Success The return value equals the number of bytes actually written.
 * @return MFSDK_FS_RET_WRITE_FAIL Fail  
 * @return write size
*/
LIB_EXPORT s32 MfSdkFsWrite(FILE_HANDLE handle, char *buffer, s32 size);

/**
 * @brief This includes writing through or flushing a disk cache if present
 * @param[in] handle File handle to be written
 * @param[in] buffer Data to be written
 * @param[in] size data sizeto be written
 * @param[in] bSync 
 * @return Success The return value equals the number of bytes actually written.
 * @return MFSDK_FS_RET_WRITE_FAIL Fail  
 * @return write size
*/
LIB_EXPORT s32 MfSdkFsWriteSync(FILE_HANDLE handle, char *buffer, s32 size, MFSDKBOOL bSync);

/**
 * @brief write one block data
 * 
 * @param[in] s8 * file_name  file name
 * @param[in] s32 write_start start offset
 * @param[in] s8 * write_buff write data
 * @param[in] s32 write_size  write data count
 * @return > 0 Write the actual length
 * @return other fail
 */
LIB_EXPORT s32 MfSdkFsWriteBlockByName(s8 * file_name, s32 write_start, s8 * write_buff, s32 write_size);
/**
 * @brief write a profile int to a ini file
 * 
 * @param[in] const s8* section name of the section,can't be NULL and empty string
 * @param[in] const s8* key name of the key pairs to value, can't be NULL and empty string
 * @param[in] s32 value profile int value
 * @param[in] const s8* file ath of ini file
 * @return  1 : success, 0 : failure
 */
LIB_EXPORT s32 MfSdkFsWriteProfileInt(const s8* section, const s8* key, s32 value, const s8* file);
/**
 * @brief write a profile string to a ini file
 * 
 * @param[] const s8* section name of the section,can't be NULL and empty string
 * @param[] const s8* key  name of the key pairs to value, can't be NULL and empty string
 * @param[] const s8* value  profile string value
 * @param[] const s8* file path of ini file
 * @return 1 : success, 0 : failure
 */
LIB_EXPORT s32 MfSdkFsWriteProfileString(const s8* section, const s8* key, const s8* value, const s8* file);
/**
 * @brief renames a file, moving it between directories if required
 * 
 * @param[in] const char *oldName
 * @param[in] const char *newName
 * @return MFSDK_FS_RET_PARM_ERROR input params NULL
 * @return MFSDK_FS_RET_OK success
 */
LIB_EXPORT s32 MfSdkFsRenamePath(const char *oldName, const char *newName);

/**
 * @brief get file length
 * 
 * @param[in] const char *fileName
 * @return MFSDK_FS_RET_PARM_ERROR	fileName==NULL
 * @return >= 0 file length
 */
LIB_EXPORT s32 MfSdkFsGetFileLength(const char *fileName);

/**
 * @brief truncate to 0
 * 
 * @param[in] cchar *FileName
 * @return MFSDK_FS_RET_OK
 */
LIB_EXPORT s32 MfSdkFsClearFile(cchar *FileName);

/**
 * @brief open directory
 * 
 * @param[in] const char *path
 * @return dir pointer
 */
LIB_EXPORT void *MfSdkFsOpenDir(const char *path);

/**
 * @brief read directory
 * 
 * @param[in] void *dp dir pointer
 * @return  MfSdkDirent_T pointer
 */
LIB_EXPORT MfSdkDirent_T* MfSdkFsReadDir(void *dp);

/**
 * @brief close directory
 * 
 * @param[in] void *dp
 * @return Ref. MfSdkFsRet_E
 */
LIB_EXPORT s32 MfSdkFsCloseDir(void *dp);

/**
 * @brief Delete the files in the directory
 * 
 * @param[in] const char* path
 * @return MFSDK_FS_RET_OK, success
 * @return MFSDK_FS_RET_NOEXIST, the directory does not exist
 * @return MFSDK_FS_RET_FAILED, not support
 */
 
LIB_EXPORT s32 MfSdkFsDelDirFiles(const char* path);
/**
 * @brief Delete the directory and delete the files 
 * and directories in the directory 
 * 
 * @param[in] const char *path
 * @return Ref. MfSdkFsRet_E
 */
LIB_EXPORT s32 MfSdkFsRmDir(const char *path);

/**
 * @brief File or directory rename.
 * 
 * @param[in] const char *oldpath
 * @param[in] const char *newpath
 * @return Ref. MfSdkFsRet_E
 */
LIB_EXPORT s32 MfSdkFsRenameA(const char *oldpath, const char *newpath);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_FS_H__ */
