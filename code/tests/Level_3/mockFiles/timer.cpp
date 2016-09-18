#include "timer.h"
#include <CppUTestExt/MockSupport.h>


uint32_t Init_Timers(void)
{
    mock().actualCall("Init_Timers");
    return 0;
}

