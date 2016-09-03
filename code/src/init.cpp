#include "init.h"
#include "leds.h"

extern CLedComp leds;

void init(void)
{
    leds.Initialize();
}

