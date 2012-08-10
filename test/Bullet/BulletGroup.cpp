#include "BulletGroup.h"

#include <GL/glfw.h>

BulletGroup::BulletGroup()
{
    actionMap[DirectionAbs] = &setDirectionAbsolute;
    actionMap[DirectionRel] = &setDirectionRelative;
    actionMap[VelocityAbs]  = &setSpeedAbsolute;
    actionMap[VelocityRel]  = &setSpeedRelative;
    actionMap[KillBullet]   = &killBullet;
}

BulletGroup::~BulletGroup()
{
}

void BulletGroup::add(Bullet* b)
{
    group.push_back(b);
}

void BulletGroup::queueAction(BulletAction action)
{
    actionQueue.push(action);
}

void BulletGroup::logic(float step)
{
    time += step;

    BulletAction bulletAction = actionQueue.top();
    if (bulletAction.wait >= time)
    {
        actionQueue.pop();

        for (unsigned int i = 0; i < group.size(); ++i)
        {
            actionMap[bulletAction.action](*group[i], bulletAction.change);
        }
    }
}

void BulletGroup::draw(float x, float y) const
{
    /*
    for (std::vector<Bullet*>::iterator iter = group.begin();
         iter != group.end();
         ++iter)
    {
        iter->draw();
    }
    */

    for (unsigned int i = 0; i < group.size(); ++i)
    {
        group[i]->draw();
    }
}

// Bullet Methods
void setDirectionAbsolute(Bullet& b, float change)
{
    float magnitude = b.getVelocity().magnitude();
    Vector2f newVelocity(magnitude * cos(change),
                         magnitude * sin(change));
    b.setVelocity(newVelocity);
}

void setDirectionRelative(Bullet& b, float change)
{
    float direction = b.getVelocity().direction();
    direction += change;
    setDirectionAbsolute(b, direction);
}

void setSpeedAbsolute(Bullet& b, float change)
{
    b.setVelocity(b.getVelocity().normalize() * change);
}

void setSpeedRelative(Bullet& b, float change)
{
    b.setVelocity(b.getVelocity() * change);
}

void killBullet(Bullet& b, float change)
{
    b.kill();
}

