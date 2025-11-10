/**
 * @file smooth_seconds_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "smooth_seconds_gen.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "src/lvgl_private.h"
#else
    #include "lvgl/src/lvgl_private.h"
#endif

#if LV_USE_XML

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

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void * smooth_seconds_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = smooth_seconds_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create smooth_seconds");
        return NULL;
    }

    return item;
}

void smooth_seconds_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("pivot_x", name)) {
            smooth_seconds_set_pivot_x(item, lv_xml_atoi(value));
        }

        if(lv_streq("pivot_y", name)) {
            smooth_seconds_set_pivot_y(item, lv_xml_atoi(value));
        }

        if(lv_streq("src", name)) {
            smooth_seconds_set_src(item, lv_xml_get_image(&state->scope, value));
        }

        if(lv_streq("offset", name)) {
            smooth_seconds_set_offset(item, lv_xml_atoi(value));
        }
    }
}

void smooth_seconds_register(void)
{
    lv_xml_register_widget("smooth_seconds", smooth_seconds_xml_create, smooth_seconds_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */