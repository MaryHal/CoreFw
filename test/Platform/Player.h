#ifndef _Player_h_
#define _Player_h_

#include <Math/Vector2.h>
#include <Graphics/Drawable.h>

class Input;

class Player : public Drawable
{
    private:
    static const int horiVel = 250;
    static const int jump = -750;
    static const int gravity = 2000;

    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    public:
    Player();
    ~Player();

    void handleInput(Input& input, int value, int action);
    void logic(float timeStep);
    void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif
