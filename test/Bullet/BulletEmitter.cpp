#include "BulletEmitter.h"
#include "BulletGroup.h"

#include <GL/glfw.h>
#include <cmath>

BulletEmitter::BulletEmitter()
    : position(320.0f, 180.0f),
      bulletMem(MAX_BULLETS),
      dir(0.0f),
      timeRef(0)
{
    forward = false;
}

BulletEmitter::~BulletEmitter()
{
}

void BulletEmitter::fire()
{
    pattern1();
}

void BulletEmitter::pattern1()
{
    Vector2f position(320.0f, 240.0f);
    float magnitude = 3.5;
    Vector2f acceleration(0.0f, 0.0f);
    Color color(0.8f, 0.0f, 1.0f, 0.9f);

    Bullet b;
    b.queueAction(BulletAction(VelocityAbs,  18, 0.01f));
    b.queueAction(BulletAction(DirectionRel, 60, 3.14f));
    b.queueAction(BulletAction(VelocityAbs,  60, 3.5f));

    b.set(position, dir, magnitude, acceleration, color);
    bulletMem.add(b);

    b.set(position, 3.14 / 2 + dir, magnitude, acceleration, color);
    bulletMem.add(b);

    b.set(position, 3.14 + dir, magnitude, acceleration, color);
    bulletMem.add(b);

    b.set(position, 3 * 3.14 / 2 + dir, magnitude, acceleration, color);
    bulletMem.add(b);

    /*
    b.set(position, dir + 3.14f, magnitude * 1.25, acceleration, color);
    bulletMem.add(b);
    */
    if (dir > 20.0f)
        forward = false;
    else if (dir < 0.0f)
        forward = true;

    if (forward)
        dir += 0.05f;
    else
        dir -= 0.05f;
}

void BulletEmitter::logic(float step)
{
    bulletMem.logic(step);
}

void BulletEmitter::draw(float x, float y) const
{
    glPointSize(4.0f);
    glPushMatrix();
    //glTranslatef(position.x, position.y, 0.0f);
    bulletMem.draw();
    glPopMatrix();
}

