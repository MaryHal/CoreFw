#ifndef _Burst_h_
#define _Burst_h_

#include "ParticleEmitter.h"

class Burst : public ParticleEmitter
{
    private:
        static const int SINGLE = 512.0f;

    public:
        virtual void set(float x, float y);
};

#endif

