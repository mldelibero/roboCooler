#ifndef __LIDMOTORMOCK_H
#define __LIDMOTORMOCK_H
#include "lidMotor.h"

class CLidMotorMock : public CLidMotorComp
{
    public:
        CLidMotorMock(void);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
};
#endif //#ifndef __LIDMOTORMOCK_H

