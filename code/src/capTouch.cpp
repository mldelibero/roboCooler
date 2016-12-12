#include "capTouch.h"

CCapTouchComp::CCapTouchComp(CCapTouchDriver* capTouchDriver)
{
    m_CapTouchDriver = capTouchDriver;
    m_TouchDetected  = false;
}

void CCapTouchComp::Execute(void)
{
    if (m_CapTouchDriver->Is_DataReady())
    {
        if ((m_CapTouchDriver->ReadFromDevice() & PROX_STATUS_BIT) != 0)
        { // This variable is cleared only after it has been polled
            m_TouchDetected = true;
        }
    }
}

void CCapTouchComp::Initialize(void)
{
}

bool CCapTouchComp::Is_TouchDetected(void)
{
    if (m_TouchDetected == true)
    {
        m_TouchDetected = false;
        return true;
    }
    else
    {
        return false;
    }
}

