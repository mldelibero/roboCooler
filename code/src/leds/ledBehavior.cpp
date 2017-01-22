#include "ledBehavior.h"

CLedBehaviorComp::CLedBehaviorComp()
{
    Initialize();
    m_RunForever = true;
}

CLedBehaviorComp::CLedBehaviorComp(uint32_t runTime_ms)
{
    Initialize();
    m_RunTime_ms = runTime_ms;
    m_RunForever = false;
}

void CLedBehaviorComp::Execute(void)
{
    Update_Leds();

    if (m_RunForever == true);
    else
    {
        m_RunTime_ms -= Get_ComponentPeriod_ms();
        if (m_RunTime_ms <= 0)
        {
            m_Status = BEHAVIOR_DONE;
            m_RunTime_ms = 0;
        }
    }
}

void CLedBehaviorComp::Initialize(void)
{
    m_IsBlended = false;
    m_Status    = BEHAVIOR_ACTIVE;
    Set_ComponentPeriod_ms(BEH_DEF_PER_MS);
    m_RunTime_ms = -1;
    m_NumLeds = 0;
    m_StartingPercentage = 0;
    m_EndingPercentage   = 100;
}

uint16_t CLedBehaviorComp::Get_NumLeds(void)
{
    return m_NumLeds;
}

Led_Behavior_t CLedBehaviorComp::Get_Status(void)
{
    return m_Status;
}

int32_t CLedBehaviorComp::Get_TimeLeft_ms(void)
{
    return m_RunTime_ms;
}

void CLedBehaviorComp::Set_NumLeds(uint16_t numLeds)
{
    m_NumLeds = numLeds;
}

bool CLedBehaviorComp::Is_Blended(void)
{ // If true -- will blend with the previous behavior
    return m_IsBlended;
}

void CLedBehaviorComp::Set_IsBlended(void)
{
    m_IsBlended = true;
}

void CLedBehaviorComp::Clear_IsBlended(void)
{
    m_IsBlended = false;
}

void CLedBehaviorComp::Update_Leds(void)
{ // Shows example of how to use this function
    CLedObj ledObj;

    for (uint16_t led = 0; led < m_NumLeds; led++)
    {
        Set_Led(led, ledObj);
    }
}

void CLedBehaviorComp::Set_Led(uint16_t led, CLedObj LedValue)
{
    if (led < Get_FirstLedIndex() || led > Get_LastLedIndex() || Get_FirstLedIndex() > Get_LastLedIndex()) return;

    CLedObj* LedArray = (CLedObj*)(m_Target_p);
    if (LedArray == NULL) return;

    LedArray[led] = LedValue;
}

uint16_t CLedBehaviorComp::RoundPercentageToIndex(float percentage)
{
    // Round value
    float value = m_NumLeds * percentage / 100;
    uint32_t floor = uint32_t(value);
    uint16_t roundedValue = (value - (float)floor < 0.5f) ? uint16_t(floor) : uint16_t(floor+1);
    return (roundedValue > 0) ? uint16_t(roundedValue - 1) : uint16_t(0);
}

uint16_t CLedBehaviorComp::Get_FirstLedIndex(void)
{
    return RoundPercentageToIndex(m_StartingPercentage);
}

uint16_t CLedBehaviorComp::Get_LastLedIndex(void)
{
    return RoundPercentageToIndex(m_EndingPercentage);
}

void CLedBehaviorComp::Set_StartingPercentage(uint8_t startingPercentage)
{
    m_StartingPercentage = (startingPercentage <= 100) ? startingPercentage : 100;
}

void CLedBehaviorComp::Set_EndingPercentage(uint8_t endingPercentage)
{
    m_EndingPercentage = (endingPercentage <= 100) ? endingPercentage : 100;
}

