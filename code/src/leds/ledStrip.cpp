#include "ledStrip.h"
#include "ledStripDriver.h"

CLedStripComp::CLedStripComp(CLedStripDriver* LedStripDriver, CSceneComp* FirstScene)
{
    m_LedStripDriver = LedStripDriver;
    m_FirstScene     = FirstScene;
}

void CLedStripComp::Execute(void)
{
}

void CLedStripComp::Initialize(void)
{
}

