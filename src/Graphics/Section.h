#ifndef _Section_h_
#define _Section_h_

#include "Drawable.h"
#include "Texture.h"

#include "../Math/Rect.h"

#include "VertexBuffer.h"

class Section : public Drawable
{
    private:
        const Texture* texture;
        VertexBuffer vb;

    public:
        Section();
        Section(const Texture& t, Rect<float>* r);
        ~Section();

        void setTexture(Texture* tex);

        void createSection(const Texture& t, Rect<float>* r);
        void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif

