#ifndef __LIBAPI_TR31_H_
#define __LIBAPI_TR31_H_

#include "libapi_pub.h"
#define TR_ERR_LENTH	-9001
#define	TR_ERR_HEAD		-9002
#define	TR_ERR_DATA		-9003
#define	TR_ERR_MAC		-9004

/**
 * @brief save key plaintext
 *
 * @param[in] type:default o
 * @param[in] mk: key for decrypt the TR31 string 
 * @param[in] nkeysize : mk size
 * @param[in] data : TR31 string
 * @param[in] size: TR31 data size
 * @param[out] wk: Decrypted key
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int GetTr31Data_Ex(unsigned int type,char * mk,int nkeysize,unsigned char *data, int size,char *wk);

/**
 * @brief save key plaintext
 *
 * @param[in] type:default o
 * @param[in] mk: key for decrypt the TR31 string 
 * @param[in] nkeysize : mk size
 * @param[in] data : TR31 string
 * @param[in] size: TR31 data size
 * @param[out] wk: Decrypted key
 * @param[out] ksn: ksn 
 * @return  0, success
 * @return	Other, failure
 */

LIB_EXPORT int Tr31GetData(unsigned int type,char * mk,int nkeysize,unsigned char *data, int size, char *wk ,char* ksn);

#endif

