#include <CppUTest/TestHarness.h>
#include <stdint.h>
#include <stdio.h>
#include "timer.h"

int32_t timer = -1;

TEST_GROUP(TimeTests)
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

TEST(TimeTests, NumTimersGreaterThanZero)
{
	CHECK(NUM_TIMERS > 0);
}

TEST(TimeTests, NoTimersAllocatedAfterInit)
{
	CHECK(Get_NumTimersAllocated() == 0);	
}

TEST(TimeTests, CanAllocateTimerIfAvailable)
{
	CHECK(AllocateTimer() == 0);
}

TEST(TimeTests, CannotAllocateTimerIfNotAvailable)
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

TEST(TimeTests, AllocatedTimerInitializedtoZero)
{
	timer = AllocateTimer();
	CHECK(IsTimerExpired(timer) == true);
}

TEST(TimeTests, CanSetTimerToValue)
{
	timer = AllocateTimer();
	Set_TimerValue(timer, 100);
	CHECK(Get_TimerValue(timer) == 100);
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

