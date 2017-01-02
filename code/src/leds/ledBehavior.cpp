#include "ledBehavior.h"

CLedBehaviorComp::CLedBehaviorComp()
{
    m_Status = BEHAVIOR_ACTIVE;
}

void CLedBehaviorComp::Execute(void)
{}

void CLedBehaviorComp::Initialize(void)
{}

Led_Behavior_t CLedBehaviorComp::Get_Status(void)
{
    return m_Status;
}

