#include "FpsCounter.h"

#include <GL/glfw.h>

FpsCounter::FpsCounter()
    : frameCount(0), startTime(glfwGetTime()), currentTime(0.0f), fps(0.0f)
{
}

FpsCounter::~FpsCounter()
{
}

void FpsCounter::calculate()
{
    lastTime = currentTime;
    currentTime = glfwGetTime();
    if (currentTime - startTime > 1 || frameCount == 0)
    {
        fps = (float)frameCount / (currentTime - startTime);
        startTime = currentTime;
        frameCount = 0;
    }
    frameCount++;
}

float FpsCounter::getFrameTime() const
{
    return currentTime - lastTime;
}

float FpsCounter::getFps() const
{
    return fps;
}

