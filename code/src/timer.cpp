/* brief
	The timer module will subtract one from an array of timers at a fixed interval inside of an interrupt. It will not lower a timer below zero. It will have no knowlede of the meaning of any of the timers. Resetting the timers will be the responsibility of the client.
*/
#include "timer.h"
#include <stdio.h>
#include <stdint.h>

static uint32_t timers[NUM_TIMERS];
static uint32_t numTimersAllocated = 0;

uint32_t Get_NumTimersAllocated(void)
{
	return numTimersAllocated;
}

uint32_t Init_Timers(void)
{
	numTimersAllocated = 0;
	for (int i = 0; i < NUM_TIMERS; i++)
	{
		timers[i] = 0;
	}
	return numTimersAllocated;
}

void AllocateTimer(uint32_t** timer)
{
	if (numTimersAllocated < NUM_TIMERS) 
	{
		*timer = &timers[numTimersAllocated];
		numTimersAllocated++;
	}
	else *timer = NULL;
} // end - void AllocateTimer(uint32_t** timer)

