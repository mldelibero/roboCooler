#ifndef __LEDOBJS_H
#define __LEDOBJS_H
#include <stm32f4xx.h>

class CLedObj
{
    public:
        CLedObj();
        CLedObj(float RedPercentOn, float GreenPercentOn, float BluePercentOn);

        float Get_Red_PercentOn  (void);
        float Get_Green_PercentOn(void);
        float Get_Blue_PercentOn (void);

        void Set_Red_PercentOn  (float level);
        void Set_Green_PercentOn(float level);
        void Set_Blue_PercentOn (float level);
        void Set_All_PercentOn(float RedPercentOn, float GreenPercentOn, float BluePercentOn);

        void TurnOff(void);

    private:
        float m_Red_PercentOn;
        float m_Green_PercentOn;
        float m_Blue_PercentOn;
};

#endif // #ifndef __LEDOBJS_H

