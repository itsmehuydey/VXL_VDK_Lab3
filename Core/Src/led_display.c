#include "led_display.h"

int vertical_state  = 3;
int vertical_counter = 3;

int horizontal_state = 5;
int horizontal_counter = 5;

int red_time = 5;
int green_time = 3;
int yellow_time= 2;

void display7SEG (int num, GPIO_TypeDef* type, uint16_t A, uint16_t B, uint16_t C, uint16_t D){
	switch(num){
	case -1:
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

void traffic_func(void) {
    vertical_counter--;
    int vertical_counter_high = vertical_counter / 10;
    int vertical_counter_low  = vertical_counter % 10;

    display7SEG(vertical_counter_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
                 GPIO_PIN_2, GPIO_PIN_3);
    display7SEG(vertical_counter_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
                 GPIO_PIN_6, GPIO_PIN_7);
    switch (vertical_state) {
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
}


