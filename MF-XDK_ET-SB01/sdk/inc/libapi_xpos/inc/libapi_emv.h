#ifndef _LIBAPI_EMV__H__
#define _LIBAPI_EMV__H__

#include "emvapi.h"
/**
 * @file libapi_emv.h
 * @author chenyue(Ronaldo)
 * @brief emv correlation function
 * @date 2023-05-22
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

typedef enum _read_card_mod {
	READ_CARD_MODE_MAGNETIC = 0x01, 	///< Read magnetic card
	READ_CARD_MODE_ICC = 0x02,			///< Read icc card
	READ_CARD_MODE_RFID = 0x04,			///< Read rfid card
	READ_CARD_MODE_ALL = 0xFF,			///< Read all
}read_card_mod;

typedef void (*_read_page)();

/**
 * @brief check and read card
 *
 * @param[in] mod reference enum read_card_mod
 * @param[out] type output card type,MAGTEK:0,ICC:1,RFIC:2
 * @param[out] trackInfo Track message, swipe card data
 * @param[in] card_in the same value as emv_card_begin
 * @param[out] card_out card_out: IC data and pinblock . refer to st_read_card_out struct
 * @param[in] page_cb check the card,show page
 * @param[in] timeout timeout
 * @return  0  	,	EMVAPI_RET_TC				 //TC
 * @return	1  	,	EMVAPI_RET_ARQC	 			 //ARQC
 * @return	-1  ,	EMVAPI_RET_AAC	 			 //AAC
 * @return	-2  ,	EMVAPI_RET_AAR	 			 //Terminate
 * @return	-3  ,	EMVAPI_RET_CANCEL			 //Cancel
 */
LIB_EXPORT int EMV_check_read_card(int mod, int* type, card_magtek_track_info* trackInfo, st_read_card_in* card_in, st_read_card_out* card_out, _read_page page_cb, int timeout);

#endif



