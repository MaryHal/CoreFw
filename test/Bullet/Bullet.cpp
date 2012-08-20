#include "Bullet.h"

#include <GL/glfw.h>
#include <System/Log.h>

Bullet::ActionFunction Bullet::actionMap[ACTION_COUNT] =
{
    &noAction,
    &setDirectionAbsolute,
    &setDirectionRelative,
    &setSpeedAbsolute,
    &setSpeedRelative,
    &killBullet
};

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
    time = 0.0f;
}

void Bullet::set(Vector2f& pos, float vel_direction, float vel_magnitude, Vector2f& acc,
                 Color& c)
{
    position = pos;
    velocity.x = vel_magnitude * cos(vel_direction);
    velocity.y = vel_magnitude * sin(vel_direction);
    acceleration = acc;

    color = c;

    alive = true;
    time = 0.0f;
}

void Bullet::set(const BulletProperties& p)
{
    position = p.position;
    velocity = p.velocity;
    acceleration = p.acceleration;

    color = p.color;

    alive = true;
    time = 0.0f;
}

void Bullet::remove()
{
    alive = false;
    time = 0.0f;
    while (!actionQueue.empty())
        actionQueue.pop();
}

void Bullet::queueAction(BulletAction action)
{
    actionQueue.push(action);
}

void Bullet::logic(float step)
{
    time += 1;
    //logf("%d %f %f", actionQueue.size(), actionQueue.top().wait, time);
    while (!actionQueue.empty() && actionQueue.top().wait <= time)
    {
        logf("%d", actionQueue.size());
        BulletAction bulletAction = actionQueue.top();
        Bullet::actionMap[bulletAction.action](*this, bulletAction.change);

        actionQueue.pop();
    }

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

void Bullet::setVelocity(float direction, float magnitude)
{
    velocity.x = magnitude * cos(direction);
    velocity.y = magnitude * sin(direction);
}

Vector2f Bullet::getAcceleration()
{
    return acceleration;
}

void Bullet::setAcceleration(Vector2f v)
{
    acceleration = v;
}

void Bullet::setAcceleration(float direction, float magnitude)
{
    acceleration.x = magnitude * cos(direction);
    acceleration.y = magnitude * sin(direction);
}

Color Bullet::getColor()
{
    return color;
}

void Bullet::setColor(Color c)
{
    color = c;
}

bool Bullet::isAlive() const
{
    return alive;
}

void Bullet::kill()
{
    alive = false;
}


// Bullet Methods
void Bullet::noAction(Bullet& b, float change)
{
    return;
}

void Bullet::setDirectionAbsolute(Bullet& b, float change)
{
    float magnitude = b.getVelocity().magnitude();
    b.setVelocity(change, magnitude);
}

void Bullet::setDirectionRelative(Bullet& b, float change)
{
    float direction = b.getVelocity().direction();
    direction += change;
    b.setVelocity(direction, b.getVelocity().magnitude());
}

void Bullet::setSpeedAbsolute(Bullet& b, float change)
{
    b.setVelocity(b.getVelocity().direction(), change);
}

void Bullet::setSpeedRelative(Bullet& b, float change)
{
    b.setVelocity(b.getVelocity() * change);
}

void Bullet::killBullet(Bullet& b, float change)
{
    b.kill();
}

