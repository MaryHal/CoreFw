#ifndef _TestState_h_
#define _TestState_h_

#include <Core/CoreState.h>

#include <System/ResourcePtr.h>
#include <Utils/Timer.h>

#include <Graphics/VertexBuffer.h>

class Menu;

class TestState : public CoreState
{
    private:
        Text text;
        FontPtr font;
        TexturePtr background;

        VertexBuffer* vb;

        Menu* menu;

    public:
        TestState();
        ~TestState();

        void init(ResourceManager& resources);
        void deinit();

        void handleInput(Input& input, int value, int action);
        void logic(float timeStep);
        void draw();
};

#endif

