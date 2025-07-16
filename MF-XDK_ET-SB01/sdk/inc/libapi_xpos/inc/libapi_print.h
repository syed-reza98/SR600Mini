#ifndef __LIBAPI_PRINT_HEADER__
#define __LIBAPI_PRINT_HEADER__

/**
 * @file libapi_print.h
 * @author chenyue(Ronaldo)
 * @brief Print correlation function
 * @date 2023-05-17
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#include "libapi_pub.h"

#define		UPRN_SUCCESS             0		      ///<Success
#define		UPRN_FAIL				-1		      ///<Printer unknown fault
#define		UPRN_DEV_FAIL           -2			  ///<Printer device failure
#define		UPRN_OUTOF_PAPER        -3            ///<The printer is out of paper
#define		UPRN_LOSE_COMMAND       -4            ///<Print handle not obtained
#define		UPRN_FILE_FAIL          -5            ///<Fail to open the file
#define		UPRN_HANDLE_BACK        -6            ///<Split machine handle is not put back
#define		UPRN_CACHE_ERR          -7            ///<Save cache failed


/**
 * @brief Get version number of print class module.
 * 
 * @param[out] pszVer Module version number
 * @return 0,success
 * @return other,fail
 */
LIB_EXPORT int UPrint_GetModuleVer(char *pszVer);


/**
 * @brief Initialize, check the printer status (if it is out of paper), set the print font, use before printing.
 * 
 * @return 0,success
 * @return -3,The printer is out of paper;
 */
LIB_EXPORT int UPrint_Init(void);

/**
 * @brief String printing with automatic line break function, support \r, \n newline
 * 
 * @param[in] str Need to print string information
 * @param[in] linegap Line spacing: unit pixels, 0 is the default value (for Pin printing use)
 * @param[in] newline 0 Does not support line breaks;1 support \r, \n newline
 * @return 0,success
 * @return other,fail
 * @details Save the string to the printer cache and call Print Start (Print_Start) to print
 */
LIB_EXPORT int UPrint_Str(char *str, int linegap, byte newline);

/**
 * @brief print image (XXX.bmp)
 * 
 * @param[in] BmpFile Image file name (XXX.bmp)
 * @param[in] pattern Alignment: 0 left alignment, 1 center alignment, 2 right alignment
 * @return 0,success
 * @return other,fail
 * @details Automatic line wrap is not supported;
			Internal processing of half-word problems, no half-words appear when displayed;
			Only the font part is reversed.
 */
LIB_EXPORT int UPrint_BitMap(char *BmpFile,byte pattern);

/**
 * @brief Start printing
 * 
 * @return 	-6,UPRN_HANDLE_BACK   	Split machine handle is not put back;
 * @return	-5,UPRN_FILE_FAIL     	Fail to open the file;
 * @return	-4,UPRN_LOSE_COMMAND  	Print handle not obtained;
 * @return	-3,UPRN_OUTOF_PAPER   	The printer is out of paper;
 * @return	-2,UPRN_DEV_FAIL      	Printer device failure;
 * @return	-1,UPRN_FAIL          	Printer unknown fault;
 * @return	0,UPRN_SUCCESS        	Success ;
* @details Thermal printing: no more blank lines (processed by the application layer) are required after printing is completed;
		Needle printing: automatic page change after printing is completed.
 */
LIB_EXPORT int UPrint_Start(void);

/**
 * @brief String printing (UPrint_StrBold) with automatic line feed function, support \r, \n newline
 * 
 * @param[in] pszStr Need to print string information
 * @param[in] cPattern Print position: 0 left, 1 center, 2 right
 * @param[in] nLinegap Line spacing, unit pixels, 0 is the default value (for Pin printing use)
 * @param[in] newline 0 Does not support line breaks;1 support \r, \n newline
 * @return 	-7,UPRN_CACHE_ERR    Save cache failed;
 * @return	0,UPRN_SUCCESS  	Success ;
 * @details Save the string to the printer cache and call Print Start (Print_Start) to print			
 */
LIB_EXPORT int UPrint_StrBold(char *pszStr, byte cPattern,int nLinegap, byte newline);

/**
 * @brief Printer paper
 * 
 * @param[in] nFeedLines nFeedLines   Paper length (pixels)
 * @return 	-7,UPRN_CACHE_ERR    Save cache failed;
 * @return	0,UPRN_SUCCESS  	Success;
 * @details Thermal printing: can only support paper feeding
			Needle printing: support for paper withdrawal and paper feeding		
 */
LIB_EXPORT int UPrint_Feed(int nFeedLines);

/**
 * @brief Print QR code,Convert incoming data to QR code and print
 * 
 * @param[in] psMatrixCode QR code data
 * @param[in] nLen QR code data length
 * @param[in] cSize QR code size, 0-small, 1-medium, 2-large
 * @param[in] cPattern Alignment, 0 left alignment, 1 center alignment, 2 right alignment
 * @return 	-7,UPRN_CACHE_ERR    Save cache failed;
 * @return	0,UPRN_SUCCESS  	Success ;
 */
LIB_EXPORT int UPrint_MatrixCode(const char *psMatrixCode, int nLen,byte cSize,byte cPattern);

/**
 * @brief Set print font(English)
 * 
 * @param[in] size Set print English font size(0--8)
 * @param[in] zoom_w Set the horizontal magnification of English(1--5)
 * @param[in] zoom_h Set the vertical magnification of English(1--5)
 * @return	0,UPRN_SUCCESS  	Success ;
 */
LIB_EXPORT int UPrint_SetFont(int size, int zoom_w, int zoom_h);

/**
 * @brief Set print font(Chinese)
 * 
 * @param[in] size Set print other font size(0--1)
 * @param[in] zoom_w Set the horizontal magnification of English(1--5)
 * @param[in] zoom_h Set the vertical magnification of English(1--5)
 * @return	0,UPRN_SUCCESS  	Success ;
 */
LIB_EXPORT int UPrint_SetFontcn(int size, int zoom_w, int zoom_h);

/**
 * @brief Set print density
 * 
 * @param[in] v Set print density (1--5, 3 is normal)
 * @return	0,UPRN_SUCCESS  	Success ;
 */
LIB_EXPORT int UPrint_SetDensity(int v);

/**
 * @brief set the follow print buffer align format
 * 
 * @param[in] nAlign 0 left, 1 center, 2 right
 * @return Nothing 
 */
LIB_EXPORT void UPrint_Set_Align(int nAlign);

/**
 * @brief set the line print buffer align format,will not affect next line
 * 
 * @param[in] nAlign 0 left, 1 center, 2 right
 * @return Nothing 
 */
LIB_EXPORT void UPrint_Set_LineAlign(int nAlign);

/**
 * @brief String printing (UPrint_StrBold) with automatic line feed function, support \r, \n newline
 * 
 * @param[in] sLeft left align string
 * @param[in] sRight right align string
 * @param[in] nLinegap Line spacing, unit pixels, 0 is the default value (for Pin printing use)
 * @return Nothing 
 * @details For Persian print
 */
LIB_EXPORT void UPrint_str_line(char*sLeft,char*sRight,int nLinegap);

/**
 * @brief set the line space of follow print buffer
 *
 * @param[in] nLinegap:line space value
 */
LIB_EXPORT void UPrint_Set_LineSpace(int nLinegap);
/**
 * @brief check the printer if it is out of paper
 *
 * @return 0, success, no papger
 * @return 1, success, has papger
 * @return Other, fail
 */
LIB_EXPORT int UPrint_CheckPaper(void);
/**
 * @brief generate barcode file to print
 *
 * @return 0, success, no papger
 * @return 1, success, has papger
 * @return Other, fail
 */
LIB_EXPORT int UPrint_BarCode(const char* psBarCode);
/**
 * @brief generate barcode file to print
 *
 * @param[in] maxwidth maximum barcode width
 * @param[in] height barcode height
 * @param[in] code text content
 * @param[out] nwidth actual length
 * @return 0, success
 * @return Other, fail
 */
LIB_EXPORT void UPrint_bar_creat_type(int maxwidth, int height, char* code, int* nwidth);
/**
 * @brief generate barcode buffer to show
 *
 * @param[in] maxwidth maximum barcode width
 * @param[in] height barcode height
 * @param[in] code text content
 * @param[out] nwidth final width of barcode
 * @return !=0, success, the generated buffer pointer
 * @return 0, fail
 * @details only for H9G, H9L
 */
LIB_EXPORT char* UPrint_bar_creatbuff(int maxwidth, int height, char* code, int* nwidth);

/**
 * @brief free the buffer generated by UPrint_bar_creatbuff
 *
 * @param[in] buffer buffer pointer
 * @details only for H9G, H9L
 */
LIB_EXPORT void UPrint_bar_free(char* buffer);

#endif /*__LIBAPI_PRINT_HEADER__*/
