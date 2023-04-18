#include "lvgl.h"
#include "do_wifi.h"

/* ================== Configuration and Setup ==================*/

static String default_password = "6666"; // Password for the door
static String default_password2 = "8888"; // Password for second door
static int wait_time = 20; // Time to wait for back to the main screen (60s)
extern int now_time;
static int out_pin = 12; // Output pin for the relay 1 Lower
static int out_pin2 = 13; // Output pin for the relay 2 Upper 
static int out_time = 10; // Time to keep the relay on (10 s)
static int box_close_time = 5; // Time to close msgbox 5s

void main_init();
void do_wifi(void *pvParameters);
void ui_event_Key_Ok(lv_event_t * e);
static void back_main(lv_timer_t *timer);
void do_pin_out(void *pvParameters);
static void close_msgbox(lv_timer_t *timer);
