#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "timerDriver_Int.h"
#include "timerDriver_IntTest.h"

#include "timer.h"

TEST_GROUP(TimerDriver_IntTests)
{
    void setup()
    {
        mock().clear();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(TimerDriver_IntTests)

TEST(TimerDriver_IntTests, Fail)
{
    int callOrder = 1;

    mock().expectOneCall("RCC_AHB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_PinAFConfig"      ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit"       ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"             ).withCallOrder(callOrder++);
    mock().expectOneCall("TIM_OC2Init"           ).withCallOrder(callOrder++);

    init_TimerDriver_Int();
}

