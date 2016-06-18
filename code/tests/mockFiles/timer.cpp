#include <CppUTestExt/MockSupport.h>

int32_t mock_timerValue = 0;

int32_t AllocateTimer(void)
{
    mock().actualCall("AllocateTimer");
    return 1;
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
    mock().actualCall("Set_TimerValue").withParameter("timerValue", timerValue);
    mock_timerValue = timerValue;

    if (timer)      return;
}

