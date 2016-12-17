#ifndef __CAP_TOUCH_H
#define __CAP_TOUCH_H
#include <stm32f4xx.h>
#include "component.h"
#include "capTouchDriver.h"

class CCapTouchComp: public CComponent
{
    public:
        CCapTouchComp(CCapTouchDriver* capTouchDriver);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool Is_TouchDetected(void);

    private:
        CCapTouchDriver* m_CapTouchDriver;
        bool m_TouchDetected;
};

#define    MHD_R    0x36
#define    NHD_R    0x37
#define    NCL_R    0x38
#define    FDL_R    0x39
#define    MHD_F    0x3A
#define    NHD_F    0x3B
#define    NCL_F    0x3C
#define    FDL_F    0x3D
#define    NHD_T    0x3E
#define    NCL_T    0x3F
#define    FDL_T    0x40

#define    ELEPROXTTH   0x59 //!< Proximity Electrode Touch   Threshold
#define    ELEPROXRTH   0x5A //!< Proximity Electrode Release Threshold

#define    ACCR0        0x7B //!< Auto-Configure Control Register 0
#define    ACCR1        0x7C //!< Auto-Configure Control Register 1

// ACCR0 Bits
#define FFI_6SAMPLES    0xC0          //!< First Filter Iterations
#define RETRY_8TIMES    0x30          //!< Retry 8 Times
#define RETRY           RETRY_8TIMES  //!< Number of times to retry the auto-configuration
#define BVA             (ECR_CL >> 4) //!< Must be same as ECR Calibration lock bits
#define ARE             (1 << 1)      //!< Auto-Reconfigration Enable
#define ACE             (1 << 0)      //!< Auto-Configration Enable
#define ACCR0_VAL       (FFI_6SAMPLES | RETRY | BVA | ARE | ACE)

// ACCR1 Bits
#define SCTS            (0 << 7) //!< Skip Charge Time Search
#define OORIE           (0 << 2) //!< Out of Range Interrupt Enable
#define ARFIE           (0 << 1) //!< Auto-configuration fail interrpt enable
#define ACRIE           (0 << 0) //!< auto-reconfiguration fail interrupt enable
#define ACCR1_VAL       (SCTS | OORIE | ARFIE | ACRIE)

// ECR Bits
#define ECR_CL          (0 << 6)     //!< Calibration Lock -- Default Behavior
#define ECR_VAL         ECR_CL       //!< Electrode Configuration Register Value

// AFE Filter and Configuration Register Bits
#define AFE_CFG     0x5C //!< AFE Configuration Register
#define FFI         (0    << 6) //!< First Filter Iterations -- 6 Samples
#define CDC         (0x10 << 0) //!< Charge Discharge Current -- 16uA (Defualt)
#define AFE_CFG_VAL (FFI | CDC)

#define FIL_CFG     0x5D //!< Filter Configuration Register
#define CDT         (1 << 6) //!< Charge Discharge Time -- 0.5us (Default)
#define SFI         (0 << 4) //!< Second Filter Iterations -- 4 Samples (Defualt)
#define ESI         (4 << 0) //!< Electrode Sample Interval -- 16ms (Defualt)
#define FIL_CFG_VAL CDT | SFI | ESI //!< Filter Configuration Value

// Electrode Configuration Bits
#define ELE_CFG     0x5E //!< Electrode Configuration Register
#define AREA_DETECTION_0to11    (3 << 4) //!< Aread Detection by connection ELE0-11
#define ELE_CFG_VAL     AREA_DETECTION_0to11 //!< ELE_CFG Value

// Auto Configuration
#define    ATO_CFGU    0x7D
#define    ATO_CFGL    0x7E
#define    ATO_CFGT    0x7F

#endif // #ifndef __CAP_TOUCH_H

