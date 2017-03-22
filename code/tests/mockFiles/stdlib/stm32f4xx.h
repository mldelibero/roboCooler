#ifndef _STM32F4XX__H
#define _STM32F4XX__H

#include <stdint.h>
#include "stm32f407xx.h"

#define TIM_OutputState_Enable             ((uint16_t)0x0001)

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

typedef struct _TIM_TypeDef /// Timer type def
{
    uint16_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
    uint16_t      RESERVED0;   /*!< Reserved, 0x02                                            */
    uint16_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
    uint16_t      RESERVED1;   /*!< Reserved, 0x06                                            */
    uint16_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
    uint16_t      RESERVED2;   /*!< Reserved, 0x0A                                            */
    uint16_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
    uint16_t      RESERVED3;   /*!< Reserved, 0x0E                                            */
    uint16_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
    uint16_t      RESERVED4;   /*!< Reserved, 0x12                                            */
    uint16_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
    uint16_t      RESERVED5;   /*!< Reserved, 0x16                                            */
    uint16_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
    uint16_t      RESERVED6;   /*!< Reserved, 0x1A                                            */
    uint16_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
    uint16_t      RESERVED7;   /*!< Reserved, 0x1E                                            */
    uint16_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
    uint16_t      RESERVED8;   /*!< Reserved, 0x22                                            */
    uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
    uint16_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
    uint16_t      RESERVED9;   /*!< Reserved, 0x2A                                            */
    uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
    uint16_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
    uint16_t      RESERVED10;  /*!< Reserved, 0x32                                            */
    uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
    uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
    uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
    uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
    uint16_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
    uint16_t      RESERVED11;  /*!< Reserved, 0x46                                            */
    uint16_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
    uint16_t      RESERVED12;  /*!< Reserved, 0x4A                                            */
    uint16_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
    uint16_t      RESERVED13;  /*!< Reserved, 0x4E                                            */
    uint16_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
    uint16_t      RESERVED14;  /*!< Reserved, 0x52                                            */
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

typedef struct
{
  uint16_t CR1;        /*!< I2C Control register 1,     Address offset: 0x00 */
  uint16_t      RESERVED0;  /*!< Reserved, 0x02                                   */
  uint16_t CR2;        /*!< I2C Control register 2,     Address offset: 0x04 */
  uint16_t      RESERVED1;  /*!< Reserved, 0x06                                   */
  uint16_t OAR1;       /*!< I2C Own address register 1, Address offset: 0x08 */
  uint16_t      RESERVED2;  /*!< Reserved, 0x0A                                   */
  uint16_t OAR2;       /*!< I2C Own address register 2, Address offset: 0x0C */
  uint16_t      RESERVED3;  /*!< Reserved, 0x0E                                   */
  uint16_t DR;         /*!< I2C Data register,          Address offset: 0x10 */
  uint16_t      RESERVED4;  /*!< Reserved, 0x12                                   */
  uint16_t SR1;        /*!< I2C Status register 1,      Address offset: 0x14 */
  uint16_t      RESERVED5;  /*!< Reserved, 0x16                                   */
  uint16_t SR2;        /*!< I2C Status register 2,      Address offset: 0x18 */
  uint16_t      RESERVED6;  /*!< Reserved, 0x1A                                   */
  uint16_t CCR;        /*!< I2C Clock control register, Address offset: 0x1C */
  uint16_t      RESERVED7;  /*!< Reserved, 0x1E                                   */
  uint16_t TRISE;      /*!< I2C TRISE register,         Address offset: 0x20 */
  uint16_t      RESERVED8;  /*!< Reserved, 0x22                                   */
  uint16_t FLTR;       /*!< I2C FLTR register,          Address offset: 0x24 */
  uint16_t      RESERVED9;  /*!< Reserved, 0x26                                   */
} I2C_TypeDef;

extern GPIO_TypeDef* GPIOA;
extern GPIO_TypeDef* GPIOB;
extern GPIO_TypeDef* GPIOC;
extern GPIO_TypeDef* GPIOD;
extern GPIO_TypeDef* GPIOE;
extern GPIO_TypeDef* GPIOF;
extern GPIO_TypeDef* GPIOG;
extern GPIO_TypeDef* GPIOH;
extern GPIO_TypeDef* GPIOI;

extern I2C_TypeDef*  I2C1;

extern uint32_t     SystemCoreClock;

extern TIM_TypeDef* TIM4;


// DMA
typedef struct _DMA_Stream_TypeDef /// DMA stream type def
{
  uint32_t CR;     /*!< DMA stream x configuration register      */
  uint32_t NDTR;   /*!< DMA stream x number of data register     */
  uint32_t PAR;    /*!< DMA stream x peripheral address register */
  uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
  uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
  uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

extern DMA_Stream_TypeDef* DMA2_Stream6;

typedef struct
{
  uint16_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
  uint16_t      RESERVED0;  /*!< Reserved, 0x02                                                */
  uint16_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
  uint16_t      RESERVED1;  /*!< Reserved, 0x06                                                */
  uint16_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  uint16_t      RESERVED2;  /*!< Reserved, 0x0A                                                */
  uint16_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  uint16_t      RESERVED3;  /*!< Reserved, 0x0E                                                */
  uint16_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  uint16_t      RESERVED4;  /*!< Reserved, 0x12                                                */
  uint16_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  uint16_t      RESERVED5;  /*!< Reserved, 0x16                                                */
  uint16_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
  uint16_t      RESERVED6;  /*!< Reserved, 0x1A                                                */
} USART_TypeDef;

extern USART_TypeDef* USART2;
#endif /* ifndef _STM32F4XX__H */

