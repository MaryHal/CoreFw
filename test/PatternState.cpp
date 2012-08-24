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

    patternFunction = &BulletEmitter::pattern1;
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
        patternFunction = &BulletEmitter::pattern1;
    }
    else if (value == 'W' && action == GLFW_PRESS)
    {
        patternFunction = &BulletEmitter::pattern2;
    }
    else if (value == 'E' && action == GLFW_PRESS)
    {
        patternFunction = &BulletEmitter::pattern3;
    }
}

void PatternState::logic(float timeStep)
{
    //emitter.fire();
    patternFunction(&emitter);
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

