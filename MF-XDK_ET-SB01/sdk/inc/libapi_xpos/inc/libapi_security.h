#pragma once

#include "libapi_pub.h"

/**
 * @file libapi_security.h
 * @author baijz
 * @brief security
 * @date 2023-05-24
 *
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 *
 */

#define SEC_KEY_NOT_EXIST			-22

#define MKSK_MAINKEY_TYPE			0x00
#define MKSK_PINENC_TYPE			0x01
#define MKSK_MACENC_TYPE			0x02
#define MKSK_MAGDEC_TYPE			0x03
#define MKSK_TRANSKEY_TYPE			0x04

#define MKSK_AES_KEY_TMK 			0x05
#define MKSK_AES_KEY_TMK1  			0x06
#define MKSK_AES_KEY_MAINKEY 		0x07
#define MKSK_AES_KEY_PINENC 		0x08
#define MKSK_AES_KEY_MACENC 		0x09
#define MKSK_AES_KEY_MAGENC 		0x0A
#define MKSK_AES_KEY_TMK1_PIN  		0x0B
#define MKSK_AES_KEY_TMK1_MAC       0x0C
#define MKSK_AES_KEY_TMK1_MAG  		0x0D
#define MKSK_AES_KEY_TMK2_PIN  		0x0E
#define MKSK_AES_KEY_TMK2_MAC       0x0F
#define MKSK_AES_KEY_TMK2_MAG  		0x10



#define MKSK_ENCRYPT				0x00
#define MKSK_DECRYPT				0x01



#define SEC_FIXED_FIELD				0x00
#define SEC_MKSK_FIELD				0x01
#define SEC_DUKPT_FIELD				0x02
#define SEC_AES_FIELD				0x03

#define SEC_MAC_UPAY_FORMAT			0x01
#define SEC_MAC_X99_FORMAT			0x02
#define SEC_MAC_X919_FORMAT			0x03
#define SEC_MAC_XOR_FORMAT			0x04


#define SEC_PIN_FORMAT0				0x00
#define SEC_PIN_FORMAT1				0x01
#define SEC_PIN_FORMAT2				0x02
#define SEC_PIN_FORMAT3				0x03
#define SEC_PIN_FORMAT4				0x04

#define DES_TYPE_ENCRYPT			0x00
#define DES_TYPE_DECRYPT			0x01

#define DES_MODE_ECB				0x00
#define DES_MODE_CBC				0x01

#define DUKPT_DES_KEY_PIN			0x00
#define DUKPT_DES_KEY_MAC1			0x01
#define DUKPT_DES_KEY_MAC2			0x02
#define DUKPT_DES_KEY_DATA1			0x03
#define DUKPT_DES_KEY_DATA2			0x04

 /**
  * @brief set key length
  *
  * @param[in] size length of key (8 , 16, 24)
  */
LIB_EXPORT void sec_set_key_size(int size);

/**
 * @brief save key plaintext
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[in] key key plaintext
 * @param[out] kvc key kvc(key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_save_plaintext_key(int type, int gid, unsigned char * key, unsigned char *kvc);

/**
 * @brief save key ciphertext
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] key key ciphertext
 * @param[out] kvc key kvc(key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_save_encrypted_key(int type, int gid, unsigned char * key, unsigned char *kvc);

/**
 * @brief save key ciphertext (mksk_save_encrypted_key_ex)
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] key key plaintext
 * @param[in] des_mode mode(0 - ECB, 1 - CBC)
 * @param[out] kvc key kvc(key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_save_encrypted_key_ex(int type, int gid, unsigned char * key, int des_mode,unsigned char *kvc);

/**
 * @brief use key 3des operation
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] mode operation type(0 - encryption, 1 - decryption)
 * @param[in] ind raw data
 * @param[in] size data length (8-byte multiple)
 * @param[out] outd calculation results
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_3des_run(int type, int gid, int mode, unsigned char *ind, int size, unsigned char *outd);

/**
 * @brief use key 3des operation
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] mode operation type (0 - encryption, 1 - decryption)
 * @param[in] ind raw data
 * @param[in] size data length (8-byte multiple)
 * @param[in] des_mode mode(0 - ECB, 1 - CBC)
 * @param[out] outd calculation results
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_3des_run_ex(int type, int gid, int mode, unsigned char *ind, int size, unsigned char *outd, int des_mode);

/**
 * @brief use key 3des operation
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] mode operation type (0 - encryption, 1 - decryption)
 * @param[in] ind raw data
 * @param[in] size data length (8-byte multiple)
 * @param[in] iv initialization vector
 * @param[in] des_mode mode(0 - ECB, 1 - CBC)
 * @param[out] outd calculation results
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_3des_run_ex2(int type, int gid, int mode, unsigned char *ind, int size, unsigned char iv[8],unsigned char *outd, int des_mode);

/**
 * @brief get a set of dukpt keys
 *
 * @param[in] gid key grouping,,max 100 group (0 - 99)
 * @param[out] ksn, key corresponds to ksn;
 * @return  0, success;
 * @return	Other, failure;
 */
LIB_EXPORT int dukpt_prepare_key(unsigned char gid, unsigned char * ksn);

/**
 * @brief use the previously obtained key 3des operation
 *
 * @param[in] mode operation type (0 - encryption, 1 - decryption)
 * @param[in] ind raw data
 * @param[in] size, data length (8-byte multiple)
 * @param[out] outd calculation results
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_3des_run(int mode, char *ind, int size, char *outd);

/**
 * @brief use the previously obtained key 3des operation
 *
 * @param[in] mode operation type (0 - encryption, 1 - decryption)
 * @param[in] ind raw data
 * @param[in] size data length (8-byte multiple)
 * @param[in] des_mode mode(0 - ECB, 1 - CBC)
 * @param[in] key_tpye	key type(0 - DUKPT_DES_KEY_PIN, 1 - DUKPT_DES_KEY_MAC1, 2 - DUKPT_DES_KEY_MAC2, 3 - DUKPT_DES_KEY_DATA1, 4 - DUKPT_DES_KEY_DATA2)
 * @param[out] outd calculation results
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_3des_run_ex(int mode, char *ind, int size, char *outd, int des_mode, int key_tpye);

/**
 * @brief initialize the dukpt key
 *
 * @param[in] mode encryption method of initial key(0 - plaintext, 1 - tmk encryption, 2 - kek encryption)
 * @param[in] type initial key type(0 - ipek, 1 - bdk)
 * @param[in] gid key grouping,,max 100 group (0 - 99)
 * @param[in] init_ksn	initial ksn
 * @param[in] init_key	Initial key
 * @param[in] kvc key kvc(Key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_load_key(int mode, int type, int gid, unsigned char* init_ksn, unsigned char* init_key, char * kvc);

/**
 * @brief initialize the dukpt key use IPEK
 *
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] init_ksn	initial ksn
 * @param[in] init_key	Initial key
 * @param[in] kvc key kvc(Key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_init_ipek(unsigned char gid, unsigned char* init_ksn, unsigned char* init_key);

/**
 * @brief initialize the dukpt key use IPEK ciphertext
 *
 * @param[in] gid key grouping,,max 100 group (0 - 99)
 * @param[in] key ipek ciphertext
 * @param[in] kvc key kvc(Key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_init_ciphertext_ipek(unsigned char gid, unsigned char* key, char * kvc);

/**
 * @brief initialize the dukpt key use BDK
 *
 * @param[in] gid key grouping,,max 100 group (0 - 99)
 * @param[in] init_ksn initial ksn
 * @param[in] init_key bdk
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_init_bdk(unsigned char gid, unsigned char* init_ksn, unsigned char* init_key);

/**
 * @brief computing mac
 *
 * @param[in] fid field id (1 - SEC_MKSK_FIELD, 2 - SEC_DUKPT_FIELD)
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[in] format mac format (1 - SEC_MAC_UPAY_FORMAT, 2 - SEC_MAC_X99_FORMAT, 3 - SEC_MAC_X919_FORMAT, 4 - SEC_MAC_XOR_FORMAT)
 * @param[in] data mac source data
 * @param[in] len data length
 * @param[in] key_tpye key type(1 - MF_DUKPT_DES_KEY_MAC1, 2 - MF_DUKPT_DES_KEY_MAC2)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int sec_mac_proc(int fid, int gid, int format, char *data, int len, char *mac, int key_tpye);

/**
 * @brief read pin ciphertext from the security keyboard
 *
 * @param[in] fid field id (1 - SEC_MKSK_FIELD, 2 - SEC_DUKPT_FIELD)
 * @param[in] format pin format (0 - SEC_PIN_FORMAT0, 1 - SEC_PIN_FORMAT1, 2 - SEC_PIN_FORMAT2, 3 - SEC_PIN_FORMAT3, 4 - SEC_PIN_FORMAT4)
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[in] pan card number
 * @param[in] pin pin plaintext
 * @param[out] pinblock, pinblock ciphertext
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int sec_encrypt_pin_proc(int fid, int format, int gid, char * pan, char *pinblock, char * pin);


/**
 * @brief Set enable pin input mode
 *
 * @param[in] mode 2,open encrypted pin(The backbutton deletes a pin); 3,open encrypted pin(The backbutton deletes all pin);
 * @param[in] min Minimum pin length
 * @param[in] max Maximum pin length
 * @param[in] timeover timeover(ms)
 */
LIB_EXPORT void sec_set_pin_mode(int mode, int min, int max, int timeover);

/**
 * @brief
 * 
 * @param[in] int mode   0, 1 , 2
 * @return 0 - success
 * @return other failed
 */
LIB_EXPORT int sec_set_pin_mod(int mode);


/**
 * @brief Get pin mode status
 *
 * @param[out] Current pin length
 * @return  0, Still input
 * @return  1, Press the enter(OK) button
 * @return  2, Press the exit button
 * @return  3, timeover
 */
LIB_EXPORT int sec_get_pin_mode_status(int* length);
/**
 * @brief save the private key to the security module
 *
 * @param[in] index key index (0 - 9)
 * @param[in] length rsa byte size(128/256)
 * @param[in] p private key P component
 * @param[in] q private key Q component
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int sec_save_rsa_pri_key(int index, int length, char * p, char * q);

/**
 * @brief save the public key to the security module
 *
 * @param[in] index key index (0 - 9)
 * @param[in] length rsa byte size(128/256)
 * @param[in] n public  key N component
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int sec_save_rsa_puk_key(int index, int length, char * n);

/**
 * @brief RSA block calculation
 *
 * @param[in] index key index (0 - 9)
 * @param[in] ind in data
 * @param[in] outd out data
 * @param[in] length rsa key byte size(128/256)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int sec_rsa_block(int index, char * ind, char *outd, int length);

/**
 * @brief get pci hardware version
 *
 * @return  hardware version
 */
LIB_EXPORT char * sec_get_hw_ver();

/**
 * @brief get pci firmware version
 *
 * @return  firmware version
 */
LIB_EXPORT char * sec_get_fw_ver();

/**
 * @brief get key corresponds to ksn
 *
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[out] ksn key corresponds to ksn
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_get_ksn(unsigned char gid, unsigned char * ksn);

/**
 * @brief check dukpt ksn(non-incremental)
 * 
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[out] ksn key corresponds to ksn
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_check_ksn(unsigned char gid, unsigned char* ksn);
/**
 * @brief initialize the dukpt key
 *
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] init_ksn	initial ksn
 * @param[in] init_key	Initial key
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int dukpt_init_key(unsigned char gid, unsigned char* init_ksn, unsigned char* init_key);

/**
 * @brief delete index key
 *
 * @param[in] keyType 0:MKSK,1:DUKPT
 * @param[in] keyindex	key index(0-99)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int delete_key(int keyType, int keyindex);
LIB_EXPORT int deleteTransKey();
/**
 * @brief get mksk kcv
 *
 * @param[in] keyIndex key index(0-99)
 * @param[in] keyType	MKSK_MAINKEY_TYPE,MKSK_PINENC_TYPE,MKSK_MAGDEC_TYPE,MKSK_MAGDEC_TYPE,MKSK_TRANSKEY_TYPE
 * @param[out] OutKcv kcv
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_get_kcv(int keyIndex, int keyType, char* OutKcv);
/**
 * @brief get mksk kcv
 *
 * @param[in] keyIndex key index(0 - 99)
 * @param[in] keyType	MKSK_MAINKEY_TYPE,MKSK_PINENC_TYPE,MKSK_MAGDEC_TYPE,MKSK_MAGDEC_TYPE,MKSK_TRANSKEY_TYPE
 * @param[out] OutKcv kcv
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int MKSK_get_kcv(int keyIndex, int keyType, char* OutKcv);

/**
 * @brief get key corresponds to ksn
 *
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[out] ksn key corresponds to ksn
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int DUKPT_get_ksn(int keyIndex, char* OutKSN);

/**
 * @brief set MKSK main key
 *
 * @param[in] KeyIndex key index(0 - 99)
 * @param[in] nkeyLength key length
 * @param[in] key key plaintext
 * @param[out] KCV key kvc(key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int MKSK_inject_mainkey(char KeyIndex, int nkeyLength, char* key, char* KCV);

/**
 * @brief set MKSK work key
 *
 * @param[in] type key type(1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE)
 * @param[in] KeyIndex key index (0-99)
 * @param[in] nkeyLength key length
 * @param[in] key key plaintext
 * @param[out] KCV key kvc(key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int MKSK_inject_workkey(char keyType, char KeyIndex, int nkeyLength, char* key, char* KCV);

/**
 * @brief set dukpt key
 *
 * @param[in] key_type key type(0 - IPEK,1 - BDK)
 * @param[in] KeyIndex key index(0 - 99)
 * @param[in] nkeyLength key length
 * @param[in] key key
 * @param[in] KSN ksn
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int DUKPT_inject_key(char keyType, int KeyIndex, int nkeyLength, char* key, char* KSN);
/**
 * @brief save key plaintext
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[in] key key plaintext
 * @param[in] keyLen key length
 * @param[out] kvc key kvc(key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_save_plaintext_key_ex(int type, int gid, unsigned char* key, int keyLen, unsigned char* kvc);
/**
 * @brief save key ciphertext
 *
 * @param[in] type key type(0 - MKSK_MAINKEY_TYPE, 1 - MKSK_PINENC_TYPE, 2 - MKSK_MACENC_TYPE, 3 - MKSK_MAGDEC_TYPE, 4 - MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] key key plaintext
 * @param[in] keyLen key length
 * @param[in] des_mode mode(0 - ECB, 1 - CBC)
 * @param[out] kvc key kvc(key plaintext encryption 8 0x00)
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT int mksk_save_encrypted_key_ex2(int type, int gid, unsigned char* key, int keyLen, int des_mode, unsigned char* kvc);
