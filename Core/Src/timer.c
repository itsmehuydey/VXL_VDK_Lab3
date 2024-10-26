#include "timer.h"

// Định nghĩa các biến và hằng số cần thiết
static int MAX_COUNTER_IN_MODE_2_3_4 = 0;
int counter_mode_2_3_4 = 0;
int flagMode_RED_BLINK = 0;
int flagMode_GREEN_BLINK = 0;
int flagMode_YELLOW_BLINK = 0;
int flagInteruptLED_and_SEG = 0;

// Khai báo mảng flag cho LED
int flagRed[2] = {0, 0};    // Cờ cho LED đỏ (hoặc bất kỳ kích thước cần thiết nào)
int flagGreen[2] = {0, 0};  // Cờ cho LED xanh
int flagYellow[2] = {0, 0}; // Cờ cho LED vàng
//int timer0_counter = 0;
//int timer0_flag = 0;
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

//	if(timer1_counter > 0){
//		timer1_counter--;
//		if(timer1_counter == 0) timer1_flag = 1;
//	}

// Định nghĩa hàm callback của Timer
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if(htim->Instance == TIM2) {
        button_reading();
        if(flagInteruptLED_and_SEG == 1) {
            runTimer_LED();
        } else {
            if(MAX_COUNTER_IN_MODE_2_3_4 <= 0) {
                MAX_COUNTER_IN_MODE_2_3_4 = 500 / 10;
                counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
            }
            if(flagMode_RED_BLINK == 1) {
                if(counter_mode_2_3_4 <= 0) {
                    counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
                } else {
                    if(counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4 / 2) {
                        flagRed[0] = 0;
                        flagRed[1] = 0;
                    } else if(counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4) {
                        flagRed[0] = 1;
                        flagRed[1] = 1;
                    }
                    --counter_mode_2_3_4;
                }
            }
            if(flagMode_GREEN_BLINK == 1) {
                if(counter_mode_2_3_4 <= 0) {
                    counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
                } else {
                    if(counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4 / 2) {
                        flagGreen[0] = 0;
                        flagGreen[1] = 0;
                    } else if(counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4) {
                        flagGreen[0] = 1;
                        flagGreen[1] = 1;
                    }
                    --counter_mode_2_3_4;
                }
            }
            if(flagMode_YELLOW_BLINK) {
                if(counter_mode_2_3_4 <= 0) {
                    counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
                } else {
                    if(counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4 / 2) {
                        flagYellow[0] = 0;
                        flagYellow[1] = 0;
                    } else if(counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4) {
                        flagYellow[0] = 1;
                        flagYellow[1] = 1;
                    }
                    --counter_mode_2_3_4;
                }
            }
        }
    }
}
