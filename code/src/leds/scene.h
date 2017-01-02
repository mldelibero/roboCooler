#ifndef __SCENE_H
#define __SCENE_H
#include <stm32f4xx.h>
#include "component.h"
#include "ledObj.h"
#include "ledBehavior.h"

#define MAX_BEHAVIORS   10

class CScene
{
    public:
        CScene(void);
        virtual ~CScene(void);

        void         Play(CLedObj* LedArray, uint16_t NumLeds);
        virtual bool Is_StartCriteriaMet(void);
        bool         Is_Running(void);
        bool         Is_StartTriggerMet(void);
        bool         Add_Behavior(CLedBehaviorComp* behavior);

    private:
        CLedBehaviorComp* m_Behaviors[MAX_BEHAVIORS];
        CLedObj*          m_LedArray;
        uint16_t          m_NumLeds;
        uint8_t           m_NumBehaviors; //< Number of behaviors stored in this scene
};
#endif // #ifndef __SCENE_H

