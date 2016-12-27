#include <CppUTestExt/MockSupport.h>
#include "ledStrip.h"

#include "capTouchMock.h"
#include "limitSwitchMock.h"
#include "ledStripDriverMock.h"


CLedStripComp::CLedStripComp::CLedStripComp(CLedStripDriver* LedStripDriver, CScene* FirstScene)
{
    if (LedStripDriver) return;
    m_Scenes[0] = FirstScene;
}

void CLedStripComp::Execute(void)
{
    mock().actualCall("CLedStripComp::Execute");
}

void CLedStripComp::Initialize(void)
{
    mock().actualCall("CLedStripComp::Initialize");
}

uint32_t CLedStripComp::Get_NumberOfScenes(void)
{
    mock().actualCall("CLedStripComp::Get_NumberOfScenes");
    return 0;
}

void CLedStripComp::Add_Scene(CScene* NextScene)
{
    m_Scenes[0] = NextScene;
    mock().actualCall("CLedStripComp::Add_Scene");
}

