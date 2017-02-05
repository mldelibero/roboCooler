#include "scene.h"
#include <stdio.h>

CScene::CScene(uint16_t NumLeds)
{
    m_NumBehaviors = 0;
    m_NumLeds      = NumLeds;
    m_State        = SCENE_INIT;
    for (int b = 0; b < MAX_BEHAVIORS; b++)
    {
        m_Behaviors[b] = NULL;
    }
}

CScene::~CScene(void)
{}

bool CScene::Add_Behavior(CLedBehaviorComp* behavior)
{
    if (m_NumBehaviors < MAX_BEHAVIORS)
    {
        m_Behaviors[m_NumBehaviors++] = behavior;
        return true;
    }
    return false;
}

void CScene::Play(CLedObj* LedObjArray)
{
    Update_State();

    if (m_State == SCENE_RUNNING)
    {
        bool firstBehRun = false;

        for (int behavior = 0; behavior < m_NumBehaviors; behavior++)
        {
            if (m_Behaviors[behavior] == NULL) break;

            else if (firstBehRun == true)
            {
                if (m_Behaviors[behavior]->Is_Blended() == true && m_Behaviors[behavior]->Get_Status() == BEHAVIOR_ACTIVE)
                {
                    m_Behaviors[behavior]->Run(LedObjArray);
                }
                else break;
            } // end - else if (firstBehRun == true)

            else if (m_Behaviors[behavior]->Get_Status() == BEHAVIOR_ACTIVE)
            {
                m_Behaviors[behavior]->Run(LedObjArray);
                firstBehRun = true;
            }
        }
    }
} // end - void CScene::Play(CLedObj* LedObjArray)

bool CScene::Is_StartTriggerMet(void)
{
    return false;
}

bool CScene::Is_StopTriggerMet(void)
{
  for (int b = 0; b < m_NumBehaviors; b++)
  {
      if (m_Behaviors[b]->Get_Status() == BEHAVIOR_ACTIVE)
      {
          return false;
      }
  }

  return true; // All behaviors have finished
}

void CScene::Update_State(void)
{
    if (Is_StopTriggerMet() == true) m_State = SCENE_INIT;
    else if (m_State == SCENE_INIT && Is_StartTriggerMet() && Is_StopTriggerMet() == false)
    {
        for (int behavior = 0; behavior < m_NumBehaviors; behavior++)
        {
            m_Behaviors[behavior]->Initialize();
        }

        m_State = SCENE_RUNNING;
    }
}

/*
bool CScene::Is_Running(void)
{
    return true;
    //return false;
}
*/


CSceneOn::CSceneOn(uint16_t NumLeds) : CScene(NumLeds) {}

CSceneOn::~CSceneOn(void) {}

bool CSceneOn::Is_StartTriggerMet(void)
{
    return true;
}

