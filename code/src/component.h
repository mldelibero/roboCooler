#ifndef __COMPONENT_H
#define __COMPONENT_H
#include <stm32f4xx.h>

class CComponent
{
    public:
        CComponent();
        CComponent(int32_t resetValue);

        int32_t Get_TimerIndex(void);
        int32_t Get_TimerResetValue(void);
        void    ResetComponent(void);
        bool    Run(void);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        int32_t m_TimerIndex;
        int32_t m_TimerResetValue;

    protected:
        void Set_TimerResetValue(int32_t val);
};
#endif //#ifndef __COMPONENT_H

