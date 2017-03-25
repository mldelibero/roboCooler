#ifndef __STM32F4xx_HAL_RCC_H
#define __STM32F4xx_HAL_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_rcc_ex.h"

#define RCC_HCLK_DIV2                    RCC_CFGR_PPRE1_DIV2
#define RCC_CFGR_PPRE1_DIV4                0x00001400U                         /*!< HCLK divided by 4  */
#define RCC_HCLK_DIV4                    RCC_CFGR_PPRE1_DIV4
#define RCC_SYSCLK_DIV1                  RCC_CFGR_HPRE_DIV1

#define RCC_CLOCKTYPE_SYSCLK             ((uint32_t)0x00000001U)
#define RCC_CLOCKTYPE_HCLK               ((uint32_t)0x00000002U)
#define RCC_CLOCKTYPE_PCLK1              ((uint32_t)0x00000004U)
#define RCC_CLOCKTYPE_PCLK2              ((uint32_t)0x00000008U)

#define RCC_SYSCLKSOURCE_PLLCLK          RCC_CFGR_SW_PLL
#define RCC_SYSCLKSOURCE_PLLRCLK         ((uint32_t)(RCC_CFGR_SW_0 | RCC_CFGR_SW_1))

#define RCC_PLLP_DIV2                  ((uint32_t)0x00000002U)
#define RCC_PLLSOURCE_HSE                RCC_PLLCFGR_PLLSRC_HSE
#define RCC_PLL_ON                        ((uint8_t)0x02U)
#define RCC_HSE_ON                       RCC_CR_HSEON
#define RCC_OSCILLATORTYPE_HSE             ((uint32_t)0x00000001U)

#define __HAL_RCC_DMA2_CLK_ENABLE()    {}
#define __HAL_RCC_GPIOA_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOB_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOC_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOD_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOE_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOF_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOG_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOH_CLK_ENABLE()   {}
#define __HAL_RCC_GPIOI_CLK_ENABLE()   {}
#define __HAL_RCC_PWR_CLK_ENABLE()     {}
#define __HAL_RCC_USART2_CLK_ENABLE()  {}

/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition  
  */
typedef struct
{
  uint32_t ClockType;             /*!< The clock to be configured.
                                       This parameter can be a value of @ref RCC_System_Clock_Type      */

  uint32_t SYSCLKSource;          /*!< The clock source (SYSCLKS) used as system clock.
                                       This parameter can be a value of @ref RCC_System_Clock_Source    */

  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_AHB_Clock_Source       */

  uint32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

  uint32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

}RCC_ClkInitTypeDef;

/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, LSE and LSI) configuration structure definition  
  */
typedef struct
{
  uint32_t OscillatorType;       /*!< The oscillators to be configured.
                                      This parameter can be a value of @ref RCC_Oscillator_Type                   */

  uint32_t HSEState;             /*!< The new state of the HSE.
                                      This parameter can be a value of @ref RCC_HSE_Config                        */

  uint32_t LSEState;             /*!< The new state of the LSE.
                                      This parameter can be a value of @ref RCC_LSE_Config                        */

  uint32_t HSIState;             /*!< The new state of the HSI.
                                      This parameter can be a value of @ref RCC_HSI_Config                        */

  uint32_t HSICalibrationValue;  /*!< The HSI calibration trimming value (default is RCC_HSICALIBRATION_DEFAULT).
                                       This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x1F */

  uint32_t LSIState;             /*!< The new state of the LSI.
                                      This parameter can be a value of @ref RCC_LSI_Config                        */

  RCC_PLLInitTypeDef PLL;        /*!< PLL structure parameters                                                    */
}RCC_OscInitTypeDef;

HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);

#ifdef __cplusplus
}
#endif
#endif /* __STM32F4xx_HAL_RCC_H */

