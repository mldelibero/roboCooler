#ifndef __CAP_TOUCH_DRIVER_H
#define __CAP_TOUCH_DRIVER_H
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_i2c.h>
#include <stm32f4xx_hal_rcc.h>
#include "CDriver.h"

#define PROX_STATUS_BIT                    0X1000 // in ELE Touch Status Register -- 1 indicates a touch is detected

class CCapTouchDriver : CDriver
{
    public:
        CCapTouchDriver(
                GPIO_TypeDef* SCL_GPIOx,
                uint16_t      SCL_GPIO_PIN_x,

                GPIO_TypeDef* SDA_GPIOx,
                uint16_t      SDA_GPIO_PIN_x,

                GPIO_TypeDef* IRQ_GPIOx,
                uint16_t      IRQ_GPIO_PIN_x,

                uint8_t       GPIO_AF,
                uint32_t      m_APBxPeriph_I2Cx,
                I2C_TypeDef*  m_I2Cx);

        virtual ~CCapTouchDriver(void);

        virtual void     Initialize_Hardware(void);
        virtual bool     Is_DataReady(void);
        virtual uint16_t Read(unsigned char address);
        void             Write(unsigned char address, unsigned char data);

    protected:
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

