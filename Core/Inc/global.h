#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "input_reading.h"
#include "led_display.h"
#include "input_processing.h"

#define RED_LIGHT    5
#define GREEN_LIGHT  3
#define YELLOW_LIGHT 2


extern int vertical_state;
extern int vertical_counter;

extern int horizontal_state;
extern int horizontal_counter;


extern int value_high;
extern int value_low;


extern int red_time;
extern int green_time;
extern int yellow_time;
extern int vertical_state;
extern int vertical_counter;

extern int horizontal_state;
extern int horizontal_counter;

#define TIMER_CYCLE 10
#define NUM_OF_BUTTONS 3
#define RELEASED 1
#define PRESSED 0
#define HOLDED 100
#define INCREASE 2
#define COUNT_500MS 500
#define COUNT_1S 1000
#define DEBOUNCE_THRESHOLD 3
#define NORMAL_STATE 0
GPIO_TypeDef *portBuffer[NUM_OF_BUTTONS];
uint16_t pinBuffer[NUM_OF_BUTTONS];

extern int buttonCounter[NUM_OF_BUTTONS];
extern int postState[NUM_OF_BUTTONS];//2 //000
extern int preState[NUM_OF_BUTTONS];//0 //000
extern int currentState[NUM_OF_BUTTONS];//1
extern int button[NUM_OF_BUTTONS];
extern int buttonState[NUM_OF_BUTTONS];
extern int number_settime;
extern int mode, flag_set,flag_change, flag_settime_mode, flag_reset, timer0_counter, timer0_flag, timer1_counter, timer1_flag ,
 lastStableButtonState[NUM_OF_BUTTONS];
extern int KeyReg0[NUM_OF_BUTTONS], KeyReg1[NUM_OF_BUTTONS],
 KeyReg2[NUM_OF_BUTTONS],
 KeyReg3[NUM_OF_BUTTONS];
#endif /* INC_GLOBAL_H_ */
