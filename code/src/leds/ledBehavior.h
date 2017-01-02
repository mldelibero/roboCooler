#ifndef __LEDBEHAVIOR_H
#define __LEDBEHAVIOR_H
#include "component.h"
#include "ledBehavior.h"

typedef enum
{
    BEHAVIOR_ACTIVE = 0,
    BEHAVIOR_DONE
} Led_Behavior_t;

class CLedBehaviorComp : public CComponent
{
    public:
        CLedBehaviorComp(void);

        virtual void Execute(void);
        virtual void Initialize(void);

        Led_Behavior_t Get_Status(void);

    protected:
        Led_Behavior_t m_Status;
}; // end - class CLedBehaviorComp : public CComponent
#endif // #ifndef __LEDBEHAVIOR_H

