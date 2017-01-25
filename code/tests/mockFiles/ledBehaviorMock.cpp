#include <CppUTestExt/MockSupport.h>

#include "ledBehavior.h"
#include "ledBehaviorMock.h"

uint16_t Mock_NumLeds       = 10;
uint16_t Mock_StartingIndex = 0;
uint16_t Mock_EndingIndex   = 9;

//--- Compile mock version
CLedBehaviorComp::CLedBehaviorComp(uint16_t NumLeds, uint16_t StartingIndex, uint16_t EndingIndex)
{
    m_Status = BEHAVIOR_ACTIVE;
    if (NumLeds)       return;
    if (StartingIndex) return;
    if (EndingIndex)   return;
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

void CLedBehaviorComp::Update_Leds(void)
{
}

//--- Compile abstract mock version with output control
CLedBehaviorMock::CLedBehaviorMock() : CLedBehaviorComp(Mock_NumLeds, Mock_StartingIndex, Mock_EndingIndex)
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

