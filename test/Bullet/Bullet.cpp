#include "Bullet.h"
#include <GL/glfw.h>

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::draw(float x, float y) const
{
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

