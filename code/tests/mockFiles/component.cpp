#include <CppUTestExt/MockSupport.h>
#include "component.h"

CComponent::CComponent()
{}

CComponent::CComponent(int32_t resetValue)
{
    mock().actualCall("CComponent::Constructor").withParameter("resetValue",resetValue);
}

CComponent::~CComponent()
{}

void CComponent::Execute(void)
{}

void CComponent::Initialize(void)
{}

int32_t CComponent::Get_TimerIndex(void)
{
    return 0;
}

bool CComponent::Run(void)
{
    Execute();
    return true;
}

bool CComponent::Run(void* target_p)
{
    m_Target_p = target_p;
    Execute();
    return true;
}

int32_t CComponent::Get_ComponentPeriod_ms(void)
{
    return m_ComponentPeriod_ms;
}

void CComponent::Set_ComponentPeriod_ms(int32_t period)
{

    mock().actualCall("CComponent::Set_ComponentPeriod_ms").withParameter("period",period);
    m_ComponentPeriod_ms = period;
}

