#include <misc.h>
#include <stm32f4xx.h>
#include <stm32f407xx.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include <stm32f4xx_gpio.h>
#include "lidMotor.h"

#define RCC_APBxPeriph_LIDMOTOR_RCC      RCC_APB2Periph_TIM1
#define LIDMOTOR_RCC_APBxPeriphClockCmd  RCC_APB2PeriphClockCmd
#define LIDMOTOR_TIMx_IRQn               TIM1_UP_TIM10_IRQn
#define LIDMOTOR_TIMx                    TIM1
#define LIDMOTOR_CLK                     42000000
#define LIDMOTOR_FREQ                    30000
#define LIDMOTOR_PER                     (LIDMOTOR_CLK / LIDMOTOR_FREQ - 1)
#define MOTOR_GPIO_AF                    GPIO_AF_TIM1

// PE9
#define FWD_HI_OCxInit                   TIM_OC1Init
#define FWD_HI_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define FWD_HI_GPIOx                     GPIOE
#define FWD_HI_GPIO_PinSourcex           GPIO_PinSource9
#define FWD_HI_GPIO_PIN_X                GPIO_Pin_9

// PE11
#define FWD_LO_OCxInit                   TIM_OC2Init
#define FWD_LO_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define FWD_LO_GPIOx                     GPIOE
#define FWD_LO_GPIO_PinSourcex           GPIO_PinSource11
#define FWD_LO_GPIO_PIN_X                GPIO_Pin_11

// PE13
#define REV_HI_OCxInit                   TIM_OC3Init
#define REV_HI_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define REV_HI_GPIOx                     GPIOE
#define REV_HI_GPIO_PinSourcex           GPIO_PinSource13
#define REV_HI_GPIO_PIN_X                GPIO_Pin_13

// PE14
#define REV_LO_OCxInit                   TIM_OC4Init
#define REV_LO_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define REV_LO_GPIOx                     GPIOE
#define REV_LO_GPIO_PinSourcex           GPIO_PinSource14
#define REV_LO_GPIO_PIN_X                GPIO_Pin_14

static uint16_t PrescalerValue;

void init_lidMotor(void)
{
    GPIO_InitTypeDef        GPIO_InitStruct;
    TIM_OCInitTypeDef       TIM_OCInitStruct;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;

    // Init Peripheral clocks
    RCC_AHB1PeriphClockCmd(FWD_HI_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(FWD_LO_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(REV_HI_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(REV_LO_AHB1Periph_GPIOx,  ENABLE);
    LIDMOTOR_RCC_APBxPeriphClockCmd(RCC_APBxPeriph_LIDMOTOR_RCC, ENABLE);

    // Init GPIO
    GPIO_PinAFConfig(FWD_HI_GPIOx, FWD_HI_GPIO_PinSourcex, MOTOR_GPIO_AF);
    GPIO_PinAFConfig(FWD_LO_GPIOx, FWD_LO_GPIO_PinSourcex, MOTOR_GPIO_AF);
    GPIO_PinAFConfig(REV_HI_GPIOx, REV_HI_GPIO_PinSourcex, MOTOR_GPIO_AF);
    GPIO_PinAFConfig(REV_LO_GPIOx, REV_LO_GPIO_PinSourcex, MOTOR_GPIO_AF);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF;

    GPIO_InitStruct.GPIO_Pin   = FWD_HI_GPIO_PIN_X;
    GPIO_Init(FWD_HI_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = FWD_LO_GPIO_PIN_X;
    GPIO_Init(FWD_LO_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = REV_HI_GPIO_PIN_X;
    GPIO_Init(REV_HI_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = REV_LO_GPIO_PIN_X;
    GPIO_Init(REV_LO_GPIOx,&GPIO_InitStruct);

    // Init timer
    TIM_DeInit(LIDMOTOR_TIMx);

    PrescalerValue = (uint16_t) ((SystemCoreClock) / LIDMOTOR_CLK) - 1;

    TIM_TimeBaseInitStruct.TIM_Prescaler         = PrescalerValue;
    TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period            = LIDMOTOR_PER;
    TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;

    TIM_TimeBaseInit(LIDMOTOR_TIMx, &TIM_TimeBaseInitStruct);

    TIM_OCInitStruct.TIM_OutputState  = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
    TIM_OCInitStruct.TIM_Pulse        = LIDMOTOR_PER / 2;
    TIM_OCInitStruct.TIM_OCPolarity   = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_OCIdleState  = TIM_OCIdleState_Set;

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    FWD_HI_OCxInit(LIDMOTOR_TIMx, &TIM_OCInitStruct);
    REV_HI_OCxInit(LIDMOTOR_TIMx, &TIM_OCInitStruct);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM2;
    FWD_LO_OCxInit(LIDMOTOR_TIMx, &TIM_OCInitStruct);
    REV_LO_OCxInit(LIDMOTOR_TIMx, &TIM_OCInitStruct);

    TIM_CtrlPWMOutputs(LIDMOTOR_TIMx, ENABLE);
    TIM_Cmd           (LIDMOTOR_TIMx, ENABLE);
} // end - void init_scheduler(void)

