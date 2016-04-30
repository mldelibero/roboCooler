#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "timer_Int.h"
#include "timer_IntTest.h"
#include "timer.h"
#include "timerDriver.h"

int callOrder = -1;

TEST_GROUP(Timer_IntTests)
{
    void setup()
    {
        callOrder = 1;
        mock().clear();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(Timer_IntTests)

TEST(Timer_IntTests, DriverSetup)
{
    mock().expectOneCall("RCC_AHB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_PinAFConfig"      ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit"       ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"             ).withCallOrder(callOrder++);
    mock().expectOneCall("TIM_OC2Init"           ).withCallOrder(callOrder++);

    init_TimerDriver_Int();
}

TEST(Timer_IntTests, TimerSetup)
{
    mock().expectOneCall("RCC_AHB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_PinAFConfig"      ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit"       ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"             ).withCallOrder(callOrder++);

    mock().expectOneCall("AllocateTimer"         ).withCallOrder(callOrder++);
    mock().expectOneCall("Set_TimerValue"        ).withCallOrder(callOrder++).withParameter("timerValue", TIMER_INT_FREQ);

    init_Timer_Int();
}

TEST(Timer_IntTests, Toggle)
{
    mock().expectOneCall("Set_TimerValue"        ).withCallOrder(callOrder++)
        .withParameter("timerValue", 0);
    Set_TimerValue(0, 0); // Sets all timers to be expired

    mock().expectOneCall("IsTimerExpired"        ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_ToggleBits"       ).withCallOrder(callOrder++)
        .withParameter("GPIOx"   , TIMER_INT_GPIOx)
        .withParameter("GPIO_Pin", TIMER_INT_GPIO_PIN_X);

    mock().expectOneCall("Set_TimerValue"        ).withCallOrder(callOrder++)
        .withParameter("timerValue", TIMER_INT_FREQ);

    timer_Int();
} // end - TEST(Timer_IntTests, Toggle)

TEST(Timer_IntTests, NoToggle)
{
    mock().expectOneCall("Set_TimerValue"        ).withCallOrder(callOrder++).withParameter("timerValue", 10);
    Set_TimerValue(0, 10); // Sets all timers to not be expired

    mock().expectOneCall("IsTimerExpired"        ).withCallOrder(callOrder++);

    timer_Int();
} // end - TEST(Timer_IntTests, NoToggle)

