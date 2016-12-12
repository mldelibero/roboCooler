#include "init.h"

#include "capTouchDriver.h"
#include "leds.h"
#include "lidMotor.h"
#include "limitSwitch.h"
#include "limitSwitchDriver.h"
#include "timer.h"

CLedComp leds;

CCapTouchDriver CapTouchDriver(
        CAP_SCL_RCC_AHB1Periph_GPIOx, CAP_SCL_GPIOx, CAP_SCL_GPIO_Pin_x, CAP_SCL_GPIO_PinSourcex,
        CAP_SDA_RCC_AHB1Periph_GPIOx, CAP_SDA_GPIOx, CAP_SDA_GPIO_Pin_x, CAP_SCL_GPIO_PinSourcex,
        CAP_IRQ_RCC_AHB1Periph_GPIOx, CAP_IRQ_GPIOx, CAP_IRQ_GPIO_Pin_x, CAP_SCL_GPIO_PinSourcex,
        CAP_GPIO_AF, CAP_APBxPeriph_I2Cx, CAP_I2Cx);

CCapTouchComp CapTouch(&CapTouchDriver);

CLimSwDriver* Opened_LimSwDriver = NULL;
CLimSwDriver* Closed_LimSwDriver = NULL;
CLimSwComp Opened_Limit(Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);
CLimSwComp Closed_Limit(Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);

CLidMotorComp LidMotor(&Opened_Limit, &Closed_Limit, &CapTouch);


void init(void)
{
    Init_Timers();

    leds.Initialize();
    LidMotor.Initialize();

    CapTouchDriver.Initialize_Hardware();
    CapTouch.Initialize();

    if (Opened_LimSwDriver != NULL) delete Opened_LimSwDriver;
    Opened_LimSwDriver = new CLimSwDriver(OPEN_LIMSW_AHB1Periph_GPIOx, OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);

    if (Closed_LimSwDriver != NULL) delete Closed_LimSwDriver;
    Closed_LimSwDriver = new CLimSwDriver(OPEN_LIMSW_AHB1Periph_GPIOx, OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);

    Closed_LimSwDriver->Initialize_Hardware();
    Closed_LimSwDriver->Initialize_Hardware();

    Opened_Limit.Initialize();
    Closed_Limit.Initialize();
}

