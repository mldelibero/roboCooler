#ifndef __SCENE_H
#define __SCENE_H
#include <stm32f4xx.h>
#include "component.h"
#include "ledObj.h"

class CScene
{
    public:
        CScene(void);
        virtual ~CScene(void);

        void Play(CLedObj* LedArray, uint16_t NumLeds);
        virtual bool Is_StartCriteriaMet(void);

    private:
        CLedObj* m_LedArray;
        uint16_t m_NumLeds;
};
#endif // #ifndef __SCENE_H

