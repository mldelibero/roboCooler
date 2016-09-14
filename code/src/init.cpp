#include "init.h"
#include "leds.h"
#include "timer.h"

extern CLedComp leds;

void init(void)
{
    leds.Initialize();
    Init_Timers();
}

