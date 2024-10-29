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

// Các biến lưu trạng thái và bộ đếm của đèn giao thông
extern int vertical_state;         // Trạng thái hiện tại của đèn giao thông dọc (RED, GREEN, YELLOW)
extern int vertical_counter;       // Bộ đếm thời gian cho đèn giao thông dọc

extern int horizontal_state;       // Trạng thái hiện tại của đèn giao thông ngang (RED, GREEN, YELLOW)
extern int horizontal_counter;     // Bộ đếm thời gian cho đèn giao thông ngang

// Biến hiển thị giá trị trên LED 7 đoạn
extern int value_high;             // Giá trị cao (hàng chục) của biến `value`
extern int value_low;              // Giá trị thấp (hàng đơn vị) của biến `value`

// Các biến thời gian cho đèn giao thông
extern int red_time;               // Thời gian cho đèn đỏ
extern int green_time;             // Thời gian cho đèn xanh
extern int yellow_time;            // Thời gian cho đèn vàng
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
extern int flag_reset ;
extern int flag_set;
extern int value;
extern int mode , flag_reset, timer0_counter, timer0_flag, timer1_counter, timer1_flag ;
#endif /* INC_GLOBAL_H_ */
