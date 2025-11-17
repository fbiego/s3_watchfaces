/**
 * @file sample_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "sample_gen.h"
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

lv_obj_t * sample_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));

        lv_style_init(&style_cont);
        lv_style_set_bg_color(&style_cont, lv_color_hex(0x000000));
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_bg_opa(&style_cont, 0);
        lv_style_set_text_color(&style_cont, lv_color_hex(0xffff00));
        lv_style_set_text_font(&style_cont, NS_Bold_60);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_pad_column(&style_cont, 0);
        lv_style_set_width(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_height(&style_cont, LV_SIZE_CONTENT);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "sample_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_obj_1, 180);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_0, &subject_hour, "%02d");
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_1, ":");
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_2, &subject_minute, "%02d");
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_3, ":");
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_4, &subject_seconds, "%02d");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

