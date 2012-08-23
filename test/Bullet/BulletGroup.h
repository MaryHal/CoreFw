#ifndef _BulletGroup_h_
#define _BulletGroup_h_

#include <vector>
#include <stack>

#include <Math/Rect.h>
#include <Graphics/Drawable.h>
#include "Bullet.h"

class BulletGroup : public Drawable
{
    private:
    std::vector<Bullet> mem;
    std::stack<Bullet*> freeMem;

    Rectf screen;
    int frameRef;

    public:
    BulletGroup(int capacity);
    ~BulletGroup();

    Bullet& get(int i);

    void add(Bullet& b);
    void add(const BulletProperties& p);
    void add(Vector2f& pos, Vector2f& vel, Vector2f& acc,
             Color& c);
    void add(Vector2f& pos, float vel_direction, float vel_magnitude, Vector2f& acc,
             Color& c);
    void remove(unsigned int index);

    void logic(float step);
    void draw(float x = 0.0f, float y = 0.0f) const;
};

#endif
