#ifndef _BulletEmitter_h_
#define _BulletEmitter_h_

#include "BulletMem.h"
#include <Graphics/Drawable.h>

class BulletEmitter : public Drawable
{
    private:
        BulletMem bulletMem;

    public:
        BulletEmitter();
        ~BulletEmitter();

        void fire();

        void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif

