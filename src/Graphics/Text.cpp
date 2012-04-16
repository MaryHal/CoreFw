#include "Text.h"

#include <ft2build.h>
#include FT_FREETYPE_H

Text::Text()
    : font(NULL), text(), length(0.0f)
{
}

Text::Text(Font* f)
    : font(f), text(""), length(0.0f)
{
}

Text::Text(Font* f, const std::string& t)
    : font(f)
{
    setText(t);
}

Text::~Text()
{
}

void Text::setFont(Font* f)
{
    font = f;
}

void Text::setText(const std::string& t)
{
    text = t;

    length = 0.0f;
    unsigned char prev(0);
    for (unsigned int i = 0; i < text.length(); ++i)
    {
        if (text[i] == '\n')
        {
            length = 0.0f;
        }

        unsigned int ch = text[i] - ' ';

        if (ch < 0 || ch > font->NUM_CHARS)
            continue;

        Glyph* glyph = font->getGlyph(ch);

        if (prev && ch)
        {
            FT_Vector delta;
            FT_Get_Kerning(font->getFace(), prev, text[i], FT_KERNING_DEFAULT, &delta);
            length += delta.x >> 6;
        }

        length += glyph->advance;

        prev = text[i];
    }
}

void Text::draw(float x, float y) const
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    float nx(0.0f);
    float ny(0.0f);

    unsigned char prev(0);

    for (unsigned int i = 0; i < text.length(); ++i)
    {
        if (text[i] == '\n')
        {
            nx = 0.0f;
            ny += font->getHeight();
        }

        unsigned int ch = text[i] - ' ';

        if (ch < 0 || ch > font->NUM_CHARS)
            continue;

        Glyph* glyph = font->getGlyph(ch);

        if (prev && ch)
        {
            FT_Vector delta;
            FT_Get_Kerning(font->getFace(), prev, text[i], FT_KERNING_DEFAULT, &delta);
            nx += delta.x >> 6;
        }

        glyph->sect.draw(nx, ny);
        nx += glyph->advance;

        prev = text[i];
    }

    glPopMatrix();
}

float Text::getLength() const
{
    return length;
}

std::string Text::getText()
{
    return text;
}

