#ifndef __CDRIVER_H
#define __CDRIVER_H
class CDriver
{
    public:
        CDriver(void);
        virtual ~CDriver(void);
        virtual void Initialize_Hardware(void) = 0;
}; // end - class CDriver
#endif //#ifndef __CDRIVER_H

