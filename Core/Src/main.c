/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "common.h"
#include "software_timer.h"
#include "lcd.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
	char data[40];
	uint8_t i = 0;
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

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
  sSoftwareTimer.Enable();
  sLcd.Initialize();
  sLcd.WriteString(0, 0, "Hello World", LCD_ALIGN_LEFT);
  sLcd.WriteString(1, 0, "Align Left", LCD_ALIGN_LEFT);
  HAL_Delay(1000);
  sLcd.WriteString(0, 0, "Align Center", LCD_ALIGN_CENTER);
  sLcd.WriteString(1, 0, "Align Right", LCD_ALIGN_RIGHT);
  HAL_Delay(1000);

  sLcd.ClearDisplay();
  sLcd.WriteString(0, 0, "One By One Keyin", LCD_ALIGN_LEFT);
  sLcd.SetAttribute(1, CURSOR_BLINK_ON);
  sLcd.WriteCharacterTo(1, 0, 'H');
  HAL_Delay(500);
  sLcd.WriteCharacter('o');
  HAL_Delay(500);
  sLcd.WriteCharacter('w');
  HAL_Delay(500);
  sLcd.WriteCharacter(' ');
  HAL_Delay(500);
  sLcd.WriteCharacter('a');
  HAL_Delay(500);
  sLcd.WriteCharacter('r');
  HAL_Delay(500);
  sLcd.WriteCharacter('e');
  HAL_Delay(500);
  sLcd.WriteCharacter(' ');
  HAL_Delay(500);
  sLcd.WriteCharacter('y');
  HAL_Delay(500);
  sLcd.WriteCharacter('o');
  HAL_Delay(500);
  sLcd.WriteCharacter('u');
  HAL_Delay(500);
  sLcd.WriteCharacter(' ');
  HAL_Delay(500);
  sLcd.WriteCharacter('t');
  HAL_Delay(500);
  sLcd.WriteCharacter('o');
  HAL_Delay(500);
  sLcd.WriteCharacter('d');
  HAL_Delay(500);
  sLcd.SetAttribute(1, SHIFT_DISPLAY);
  sLcd.WriteCharacter('o');
  HAL_Delay(500);
  sLcd.WriteCharacter('y');
  HAL_Delay(500);
  sLcd.WriteCharacter('?');
  HAL_Delay(500);
  sLcd.WriteCharacter(' ');
  HAL_Delay(500);
  sLcd.WriteCharacter('I');
  HAL_Delay(500);
  sLcd.WriteCharacter(' ');
  HAL_Delay(500);
  sLcd.WriteCharacter('a');
  HAL_Delay(500);
  sLcd.WriteCharacter('m');
  HAL_Delay(500);
  sLcd.WriteCharacter(' ');
  HAL_Delay(500);
  sLcd.WriteCharacter('f');
  HAL_Delay(500);
  sLcd.WriteCharacter('i');
  HAL_Delay(500);
  sLcd.WriteCharacter('n');
  HAL_Delay(500);
  sLcd.WriteCharacter('e');
  HAL_Delay(500);
  sLcd.WriteCharacter('.');
  HAL_Delay(1000);

  sLcd.ClearDisplay();
  sLcd.SetAttribute(3, CURSOR_ON, CURSOR_BLINK_OFF, NO_SHIFT_DISPLAY);
  sLcd.WriteString(0, 0, "Move cursor", LCD_ALIGN_LEFT);
  sLcd.WriteString(1, 0, "Hello Walrd", LCD_ALIGN_LEFT);
  sLcd.GoTo(1, 11);
  HAL_Delay(500);
  sLcd.ShiftCursorDisplay(SHIFT_CURSOR_LEFT);
  HAL_Delay(500);
  sLcd.ShiftCursorDisplay(SHIFT_CURSOR_LEFT);
  HAL_Delay(500);
  sLcd.ShiftCursorDisplay(SHIFT_CURSOR_LEFT);
  HAL_Delay(500);
  sLcd.ShiftCursorDisplay(SHIFT_CURSOR_LEFT);
  HAL_Delay(500);
  sLcd.WriteCharacter('o');
  HAL_Delay(500);
  sLcd.WriteCharacter('r');
  HAL_Delay(500);
  sLcd.WriteCharacter('l');
  HAL_Delay(1000);

  sLcd.ClearDisplay();
  sLcd.SetAttribute(2, CURSOR_OFF, CURSOR_BLINK_OFF);
  sLcd.WriteString(0, 0, "Shift display left or right.", LCD_ALIGN_LEFT);
  sLcd.WriteString(1, 0, "                   2 line shift together", LCD_ALIGN_LEFT);
  HAL_Delay(500);
  for(i = 0; i < 40; i++)
  {
	  sLcd.ShiftCursorDisplay(SHIFT_DISPLAY_LEFT);
	  HAL_Delay(200);
  }
  for(i = 0; i < 40; i++)
  {
	  sLcd.ShiftCursorDisplay(SHIFT_DISPLAY_RIGHT);
	  HAL_Delay(200);
  }
  HAL_Delay(1000);

  sLcd.ClearDisplay();
  data[0] = CELSIUS_DEGREE_LOGO;
  data[1] = ' ';
  data[2] = BATTERY_LOGO;
  data[3] = ' ';
  data[4] = SIGNAL_LOGO;
  data[5] = ' ';
  data[6] = BULETOOTH_LOGO;
  data[7] = ' ';
  data[8] = SPEAKER_LOGO;
  data[9] = ' ';
  data[10] = CHARGING_LOGO;
  data[11] = ' ';
  data[12] = PLUG_LOGO;
  data[13] = ' ';
  data[14] = USB_LOGO;
  data[15] = ' ';
  data[16] = '\0';
  sLcd.WriteString(0, 0, "Own Logo", LCD_ALIGN_CENTER);
  sLcd.WriteString(1, 2, &data[2], LCD_ALIGN_LEFT);
  sLcd.WriteCharacterTo(1, 0, data[0]);
  HAL_Delay(500);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
