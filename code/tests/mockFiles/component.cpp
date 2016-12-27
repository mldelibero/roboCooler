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

int32_t CComponent::Get_TimerResetValue(void)
{
    return m_TimerResetValue;
}

void CComponent::Set_TimerResetValue(int32_t val)
{
    if (val) return;
}

