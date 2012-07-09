#ifndef _Bullet_h_
#define _Bullet_h_

#include "Particle.h"

class ParticleMem;

class Bullet : public Particle
{
    private:

    public:
        Bullet();
        Bullet(const Vector2f& positive, 
                 const Vector2f& velocity, 
                 const Vector2f acceleration, 
                 const Color& color, 
                 float life=2.0f);
        Bullet(const ParticleProperties& p);
        ~Bullet();
};

#endif

