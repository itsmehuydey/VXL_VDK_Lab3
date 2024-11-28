/*
 * fsm_automatic.c
 *
 *  Created on: Nov 27, 2024
 *      Author: pc
 */

#include "fsm_automatic.h"

void run_traffic_light(){
	if(timer_flag[0]){
		blinkingLed(status);
		setTimer(0, 50);
	}
}
//void fsm_automatic(){
//	int fre_amber;
//	int fre_green;
//	switch(status){
//		case INIT:
//			subKeyProcess();
//			status = RED_GREEN;
//			setTimer(1, 100);//300
//			setTimer(0, 100);//0
//			clearAllLed();
//			red = max_red;
//			amber = max_amber;
//			green = max_green;
//			temp_red = max_red;
//			temp_amber = max_amber;
//			temp_green = max_green;
//			break;
//		case RED_GREEN:
//			led_red_green();
//			if(timer_flag[0]){
//				--red;
//				--green;
//				displayLED7SEG(red, 0);
//				displayLED7SEG(green, 1);
//				controlTime_led();
//				setTimer(0, 100);
//			}
//			if(timer_flag[1]){
//				status = RED_AMBER;
//				clearAllLed();
//				fre_amber = amber*100;
//				setTimer(1, fre_amber);
//			}
//			if(isButtonPressed(1)){
//				status = MAN_RED_GREEN;
//				setTimer(1, 1000);
//				clearAllLed();
//				red = 10;
//				green = 10;
//				button_flag[1] = 0;
//				setTimer(0, 1);
//			}
//			if(isButtonPressed(0)){
//				status = MODE_2;
//				clearAllLed();
//				setTimer(0, 1);
//				button_flag[0] = 0;
//			}
//			break;
//		case RED_AMBER:
//			led_red_amber();
//			if(timer_flag[0]){
//				--red;
//				--amber;
//				displayLED7SEG(red, 0);
//				displayLED7SEG(amber, 1);
//
//
//				controlTime_led();
//
//				setTimer(0, 100);
//			}
//			if(timer_flag[1]){
//				status = GREEN_RED;
//				clearAllLed();
//				fre_green = green*100;
//				setTimer(1, fre_green);
//			}
//			if(isButtonPressed(1)){
//				status = MAN_RED_AMBER;
//				setTimer(1, 1000);
//				clearAllLed();
//				red = 10;
//				amber = 10;
//				button_flag[1] = 0;
//				setTimer(0, 1);
//			}
//			if(isButtonPressed(0)){
//				status = MODE_2;
//				clearAllLed();
//				setTimer(0, 1);
//				button_flag[0] = 0;
//			}
//			break;
//		case GREEN_RED:
//			led_green_red();
//			if(timer_flag[0]){
//				--red;
//				--green;
//				displayLED7SEG(green, 0);
//				displayLED7SEG(red, 1);
//				controlTime_led();
//				setTimer(0, 100);
//			}
//			if(timer_flag[1]){
//				status = AMBER_RED;
//				clearAllLed();
//				fre_amber = amber*100;
//				setTimer(1, fre_amber);
//			}
//			if(isButtonPressed(1)){
//				status = MAN_GREEN_RED;
//				red = 10;
//				green = 10;
//				clearAllLed();
//				setTimer(1, 1000);
//				button_flag[1] = 0;
//				setTimer(0, 1);
//			}
//			if(isButtonPressed(0)){
//				status = MODE_2;
//				clearAllLed();
//				setTimer(0, 1);
//				button_flag[0] = 0;
//			}
//			break;
//		case AMBER_RED:
//			led_amber_red();
//			if(timer_flag[0]){
//				--red;
//				--amber;
//				displayLED7SEG(amber, 0);
//				displayLED7SEG(red, 1);
//				controlTime_led();
//				setTimer(0, 100);
//			}
//			if(timer_flag[1]){
//				status = RED_GREEN;
//				clearAllLed();
//				fre_green = green*100;
//				setTimer(1, fre_green);
//			}
//			if(isButtonPressed(1)){
//				status = MAN_AMBER_RED;
//				red = 10;
//				amber = 10;
//				setTimer(1, 1000);
//				clearAllLed();
//				button_flag[1] = 0;
//				setTimer(0, 1);
//			}
//			if(isButtonPressed(0)){
//				status = MODE_2;
//				clearAllLed();
//				setTimer(0, 1);
//				button_flag[0] = 0;
//			}
//			break;
//		default: break;
//	}
//}

void handleButtonPress(int manualState, int newRed, int newAmberGreen) {
    status = manualState;
    red = newRed;
    amber = green = newAmberGreen;
    clearAllLed();
    setTimer(1, 1000);
    button_flag[1] = 0;
    setTimer(0, 1);
}



void handleTimerFlag0(int *time1, int *time2, int displayIndex1, int displayIndex2) {
    --(*time1);
    --(*time2);
    displayLED7SEG(*time1, displayIndex1);
    displayLED7SEG(*time2, displayIndex2);
    controlTime_led();
    setTimer(0, 100);
}

void fsm_automatic() {
    int fre_amber, fre_green;
	if(timer_flag[2] ==1){
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		setTimer(2, 100);
	}
    switch (status) {
        case INIT:
            status = RED_GREEN;
            setTimer(1, 100); // 300
            setTimer(0, 100); // 0
            clearAllLed();
            red = amber = green = max_red;
            temp_red = temp_amber = temp_green = max_red;
            break;

        case RED_GREEN:
            led_red_green();
            if (timer_flag[0]) handleTimerFlag0(&red, &green, 0, 1);
            if (timer_flag[1]) {
                status = RED_AMBER;
                clearAllLed();
                fre_amber = amber * 100;
                setTimer(1, fre_amber);
            }
            if (isButtonPressed(1)) handleButtonPress(MAN_RED_GREEN, 10, 10);
            if (isButtonPressed(0)) {
                status = MODE_2;
                clearAllLed();
                button_flag[0] = 0;
                setTimer(0, 1);
            }
            break;

        case RED_AMBER:
            led_red_amber();
            if (timer_flag[0]) handleTimerFlag0(&red, &amber, 0, 1);
            if (timer_flag[1]) {
                status = GREEN_RED;
                clearAllLed();
                fre_green = green * 100;
                setTimer(1, fre_green);
            }
            if (isButtonPressed(1)) handleButtonPress(MAN_RED_AMBER, 10, 10);
            if (isButtonPressed(0)) {
                status = MODE_2;
                clearAllLed();
                button_flag[0] = 0;
                setTimer(0, 1);
            }
            break;

        case GREEN_RED:
            led_green_red();
            if (timer_flag[0]) handleTimerFlag0(&green, &red, 0, 1);
            if (timer_flag[1]) {
                status = AMBER_RED;
                clearAllLed();
                fre_amber = amber * 100;
                setTimer(1, fre_amber);
            }
            if (isButtonPressed(1)) handleButtonPress(MAN_GREEN_RED, 10, 10);
            if (isButtonPressed(0)) {
                status = MODE_2;
                clearAllLed();
                button_flag[0] = 0;
                setTimer(0, 1);
            }
            break;

        case AMBER_RED:
            led_amber_red();
            if (timer_flag[0]) handleTimerFlag0(&amber, &red, 0, 1);
            if (timer_flag[1]) {
                status = RED_GREEN;
                clearAllLed();
                fre_green = green * 100;
                setTimer(1, fre_green);
            }
            if (isButtonPressed(1)) handleButtonPress(MAN_AMBER_RED, 10, 10);
            if (isButtonPressed(0)) {
                status = MODE_2;
                clearAllLed();
                button_flag[0] = 0;
                setTimer(0, 1);
            }
            break;

        default:
            break;
    }
}

