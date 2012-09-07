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

    fpstext = fonts->makeText("default");
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
    else if (value == 'Q' && action == GLFW_PRESS)
    {
        emitter.setPattern(0);
    }
    else if (value == 'W' && action == GLFW_PRESS)
    {
        emitter.setPattern(1);
    }
    else if (value == 'E' && action == GLFW_PRESS)
    {
        emitter.setPattern(2);
    }
}

void PatternState::logic(float timeStep)
{
    emitter.fire();
    emitter.logic(timeStep);

    fps.calculate();
    fpstext.setText(toString(fps.getFps()));
}

void PatternState::draw()
{
    background->draw(0.0f, 0.0f);
    emitter.draw();
    fpstext.draw(4.0f, 4.0f);
}

