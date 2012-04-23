#ifndef _ParticleEmitter_h_
#define _ParticleEmitter_h_

#include "../../src/Math/Random.h"
#include "../../src/Graphics/Drawable.h"

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

        void init();

        void logic(float step);
        virtual void draw(float x = 0.0f, float y = 0.0f) const;

        virtual void set(float x, float y) = 0;

        const int particleCount() const;
};

#endif

