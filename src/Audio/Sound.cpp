#include "Sound.h"
#include "Listener.h"

#include <fmodex/fmod.hpp>
#include <fmodex/fmod_errors.h>
#include <cstdio>

#include "../System/Log.h"

Sound::Sound()
    : sound(NULL),
    channel(NULL)
{
}

Sound::Sound(const std::string& filename, int type)
{
    loadSound(filename, type);
}

Sound::~Sound()
{
}

void Sound::loadSound(const std::string& filename, int type)
{
    FMOD_RESULT result;
    if (type == SoundType::Default)
    {
        result = Listener::system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
    }

    else if (type == SoundType::Stream)
    {
        result = Listener::system->createStream(filename.c_str(), FMOD_DEFAULT, 0, &sound);
    }

    if (result != FMOD_OK)
    {
        logf("FMOD error! (%d) %s.", result, FMOD_ErrorString(result));
        return;
    }

    logf("Sound @ \"%s\" loaded.", filename.c_str());
}

void Sound::play()
{
    if (isPlaying())
        return;
    if (isPaused())
    {
        pause();
        return;
    }

    FMOD_RESULT result = Listener::system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
    if (result != FMOD_OK)
    {
        logf("FMOD error! (%d) %s.", result, FMOD_ErrorString(result));
    }
}

void Sound::stop()
{
    FMOD_RESULT result = channel->stop();
    if (result != FMOD_OK)
    {
        logf("FMOD error! (%d) %s.", result, FMOD_ErrorString(result));
    }
}

void Sound::pause()
{
    bool paused;
    channel->getPaused(&paused);

    // toggle
    FMOD_RESULT result = channel->setPaused(!paused);
    if (result != FMOD_OK)
    {
        logf("FMOD error! (%d) %s.", result, FMOD_ErrorString(result));
    }
}

void Sound::setVolume(float volume)
{
    channel->setVolume(volume);
}

float Sound::getVolume()
{
    float volume = 0.0f;
    channel->getVolume(&volume);

    return volume;
}

bool Sound::isPlaying()
{
    bool playing;
    channel->isPlaying(&playing);

    return playing;
}

bool Sound::isPaused()
{
    bool paused;
    channel->getPaused(&paused);

    return paused;
}

void Sound::setTime(float time)
{
    channel->setPosition((unsigned int)(time * 1000), FMOD_TIMEUNIT_MS);  
}

float Sound::getTime()
{
    unsigned int position;
    channel->getPosition(&position, FMOD_TIMEUNIT_MS); 

    return (float)position / 1000;
}

float Sound::getLength()
{
    unsigned int length;
    sound->getLength(&length, FMOD_TIMEUNIT_MS); 

    return (float)length/ 1000;
}

// Tracker module stuff
int Sound::getPattern()
{
    unsigned int pattern;
    channel->getPosition(&pattern, FMOD_TIMEUNIT_MODPATTERN); 

    return pattern;
}

int Sound::getPatternCount()
{
    unsigned int patternCount;
    sound->getLength(&patternCount, FMOD_TIMEUNIT_MODPATTERN); 

    return patternCount;
}

int Sound::getRow()
{
    unsigned int row;
    channel->getPosition(&row, FMOD_TIMEUNIT_MODROW);

    return row;
}

int Sound::getRowCount()
{
    unsigned int rowCount;
    sound->getLength(&rowCount, FMOD_TIMEUNIT_MODROW); 

    return rowCount;
}

int Sound::getOrder()
{
    unsigned int order;
    sound->getLength(&order, FMOD_TIMEUNIT_MODORDER); 

    return order;
}

float Sound::getFrequency()
{
    float frequency;
    channel->getFrequency(&frequency);

    return frequency;
}

void Sound::setFrequency(float frequency)
{
    channel->setFrequency(frequency);
}

float Sound::getSpeed()
{
    float speed;
    sound->getMusicSpeed(&speed);

    return speed;
}

void Sound::setSpeed(float speed)
{
    sound->setMusicSpeed(speed);
}

