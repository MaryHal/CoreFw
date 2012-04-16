#ifndef _ComplexSound_h_
#define _ComplexSound_h_

#include "Sound.h"

namespace FMOD
{
    class DSP;
};

class ComplexSound : public Sound
{
    private:
        FMOD::DSP* dsp;

    public:
        ComplexSound();
        ComplexSound(const std::string& filename, int type=SoundType::Default);
        ~ComplexSound();

        void loadSound(const std::string& filename, int type = SoundType::Default);
        void play();

        void setFrequency(float frequency);
};

#endif

