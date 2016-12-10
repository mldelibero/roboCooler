#ifndef __CAP_TOUCH_DRIVER_H
#define __CAP_TOUCH_DRIVER_H
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "CDriver.h"

#define CAP_SCL_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_SCL_GPIOx                      GPIOA
#define CAP_SCL_GPIO_Pin_x                 GPIO_Pin_1

#define CAP_SDA_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_SDA_GPIOx                      GPIOA
#define CAP_SDA_GPIO_Pin_x                 GPIO_Pin_1

#define CAP_IRQ_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_IRQ_GPIOx                      GPIOA
#define CAP_IRQ_GPIO_Pin_x                 GPIO_Pin_1

class CCapTouchDriver : CDriver
{
    public:
        CCapTouchDriver(
                uint32_t      SCL_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SCL_GPIOx,
                uint16_t      SCL_GPIO_Pin_x,
                uint32_t      SDA_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SDA_GPIOx,
                uint16_t      SDA_GPIO_Pin_x,
                uint32_t      IRQ_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* IRQ_GPIOx,
                uint16_t      IRQ_GPIO_Pin_x);
        virtual ~CCapTouchDriver(void);

        void Initialize_Hardware(void);
//        virtual BitAction SampleInput(void);

    protected:
                uint32_t      m_SCL_RCC_AHB1Periph_GPIOx;
                GPIO_TypeDef* m_SCL_GPIOx;
                uint16_t      m_SCL_GPIO_Pin_x;
                uint32_t      m_SDA_RCC_AHB1Periph_GPIOx;
                GPIO_TypeDef* m_SDA_GPIOx;
                uint16_t      m_SDA_GPIO_Pin_x;
                uint32_t      m_IRQ_RCC_AHB1Periph_GPIOx;
                GPIO_TypeDef* m_IRQ_GPIOx;
                uint16_t      m_IRQ_GPIO_Pin_x;

}; // end -- class CCapTouchDriver
#endif //#ifndef __CAP_TOUCH_DRIVER_H

