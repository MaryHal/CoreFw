#include "ParticleEmitter.h"

#include "ParticleMem.h"

#include <cmath>
#include <cstdio>

#include <GL/glew.h>

ParticleEmitter::ParticleEmitter()
{
    particles = new VectorMem(ParticleMem::MAX_PARTICLES);

    if (GLEW_ARB_vertex_buffer_object)
    {
        glGenBuffers(1, &bufferID);
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);
        glBufferData(GL_ARRAY_BUFFER, 
                        particles->getVertexBufferSize() + particles->getColorBufferSize(),
                        NULL,
                        GL_STREAM_DRAW);
    }
}

ParticleEmitter::~ParticleEmitter()
{
    if (GLEW_ARB_vertex_buffer_object)
    {
        glDeleteBuffers(1, &bufferID);
    }

    delete particles;
}

void ParticleEmitter::logic(float step)
{
    //printf("%d\n", particles->size());
    for (int i = 0; i < particles->size(); ++i)
    {
        Particle& p = particles->get(i);
        p.logic(step, 
                particles->getVertexBuffer() + i * 2, 
                particles->getColorBuffer() + i * 4);
        if (!p.isAlive())
            particles->remove(i);
    }

    if (GLEW_ARB_vertex_buffer_object)
    {
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);
        glBufferSubData(GL_ARRAY_BUFFER_ARB, 
                        0, 
                        particles->getVertexBufferSize(),
                        particles->getVertexBuffer());

        glBufferSubData(GL_ARRAY_BUFFER_ARB,
                        particles->getVertexBufferSize(),
                        particles->getColorBufferSize(),
                        particles->getColorBuffer());

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

void ParticleEmitter::draw(float x, float y) const
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    if (GLEW_ARB_vertex_buffer_object)
    {
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);

        glPointSize(4.0f);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, NULL);
        glColorPointer(4, GL_FLOAT, 0, (GLvoid*)(size_t)particles->getVertexBufferSize());

        glDrawArrays(GL_POINTS, 0, particles->size());

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    glPopMatrix();
}

const int ParticleEmitter::getParticleCount() const
{
    return particles->size();
}

