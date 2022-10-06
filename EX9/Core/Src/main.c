/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num){
	  if(num == 0){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, SET);
	  }
	  if(num == 1){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, SET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, SET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, SET);
	  }
	  if(num == 2){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, SET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 3){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 4){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, SET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, SET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 5){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, SET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 6){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, SET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 7){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, SET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, SET);
	  }
	  if(num == 8){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 9){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
}
const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};
void update7SEG(int index){
	index = index % MAX_LED;
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[0]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[1]);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[2]);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEG(led_buffer[3]);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		break;
	default:
		index = 0;
		break;
	}
}
void updateClockBuffer(int hour, int minute, int* led_buffer){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}

uint8_t matrix_buffer[8] = {0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x66};
int rowBuffer[8] ={1,1,1,1,1,1,1,1};
int offset = 0;
/*
 * offset is used to move character on Led Matrix
 *
 * */
void updateRowSignal(int index, int offset){
	/*
	 * Extract digit from buffer to feed rowBuffer to control row's signal
	 * Ex: 12345678
	 * rowBuffer[0] = 1
	 * rowBuffer[1] = 2
	 * ...
	 * rowBuffer[7] = 8
	 */
	rowBuffer[0] = ((matrix_buffer[index] >> (7+offset)) & 1);
	rowBuffer[1] = ((matrix_buffer[index] >> (6+offset)) & 1);
	rowBuffer[2] = ((matrix_buffer[index] >> (5+offset)) & 1);
	rowBuffer[3] = ((matrix_buffer[index] >> (4+offset)) & 1);
	rowBuffer[4] = ((matrix_buffer[index] >> (3+offset)) & 1);
	rowBuffer[5] = ((matrix_buffer[index] >> (2+offset)) & 1);
	rowBuffer[6] = ((matrix_buffer[index] >> (1+offset)) & 1);
	rowBuffer[7] = ((matrix_buffer[index] >> (0+offset)) & 1);
}
void displayRowSignal(int* rowBuffer){
	if(rowBuffer[0] == 0){
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
	}
	if(rowBuffer[1] == 0){
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
	}
	if(rowBuffer[2] == 0){
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
	}
	if(rowBuffer[3] == 0){
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
	}
	if(rowBuffer[4] == 0){
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
	}
	if(rowBuffer[5] == 0){
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
	}
	if(rowBuffer[6] == 0){
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
	}
	if(rowBuffer[7] == 0){
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	}
	else{
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
	}
}
void updateLEDMaxtrix(int index, int offset){
	switch(index){
	case 0:
		/*Set signal for row than enable col to display*/
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 1:
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 2:
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 3:
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 4:
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 5:
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 6:
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 7:
		updateRowSignal(index,offset);
		displayRowSignal(rowBuffer);
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	default:
		index = 0;
		break;

	}
}
void turnOffCol(){

	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);

}
int timer0_counter = 0;
int timer0_flag = 0;
int timer1_counter = 0;
int timer1_flag = 0;

int TIMER_CYCLE = 10;
void setTimer0(int duration){
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}
void setTimer1(int duration){
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}
void timerRun(){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter == 0){
			timer0_flag = 1;
		}
	}
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0){
			timer1_flag = 1;
		}
	}
}

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

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int hour = 15, minute = 18, second = 50;
  setTimer0(1000);
  setTimer1(250);
  int indexForMatrix = 0;
  int offsetRemainTime = 3;
  while (1)
  {
	  /*Timer0 for digital clock*/
	  if(timer0_flag == 1){
		  second++;
		  if(second >= 60){
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60){
			  minute = 0;
			  hour++;
		  }
		  if(hour >= 24){
			  hour = 0;
		  }
		  updateClockBuffer(hour, minute, led_buffer);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
		  setTimer0(1000);
	  }
	  /*Timer1 for Led Matrix*/
	  if(timer1_flag == 1){
		  turnOffCol();
		  indexForMatrix++;
		  indexForMatrix = indexForMatrix%8;
		  if(indexForMatrix == 0)
			  offsetRemainTime--;
		  if(offsetRemainTime == 0){
			  offset++;
			  offsetRemainTime = 2;
		  }
		  if(offset >= 8) offset = -7;
		  updateLEDMaxtrix(indexForMatrix, offset);
//		  index_led++;
//		  update7SEG(index_led);
		  setTimer1(10);
	  }


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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_a_Pin|SEG_b_Pin|SEG_c_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_d_Pin|SEG_e_Pin|SEG_f_Pin
                          |SEG_g_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_a_Pin SEG_b_Pin SEG_c_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG_d_Pin SEG_e_Pin SEG_f_Pin
                           SEG_g_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG_a_Pin|SEG_b_Pin|SEG_c_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_d_Pin|SEG_e_Pin|SEG_f_Pin
                          |SEG_g_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
	timerRun();
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

