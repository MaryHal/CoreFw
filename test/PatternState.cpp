#include "PatternState.h"

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
}

void PatternState::deinit()
{
}

void PatternState::handleInput(Input& input, int value, int action)
{
}

void PatternState::logic(float timeStep)
{
}

void PatternState::draw()
{
}



