#ifndef _Music_h_
#define _Music_h_

#include "Sound.h"
#include <string>

#include <GL/glfw.h>
#include <AL/al.h>

#include <sndfile.h>

class Music : public Sound
{
    private:
        struct SoundChunk
        {
            short* samples;
            std::size_t sampleCount;
        };

        static const unsigned int BUFFER_COUNT = 4;

        SNDFILE* file;

        GLFWthread thread;
        bool streaming;
        unsigned int buffers[BUFFER_COUNT];
        bool endBuffers[BUFFER_COUNT];

        std::size_t  sampleCount;
        unsigned int channelCount;
        unsigned int sampleRate;

        ALenum format;
        unsigned long samplesProcessed;

    public:
        Music();
        Music(const std::string& filename);
        ~Music();

        void play();
        void startMusic();
        void stop();

        void loadSound(const std::string& filename);
        bool loadChunk(SoundChunk& c, std::size_t size);

        bool fillQueue();
        bool fillAndPushBuffer(unsigned int bufferNum);
        void clearQueue();
        
        bool isStreaming();
        ALint buffersProcessed();

        unsigned int popBuffer();
        unsigned int getBufferNum(ALuint buffer);

        void setSamplesProcessed(unsigned long i);
        void addSamplesProcessed(unsigned long i);
        void setEndBuffer(unsigned int bufferNum, bool value);
        bool getEndBuffer(unsigned int bufferNum);
};

#endif

