#include "lidMotorDriver.h"
#include "lidMotor.h"
#include "limitSwitch.h"

CLidMotorComp::CLidMotorComp(CLimSwComp* OpenedLimSw_p, CLimSwComp* ClosedLimSw_p)
{
    m_OpenedLimSw_p = OpenedLimSw_p;
    m_ClosedLimSw_p = ClosedLimSw_p;
}

void CLidMotorComp::Execute(void)
{
    if (m_OpenedLimSw_p->At_Limit() == true) m_LidState = LID_ATFULLOPEN;
    if (m_ClosedLimSw_p->At_Limit() == true) m_LidState = LID_ATFULLCLOSE;
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

