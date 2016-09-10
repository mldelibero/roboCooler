#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "leds.h"
#include "ledDriver.h"

CLedComp leds;

CLedComp::CLedComp()
{
    m_LedTimerReset = 25;
    Set_TimerResetValue(25); // 40Hz

    m_BootLedStates = 0;
    m_BootPeriod = 500 / m_LedTimerReset; // 500ms -- Count every execution
    m_NumRunsInBoot = 0;
    m_TotalRunsInBoot = m_BootPeriod * 9;
}

void CLedComp::Execute(void)
{
    if (Is_InBootMode())
    {
         if (m_NumRunsInBoot++ % m_BootPeriod == 0)
         {
             if (m_NumRunsInBoot / m_BootPeriod == 8)
             {
                 m_BootLedStates = 0;
             }
             else
             {
                 m_BootLedStates = uint8_t((m_BootLedStates << 1) + 1);
             }
         }

         SetLeds(m_BootLedStates);
    }

    else SetLeds(m_LedStates);
}

void CLedComp::Initialize(void)
{
    init_ledDriver();
}

void CLedComp::BypassBootSequence(void)
{
    m_NumRunsInBoot = m_TotalRunsInBoot; // Ends the boot sequence
}

bool CLedComp::Is_InBootMode(void)
{
    if (m_NumRunsInBoot >= m_TotalRunsInBoot) return false;
    else return true;
}

uint8_t CLedComp::Get_BootLedStates(void)
{
    return m_BootLedStates;
}

int32_t CLedComp::Get_BootPeriod(void)
{
    return m_BootPeriod;
}

uint8_t CLedComp::Get_LedStates(void)
{
    return m_LedStates;
}

int32_t CLedComp::Get_TotalRunsInBoot(void)
{
    return m_TotalRunsInBoot;
}

void CLedComp::WriteAllLedStates(uint8_t ledStates)
{
    m_LedStates = ledStates;
}

