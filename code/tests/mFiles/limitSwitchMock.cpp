#include <CppUTestExt/MockSupport.h>
#include "limitSwitch.h"
#include "limitSwitchDriverMock.h"
#include "limitSwitchMock.h"

CLimSwDriver* Mock_limSwDriver;
uint8_t       Mock_Lo_CutOff;
uint8_t       Mock_Hi_Cutoff;
uint8_t       Mock_bufferSize;

//--- Compile mock version
CLimSwComp::CLimSwComp(CLimSwDriver* limSwDriver, uint8_t Lo_CutOff, uint8_t Hi_Cutoff, uint8_t bufferSize)
{
    if (limSwDriver) return;
    if (Lo_CutOff)   return;
    if (Hi_Cutoff)   return;
    if (bufferSize)  return;
}

void CLimSwComp::Execute(void)
{
    mock().actualCall("CLimSwComp::Execute");
}

void CLimSwComp::Initialize(void)
{
    mock().actualCall("CLimSwComp::Initialize");
}

bool CLimSwComp::At_Limit(void)
{
    return true;
}

//--- Compile abstract mock version with output control

CLimSwMock::CLimSwMock() : CLimSwComp(Mock_limSwDriver, Mock_Lo_CutOff, Mock_Hi_Cutoff, Mock_bufferSize)
{
}

void CLimSwMock::Execute(void)
{
    mock().actualCall("CLimSwComp::Execute");
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

