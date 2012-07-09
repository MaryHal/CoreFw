#include "ParticleMem.h"

#include <cstdlib>

ParticleMem::ParticleMem() 
    : mem(NULL), vertexBuffer(NULL), colorBuffer(NULL), 
      vertexBufferSize(0), colorBufferSize(0)
{ 
}

ParticleMem::~ParticleMem()
{
}

float* ParticleMem::getVertexBuffer() const
{
    return vertexBuffer;
}

float* ParticleMem::getColorBuffer() const
{
    return colorBuffer;
}

const int ParticleMem::getVertexBufferSize() const
{
    return vertexBufferSize;
}

const int ParticleMem::getColorBufferSize() const
{
    return colorBufferSize;
}

//=======================================================================
// VECTOR MEM
//=======================================================================

void VectorMem::swap(int index1, int index2)
{
    // Swap Particles:
    // Uh, Yeah, so we don't really need to swap anything...
    //Particle temp = mem[index1];
    mem[index1] = mem[index2];
    //mem[index2] = temp;

    swapData(index1, index2);
}

void VectorMem::swapData(int index1, int index2)
{
    for (int i = 0; i < 2; ++i) 
    {
        //float temp = vertexBuffer[index1 * 2 + i];
        vertexBuffer[index1 * 2 + i] = vertexBuffer[index2 * 2 + i];
        //vertexBuffer[index2 * 2 + i] = temp;
    }
    for (int i = 0; i < 4; ++i) 
    {
        //float temp = colorBuffer[index1 * 4 + i];
        colorBuffer[index1 * 4 + i] = colorBuffer[index2 * 4 + i];
        //colorBuffer[index2 * 4 + i] = temp;
    }
}

void VectorMem::allocateData(int size)
{
    vertexBuffer = new float[size * 2];
    colorBuffer  = new float[size * 4];

    vertexBufferSize = sizeof(float) * 2 * size;
    colorBufferSize  = sizeof(float) * 4 * size;

    allocateParticles();
}

void VectorMem::allocateParticles()
{
    mem = new Particle[MAX_PARTICLES];
}

VectorMem::VectorMem(int size)
    : ParticleMem(), deadIndex(0)
{
    allocateData(size);
}

VectorMem::~VectorMem()
{
    delete [] mem;
    delete vertexBuffer;
    delete colorBuffer;
}

/*
void VectorMem::add(const Particle& p)
{
    if (deadIndex > MAX_PARTICLES)
        return;
    mem[deadIndex] = p;
    ++deadIndex;
}
*/

void VectorMem::add(const Vector2f& position, 
                    const Vector2f& velocity, 
                    const Vector2f acceleration, 
                    const Color& color, 
                    float life)
{
    if (deadIndex > MAX_PARTICLES)
        return;
    mem[deadIndex].set(position, velocity, acceleration, color, life);
    ++deadIndex;
}

void VectorMem::add(const ParticleProperties& p)
{
    if (deadIndex > MAX_PARTICLES)
        return;
    mem[deadIndex].set(p);

    vertexBuffer[deadIndex * 2 + 0] = p.position.x;
    vertexBuffer[deadIndex * 2 + 1] = p.position.y;

    colorBuffer[deadIndex * 4 + 0] = p.currentColor.r;
    colorBuffer[deadIndex * 4 + 1] = p.currentColor.g;
    colorBuffer[deadIndex * 4 + 2] = p.currentColor.b;
    colorBuffer[deadIndex * 4 + 3] = p.currentColor.a;

    ++deadIndex;
}

void VectorMem::remove(int index)
{
    swap(index, deadIndex - 1);
    --deadIndex;
}

Particle& VectorMem::get(int index)
{
    return mem[index];
}

const int VectorMem::size() const
{
    return deadIndex;
}

