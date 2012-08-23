#ifndef _Bullet_h_
#define _Bullet_h_

#include <queue>

#include <Math/Vector2.h>
#include <Graphics/Color.h>

#include <Graphics/Drawable.h>

struct BulletProperties
{
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    Color color;
};

enum ActionType
{
    NoAction,
    DirectionAbs,
    DirectionRel,
    VelocityAbs,
    VelocityRel,
    AccelDirAbs,
    AccelDirRel,
    AccelerationAbs,
    AccelerationRel,
    Kill,
    ACTION_COUNT
};

struct BulletAction
{
    BulletAction(ActionType a, int w, float c)
        : action(a), wait(w), change(c)
    {
    }

    ActionType action;
    int wait;
    float change;
};

class Bullet
{
    private:
    typedef void(*ActionFunction)(Bullet& b, float change);
    //typedef std::map<ActionType, ActionFunction> ActionMap;
    //ActionMap actionMap;
    static ActionFunction actionMap[ACTION_COUNT];

    class CompareAction
    {
        public:
        bool operator()(BulletAction& a, BulletAction& b)
        {
            if (a.wait > b.wait)
                return true;
            return false;
        }
    };

    std::priority_queue<BulletAction, std::vector<BulletAction>, CompareAction> actionQueue;

    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    Color color;
    Color colorDelta;

    int time;
    bool alive;

    public:
    Bullet();
    ~Bullet();

    void set(Vector2f& pos, Vector2f& vel, Vector2f& acc,
             Color& c);
    void set(Vector2f& pos, float vel_direction, float vel_magnitude, Vector2f& acc,
             Color& c);
    void set(const BulletProperties& p);
    void remove();

    void queueAction(BulletAction action);

    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;

    // Getters and setters
    Vector2f getPosition();
    void setPosition(Vector2f v);

    Vector2f getVelocity();
    void setVelocity(Vector2f v);
    void setVelocity(float direction, float magnitude);

    Vector2f getAcceleration();
    void setAcceleration(Vector2f v);
    void setAcceleration(float direction, float magnitude);

    Color getColor();
    void setColor(Color c);

    bool isAlive() const;
    void kill();

    // Bullet Methods
    static void noAction(Bullet& b, float change);
    static void setDirectionAbsolute(Bullet& b, float change);
    static void setDirectionRelative(Bullet& b, float change);
    static void setSpeedAbsolute(Bullet& b, float change);
    static void setSpeedRelative(Bullet& b, float change);
    static void setAccelDirAbsolute(Bullet& b, float change);
    static void setAccelDirRelative(Bullet& b, float change);
    static void setAccelerationAbsolute(Bullet& b, float change);
    static void setAccelerationRelative(Bullet& b, float change);

    static void killBullet(Bullet& b, float change);

};

#endif

