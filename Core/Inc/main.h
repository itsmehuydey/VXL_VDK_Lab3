/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define red1_Pin GPIO_PIN_3
#define red1_GPIO_Port GPIOA
#define yellow1_Pin GPIO_PIN_4
#define yellow1_GPIO_Port GPIOA
#define green1_Pin GPIO_PIN_5
#define green1_GPIO_Port GPIOA
#define red2_Pin GPIO_PIN_6
#define red2_GPIO_Port GPIOA
#define yellow2_Pin GPIO_PIN_7
#define yellow2_GPIO_Port GPIOA
#define am10_Pin GPIO_PIN_0
#define am10_GPIO_Port GPIOB
#define am11_Pin GPIO_PIN_1
#define am11_GPIO_Port GPIOB
#define am12_Pin GPIO_PIN_2
#define am12_GPIO_Port GPIOB
#define am32_Pin GPIO_PIN_10
#define am32_GPIO_Port GPIOB
#define am33_Pin GPIO_PIN_11
#define am33_GPIO_Port GPIOB
#define mode0_Pin GPIO_PIN_12
#define mode0_GPIO_Port GPIOB
#define mode1_Pin GPIO_PIN_13
#define mode1_GPIO_Port GPIOB
#define mode2_Pin GPIO_PIN_14
#define mode2_GPIO_Port GPIOB
#define mode3_Pin GPIO_PIN_15
#define mode3_GPIO_Port GPIOB
#define green2_Pin GPIO_PIN_8
#define green2_GPIO_Port GPIOA
#define button0_Pin GPIO_PIN_9
#define button0_GPIO_Port GPIOA
#define button1_Pin GPIO_PIN_10
#define button1_GPIO_Port GPIOA
#define button2_Pin GPIO_PIN_11
#define button2_GPIO_Port GPIOA
#define am00_Pin GPIO_PIN_12
#define am00_GPIO_Port GPIOA
#define am01_Pin GPIO_PIN_13
#define am01_GPIO_Port GPIOA
#define am02_Pin GPIO_PIN_14
#define am02_GPIO_Port GPIOA
#define am03_Pin GPIO_PIN_15
#define am03_GPIO_Port GPIOA
#define am13_Pin GPIO_PIN_3
#define am13_GPIO_Port GPIOB
#define am20_Pin GPIO_PIN_4
#define am20_GPIO_Port GPIOB
#define am21_Pin GPIO_PIN_5
#define am21_GPIO_Port GPIOB
#define am22_Pin GPIO_PIN_6
#define am22_GPIO_Port GPIOB
#define am23_Pin GPIO_PIN_7
#define am23_GPIO_Port GPIOB
#define am30_Pin GPIO_PIN_8
#define am30_GPIO_Port GPIOB
#define am31_Pin GPIO_PIN_9
#define am31_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
