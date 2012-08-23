#include "BulletGroup.h"
#include <System/Log.h>

#include <GL/glfw.h>

BulletGroup::BulletGroup(int capacity)
    : mem(capacity),
      screen(-320.0f, -240.0f, 640.0f, 480.0f),
      frameRef(0)
{
    for (int i = 0; i < capacity; ++i)
    {
        freeMem.push(&mem[i]);
    }
}

BulletGroup::~BulletGroup()
{
}

void BulletGroup::add(Bullet& b)
{
    Bullet* bulletRef = freeMem.top();
    freeMem.pop();
    *bulletRef = b;
}

void BulletGroup::add(const BulletProperties& p)
{
    Bullet* bulletRef = freeMem.top();
    freeMem.pop();
    bulletRef->set(p);
}

void BulletGroup::add(Vector2f& pos, Vector2f& vel, Vector2f& acc,
                      Color& c)
{
    Bullet* bulletRef = freeMem.top();
    freeMem.pop();
    bulletRef->set(pos, vel, acc, c);
}

void BulletGroup::add(Vector2f& pos, float vel_direction, float vel_magnitude, Vector2f& acc,
                      Color& c)
{
    Bullet* bulletRef = freeMem.top();
    freeMem.pop();
    bulletRef->set(pos, vel_direction, vel_magnitude, acc, c);
}

void BulletGroup::remove(unsigned int index)
{
    mem[index].remove();
    freeMem.push(&mem[index]);
}

void BulletGroup::logic(float step)
{
    for (unsigned int i = 0; i < mem.size(); ++i)
    {
        if (mem[i].isAlive())
        {
            mem[i].logic(step);
            /*
              if (!screen.collide(mem[i].getPosition()))
              {
              mem[i].kill();
              remove(i);
              }
            */
            Vector2f pos = mem[i].getPosition();
            if (pos.x < 0.0f || pos.x > 640.0f)
            {
                mem[i].kill();
                remove(i);
            }
            if (pos.y < 0.0f || pos.y > 480.0f)
            {
                mem[i].kill();
                remove(i);
            }
        }
    }

    frameRef += 1;
}

void BulletGroup::draw(float x, float y) const
{
    for (unsigned int i = 0; i < mem.size(); ++i)
    {
        if (mem[i].isAlive())
            mem[i].draw();
    }
}

