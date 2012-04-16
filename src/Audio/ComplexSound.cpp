#include "ComplexSound.h"

#include "Listener.h"

#include <fmodex/fmod.hpp>
#include <fmodex/fmod_errors.h>

#include <cmath>

#include <cstdio>

ComplexSound::ComplexSound()
    : Sound(),
    dsp(NULL)
{

}

ComplexSound::ComplexSound(const std::string& filename, int type)
{
    Sound::loadSound(filename, type);
    /*
    float f;
    char s[16];
    dsp->getParameter(0, &f, s, 16);
    printf("%f, %s\n", f, s);
    */
}

ComplexSound::~ComplexSound()
{
}

void ComplexSound::loadSound(const std::string& filename, int type)
{
    Sound::loadSound(filename, type);
    Listener::getSystem()->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
}

void ComplexSound::play()
{
    Sound::play();
    channel->addDSP(dsp, 0);
}

void ComplexSound::setFrequency(float frequency)
{
    //float currentFrequency = getFrequency();
    //float ratio = frequency / currentFrequency;
    channel->setFrequency(frequency);

    int i = 0;
    dsp->getNumParameters(&i);
    printf("%d\n", i);
    dsp->setParameter(0, 2.0);
}
