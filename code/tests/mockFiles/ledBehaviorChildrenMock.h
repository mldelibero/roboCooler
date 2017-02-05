#ifndef __LEDBEHAVIORCHILDRENMOCK_H
#define __LEDBEHAVIORCHILDRENMOCK_H
#include "ledBehaviorChildren.h"
class CLedBeh_SolidMock : public CLedBehaviorComp
{
    public:
        CLedBeh_SolidMock(void);

    private:
        virtual void Update_Leds(void);
};
#endif // #ifdef __LEDBEHAVIORCHILDRENMOCK_H

