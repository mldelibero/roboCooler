#include <CppUTestExt/MockSupport.h>
#include "lidMotor.h"

CLimSwComp    OpenedLimSw;
CLimSwComp    ClosedLimSw;
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
