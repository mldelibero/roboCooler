#include "init.h"
#include "scheduler.h"
#include "leds.h"

void init(void)
{
    init_scheduler();
    init_leds();
}
