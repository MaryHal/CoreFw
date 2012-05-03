#include "Burst.h"

#include "Particle.h"
#include "ParticleMem.h"

#include <cmath>

void Burst::set()
{
    ParticleProperties p = 
    {
        Vector2f(0, 0),           // position
        Vector2f(0.0f, 0.0f),     // velocity
        Vector2f(0.0f, 300.0f),   // acceleration
        
        Color(1.0, 1.0, 1.0, 1.0), // currentColor
        Color(1.0, 1.0, 1.0, 0),   // fadeColor
        1.0f                       // lifespan
    };

    int magnitude = random.genRand(350.0, 400.0);

    for (int i = 0; i < SINGLE; ++i)
    {
        float u = random.genRand(0.0, 6.28);
        float w = random.genRand(-1.0, 1.0);
        float r = magnitude * sqrt(1 - w * w);

        p.life = 1.0f + random.genRand(-0.3, 0.3);

        p.velocity.x = r * sin(u);
        p.velocity.y = r * cos(u);
        particles->add(p);
    }
}

