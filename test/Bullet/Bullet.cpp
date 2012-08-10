#include "Bullet.h"

#include <GL/glfw.h>

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::set(Vector2f& pos, Vector2f& vel, Vector2f& acc,
                 Color& c)
{
    position = pos;
    velocity = vel;
    acceleration = acc;

    color = c;

    alive = true;
}

void Bullet::set(const BulletProperties& p)
{
    position = p.position;
    velocity = p.velocity;
    acceleration = p.acceleration;

    color = p.color;

    alive = true;
}

void Bullet::logic(float step)
{
    velocity += acceleration * step;
    position += velocity * step;

    color += colorDelta * step;
}

void Bullet::draw(float x, float y) const
{
    glBegin(GL_POINTS);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(position.x, position.y);
    glEnd();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

Vector2f Bullet::getPosition()
{
    return position;
}

void Bullet::setPosition(Vector2f v)
{
    position = v;
}

Vector2f Bullet::getVelocity()
{
    return velocity;
}

void Bullet::setVelocity(Vector2f v)
{
    velocity = v;
}

Vector2f Bullet::getAcceleration()
{
    return acceleration;
}

void Bullet::setAcceleration(Vector2f v)
{
    acceleration = v;
}

Color Bullet::getColor()
{
    return color;
}

void Bullet::setColor(Color c)
{
    color = c;
}

bool Bullet::isAlive()
{
    return alive;
}

void Bullet::kill()
{
    alive = false;
}

