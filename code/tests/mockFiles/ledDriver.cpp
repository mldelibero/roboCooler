#include <CppUTestExt/MockSupport.h>
#include "ledDriver.h"

void init_ledDriver(void)
{
    mock().actualCall("init_ledDriver");
}

void SetLeds(uint8_t ledValues)
{
    mock().actualCall("SetLeds")
    .withParameter("ledValues", ledValues);
}
