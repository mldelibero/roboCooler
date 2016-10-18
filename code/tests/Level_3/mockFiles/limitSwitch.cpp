#include <CppUTestExt/MockSupport.h>
#include "limitSwitch.h"
#include "limitSwitchDriver.h"
#include "limitSwitchMock.h"


CLimSwComp::CLimSwComp(void)
{
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
