/**
 * @file smooth_seconds_private_gen.h
 *
 */

#ifndef SMOOTH_SECONDS_PRIVATE_H
#define SMOOTH_SECONDS_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "smooth_seconds.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_image_t obj;  /* Base widget to extend */
    const void * src;
    int32_t pivot_x;
    int32_t pivot_y;
    int32_t offset;
} smooth_seconds_t;

extern const lv_obj_class_t smooth_seconds_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void smooth_seconds_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SMOOTH_SECONDS_PRIVATE_H*/