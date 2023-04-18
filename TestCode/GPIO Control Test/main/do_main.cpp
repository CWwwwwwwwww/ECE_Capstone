#include "do_main.h"
#include "ui.h"
#include "ui_helpers.h"

int now_time = 0;
int box_time = 0;
int pin_time = 0;
lv_obj_t *mbox1;

/* ========================= Initialize ========================= */
void main_init()
{
    Serial.begin(115200);
    ui_init();
    xTaskCreatePinnedToCore(do_wifi, "do_wifi", 10000, NULL, 1, NULL, 1);
    lv_obj_add_event_cb(ui_Screen2_Keyboard1, ui_event_Key_Ok, LV_EVENT_READY, NULL);
    
}



/* ========================= Wi-Fi Connection ========================= */
void do_wifi(void *pvParameters)
{
    delay(600);

    Serial.println("Starting Wi-Fi Connection...");
    // Enterprise Wi-Fi Connection 
    //connectWifi();

    // Home Wi-Fi Connection
    connect("NotYourWIFI", "Wsn@244466666!");
    Serial.println("Wi-Fi Connected");

    vTaskDelete(NULL);
}



/* ========================= Relay 1 Control ========================= */
void set_out_pin(lv_timer_t *timer)
{
    pin_time++;
    if (pin_time == 1)
    {
        Serial.println("Pin 12 High, Relay Open");
        pinMode(out_pin, OUTPUT);
        digitalWrite(out_pin, HIGH);
    }
    if (pin_time == out_time)
    {
        Serial.println("Pin 12 Low, Relay Closed");
        digitalWrite(out_pin, LOW);
        lv_timer_del(timer);
        lv_scr_load(ui_Screen1);
        lv_textarea_set_text(ui_Screen2_TextArea1, "");
    }
}



/* ========================= Relay 2 Control ========================= */
void set_out_pin2(lv_timer_t *timer)
{
    pin_time++;
    if (pin_time == 1)
    {
        Serial.println("Pin 13 High, Relay Open");
        pinMode(out_pin2, OUTPUT);
        digitalWrite(out_pin2, HIGH);
    }
    if (pin_time == out_time)
    {
        Serial.println("Pin 13 Low, Relay Closed");
        digitalWrite(out_pin2, LOW);
        lv_timer_del(timer);
        lv_scr_load(ui_Screen1);
        lv_textarea_set_text(ui_Screen2_TextArea1, "");
    }
}



/* ========================= Password Input ========================= */
void ui_event_Key_Ok(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);

    if (event_code == LV_EVENT_READY)
    {
        Serial.println("Button pressed");
        Serial.println(lv_textarea_get_text(ui_Screen2_TextArea1));

        // Get Password input
        String password = lv_textarea_get_text(ui_Screen2_TextArea1);

        if (password == default_password)
        {
            Serial.println("Password correct!");

            static const char *btns[] = {""};

            mbox1 = lv_msgbox_create(NULL, "Password Correct!", "Cabinet Unlocked. Please close the door after pick up the food.", btns, true);
            lv_obj_set_width(mbox1, 300);
            lv_obj_set_height(mbox1, 120);

            lv_obj_center(mbox1);
            Serial.println("Cabinet Open.");
            pin_time = 0;
            lv_timer_create(set_out_pin, 1000, NULL);
            box_time = 0;
            lv_timer_create(close_msgbox, 1000, NULL);
        }

        else if (password == default_password2)
        {
            Serial.println("Password correct!");

            static const char *btns[] = {""};

            mbox1 = lv_msgbox_create(NULL, "Password Correct!", "Cabinet Unlocked. Please close the door after pick up the food.", btns, true);
            lv_obj_set_width(mbox1, 300);
            lv_obj_set_height(mbox1, 120);

            lv_obj_center(mbox1);
            Serial.println("Cabinet Open.");
            pin_time = 0;
            lv_timer_create(set_out_pin2, 1000, NULL);
            box_time = 0;
            lv_timer_create(close_msgbox, 1000, NULL);
        }

        else
        {
            Serial.println("Password incorrect!");
            static const char *btns[] = {""};

            mbox1 = lv_msgbox_create(NULL, "Oops!", "Incorrect Password! Please try again.", btns, true);
            lv_obj_set_width(mbox1, 300);
            lv_obj_set_height(mbox1, 120);

            lv_obj_center(mbox1);
            lv_textarea_set_text(ui_Screen2_TextArea1, "");
            box_time = 0;
            lv_timer_create(close_msgbox, 1000, NULL);
        }
    }
}




/* ========================= Back Screen 1 ========================= */
static void back_main(lv_timer_t *timer)
{
    now_time++;
    if (now_time >= wait_time)
    {
        lv_timer_del(timer);
        lv_scr_load(ui_Screen1);
        lv_textarea_set_text(ui_Screen2_TextArea1, "");
    }
    Serial.println(now_time);
}



/* ========================= Button 1 - Customer ========================= */
void ui_event_Screen1_Button1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
        lv_timer_create(back_main, 1000, NULL);
    }
}



/* ========================= Button 2 - Driver ========================= */
void ui_event_Screen1_Button2(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
        lv_timer_create(back_main, 1000, NULL);
    }
}



/* ========================= Close Msgbox ========================= */
static void close_msgbox(lv_timer_t *timer)
{

    box_time++;
    if (box_time >= box_close_time)
    {
        lv_timer_del(timer);
        lv_msgbox_close(mbox1);
    }
    Serial.println(now_time);
}
