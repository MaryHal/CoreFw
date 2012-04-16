#ifndef _Renderer_h_
#define _Renderer_h_

#include "../Math/Vector2.h"

class Drawable;

class Renderer
{
    protected:
        int dispWidth;
        int dispHeight;

    public:
        Renderer(int w, int h);
        ~Renderer();

        void init() const;
        void deinit() const;

        void pre() const;
        void draw(Drawable& Object, float x, float y);
        void draw(Drawable& Object, Vector2f& loc);
        void post() const;

        void rotate(float rotation);
        void scale(float x, float y);
};

#endif

