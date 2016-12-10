#ifndef __CAP_TOUCH_DRIVER_MOCK_H
#define __CAP_TOUCH_DRIVER_MOCK_H
class CCapTouchDriverMock : public CCapTouchDriver
{
    public:
        CCapTouchDriverMock(void);
        ~CCapTouchDriverMock(void);

        void Initialize_Hardware(void);
        BitAction SampleInput(void);
        void Set_MockInput(void);
        void Clear_MockInput(void);

    private:
        BitAction m_MockInputValue;
};
#endif // #ifndef __CAP_TOUCH_DRIVER_MOCK_H

