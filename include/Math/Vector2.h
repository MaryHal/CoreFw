#ifndef _Vector2_h_
#define _Vector2_h_

template <typename T>
class Vector2
{
    public:
        T x;
        T y;

        Vector2()
            : x(0), y(0)
        {
        }

        Vector2(const Vector2<T>& v)
            : x(v.x), y(v.y)
        {
        }

        Vector2(float X, float Y)
            : x(X), y(Y)
        {
        }

        float dotProduct(Vector2<T>& v)
        {
            return x*v.x + y+v.y;
        }

        float magnitude()
        {
            return sqrt(x * x + y * y);
        }

        Vector2<T> normalize()
        {
            return *this / magnitude();
        }

        void extend(float newMagnitude)
        {
            Vector2<T> v = normalize() * newMagnitude;
            x = v.x;
            y = v.y;
        }

        void set(T X, T Y)
        {
            x = X;
            y = Y;
        }

        void set(const Vector2<T>& v)
        {
            x = v.x;
            y = v.y;
        }

        Vector2<T> operator+(const Vector2<T>& v) const
        {
            return Vector2<T>(x + v.x, y + v.y);
        }

        Vector2<T> operator-(const Vector2<T>& v) const
        {
            return Vector2<T>(x - v.x, y - v.y);
        }

        Vector2<T> operator*(T n) const
        {
            return Vector2<T>(x * n, y * n);
        }

        Vector2<T> operator/(T n) const
        {
            return Vector2<T>(x / n, y / n);
        }

        Vector2<T> operator+=(const Vector2<T>& v)
        {
            *this = *this + v;
            return *this;
        }

        Vector2<T> operator-=(const Vector2<T>& v)
        {
            *this = *this - v;
            return *this;
        }

        Vector2<T> operator*=(T n)
        {
            *this = *this * n;
            return *this;
        }

        Vector2<T> operator/=(T n)
        {
            *this = *this / n;
            return *this;
        }

        bool operator==(const Vector2<T>& v)
        {
            return (x == v.x && y = v.y);
        }

        bool operator!=(const Vector2<T>& v)
        {
            return !(*this == v);
        }
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

float linearInterpolate(float a, float b, float step);
Vector2f linearInterpolate(Vector2f a, Vector2f b, float step);

#endif

