#include "BulletMem.h"

#include <System/Log.h>

void BulletMem::swap(int index1, int index2)
{
    mem[index1] = mem[index2];
}

BulletMem::BulletMem()
    : deadIndex(0)
{
    //mem = new Bullet[MAX_BULLETS];
}

BulletMem::~BulletMem()
{
    //delete [] mem;
}

Bullet& BulletMem::get(int index)
{
    coreAssert(index > 0 || index < MAX_BULLETS, "BulletMem::get index out of bounds.");
    return mem[index];
}

void BulletMem::add(Vector2f& pos, Vector2f& vel, Vector2f& acc,
                    Color& c)
{
    if (deadIndex > MAX_BULLETS)
        return;
    mem[deadIndex].set(pos, vel, acc, c);
    ++deadIndex;
}

void BulletMem::add(const BulletProperties& p)
{
    if (deadIndex > MAX_BULLETS)
        return;
    mem[deadIndex].set(p);
    ++deadIndex;
}

void BulletMem::remove(int index)
{
    swap(index, deadIndex - 1);
    --deadIndex;
}

const int BulletMem::size() const
{
    return deadIndex;
}

