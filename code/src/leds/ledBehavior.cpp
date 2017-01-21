#include "ledBehavior.h"

CLedBehaviorComp::CLedBehaviorComp()
{
    m_IsBlended = false;
    m_Status    = BEHAVIOR_ACTIVE;
}

void CLedBehaviorComp::Execute(void)
{}

void CLedBehaviorComp::Initialize(void)
{
    m_Status = BEHAVIOR_ACTIVE;
}

Led_Behavior_t CLedBehaviorComp::Get_Status(void)
{
    return m_Status;
}

bool CLedBehaviorComp::Is_Blended(void)
{ // If true -- will blend with the previous behavior
    return m_IsBlended;
}

void CLedBehaviorComp::Set_IsBlended(void)
{
    m_IsBlended = true;
}

void CLedBehaviorComp::Clear_IsBlended(void)
{
    m_IsBlended = false;
}

