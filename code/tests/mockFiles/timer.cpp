#include <CppUTestExt/MockSupport.h>
#include "timer.h"

uint32_t Init_Timers(void)
{
    mock().actualCall("Init_Timers");
    return 0;
}

