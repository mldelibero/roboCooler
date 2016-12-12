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
        {
            m_TouchDetected = true;
        }
        else
        {
            m_TouchDetected = false;
        }
    }
}

void CCapTouchComp::Initialize(void)
{
}

bool CCapTouchComp::Is_TouchDetected(void)
{
    return m_TouchDetected;
}

