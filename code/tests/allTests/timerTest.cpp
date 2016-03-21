#include <CppUTest/TestHarness.h>
#include <stdint.h>
#include <stdio.h>
#include "timer.h"

uint32_t* timer_p = NULL;

TEST_GROUP(TimeTests)
{
	void setup()
	{
		Init_Timers();
		timer_p = NULL;
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
	AllocateTimer(&timer_p);
	CHECK(timer_p != NULL);
}

TEST(TimeTests, CannotAllocateTimerIfNotAvailable)
{
	for (int t = 0; t < NUM_TIMERS; t++)
	{
		AllocateTimer(&timer_p);
	}
	CHECK(timer_p != NULL);

	// No more timers
	AllocateTimer(&timer_p);
	CHECK(timer_p == NULL);
}

TEST(TimeTests, AllocatedTimerInitializedtoZero)
{
	AllocateTimer(&timer_p);
	CHECK(*timer_p == 0);
}

/*
This is a list of the time functionality that has yet to be tested here.

-Driver Functions
* Timer is enabled
* ARR is non-zero
* Interrput is enabled

-Use
* Can poll if a particular timer is expired
* Can reset a timer

*/

