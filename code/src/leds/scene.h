#ifndef __SCENE_H
#define __SCENE_H
#include <stm32f4xx.h>
#include "component.h"

class CSceneComp: public CComponent
{
    public:
        CSceneComp();

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
};
#endif // #ifndef __SCENE_H

