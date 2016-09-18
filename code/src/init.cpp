#include "init.h"
#include "leds.h"
#include "timer.h"
#include "lidMotor.h"
#include "limitSwitch.h"
#include "limitSwitchDriver.h"

extern CLedComp leds;
extern CLidMotorComp lidMotor;
extern CLimSwComp Opened_Limit;
extern CLimSwComp Closed_Limit;

void init(void)
{
    Init_Timers();

    leds.Initialize();
    lidMotor.Initialize();
    Opened_Limit.Initialize();
    Closed_Limit.Initialize();
    init_LimSwDriver();
}

