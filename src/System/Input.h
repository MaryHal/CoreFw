#ifndef _Input_h_
#define _Input_h_

#include <string>
#include <map>

#include <GL/glfw.h>

#include "../Math/Vector2.h"

enum KeyAction
{
    KeyRelease = 0,
    KeyPress
};

class Input
{
    private:
        std::map<std::string, int> keys;

        int key;
        int action;

        void __setDefaultKeys();

    public:
        Input();
        ~Input();

        int operator[](const std::string& key);

        int getKey(const std::string& key);
        void addKey(std::string key, int k);

        Vector2f getMousePos() const;
        void setMousePos(int x, int y);
};

#endif

