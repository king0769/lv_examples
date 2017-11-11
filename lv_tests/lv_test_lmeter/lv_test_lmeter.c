/**
 * @file lv_test_lmeter.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>

#include "lv_test_lmeter.h"

#if USE_LV_LMETER != 0

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
/**
 * Create a default object and test the basic functions
 */
void lv_test_lmeter_1(void)
{
    /* Create a default object*/
    lv_obj_t *lmeter1 = lv_lmeter_create(lv_scr_act(), NULL);
    lv_obj_set_pos_scale(lmeter1, 10, 10);
    lv_lmeter_set_value(lmeter1, 60);

    /*Copy the previous line meter and set smaller size for it*/
    lv_obj_t *lmeter2 = lv_lmeter_create(lv_scr_act(), lmeter1);
    lv_obj_set_size(lmeter2, LV_DPI / 2,  LV_DPI / 2);
    lv_obj_align_scale(lmeter2, lmeter1, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

    /*Create a styled line meter*/
    static lv_style_t style3;
    lv_style_copy(&style3, &lv_style_pretty);
    style3.body.color_main = COLOR_GREEN;
    style3.body.color_gradient = COLOR_RED;
    style3.body.padding.hor = 4 << LV_ANTIALIAS;    /*Means the line length*/
    style3.body.border.color= COLOR_GRAY;
    style3.line.width = 2 << LV_ANTIALIAS;
    style3.line.color = COLOR_SILVER;

    lv_obj_t *lmeter3 = lv_lmeter_create(lv_scr_act(), lmeter1);
    lv_obj_align_scale(lmeter3, lmeter1, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    lv_obj_set_style(lmeter3, &style3);
    lv_lmeter_set_scale(lmeter3, 270, 41);
    lv_lmeter_set_range(lmeter3, -100, 100);
    lv_lmeter_set_value(lmeter3, 50);

    /*Copy the modified 'lmeter3' and set a smaller size for it*/
    lv_obj_t *lmeter4 = lv_lmeter_create(lv_scr_act(), lmeter3);
    lv_obj_set_size_scale(lmeter4, 60, 60);
    lv_obj_align_scale(lmeter4, lmeter3, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*USE_LV_LMETER*/
