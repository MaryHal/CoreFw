#include "Font.h"

Font::Font()
{
}

Font::Font(const std::string& filename, unsigned int charSize)
{
    loadFont(filename, charSize);
}

Font::~Font()
{
}

void Font::loadFont(const std::string& filename, unsigned int charSize)
{
    height = charSize;
    FontLoader::loadFont(filename, texture, height, buffer, glyphs, fontinfo);
}

#if 0
void Font::__renderTexture()
{
    fontTexture.draw(0.0f, 0.0f);
}
#endif

unsigned int Font::getTexture()
{
    return texture;
}

unsigned int Font::getHeight()
{
    return height;
}

Glyph* Font::getGlyph(int ch)
{
    return &glyphs[ch];
}

FontInfo* Font::getInfo()
{
    return &fontinfo;
}

