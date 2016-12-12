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

        virtual bool Is_TouchDetected(void);

    private:
        CCapTouchDriver* m_CapTouchDriver;
        bool m_TouchDetected;
};

#endif // #ifndef __CAP_TOUCH_H

