#ifndef __CAP_TOUCH_H
#define __CAP_TOUCH_H
#include <stm32f4xx.h>
#include "component.h"
#include "capTouchDriver.h"

class CCapTouchComp: public CComponent
{
    public:
        CCapTouchComp(CCapTouchDriver* capTouchDriver);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool Get_TouchDetected(void);

    private:
        CCapTouchDriver* m_CapTouchDriver;
};

#endif // #ifndef __CAP_TOUCH_H

