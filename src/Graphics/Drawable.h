#ifndef _Drawable_h_
#define _Drawable_h_

#include "Color.h"
#include "../Math/Vector2.h"

namespace Blend
{
    const int None = 0;
    const int Alpha = 1;
    const int Add = 2;
    const int Multiply = 3;
};

class Drawable
{
    private:

    public:
        Drawable();
        virtual ~Drawable() {} 

        virtual void draw(Vector2<float> v) const;
        virtual void draw(float x = 0.0f, float y = 0.0f) const = 0;
};  

#endif

