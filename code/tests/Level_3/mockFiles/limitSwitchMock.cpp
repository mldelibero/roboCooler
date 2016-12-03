#include <CppUTestExt/MockSupport.h>
#include "limitSwitch.h"
#include "limitSwitchDriverMock.h"
#include "limitSwitchMock.h"

CLimSwDriverMock* Mock_limSwDriver;
uint8_t           Mock_bufferSize;
uint8_t           Mock_filterCutoff;

CLimSwMock::CLimSwMock() : CLimSwComp(Mock_limSwDriver, Mock_bufferSize, Mock_filterCutoff)
{
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

