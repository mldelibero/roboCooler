#include <CppUTestExt/MockSupport.h>
#include "leds.h"

void Init_Timers(void)
{
}

CLedComp::CLedComp()
{
}

void CLedComp::Initialize(void)
{
    mock().actualCall("CLedComp::Initialize");
}

void CLedComp::Execute(void)
{
}
