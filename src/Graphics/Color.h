#ifndef _Color_h_
#define _Color_h_

class Color
{
    public:
        float r;
        float g;
        float b;
        float a;

        //Color();
        Color(float r=1.0f, float g=1.0f, float b=1.0f, float a=1.0f);
        Color(const Color& c);

        void set(float r, float g, float b, float a);

        Color operator+(const Color& c) const
        {
            return Color(r + c.r, g + c.g, b + c.b, a + c.a);
        }
        Color operator-(const Color& c) const
        {
            return Color(r - c.r, g - c.g, b - c.b, a - c.a);
        }
        Color operator*(float n) const
        {
            return Color(r * n, g * n, b * n, a * n);
        }
        Color operator/(float n) const
        {
            return Color(r / n, g / n, b / n, a / n);
        }
        Color operator+=(const Color& c)
        {
            *this = *this + c;
            return *this;
        }
        Color operator-=(const Color& c)
        {
            *this = *this - c;
            return *this;
        }
        Color operator*=(float n)
        {
            *this = *this * n;
            return *this;
        }
        Color operator/=(float n)
        {
            *this = *this / n;
            return *this;
        }

        bool operator==(const Color& c)
        {
            return (r == c.r &&
                    g == c.g &&
                    b == c.b &&
                    a == c.a);
        }

        bool operator!=(const Color& c)
        {
            return !(*this == c);
        }

        static Color BLACK;
        static Color WHITE;

        static Color RED;
        static Color GREEN;
        static Color BLUE;
};

Color linearInterpolate(const Color& color1, const Color& color2, float stepSize);

#endif

