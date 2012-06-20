#include "SoundLoader.h"

#include <sndfile.h>

ALenum SoundLoader::getFormat(unsigned int channels)
{
    switch (channels)
    {
        case 1 : return AL_FORMAT_MONO16;
        case 2 : return AL_FORMAT_STEREO16;
        case 4 : return alGetEnumValue("AL_FORMAT_QUAD16");
        case 6 : return alGetEnumValue("AL_FORMAT_51CHN16");
        case 7 : return alGetEnumValue("AL_FORMAT_61CHN16");
        case 8 : return alGetEnumValue("AL_FORMAT_71CHN16");
    }

    return 0;
}

bool SoundLoader::loadSound(const std::string& filename, unsigned int& buffer)
{
    std::size_t  SamplesCount;
    unsigned int ChannelsCount;
    unsigned int SampleRate;

    SF_INFO FileInfos;
    SNDFILE* myFile;
    myFile = sf_open(filename.c_str(), SFM_READ, &FileInfos);
    if (!myFile)
    {
        //std::cerr << "Failed to read sound file \"" << Filename << "\"" << std::endl;
        return false;
    }

    // Set the sound parameters
    ChannelsCount = FileInfos.channels;
    SampleRate    = FileInfos.samplerate;
    SamplesCount  = static_cast<std::size_t>(FileInfos.frames) * ChannelsCount;

    // Read Data
    short* data = new short[SamplesCount];
    static_cast<std::size_t>(sf_read_short(myFile, data, SamplesCount));

    update(data, buffer, ChannelsCount, SampleRate, SamplesCount);
    delete data;

    return true;
}

bool SoundLoader::update(short* data, unsigned int& buffer, unsigned int channels, unsigned int sampleRate, std::size_t sampleCount)
{
    // Find the good format according to the number of channels
    ALenum Format = SoundLoader::getFormat(channels);

    // Check if the format is valid
    if (Format == 0)
    {
        //std::cerr << "Unsupported number of channels (" << ChannelsCount << ")" << std::endl;
        return false;
    }

    // Fill the buffer
    ALsizei Size = static_cast<ALsizei>(sampleCount) * sizeof(short);
    alBufferData(buffer, Format, data, Size, sampleRate);

    // Compute the duration
    // myDuration = static_cast<float>(mySamples.size()) / SampleRate / ChannelsCount;
    return true;
}

