#ifndef __TIMER_INT_H
#define __TIMER_INT_H

// PB7
#define TIMERDRIVER_INT_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOB
#define TIMERDRIVER_INT_GPIOx                  GPIOB
#define TIMERDRIVER_INT_GPIO_PinSourcex        GPIO_PinSource7
#define TIMERDRIVER_INT_GPIO_PIN_X             GPIO_Pin_7
#define TIMERDRIVER_INT_OCxInit                TIM_OC2Init

// PE15
#define TIMER_INT_AHB1Periph_GPIOx             RCC_AHB1Periph_GPIOE
#define TIMER_INT_GPIOx                        GPIOE
#define TIMER_INT_GPIO_PinSourcex              GPIO_PinSource15
#define TIMER_INT_GPIO_PIN_X                   GPIO_Pin_15

void init_TimerDriver_Int(void);
void init_Timer_Int(void);
void timer_Int(void);
#endif // ifndef __TIMER_INT_H

