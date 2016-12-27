#include <CppUTestExt/MockSupport.h>
#include "timer.h"

static uint32_t numTimersAllocated = 0;

uint32_t Init_Timers(void)
{
    mock().actualCall("Init_Timers");
    numTimersAllocated = 0;
    return 0;
}

uint32_t Get_NumTimersAllocated(void)
{
    return numTimersAllocated;
}

int32_t AllocateTimer(void)
{
    return ++numTimersAllocated;
}

