#ifndef _Math_h_
#define _Math_h_

namespace Math
{
    const float PI = 3.141593f;
    const double TWO_PI = (PI * 2.0);

    float radToDeg(float radians);
    float degToRad(float degrees);

    unsigned int nextPow2(register unsigned int n);
    bool checkPow2(unsigned int n);

    int min(int a, int b);
    int max(int a, int b);
};

#endif

