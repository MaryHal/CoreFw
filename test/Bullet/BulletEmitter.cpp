#include "BulletEmitter.h"

#include "ParticleMem.h"

BulletEmitter::BulletEmitter()
    : ParticleEmitter()
{

}

BulletEmitter::~BulletEmitter()
{
}

void BulletEmitter::allocateMem()
{
    particles = new BulletMem(ParticleMem::MAX_PARTICLES);
}

void BulletEmitter::set()
{
}

