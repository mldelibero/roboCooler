#include "init.h"
#include "timerDriver.h"
#include "timer_Int.h"

void init_Integration(void)
{
    init_TimerDriver();
    init_TimerDriver_Int();
    init_Timer_Int();
}

