#include "init.h"
#include "scheduler.h"

void init(void)
{
    init_scheduler();
    init_leds();
}
