/**
 * @file analog_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "analog_gen.h"
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

lv_obj_t * analog_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_hour;
    static lv_style_t style_minute;
    static lv_style_t style_second;
    static lv_style_t style_dot;
    static lv_style_t style_dot_s;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_color(&style_main, lv_color_hex(0x7fff48));

        lv_style_init(&style_hour);
        lv_style_set_width(&style_hour, 140);
        lv_style_set_height(&style_hour, 10);
        lv_style_set_bg_color(&style_hour, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_hour, 255);
        lv_style_set_radius(&style_hour, 0);

        lv_style_init(&style_minute);
        lv_style_set_width(&style_minute, 180);
        lv_style_set_height(&style_minute, 6);
        lv_style_set_bg_color(&style_minute, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_minute, 255);
        lv_style_set_radius(&style_minute, 0);

        lv_style_init(&style_second);
        lv_style_set_width(&style_second, 240);
        lv_style_set_height(&style_second, 4);
        lv_style_set_bg_color(&style_second, lv_color_hex(0x7fff48));
        lv_style_set_bg_opa(&style_second, 255);
        lv_style_set_radius(&style_second, 0);

        lv_style_init(&style_dot);
        lv_style_set_width(&style_dot, 30);
        lv_style_set_height(&style_dot, 30);
        lv_style_set_bg_color(&style_dot, lv_color_hex(0x626262));
        lv_style_set_radius(&style_dot, 20);
        lv_style_set_border_width(&style_dot, 0);
        lv_style_set_pad_all(&style_dot, 0);

        lv_style_init(&style_dot_s);
        lv_style_set_width(&style_dot_s, 20);
        lv_style_set_height(&style_dot_s, 20);
        lv_style_set_bg_color(&style_dot_s, lv_color_hex(0x7fff48));
        lv_style_set_radius(&style_dot_s, 20);
        lv_style_set_border_width(&style_dot_s, 0);
        lv_style_set_pad_all(&style_dot_s, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "analog_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * analog_hand_0 = analog_hand_create(lv_obj_0);
    lv_obj_set_x(analog_hand_0, 205);
    lv_obj_set_y(analog_hand_0, 246);
    analog_hand_set_pivot_x(analog_hand_0, 0);
    analog_hand_set_pivot_y(analog_hand_0, 5);
    analog_hand_set_offset(analog_hand_0, -900);
    analog_hand_bind_rotation(analog_hand_0, &subject_hour_analog);
    lv_obj_add_style(analog_hand_0, &style_hour, 0);
    
    lv_obj_t * analog_hand_1 = analog_hand_create(lv_obj_0);
    lv_obj_set_x(analog_hand_1, 205);
    lv_obj_set_y(analog_hand_1, 248);
    analog_hand_set_pivot_x(analog_hand_1, 0);
    analog_hand_set_pivot_y(analog_hand_1, 3);
    analog_hand_set_offset(analog_hand_1, -900);
    analog_hand_bind_rotation(analog_hand_1, &subject_minute_analog);
    lv_obj_add_style(analog_hand_1, &style_minute, 0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
    lv_obj_add_style(lv_obj_1, &style_dot, 0);
    
    lv_obj_t * smooth_seconds_0 = smooth_seconds_create(lv_obj_0);
    lv_obj_set_x(smooth_seconds_0, 165);
    lv_obj_set_y(smooth_seconds_0, 249);
    smooth_seconds_set_pivot_x(smooth_seconds_0, 40);
    smooth_seconds_set_pivot_y(smooth_seconds_0, 2);
    smooth_seconds_set_offset(smooth_seconds_0, -900);
    lv_obj_add_style(smooth_seconds_0, &style_second, 0);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_CENTER);
    lv_obj_add_style(lv_obj_2, &style_dot_s, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

