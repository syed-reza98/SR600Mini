#pragma once

/**
 * @file libapi_pub.h
 * @author chenyue(Ronaldo)
 * @brief public function
 * @date 2023-05-17
 * @copyright Fujian MoreFun Electronic Technology Co., Ltd.
 */

#ifdef WIN32
#ifdef DLL_EXPORTS
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT __declspec(dllimport)
#endif
#else
#define LIB_EXPORT

#endif

#include "def.h"

