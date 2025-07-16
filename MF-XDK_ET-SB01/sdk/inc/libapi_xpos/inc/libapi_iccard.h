#ifndef __LIBAPI_ICCARD_HEADER__
#define __LIBAPI_ICCARD_HEADER__

/**
 * @file libapi_iccard.h
 * @author caijh(Eric)
 * @brief ICCard related functions
 * @date 2023-05-24
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#include "libapi_pub.h"
//#include "driver/mf_magtek.h"
/**
 * @brief Get ICCard module version (Icc_GetModuleVer)
 *
 * @param[out] pszVer Get ICCard module version
 * @return 0, Success
 * @return Other, Failure
 */
LIB_EXPORT int Icc_GetModuleVer(char *pszVer);

/**
 * @brief Detection card (Icc_GetCardStatus)
 *
 * @param[in] iSlotType Card slot number, see enum SlotType
 * @return  UICC_NORF = -3, No Card
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK = 0, Success
 * @details Contact card: Check if the card is in the card slot,
			Please call the IC card device (Icc_Open) first
 */
LIB_EXPORT int Icc_GetCardStatus(int iSlotType);

/**
 * @brief Icc_PowerUp (Icc_PowerUp)
 *
 * @param[in] iCardType IC card type, see enum IccType
 * @param[in] iSlotType Card slot number, see enum SlotType
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 * @details Including card reset operation
 */
LIB_EXPORT int Icc_PowerUp(int iCardType, int iSlotType);

/**
 * @brief Contact card Power down (Icc_PowerDown)
 *
 * @param[in] iCardType IC card type, see enum IccType
 * @param[in] iSlotType Card slot number, see enum SlotType
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 * @details Pay attention to calling off IC card device (Icc_Close) after power off
 */
LIB_EXPORT int Icc_PowerDown(int iCardType , int iSlotType);

/**
 * @brief Contact card communication (Icc_ICComm)
 *
 * @param[in] iCardType IC card type, see enum IccType
 * @param[in] iSlotType Card slot number, see enum SlotType
 * @param[in] Apdu See ICCAPDU structure
 * @param[out] Apdu The data returned depends on the type of OperType operation 
			   in the ICCAPDU structure and is placed in R_Data
 * @return  UICC_COMMAND_FAIL = -2, Communication error
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 */
LIB_EXPORT int Icc_ICComm (int iCardType,int iSlotType, ICCAPDU *Apdu);

/**
 * @brief RF Seek (Icc_CTLSPowerUpAndSeek)
 *
 * @param[in] iCardType IC card type, see enum IccType
 * @param[out] psUID Card serial number. The first byte is the serial number length
 * @return  UICC_NORF = -3, No Card
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 * @details Please call the IC card device (Icc_Open) first.
			Includes card reset operation application layer loop call.
 */
LIB_EXPORT int Icc_CTLSPowerUpAndSeek (int iCardType, char *psUID);

/**
 * @brief RF CARD Power down (Icc_CTLSPowerDown)
 *
 * @return  0, Success
 * @return  Other, Failure
 * @details Pay attention to calling off IC card device (Icc_Close) after power off.
 */
LIB_EXPORT int Icc_CTLSPowerDown();

/**
 * @brief Non connected card communication (Icc_CTLSComm)
 *
 * @param[in] iCardType IC card type, see enum IccType
 * @param[in] Apdu see the ICCAPDU structure specification
 * @param[out] Apdu The data returned depends on the type of OperType operation in the ICCAPDU structure and is placed in R_Data.
 * @return  UICC_COMMAND_FAIL = -2, Communication error
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 */
LIB_EXPORT int Icc_CTLSComm(int iCardType,ICCAPDU *Apdu);

/**
 * @brief Open IC card (Icc_Open)
 *
 * @param[in] iSlotType Card slot number, see enum SlotType
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK = 0, Success
 */
LIB_EXPORT int Icc_Open(int iSlotType);

/**
 * @brief Close IC card (Icc_Close)
 *
 * @param[in] iSlotType Card slot number, see enum SlotType
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 */
LIB_EXPORT int Icc_Close(int iSlotType);

/**
 * @brief Get IC card reset information ATR (Answer To Reset)
 *
 * @param[in] iCardType IC card type, see enum IccType
 * @param[in] iSlotType Card slot number, see enum SlotType
 * @param[out] psATR ATR information
 * @param[out] pnATRLen psATR Cache size
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 * @details Used to obtain IC card reset information ATR (Answer To Reset), which is called 
			after resetting Icc_PowerUp, Icc_CTLSPowerUp and AndSeek on the card by power
 */
LIB_EXPORT int Icc_GetCardATR(int iCardType, int iSlotType, byte *psATR, int*pnATRLen);

/**
 * @brief Check if the terminal is inserted into the IC card
 *
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK = 0, Success
 */
LIB_EXPORT int Icc_CardInsertDetect();

/**
 * @brief Check whether the user swipes the card at the terminal
 *
 * @return  UICC_FAIL = -1, Failure
 			UICC_FAIL = -4, multiple card
 * @return  UICC_OK = 0, Success
 */
LIB_EXPORT int Icc_CardRfDetect();

/**
 * @brief Clear magtek buffer
 *
 * @return  Nothing
 * @details Must call card_magtek_flush before card_MagStripeDetect
 */
LIB_EXPORT void card_magtek_flush(void);

/**
 * @brief Check if the terminal is swiping
 *
 * @param[out] trackinfo If successful, the magnetic stripe card data is returned
 * @return  UICC_FAIL = -1, Failure
 * @return  UICC_OK	= 0, Success
 * @details Must call card_magtek_flush before card_MagStripeDetect
 */
LIB_EXPORT int card_MagStripeDetect(card_magtek_track_info *trackinfo);

LIB_EXPORT int Icc_rfid_get_uid(unsigned char* uid);
/*****************************************************************************
* Procedure: Icc_rfid_init
* Function:
* Parameters:           void
* Result:	UICC_OK : success,other fail
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Icc_rfid_init(void);
/*****************************************************************************
* Procedure: Icc_rfid_tcl_close
* Function:
* Parameters:           void
* Result: success : UICC_OK ,fail : UICC_OK
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Icc_rfid_tcl_close(void);
/*****************************************************************************
* Procedure: Icc_rfid_tcl_detect
* Function:
* Parameters:           Input: None
* Result:	enum ICCStatus	UICC_OK:success,UICC_NORF: No card detected
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Icc_rfid_tcl_detect(void);
/*****************************************************************************
* Procedure: Icc_Rfid_tcl_exchange
* Function:
* Parameters:           unsigned char *tbuf  apdu request command
                               unsigned short tlen  apdu request command length
                               unsigned char **rbuf  eg. unsigned char *pTemp &pTemp
                               unsigned short *rlen  apdu response length point
* Result:	UICC_OK:success,UICC_FAIL:fail
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Icc_Rfid_tcl_exchange(unsigned char *tbuf, unsigned short tlen, unsigned char **rbuf, unsigned short *rlen);
/*****************************************************************************
* Procedure: Icc_rfid_tcl_open
* Function:
* Parameters:           Input: None
* Result: enum ICCStatus	UICC_OK:success,UICC_FAIL:fail
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Icc_rfid_tcl_open(void);
/*****************************************************************************
* Procedure: Icc_rfid_tcl_reset
* Function:
* Parameters:			unsigned char* pAtr Atr buffer
					int iAtrLength	pAtr buffer size
* Result: UICC_FAIL , > 0 atr length
* Descriptions:
* Created By:		CHAR  2023.10.31
*****************************************************************************
* LOG	DATE			AUTHOR		 ACTION
*****************************************************************************
*****************************************************************************/
LIB_EXPORT int Icc_rfid_tcl_reset(unsigned char* pAtr, int iAtrLength);

/**
 * @brief
 * 
 * @return 1 - success
 * @return other - failed
 */
LIB_EXPORT int Icc_rfid_probe(void);


/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT int Icc_RfMfclAtqa(void);
/**
 * @brief
 * 
 * @param[in] int cmd
 * @param[in] int block
 * @return 
 */
LIB_EXPORT int Icc_RfMfclAuth(int cmd, int block);
/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT int Icc_RfMfclClose(void);
/**
 * @brief
 * 
 * @param[in] int block
 * @param[in] int operand
 * @return 
 */
LIB_EXPORT int Icc_RfMfclDecrement(int block, int operand);
/**
 * @brief
 * 
 * @param[out] unsigned char *uid
 * @return 
 */
LIB_EXPORT int Icc_RfMfclGetUid(unsigned char *uid);
/**
 * @brief
 * 
 * @param[in] int block
 * @param[in] int operand
 * @return 
 */
/**
 * @brief
 * 
 * @param[in] int block
 * @param[in] int operand
 * @return 
 */
LIB_EXPORT int Icc_RfMfclIncrement(int block, int operand);
/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT int Icc_RfMfclOpen(void);
/**
 * @brief
 * 
 * @param[in] int block
 * @param[out] unsigned char *buf
 * @param[out] int *len
 * @return 
 */
LIB_EXPORT int Icc_RfMfclRead(int block, unsigned char *buf, int *len);
/**
 * @brief
 * 
 * @param[in] int block
 * @return 
 */
LIB_EXPORT int Icc_RfMfclRestore(int block);
/**
 * @brief
 * 
 * @param[in] unsigned char *key
 * @return 
 */
LIB_EXPORT int Icc_RfMfclSetKey(unsigned char *key);
/**
 * @brief
 * 
 * @param[in] int block
 * @return 
 */
LIB_EXPORT int Icc_RfMfclTransfer(int block);
/**
 * @brief
 * 
 * @param[in] int block
 * @param[in] unsigned char *buf
 * @param[in] int len
 * @return 
 */
LIB_EXPORT int Icc_RfMfclWrite(int block, unsigned char *buf, int len);

LIB_EXPORT int emvapi_check_ic();
/*************************************************************************************

*************************************************************************************/
//LIB_EXPORT int emvapi_check_magtek(struct magtek_track_info *trackinfo);
/*************************************************************************************

*************************************************************************************/
LIB_EXPORT int emvapi_check_rf();


#endif /* __LIBAPI_ICCARD_H__ */
