#ifndef __LIDMOTOR_DRIVER_H
#define __LIDMOTOR_DRIVER_H
#include "CDriver.h"

class CLidMotorDriver : CDriver
{
    public:
        CLidMotorDriver(void);
        virtual ~CLidMotorDriver(void);

        virtual void Initialize_Hardware(void);
        void Close(void);
        void Open(void);
        void Stop(void);

    private:
}; // end - class CLidMotorDriver : CDriver
#endif //#ifndef __LIDMOTOR_DRIVER_H

