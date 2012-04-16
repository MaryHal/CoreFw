#ifndef _Font_h_
#define _Font_h_

#include "../Graphics/Texture.h"
#include "../Graphics/Section.h"

#include "../Graphics/FontLoader.h"

#include <ft2build.h>
#include FT_FREETYPE_H

class Font
{
    public:
        static const unsigned int SPACE = 32;
        static const unsigned int NUM_CHARS = 96;

    protected:
        FT_Face fontFace;
        Texture fontTexture;
        unsigned int height;
        Glyph glyphs[NUM_CHARS];

    public:
        Font();
        Font(const std::string& filename, unsigned int charSize);
        ~Font();

        void loadFont(const std::string& filename, unsigned int charSize);

        // void __renderTexture();

        FT_Face& getFace();
        unsigned int getHeight();
        Glyph* getGlyph(int ch);
};

#endif

