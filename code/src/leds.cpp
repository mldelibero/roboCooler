#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "leds.h"
#include "ledDriver.h"

CLedComp leds;

CLedComp::CLedComp()
{}

void CLedComp::Execute(void)
{
    SetLeds(m_LedStates);
}

void CLedComp::Initialize(void)
{
    init_ledDriver();
}

uint8_t CLedComp::Get_LedStates(void)
{
    return m_LedStates;
}

void CLedComp::WriteAllLedStates(uint8_t ledStates)
{
    m_LedStates = ledStates;
}

