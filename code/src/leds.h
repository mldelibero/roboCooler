#ifndef __LEDS_H
#define __LEDS_H
#include <stm32f4xx.h>
#include "component.h"

#define NUM_LEDS            8

class CLedComp: public CComponent
{
    public:
        CLedComp();

        void    BypassBootSequence(void);
        uint8_t Get_BootLedStates(void);
        int32_t Get_BootPeriod   (void);
        uint8_t Get_LedStates    (void);
        int32_t Get_TotalRunsInBoot(void);
        bool    Is_InBootMode    (void);
        void    WriteAllLedStates(uint8_t ledStates);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        uint8_t m_BootLedStates;
        int32_t m_BootPeriod;
        uint8_t m_LedStates;
        int32_t m_LedTimerReset;
        int32_t m_NumRunsInBoot;
        int32_t m_TotalRunsInBoot;
};

#endif // #ifndef __LEDS_H

