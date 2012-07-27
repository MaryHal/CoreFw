#ifndef _FontLoader_h_
#define _FontLoader_h_

#include <string>
#include "../stblib/stb_truetype.h"

typedef stbtt_bakedchar Glyph;
typedef stbtt_fontinfo FontInfo;
class Font;

class FontLoader
{
    private:

    public:
        static void init();
        static void deinit();
        static bool loadFont(const std::string& Filename, unsigned int& texture, 
                             unsigned int& height, unsigned char* buffer, Glyph* glyphs, FontInfo& fontinfo);
};

#endif

