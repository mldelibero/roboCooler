#ifndef __LIMIT_SWITCH_H
#define __LIMIT_SWITCH_H
#include <stm32f4xx.h>
#include "component.h"

class CLimSwComp: public CComponent
{
    public:
        CLimSwComp();

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool At_Limit(void);

    private:
};

#endif // #ifndef __LIMIT_SWITCH_H

