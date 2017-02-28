#ifndef __CDRIVER_H
#define __CDRIVER_H
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_rcc_ex.h"

class CDriver
{
    public:
        CDriver(void);
        virtual ~CDriver(void);
        virtual void Initialize_Hardware(void) = 0;

    protected:
       void  InitializeGPIOClock(GPIO_TypeDef* GPIOx);
}; // end - class CDriver
#endif //#ifndef __CDRIVER_H

