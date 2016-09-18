#include <CppUTestExt/MockSupport.h>
#include "leds.h"

volatile CLedComp leds;

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
