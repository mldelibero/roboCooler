#ifndef __LIMIT_SWITCH_H
#define __LIMIT_SWITCH_H
#include <stm32f4xx.h>
#include "component.h"
#include "limitSwitchDriver.h"

class CLimSwComp: public CComponent
{
    public:
        CLimSwComp(CLimSwDriver* limSwDriver);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool At_Limit(void);

    private:
        CLimSwDriver* m_LimSwDriver;
};

#endif // #ifndef __LIMIT_SWITCH_H

