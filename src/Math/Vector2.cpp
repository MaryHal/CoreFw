#include "Vector2.h"

float linearInterpolate(float a, float b, float step)
{
    return float((b - a) / step);
}

Vector2f linearInterpolate(Vector2f a, Vector2f b, float step)
{
    return (b - a) / step;
}

