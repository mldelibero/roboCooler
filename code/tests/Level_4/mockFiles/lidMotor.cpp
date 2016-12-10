#include <CppUTestExt/MockSupport.h>
#include "lidMotor.h"
#include "limitSwitchDriverMock.h"
#include "limitSwitchMock.h"

CLimSwDriverMock limSwDriver();

CLimSwMock    OpenedLimSw;
CLimSwMock    ClosedLimSw;

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
