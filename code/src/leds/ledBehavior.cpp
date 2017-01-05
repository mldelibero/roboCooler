#include "ledBehavior.h"

CLedBehaviorComp::CLedBehaviorComp()
{
    m_Status = BEHAVIOR_ACTIVE;
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
{ // Will blend with the previous behavior
    return false;
}
