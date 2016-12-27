#include <CppUTestExt/MockSupport.h>
#include "scene.h"
#include "sceneMock.h"

//--- Compile mock version
CSceneComp::CSceneComp(void)
{
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

CSceneMock::CSceneMock() : CSceneComp()
{
}

void CSceneMock::Execute(void)
{
    mock().actualCall("CSceneComp::Execute");
}

void CSceneMock::Initialize(void)
{
    mock().actualCall("CSceneComp::Initialize");
}

