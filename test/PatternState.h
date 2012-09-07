#ifndef _PatternState_h_
#define _PatternState_h_

#include <Core/CoreState.h>
#include <System/ResourcePtr.h>
#include <Utils/FpsCounter.h>

#include "Bullet/BulletEmitter.h"

#include <boost/function.hpp>

class PatternState : public CoreState
{
    private:
    TexturePtr background;
    BulletEmitter emitter;

    Text fpstext;
    FpsCounter fps;

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

