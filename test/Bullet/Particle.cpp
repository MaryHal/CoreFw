#include "Particle.h"

#include <cstdio>

Particle::Particle()
{
    /*
    velocity = Vector2f(0.0f, 0.0f);
    acceleration = Vector2f(0.0f, 0.0f);
    currentColor = Color::Black;
    fadeColor = 
    */
}

Particle::Particle(const Vector2f& positive, 
                   const Vector2f& velocity, 
                   const Vector2f acceleration, 
                   const Color& color, 
                   float life)
{
    set(position, velocity, acceleration, color, life);
}

Particle::Particle(const ParticleProperties& p)
{
    set(p);
}

Particle::~Particle()
{
}

void Particle::set(const Vector2f& position, 
                   const Vector2f& velocity, 
                   const Vector2f acceleration, 
                   const Color& color, 
                   float life)
{
    this->position = position;
    this->velocity = velocity;
    this->acceleration = acceleration;

    this->life = life;

    this->alive = true;
}

void Particle::set(const ParticleProperties& p)
{
    this->position = p.position;
    this->velocity = p.velocity;
    this->acceleration = p.acceleration;
    
    //printf("%.2f, %.2f, %.2f, %.2f\n", colorDelta[0], colorDelta[1], colorDelta[2], colorDelta[3]);
    
    this->life = p.life;

    colorDelta = linearInterpolate(p.currentColor, p.fadeColor, life);
    //printf("%.2f, %.2f, %.2f, %.2f\n", colorDelta[0], colorDelta[1], colorDelta[2], colorDelta[3]);

    alive = true;
}

Vector2f& Particle::getVelocity()
{
    return velocity;
}

Vector2f& Particle::getAcceleration()
{
    return acceleration;
}

bool Particle::isAlive() const
{
    return alive;
}

void Particle::logic(float step, float* vertices, float* colors)
{
    processColor(step, colors);
    processTranslation(step, vertices);

    life -= step;

    if (life <= 0.0f)
        alive = false;
}


void Particle::processTranslation(float step, float* vertices)
{
    velocity += acceleration * step;

    vertices[0] += velocity.x * step;
    vertices[1] += velocity.y * step;

    position.x = vertices[0];
    position.y = vertices[1];

    //printf("%.2f, %.2f\n", vertices[0], vertices[1]);
}

void Particle::processColor(float step, float* colors)
{
    colors[0] += colorDelta.r * step; 
    colors[1] += colorDelta.g * step; 
    colors[2] += colorDelta.b * step; 
    colors[3] += colorDelta.a * step; 

    //printf("%.2f, %.2f, %.2f, %.2f\n", colors[0], colors[1], colors[2], colors[3]);
}

/*
void Particle::draw()
{
    currentColor.set();
    glBegin(GL_POINT);
        glVertex2f(position.x, position.y);
    glEnd();
}
*/

