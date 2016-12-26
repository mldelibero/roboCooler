#ifndef __LID_MOTOR_H
#define __LID_MOTOR_H
#include <stm32f4xx.h>
#include "component.h"
#include "limitSwitch.h"
#include "capTouch.h"

typedef enum
{
    LID_ATFULLOPEN,
    LID_ATFULLCLOSE,
    LID_MOVING
} lidMotorState_t;

class CLidMotorComp: public CComponent
{
    public:
        CLidMotorComp(CCapTouchComp* CapTouch_p, CLimSwComp* ClosedLimSw_p, CLimSwComp* OpenedLimSw_p);

        virtual void Execute(void);
        virtual void Initialize(void);

        lidMotorState_t Get_State(void);
        CLimSwComp*     Get_OpenLimSwPtr(void);
        CLimSwComp*     Get_CloseLimSwPtr(void);
        CCapTouchComp*  Get_CapSensePtr(void);

    private:
        lidMotorState_t m_LidState;
        CLimSwComp* m_OpenedLimSw_p;
        CLimSwComp* m_ClosedLimSw_p;
        CCapTouchComp* m_CapTouch_p;
};

#endif // #ifndef __LID_MOTOR_H

