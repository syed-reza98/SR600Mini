/**
 * @file mfsdk_comm.h
 * @author CHAR
 * @brief 
 * @date 2023-11-21
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */
#ifndef __MFSDK_COMM_H__
#define __MFSDK_COMM_H__
#include "libapi_comm.h"
#include "mfsdk_define.h"
typedef st_wifi_ap_list MfSdkCommWifiApList_T;
typedef st_apninfo_mcc MfSdkCommApinfoMcc_T;
typedef st_apninfo MfSdkCommApnInfo_T;

#define MFSDK_SYS_WIFI_DEFAULT_SAVE_PWD "0000000000000000000"
#define MFSDK_SYS_WIFI_MAX_AP_COUNT 30

typedef enum
{
    MFSDK_COMM_SOCKET_INDEX_MIN = 0,
    MFSDK_COMM_SOCKET_INDEX_0 = MFSDK_COMM_SOCKET_INDEX_MIN,
    MFSDK_COMM_SOCKET_INDEX_1,
    MFSDK_COMM_SOCKET_INDEX_2,
    MFSDK_COMM_SOCKET_INDEX_3,
    MFSDK_COMM_SOCKET_INDEX_4,
    MFSDK_COMM_SOCKET_INDEX_MAX
}MfSdkCommSocketIndex_E;

typedef enum
{
	MFSDK_COMM_NET_ONLY_WIRELESS = 0,		// only wireless 0 
	MFSDK_COMM_NET_ONLY_WIFI,				// only wifi
	MFSDK_COMM_NET_ONLY_WIRELESS_1,		    // only wireless 1 (Device not supported)
	MFSDK_COMM_NET_ONLY_ETHERNET,           // ETHERNET
	MFSDK_COMM_NET_FIRST_WIRELESS,           // wireless priority
	MFSDK_COMM_NET_FIRST_WIFI,				// wifi priority
}MfSdkCommNetSelect_E;

typedef MfSdkCommNetSelect_E MfSdkCommMode_E;

typedef enum
{
	MFSDK_COMM_UART_COM0 = 0,
	MFSDK_COMM_UART_COM1,
	MFSDK_COMM_UART_COM2,
	MFSDK_COMM_UART_COM3,
	MFSDK_COMM_UART_COM4,
	MFSDK_COMM_UART_COM5,
	MFSDK_COMM_UART_COM6,
	MFSDK_COMM_UART_COM7,
	MFSDK_COMM_UART_COM8,
	MFSDK_COMM_UART_COM9,
	MFSDK_COMM_UART_COM10,
	MFSDK_COMM_UART_COM11,
	MFSDK_COMM_UART_COM12,
	MFSDK_COMM_UART_COM13,
	MFSDK_COMM_UART_COM14,
	MFSDK_COMM_UART_COM15,
	MFSDK_COMM_UART_COM16,
	MFSDK_COMM_UART_COM17,
	MFSDK_COMM_UART_COM18,
	MFSDK_COMM_UART_COM19,
	MFSDK_COMM_UART_COM20,
	MFSDK_COMM_UART_COM21,
	MFSDK_COMM_UART_COM22,
	MFSDK_COMM_UART_COM23,
	MFSDK_COMM_UART_COM24,
	MFSDK_COMM_UART_COM25,
	MFSDK_COMM_UART_COM26,
	MFSDK_COMM_UART_COM27,
	MFSDK_COMM_UART_COM28,
	MFSDK_COMM_UART_COM29,
	MFSDK_COMM_UART_COM30,
}MfSdkCommUart_E;

typedef enum
{
	MFSDK_COMM_RET_FAILED = -3, //failed 
	MFSDK_COMM_RET_BOUNDS = -2, //Array out-of-bounds 
	MFSDK_COMM_RET_PARM_ERROR = -1, //check param
	MFSDK_COMM_RET_OK = 0,
}MfSdkCommRet_E;

typedef enum
{
	MFSDK_COMM_ATCCPIN_FAIL = 0, //Failure
	MFSDK_COMM_ATCCPIN_LOCKED,  //locked
	MFSDK_COMM_ATCCPIN_NORMAL, //noraml
	MFSDK_COMM_ATCCPIN_PUK  //Puk
}MfSdkCommAtcCpin_E;

typedef enum
{
	MFSDK_COMM_WIFI_STATE_CONNECT_PROCESS = -999,
	MFSDK_COMM_WIFI_STATE_DISCONNECT_PROCESS = -998,
	MFSDK_COMM_WIFI_STATE_CONNECT_START = -997,
	MFSDK_COMM_WIFI_STATE_NOT_EXIST = -2,
	MFSDK_COMM_WIFI_STATE_PWD_ERROR = -1,
	MFSDK_COMM_WIFI_STATE_DISCONNECT = 0,
	MFSDK_COMM_WIFI_STATE_CONNECT = 1,
}MfSdkCommWifiState_E;

typedef enum
{
	MFSDK_COMM_MOBILE_NO_SIGNAL = 0,
	MFSDK_COMM_MOBILE_1G, //The 1st Generation Mobile Communication System
	MFSDK_COMM_MOBILE_2G, //The 2nd Generation Mobile Communication System
	MFSDK_COMM_MOBILE_3G, //The 3rd Generation Mobile Communication System
	MFSDK_COMM_MOBILE_4G, //The 4th Generation Mobile Communication System
	MFSDK_COMM_MOBILE_5G,//RFU The 5th Generation Mobile Communication System
	MFSDK_COMM_MOBILE_6G,//RFU The 6th Generation Mobile Communication System
}MfSdkCommMobileGen_E;

typedef enum
{
	MFSDK_COMM_IPV4 = 1,  //only ipv4
	MFSDK_COMM_IPV6,    //only ipv6
	MFSDK_COMM_IPV4_IPV6,	// both ipv4 and ipv6
}MfSdkCommIpVer_E;

typedef enum
{
	MFSDK_COMM_ATC_OFF = 0, // turn off
	MFSDK_COMM_ATC_ON,	  //turn on		
}MfSdkCommAtcPowerState_E;

typedef enum
{
	MFSDK_COMM_SIM_PROC_PPP_NETWORK_OK = 0,
	MFSDK_COMM_SIM_PROC_NETWORK_CONNECTED,
	MFSDK_COMM_SIM_PROC_NETWORK_REGISTER_NETOWK,
	MFSDK_COMM_SIM_PROC_SIM_NORMAL,
	MFSDK_COMM_SIM_PROC_SWITCHING_SIM,
	MFSDK_COMM_SIM_PROC_NO_SIM_CARD,

}MfSdkCommSimProcStatus_E;

typedef enum
{
	MFSDK_COMM_IPTYPE_V4,  // Get IP address type  IPv4
	MFSDK_COMM_IPTYPE_V6,  // Get IP address type  IPv6
}MfSdkCommIpType_E;

typedef enum
{
	MFSDK_COMM_TLS_V1_2 = 0,	// TLS 1.2 default
	MFSDK_COMM_TLS_V1_3,		// TLS 1.3		
}MfSdkCommTlsVer_E;

typedef struct
{
	char  ip[20];		/*IP address*/
	char  gateway[30];	/*Local gateway*/
	char  mask[30];		/*Local subnet mask*/
	char  dns[30];		/*DNS*/
}MfSdkCommLanCfg_T;

/**
 * @brief
 */
typedef void (*MfSdkCommSetApnProcCb)(void);

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/**
 * @brief Get net link state for both GPRS and Wifi 
 *
 * @return  1, linked
 * @return  0, disconnect
 */
LIB_EXPORT MFSDKBOOL MfSdkCommLinkState(void);
/**
 * @brief
 * 
 * @return Ref. MfSdkCommMode_E
 */
LIB_EXPORT MfSdkCommMode_E MfSdkCommGetNetMode(void);
/**
 * @brief get 1st net registered cell
 * 
 * @param[in] s32 index
 * @return Cell ID
 */
LIB_EXPORT s32 MfSdkCommAtcCell(s32 index);
/**
 * @brief get net registered cell
 * 
 * @param[in] s32 *cid buffer
 * @param[in] s32 size buffer size
 * @param[out] s32 *num
 * @return  MFSDK_COMM_RET_OK The number that get
 * @return  other fail
 */
LIB_EXPORT s32 MfSdkCommAtcCellInfor(s32 *cid, s32 size, s32 *num);
/**
 * @brief
 * Ref. MfSdkCommAtcCpin_E
 * @param[in] s32 index
 * @return  MFSDK_COMM_ATCCPIN_FAIL, Failure
 * @return  MFSDK_COMM_ATCCPIN_LOCKED, Locked
 * @return  MFSDK_COMM_ATCCPIN_NORMAL, Normal
 * @return  MFSDK_COMM_ATCCPIN_PUK, Puk  
 */
LIB_EXPORT MfSdkCommAtcCpin_E MfSdkCommAtcCpin(s32 index);
/**
 * @brief Get local ip
 * 
 * @param[out] s8* ip
 * @return 
 */
LIB_EXPORT s32 MfSdkCommAtcGetLocalIp(s8* ip);

/**
 * @brief Get index Integrate circuit card identity value
 * 
 * @param[in] s32 index
 * @return iccid
 */
LIB_EXPORT const s8* MfSdkCommAtcIccid(s32 index);
/**
 * @brief Get Module imei
 * 
 * @param[in] s32 index
 * @return  imei value
 */
LIB_EXPORT const s8* MfSdkCommAtcImei(s32 index);
/**
 * @brief Get Module imsi
 * 
 * @param[in] s32 index
 * @return imsi value
 */
LIB_EXPORT const s8* MfSdkCommAtcImsi(s32 index);
/**
 * @brief Get net registered lac
 *
 * @param[in] s32 index GPRS/4G index 0-1
 * @return  lac value 
 */
LIB_EXPORT s32 MfSdkCommAtcLac(s32 index);

/**
 * @brief  Get MCC
 * 
 * @param[in] s32 index  Soundbox use 0
 * @return mcc
 */
LIB_EXPORT s32 MfSdkCommAtcGetMcc(s32 index);

/**
 * @brief Gey MNC
 * 
 * @param[in] s32 index  Soundbox use 0
 * @return mnc
 */
LIB_EXPORT s32 MfSdkCommAtcGetMnc(s32 index);

/**
 * @brief get net registered lac
 * 
 * @param[in] s32 *lac buffer
 * @param[in] s32 size buffer size
 * @param[out] s32 *num  lac num
 * @return MFSDK_COMM_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkCommAtcLacInfor(s32 *lac, s32 size, s32 *num);

/**
 * @brief Get Module signal
 *
 * @param[in] index GPRS/4G index 0-1
 * @return  0, Unregistered
 * @return  1, One grid signal
 * @return  2, Two grid signal
 * @return  3, Three grid signal
 * @return  4, Four grid signal
 */
LIB_EXPORT s32 MfSdkCommAtcSignal(s32 index);
/**
 * @brief Get the atc generation
 *
 * @param[in] index sim index 0-1 (Single sim card select 0)
 * @return  Ref. MfSdkCommMobileGen_E
 */
LIB_EXPORT MfSdkCommMobileGen_E MfSdkCommGetAtcGeneration(s32 index);

/**
 * @brief Get the atc power
 *
 * @return  Ref. MfSdkCommAtcPowerState_E
 */
LIB_EXPORT MfSdkCommAtcPowerState_E MfSdkCommGetAtcPower(void);
/**
 * @brief Send and recv AT commend (4G module)
 *
 * @param[in] cmd: 
 * @param[in] timeout   unit: ms
 * @param[in] RecvSize:size of recv buff
 			  count: resend count
 * @param[out] RecvData: AT commend respond
 * @return  0,success
 */
LIB_EXPORT s32 MfSdkCommAtcSendCmd(s8 * cmd,s8 * RecvData,s32 RecvSize,s32 timeout,s32 count);

/**
 * @brief Get mode of wifi or gprs or the Priority
 *
 * @return  0, WIRELESS
 * @return  1, WIFI
 * @return Ref. MfSdkCommNetSelect_E
 */
LIB_EXPORT MfSdkCommNetSelect_E MfSdkCommGetNetSelect(void);

/**
 * @brief Read the id of the working sim card(Only devices with two sim cards are supported)
 *
 * @return 0 sim1
 * @return 1 sim2
 * @return Other,fail
 */
LIB_EXPORT s32 MfSdkCommGetOperateId(void);
/**
 * @brief Get the WiFi power
 *
 * @return  0, Power off
 * @return  1, Power on
 */
LIB_EXPORT s32 MfSdkCommGetWifiPower(void);

/**
 * @brief Get gsm signal
 * 
 * @return 
 */
LIB_EXPORT s32 MfSdkCommGsmGetSignal(void);

/**
 * @brief HTTP download
 * 
 * @param[in] s8 *url url address
 * @param[in] s8*fullpathfilename The full name of the downloaded file
 * @param[in] s32 iscontinue 1-sequel 0-download again
 * @param[in] s32 nRetry  retry count
 * @return MFSDK_COMM_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkCommHttpDownload(s8 *url, s8*fullpathfilename, s32 iscontinue, s32 nRetry);
/**
 * @brief if you use mbedtls ,need init mbedtls
 * 
 * @param[in] int use_session
 * @param[in] int loglevel
 * @return Ref. MfSdkCommRet_E
 */
LIB_EXPORT s32 MfSdkCommMbedtlsInit(s32 useSession, s32 logLevel);
/**
 * @brief Connect Network
 * 
 * @param[in] void * pfunc
 * @param[in] char * apn
 * @param[in] s32 timeover
 * @return  MFSDK_COMM_RET_OK, success
 * @return  other, fail
 */
LIB_EXPORT s32 MfSdkCommNetLink(void * pfunc, char * apn, s32 timeover);
/**
 * @brief Connect Network
 *
 * @param[in] apn GPRS apn
 * @param[in] user GPRS apn user id
 * @param[in] pwd GPRS apn user password
 * @return  MFSDK_COMM_RET_OK, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommNetLinkWithUserInfo(s8 * apn, s8 *user, s8 *pwd);
/**
 * @brief Disconnect from the network
 *
 * @return  MFSDK_COMM_RET_OK, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommNetUnlink(void);
/**
 * @brief set IPV version, should be called in main.c before network initial
 * Functions:
 * @param[in] s32 mode MfSdkCommIpVer_E 1:only IPV4; 2:only IPV6; 3:IPV4&IPV6
 * @return  MfSdkCommRet_E
 */
LIB_EXPORT s32 MfSdkCommSetApMode(MfSdkCommIpVer_E mode);
/**
 * @brief
 * 
 * @param[in] MfSdkCommApnInfo_T apn_list[] APN operator corresponding list
 * @param[in] s32 ncount APN count
 * @return MfSdkCommRet_E
 */
LIB_EXPORT s32 MfSdkCommSetApnList(MfSdkCommApnInfo_T apn_list[], s32 ncount);

/**
 * @brief
 * 
 * @param[in] apnlistMcc apn list
 * @param[in] count apn count
 * @return  MFSDK_COMM_RET_OK, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommSetApnListMcc(MfSdkCommApinfoMcc_T*apnlistMcc, s32 count);

/**
 * @brief Set the atc power
 *
 * @param[in] MfSdkCommAtcPowerState_E flag 0 - Turn off atc, 1 - Turn on atc
 * @return  MFSDK_COMM_RET_OK, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommSetAtcPower(MfSdkCommAtcPowerState_E flag);
/**
 * @brief set gprs apn
 *  
 * @param[in] s8 *apn  GPRS APN
 * @param[in] s8 *user GPRS USER
 * @param[in] s8 *pwd  GRPS PASSWORD
 * @return 
 */
LIB_EXPORT s32 MfSdkCommSetInitApn(s8 *apn, s8 *user, s8 *pwd);
/**
 * @brief Switch network switching mode
 *
 * @param[in] s32 mode MfSdkCommNetSelect_E
 */

LIB_EXPORT s32 MfSdkCommSetNetMode(s32 mode);
/**
 * @brief
 * 
 * @param[in] MfSdkCommNetSelect_E index
 * @return 
 */
LIB_EXPORT s32 MfSdkCommSetNetSelect(MfSdkCommNetSelect_E index);


/**
 * @brief set wifi name, (WiFi version V5.1.2 and above support modify the wifi name)
 * 
 * @param[in] s32 mode mode = 0: KM_AP, default: KM_(SN)
 * @return 
 */
LIB_EXPORT s32 MfSdkCommSetWifiName(s32 mode);

/**
 * @brief set wifi host name
 * 
 * @param[in] s8 *hostname hostname
 * @return 
 */
s32 MfSdkCommSetWifiHostName(s8* hostname);
/**
 * @brief Disconnect the server, Support for SSL and non-SSL.
 *
 * @param[in] index Sock index (1-4)
 * @return  MFSDK_COMM_RET_OK, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommSocketClose(MfSdkCommSocketIndex_E index);
/**
 * @brief Connect to the server, Support for SSL and non-SSL.
 *
 * @param[in] index Sock index (1-4)
 * @param[in] ip IP address
 * @param[in] port Port number
 * @param[in] timeoutMs time-out period unit:ms
 * @param[in] func callback function
 * @return  >= 0, Success
 * @return  < 0, Failure
 */
LIB_EXPORT s32 MfSdkCommSocketConnect(MfSdkCommSocketIndex_E index, s8 *ip, s32 port, s32 timeoutMs, void *func);
/**
 * @brief
 * 
 * @param[in] s32 mode mode=0(priority ipv4);mode=1(priority ipv6)
 * @return MFSDK_COMM_RET_OK success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkCommSocketConnectPriority(s32 mode);
/**
 * @brief Create socket
 *
 * @param[in] index Sock index (1-4)
 * @return  >= 0, Success
 * @return  < 0, Failure
 */
LIB_EXPORT s32 MfSdkCommSocketCreate(MfSdkCommSocketIndex_E index);
/**
 * @brief
 * 
 * @param[in] s32 index
 * @param[in] s32 size
 * @return  >= 0, Success
 * @return  < 0, Failure
 */
LIB_EXPORT s32 MfSdkCommSocketFifoResize(s32 index, s32 size);
/**
 * @brief Receive data, Support for SSL and non-SSL.
 *
 * @param[in] index Sock index (1-4)
 * @param[out] buff Receive buffer
 * @param[out] len Receiving length
 * @param[in] timeover Receive timeout
 * @return  = -1, Network disconnection
 * @return  = 0, Timeout
 * @return  > 0, Receive length
 */
LIB_EXPORT s32 MfSdkCommSocketRecv(MfSdkCommSocketIndex_E index, u8 * buff, s32 len, u32 timeover);
/**
 * @brief Send data, Support for SSL and non-SSL.
 *
 * @param[in] index Sock index (1-4)
 * @param[in] buff Send buffer
 * @param[in] size Send length
 * @return   < 0, Failure
 * @return other, Success
 */
LIB_EXPORT s32 MfSdkCommSocketSend(MfSdkCommSocketIndex_E index, u8* buff, s32 size);
/**
 * @brief Set the certificate verification mode.
 * 
 * @param[in] MfSdkCommSocketIndex_E index Sock index (1-4)
 * @param[in] s32 authMode Ref. 
 * 						MBEDTLS_SSL_VERIFY_NONE    
 * 						MBEDTLS_SSL_VERIFY_OPTIONAL
 * 						MBEDTLS_SSL_VERIFY_REQUIRED
 * 						MBEDTLS_SSL_VERIFY_UNSET   
 * @return MFSDK_COMM_RET_OK success
 * @return MFSDK_COMM_RET_FAILED failed
 */
LIB_EXPORT s32 MfSdkCommSslAuthMode(MfSdkCommSocketIndex_E index, s32 authMode);
/**
 * @brief
 * The API MfSdkCommSslClose is already deprecated.
 * Use new API MfSdkCommSocketClose pls. 
 * @param[in] MfSdkCommSocketIndex_E index Sock index (1-4)
 * @return MFSDK_COMM_RET_OK success
 * @return MFSDK_COMM_RET_FAILED failed
 */
LIB_EXPORT MFSDK_DEPRECATED("MfSdkCommSocketClose") s32 MfSdkCommSslClose(MfSdkCommSocketIndex_E index);
/**
 * @brief 
 * The API MfSdkCommSslConnect is already deprecated.
 * Use new API MfSdkCommSocketConnect pls.
 * 
 * @param[in] MfSdkCommSocketIndex_E index Sock index (1-4)
 * @param[in] char * ip IP address
 * @param[in] s32 port Port number
 * @param[in] void *func callback function  int (*connect_server_func)(void);
 * @return MFSDK_COMM_RET_OK success
 * @return MFSDK_COMM_RET_FAILED failed
 */
LIB_EXPORT MFSDK_DEPRECATED("MfSdkCommSocketConnect") s32 MfSdkCommSslConnect(MfSdkCommSocketIndex_E index, char * ip, s32 port, void *func);
/**
 * @brief
 * 
 * @param[in] MfSdkCommSocketIndex_E index Sock index (1-4)
 * @param[in] char * cacert
 * @param[in] char * clientcert
 * @param[in] char * clientkey
 * @param[in] s32 level level Verification level 0=Not verified 1=Verify server certificate
 * @return MFSDK_COMM_RET_OK success
 * @return MFSDK_COMM_RET_FAILED failed
 */
LIB_EXPORT s32 MfSdkCommSslInit(MfSdkCommSocketIndex_E index, char * cacert, char * clientcert, char * clientkey, s32 level);
/**
 * @brief
 * 
 * @param[in]MfSdkCommSocketIndex_E index Sock index (1-4)

 * @param[in]  char * cn : hostname
 * @return MFSDK_COMM_RET_OK success
 * @return MFSDK_COMM_RET_FAILED failed
 */
LIB_EXPORT s32 MfSdkCommSslSetHostname(MfSdkCommSocketIndex_E index , const char * cn);
/**
 * @brief
 * 
 * @param[in] s32 mbedtls
 * @return MFSDK_COMM_RET_OK success
 * @return MFSDK_COMM_RET_FAILED failed 
 */
LIB_EXPORT s32 MfSdkCommSslMbedtls(s32 mbedtls);
/**
 * @brief
 * The API MfSdkCommSslRecv is already deprecated.
 * Use new API MfSdkCommSocketRecv pls.
 *  
 * @param[in] MfSdkCommSocketIndex_E index
 * @param[out] char * pdata
 * @param[in] s32 size
 * @return 
 */
LIB_EXPORT MFSDK_DEPRECATED("MfSdkCommSocketRecv") s32 MfSdkCommSslRecv(MfSdkCommSocketIndex_E index, char * pdata, s32 size);
/**
 * @brief
 * The API MfSdkCommSslSend is already deprecated.
 * Use new API MfSdkCommSocketSend pls.
 *  
 * @param[in] MfSdkCommSocketIndex_E index
 * @param[in] char * pdata
 * @param[in] s32 size
 * @return 
 */
LIB_EXPORT MFSDK_DEPRECATED("MfSdkCommSocketSend") s32 MfSdkCommSslSend(MfSdkCommSocketIndex_E index, char * pdata, s32 size);
/**
 * @brief
 * 
 * @param[in] s32 index
 * @param[in] char * pdata
 * @param[in] s32 size
 * @return 
 */
LIB_EXPORT s32 MfSdkCommSslSend2(s32 index, char * pdata, s32 size);
/**
 * @brief Clear uart fifo buff
 * 
 * @param[in] nCom For details, see MfSdkCommUart_E.
 * @return MFSDK_COMM_RET_OK,success;other fail
 */
LIB_EXPORT s32 MfSdkCommUartClear(MfSdkCommUart_E nCom);
/**
 * @brief close uart port
 * 
 * @param[in] nCom For details, see MfSdkCommUart_E.
 * @return MFSDK_COMM_RET_OK,success;other fail
 */
LIB_EXPORT s32 MfSdkCommUartClose(MfSdkCommUart_E nCom);
/**
 * @brief Get receive buff len
 * 
 * @param[in] nCom For details, see MfSdkCommUart_E.
 * @return receive buff len
 */
LIB_EXPORT s32 MfSdkCommUartGetRxBufLength(MfSdkCommUart_E nCom);
/**
 * @brief open uart port
 * 
 * @param[in] nCom For details, see MfSdkCommUart_E.
 * @param[in] u32 nBaud Baud rate
 * @param[in] u32 nData Data bits
 * @param[in] u32 nStop Stop bits
 * @param[in] u32 nParity Parity
 * @return 
 */
LIB_EXPORT s32 MfSdkCommUartOpen(MfSdkCommUart_E nCom, u32 nBaud,u32 nData,u32 nStop,u32 nParity);
/**
 * @brief receive uart port data
 * 
 * @param[in] nCom For details, see MfSdkCommUart_E.
 * @param[out] u8* pBuffer recv buffer
 * @param[in] u32 nLength recv length
 * @param[in] s32 timeout time-out period
 * @return >=0 receive data len
 */
LIB_EXPORT s32 MfSdkCommUartRecv(MfSdkCommUart_E nCom, u8* pBuffer, u32 nLength, s32 timeout);
/**
 * @brief send uart port data
 * 
 * @param[in] nCom For details, see MfSdkCommUart_E.
 * @param[in] u8* pBuffer send buffer
 * @param[in] u32 nLength send buffer length
 * @return >=0 send data len
 */
LIB_EXPORT s32 MfSdkCommUartSend(MfSdkCommUart_E nCom, u8* pBuffer, u32 nLength);

/**
 * @brief set uart comm buffer size
 * 
 * @param[in] nCom For details, see MfSdkCommUart_E.
 * @param[in] u8* buffer uart comm buffer handler
 * @param[in] s32 size buffer size
 * @return MFSDK_COMM_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkCommUartSetupComm(MfSdkCommUart_E nCom , u8* buffer , s32 size);

/**
 * @brief Clear wifi ap list
 * 
 * @return MFSDK_COMM_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkCommWifiClearListApNum(void);
/**
 * @brief Get Wifi AP MAC
 * 
 * @return AP Mac
 */
LIB_EXPORT s8 *MfSdkCommWifiGetApMac(void);
/**
 * @brief Get wifi channel
 * 
 * @return wifi channel
 */
LIB_EXPORT s32 MfSdkCommWifiGetChannel(void);
/**
 * @brief Get connection status
 * Ref. MfSdkCommWifiLinkState_E
 * @return  MFSDK_COMM_WIFI_STATE_CONNECT, Connection
 * @return  MFSDK_COMM_WIFI_STATE_DISCONNECT, Disconnect
 * @return  MFSDK_COMM_WIFI_STATE_PWD_ERROR, Pwd error 
 * @return  MFSDK_COMM_WIFI_STATE_NOT_EXIST, No exist 
 * @return  MFSDK_COMM_WIFI_STATE_CONNECT_PROCESS, Connect in process
 * @return  MFSDK_COMM_WIFI_STATE_DISCONNECT_PROCESS, Disconnect in process
 * @return  MFSDK_COMM_WIFI_STATE_CONNECT_START, Connect start 
 */
LIB_EXPORT MfSdkCommWifiState_E MfSdkCommWifiGetLinkState(void);
/**
 * @brief Get Local IP
 * 
 * @return wifi ip
 */
LIB_EXPORT s8* MfSdkCommWifiGetLocalip(void);
/**
 * @brief Get Wifi Mac
 * 
 * @return wifi mac
 */
LIB_EXPORT s8* MfSdkCommWifiGetLocalMac(void);
/**
 * @brief Get Wifi Rssi
 * 
 * @return wifi rssi
 */
LIB_EXPORT s32 MfSdkCommWifiGetRssi(void);
/**
 * @brief Get Wifi Signal
 * 
 * @return wifi signal
 */
LIB_EXPORT s32 MfSdkCommWifiGetSignal(void);
/**
 * @brief Get Wifi Ssid
 * 
 * @return  wifi ssid
 */
LIB_EXPORT s8 *MfSdkCommWifiGetSsid(void);
/**
 * @brief Connect to WiFi
 * 
 * @param[in] apList wifi info
 * @param[in] pwd wifi password
 * @return MFSDK_COMM_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkCommWifiLinkAp(MfSdkCommWifiApList_T *apList, s8 *pwd);
/**
 * @brief Get the router list
 *
 * @param[out] ap_list Router list data, 
 * The ap_list space is allocated by the 
 * caller with an array size of 10/30(Soundbox 10,traditional POS 30)
 * @return  Number of routers
 */
LIB_EXPORT s32 MfSdkCommWifiListAp(MfSdkCommWifiApList_T *apList);
/**
 * @brief quit the router list
 * 
 * @return MFSDK_COMM_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkCommWifiListApQuit(void);
/**
 * @brief Get the router save ap list
 * 
 * @param[out] ap_list Router list data, 
 * The ap_list space is allocated by the 
 * caller with an array size of 10/30(Soundbox 10,traditional POS 30)
 * @return Number of routers
 */
LIB_EXPORT s32 MfSdkCommWifiListNetWork(MfSdkCommWifiApList_T *apList);
/**
 * @brief Remove Wifi Ap
 * 
 * @param[in] ssid Wifi Ap
 * @return MFSDK_COMM_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkCommWifiRemoveNetWorkAp(s8* ssid);
/**
 * @brief Set the WiFi power
 * 
 * @param[in] flag 0 - Turn off wifi power; 1 - Turn on wifi power
 * @return  MFSDK_COMM_RET_OK, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommWifiSetPower(s32 flag);
/**
 * @brief Start scan wifi
 * 
 * @param[in] flag 0:stop scan 1:auto scan one time 2:scan immediately one time
 * @return MFSDK_COMM_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkCommWifiSetScan(s32 flag);
/**
 * @brief Unlink wifi ap
 * 
 * @param[in] ssid wifi ap
 * @return MFSDK_COMM_RET_OK success
 * @return other failed
 */
LIB_EXPORT s32 MfSdkCommWifiUnlinkAp(s8 *ssid);

/**
 * @brief set net to 4G mode
 * 
 * @return MFSDK_COMM_RET_OK success
 */
LIB_EXPORT s32 MfSdkCommSet4gMode(void);
/**
 * @brief check wifi state
 * 
 * @return 1- sucess 
 * @return other fail
 */
LIB_EXPORT s32 MfSdkCommWifiCheckState(void);
/**
 * @brief start config wifi 
 * 
 * @return MFSDK_COMM_RET_OK success
 */
LIB_EXPORT s32 MfSdkCommWifiStartConfig(void);

/**
 * @brief init device uart
 * 
 */
LIB_EXPORT void MfSdkCommUartInit(void);
/**
 * @brief Whether the device is connected to a network cable
 * 
 * @return 0 unconnected
 * @return 1 connected
 */
LIB_EXPORT s32 MfSdkCommLanCableCheck(void);

/**
 * @brief Set whether to enable DHCP
 * 
 * @param[in] mod 1 enable,0 disenable
 * @return 0 success
 * @return other fail
 */
LIB_EXPORT s32 MfSdkCommLanSetDHCP(int mod);

/**
 * @brief Whether to enable DHCP
 * 
 * @return  0 disenable
 * @return  1 enable
 * @return  other fail
 */
LIB_EXPORT s32 MfSdkCommLanIsDHCP();

/**
 * @brief Configuring Ethernet
 * 
 * @param lanCfg Configuring Ethernet
 * @return  nothing
 */
LIB_EXPORT void MfSdkCommLanCfg(const MfSdkCommLanCfg_T *lanCfg);

/**
 * @brief get the status of the sim card switchover
 * 
 * @return  For details, see MfSdkCommSimProcStatus_E
 */
LIB_EXPORT MfSdkCommSimProcStatus_E MfSdkCommGetSwitchSimProcStatus();

/**
 * @brief set the id of the working sim card(nonblocking)(Only devices with two sim cards are supported)
 * 
 * @param[in] val 0:sim1 , 1: sim2
 * @return >=0 ,success
 * @return Other,fail
 */
LIB_EXPORT s32 MfSdkCommSetOperateIdTask(s32 val);
/**
 * @brief init wifi logo
 * 
 * @param[in] void* state  lv_obj_t* 
 * @param[in] int mode	logo color 0-black ,1-white
 */
LIB_EXPORT void MfSdkCommWifiPageInitMode(void* state,int mode);
/**
 * @brief init wifi page
 * 
 * @param[in] void* obj lv_obj_t* 
 * @param[in] int align ref. lv_align_t
 * @param[in] int x_ofs x offset
 * @param[in] int y_ofs y offset
 */
LIB_EXPORT void MfSdkCommWifiPageInit(void* obj, int align, int x_ofs, int y_ofs);
/**
 * @brief init gprs page 
 * 
 * @param[in] void* obj lv_obj_t* 
 * @param[in] int align ref. lv_align_t
 * @param[in] int x_ofs x offset
 * @param[in] int y_ofs y offset
 */
LIB_EXPORT void MfSdkCommAtcPageInit(void* obj, int align, int x_ofs, int y_ofs);
/**
 * @brief init GSM logo
 * 
 * @param[in] void* state  lv_obj_t* 
 * @param[in] int mode	logo color 0-black ,1-white
 */
LIB_EXPORT void MfSdkCommAtcPageInitMode(void* state,int mode);

/**
 * @brief enable Ethernet
 * 
 * @return  For details, see MfSdkCommRet_E
 */
LIB_EXPORT s32 MfSdkCommLanEnable();

/**
 * @brief disenable Ethernet
 *
 * @return  For details, see MfSdkCommRet_E
 */
LIB_EXPORT s32 MfSdkCommLanDisenable();

/**
 * @brief Get local IP, default IPv4
 * 
 * @param[in] MfSdkCommIpType_E ipType	IPv4/IPv6
 * @param[out] s8* ip  ip buffer
 * @param[in] s32 length  ip buffer size
 * @return > 0 ip length
 * @other failed
 */
LIB_EXPORT s32 MfSdkCommAtcGetIp(MfSdkCommIpType_E ipType, s8* ip ,s32 length);

/**
 * @brief Get Ethernet Power
 * 
 * @return  0 Turn off 
 * @return  1 Turn on
 */
LIB_EXPORT s32 MfSdkCommLanGetEthernetPower(void);

/**
 * @brief Set Ethernet Power
 * 
 * @param[in] flag 0 - Turn off , 1 - Turn on
 * @return  For details, see MfSdkCommRet_E
 */
LIB_EXPORT s32 MfSdkCommLanSetEthernetPower(s32 flag);

/**
 * @brief Check if the device has a Ethernet chip
 *
 * @return  1 Have Ethernet chip
 * @return  0 No Ethernet chip
 */
LIB_EXPORT s32 MfSdkCommLanChipExist();

 /**
 * @brief Check if the device has a WiFi chip
 *
 * @return  1 Have WiFi chip
 * @return  0 No WiFi chip
 */
LIB_EXPORT s32 MfSdkCommWifiChipExist();

/**
 * @brief Set network mode
 *
 * @param[in] mode	 0 = "AUTO";
				 1  = "only 2G";
				 2 = "only 3G";
				 3 = "only 4G";
				 4 = "2G_3G";
				 5 = "2G_3G_4G";
 */
LIB_EXPORT void MfSdkCommAtcSetNetMode(s32 mode);

/**
 * @brief Send AT command
 *
 * @param[in] cmd at cmd
 * @param[in] timeover timeover(ms)
 * @param[out] retstr Returned data
 * @param[in] len AT cmd len
 * @param[in] count retry count
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommAtcSendAtCmd(s8* cmd, s32 timeover, s8* retstr, s32 len, s32 count);

/**
 * @brief Get Ethernet IP and mask
 *
 * @param[out] ip ip info
 * @param[out] Mask mask info
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommLanGetIpAndMask(s8* ip, s8* Mask);

/**
 * @brief Get Ethernet Gateway
 *
 * @param[out] Gateway Gateway info
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommLanGetGateway(s8* gateway);

/**
 * @brief Get Ethernet DNS
 *
 * @param[out] dnsArr dns info
 * @param[int] dnsArrCount dns array count
 * @return  >0, Success,count of DNS
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommLanGetDns(s8 dnsArr[][64], s32 dnsArrCount);

/**
 * @brief Get Ethernet mac
 *
 * @param[out] mac mac info
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommLanGetMac(s8* mac);

/**
 * @brief  Reply to network connection status
 * 
 */
LIB_EXPORT void MfSdkCommConfigReset(void);

/**
 * @brief WIFI stop config network
 * 
 */
LIB_EXPORT void MfSdkCommWifiStopConfig(void);

/**
 * @brief Restart the WiFi module only for ET389
 * 
 */
LIB_EXPORT void MfSdkCommWifiRestart(void);

/**
 * @brief Get current model type
 * @param socket_index socket index
 * @return Connect Type: 0:WIRELESS; 1:WIFI
*/
LIB_EXPORT int MFSdkCommSocketGetModelType(int socket_index);

/**
 * @brief Set ping address
 *
 * @param[in] addr address.example:"www.baidu.com"
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT s32 MfSdkCommSetPingAddr(u8* addr);
/**
 * @brief 
 * Only for SR600mini other device will return MFSDK_COMM_RET_FAILED
 * wifi mode and 4G mode switch
 * @param[in] MfSdkCommNetSelect_E netSelect
 * @return MFSDK_COMM_RET_PARM_ERROR netSelect MFSDK_COMM_NET_ONLY_WIRELESS && MFSDK_COMM_NET_ONLY_WIFI
 * @return MFSDK_COMM_RET_FAILED not support
 * @return MFSDK_COMM_RET_OK success
 */
LIB_EXPORT s32 MFSdkCommModeSwitch(MfSdkCommNetSelect_E netSelect);

/**
 * @brief 
 * Only for SR600mini other device will return MFSDK_COMM_RET_FAILED
 * 
 * @param[in] MfSdkCommNetSelect_E netSelect
 * @return 1 Network mode switching
 * @return 0 Network switchover was successful or default status
 * @return MFSDK_COMM_RET_FAILED not support
 */
LIB_EXPORT s32 MFSdkCommModeSwitchResult(MfSdkCommNetSelect_E netSelect);

/**
 * @brief only for MP70One
 * 
 * @param[in] MfSdkCommTlsVer_E ver
 * @return MFSDK_COMM_RET_FAILED doesnt support
 * @return MFSDK_COMM_RET_OK successful
 * @return MFSDK_COMM_RET_PARM_ERROR tls version value error
 */
LIB_EXPORT s32 MFSdkCommTlsSetVerion(MfSdkCommTlsVer_E ver);

/**
 * @brief	Set APN
 * 
 * @param[in] MfSdkCommSetApnProcCb pFuncCb
 * @return 
 */
LIB_EXPORT s32 MfSdkCommSetApnCbProc(MfSdkCommSetApnProcCb pFuncCb);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MFSDK_COMM_H__ */

