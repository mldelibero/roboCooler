#include <CppUTestExt/MockSupport.h>
#include "capTouch.h"
#include "capTouchMock.h"

//--- Compile mock version

CCapTouchComp::CCapTouchComp(void)
{
}

void CCapTouchComp::Execute(void)
{
    mock().actualCall("CCapTouchComp::Execute");
}

void CCapTouchComp::Initialize(void)
{
    mock().actualCall("CCapTouchComp::Initialize");
}

bool CCapTouchComp::Get_TouchDetected(void)
{
    mock().actualCall("CCapTouchComp::Get_TouchDetected");
    return true;
}


//--- Compile abstract mock version with output control

CCapTouchMock::CCapTouchMock()
{
}

void CCapTouchMock::Execute(void)
{
    mock().actualCall("CCapTouchComp::Execute");
}

void CCapTouchMock::Initialize(void)
{
    mock().actualCall("CCapTouchComp::Initialize");
}

bool CCapTouchMock::Get_TouchDetected(void)
{
    mock().actualCall("CCapTouchComp::Get_TouchDetected");
    return m_MockTouchDetected;
}

void CCapTouchMock::ForceTouchDetected(void)
{
    m_MockTouchDetected = true;
}

void CCapTouchMock::ForceTouchNotDetected(void)
{
    m_MockTouchDetected = false;
}

