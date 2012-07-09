#include "Core.h"
#include "../Utils/FpsCounter.h"

#include "../Graphics/Renderer.h"

#include <GL/glew.h>
#include <GL/glfw.h>

#include <cstdio>

#include "CoreRegistry.h"
#include "CoreState.h"

//#include "../Graphics/ImageLoader.h"
#include "../Graphics/FontLoader.h"
#include "../Audio/Listener.h"

#include "../System/ResourceManager.h"

#include "../Utils/Ini.h"
#include "../Utils/StringUtils.h"

#include "../System/Input.h"
#include "../System/Log.h"

const std::string Core::version = "0.02a";

std::string Core::title = "";
unsigned int Core::width = 0;
unsigned int Core::height = 0;
bool Core::fullscreen = false;
bool Core::running = false;

CoreState* Core::currentState = NULL;
CoreState* Core::nextState    = NULL;

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
    glfwTerminate();
    delete renderer;
}

void Core::run()
{
    if (currentState == NULL)
    {
        log(" ## No Initial State");
        return;
    }

    running = true;

    while (running)
    {
        if (nextState)
        {
            changeState(nextState);
        }

        fps->calculate();

        renderer->pre();

        //logf("%.2f | %.2f", fps->getFps(), fps->getFrameTime());
        currentState->logic(fps->getFrameTime());
        currentState->draw();

        renderer->post();
        //Listener::update();

        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
        //glfwSleep(1.0 / 60.0 - fps.getFrameTime());
    }

    deleteState();
}

void Core::changeState(CoreState* s)
{
    if (currentState)
    {
        currentState->deinit();
        logf(" -- Deinitialized State: \"%s\"", getStateName().c_str());
    }

    currentState = s;

    if (currentState == NULL)
    {
        return;
    }

    currentState->init(*resourceManager);
    logf(" -- Initialized State: \"%s\"", getStateName().c_str());

    nextState = NULL;
}

void Core::setNextState(CoreState* s)
{
    nextState = s;
}

void Core::deleteState()
{
    if (currentState)
    {
        currentState->deinit();
        logf(" -- Deinitialized State: \"%s\"", getStateName().c_str());
    }
}

void Core::exit()
{
    running = false;
}

const std::string& Core::getStateName()
{
    return CoreRegistry::getStateName(currentState);
}

const std::string& Core::getVersion()
{
    return version;
}

void GLFWCALL Core::keyInput(int key, int action)
{
    currentState->handleInput(*input, key, action);
}

void GLFWCALL Core::mouseMoveInput(int x, int y)
{

}

void GLFWCALL Core::mouseInput(int button, int action)
{
    currentState->handleInput(*input, button, action);
}

