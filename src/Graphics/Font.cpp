#include "Font.h"

#include "../Graphics/FontLoader.h"

Font::Font()
{
}

Font::Font(const std::string& filename, unsigned int charSize)
{
    loadFont(filename, charSize);
}

Font::~Font()
{
    FT_Done_Face(fontFace);
}

void Font::loadFont(const std::string& filename, unsigned int charSize)
{
    FontLoader::loadFont(filename, charSize, fontFace, fontTexture, height, glyphs);
}

#if 0
void Font::__renderTexture()
{
    fontTexture.draw(0.0f, 0.0f);
}
#endif

FT_Face& Font::getFace()
{
    return fontFace;
}

unsigned int Font::getHeight()
{
    return height;
}

Glyph* Font::getGlyph(int ch)
{
    return &glyphs[ch];
}

