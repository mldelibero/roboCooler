#ifndef __LIDMOTOR_DRIVER_H
#define __LIDMOTOR_DRIVER_H
#include "CDriver.h"

void motorStop(void);
void lidMotor_Open(void);
void lidMotor_Close(void);

class CLidMotorDriver : CDriver
{
    public:
        CLidMotorDriver(void);
        virtual ~CLidMotorDriver(void);

        virtual void Initialize_Hardware(void);

    private:
}; // end - class CLidMotorDriver : CDriver
#endif //#ifndef __LIDMOTOR_DRIVER_H

