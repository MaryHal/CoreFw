#include "PatternState.h"

#include <System/Input.h>

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

#include <Utils/StringUtils.h>

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

    text = fonts->makeText("default");
}

void PatternState::deinit()
{
    CoreState::deinit();
}

void PatternState::handleInput(Input& input, int value, int action)
{
    if (value == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
    {
        Core::popState();
    }
    if (value == 'Q' && action == GLFW_PRESS)
    {
        emitter.fire();
    }
}

void PatternState::logic(float timeStep)
{
    emitter.fire();
    emitter.logic(timeStep);

    fps.calculate();
    text.setText(toString(fps.getFps()));
}

void PatternState::draw()
{
    background->draw(0.0f, 0.0f);
    emitter.draw();
    text.draw(4.0f, 4.0f);
}

