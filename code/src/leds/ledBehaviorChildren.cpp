#include "ledBehavior.h"
#include "ledBehaviorChildren.h"
#include "ledObj.h"

CLedBeh_Solid::CLedBeh_Solid(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex, CLedObj LedObj) : CLedBehaviorComp(NumLeds, FirstIndex, LastIndex)
{
    m_LedObj = LedObj;
}

void CLedBeh_Solid::Update_Leds(void)
{
    for (uint16_t led = 0; led < m_NumLeds; led++)
    {
        Set_Led(led, m_LedObj);
    }
}

// -- Moving LED band tests -----------------------------------------------
CLedBeh_MovingBand::CLedBeh_MovingBand(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex, CLedObj LedObj) : CLedBehaviorComp(NumLeds, FirstIndex, LastIndex)
{
    m_LedObj    = LedObj;
    m_LedOffset = 0;
}

void CLedBeh_MovingBand::Update_Leds(void)
{
    for (uint16_t led = 0; led < m_NumLeds; led++)
    {
        Set_Led(led, m_LedObj);
    }


    if (++m_FirstLedIndex == m_NumLeds)
    {
        m_FirstLedIndex = 0;
        m_IndicesWrap = false;
    }

    if (++m_LastLedIndex == m_NumLeds)
    {
        m_LastLedIndex = 0;
        m_IndicesWrap = true;
    }
}

