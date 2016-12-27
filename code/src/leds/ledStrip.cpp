#include "ledStrip.h"
#include "ledStripDriver.h"
#include "component.h"

#include "scene.h"

CLedStripComp::CLedStripComp(CLedStripDriver* LedStripDriver, CSceneComp* FirstScene) : CComponent(0)
{
    m_LedStripDriver = LedStripDriver;
    m_NumScenes      = 0; // Gets increased in the Add_Scene function

    this->Add_Scene(FirstScene);
}

void CLedStripComp::Execute(void)
{
    for (int scene = 0; scene < m_NumScenes; scene++)
    {
        m_Scenes[scene]->Run();
    }

    m_LedStripDriver->Update();
}

void CLedStripComp::Initialize(void)
{
}

uint32_t CLedStripComp::Get_NumberOfScenes(void)
{
    return m_NumScenes;
}

void CLedStripComp::Add_Scene(CSceneComp* NextScene)
{
    if (m_NumScenes < 10)
    {
        m_Scenes[m_NumScenes++] = NextScene;
    }
}

