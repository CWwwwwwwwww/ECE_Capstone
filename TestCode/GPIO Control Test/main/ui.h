#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "ui_helpers.h"

extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Screen1_Image1;
void ui_event_Screen1_Button1(lv_event_t * e);
extern lv_obj_t * ui_Screen1_Button1;
extern lv_obj_t * ui_Screen1_Label2;
extern lv_obj_t * ui_Screen1_Panel1;
extern lv_obj_t * ui_Screen1_Label1;
void ui_event_Screen1_Button2(lv_event_t * e);
extern lv_obj_t * ui_Screen1_Button2;
extern lv_obj_t * ui_Screen1_Label3;
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Screen1_Panel2;
extern lv_obj_t * ui_Screen1_Label5;
extern lv_obj_t * ui_Screen2_TextArea1;
extern lv_obj_t * ui_Screen2_Keyboard1;
void ui_event_Screen2_Button1(lv_event_t * e);
extern lv_obj_t * ui_Screen2_Button1;
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Button3;


LV_IMG_DECLARE(ui_img_bg1_png);    // assets\back1.png
LV_IMG_DECLARE(ui_img_back_png);    // assets\back.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
