#ifndef _Text_h_
#define _Text_h_

#include "../Graphics/Drawable.h"
#include "../Graphics/Font.h"
#include "../System/ResourcePtr.h"

#include <string>

class Text : public Drawable
{
    private:
        FontPtr font;
        std::string text;

        float length;

    public:
        Text();
        Text(const FontPtr& f);
        Text(const FontPtr& f, const std::string& t);
        ~Text();

        void setFont(const FontPtr& f);
        void setText(const std::string& t);
        void draw(float x, float y) const;

        float getLength() const;
        std::string getString();
};

#endif

