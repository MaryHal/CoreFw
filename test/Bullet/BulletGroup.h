#ifndef _BulletGroup_h_
#define _BulletGroup_h_

#include <vector>
#include <queue>
#include <map>
#include <Graphics/Drawable.h>
#include "Bullet.h"

enum ActionType
{
    NoAction,
    DirectionAbs,
    DirectionRel,
    VelocityAbs,
    VelocityRel,
    Kill
};

struct BulletAction
{
    BulletAction(ActionType a, float w, float c)
        : action(a), wait(w), change(c)
    {
    }

    ActionType action;
    float wait;
    float change;
};

class BulletGroup : public Drawable
{
    private:
    class CompareAction
    {
        public:
        bool operator()(BulletAction& a, BulletAction& b)
        {
            if (a.wait < b.wait)
                return true;
            return false;
        }
    };

    std::vector<Bullet> mem;
    std::priority_queue<BulletAction, std::vector<BulletAction>, CompareAction> actionQueue;

    typedef void(*ActionFunction)(Bullet& b, float change);
    typedef std::map<ActionType, ActionFunction> ActionMap;
    ActionMap actionMap;

    float time;
    unsigned int deadIndex;

    void swap(int index1, int index2);

    public:
    BulletGroup(int capacity);
    ~BulletGroup();

    void add(Bullet& b);
    void add(const BulletProperties& p);
    void add(Vector2f& pos, Vector2f& vel, Vector2f& acc,
             Color& c);
    void remove(unsigned int index);

    void queueAction(BulletAction action);

    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;
};

// Bullet Methods
void noAction(Bullet& b, float change);
void setDirectionAbsolute(Bullet& b, float change);
void setDirectionRelative(Bullet& b, float change);
void setSpeedAbsolute(Bullet& b, float change);
void setSpeedRelative(Bullet& b, float change);

void killBullet(Bullet& b, float change);

#endif
