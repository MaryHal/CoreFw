#include "QuadTree.h"
#include <cstdio>

// For convenience, my node list is going to be 1-indexed.
QuadTree::QuadTree(float x, float y, float width, float height)
    : nodes(ARBITRARY_DEFAULT_CAPACITY + 1)
{
    clear();
    nodes[1].active = true;
    nodes[1].x = x;
    nodes[1].y = y;
    nodes[1].width  = width;
    nodes[1].height = height;
}

QuadTree::QuadTree(float x, float y, float width, float height, int capacity)
    : nodes(capacity + 1)
{
    clear();
    nodes[1].active = true;
    nodes[1].x = x;
    nodes[1].y = y;
    nodes[1].width  = width;
    nodes[1].height = height;
}

QuadTree::~QuadTree()
{
}

void QuadTree::add(Vector2f v)
{
    allPoints.push_back(v);

    int i = 1;
    nodes[i].points.push_back(&v);

    while (SE(i) < ARBITRARY_DEFAULT_CAPACITY && nodes[i].points.size() > SPLIT_CAPACITY)
    {
        if (!nodes[SE(i)].active)
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
    nodes[1].active = true;
}

int QuadTree::NE(int x)
{
    return (x * 4) + 1;
}

int QuadTree::NW(int x)
{
    return (x * 4) + 2;
}

int QuadTree::SW(int x)
{
    return (x * 4) + 3;
}

int QuadTree::SE(int x)
{
    return (x * 4) + 4;
}

int QuadTree::Parent(int x)
{
    return x / 4;
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


