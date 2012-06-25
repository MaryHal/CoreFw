#include "Sound.h"

#include "SoundLoader.h"

#include "../System/Log.h"

void Sound::__generateSource()
{
    // Setup our source
    alGenSources(1, &source);
    alSourcef(source, AL_PITCH, 1);
    alSourcef(source, AL_GAIN, 1);
    alSource3f(source, AL_POSITION, 0, 0, 0);
    alSource3f(source, AL_VELOCITY, 0, 0, 0);
    alSourcei(source, AL_LOOPING, AL_FALSE);
}

void Sound::__setSource(const unsigned int& bufferID)
{
    alSourcei(source, AL_BUFFER, bufferID);
}

Sound::Sound()
{
}

Sound::Sound(const std::string& filename)
{
    // logf("Sound @ \"%s\" loaded.", filename.c_str());
}

Sound::~Sound()
{
    alDeleteSources(1, &source);
}

void Sound::play()
{
    // log("Playing Sound");
    alSourcePlay(source);
}

void Sound::stop()
{
    alSourceStop(source);
}

void Sound::pause()
{
    alSourcePause(source);
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

