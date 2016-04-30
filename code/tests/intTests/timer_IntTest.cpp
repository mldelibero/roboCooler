#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "timer_Int.h"
#include "timer_IntTest.h"

TEST_GROUP(Timer_IntTests)
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
}; // end - TEST_GROUP(Timer_IntTests)

TEST(Timer_IntTests, DriverSetup)
{
    int callOrder = 1;

    mock().expectOneCall("RCC_AHB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_PinAFConfig"      ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit"       ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"             ).withCallOrder(callOrder++);
    mock().expectOneCall("TIM_OC2Init"           ).withCallOrder(callOrder++);

    init_TimerDriver_Int();
}

TEST(Timer_IntTests, TimerSetup)
{
    int callOrder = 1;

    mock().expectOneCall("RCC_AHB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_PinAFConfig"      ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit"       ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"             ).withCallOrder(callOrder++);

    init_Timer_Int();
}

TEST(Timer_IntTests, togglePin)
{
//    timer_Int();
    CHECK(true);
}
