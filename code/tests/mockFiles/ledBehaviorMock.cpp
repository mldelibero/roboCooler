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
    return false;
}

void CLedBehaviorComp::Set_NumLeds(uint16_t numLeds)
{
    mock().actualCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",numLeds).onObject(this);
}

void CLedBehaviorComp::Update_Leds(void)
{
}

//--- Compile abstract mock version with output control
CLedBehaviorMock::CLedBehaviorMock() : CLedBehaviorComp()
{
    m_IsBlended = false;
}

void CLedBehaviorMock::Execute(void)
{
    mock().actualCall("CLedBehaviorComp::Execute").withParameter("LedObjArray", m_Target_p).onObject(this);
}

void CLedBehaviorMock::Initialize(void)
{
    mock().actualCall("CLedBehaviorComp::Initialize").onObject(this);
}

bool CLedBehaviorMock::Is_Blended(void)
{
    return m_IsBlended;
}

void CLedBehaviorMock::Force_Blended(bool isBlended)
{
    m_IsBlended = isBlended;
}

void CLedBehaviorMock::Force_State(Led_Behavior_t state)
{
    m_Status = state;
}

