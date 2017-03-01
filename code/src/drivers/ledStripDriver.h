#ifndef __LED_STRIP_DRIVER_H
#define __LED_STRIP_DRIVER_H
#include "CDriver.h"
#include "ledObj.h"
#include "component.h"
#include "hardwareSettings.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_usart.h"

#define BIT_LOW     0x06 //110
#define BIT_HI      0x04 //100

class CLedStripDriver : public CDriver , public CComponent
{
    public:
        CLedStripDriver(uint16_t NumLeds, DMA_Settings_t DMA_Settings, GPIO_Settings_t GPIO_Settings, USART_TypeDef* UARTN);
        virtual ~CLedStripDriver(void);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual void Initialize_Hardware(void);
        void Update(CLedObj* LedObjArray);

    protected:
        uint16_t m_NumLeds;
        uint8_t* m_DMA_Ptr[2];
        uint8_t  m_DMA_PtrIndex;

        // DMA Variables
        uint32_t            m_DMA_Channel_X;
        uint32_t            m_DMA_FLAG_TCIFX;
        DMA_Stream_TypeDef* m_DMAX_StreamX;
        uint32_t            m_RCC_AHB1Periph_DMAX;

    private:
        USART_HandleTypeDef m_USART_Handle;
        bool m_UpdateAvailable;
        inline void UpdatePartialLedValue(uint8_t* WritePointer, uint8_t Index, uint8_t HiBits, uint8_t MedBits, uint8_t LoBits);
        inline void UpdateSingleLed(CLedObj* LedObjArray, uint8_t* WritePointer, uint8_t LedIndex);

        DMA_Settings_t  m_DMA;
        GPIO_Settings_t m_GPIO;
        UART_Settings_t m_UART;
}; // end -- class CLedStripDriver
#endif //#ifndef __LED_STRIP_DRIVER_H

