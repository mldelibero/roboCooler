#ifndef __LID_MOTOR_H
#define __LID_MOTOR_H
#include <stm32f4xx.h>
#include "component.h"
#include "limitSwitch.h"

typedef enum
{
    LID_ATFULLOPEN,
    LID_ATFULLCLOSE,
    LID_MOVING
} lidMotorState_t;

class CLidMotorComp: public CComponent
{
    public:
        CLidMotorComp(CLimSwComp* OpenedLimSw_p, CLimSwComp* ClosedLimSw_p);

        virtual void Execute(void);
        virtual void Initialize(void);

        lidMotorState_t Get_State(void);
        CLimSwComp* Get_OpenLimSwPtr(void);
        CLimSwComp* Get_CloseLimSwPtr(void);

    private:
        lidMotorState_t m_LidState;
        CLimSwComp* m_OpenedLimSw_p;
        CLimSwComp* m_ClosedLimSw_p;
};

#endif // #ifndef __LID_MOTOR_H

