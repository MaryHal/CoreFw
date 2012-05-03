#include "GameState.h"

#include <System/Input.h>

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

#include <Utils/StringUtils.h>

#include "Bullet/ParticleEmitter.h"
#include "Bullet/Burst.h"

REGISTER_GAME("Game", GameState);

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::init(ResourceManager& resources)
{
    CoreState::init(resources);

    text = fonts->makeText("default");

    emitter = new Burst();
    held = false;
}

void GameState::deinit()
{
    CoreState::deinit();
    delete emitter;
}

void GameState::handleInput(Input& input, int value, int action)
{
    if (input["go2"] == value)
    {
        if (action == KeyPress)
            held = true;
        else
            held = false;
    }

    if (input["go"] == value && action == KeyPress)
    {
        emitter->set();
    }
}

void GameState::logic(float timeStep)
{
    if (held)
    {
        emitter->set();
    }
    emitter->logic(timeStep);
    text.setText(toString(emitter->getParticleCount()) + 
                 '\n' +
                 toString(1.0f / timeStep));
}

void GameState::draw()
{
    emitter->draw(320.0f, 240.0f);
    text.draw(4.0f, 4.0f);
}



