#ifndef __LEDOBJS_H
#define __LEDOBJS_H
#include <stm32f4xx.h>

class CLedObj
{
    public:
        CLedObj();

        uint8_t Get_Red_PercentOn  (void);
        uint8_t Get_Green_PercentOn(void);
        uint8_t Get_Blue_PercentOn (void);

        void Set_Red_PercentOn  (uint8_t level);
        void Set_Green_PercentOn(uint8_t level);
        void Set_Blue_PercentOn (uint8_t level);

        void TurnOff(void);

    private:
        uint8_t m_Red_PercentOn;
        uint8_t m_Green_PercentOn;
        uint8_t m_Blue_PercentOn;
};

#endif // #ifndef __LEDOBJS_H

