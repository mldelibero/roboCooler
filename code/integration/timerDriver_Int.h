#ifndef __TIMERDRIVER_INT_H
#define __TIMERDRIVER_INT_H

// PB7
#define TIMER_INT_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOB
#define TIMER_INT_GPIOx                    GPIOB
#define TIMER_INT_GPIO_PinSourcex          GPIO_PinSource7
#define TIMER_INT_GPIO_PIN_X               GPIO_Pin_7
#define TIMER_INT_OCxInit                  TIM_OC2Init

void init_TimerDriver_Int(void);
#endif // ifndef __TIMERDRIVER_INT_H

