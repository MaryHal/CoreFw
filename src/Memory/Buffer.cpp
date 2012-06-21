#include "Buffer.h"

#include <cstring>

#include "../Math/Vector2.h"
#include "../Graphics/Color.h"

#include "../System/Log.h"

Buffer::Buffer()
    : data(NULL),
      length(0),
      bufferEnd(NULL),
      readLoc(NULL),
      writeLoc(NULL),
      external(false)
{
}

Buffer::Buffer(size_t maxSize)
{
    allocateData(maxSize);
}

Buffer::Buffer(char* buf, int bufferLength)
{
    setBuffer(buf, bufferLength);
}

Buffer::~Buffer()
{
    if (!external)
        delete [] data;
    data = NULL;
}

void Buffer::allocateData(size_t maxSize)
{
    data = new char[maxSize];
    length = maxSize;
    bufferEnd = &data[length];

    readLoc = writeLoc = data;

    external = false;
}

void Buffer::setBuffer(char* buf, int bufferLength)
{
    data = buf;
    length = bufferLength;
    bufferEnd = &data[length];

    readLoc = data;
    writeLoc = bufferEnd;

    external = true;

    logf("%p, %d", data, length);
}

bool Buffer::atEnd()
{
    return readLoc == bufferEnd;
}

size_t Buffer::size()
{
    return (size_t)(bufferEnd - data);
}

void Buffer::rewind()
{
    readLoc = data;
}

void Buffer::clear()
{
    writeLoc = readLoc = data;
}

void Buffer::append(Buffer* b)
{
    memcpy(bufferEnd, b->getData(), b->size());
    writeLoc += b->size();
}

char* Buffer::getData()
{
    return data;
}

float Buffer::readFloat()
{
    float f;
    memcpy(&f, readLoc, sizeof(f));
    readLoc += sizeof(f);

    return f;
}

void Buffer::writeFloat(float f)
{
    memcpy(writeLoc, &f, sizeof(f));
    writeLoc += sizeof(f);
}

void Buffer::readVector(Vector2f* v)
{
    float x = readFloat();
    float y = readFloat();

    v->set(x, y);
}

void Buffer::writeVector(float x, float y)
{
    writeFloat(x);
    writeFloat(y);
}

void Buffer::writeVector(const Vector2f& v)
{
    writeVector(v.x, v.y);
}

void Buffer::readColor(Color* c)
{
    float r = readFloat();
    float g = readFloat();
    float b = readFloat();
    float a = readFloat();

    c->set(r, g, b, a);
}

void Buffer::writeColor(float r, float g, float b, float a)
{
    writeFloat(r);
    writeFloat(g);
    writeFloat(b);
    writeFloat(a);
}

void Buffer::writeColor(const Color& c)
{
    writeColor(c.r, c.g, c.b, c.a);
}

void Buffer::dumpBuffer()
{
    rewind();

    while (!atEnd())
    {
        logf("%f", readFloat());
    }
}


