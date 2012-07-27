#include "BulletMem.h"

#include <System/Log.h>

void BulletMem::swap(int index1, int index2)
{
    mem[index1] = mem[index2];
}

BulletMem::BulletMem()
{
    //mem = new Bullet[MAX_BULLETS];
}

BulletMem::~BulletMem()
{
    //delete [] mem;
}

const Bullet& BulletMem::get(int index) const
{
    coreAssert(index < 0 || index >= MAX_BULLETS, "BulletMem::get index out of bounds.");
    return mem[index];
}

void BulletMem::add()
{
    if (deadIndex > MAX_BULLETS)
        return;
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

