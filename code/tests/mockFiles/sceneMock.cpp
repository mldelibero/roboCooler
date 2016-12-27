#include <CppUTestExt/MockSupport.h>
#include "scene.h"
#include "sceneMock.h"
#include "ledObj.h"


CLedObj* Mock_LedArray;
static uint16_t Mock_NumLeds = 10;

//--- Compile mock version

CSceneComp::CSceneComp(CLedObj* LedArray, uint16_t NumLeds)
{
    m_LedArray = LedArray;
    if (NumLeds) return;
}

void CSceneComp::Execute(void)
{
    mock().actualCall("CSceneComp::Execute");
}

void CSceneComp::Initialize(void)
{
    mock().actualCall("CSceneComp::Initialize");
}

//--- Compile abstract mock version with output control

CSceneMock::CSceneMock() : CSceneComp(Mock_LedArray, Mock_NumLeds)
{
    m_HasBeenRun = false;
}

void CSceneMock::Execute(void)
{
    mock().actualCall("CSceneComp::Execute");
    m_HasBeenRun = true;
}

void CSceneMock::Initialize(void)
{
    mock().actualCall("CSceneComp::Initialize");
}

bool CSceneMock::HasBeenRun(void)
{
    bool tmp = m_HasBeenRun;
    m_HasBeenRun = false;
    return tmp;
}
