#ifndef _Burst_h_
#define _Burst_h_

#include "Particle.h"
#include "ParticleEmitter.h"

class Burst : public ParticleEmitter
{
    private:
        static ParticleProperties p;
        static const int SINGLE = 512.0f;
        bool skittles;

    public:
        Burst();

        void setSkittles(bool value);
        bool getSkittles();
        virtual void set();
};

#endif

