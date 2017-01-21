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
}

Led_Behavior_t CLedBehaviorComp::Get_Status(void)
{
    return m_Status;
}

int32_t CLedBehaviorComp::Get_TimeLeft_ms(void)
{
    return m_RunTime_ms;
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

