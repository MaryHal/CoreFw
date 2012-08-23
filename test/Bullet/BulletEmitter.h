#ifndef _BulletEmitter_h_
#define _BulletEmitter_h_

#include "BulletGroup.h"

#include <Math/Vector2.h>
#include <Graphics/Drawable.h>

class BulletEmitter : public Drawable
{
    private:
    static const int MAX_BULLETS = 1024 * 4;
    Vector2f position;
    BulletGroup bulletMem;

    float dir;
    int timeRef;
    bool forward;

    public:
    BulletEmitter();
    ~BulletEmitter();

    void pattern1();

    virtual void fire();

    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif


