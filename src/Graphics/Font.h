#ifndef _Font_h_
#define _Font_h_

#include "FontLoader.h"

class Font
{
    public:
        static const unsigned int SPACE = 32;
        static const unsigned int NUM_CHARS = 96;

    protected:
        //Texture fontTexture;
        unsigned int texture;
        unsigned int height;
        unsigned char buffer[1<<20];
        Glyph glyphs[NUM_CHARS];
        FontInfo fontinfo;

    public:
        Font();
        Font(const std::string& filename, unsigned int charSize);
        ~Font();

        void loadFont(const std::string& filename, unsigned int charSize);

        // void __renderTexture();

        unsigned int getTexture();
        unsigned int getHeight();
        Glyph* getGlyph(int ch);
        FontInfo* getInfo();
};

#endif

