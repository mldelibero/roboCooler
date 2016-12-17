#include "capTouch.h"

CCapTouchComp::CCapTouchComp(CCapTouchDriver* capTouchDriver)
{
    m_CapTouchDriver = capTouchDriver;
    m_TouchDetected  = false;
}

void CCapTouchComp::Execute(void)
{
    if (m_CapTouchDriver->Is_DataReady())
    {
        if ((m_CapTouchDriver->Read(0) & PROX_STATUS_BIT) != 0)
        { // This variable is cleared only after it has been polled
            m_TouchDetected = true;
        }
    }
}

void CCapTouchComp::Initialize(void)
{
    // Proximity Touch/Release Threshold
    m_CapTouchDriver->Write(ELEPROXTTH, 0x08);
    m_CapTouchDriver->Write(ELEPROXRTH, 0x05);

    // Proximity Baseline Filter Setting
    // Rising
    m_CapTouchDriver->Write(MHD_R, 0xFF);
    m_CapTouchDriver->Write(NHD_R, 0xFF);
    m_CapTouchDriver->Write(NCL_R, 0x00);
    m_CapTouchDriver->Write(FDL_R, 0x00);
    // Fallilng
    m_CapTouchDriver->Write(MHD_F, 0x01);
    m_CapTouchDriver->Write(NHD_F, 0x01);
    m_CapTouchDriver->Write(NCL_F, 0xFF);
    m_CapTouchDriver->Write(FDL_F, 0xFF);
    // Touched
    m_CapTouchDriver->Write(NHD_T, 0x00);
    m_CapTouchDriver->Write(NCL_T, 0x00);
    m_CapTouchDriver->Write(FDL_T, 0x00);

    // Electrode Configuration for Proximity Sensing
    m_CapTouchDriver->Write(ACCR0, ACCR0_VAL);
    m_CapTouchDriver->Write(ACCR1, ACCR1_VAL);
    m_CapTouchDriver->Write(ATO_CFGU, 0xC9);    // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V
    m_CapTouchDriver->Write(ATO_CFGL, 0x83);    // LSL = 0.65*USL = 0x83 @3.3V
    m_CapTouchDriver->Write(ATO_CFGT, 0xB5);    // Target = 0.9*USL = 0xB5 @3.3V

    // AFE Filter and Configuration Register
    m_CapTouchDriver->Write(FIL_CFG, FIL_CFG_VAL);
    m_CapTouchDriver->Write(AFE_CFG, AFE_CFG_VAL);

    // Enable Proximity Sensing
    m_CapTouchDriver->Write(ELE_CFG, ELE_CFG_VAL);
} // end - void CCapTouchComp::Initialize(void)

bool CCapTouchComp::Is_TouchDetected(void)
{
    if (m_TouchDetected == true)
    {
        m_TouchDetected = false;
        return true;
    }
    else
    {
        return false;
    }
}

