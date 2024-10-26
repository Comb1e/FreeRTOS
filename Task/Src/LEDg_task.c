
#include "LEDg_task.h"
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "task.h"

void LEDg_task(void *argument)
{
    HAL_GPIO_TogglePin(GPIOH,GPIO_PIN_11);
    osDelay(1000);
}
