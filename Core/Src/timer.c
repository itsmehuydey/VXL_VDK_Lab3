/*
 * timer.c
 *
 *  Created on: Oct 4, 2024
 *      Author: pc
 */

#include "timer.h"
#include "input_reading.h"
//void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
//{
//if( htim -> Instance == TIM2 ) {
//button_reading () ;
//}
//}


static int MAX_COUNTER_IN_MODE_2_3_4 = 0;
int counter_mode_2_3_4 = 0;
int flagMode_RED_BLINK = 0;
int flagMode_GREEN_BLINK = 0;
int flagMode_YELLOW_BLINK = 0, flagInteruptLED_and_SEG =0;
int flagRed[2] = {0, 0};
int flagGreen[2] = {0, 0};
int flagYellow[2] = {0, 0};


int TIMER_CYCLE = 10;
int timer_counter =0;
int timer_flag = 0;

void setTimer2(int duration){
	timer_counter = duration  / 10;
	timer_flag = 0;
}

void timer_run(){
	if(timer_counter > 0){
		timer_counter--;
		if(timer_counter == 0) timer_flag = 1;
	}
}

int getCYCLE_TIME_ms() {
    return 100;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    if (htim->Instance == TIM2) {
        button_reading();
        if (flagInteruptLED_and_SEG == 1) {
        	timer_run();
        } else {
            if (MAX_COUNTER_IN_MODE_2_3_4 <= 0) {
                MAX_COUNTER_IN_MODE_2_3_4 = 500 / getCYCLE_TIME_ms();
                counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
            }
            if (flagMode_RED_BLINK == 1) {
                if (counter_mode_2_3_4 <= 0) {
                    counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
                } else {
                    if (counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4 / 2) {
                        flagRed[0] = 0;
                        flagRed[1] = 0;
                    } else if (counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4) {
                        flagRed[0] = 1;
                        flagRed[1] = 1;
                    }
                    --counter_mode_2_3_4;
                }
            }
            if (flagMode_GREEN_BLINK == 1) {
                if (counter_mode_2_3_4 <= 0) {
                    counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
                } else {
                    if (counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4 / 2) {
                        flagGreen[0] = 0;
                        flagGreen[1] = 0;
                    } else if (counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4) {
                        flagGreen[0] = 1;
                        flagGreen[1] = 1;
                    }
                    --counter_mode_2_3_4;
                }
            }
            if (flagMode_YELLOW_BLINK) {
                if (counter_mode_2_3_4 <= 0) {
                    counter_mode_2_3_4 = MAX_COUNTER_IN_MODE_2_3_4;
                } else {
                    if (counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4 / 2) {
                        flagYellow[0] = 0;
                        flagYellow[1] = 0;
                    } else if (counter_mode_2_3_4 == MAX_COUNTER_IN_MODE_2_3_4) {
                        flagYellow[0] = 1;
                        flagYellow[1] = 1;
                    }
                    --counter_mode_2_3_4;
                }
            }
        }
    }
}
