#ifndef _Sound_h_
#define _Sound_h_

#include <string>

#include <AL/al.h>
#include <AL/alc.h>

#include "SoundBuffer.h"

class Sound
{
    protected:
        ALuint source;

        void __generateSource();
        void __setSource(const unsigned int& bufferID);

    public:
        Sound();
        Sound(const std::string& filename);
        ~Sound();

        virtual void loadSound(const std::string& filename) = 0;

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

        ALuint getSource();
};

#endif

