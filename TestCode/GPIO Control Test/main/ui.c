#include "ui.h"


///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Image1;
void ui_event_Screen1_Button1(lv_event_t * e);
lv_obj_t * ui_Screen1_Button1;
lv_obj_t * ui_Screen1_Label2;
lv_obj_t * ui_Screen1_Panel1;
lv_obj_t * ui_Screen1_Label1;
void ui_event_Screen1_Button2(lv_event_t * e);
lv_obj_t * ui_Screen1_Button2;
lv_obj_t * ui_Screen1_Label3;
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Screen1_Panel2;
lv_obj_t * ui_Screen1_Label5;
lv_obj_t * ui_Screen2_TextArea1;
lv_obj_t * ui_Screen2_Keyboard1;
void ui_event_Screen2_Button1(lv_event_t * e);
lv_obj_t * ui_Screen2_Button1;
lv_obj_t * ui_Button1;
lv_obj_t * ui_Button2;
lv_obj_t * ui_Button3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

void ui_event_Screen2_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
        lv_textarea_set_text(ui_Screen2_TextArea1, "");
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Image1 = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Screen1_Image1, &ui_img_bg1_png);
    lv_obj_set_width(ui_Screen1_Image1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Image1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Image1, 0);
    lv_obj_set_y(ui_Screen1_Image1, 4);
    lv_obj_set_align(ui_Screen1_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button1, 158);
    lv_obj_set_height(ui_Screen1_Button1, 104);
    lv_obj_set_x(ui_Screen1_Button1, -110);
    lv_obj_set_y(ui_Screen1_Button1, 28);
    lv_obj_set_align(ui_Screen1_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1_Button1, lv_color_hex(0x1E1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label2 = lv_label_create(ui_Screen1_Button1);
    lv_obj_set_width(ui_Screen1_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label2, "Customer\n  Pick-up");
    lv_obj_set_style_text_color(ui_Screen1_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label2, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel1, 504);
    lv_obj_set_height(ui_Screen1_Panel1, 50);
    lv_obj_set_x(ui_Screen1_Panel1, -6);
    lv_obj_set_y(ui_Screen1_Panel1, -140);
    lv_obj_set_align(ui_Screen1_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Panel1, lv_color_hex(0xBA0C2F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label1, LV_SIZE_CONTENT);   /// 2
    lv_obj_set_height(ui_Screen1_Label1, LV_SIZE_CONTENT);    /// 2
    lv_obj_set_x(ui_Screen1_Label1, 0);
    lv_obj_set_y(ui_Screen1_Label1, -138);
    lv_obj_set_align(ui_Screen1_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label1, "Smart Takeout Locker");
    lv_obj_set_style_text_color(ui_Screen1_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen1_Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button2, 158);
    lv_obj_set_height(ui_Screen1_Button2, 104);
    lv_obj_set_x(ui_Screen1_Button2, 107);
    lv_obj_set_y(ui_Screen1_Button2, 27);
    lv_obj_set_align(ui_Screen1_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1_Button2, lv_color_hex(0x1E1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label3 = lv_label_create(ui_Screen1_Button2);
    lv_obj_set_width(ui_Screen1_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label3, "Delivery\nDrop off");
    lv_obj_set_style_text_color(ui_Screen1_Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label3, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Screen1_Button1, ui_event_Screen1_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen1_Button2, ui_event_Screen1_Button2, LV_EVENT_ALL, NULL);

}
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Panel2 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Screen1_Panel2, 504);
    lv_obj_set_height(ui_Screen1_Panel2, 50);
    lv_obj_set_x(ui_Screen1_Panel2, -6);
    lv_obj_set_y(ui_Screen1_Panel2, -140);
    lv_obj_set_align(ui_Screen1_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Panel2, lv_color_hex(0xBA0C2F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label5 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Screen1_Label5, LV_SIZE_CONTENT);   /// 2
    lv_obj_set_height(ui_Screen1_Label5, LV_SIZE_CONTENT);    /// 2
    lv_obj_set_x(ui_Screen1_Label5, 0);
    lv_obj_set_y(ui_Screen1_Label5, -138);
    lv_obj_set_align(ui_Screen1_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label5, "Smart Takeout Locker");
    lv_obj_set_style_text_color(ui_Screen1_Label5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label5, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen2_TextArea1 = lv_textarea_create(ui_Screen2);
    lv_obj_set_width(ui_Screen2_TextArea1, 452);
    lv_obj_set_height(ui_Screen2_TextArea1, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Screen2_TextArea1, -1);
    lv_obj_set_y(ui_Screen2_TextArea1, -86);
    lv_obj_set_align(ui_Screen2_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_Screen2_TextArea1, 4);  // Max Length of the password
    lv_textarea_set_placeholder_text(ui_Screen2_TextArea1, "Please input the password");
    lv_textarea_set_one_line(ui_Screen2_TextArea1, true);
    lv_obj_set_style_text_align(ui_Screen2_TextArea1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_TextArea1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_align(ui_Screen2_TextArea1, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Screen2_TextArea1, lv_color_hex(0x282727),
                                LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_TextArea1, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_Screen2_Keyboard1 = lv_keyboard_create(ui_Screen2);
    lv_keyboard_set_mode(ui_Screen2_Keyboard1, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_Screen2_Keyboard1, 472);
    lv_obj_set_height(ui_Screen2_Keyboard1, 212);
    lv_obj_set_x(ui_Screen2_Keyboard1, 0);
    lv_obj_set_y(ui_Screen2_Keyboard1, 49);
    lv_obj_set_align(ui_Screen2_Keyboard1, LV_ALIGN_CENTER);

    ui_Screen2_Button1 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Screen2_Button1, 82);
    lv_obj_set_height(ui_Screen2_Button1, 36);
    lv_obj_set_x(ui_Screen2_Button1, -195);
    lv_obj_set_y(ui_Screen2_Button1, -138);
    lv_obj_set_align(ui_Screen2_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen2_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen2_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen2_Button1, lv_color_hex(0x8E0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen2_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Screen2_Button1, &ui_img_back_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen2_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button1, 77);
    lv_obj_set_height(ui_Button1, 34);
    lv_obj_set_x(ui_Button1, -1);
    lv_obj_set_y(ui_Button1, 126);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Button1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button2, 78);
    lv_obj_set_height(ui_Button2, 36);
    lv_obj_set_x(ui_Button2, -186);
    lv_obj_set_y(ui_Button2, 127);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Button2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button3, 167);
    lv_obj_set_height(ui_Button3, 29);
    lv_obj_set_x(ui_Button3, 141);
    lv_obj_set_y(ui_Button3, -28);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xE6E2E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button3, lv_color_hex(0xE6E2E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Button3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_keyboard_set_textarea(ui_Screen2_Keyboard1, ui_Screen2_TextArea1);
    lv_obj_add_event_cb(ui_Screen2_Button1, ui_event_Screen2_Button1, LV_EVENT_ALL, NULL);

    

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
