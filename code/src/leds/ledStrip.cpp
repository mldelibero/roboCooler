#include "ledStrip.h"
#include "ledStripDriver.h"

CLedStripComp::CLedStripComp(CLedStripDriver* LedStripDriver,  CCapTouchComp* CapTouch, CLimSwComp* Closed_LimSw, CLimSwComp* Opened_LimSw)
{

    m_LedStripDriver = LedStripDriver;
    m_CapTouch       = CapTouch;
    m_Closed_LimSw   = Closed_LimSw;
    m_Opened_LimSw   = Opened_LimSw;
}

void CLedStripComp::Execute(void)
{
}

void CLedStripComp::Initialize(void)
{
}

