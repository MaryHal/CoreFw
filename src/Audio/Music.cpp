#include "Music.h"

#include "SoundLoader.h"
#include "SoundStream.h"
#include "../System/Log.h"

Music::Music()
{
}

Music::Music(const std::string& filename)
    : file(NULL), 
    streaming(false),
    sampleCount(0),
    channelCount(0),
    sampleRate(0),
    samplesProcessed(0)
{
    // Generate Buffers
    alGenBuffers(BUFFER_COUNT, buffers);
    for (unsigned int i = 0; i < BUFFER_COUNT; ++i)
        endBuffers[i] = false;

    __generateSource();
    loadSound(filename);
}

Music::~Music()
{
    stop();
    alDeleteBuffers(BUFFER_COUNT, buffers);
    if (file)
        sf_close(file);
}

void Music::play()
{
    if (!streaming)
    {
        streaming = true;
        thread = glfwCreateThread(&SoundStream::streamData, this);
    }
}

void Music::startMusic()
{
    Sound::play();
}

void Music::stop()
{
    streaming = false;
    glfwWaitThread(thread, GLFW_WAIT);
    Sound::stop();
}

void Music::loadSound(const std::string& filename)
{
    SF_INFO FileInfos;
    file = sf_open(filename.c_str(), SFM_READ, &FileInfos);
    if (!file)
    {
        //std::cerr << "Failed to read sound file \"" << Filename << "\"" << std::endl;
        return;
    }

    // Set the sound parameters
    sampleCount = static_cast<std::size_t>(FileInfos.frames) * FileInfos.channels;
    channelCount = FileInfos.channels;
    sampleRate = FileInfos.samplerate;

    format = SoundLoader::getFormat(channelCount);

    // Check if the format is valid
    if (format == 0)
    {
        channelCount = 0;
        sampleRate   = 0;

        logf("Unsupported number of channels (%d)", channelCount);
    }
}

bool Music::loadChunk(SoundChunk& c, std::size_t size)
{
    GLFWmutex mutex = glfwCreateMutex();
    c.sampleCount = static_cast<std::size_t>(sf_read_short(file, c.samples, size));
    glfwDestroyMutex(mutex);

    return c.sampleCount == size;
}

bool Music::fillQueue()
{
    // Fill and enqueue all the available buffers
    bool requestStop = false;
    for (unsigned int i = 0; (i < BUFFER_COUNT) && !requestStop; ++i)
    {
        if (fillAndPushBuffer(i))
            requestStop = true;
    }

    return requestStop;
}

bool Music::fillAndPushBuffer(unsigned int bufferNum)
{
    bool requestStop = false;

    // Acquire audio data
    std::size_t size = sampleRate * channelCount * sizeof(short);
    SoundChunk chunk = {NULL, 0};
    chunk.samples = new short[sampleRate * channelCount * 2];

    if (!loadChunk(chunk, size))
    {
        endBuffers[bufferNum] = true;
        requestStop = true;
    }

    // Buffer the data
    if (chunk.samples && chunk.sampleCount)
    {
        unsigned int buffer = buffers[bufferNum];

        // Fill the buffer
        ALsizei alsize = static_cast<ALsizei>(chunk.sampleCount) * sizeof(short);
        alBufferData(buffer, format, chunk.samples, alsize, sampleRate);

        // Push it into the sound queue
        alSourceQueueBuffers(source, 1, &buffer);
    }

    delete chunk.samples;

    return requestStop;
}

void Music::clearQueue()
{
    // Get the number of buffers still in the queue
    ALint nbQueued;
    alGetSourcei(source, AL_BUFFERS_QUEUED, &nbQueued);

    // Unqueue them all
    ALuint buffer;
    for (ALint i = 0; i < nbQueued; ++i)
        alSourceUnqueueBuffers(source, 1, &buffer);
}

bool Music::isStreaming()
{
    return streaming;
}

ALint Music::buffersProcessed()
{
    ALint processed = 0;
    alGetSourcei(source, AL_BUFFERS_PROCESSED, &processed);

    return processed;
}

unsigned int Music::popBuffer()
{
    ALuint unusedBuffer;
    alSourceUnqueueBuffers(source, 1, &unusedBuffer);

    return unusedBuffer;
}

unsigned int Music::getBufferNum(ALuint buffer)
{
    // Find its number
    unsigned int bufferNum = 0;
    for (unsigned int i = 0; i < BUFFER_COUNT; ++i)
    {
        if (buffers[i] == buffer)
        {
            bufferNum = i;
            break;
        }
    }

    return bufferNum;
}

void Music::setSamplesProcessed(unsigned long i)
{
    samplesProcessed = i;
}

void Music::addSamplesProcessed(unsigned long i)
{
    samplesProcessed += i;
}

void Music::setEndBuffer(unsigned int bufferNum, bool value)
{
    endBuffers[bufferNum] = value;
}

bool Music::getEndBuffer(unsigned int bufferNum)
{
    return endBuffers[bufferNum];
}



