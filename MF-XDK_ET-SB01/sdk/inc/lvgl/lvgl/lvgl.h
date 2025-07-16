/**
 * @file lvgl.h
 * Include all LittleV GL related headers
 */

#ifndef LVGL_H
#define LVGL_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************
 * CURRENT VERSION OF LVGL
 ***************************/
#define LVGL_VERSION_MAJOR 7
#define LVGL_VERSION_MINOR 11
#define LVGL_VERSION_PATCH 0
#define LVGL_VERSION_INFO "dev"

/*********************
 *      INCLUDES
 *********************/



#include "lvgl/src/lv_misc/lv_log.h"
#include "lvgl/src/lv_misc/lv_task.h"
#include "lvgl/src/lv_misc/lv_math.h"
#include "lvgl/src/lv_misc/lv_async.h"

#include "lvgl/src/lv_hal/lv_hal.h"

#include "lvgl/src/lv_core/lv_obj.h"
#include "lvgl/src/lv_core/lv_group.h"
#include "lvgl/src/lv_core/lv_indev.h"

#include "lvgl/src/lv_core/lv_refr.h"
#include "lvgl/src/lv_core/lv_disp.h"

#include "lvgl/src/lv_themes/lv_theme.h"

#include "lvgl/src/lv_font/lv_font.h"
#include "lvgl/src/lv_font/lv_font_loader.h"
#include "lvgl/src/lv_font/lv_font_fmt_txt.h"
#include "lvgl/src/lv_misc/lv_printf.h"

#include "lvgl/src/lv_widgets/lv_btn.h"
#include "lvgl/src/lv_widgets/lv_imgbtn.h"
#include "lvgl/src/lv_widgets/lv_img.h"
#include "lvgl/src/lv_widgets/lv_label.h"
#include "lvgl/src/lv_widgets/lv_line.h"
#include "lvgl/src/lv_widgets/lv_page.h"
#include "lvgl/src/lv_widgets/lv_cont.h"
#include "lvgl/src/lv_widgets/lv_list.h"
#include "lvgl/src/lv_widgets/lv_chart.h"
#include "lvgl/src/lv_widgets/lv_table.h"
#include "lvgl/src/lv_widgets/lv_checkbox.h"
#include "lvgl/src/lv_widgets/lv_cpicker.h"
#include "lvgl/src/lv_widgets/lv_bar.h"
#include "lvgl/src/lv_widgets/lv_slider.h"
#include "lvgl/src/lv_widgets/lv_led.h"
#include "lvgl/src/lv_widgets/lv_btnmatrix.h"
#include "lvgl/src/lv_widgets/lv_keyboard.h"
#include "lvgl/src/lv_widgets/lv_dropdown.h"
#include "lvgl/src/lv_widgets/lv_roller.h"
#include "lvgl/src/lv_widgets/lv_textarea.h"
#include "lvgl/src/lv_widgets/lv_canvas.h"
#include "lvgl/src/lv_widgets/lv_win.h"
#include "lvgl/src/lv_widgets/lv_tabview.h"
#include "lvgl/src/lv_widgets/lv_tileview.h"
#include "lvgl/src/lv_widgets/lv_msgbox.h"
#include "lvgl/src/lv_widgets/lv_objmask.h"
#include "lvgl/src/lv_widgets/lv_gauge.h"
#include "lvgl/src/lv_widgets/lv_linemeter.h"
#include "lvgl/src/lv_widgets/lv_switch.h"
#include "lvgl/src/lv_widgets/lv_arc.h"
#include "lvgl/src/lv_widgets/lv_spinner.h"
#include "lvgl/src/lv_widgets/lv_calendar.h"
#include "lvgl/src/lv_widgets/lv_spinbox.h"

#include "lvgl/src/lv_draw/lv_img_cache.h"

#include "lvgl/src/lv_api_map.h"

#include "lvgl/src/lv_core/lv_style.h"
#include "lvgl/src/lv_core/lv_obj.h"
#include "lvgl/src/lv_key_mf.h"
#include "lvgl/src/lv_lib_qrcode/lv_qrcode.h"
#include "lvgl/src/lv_lib_qrcode/qrcodegen.h"


//#include "lvgl/src/lv_lib_freetype/lv_freetype.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/** Gives 1 if the x.y.z version is supported in the current version
 * Usage:
 *
 * - Require v6
 * #if LV_VERSION_CHECK(6,0,0)
 *   new_func_in_v6();
 * #endif
 *
 *
 * - Require at least v5.3
 * #if LV_VERSION_CHECK(5,3,0)
 *   new_feature_from_v5_3();
 * #endif
 *
 *
 * - Require v5.3.2 bugfixes
 * #if LV_VERSION_CHECK(5,3,2)
 *   bugfix_in_v5_3_2();
 * #endif
 *
 * */
#define LV_VERSION_CHECK(x,y,z) (x == LVGL_VERSION_MAJOR && (y < LVGL_VERSION_MINOR || (y == LVGL_VERSION_MINOR && z <= LVGL_VERSION_PATCH)))

/**
 * Wrapper functions for VERSION macros
 */

static inline int lv_version_major(void)
{
    return LVGL_VERSION_MAJOR;
}

static inline int lv_version_minor(void)
{
    return LVGL_VERSION_MINOR;
}

static inline int lv_version_patch(void)
{
    return LVGL_VERSION_PATCH;
}

static inline const char *lv_version_info(void)
{
    return LVGL_VERSION_INFO;
}


//��pinģʽ �ӿڽṹ�����
typedef struct __pin_mode_data
{
    int mode;
    int min;
    int max;
    int timeover;
    int ns_flag;    //�Ƿ�֧������
}Pin_mode_data;

int lv_key_pin_data(char* data);
int lv_key_pin_len();
int lv_key_pin_code();
void lv_key_pin_mode(int mode, int min, int max, int timeover);

#ifdef __cplusplus
}
#endif

#endif /*LVGL_H*/
