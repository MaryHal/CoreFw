#include "BulletEmitter.h"

BulletEmitter::BulletEmitter()
{
}

BulletEmitter::~BulletEmitter()
{
}

void BulletEmitter::fire()
{
}

void BulletEmitter::draw(float x, float y) const
{
    for (int i = 0; i < bulletMem.size(); ++i)
    {
        bulletMem.get(i).draw();
    }
}

