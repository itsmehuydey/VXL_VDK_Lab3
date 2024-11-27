#include "input_processing.h"
int value_high;
int value_low, mode;
 //mode = 0;
//void fsm_manual() {
//    //but1
//		if (flag_reset == 1) {
//	            reset();
//	            flag_reset = 0;
//                mode++;
//                if (mode > 4) {
//                  mode = 1;
//                  retime();
//                  }
//                number_settime = 0;
//       	     if(mode != 1) {
//       	       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
//       	     } else {
//       	       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
//       	     }
//	        }
//
//}


void fsm_automatic(void) {
    if (timer0_flag == 1) {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
        vertical_counter--;
        int vertical_counter_high = vertical_counter / 10;
        int vertical_counter_low  = vertical_counter % 10;

        display7SEG(vertical_counter_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
                     GPIO_PIN_2, GPIO_PIN_3);
        display7SEG(vertical_counter_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
                     GPIO_PIN_6, GPIO_PIN_7);

        switch (vertical_state) {
            case INIT:

                vertical_state = RED_LIGHT;
                break;
            case RED_LIGHT:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_10, RESET);
                if (vertical_counter <= 0) {
                    vertical_counter = green_time;
                    vertical_state = GREEN_LIGHT;
                }
                break;
            case GREEN_LIGHT:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_8, RESET);
                if (vertical_counter <= 0) {
                    vertical_counter = yellow_time;
                    vertical_state = YELLOW_LIGHT;
                }
                break;
            case YELLOW_LIGHT:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_8, RESET);
                if (vertical_counter <= 0) {
                    vertical_counter = red_time;
                    vertical_state = RED_LIGHT;
                }
                break;
            default:
                break;
        }

        horizontal_counter--;
        int horizontal_counter_high = horizontal_counter / 10;
        int horizontal_counter_low  = horizontal_counter % 10;
        display7SEG(horizontal_counter_high, GPIOA, GPIO_PIN_8, GPIO_PIN_9,
                     GPIO_PIN_10, GPIO_PIN_11);
        display7SEG(horizontal_counter_low, GPIOA, GPIO_PIN_12,
                     GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);

        switch (horizontal_state) {
            case INIT:
            	//retime();
                horizontal_state = RED_LIGHT;
                break;
            case RED_LIGHT:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_12, RESET);
                if (horizontal_counter <= 0) {
                    horizontal_counter = green_time;
                    horizontal_state = GREEN_LIGHT;
                }
                break;
            case GREEN_LIGHT:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_13, RESET);
                if (horizontal_counter <= 0) {
                    horizontal_counter = yellow_time;
                    horizontal_state = YELLOW_LIGHT;
                }
                break;
            case YELLOW_LIGHT:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_12, RESET);
                if (horizontal_counter <= 0) {
                    horizontal_counter = red_time;
                    horizontal_state = RED_LIGHT;
                }
                break;
            default:
                break;
        }
        timer0_flag = 0;
        setTimer0(1000);
    }
}

void fsm_setting() {
	if(mode != 1) {
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
	} else {
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
	}
    switch (mode) {
        case INIT:
        	//retime();
            mode = MODE1;
            break;

        case MODE1:
        	display7SEG(mode, GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);
            if (flag_reset == 1){
            	mode = MODE2;
            	flag_reset = 0;
            	number_settime = 0;
            }
            //fsm_automatic();
            break;
        case MODE2:
        	vertical_state = -1;
        	horizontal_state = -1;
            value_high = number_settime / 10;
            value_low = number_settime % 10;
            display7SEG(value_high, GPIOA, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11); // LED2
            display7SEG(value_low, GPIOA, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15); // LED3
            display7SEG(mode, GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);
            int red_time_high = red_time / 10;
            int red_time_low = red_time % 10;
            display7SEG(red_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3);  // RED time high
            display7SEG(red_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);   // RED time low

            if (flag_reset == 1){
                        	mode = MODE3;
                        	flag_reset = 0;
                        	number_settime = 0;
                        }


            if (timer1_flag) {
                setTimer1(500);
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);
            }

            if (flag_settime_mode == 1) {
                number_settime++;
                if (number_settime > 99) number_settime = 0;
                flag_settime_mode = 0;
            }

            if (flag_set ==1 ) {
                red_time = number_settime;
                flag_set = 0;
                retime();
            }
            break;

        case MODE3:
        	vertical_state = -1;
        	horizontal_state = -1;
            value_high = number_settime / 10;
            value_low = number_settime % 10;
            display7SEG(value_high, GPIOA, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11); // LED2
            display7SEG(value_low, GPIOA, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15); // LED3
            display7SEG(mode, GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);
            int green_time_high = green_time / 10;
            int green_time_low = green_time % 10;
            display7SEG(green_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3);  // GREEN time high
            display7SEG(green_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);   // GREEN time low

            if (timer1_flag) {
                setTimer1(500);
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
            }

            if (flag_settime_mode == 1) {
                number_settime++;
                if (number_settime > 99) number_settime = 0;
                flag_settime_mode = 0;
            }

            if (flag_reset == 1){
                        	mode = MODE4;
                        	flag_reset = 0;
                        	number_settime = 0;
                        }

            if (flag_set == 1) {
                green_time = number_settime;
                flag_set = 0;
                retime();
            }
            break;

        case MODE4:
        	vertical_state = -1;
        	horizontal_state = -1;
            value_high = number_settime / 10;
            value_low = number_settime % 10;
            display7SEG(value_high, GPIOA, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11); // LED2
            display7SEG(value_low, GPIOA, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15); // LED3
            display7SEG( mode, GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);
            int yellow_time_high = yellow_time / 10;
            int yellow_time_low = yellow_time % 10;
            display7SEG(yellow_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3);  // YELLOW time high
            display7SEG(yellow_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);   // YELLOW time low

            if (timer1_flag) {
                setTimer1(500);
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
            }

            if (flag_settime_mode == 1) {
                number_settime++;
                if (number_settime > 99) number_settime = 0;
                flag_settime_mode = 0;
            }

            if (flag_reset == 1){
                        	mode = MODE1;
                        	reset();
                        	flag_reset = 0;
                        	number_settime = 0;
                        	if (mode > 4) {
                        	mode = 1;
                        	retime();
                        	}
                        	vertical_state = 0;
                        	horizontal_state = 0;
                        }

            if (flag_set == 1) {
                yellow_time = number_settime;
                flag_set = 0;
                retime();
            }
            break;

        default:
            break;
    }
}

void retime() {
    if (red_time == yellow_time + green_time) {
        vertical_state = GREEN_LIGHT;
        vertical_counter = green_time;
        horizontal_state = RED_LIGHT;
        horizontal_counter = red_time;
    } else {
    	renew_all();
    }
}

void renew_all() {
    portBuffer[0] = GPIOB;
    portBuffer[1] = GPIOB;
    portBuffer[2] = GPIOB;
    pinBuffer[0] = GPIO_PIN_1;
    pinBuffer[1] = GPIO_PIN_2;
    pinBuffer[2] = GPIO_PIN_3;
    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    	button[i] = RELEASED;
    	postState[i]=RELEASED;
    	preState[i]=RELEASED;
    	currentState[i]=RELEASED;
    	buttonState[i] = RELEASED;
        buttonCounter[i] = 0;
    }
    mode = 0; //mode1
    number_settime = 0;
    red_time = RED_LIGHT;
    green_time = GREEN_LIGHT;
    yellow_time = YELLOW_LIGHT;
    retime();
    reset();
    flag_set = 0;
    flag_reset = 0;
    flag_settime_mode = 0;
}

void reset() {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 |
                      GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 |
                      GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 |
                      GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, RESET);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 |
                      GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13, RESET);
}
