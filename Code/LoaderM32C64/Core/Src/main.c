/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "e2.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
//  SCB->VTOR = 0x24000000;
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

#define DEVICE_SIZE   512
#define SIZE          256
#define COUNT         2

  uint8_t Buff[SIZE*COUNT];

  for(int i = 0; i < COUNT; i++)
	  memset(&Buff[SIZE*i],  i, SIZE);
  E2_Write(Buff, 0, sizeof(Buff));

  memset(Buff, 0x00, sizeof(Buff));
  E2_Read(Buff, 0, sizeof(Buff));








//  uint8_t BufWR[DEVICE_SIZE];
//  uint8_t BufRD[DEVICE_SIZE];
//
//  memset(BufRD, 0x00, DEVICE_SIZE);
//  E2_Read(BufRD, 0, 268);
//
//  for(int Page = 0, Value = 0; Page < DEVICE_SIZE; Page += PAGE_SIZE, Value++)
//	  memset(&BufWR[Page], Value, PAGE_SIZE);
//  E2_Write(BufWR, 0, DEVICE_SIZE);
////  E2_Write(BufWR, 25, 33);
//
//  memset(BufRD, 0x00, DEVICE_SIZE);
//  E2_Read(BufRD, 0, DEVICE_SIZE);




//  for(int Page = 0; Page < DEVICE_SIZE / PAGE_SIZE; Page++)
//	  memset(&DeviceWR[Page * PAGE_SIZE], Page, PAGE_SIZE);
//  E2_Write(DeviceWR, 0, DEVICE_SIZE);
//
//  memset(DeviceRD, 0x00, DEVICE_SIZE);
//  E2_Read(DeviceRD, 0, DEVICE_SIZE);

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 2;
  RCC_OscInitStruct.PLL.PLLN = 15;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 2950;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0xC0000709;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(E2_WP_GPIO_Port, E2_WP_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : E2_WP_Pin */
  GPIO_InitStruct.Pin = E2_WP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(E2_WP_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

#define MCU_FLASH 	 1
#define NAND_FLASH   2
#define NOR_FLASH    3
#define SRAM         4
#define PSRAM        5
#define PC_CARD      6
#define SPI_FLASH    7
#define I2C_FLASH    8
#define SDRAM        9
#define I2C_EEPROM   10

#define SECTOR_NUM   10   //Maximum number of sector types

struct DeviceSectors
{
	unsigned long SectorNum;    //Number of sectors
	unsigned long SectorSize;   //Sector size in bytes
};

struct StorageInfo
{
	char                 DeviceName[100];       //Device name and description
	unsigned short       DeviceType;            //Device type: ONCHIP, EXT8BIT, EXT16BIT, ...
	unsigned long        DeviceStartAddress;    //Default device start address
	unsigned long        DeviceSize;            //Total size of device
	unsigned long        PageSize;              //Programming page size
	unsigned char        EraseValue;            //Content of erased memory
	struct DeviceSectors sectors[SECTOR_NUM];
};

struct StorageInfo __attribute__((section(".Dev_info"))) StorageInfo =
{
    "M24C32",     //Device name
	I2C_EEPROM,   //Device type
    0x07000000,   //Device start address
    0x00001000,   //Device size 4KB
    0x20,         //Programming page size 32B
    0xFF,         //Initial content of erased memory
    {
		{ 0x00000001, 0x00001000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 }
    }
};

int Init(void)
{
	__disable_irq();
	MX_I2C2_Init();
	__enable_irq();

	return 1;
}

int Write(uint32_t Address, uint32_t Size, uint8_t *Buffer)
{
	if(E2_Write(Buffer, Address - StorageInfo.DeviceStartAddress, Size) == 0)
		return 0;

	return 1;
}

int Read(uint32_t Address, uint32_t Size, uint8_t *Buffer)
{
//	if(E2_Read(Buffer, 0, 16) == 0)
//		return 0;

//	uint8_t Tmp[16];
//	Buffer[0] = E2_Read(Buffer, 0, sizeof(Tmp));

//	uint8_t Tmp[16];
//
//	if(E2_Read(Tmp, 0, sizeof(Tmp)) == 0)
//		return 0;

//	for(int i = 0; i < 4096; i++)
//		Buffer[i] = i;

	if(E2_Read(Buffer, (uint16_t)(Address - StorageInfo.DeviceStartAddress), (uint16_t)Size) == 0)
		return 0;

	return 1;
}

int SectorErase(uint32_t EraseStartAddress ,uint32_t EraseEndAddress)
{
	return 1;
}

int MassErase(void)
{
	return 1;
}

uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal)
{
	return 0;
}

uint64_t Verify(uint32_t MemoryAddr, uint32_t BufferAddr, uint32_t Size, uint32_t Missalignement)
{
	return 0;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
