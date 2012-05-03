#include "Text.h"
#include <stdio.h>

#include "../stblib/stb_truetype.h"

Text::Text()
    : font(), text(), length(0.0f)
{
}

Text::Text(const FontPtr& f)
    : font(f), text(""), length(0.0f)
{
}

Text::Text(const FontPtr& f, const std::string& t)
    : font(f)
{
    setText(t);
}

Text::~Text()
{
}

void Text::setFont(const FontPtr& f)
{
    font = f;
}

void Text::setText(const std::string& t)
{
    text = t;
    length = 0.0f;

    //unsigned char prev(0);
    for (unsigned int i = 0; i < text.length(); ++i)
    {
        unsigned int ch = text[i] - ' ';

        if (ch < 0 || ch > Font::NUM_CHARS)
            continue;

        Glyph* glyph = font->getGlyph(ch);

        /*
        if (i < text.length())
        {
            length += stbtt_GetGlyphKernAdvance(font->getInfo(), text[i], text[i+1]);
            //printf("%d", stbtt_GetGlyphKernAdvance(font->getInfo(), text[i], text[i+1]));
        }
        */

        length += glyph->xadvance;

        //prev = text[i];
    }
}

void Text::draw(float x, float y) const
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, font->getTexture());
    glTranslatef(x, y, 0.0f);

    x = 0.0f;
    y = 0.0f;

    // This is horrible. FIXITPLZ.
    Glyph* H = font->getGlyph('H');
    float yoffset = H->y1 - H->y0;

    for (unsigned int i = 0; i < text.length(); ++i)
    {
        unsigned int ch = text[i] - ' ';

        if (text[i] == '\n')
        {
            x = 0.0f;
            y += font->getHeight();
            continue;
        }

        if (ch < 0 || ch > Font::NUM_CHARS)
            continue;

        /*
        if (i < text.length())
        {
            int kern = stbtt_GetGlyphKernAdvance(font->getInfo(), text[i], text[i+1]);
            x += kern;
        }
        */

        stbtt_aligned_quad q;
        stbtt_GetBakedQuad(font->getGlyph(0), 512, 512, ch, &x, &y, &q, 1);//1=opengl,0=old d3d

        glBegin(GL_QUADS);
        glTexCoord2f(q.s0,q.t0); glVertex2f(q.x0,q.y0 + yoffset);
        glTexCoord2f(q.s1,q.t0); glVertex2f(q.x1,q.y0 + yoffset);
        glTexCoord2f(q.s1,q.t1); glVertex2f(q.x1,q.y1 + yoffset);
        glTexCoord2f(q.s0,q.t1); glVertex2f(q.x0,q.y1 + yoffset);
        glEnd();

        //prev = text[i];
        //printf("(x, y): %f %f\n", x, y);
    }

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

float Text::getLength() const
{
    return length;
}

std::string Text::getString()
{
    return text;
}

