#include <CppUTestExt/MockSupport.h>
#include "ledStrip.h"

#include "capTouchMock.h"
#include "limitSwitchMock.h"
#include "ledStripDriverMock.h"


CLedStripComp::CLedStripComp(CLedStripDriver* LedStripDriver, CSceneComp* FirstScene)
{
    m_LedStripDriver = LedStripDriver;
    m_FirstScene     = FirstScene;
}

void CLedStripComp::Execute(void)
{
    mock().actualCall("CLedStripComp::Execute");
}

void CLedStripComp::Initialize(void)
{
    mock().actualCall("CLedStripComp::Initialize");
}

