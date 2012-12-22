#ifndef _QUADTREE_H_
#define _QUADTREE_H_

#include <vector>
#include "../Math/Vector2.h"
#include "../Math/Rect.h"

struct Node
{
    public:
    // Area Partition
    float x;
    float y;
    float width;
    float height;

    // For lazy deletion
    bool active;

    std::vector<Vector2f*> points;

    bool contains(const Vector2f& v)
    {
        return v.x >= x && v.y >= y && v.x <= x + width && v.y <= y + height;
    }

    void setArea(float x, float y, float width, float height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void setArea(const Rectf& rect)
    {
        this->x = rect.left;
        this->y = rect.top;
        this->width  = rect.getWidth();
        this->height = rect.getHeight();
    }
};

class QuadTree
{
    private:
    static const int ARBITRARY_DEFAULT_CAPACITY = 1024;
    static const unsigned int SPLIT_CAPACITY = 4;
    std::vector<Node> nodes;
    std::vector<Vector2f> allPoints;

    public:
    QuadTree(float x, float y, float width, float height);
    QuadTree(float x, float y, float width, float height, int capacity);
    ~QuadTree();

    void add(Vector2f v);
    void splitNode(int i);
    void clear();

    inline int NE(int x);
    inline int NW(int x);
    inline int SW(int x);
    inline int SE(int x);

    inline int Parent(int x);

    // Debugging
    unsigned int __debugUsedNodes();

    std::vector<Vector2f>& getPoints();
    std::vector<Node>& getNodes();
};

#endif /* _QUADTREE_H_ */

