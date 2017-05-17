#ifndef __LIDMOTOR_DRIVER_H
#define __LIDMOTOR_DRIVER_H
#include "CDriver.h"

class CHalDriver : CDriver
{
    public:
        CHalDriver(GPIO_TypeDef* GPIOn, uint16_t m_GPIO_PIN_n);
        virtual ~CHalDriver(void);

        virtual void Initialize_Hardware(void);
        GPIO_PinState Is_Triggered(void);

    private:
        GPIO_TypeDef* m_GPIOn;
        uint16_t      m_GPIO_PIN_n;
}; // end - class CHalDriver : CDriver
#endif //#ifndef __LIDMOTOR_DRIVER_H

