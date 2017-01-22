#include "ledBehavior.h"
#include "ledBehaviorChildren.h"
#include "ledObj.h"

CLedBeh_Solid::CLedBeh_Solid(CLedObj ledColor) : CLedBehaviorComp()
{
    m_LedColor = ledColor;
}

CLedBeh_Solid::CLedBeh_Solid(uint32_t runTime_ms) : CLedBehaviorComp(runTime_ms)
{
    m_LedColor.Set_Red_PercentOn  (0);
    m_LedColor.Set_Green_PercentOn(0);
    m_LedColor.Set_Blue_PercentOn (0);
}

void CLedBeh_Solid::Update_Leds(void)
{
    for (uint16_t led = 0; led < m_NumLeds; led++)
    {
        Set_Led(led, m_LedColor);
    }
}

