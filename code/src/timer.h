#ifndef _TIMER__H
#define _TIMER__H

#include <stm32f4xx.h>

#define NUM_TIMERS 5

void	 AllocateTimer(uint32_t** timer);
uint32_t Get_NumTimersAllocated(void);
uint32_t Init_Timers(void);

#endif //#define _TIMER__H
