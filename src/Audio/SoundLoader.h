#ifndef _SoundLoader_h_
#define _SoundLoader_h_

#include <string>
#include <AL/al.h>

class SoundLoader
{
    private:
        static ALenum getFormat(unsigned int channels);

    public:
        static bool loadSound(const std::string& filename, unsigned int& buffer);
        static bool update(short* data, unsigned int& buffer, unsigned int channels, unsigned int sampleRate, std::size_t sampleCount);
};

#endif

