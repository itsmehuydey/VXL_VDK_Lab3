/*
 * global.h
 *
 *  Created on: Oct 20, 2024
 *      Author: pc
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "input_processing.h"
#include "input_reading.h"
#include "led_display.h"
#include "timer.h"




#define N0_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_SET
#define BUTTON_IS_RELEASED GPIO_PIN_RESET
#define BUTTON_PIN_0 GPIO_PIN_9
#define BUTTON_PIN_1 GPIO_PIN_10
#define BUTTON_PIN_2 GPIO_PIN_11

#define PORTYPE_A GPIOA
#define PORTYPE_B GPIOB

#define PIN_RED_1 GPIO_PIN_3      // PORT A
#define PIN_GREEN_1 GPIO_PIN_4    // PORT A
#define PIN_YELLOW_1 GPIO_PIN_5   // PORT A
#define PIN_RED_2 GPIO_PIN_6      // PORT A
#define PIN_GREEN_2 GPIO_PIN_7    // PORT A
#define PIN_YELLOW_2 GPIO_PIN_8   // PORT A

//BUTTON


// SEGMENT [0]
#define PIN_INP_SEG0_0 GPIO_PIN_12 // PORT A
#define PIN_INP_SEG0_1 GPIO_PIN_13 // PORT A
#define PIN_INP_SEG0_2 GPIO_PIN_14 // PORT A
#define PIN_INP_SEG0_3 GPIO_PIN_15 // PORT A

// SEGMENT [1]
#define PIN_INP_SEG1_0 GPIO_PIN_0  // PORT B
#define PIN_INP_SEG1_1 GPIO_PIN_1  // PORT B
#define PIN_INP_SEG1_2 GPIO_PIN_2  // PORT B
#define PIN_INP_SEG1_3 GPIO_PIN_3  // PORT B

// SEGMENT TOP
#define PIN_INP_SEG2_0 GPIO_PIN_4  // PORT B
#define PIN_INP_SEG2_1 GPIO_PIN_5  // PORT B
#define PIN_INP_SEG2_2 GPIO_PIN_6  // PORT B
#define PIN_INP_SEG2_3 GPIO_PIN_7  // PORT B

// SEGMENT TOP
#define PIN_INP_SEG3_0 GPIO_PIN_8  // PORT B
#define PIN_INP_SEG3_1 GPIO_PIN_9  // PORT B
#define PIN_INP_SEG3_2 GPIO_PIN_10 // PORT B
#define PIN_INP_SEG3_3 GPIO_PIN_11 // PORT B

// SEGMENT MODE
#define PIN_INP_SEG_MODE_0 GPIO_PIN_12 // PORT B
#define PIN_INP_SEG_MODE_1 GPIO_PIN_13 // PORT B
#define PIN_INP_SEG_MODE_2 GPIO_PIN_14 // PORT B
#define PIN_INP_SEG_MODE_3 GPIO_PIN_15 // PORT B

#endif /* INC_GLOBAL_H_ */
