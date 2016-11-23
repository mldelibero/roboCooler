#include "init.h"
#include "leds.h"
#include "timer.h"
#include "lidMotor.h"
#include "limitSwitch.h"
#include "limitSwitchDriver.h"

extern CLedComp leds;
extern CLidMotorComp lidMotor;
CLimSwDriver* Opened_LimSwDriver = NULL;
CLimSwDriver* Closed_LimSwDriver = NULL;
CLimSwComp Opened_Limit(Opened_LimSwDriver);
CLimSwComp Closed_Limit(Closed_LimSwDriver);

void init(void)
{
    Init_Timers();

    leds.Initialize();
    lidMotor.Initialize();

    if (Opened_LimSwDriver != NULL) delete Opened_LimSwDriver;
    Opened_LimSwDriver = new CLimSwDriver(OPEN_LIMSW_AHB1Periph_GPIOx, OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);

    if (Closed_LimSwDriver != NULL) delete Closed_LimSwDriver;
    Closed_LimSwDriver = new CLimSwDriver(OPEN_LIMSW_AHB1Periph_GPIOx, OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);

    Closed_LimSwDriver->Initialize_Hardware();
    Closed_LimSwDriver->Initialize_Hardware();

    Opened_Limit.Initialize();
    Closed_Limit.Initialize();
}

