#ifndef _Bullet_h_
#define _Bullet_h_

#include <Math/Vector2.h>
#include <Graphics/Color.h>

#include <Graphics/Drawable.h>

enum Action
{
    DirectionAbs,
    DirectionRel,
    VelocityAbs,
    VelocityRel,
    KillBullet
};

struct BulletAction
{
    BulletAction(Action a, float w, float c)
        : action(a), wait(w), change(c)
    {
    }

    Action action;
    float wait;
    float change;
};

struct BulletProperties
{
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    Color color;
};

class Bullet
{
    private:
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    Color color;
    Color colorDelta;

    bool alive;

    public:
    Bullet();
    ~Bullet();

    void set(Vector2f& pos, Vector2f& vel, Vector2f& acc,
             Color& c);
    void set(const BulletProperties& p);

    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;

    Vector2f getPosition();
    void setPosition(Vector2f v);

    Vector2f getVelocity();
    void setVelocity(Vector2f v);

    Vector2f getAcceleration();
    void setAcceleration(Vector2f v);

    Color getColor();
    void setColor(Color c);

    bool isAlive();
    void kill();
};

#endif

