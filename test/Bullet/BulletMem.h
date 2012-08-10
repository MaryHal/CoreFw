#ifndef _BulletMem_h_
#define _BulletMem_h_

#include "Bullet.h"

class BulletMem
{
    private:
    static const int MAX_BULLETS = 1024 * 2;
    void swap(int index1, int index2);

    Bullet mem[MAX_BULLETS];
    int deadIndex;

    public:
    BulletMem();
    ~BulletMem();

    Bullet& get(int index);

    void add(Vector2f& pos, Vector2f& vel, Vector2f& acc,
             Color& c);
    void add(const BulletProperties& p);
    void remove(int index);

    const int size() const;
};

#endif

