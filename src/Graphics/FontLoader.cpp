#include "FontLoader.h"
#include "../Graphics/Font.h"

#include "../Math/Math.h"

#include "../System/Log.h"

#define STB_TRUETYPE_IMPLEMENTATION
#include "../stblib/stb_truetype.h"

#include <cstdio>

void FontLoader::init()
{
    /*
    if (error)
        log("Could not initialize freetype.");
    log("Freetype Initialized.");
    */
}

void FontLoader::deinit()
{
}

bool FontLoader::loadFont(const std::string& Filename, unsigned int& texture,
                          unsigned int& height, unsigned char* buffer, Glyph* glyphs, FontInfo& fontinfo)
{
    unsigned char bitmap[512*512];

    FILE* f = NULL;
    f = fopen(Filename.c_str(), "rb");
    if (!f)
        return false;

    fread(buffer, 1, 1<<20, f);
    //const unsigned char* data = (const unsigned char*)buffer;

    stbtt_BakeFontBitmap(buffer, 0, height, bitmap, 512, 512, 32, 96, glyphs); // no guarantee this fits!
    //int error = stbtt_InitFont(fontinfo, buffer, stbtt_GetFontOffsetForIndex(buffer, 0));
    int error = stbtt_InitFont(&fontinfo, buffer, 0);
    //printf("%d\n", error);
    if (error == 0)
        printf("what???\n");

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, 512, 512, 0, GL_ALPHA, GL_UNSIGNED_BYTE, bitmap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    logf("Font @ \"%s\" loaded", Filename.c_str());

    return true;
}

