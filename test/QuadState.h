#ifndef _QUADSTATE_H_
#define _QUADSTATE_H_

#include <Core/CoreState.h>
#include <System/ResourcePtr.h>

#include <Utils/QuadTree.h>

class QuadState : public CoreState
{
    private:
    TexturePtr background;
    QuadTree tree;
    Text info;

    public:
    QuadState();
    ~QuadState();

    void init(ResourceManager& resources);
    void deinit();

    void handleInput(Input& input, int value, int action);
    void handleMouseInput(Input& input, int value, int action);
    void logic(float timeStep);
    void draw();
};


#endif /* _QUADSTATE_H_ */
