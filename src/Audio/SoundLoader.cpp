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

bool SoundLoader::loadSound(const std::string& filename, SoundBuffer& buffer)
{
    SF_INFO FileInfos;
    SNDFILE* myFile = sf_open(filename.c_str(), SFM_READ, &FileInfos);
    if (!myFile)
    {
        //std::cerr << "Failed to read sound file \"" << Filename << "\"" << std::endl;
        return false;
    }

    // Set the sound parameters
    buffer.setSoundBuffer(static_cast<std::size_t>(FileInfos.frames) * FileInfos.channels,
                          FileInfos.channels,
                          FileInfos.samplerate);
    // Read Data
    static_cast<std::size_t>(sf_read_short(myFile, (short*)buffer.getData(), buffer.getSampleCount()));

    sf_close(myFile);

    return true;
}

