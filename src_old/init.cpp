#include "init.h"
#include "scheduler.h"
#include "leds.h"
#include "lidMotor.h"
#include "capsense.h"

void init(void)
{
    init_scheduler();
//    init_leds();
   // init_cs();
    init_lidMotor();
}
