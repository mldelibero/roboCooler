#ifndef __COMPONENT_H
#define __COMPONENT_H
#include <stm32f4xx.h>

class CComponent
{
    public:
        CComponent();
        CComponent(int32_t resetValue);

        virtual ~CComponent();

        int32_t Get_ComponentPeriod_ms(void);
        int32_t Get_TimerIndex(void);
        void    ResetComponent(void);
        bool    Run(void);
        bool    Run(void* target_p);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        int32_t m_ComponentPeriod_ms;
        int32_t m_TimerIndex;

    protected:
        void  Set_ComponentPeriod_ms(int32_t val);

        void* m_Target_p;
};
#endif //#ifndef __COMPONENT_H

