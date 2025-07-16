/**
 * @file mfsdk_prt.h
 * @author Ronaldo
 * @brief Print correlation function
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 * 
 */

#ifndef __MFSDK_PRT_H__
#define __MFSDK_PRT_H__
#include "mfsdk_define.h"


typedef enum
{
    MFSDK_PRT_SUCCESS = 0, //Success 
    MFSDK_PRT_FAIL = -1, //Printer unknown fault 
    MFSDK_PRT_DEV_FAIL = -2, //Printer device failure 
    MFSDK_PRT_OUTOF_PAPER = -3, //The printer is out of paper 
    MFSDK_PRT_LOSE_COMMAND = -4, //Print handle not obtained 
    MFSDK_PRT_FILE_FAIL = -5, //Fail to open the file 
    MFSDK_PRT_HANDLE_BACK = -6, //Split machine handle is not put back
    MFSDK_PRT_CACHE_ERR = -7, //Save cache failed
    MFSDK_PRT_PARM_ERROR = -8,//Parameter error
}MfSdkPrtRet_E;

typedef enum
{
    MFSDK_PRT_PATTERN_LEFT = 0,     //left
    MFSDK_PRT_PATTERN_CENTER = 1,   //center
    MFSDK_PRT_PATTERN_RIGHT = 2,    //right
}MfSdkPrtPattern_E;

/**
 * @brief Printer initialize, check the printer status (if it is out of paper).
 * 
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtInit(void);

/**
 * @brief String printing with automatic line break function, support \r\n newline
 * 
 * @param[in] str Need to print string information
 * @param[in] linegap Line spacing: unit pixels, 0 is the default value (for Pin printing use)
 * @param[in] newline 0 Does not support line breaks;1 support \r\n newline
 * @return s32 For details, see MfSdkPrtRet_E.
 * @details Save the string to the printer cache and call Print Start (Print_Start) to print
 */
LIB_EXPORT s32 MfSdkPrtStr( s8 *str, s32 linegap, MFSDKBOOL newline);

/**
 * @brief print image (XXX.bmp)
 * 
 * @param[in] BmpFile Image file name (XXX.bmp)
 * @param[in] pattern alignment (see 'MfSdkPrtPattern_E' enum)
 * @return s32 For details, see MfSdkPrtRet_E.
 * @details Automatic line wrap is not supported;
 */
LIB_EXPORT s32 MfSdkPrtBitMap( s8 *BmpFile, MfSdkPrtPattern_E pattern);

/**
 * @brief Start printing
 * 
 * @return s32 For details, see MfSdkPrtRet_E.
 * @details Thermal printing: no more blank lines (processed by the application layer) are required after printing is completed;
		    Needle printing: automatic page change after printing is completed.
 */
LIB_EXPORT s32 MfSdkPrtStart(void);

/**
 * @brief String printing with automatic line feed function, support \r\n newline
 * 
 * @param[in] pszStr Need to print string information
 * @param[in] pattern alignment (see 'MfSdkPrtPattern_E' enum)
 * @param[in] linegap Line spacing, unit pixels, 0 is the default value (for Pin printing use)
 * @param[in] newline 0 Does not support line breaks;1 support \r\n newline
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtStrBold( s8 *pszStr, MfSdkPrtPattern_E pattern, s32 linegap, MFSDKBOOL newline);

/**
 * @brief Printer paper
 * 
 * @param[in] linegap Paper length (pixels)
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtFeed(s32 linegap);

/**
 * @brief Print QR code,Convert incoming data to QR code and print
 * 
 * @param[in] psMatrixCode QR code data
 * @param[in] nLen QR code data length
 * @param[in] cSize QR code size, 0-small, 1-medium, 2-large
 * @param[in] pattern alignment (see 'MfSdkPrtPattern_E' enum)
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtMatrixCode(const s8 *psMatrixCode, s32 nLen, s8 cSize, MfSdkPrtPattern_E pattern);

/**
 * @brief Set print font(English)
 * 
 * @param[in] size et print English font size(0--8)
 * @param[in] zoomW Set the horizontal magnification of English(1--5)
 * @param[in] zoomH Set the vertical magnification of English(1--5)
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtSetFontEN(s32 size, s32 zoomW, s32 zoomH);

/**
 * @brief Set print font(Chinese)
 * 
 * @param[in] size Set print other font size(0--2)
 * @param[in] zoomW Set the horizontal magnification of English(1--5)
 * @param[in] zoomH Set the vertical magnification of English(1--5)
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtSetFontCN(s32 size, s32 zoomW, s32 zoomH);

/**
 * @brief Set print density
 * 
 * @param[in] val Set print density (1--5, 3 is normal)
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtSetDensity(s32 val);

/**
 * @brief Set the follow print buffer align format
 * 
 * @param[in] pattern alignment (see 'MfSdkPrtPattern_E' enum)
 */
LIB_EXPORT void MfSdkPrtSetAlign(MfSdkPrtPattern_E pattern);

/**
 * @brief Set the line print buffer align format,will not affect next line
 * 
 * @param[in] pattern alignment (see 'MfSdkPrtPattern_E' enum)
 */
LIB_EXPORT void MfSdkPrtSetLineAlign(MfSdkPrtPattern_E pattern);

/**
 * @brief String printing with automatic line feed function, support \r\n newline
 * 
 * @param[in] sLeft left align string
 * @param[in] sRight right align string
 * @param[in] nLinegap Line spacing, unit pixels, 0 is the default value (for Pin printing use)
 */
LIB_EXPORT void MfSdkPrtStrLine( s8 *sLeft,  s8 *sRight, s32 nLinegap);

/**
 * @brief set the line space of follow print buffer
 * 
 * @param[in] nLinegap line space value
 */
LIB_EXPORT void MfSdkPrtSetLineSpace(s32 nLinegap);

/**
 * @brief Set the printing mode for English letters and numbers
 *
 * @param[in] mod 1 Print English letters and numbers characters using font files; 0 or no setting, the default print uses the code font
 */
LIB_EXPORT void MfSdkPrtSetFontMode(s32 mod);
/**
 * @brief Check if the device is out of paper
 *
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtCheckNopaper();
/**
 * @brief Set the printing mode for English letters and numbers
 *
 * @param[in] order 1:Set up Arabic digital reverse printing
 * @return s32 For details, see MfSdkPrtRet_E.
 */
LIB_EXPORT s32 MfSdkPrtSetArabicNumOrder(s32 order);
#endif /* __MFSDK_PRT_H__ */



