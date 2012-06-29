#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
    textureCache.removeAll();
    fontCache.removeAll();
    soundCache.removeAll();
}

