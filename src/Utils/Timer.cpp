#include "Timer.h"
:A

#include <GL/glfw.h>

Timer::Timer()
    : startTicks(0),
      pauseTicks(0),
      started(false),
      paused(false)
{
}

void Timer::start()
{
    // Set status
    started = true;
    paused = false;

    // Get current clock time
    startTicks = glfwGetTime();
}

void Timer::stop()
{
    // Set status
    started = false;
    paused = false;
}

void Timer::pause()
{
    if ((started == true) && (paused == false))
    {
        // Set status
        paused = true;

        // Calculate time
        pauseTicks = glfwGetTime() - startTicks;
    }
}

void Timer::unpause()
{
    if (paused == true)
    {
        // Set status
        paused = false;

        // Reset times
        startTicks = glfwGetTime() - pauseTicks;
        pauseTicks = 0;
    }
}

void Timer::offsetTime(float time)
{
    startTicks += time;
}

float Timer::getTime()
{
    if (started == true)
    {
        if (paused == true)
            return pauseTicks;
        else
            return (glfwGetTime() - startTicks);
    }

    return 0;
}

bool Timer::isStarted()
{
    return started;
}

bool Timer::isPaused()
{
    return paused;
}

