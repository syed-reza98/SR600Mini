/**
 * @file lv_gpu_nxp_pxp_osa.h
 *
 */

/**
 * MIT License
 *
 * Copyright (c) 2020 NXP
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next paragraph)
 * shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef LV_SRC_LV_GPU_LV_GPU_NXP_PXP_OSA_H_
#define LV_SRC_LV_GPU_LV_GPU_NXP_PXP_OSA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/src/lv_conf_internal.h"

#if LV_USE_GPU_NXP_PXP && LV_USE_GPU_NXP_PXP_AUTO_INIT
extern lv_nxp_pxp_cfg_t pxp_default_cfg;
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LV_SRC_LV_GPU_LV_GPU_NXP_PXP_OSA_H_ */
