#include "Core.h"
#include "CoreRegistry.h"
#include "CoreState.h"

#include "../Utils/FpsCounter.h"

#include "../Graphics/Renderer.h"

//#include "../Graphics/ImageLoader.h"
#include "../Graphics/FontLoader.h"
#include "../Audio/Listener.h"

#include "../System/ResourceManager.h"

#include "../System/Input.h"
#include "../System/Log.h"

#include <GL/glew.h>
#include <GL/glfw.h>

#include <cstdio>


const std::string Core::version = "0.02a";

std::string Core::title = "";
unsigned int Core::width = 0;
unsigned int Core::height = 0;
bool Core::fullscreen = false;
bool Core::running = false;
std::stack<CoreState*> Core::states;

Renderer* Core::renderer = NULL;

ResourceManager* Core::resourceManager = NULL;
Input* Core::input = NULL;

FpsCounter* Core::fps = NULL;

bool Core::initGLFW()
{
    glfwInit();

    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    int ok = glfwOpenWindow(width, height,
            8, 8, 8, 8,
            0, 0,
            fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW);
    if (!ok)
    {
        running = false;
        return false;
    }

    glfwSetWindowTitle(title.c_str());
    glfwSwapInterval(1);

    glfwSetKeyCallback(keyInput);
    glfwSetMousePosCallback(mouseMoveInput);
    glfwSetMouseButtonCallback(mouseInput);

    glewInit();

    return true;
}

void Core::init(std::string title, unsigned int width, unsigned int height, bool fullscreen)
{
    Core::title  = title;
    Core::width  = width;
    Core::height = height;
    Core::fullscreen = fullscreen;
    running = false;

    initGLFW();

    Listener::init();

    renderer = new Renderer(width, height);
    resourceManager = new ResourceManager();
    input = new Input();

    fps = new FpsCounter();
}

void Core::deinit()
{
    delete resourceManager;
    delete input;

    delete fps;

    // Deinit...everything else
    CoreRegistry::unregisterAll();
    Listener::deinit();
    FontLoader::deinit();

    // Deinit OpenGL stuff
    delete renderer;
    glfwTerminate();
}

void Core::run()
{
    if (states.empty())
    {
        log(" ## No Initial State");
        return;
    }

    running = true;

    while (running)
    {
        fps->calculate();

        renderer->pre();

        //logf("%.2f | %.2f", fps->getFps(), fps->getFrameTime());
        states.top()->logic(fps->getFrameTime());
        states.top()->draw();

        renderer->post();
        //Listener::update();

        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);

        if (glfwGetKey(GLFW_KEY_F12))
        {
            popState();
            glfwSleep(1.0f);
        }

        //glfwSleep(1.0 / 60.0 - fps.getFrameTime());
    }

    popAllStates();
}

void Core::pushState(CoreState* s)
{
    if (s == NULL)
    {
        logf(" ## Trying to push NULL state: \"%s\"",
             CoreRegistry::getStateName(s).c_str());
        return;
    }

    if (s->isInitialized())
    {
        logf(" ## Trying to push already initialized state: \"%s\"",
             CoreRegistry::getStateName(s).c_str());
        return;
    }

    states.push(s);
    s->init(*resourceManager);
    logf(" -- (%d) Initializing \"%s\"", states.size(), CoreRegistry::getStateName(s).c_str());
}

void Core::popState()
{
    if (!states.empty())
    {
        // Get top member and remove it.
        CoreState* current = states.top();
        logf(" -- (%d) Deinitializing \"%s\"", states.size(), CoreRegistry::getStateName(current).c_str());
        current->deinit();

        states.pop();

        if (states.empty())
            running  = false;
    }
}

void Core::popAllStates()
{
    while (!states.empty())
    {
        CoreState* current = states.top();
        if (current->isInitialized())
        {
            logf(" -- (%d) Deinitializing \"%s\"", states.size(), CoreRegistry::getStateName(current).c_str());
            current->deinit();
        }

        states.pop();
    }
}

void Core::exit()
{
    running = false;
}

void Core::printStateStack()
{
    std::stack<CoreState*> tempStack;
}

const std::string& Core::getVersion()
{
    return version;
}

void GLFWCALL Core::keyInput(int key, int action)
{
    states.top()->handleInput(*input, key, action);
}

void GLFWCALL Core::mouseMoveInput(int x, int y)
{

}

void GLFWCALL Core::mouseInput(int button, int action)
{
    states.top()->handleMouseInput(*input, button, action);
}
