#include "scene.h"
        CLedObj*       m_LedArray;
        Led_Behavior_t m_Status;

CScene::CScene(void)
{
    m_NumBehaviors = 0;
    m_NumLeds      = 0;
    m_State        = SCENE_INIT;
    for (int b = 0; b < MAX_BEHAVIORS; b++)
    {
        m_Behaviors[b] = NULL;
    }
}

CScene::~CScene(void)
{}

bool CScene::Is_Running(void)
{
    return false;
}

bool CScene::Is_StopTriggerMet(void)
{
    return true;
}

bool CScene::Is_StartTriggerMet(void)
{
    return false;
}

bool CScene::Add_Behavior(CLedBehaviorComp* behavior)
{
    if (m_NumBehaviors < MAX_BEHAVIORS)
    {
        m_Behaviors[m_NumBehaviors] = behavior;
        m_Behaviors[m_NumBehaviors++]->Set_NumLeds(m_NumLeds);
        return true;
    }

    return false;
}

void CScene::Set_NumLeds(uint16_t numLeds)
{
    m_NumLeds = numLeds;
    for (int b = 0; b < m_NumBehaviors; b++)
    {
        m_Behaviors[b]->Set_NumLeds(m_NumLeds);
    }
}

void CScene::Update_State(void)
{
    if (m_State == SCENE_INIT && this->Is_StartTriggerMet() && this->Is_StopTriggerMet() == false)
    {
        for (int b = 0; b < MAX_BEHAVIORS; b++)
        { // Reset all behaviors when coming out of init state
            if  (m_Behaviors[b] == NULL) break;
            else m_Behaviors[b]->Initialize();
        }

        m_State = SCENE_RUNNING;
    }

    else if (m_State == SCENE_RUNNING && this->Is_StopTriggerMet())
    {
        m_State = SCENE_FINISHED;
    }
}

void CScene::Play(CLedObj* LedObjArray)
{
    this->Update_State();

    if (m_State == SCENE_RUNNING)
    {
        int behavior = 0;
        for (behavior = 0; behavior < m_NumBehaviors; behavior++)
        {
            if (m_Behaviors[behavior] == NULL) break;
            if (m_Behaviors[behavior]->Get_Status() == BEHAVIOR_ACTIVE)
            {
                m_Behaviors[behavior]->Run(LedObjArray);
                break;
            }
        }

        behavior++;

        for (;behavior < m_NumBehaviors; behavior++)
        { // Blend the rest if necessary
                if (m_Behaviors[behavior]               == NULL  ||
                    m_Behaviors[behavior]->Is_Blended() == false ||
                    m_Behaviors[behavior]->Get_Status() != BEHAVIOR_ACTIVE)
                {
                    break;
                }

                if (m_Behaviors[behavior]->Get_Status() == BEHAVIOR_ACTIVE)
                {
                    m_Behaviors[behavior]->Run(LedObjArray);
                }
       }

        if (LedObjArray == NULL) return;
    } // end - if (m_State != SCENE_RUNNING)
} // end - void CScene::Play(CLedObj* LedObjArray, uint16_t NumLeds)

