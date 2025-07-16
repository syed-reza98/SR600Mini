/**
* @file  tms_pub.h
* @brief  tms接口(包括tms初始化，升级下载文件等操作)
* @author lx
* @date   2021/06/24
*/
#pragma once

#include <pub/pub.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief    tms初始化，并启动后台TMS
* @details   tms初始化，并启动线程进行是否需要TMS升级检测
* @return    线程创建成功与否结果的返回
* - 0 初始化成功
* - 其他 失败
*/
	LIB_EXPORT int tms_init();

/**
* @brief    升级已下载好的文件
* @details   升级已下载好的文件
* @param[const char *]  file    用于升级的文件名
* @return    升级结果
* - 0 成功
* - 其他失败
*/
	LIB_EXPORT int tms_update(const char* file);
	LIB_EXPORT int tms_update_app2();

	/*************************************************************************************
	Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
	Author:lxz
	Functions:TMS upgrade
	Input : file：Upgrade file name
			flag：1 upgrade application and data, 0 upgrade data only

	Output : Nothing
	return: 0,     success
			Other, failure
	*************************************************************************************/

	LIB_EXPORT int tms_update_ex(const char* file, int flag);

/**
* @enum eTMSACTION
* @brief tms进行下载还是升级程序的动作标志
*/
	typedef enum eTMSACTION {
		TA_DOWNLOADING,	//准备下载升级程序
		TA_UPDATEING,	//准备升级下载好的程序
	}TMSACTION;

	typedef enum
	{
		TMS_NET_FAIL = -100,				//网络异常
		TMS_SOCKET_FAIL,			//服务器连接异常
		TMS_LOGIN_FAIL,				//登录失败
		TMS_LOGIN_FORMAT_ERROR,		//返回登录包错误
		TMS_DEVICE_ERROR,			//设备不合法
		TMS_MD5_ERROR,				//升级包md5校验失败
		TMS_SIG_ERROR,				//升级包校验失败
		TMS_LOW_BATTERY,			//设备低电量
		TMS_UPDATE_FAIL,			//下载失败
		TMS_CONNECT_SERVER_FAIL,//
		TMS_SEND_SERVER_FAIL,
		TMS_RECV_SERVER_FAIL,
		TMS_UPDATE_SUCCESS = 0,     //tms升级成功
		TMS_UPDATE_NO_TRIGERR,      //无TMS升级触发	
		TMS_CONNECT_SERVER,//链接服务器
		TMS_SEND_SERVER,//发送服务器消息
		TMS_RECV_SERVER,//接收服务器消息
		TMS_UPDATING,//TMS下载中
		TMS_FINISH = 999
	}enum_tms_state;



	//返回  0 取消对应动作  1 允许对应动作
	typedef int (*tms_action)(TMSACTION type);

	//升级结果
	typedef int (*_tms_result_proc)(enum_tms_state type);


/**
* @brief   添加tms事件处理回调
* @param[tms_action] proc   回调事件
* @return   
* - 0    添加成功
* - 其他 添加失败
*/
	LIB_EXPORT int tms_set_actionproc(tms_action proc);

	//endtime 秒处理如果超过时间后必须退出
	typedef int (*_tms_proc)(int endtime);

/**
* @brief   设置使用tms线程后台处理函数
* @param[_tms_proc]  proc    tms后台处理具体函数
* @return  NULL
*/
	LIB_EXPORT void	tms_setproc(_tms_proc proc);

/**
* @brief  函数弃用
*/
	LIB_EXPORT int tms_init2();
/**
* @brief   tms检查更新
* @param[ const char *]  file   文件
* @return  检查结果
* - 0  成功
* - -1 失败
*/
	LIB_EXPORT int tms_check_update(const char* file);
/**
* @brief    tms心跳
* @details   tms心跳事件，向服务器上送包，接收回包并解析判断是否需要升级操作
* @return    检测结果
* -   0  不需要更新
* -   1  需要升级，下载升级包
* -  -1  未能接收到服务器发的包，不需要下载
* -  -2  收到的包格式错误
* -  -3  非法设备
*/
	LIB_EXPORT int tms_heart();
/**
* @brief   触发升级检测  有后台的使用线程 无后台的使用tms_heart
* @return  NULL
*/
	LIB_EXPORT int tms_heart2();

/**
* @brief  TMS正在升级
* @return  1 正在升级我， 其它值 未升级
*/
	LIB_EXPORT int tms_isupdate();


	LIB_EXPORT void enable_tms_update(int flag);


	LIB_EXPORT void tdownload_proc();


#ifdef __cplusplus
}
#endif	