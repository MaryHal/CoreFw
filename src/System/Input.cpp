#include "Input.h"

void Input::__setDefaultKeys()
{
    addKey("1", 'A');
    addKey("2", 'S');
    addKey("3", 'D');
    addKey("4", ' ');
    addKey("5", 'J');
    addKey("6", 'K');
    addKey("7", 'L');

    addKey("up", 'W');
    addKey("down", 'S');
    addKey("left", 'A');
    addKey("right", 'D');
    addKey("go", 'J');

    /*
    addKey("up", GLFW_KEY_UP);
    addKey("down", GLFW_KEY_DOWN);
    addKey("left", GLFW_KEY_LEFT);
    addKey("right", GLFW_KEY_RIGHT);
    */
}

Input::Input()
{
    __setDefaultKeys();
}

Input::~Input()
{
}

int Input::operator[](const std::string& key)
{
    return getKey(key);
}

int Input::getKey(const std::string& key)
{
    return keys[key];
}

void Input::addKey(std::string key, int k)
{
    keys[key] = k;
}

Vector2f Input::getMousePos() const
{
    int x;
    int y;
    glfwGetMousePos(&x, &y);

    return Vector2f(x, y);
}

void Input::setMousePos(int x, int y)
{
    glfwSetMousePos(x, y);
}

