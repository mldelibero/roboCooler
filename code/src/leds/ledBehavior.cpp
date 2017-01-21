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
    CLedObj* LedArray = (CLedObj*)(m_Target_p);
    if (LedArray == NULL) return;

    LedArray[led] = LedValue;
}

