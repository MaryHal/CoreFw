#include "MusicState.h"

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

#include "Menu.h"
#include <Math/Math.h>
#include <Utils/StringUtils.h>

#include <GL/glfw.h>

REGISTER_GAME("Music", MusicState);

MusicState::MusicState()
{
}

MusicState::~MusicState()
{
}

void MusicState::init(ResourceManager& resources)
{
    CoreState::init(resources);

    fonts->add("default", "data/fonts/DroidSans.ttf", 16);
    text = fonts->makeText("default", "");

    sounds->addMusic("PainAndPossibility", "data/music/song1.flac");
    sounds->addMusic("Nevergreen", "data/music/song2.wav");

    background = textures->add("musicBackground", "data/graphics/Frac2.png");

    menu = new Menu("Songs", fonts->get("default"));
    menu->setMetrics(6, 20);
    menu->addItem("PainAndPossibility");
    menu->addItem("Nevergreen");
    menu->sortItems();
    menu->make();
}

void MusicState::deinit()
{
    //music->stop();
    CoreState::deinit();
    delete menu;
}

void MusicState::handleInput(Input& input, int value, int action)
{
    menu->handleInput(input, value, action);

    if (value == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
    {
        Core::popState();
    }
    if (value == 'Q' && action == GLFW_PRESS)
    {
        if (music)
            music->stop();
    }
}

void MusicState::logic(float timeStep)
{
    if (menu->checkChoice())
    {
        if (music)
        {
            music->stop();
        }

        std::string choice = menu->getChoice();

        music = sounds->get(choice);
        music->play();

        menu->resetChoice();
    }
    if (music)
    {

        //std::string currentTime  = toString<float>(music->getTime());
        //std::string durationTime = toString<float>(music->getDuration());
        text.setText(formatString("%.2f / %.2f", music->getTime(), music->getDuration()));
    }
}

void MusicState::draw()
{
    background->draw(0.0f, 0.0f);
    menu->draw(440.0f, 240.0f);
    text.draw(13.0f, 13.0f);

    if (music)
    {
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(12.0f, 32.0f);
        glVertex2f(12 + (640.0f - 24.0f) * music->getTime() / music->getDuration(), 32.0f);
        glEnd();
    }
}

