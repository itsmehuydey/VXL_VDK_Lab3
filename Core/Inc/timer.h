/*
 * timer.h
 *
 *  Created on: Oct 4, 2024
 *      Author: pc
 */
#include "main.h"
#ifndef INC_TIMER_H_
#define INC_TIMER_H_

static  int MAX_COUNTER_IN_MODE_2_3_4 ;
extern int counter_mode_2_3_4 ;
extern int flagMode_RED_BLINK;
extern int flagMode_GREEN_BLINK ;
extern int flagMode_YELLOW_BLINK ;
extern int flagInteruptLED_and_SEG ;

extern int flagRed[2] ;
extern int flagGreen[2] ;
extern int flagYellow[2] ;
extern int TIMER_CYCLE ;

extern int timerLED_counter;
extern int timerLED_flag ;

void setTimer_LED(int duration);

void runTimer_LED() ;

#endif /* INC_TIMER_H_ */
