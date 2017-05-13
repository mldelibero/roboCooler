#ifndef __CAP_TOUCH_DRIVER_H
#define __CAP_TOUCH_DRIVER_H
#include <stm32f4xx_hal.h>
#include "CDriver.h"
#include <Driver_I2C.h>

#define PROX_STATUS_BIT 0X1000 // in ELE Touch Status Register -- 1 indicates a touch is detected

class CCapTouchDriver : CDriver
{
    public:
        CCapTouchDriver(GPIO_TypeDef* IRQ_GPIOx, uint16_t IRQ_GPIO_PIN_x, ARM_DRIVER_I2C* Driver_I2Cn);
        virtual ~CCapTouchDriver(void);

        virtual void     Initialize_Hardware(void);
        virtual bool     Is_DataReady(void);
        virtual uint16_t Read(unsigned char address);
        void             Write(unsigned char address, unsigned char data);

    protected:
        ARM_DRIVER_I2C* m_Driver_I2Cn;
        // GPIO
        GPIO_TypeDef* m_SCL_GPIOx;
        uint16_t      m_SCL_GPIO_PIN_x;

        GPIO_TypeDef* m_SDA_GPIOx;
        uint16_t      m_SDA_GPIO_PIN_x;

        GPIO_TypeDef* m_IRQ_GPIOx;
        uint16_t      m_IRQ_GPIO_PIN_x;

        uint8_t       m_GPIO_AF;

        // I2C
        uint32_t      m_APBxPeriph_I2Cx;
        I2C_HandleTypeDef m_I2C_Handle;
}; // end -- class CCapTouchDriver
#endif //#ifndef __CAP_TOUCH_DRIVER_H

