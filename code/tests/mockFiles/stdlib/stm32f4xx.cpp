#include "stm32f4xx.h"

uint32_t SystemCoreClock = 168000000;

TIM_TypeDef  TIMx;         // Actual memory location for timers
TIM_TypeDef* TIM4 = &TIMx; // pointer for timer4

GPIO_TypeDef GPIOA_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOB_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOC_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOD_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOE_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOF_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOG_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOH_real; // Actual memory location for GPIO
GPIO_TypeDef GPIOI_real; // Actual memory location for GPIO
GPIO_TypeDef* GPIOA = &GPIOA_real;
GPIO_TypeDef* GPIOB = &GPIOB_real;
GPIO_TypeDef* GPIOC = &GPIOC_real;
GPIO_TypeDef* GPIOD = &GPIOD_real;
GPIO_TypeDef* GPIOE = &GPIOE_real;
GPIO_TypeDef* GPIOF = &GPIOF_real;
GPIO_TypeDef* GPIOG = &GPIOG_real;
GPIO_TypeDef* GPIOH = &GPIOH_real;
GPIO_TypeDef* GPIOI = &GPIOI_real;

I2C_TypeDef I2C1_real; // Actual memory location for I2C
I2C_TypeDef* I2C1 = &I2C1_real;

// DMA
DMA_Stream_TypeDef DMAY_StreamX; //!< actual memory location for DMA Stream
DMA_Stream_TypeDef* DMA2_Stream6 = &DMAY_StreamX;  //!< DMA1_Stream0 pointer

// USART
USART_TypeDef USART_real; // Actual memory location for timers
USART_TypeDef* USART2 = &USART_real;
//

