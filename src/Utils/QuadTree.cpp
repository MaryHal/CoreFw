#include "QuadTree.h"

// THIS IS SO MEMORY INEFFICIENT!!!

// To be slightly-more convenient, my node list is going to be 1-indexed.
// Let's change that! (Did it!)
QuadTree::QuadTree(float x, float y, float width, float height)
    : nodes(ARBITRARY_DEFAULT_CAPACITY)
{
    clear();
    nodes[0].active = true;
    nodes[0].x = x;
    nodes[0].y = y;
    nodes[0].width  = width;
    nodes[0].height = height;
}

QuadTree::QuadTree(float x, float y, float width, float height, int capacity)
    : nodes(capacity + 0)
{
    clear();
    nodes[0].active = true;
    nodes[0].x = x;
    nodes[0].y = y;
    nodes[0].width  = width;
    nodes[0].height = height;
}

QuadTree::~QuadTree()
{
}

void QuadTree::add(Vector2f v)
{
    allPoints.push_back(v);

    int i = 0;
    nodes[i].points.push_back(&v);

    while (SE(i) < ARBITRARY_DEFAULT_CAPACITY)
        // && nodes[i].points.size() > SPLIT_CAPACITY)
    {
        if (nodes[i].points.size() > SPLIT_CAPACITY && !nodes[NW(i)].active)
        {
            splitNode(i);
        }

        if (nodes[NW(i)].contains(v))
            i = NW(i);
        else if (nodes[SW(i)].contains(v))
            i = SW(i);
        else if (nodes[NE(i)].contains(v))
            i = NE(i);
        else if (nodes[SE(i)].contains(v))
            i = SE(i);
        nodes[i].points.push_back(&v);
    }
}

void QuadTree::splitNode(int i)
{
    if (!nodes[i].active)
        return;

    Node& currentNode = nodes[i];
    float x = currentNode.x;
    float y = currentNode.y;
    float width  = currentNode.width  / 2.0f;
    float height = currentNode.height / 2.0f;

    nodes[NW(i)].setArea(x, y, width, height);
    nodes[NW(i)].active = true;

    nodes[NE(i)].setArea(x + width, y, width, height);
    nodes[NE(i)].active = true;

    nodes[SW(i)].setArea(x, y + height, width, height);
    nodes[SW(i)].active = true;

    nodes[SE(i)].setArea(x + width, y + height, width, height);
    nodes[SE(i)].active = true;
}

void QuadTree::clear()
{
    for (std::vector<Node>::iterator iter = nodes.begin();
         iter != nodes.end();
         ++iter)
    {
        iter->active = false;
        iter->points.clear();
    }
    allPoints.clear();
    nodes[0].active = true;
}

int QuadTree::NE(int x)
{
    return ((x + 1) * 4);
}

int QuadTree::NW(int x)
{
    return ((x + 1) * 4) + 1;
}

int QuadTree::SW(int x)
{
    return ((x + 1) * 4) + 2;
}

int QuadTree::SE(int x)
{
    return ((x + 1) * 4) + 3;
}

int QuadTree::Parent(int x)
{
    return (x / 4) - 1;
}

// Debugging
unsigned int QuadTree::__debugUsedNodes()
{
    unsigned int s = 0;
    for (unsigned int i = 0; i < nodes.size(); ++i)
    {
        if (nodes[i].active == true)
            s += 1;
    }
    return s;
}

std::vector<Vector2f>& QuadTree::getPoints()
{
    return allPoints;
}

std::vector<Node>& QuadTree::getNodes()
{
    return nodes;
}


