#ifndef _ParticleEmitter_h_
#define _ParticleEmitter_h_

#include <Math/Random.h>
#include <Graphics/Drawable.h>

class VectorMem;

class ParticleEmitter : public Drawable
{
    protected:
        Random random;
        VectorMem* particles;

        unsigned int bufferID;

    public:
        ParticleEmitter();
        ~ParticleEmitter();

        void logic(float step);
        virtual void draw(float x = 0.0f, float y = 0.0f) const;

        virtual void set() = 0;

        const int getParticleCount() const;
};

#endif

