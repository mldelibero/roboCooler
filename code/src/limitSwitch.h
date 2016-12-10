#ifndef __LIMIT_SWITCH_H
#define __LIMIT_SWITCH_H
#include <stm32f4xx.h>
#include "component.h"
#include "limitSwitchDriver.h"

#define LIM_SW_LO_CUTOFF        3
#define LIM_SW_Hi_CUTOFF        7
#define LIM_SW_BUFFER_SIZE      10

class CLimSwComp: public CComponent
{
    public:
        CLimSwComp(CLimSwDriver* limSwDriver, uint8_t Lo_CutOff, uint8_t Hi_Cutoff, uint8_t bufferSize);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool At_Limit(void);

    private:
        CLimSwDriver* m_LimSwDriver;
        void Filter_Input(uint8_t input);

        int8_t  m_FilteredInput;
        uint8_t m_Lo_Cutoff;
        uint8_t m_Hi_Cutoff;
        uint8_t m_BufferSize;

        bool m_LastOutput;
};

#endif // #ifndef __LIMIT_SWITCH_H

