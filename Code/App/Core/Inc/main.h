/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "cmsis_os2.h"
#include "basic.h"
#include "products.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern UART_HandleTypeDef huart3;
extern I2C_HandleTypeDef  hi2c2;
extern I2C_HandleTypeDef  hi2c5;
extern OSPI_HandleTypeDef hospi1;
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
void WriteCommand(unsigned char cmd);
void WriteData(unsigned char dat);
void Wrt_Reg_3052(unsigned char d1,unsigned char d2);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define E2_WP_Pin GPIO_PIN_3
#define E2_WP_GPIO_Port GPIOE
#define LCD_BL_CTRL_Pin GPIO_PIN_13
#define LCD_BL_CTRL_GPIO_Port GPIOF
#define LCD_RST_Pin GPIO_PIN_6
#define LCD_RST_GPIO_Port GPIOH

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
