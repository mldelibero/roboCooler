#include <CppUTestExt/MockSupport.h>
#include "lidMotorMock.h"
#include "limitSwitchMock.h"
#include "capTouchMock.h"

CLimSwMock    Mock_OpenedLimSw;
CLimSwMock    Mock_ClosedLimSw;
CCapTouchMock Mock_CapTouch;

//--- Compile mock version
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
    mock().actualCall("CLidMotorComp::Execute");
}

//--- Compile abstract mock version with output control
CLidMotorMock::CLidMotorMock() : CLidMotorComp(&Mock_OpenedLimSw, &Mock_ClosedLimSw, &Mock_CapTouch)
{
}

void CLidMotorMock::Initialize(void)
{
    mock().actualCall("CLidMotorComp::Initialize");
}

void CLidMotorMock::Execute(void)
{
    mock().actualCall("CLidMotorComp::Execute");
}

