// Component Class for roboCooler

#include "component.h"
#include "timer.h"

CComponent::CComponent()
{
    ResetComponent();
}

CComponent::CComponent(int32_t resetValue)
{
    ResetComponent();
    m_TimerResetValue = resetValue;
}

void CComponent::ResetComponent(void)
{
    m_TimerIndex      = AllocateTimer();
    m_TimerResetValue = 100;

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

int32_t CComponent::Get_TimerResetValue(void)
{
    return m_TimerResetValue;
}

bool CComponent::Run(void)
{
    if (IsTimerExpired(m_TimerIndex))
    {
        Set_TimerValue(m_TimerIndex, m_TimerResetValue);
        Execute(); // Execute's child specific code
        return true;
    }

    return false;
}
