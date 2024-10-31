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

GPIO_TypeDef *portBuffer[NUM_OF_BUTTONS];
uint16_t pinBuffer[NUM_OF_BUTTONS];

GPIO_PinState thisButton[NUM_OF_BUTTONS];
GPIO_PinState lastButton[NUM_OF_BUTTONS];

extern int buttonCounter[NUM_OF_BUTTONS];
extern int buttonCounter_500ms;

extern int buttonBuffer[NUM_OF_BUTTONS];
extern int value;
extern int mode, flag_set, flag_reset, timer0_counter, timer0_flag, timer1_counter, timer1_flag , KeyReg0[NUM_OF_BUTTONS] , KeyReg1[NUM_OF_BUTTONS], KeyReg2[NUM_OF_BUTTONS] ,
 lastStableButtonState[NUM_OF_BUTTONS];

#endif /* INC_GLOBAL_H_ */
