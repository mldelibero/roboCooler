#ifndef __TIMER_H
#define __TIMER_H

#include <stm32f4xx.h>

#define NUM_TIMERS 5
typedef int Bool;
#define FALSE   0
#define TRUE    1


int32_t  AllocateTimer(void);
uint32_t Get_NumTimersAllocated(void);
uint32_t Init_Timers(void);
Bool     IsTimerExpired(int32_t timer);
void     Set_TimerValue(int32_t timer, int32_t timerValue);
int32_t  Get_TimerValue(int32_t timer);

#endif //#define __TIMER_H
