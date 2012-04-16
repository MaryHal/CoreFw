#include "Listener.h"

#include <fmodex/fmod.hpp>
#include <fmodex/fmod_errors.h>
#include <cstdio>

#include "../System/Log.h"

FMOD::System* Listener::system = NULL;

void Listener::init()
{
    FMOD_RESULT result;

    result = FMOD::System_Create(&system);      // Create the main system object.
    if (result != FMOD_OK)
    {
        logf("FMOD error! (%d) %s.", result, FMOD_ErrorString(result));
        return;
    }

    result = system->init(100, FMOD_INIT_NORMAL, 0);	// Initialize FMOD.
    if (result != FMOD_OK)
    {
        logf("FMOD error! (%d) %s.", result, FMOD_ErrorString(result));
        return;
    }

    log("Listener Initialized.");
}

void Listener::deinit()
{
    system->release();
}

void Listener::update()
{
    system->update();
}

FMOD::System* Listener::getSystem()
{
    return system;
}

