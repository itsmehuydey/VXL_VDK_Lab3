#include "timer.h"

// Định nghĩa các biến và hằng số cần thiết
static int MAX_COUNTER_IN_MODE_2_3_4 = 0;
int counter_mode_2_3_4 = 0;
int flagMode_RED_BLINK = 0;
int flagMode_GREEN_BLINK = 0;
int flagMode_YELLOW_BLINK = 0;
int flagInteruptLED_and_SEG = 0;


int flagRed[2] = {0, 0};
int flagGreen[2] = {0, 0};
int flagYellow[2] = {0, 0};
int TIMER_CYCLE = 0;

int timerLED_counter = 0;
int timerLED_flag = 0;

void setTimer_LED(int duration) {
    timerLED_counter = duration / TIMER_CYCLE;
    timerLED_flag = 0;
}

void runTimer_LED() {
    if(timerLED_counter > 0) {
        timerLED_counter--;
        if(timerLED_counter == 0) {
            timerLED_flag = 1;
        }
    }
}




