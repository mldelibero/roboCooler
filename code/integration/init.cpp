#include "init.h"
#include "timerDriver.h"
#include "timerDriver_Int.h"

void init_Integration(void)
{
    init_TimerDriver();
    init_TimerDriver_Int();
}

