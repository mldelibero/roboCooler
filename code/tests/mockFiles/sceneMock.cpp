#include <CppUTestExt/MockSupport.h>
#include "scene.h"
#include "sceneMock.h"
#include "ledObj.h"


CLedObj* Mock_LedArray;
static uint16_t Mock_NumLeds = 10;
static bool SceneHasBeenPlayed = false;

//--- Compile mock version

CScene::CScene(CLedObj* LedArray, uint16_t NumLeds)
{
    SceneHasBeenPlayed = false;
    m_LedArray = LedArray;
    if (NumLeds) return;
}

void CScene::Play(void)
{
    mock().actualCall("CScene::Play");
    SceneHasBeenPlayed = true;
}

bool CScene::Is_StartCriteriaMet(void)
{
    return false;
}

//--- Compile abstract mock version with output control

CSceneMock::CSceneMock() : CScene(Mock_LedArray, Mock_NumLeds)
{
    SceneHasBeenPlayed = false;
}

CSceneMock::~CSceneMock()
{}

void CSceneMock::Play(void)
{
    mock().actualCall("CScene::Play");
    SceneHasBeenPlayed = true;
}

bool CSceneMock::HasBeenPlayed(void)
{
    bool tmp = SceneHasBeenPlayed;
    SceneHasBeenPlayed = false;
    return tmp;
}

