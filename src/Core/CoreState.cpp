#include "CoreState.h"

CoreState::CoreState()
    : textures(NULL),
      fonts(NULL),
      sounds(NULL),
      initialized(false)
{
}

CoreState::~CoreState()
{
}

void CoreState::init(ResourceManager& resources)
{
    textures = &resources.textureCache;
    fonts = &resources.fontCache;
    sounds = &resources.soundCache;
    initialized = true;
}

void CoreState::deinit()
{
    initialized = false;
}

bool CoreState::isInitialized() const
{
    return initialized;
}

