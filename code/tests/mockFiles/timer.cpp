#include <CppUTestExt/MockSupport.h>
#include "timer_mock.h"

static int32_t mock_timerValue = 0;
static int32_t mock_TimerToAllocate = 1;

int32_t AllocateTimer(void)
{
    mock().actualCall("AllocateTimer");
    return mock_TimerToAllocate;
} // end - int32_t AllocateTimer(void)

bool IsTimerExpired(int32_t timer)
{
    mock().actualCall("IsTimerExpired");
    return mock().returnIntValueOrDefault(true);

    if (mock_timerValue == 0) return true;
    else                      return false;
    if (timer) return true;
}

void  Set_TimerValue(int32_t timer, int32_t timerValue)
{
    mock().actualCall("Set_TimerValue")
        .withParameter("timer", timer)
        .withParameter("timerValue", timerValue);
    mock_timerValue = timerValue;
}

void Reset_timerMock(void)
{
    mock_timerValue = 0;
}

void Set_TimerToAllocate(int32_t timer)
{
    mock_TimerToAllocate = timer;
}

