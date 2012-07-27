#ifndef _SoundLoader_h_
#define _SoundLoader_h_

#include <string>
#include <AL/al.h>

#include "SoundBuffer.h"

class SoundLoader
{
    public:
        static ALenum getFormat(unsigned int channels);
};

#endif

