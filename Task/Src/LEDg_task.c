
#include "LEDg_task.h"
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "task.h"

void LEDg_Task()
{
    HAL_GPIO_TogglePin(GPIOH,GPIO_PIN_11);
}
