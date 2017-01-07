#include <CppUTestExt/MockSupport.h>
#include "scene.h"
#include "sceneMock.h"
#include "ledObj.h"

static bool SceneHasBeenPlayed = false;

//--- Compile mock version

CScene::CScene(void)
{
    SceneHasBeenPlayed = false;
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

void CScene::Play(CLedObj* LedArray)
{
    mock().actualCall("CScene::Play").withParameter("LedArray", LedArray).onObject(this);
    SceneHasBeenPlayed = true;
}

void CScene::Set_NumLeds(uint16_t numLeds)
{
    mock().actualCall("CScene::Set_NumLeds").onObject(this);;
    if (numLeds) return;
}
//--- Compile abstract mock version with output control

CSceneMock::CSceneMock() : CScene()
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

