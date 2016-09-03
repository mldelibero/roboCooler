#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "leds.h"
#include "ledDriver.h"

CLedComp leds;

CLedComp::CLedComp()
{}

void CLedComp::Initialize(void)
{
    init_ledDriver();
}

