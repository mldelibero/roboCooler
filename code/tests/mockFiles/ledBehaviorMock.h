#ifndef __LEDBEHAVIORMOCK_H
#define __LEDBEHAVIORMOCK_H
#include "ledBehavior.h"

class CLedBehaviorMock : public CLedBehaviorComp
{
    public:
        CLedBehaviorMock();

        virtual void Execute(void);
        virtual void Initialize(void);

        void Force_State(Led_Behavior_t state);
};
#endif // #ifndef __LEDBEHAVIORMOCK_H

