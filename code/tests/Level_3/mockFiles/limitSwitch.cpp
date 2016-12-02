#include <CppUTestExt/MockSupport.h>
#include "limitSwitch.h"
#include "limitSwitchDriver.h"
#include "limitSwitchMock.h"


CLimSwComp::CLimSwComp(CLimSwDriver* limSwDriver, uint8_t bufferSize, uint8_t filterCutoff)
{
    m_LimSwDriver  = limSwDriver;
    m_BufferSize   = bufferSize;
    m_FilterCutoff = filterCutoff;
}

void CLimSwComp::Execute(void)
{
}

void CLimSwComp::Initialize(void)
{
    mock().actualCall("CLimSwComp::Initialize");
}

bool CLimSwComp::At_Limit(void)
{
    return false;
}
