#include "stm32f4xx_gpio.h"

// PE15
#define PBUP_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOE
#define PBUP_GPIOx                    GPIOE
#define PBUP_GPIO_PinSourcex          GPIO_PinSource15
#define PBUP_GPIO_PIN_X               GPIO_Pin_15

// PD11
#define PBDN_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOD
#define PBDN_GPIOx                    GPIOD
#define PBDN_GPIO_PinSourcex          GPIO_PinSource11
#define PBDN_GPIO_PIN_X               GPIO_Pin_11

void init_PushButtonDriver(void);

