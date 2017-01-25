#include <CppUTestExt/MockSupport.h>
#include "scene.h"
#include "sceneMock.h"
#include "ledObj.h"

static bool SceneHasBeenPlayed = false;
uint16_t Mock_NumLeds = 0;

//--- Compile mock version

CScene::CScene(uint16_t NumLeds)
{
    SceneHasBeenPlayed = false;
    if (NumLeds) return;
}

CScene::~CScene(void)
{}

bool CScene::Is_StartTriggerMet(void)
{
    return false;
}

bool CScene::Is_StopTriggerMet(void)
{
    return false;
}

void CScene::Play(CLedObj* LedObjArray)
{
    mock().actualCall("CScene::Play").withParameter("LedObjArray", LedObjArray).onObject(this);
    SceneHasBeenPlayed = true;
}

//--- Compile abstract mock version with output control

CSceneMock::CSceneMock() : CScene(Mock_NumLeds)
{
    SceneHasBeenPlayed = false;
}

CSceneMock::~CSceneMock()
{}

void CSceneMock::Play(void)
{
    SceneHasBeenPlayed = true;
}

bool CSceneMock::HasBeenPlayed(void)
{
    bool tmp = SceneHasBeenPlayed;
    SceneHasBeenPlayed = false;
    return tmp;
}

uint32_t CSceneMock::Get_NumLeds(void)
{
    return 0;
}

