#ifndef _STM32F4XX__H
#define _STM32F4XX__H

#include <stdint.h>

#define TIM_OutputState_Enable             ((uint16_t)0x0001)

typedef struct
{
} TIM_TypeDef;

typedef enum IRQn
{
  TIM4_IRQn                   = 30     /*!< TIM4 global Interrupt                                             */
} IRQn_Type;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

typedef struct
{
   uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
   uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
   uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
   uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
   uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
   uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
   uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
   uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
   uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
   uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
   uint16_t pinStates; // used to mock setting and getting pin values
} GPIO_TypeDef;

extern uint32_t     SystemCoreClock;
extern TIM_TypeDef* TIM4;
extern GPIO_TypeDef* GPIOA;
extern GPIO_TypeDef* GPIOB;
extern GPIO_TypeDef* GPIOC;
extern GPIO_TypeDef* GPIOD;
extern GPIO_TypeDef* GPIOE;

#endif /* ifndef _STM32F4XX__H */
