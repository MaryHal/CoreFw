#include "JumpState.h"

#include <System/Input.h>

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

REGISTER_GAME("Jump", JumpState);

JumpState::JumpState()
{
}

JumpState::~JumpState()
{
}

void JumpState::init(ResourceManager& resources)
{
    CoreState::init(resources);

    background = textures->add("burstBackground", "data/graphics/Frac3.png");
}

void JumpState::deinit()
{
    CoreState::deinit();
}

void JumpState::handleInput(Input& input, int value, int action)
{
    player.handleInput(input, value, action);
}

void JumpState::logic(float timeStep)
{
    player.logic(timeStep);
}

void JumpState::draw()
{
    background->draw();
    player.draw();
}


