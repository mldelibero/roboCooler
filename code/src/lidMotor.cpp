#include "lidMotorDriver.h"
#include "lidMotor.h"
#include "limitSwitch.h"

CLidMotorComp::CLidMotorComp(CCapTouchComp* CapTouch_p, CLimSwComp* ClosedLimSw_p, CLimSwComp* OpenedLimSw_p)
{
    m_CapTouch_p    = CapTouch_p;
    m_ClosedLimSw_p = ClosedLimSw_p;
    m_OpenedLimSw_p = OpenedLimSw_p;
}

void CLidMotorComp::Execute(void)
{
    m_LidState = LID_MOVING;

    // Update from Limit Switches
    if (m_OpenedLimSw_p->At_Limit() == true) m_LidState = LID_ATFULLOPEN;
    if (m_ClosedLimSw_p->At_Limit() == true) m_LidState = LID_ATFULLCLOSE;

    if (m_LidState != LID_MOVING) motorStop();

    // Update from Capacitive touch sensor
    if (m_CapTouch_p->Is_TouchDetected() == true)
    {
        if      (m_LidState == LID_ATFULLCLOSE) lidMotor_Open();
        else if (m_LidState == LID_ATFULLOPEN ) lidMotor_Close();
    }
}

void CLidMotorComp::Initialize(void)
{
    init_lidMotorDriver();
}

lidMotorState_t CLidMotorComp::Get_State(void)
{
    return m_LidState;
}

CLimSwComp* CLidMotorComp::Get_OpenLimSwPtr(void)
{
    return m_OpenedLimSw_p;
}

CLimSwComp* CLidMotorComp::Get_CloseLimSwPtr(void)
{
    return m_ClosedLimSw_p;
}

CCapTouchComp* CLidMotorComp::Get_CapSensePtr(void)
{
    return m_CapTouch_p;
}

