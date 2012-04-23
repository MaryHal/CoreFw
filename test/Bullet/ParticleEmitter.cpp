#include "ParticleEmitter.h"

#include "ParticleMem.h"

#include <cmath>
#include <cstdio>

#include <GL/glew.h>

ParticleEmitter::ParticleEmitter()
{
}

ParticleEmitter::~ParticleEmitter()
{
    if (GLEW_ARB_vertex_buffer_object)
    {
        glDeleteBuffers(1, &bufferID);
    }

    delete particles;
}

void ParticleEmitter::init()
{
    particles = new VectorMem(ParticleMem::MAX_PARTICLES);

    if (GLEW_ARB_vertex_buffer_object)
    {
        glGenBuffers(1, &bufferID);
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);
        glBufferData(GL_ARRAY_BUFFER, 
                        particles->vertexBufferSize + particles->colorBufferSize,
                        NULL,
                        GL_STREAM_DRAW);
    }
}

void ParticleEmitter::logic(float step)
{
    //printf("%d\n", particles->size());
    for (int i = 0; i < particles->size(); ++i)
    {
        Particle& p = particles->get(i);
        p.logic(step, particles->vertexBuffer + i * 2, particles->colorBuffer + i * 4);
        if (!p.isAlive())
            particles->remove(i);
    }

    if (GLEW_ARB_vertex_buffer_object)
    {
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);
        glBufferSubData(GL_ARRAY_BUFFER_ARB, 
                        0, 
                        particles->vertexBufferSize,
                        particles->vertexBuffer);

        glBufferSubData(GL_ARRAY_BUFFER_ARB,
                        particles->vertexBufferSize,
                        particles->colorBufferSize,
                        particles->colorBuffer);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

void ParticleEmitter::draw(float x, float y) const
{
    /*
    float* vertex = particles->vertexBuffer;
    float* color = particles->colorBuffer;
    printf("%.2f, %.2f |  %.2f, %.2f, %.2f, %.2f\n", vertex[0], vertex[1],
                                                     color[0], color[1], color[2], color[3]);
                                                     */
    glPushMatrix();
    glTranslatef(320.0f, 240.0f, 0.0f);

    if (GLEW_ARB_vertex_buffer_object)
    {
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);

        glPointSize(4.0f);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, NULL);
        glColorPointer(4, GL_FLOAT, 0, (GLvoid*)(size_t)particles->vertexBufferSize);
        /*
        int error = glGetError();
        if (error)
            printf("0x%x ", error);
            */

        glDrawArrays(GL_POINTS, 0, particles->size());
        /*
        error = glGetError();
        if (error)
            printf("0x%x\n", error);
            */
        

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    glPopMatrix();
}

/*
void ParticleEmitter::set()
{
    ParticleProperties p = 
    {
        Vector2f(0.0f, 0.0f),     // position
        Vector2f(0.0f, 0.0f),     // velocity
        Vector2f(0.0f, 300.0f),   // acceleration
        
        Color(1.0, 1.0, 1.0, 1.0), // currentColor
        Color(1.0, 1.0, 1.0, 0),   // fadeColor
        2.0f                       // lifespan
    };

    int magnitude = random.genRand(350.0, 400.0);

    for (int i = 0; i < SINGLE; ++i)
    {
        float u = random.genRand(0.0, 6.28);
        float w = random.genRand(-1.0, 1.0);
        float r = magnitude * sqrt(1 - w * w);

        p.life = 2.0f + random.genRand(-0.3, 0.3);

        p.velocity.x = r * sin(u);
        p.velocity.y = r * cos(u);
        particles->add(p);
    }
}
*/

const int ParticleEmitter::particleCount() const
{
    return particles->size();    
}

