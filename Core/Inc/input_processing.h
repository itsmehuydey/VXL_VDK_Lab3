/*
 * input_processing.h
 *
 *  Created on: Oct 4, 2024
 *      Author: pc
 */
# ifndef INC_INPUT_PROCESSING_H_
 # define INC_INPUT_PROCESSING_H_
#include "global.h"


void fsm_setting();
void setTime();
void preprocess();
void resetPin(void);
void fsm_automatic() ;
void fsm_manual(int light_color);


 # endif /* INC_INPUT_PROCESSING_H_ */
