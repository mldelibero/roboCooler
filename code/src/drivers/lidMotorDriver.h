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

    GPIO_TypeDef* m_PWM_GPIOn;
    uint16_t      m_PWM_GPIO_PIN_n;

    GPIO_TypeDef* m_Open_GPIOn;
    uint16_t      m_Open_GPIO_PIN_n;

    GPIO_TypeDef* m_Close_GPIOn;
    uint16_t      m_Close_GPIO_PIN_n;
}; // end - class CLidMotorDriver : CDriver
#endif //#ifndef __LIDMOTOR_DRIVER_H

