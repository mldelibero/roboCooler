#ifndef __LED_STRIP_DRIVER_H
#define __LED_STRIP_DRIVER_H
#include "CDriver.h"
#include "ledObj.h"
#include "component.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"

#define BIT_LOW     0x06 //110
#define BIT_HI      0x04 //100

class CLedStripDriver : public CDriver , public CComponent
{
    public:
        CLedStripDriver(uint16_t NumLeds, uint32_t RCC_AHB1Periph_DMAX, uint32_t DMA_Channel_X, DMA_Stream_TypeDef* DMAX_StreamX, uint32_t DMA_FLAG_TCIFX);
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
        bool m_UpdateAvailable;
        inline void UpdatePartialLedValue(uint8_t* WritePointer, uint8_t Index, uint8_t HiBits, uint8_t MedBits, uint8_t LoBits);
        inline void UpdateSingleLed(CLedObj* LedObjArray, uint8_t* WritePointer, uint8_t LedIndex);
}; // end -- class CLedStripDriver

#define LED_DMA_AHBxPeriphClockCmd   RCC_AHB1PeriphClockCmd
#define LED_AHBxPeriph_DMAx          RCC_AHB1Periph_DMA1
#define USARTx_TX_DMA_CHANNEL        DMA_Channel_4
#define USARTx_TX_DMA_STREAM         DMA2_Stream6
#define USARTx_TX_DMA_FLAG_TCIF      DMA_FLAG_TCIF6
#endif //#ifndef __LED_STRIP_DRIVER_H

