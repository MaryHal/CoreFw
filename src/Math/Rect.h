#ifndef _Rect_h_
#define _Rect_h_

template <typename T> class Rect
{
    public:
        T top;
        T bottom;
        T left;
        T right;

        Rect()
            : top(0), bottom(0), left(0), right(0)
        {
        }

        Rect(T coordLeft, T coordTop, T coordRight, T coordBottom)
            : top(coordTop), bottom(coordBottom), left(coordLeft), right(coordRight)
        {
        }

        void offset(T offsetx, T offsety)
        {
            left += offsetx;
            right += offsetx;
            top += offsety;
            bottom += offsety;
        }

        bool collide(const Rect<T>& rect)
        {
            if (bottom < rect.top) 
                return true;
            if (top > rect.bottom) 
                return true;
            if (right < rect.left) 
                return true;
            if (left > rect.right) 
                return true;

            return false;
        }
        
        bool collide(const Vector2<T>& point)
        {
            if (point.x > left && point.x < right)
                return true;
            if (point.y > top && point.y < bottom)
                return true;
            return false;
        }

        T getWidth() const
        {
            return right - left;
        }

        T getHeight() const
        {
            return bottom - top;
        }
};

typedef Rect<float> Rectf;
typedef Rect<int> Recti;

#endif

