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

const std::string Core::version = "0.01a";

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

bool Core::initOpenGL()
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

    renderer = new Renderer(width, height);
    renderer->init();

    fps = new FpsCounter();

    return true;
}

void Core::init(std::string title, unsigned int width, unsigned int height, bool fullscreen)
{
    Core::title  = title;
    Core::width  = width;
    Core::height = height;
    Core::fullscreen = fullscreen;
    running = false;

    initOpenGL();

    Listener::init();
    FontLoader::init();

    resourceManager = new ResourceManager();
    input = new Input();

    delete fps;
}

void Core::init(const std::string& filename)
{
    Ini ini(filename);
    Core::title = ini["Title"];
    Core::width = fromString<unsigned int>(ini["Width"]);
    Core::height = fromString<unsigned int>(ini["Height"]);
    Core::fullscreen = fromString<bool>(ini["Fullscreen"]);
    running = false;

    initOpenGL();

    Listener::init();

    resourceManager = new ResourceManager();
    input = new Input();
}

void Core::deinit()
{
    // Deinit OpenGL stuff
    glfwTerminate();
    renderer->deinit();
    delete renderer;

    // deleting fonts/resources must happen before deinitializing the
    // FontLoader
    delete resourceManager;

    delete input;

    // Deinit...everything else
    Listener::deinit();
    FontLoader::deinit();
    CoreRegistry::unregisterAll();
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
        Listener::update();

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

