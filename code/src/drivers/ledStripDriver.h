#ifndef __LED_STRIP_DRIVER_H
#define __LED_STRIP_DRIVER_H
#include "CDriver.h"
#include "ledObj.h"
#include "component.h"
#include "hardwareSettings.h"
#include "stm32f4xx_hal.h"
#include <Driver_USART.h>

#define BIT_LOW     0x06 //110
#define BIT_HI      0x04 //100

class CLedStripDriver : public CDriver , public CComponent
{
    public:
        CLedStripDriver(uint16_t NumLeds, ARM_DRIVER_USART* Driver_USARTn);
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
        ARM_DRIVER_USART*   m_Driver_USARTn;
        USART_HandleTypeDef m_USART_Handle;
        bool m_UpdateAvailable;
        inline void UpdatePartialLedValue(uint8_t* WritePointer, uint8_t Index, uint8_t HiBits, uint8_t MedBits, uint8_t LoBits);
        inline void UpdateSingleLed(CLedObj* LedObjArray, uint8_t* WritePointer, uint8_t LedIndex);

        GPIO_Settings_t m_GPIO;
}; // end -- class CLedStripDriver

void DMA2_Stream6_IRQHandler(void);
#endif //#ifndef __LED_STRIP_DRIVER_H

