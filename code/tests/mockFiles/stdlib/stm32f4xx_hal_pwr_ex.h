/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_PWR_EX_H
#define __STM32F4xx_HAL_PWR_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_def.h"
#define PWR_REGULATOR_VOLTAGE_SCALE1         PWR_CR_VOS             /* Scale 1 mode(default value at reset): the maximum value of fHCLK = 168 MHz. */
#define __HAL_PWR_VOLTAGESCALING_CONFIG(__REGULATOR__) {}


#ifdef __cplusplus
}
#endif


#endif /* __STM32F4xx_HAL_PWR_EX_H */

