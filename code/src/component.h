#ifndef __COMPONENT_H
#define __COMPONENT_H

class CComponent
{
    public:
        CComponent();
        CComponent(int32_t resetValue);

        int32_t Get_TimerIndex(void);
        int32_t Get_TimerResetValue(void);
        bool    Has_BaseExFunRun(void);
        bool    Run(void);

        virtual void Execute(void);

    private:
        int32_t m_BaseExFunRan; // Use to determine if a child has overwritten Execute funtion
        int32_t m_TimerIndex;
        int32_t m_TimerResetValue;

        void ResetComponent(void);
};
#endif //#ifndef __COMPONENT_H

