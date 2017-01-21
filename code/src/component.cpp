// Component Class for roboCooler

#include "component.h"
#include "timer.h"

CComponent::CComponent()
{
    ResetComponent();
}

CComponent::~CComponent()
{
}

CComponent::CComponent(int32_t resetValue)
{
    ResetComponent();
    m_ComponentPeriod_ms = resetValue;
}

void CComponent::ResetComponent(void)
{
    m_TimerIndex      = AllocateTimer();
    m_ComponentPeriod_ms = 100;

    Initialize();
}

void CComponent::Initialize(void)
{
}

void CComponent::Execute(void)
{
}

int32_t CComponent::Get_TimerIndex(void)
{
    return m_TimerIndex;
}

int32_t CComponent::Get_ComponentPeriod_ms(void)
{
    return m_ComponentPeriod_ms;
}

bool CComponent::Run(void)
{
    if (IsTimerExpired(m_TimerIndex))
    {
        Set_TimerValue(m_TimerIndex, m_ComponentPeriod_ms);
        Execute(); // Execute's child specific code
        return true;
    }

    return false;
}

bool CComponent::Run(void* target_p)
{
    m_Target_p = target_p;
    bool tmp = Run();
    m_Target_p = NULL;
    return tmp;
}

void CComponent::Set_ComponentPeriod_ms(int32_t val)
{
    m_ComponentPeriod_ms = val;
}

