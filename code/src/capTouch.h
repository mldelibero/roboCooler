#ifndef __CAP_TOUCH_H
#define __CAP_TOUCH_H
#include <stm32f4xx.h>
#include "component.h"

class CCapTouchComp: public CComponent
{
    public:
        CCapTouchComp();

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool Get_TouchDetected(void);

    private:
};

#endif // #ifndef __CAP_TOUCH_H

