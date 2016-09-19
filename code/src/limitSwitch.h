#ifndef __LIMIT_SWITCH_H
#define __LIMIT_SWITCH_H
#include <stm32f4xx.h>
#include "component.h"

typedef uint8_t (*sampInFun_t)(void);

class CLimSwComp: public CComponent
{
    public:
        CLimSwComp(sampInFun_t sampleIn_fpt);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool At_Limit(void);

    private:
        sampInFun_t SampleInput_fpt;
};

#endif // #ifndef __LIMIT_SWITCH_H

