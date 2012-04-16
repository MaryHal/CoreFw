#include "FontLoader.h"
#include "../Graphics/Font.h"

#include "../Math/Math.h"
#include <cstdio>

#include "../System/Log.h"

FT_Library FontLoader::library;

void FontLoader::init()
{
    FT_Error error = FT_Init_FreeType(&library);
    if (error)
        log("Could not initialize freetype.");
    log("Freetype Initialized.");
}

void FontLoader::deinit()
{
    FT_Done_FreeType(library);
}

bool FontLoader::loadFont(const std::string& Filename, unsigned int charSize, FT_Face& fontFace, Texture& fontTexture, unsigned int& height, Glyph* glyphs)
{
    if (!library)
    {
        logf("Failed to load font @ \"%s\". Freetype library not initialized.", Filename.c_str()); 
        return false;
    }

    FT_Error error = FT_New_Face(library, Filename.c_str(), 0, &fontFace);
    if (error)
    {
        logf("Failed to load font @ \"%s\".", Filename.c_str()); 
        return false;
    }

    // Okay. Time for some magic.
    error = FT_Set_Pixel_Sizes(fontFace, 0, charSize);
    if (error)
    {
        logf("Could not set font size.");
        // return error;
        return false;
    }

    // Check maximum texture size
    GLint max;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);

    const unsigned int SPACE = 32;
    const unsigned int NUM_CHARS = 96;
    const size_t MARGIN = 6;

    // Image sizings and stuff
    int imageWidth(max);
    int imageHeight(0);

    int lines(1);
    int lineSpace(imageWidth);

    size_t charIndex(0);
    int maxDescent(0);
    int maxAscent(0);

    for (unsigned char ch = 0; ch < NUM_CHARS; ++ch)
    {
        charIndex = FT_Get_Char_Index(fontFace, ch + SPACE);
        FT_Load_Glyph(fontFace, charIndex, FT_LOAD_RENDER);

        // Set advance
        glyphs[ch].advance = 
            (fontFace->glyph->metrics.horiAdvance >> 6);

        if (lineSpace < glyphs[ch].advance)
        {
            lineSpace = imageWidth;
            ++lines;
        }
        lineSpace -= glyphs[ch].advance + MARGIN;

        maxAscent = Math::max(fontFace->glyph->bitmap_top, maxAscent);
        maxDescent = Math::max(fontFace->glyph->bitmap.rows - 
                fontFace->glyph->bitmap_top, maxDescent);
    }

    height = maxAscent + maxDescent;
    imageHeight = Math::nextPow2(height * lines);

    unsigned char* glyphBuffer = new unsigned char[imageWidth * imageHeight];
    memset(glyphBuffer, 0, sizeof(unsigned char) * imageWidth * imageHeight);

    // set texture sizes
    fontTexture.setTexture(0, imageWidth, imageHeight);

    int x(0); 
    int y(maxAscent);

    for (unsigned int ch = 0; ch < NUM_CHARS; ++ch)
    {
        // Load Glyph
        size_t charIndex = FT_Get_Char_Index(fontFace, ch + SPACE); 
        FT_Load_Glyph(fontFace, charIndex, FT_LOAD_DEFAULT);

        // Render glyph
        FT_Render_Glyph(fontFace->glyph, FT_RENDER_MODE_NORMAL);

        if (glyphs[ch].advance > imageWidth - x)
        {
            x = MARGIN;
            y += height;
        }

        int w = fontFace->glyph->bitmap.width + fontFace->glyph->bitmap_left + MARGIN;

        glyphs[ch].sect.createSection(
                &fontTexture,
                new Rect<float>(x, y - maxAscent, 
                    x + w, y + maxDescent)
                );

        for (int row = 0; row < fontFace->glyph->bitmap.rows; ++row)
        {
            for (int pixel = 0; pixel < fontFace->glyph->bitmap.width; ++pixel)
            {
                glyphBuffer[(x + fontFace->glyph->bitmap_left + pixel) + 
                    (y - fontFace->glyph->bitmap_top + row) * imageWidth] = 
                    fontFace->glyph->bitmap.buffer[pixel + 
                    row * fontFace->glyph->bitmap.pitch];
            }

        }

        x += glyphs[ch].advance + MARGIN;
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA8, imageWidth, imageHeight, 0,
            GL_ALPHA, GL_UNSIGNED_BYTE, glyphBuffer);

    fontTexture.setTexture(tex);

    delete [] glyphBuffer;

    logf("Font @ \"%s\" loaded", Filename.c_str());

    return true;
}

FT_Library& FontLoader::getLib()
{
    return library;
}

