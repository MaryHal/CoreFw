#ifndef _Text_h_
#define _Text_h_

#include "Drawable.h"
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
        void draw(float x = 0.0f, float y = 0.0f) const;

        float getLength() const;
        const std::string& getString() const;
};

#endif

