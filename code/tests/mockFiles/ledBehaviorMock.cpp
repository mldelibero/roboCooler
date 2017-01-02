#include <CppUTestExt/MockSupport.h>

#include "ledBehavior.h"
#include "ledBehaviorMock.h"

//--- Compile mock version
CLedBehaviorComp::CLedBehaviorComp()
{
    m_Status = BEHAVIOR_ACTIVE;
}

void CLedBehaviorComp::Execute(void)
{
    mock().actualCall("CLedBehaviorComp::Execute").onObject(this);
}

void CLedBehaviorComp::Initialize(void)
{
    mock().actualCall("CLedBehaviorComp::Initialize");
}

Led_Behavior_t CLedBehaviorComp::Get_Status(void)
{
    return m_Status;
}

//--- Compile abstract mock version with output control
CLedBehaviorMock::CLedBehaviorMock() : CLedBehaviorComp()
{
}

void CLedBehaviorMock::Execute(void)
{
    mock().actualCall("CLedBehaviorComp::Execute").onObject(this);
}

void CLedBehaviorMock::Initialize(void)
{
    mock().actualCall("CLedBehaviorComp::Initialize");
}

void CLedBehaviorMock::Force_State(Led_Behavior_t state)
{
    m_Status = state;
}
