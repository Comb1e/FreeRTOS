/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LEDg_task.h"
#include "LEDr_task.h"
#include "imu_task.h"
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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for START_LEDR_TASK */
osThreadId_t START_LEDR_TASKHandle;
const osThreadAttr_t START_LEDR_TASK_attributes = {
  .name = "START_LEDR_TASK",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for START_LEDG_TASK */
osThreadId_t START_LEDG_TASKHandle;
const osThreadAttr_t START_LEDG_TASK_attributes = {
  .name = "START_LEDG_TASK",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for START_IMU_TASK */
osThreadId_t START_IMU_TASKHandle;
const osThreadAttr_t START_IMU_TASK_attributes = {
  .name = "START_IMU_TASK",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartLEDrTask(void *argument);
void StartLEDgTask(void *argument);
void StartIMUTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of START_LEDR_TASK */
  START_LEDR_TASKHandle = osThreadNew(StartLEDrTask, NULL, &START_LEDR_TASK_attributes);

  /* creation of START_LEDG_TASK */
  START_LEDG_TASKHandle = osThreadNew(StartLEDgTask, NULL, &START_LEDG_TASK_attributes);

  /* creation of START_IMU_TASK */
  START_IMU_TASKHandle = osThreadNew(StartIMUTask, NULL, &START_IMU_TASK_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartLEDrTask */
/**
* @brief Function implementing the START_LEDR_TASK thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLEDrTask */
void StartLEDrTask(void *argument)
{
  /* USER CODE BEGIN StartLEDrTask */
  /* Infinite loop */
  for(;;)
  {
    LEDr_Task();
    osDelay(500);
  }
  /* USER CODE END StartLEDrTask */
}

/* USER CODE BEGIN Header_StartLEDgTask */
/**
* @brief Function implementing the START_LEDG_TASK thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLEDgTask */
void StartLEDgTask(void *argument)
{
  /* USER CODE BEGIN StartLEDgTask */
  /* Infinite loop */
  for(;;)
  {
    LEDg_Task();
    osDelay(1000);
  }
  /* USER CODE END StartLEDgTask */
}

/* USER CODE BEGIN Header_StartIMUTask */
/**
* @brief Function implementing the START_IMU_TASK thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartIMUTask */
void StartIMUTask(void *argument)
{
  /* USER CODE BEGIN StartIMUTask */
  IMU_Init();
  /* Infinite loop */
  for(;;)
  {
    IMU_Task();
    osDelay(1);
  }
  /* USER CODE END StartIMUTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

