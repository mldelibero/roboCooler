#ifndef __SCENEMOCK_H
#define __SCENEMOCK_H
#include "scene.h"
class CSceneMock : public CScene
{
    public:
        CSceneMock();
        virtual ~CSceneMock();

        void Play(void);
        bool HasBeenPlayed(void);
};
#endif // #ifndef __SCENEMOCK_H

