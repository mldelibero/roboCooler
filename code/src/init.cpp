#include "init.h"
#include "leds.h"
#include "timer.h"
#include "lidMotor.h"
#include "limitSwitch.h"
#include "limitSwitchDriver.h"

CLedComp leds;

CCapTouchComp* CapTouch_p;

CLimSwDriver* Opened_LimSwDriver = NULL;
CLimSwDriver* Closed_LimSwDriver = NULL;
CLimSwComp Opened_Limit(Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);
CLimSwComp Closed_Limit(Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);

CLidMotorComp lidMotor(&Opened_Limit, &Closed_Limit, CapTouch_p);


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

