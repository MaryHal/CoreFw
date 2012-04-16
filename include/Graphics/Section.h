#ifndef _Section_h_
#define _Section_h_

#include "Drawable.h"
#include "Texture.h"

#include "../Math/Rect.h"

#include "VertexBuffer.h"

class Section : public Drawable
{
    private:
        Texture* texture;
        VertexBuffer vb;

    public:
        Section();
        Section(Texture* t, Rect<float>* r);
        ~Section();

        void setTexture(Texture* tex);

        void createSection(Texture* t, Rect<float>* r);
        void draw(float x, float y) const;
};

#endif

