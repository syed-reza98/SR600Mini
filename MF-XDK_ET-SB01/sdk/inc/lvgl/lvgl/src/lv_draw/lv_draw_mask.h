/**
 * @file lv_mask.h
 *
 */

#ifndef LV_MASK_H
#define LV_MASK_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include "lvgl/src/lv_misc/lv_area.h"
#include "lvgl/src/lv_misc/lv_color.h"

/*********************
 *      DEFINES
 *********************/
#define LV_MASK_ID_INV  (-1)
#define _LV_MASK_MAX_NUM     16

/**********************
 *      TYPEDEFS
 **********************/

enum {
    LV_DRAW_MASK_RES_TRANSP,
    LV_DRAW_MASK_RES_FULL_COVER,
    LV_DRAW_MASK_RES_CHANGED,
    LV_DRAW_MASK_RES_UNKNOWN
};

typedef uint8_t lv_draw_mask_res_t;

enum {
    LV_DRAW_MASK_TYPE_LINE,
    LV_DRAW_MASK_TYPE_ANGLE,
    LV_DRAW_MASK_TYPE_RADIUS,
    LV_DRAW_MASK_TYPE_FADE,
    LV_DRAW_MASK_TYPE_MAP,
};

typedef uint8_t lv_draw_mask_type_t;

enum {
    LV_DRAW_MASK_LINE_SIDE_LEFT = 0,
    LV_DRAW_MASK_LINE_SIDE_RIGHT,
    LV_DRAW_MASK_LINE_SIDE_TOP,
    LV_DRAW_MASK_LINE_SIDE_BOTTOM,
};

/**
 * A common callback type for every mask type.
 * Used internally by the library.
 */
typedef lv_draw_mask_res_t (*lv_draw_mask_xcb_t)(lv_opa_t * mask_buf, lv_coord_t abs_x, lv_coord_t abs_y,
                                                 lv_coord_t len,
                                                 void * p);

typedef uint8_t lv_draw_mask_line_side_t;

typedef struct {
    lv_draw_mask_xcb_t cb;
    lv_draw_mask_type_t type;
} lv_draw_mask_common_dsc_t;

typedef struct {
    /*The first element must be the common descriptor*/
    lv_draw_mask_common_dsc_t dsc;

    struct {
        /*First point */
        lv_point_t p1;

        /*Second point*/
        lv_point_t p2;

        /*Which side to keep?*/
        lv_draw_mask_line_side_t side : 2;
    } cfg;

    /*A point of the line*/
    lv_point_t origo;

    /* X / (1024*Y) steepness (X is 0..1023 range). What is the change of X in 1024 Y?*/
    int32_t xy_steep;

    /* Y / (1024*X) steepness (Y is 0..1023 range). What is the change of Y in 1024 X?*/
    int32_t yx_steep;

    /*Helper which stores yx_steep for flat lines and xy_steep for steep (non flat) lines */
    int32_t steep;

    /*Steepness in 1 px in 0..255 range. Used only by flat lines. */
    int32_t spx;

    /*1: It's a flat line? (Near to horizontal)*/
    uint8_t flat : 1;

    /* Invert the mask. The default is: Keep the left part.
     * It is used to select left/right/top/bottom*/
    uint8_t inv: 1;
} lv_draw_mask_line_param_t;

typedef struct {
    /*The first element must be the common descriptor*/
    lv_draw_mask_common_dsc_t dsc;

    struct {
        lv_point_t vertex_p;
        lv_coord_t start_angle;
        lv_coord_t end_angle;
    } cfg;

    lv_draw_mask_line_param_t start_line;
    lv_draw_mask_line_param_t end_line;
    uint16_t delta_deg;
} lv_draw_mask_angle_param_t;

typedef struct {
    /*The first element must be the common descriptor*/
    lv_draw_mask_common_dsc_t dsc;

    struct {
        lv_area_t rect;
        lv_coord_t radius;
        /* Invert the mask. 0: Keep the pixels inside.*/
        uint8_t outer: 1;
    } cfg;
    int32_t y_prev;
    lv_sqrt_res_t y_prev_x;

} lv_draw_mask_radius_param_t;

typedef struct {
    /*The first element must be the common descriptor*/
    lv_draw_mask_common_dsc_t dsc;

    struct {
        lv_area_t coords;
        lv_coord_t y_top;
        lv_coord_t y_bottom;
        lv_opa_t opa_top;
        lv_opa_t opa_bottom;
    } cfg;

} lv_draw_mask_fade_param_t;

typedef struct _lv_draw_mask_map_param_t {
    /*The first element must be the common descriptor*/
    lv_draw_mask_common_dsc_t dsc;

    struct {
        lv_area_t coords;
        const lv_opa_t * map;
    } cfg;
} lv_draw_mask_map_param_t;

typedef struct {
    void * param;
    void * custom_id;
} _lv_draw_mask_saved_t;

typedef _lv_draw_mask_saved_t _lv_draw_mask_saved_arr_t[_LV_MASK_MAX_NUM];

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Add a draw mask. Everything drawn after it (until removing the mask) will be affected by the mask.
 * @param param an initialized mask parameter. Only the pointer is saved.
 * @param custom_id a custom pointer to identify the mask. Used in `lv_draw_mask_remove_custom`.
 * @return the an integer, the ID of the mask. Can be used in `lv_draw_mask_remove_id`.
 */
int16_t lv_draw_mask_add(void * param, void * custom_id);

//! @cond Doxygen_Suppress

/**
 * Apply the added buffers on a line. Used internally by the library's drawing routines.
 * @param mask_buf store the result mask here. Has to be `len` byte long. Should be initialized with `0xFF`.
 * @param abs_x absolute X coordinate where the line to calculate start
 * @param abs_y absolute Y coordinate where the line to calculate start
 * @param len length of the line to calculate (in pixel count)
 * @return One of these values:
 * - `LV_DRAW_MASK_RES_FULL_TRANSP`: the whole line is transparent. `mask_buf` is not set to zero
 * - `LV_DRAW_MASK_RES_FULL_COVER`: the whole line is fully visible. `mask_buf` is unchanged
 * - `LV_DRAW_MASK_RES_CHANGED`: `mask_buf` has changed, it shows the desired opacity of each pixel in the given line
 */
LV_ATTRIBUTE_FAST_MEM lv_draw_mask_res_t lv_draw_mask_apply(lv_opa_t * mask_buf, lv_coord_t abs_x, lv_coord_t abs_y,
                                                            lv_coord_t len);

//! @endcond

/**
 * Remove a mask with a given ID
 * @param id the ID of the mask.  Returned by `lv_draw_mask_add`
 * @return the parameter of the removed mask.
 * If more masks have `custom_id` ID then the last mask's parameter will be returned
 */
void * lv_draw_mask_remove_id(int16_t id);

/**
 * Remove all mask with a given custom ID
 * @param custom_id a pointer used in `lv_draw_mask_add`
 * @return return the parameter of the removed mask.
 * If more masks have `custom_id` ID then the last mask's parameter will be returned
 */
void * lv_draw_mask_remove_custom(void * custom_id);

//! @cond Doxygen_Suppress

/**
 * Count the currently added masks
 * @return number of active masks
 */
LV_ATTRIBUTE_FAST_MEM uint8_t lv_draw_mask_get_cnt(void);

//! @endcond

/**
 *Initialize a line mask from two points.
 * @param param pointer to a `lv_draw_mask_param_t` to initialize
 * @param p1x X coordinate of the first point of the line
 * @param p1y Y coordinate of the first point of the line
 * @param p2x X coordinate of the second point of the line
 * @param p2y y coordinate of the second point of the line
 * @param side and element of `lv_draw_mask_line_side_t` to describe which side to keep.
 * With `LV_DRAW_MASK_LINE_SIDE_LEFT/RIGHT` and horizontal line all pixels are kept
 * With `LV_DRAW_MASK_LINE_SIDE_TOP/BOTTOM` and vertical line all pixels are kept
 */
void lv_draw_mask_line_points_init(lv_draw_mask_line_param_t * param, lv_coord_t p1x, lv_coord_t p1y, lv_coord_t p2x,
                                   lv_coord_t p2y, lv_draw_mask_line_side_t side);

/**
 *Initialize a line mask from a point and an angle.
 * @param param pointer to a `lv_draw_mask_param_t` to initialize
 * @param px X coordinate of a point of the line
 * @param py X coordinate of a point of the line
 * @param angle right 0 deg, bottom: 90
 * @param side and element of `lv_draw_mask_line_side_t` to describe which side to keep.
 * With `LV_DRAW_MASK_LINE_SIDE_LEFT/RIGHT` and horizontal line all pixels are kept
 * With `LV_DRAW_MASK_LINE_SIDE_TOP/BOTTOM` and vertical line all pixels are kept
 */
void lv_draw_mask_line_angle_init(lv_draw_mask_line_param_t * param, lv_coord_t p1x, lv_coord_t py, int16_t angle,
                                  lv_draw_mask_line_side_t side);

/**
 * Initialize an angle mask.
 * @param param pointer to a `lv_draw_mask_param_t` to initialize
 * @param vertex_x X coordinate of the angle vertex (absolute coordinates)
 * @param vertex_y Y coordinate of the angle vertex (absolute coordinates)
 * @param start_angle start angle in degrees. 0 deg on the right, 90 deg, on the bottom
 * @param end_angle end angle
 */
void lv_draw_mask_angle_init(lv_draw_mask_angle_param_t * param, lv_coord_t vertex_x, lv_coord_t vertex_y,
                             lv_coord_t start_angle, lv_coord_t end_angle);

/**
 * Initialize a fade mask.
 * @param param param pointer to a `lv_draw_mask_param_t` to initialize
 * @param rect coordinates of the rectangle to affect (absolute coordinates)
 * @param radius radius of the rectangle
 * @param inv: true: keep the pixels inside the rectangle; keep the pixels outside of the rectangle
 */
void lv_draw_mask_radius_init(lv_draw_mask_radius_param_t * param, const lv_area_t * rect, lv_coord_t radius, bool inv);

/**
 * Initialize a fade mask.
 * @param param pointer to a `lv_draw_mask_param_t` to initialize
 * @param coords coordinates of the area to affect (absolute coordinates)
 * @param opa_top opacity on the top
 * @param y_top at which coordinate start to change to opacity to `opa_bottom`
 * @param opa_bottom opacity at the bottom
 * @param y_bottom at which coordinate reach `opa_bottom`.
 */
void lv_draw_mask_fade_init(lv_draw_mask_fade_param_t * param, const lv_area_t * coords, lv_opa_t opa_top,
                            lv_coord_t y_top,
                            lv_opa_t opa_bottom, lv_coord_t y_bottom);

/**
 * Initialize a map mask.
 * @param param pointer to a `lv_draw_mask_param_t` to initialize
 * @param coords coordinates of the map (absolute coordinates)
 * @param map array of bytes with the mask values
 */
void lv_draw_mask_map_init(lv_draw_mask_map_param_t * param, const lv_area_t * coords, const lv_opa_t * map);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_MASK_H*/
