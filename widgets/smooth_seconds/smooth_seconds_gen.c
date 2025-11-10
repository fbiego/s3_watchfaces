/**
 * @file smooth_seconds_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "smooth_seconds_private_gen.h"
#include "lvgl/src/core/lv_obj_class_private.h"
#include "s3_watchfaces.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void smooth_seconds_constructor_hook(lv_obj_t * obj);
void smooth_seconds_destructor_hook(lv_obj_t * obj);
void smooth_seconds_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void smooth_seconds_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void smooth_seconds_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void smooth_seconds_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t smooth_seconds_class = {
    .base_class = &lv_image_class,
    .constructor_cb = smooth_seconds_constructor,
    .destructor_cb = smooth_seconds_destructor,
    .event_cb = smooth_seconds_event,
    .instance_size = sizeof(smooth_seconds_t),
    .editable = 1,
    .name = "smooth_seconds"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * smooth_seconds_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&smooth_seconds_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void smooth_seconds_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    smooth_seconds_t * widget = (smooth_seconds_t *)obj;
    static lv_style_t style_main;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, LV_SIZE_CONTENT);
        lv_style_set_height(&style_main, LV_SIZE_CONTENT);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_main, 0);


    smooth_seconds_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void smooth_seconds_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    smooth_seconds_destructor_hook(obj);
}

static void smooth_seconds_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&smooth_seconds_class, e);
    if(res != LV_RESULT_OK) return;

    smooth_seconds_event_hook(e);
}

