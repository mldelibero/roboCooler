#ifndef __LEDDRIVER_H
#define __LEDDRIVER_H
#include <stm32f4xx.h>

// PC1
#define LED0_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOC
#define LED0_GPIOx                     GPIOC
#define LED0_GPIO_PIN_X                GPIO_Pin_1

// PA1
#define LED1_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
#define LED1_GPIOx                     GPIOA
#define LED1_GPIO_PIN_X                GPIO_Pin_1

// PA3
#define LED2_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
#define LED2_GPIOx                     GPIOA
#define LED2_GPIO_PIN_X                GPIO_Pin_3

// PA7
#define LED3_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
#define LED3_GPIOx                     GPIOA
#define LED3_GPIO_PIN_X                GPIO_Pin_7

// PC5
#define LED4_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOC
#define LED4_GPIOx                     GPIOC
#define LED4_GPIO_PIN_X                GPIO_Pin_5

// PB1
#define LED5_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOB
#define LED5_GPIOx                     GPIOB
#define LED5_GPIO_PIN_X                GPIO_Pin_1

// PE7
#define LED6_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define LED6_GPIOx                     GPIOE
#define LED6_GPIO_PIN_X                GPIO_Pin_7

// PE9
#define LED7_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define LED7_GPIOx                     GPIOE
#define LED7_GPIO_PIN_X                GPIO_Pin_9

void init_ledDriver(void);
void SetLeds(uint8_t ledValues);
uint8_t Get_LedStates(void);
#endif // #ifndef __LEDDRIVER_H

