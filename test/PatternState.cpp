#include "PatternState.h"

#include <System/Input.h>

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

REGISTER_GAME("Pattern", PatternState);

PatternState::PatternState()
{
}

PatternState::~PatternState()
{
}

void PatternState::init(ResourceManager& resources)
{
    CoreState::init(resources);
    background = textures->add("patternBackground", "data/graphics/Frac4.png");
}

void PatternState::deinit()
{
    CoreState::deinit();
}

void PatternState::handleInput(Input& input, int value, int action)
{
    if (input["up"] == value && action == KeyPress)
        Core::popState();
}

void PatternState::logic(float timeStep)
{
}

void PatternState::draw()
{
    background->draw(0.0f, 0.0f);
}

