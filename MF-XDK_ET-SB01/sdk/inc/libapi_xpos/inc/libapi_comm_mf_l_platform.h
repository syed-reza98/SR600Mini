#if defined(_MF_MODULE_COMM_L_)
#pragma once

/**
 * @file libapi_comm.h
 * @author caijh(Eric)
 * @brief Communication related functions
 * @date 2023-05-23
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#include "libapi_pub.h"

#ifdef __cplusplus
extern "C"{
#endif

#define WIFI_DISCONNECT    0
#define CONNECTED     1
#define PWN_ERROR     -1
#define AP_NOTFOUND   -2
#define CONNECTING    -999
#define DICONNECTING  -998
#define CONNECT_BEGIN -997

#define DEFAULT_SAVE_PWD "0000000000000000000"

#define MAX_AP_COUNT 30//must same as AP_NETWORK_MAX

///<data bit 
#define COMM_UART_DATABIT5		5
#define COMM_UART_DATABIT6		6
#define COMM_UART_DATABIT7		7
#define COMM_UART_DATABIT8		8
///<stop bit 
#define COMM_UART_STOPBIT1		0
#define COMM_UART_STOPBIT1_5	1
#define COMM_UART_STOPBIT2		2
///<parity bit 
#define COMM_UART_NOPARITY		0
#define COMM_UART_ODDPARITY		1
#define COMM_UART_EVENPARITY	2

typedef struct __st_wifi_ap_list{
	int id;				///< id
	char index[12];		///< index
	char type[12];		///< type
	int ecn;			///< Encryption method 0: OPEN 1: WEP 2: WPA_PSK 3: WPA2_PSK 4: WPA_WPA2_PSK
	char ssid[128];		///< WiFi name
	int rssi;			///< rssi, Receiver Signal Strength Indication
	char mac[20];		///< mac address
	int channel;		///< channel
	int freq;			///< frequency
	char mem[32];		///< dbus 7168 enough for 30 max count
}st_wifi_ap_list;

typedef struct _st_apninfor{

	char apn[48];
	char user[48];
	char pwd[48];
	char copsname[48];
}st_apninfo;

typedef struct _st_apninfo_mcc {

	char apn[48];
	char user[48];
	char pwd[48];
	char mcc[16];
	char mnc[16];
}st_apninfo_mcc;

typedef enum {
	UART_APP_COM=0,
}e_uart_comm;


/**
 * @brief Connect Network
 *
 * @param[in] pfunc Callback
 * @param[in] apn GPRS apn
 * @param[in] timeover Connection timeout
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_net_link(void * pfunc, char * apn , int timeover);
LIB_EXPORT int comm_net_link_state();
/**
 * @brief Connect Network
 *
 * @param[in] pfunc Callback
 * @param[in] apn GPRS apn
 * @param[in] timeover Connection timeout
 * @param[in] user GPRS apn user id
 * @param[in] pwd GPRS apn user password
 * @param[in] auth Authentication parameter
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_net_link_ex(void * pfunc, char * apn, int timeover, char *user, char *pwd, int auth);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:set gprs apn in main.c
Input :   apn:gprs apn
		  user:	gprs apn user id
		  pwd: gprs apn user password
		
Output : Nothing
return: 0,     success
		Other, failure	
*************************************************************************************/
LIB_EXPORT int comm_set_init_apn(char *apn,char *user,char *pwd);
/**
 * @brief Disconnect from the network
 *
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_net_unlink();

/**
 * @brief Create socket
 *
 * @param[in] index Sock index (0-4)
 * @return  >= 0, Success
 * @return  < 0, Failure
 */
LIB_EXPORT int comm_sock_create(int index);

/**
 * @brief Connect to the server
 *
 * @param[in] index Sock index (0-4)
 * @param[in] ip IP address
 * @param[in] port Port number
 * @return  >= 0, Success
 * @return  < 0, Failure
 */
LIB_EXPORT int comm_sock_connect(int index, char * ip, int port);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:ware
Functions:connect to the server 
Input : index		sock index
		  ip		server ip
		  port		server port
		  timeout		timeout
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_sock_connect_timeout(int index, char * ip, int port, int timeout);
/**
 * @brief Connect to the server
 *
 * @param[in] index Sock index (0-4)
 * @param[in] ip IP address
 * @param[in] port Port number
 * @param[in] func callback function
 * @return  >= 0, Success
 * @return  < 0, Failure
 */
LIB_EXPORT int comm_sock_connect2(int index , char * ip , int port,void *func);

/**
 * @brief Receive data
 *
 * @param[in] index Sock index (0-4)
 * @param[out] buff Receive buffer
 * @param[out] len Receiving length
 * @param[in] timeover Receive timeout
 * @return  = -1, Network disconnection
 * @return  = 0, Timeout
 * @return  > 0, Receive length
 */
LIB_EXPORT int comm_sock_recv(int index, unsigned char * buff, int len, unsigned int timeover);

/**
 * @brief Send data
 *
 * @param[in] index Sock index (0-4)
 * @param[in] buff Send buffer
 * @param[in] size Send length
 * @return   < 0, Failure
 * @return other, Success
 */
LIB_EXPORT int comm_sock_send(int index, unsigned char * buff , int size);

/**
 * @brief Disconnect the server
 *
 * @param[in] index Sock index (0-4)
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_sock_close(int index);

/*****************************************************************************
* Procedure: comm_ssl_authmode
* Function:	
** Parameters:    	int index sock index
*					int authmode  
*					0-peer certificate is not checked;
*					1-peer certificate is checked, however the handshake continues even if verification failed;
*					2-peer *must* present a valid certificate,handshake is aborted if verification failed;
*					
* Result:	
* Descriptions:	
** Created By:		CHAR20231115
*****************************************************************************
* LOG   DATE            AUTHOR       ACTION
*****************************************************************************/
LIB_EXPORT int comm_ssl_authmode(int index , int authmode);
/**
 * @brief ssl initialization
 *
 * @param[in] index Sock index (0-4)
 * @param[in] cacert CA certificate
 * @param[in] clientcert Client certificate
 * @param[in] clientkey Client Key
 * @param[in] level Verification level 0=Not verified 1=Verify server certificate
 * @return  = 0, Success
 * @return  < 0, Failure
 */
LIB_EXPORT int comm_ssl_init(int index, char * cacert, char * clientcert, char * clientkey,int level);

/**
 * @brief ssl connect to the server
 *
 * @param[in] index Sock index (0-4)
 * @param[in] ip Server ip
 * @param[in] port Server port
 * @return  = 0, Success
 * @return  < 0, Failure
 * @return  = 2. Cancel
 */
LIB_EXPORT int comm_ssl_connect(int index , char * ip , int port);

/**
 * @brief ssl connect to the server
 *
 * @param[in] index Sock index (0-4)
 * @param[in] ip Server ip
 * @param[in] port Server port
 * @param[in] func Callback
 * @return  = 0, Success
 * @return  < 0, Failure
 * @return  = 2. Cancel
 */
LIB_EXPORT int comm_ssl_connect2(int index , char * ip , int port,void *func);

/**
 * @brief ssl send data
 *
 * @param[in] index Sock index (0-4)
 * @param[in] pdata ssl data
 * @param[in] size Data size
 * @return  = 0, Success
 * @return  < 0, Failure
 * @return  > 0. Not fully sent, Return send length
 */
LIB_EXPORT int comm_ssl_send(int index, char * pdata, int size);

/**
 * @brief ssl Receive data
 *
 * @param[in] index Sock index (0-4)
 * @param[in] pdata ssl data
 * @param[in] size Data size
 * @return  >= 0, Received data length
 * @return  < 0, Received failure
 */
LIB_EXPORT int comm_ssl_recv(int index, char * pdata, int size);
LIB_EXPORT int comm_ssl_recv3(int sock_index);
/**
 * @brief ssl Disconnect
 *
 * @param[in] index Sock index (0-4)
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_ssl_close(int index);

/**
 * @brief Get the router list
 *
 * @param[out] ap_list Router list data, The ap_list space is allocated by the caller with an array size of 10
 * @return  Number of routers
 */
LIB_EXPORT int comm_wifi_list_ap(st_wifi_ap_list * ap_list);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:quit the router list
Input : Nothing
Output :
return: Nothing
*************************************************************************************/
LIB_EXPORT void comm_list_ap_quit();
/**
 * @brief Get the router save ap list
 *
 * @param[out] ap_list Router list data, The ap_list space is allocated by the caller with an array size of 10
 * @return  Number of routers
 */
LIB_EXPORT int comm_wifi_list_network(st_wifi_ap_list* ap_list);
/**
 * @brief Connecting router
 *
 * @param[in] ssid Router id
 * @param[in] pwd Router password
 * @return   0, Success
 * @return  -1, Password too long
 * @return  -2, ssid is empty
 */
LIB_EXPORT int comm_wifi_link_ap(char * ssid , char * pwd);
//Note SoundBox api not use LIB_EXPORT int comm_wifi_link_ap(st_wifi_ap_list * ap_list , char * pwd);
/**
 * @brief Unlink router
 *
 * @param[in] ssid Router id
 * @return 0, Disconnect Success
 * @return Other, Disconnect Failure
 */
LIB_EXPORT int comm_wifi_unlink_ap(char* ssid);

/**
 * @brief Remove connected ap
 *
 * @param[in] ssid Router id
 * @return 0, Success
 * @return Other, Failure
 */
LIB_EXPORT int comm_wifi_remove_ap(char* ssid);

/**
 * @brief Clear ap count
 *
 * @return  Nothing
 */
LIB_EXPORT void comm_wifi_clear_list_ap_num();

/**
 * @brief Start scan wifi
 *
 * @param[in] flag 0:stop scan 1:auto scan one time 2:scan immediately one time
 * @return  Scanning results
 */
LIB_EXPORT int comm_wifi_set_scan(int flag);

/**
 * @brief Get connection status
 *
 * @return  1, Connection
 * @return  0, Disconnect
 * @return  -1, Pwd error 
 * @return  -2, No exist 
 * @return  -999, Connect in process
 * @return  -998, Disconnect in process
 * @return  -997, Connect start 
 */
LIB_EXPORT int comm_wifi_get_link_state();

/**
 * @brief Get wifi signal
 *
 * @return  0, Disconnect
 * @return  1, One grid signal
 * @return  2, Two grid signal
 * @return  3, Three grid signal
 * @return  4, Four grid signal
 */
LIB_EXPORT int comm_wifi_get_signal();

/**
 * @brief Get wifi ssid
 *
 * @return  Router id
 */
LIB_EXPORT char * comm_wifi_get_ssid();

/**
 * @brief Get wifi ap mac address
 *
 * @return  ap mac address
 */
LIB_EXPORT char * comm_wifi_get_ap_mac();

/**
 * @brief Get wifi rssi
 *
 * @return  wifi rssi
 */
LIB_EXPORT int comm_wifi_get_rssi();

/**
 * @brief Get wifi channel
 *
 * @return  wifi channel
 */
LIB_EXPORT int comm_wifi_get_channel();

/**
 * @brief Get wifi local mac address
 *
 * @return  local mac address
 */
LIB_EXPORT char * comm_wifi_get_local_mac();

/**
 * @brief Get wifi local ip
 *
 * @return  ip address
 */
LIB_EXPORT char * comm_wifi_get_local_ip();

/**
 * @brief Get Module imei
 *
 * @param[in] index GPRS/4G index 0-1
 * @return  imei value
 */
LIB_EXPORT const char * comm_atc_imei(int index);

/**
 * @brief Get Module sim card status
 *
 * @param[in] index GPRS/4G index 0-1
 * @return  0, Failure
 * @return  1, Locked
 * @return  2, Normal
 * @return  3, Puk
 */
LIB_EXPORT int comm_atc_cpin(int index);

/**
 * @brief Get Module imsi
 *
 * @param[in] index GPRS/4G index 0-1
 * @return  imsi value
 */
LIB_EXPORT const char * comm_atc_imsi(int index);

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
LIB_EXPORT int comm_atc_signal(int index);

/**
 * @brief Get net registered cell
 *
 * @param[in] index GPRS/4G index 0-1
 * @return  cell value
 */
LIB_EXPORT int comm_atc_cell(int index);

/**
 * @brief Get net registered lac
 *
 * @param[in] index GPRS/4G index 0-1
 * @return  lac value 
 */
LIB_EXPORT int comm_atc_lac(int index);

/**
 * @brief Get Module iccid
 *
 * @param[in] index GPRS/4G index 0-1
 * @return  iccid value
 */
LIB_EXPORT const char * comm_atc_iccid(int index);

/**
 * @brief Get net model GPRS or Wifi 
 *
 * @return  0, WIRELESS
 * @return  1, WIFI
 */
LIB_EXPORT int comm_net_model();

/**
 * @brief Get net link state for both GPRS and Wifi 
 *
 * @return  1, linked
 * @return  0, disconnect
 */
LIB_EXPORT int comm_link_state();

/**
 * @brief Select wifi or gprs
 *
 * @param[in] nselect 0 - WIRELESS, 1 - WIFI
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_set_netselect(int nselect);

/**
 * @brief Get mode of wifi or gprs or the Priority
 *
 * @return  0, WIRELESS
 * @return  1, WIFI
 */
LIB_EXPORT int comm_get_netselect(void);

/**
 * @brief Set the WiFi power
 *
 * @param[in] flag 0 - Turn off wifi power; 1 - Turn on wifi power
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_set_wifi_power(int flag);

/**
 * @brief Get the WiFi power
 *
 * @return  0, Turn off
 * @return  1, Turn on
 */
LIB_EXPORT int comm_get_wifi_power(void);

/**
 * @brief Set the atc power
 *
 * @param[in] flag 0 - Turn off atc, 1 - Turn on atc
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_set_atc_power(int flag);

/**
 * @brief Get the atc power
 *
 * @return  0, Turn off
 * @return  1, Turn on
 */
LIB_EXPORT int comm_get_atc_power(void);

/**
 * @brief Get the atc generation
 *
 * @param[in] index sim index 0-1 (Single sim card select 0)
 * @return  0, No signal
 * @return  2, 2G
 * @return  3, 3G
 * @return  4, 4G
 */
LIB_EXPORT int comm_get_atc_generation(int index);

/**
 * @brief Set the default apn list by mcc and mnc
 *
 * @param[in] apn list
 * @param[in] apn count
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_set_apn_list_mcc(st_apninfo_mcc* apnlist_mcc, int count);

/**
 * @brief open serial port
 * 
 * @param nCom enum e_uart_comm
 * @param nBaud Baud rate
 * @param nData Data bit length
 * @param nStop Stop bit length
 * @param nParity Parity bit
 * @return  0, Success
 * @return  Other, Failure
 * @code 
 * comm_uart_open(UART_APP_COM,115200,COMM_UART_DATABIT8,COMM_UART_STOPBIT1,COMM_UART_NOPARITY);
 * @endcode
 * 
 */
LIB_EXPORT unsigned int comm_uart_open(e_uart_comm nCom, unsigned int nBaud, unsigned int nData, unsigned int nStop, unsigned int nParity);

/**
 * @brief close serial port
 * 
 * @param nCom enum e_uart_comm
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT unsigned int comm_uart_close(e_uart_comm nCom);

/**
 * @brief Send serial port data
 * 
 * @param[in] nCom enum e_uart_comm
 * @param[in] pBuffer Sent buff
 * @param[in] nLength Sent buff length
 * @return Length of send
 */
LIB_EXPORT unsigned int comm_uart_send(e_uart_comm nCom, unsigned char* pBuffer, unsigned int nLength);

/**
 * @brief Receiving serial port data
 * 
 * @param[in] nCom enum e_uart_comm
 * @param[out] pBuffer Receive buff
 * @param[in] nLength Receive buff length
 * @param[in] timeout timeout(ms)
 * @return Length of reception 
 */
LIB_EXPORT unsigned int comm_uart_recv(e_uart_comm nCom, unsigned char* pBuffer, unsigned int nLength, int timeout);

/**
 * @brief Clear serial port buffer data
 * 
 * @param nCom enum e_uart_comm
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT unsigned int comm_uart_clear(e_uart_comm nCom);

/**
 * @brief Gets the length of the serial port receive buffer
 * 
 * @param nCom enum e_uart_comm
 * @return Length of recv buf
 */
LIB_EXPORT unsigned int comm_uart_get_rx_buf_len(e_uart_comm nCom);

/**
 * @brief Read the id of the working sim card(Only devices with two sim cards are supported)
 *
 * @return 0 sim1
 * @return 1 sim2
 * @return Other,fail
 */
LIB_EXPORT int comm_get_operate_id();

/**
 * @brief Read the id of the working sim card(Only devices with two sim cards are supported)
 *
 * @param[in] value 0:sim 1; 1: sim 2
 * @return >=0 success
 * @return Other,fail
 */
LIB_EXPORT int comm_set_operate_id(int value);
/**
 * @brief Get net connection status
 *
 * @return  1, connection
 * @return  0, disconnect
 */
LIB_EXPORT int comm_net_get_link_state(void);
/**
 * @brief get Module ip;should call the atc_dns_init(); before get
 *
 * @param[out] ip local ip
 * @return  0, Success
 * @return  Other, Failure
 */
LIB_EXPORT int comm_atc_get_local_ip(char* ip);
/**
 * @brief set GPRS/WIFI icon not visible when set with only WIFI/GPRS
 *
 * @param[in] nhide 1, not visible; 0 visible
 * @details only for H9G, H9L
 */
LIB_EXPORT void comm_set_iconhide(int nhide);
/**
 * @brief wifi get exist
 *
 * return 1: wifi exist . others : wifi doesn't exist
 *
 */
LIB_EXPORT int comm_wifi_get_exist();
/**
 * @brief Get wifi subnet mask
 * @return  subnet mask string
 *
 */
LIB_EXPORT char* comm_wifi_get_subnet_mask(void);

/**
 * @brief Get wifi gateway
 *
 * @param[in] gateway buff
 * @param[in] length buff length
 * @return  gateway value length
 * @return  < 0, Failure
 */
LIB_EXPORT int comm_wifi_get_default_gateway(char* gateway, int length);

#ifdef __cplusplus
}
#endif	
#endif

