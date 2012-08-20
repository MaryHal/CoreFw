#include "BulletGroup.h"
#include <System/Log.h>

#include <GL/glfw.h>

void BulletGroup::swap(int index1, int index2)
{
    mem[index1] = mem[index2];
}

BulletGroup::BulletGroup(int capacity)
    : mem(capacity),
      time(0.0f),
      deadIndex(0)
{
    actionMap[NoAction]     = &noAction;
    actionMap[DirectionAbs] = &setDirectionAbsolute;
    actionMap[DirectionRel] = &setDirectionRelative;
    actionMap[VelocityAbs]  = &setSpeedAbsolute;
    actionMap[VelocityRel]  = &setSpeedRelative;
    actionMap[Kill]         = &killBullet;
}

BulletGroup::~BulletGroup()
{
}

void BulletGroup::add(Bullet& b)
{
    if (deadIndex >= mem.size())
        return;
    mem[deadIndex] = b;
    ++deadIndex;
}

void BulletGroup::add(const BulletProperties& p)
{
    if (deadIndex >= mem.size())
        return;
    mem[deadIndex].set(p);
    ++deadIndex;
}

void BulletGroup::add(Vector2f& pos, Vector2f& vel, Vector2f& acc,
                      Color& c)
{
    if (deadIndex >= mem.size())
        return;
    mem[deadIndex].set(pos, vel, acc, c);
    ++deadIndex;
}

void BulletGroup::remove(unsigned int index)
{
    if (index >= mem.size())
        return;
    swap(index, deadIndex - 1);
    --deadIndex;
}

void BulletGroup::queueAction(BulletAction action)
{
    actionQueue.push(action);
}

void BulletGroup::logic(float step)
{
    time += step;

    while (actionQueue.top().wait >= time)
    {
        BulletAction bulletAction = actionQueue.top();
        actionQueue.pop();

        /*
        for (std::vector<Bullet>::iterator iter = mem.begin();
             iter != mem.end();
             ++iter)
        {
            actionMap[bulletAction.action](*iter, bulletAction.change);
        }
        */

        for (unsigned int i = 0; i < mem.size(); ++i)
        {
            actionMap[bulletAction.action](mem[i], bulletAction.change);
        }
    }
}

void BulletGroup::draw(float x, float y) const
{
    for (std::vector<Bullet>::const_iterator iter = mem.begin();
         iter != mem.end();
         ++iter)
    {
        iter->draw();
    }

    /*
    for (unsigned int i = 0; i < mem.size(); ++i)
    {
        mem[i].draw();
    }
    */
}

// Bullet Methods
void noAction(Bullet& b, float change)
{
    return;
}

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

