#ifndef _BulletEmitter_h_
#define _BulletEmitter_h_

#include "BulletGroup.h"

#include <Math/Vector2.h>
#include <Graphics/Drawable.h>
#include <Math/Random.h>

class BulletEmitter : public Drawable
{
    private:
    static const int MAX_BULLETS = 1024 * 4;
    Random rng;

    Vector2f position;
    BulletGroup bulletMem;

    float dir;
    int timeRef;
    bool forward;

    int patternNum;

    public:
    BulletEmitter();
    ~BulletEmitter();

    virtual void fire();

    void pattern1();
    void pattern2();
    void pattern3();

    void setPattern(int i);
    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif


