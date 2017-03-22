#ifndef __SCENEMOCK_H
#define __SCENEMOCK_H
#include "scene.h"
#include "ledObj.h"

class CSceneMock : public CScene
{
    public:
        CSceneMock();
        virtual ~CSceneMock();

        void Play(void);
        bool HasBeenPlayed(void);
        uint32_t Get_NumLeds(void);
};
#endif // #ifndef __SCENEMOCK_H

