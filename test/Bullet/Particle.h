#ifndef _Particle_h_
#define _Particle_h_

#include <Math/Vector2.h>
#include <Graphics/Color.h>

struct ParticleProperties
{
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    Color currentColor;
    Color fadeColor;

    float life;
};

class Particle
{
    private:
        Vector2f position;
        Vector2f velocity;
        Vector2f acceleration;

        Color colorDelta;

        float life;
        bool alive;

    public:
        Particle();
        Particle(const Vector2f& velocity, const Vector2f acceleration, const Color& color, float life=2.0f);
        Particle(const ParticleProperties& p);
        ~Particle();

        void set(const Vector2f& velocity, const Vector2f acceleration, const Color& color, float life=2.0f);
        void set(const ParticleProperties& p);

        Vector2f& getVelocity();
        Vector2f& getAcceleration();
        bool isAlive() const;

        void logic(float step, float* vertices, float* colors);

        void processTranslation(float step, float* vertices);
        void processColor(float step, float* colors);
};

#endif

