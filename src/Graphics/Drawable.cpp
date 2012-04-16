#include "Drawable.h"

#include "../Graphics/Renderer.h"

Drawable::Drawable()
{
}

void Drawable::draw(Vector2<float> v) const
{
    this->draw(v.x, v.y);
}

