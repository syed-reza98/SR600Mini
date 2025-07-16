/**
 * @file mfsdk_rki.h
 * @author CHAR
 * @brief 
 * @date 2024-11-20
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_RKI_H__
#define __MFSDK_RKI_H__
/*NOTE: MFSDK_RKI_MAX_BUF_SIZE The value cannot be modified */
#define MFSDK_RKI_MAX_BUF_SIZE (4096)
/// certificate chain definition
typedef struct certificate_chain_t
{
    u8* ca_cert; /// The pointer of XXXX_CA_CERT/T_CA_CERT buffer
    u32 ca_cert_len; /// The length of XXXX_CA_CERT  T_CA_CERT buffer
    u8* subca_cert; /// The pointer of XXXX_SUBCA_CERT T_SUBCA_CERT buffer
    u32 subca_cert_len; /// The length of XXXX_SUBCA_CERT T_SUBCA_CERT buffer
    u8* subsubca_cert; /// The pointer of XXXX_SUBSUBCA_CERT  T_CIPHER_CERT buffer
    u32 subsubca_cert_len; /// The length of XXXX_SUBSUBCA_CERT  T_CIPHER_CERT buffer
}MfSdkRkiCrtChain_T;

typedef enum{
	MFSDK_RKI_TEST_CERT = 0,
	MFSDK_RKI_PREINSTALL_TEST_CERT = 1,
	MFSDK_RKI_RELEASE_CERT = 2,
}MfSdkRkiCertType_E;


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/**
 * @brief Authenticate Server certification chain.
 * 
 * @param[in] const MfSdkRkiCrtChain_T* chain
 * @return 0 success ,other failed 
 */
LIB_EXPORT s32 MfSdkRkiAuthKmsCertChain(const MfSdkRkiCrtChain_T* chain);
/**
 * @brief
 * 
 * @param[in] u8*priData RSA private key pem or der format.
 * @param[in] s32 priLength RSA private key length,if use pem format, priLength = strlen(priData) + 1
 * @param[in] const u8* input sign data 
 * @param[in] s32 ilen sign data length
 * @param[out] u8 *output out data 
 * @param[in] s32 length output buffer size
 * @return > 0  output data length ,other failed
 */
LIB_EXPORT s32 MfSdkRkiDataSignSha256(u8*priData, s32 priLength, const u8* input, s32 ilen,u8 *output, s32 length);
/**
 * @brief Form Terminal Cipher certificate (T_CIPHER_CERT)
 * 
 * @return 0 success ,other failed 
 */
LIB_EXPORT s32 MfSdkRkiFormTerminalCipherCert(void);
/**
 * @brief Generate Terminal Cipher key pair.
 * 
 * @return 0 success ,other failed 
 */
LIB_EXPORT s32 MfSdkRkiGenTerminalCipherKeyPair(void);
/**
 * @brief Get terminal certificate from secure storage
 * 
 * @param[out] MfSdkRkiCrtChain_T* chain
 * @return 0 success ,other failed 
 */
LIB_EXPORT s32 MfSdkRkiGetTerminalCertChain(MfSdkRkiCrtChain_T* chain);
/**
 * @brief
 * 
 * @param[in] const u8* key
 * @param[in] u32 len
 * @param[in] const u8* sig
 * @param[out] u8* kcv  
 * @return ref. API MfSdkPedAesSavePlaintextKey
 */
LIB_EXPORT s32 MfSdkRkiLoadTMK(const u8* key, u32 len, const u8* sig, u8* kcv);
/**
 * @brief  PKCS#1 v2.1 OAEP with SHA256
 * 
 * @param[in] const u8* pubCert  RSA public key cert
 * @param[in] s32 pubCertlen RSA public key cert length
 * @param[in] const u8* in 
 * @param[in] s32 inLength
 * @param[out] u8* out
 * @return > 0  out data length,other failed 
 */
LIB_EXPORT s32 MfSdkRkiPublicRsaOaep256(const u8* pubCert, s32 pubCertlen, const u8* in, s32 inLength, u8* out);
/**
 * @brief  Deprecated
 * 
 * @param[in] s32 flag  0-dynamic gen cipher use test cert, 
 *						1-load preinstall cipher use test cert , 
 *						2-use release cert  ref.  MfSdkRkiCertType_E
 */
LIB_EXPORT void MfSdkRkiSelfTest(s32 flag);

/**
 * @brief  it replaces MfSdkRkiSelfTest
 * 
 */
LIB_EXPORT s32 MfSdkRkiInit(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_RKI_H__ */
