#include "init.h"
#include "leds.h"
#include "timer.h"
#include "lidMotor.h"

extern CLedComp leds;
extern CLidMotorComp lidMotor;

void init(void)
{
    leds.Initialize();
    lidMotor.Initialize();
    Init_Timers();
}

