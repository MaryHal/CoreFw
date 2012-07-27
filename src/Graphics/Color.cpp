#include "Color.h"
#include <GL/glfw.h>

/*
Color::Color()
{
    r = 0.0f;
    g = 0.0f;
    b = 0.0f;
    a = 0.0f;
}
*/

Color::Color(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color::Color(const Color& c)
{
    this->r = c.r;
    this->g = c.g;
    this->b = c.b;
    this->a = c.a;
}

void Color::set(float r, float g, float b, float a)
{
    glColor4f(r, g, b, a);
}


Color linearInterpolate(const Color& color1, const Color& color2, float stepSize)
{
    return (color2 - color1) / stepSize;
}

Color Color::BLACK = Color(0.0f, 0.0f, 0.0f, 1.0f);
Color Color::WHITE = Color(1.0f, 1.0f, 1.0f, 1.0f);

Color Color::RED   = Color(1.0f, 0.0f, 0.0f, 1.0f);
Color Color::GREEN = Color(0.0f, 1.0f, 0.0f, 1.0f);
Color Color::BLUE  = Color(0.0f, 0.0f, 1.0f, 1.0f);

