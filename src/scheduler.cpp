#include "misc.h"
#include "stm32f4xx_rcc.h"
#include "scheduler.h"
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define SCHED_TIMx_IRQn               TIM1_UP_TIM10_IRQn
#define HB_CNT_RESET                  (SCHED_CLK / HB_FREQ)
#define HB_FREQ                       2
#define HB_GPIOO_SPEED                GPIO_Low_Speed
#define HB_GPIO_MODE                  GPIO_Mode_OUT
#define HB_GPIO_PIN_X                 GPIO_Pin_12
#define HB_GPIOx                      GPIOD
#define SCHED_RCC_APBxPeriphClockCmd  RCC_APB2PeriphClockCmd
#define RCC_APBxPeriph_SCHED_RCC      RCC_APB2Periph_TIM1
#define SCHED_CLK                     10000
#define SCHED_TIM_CLK                 1000
#define SCHED_TIMx                    TIM1

uint16_t PrescalerValue;

void init_heartBeatLed(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_DeInit(HB_GPIOx);
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = HB_GPIO_PIN_X;
    GPIO_InitStruct.GPIO_Mode  = HB_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = HB_GPIOO_SPEED;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;

    GPIO_Init(HB_GPIOx,&GPIO_InitStruct);
}

void init_scheduler(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;

    TIM_DeInit(SCHED_TIMx);
    SCHED_RCC_APBxPeriphClockCmd(RCC_APBxPeriph_SCHED_RCC, ENABLE);

    PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / SCHED_CLK) - 1;

    TIM_TimeBaseInitStruct.TIM_Prescaler         = PrescalerValue;
    TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period            = SCHED_CLK / SCHED_TIM_CLK;
    TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;

    TIM_TimeBaseInit(SCHED_TIMx, &TIM_TimeBaseInitStruct);


    NVIC_InitStructure.NVIC_IRQChannel                   = SCHED_TIMx_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_ITConfig(SCHED_TIMx, TIM_IT_Update, ENABLE);
    TIM_Cmd(SCHED_TIMx, ENABLE);

    init_heartBeatLed();
} // end - void init_scheduler(void)


void SCHED_IRQHandler(void)
{
    static int32_t HB_Cnt = HB_CNT_RESET;

    if (--HB_Cnt <= 0)
    {
      GPIO_ToggleBits(HB_GPIOx, HB_GPIO_PIN_X);
      HB_Cnt = HB_CNT_RESET;
    }

    TIM_ClearITPendingBit(SCHED_TIMx, TIM_IT_Update);
}

