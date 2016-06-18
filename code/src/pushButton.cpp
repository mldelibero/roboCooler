#include "pushButton.h"
#include "pushButtonDriver.h"
#include "timer.h"

static int32_t timer = 0;
uint8_t pbUpStatus = 0;
uint8_t pbDnStatus = 0;

void init_PushButton(void)
{
    init_PushButtonDriver();
    timer = AllocateTimer();
    Reset_PushButtonFilters();
}

void Reset_PushButtonFilters(void)
{
}
uint8_t Get_PbUpStatus(void)
{
    return pbUpStatus;
}
uint8_t Get_PbDnStatus(void)
{
    return pbDnStatus;
}

void Run_PushButtons(void)
{
    IsTimerExpired(timer);

    pbUpStatus = GPIO_ReadInputDataBit(PBUP_GPIOx, PBUP_GPIO_PIN_X);
    pbDnStatus = GPIO_ReadInputDataBit(PBDN_GPIOx, PBDN_GPIO_PIN_X);
}

