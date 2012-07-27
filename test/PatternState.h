#ifndef _PatternState_h_
#define _PatternState_h_

#include <Core/CoreState.h>
#include <System/ResourcePtr.h>

#include "Bullet/BulletEmitter.h"

class PatternState : public CoreState
{
    private:
        TexturePtr background;

    public:
        PatternState();
        ~PatternState();

        void init(ResourceManager& resources);
        void deinit();

        void handleInput(Input& input, int value, int action);
        void logic(float timeStep);
        void draw();
};

#endif

