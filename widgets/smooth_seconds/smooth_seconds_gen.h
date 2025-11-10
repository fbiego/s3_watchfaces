/**
 * @file smooth_seconds_gen.h
 *
 */

#ifndef SMOOTH_SECONDS_GEN_H
#define SMOOTH_SECONDS_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#include "s3_watchfaces_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a smooth_seconds object
 * @param parent pointer to an object, it will be the parent of the new smooth_seconds
 * @return pointer to the created smooth_seconds
 */
lv_obj_t * smooth_seconds_create(lv_obj_t * parent);
/**
 * The image src
 * @param obj   pointer to a smooth_seconds
 * @param src  The image src
 */
void smooth_seconds_set_src(lv_obj_t * smooth_seconds, const void * src);

/**
 * The x pivot point of the image
 * @param obj   pointer to a smooth_seconds
 * @param pivot_x  The x pivot point of the image
 */
void smooth_seconds_set_pivot_x(lv_obj_t * smooth_seconds, int32_t pivot_x);

/**
 * The y pivot point of the image
 * @param obj   pointer to a smooth_seconds
 * @param pivot_y  The y pivot point of the image
 */
void smooth_seconds_set_pivot_y(lv_obj_t * smooth_seconds, int32_t pivot_y);

/**
 * The offset of the rotation
 * @param obj   pointer to a smooth_seconds
 * @param offset  The offset of the rotation
 */
void smooth_seconds_set_offset(lv_obj_t * smooth_seconds, int32_t offset);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SMOOTH_SECONDS_GEN_H*/