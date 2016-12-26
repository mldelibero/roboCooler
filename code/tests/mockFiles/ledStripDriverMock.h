#ifndef __LED_STRIP_DRIVER_MOCK_H
#define __LED_STRIP_DRIVER_MOCK_H
class CLedStripDriverMock : public CLedStripDriver
{
    public:
        CLedStripDriverMock(void);

        ~CLedStripDriverMock(void);

        void Initialize_Hardware(void);

    private:
};
#endif // #define __LED_STRIP_DRIVER_MOCK_H

