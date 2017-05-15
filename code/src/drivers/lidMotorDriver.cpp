#include "lidMotorDriver.h"
#include "stm32f4xx_hal.h"
#include <string.h>

TIM_HandleTypeDef htim1;

CLidMotorDriver::CLidMotorDriver(void) {}
CLidMotorDriver::~CLidMotorDriver(void) {}

#define PERIOD      63000
#define HALF_PERIOD (PERIOD / 2)
bool error = false;
void Error_Handler(void)
{
    error = true;
}

void MX_TIM1_Init(void)
{
    TIM_MasterConfigTypeDef        sMasterConfig;
    TIM_OC_InitTypeDef             sConfigOC;
    memset(&sMasterConfig, 0 , sizeof(sMasterConfig));
    memset(&sConfigOC    , 0 , sizeof(sConfigOC));

    __HAL_RCC_TIM1_CLK_ENABLE();

    htim1.Instance               = TIM1;
    htim1.Init.Prescaler         = 4;
    htim1.Init.CounterMode       = TIM_COUNTERMODE_UP;
    htim1.Init.Period            = PERIOD;
    htim1.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    htim1.Init.RepetitionCounter = 0;
    if (HAL_TIM_PWM_Init(&htim1) != HAL_OK) Error_Handler();

    sConfigOC.OCMode       = TIM_OCMODE_PWM1;
    sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
    sConfigOC.Pulse        = HALF_PERIOD;
    sConfigOC.OCFastMode   = TIM_OCFAST_ENABLE;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;

    sConfigOC.OCPolarity   = TIM_OCPOLARITY_HIGH;
    HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC,TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC,TIM_CHANNEL_3);

    sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
    HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC,TIM_CHANNEL_2);
    HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC,TIM_CHANNEL_4);
    HAL_TIM_PWM_Init(&htim1);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
    GPIO_InitTypeDef               GPIO_InitStruct;
    memset(&GPIO_InitStruct, 0 , sizeof(GPIO_InitStruct));

    __HAL_RCC_GPIOE_CLK_ENABLE();

    if(htim_pwm->Instance==TIM1)
    {
        GPIO_InitStruct.Pin       = GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14;
        GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull      = GPIO_NOPULL;
        GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
        HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    }
}

void CLidMotorDriver::Initialize_Hardware(void)
{
    MX_TIM1_Init();
//    MX_GPIO_Init();
/*
    TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig;
    TIM_ClockConfigTypeDef         sClockSourceConfig;

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK) // Error_Handler();

    if (HAL_TIM_OC_Init(&htim1) != HAL_OK) // Error_Handler();

    sBreakDeadTimeConfig.OffStateRunMode  = TIM_OSSR_DISABLE;
    sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
    sBreakDeadTimeConfig.LockLevel        = TIM_LOCKLEVEL_OFF;
    sBreakDeadTimeConfig.DeadTime         = 0;
    sBreakDeadTimeConfig.BreakState       = TIM_BREAK_DISABLE;
    sBreakDeadTimeConfig.BreakPolarity    = TIM_BREAKPOLARITY_HIGH;
    sBreakDeadTimeConfig.AutomaticOutput  = TIM_AUTOMATICOUTPUT_DISABLE;
    if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK) {}// Error_Handler();

    //HAL_TIM_PWM_Init(&htim1);
    HAL_TIM_Base_Start(&htim1);
    */
}


void CLidMotorDriver::Stop(void)
{
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_4);
    __HAL_TIM_DISABLE(&htim1);
}

void CLidMotorDriver::Open(void)
{
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}

void CLidMotorDriver::Close(void)
{
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop (&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

