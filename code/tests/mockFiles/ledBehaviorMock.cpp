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
    m_Status = BEHAVIOR_ACTIVE;
}

Led_Behavior_t CLedBehaviorComp::Get_Status(void)
{
    return m_Status;
}

bool CLedBehaviorComp::Is_Blended(void)
{
    return m_Blended;
}

void CLedBehaviorComp::Set_NumLeds(uint16_t numLeds)
{
    mock().actualCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",numLeds).onObject(this);
}

//--- Compile abstract mock version with output control
CLedBehaviorMock::CLedBehaviorMock() : CLedBehaviorComp()
{
}

void CLedBehaviorMock::Execute(void)
{
    mock().actualCall("CLedBehaviorComp::Execute").withParameter("LedObjArray", m_Target_p).onObject(this);
}

void CLedBehaviorMock::Initialize(void)
{
    mock().actualCall("CLedBehaviorComp::Initialize").onObject(this);
}

void CLedBehaviorMock::Force_Blended(bool isBlended)
{
    m_Blended = isBlended;
}

void CLedBehaviorMock::Force_State(Led_Behavior_t state)
{
    m_Status = state;
}

