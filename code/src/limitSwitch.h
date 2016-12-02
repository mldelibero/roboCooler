#ifndef __LIMIT_SWITCH_H
#define __LIMIT_SWITCH_H
#include <stm32f4xx.h>
#include "component.h"
#include "limitSwitchDriver.h"

#define LIM_SW_BUFFER_SIZE      10
#define LIM_SW_BUFFER_CUTOFF    7

class CLimSwComp: public CComponent
{
    public:
        CLimSwComp(CLimSwDriver* limSwDriver, uint8_t bufferSize, uint8_t filterCutoff);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool At_Limit(void);

    private:
        CLimSwDriver* m_LimSwDriver;
        void Filter_Input(uint8_t input);

        int8_t m_FilteredInput;
        uint8_t m_BufferSize;
        uint8_t m_FilterCutoff;
};

#endif // #ifndef __LIMIT_SWITCH_H

