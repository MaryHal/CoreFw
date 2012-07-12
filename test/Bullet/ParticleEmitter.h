#ifndef _ParticleEmitter_h_
#define _ParticleEmitter_h_

#include <Math/Random.h>
#include <Graphics/Drawable.h>

class ParticleMem;

class ParticleEmitter : public Drawable
{
    protected:
        Random random;
        ParticleMem* particles;

        unsigned int bufferID;

    public:
        ParticleEmitter();
        virtual ~ParticleEmitter();

        virtual void allocateMem();

        void logic(float step);
        void draw(float x = 0.0f, float y = 0.0f) const;

        virtual void set() = 0;

        const int getParticleCount() const;
};

#endif

