#ifndef _Bullet_h_
#define _Bullet_h_

#include <Math/Vector2.h>
#include <Graphics/Color.h>

#include <Graphics/Drawable.h>

#include <iostream>

enum Action
{
    DIRECTION,
    SPEED,
    ACCELERATE,
    VANISH
};

struct BulletAction
{
    Action action;
    float wait;
    float change;
};

class Bullet : public Drawable
{
    private:
        Vector2f position;
        Vector2f velocity;
        Vector2f acceleration;

        Color colorDelta;

        bool alive;

    public:
        Bullet();
        ~Bullet();

	void logic(float time);
        void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif

