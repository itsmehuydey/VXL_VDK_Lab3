#include "input_reading.h"

int value_high;
int value_low;

int vertical_state  = 3;
int vertical_counter = 3;

int horizontal_state = 5;
int horizontal_counter = 5;

int red_time = 5;
int green_time = 3;
int yellow_time= 2;

int flag_1s = 0, flag_500ms = 0;
GPIO_TypeDef *portBuffer[NUM_OF_BUTTONS];
uint16_t pinBuffer[NUM_OF_BUTTONS];

GPIO_PinState thisButton[NUM_OF_BUTTONS];
GPIO_PinState lastButton[NUM_OF_BUTTONS];

int buttonCounter[NUM_OF_BUTTONS];
int buttonCounter_500ms = 0;

int buttonBuffer[NUM_OF_BUTTONS];
int flag_reset = 0;
int flag_set = 0;
int value = 0;
int mode = 0;



void set_portBuffer(void){
	portBuffer[0] = GPIOB;
	portBuffer[1] = GPIOB;
	portBuffer[2] = GPIOB;
}
void set_pinBuffer(void){
	pinBuffer[0] = GPIO_PIN_1;
	pinBuffer[1] = GPIO_PIN_2;
	pinBuffer[2] = GPIO_PIN_3;
}
void readButton_preprocess(void){
	set_portBuffer();
	set_pinBuffer();

	for(int i=0; i<NUM_OF_BUTTONS; i++){
		buttonBuffer[i] = RELEASED;
		thisButton[i] = RELEASED;
		lastButton[i] = RELEASED;

		buttonCounter[i] = 0;
	}
}




int getButton(int index){
	if(index >= NUM_OF_BUTTONS) return -1;
	else return buttonBuffer[index];
}



void display7SEG (int num, GPIO_TypeDef* type, uint16_t A, uint16_t B, uint16_t C, uint16_t D){
	switch(num){
	case -1: // turn off seg led
		HAL_GPIO_WritePin(type, D|C|B|A, SET);
		break;
	case 0:
		HAL_GPIO_WritePin(type, D|C|B|A, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(type, D|C|B, RESET);
		HAL_GPIO_WritePin(type, A, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(type, D|C|A, RESET);
		HAL_GPIO_WritePin(type, B, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(type, D|C, RESET);
		HAL_GPIO_WritePin(type, B|A, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(type, D|B|A, RESET);
		HAL_GPIO_WritePin(type, C, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(type, D|B, RESET);
		HAL_GPIO_WritePin(type, C|A, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(type, D|A, RESET);
		HAL_GPIO_WritePin(type, B|C, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(type, D, RESET);
		HAL_GPIO_WritePin(type, C|B|A, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(type, C|B|A, RESET);
		HAL_GPIO_WritePin(type, D, SET);
		break;
	case 9:
		HAL_GPIO_WritePin(type, C|B, RESET);
		HAL_GPIO_WritePin(type, D|A, SET);
		break;
	default:
		HAL_GPIO_WritePin(type, D|C|B|A, SET);
		break;
	}
}

void traffic_func(void){
	vertical_counter--;
	int vertical_counter_high = vertical_counter / 10;
	int vertical_counter_low  = vertical_counter % 10;
	switch(vertical_state){
	case RED_LIGHT:
		display7SEG(vertical_counter_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
				 GPIO_PIN_2, GPIO_PIN_3);
		display7SEG(vertical_counter_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
				 GPIO_PIN_6, GPIO_PIN_7);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_10, SET);

		if(vertical_counter <= 0) {
			vertical_counter = green_time;
			vertical_state = GREEN_LIGHT;
		}
		break;

	case GREEN_LIGHT:
		display7SEG(vertical_counter_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
				 GPIO_PIN_2, GPIO_PIN_3);
		display7SEG(vertical_counter_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
				 GPIO_PIN_6, GPIO_PIN_7);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_10, SET);

		if(vertical_counter <= 0) {
			vertical_counter = yellow_time;
			vertical_state = YELLOW_LIGHT;
		}
		break;

	case YELLOW_LIGHT:
		display7SEG(vertical_counter_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
				 GPIO_PIN_2, GPIO_PIN_3);
		display7SEG(vertical_counter_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
				 GPIO_PIN_6, GPIO_PIN_7);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9, SET);

		if(vertical_counter <= 0) {
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
	switch(horizontal_state){
		case RED_LIGHT:
			display7SEG(horizontal_counter_high, GPIOA, GPIO_PIN_8,
					GPIO_PIN_9,	GPIO_PIN_10, GPIO_PIN_11);
			display7SEG(horizontal_counter_low, GPIOA, GPIO_PIN_12,
					GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13, SET);

			if(horizontal_counter <= 0) {
				horizontal_counter = green_time;
				horizontal_state = GREEN_LIGHT;
			}
			break;

		case GREEN_LIGHT:
			display7SEG(horizontal_counter_high, GPIOA, GPIO_PIN_8,
					GPIO_PIN_9,	GPIO_PIN_10, GPIO_PIN_11);
			display7SEG(horizontal_counter_low, GPIOA, GPIO_PIN_12,
					GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_13, SET);

			if(horizontal_counter <= 0) {
				horizontal_counter = yellow_time;
				horizontal_state = YELLOW_LIGHT;
			}
			break;

		case YELLOW_LIGHT:
			display7SEG(horizontal_counter_high, GPIOA, GPIO_PIN_8,
					GPIO_PIN_9,	GPIO_PIN_10, GPIO_PIN_11);
			display7SEG(horizontal_counter_low, GPIOA, GPIO_PIN_12,
					GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_12, SET);

			if(horizontal_counter <= 0) {
				horizontal_counter = red_time;
				horizontal_state = RED_LIGHT;
			}
			break;

		default:
			break;
		}
}


void resetPin(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|
			GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|
			GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|
			GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, SET);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|
			GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, SET);
}


void readButton(void) {
    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
        lastButton[i] = thisButton[i];
        thisButton[i] = HAL_GPIO_ReadPin(portBuffer[i], pinBuffer[i]);

        if (thisButton[i] == lastButton[i]) {  // Đảm bảo không bị nhiễu do debounce
            switch (buttonBuffer[i]) {
                case RELEASED:
                    buttonBuffer[i] = thisButton[i];
                    break;

                case PRESSED:
                    if (thisButton[i] == PRESSED) {
                        if (i == 0 && buttonCounter[0] == 0) {
                            flag_reset = 1;
                            value = 0;
                            mode++;
                        } else if (i == 1 && buttonCounter[1] == 0) {  // Button 2
                            value++;
                            if (value > 10) value = 1;
                        } else if (i == 2 && buttonCounter[2] == 0) flag_set = 1;

                        if (buttonCounter[i] <= 50) {
                        	buttonCounter[i]++;
                        }
                        else {
                        	buttonCounter[i] = 0;
                        	//value++;
                            break;
                        }

                    } else {
                        buttonCounter[i] = 0;
                        buttonBuffer[i] = RELEASED;
                    }
                    break;

                default:
                    break;
            }
        }
    }
}


//void button_reading(void) {
//    for (char i = 0; i < N0_OF_BUTTONS; i++) {
//        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
//        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
//
//        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
//            buttonBuffer[i] = debounceButtonBuffer1[i];
//
//        if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
//            if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
//                counterForButtonPress1s[i]++;
//            } else {
//                flagForButtonPress1s[i] = 1;
//                // todo
//            }
//        } else {
//            counterForButtonPress1s[i] = 0;
//            flagForButtonPress1s[i] = 0;
//        }
//    }
//}

int value_high;
int value_low;
void fsm_input_processing(void){

	display7SEG(mode, GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);

	switch(mode){
	case 1:
		if(flag_1s) {
			traffic_func();
			flag_1s = 0;
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

		if(flag_500ms){
			flag_500ms = 0;
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
		if(flag_500ms){
			flag_500ms = 0;
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


		if(flag_500ms){
			flag_500ms = 0;
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
	vertical_state = GREEN_LIGHT;
	vertical_counter = green_time;
	horizontal_state = RED_LIGHT;
	horizontal_counter = red_time;
}

void preprocess(){
	mode = 1;
	value = 0;
	red_time = 5;
	green_time = 3;
	yellow_time = 2;
	setTime();
	flag_set = 0;
	flag_1s = 0;
	flag_500ms = 0;
	flag_reset = 0;
	readButton_preprocess();
}

