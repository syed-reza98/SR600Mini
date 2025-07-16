#pragma once

#include "libapi_system.h"

/**
 * @file tracedef.h
 * @author chenyue(Ronaldo)
 * @brief Capture log
 * @date 2023-05-23
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */


enum {
	SYS_LOG_LEVEL_TRACE,		///< TRACE
	SYS_LOG_LEVEL_DEBUG,		///< DEBUG
	SYS_LOG_LEVEL_INFO,			///< INFO
	SYS_LOG_LEVEL_WARN,			///< WARN
	SYS_LOG_LEVEL_ERROR,		///< ERROR
	SYS_LOG_LEVEL_FATAL,		///< FATAL
};

#define APP_TRACE(...) 	osl_log("app",SYS_LOG_LEVEL_TRACE, __VA_ARGS__);

