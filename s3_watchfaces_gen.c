/**
 * @file s3_watchfaces_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "s3_watchfaces_gen.h"

#if LV_USE_XML
#include "widgets/analog_hand/analog_hand_private_gen.h"
#include "widgets/smooth_seconds/smooth_seconds_private_gen.h"
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * NS_Regular_20;
extern lv_font_t NS_Regular_20_data;
lv_font_t * NS_Regular_30;
extern lv_font_t NS_Regular_30_data;
lv_font_t * NS_Bold_40;
extern lv_font_t NS_Bold_40_data;
lv_font_t * NS_Bold_60;
extern lv_font_t NS_Bold_60_data;
lv_font_t * Segment_100;
lv_font_t * Segment_40;

/*----------------
 * Images
 *----------------*/

const void * img_preview;
extern const void * img_preview_data;
const void * img_casio_bg;
extern const void * img_casio_bg_data;
const void * img_ultra_bg;
extern const void * img_ultra_bg_data;
const void * img_eyes;
extern const void * img_eyes_data;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_time;
lv_subject_t subject_date;
lv_subject_t subject_hour;
lv_subject_t subject_minute;
lv_subject_t subject_seconds;
lv_subject_t subject_hour_analog;
lv_subject_t subject_minute_analog;
lv_subject_t subject_seconds_analog;
lv_subject_t subject_am_pm;
lv_subject_t subject_day;
lv_subject_t subject_month;
lv_subject_t subject_year;
lv_subject_t subject_month_short;
lv_subject_t subject_month_long;
lv_subject_t subject_weekday;
lv_subject_t subject_weekday_short;
lv_subject_t subject_weekday_long;
lv_subject_t subject_battery;
lv_subject_t subject_steps;
lv_subject_t subject_voltage;
lv_subject_t subject_brightness;
lv_subject_t subject_info;
lv_subject_t subject_esp_time;
lv_subject_t subject_rtc_time;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void s3_watchfaces_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/

    /* get font 'NS_Regular_20' from a C array */
    NS_Regular_20 = &NS_Regular_20_data;
    /* get font 'NS_Regular_30' from a C array */
    NS_Regular_30 = &NS_Regular_30_data;
    /* get font 'NS_Bold_40' from a C array */
    NS_Bold_40 = &NS_Bold_40_data;
    /* get font 'NS_Bold_60' from a C array */
    NS_Bold_60 = &NS_Bold_60_data;
    /* create bin font 'Segment_100' from file */
    lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Segment_100");
    Segment_100 = lv_binfont_create(buf);
    /* create bin font 'Segment_40' from file */
    lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Segment_40");
    Segment_40 = lv_binfont_create(buf);


    /*----------------
     * Images
     *----------------*/
    img_preview = &img_preview_data;
    img_casio_bg = &img_casio_bg_data;
    img_ultra_bg = &img_ultra_bg_data;
    img_eyes = &img_eyes_data;

    /*----------------
     * Subjects
     *----------------*/
    static char subject_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_time,
                           subject_time_buf,
                           subject_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "12:45"
                          );
    static char subject_date_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_date_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_date,
                           subject_date_buf,
                           subject_date_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sun 5 Oct"
                          );
    lv_subject_init_int(&subject_hour, 12);
    lv_subject_init_int(&subject_minute, 45);
    lv_subject_init_int(&subject_seconds, 23);
    lv_subject_init_int(&subject_hour_analog, 3150);
    lv_subject_init_int(&subject_minute_analog, 450);
    lv_subject_init_int(&subject_seconds_analog, 1800);
    static char subject_am_pm_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_am_pm_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_am_pm,
                           subject_am_pm_buf,
                           subject_am_pm_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "AM"
                          );
    lv_subject_init_int(&subject_day, 5);
    lv_subject_init_int(&subject_month, 10);
    lv_subject_init_int(&subject_year, 2025);
    static char subject_month_short_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_month_short_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_month_short,
                           subject_month_short_buf,
                           subject_month_short_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Oct"
                          );
    static char subject_month_long_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_month_long_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_month_long,
                           subject_month_long_buf,
                           subject_month_long_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "October"
                          );
    lv_subject_init_int(&subject_weekday, 0);
    static char subject_weekday_short_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_weekday_short_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_weekday_short,
                           subject_weekday_short_buf,
                           subject_weekday_short_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sun"
                          );
    static char subject_weekday_long_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_weekday_long_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_weekday_long,
                           subject_weekday_long_buf,
                           subject_weekday_long_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sunday"
                          );
    lv_subject_init_int(&subject_battery, 83);
    lv_subject_init_int(&subject_steps, 1234);
    lv_subject_init_int(&subject_voltage, 3869);
    lv_subject_init_int(&subject_brightness, 150);
    static char subject_info_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_info_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_info,
                           subject_info_buf,
                           subject_info_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "None"
                          );
    static char subject_esp_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_esp_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_esp_time,
                           subject_esp_time_buf,
                           subject_esp_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "14:55:02"
                          );
    static char subject_rtc_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_rtc_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_rtc_time,
                           subject_rtc_time_buf,
                           subject_rtc_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "09:55:02\\nMon 3 Nov"
                          );

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */
    analog_hand_register();
    smooth_seconds_register();

    /* Register fonts */
    lv_xml_register_font(NULL, "NS_Regular_20", NS_Regular_20);
    lv_xml_register_font(NULL, "NS_Regular_30", NS_Regular_30);
    lv_xml_register_font(NULL, "NS_Bold_40", NS_Bold_40);
    lv_xml_register_font(NULL, "NS_Bold_60", NS_Bold_60);
    lv_xml_register_font(NULL, "Segment_100", Segment_100);
    lv_xml_register_font(NULL, "Segment_40", Segment_40);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_time", &subject_time);
    lv_xml_register_subject(NULL, "subject_date", &subject_date);
    lv_xml_register_subject(NULL, "subject_hour", &subject_hour);
    lv_xml_register_subject(NULL, "subject_minute", &subject_minute);
    lv_xml_register_subject(NULL, "subject_seconds", &subject_seconds);
    lv_xml_register_subject(NULL, "subject_hour_analog", &subject_hour_analog);
    lv_xml_register_subject(NULL, "subject_minute_analog", &subject_minute_analog);
    lv_xml_register_subject(NULL, "subject_seconds_analog", &subject_seconds_analog);
    lv_xml_register_subject(NULL, "subject_am_pm", &subject_am_pm);
    lv_xml_register_subject(NULL, "subject_day", &subject_day);
    lv_xml_register_subject(NULL, "subject_month", &subject_month);
    lv_xml_register_subject(NULL, "subject_year", &subject_year);
    lv_xml_register_subject(NULL, "subject_month_short", &subject_month_short);
    lv_xml_register_subject(NULL, "subject_month_long", &subject_month_long);
    lv_xml_register_subject(NULL, "subject_weekday", &subject_weekday);
    lv_xml_register_subject(NULL, "subject_weekday_short", &subject_weekday_short);
    lv_xml_register_subject(NULL, "subject_weekday_long", &subject_weekday_long);
    lv_xml_register_subject(NULL, "subject_battery", &subject_battery);
    lv_xml_register_subject(NULL, "subject_steps", &subject_steps);
    lv_xml_register_subject(NULL, "subject_voltage", &subject_voltage);
    lv_xml_register_subject(NULL, "subject_brightness", &subject_brightness);
    lv_xml_register_subject(NULL, "subject_info", &subject_info);
    lv_xml_register_subject(NULL, "subject_esp_time", &subject_esp_time);
    lv_xml_register_subject(NULL, "subject_rtc_time", &subject_rtc_time);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_preview", img_preview);
    lv_xml_register_image(NULL, "img_casio_bg", img_casio_bg);
    lv_xml_register_image(NULL, "img_ultra_bg", img_ultra_bg);
    lv_xml_register_image(NULL, "img_eyes", img_eyes);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/