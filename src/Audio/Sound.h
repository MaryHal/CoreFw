#ifndef _Sound_h_
#define _Sound_h_

#include <string>

#include <AL/al.h>
#include <AL/alc.h>

#include <sndfile.h>

class Sound
{
    protected:
        ALuint source;
        ALuint buffer;

    public:
        Sound();
        Sound(const std::string& filename);
        ~Sound();

        void loadSound(const std::string& filename);

        void play();
        void stop();
        void pause();

        void setVolume(float volume);
        float getVolume();

        bool isPlaying();
        bool isPaused();

        void setTime(float time);
        float getTime();

        float getLength();
};

#endif

