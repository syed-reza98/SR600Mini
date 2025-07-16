#ifndef __LIBAPI_FILE_HEADER__
#define __LIBAPI_FILE_HEADER__

/**
 * @file libapi_file.h
 * @author guosy(Randy)
 * @brief File system related functions
 * @date 2023-05-19
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#include "libapi_pub.h"
#include "def.h"

#define FILE_OPEN_FAIL (-1)

/**
 * @brief 2.2.9.3	Get File module version
 * @param[in] pszVer Nothing
 * @return 0, Success
 * @return Other, Failure
*/
LIB_EXPORT int UFile_GetModuleVer(char *pszVer);

/**
 * @brief Test files exist(UFile_Check)
 * @param[in] FileName File Name End with NULL
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @return UFILE_NO_EXIST       = -12,             //The specified file does not exist.
 * @return UFILE_SUCCESS        =  0               //Successful file operation
*/
LIB_EXPORT int UFile_Check(cchar *FileName, int iFileLocation);

/**
 * @brief File open / create
 * @param[in] FileName File Name End with NULL
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] Flag Open the file mode and refer to the FileFlags definition.
 * @param[out] fh File handle
 * @param[in] RecSize File record size
		      RecSize = 0,Create open stream file, text file
			  RecSize = 1,Create a non fixed length record (TLV) file
			  8<=RecSize<=4090 Create open fixed length record file
 * @return UFILE_OPEN_FAIL  	= -2,              //Open a mistake
 * @return UFILE_SUCCESS        =  0               //Successful file operation
 * @details For newly created file RecSize, it works.
		    The RecSize parameter should be ignored for opening the created file
*/
LIB_EXPORT int UFile_OpenCreate(cchar *FileName, int iFileLocation, int Flag, FILE_HANDLE *fh, int RecSize);

/**
 * @brief 2.2.9.6	file open
 * @param[in] name File Name End with NULL
 * @param[in] flag Open the file flag
 * @param[in] mode Open the file mode and refer to the FileFlags definition.
 * @return >=0, File handle, Successful
 * @return Other, Failure
*/
LIB_EXPORT int UFile_Open(const char* name, int flag, int mode);

/**
 * @brief 2.2.9.6	file read
 * @param[in] handle read File handle
 * @param[out] buffer 
 * @param[in] size read data size
 * @return File read successfully: the return value is equal to the number of bytes actually read.
 * @details Nothing
*/
LIB_EXPORT int UFile_Read(FILE_HANDLE handle, char *buffer, int size);

/**
 * @brief File writing
 * @param[in] handle File handle to be written
 * @param[in] buffer Data to be written
 * @param[in] size data sizeto be written
 * @return Success The return value equals the number of bytes actually written.
 * @return UFILE_WRITE_FAIL		= -4,			   //Fail      
 * @details Nothing
*/
LIB_EXPORT int UFile_Write(FILE_HANDLE handle, char *buffer, int size);

/**
 * @brief Locating file pointer
 * @param[in] handle File handle
 * @param[in] offset offset
 * @param[in] origin start position
 * @return offset position
 * @details Nothing
*/
LIB_EXPORT long UFile_Lseek(FILE_HANDLE handle, long offset, int origin);

/**
 * @brief 2.2.9.9	delete file record
 * @param[in] handle File handle
 * @param[in] size Deleted File Bytes
 * @return UFILE_DELETE_FAIL	= -7,              delete file record error
 * @return UFILE_SUCCESS        =  0
 * @details Nothing
*/
LIB_EXPORT int UFile_Delete(FILE_HANDLE handle, uint size);

/**
 * @brief 2.2.9.10	Close the file
 * @param[in] handle File handle
 * @return UFILE_PARAERROR      = -11,            //Parameter Error
 * @return UFILE_CLOSE_FAIL		= -8,              //closing file error
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Nothing
*/
LIB_EXPORT int UFile_Close(FILE_HANDLE handle);

/**
 * @brief 2.2.9.11	Delete file
 * @param[in] filename: File Name End with NULL
 * @param[in] iFileLocation: Storage location,Reference enum FILELOCATION
 * @return 0 success
 * @return Other failue
 * @details Nothing
*/
LIB_EXPORT int UFile_Remove(cchar *filename, int iFileLocation);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:2.2.9.11	Delete file£¨UFile_Unlink£©
Input : fileName£ºFile Name End with NULL(use absolute paths,for example: "data\\xxx.ini")

Output : Nothing
return: UFILE_NO_EXIST       = -12,             //The specified file does not exist.
		UFILE_PARAERROR      = -11£¬            //Parameter Error
		UFILE_FAIL			= -1,              //Fail
		UFILE_SUCCESS        =  0              //Successful file operation
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int UFile_Unlink(cchar* filename);
/**
 * @brief 2.2.9.12	Rename file
 * @param[in] oldname Old  FileName
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] newname New FileName
 * @return 0 success
 * @return Other failue
 * @details Nothing
*/
LIB_EXPORT int UFile_Rename(cchar *oldname, int iFileLocation, cchar *newname);

/**
 * @brief 2.2.9.13	Empty File
 * @param[in] FileName File Name End with NULL 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Nothing
*/
LIB_EXPORT int UFile_Clear(cchar *FileName, int iFileLocation);

/**
 * @brief File system remaining space
 * @param[in] drive 0
 * @return Success Return to the remaining space unit K
 * @return UFILE_FAIL			= -1,              //Fail
 * @details Nothing
*/
LIB_EXPORT long UFile_GetFreeSpace(cchar *drive);

/**
 * @brief 2.2.9.15	get record number
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] Record_Len Single Record Len
 * @return Success: record number
 * @return UFILE_FAIL			= -1,              //Fail
 * @details Nothing
*/
LIB_EXPORT int UFile_GetNumberOfRecords(cchar *FileName, int iFileLocation, int Record_Len);

/**
 * @brief 2.2.9.16	AppendRecord
 * @param[in] FileName File Name End with NULL
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] Record Record data
 * @param[in] Record_Len Length of recorded data
 * @return UFILE_FAIL			= -1,              //Fail
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Power off protection
		    At the end of the file, add a fixed length record file. 
		    When the file does not exist, the file is created automatically
*/
LIB_EXPORT int UFile_AppendRecord(cchar *FileName, int iFileLocation, char *Record, int Record_Len);

/**
 * @brief Query record by index
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[out] Record Record data
 * @param[in] Record_Len Record Len
 * @param[in] Record_Index Record index (starting from 0)
 * @return UFILE_NO_RECORD		= -10,             //Record not found
 * @return UFILE_READ_FAIL		= -5,		       //read failure
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Nothing
*/
LIB_EXPORT int UFile_GetRecordByIndex(cchar *FileName, int iFileLocation, void *Record, int Record_Len, int Record_Index);

/**
 * @brief Query record
 * @param[in] FileName File Name
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[out] Record Record data
 * @param[in] Record_Len Record Len
 * @param[in] Condtion For reference, refer to DBSearCond structure.
 * @return UFILE_NO_RECORD		= -10,             //Record not found
 * @return UFILE_READ_FAIL		= -5,			   //read failure
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Nothing
*/
LIB_EXPORT int UFile_GetRecord(cchar *FileName, int iFileLocation, void *Record, int Record_Len, DBSEARCOND *Condtion);

/**
 * @brief Update record
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in][out] Record Record data
 * @param[in] Record_Len Record Len
 * @param[in] Condtion For reference, refer to DBSearCond structure.
 * @return UFILE_NO_RECORD		= -10,             //Record not found
 * @return UFILE_READ_FAIL		= -5,			   //read failure
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Power off protection,
		    Record is both a reference and a reference. 
		    In search of Success, Record is filled with search results
*/
LIB_EXPORT int UFile_UpdateRecord(cchar *FileName, int iFileLocation, void *Record, int Record_Len, DBSEARCOND *Condtion);

/**
 * @brief Update record according to index number
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in][out] Record Record data
 * @param[in] Record_Len Record Len
 * @param[in] Index Record Index
 * @return UFILE_NO_RECORD		= -10,             //Record not found
 * @return UFILE_READ_FAIL		= -5,
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Power off protection,
		    Record is both a reference and a reference. 
		    In search of Success, Record is filled with search results
*/
LIB_EXPORT int UFile_UpdateRecordByIndex(cchar *FileName, int iFileLocation, void *Record, int Record_Len, uint Index);

/**
 * @brief Write data Block By file name
 * @param[in] file_name File Name 
 * @param[in] write_start the offset start to write
 * @param[in] write_buff the buffer to write
 * @param[in] write_size the size to write
 * @return actual size wrote
 * @details Nothing
*/
LIB_EXPORT int UFile_WriteBlockByName(char * file_name,int write_start, char * write_buff,int write_size);

/**
 * @brief 2.2.9.21	Delete record by deleting any record by condition.
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] Record_Len Record Len
 * @param[in] Condtion For reference, refer to DBSearCond structure.
 * @return UFILE_NO_RECORD		= -10,             //Record not found
 * @return UFILE_DELETE_FAIL	= -7,              //delete file record error
 * @return UFILE_OPEN_FAIL  	= -2,              //Open a mistake
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Power off protection
*/
LIB_EXPORT int UFile_DeleteRecord(cchar *FileName, int iFileLocation, int Record_Len, DBSEARCOND *Condtion);

/**
 * @brief 2.2.9.22	Delete record based on index number
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] Record_Len Record Len
 * @param[in] Index Record Index
 * @return UFILE_NO_RECORD		= -10,             //Record not found
 * @return UFILE_DELETE_FAIL	= -7,              delete file record error
 * @return UFILE_OPEN_FAIL  	= -2,              //Open a mistake
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Power off protection
*/
LIB_EXPORT int UFile_DeleteRecordByIndex(cchar *FileName, int iFileLocation, int Record_Len, uint Index);

/**
 * @brief Read a line of text and support \r \n wrap
 * @param[in] pFile File Handle
 * @param[out] pLineBuff Line Buff Size
 * @param[in] LineBuffSize Text data read
 * @return UFILE_FAIL			= -1,              //Fail
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details For text files, read one row of data from the current location and jump to the next line.
*/
LIB_EXPORT int UFile_ReadLine(FILE_HANDLE pFile, char *pLineBuff,uint LineBuffSize);

/**
 * @brief Read the non fixed length record
		  to read the non fixed length record TLV, which is consistent with the IC card TVL format.
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] FldID (Tag)
 * @param[out] Data (Value)
 * @param[out] DataLen (length)
 * @return UFILE_NO_RECORD		= -10,             //Record not found
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Read the record in TLV format
*/
LIB_EXPORT int UFile_ReadTLV(char *FileName, int iFileLocation, uint FldID, char *Data, uint *DataLen);

/**
 * @brief Writing non fixed length data
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] FldID (Tag)
 * @param[in] Data (Value)
 * @param[in] DataLen (length)
 * @return UFILE_WRITE_FAIL		= -4,			   //Write failed
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Nothing
*/
LIB_EXPORT int UFile_WriteTLV(char *FileName, int iFileLocation, uint FldID, char *Data, uint DataLen);

/**
 * @brief 2.2.9.26	Delete non fixed length record
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @param[in] FldID (Tag)
 * @return UFILE_WRITE_FAIL		= -4,			   //Write failed
 * @return UFILE_SUCCESS        =  0              //Successful file operation
 * @details Nothing
*/
LIB_EXPORT int UFile_DeleteTLV(char *FileName, int iFileLocation, uint FldID);

/**
 * @brief Obtain file length
 * @param[in] FileName File Name 
 * @param[in] iFileLocation Storage location,Reference enum FILELOCATION
 * @return length
 * @details Nothing
*/
LIB_EXPORT int UFile_GetLength(cchar *FileName, int iFileLocation);
LIB_EXPORT void UFile_Path_clean(char* path);
LIB_EXPORT void UFile_clean(void);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions: Test files exist
Input : FilePath:File path
Output : Nothing
return: UFILE_NO_EXIST       = -12,             //The specified file does not exist.
		UFILE_PARAERROR      = -11,            //Parameter Error
		UFILE_SUCCESS        =  0               //Successful file operation
Remarks: Nothing
eg.UFile_Check_Ex("lang1\\test.mp3");
*************************************************************************************/
LIB_EXPORT int UFile_Check_Ex(cchar* FilePath);
/**
 * @brief write a profile int to a ini file
 * @param[in] section name of the section,can't be NULL and empty string
 * @param[in] key name of the key pairs to value, can't be NULL and empty string
 * @param[in] value profile int value
 * @param[in] file path of ini file
 * @return 1  success
 * @return 0  failure
 * @details Nothing
*/
LIB_EXPORT int  UFile_write_profile_int(const char* section, const char* key, int value, const char* file);

/**
 * @brief write a profile string to a ini file
 * @param[in] section name of the section,can't be NULL and empty string
 * @param[in] key name of the key pairs to value, can't be NULL and empty string
 * @param[in] value profile string value
 * @param[in] file path of ini file
 * @return 1  success
 * @return 0  failure
 * @details Nothing
*/
LIB_EXPORT int  UFile_write_profile_string(const char* section, const char* key, const char* value, const char* file);

/**
 * @brief read int value in initialization file\n
		  * retrieves int value from the specified section in an initialization file
 * @param[in] section name of the section containing the key name
 * @param[in] key name of the key pairs to value 
 * @param[in] default_value default value of result
 * @param[in] file path of the initialization file
 * @return 1  success
 * @return 0  failure
 * @details Nothing
*/
LIB_EXPORT int  UFile_read_profile_int(const char* section, const char* key, int default_value, const char* file);

/**
 * @brief read string in initialization file\n
		  * retrieves a string from the specified section in an initialization file
 * @param[in] section name of the section containing the key name
 * @param[in] key name of the key pairs to value 
 * @param[in] value pointer to the buffer that receives the retrieved string
 * @param[in] size size of result's buffer 
 * @param[in] default_value default value of result
 * @param[in] file path of the initialization file
 * @return 1  success
 * @return 0  failure
 * @details Nothing
*/
LIB_EXPORT int  UFile_read_profile_string(const char* section, const char* key, char* value, int size, const char* default_value, const char* file);

LIB_EXPORT void UFile_mkdir(char* dirName);
LIB_EXPORT void UFile_clean();
LIB_EXPORT void UFile_Path_clean(char* path);


#endif /*__LIBAPI_FILE_HEADER__*/
