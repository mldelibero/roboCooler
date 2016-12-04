#include <CppUTestExt/MockSupport.h>
#include "limitSwitch.h"
#include "limitSwitchDriverMock.h"
#include "limitSwitchMock.h"

CLimSwDriverMock* Mock_limSwDriver;
uint8_t           Mock_bufferSize;
uint8_t           Mock_filterCutoff;

//--- Compile mock version
CLimSwComp::CLimSwComp(CLimSwDriver* limSwDriver, uint8_t bufferSize, uint8_t filterCutoff)
{
    if (limSwDriver)  return;
    if (bufferSize)   return;
    if (filterCutoff) return;
}

void CLimSwComp::Execute(void)
{}

void CLimSwComp::Initialize(void)
{}

bool CLimSwComp::At_Limit(void)
{
    return true;
}

//--- Compile abstract mock version with output control

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

