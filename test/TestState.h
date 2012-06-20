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
        Text text2;
        FontPtr font;
        TexturePtr background;
        SoundPtr sound;

        VertexBuffer* vb;
        VertexBuffer* line;

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

