/**
 * @file s3_watchfaces_gen.h
 */

#ifndef S3_WATCHFACES_GEN_H
#define S3_WATCHFACES_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * NS_Regular_20;

extern lv_font_t * NS_Regular_30;

extern lv_font_t * NS_Bold_40;

extern lv_font_t * NS_Bold_60;

extern lv_font_t * Segment_100;

extern lv_font_t * Segment_40;

/*----------------
 * Images
 *----------------*/

extern const void * img_preview;
extern const void * img_casio_bg;
extern const void * img_ultra_bg;
extern const void * img_eyes;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_time;
extern lv_subject_t subject_date;
extern lv_subject_t subject_hour;
extern lv_subject_t subject_minute;
extern lv_subject_t subject_seconds;
extern lv_subject_t subject_hour_analog;
extern lv_subject_t subject_minute_analog;
extern lv_subject_t subject_seconds_analog;
extern lv_subject_t subject_am_pm;
extern lv_subject_t subject_day;
extern lv_subject_t subject_month;
extern lv_subject_t subject_year;
extern lv_subject_t subject_month_short;
extern lv_subject_t subject_month_long;
extern lv_subject_t subject_weekday;
extern lv_subject_t subject_weekday_short;
extern lv_subject_t subject_weekday_long;
extern lv_subject_t subject_battery;
extern lv_subject_t subject_steps;
extern lv_subject_t subject_voltage;
extern lv_subject_t subject_brightness;
extern lv_subject_t subject_info;
extern lv_subject_t subject_esp_time;
extern lv_subject_t subject_rtc_time;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void s3_watchfaces_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "widgets/analog_hand/analog_hand_gen.h"
#include "widgets/smooth_seconds/smooth_seconds_gen.h"
#include "screens/analog/analog_gen.h"
#include "screens/apple/apple_gen.h"
#include "screens/casio/casio_gen.h"
#include "screens/control/control_gen.h"
#include "screens/eyes/eyes_gen.h"
#include "screens/sample/sample_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*S3_WATCHFACES_GEN_H*/