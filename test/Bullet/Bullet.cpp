#include "Bullet.h"

Bullet::Bullet()
    : Particle()
{
    /*
    velocity = Vector2f(0.0f, 0.0f);
    acceleration = Vector2f(0.0f, 0.0f);
    currentColor = Color::Black;
    fadeColor = 
    */
}

Bullet::Bullet(const Vector2f& positive, 
                   const Vector2f& velocity, 
                   const Vector2f acceleration, 
                   const Color& color, 
                   float life)
    : Particle(position, velocity, acceleration, color, life)
{
}

Bullet::Bullet(const ParticleProperties& p)
    : Particle(p)
{
}

Bullet::~Bullet()
{
}

