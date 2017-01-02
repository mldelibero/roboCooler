#include "scene.h"

CScene::CScene(void)
{
    m_NumBehaviors = 0;
}

CScene::~CScene(void)
{}

bool CScene::Is_StartCriteriaMet(void)
{
    return false;
}

bool CScene::Is_Running(void)
{
    return false;
}

bool CScene::Is_StartTriggerMet(void)
{
    return false;
}

bool CScene::Add_Behavior(CLedBehaviorComp* behavior)
{
    if (m_NumBehaviors < MAX_BEHAVIORS)
    {
        m_Behaviors[m_NumBehaviors++] = behavior;
        return true;
    }
    return false;
}

void CScene::Play(CLedObj* LedArray, uint16_t NumLeds)
{
    int behavior = 0;
    for (behavior = 0; behavior < MAX_BEHAVIORS; behavior++)
    {
        if (m_Behaviors[behavior]->Get_Status() == BEHAVIOR_ACTIVE) break;
    }

    m_Behaviors[behavior]->Run();

    if (LedArray == NULL) return;
    if (NumLeds)          return;
}

