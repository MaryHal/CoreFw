#ifndef _Trigonometry_h_
#define _Trigonometry_h_

#include <cmath>

class Trig
{
    public:
        static float Sin(float deg)					{ return std::sin(DegToRad(deg));			}
        static float Cos(float deg)					{ return std::cos(DegToRad(deg));			}
        static float Tan(float deg)					{ return std::tan(DegToRad(deg));			}
        static float ArcSin(float value)				{ return RadToDeg(std::asin(value));		}
        static float ArcCos(float value)				{ return RadToDeg(std::acos(value));		}
        static float ArcTan2(float valY, float valX)	{ return RadToDeg(std::atan2(valY, valX));	}
        static float Sqrt(float value)				    { return std::sqrt(value);					}

        static float Pi()							    { return 3.14159265f;						}
        static float RadToDeg(float rad)				{ return 180 / 3.14159265f * rad;			}
        static float DegToRad(float deg)				{ return 3.14159265f / 180 * deg;			}
};

#endif

