
#include "LEDr_task.h"
#include "cmsis_os.h"
#include "task.h"
#include "stm32f4xx_hal_gpio.h"

void LEDr_Task()
{
    HAL_GPIO_TogglePin(GPIOH, GPIO_PIN_12);
}
