#include "BulletEmitter.h"
#include "BulletGroup.h"

#include <GL/glfw.h>
#include <cmath>

BulletEmitter::BulletEmitter()
    : position(320.0f, 180.0f)
{
}

BulletEmitter::~BulletEmitter()
{
}

void BulletEmitter::fire()
{
    BulletProperties p =
    {
        Vector2f(0.0f, 0.0f),
        Vector2f(0.0f, 0.0f),
        Vector2f(0.0f, 300.0f),

        Color(0.0f, 0.0f, 1.0f, 0.8f)
    };

    bulletMem.add(p);
}

void BulletEmitter::logic(float step)
{
    for (int i = 0; i < bulletMem.size(); ++i)
    {
        Bullet& b = bulletMem.get(i);
        b.logic(step);

        if (!b.isAlive())
            bulletMem.remove(i);
    }
}

void BulletEmitter::draw(float x, float y) const
{
    glPushMatrix();
    glTranslatef(position.x, position.y, 0.0f);
    for (int i = 0; i < bulletMem.size(); ++i)
    {
        //bulletMem.drawBullet(i);
    }
    glPopMatrix();
}

