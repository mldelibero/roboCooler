#include <CppUTestExt/MockSupport.h>
#include "capTouch.h"
#include "capTouchMock.h"
#include "capTouchDriverMock.h"

CCapTouchDriverMock MOCK_CapTouchDriver;

//--- Compile mock version


CCapTouchComp::CCapTouchComp(CCapTouchDriver* capTouchDriver)
{
    if (capTouchDriver) return;
}

void CCapTouchComp::Execute(void)
{
    mock().actualCall("CCapTouchComp::Execute");
}

void CCapTouchComp::Initialize(void)
{
    mock().actualCall("CCapTouchComp::Initialize");
}

bool CCapTouchComp::Is_TouchDetected(void)
{
    mock().actualCall("CCapTouchComp::Is_TouchDetected");
    return false;
}


//--- Compile abstract mock version with output control

CCapTouchMock::CCapTouchMock() : CCapTouchComp((CCapTouchDriver*)&MOCK_CapTouchDriver)
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

bool CCapTouchMock::Is_TouchDetected(void)
{
    mock().actualCall("CCapTouchComp::Is_TouchDetected");
    return m_Mock_TouchDetected;
}

void CCapTouchMock::ForceTouchDetected(void)
{
    m_Mock_TouchDetected = true;
}

void CCapTouchMock::ForceTouchNotDetected(void)
{
    m_Mock_TouchDetected = false;
}

