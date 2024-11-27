#include <traffic_light.h>

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




