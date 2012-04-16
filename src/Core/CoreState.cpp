#include "CoreState.h"

CoreState::CoreState()
    : textures(NULL),
      fonts(NULL),
      sounds(NULL)
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
}

