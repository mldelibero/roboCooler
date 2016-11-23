#include <CppUTestExt/MockSupport.h>
#include "lidMotor.h"
#include "limitSwitchDriver.h"

#define TEST_LIMSW_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
#define TEST_LIMSW_GPIOx                     GPIOA
#define TEST_LIMSW_GPIO_PIN_X                GPIO_Pin_0

CLimSwDriver limSwDriver(TEST_LIMSW_AHB1Periph_GPIOx, TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X);

CLimSwComp    OpenedLimSw(&limSwDriver);
CLimSwComp    ClosedLimSw(&limSwDriver);
CCapTouchComp CapTouch;

CLidMotorComp lidMotor(&OpenedLimSw, &ClosedLimSw, &CapTouch);

CLidMotorComp::CLidMotorComp(CLimSwComp* OpenedLimSw_p, CLimSwComp* ClosedLimSw_p, CCapTouchComp* CapTouch_p)
{
    m_OpenedLimSw_p = OpenedLimSw_p;
    m_ClosedLimSw_p = ClosedLimSw_p;
    m_CapTouch_p    = CapTouch_p;
}

void CLidMotorComp::Initialize(void)
{
    mock().actualCall("CLidMotorComp::Initialize");
}

void CLidMotorComp::Execute(void)
{
}
