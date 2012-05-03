#ifndef _GameState_h_
#define _GameState_h_

#include <Core/CoreState.h>

class ParticleEmitter;

class GameState : public CoreState
{
    private:
        Text text;
        ParticleEmitter* emitter;
        bool held;

    public:
        GameState();
        ~GameState();

        void init(ResourceManager& resources);
        void deinit();

        void handleInput(Input& input, int value, int action);
        void logic(float timeStep);
        void draw();
};

#endif

