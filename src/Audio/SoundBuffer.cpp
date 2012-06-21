#include "SoundBuffer.h"

#include <AL/al.h>
#include "SoundLoader.h"

SoundBuffer::SoundBuffer()
{
}

SoundBuffer::SoundBuffer(std::size_t sampleCount,
                         unsigned int channelCount,
                         unsigned int sampleRate)
    : buffer(0)
{
    setSoundBuffer(sampleCount, channelCount, sampleRate);
}

SoundBuffer::~SoundBuffer()
{
    alDeleteBuffers(1, &buffer);
}

void SoundBuffer::setSoundBuffer(std::size_t sampleCount,
                                 unsigned int channelCount,
                                 unsigned int sampleRate)
{
    this->sampleCount = sampleCount;
    this->channelCount = channelCount;
    this->sampleRate = sampleRate;

    // We now need to generate a buffer, fill it with data, then set our
    // source to play the buffer.
    alGenBuffers(1, &buffer);

    allocateData(sampleCount * sizeof(short));
}

void SoundBuffer::update()
{
    // Find the good format according to the number of channels
    ALenum format = SoundLoader::getFormat(channelCount);

    // Check if the format is valid
    if (format == 0)
    {
        //std::cerr << "Unsupported number of channels (" << ChannelsCount << ")" << std::endl;
        return;
    }

    // Fill the buffer
    ALsizei size = static_cast<ALsizei>(sampleCount) * sizeof(short);
    alBufferData(buffer, format, data, size, sampleRate);

    // Compute the duration
    // myDuration = static_cast<float>(mySamples.size()) / SampleRate / ChannelsCount;
}

const unsigned int SoundBuffer::getBufferID() const
{
    return buffer;
}

const std::size_t SoundBuffer::getSampleCount() const
{
    return sampleCount;
}

