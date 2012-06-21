#ifndef _SoundBuffer_h_
#define _SoundBuffer_h_

#include "../Memory/Buffer.h"

class SoundBuffer : public Buffer
{
    private:
        unsigned int buffer;
        
        std::size_t  sampleCount;
        unsigned int channelCount;
        unsigned int sampleRate;

    public:
        SoundBuffer();
        SoundBuffer(std::size_t sampleCount,
                    unsigned int channelCount,
                    unsigned int sampleRate);
        ~SoundBuffer();

        void setSoundBuffer(std::size_t sampleCount,
                            unsigned int channelCount,
                            unsigned int sampleRate);

        void update();
        const unsigned int getBufferID() const;

        const std::size_t getSampleCount() const;
};

#endif

