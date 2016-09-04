#ifndef __LEDS_H
#define __LEDS_H
#include <stm32f4xx.h>
#include "component.h"

#define LED_TIMER_RESET     30 //ms

class CLedComp: public CComponent
{
    public:
        CLedComp();

        uint8_t Get_LedStates    (void);
        bool    Is_InBootMode    (void);
        void    SetAllStates     (uint8_t ledStates);
        void    WriteAllLedStates(uint8_t ledStates);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        uint8_t m_LedStates;
};

#endif // #ifndef __LEDS_H

