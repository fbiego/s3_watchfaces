/**
 * @file smooth_seconds.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "smooth_seconds_private_gen.h"
#include "s3_watchfaces.h"
#include "time.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void start_animation(smooth_seconds_t * widget);
static void rotate_obj_cb(void * var, int32_t v);
/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void smooth_seconds_constructor_hook(lv_obj_t * obj)
{

    smooth_seconds_t * widget = (smooth_seconds_t *)obj;

    start_animation(widget);

}

void smooth_seconds_destructor_hook(lv_obj_t * obj)
{

    lv_anim_t *anim = lv_obj_get_user_data(obj);

    if (anim)
    {
        lv_anim_delete(anim->var, anim->exec_cb);
    }

}

void smooth_seconds_event_hook(lv_event_t * e)
{

}

void smooth_seconds_set_src(lv_obj_t * smooth_seconds, const void * src)
{
    smooth_seconds_t * widget = (smooth_seconds_t *)smooth_seconds;
    widget->src = src;
    lv_image_set_src(smooth_seconds, src);
}

void smooth_seconds_set_pivot_x(lv_obj_t * smooth_seconds, int32_t pivot_x)
{
    smooth_seconds_t * widget = (smooth_seconds_t *)smooth_seconds;
    widget->pivot_x = pivot_x;
    lv_obj_set_style_transform_pivot_x(smooth_seconds, widget->pivot_x, 0);
}

void smooth_seconds_set_pivot_y(lv_obj_t * smooth_seconds, int32_t pivot_y)
{
    smooth_seconds_t * widget = (smooth_seconds_t *)smooth_seconds;
    widget->pivot_y = pivot_y;
    lv_obj_set_style_transform_pivot_y(smooth_seconds, widget->pivot_y, 0);
}

void smooth_seconds_set_offset(lv_obj_t * smooth_seconds, int32_t offset)
{
    smooth_seconds_t * widget = (smooth_seconds_t *)smooth_seconds;
    widget->offset = offset;
}

void smooth_seconds_restart(lv_obj_t *obj)
{
    smooth_seconds_t * widget = (smooth_seconds_t *)obj;
    start_animation(widget);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void start_animation(smooth_seconds_t * widget)
{
    lv_obj_t *obj = (lv_obj_t *)widget;
    lv_anim_t *anim = lv_obj_get_user_data(obj);
    if (anim)
    {
        lv_anim_delete(anim->var, anim->exec_cb);
    }

    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    int second = ltm->tm_sec;

    lv_obj_set_style_transform_rotation(obj, (second * 60) + widget->offset, 0);


    lv_anim_t rotate;
    lv_anim_init(&rotate);
    lv_anim_set_var(&rotate, widget);
    lv_anim_set_values(&rotate, (second * 60), (second * 60) + 3600);
    lv_anim_set_duration(&rotate, 60000);
    lv_anim_set_exec_cb(&rotate, rotate_obj_cb);
    lv_anim_set_repeat_count(&rotate, LV_ANIM_REPEAT_INFINITE);
    lv_anim_t *running_anim = lv_anim_start(&rotate);

    lv_obj_set_user_data(obj, running_anim);

}

static void rotate_obj_cb(void * var, int32_t v)
{
    smooth_seconds_t * widget = (smooth_seconds_t *)var;
    lv_obj_t *obj = (lv_obj_t *)widget;
    lv_obj_set_style_transform_rotation(obj, v + widget->offset, 0);
}