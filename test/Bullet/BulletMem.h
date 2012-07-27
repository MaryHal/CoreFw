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

        const Bullet& get(int index) const;

        void add();
        void remove(int index);

        const int size() const;
};

#endif

