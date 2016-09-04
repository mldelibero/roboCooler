#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "leds.h"
#include "ledDriver.h"

CLedComp leds;

CLedComp::CLedComp()
{
    Set_TimerResetValue(25); // 40Hz
}

void CLedComp::Execute(void)
{
    SetLeds(m_LedStates);
}

void CLedComp::Initialize(void)
{
    init_ledDriver();
}

bool CLedComp::Is_InBootMode(void)
{
    return true;
}

uint8_t CLedComp::Get_LedStates(void)
{
    return m_LedStates;
}

void CLedComp::WriteAllLedStates(uint8_t ledStates)
{
    m_LedStates = ledStates;
}

