#ifndef __LIMIT_SWITCH_DRIVER_MOCK_H
#define __LIMIT_SWITCH_DRIVER_MOCK_H
class CLimSwDriverMock : public CLimSwDriver
{
    public:
        CLimSwDriverMock(void);
        ~CLimSwDriverMock(void);

        void Initialize_Hardware(void);
        BitAction SampleInput(void);
        void Set_MockInput(void);
        void Clear_MockInput(void);

    private:
        BitAction m_MockInputValue;
};
#endif // #ifndef __LIMIT_SWITCH_DRIVER_MOCK_H

