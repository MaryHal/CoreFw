#ifndef _FontLoader_h_
#define _FontLoader_h_

#include "../Graphics/Texture.h"
#include "../Graphics/Section.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>

struct Glyph
{
    Section sect;
    int advance;
};

class Font;

class FontLoader
{
    private:
        static FT_Library library;

    public:
        static void init();
        static void deinit();
        static bool loadFont(const std::string& Filename, unsigned int charSize, FT_Face& fontFace, 
                      Texture& fontTexture, unsigned int& height, Glyph* glyphs);
        static FT_Library& getLib();
};

#endif

