#ifndef _JumpState_h_
#define _JumpState_h_

#include <Core/CoreState.h>

#include "Platform/Player.h"

class JumpState : public CoreState
{
    private:
    TexturePtr background;
    Player player;

    public:
    JumpState();
    ~JumpState();

    void init(ResourceManager& resources);
    void deinit();

    void handleInput(Input& input, int value, int action);
    void logic(float timeStep);
    void draw();
};

#endif
