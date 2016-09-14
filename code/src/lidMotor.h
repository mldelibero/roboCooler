#ifndef __LID_MOTOR_H
#define __LID_MOTOR_H
#include <stm32f4xx.h>
#include "component.h"

class CLidMotorComp: public CComponent
{
    public:
        CLidMotorComp();

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
};

#endif // #ifndef __LID_MOTOR_H

