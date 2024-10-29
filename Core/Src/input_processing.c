#include "input_processing.h"
int value_high;
int value_low;
void fsm_input_processing(void){

	display7SEG(mode, GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);

	switch(mode){
	case 1:
		if(timer0_flag) {
			traffic_func();
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
			setTimer0(1000);
		}
		break;
	case 2:
		value_high = value/10;
		value_low = value%10;
		display7SEG(value_high, GPIOA, GPIO_PIN_8,
				GPIO_PIN_9,	GPIO_PIN_10, GPIO_PIN_11);
		display7SEG(value_low, GPIOA, GPIO_PIN_12,
				GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);

		// show red time on 7SEG
		int red_time_high = red_time/10;
		int red_time_low  = red_time%10;
		display7SEG(red_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
				 GPIO_PIN_2, GPIO_PIN_3);
		display7SEG(red_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
				 GPIO_PIN_6, GPIO_PIN_7);

		if(timer1_flag){
			setTimer1(500);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);
		}

		if(flag_set == 1){
			flag_set = 0;
			red_time = value;
		}
		break;

	case 3:
		value_high = value/10;
		value_low = value%10;
		display7SEG(value_high, GPIOA, GPIO_PIN_8,
				GPIO_PIN_9,	GPIO_PIN_10, GPIO_PIN_11);
		display7SEG(value_low, GPIOA, GPIO_PIN_12,
				GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);

		// show green time on 7SEG
		int green_time_high = green_time/10;
		int green_time_low  = green_time%10;
		display7SEG(green_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
				 GPIO_PIN_2, GPIO_PIN_3);
		display7SEG(green_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
				 GPIO_PIN_6, GPIO_PIN_7);

		// blink red led
		if(timer1_flag){
			setTimer1(500);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
		}

		// enter set button
		if(flag_set){
			flag_set = 0;
			green_time = value;
		}
		break;

	case 4:
		value_high = value/10;
		value_low = value%10;
		display7SEG(value_high, GPIOA, GPIO_PIN_8,
				GPIO_PIN_9,	GPIO_PIN_10, GPIO_PIN_11);
		display7SEG(value_low, GPIOA, GPIO_PIN_12,
				GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);

		// show red time on 7SEG
		int yellow_time_high = yellow_time/10;
		int yellow_time_low  = yellow_time%10;
		display7SEG(yellow_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
				 GPIO_PIN_2, GPIO_PIN_3);
		display7SEG(yellow_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
				 GPIO_PIN_6, GPIO_PIN_7);


		if(timer1_flag){
			setTimer1(500);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}

		if(flag_set){
			flag_set = 0;
			yellow_time = value;
		}
		break;
	default:
		break;
	}

}

void setTime(){
	if (red_time == yellow_time + green_time){
		vertical_state = GREEN_LIGHT;
			vertical_counter = green_time;
			horizontal_state = RED_LIGHT;
			horizontal_counter = red_time;
	}
	else preprocess();
}


void preprocess() {
    portBuffer[0] = GPIOB;
    portBuffer[1] = GPIOB;
    portBuffer[2] = GPIOB;
    pinBuffer[0] = GPIO_PIN_1;
    pinBuffer[1] = GPIO_PIN_2;
    pinBuffer[2] = GPIO_PIN_3;

    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
        buttonBuffer[i] = RELEASED;
        thisButton[i] = RELEASED;
        lastButton[i] = RELEASED;
        buttonCounter[i] = 0;
    }

    mode = 1;
    value = 0;
    red_time = 5;
    green_time = 3;
    yellow_time = 2;
    setTime();
    flag_set = 0;
    flag_reset = 0;
}


void resetPin(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|
			GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|
			GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|
			GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, RESET);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|
			GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, RESET);
}
