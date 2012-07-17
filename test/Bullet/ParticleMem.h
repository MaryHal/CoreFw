#ifndef _ParticleMem_h_
#define _ParticleMem_h_

#include <vector>
#include "Particle.h"
#include "Bullet.h"

// Interface dealie for particles. How are we going to store the particles and manage them?
class ParticleMem
{
    protected:
        Particle* mem;
        float* vertexBuffer;
        float* colorBuffer;

        int vertexBufferSize;
        int colorBufferSize;

    public:
        static const int MAX_PARTICLES =  512 * 128;

        ParticleMem();

        virtual ~ParticleMem();

        //virtual void add(const Particle& p) = 0;
        virtual void add(const Vector2f& position, 
                         const Vector2f& velocity, 
                         const Vector2f acceleration, 
                         const Color& color, 
                         float life=2.0f) = 0;
        virtual void add(const ParticleProperties& p) = 0;

        virtual void remove(int index) = 0;

        virtual Particle& get(int index) = 0;

        virtual const int size() const = 0;

        float* getVertexBuffer() const;
        float* getColorBuffer() const;
        const int getVertexBufferSize() const;
        const int getColorBufferSize() const;
};

// This will just use a simple vector to store the particles and just some fun little 
// swapping for speed.
class VectorMem : public ParticleMem
{
    protected:
        int deadIndex;

        void swap(int index1, int index2);
        void swapData(int index1, int index2);

        virtual void allocateParticles();
        void allocateData(int size);

    public:
        VectorMem(int size);
        ~VectorMem();

        //void add(const Particle& p);
        void add(const Vector2f& position, 
                 const Vector2f& velocity, 
                 const Vector2f acceleration, 
                 const Color& color, 
                 float life=2.0f);
        void add(const ParticleProperties& p);
        void remove(int index);

        Particle& get(int index);

        const int size() const;
};

class BulletMem : public VectorMem 
{
    private:
        void allocateParticles();

    public:
        BulletMem(int size);
        ~BulletMem();
};

#endif

