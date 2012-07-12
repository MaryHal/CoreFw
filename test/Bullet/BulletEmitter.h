#ifndef _BulletEmitter_h_
#define _BulletEmitter_h_

#include "ParticleEmitter.h"

class BulletEmitter : public ParticleEmitter 
{
    private:

    public:
        BulletEmitter();
        ~BulletEmitter();

        void allocateMem();
        void set();
};

#endif

