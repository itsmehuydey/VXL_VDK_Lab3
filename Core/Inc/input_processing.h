/*
 * input_processing.h
 *
 *  Created on: Oct 4, 2024
 *      Author: pc
 */
# ifndef INC_INPUT_PROCESSING_H_
 # define INC_INPUT_PROCESSING_H_
#include "global.h"

void display7SEG (int num, GPIO_TypeDef* type, uint16_t A, uint16_t B, uint16_t C, uint16_t D);

void traffic_func(void);
void resetPin(void);
void fsm_input_processing(void);
void setTime();
void preprocess();


 # endif /* INC_INPUT_PROCESSING_H_ */
