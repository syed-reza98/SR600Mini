/**
 * @file mfsdk_ped.h
 * @author Ronaldo
 * @brief
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 *
 */

#ifndef __MFSDK_PED_H__
#define __MFSDK_PED_H__
#include "mfsdk_define.h"

typedef enum
{
	MFSDK_PED_NOT_KEY = -22,    // No injection key
	MFSDK_PED_PARM_ERROR = -21, // Parameter error
	MFSDK_PED_PINPAD_INSUFFICIENT_SPACE = -16,//The pinpad space is insufficient
	MFSDK_PED_PINPAD_NO_PUBLIC_KEY_SIGN = -15,//The pinpad upgrade lacks the public key signature
	MFSDK_PED_PINPAD_REPEATED_SET_MODE = -12, //Repeated setting mode
	MFSDK_PED_PINPAD_UPDATEFILE_TOO_BIG = -11, // update file too big
	MFSDK_PED_UPDATEFILE_FORMAT_ERR = -10, // update file format error
	MFSDK_PED_UPDATE_COMPLETE_RECONNECT_FAILED = -9, // failed to reconnect to the pinpad after the update is complete
	MFSDK_PED_MD5_FAILED = -8, // pinpad app md5 authentication failed
	MFSDK_PED_WRITE_FAILED = -7, // pinpad failed to write files
	MFSDK_PED_OPEN_FAILED = -6, // app to be updated failed to open
	MFSDK_PED_NO_APP_UPDATE = -5, // no apps to update(mo data/pinpad.bin)
	MFSDK_PED_PINPAD_TIMEOUT = -2, // External Pinpad communication timed out
    MFSDK_PED_OTHER = -1,
    MFSDK_PED_SUCCESS = 0,         // Success
}MfSdkPedRet_E;


typedef enum
{
    MFSDK_PED_ENCRYPT = 0, // Encryption mode
    MFSDK_PED_DECRYPT = 1, // Decryption mode

} MfSdkPedMod_E;

typedef enum
{
    MFSDK_PED_DES_ECB = 0, // des mode ECB
    MFSDK_PED_DES_CBC = 1, // des mode CBC
} MfSdkPedDesMod_E;

typedef enum
{
	MFSDK_PED_PINPAD_INPUT_PIN = 0,
	MFSDK_PED_PINPAD_PRESS_OK,
	MFSDK_PED_PINPAD_PRESS_ESC,
}MfSdkPedPinpadStatus_E;

typedef enum
{
	MFSDK_PED_RSA_PADDING_NONE = -1,	/**< None. */
	MFSDK_PED_RSA_PADDING_PKCS_V15 = 0, /**< Use PKCS#1 v1.5 encoding. */
	MFSDK_PED_RSA_PADDING_PKCS_V21,		/**< Use PKCS#1 v2.1 encoding. */
} MfSdkPedRsaPadding_E;
typedef enum
{
	MFSDK_PED_RSA_HASH_NONE = 0,    /**< None. */
	MFSDK_PED_RSA_HASH_MD2,       /**< The MD2 message digest. */
	MFSDK_PED_RSA_HASH_MD4,       /**< The MD4 message digest. */
	MFSDK_PED_RSA_HASH_MD5,       /**< The MD5 message digest. */
	MFSDK_PED_RSA_HASH_SHA1,      /**< The SHA-1 message digest. */
	MFSDK_PED_RSA_HASH_SHA224,    /**< The SHA-224 message digest. */
	MFSDK_PED_RSA_HASH_SHA256,    /**< The SHA-256 message digest. */
	MFSDK_PED_RSA_HASH_SHA384,    /**< The SHA-384 message digest. */
	MFSDK_PED_RSA_HASH_SHA512,    /**< The SHA-512 message digest. */
	MFSDK_PED_RSA_HASH_RIPEMD160, /**< The RIPEMD-160 message digest. */
} MfSdkPedRsaHash_E;
typedef struct
{
    u8 mode; // mode 2,open encrypted pin(The backbutton deletes a pin); 3,open encrypted pin(The backbutton deletes all pin);
    u8 min;//Minimum pin length
    u8 max;//Maximum pin length
    u8 isBypass;//Whether to support bypass
    u8 flag; // fid gid format 1 - enable , 0-disable
    u8 fid; //MFSDK_SEC_FIXED_FIELD , MFSDK_SEC_MKSK_FIELD ,MFSDK_SEC_DUKPT_FIELD,MFSDK_SEC_AES_FIELD, 0xff-not support
	u8 gid; //key index  0xff - not support
	u8 format;//MFSDK_SEC_PIN_FORMAT0 ~ MFSDK_SEC_PIN_FORMAT4
} MfSdkPedPinModCfg_T;

#define MFSDK_MKSK_MAINKEY_TYPE 0x00
#define MFSDK_MKSK_PINENC_TYPE 0x01
#define MFSDK_MKSK_MACENC_TYPE 0x02
#define MFSDK_MKSK_MAGDEC_TYPE 0x03
#define MFSDK_MKSK_TRANSKEY_TYPE 0x04
#define MFSDK_MKSK_FP_MAINKEY_TYPE 0x05	

#define MFSDK_MKSK_AES_KEY_TMK 	 	0x05
#define MFSDK_MKSK_AES_KEY_TMK1		0x06
#define MFSDK_MKSK_AES_KEY_MAINKEY 	0x07
#define MFSDK_MKSK_AES_KEY_PINENC  	0x08
#define MFSDK_MKSK_AES_KEY_MACENC   0x09
#define MFSDK_MKSK_AES_KEY_MAGENC 	0x0A
#define MFSDK_MKSK_AES_KEY_TMK1_PIN 0x0B
#define MFSDK_MKSK_AES_KEY_TMK1_MAC 0x0C
#define MFSDK_MKSK_AES_KEY_TMK1_MAG 0x0D
#define MFSDK_MKSK_AES_KEY_TMK2_PIN 0x0E
#define MFSDK_MKSK_AES_KEY_TMK2_MAC 0x0F
#define MFSDK_MKSK_AES_KEY_TMK2_MAG 0x10


#define MFSDK_SEC_FIXED_FIELD 0x00
#define MFSDK_SEC_MKSK_FIELD 0x01
#define MFSDK_SEC_DUKPT_FIELD 0x02
#define MFSDK_SEC_AES_FIELD 0x03


#define MFSDK_SEC_MAC_UPAY_FORMAT 0x01
#define MFSDK_SEC_MAC_X99_FORMAT 0x02
#define MFSDK_SEC_MAC_X919_FORMAT 0x03
#define MFSDK_SEC_MAC_XOR_FORMAT 0x04

#define MFSDK_SEC_PIN_FORMAT0 0x00
#define MFSDK_SEC_PIN_FORMAT1 0x01
#define MFSDK_SEC_PIN_FORMAT2 0x02
#define MFSDK_SEC_PIN_FORMAT3 0x03
#define MFSDK_SEC_PIN_FORMAT4 0x04

#define MFSDK_DUKPT_DES_KEY_PIN 0x00
#define MFSDK_DUKPT_DES_KEY_MAC1 0x01
#define MFSDK_DUKPT_DES_KEY_MAC2 0x02
#define MFSDK_DUKPT_DES_KEY_DATA1 0x03
#define MFSDK_DUKPT_DES_KEY_DATA2 0x04
#define MFSDK_DUKPT_DES_KEY_PEK 0x05

typedef enum
{
	MFSDK_PED_TR31_TYPE_IPEK = 0,
	MFSDK_PED_TR31_TYPE_BDK,
	MFSDK_PED_TR31_TYPE_FP_IPEK,
}MfSdkPedTr31KeyType_E;

typedef enum
{
	MFSDK_PED_PINPAD_UPDATE_START = 0x01,
	MFSDK_PED_PINPAD_UPDATEING,
    MFSDK_PED_PINPAD_UPDATE_END,
    MFSDK_PED_PINPAD_RESTORE_CONNECTION,
}MfSdkPedPinpadUpdateStatus_E;

typedef struct
{
	s8 appVer[10];
	s8 pinpadSn[32];
	s8 model[10];
}MfSdkPedPinpadInfo_T;
/**
 * @brief status:Upgraded state,total:Size of the pinpad app,updatedSize:Updated size,time:Time spent(ms)
 * 
 */
typedef s32 (*MfSdkPedPinpadUpdateCb)(MfSdkPedPinpadUpdateStatus_E status, s32 total, s32 updatedSize, u32 time);
/**
 * @brief 
 * 
 */
typedef int (*MfSdkPedKeyCmdCb)(char* recvdata, int recvlen, char* senddata);
/**
 * @brief Set the key length
 * 
 * @param[in] s32 size ,16 or 24 
 * @return MFSDK_PED_PARM_ERROR, size != 16 && size != 24
 * @return MFSDK_PED_SUCCESS success
 */
LIB_EXPORT s32 MfSdkPedSetKeySize(s32 size);

/**
 * @brief Get the key length
 * 
 * @return key length
 */
LIB_EXPORT s32 MfSdkPedGetKeySize(void);
/**
 * @brief initialize the dukpt key
 * 
 * @param[in] mode encryption method of initial key(0 - plaintext, 1 - tmk encryption, 2 - kek encryption)
 * @param[in] type initial key type(0 - ipek, 1 - bdk)
 * @param[in] gid key grouping,,max 100 group (0 - 99)
 * @param[in] init_ksn initial ksn
 * @param[in] init_key Initial key
 * @param[out] kvc key kvc(Key plaintext encryption 8 0x00)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedDukptLoadKey(s32 mode, s32 type, s32 gid, u8 *init_ksn, u8 *init_key, u8 *kvc);

/**
 * @brief use the previously obtained key 3des operation
 * 
 * @param[in] mode mode(see 'MfSdkPedMod_E' enum)
 * @param[in] inData raw data
 * @param[in] size data length (8-byte multiple)
 * @param[out] outData out data
 * @param[in] desMode des mode(see 'MfSdkPedDesMod_E' enum)
 * @param[in] keyTpye key type(0 - MFSDK_DUKPT_DES_KEY_PIN, 1 - MFSDK_DUKPT_DES_KEY_MAC1, 2 - MFSDK_DUKPT_DES_KEY_MAC2, 3 - MFSDK_DUKPT_DES_KEY_DATA1, 4 - MFSDK_DUKPT_DES_KEY_DATA2)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedDukpt3desRun(MfSdkPedMod_E mode, s8 *inData, s32 size, s8 *outData, MfSdkPedDesMod_E desMode, s32 keyTpye);

/**
 * @brief get key corresponds to ksn
 * 
 * @param[in] gid gid key grouping ,max 100 group (0 - 99)
 * @param[out] ksn key corresponds to ksn
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedDukptGetKsn(u32 gid, u8 *ksn);

/**
 * @brief save key plaintext
 * 
 * @param[in] type key type(0 - MFSDK_MKSK_MAINKEY_TYPE, 1 - MFSDK_MKSK_PINENC_TYPE, 2 - MFSDK_MKSK_MACENC_TYPE, 3 - MFSDK_MKSK_MAGDEC_TYPE, 4 - MFSDK_MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[in] key key key plaintext
 * @param[out] kvc key kvc(key plaintext encryption 8 0x00)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedMkSkSavePlaintextKey(s32 type, u32 gid, u8 *key, u8 *kvc);

/**
 * @brief save key ciphertext
 * 
 * @param[in] type key type(0 - MFSDK_MKSK_MAINKEY_TYPE, 1 - MFSDK_MKSK_PINENC_TYPE, 2 - MFSDK_MKSK_MACENC_TYPE, 3 - MFSDK_MKSK_MAGDEC_TYPE, 4 - MFSDK_MKSK_TRANSKEY_TYPE)
 * @param[in] gid key grouping,max 100 group (0 - 99)
 * @param[in] key key ciphertext
 * @param[in] desMode des mode(see 'MfSdkPedDesMod_E' enum)
 * @param[out] kvc key kvc(key plaintext encryption 8 0x00)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedMkSkSaveEncryptedKey(s32 type, u32 gid, u8 *key, MfSdkPedDesMod_E desMode, u8 *kvc);

/**
 * @brief get mksk kcv
 * 
 * @param[in] keyIndex keyIndex key index(0-99)
 * @param[in] keyType (0 - MFSDK_MKSK_MAINKEY_TYPE, 1 - MFSDK_MKSK_PINENC_TYPE, 2 - MFSDK_MKSK_MACENC_TYPE, 3 - MFSDK_MKSK_MAGDEC_TYPE, 4 - MFSDK_MKSK_TRANSKEY_TYPE)
 * @param[out] outKvc kvc
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedMkSkGetKcv(s32 keyIndex, s32 keyType, u8 *outKvc);

/**
 * @brief use key 3des operation
 * 
 * @param[in] type key type(0 - MFSDK_MKSK_MAINKEY_TYPE, 1 - MFSDK_MKSK_PINENC_TYPE, 2 - MFSDK_MKSK_MACENC_TYPE, 3 - MFSDK_MKSK_MAGDEC_TYPE, 4 - MFSDK_MKSK_TRANSKEY_TYPE)
 * @param[in]  gid key grouping,max 100 group (0 - 99)
 * @param[in]  mode mode(see 'MfSdkPedMod_E' enum)
 * @param[in]  ind raw data
 * @param[in]  size data length (8-byte multiple)
 * @param[in]  iv initialization vector
 * @param[out]  outd calculation results
 * @param[in]  desMode des mode(see 'MfSdkPedDesMod_E' enum)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedMkSk3desRun(s32 type, s32 gid, MfSdkPedMod_E mode, u8 *ind, s32 size, u8 iv[8], u8 *outd, MfSdkPedDesMod_E desMode);

/**
 * @brief computing mac
 * 
 * @param[in] fid field id (1 - MFSDK_SEC_MKSK_FIELD, 2 - MFSDK_SEC_DUKPT_FIELD, 3 - MFSDK_SEC_AES_FIELD)
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[in] format mac format (1 - MFSDK_SEC_MAC_UPAY_FORMAT, 2 - MFSDK_SEC_MAC_X99_FORMAT, 3 - MFSDK_SEC_MAC_X919_FORMAT, 4 - MFSDK_SEC_MAC_XOR_FORMAT)
 * @param[in] data mac source data
 * @param[in] len data length
 * @param[out] mac mac
 * @param[in] keyTpye key type(1 - MFSDK_DUKPT_DES_KEY_MAC1, 2 - MFSDK_DUKPT_DES_KEY_MAC2)
 * @param[in] keySize key size
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedMacProc(s32 fid, s32 gid, s32 format, u8 *data, s32 len, u8 *mac, s32 keyTpye, s32 keySize);

/**
 * @brief read pin ciphertext from the security keyboard
 * 
 * @param[in] fid field id (1 - MFSDK_SEC_MKSK_FIELD, 2 - MFSDK_SEC_DUKPT_FIELD, 3 - MFSDK_SEC_AES_FIELD)
 * @param[in] format pin format (0 - MFSDK_SEC_PIN_FORMAT0, 1 - MFSDK_SEC_PIN_FORMAT1, 2 - MFSDK_SEC_PIN_FORMAT2, 3 - MFSDK_SEC_PIN_FORMAT3, 4 - MFSDK_SEC_PIN_FORMAT4)
 * @param[in] gid key grouping ,max 100 group (0 - 99)
 * @param[in] pan card number
 * @param[out] pinBlock pin Block
 * @param[in] pin pin plaintext
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedEncryptPinProc(s32 fid, s32 format, s32 gid, u8 *pan, u8 *pinBlock, u8 *pin);


/**
 * @brief Pin mode config init  
 * pin is plaintext and 4-6 , it does not support bypass
 * MfSdkPedPinModCfg_T flag is 0
 */
LIB_EXPORT void MfSdkPedSetPinModeCfgInit(void);


/**
 * @brief Set enable pin input mode config
 * 
 * @param cfg For details, see MfSdkPedPinModCfg_T
 */
LIB_EXPORT void MfSdkPedSetPinModeCfg(MfSdkPedPinModCfg_T cfg);

/**
 * @brief Calculated pinblock value,MfSdkPedSetPinModeCfg needs to be called first.
 *
 * @param[in] pan card number
 * @param[out] pinBlock pin Block
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedEncryptPinProcEx(u8* pan, u8* pinBlock);
/**
 * @brief Get pin input mode config
 * 
 * @return MfSdkPedPinModCfg_T point
 */
LIB_EXPORT MfSdkPedPinModCfg_T *MfSdkPedGetPinModeCfg(void);

/**
 * @brief Get pin mode status
 * 
 * @param[out] length pin length
 * @return  0, Still input
 * @return  1, Press the enter(OK) button
 * @return  2, Press the exit button
 * @return  3, timeover
 */
LIB_EXPORT s32 MfSdkPedGetPinModeStatus(s32 *length);

/**
 * @brief save the private key to the security module
 * 
 * @param[in] index index key index (0 - 9)
 * @param[in] length rsa byte size(128/256)
 * @param[in] p private key P component
 * @param[in] q private key Q component
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSaveRsaPriKey(s32 index, s32 length, u8 *p, u8 *q);

/**
 * @brief save the public key to the security module
 * 
 * @param[in] index index key index (0 - 9)
 * @param[in] length length rsa byte size(128/256)
 * @param[in] n public  key N component
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSaveRsaPukKey(s32 index, s32 length, u8 *n);

/**
 * @brief RSA block calculation
 * 
 * @param[in] index index key index (0 - 9)
 * @param[in] inD in data
 * @param[out] outD out data
 * @param[in] length rsa key byte size(128/256)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedRsaBlock(s32 index, s8 *inD, s8 *outD, s32 length);

/**
 * @brief delete index key
 * 
 * @param[in] keyType 0:MKSK,1:DUKPT
 * @param[in] keyIndex key index(0-99)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedDeleteKey(s32 keyType, s32 keyIndex);


/**
 * @brief save key plaintext
 *
 * @param[in] type:default o
 * @param[in] mk: key for decrypt the TR31 string 
 * @param[in] nKeySize : mk size
 * @param[in] data : TR31 string
 * @param[in] size: TR31 data size
 * @param[out] wk: Decrypted key
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedTr31GetData(u32 type,  u8 *mk, s32 nKeySize,  u8 *data, s32 size, s8 *wk);

/**
 * @brief load the rki key use dukpt
 *
 * @param[in] keyData key data
 * @param[in] len key length
 * @return  0, success
 * @return	Other, failure
 */
LIB_EXPORT s32 MfSdkPedRkiDukptLoad(const s8 *keyData, s32 len);

/**
 * @brief verify the app hash
 *
 * @param[in] sHashValue sha256 value of app KEY
 * @return  1, Yes
 * @return	0, No
 */
LIB_EXPORT s32 MfSdkPedRkiCheckAppKey( u8 *sHashValue);

/**
 * @brief set input pinpad
 * 
 * @param[in] mod 1:external Pinpad, 0:device's Pinpad
 * 
 * @return	0, success
 * @return  For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSetPinpad(s32 mod);

/**
 * @brief get input pinpad
 * 
 * @return 1:external Pinpad, 
 * @return 0:device's Pinpad
 */
LIB_EXPORT s32 MfSdkPedGetPinpad(void);

/**
 * @brief Send page buf to external pinpad
 * 
 * @param[in] buff page buff(320*240)
 * @param[in] len buff len
 * @return  For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSetPedUi(u8 *buff, u32 len);

/**
 * @brief Use the external pinpad to check card
 * 
 * @return 0 no card
 * @return 1 icc card
 * @return 2 rfid cad
 * @return other fail
 */
LIB_EXPORT s32 MfSdkPedCheckCardOnce(void);

/**
 * @brief Whether the terminal has external pinpad.
 * 
 * @param[in] timeoutMs timeout
 * @return 1, Connect the external pinpad
 * @return 0, External pinpad is not connected
 */
LIB_EXPORT s32 MfSdkPedIsWithPinpad(s32 timeoutMs);

/**
 * @brief Update the external pinpad app.The pinpad app path must be in data/pinpad.bin
 * 
 * @param[in] cb Set the callback for the update process(500ms call once)
 * @return  0, success
 * @return  -2, uart communication timeout
 * @return	-5, no apps to update(mo data/pinpad.bin)
 * @return	-6, app to be updated failed to open
 * @return	-7, pinpad failed to write files
 * @return	-8, pinpad app md5 authentication failed
 * @return	-9, failed to reconnect to the pinpad after the update is complete
 * @return  ref.  MfSdkPedRet_E
 */
LIB_EXPORT s32 MfSdkPedExPinpadUpdate(MfSdkPedPinpadUpdateCb cb);
/**
 * @brief Get the version of the external pinpad
 * 
 * @param[out] buf Version buff
 * @param[in] bufSize Version buff size
 * @return  For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedGetExPinpadVersion(s8 *buf, s32 bufSize);

/**
 * @brief  Get the info of the external pinpad
 * 
 * @param info pinpad info
 * @return  For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedGetExPinpadInfo(MfSdkPedPinpadInfo_T *info);
/**
 * @brief Set the external pinpad pin 
 * 
 * @param[in] min pin min len
 * @param[in] max pin max len
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSetPedPinMod(s32 min, s32 max);
/**
 * @brief Gets the pin of the external pinpad
 * 
 * @param[out] len Enter the pin length
 * @param[out] pinBuf pin 
 * @return For details, see MfSdkPedPinpadStatus_E.
 * @return other fail
 */
LIB_EXPORT s32 MfSdkPedGetPin(s32 *len, s8 *pinBuf);
/**
 * @brief  Load TR-31 clear-text KBPK
 * 
 * @param[in] s32 gid  key index 0-99
 * @param[in] u8 *kbpk kbpk value
 * @param[in] u32 kbpkLen kbpk length
 * @return MFSDK_PED_PARM_ERROR  failed
 * @return MFSDK_PED_SUCCESS successful
 */
LIB_EXPORT s32 MfSdkPedTR31LoadKBPK(s32 gid, u8 *kbpk, u32 kbpkLen);
/**
 * @brief  Load cipher-text dukpt bdk/ipek by TR-31
 * 
 * @param[in] MfSdkPedTr31KeyType_E type  	key type (0 - ipek, 1 - bdk)
 * @param[in] s32 gid
 * @param[in] u8 *keyblock
 * @param[in] u32 keyblockLen
 * @return MFSDK_PED_SUCCESS
 * @return other fail
 */
LIB_EXPORT s32 MfSdkPedDukptLoadEncryptedKeyByTR31(MfSdkPedTr31KeyType_E type, s32 gid, u8 *keyblock, u32 keyblockLen);
/**
 * @brief  Load cipher-text dukpt bdk/ipek by TR-31
 * Note pKsn != NULL && ksnLength > 0 will load pKsn
 * @param[in] MfSdkPedTr31KeyType_E type  	key type (0 - ipek, 1 - bdk)
 * @param[in] s32 gid
 * @param[in] u8 *keyblock
 * @param[in] u32 keyblockLen
 * @param[in] u8 *pKsn 
 * @param[in] s32 ksnLength
 * @param[out] u8* kvc
 * @param[in]  s32 kvcLenth
 * @return MFSDK_PED_SUCCESS
 * @return other fail
 */
LIB_EXPORT s32 MfSdkPedDukptLoadEncryptedKeyByTR31A(MfSdkPedTr31KeyType_E type, s32 gid, u8 *keyblock, u32 keyblockLen, u8 *pKsn ,s32 ksnLength,u8 *kvc ,s32 kvcLenth);
/**
 * @brief Load cipher-text mk/wk by TR-31
 * 
 * @param[in] s32 type 
 *	MFSDK_MKSK_MAINKEY_TYPE 
 *	MFSDK_MKSK_PINENC_TYPE 
 *	MFSDK_MKSK_MACENC_TYPE 
 *	MFSDK_MKSK_MAGDEC_TYPE 
 *	MFSDK_MKSK_TRANSKEY_TYPE 
 * @param[in] u32 gid max 100 group (0 ~ 99)
 * @param[in] u8 *keyblock max 100 group (0 ~ 99)
 * @param[in] u32 keyblockLen  keyblock length
 * @return MFSDK_PED_SUCCESS
 * @return other fail
 */
LIB_EXPORT s32 MfSdkPedMkskSaveEncryptedKeyByTR31(s32 type, u32 gid, u8 *keyblock, u32 keyblockLen ,u8 *kvc ,s32 kvcLenth);

/**
 * @brief Save the mksk trans key
 * 
 * @param[in] gid max 100 group (0 ~ 99)
 * @param[in] key trans key
 * @return For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSetTransKey(s32 gid, s8 *key);

/**
 * @brief Get the mksk trans key kvc
 *
 * @param[in] gid max 100 group (0 ~ 99)
 * @param[out] kvcBuf kvc(Length 4 bytes)
 * @param[in] kvcBufLen kvcBuf len
 * @return For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedGetTransKeyKvc(s32 gid, s8* kvcBuf, s32 kvcBufLen);

/**
 * @brief Save the encrypted main key by trans key
 *
 * @param[in] gid max 100 group (0 ~ 99)
 * @param[in] key encrypted main key by trans key
 * @param[in] mode desMode des mode(see 'MfSdkPedDesMod_E' enum)
 * @param[out] kvcBuf kvc(Length 4 bytes)
 * @return For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSaveEncryptedMKByTransKey(u32 gid, u8* key, MfSdkPedDesMod_E mode, u8* kvc);

/**
 * @brief Delete the mksk trans key
 * 
 * @param[in] gid max 100 group (0 ~ 99)
 * @return  For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedDeleteTransKey(s32 gid);

/**
 * @brief Reboot the external pinpad
 * 
 * @return  For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedRebootCmd();

/**
 * @brief External pinpad Back to the main page
 *
 * @return  For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedGotoMainPage();
/**
 * @brief Save the aes key
 * 
 * @param[in] s32 type  MFSDK_MKSK_AES_KEY_TMK - MFSDK_MKSK_AES_KEY_TMK2_MAG
 * @param[in] s32 gid  0 - 49
 * @param[in] const u8 * key
 * @param[in] s32 length key length support 16 and 24 bytes
 * @param[out] u8 *kvc
 * @return ref. MfSdkPedRet_E
 */
LIB_EXPORT s32 MfSdkPedAesSavePlaintextKey(s32 type, s32 gid, const u8 * key,s32 length, u8*kvc);

/**
 * @brief Three-level key system
 * 
 * @param[in] int gid  key index 0 - 49
 * @param[in] int keyType key type MFSDK_MKSK_AES_KEY_TMK - MFSDK_MKSK_AES_KEY_TMK2_MAG
 * @param[in] unsigned char * data
 * @param[in] int size
 * @param[out] u8 checkvalue[4]
 * @return 0-successful 
 * @return other-failed 
 */
LIB_EXPORT s32 MfSdkPedTr31LoadAesKey(s32 gid, s32 keyType,const u8* data, s32 size, u8 checkvalue[4]);


/**
 * @brief use key aes operation
 * 
 * @param[in] type key type(0x08 - MFSDK_MKSK_AES_KEY_PINENC, 0x09 - MFSDK_MKSK_AES_KEY_MACENC, 0x0A - MFSDK_MKSK_AES_KEY_MAGENC ... MFSDK_MKSK_AES_KEY_TMK2_MAG)
 * @param[in]  gid key grouping,max 50 group (0 - 49)
 * @param[in]  mode mode(see 'MfSdkPedMod_E' enum)
 * @param[in]  ind raw data
 * @param[in]  size data length (16-bytes multiple)
 * @param[in]  iv initialization vector
 * @param[out]  outd calculation results
 * @param[in]  desMode des mode(see 'MfSdkPedDesMod_E' enum)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedMkSkAesRun(s32 type, s32 gid, MfSdkPedMod_E mode, u8 *ind, s32 size, u8 iv[16], u8 *outd, MfSdkPedDesMod_E desMode);

/**
 * @brief Save the p and q of the rsa key
 *
 * @param[in]  gid key grouping,max 20 group (0 - 19)
 * @param[in]  pBuf rsa p
 * @param[in]  pLen pBuf len
 * @param[in]  qBuf rsa q
 * @param[in]  qLen qBuf len
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSaveRsaKey(s32 gid, u8* pBuf, s32 pLen, u8* qBuf, s32 qLen);
/**
 * @brief delete rsa key
 *
 * @param[in]  gid key grouping,max 20 group (0 - 19)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedDelRsaKey(s32 gid);
/**
 * @brief Load cipher-text master key by Rsa(Decryption with private key)
 *
 * @param[in]  rsaGid rsa key grouping,max 20 group (0 - 19)
 * @param[in]  input ciphertext
 * @param[in]  keyGid master key grouping,max 100 group (0 - 99)
 * @param[in]  pinddingType pindding type
 * @param[in]  hashType hash type
 * @param[out]  kcv kvc(master key plaintext encryption 8 0x00)
 * @return s32 For details, see MfSdkPedRet_E.
 */
LIB_EXPORT s32 MfSdkPedSaveMasterKeyByRsa(s32 rsaGid, u8* input, s32 keyGid, MfSdkPedRsaPadding_E pinddingType, MfSdkPedRsaHash_E hashType, s8 kcv[4]);

/**
 * @brief set keydownload mode
 * 
 * @param[in] MFSDKBOOL enable, MFSDK_TRUE: enable keydownload,MFSDK_FALSE: disenable keydownload
 */
LIB_EXPORT void MfSdkPedKeyDownloadMode(MFSDKBOOL enable);
/**
 * @brief set key download command callback
 *
 * @param[in] MfSdkPowerResumeProcCb pFuncCb
 * @return
 */
LIB_EXPORT void MfSdkPedKeyDownloadProcCb(MfSdkPedKeyCmdCb pFuncCb);
#endif /* __MFSDK_PED_H__ */



