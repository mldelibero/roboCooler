#ifndef _TIMER__H
#define _TIMER__H

#include <stm32f4xx.h>

#define NUM_TIMERS 5

void	 AT(uint32_t** timer);
int32_t  AllocateTimer(void);
uint32_t Get_NumTimersAllocated(void);
uint32_t Init_Timers(void);
bool     IsTimerExpired(int32_t timer);

#endif //#define _TIMER__H
