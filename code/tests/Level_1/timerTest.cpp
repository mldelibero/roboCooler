/**
 ******************************************************************************
 * @file    timerTest.cpp
 * @author  Michael DeLibero
 * @brief   ....
 ******************************************************************************
 */
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
//#include <stdint.h>
//#include <stdio.h>
//#include "timer.h"
#include "timerDriver.h"

int32_t timer = -1;

TEST_GROUP(TimerTests)
{
    void setup()
    {
        mock().disable();
//        Init_Timers();
        timer = -1;
    }
    void teardown()
    {
    }
};
/*
TEST(TimerTests, NumTimersGreaterThanZero)
{
    CHECK(NUM_TIMERS > 0);
}

TEST(TimerTests, NoTimersAllocatedAfterInit)
{
    CHECK(Get_NumTimersAllocated() == 0);
}

TEST(TimerTests, CanAllocateTimerIfAvailable)
{
    CHECK(AllocateTimer() == 0);
}

TEST(TimerTests, CannotAllocateTimerIfNotAvailable)
{
    for (int t = 0; t < NUM_TIMERS; t++)
    {
        timer = AllocateTimer();
    }
    CHECK(timer != -1);

    // No more timers
    timer = AllocateTimer();
    CHECK(timer == -1);
    CHECK(timer != NUM_TIMERS);
}

TEST(TimerTests, AllocatedTimerInitializedtoZero)
{
    timer = AllocateTimer();
    CHECK(IsTimerExpired(timer) == true);
}

TEST(TimerTests, CanSetTimerToValue)
{
    timer = AllocateTimer();
    Set_TimerValue(timer, 100);
    CHECK(Get_TimerValue(timer) == 100);
}

TEST(TimerTests, TimerNotExpiredIfTimeIsLeft)
{
    timer = AllocateTimer();
    Set_TimerValue(timer, 100);
    CHECK(IsTimerExpired(timer) == false);
}

TEST(TimerTests, TimerExpiredIfNoTimeLeft)
{
    timer = AllocateTimer();
    Set_TimerValue(timer, 0);
    CHECK(IsTimerExpired(timer) == true);
}

TEST(TimerTests, SecondTimerExpiredIfNoTimeLeft)
{
    int timer1, timer2;
    timer1 = AllocateTimer();
    timer2 = AllocateTimer();

    Set_TimerValue(timer1, 100);
    Set_TimerValue(timer2,   0);
    CHECK(IsTimerExpired(timer1) == false);
    CHECK(IsTimerExpired(timer2) == true);
}

TEST(TimerTests, OutOfBoundsTimerIsExpired)
{
    CHECK(IsTimerExpired(timer) == false);
}

TEST(TimerTests, InterruptDecrementsTimer)
{
    timer = AllocateTimer();

    Set_TimerValue(timer, 1);
    CHECK_EQUAL(Get_TimerValue(timer), 1);

    TIMER_IRQHandler();
    CHECK_EQUAL(Get_TimerValue(timer), 0);

    TIMER_IRQHandler();
    CHECK_EQUAL(Get_TimerValue(timer), 0);
}

TEST(TimerTests, InterruptDecrementsAllTimers)
{
    int timer1, timer2;

    timer1 = AllocateTimer();
    timer2 = AllocateTimer();

    Set_TimerValue(timer1, 1);
    Set_TimerValue(timer2, 1);
    CHECK_EQUAL(Get_TimerValue(timer1), 1);
    CHECK_EQUAL(Get_TimerValue(timer2), 1);

    TIMER_IRQHandler();
    CHECK_EQUAL(Get_TimerValue(timer1), 0);
    CHECK_EQUAL(Get_TimerValue(timer2), 0);

    TIMER_IRQHandler();
    CHECK_EQUAL(Get_TimerValue(timer1), 0);
    CHECK_EQUAL(Get_TimerValue(timer2), 0);
}

TEST_GROUP(TimerDriverTests)
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
};

TEST(TimerDriverTests, TestInitCalls)
{
    int callOrder = 1;

    mock().expectOneCall("TIM_DeInit"            ).withCallOrder(callOrder++);
    mock().expectOneCall("RCC_APB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("TIM_TimeBaseInit"      ).withCallOrder(callOrder++);
    mock().expectOneCall("NVIC_Init"             ).withCallOrder(callOrder++);
    mock().expectOneCall("TIM_ITConfig"          ).withCallOrder(callOrder++);
    mock().expectOneCall("TIM_Cmd"               ).withCallOrder(callOrder++);

    Init_Timers();
}

*/
/*
   This is a list of the time functionality that has yet to be tested here.

   -Driver Functions
 * Timer is enabled
 * ARR is non-zero
 * Interrput is enabled

 -Use
 * Can reset a timer
 */

