#include "capsense.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"

bool check_csIrq(void);
void mpr121_init(void);
uint8_t mpr121Read(unsigned char address);
static char touchstatus = 0;

// PB8
#define CS_SCL_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_SCL_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_SCL_GPIOx                    GPIOB
#define CS_SCL_GPIO_PinSourcex          GPIO_PinSource8
#define CS_SCL_GPIO_AF                  GPIO_AF_I2C1
#define CS_SCL_GPIO_PIN_X               GPIO_Pin_8
#define CS_SCL_GPIO_MODE                GPIO_Mode_AF
#define CS_SCL_GPIO_SPEED               GPIO_High_Speed

// PB7
#define CS_SDA_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_SDA_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_SDA_GPIOx                    GPIOB
#define CS_SDA_GPIO_PinSourcex          GPIO_PinSource7
#define CS_SDA_GPIO_AF                  GPIO_AF_I2C1
#define CS_SDA_GPIO_PIN_X               GPIO_Pin_7
#define CS_SDA_GPIO_MODE                GPIO_Mode_AF
#define CS_SDA_GPIO_SPEED               GPIO_High_Speed

// PB9
#define CS_IRQ_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_IRQ_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_IRQ_GPIOx                    GPIOB
#define CS_IRQ_GPIO_PinSourcex          GPIO_PinSource9
#define CS_IRQ_GPIO_PIN_X               GPIO_Pin_9
#define CS_IRQ_GPIO_MODE                GPIO_Mode_IN
#define CS_IRQ_GPIO_SPEED               GPIO_High_Speed

// PB5
#define CS_ADD_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_ADD_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_ADD_GPIOx                    GPIOB
#define CS_ADD_GPIO_PinSourcex          GPIO_PinSource5
#define CS_ADD_GPIO_PIN_X               GPIO_Pin_5
#define CS_ADD_GPIO_MODE                GPIO_Mode_IN
#define CS_ADD_GPIO_SPEED               GPIO_High_Speed

#define CS_RCC_APBxPeriphClockCmd       RCC_APB1PeriphClockCmd
#define CS_APBxPeriph_I2Cx              RCC_APB1Periph_I2C1
#define CS_I2Cx                         I2C1

#define CS_I2C_ADDR_WR     0xB4
//#define CS_I2C_ADDR_WR     0x5D
#define CS_I2C_ADDR_RE     0xB5

#define    MHD_R    0x2B
#define    NHD_R    0x2C
#define    NCL_R    0x2D
#define    FDL_R    0x2E
#define    MHD_F    0x2F
#define    NHD_F    0x30
#define    NCL_F    0x31
#define    FDL_F    0x32
#define    ELE0_T    0x41
#define    ELE0_R    0x42
#define    ELE1_T    0x43
#define    ELE1_R    0x44
#define    ELE2_T    0x45
#define    ELE2_R    0x46
#define    ELE3_T    0x47
#define    ELE3_R    0x48
#define    ELE4_T    0x49
#define    ELE4_R    0x4A
#define    ELE5_T    0x4B
#define    ELE5_R    0x4C
#define    ELE6_T    0x4D
#define    ELE6_R    0x4E
#define    ELE7_T    0x4F
#define    ELE7_R    0x50
#define    ELE8_T    0x51
#define    ELE8_R    0x52
#define    ELE9_T    0x53
#define    ELE9_R    0x54
#define    ELE10_T    0x55
#define    ELE10_R    0x56
#define    ELE11_T    0x57
#define    ELE11_R    0x58
#define    FIL_CFG    0x5D
#define    ELE_CFG    0x5E
#define    GPIO_CTRL0    0x73
#define    GPIO_CTRL1    0x74
#define    GPIO_DATA    0x75
#define    GPIO_DIR    0x76
#define    GPIO_EN     0x77
#define    GPIO_SET    0x78
#define    GPIO_CLEAR  0x79
#define    GPIO_TOGGLE 0x7A
#define    ATO_CFG0    0x7B
#define    ATO_CFGU    0x7D
#define    ATO_CFGL    0x7E
#define    ATO_CFGT    0x7F


// Global Constants
#define TOU_THRESH    0x0F
#define REL_THRESH    0x0A
void init_cs(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    I2C_InitTypeDef  I2C_InitStruct;

    // Init Peripheral clocks
    CS_SCL_GPIO_AHBxPeriphClockCmd(CS_SCL_AHBxPeriph_GPIOx,  ENABLE);
    CS_SDA_GPIO_AHBxPeriphClockCmd(CS_SDA_AHBxPeriph_GPIOx,  ENABLE);
    CS_IRQ_GPIO_AHBxPeriphClockCmd(CS_IRQ_AHBxPeriph_GPIOx,  ENABLE);
    CS_ADD_GPIO_AHBxPeriphClockCmd(CS_ADD_AHBxPeriph_GPIOx,  ENABLE);

    CS_RCC_APBxPeriphClockCmd(CS_APBxPeriph_I2Cx, ENABLE);

    // Init GPIO
    GPIO_PinAFConfig(CS_SCL_GPIOx, CS_SCL_GPIO_PinSourcex, CS_SCL_GPIO_AF);
    GPIO_PinAFConfig(CS_SDA_GPIOx, CS_SDA_GPIO_PinSourcex, CS_SDA_GPIO_AF);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;

    GPIO_InitStruct.GPIO_Mode  = CS_SCL_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_SCL_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_SCL_GPIO_PIN_X;
    GPIO_Init(CS_SCL_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = CS_SDA_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_SDA_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_SDA_GPIO_PIN_X;
    GPIO_Init(CS_SDA_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = CS_IRQ_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_IRQ_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_IRQ_GPIO_PIN_X;
    GPIO_Init(CS_IRQ_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = CS_ADD_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_ADD_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_ADD_GPIO_PIN_X;
    GPIO_Init(CS_ADD_GPIOx,&GPIO_InitStruct);

    // Set Address Pin Low
    GPIO_ResetBits(CS_ADD_GPIOx, CS_ADD_GPIO_PIN_X);

    // Init I2C Peripheral
    I2C_DeInit(CS_I2Cx);
    I2C_StructInit(&I2C_InitStruct);

    I2C_InitStruct.I2C_ClockSpeed          = 100000;
    I2C_InitStruct.I2C_Mode                = I2C_Mode_I2C;
    I2C_InitStruct.I2C_DutyCycle           = I2C_DutyCycle_2;
    I2C_InitStruct.I2C_OwnAddress1         = 0;
    I2C_InitStruct.I2C_Ack                 = I2C_Ack_Enable;
    I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Init(CS_I2Cx, &I2C_InitStruct);

    I2C_Cmd(CS_I2Cx, ENABLE);


    mpr121_init();
    while(1)
    {
        while(check_csIrq() == false);
        touchstatus = mpr121Read(0x00);	// Read touch status
        touchstatus = touchstatus << 2;	// Shift two bits over
    }
} // end - void init_cs(void)

bool check_csIrq(void)
{
    if (GPIO_ReadInputDataBit(CS_IRQ_GPIOx, CS_IRQ_GPIO_PIN_X) == 1) return true;
    else                                                             return false;
} // end - bool check_csIrq(void)

void mpr121Write(unsigned char address, unsigned char data)
{
    I2C_GenerateSTART(CS_I2Cx, ENABLE);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_MODE_SELECT) == ERROR);

    I2C_Send7bitAddress(CS_I2Cx, CS_I2C_ADDR_WR, I2C_Direction_Transmitter);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == ERROR);

    I2C_SendData(CS_I2Cx, address);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTING) == ERROR);

    I2C_SendData(CS_I2Cx, data);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED) == ERROR);

    I2C_GenerateSTOP(CS_I2Cx, ENABLE);
} // end - void mpr121Write(unsigned char address, unsigned char data)

uint8_t mpr121Read(unsigned char address)
{
    uint8_t data;
    
    I2C_GenerateSTART(CS_I2Cx, ENABLE);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_MODE_SELECT) == ERROR);
    
    I2C_Send7bitAddress(CS_I2Cx, CS_I2C_ADDR_WR, I2C_Direction_Transmitter);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == ERROR);
    
    I2C_SendData(CS_I2Cx, address);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTING) == ERROR);
    
    // Read
    I2C_GenerateSTART(CS_I2Cx, ENABLE);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_MODE_SELECT) == ERROR);

    I2C_Send7bitAddress(CS_I2Cx, CS_I2C_ADDR_RE, I2C_Direction_Transmitter);
    I2C_NACKPositionConfig(CS_I2Cx, I2C_NACKPosition_Current);
    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == ERROR);
    

    while (I2C_CheckEvent(CS_I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED) == ERROR);
    data = I2C_ReceiveData(CS_I2Cx);

    I2C_GenerateSTOP(CS_I2Cx, ENABLE);

    return data;
}

void mpr121_init(void)
{
    // Section A
    // This group controls filtering when data is > baseline.
    mpr121Write(MHD_R, 0x01);
    mpr121Write(NHD_R, 0x01);
    mpr121Write(NCL_R, 0x00);
    mpr121Write(FDL_R, 0x00);
    
    // Section B
    // This group controls filtering when data is < baseline.
    mpr121Write(MHD_F, 0x01);
    mpr121Write(NHD_F, 0x01);
    mpr121Write(NCL_F, 0xFF);
    mpr121Write(FDL_F, 0x02);
    
    // Section C
    // This group sets touch and release thresholds for each electrode
    mpr121Write(ELE0_T, TOU_THRESH);
    mpr121Write(ELE0_R, REL_THRESH);
    mpr121Write(ELE1_T, TOU_THRESH);
    mpr121Write(ELE1_R, REL_THRESH);
    mpr121Write(ELE2_T, TOU_THRESH);
    mpr121Write(ELE2_R, REL_THRESH);
    mpr121Write(ELE3_T, TOU_THRESH);
    mpr121Write(ELE3_R, REL_THRESH);
    mpr121Write(ELE4_T, TOU_THRESH);
    mpr121Write(ELE4_R, REL_THRESH);
    mpr121Write(ELE5_T, TOU_THRESH);
    mpr121Write(ELE5_R, REL_THRESH);
    /*mpr121Write(ELE6_T, TOU_THRESH);
    mpr121Write(ELE6_R, REL_THRESH);
    mpr121Write(ELE7_T, TOU_THRESH);
    mpr121Write(ELE7_R, REL_THRESH);
    mpr121Write(ELE8_T, TOU_THRESH);
    mpr121Write(ELE8_R, REL_THRESH);
    mpr121Write(ELE9_T, TOU_THRESH);
    mpr121Write(ELE9_R, REL_THRESH);
    mpr121Write(ELE10_T, TOU_THRESH);
    mpr121Write(ELE10_R, REL_THRESH);
    mpr121Write(ELE11_T, TOU_THRESH);
    mpr121Write(ELE11_R, REL_THRESH);*/
    
    // Section D
    // Set the Filter Configuration
    // Set ESI2
    mpr121Write(FIL_CFG, 0x04);
    
    // Section E
    // Electrode Configuration
    // Enable 6 Electrodes and set to run mode
    // Set ELE_CFG to 0x00 to return to standby mode
    // mpr121Write(ELE_CFG, 0x0C);    // Enables all 12 Electrodes
    mpr121Write(ELE_CFG, 0x06);        // Enable first 6 electrodes
    
    // Section F
    // Enable Auto Config and auto Reconfig
    /*mpr121Write(ATO_CFG0, 0x0B);
    mpr121Write(ATO_CFGU, 0xC9);    // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V
    mpr121Write(ATO_CFGL, 0x82);    // LSL = 0.65*USL = 0x82 @3.3V
    mpr121Write(ATO_CFGT, 0xB5);*/    // Target = 0.9*USL = 0xB5 @3.3V
} // end - void mpr121_init(void)

