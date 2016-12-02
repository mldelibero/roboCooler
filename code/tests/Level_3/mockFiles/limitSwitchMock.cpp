#include <CppUTestExt/MockSupport.h>
#include "limitSwitch.h"
#include "limitSwitchDriver.h"
#include "limitSwitchMock.h"

CLimSwMock::CLimSwMock(CLimSwDriver* limSwDriver, uint8_t bufferSize, uint8_t filterCutoff) : CLimSwComp(limSwDriver, bufferSize, filterCutoff)
{
    m_LimSwDriver = limSwDriver;
}

void CLimSwMock::Execute(void)
{
}

void CLimSwMock::Initialize(void)
{
}

bool CLimSwMock::At_Limit(void)
{
    mock().actualCall("CLimSwComp::At_Limit");
    return m_MockLimitInput;
}

void CLimSwMock::ForceAtLimit(void)
{
    m_MockLimitInput = true;
}

void CLimSwMock::ForceNotAtLimit(void)
{
    m_MockLimitInput = false;
}

