#ifndef _BulletEmitter_h_
#define _BulletEmitter_h_

#include "BulletMem.h"

#include <Math/Vector2.h>
#include <Graphics/Drawable.h>

class BulletEmitter : public Drawable
{
    private:
    Vector2f position;
    BulletMem bulletMem;

    public:
    BulletEmitter();
    ~BulletEmitter();

    virtual void fire();

    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif

