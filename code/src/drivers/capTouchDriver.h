#ifndef __CAP_TOUCH_DRIVER_H
#define __CAP_TOUCH_DRIVER_H
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_i2c.h>
#include <stm32f4xx_rcc.h>
#include "CDriver.h"

#define CAP_SCL_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_SCL_GPIOx                      GPIOA
#define CAP_SCL_GPIO_Pin_x                 GPIO_Pin_1
#define CAP_SCL_GPIO_PinSourcex            GPIO_PinSource1

#define CAP_SDA_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_SDA_GPIOx                      GPIOA
#define CAP_SDA_GPIO_Pin_x                 GPIO_Pin_1
#define CAP_SDA_GPIO_PinSourcex            GPIO_PinSource1

#define CAP_IRQ_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_IRQ_GPIOx                      GPIOA
#define CAP_IRQ_GPIO_Pin_x                 GPIO_Pin_1
#define CAP_IRQ_GPIO_PinSourcex            GPIO_PinSource1

#define CAP_GPIO_AF                        GPIO_AF_I2C1
#define CAP_GPIO_AF                        GPIO_AF_I2C1
#define CAP_GPIO_AF                        GPIO_AF_I2C1
#define CAP_APBxPeriph_I2Cx                RCC_APB1Periph_I2C1
#define CAP_I2Cx                           I2C1

class CCapTouchDriver : CDriver
{
    public:
        CCapTouchDriver(
                uint32_t      SCL_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SCL_GPIOx,
                uint16_t      SCL_GPIO_Pin_x,
                uint16_t      SCL_GPIO_PinSourcex,

                uint32_t      SDA_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SDA_GPIOx,
                uint16_t      SDA_GPIO_Pin_x,
                uint16_t      SDA_GPIO_PinSourcex,

                uint32_t      IRQ_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* IRQ_GPIOx,
                uint16_t      IRQ_GPIO_Pin_x,
                uint16_t      IRQ_GPIO_PinSourcex,

                uint8_t       GPIO_AF,
                uint32_t      m_APBxPeriph_I2Cx,
                I2C_TypeDef*  m_I2Cx);

        virtual ~CCapTouchDriver(void);

        void Initialize_Hardware(void);
        //        virtual BitAction SampleInput(void);

    protected:
        // GPIO
        uint32_t      m_SCL_RCC_AHB1Periph_GPIOx;
        GPIO_TypeDef* m_SCL_GPIOx;
        uint16_t      m_SCL_GPIO_Pin_x;
        uint16_t      m_SCL_GPIO_PinSourcex;

        uint32_t      m_SDA_RCC_AHB1Periph_GPIOx;
        GPIO_TypeDef* m_SDA_GPIOx;
        uint16_t      m_SDA_GPIO_Pin_x;
        uint16_t      m_SDA_GPIO_PinSourcex;

        uint32_t      m_IRQ_RCC_AHB1Periph_GPIOx;
        GPIO_TypeDef* m_IRQ_GPIOx;
        uint16_t      m_IRQ_GPIO_Pin_x;
        uint16_t      m_IRQ_GPIO_PinSourcex;

        uint8_t       m_GPIO_AF;

        // I2C
        uint32_t      m_APBxPeriph_I2Cx;
        I2C_TypeDef*  m_I2Cx;
}; // end -- class CCapTouchDriver
#endif //#ifndef __CAP_TOUCH_DRIVER_H
