/**
 * @file casio_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "casio_gen.h"
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

lv_obj_t * casio_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_dot;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_main, Segment_100);

        lv_style_init(&style_dot);
        lv_style_set_width(&style_dot, 6);
        lv_style_set_height(&style_dot, 6);
        lv_style_set_bg_color(&style_dot, lv_color_hex(0x000000));
        lv_style_set_radius(&style_dot, 3);
        lv_style_set_border_width(&style_dot, 0);
        lv_style_set_pad_all(&style_dot, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "casio_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, img_casio_bg);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_0, &subject_date, NULL);
    lv_obj_set_style_text_font(lv_label_0, Segment_40, 0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_0, 180);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_1, &subject_hour, "%02d");
    lv_obj_set_style_text_font(lv_label_1, Segment_100, 0);
    lv_obj_set_align(lv_label_1, LV_ALIGN_RIGHT_MID);
    lv_obj_set_y(lv_label_1, 30);
    lv_obj_set_x(lv_label_1, -215);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_2, &subject_minute, "%02d");
    lv_obj_set_style_text_font(lv_label_2, Segment_100, 0);
    lv_obj_set_align(lv_label_2, LV_ALIGN_LEFT_MID);
    lv_obj_set_y(lv_label_2, 30);
    lv_obj_set_x(lv_label_2, 215);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_obj_1, 15);
    lv_obj_add_style(lv_obj_1, &style_dot, 0);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_obj_2, 40);
    lv_obj_add_style(lv_obj_2, &style_dot, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

