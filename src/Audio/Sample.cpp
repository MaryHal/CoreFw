#include "Sample.h"

#include "SoundLoader.h"

Sample::Sample()
    : Sound()
{
}

Sample::Sample(const std::string& filename)
    : Sound(filename)
{
    loadSound(filename);
}

Sample::~Sample()
{
}

void Sample::loadSound(const std::string& filename)
{
    __generateSource();
    SoundLoader::loadSound(filename, buffer);
    buffer.update();
    __setSource();
}

