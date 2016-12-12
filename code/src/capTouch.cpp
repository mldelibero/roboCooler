#include "capTouch.h"

CCapTouchComp::CCapTouchComp(CCapTouchDriver* capTouchDriver)
{
    m_CapTouchDriver = capTouchDriver;
    m_TouchDetected  = false;
}

bool CCapTouchComp::Is_TouchDetected(void)
{
    return m_TouchDetected;
}

