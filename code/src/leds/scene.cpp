#include "scene.h"

CScene::CScene(void)
{
    m_NumBehaviors = 0;
    m_State        = SCENE_INIT;
}

CScene::~CScene(void)
{}

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

void CScene::Update_State(void)
{
    if (m_State == SCENE_INIT && this->Is_StartTriggerMet())
    {
        m_State = SCENE_RUNNING;
    }
}

void CScene::Play(CLedObj* LedArray, uint16_t NumLeds)
{
    this->Update_State();

    if (m_State == SCENE_RUNNING)
    {
        int behavior = 0;
        for (behavior = 0; behavior < m_NumBehaviors; behavior++)
        {
            if (m_Behaviors[behavior]->Get_Status() == BEHAVIOR_ACTIVE)
            {
                m_Behaviors[behavior]->Run();
                break;
            }
        }

        if (LedArray == NULL) return;
        if (NumLeds)          return;

    } // end - if (m_State != SCENE_RUNNING)
} // end - void CScene::Play(CLedObj* LedArray, uint16_t NumLeds)

