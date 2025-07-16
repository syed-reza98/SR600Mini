#pragma once

#include "libapi_pub.h"

/**
 * @file libapi_rki.h
 * @author baijz
 * @brief rki
 * @date 2023-05-25
 *
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 *
 */

#define RKI_MODE_Mosambee  1

 /**
  * @brief initialize the rki
  *
  * @param[in] mode reserve
  * @return  0, success
  * @return	 Other, failure
  */
LIB_EXPORT int rki_init( int mode);

/**
 * @brief load the rki key use dukpt
 *
 * @param[in] keydata key data
 * @param[in] len key length
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int rki_dukpt_load( const char *keydata ,int len );

/**
 * @brief verify the app hash
 *
 * @param[in] sHashValue app hash
 * @return  1, Yes
 * @return	0, No
 */
LIB_EXPORT int check_app_key(unsigned char *sHashValue);

/**
 * @brief rki self test
 *
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int rki_self_test();

LIB_EXPORT int check_layer_key();
/**
 * @brief load the rki key use mksk
 *
 * @param[in] keydata key data
 * @param[in] len key length
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int rki_load_key(int index, char* keydata);
/**
 * @brief process the rki
 *
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int api_rki_proc();
/**
 * @brief verify the psp hash
 *
 * @param[in] sHashValue app hash
 * @return  1, Yes
 * @return	0, No
 */
LIB_EXPORT int check_psp_key(unsigned char* sHashValue);
