#ifndef __ROBOCOOLER_H
#define __ROBOCOOLER_H
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_gpio_ex.h"


// Limit Switch Driver ---------------------------
// PE6
#define OPEN_LIMSW_GPIOx                     GPIOE
#define OPEN_LIMSW_GPIO_PIN_X                GPIO_PIN_6

// PE4
#define CLOSE_LIMSW_GPIOx                    GPIOE
#define CLOSE_LIMSW_GPIO_PIN_X               GPIO_PIN_5


// Led Strip Driver ------------------------------
#define LED_DMA_AHBxPeriphClockCmd   RCC_AHB1PeriphClockCmd
#define LED_AHBxPeriph_DMAx          RCC_AHB1Periph_DMA1
#define USARTx_TX_DMA_CHANNEL        DMA_Channel_4
#define USARTx_TX_DMA_STREAM         DMA2_Stream6
#define USARTx_TX_DMA_FLAG_TCIF      DMA_FLAG_TCIF6

// PA2
#define LED_AHB1Periph_GPIOX         RCC_AHB1Periph_GPIOA
#define LED_GPIOX                    GPIOA
#define LED_GPIO_AF                  GPIO_AF7_USART2
#define LED_GPIO_PIN_N               GPIO_PIN_2

#define LED_APBNPeriph_USARTN        RCC_APB1Periph_USART2
#define LED_USARTN                   USART2


// Cap Touch Driver ------------------------------
#define CAP_SCL_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_SCL_GPIOx                      GPIOA
#define CAP_SCL_GPIO_PIN_x                 GPIO_PIN_1

#define CAP_SDA_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_SDA_GPIOx                      GPIOA
#define CAP_SDA_GPIO_PIN_x                 GPIO_PIN_1

#define CAP_IRQ_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define CAP_IRQ_GPIOx                      GPIOA
#define CAP_IRQ_GPIO_PIN_x                 GPIO_PIN_1

#define CAP_GPIO_AF                        GPIO_AF4_I2C1
#define CAP_APBxPeriph_I2Cx                RCC_APB1Periph_I2C1
#define CAP_I2Cx                           I2C1


// Push Button Driver ----------------------------
// PE15
#define PBUP_CLK_ENABLE               __HAL_RCC_GPIOE_CLK_ENABLE
#define PBUP_GPIOx                    GPIOE
#define PBUP_GPIO_PIN_X               GPIO_PIN_15

// PD11
#define PBDN_CLK_ENABLE               __HAL_RCC_GPIOD_CLK_ENABLE
#define PBDN_GPIOx                    GPIOD
#define PBDN_GPIO_PIN_X               GPIO_PIN_11

#endif // #ifndef __ROBOCOOLER_H

