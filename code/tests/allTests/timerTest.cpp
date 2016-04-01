#include <CppUTest/TestHarness.h>
#include <stdint.h>
#include <stdio.h>
#include "timer.h"

int32_t timer = -1;

TEST_GROUP(TimerTests)
{
	void setup()
	{
		Init_Timers();
		timer = -1;
	}
	void teardown()
	{
	}
};

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

TEST_GROUP(TimerDriverTests)
{
    void setup()
    {
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

/*
This is a list of the time functionality that has yet to be tested here.

-Driver Functions
* Timer is enabled
* ARR is non-zero
* Interrput is enabled

-Use
* Can reset a timer
*/

