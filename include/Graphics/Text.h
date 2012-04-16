#ifndef _Text_h_
#define _Text_h_

#include "../Graphics/Drawable.h"
#include "../Graphics/Font.h"

#include <string>

class Text : public Drawable
{
    private:
        Font* font;
        std::string text;

        float length;

    public:
        Text();
        Text(Font* f);
        Text(Font* f, const std::string& t);
        ~Text();

        void setFont(Font* f);
        void setText(const std::string& t);
        void draw(float x, float y) const;

        float getLength() const;
        std::string getText();
};

#endif

