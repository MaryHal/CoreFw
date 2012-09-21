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

    bool initialized;

    public:
    CoreState();
    virtual ~CoreState();

    virtual void init(ResourceManager& resources);
    virtual void deinit();

    virtual void handleInput(Input& i, int value, int action) = 0;
    virtual void handleMouseInput(Input& i, int value, int action) {};
    virtual void logic(float timeStep) = 0;
    virtual void draw() = 0;

    bool isInitialized() const;
};

#endif

