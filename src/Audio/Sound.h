#ifndef _Sound_h_
#define _Sound_h_

#include <string>

namespace FMOD
{
    class Sound;
    class Channel;
};

namespace SoundType
{
    const int Default = 0;
    const int Stream = 1;
};

class Sound
{
    protected:
        FMOD::Sound* sound;
        FMOD::Channel* channel;

    public:
        Sound();
        Sound(const std::string& filename, int type=SoundType::Default);
        ~Sound();

        void loadSound(const std::string& filename, int type=SoundType::Default);

        virtual void play();
        void stop();
        void pause();

        void setVolume(float volume);
        float getVolume();

        bool isPlaying();
        bool isPaused();

        void setTime(float time);
        float getTime();

        float getLength();

        // Tracker module stuff
        int getPattern();
        int getPatternCount();
        int getRow();
        int getRowCount();
        int getOrder();

        float getFrequency();
        virtual void setFrequency(float frequency);

        float getSpeed();
        void setSpeed(float speed);
};

#endif

