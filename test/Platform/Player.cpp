#include "Player.h"

#include <System/Input.h>

Player::Player()
    : position(320.0f, 0.0f),
      velocity(0.0f, 0.0f),
      acceleration(0.0f, gravity)
{
}

Player::~Player()
{
}

void Player::handleInput(Input& input, int value, int action)
{
    if (action == KeyPress)
    {
        if (value == 'A')
            velocity.x -= horiVel;
        if (value == 'D')
            velocity.x += horiVel;
        if (value == 'J')
            velocity.y = jump;
    }
    if (action == KeyRelease)
    {
        if (value == 'A')
            velocity.x += horiVel;
        if (value == 'D')
            velocity.x -= horiVel;
        if (value == 'J')
            velocity.y /= 2;
    }
}

void Player::logic(float timeStep)
{
    velocity.x += acceleration.x * timeStep;
    velocity.y += acceleration.y * timeStep;

    position.x += velocity.x * timeStep;
    position.y += velocity.y * timeStep;

    if (position.x < 0.0f)
        position.x = 0.0f;
    if (position.x + 16 > 640.0f)
        position.x = 640.0f - 16.0f;
    if (position.y < 0.0f)
        position.y = 0.0f;
    if (position.y + 16 > 480.0f)
        position.y = 480.0f - 16.0f;
}

void Player::draw(float x, float y) const
{
    glPushMatrix();
    glTranslatef(position.x, position.y, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(16.0f, 0.0f);
    glVertex2f(16.0f, 16.0f);
    glVertex2f(0.0f, 16.0f);
    glEnd();

    glPopMatrix();
}
