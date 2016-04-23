
// PB7
#define PB1_INT_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOB
#define PB1_INT_GPIOx                    GPIOB
#define PB1_INT_GPIO_PinSourcex          GPIO_PinSource7
#define PB1_INT_GPIO_PIN_X               GPIO_Pin_7
#define PB1_INT_OCxInit                  TIM_OC2Init

// PB8
#define PB2_INT_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOB
#define PB2_INT_GPIOx                    GPIOB
#define PB2_INT_GPIO_PinSourcex          GPIO_PinSource8
#define PB2_INT_GPIO_PIN_X               GPIO_Pin_8
#define PB2_INT_OCxInit                  TIM_OC2Init

void init_PushButtonDriver(void);
