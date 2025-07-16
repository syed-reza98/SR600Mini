#if !defined(_MF_MODULE_COMM_L_) || defined(_MF_RTOS_PLATFORM_)

#pragma once

#include "libapi_pub.h"


typedef struct __st_wifi_ap_list{
	int ecn;
	char ssid[64];//WiFi name
	char utf8ssid[64];
	int rssi;//Signal strength
	char mac[20];
	int channel;
	int freq;
}st_wifi_ap_list;



typedef struct _st_apninfor{

	char apn[48];
	char user[48];
	char pwd[48];
	char copsname[48];
}st_apninfo;


typedef struct _st_apninfor_mcc{

	char apn[48];
	char user[48];
	char pwd[48];
	char mcc[16];
	char mnc[16];
}st_apninfo_mcc;


//! 通讯模块类型
enum{
	MODEL_WIRELESS = 0,		///<无线
	MODEL_MODEM,			///<有线
	MODEL_WIFI,				///<wifi
	MODEL_WIN32_SOCK,	///<模拟器
};

enum{
	MODEL_MODE_ONLY_WIRELESS = 0,		// 仅 无线
	MODEL_MODE_ONLY_WIFI,				// 仅 wifi

};

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Connect Network
Input : title：Tips for connecting to the network
		  apn：gprs apn
		  timeover : Connection timeout
		
Output : Nothing
return: 1,     success
		Other, failure	
		*************************************************************************************/
LIB_EXPORT int comm_net_link(char * title, char * apn , int timeover);

/**
 * @brief
 * 
 * @param[in] int index
 * @return 
 */
LIB_EXPORT int comm_ssl_recv3(int index);
/**
 * @brief
 * 
 * @param[in] int index
 * @param[in] char * pdata
 * @param[in] int size
 * @return 
 */
LIB_EXPORT int comm_ssl_send2(int index, char * pdata, int size);

LIB_EXPORT int comm_net_link_state();

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


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Connect Network with user id and password
Input : title：Tips for connecting to the network
		  apn：gprs apn
		  timeover : Connection timeout
		  user:	gprs apn user id
		  pwd: gprs apn user password
		
Output : Nothing
return: 0,     success
		Other, failure	
*************************************************************************************/
LIB_EXPORT int comm_net_link_ex(char * title, char * apn,  int timeover, char *user,char *pwd);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:set gprs apn in main.c
Input :   apn：gprs apn
		  user:	gprs apn user id
		  pwd: gprs apn user password
		
Output : Nothing
return: 0,     success
		Other, failure	
*************************************************************************************/
LIB_EXPORT int comm_set_init_apn(char *apn,char *user,char *pwd);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Disconnect from the network
Input : Nothing
Output : Nothing
return: 0,     success
		Other, failure	
*************************************************************************************/
LIB_EXPORT int comm_net_unlink();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:create socket
Input : index(0/1)
Output : Nothing
return: 0,     success
		Other, failure	
*************************************************************************************/
LIB_EXPORT int comm_sock_create(int index);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:connect to the server
Input : index		sock index
		  ip		server ip
		  port		server port
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Receive data
Input : index		sock index
		  buff		Receive buffer
		  len		Receiving length
		  timeover	overtime time
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_sock_recv(int index, unsigned char * buff, int len, unsigned int timeover);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:send data
Input : index		sock index
		  buff		Send buffer
		  len		Send length
Output : Nothing			
return: >0,     length ot sent
		Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_sock_send(int index, unsigned char * buff , int size);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Disconnect the server
Input : index		sock index
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:ssl initialization
Input : index		sock index
	      cacert	Server certificate
		  clientcert Client certificate
		  clientkey	Client key
		  level		Verification level 0=Not verified 1=Verify server certificate
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_ssl_init(int index, char * cacert, char * clientcert, char * clientkey,int level);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:ssl connect to the server
Input : index		sock index
	      ip		server ip
		  port		server port

Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_ssl_connect(int index , char * ip , int port);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:ssl connect to the server
Input : index		sock index
	      ip		server ip
		  port		server port
		  func      callback
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/

LIB_EXPORT int comm_ssl_connect2(int index , char * ip , int port,void *func);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:ssl send data
Input : index		sock index
	      data		ssl data
		  size		Data size
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_ssl_send(int index, char * pdata, int size);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:ssl Receive data
Input : index		sock index
	      data		ssl data
		  size		Data size
Output : Nothing			
return: 0,     success
		Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_ssl_recv(int index, char * pdata, int size);
LIB_EXPORT int comm_ssl_recv3(int sock_index);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:ssl Disconnect
Input : index		sock index
Output : Nothing			
return: 0,     success
		Other, failure	
*************************************************************************************/
LIB_EXPORT int comm_ssl_close(int index);




/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Get the router list
Input : Nothing	
Output : ap_list	Router list data,	The ap_list space is allocated by the caller with an array size of 10	
return: 	Number of routers
*************************************************************************************/
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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Connecting router
Input : ap_list	Router data	
Input : pwd password	
Output : 
return: 0,     success
Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_wifi_link_ap(st_wifi_ap_list * ap_list , char * pwd);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:unlink router
Input : 
Output : 
return: 0,     success
Other, failure		
*************************************************************************************/
LIB_EXPORT int comm_wifi_unlink_ap();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:Get connection status
Input : 
Output : 
return: 1,     connection
		0 ,    disconnect
*************************************************************************************/
LIB_EXPORT int comm_wifi_get_link_state();

/**
 * @brief
 * 
 * @return 
 */
LIB_EXPORT int comm_gprs_get_signal();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Getting WIFI signal value
Input : 
Output : 
return: 0 Unregistered Internet  1-4 Signal Lattice Number
*************************************************************************************/
LIB_EXPORT int comm_wifi_get_signal();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get wifi signal
Input : 
Output : 
return: wifi signal
*************************************************************************************/
LIB_EXPORT char * comm_wifi_get_ssid();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get wifi ap mac address
Input : 
Output : 
return: ap mac address
*************************************************************************************/
LIB_EXPORT char * comm_wifi_get_ap_mac();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get wifi rssi
Input : 
Output : 
return: rssi
*************************************************************************************/
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

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get wifi channel
Input : 
Output : 
return: channel
*************************************************************************************/
LIB_EXPORT int comm_wifi_get_channel();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get wifi local mac address
Input : 
Output : 
return: local mac address
*************************************************************************************/
LIB_EXPORT char * comm_wifi_get_local_mac();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get wifi local ip
Input : 
Output : 
return: wifi signal
*************************************************************************************/
LIB_EXPORT char * comm_wifi_get_local_ip();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get Module imei
Input : 
Output : 
return: imei
*************************************************************************************/
LIB_EXPORT const char * comm_atc_imei();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get Module sim card status
Input : 
Output : 
return: sim card status
*************************************************************************************/
LIB_EXPORT int comm_atc_cpin();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get Module imsi
Input : 
Output : 
return: imsi
*************************************************************************************/
LIB_EXPORT const char * comm_atc_imsi();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get Module signal
Input : 
Output : 
return: signal
*************************************************************************************/
LIB_EXPORT int comm_atc_signal();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get net registered cell
Input : 
Output : 
return: cell
*************************************************************************************/
LIB_EXPORT int comm_atc_cell();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get net registered lac
Input : 
Output : 
return: lac
*************************************************************************************/
LIB_EXPORT int comm_atc_lac();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get net registered lac
Input :lac:buffer
	   size:buffer size
Output :num:The number that get
return: 0 success
		-1 fail
eg:
	int lac[14] = { 0 };
	int num = 0;
	ret = atc_cell_ex(lac, sizeof(lac), &num);
*************************************************************************************/
LIB_EXPORT int comm_atc_lac_ex(int* lac, int size, int* num);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get net registered cell
Input :cid:buffer
	   size:buffer size
Output :num:The number that get
return: 0 success
		-1 fail
*************************************************************************************/
LIB_EXPORT int comm_atc_cell_ex(int* cid, int size, int* num);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:get Module iccid
Input : 
Output : 
return: iccid
*************************************************************************************/
LIB_EXPORT const char * comm_atc_iccid();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx2
Functions:HTTP download
Input : url address
		fullpathfilename The full name of the downloaded file
		iscontinue Continue or not   1 sequel 0 download again
		nRetry retry count
Output : 
return: 0 success < 0 failure
*************************************************************************************/


LIB_EXPORT int comm_http_download_try(const char *url,const char *fullpathfilename,int iscontinue, int nRetry );



/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx2
Functions:Set network mode
Input : mode network mode
		fullpathfilename The full name of the downloaded file
		iscontinue Continue or not   1 sequel 0 download again
		nRetry retry count
Output : 
return: null
*************************************************************************************/
LIB_EXPORT void comm_set_net_mode(int mode);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Set APN through operator
Input : apn_list   APN operator corresponding list		
		ncount List length
Output : 
return: null
*************************************************************************************/

LIB_EXPORT int  comm_set_apn_list(st_apninfo apn_list[],int ncount);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:leo
Functions:get Module ip;should call the atc_dns_init(); before get
Input :
Output : ip
return:
*************************************************************************************/
LIB_EXPORT int comm_atc_get_local_ip(char* ip);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:set IPV version, should be called in main.c before network initial
Input : value 1:only IPV4; 2:only IPV6; 3:IPV4&IPV6
Output : ip
return:
*************************************************************************************/
LIB_EXPORT void comm_set_ap_mode(int mode);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ronaldo
Functions:Set the socket to connect to ipv6 or ipv4
Input : mode mode=0(priority ipv4);mode=1(priority ipv6)
return: 0,success;Other,fail
*************************************************************************************/
LIB_EXPORT int comm_sock_connect_priority(int mode);

LIB_EXPORT int comm_set_apn_list_mcc(st_apninfo_mcc apn_list[], int ncount);

LIB_EXPORT void comm_sock_fifo_resize(int index, int size);


/**
 * @brief
 * 
 * @param[in] int mbedtls
 * @return 
 */
LIB_EXPORT int comm_ssl_mbedtls(int mbedtls);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Ware
Functions: set wifi name, (WiFi version V5.1.2 and above support modify the wifi name)
Input : int mode 
		mode = 0: KM_AP, default: KM_(SN)
Output : Nothing
return: void
*************************************************************************************/
LIB_EXPORT void comm_set_WifiName(int mode);

/**
 * @brief
 * 
 * @param[in] int use_session
 * @param[in] int loglevel
 * @return 
 */
LIB_EXPORT int comm_mbedtls_init( int use_session,int loglevel );


#endif

