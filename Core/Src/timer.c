/*
 * timer.c
 *
 *  Created on: Oct 4, 2024
 *      Author: pc
 */

#include "timer.h"
#include "input_reading.h"
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
if( htim -> Instance == TIM2 ) {
button_reading () ;
}
}
