#include <stm32f4xx_hal_gpio.h>
#include "pushButton.h"
#include "pushButtonDriver.h"
#include "timer.h"
#include "roboCooler.h"

static int32_t timer = 0;
GPIO_PinState pbUpStatus = GPIO_PIN_RESET;
GPIO_PinState pbDnStatus = GPIO_PIN_RESET;

void init_PushButton(void)
{
    init_PushButtonDriver();
    timer = AllocateTimer();
    Reset_PushButtonFilters();
}

void Reset_PushButtonFilters(void)
{
}

GPIO_PinState Get_PbUpStatus(void)
{
    return pbUpStatus;
}

GPIO_PinState Get_PbDnStatus(void)
{
    return pbDnStatus;
}

void Run_PushButtons(void)
{
    IsTimerExpired(timer);

    pbUpStatus = HAL_GPIO_ReadPin(PBUP_GPIOx, PBUP_GPIO_PIN_X);
    pbDnStatus = HAL_GPIO_ReadPin(PBDN_GPIOx, PBDN_GPIO_PIN_X);
}

