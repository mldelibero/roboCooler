#ifndef __LEDS_H
#define __LEDS_H
#include <stm32f4xx.h>
#include "component.h"

#define LED_TIMER_RESET     30 //ms

class CLedComp: public CComponent
{
    public:
        CLedComp();
        virtual void Initialize(void);

    private:
};

#endif // #ifndef __LEDS_H

