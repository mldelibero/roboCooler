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
    SCENE_RUNNING
} Scene_t;

class CScene
{
    public:
        CScene(uint16_t NumLeds);
        virtual ~CScene(void);

        void         Play(CLedObj* LedObjArray);
//        bool         Is_Running(void);
        bool         Add_Behavior(CLedBehaviorComp* behavior);

    private:
        void Update_State(void);
        virtual bool Is_StartTriggerMet(void);

        uint16_t          m_NumLeds;
        Scene_t           m_State;

    protected:
        virtual bool Is_StopTriggerMet(void);

        CLedBehaviorComp* m_Behaviors[MAX_BEHAVIORS];
        uint8_t           m_NumBehaviors; //< Number of behaviors stored in this scene
};

class CSceneOn : public CScene
{
    public:
        CSceneOn(uint16_t NumLeds);
        virtual ~CSceneOn(void);

    private:
        virtual bool Is_StartTriggerMet(void);
};
#endif // #ifndef __SCENE_H

