#include "Sound.h"

#include "SoundLoader.h"

#include "../System/Log.h"

Sound::Sound()
{
}

Sound::Sound(const std::string& filename)
{
    loadSound(filename);
}

Sound::~Sound()
{
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
}

void Sound::loadSound(const std::string& filename)
{
    // Setup our source
    alGenSources(1, &source);
    alSourcef(source, AL_PITCH, 1);
    alSourcef(source, AL_GAIN, 1);
    alSource3f(source, AL_POSITION, 0, 0, 0);
    alSource3f(source, AL_VELOCITY, 0, 0, 0);
    alSourcei(source, AL_LOOPING, AL_FALSE);

    // We now need to generate a buffer, fill it with data, then set our
    // source to play the buffer.
    alGenBuffers(1, &buffer);

    SoundLoader::loadSound(filename, buffer);

    alSourcei(source, AL_BUFFER, buffer);

    logf("Sound @ \"%s\" loaded.", filename.c_str());
}

void Sound::play()
{
    log("Playing Sound");
    alSourcePlay(source);
}

void Sound::stop()
{
}

void Sound::pause()
{
}

void Sound::setVolume(float volume)
{
}

float Sound::getVolume()
{
    return 0.0f;
}

bool Sound::isPlaying()
{
    return false;
}

bool Sound::isPaused()
{
    return false;
}

void Sound::setTime(float time)
{
}

float Sound::getTime()
{
    return 0;
}

float Sound::getLength()
{
    return 0;
}

