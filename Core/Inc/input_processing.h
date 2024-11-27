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
void  retime();
void renew_all();
void reset();
void fsm_automatic() ;
void fsm_manual();
void controlLoop(void);
void fsm_traffic_control(void);

void display_color_time(int color, int time);

void toggle_led(int color);

void adjust_time(int* time);
//void fsm_setting();

void reset_flags();
 # endif /* INC_INPUT_PROCESSING_H_ */
