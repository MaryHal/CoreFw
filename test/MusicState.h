#ifndef _MusicState_h_
#define _MusicState_h_

#include <Core/CoreState.h>
#include <System/ResourcePtr.h>

class Menu;

class MusicState : public CoreState
{
    private:
        TexturePtr background;
        SoundPtr music;
        Menu* menu;
        Text text;

    public:
        MusicState();
        ~MusicState();

        void init(ResourceManager& resources);
        void deinit();

        void handleInput(Input& input, int value, int action);
        void logic(float timeStep);
        void draw();
};

#endif

