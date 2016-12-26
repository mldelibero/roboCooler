#include <CppUTestExt/MockSupport.h>
#include "ledStrip.h"

#include "capTouchMock.h"
#include "limitSwitchMock.h"


CLedStripComp::CLedStripComp(CCapTouchComp* CapTouch, CLimSwComp* Closed_LimSw, CLimSwComp* Opened_LimSw)
{
    m_CapTouch     = CapTouch;
    m_Closed_LimSw = Closed_LimSw;
    m_Opened_LimSw = Opened_LimSw;
}

void CLedStripComp::Execute(void)
{
    mock().actualCall("CLedStripComp::Execute");
}

void CLedStripComp::Initialize(void)
{
    mock().actualCall("CLedStripComp::Initialize");
}

