#ifndef _BulletGroup_h_
#define _BulletGroup_h_

#include <vector>
#include <queue>
#include <map>
#include <Graphics/Drawable.h>
#include "Bullet.h"

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

class BulletGroup : public Drawable
{
    private:
    std::vector<Bullet*> group;
    std::priority_queue<BulletAction, std::vector<BulletAction>, CompareAction> actionQueue;

    typedef void(*ActionFunction)(Bullet& b, float change);
    typedef std::map<Action, ActionFunction> ActionMap;
    ActionMap actionMap;

    float time;

    public:
    BulletGroup();
    ~BulletGroup();

    void add(Bullet* b);
    void queueAction(BulletAction action);

    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;
};

// Bullet Methods
void setDirectionAbsolute(Bullet& b, float change);
void setDirectionRelative(Bullet& b, float change);
void setSpeedAbsolute(Bullet& b, float change);
void setSpeedRelative(Bullet& b, float change);

void killBullet(Bullet& b, float change);

#endif
