#include "GameState.h"

#include <System/Input.h>

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

#include <Utils/StringUtils.h>

#include "Particle/ParticleEmitter.h"
#include "Particle/Burst.h"

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

    background = textures->add("burstBackground", "data/graphics/Frac3.png");
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

    if ('Q' == value && action == KeyPress)
    {
        ((Burst*)emitter)->setSkittles(!((Burst*)emitter)->getSkittles());
    }

    if (value == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
    {
        Core::popState();
    }
}

void GameState::logic(float timeStep)
{
    if (held)
    {
        emitter->set();
    }
    emitter->logic(timeStep);
    fps.calculate();
    text.setText(toString(emitter->getParticleCount()) + 
                 '\n' +
                 toString(fps.getFps()) +
                 '\n' +
                 "Skittles: " +
                 toString(((Burst*)emitter)->getSkittles()));
}

void GameState::draw()
{
    background->draw(0.0f, 0.0f);
    emitter->draw(320.0f, 240.0f);
    text.draw(4.0f, 4.0f);
}



