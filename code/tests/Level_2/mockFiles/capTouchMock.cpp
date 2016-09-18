#include <CppUTestExt/MockSupport.h>
#include "capTouch.h"
//#include "capTouchDriver.h"
#include "capTouchMock.h"

CCapTouchMock::CCapTouchMock()
{
}

void CCapTouchMock::Execute(void)
{
}

void CCapTouchMock::Initialize(void)
{
}

bool CCapTouchMock::Get_TouchDetected(void)
{
    mock().actualCall("CCapSenseComp::Get_TouchDetected");
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

