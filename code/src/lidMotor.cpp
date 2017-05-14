#include "lidMotorDriver.h"
#include "lidMotor.h"
#include "limitSwitch.h"

CLidMotorComp::CLidMotorComp(CLidMotorDriver* LidMotorDriver_p, CCapTouchComp* CapTouch_p, CLimSwComp* ClosedLimSw_p, CLimSwComp* OpenedLimSw_p)
{
    m_CapTouch_p       = CapTouch_p;
    m_ClosedLimSw_p    = ClosedLimSw_p;
    m_OpenedLimSw_p    = OpenedLimSw_p;
    m_LidMotorDriver_p = LidMotorDriver_p;
}

void CLidMotorComp::Execute(void)
{
    m_LidState = LID_MOVING;

    // Update from Limit Switches
    if (m_OpenedLimSw_p->At_Limit() == true) m_LidState = LID_ATFULLOPEN;
    if (m_ClosedLimSw_p->At_Limit() == true) m_LidState = LID_ATFULLCLOSE;

    if (m_LidState != LID_MOVING) m_LidMotorDriver_p->Stop();

    // Update from Capacitive touch sensor
    if (m_CapTouch_p->Is_TouchDetected() == true)
    {
        if      (m_LidState == LID_ATFULLCLOSE) m_LidMotorDriver_p->Open();
        else if (m_LidState == LID_ATFULLOPEN ) m_LidMotorDriver_p->Close();
    }
}

void CLidMotorComp::Initialize(void)
{
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

