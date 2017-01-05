#ifndef __SCENE_H
#define __SCENE_H
#include <stm32f4xx.h>
#include "component.h"
#include "ledObj.h"
#include "ledBehavior.h"

#define MAX_BEHAVIORS   10

typedef enum
{
    SCENE_INIT,
    SCENE_RUNNING,
    SCENE_FINISHED
} Scene_t;

class CScene
{
    public:
        CScene(void);
        virtual ~CScene(void);

        void         Play(CLedObj* LedArray, uint16_t NumLeds);
        bool         Is_Running(void);
        bool         Add_Behavior(CLedBehaviorComp* behavior);

    private:
        void Update_State(void);
        virtual bool Is_StartTriggerMet(void);
        virtual bool Is_StopTriggerMet(void);

        CLedBehaviorComp* m_Behaviors[MAX_BEHAVIORS];
        CLedObj*          m_LedArray;
        uint16_t          m_NumLeds;
        uint8_t           m_NumBehaviors; //< Number of behaviors stored in this scene
        Scene_t           m_State;
};
#endif // #ifndef __SCENE_H

