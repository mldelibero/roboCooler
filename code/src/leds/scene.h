#ifndef __SCENE_H
#define __SCENE_H
#include <stm32f4xx.h>
#include "component.h"
#include "ledObj.h"

class CSceneComp: public CComponent
{
    public:
        CSceneComp(CLedObj* LedArray, uint16_t NumLeds);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        CLedObj* m_LedArray;
        uint16_t m_NumLeds;
};
#endif // #ifndef __SCENE_H

