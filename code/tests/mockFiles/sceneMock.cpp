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

void CScene::Play(CLedObj* LedArray, uint16_t NumLeds)
{
    mock().actualCall("CScene::Play").onObject(this);
    SceneHasBeenPlayed = true;
    if (LedArray == NULL) return;
    if (NumLeds)          return;
}

bool CScene::Is_StartCriteriaMet(void)
{
    return false;
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
    mock().actualCall("CScene::Play").onObject(this);
    SceneHasBeenPlayed = true;
}

bool CSceneMock::HasBeenPlayed(void)
{
    bool tmp = SceneHasBeenPlayed;
    SceneHasBeenPlayed = false;
    return tmp;
}

