/**
 * @file control_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "control_gen.h"
#include "s3_watchfaces.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * control_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_color(&style_main, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_main, NS_Bold_60);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "control_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_0, &subject_time, NULL);
    lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_0, 100);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_1, &subject_date, NULL);
    lv_obj_set_align(lv_label_1, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_1, 170);
    lv_obj_set_style_text_font(lv_label_1, NS_Bold_40, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_2, &subject_brightness, "Brightness %d");
    lv_obj_set_style_text_font(lv_label_2, NS_Regular_20, 0);
    lv_obj_set_align(lv_label_2, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(lv_label_2, -70);
    
    lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_0);
    lv_slider_bind_value(lv_slider_0, &subject_brightness);
    lv_obj_set_align(lv_slider_0, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(lv_slider_0, -50);
    lv_slider_set_min_value(lv_slider_0, 1);
    lv_slider_set_max_value(lv_slider_0, 255);
    
    lv_obj_t * lv_animimg_0 = lv_animimg_create(lv_obj_0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

