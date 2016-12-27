#ifndef __SCENEMOCK_H
#define __SCENEMOCK_H
#include "scene.h"
class CSceneMock : public CSceneComp
{
    public:
        CSceneMock();

        virtual void Execute(void);
        virtual void Initialize(void);

        bool HasBeenRun(void);

    private:
        bool m_HasBeenRun;
};
#endif // #ifndef __SCENEMOCK_H

