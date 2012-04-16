#ifndef _CoreState_h_
#define _CoreState_h_

#include "../System/ResourceManager.h"

class Input;

class CoreState
{
    protected:
        TextureCache* textures;
        FontCache* fonts;
        SoundCache* sounds;

    public:
        CoreState();
        virtual ~CoreState();

        virtual void init(ResourceManager& resources);
        virtual void deinit() = 0;

        virtual void handleInput(Input& i, int value, int action) = 0;
        virtual void logic(float timeStep) = 0;
        virtual void draw() = 0;
};

#endif
